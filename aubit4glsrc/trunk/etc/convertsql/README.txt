SQL DIALECT CONVERSION RULE FILES
---------------------------------

This directory contains files that specify what conversions need to be done
on SQL statement text to convert from one dialect of SQL to another.

The files are named as <source>-<target>.cnv
eg.
   INFORMIX-ORACLE.cnv  - rules for translating Informix to Oracle
   ORACLE-POSTGRES.cnv  - rules for translating Oracle to PostgreSQL

These are simple text files, containing a list of directives, one to a
line.  Lines beginning with a # are treated as comments and are ignored.

The possible directives are listed below:


1) Simple directives, taking no arguments

 DOUBLE_TO_SINGLE_QUOTES

   Change double quotes (") to single quotes (') around literal strings.

 MATCHES_TO_LIKE

    Change Informix_style 'matches' clause to one using 'like',
    and change * and ? to % and _ respectively.
    eg:
       matches 'X?Z*'   ->  like 'X_Z%'

 MATCHES_TO_REGEX

    Similar to 'matches-to-like' but uses the Postgres style regular
    expression syntax,
    eg:
       matches 'X?Z*'   ->  ~ '^X.Z.*'

 TABLE_ALIAS_AS

    Insert the word "as" before table alias names in a 'from' clause
    eg:
       from ..., table1 t1, ...  ->  from ..., table1 as t1, ...

 COLUMN_ALIAS_AS

    Insert the word "as" before column/expression alias names in a
    'select' clause
    eg:
       select ..., sum(amount) amt, ...
       ->
       select ..., sum(amount) as amt, ...

 ANSI_UPDATE_SYNTAX

    Convert Informix-style "update ... set (..,..) = (..,..) " to the
    ANSI standard format "update ... set ...=..., ...=... "
    eg.
       update mytable set (col1,col2,col3) = ("01", "X", 104) where ...
       ->
       update mytable set col1="01", col2="X", col3=104  where ...

 CONSTRAINT_NAME_AFTER

    Move the constraint name in a constraint command to after the
    constraint definition,
    eg:
       ... constraint c_name unique
       ->
       ... unique constraint c_name

 CONSTRAINT_NAME_BEFORE

    Move the constraint name in a constraint command to before the
    constraint definition,
    eg:
       ... unique constraint c_name
       ->
       ... constraint c_name unique


2) Directives that take an argument ( in the rules below, replace
   the word "string" with the appropriate values )

 SUBSTRING_FUNCTION = string

   Change Informix-style string subscripting to a function call,
   Replace 'string' with the name of the sql function.
   eg. 
       where ... foo[3,5] = ....
       ->
       where ... substr(foo,3,3)

3) Text replacement directives

   Search and replace is not case-sensitive. For legibility, lower case
   is used in the rules for search/replace strings to distinguish them from 
   the keywords (in upper case).

   You may leave the replacement string (after the = sign) blank. This will
   have the effect of removing the matched string from the converted output.
 

 REPLACE before = after

   Replace any occurrence of the string 'before' with 'after',
   eg.
      REPLACE rowid = oid
      REPLACE current year to second = sysdate
      REPLACE today = date(now())

 REPLACE_EXPR before = after

   Replace only if the 'before' text is found in an expression or where
   an expression is allowed, such as in a where clause or a select clause.
   
   eg.
      REPLACE_EXPR sysdate = current year to second
      REPLACE_EXPR today = date(now())

 REPLACE COMMAND before = after

   Replace, but only if the whole SQL statement matches the 'before' string
   eg. 
      REPLACE_COMMAND set isolation to dirty read =

