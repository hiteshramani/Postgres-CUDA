/*
 * cash.c
 * Written by D'Arcy J.M. Cain
 *
 * Functions to allow input and output of money normally but store
 * and handle it as int4s
 *
 * A slightly modified version of this file and a discussion of the
 * workings can be found in the book "Software Solutions in C" by
 * Dale Schumacher, Academic Press, ISBN: 0-12-632360-7.
 *
 * $PostgreSQL: pgsql/src/backend/utils/adt/cash.c,v 1.68.2.1 2009/06/10 16:31:44 tgl Exp $
 */

#include "postgres.h"

#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

#include "libpq/pqformat.h"
#include "utils/cash.h"
#include "utils/pg_locale.h"


static const char *num_word(Cash value);


/*
 * Cash is a pass-by-ref SQL type, so we must pass and return pointers.
 * These macros and support routine hide the pass-by-refness.
 */
#define PG_GETARG_CASH(n)  (* ((Cash *) PG_GETARG_POINTER(n)))
#define PG_RETURN_CASH(x)  return CashGetDatum(x)

static Datum
CashGetDatum(Cash value)
{
	Cash	   *result = (Cash *) palloc(sizeof(Cash));

	*result = value;
	return PointerGetDatum(result);
}


/* cash_in()
 * Convert a string to a cash data type.
 * Format is [$]###[,]###[.##]
 * Examples: 123.45 $123.45 $123,456.78
 *
 * This is currently implemented as a 32-bit integer.
 * XXX HACK It looks as though some of the symbols for
 *	monetary values returned by localeconv() can be multiple
 *	bytes/characters. This code assumes one byte only. - tgl 97/04/14
 * XXX UNHACK Allow the currency symbol to be multibyte.
 *	- thomas 1998-03-01
 */
Datum
cash_in(PG_FUNCTION_ARGS)
{
	char	   *str = PG_GETARG_CSTRING(0);
	Cash		result;
	Cash		value = 0;
	Cash		dec = 0;
	Cash		sgn = 1;
	bool		seen_dot = false;
	const char *s = str;
	int			fpoint;
	char		dsymbol;
	const char *ssymbol,
			   *psymbol,
			   *nsymbol,
			   *csymbol;

	struct lconv *lconvert = PGLC_localeconv();

	/*
	 * frac_digits will be CHAR_MAX in some locales, notably C.  However, just
	 * testing for == CHAR_MAX is risky, because of compilers like gcc that
	 * "helpfully" let you alter the platform-standard definition of whether
	 * char is signed or not.  If we are so unfortunate as to get compiled
	 * with a nonstandard -fsigned-char or -funsigned-char switch, then our
	 * idea of CHAR_MAX will not agree with libc's. The safest course is not
	 * to test for CHAR_MAX at all, but to impose a range check for plausible
	 * frac_digits values.
	 */
	fpoint = lconvert->frac_digits;
	if (fpoint < 0 || fpoint > 10)
		fpoint = 2;				/* best guess in this case, I think */

	/* we restrict dsymbol to be a single byte, but not the other symbols */
	if (*lconvert->mon_decimal_point != '\0' &&
		lconvert->mon_decimal_point[1] == '\0')
		dsymbol = *lconvert->mon_decimal_point;
	else
		dsymbol = '.';
	if (*lconvert->mon_thousands_sep != '\0')
		ssymbol = lconvert->mon_thousands_sep;
	else						/* ssymbol should not equal dsymbol */
		ssymbol = (dsymbol != ',') ? "," : ".";
	csymbol = (*lconvert->currency_symbol != '\0') ? lconvert->currency_symbol : "$";
	psymbol = (*lconvert->positive_sign != '\0') ? lconvert->positive_sign : "+";
	nsymbol = (*lconvert->negative_sign != '\0') ? lconvert->negative_sign : "-";

#ifdef CASHDEBUG
	printf("cashin- precision '%d'; decimal '%c'; thousands '%s'; currency '%s'; positive '%s'; negative '%s'\n",
		   fpoint, dsymbol, ssymbol, csymbol, psymbol, nsymbol);
#endif

	/* we need to add all sorts of checking here.  For now just */
	/* strip all leading whitespace and any leading currency symbol */
	while (isspace((unsigned char) *s))
		s++;
	if (strncmp(s, csymbol, strlen(csymbol)) == 0)
		s += strlen(csymbol);

#ifdef CASHDEBUG
	printf("cashin- string is '%s'\n", s);
#endif

	/* a leading minus or paren signifies a negative number */
	/* again, better heuristics needed */
	if (strncmp(s, nsymbol, strlen(nsymbol)) == 0)
	{
		sgn = -1;
		s += strlen(nsymbol);
	}
	else if (*s == '(')
	{
		sgn = -1;
		s++;
	}
	else if (strncmp(s, psymbol, strlen(psymbol)) == 0)
		s += strlen(psymbol);

#ifdef CASHDEBUG
	printf("cashin- string is '%s'\n", s);
#endif

	/* allow whitespace and currency symbol after the sign, too */
	while (isspace((unsigned char) *s))
		s++;
	if (strncmp(s, csymbol, strlen(csymbol)) == 0)
		s += strlen(csymbol);

#ifdef CASHDEBUG
	printf("cashin- string is '%s'\n", s);
#endif

	for (; *s; s++)
	{
		/* we look for digits as long as we have found less */
		/* than the required number of decimal places */
		if (isdigit((unsigned char) *s) && (!seen_dot || dec < fpoint))
		{
			value = (value * 10) + (*s - '0');

			if (seen_dot)
				dec++;
		}
		/* decimal point? then start counting fractions... */
		else if (*s == dsymbol && !seen_dot)
		{
			seen_dot = true;
		}
		/* ignore if "thousands" separator, else we're done */
		else if (strncmp(s, ssymbol, strlen(ssymbol)) == 0)
			s += strlen(ssymbol) - 1;
		else
			break;
	}

	/* round off if there's another digit */
	if (isdigit((unsigned char) *s) && *s >= '5')
		value++;

	/* adjust for less than required decimal places */
	for (; dec < fpoint; dec++)
		value *= 10;

	/*
	 * should only be trailing digits followed by whitespace, right paren,
	 * or possibly a trailing minus sign
	 */
	while (isdigit((unsigned char) *s))
		s++;
	while (*s)
	{
		if (isspace((unsigned char) *s) || *s == ')')
			s++;
		else if (strncmp(s, nsymbol, strlen(nsymbol)) == 0)
		{
			sgn = -1;
			s += strlen(nsymbol);
		}
		else
			ereport(ERROR,
					(errcode(ERRCODE_INVALID_TEXT_REPRESENTATION),
					 errmsg("invalid input syntax for type money: \"%s\"",
							str)));
	}

	result = value * sgn;

#ifdef CASHDEBUG
	printf("cashin- result is %d\n", result);
#endif

	PG_RETURN_CASH(result);
}


/* cash_out()
 * Function to convert cash to a dollars and cents representation, using
 * the lc_monetary locale's formatting.
 */
Datum
cash_out(PG_FUNCTION_ARGS)
{
	Cash		value = PG_GETARG_CASH(0);
	char	   *result;
	char		buf[128];
	char	   *bufptr;
	bool		minus = false;
	int			digit_pos;
	int			points,
				mon_group;
	char		dsymbol;
	const char *ssymbol,
			   *csymbol,
			   *nsymbol;
	char		convention;

	struct lconv *lconvert = PGLC_localeconv();

	/* see comments about frac_digits in cash_in() */
	points = lconvert->frac_digits;
	if (points < 0 || points > 10)
		points = 2;				/* best guess in this case, I think */

	/*
	 * As with frac_digits, must apply a range check to mon_grouping to avoid
	 * being fooled by variant CHAR_MAX values.
	 */
	mon_group = *lconvert->mon_grouping;
	if (mon_group <= 0 || mon_group > 6)
		mon_group = 3;

	convention = lconvert->n_sign_posn;

	/* we restrict dsymbol to be a single byte, but not the other symbols */
	if (*lconvert->mon_decimal_point != '\0' &&
		lconvert->mon_decimal_point[1] == '\0')
		dsymbol = *lconvert->mon_decimal_point;
	else
		dsymbol = '.';
	if (*lconvert->mon_thousands_sep != '\0')
		ssymbol = lconvert->mon_thousands_sep;
	else						/* ssymbol should not equal dsymbol */
		ssymbol = (dsymbol != ',') ? "," : ".";
	csymbol = (*lconvert->currency_symbol != '\0') ? lconvert->currency_symbol : "$";
	nsymbol = (*lconvert->negative_sign != '\0') ? lconvert->negative_sign : "-";

	/* we work with positive amounts and add the minus sign at the end */
	if (value < 0)
	{
		minus = true;
		value = -value;
	}

	/* we build the result string right-to-left in buf[] */
	bufptr = buf + sizeof(buf) - 1;
	*bufptr = '\0';

	/*
	 * Generate digits till there are no non-zero digits left and we emitted
	 * at least one to the left of the decimal point.  digit_pos is the
	 * current digit position, with zero as the digit just left of the decimal
	 * point, increasing to the right.
	 */
	digit_pos = points;
	do
	{
		if (points && digit_pos == 0)
		{
			/* insert decimal point */
			*(--bufptr) = dsymbol;
		}
		else if (digit_pos < points && (digit_pos % mon_group) == 0)
		{
			/* insert thousands sep */
			bufptr -= strlen(ssymbol);
			memcpy(bufptr, ssymbol, strlen(ssymbol));
		}

		*(--bufptr) = ((unsigned int) value % 10) + '0';
		value = ((unsigned int) value) / 10;
		digit_pos--;
	} while (value || digit_pos >= 0);

	/* prepend csymbol */
	bufptr -= strlen(csymbol);
	memcpy(bufptr, csymbol, strlen(csymbol));

	/* see if we need to signify negative amount */
	if (minus)
	{
		result = palloc(strlen(bufptr) + strlen(nsymbol) + 3);

		/* Position code of 0 means use parens */
		if (convention == 0)
			sprintf(result, "(%s)", bufptr);
		else if (convention == 2)
			sprintf(result, "%s%s", bufptr, nsymbol);
		else
			sprintf(result, "%s%s", nsymbol, bufptr);
	}
	else
	{
		/* just emit what we have */
		result = pstrdup(bufptr);
	}

	PG_RETURN_CSTRING(result);
}

/*
 *		cash_recv			- converts external binary format to cash
 */
Datum
cash_recv(PG_FUNCTION_ARGS)
{
	StringInfo	buf = (StringInfo) PG_GETARG_POINTER(0);

	PG_RETURN_CASH((Cash) pq_getmsgint(buf, sizeof(Cash)));
}

/*
 *		cash_send			- converts cash to binary format
 */
Datum
cash_send(PG_FUNCTION_ARGS)
{
	Cash		arg1 = PG_GETARG_CASH(0);
	StringInfoData buf;

	pq_begintypsend(&buf);
	pq_sendint(&buf, arg1, sizeof(Cash));
	PG_RETURN_BYTEA_P(pq_endtypsend(&buf));
}

/*
 * Comparison functions
 */

Datum
cash_eq(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);

	PG_RETURN_BOOL(c1 == c2);
}

Datum
cash_ne(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);

	PG_RETURN_BOOL(c1 != c2);
}

Datum
cash_lt(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);

	PG_RETURN_BOOL(c1 < c2);
}

Datum
cash_le(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);

	PG_RETURN_BOOL(c1 <= c2);
}

Datum
cash_gt(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);

	PG_RETURN_BOOL(c1 > c2);
}

Datum
cash_ge(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);

	PG_RETURN_BOOL(c1 >= c2);
}

Datum
cash_cmp(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);

	if (c1 > c2)
		PG_RETURN_INT32(1);
	else if (c1 == c2)
		PG_RETURN_INT32(0);
	else
		PG_RETURN_INT32(-1);
}


/* cash_pl()
 * Add two cash values.
 */
Datum
cash_pl(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);
	Cash		result;

	result = c1 + c2;

	PG_RETURN_CASH(result);
}


/* cash_mi()
 * Subtract two cash values.
 */
Datum
cash_mi(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);
	Cash		result;

	result = c1 - c2;

	PG_RETURN_CASH(result);
}


/* cash_mul_flt8()
 * Multiply cash by float8.
 */
Datum
cash_mul_flt8(PG_FUNCTION_ARGS)
{
	Cash		c = PG_GETARG_CASH(0);
	float8		f = PG_GETARG_FLOAT8(1);
	Cash		result;

	result = c * f;
	PG_RETURN_CASH(result);
}


/* flt8_mul_cash()
 * Multiply float8 by cash.
 */
Datum
flt8_mul_cash(PG_FUNCTION_ARGS)
{
	float8		f = PG_GETARG_FLOAT8(0);
	Cash		c = PG_GETARG_CASH(1);
	Cash		result;

	result = f * c;
	PG_RETURN_CASH(result);
}


/* cash_div_flt8()
 * Divide cash by float8.
 *
 * XXX Don't know if rounding or truncating is correct behavior.
 * Round for now. - tgl 97/04/15
 */
Datum
cash_div_flt8(PG_FUNCTION_ARGS)
{
	Cash		c = PG_GETARG_CASH(0);
	float8		f = PG_GETARG_FLOAT8(1);
	Cash		result;

	if (f == 0.0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));

	result = rint(c / f);
	PG_RETURN_CASH(result);
}

/* cash_mul_flt4()
 * Multiply cash by float4.
 */
Datum
cash_mul_flt4(PG_FUNCTION_ARGS)
{
	Cash		c = PG_GETARG_CASH(0);
	float4		f = PG_GETARG_FLOAT4(1);
	Cash		result;

	result = c * f;
	PG_RETURN_CASH(result);
}


/* flt4_mul_cash()
 * Multiply float4 by cash.
 */
Datum
flt4_mul_cash(PG_FUNCTION_ARGS)
{
	float4		f = PG_GETARG_FLOAT4(0);
	Cash		c = PG_GETARG_CASH(1);
	Cash		result;

	result = f * c;
	PG_RETURN_CASH(result);
}


/* cash_div_flt4()
 * Divide cash by float4.
 *
 * XXX Don't know if rounding or truncating is correct behavior.
 * Round for now. - tgl 97/04/15
 */
Datum
cash_div_flt4(PG_FUNCTION_ARGS)
{
	Cash		c = PG_GETARG_CASH(0);
	float4		f = PG_GETARG_FLOAT4(1);
	Cash		result;

	if (f == 0.0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));

	result = rint(c / f);
	PG_RETURN_CASH(result);
}


/* cash_mul_int4()
 * Multiply cash by int4.
 */
Datum
cash_mul_int4(PG_FUNCTION_ARGS)
{
	Cash		c = PG_GETARG_CASH(0);
	int32		i = PG_GETARG_INT32(1);
	Cash		result;

	result = c * i;
	PG_RETURN_CASH(result);
}


/* int4_mul_cash()
 * Multiply int4 by cash.
 */
Datum
int4_mul_cash(PG_FUNCTION_ARGS)
{
	int32		i = PG_GETARG_INT32(0);
	Cash		c = PG_GETARG_CASH(1);
	Cash		result;

	result = i * c;
	PG_RETURN_CASH(result);
}


/* cash_div_int4()
 * Divide cash by 4-byte integer.
 *
 * XXX Don't know if rounding or truncating is correct behavior.
 * Round for now. - tgl 97/04/15
 */
Datum
cash_div_int4(PG_FUNCTION_ARGS)
{
	Cash		c = PG_GETARG_CASH(0);
	int32		i = PG_GETARG_INT32(1);
	Cash		result;

	if (i == 0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));

	result = rint(c / i);

	PG_RETURN_CASH(result);
}


/* cash_mul_int2()
 * Multiply cash by int2.
 */
Datum
cash_mul_int2(PG_FUNCTION_ARGS)
{
	Cash		c = PG_GETARG_CASH(0);
	int16		s = PG_GETARG_INT16(1);
	Cash		result;

	result = c * s;
	PG_RETURN_CASH(result);
}

/* int2_mul_cash()
 * Multiply int2 by cash.
 */
Datum
int2_mul_cash(PG_FUNCTION_ARGS)
{
	int16		s = PG_GETARG_INT16(0);
	Cash		c = PG_GETARG_CASH(1);
	Cash		result;

	result = s * c;
	PG_RETURN_CASH(result);
}

/* cash_div_int2()
 * Divide cash by int2.
 *
 * XXX Don't know if rounding or truncating is correct behavior.
 * Round for now. - tgl 97/04/15
 */
Datum
cash_div_int2(PG_FUNCTION_ARGS)
{
	Cash		c = PG_GETARG_CASH(0);
	int16		s = PG_GETARG_INT16(1);
	Cash		result;

	if (s == 0)
		ereport(ERROR,
				(errcode(ERRCODE_DIVISION_BY_ZERO),
				 errmsg("division by zero")));

	result = rint(c / s);
	PG_RETURN_CASH(result);
}

/* cashlarger()
 * Return larger of two cash values.
 */
Datum
cashlarger(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);
	Cash		result;

	result = (c1 > c2) ? c1 : c2;

	PG_RETURN_CASH(result);
}

/* cashsmaller()
 * Return smaller of two cash values.
 */
Datum
cashsmaller(PG_FUNCTION_ARGS)
{
	Cash		c1 = PG_GETARG_CASH(0);
	Cash		c2 = PG_GETARG_CASH(1);
	Cash		result;

	result = (c1 < c2) ? c1 : c2;

	PG_RETURN_CASH(result);
}


/* cash_words()
 * This converts a int4 as well but to a representation using words
 * Obviously way North American centric - sorry
 */
Datum
cash_words(PG_FUNCTION_ARGS)
{
	Cash		value = PG_GETARG_CASH(0);
	unsigned int val;
	char		buf[256];
	char	   *p = buf;
	Cash		m0;
	Cash		m1;
	Cash		m2;
	Cash		m3;
	text	   *result;

	/* work with positive numbers */
	if (value < 0)
	{
		value = -value;
		strcpy(buf, "minus ");
		p += 6;
	}
	else
		buf[0] = '\0';

	/* Now treat as unsigned, to avoid trouble at INT_MIN */
	val = (unsigned int) value;

	m0 = val % 100;				/* cents */
	m1 = (val / 100) % 1000;	/* hundreds */
	m2 = (val / 100000) % 1000; /* thousands */
	m3 = val / 100000000 % 1000;	/* millions */

	if (m3)
	{
		strcat(buf, num_word(m3));
		strcat(buf, " million ");
	}

	if (m2)
	{
		strcat(buf, num_word(m2));
		strcat(buf, " thousand ");
	}

	if (m1)
		strcat(buf, num_word(m1));

	if (!*p)
		strcat(buf, "zero");

	strcat(buf, (val / 100) == 1 ? " dollar and " : " dollars and ");
	strcat(buf, num_word(m0));
	strcat(buf, m0 == 1 ? " cent" : " cents");

	/* capitalize output */
	buf[0] = pg_toupper((unsigned char) buf[0]);

	/* make a text type for output */
	result = (text *) palloc(strlen(buf) + VARHDRSZ);
	VARATT_SIZEP(result) = strlen(buf) + VARHDRSZ;
	memcpy(VARDATA(result), buf, strlen(buf));

	PG_RETURN_TEXT_P(result);
}


/*************************************************************************
 * Private routines
 ************************************************************************/

static const char *
num_word(Cash value)
{
	static char buf[128];
	static const char *small[] = {
		"zero", "one", "two", "three", "four", "five", "six", "seven",
		"eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
		"thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
	};
	const char **big = small + 18;
	int			tu = value % 100;

	/* deal with the simple cases first */
	if (value <= 20)
		return small[value];

	/* is it an even multiple of 100? */
	if (!tu)
	{
		sprintf(buf, "%s hundred", small[value / 100]);
		return buf;
	}

	/* more than 99? */
	if (value > 99)
	{
		/* is it an even multiple of 10 other than 10? */
		if (value % 10 == 0 && tu > 10)
			sprintf(buf, "%s hundred %s",
					small[value / 100], big[tu / 10]);
		else if (tu < 20)
			sprintf(buf, "%s hundred and %s",
					small[value / 100], small[tu]);
		else
			sprintf(buf, "%s hundred %s %s",
					small[value / 100], big[tu / 10], small[tu % 10]);

	}
	else
	{
		/* is it an even multiple of 10 other than 10? */
		if (value % 10 == 0 && tu > 10)
			sprintf(buf, "%s", big[tu / 10]);
		else if (tu < 20)
			sprintf(buf, "%s", small[tu]);
		else
			sprintf(buf, "%s %s", big[tu / 10], small[tu % 10]);
	}

	return buf;
}	/* num_word() */
