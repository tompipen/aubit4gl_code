SQL CONVERSION TOOL

convertsql takes SQL statements and converts them from one dialect
of SQL into another, according to the conversion rules in
/opt/aubit4gl/etc/convertsql/

convertsql takes two arguments - the input and output dialects.
It converts standard input to standard output.

eg. to convert a file "mystuff.sql" containing Informix style SQL
    commands to one containing Postgres compatible SQL,
    you would run the following at the command line:

    convertsql INFORMIX POSTGRES < mystuff.sql > mystuff_pg.sql

COMPILING AND INSTALLING

Enter and run the following at the command line:

 make
 make install

The program convertsql will be installed into the aubit bin directory.

