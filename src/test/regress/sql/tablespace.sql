-- create a tablespace we can use
CREATE TABLESPACE testspace LOCATION '/home/hitesh/Desktop/Project/postgresql-8.2c.23/src/test/regress/testtablespace';

-- create a schema we can use
CREATE SCHEMA testschema;

-- try a table
CREATE TABLE testschema.foo (i int) TABLESPACE testspace;
SELECT relname, spcname FROM pg_catalog.pg_tablespace t, pg_catalog.pg_class c
    where c.reltablespace = t.oid AND c.relname = 'foo';

INSERT INTO testschema.foo VALUES(1);
INSERT INTO testschema.foo VALUES(2);

-- tables from dynamic sources
CREATE TABLE testschema.asselect TABLESPACE testspace AS SELECT 1;
SELECT relname, spcname FROM pg_catalog.pg_tablespace t, pg_catalog.pg_class c
    where c.reltablespace = t.oid AND c.relname = 'asselect';

PREPARE selectsource(int) AS SELECT $1;
CREATE TABLE testschema.asexecute TABLESPACE testspace
    AS EXECUTE selectsource(2);
SELECT relname, spcname FROM pg_catalog.pg_tablespace t, pg_catalog.pg_class c
    where c.reltablespace = t.oid AND c.relname = 'asexecute';

-- index
CREATE INDEX foo_idx on testschema.foo(i) TABLESPACE testspace;
SELECT relname, spcname FROM pg_catalog.pg_tablespace t, pg_catalog.pg_class c
    where c.reltablespace = t.oid AND c.relname = 'foo_idx';

-- Will fail with bad path
CREATE TABLESPACE badspace LOCATION '/no/such/location';

-- No such tablespace
CREATE TABLE bar (i int) TABLESPACE nosuchspace;

-- Fail, not empty
DROP TABLESPACE testspace;

DROP SCHEMA testschema CASCADE;

-- Should succeed
DROP TABLESPACE testspace;
