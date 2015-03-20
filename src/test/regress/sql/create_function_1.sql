--
-- CREATE_FUNCTION_1
--

CREATE FUNCTION widget_in(cstring)
   RETURNS widget
   AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
   LANGUAGE C STRICT;

CREATE FUNCTION widget_out(widget)
   RETURNS cstring
   AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
   LANGUAGE C STRICT;

CREATE FUNCTION int44in(cstring)
   RETURNS city_budget
   AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
   LANGUAGE C STRICT;

CREATE FUNCTION int44out(city_budget)
   RETURNS cstring
   AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
   LANGUAGE C STRICT;

CREATE FUNCTION check_primary_key ()
	RETURNS trigger
	AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/../../../contrib/spi/refint.so'
	LANGUAGE C;

CREATE FUNCTION check_foreign_key ()
	RETURNS trigger
	AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/../../../contrib/spi/refint.so'
	LANGUAGE C;

CREATE FUNCTION autoinc ()
	RETURNS trigger
	AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/../../../contrib/spi/autoinc.so'
	LANGUAGE C;

CREATE FUNCTION funny_dup17 ()
        RETURNS trigger
        AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
        LANGUAGE C;

CREATE FUNCTION ttdummy ()
        RETURNS trigger
        AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
        LANGUAGE C;

CREATE FUNCTION set_ttdummy (int4)
        RETURNS int4
        AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
        LANGUAGE C STRICT;

-- Things that shouldn't work:

CREATE FUNCTION test1 (int) RETURNS int LANGUAGE SQL
    AS 'SELECT ''not an integer'';';

CREATE FUNCTION test1 (int) RETURNS int LANGUAGE SQL
    AS 'not even SQL';

CREATE FUNCTION test1 (int) RETURNS int LANGUAGE SQL
    AS 'SELECT 1, 2, 3;';

CREATE FUNCTION test1 (int) RETURNS int LANGUAGE SQL
    AS 'SELECT $2;';

CREATE FUNCTION test1 (int) RETURNS int LANGUAGE SQL
    AS 'a', 'b';

CREATE FUNCTION test1 (int) RETURNS int LANGUAGE C
    AS 'nosuchfile';

CREATE FUNCTION test1 (int) RETURNS int LANGUAGE C
    AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so', 'nosuchsymbol';

CREATE FUNCTION test1 (int) RETURNS int LANGUAGE internal
    AS 'nosuch';
