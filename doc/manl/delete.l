.\\" auto-generated by docbook2man-spec $Revision: 1.1.1.1 $
.TH "DELETE" "" "2011-12-01" "SQL - Language Statements" "SQL Commands"
.SH NAME
DELETE \- delete rows of a table

.SH SYNOPSIS
.sp
.nf
DELETE FROM [ ONLY ] \fItable\fR [ [ AS ] \fIalias\fR ]
    [ USING \fIusinglist\fR ]
    [ WHERE \fIcondition\fR ]
    [ RETURNING * | \fIoutput_expression\fR [ AS \fIoutput_name\fR ] [, ...] ]
.sp
.fi
.SH "DESCRIPTION"
.PP
\fBDELETE\fR deletes rows that satisfy the
WHERE clause from the specified table. If the
WHERE clause is absent, the effect is to delete
all rows in the table. The result is a valid, but empty table.
.sp
.RS
.B "Tip:"
TRUNCATE [\fBtruncate\fR(l)] is a
PostgreSQL extension that provides a
faster mechanism to remove all rows from a table.
.RE
.sp
.PP
By default, \fBDELETE\fR will delete rows in the
specified table and all its child tables. If you wish to delete only
from the specific table mentioned, you must use the
ONLY clause.
.PP
There are two ways to delete rows in a table using information
contained in other tables in the database: using sub-selects, or
specifying additional tables in the USING clause.
Which technique is more appropriate depends on the specific
circumstances.
.PP
The optional RETURNING clause causes \fBDELETE\fR
to compute and return value(s) based on each row actually deleted.
Any expression using the table's columns, and/or columns of other
tables mentioned in USING, can be computed.
The syntax of the RETURNING list is identical to that of the
output list of \fBSELECT\fR.
.PP
You must have the DELETE privilege on the table
to delete from it, as well as the SELECT
privilege for any table in the USING clause or
whose values are read in the \fIcondition\fR.
.SH "PARAMETERS"
.TP
\fBONLY\fR
If specified, delete rows from the named table only. When not
specified, any tables inheriting from the named table are also processed.
.TP
\fB\fItable\fB\fR
The name (optionally schema-qualified) of an existing table.
.TP
\fB\fIalias\fB\fR
A substitute name for the target table. When an alias is
provided, it completely hides the actual name of the table. For
example, given DELETE FROM foo AS f, the remainder
of the \fBDELETE\fR statement must refer to this
table as f not foo.
.TP
\fB\fIusinglist\fB\fR
A list of table expressions, allowing columns from other tables
to appear in the WHERE condition. This is similar
to the list of tables that can be specified in the FROM Clause [\fBselect\fR(l)] of a
\fBSELECT\fR statement; for example, an alias for
the table name can be specified. Do not repeat the target table
in the \fIusinglist\fR,
unless you wish to set up a self-join.
.TP
\fB\fIcondition\fB\fR
An expression returning a value of type
\fBboolean\fR, which determines the rows that are to be
deleted.
.TP
\fB\fIoutput_expression\fB\fR
An expression to be computed and returned by the \fBDELETE\fR
command after each row is deleted. The expression may use any
column names of the \fItable\fR
or table(s) listed in USING.
Write * to return all columns.
.TP
\fB\fIoutput_name\fB\fR
A name to use for a returned column.
.SH "OUTPUTS"
.PP
On successful completion, a \fBDELETE\fR command returns a command
tag of the form
.sp
.nf
DELETE \fIcount\fR
.sp
.fi
The \fIcount\fR is the number
of rows deleted. If \fIcount\fR is
0, no rows matched the \fIcondition\fR (this is not considered
an error).
.PP
If the \fBDELETE\fR command contains a RETURNING
clause, the result will be similar to that of a \fBSELECT\fR
statement containing the columns and values defined in the
RETURNING list, computed over the row(s) deleted by the
command.
.SH "NOTES"
.PP
PostgreSQL lets you reference columns of
other tables in the WHERE condition by specifying the
other tables in the USING clause. For example,
to delete all films produced by a given producer, one might do
.sp
.nf
DELETE FROM films USING producers
  WHERE producer_id = producers.id AND producers.name = 'foo';
.sp
.fi
What is essentially happening here is a join between \fBfilms\fR
and \fBproducers\fR, with all successfully joined
\fBfilms\fR rows being marked for deletion.
This syntax is not standard. A more standard way to do it is
.sp
.nf
DELETE FROM films
  WHERE producer_id IN (SELECT id FROM producers WHERE name = 'foo');
.sp
.fi
In some cases the join style is easier to write or faster to
execute than the sub-select style.
.SH "EXAMPLES"
.PP
Delete all films but musicals:
.sp
.nf
DELETE FROM films WHERE kind <> 'Musical';
.sp
.fi
.PP
Clear the table films:
.sp
.nf
DELETE FROM films;
.sp
.fi
.PP
Delete completed tasks, returning full details of the deleted rows:
.sp
.nf
DELETE FROM tasks WHERE status = 'DONE' RETURNING *;
.sp
.fi
.SH "COMPATIBILITY"
.PP
This command conforms to the SQL standard, except
that the USING and RETURNING clauses
are PostgreSQL extensions.