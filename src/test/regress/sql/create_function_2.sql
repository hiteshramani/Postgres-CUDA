--
-- CREATE_FUNCTION_2
--
CREATE FUNCTION hobbies(person)
   RETURNS setof hobbies_r 
   AS 'select * from hobbies_r where person = $1.name'
   LANGUAGE SQL;


CREATE FUNCTION hobby_construct(text, text)
   RETURNS hobbies_r
   AS 'select $1 as name, $2 as hobby'
   LANGUAGE SQL;


CREATE FUNCTION hobbies_by_name(hobbies_r.name%TYPE)
   RETURNS hobbies_r.person%TYPE
   AS 'select person from hobbies_r where name = $1'
   LANGUAGE SQL;


CREATE FUNCTION equipment(hobbies_r)
   RETURNS setof equipment_r
   AS 'select * from equipment_r where hobby = $1.name'
   LANGUAGE SQL;


CREATE FUNCTION user_relns()
   RETURNS setof name
   AS 'select relname 
       from pg_class c, pg_namespace n
       where relnamespace = n.oid and
             (nspname !~ ''pg_.*'' and nspname <> ''information_schema'') and
             relkind <> ''i'' '
   LANGUAGE SQL;

CREATE FUNCTION pt_in_widget(point, widget)
   RETURNS bool
   AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
   LANGUAGE C;

CREATE FUNCTION overpaid(emp)
   RETURNS bool
   AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
   LANGUAGE C;

CREATE FUNCTION boxarea(box)
   RETURNS float8
   AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
   LANGUAGE C;

CREATE FUNCTION interpt_pp(path, path)
   RETURNS point
   AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
   LANGUAGE C;

CREATE FUNCTION reverse_name(name)
   RETURNS name
   AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
   LANGUAGE C;

CREATE FUNCTION oldstyle_length(int4, text)
   RETURNS int4
   AS '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so'
   LANGUAGE C;

--
-- Function dynamic loading
--
LOAD '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/regress.so';

