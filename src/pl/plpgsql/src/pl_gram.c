
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         plpgsql_yyparse
#define yylex           plpgsql_yylex
#define yyerror         plpgsql_yyerror
#define yylval          plpgsql_yylval
#define yychar          plpgsql_yychar
#define yydebug         plpgsql_yydebug
#define yynerrs         plpgsql_yynerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "gram.y"

/*-------------------------------------------------------------------------
 *
 * gram.y				- Parser for the PL/pgSQL
 *						  procedural language
 *
 * Portions Copyright (c) 1996-2006, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  $PostgreSQL: pgsql/src/pl/plpgsql/src/gram.y,v 1.95.2.2 2009/02/02 20:25:50 tgl Exp $
 *
 *-------------------------------------------------------------------------
 */

#include "plpgsql.h"

#include "parser/parser.h"


static PLpgSQL_expr		*read_sql_construct(int until,
											int until2,
											const char *expected,
											const char *sqlstart,
											bool isexpression,
											bool valid_sql,
											int *endtoken);
static	PLpgSQL_expr	*read_sql_stmt(const char *sqlstart);
static	PLpgSQL_type	*read_datatype(int tok);
static	PLpgSQL_stmt	*make_execsql_stmt(const char *sqlstart, int lineno);
static	PLpgSQL_stmt	*make_fetch_stmt(int lineno, int curvar);
static	PLpgSQL_stmt	*make_return_stmt(int lineno);
static	PLpgSQL_stmt	*make_return_next_stmt(int lineno);
static	void			 check_assignable(PLpgSQL_datum *datum);
static	void			 read_into_target(PLpgSQL_rec **rec, PLpgSQL_row **row,
										  bool *strict);
static	PLpgSQL_row		*read_into_scalar_list(const char *initial_name,
											   PLpgSQL_datum *initial_datum);
static PLpgSQL_row		*make_scalar_list1(const char *initial_name,
										   PLpgSQL_datum *initial_datum,
										   int lineno);
static	void			 check_sql_expr(const char *stmt);
static	void			 plpgsql_sql_error_callback(void *arg);
static	void			 check_labels(const char *start_label,
									  const char *end_label);



/* Line 189 of yacc.c  */
#line 131 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     K_ALIAS = 258,
     K_ASSIGN = 259,
     K_BEGIN = 260,
     K_BY = 261,
     K_CLOSE = 262,
     K_CONSTANT = 263,
     K_CONTINUE = 264,
     K_CURSOR = 265,
     K_DEBUG = 266,
     K_DECLARE = 267,
     K_DEFAULT = 268,
     K_DIAGNOSTICS = 269,
     K_DOTDOT = 270,
     K_ELSE = 271,
     K_ELSIF = 272,
     K_END = 273,
     K_EXCEPTION = 274,
     K_EXECUTE = 275,
     K_EXIT = 276,
     K_FOR = 277,
     K_FETCH = 278,
     K_FROM = 279,
     K_GET = 280,
     K_IF = 281,
     K_IN = 282,
     K_INFO = 283,
     K_INSERT = 284,
     K_INTO = 285,
     K_IS = 286,
     K_LOG = 287,
     K_LOOP = 288,
     K_NEXT = 289,
     K_NOT = 290,
     K_NOTICE = 291,
     K_NULL = 292,
     K_OPEN = 293,
     K_OR = 294,
     K_PERFORM = 295,
     K_ROW_COUNT = 296,
     K_RAISE = 297,
     K_RENAME = 298,
     K_RESULT_OID = 299,
     K_RETURN = 300,
     K_REVERSE = 301,
     K_STRICT = 302,
     K_THEN = 303,
     K_TO = 304,
     K_TYPE = 305,
     K_WARNING = 306,
     K_WHEN = 307,
     K_WHILE = 308,
     T_FUNCTION = 309,
     T_TRIGGER = 310,
     T_STRING = 311,
     T_NUMBER = 312,
     T_SCALAR = 313,
     T_ROW = 314,
     T_RECORD = 315,
     T_DTYPE = 316,
     T_LABEL = 317,
     T_WORD = 318,
     T_ERROR = 319,
     O_OPTION = 320,
     O_DUMP = 321
   };
#endif
/* Tokens.  */
#define K_ALIAS 258
#define K_ASSIGN 259
#define K_BEGIN 260
#define K_BY 261
#define K_CLOSE 262
#define K_CONSTANT 263
#define K_CONTINUE 264
#define K_CURSOR 265
#define K_DEBUG 266
#define K_DECLARE 267
#define K_DEFAULT 268
#define K_DIAGNOSTICS 269
#define K_DOTDOT 270
#define K_ELSE 271
#define K_ELSIF 272
#define K_END 273
#define K_EXCEPTION 274
#define K_EXECUTE 275
#define K_EXIT 276
#define K_FOR 277
#define K_FETCH 278
#define K_FROM 279
#define K_GET 280
#define K_IF 281
#define K_IN 282
#define K_INFO 283
#define K_INSERT 284
#define K_INTO 285
#define K_IS 286
#define K_LOG 287
#define K_LOOP 288
#define K_NEXT 289
#define K_NOT 290
#define K_NOTICE 291
#define K_NULL 292
#define K_OPEN 293
#define K_OR 294
#define K_PERFORM 295
#define K_ROW_COUNT 296
#define K_RAISE 297
#define K_RENAME 298
#define K_RESULT_OID 299
#define K_RETURN 300
#define K_REVERSE 301
#define K_STRICT 302
#define K_THEN 303
#define K_TO 304
#define K_TYPE 305
#define K_WARNING 306
#define K_WHEN 307
#define K_WHILE 308
#define T_FUNCTION 309
#define T_TRIGGER 310
#define T_STRING 311
#define T_NUMBER 312
#define T_SCALAR 313
#define T_ROW 314
#define T_RECORD 315
#define T_DTYPE 316
#define T_LABEL 317
#define T_WORD 318
#define T_ERROR 319
#define O_OPTION 320
#define O_DUMP 321




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 52 "gram.y"

		int32					ival;
		bool					boolean;
		char					*str;
		struct
		{
			char *name;
			int  lineno;
		}						varname;
		struct
		{
			char *name;
			int  lineno;
			PLpgSQL_datum   *scalar;
			PLpgSQL_rec     *rec;
			PLpgSQL_row     *row;
		}						forvariable;
		struct
		{
			char *label;
			int  n_initvars;
			int  *initvarnos;
		}						declhdr;
		struct
		{
			char *end_label;
			List *stmts;
		}						loop_body;
		List					*list;
		PLpgSQL_type			*dtype;
		PLpgSQL_datum			*scalar;	/* a VAR, RECFIELD, or TRIGARG */
		PLpgSQL_variable		*variable;	/* a VAR, REC, or ROW */
		PLpgSQL_var				*var;
		PLpgSQL_row				*row;
		PLpgSQL_rec				*rec;
		PLpgSQL_expr			*expr;
		PLpgSQL_stmt			*stmt;
		PLpgSQL_stmt_block		*program;
		PLpgSQL_condition		*condition;
		PLpgSQL_exception		*exception;
		PLpgSQL_exception_block	*exception_block;
		PLpgSQL_nsitem			*nsitem;
		PLpgSQL_diag_item		*diagitem;



/* Line 214 of yacc.c  */
#line 346 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 358 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   344

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      70,    71,     2,     2,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    67,
      68,     2,    69,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    13,    14,    16,    19,    21,    24,
      25,    27,    35,    37,    40,    44,    46,    49,    51,    57,
      59,    61,    67,    73,    79,    80,    87,    88,    89,    93,
      95,    99,   102,   104,   106,   108,   110,   112,   113,   115,
     116,   117,   120,   122,   124,   126,   128,   129,   131,   134,
     136,   139,   141,   143,   145,   147,   149,   151,   153,   155,
     157,   159,   161,   163,   165,   167,   169,   171,   175,   180,
     186,   190,   192,   196,   198,   200,   202,   204,   206,   208,
     212,   221,   222,   228,   231,   236,   242,   247,   251,   253,
     255,   257,   259,   264,   266,   268,   271,   276,   278,   280,
     282,   284,   286,   288,   290,   296,   299,   301,   303,   305,
     308,   312,   317,   322,   325,   327,   329,   330,   331,   336,
     339,   341,   347,   351,   353,   354,   355,   356,   357,   358,
     364,   365,   367,   369,   371,   374,   376
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      75,     0,    -1,    54,    76,    80,    79,    -1,    55,    76,
      80,    79,    -1,    -1,    77,    -1,    77,    78,    -1,    78,
      -1,    65,    66,    -1,    -1,    67,    -1,    81,     5,   147,
     100,   134,    18,   144,    -1,   143,    -1,   143,    82,    -1,
     143,    82,    83,    -1,    12,    -1,    83,    84,    -1,    84,
      -1,    68,    68,   146,    69,    69,    -1,    12,    -1,    85,
      -1,    93,    95,    96,    97,    98,    -1,    93,     3,    22,
      92,    67,    -1,    43,    94,    49,    94,    67,    -1,    -1,
      93,    10,    86,    88,    91,    87,    -1,    -1,    -1,    70,
      89,    71,    -1,    90,    -1,    89,    72,    90,    -1,    93,
      96,    -1,    31,    -1,    22,    -1,    63,    -1,    63,    -1,
      63,    -1,    -1,     8,    -1,    -1,    -1,    35,    37,    -1,
      67,    -1,    99,    -1,     4,    -1,    13,    -1,    -1,   101,
      -1,   101,   102,    -1,   102,    -1,    80,    67,    -1,   104,
      -1,   111,    -1,   113,    -1,   114,    -1,   115,    -1,   118,
      -1,   120,    -1,   121,    -1,   125,    -1,   127,    -1,   103,
      -1,   105,    -1,   128,    -1,   129,    -1,   130,    -1,   131,
      -1,    40,   147,   139,    -1,   110,   147,     4,   139,    -1,
      25,    14,   147,   106,    67,    -1,   106,    72,   107,    -1,
     107,    -1,   109,     4,   108,    -1,    41,    -1,    44,    -1,
      58,    -1,    58,    -1,    59,    -1,    60,    -1,   110,    73,
     140,    -1,    26,   147,   141,   100,   112,    18,    26,    67,
      -1,    -1,    17,   147,   141,   100,   112,    -1,    16,   100,
      -1,   143,    33,   147,   124,    -1,   143,    53,   147,   142,
     124,    -1,   143,    22,   116,   124,    -1,   147,   117,    27,
      -1,    58,    -1,    63,    -1,    60,    -1,    59,    -1,   119,
     147,   144,   145,    -1,    21,    -1,     9,    -1,    45,   147,
      -1,    42,   147,   123,   122,    -1,    56,    -1,    19,    -1,
      51,    -1,    36,    -1,    28,    -1,    32,    -1,    11,    -1,
     100,    18,    33,   144,    67,    -1,   126,   147,    -1,    29,
      -1,    63,    -1,    64,    -1,    20,   147,    -1,    38,   147,
     132,    -1,    23,   147,   133,    30,    -1,     7,   147,   133,
      67,    -1,    37,    67,    -1,    58,    -1,    58,    -1,    -1,
      -1,    19,   147,   135,   136,    -1,   136,   137,    -1,   137,
      -1,    52,   147,   138,    48,   100,    -1,   138,    39,   146,
      -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,    68,    68,
     146,    69,    69,    -1,    -1,    62,    -1,    63,    -1,    67,
      -1,    52,   139,    -1,    63,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   219,   219,   223,   229,   230,   233,   234,   237,   243,
     244,   247,   269,   276,   283,   295,   304,   306,   310,   312,
     314,   318,   352,   357,   362,   361,   412,   424,   427,   456,
     460,   466,   473,   474,   476,   504,   514,   525,   526,   531,
     542,   543,   547,   549,   557,   558,   562,   565,   569,   576,
     585,   587,   589,   591,   593,   595,   597,   599,   601,   603,
     605,   607,   609,   611,   613,   615,   617,   621,   634,   648,
     661,   665,   671,   683,   687,   693,   701,   706,   711,   716,
     731,   747,   750,   779,   785,   802,   820,   859,  1074,  1089,
    1110,  1118,  1128,  1143,  1147,  1153,  1170,  1213,  1219,  1223,
    1227,  1231,  1235,  1239,  1245,  1252,  1259,  1261,  1263,  1267,
    1300,  1417,  1423,  1436,  1443,  1460,  1478,  1480,  1479,  1512,
    1516,  1522,  1535,  1545,  1552,  1556,  1560,  1564,  1568,  1572,
    1580,  1583,  1589,  1596,  1598,  1602,  1612
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "K_ALIAS", "K_ASSIGN", "K_BEGIN", "K_BY",
  "K_CLOSE", "K_CONSTANT", "K_CONTINUE", "K_CURSOR", "K_DEBUG",
  "K_DECLARE", "K_DEFAULT", "K_DIAGNOSTICS", "K_DOTDOT", "K_ELSE",
  "K_ELSIF", "K_END", "K_EXCEPTION", "K_EXECUTE", "K_EXIT", "K_FOR",
  "K_FETCH", "K_FROM", "K_GET", "K_IF", "K_IN", "K_INFO", "K_INSERT",
  "K_INTO", "K_IS", "K_LOG", "K_LOOP", "K_NEXT", "K_NOT", "K_NOTICE",
  "K_NULL", "K_OPEN", "K_OR", "K_PERFORM", "K_ROW_COUNT", "K_RAISE",
  "K_RENAME", "K_RESULT_OID", "K_RETURN", "K_REVERSE", "K_STRICT",
  "K_THEN", "K_TO", "K_TYPE", "K_WARNING", "K_WHEN", "K_WHILE",
  "T_FUNCTION", "T_TRIGGER", "T_STRING", "T_NUMBER", "T_SCALAR", "T_ROW",
  "T_RECORD", "T_DTYPE", "T_LABEL", "T_WORD", "T_ERROR", "O_OPTION",
  "O_DUMP", "';'", "'<'", "'>'", "'('", "')'", "','", "'['", "$accept",
  "pl_function", "comp_optsect", "comp_options", "comp_option", "opt_semi",
  "pl_block", "decl_sect", "decl_start", "decl_stmts", "decl_stmt",
  "decl_statement", "$@1", "decl_cursor_query", "decl_cursor_args",
  "decl_cursor_arglist", "decl_cursor_arg", "decl_is_from",
  "decl_aliasitem", "decl_varname", "decl_renname", "decl_const",
  "decl_datatype", "decl_notnull", "decl_defval", "decl_defkey",
  "proc_sect", "proc_stmts", "proc_stmt", "stmt_perform", "stmt_assign",
  "stmt_getdiag", "getdiag_list", "getdiag_list_item", "getdiag_kind",
  "getdiag_target", "assign_var", "stmt_if", "stmt_else", "stmt_loop",
  "stmt_while", "stmt_for", "for_control", "for_variable", "stmt_exit",
  "exit_type", "stmt_return", "stmt_raise", "raise_msg", "raise_level",
  "loop_body", "stmt_execsql", "execsql_start", "stmt_dynexecute",
  "stmt_open", "stmt_fetch", "stmt_close", "stmt_null", "cursor_varptr",
  "cursor_variable", "exception_sect", "@2", "proc_exceptions",
  "proc_exception", "proc_conditions", "expr_until_semi",
  "expr_until_rightbracket", "expr_until_then", "expr_until_loop",
  "opt_block_label", "opt_label", "opt_exitcond", "opt_lblname", "lno", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    59,    60,    62,
      40,    41,    44,    91
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    77,    77,    78,    79,
      79,    80,    81,    81,    81,    82,    83,    83,    84,    84,
      84,    85,    85,    85,    86,    85,    87,    88,    88,    89,
      89,    90,    91,    91,    92,    93,    94,    95,    95,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   103,   104,   105,
     106,   106,   107,   108,   108,   109,   110,   110,   110,   110,
     111,   112,   112,   112,   113,   114,   115,   116,   117,   117,
     117,   117,   118,   119,   119,   120,   121,   122,   123,   123,
     123,   123,   123,   123,   124,   125,   126,   126,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   134,   136,
     136,   137,   138,   138,   139,   140,   141,   142,   143,   143,
     144,   144,   144,   145,   145,   146,   147
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     4,     0,     1,     2,     1,     2,     0,
       1,     7,     1,     2,     3,     1,     2,     1,     5,     1,
       1,     5,     5,     5,     0,     6,     0,     0,     3,     1,
       3,     2,     1,     1,     1,     1,     1,     0,     1,     0,
       0,     2,     1,     1,     1,     1,     0,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     5,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       8,     0,     5,     2,     4,     5,     4,     3,     1,     1,
       1,     1,     4,     1,     1,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     5,     2,     1,     1,     1,     2,
       3,     4,     4,     2,     1,     1,     0,     0,     4,     2,
       1,     5,     3,     1,     0,     0,     0,     0,     0,     5,
       0,     1,     1,     1,     2,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     4,     0,     0,   128,     5,     7,   128,     1,
       8,     0,     9,     0,    12,     6,     9,     0,    10,     2,
     136,    15,    13,     3,   135,     0,   128,    19,     0,    35,
       0,    14,    17,    20,    37,     0,   136,    94,   136,    93,
     136,     0,   136,   106,     0,   136,   136,   136,   136,    76,
      77,    78,   107,   108,     0,   116,    47,    49,    61,    51,
      62,   136,    52,    53,    54,    55,    56,   136,    57,    58,
      59,   136,    60,    63,    64,    65,    66,    12,    36,     0,
       0,    16,     0,    38,    24,    39,   129,     0,   109,     0,
     136,   126,   113,     0,   124,     0,    95,    50,   136,     0,
      48,   125,     0,   130,   105,   136,   136,   136,     0,     0,
       0,    27,    40,   115,     0,     0,     0,   128,   114,   110,
      67,   103,    98,   101,   102,   100,    99,     0,   117,   130,
      79,   124,   131,   132,     0,   128,     0,   128,   127,     0,
       0,    34,     0,     0,     0,     0,     0,   112,   111,    75,
       0,    71,     0,    81,    97,    96,     0,    11,    68,   124,
     133,    92,     0,    86,    88,    91,    90,    89,     0,    84,
     128,    23,    18,    22,     0,    29,    39,    33,    32,    26,
      41,    44,    45,    42,    21,    43,    69,     0,     0,   128,
     136,     0,   136,   118,   120,   134,     0,    87,    85,    28,
       0,    31,    25,    70,    73,    74,    72,    83,   126,     0,
       0,   119,   130,    30,   128,     0,     0,   123,     0,    81,
      80,     0,   128,   104,    82,   122,   121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     5,     6,     7,    19,    54,    13,    22,    31,
      32,    33,   111,   202,   144,   174,   175,   179,   142,    34,
      79,    85,   112,   146,   184,   185,   162,    56,    57,    58,
      59,    60,   150,   151,   206,   152,    61,    62,   191,    63,
      64,    65,   135,   168,    66,    67,    68,    69,   155,   127,
     163,    70,    71,    72,    73,    74,    75,    76,   119,   114,
      99,   156,   193,   194,   216,   120,   130,   117,   170,    77,
     134,   161,    25,    26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -135
static const yytype_int16 yypact[] =
{
      -2,   -57,   -57,    35,   -22,   -19,   -57,  -135,   -19,  -135,
    -135,   -14,   -16,    59,    67,  -135,   -16,     5,  -135,  -135,
    -135,  -135,    17,  -135,  -135,    21,   160,  -135,    23,  -135,
      25,    17,  -135,  -135,    30,    39,  -135,  -135,  -135,  -135,
    -135,    91,  -135,  -135,    47,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,    48,    97,    36,  -135,  -135,  -135,
    -135,    37,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,    -6,  -135,    68,
       5,  -135,    99,  -135,  -135,  -135,  -135,    66,  -135,    66,
    -135,  -135,  -135,    71,  -135,    56,  -135,  -135,  -135,   108,
    -135,  -135,   126,    20,  -135,  -135,  -135,  -135,    23,    64,
      72,    75,   101,  -135,    70,   104,    80,   102,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,    85,  -135,    20,
    -135,  -135,  -135,  -135,   -37,   276,    43,   276,  -135,    79,
      82,  -135,    83,    86,    -3,   111,    10,  -135,  -135,  -135,
     -47,  -135,   148,    81,  -135,  -135,   106,  -135,  -135,  -135,
    -135,  -135,   135,  -135,  -135,  -135,  -135,  -135,   127,  -135,
     276,  -135,  -135,  -135,    41,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,    80,   -20,   276,
    -135,   138,  -135,   106,  -135,  -135,   131,  -135,  -135,  -135,
      86,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,   133,
       5,  -135,    20,  -135,   102,   105,   -17,  -135,   107,    81,
    -135,     5,   218,  -135,  -135,  -135,  -135
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   166,  -135,   165,   157,    29,  -135,  -135,  -135,
     144,  -135,  -135,  -135,  -135,  -135,   -24,  -135,  -135,  -134,
      69,  -135,     6,  -135,  -135,  -135,   -26,  -135,   128,  -135,
    -135,  -135,  -135,     0,  -135,  -135,  -135,  -135,   -29,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -120,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,   103,
    -135,  -135,  -135,     1,  -135,  -113,  -135,   -15,  -135,    34,
    -125,  -135,   -78,   -35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -129
static const yytype_int16 yytable[] =
{
      55,    87,   109,    88,   157,    89,    21,    91,     4,   176,
      93,    94,    95,    96,   181,   159,   105,   169,   158,   177,
     186,   204,   221,   182,   205,   187,   102,   106,   178,    27,
     160,   222,   103,    82,    12,     9,   104,    16,    83,    14,
      84,  -128,    14,    36,    10,    37,   195,   107,  -128,    11,
     198,    18,     1,     2,    17,   116,    38,    39,  -128,    40,
      28,    41,    42,   128,    20,    43,   176,   121,    24,  -128,
     136,   137,   138,    44,    45,   122,    46,   183,    47,    21,
      29,    48,   132,   133,   123,    30,    78,   218,   124,  -128,
      35,   153,   125,    80,    49,    50,    51,   189,   190,    52,
      53,   164,   165,   166,    11,    90,   167,   126,    86,    36,
     101,    37,   199,   200,    92,    97,    98,   108,   -46,   -46,
     -46,   110,    38,    39,   113,    40,   129,    41,    42,   118,
     131,    43,   217,   140,   148,   141,   145,   147,   149,    44,
      45,   154,    46,   225,    47,   143,   171,    48,   180,    29,
     173,   172,   188,   196,   197,   208,   209,   210,   192,   215,
      49,    50,    51,   207,   212,    52,    53,    36,     8,    37,
      11,    15,   220,    23,   223,    81,   213,   139,   -46,   -46,
      38,    39,   201,    40,   100,    41,    42,   203,   219,    43,
     224,     0,   115,   214,   211,     0,   226,    44,    45,     0,
      46,     0,    47,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    50,
      51,     0,     0,    52,    53,    36,     0,    37,    11,     0,
       0,     0,     0,     0,     0,     0,   -46,     0,    38,    39,
       0,    40,     0,    41,    42,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,    44,    45,     0,    46,     0,
      47,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     -46,     0,     0,     0,     0,     0,    49,    50,    51,     0,
       0,    52,    53,    36,     0,    37,    11,     0,     0,     0,
       0,     0,     0,     0,   -46,     0,    38,    39,     0,    40,
       0,    41,    42,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,    46,     0,    47,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    50,    51,     0,     0,    52,
      53,     0,     0,     0,    11
};

static const yytype_int16 yycheck[] =
{
      26,    36,    80,    38,   129,    40,    12,    42,    65,   143,
      45,    46,    47,    48,     4,    52,    22,   137,   131,    22,
      67,    41,    39,    13,    44,    72,    61,    33,    31,    12,
      67,    48,    67,     3,     5,     0,    71,     8,     8,     5,
      10,     5,     8,     7,    66,     9,   159,    53,    12,    68,
     170,    67,    54,    55,    68,    90,    20,    21,    22,    23,
      43,    25,    26,    98,     5,    29,   200,    11,    63,    33,
     105,   106,   107,    37,    38,    19,    40,    67,    42,    12,
      63,    45,    62,    63,    28,    68,    63,   212,    32,    53,
      69,   117,    36,    68,    58,    59,    60,    16,    17,    63,
      64,    58,    59,    60,    68,    14,    63,    51,    69,     7,
      73,     9,    71,    72,    67,    67,    19,    49,    16,    17,
      18,    22,    20,    21,    58,    23,    18,    25,    26,    58,
       4,    29,   210,    69,    30,    63,    35,    67,    58,    37,
      38,    56,    40,   221,    42,    70,    67,    45,    37,    63,
      67,    69,     4,    18,    27,   190,    18,   192,    52,    26,
      58,    59,    60,   189,    33,    63,    64,     7,     2,     9,
      68,     6,    67,    16,    67,    31,   200,   108,    18,    19,
      20,    21,   176,    23,    56,    25,    26,   187,   214,    29,
     219,    -1,    89,   208,   193,    -1,   222,    37,    38,    -1,
      40,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    -1,    -1,    63,    64,     7,    -1,     9,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,
      -1,    23,    -1,    25,    26,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    -1,
      42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    -1,
      -1,    63,    64,     7,    -1,     9,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    -1,    23,
      -1,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    -1,    -1,    63,
      64,    -1,    -1,    -1,    68
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,    55,    75,    65,    76,    77,    78,    76,     0,
      66,    68,    80,    81,   143,    78,    80,    68,    67,    79,
       5,    12,    82,    79,    63,   146,   147,    12,    43,    63,
      68,    83,    84,    85,    93,    69,     7,     9,    20,    21,
      23,    25,    26,    29,    37,    38,    40,    42,    45,    58,
      59,    60,    63,    64,    80,   100,   101,   102,   103,   104,
     105,   110,   111,   113,   114,   115,   118,   119,   120,   121,
     125,   126,   127,   128,   129,   130,   131,   143,    63,    94,
      68,    84,     3,     8,    10,    95,    69,   147,   147,   147,
      14,   147,    67,   147,   147,   147,   147,    67,    19,   134,
     102,    73,   147,   147,   147,    22,    33,    53,    49,   146,
      22,    86,    96,    58,   133,   133,   147,   141,    58,   132,
     139,    11,    19,    28,    32,    36,    51,   123,   147,    18,
     140,     4,    62,    63,   144,   116,   147,   147,   147,    94,
      69,    63,    92,    70,    88,    35,    97,    67,    30,    58,
     106,   107,   109,   100,    56,   122,   135,   144,   139,    52,
      67,   145,   100,   124,    58,    59,    60,    63,   117,   124,
     142,    67,    69,    67,    89,    90,    93,    22,    31,    91,
      37,     4,    13,    67,    98,    99,    67,    72,     4,    16,
      17,   112,    52,   136,   137,   139,    18,    27,   124,    71,
      72,    96,    87,   107,    41,    44,   108,   100,   147,    18,
     147,   137,    33,    90,   141,    26,   138,   146,   144,   100,
      67,    39,    48,    67,   112,   146,   100
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 220 "gram.y"
    {
						yylval.program = (PLpgSQL_stmt_block *)(yyvsp[(3) - (4)].stmt);
					}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 224 "gram.y"
    {
						yylval.program = (PLpgSQL_stmt_block *)(yyvsp[(3) - (4)].stmt);
					}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 238 "gram.y"
    {
						plpgsql_DumpExecTree = true;
					}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 248 "gram.y"
    {
						PLpgSQL_stmt_block *new;

						new = palloc0(sizeof(PLpgSQL_stmt_block));

						new->cmd_type	= PLPGSQL_STMT_BLOCK;
						new->lineno		= (yyvsp[(3) - (7)].ival);
						new->label		= (yyvsp[(1) - (7)].declhdr).label;
						new->n_initvars = (yyvsp[(1) - (7)].declhdr).n_initvars;
						new->initvarnos = (yyvsp[(1) - (7)].declhdr).initvarnos;
						new->body		= (yyvsp[(4) - (7)].list);
						new->exceptions	= (yyvsp[(5) - (7)].exception_block);

						check_labels((yyvsp[(1) - (7)].declhdr).label, (yyvsp[(7) - (7)].str));
						plpgsql_ns_pop();

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 270 "gram.y"
    {
						plpgsql_ns_setlocal(false);
						(yyval.declhdr).label	  = (yyvsp[(1) - (1)].str);
						(yyval.declhdr).n_initvars = 0;
						(yyval.declhdr).initvarnos = NULL;
					}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 277 "gram.y"
    {
						plpgsql_ns_setlocal(false);
						(yyval.declhdr).label	  = (yyvsp[(1) - (2)].str);
						(yyval.declhdr).n_initvars = 0;
						(yyval.declhdr).initvarnos = NULL;
					}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 284 "gram.y"
    {
						plpgsql_ns_setlocal(false);
						if ((yyvsp[(3) - (3)].str) != NULL)
							(yyval.declhdr).label = (yyvsp[(3) - (3)].str);
						else
							(yyval.declhdr).label = (yyvsp[(1) - (3)].str);
						/* Remember variables declared in decl_stmts */
						(yyval.declhdr).n_initvars = plpgsql_add_initdatums(&((yyval.declhdr).initvarnos));
					}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 296 "gram.y"
    {
						/* Forget any variables created before block */
						plpgsql_add_initdatums(NULL);
						/* Make variable names be local to block */
						plpgsql_ns_setlocal(true);
					}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 305 "gram.y"
    {	(yyval.str) = (yyvsp[(2) - (2)].str);	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 307 "gram.y"
    {	(yyval.str) = (yyvsp[(1) - (1)].str);	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 311 "gram.y"
    {	(yyval.str) = (yyvsp[(3) - (5)].str);	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 313 "gram.y"
    {	(yyval.str) = NULL;	}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 315 "gram.y"
    {	(yyval.str) = NULL;	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 319 "gram.y"
    {
						PLpgSQL_variable	*var;

						var = plpgsql_build_variable((yyvsp[(1) - (5)].varname).name, (yyvsp[(1) - (5)].varname).lineno,
													 (yyvsp[(3) - (5)].dtype), true);
						if ((yyvsp[(2) - (5)].boolean))
						{
							if (var->dtype == PLPGSQL_DTYPE_VAR)
								((PLpgSQL_var *) var)->isconst = (yyvsp[(2) - (5)].boolean);
							else
								ereport(ERROR,
										(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
										 errmsg("row or record variable cannot be CONSTANT")));
						}
						if ((yyvsp[(4) - (5)].boolean))
						{
							if (var->dtype == PLPGSQL_DTYPE_VAR)
								((PLpgSQL_var *) var)->notnull = (yyvsp[(4) - (5)].boolean);
							else
								ereport(ERROR,
										(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
										 errmsg("row or record variable cannot be NOT NULL")));
						}
						if ((yyvsp[(5) - (5)].expr) != NULL)
						{
							if (var->dtype == PLPGSQL_DTYPE_VAR)
								((PLpgSQL_var *) var)->default_val = (yyvsp[(5) - (5)].expr);
							else
								ereport(ERROR,
										(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
										 errmsg("default value for row or record variable is not supported")));
						}
					}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 353 "gram.y"
    {
						plpgsql_ns_additem((yyvsp[(4) - (5)].nsitem)->itemtype,
										   (yyvsp[(4) - (5)].nsitem)->itemno, (yyvsp[(1) - (5)].varname).name);
					}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 358 "gram.y"
    {
						plpgsql_ns_rename((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str));
					}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 362 "gram.y"
    { plpgsql_ns_push(NULL); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 364 "gram.y"
    {
						PLpgSQL_var *new;
						PLpgSQL_expr *curname_def;
						char		buf[1024];
						char		*cp1;
						char		*cp2;

						/* pop local namespace for cursor args */
						plpgsql_ns_pop();

						new = (PLpgSQL_var *)
							plpgsql_build_variable((yyvsp[(1) - (6)].varname).name, (yyvsp[(1) - (6)].varname).lineno,
												   plpgsql_build_datatype(REFCURSOROID,
																		  -1),
												   true);

						curname_def = palloc0(sizeof(PLpgSQL_expr));

						curname_def->dtype = PLPGSQL_DTYPE_EXPR;
						strcpy(buf, "SELECT ");
						cp1 = new->refname;
						cp2 = buf + strlen(buf);
						/*
						 * Don't trust standard_conforming_strings here;
						 * it might change before we use the string.
						 */
						if (strchr(cp1, '\\') != NULL)
							*cp2++ = ESCAPE_STRING_SYNTAX;
						*cp2++ = '\'';
						while (*cp1)
						{
							if (SQL_STR_DOUBLE(*cp1, true))
								*cp2++ = *cp1;
							*cp2++ = *cp1++;
						}
						strcpy(cp2, "'::refcursor");
						curname_def->query = pstrdup(buf);
						new->default_val = curname_def;

						new->cursor_explicit_expr = (yyvsp[(6) - (6)].expr);
						if ((yyvsp[(4) - (6)].row) == NULL)
							new->cursor_explicit_argrow = -1;
						else
							new->cursor_explicit_argrow = (yyvsp[(4) - (6)].row)->rowno;
					}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 412 "gram.y"
    {
						PLpgSQL_expr *query;

						plpgsql_ns_setlocal(false);
						query = read_sql_stmt("");
						plpgsql_ns_setlocal(true);

						(yyval.expr) = query;
					}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 424 "gram.y"
    {
						(yyval.row) = NULL;
					}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 428 "gram.y"
    {
						PLpgSQL_row *new;
						int i;
						ListCell *l;

						new = palloc0(sizeof(PLpgSQL_row));
						new->dtype = PLPGSQL_DTYPE_ROW;
						new->lineno = plpgsql_scanner_lineno();
						new->rowtupdesc = NULL;
						new->nfields = list_length((yyvsp[(2) - (3)].list));
						new->fieldnames = palloc(new->nfields * sizeof(char *));
						new->varnos = palloc(new->nfields * sizeof(int));

						i = 0;
						foreach (l, (yyvsp[(2) - (3)].list))
						{
							PLpgSQL_variable *arg = (PLpgSQL_variable *) lfirst(l);
							new->fieldnames[i] = arg->refname;
							new->varnos[i] = arg->dno;
							i++;
						}
						list_free((yyvsp[(2) - (3)].list));

						plpgsql_adddatum((PLpgSQL_datum *) new);
						(yyval.row) = new;
					}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 457 "gram.y"
    {
						(yyval.list) = list_make1((yyvsp[(1) - (1)].variable));
					}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 461 "gram.y"
    {
						(yyval.list) = lappend((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].variable));
					}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 467 "gram.y"
    {
						(yyval.variable) = plpgsql_build_variable((yyvsp[(1) - (2)].varname).name, (yyvsp[(1) - (2)].varname).lineno,
													(yyvsp[(2) - (2)].dtype), true);
					}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 477 "gram.y"
    {
						char	*name;
						PLpgSQL_nsitem *nsi;

						plpgsql_convert_ident(yytext, &name, 1);
						if (name[0] != '$')
							yyerror("only positional parameters may be aliased");

						plpgsql_ns_setlocal(false);
						nsi = plpgsql_ns_lookup(name, NULL);
						if (nsi == NULL)
						{
							plpgsql_error_lineno = plpgsql_scanner_lineno();
							ereport(ERROR,
									(errcode(ERRCODE_UNDEFINED_PARAMETER),
									 errmsg("function has no parameter \"%s\"",
											name)));
						}

						plpgsql_ns_setlocal(true);

						pfree(name);

						(yyval.nsitem) = nsi;
					}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 505 "gram.y"
    {
						char	*name;

						plpgsql_convert_ident(yytext, &name, 1);
						(yyval.varname).name = name;
						(yyval.varname).lineno  = plpgsql_scanner_lineno();
					}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 515 "gram.y"
    {
						char	*name;

						plpgsql_convert_ident(yytext, &name, 1);
						/* the result must be palloc'd, see plpgsql_ns_rename */
						(yyval.str) = name;
					}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 525 "gram.y"
    { (yyval.boolean) = false; }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 527 "gram.y"
    { (yyval.boolean) = true; }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 531 "gram.y"
    {
						/*
						 * If there's a lookahead token, read_datatype
						 * should consume it.
						 */
						(yyval.dtype) = read_datatype(yychar);
						yyclearin;
					}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 542 "gram.y"
    { (yyval.boolean) = false; }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 544 "gram.y"
    { (yyval.boolean) = true; }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 548 "gram.y"
    { (yyval.expr) = NULL; }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 550 "gram.y"
    {
						plpgsql_ns_setlocal(false);
						(yyval.expr) = plpgsql_read_expression(';', ";");
						plpgsql_ns_setlocal(true);
					}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 562 "gram.y"
    {
						(yyval.list) = NIL;
					}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 566 "gram.y"
    { (yyval.list) = (yyvsp[(1) - (1)].list); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 570 "gram.y"
    {
							if ((yyvsp[(2) - (2)].stmt) == NULL)
								(yyval.list) = (yyvsp[(1) - (2)].list);
							else
								(yyval.list) = lappend((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].stmt));
						}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 577 "gram.y"
    {
							if ((yyvsp[(1) - (1)].stmt) == NULL)
								(yyval.list) = NULL;
							else
								(yyval.list) = list_make1((yyvsp[(1) - (1)].stmt));
						}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 586 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (2)].stmt); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 588 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 590 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 592 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 594 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 596 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 598 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 600 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 602 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 604 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 606 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 608 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 610 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 612 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 614 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 616 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 618 "gram.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 622 "gram.y"
    {
						PLpgSQL_stmt_perform *new;

						new = palloc0(sizeof(PLpgSQL_stmt_perform));
						new->cmd_type = PLPGSQL_STMT_PERFORM;
						new->lineno   = (yyvsp[(2) - (3)].ival);
						new->expr  = (yyvsp[(3) - (3)].expr);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 635 "gram.y"
    {
						PLpgSQL_stmt_assign *new;

						new = palloc0(sizeof(PLpgSQL_stmt_assign));
						new->cmd_type = PLPGSQL_STMT_ASSIGN;
						new->lineno   = (yyvsp[(2) - (4)].ival);
						new->varno = (yyvsp[(1) - (4)].ival);
						new->expr  = (yyvsp[(4) - (4)].expr);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 649 "gram.y"
    {
						PLpgSQL_stmt_getdiag	 *new;

						new = palloc0(sizeof(PLpgSQL_stmt_getdiag));
						new->cmd_type = PLPGSQL_STMT_GETDIAG;
						new->lineno   = (yyvsp[(3) - (5)].ival);
						new->diag_items  = (yyvsp[(4) - (5)].list);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 662 "gram.y"
    {
						(yyval.list) = lappend((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].diagitem));
					}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 666 "gram.y"
    {
						(yyval.list) = list_make1((yyvsp[(1) - (1)].diagitem));
					}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 672 "gram.y"
    {
						PLpgSQL_diag_item *new;

						new = palloc(sizeof(PLpgSQL_diag_item));
						new->target = (yyvsp[(1) - (3)].ival);
						new->kind = (yyvsp[(3) - (3)].ival);

						(yyval.diagitem) = new;
					}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 684 "gram.y"
    {
						(yyval.ival) = PLPGSQL_GETDIAG_ROW_COUNT;
					}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 688 "gram.y"
    {
						(yyval.ival) = PLPGSQL_GETDIAG_RESULT_OID;
					}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 694 "gram.y"
    {
						check_assignable(yylval.scalar);
						(yyval.ival) = yylval.scalar->dno;
					}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 702 "gram.y"
    {
						check_assignable(yylval.scalar);
						(yyval.ival) = yylval.scalar->dno;
					}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 707 "gram.y"
    {
						check_assignable((PLpgSQL_datum *) yylval.row);
						(yyval.ival) = yylval.row->rowno;
					}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 712 "gram.y"
    {
						check_assignable((PLpgSQL_datum *) yylval.rec);
						(yyval.ival) = yylval.rec->recno;
					}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 717 "gram.y"
    {
						PLpgSQL_arrayelem	*new;

						new = palloc0(sizeof(PLpgSQL_arrayelem));
						new->dtype		= PLPGSQL_DTYPE_ARRAYELEM;
						new->subscript	= (yyvsp[(3) - (3)].expr);
						new->arrayparentno = (yyvsp[(1) - (3)].ival);

						plpgsql_adddatum((PLpgSQL_datum *)new);

						(yyval.ival) = new->dno;
					}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 732 "gram.y"
    {
						PLpgSQL_stmt_if *new;

						new = palloc0(sizeof(PLpgSQL_stmt_if));
						new->cmd_type	= PLPGSQL_STMT_IF;
						new->lineno		= (yyvsp[(2) - (8)].ival);
						new->cond		= (yyvsp[(3) - (8)].expr);
						new->true_body	= (yyvsp[(4) - (8)].list);
						new->false_body = (yyvsp[(5) - (8)].list);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 747 "gram.y"
    {
						(yyval.list) = NIL;
					}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 751 "gram.y"
    {
						/*
						 * Translate the structure:	   into:
						 *
						 * IF c1 THEN				   IF c1 THEN
						 *	 ...						   ...
						 * ELSIF c2 THEN			   ELSE
						 *								   IF c2 THEN
						 *	 ...							   ...
						 * ELSE							   ELSE
						 *	 ...							   ...
						 * END IF						   END IF
						 *							   END IF
						 */
						PLpgSQL_stmt_if *new_if;

						/* first create a new if-statement */
						new_if = palloc0(sizeof(PLpgSQL_stmt_if));
						new_if->cmd_type	= PLPGSQL_STMT_IF;
						new_if->lineno		= (yyvsp[(2) - (5)].ival);
						new_if->cond		= (yyvsp[(3) - (5)].expr);
						new_if->true_body	= (yyvsp[(4) - (5)].list);
						new_if->false_body	= (yyvsp[(5) - (5)].list);

						/* wrap the if-statement in a "container" list */
						(yyval.list) = list_make1(new_if);
					}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 780 "gram.y"
    {
						(yyval.list) = (yyvsp[(2) - (2)].list);
					}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 786 "gram.y"
    {
						PLpgSQL_stmt_loop *new;

						new = palloc0(sizeof(PLpgSQL_stmt_loop));
						new->cmd_type = PLPGSQL_STMT_LOOP;
						new->lineno   = (yyvsp[(3) - (4)].ival);
						new->label	  = (yyvsp[(1) - (4)].str);
						new->body	  = (yyvsp[(4) - (4)].loop_body).stmts;

						check_labels((yyvsp[(1) - (4)].str), (yyvsp[(4) - (4)].loop_body).end_label);
						plpgsql_ns_pop();

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 803 "gram.y"
    {
						PLpgSQL_stmt_while *new;

						new = palloc0(sizeof(PLpgSQL_stmt_while));
						new->cmd_type = PLPGSQL_STMT_WHILE;
						new->lineno   = (yyvsp[(3) - (5)].ival);
						new->label	  = (yyvsp[(1) - (5)].str);
						new->cond	  = (yyvsp[(4) - (5)].expr);
						new->body	  = (yyvsp[(5) - (5)].loop_body).stmts;

						check_labels((yyvsp[(1) - (5)].str), (yyvsp[(5) - (5)].loop_body).end_label);
						plpgsql_ns_pop();

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 821 "gram.y"
    {
						/* This runs after we've scanned the loop body */
						if ((yyvsp[(3) - (4)].stmt)->cmd_type == PLPGSQL_STMT_FORI)
						{
							PLpgSQL_stmt_fori		*new;

							new = (PLpgSQL_stmt_fori *) (yyvsp[(3) - (4)].stmt);
							new->label	  = (yyvsp[(1) - (4)].str);
							new->body	  = (yyvsp[(4) - (4)].loop_body).stmts;
							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else if ((yyvsp[(3) - (4)].stmt)->cmd_type == PLPGSQL_STMT_FORS)
						{
							PLpgSQL_stmt_fors		*new;

							new = (PLpgSQL_stmt_fors *) (yyvsp[(3) - (4)].stmt);
							new->label	  = (yyvsp[(1) - (4)].str);
							new->body	  = (yyvsp[(4) - (4)].loop_body).stmts;
							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else
						{
							PLpgSQL_stmt_dynfors	*new;

							Assert((yyvsp[(3) - (4)].stmt)->cmd_type == PLPGSQL_STMT_DYNFORS);
							new = (PLpgSQL_stmt_dynfors *) (yyvsp[(3) - (4)].stmt);
							new->label	  = (yyvsp[(1) - (4)].str);
							new->body	  = (yyvsp[(4) - (4)].loop_body).stmts;
							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}

						check_labels((yyvsp[(1) - (4)].str), (yyvsp[(4) - (4)].loop_body).end_label);
						/* close namespace started in opt_label */
						plpgsql_ns_pop();
					}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 860 "gram.y"
    {
						int			tok = yylex();

						/* Simple case: EXECUTE is a dynamic FOR loop */
						if (tok == K_EXECUTE)
						{
							PLpgSQL_stmt_dynfors	*new;
							PLpgSQL_expr			*expr;

							expr = plpgsql_read_expression(K_LOOP, "LOOP");

							new = palloc0(sizeof(PLpgSQL_stmt_dynfors));
							new->cmd_type = PLPGSQL_STMT_DYNFORS;
							new->lineno   = (yyvsp[(1) - (3)].ival);
							if ((yyvsp[(2) - (3)].forvariable).rec)
							{
								new->rec = (yyvsp[(2) - (3)].forvariable).rec;
								check_assignable((PLpgSQL_datum *) new->rec);
							}
							else if ((yyvsp[(2) - (3)].forvariable).row)
							{
								new->row = (yyvsp[(2) - (3)].forvariable).row;
								check_assignable((PLpgSQL_datum *) new->row);
							}
							else if ((yyvsp[(2) - (3)].forvariable).scalar)
							{
								/* convert single scalar to list */
								new->row = make_scalar_list1((yyvsp[(2) - (3)].forvariable).name, (yyvsp[(2) - (3)].forvariable).scalar, (yyvsp[(2) - (3)].forvariable).lineno);
								/* no need for check_assignable */
							}
							else
							{
								plpgsql_error_lineno = (yyvsp[(2) - (3)].forvariable).lineno;
								yyerror("loop variable of loop over rows must be a record or row variable or list of scalar variables");
							}
							new->query = expr;

							(yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else
						{
							PLpgSQL_expr	*expr1;
							bool			 reverse = false;

							/*
							 * We have to distinguish between two
							 * alternatives: FOR var IN a .. b and FOR
							 * var IN query. Unfortunately this is
							 * tricky, since the query in the second
							 * form needn't start with a SELECT
							 * keyword.  We use the ugly hack of
							 * looking for two periods after the first
							 * token. We also check for the REVERSE
							 * keyword, which means it must be an
							 * integer loop.
							 */
							if (tok == K_REVERSE)
								reverse = true;
							else
								plpgsql_push_back_token(tok);

							/*
							 * Read tokens until we see either a ".."
							 * or a LOOP. The text we read may not
							 * necessarily be a well-formed SQL
							 * statement, so we need to invoke
							 * read_sql_construct directly.
							 */
							expr1 = read_sql_construct(K_DOTDOT,
													   K_LOOP,
													   "LOOP",
													   "SELECT ",
													   true,
													   false,
													   &tok);

							if (tok == K_DOTDOT)
							{
								/* Saw "..", so it must be an integer loop */
								PLpgSQL_expr		*expr2;
								PLpgSQL_expr		*expr_by;
								PLpgSQL_var			*fvar;
								PLpgSQL_stmt_fori	*new;
								char				*varname;

								/* First expression is well-formed */
								check_sql_expr(expr1->query);


								expr2 = read_sql_construct(K_BY,
														   K_LOOP,
														   "LOOP",
														   "SELECT ",
														   true,
														   false,
														   &tok);

								if (tok == K_BY) 
									expr_by = plpgsql_read_expression(K_LOOP, "LOOP");
								else
								{
									/*
									 * If there is no BY clause we will assume 1
									 */
									char buf[1024];
									PLpgSQL_dstring		ds;

									plpgsql_dstring_init(&ds);

									expr_by = palloc0(sizeof(PLpgSQL_expr));
									expr_by->dtype      		= PLPGSQL_DTYPE_EXPR;
									strcpy(buf, "SELECT 1");
									plpgsql_dstring_append(&ds, buf);
									expr_by->query			    = pstrdup(plpgsql_dstring_get(&ds));
									expr_by->plan				= NULL;
								}

								/* should have had a single variable name */
								plpgsql_error_lineno = (yyvsp[(2) - (3)].forvariable).lineno;
								if ((yyvsp[(2) - (3)].forvariable).scalar && (yyvsp[(2) - (3)].forvariable).row)
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("integer FOR loop must have just one target variable")));

								/* create loop's private variable */
								plpgsql_convert_ident((yyvsp[(2) - (3)].forvariable).name, &varname, 1);
								fvar = (PLpgSQL_var *)
									plpgsql_build_variable(varname,
														   (yyvsp[(2) - (3)].forvariable).lineno,
														   plpgsql_build_datatype(INT4OID,
																				  -1),
														   true);

								new = palloc0(sizeof(PLpgSQL_stmt_fori));
								new->cmd_type = PLPGSQL_STMT_FORI;
								new->lineno   = (yyvsp[(1) - (3)].ival);
								new->var	  = fvar;
								new->reverse  = reverse;
								new->lower	  = expr1;
								new->upper	  = expr2;
								new->by		  = expr_by;

								(yyval.stmt) = (PLpgSQL_stmt *) new;
							}
							else
							{
								/*
								 * No "..", so it must be a query loop. We've prefixed an
								 * extra SELECT to the query text, so we need to remove that
								 * before performing syntax checking.
								 */
								char				*tmp_query;
								PLpgSQL_stmt_fors	*new;

								if (reverse)
									yyerror("cannot specify REVERSE in query FOR loop");

								Assert(strncmp(expr1->query, "SELECT ", 7) == 0);
								tmp_query = pstrdup(expr1->query + 7);
								pfree(expr1->query);
								expr1->query = tmp_query;

								check_sql_expr(expr1->query);

								new = palloc0(sizeof(PLpgSQL_stmt_fors));
								new->cmd_type = PLPGSQL_STMT_FORS;
								new->lineno   = (yyvsp[(1) - (3)].ival);
								if ((yyvsp[(2) - (3)].forvariable).rec)
								{
									new->rec = (yyvsp[(2) - (3)].forvariable).rec;
									check_assignable((PLpgSQL_datum *) new->rec);
								}
								else if ((yyvsp[(2) - (3)].forvariable).row)
								{
									new->row = (yyvsp[(2) - (3)].forvariable).row;
									check_assignable((PLpgSQL_datum *) new->row);
								}
								else if ((yyvsp[(2) - (3)].forvariable).scalar)
								{
									/* convert single scalar to list */
									new->row = make_scalar_list1((yyvsp[(2) - (3)].forvariable).name, (yyvsp[(2) - (3)].forvariable).scalar, (yyvsp[(2) - (3)].forvariable).lineno);
									/* no need for check_assignable */
								}
								else
								{
									plpgsql_error_lineno = (yyvsp[(2) - (3)].forvariable).lineno;
									yyerror("loop variable of loop over rows must be a record or row variable or list of scalar variables");
								}

								new->query = expr1;
								(yyval.stmt) = (PLpgSQL_stmt *) new;
							}
						}
					}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1075 "gram.y"
    {
						int			tok;

						(yyval.forvariable).name = pstrdup(yytext);
						(yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(yyval.forvariable).scalar = yylval.scalar;
						(yyval.forvariable).rec = NULL;
						(yyval.forvariable).row = NULL;
						/* check for comma-separated list */
						tok = yylex();
						plpgsql_push_back_token(tok);
						if (tok == ',')
							(yyval.forvariable).row = read_into_scalar_list((yyval.forvariable).name, (yyval.forvariable).scalar);
					}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1090 "gram.y"
    {
						int			tok;

						(yyval.forvariable).name = pstrdup(yytext);
						(yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(yyval.forvariable).scalar = NULL;
						(yyval.forvariable).rec = NULL;
						(yyval.forvariable).row = NULL;
						/* check for comma-separated list */
						tok = yylex();
						plpgsql_push_back_token(tok);
						if (tok == ',')
						{
							plpgsql_error_lineno = (yyval.forvariable).lineno;
							ereport(ERROR,
									(errcode(ERRCODE_SYNTAX_ERROR),
									 errmsg("\"%s\" is not a scalar variable",
											(yyval.forvariable).name)));
						}
					}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1111 "gram.y"
    {
						(yyval.forvariable).name = pstrdup(yytext);
						(yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(yyval.forvariable).scalar = NULL;
						(yyval.forvariable).rec = yylval.rec;
						(yyval.forvariable).row = NULL;
					}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1119 "gram.y"
    {
						(yyval.forvariable).name = pstrdup(yytext);
						(yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(yyval.forvariable).scalar = NULL;
						(yyval.forvariable).row = yylval.row;
						(yyval.forvariable).rec = NULL;
					}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1129 "gram.y"
    {
						PLpgSQL_stmt_exit *new;

						new = palloc0(sizeof(PLpgSQL_stmt_exit));
						new->cmd_type = PLPGSQL_STMT_EXIT;
						new->is_exit  = (yyvsp[(1) - (4)].boolean);
						new->lineno	  = (yyvsp[(2) - (4)].ival);
						new->label	  = (yyvsp[(3) - (4)].str);
						new->cond	  = (yyvsp[(4) - (4)].expr);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1144 "gram.y"
    {
						(yyval.boolean) = true;
					}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1148 "gram.y"
    {
						(yyval.boolean) = false;
					}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1154 "gram.y"
    {
						int	tok;

						tok = yylex();
						if (tok == K_NEXT)
						{
							(yyval.stmt) = make_return_next_stmt((yyvsp[(2) - (2)].ival));
						}
						else
						{
							plpgsql_push_back_token(tok);
							(yyval.stmt) = make_return_stmt((yyvsp[(2) - (2)].ival));
						}
					}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1171 "gram.y"
    {
						PLpgSQL_stmt_raise		*new;
						int	tok;

						new = palloc(sizeof(PLpgSQL_stmt_raise));

						new->cmd_type	= PLPGSQL_STMT_RAISE;
						new->lineno		= (yyvsp[(2) - (4)].ival);
						new->elog_level = (yyvsp[(3) - (4)].ival);
						new->message	= (yyvsp[(4) - (4)].str);
						new->params		= NIL;

						tok = yylex();

						/*
						 * We expect either a semi-colon, which
						 * indicates no parameters, or a comma that
						 * begins the list of parameter expressions
						 */
						if (tok != ',' && tok != ';')
							yyerror("syntax error");

						if (tok == ',')
						{
							PLpgSQL_expr *expr;
							int term;

							for (;;)
							{
								expr = read_sql_construct(',', ';', ", or ;",
														  "SELECT ",
														  true, true, &term);
								new->params = lappend(new->params, expr);
								if (term == ';')
									break;
							}
						}

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1214 "gram.y"
    {
						(yyval.str) = plpgsql_get_string_value();
					}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1220 "gram.y"
    {
						(yyval.ival) = ERROR;
					}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1224 "gram.y"
    {
						(yyval.ival) = WARNING;
					}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1228 "gram.y"
    {
						(yyval.ival) = NOTICE;
					}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1232 "gram.y"
    {
						(yyval.ival) = INFO;
					}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1236 "gram.y"
    {
						(yyval.ival) = LOG;
					}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1240 "gram.y"
    {
						(yyval.ival) = DEBUG1;
					}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1246 "gram.y"
    {
						(yyval.loop_body).stmts = (yyvsp[(1) - (5)].list);
						(yyval.loop_body).end_label = (yyvsp[(4) - (5)].str);
					}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1253 "gram.y"
    {
						(yyval.stmt) = make_execsql_stmt((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].ival));
					}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1260 "gram.y"
    { (yyval.str) = pstrdup(yytext); }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1262 "gram.y"
    { (yyval.str) = pstrdup(yytext); }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1264 "gram.y"
    { (yyval.str) = pstrdup(yytext); }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1268 "gram.y"
    {
						PLpgSQL_stmt_dynexecute *new;
						PLpgSQL_expr *expr;
						int endtoken;

						expr = read_sql_construct(K_INTO, ';', "INTO|;",
												  "SELECT ",
												  true, true, &endtoken);

						new = palloc(sizeof(PLpgSQL_stmt_dynexecute));
						new->cmd_type = PLPGSQL_STMT_DYNEXECUTE;
						new->lineno = (yyvsp[(2) - (2)].ival);
						new->query = expr;
						new->into = false;
						new->strict = false;
						new->rec = NULL;
						new->row = NULL;

						/* If we found "INTO", collect the argument */
						if (endtoken == K_INTO)
						{
							new->into = true;
							read_into_target(&new->rec, &new->row, &new->strict);
							if (yylex() != ';')
								yyerror("syntax error");
						}

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1301 "gram.y"
    {
						PLpgSQL_stmt_open *new;
						int				  tok;

						new = palloc0(sizeof(PLpgSQL_stmt_open));
						new->cmd_type = PLPGSQL_STMT_OPEN;
						new->lineno = (yyvsp[(2) - (3)].ival);
						new->curvar = (yyvsp[(3) - (3)].var)->varno;

						if ((yyvsp[(3) - (3)].var)->cursor_explicit_expr == NULL)
						{
						    tok = yylex();
							if (tok != K_FOR)
							{
								plpgsql_error_lineno = (yyvsp[(2) - (3)].ival);
								ereport(ERROR,
										(errcode(ERRCODE_SYNTAX_ERROR),
										 errmsg("syntax error at \"%s\"",
												yytext),
										 errdetail("Expected FOR to open a reference cursor.")));
							}

							tok = yylex();
							if (tok == K_EXECUTE)
							{
								new->dynquery = read_sql_stmt("SELECT ");
							}
							else
							{
								plpgsql_push_back_token(tok);
								new->query = read_sql_stmt("");
							}
						}
						else
						{
							if ((yyvsp[(3) - (3)].var)->cursor_explicit_argrow >= 0)
							{
								char   *cp;

								tok = yylex();
								if (tok != '(')
								{
									plpgsql_error_lineno = plpgsql_scanner_lineno();
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("cursor \"%s\" has arguments",
													(yyvsp[(3) - (3)].var)->refname)));
								}

								/*
								 * Push back the '(', else read_sql_stmt
								 * will complain about unbalanced parens.
								 */
								plpgsql_push_back_token(tok);

								new->argquery = read_sql_stmt("SELECT ");

								/*
								 * Now remove the leading and trailing parens,
								 * because we want "select 1, 2", not
								 * "select (1, 2)".
								 */
								cp = new->argquery->query;

								if (strncmp(cp, "SELECT", 6) != 0)
								{
									plpgsql_error_lineno = plpgsql_scanner_lineno();
									/* internal error */
									elog(ERROR, "expected \"SELECT (\", got \"%s\"",
										 new->argquery->query);
								}
								cp += 6;
								while (*cp == ' ') /* could be more than 1 space here */
									cp++;
								if (*cp != '(')
								{
									plpgsql_error_lineno = plpgsql_scanner_lineno();
									/* internal error */
									elog(ERROR, "expected \"SELECT (\", got \"%s\"",
										 new->argquery->query);
								}
								*cp = ' ';

								cp += strlen(cp) - 1;

								if (*cp != ')')
									yyerror("expected \")\"");
								*cp = '\0';
							}
							else
							{
								tok = yylex();
								if (tok == '(')
								{
									plpgsql_error_lineno = plpgsql_scanner_lineno();
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("cursor \"%s\" has no arguments",
													(yyvsp[(3) - (3)].var)->refname)));
								}

								if (tok != ';')
								{
									plpgsql_error_lineno = plpgsql_scanner_lineno();
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("syntax error at \"%s\"",
													yytext)));
								}
							}
						}

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1418 "gram.y"
    {
						(yyval.stmt) = make_fetch_stmt((yyvsp[(2) - (4)].ival), (yyvsp[(3) - (4)].ival));
					}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1424 "gram.y"
    {
						PLpgSQL_stmt_close *new;

						new = palloc(sizeof(PLpgSQL_stmt_close));
						new->cmd_type = PLPGSQL_STMT_CLOSE;
						new->lineno = (yyvsp[(2) - (4)].ival);
						new->curvar = (yyvsp[(3) - (4)].ival);

						(yyval.stmt) = (PLpgSQL_stmt *)new;
					}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1437 "gram.y"
    {
						/* We do not bother building a node for NULL */
						(yyval.stmt) = NULL;
					}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1444 "gram.y"
    {
						if (yylval.scalar->dtype != PLPGSQL_DTYPE_VAR)
							yyerror("cursor variable must be a simple variable");

						if (((PLpgSQL_var *) yylval.scalar)->datatype->typoid != REFCURSOROID)
						{
							plpgsql_error_lineno = plpgsql_scanner_lineno();
							ereport(ERROR,
									(errcode(ERRCODE_DATATYPE_MISMATCH),
									 errmsg("\"%s\" must be of type cursor or refcursor",
											((PLpgSQL_var *) yylval.scalar)->refname)));
						}
						(yyval.var) = (PLpgSQL_var *) yylval.scalar;
					}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1461 "gram.y"
    {
						if (yylval.scalar->dtype != PLPGSQL_DTYPE_VAR)
							yyerror("cursor variable must be a simple variable");

						if (((PLpgSQL_var *) yylval.scalar)->datatype->typoid != REFCURSOROID)
						{
							plpgsql_error_lineno = plpgsql_scanner_lineno();
							ereport(ERROR,
									(errcode(ERRCODE_DATATYPE_MISMATCH),
									 errmsg("\"%s\" must be of type refcursor",
											((PLpgSQL_var *) yylval.scalar)->refname)));
						}
						(yyval.ival) = yylval.scalar->dno;
					}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1478 "gram.y"
    { (yyval.exception_block) = NULL; }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1480 "gram.y"
    {
						/*
						 * We use a mid-rule action to add these
						 * special variables to the namespace before
						 * parsing the WHEN clauses themselves.
						 */
						PLpgSQL_exception_block *new = palloc(sizeof(PLpgSQL_exception_block));
						PLpgSQL_variable *var;

						var = plpgsql_build_variable("sqlstate", (yyvsp[(2) - (2)].ival),
													 plpgsql_build_datatype(TEXTOID, -1),
													 true);
						((PLpgSQL_var *) var)->isconst = true;
						new->sqlstate_varno = var->dno;

						var = plpgsql_build_variable("sqlerrm", (yyvsp[(2) - (2)].ival),
													 plpgsql_build_datatype(TEXTOID, -1),
													 true);
						((PLpgSQL_var *) var)->isconst = true;
						new->sqlerrm_varno = var->dno;

						(yyval.exception_block) = new;
					}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1504 "gram.y"
    {
						PLpgSQL_exception_block *new = (yyvsp[(3) - (4)].exception_block);
						new->exc_list = (yyvsp[(4) - (4)].list);

						(yyval.exception_block) = new;
					}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1513 "gram.y"
    {
							(yyval.list) = lappend((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].exception));
						}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1517 "gram.y"
    {
							(yyval.list) = list_make1((yyvsp[(1) - (1)].exception));
						}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1523 "gram.y"
    {
						PLpgSQL_exception *new;

						new = palloc0(sizeof(PLpgSQL_exception));
						new->lineno     = (yyvsp[(2) - (5)].ival);
						new->conditions = (yyvsp[(3) - (5)].condition);
						new->action	    = (yyvsp[(5) - (5)].list);

						(yyval.exception) = new;
					}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1536 "gram.y"
    {
							PLpgSQL_condition	*old;

							for (old = (yyvsp[(1) - (3)].condition); old->next != NULL; old = old->next)
								/* skip */ ;
							old->next = plpgsql_parse_err_condition((yyvsp[(3) - (3)].str));

							(yyval.condition) = (yyvsp[(1) - (3)].condition);
						}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1546 "gram.y"
    {
							(yyval.condition) = plpgsql_parse_err_condition((yyvsp[(1) - (1)].str));
						}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1552 "gram.y"
    { (yyval.expr) = plpgsql_read_expression(';', ";"); }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1556 "gram.y"
    { (yyval.expr) = plpgsql_read_expression(']', "]"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1560 "gram.y"
    { (yyval.expr) = plpgsql_read_expression(K_THEN, "THEN"); }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1564 "gram.y"
    { (yyval.expr) = plpgsql_read_expression(K_LOOP, "LOOP"); }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1568 "gram.y"
    {
						plpgsql_ns_push(NULL);
						(yyval.str) = NULL;
					}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1573 "gram.y"
    {
						plpgsql_ns_push((yyvsp[(3) - (5)].str));
						(yyval.str) = (yyvsp[(3) - (5)].str);
					}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1580 "gram.y"
    {
						(yyval.str) = NULL;
					}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1584 "gram.y"
    {
						char *label_name;
						plpgsql_convert_ident(yytext, &label_name, 1);
						(yyval.str) = label_name;
					}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1590 "gram.y"
    {
						/* just to give a better error than "syntax error" */
						yyerror("no such label");
					}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1597 "gram.y"
    { (yyval.expr) = NULL; }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1599 "gram.y"
    { (yyval.expr) = (yyvsp[(2) - (2)].expr); }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1603 "gram.y"
    {
						char	*name;

						plpgsql_convert_ident(yytext, &name, 1);
						(yyval.str) = name;
					}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1612 "gram.y"
    {
						(yyval.ival) = plpgsql_error_lineno = plpgsql_scanner_lineno();
					}
    break;



/* Line 1455 of yacc.c  */
#line 3661 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1617 "gram.y"



#define MAX_EXPR_PARAMS  1024

/*
 * determine the expression parameter position to use for a plpgsql datum
 *
 * It is important that any given plpgsql datum map to just one parameter.
 * We used to be sloppy and assign a separate parameter for each occurrence
 * of a datum reference, but that fails for situations such as "select DATUM
 * from ... group by DATUM".
 *
 * The params[] array must be of size MAX_EXPR_PARAMS.
 */
static int
assign_expr_param(int dno, int *params, int *nparams)
{
	int		i;

	/* already have an instance of this dno? */
	for (i = 0; i < *nparams; i++)
	{
		if (params[i] == dno)
			return i+1;
	}
	/* check for array overflow */
	if (*nparams >= MAX_EXPR_PARAMS)
	{
		plpgsql_error_lineno = plpgsql_scanner_lineno();
		ereport(ERROR,
				(errcode(ERRCODE_PROGRAM_LIMIT_EXCEEDED),
				 errmsg("too many variables specified in SQL statement")));
	}
	/* add new parameter dno to array */
	params[*nparams] = dno;
	(*nparams)++;
	return *nparams;
}


PLpgSQL_expr *
plpgsql_read_expression(int until, const char *expected)
{
	return read_sql_construct(until, 0, expected, "SELECT ", true, true, NULL);
}

static PLpgSQL_expr *
read_sql_stmt(const char *sqlstart)
{
	return read_sql_construct(';', 0, ";", sqlstart, false, true, NULL);
}

/*
 * Read a SQL construct and build a PLpgSQL_expr for it.
 *
 * until:		token code for expected terminator
 * until2:		token code for alternate terminator (pass 0 if none)
 * expected:	text to use in complaining that terminator was not found
 * sqlstart:	text to prefix to the accumulated SQL text
 * isexpression: whether to say we're reading an "expression" or a "statement"
 * valid_sql:   whether to check the syntax of the expr (prefixed with sqlstart)
 * endtoken:	if not NULL, ending token is stored at *endtoken
 *				(this is only interesting if until2 isn't zero)
 */
static PLpgSQL_expr *
read_sql_construct(int until,
				   int until2,
				   const char *expected,
				   const char *sqlstart,
				   bool isexpression,
				   bool valid_sql,
				   int *endtoken)
{
	int					tok;
	int					lno;
	PLpgSQL_dstring		ds;
	int					parenlevel = 0;
	int					nparams = 0;
	int					params[MAX_EXPR_PARAMS];
	char				buf[32];
	PLpgSQL_expr		*expr;

	lno = plpgsql_scanner_lineno();
	plpgsql_dstring_init(&ds);
	plpgsql_dstring_append(&ds, sqlstart);

	for (;;)
	{
		tok = yylex();
		if (tok == until && parenlevel == 0)
			break;
		if (tok == until2 && parenlevel == 0)
			break;
		if (tok == '(' || tok == '[')
			parenlevel++;
		else if (tok == ')' || tok == ']')
		{
			parenlevel--;
			if (parenlevel < 0)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("mismatched parentheses")));
		}
		/*
		 * End of function definition is an error, and we don't expect to
		 * hit a semicolon either (unless it's the until symbol, in which
		 * case we should have fallen out above).
		 */
		if (tok == 0 || tok == ';')
		{
			plpgsql_error_lineno = lno;
			if (parenlevel != 0)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("mismatched parentheses")));
			if (isexpression)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("missing \"%s\" at end of SQL expression",
								expected)));
			else
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("missing \"%s\" at end of SQL statement",
								expected)));
		}

		if (plpgsql_SpaceScanned)
			plpgsql_dstring_append(&ds, " ");

		switch (tok)
		{
			case T_SCALAR:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.scalar->dno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_ROW:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.row->rowno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_RECORD:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.rec->recno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			default:
				plpgsql_dstring_append(&ds, yytext);
				break;
		}
	}

	if (endtoken)
		*endtoken = tok;

	expr = palloc(sizeof(PLpgSQL_expr) + sizeof(int) * nparams - sizeof(int));
	expr->dtype			= PLPGSQL_DTYPE_EXPR;
	expr->query			= pstrdup(plpgsql_dstring_get(&ds));
	expr->plan			= NULL;
	expr->nparams		= nparams;
	while(nparams-- > 0)
		expr->params[nparams] = params[nparams];
	plpgsql_dstring_free(&ds);

	if (valid_sql)
		check_sql_expr(expr->query);

	return expr;
}

static PLpgSQL_type *
read_datatype(int tok)
{
	int					lno;
	PLpgSQL_dstring		ds;
	PLpgSQL_type		*result;
	bool				needspace = false;
	int					parenlevel = 0;

	lno = plpgsql_scanner_lineno();

	/* Often there will be a lookahead token, but if not, get one */
	if (tok == YYEMPTY)
		tok = yylex();

	if (tok == T_DTYPE)
	{
		/* lexer found word%TYPE and did its thing already */
		return yylval.dtype;
	}

	plpgsql_dstring_init(&ds);

	while (tok != ';')
	{
		if (tok == 0)
		{
			plpgsql_error_lineno = lno;
			if (parenlevel != 0)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("mismatched parentheses")));
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("incomplete datatype declaration")));
		}
		/* Possible followers for datatype in a declaration */
		if (tok == K_NOT || tok == K_ASSIGN || tok == K_DEFAULT)
			break;
		/* Possible followers for datatype in a cursor_arg list */
		if ((tok == ',' || tok == ')') && parenlevel == 0)
			break;
		if (tok == '(')
			parenlevel++;
		else if (tok == ')')
			parenlevel--;
		if (needspace)
			plpgsql_dstring_append(&ds, " ");
		needspace = true;
		plpgsql_dstring_append(&ds, yytext);

		tok = yylex();
	}

	plpgsql_push_back_token(tok);

	plpgsql_error_lineno = lno;	/* in case of error in parse_datatype */

	result = plpgsql_parse_datatype(plpgsql_dstring_get(&ds));

	plpgsql_dstring_free(&ds);

	return result;
}

static PLpgSQL_stmt *
make_execsql_stmt(const char *sqlstart, int lineno)
{
	PLpgSQL_dstring		ds;
	int					nparams = 0;
	int					params[MAX_EXPR_PARAMS];
	char				buf[32];
	PLpgSQL_stmt_execsql *execsql;
	PLpgSQL_expr		*expr;
	PLpgSQL_row			*row = NULL;
	PLpgSQL_rec			*rec = NULL;
	int					tok;
	int					prev_tok;
	bool				have_into = false;
	bool				have_strict = false;

	plpgsql_dstring_init(&ds);
	plpgsql_dstring_append(&ds, sqlstart);

	/*
	 * We have to special-case the sequence INSERT INTO, because we don't want
	 * that to be taken as an INTO-variables clause.  Fortunately, this is the
	 * only valid use of INTO in a pl/pgsql SQL command, and INTO is already a
	 * fully reserved word in the main grammar.  We have to treat it that way
	 * anywhere in the string, not only at the start; consider CREATE RULE
	 * containing an INSERT statement.
	 */
	if (pg_strcasecmp(sqlstart, "insert") == 0)
		tok = K_INSERT;
	else
		tok = 0;

	for (;;)
	{
		prev_tok = tok;
		tok = yylex();
		if (tok == ';')
			break;
		if (tok == 0)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("unexpected end of function definition")));
		}

		if (tok == K_INTO && prev_tok != K_INSERT)
		{
			if (have_into)
			{
				plpgsql_error_lineno = plpgsql_scanner_lineno();
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("INTO specified more than once")));
			}
			have_into = true;
			read_into_target(&rec, &row, &have_strict);
			continue;
		}

		if (plpgsql_SpaceScanned)
			plpgsql_dstring_append(&ds, " ");

		switch (tok)
		{
			case T_SCALAR:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.scalar->dno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_ROW:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.row->rowno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_RECORD:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(yylval.rec->recno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			default:
				plpgsql_dstring_append(&ds, yytext);
				break;
		}
	}

	expr = palloc(sizeof(PLpgSQL_expr) + sizeof(int) * nparams - sizeof(int));
	expr->dtype			= PLPGSQL_DTYPE_EXPR;
	expr->query			= pstrdup(plpgsql_dstring_get(&ds));
	expr->plan			= NULL;
	expr->nparams		= nparams;
	while(nparams-- > 0)
		expr->params[nparams] = params[nparams];
	plpgsql_dstring_free(&ds);

	check_sql_expr(expr->query);

	execsql = palloc(sizeof(PLpgSQL_stmt_execsql));
	execsql->cmd_type = PLPGSQL_STMT_EXECSQL;
	execsql->lineno  = lineno;
	execsql->sqlstmt = expr;
	execsql->into	 = have_into;
	execsql->strict	 = have_strict;
	execsql->rec	 = rec;
	execsql->row	 = row;

	return (PLpgSQL_stmt *) execsql;
}


static PLpgSQL_stmt *
make_fetch_stmt(int lineno, int curvar)
{
	int					tok;
	PLpgSQL_rec		   *rec;
	PLpgSQL_row		   *row;
	PLpgSQL_stmt_fetch *fetch;

	/* We have already parsed everything through the INTO keyword */
	read_into_target(&rec, &row, NULL);
	tok = yylex();
	if (tok != ';')
		yyerror("syntax error");

	fetch = palloc0(sizeof(PLpgSQL_stmt_fetch));
	fetch->cmd_type = PLPGSQL_STMT_FETCH;
	fetch->lineno	= lineno;
	fetch->rec		= rec;
	fetch->row		= row;
	fetch->curvar	= curvar;

	return (PLpgSQL_stmt *) fetch;
}


static PLpgSQL_stmt *
make_return_stmt(int lineno)
{
	PLpgSQL_stmt_return *new;

	new = palloc0(sizeof(PLpgSQL_stmt_return));
	new->cmd_type = PLPGSQL_STMT_RETURN;
	new->lineno   = lineno;
	new->expr	  = NULL;
	new->retvarno = -1;

	if (plpgsql_curr_compile->fn_retset)
	{
		if (yylex() != ';')
			yyerror("RETURN cannot have a parameter in function returning set; use RETURN NEXT");
	}
	else if (plpgsql_curr_compile->out_param_varno >= 0)
	{
		if (yylex() != ';')
			yyerror("RETURN cannot have a parameter in function with OUT parameters");
		new->retvarno = plpgsql_curr_compile->out_param_varno;
	}
	else if (plpgsql_curr_compile->fn_rettype == VOIDOID)
	{
		if (yylex() != ';')
			yyerror("RETURN cannot have a parameter in function returning void");
	}
	else if (plpgsql_curr_compile->fn_retistuple)
	{
		switch (yylex())
		{
			case K_NULL:
				/* we allow this to support RETURN NULL in triggers */
				break;

			case T_ROW:
				new->retvarno = yylval.row->rowno;
				break;

			case T_RECORD:
				new->retvarno = yylval.rec->recno;
				break;

			default:
				yyerror("RETURN must specify a record or row variable in function returning tuple");
				break;
		}
		if (yylex() != ';')
			yyerror("RETURN must specify a record or row variable in function returning tuple");
	}
	else
	{
		/*
		 * Note that a well-formed expression is
		 * _required_ here; anything else is a
		 * compile-time error.
		 */
		new->expr = plpgsql_read_expression(';', ";");
	}

	return (PLpgSQL_stmt *) new;
}


static PLpgSQL_stmt *
make_return_next_stmt(int lineno)
{
	PLpgSQL_stmt_return_next *new;

	if (!plpgsql_curr_compile->fn_retset)
		yyerror("cannot use RETURN NEXT in a non-SETOF function");

	new = palloc0(sizeof(PLpgSQL_stmt_return_next));
	new->cmd_type	= PLPGSQL_STMT_RETURN_NEXT;
	new->lineno		= lineno;
	new->expr		= NULL;
	new->retvarno	= -1;

	if (plpgsql_curr_compile->out_param_varno >= 0)
	{
		if (yylex() != ';')
			yyerror("RETURN NEXT cannot have a parameter in function with OUT parameters");
		new->retvarno = plpgsql_curr_compile->out_param_varno;
	}
	else if (plpgsql_curr_compile->fn_retistuple)
	{
		switch (yylex())
		{
			case T_ROW:
				new->retvarno = yylval.row->rowno;
				break;

			case T_RECORD:
				new->retvarno = yylval.rec->recno;
				break;

			default:
				yyerror("RETURN NEXT must specify a record or row variable in function returning tuple");
				break;
		}
		if (yylex() != ';')
			yyerror("RETURN NEXT must specify a record or row variable in function returning tuple");
	}
	else
		new->expr = plpgsql_read_expression(';', ";");

	return (PLpgSQL_stmt *) new;
}


static void
check_assignable(PLpgSQL_datum *datum)
{
	switch (datum->dtype)
	{
		case PLPGSQL_DTYPE_VAR:
			if (((PLpgSQL_var *) datum)->isconst)
			{
				plpgsql_error_lineno = plpgsql_scanner_lineno();
				ereport(ERROR,
						(errcode(ERRCODE_ERROR_IN_ASSIGNMENT),
						 errmsg("\"%s\" is declared CONSTANT",
								((PLpgSQL_var *) datum)->refname)));
			}
			break;
		case PLPGSQL_DTYPE_ROW:
			/* always assignable? */
			break;
		case PLPGSQL_DTYPE_REC:
			/* always assignable?  What about NEW/OLD? */
			break;
		case PLPGSQL_DTYPE_RECFIELD:
			/* always assignable? */
			break;
		case PLPGSQL_DTYPE_ARRAYELEM:
			/* always assignable? */
			break;
		case PLPGSQL_DTYPE_TRIGARG:
			yyerror("cannot assign to tg_argv");
			break;
		default:
			elog(ERROR, "unrecognized dtype: %d", datum->dtype);
			break;
	}
}

/*
 * Read the argument of an INTO clause.  On entry, we have just read the
 * INTO keyword.
 */
static void
read_into_target(PLpgSQL_rec **rec, PLpgSQL_row **row, bool *strict)
{
	int			tok;

	/* Set default results */
	*rec = NULL;
	*row = NULL;
	if (strict)
		*strict = false;

	tok = yylex();
	if (strict && tok == K_STRICT)
	{
		*strict = true;
		tok = yylex();
	}

	switch (tok)
	{
		case T_ROW:
			*row = yylval.row;
			check_assignable((PLpgSQL_datum *) *row);
			break;

		case T_RECORD:
			*rec = yylval.rec;
			check_assignable((PLpgSQL_datum *) *rec);
			break;

		case T_SCALAR:
			*row = read_into_scalar_list(yytext, yylval.scalar);
			break;

		default:
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("syntax error at \"%s\"", yytext),
					 errdetail("Expected record variable, row variable, "
							   "or list of scalar variables following INTO.")));
	}
}

/*
 * Given the first datum and name in the INTO list, continue to read
 * comma-separated scalar variables until we run out. Then construct
 * and return a fake "row" variable that represents the list of
 * scalars.
 */
static PLpgSQL_row *
read_into_scalar_list(const char *initial_name,
					  PLpgSQL_datum *initial_datum)
{
	int				 nfields;
	char			*fieldnames[1024];
	int				 varnos[1024];
	PLpgSQL_row		*row;
	int				 tok;

	check_assignable(initial_datum);
	fieldnames[0] = pstrdup(initial_name);
	varnos[0]	  = initial_datum->dno;
	nfields		  = 1;

	while ((tok = yylex()) == ',')
	{
		/* Check for array overflow */
		if (nfields >= 1024)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_PROGRAM_LIMIT_EXCEEDED),
					 errmsg("too many INTO variables specified")));
		}

		tok = yylex();
		switch(tok)
		{
			case T_SCALAR:
				check_assignable(yylval.scalar);
				fieldnames[nfields] = pstrdup(yytext);
				varnos[nfields++]	= yylval.scalar->dno;
				break;

			default:
				plpgsql_error_lineno = plpgsql_scanner_lineno();
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("\"%s\" is not a scalar variable",
								yytext)));
		}
	}

	/*
	 * We read an extra, non-comma token from yylex(), so push it
	 * back onto the input stream
	 */
	plpgsql_push_back_token(tok);

	row = palloc(sizeof(PLpgSQL_row));
	row->dtype = PLPGSQL_DTYPE_ROW;
	row->refname = pstrdup("*internal*");
	row->lineno = plpgsql_scanner_lineno();
	row->rowtupdesc = NULL;
	row->nfields = nfields;
	row->fieldnames = palloc(sizeof(char *) * nfields);
	row->varnos = palloc(sizeof(int) * nfields);
	while (--nfields >= 0)
	{
		row->fieldnames[nfields] = fieldnames[nfields];
		row->varnos[nfields] = varnos[nfields];
	}

	plpgsql_adddatum((PLpgSQL_datum *)row);

	return row;
}

/*
 * Convert a single scalar into a "row" list.  This is exactly
 * like read_into_scalar_list except we never consume any input.
 * In fact, since this can be invoked long after the source
 * input was actually read, the lineno has to be passed in.
 */
static PLpgSQL_row *
make_scalar_list1(const char *initial_name,
				  PLpgSQL_datum *initial_datum,
				  int lineno)
{
	PLpgSQL_row		*row;

	check_assignable(initial_datum);

	row = palloc(sizeof(PLpgSQL_row));
	row->dtype = PLPGSQL_DTYPE_ROW;
	row->refname = pstrdup("*internal*");
	row->lineno = lineno;
	row->rowtupdesc = NULL;
	row->nfields = 1;
	row->fieldnames = palloc(sizeof(char *));
	row->varnos = palloc(sizeof(int));
	row->fieldnames[0] = pstrdup(initial_name);
	row->varnos[0] = initial_datum->dno;

	plpgsql_adddatum((PLpgSQL_datum *)row);

	return row;
}

/*
 * When the PL/PgSQL parser expects to see a SQL statement, it is very
 * liberal in what it accepts; for example, we often assume an
 * unrecognized keyword is the beginning of a SQL statement. This
 * avoids the need to duplicate parts of the SQL grammar in the
 * PL/PgSQL grammar, but it means we can accept wildly malformed
 * input. To try and catch some of the more obviously invalid input,
 * we run the strings we expect to be SQL statements through the main
 * SQL parser.
 *
 * We only invoke the raw parser (not the analyzer); this doesn't do
 * any database access and does not check any semantic rules, it just
 * checks for basic syntactic correctness. We do this here, rather
 * than after parsing has finished, because a malformed SQL statement
 * may cause the PL/PgSQL parser to become confused about statement
 * borders. So it is best to bail out as early as we can.
 */
static void
check_sql_expr(const char *stmt)
{
	ErrorContextCallback  syntax_errcontext;
	ErrorContextCallback *previous_errcontext;
	MemoryContext oldCxt;

	if (!plpgsql_check_syntax)
		return;

	/*
	 * Setup error traceback support for ereport(). The previous
	 * ereport callback is installed by pl_comp.c, but we don't want
	 * that to be invoked (since it will try to transpose the syntax
	 * error to be relative to the CREATE FUNCTION), so temporarily
	 * remove it from the list of callbacks.
	 */
	Assert(error_context_stack->callback == plpgsql_compile_error_callback);

	previous_errcontext = error_context_stack;
	syntax_errcontext.callback = plpgsql_sql_error_callback;
	syntax_errcontext.arg = (char *) stmt;
	syntax_errcontext.previous = error_context_stack->previous;
	error_context_stack = &syntax_errcontext;

	oldCxt = MemoryContextSwitchTo(compile_tmp_cxt);
	(void) raw_parser(stmt);
	MemoryContextSwitchTo(oldCxt);

	/* Restore former ereport callback */
	error_context_stack = previous_errcontext;
}

static void
plpgsql_sql_error_callback(void *arg)
{
	char *sql_stmt = (char *) arg;

	Assert(plpgsql_error_funcname);

	errcontext("SQL statement in PL/PgSQL function \"%s\" near line %d",
			   plpgsql_error_funcname, plpgsql_error_lineno);
	internalerrquery(sql_stmt);
	internalerrposition(geterrposition());
	errposition(0);
}

static void
check_labels(const char *start_label, const char *end_label)
{
	if (end_label)
	{
		if (!start_label)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("end label \"%s\" specified for unlabelled block",
							end_label)));
		}

		if (strcmp(start_label, end_label) != 0)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("end label \"%s\" differs from block's label \"%s\"",
							end_label, start_label)));
		}
	}
}

/* Needed to avoid conflict between different prefix settings: */
#undef yylex

#include "pl_scan.c"

