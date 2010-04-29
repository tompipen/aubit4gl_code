
pg_dump with the -s flag,

; pg_dump -a dumps the data in postgres; COPY in
the postgres monitor gives you a little more control as to the format
of data dump.  Informix's syntax is a cleaner implementation in this
regard, though.  Postgres's pg_dump is great, though, for backing up a
whole database w/ schema and restoring it.

-----------------------------------

http://www.postgresql.org/idocs/index.php?datatype.html

Postgres has a rich set of native data types available to users. Users may add new types to Postgres using the CREATE TYPE command.

CREATE TABLE tablename (colname SERIAL);

is equivalent to specifying:
CREATE SEQUENCE tablename_colname_seq;
CREATE TABLE tablename
    (colname integer DEFAULT nextval('tablename_colname_seq');
CREATE UNIQUE INDEX tablename_colname_key on tablename (colname);

Implicit sequences supporting the serial are not automatically dropped when a table containing a serial type is dropped. So, the following commands executed in order will likely fail:
CREATE TABLE tablename (colname SERIAL);
DROP TABLE tablename;
CREATE TABLE tablename (colname SERIAL);

The sequence will remain in the database until explicitly dropped using DROP SEQUENCE.
-----------------------

is there an informix utility called dbschema which does this?

   dbschema -t all -d databasename > schema.sql

Sylte writes:
 > How is the SQL command UNLOAD (informix) used to extract both data and
 > database architecture?
 >
 > Is it able to create a file of SQL statements like when using postgresql's
 > command  "pg_dump -f outputfile mydb"
 >

 --------------------------

 copy or copy commands in psql:

I normally use \copy for tab-delimited files.
But copy also works and has help....

\h copy
Command:     COPY
Description: Copies data between files and tables
Syntax:
COPY [ BINARY ] table [ WITH OIDS ]
     FROM { 'filename' | stdin }
     [ [USING] DELIMITERS 'delimiter' ]
     [ WITH NULL AS 'null string' ]
COPY [ BINARY ] table [ WITH OIDS ]
     TO { 'filename' | stdout }
     [ [USING] DELIMITERS 'delimiter' ]
     [ WITH NULL AS 'null string' ]


COPY table FROM 'filename' USING DELIMITERS '|';

-------------------------------------

>4/Informix outer join syntax
>oinformix uses outer joins of the form
>SELECT * FROM a, outer b where a.nr = b.nr
>This will require some post-processing to determine
>the actual join conditions.

-------------------------------------------

do* need to support ROW_COUNT, but allowing
>
>     GET DIAGNOSTICS Select ROW_COUNT, SQLCODE, OID Into :a,:b:,:c;
>
> is a lot friendlier than the standard:
>
>     GET DIAGNOSTICS :a = ROW_COUNT;
>     GET DIAGNOSTICS EXCEPTION 1 :b = SQLCODE;
>     GET DIAGNOSTICS :c = OID;
>
> (not that we even support SQLCODE at this stage).

Informix does:
GET DIAGNOSTICS :a = ROW_COUNT, EXCEPTION 1 :b = SQLCODE;

separated with comma, don't know if that is standard, but it sure looks more
like the standard.


--------------------------------------------------------


------------------------

CREATE SEQUENCE person_id_seq;
CREATE TABLE person (
id INT4 NOT NULL DEFAULT nextval('person_id_seq'),
name TEXT
);
CREATE UNIQUE INDEX person_id_key ON person ( id );

. . . creates an autoincrementing field.

Then, to add values, use:

INSERT INTO person VALUES (NEXTVAL('person_id_seq'), '...');
or
INSERT INTO person (name) VALUES ('...'); -- Use DEFAULT

Also, according to the FAQ, if the SERIAL type is used, it's turned into what you see above.

. . . appears the
CREATE UNIQUE INDEX person_id_key ON person ( id );
. . . should not be included as it's done for you automatically. Attempting to create the above index (after it has already been created *for* you) is pointless.

------------------------

MONEY is a deprecated type! This should be noted in the table above. I did not know this when I was setting up tables under PostgreSQL v7.0.3 a few months ago, and now I'm paying the price since there is no built-in support for casting (converting) MONEY into FLOAT8, for example, or other more useful data types.

I just wrote some functions in C for PostgreSQL v7.0.3, however, to do the conversions 'natively'. With any luck, they will be included in the contrib directory or in the main distribution itself. I will post them to the pgsql-general and pgsql-hackers mailing lists. (The source probably won't compile under v7.1, but it won't be hard to fix.)

Please see section 3.2 Monetary Type for more details.

http://www.postgresql.org/idocs/index.php?datatype-money.html


--------------------------

Example, PG table definition:

create sequence caltype_seq start1;
create table caltype
(
caltype_nmbr int4 default nextval('caltype_seq'),
ctype char(2),
descr varchar(21),
rpt_desc varchar(8),
evntnmbr int4
);

create unique index caltype_idx on caltype (caltype_nmbr);

create unique index caltype_ctype_idx on caltype
(ctype);
create index caltype_evnt_idx on caltype (evntnmbr);

Same Table with Informix:

create table caltype
(
caltype_nmbr serial not null ,
ctype char(2),
descr char(21),
rpt_desc char(8),
evntnmbr integer
);

create unique index caltype_idx on caltype (caltype_nmbr);

create unique index caltype_ctype_idx on caltype
(ctype);
create index caltype_evnt_idx on caltype (evntnmbr);

The only real difference is in handling the serial number. I'm not sure I will continue to use varchar. I understand there may be a performance hit with it.

I'm not having difficulty with NULLs in the database though I'm not happy with how I had to load it. I was not able to use the copy command on the results of an Informix unload. I had to write a 4GL report to format the data so PostgreSQL would not ralph on the first null date or decimal
field it tried to load.


--------------------------------------------------------------------------------



Re: Triggers with arguments

--------------------------------------------------------------------------------

From: "Robert B. Easter" <reaster@comptechnews.com>
To: Scott Holmes <sholmes@pacificnet.net>
Subject: Re: Triggers with arguments
Date: Wed, 12 Jul 2000 21:44:04 -0400

--------------------------------------------------------------------------------

On Wed, 12 Jul 2000, Scott Holmes wrote:
> I'm afraid I just don't see how this is done without being able to pass
> arguments to the procedure or actually running an additional SQL statement
> within the trigger:
>
>   I have a "notes" table that is potentially linked to records in many other
> tables.  The primary key is created from 1) the name of the table, and 2) the
> primary key value of that table.  When one of these records, with notes, is
> deleted, I need to make sure that the notes records are deleted as well.
>
> I've been playing around with this and perhaps my code that doesn't work will
> illustrate what I need to accomplish and perhaps one of you kind readers will
> show me just how to do it.
>
> CREATE FUNCTION del_stxnoted () RETURNS opaque AS '
>   DECLARE
>     fname alias for $1;
>     rkey alias for $2;
>   BEGIN
>     delete from stxnoted where filename = fname
>        and record_key = rkey;
>   END;'
> LANGUAGE 'plpgsql';
>
>
> create trigger del_location_trig
> after delete
>   on location
>   for each row
>     execute procedure del_stxnoted("location", 'old.wher');
>
> Postgres will not create this trigger as it does not recognize the function
> del_stxnoted as actually existing.
>
>
> I am attempting to convert a large suite of applications that currently run on
> an Informix database.  The syntax for this is
>
> create trigger del_location delete on location referencing
>     old as pre_del
>     for each row
>         (
>         delete from stxnoted  where ((filename = 'location' ) AND (record_key
>     = pre_del.wher ) ) );
>
>
> Thanks,  Scott

Maybe try it like this:

CREATE FUNCTION del_stxnoted() RETURNS OPAQUE AS '
BEGIN
	DELETE FROM stxnoted WHERE filename = OLD.fname AND record_key = OLD.rkey;
END;
' LANGUAGE 'plpgsql';

CREATE TRIGGER del_location_trig
	AFTER DELETE ON location FOR EACH ROW
	EXECUTE PROCEDURE del_stxnoted();


		- Robert



--------------------------------------------------------------------------------

Prev by Date: Re: Figured it out (psql and Gnu readline)
Next by Date: pgsql setup
Prev by thread: Re: Triggers with arguments
Next by thread: Having a problem compiling plperl.
Index(es):
Date
Thread
Home | Main Index | Thread Index



--------------------------------------------------
Subject: Loading/Unloading - FAQ material - need assist (Art, David)]
From: jack.parker4@verizon.net (Jack Parker)
Date: 3 Jul 2001 08:45:17 -0700
Organization: http://groups.google.com/

(ok, let's start with this - and since I haven't set this box up with
news yet, and mail is bouncing, we'll post grace au Deja).  I just
incoporated Obie one's insightful comments to the earlier post.

I saw three 'load data' related questions yesterday.  Looking through
the FAQ I note that the coverage for this topic is fairly sparse.  I
also note that that document has become large enough that it needs
some
organization, the titles are too generic to be useful.  Not that I'm
volunteering, although if you need help let me know.

I'm going to go ahead and do something up here for the FAQ.  Art, I
have
not had the pleasure of working with myexport, but I note that others
swear by it, could you you jump in and add a section for it?  I would
expect it to come after dbimport but you will be the judge of that.  I
am also not very familiar with onunload, so coverage here is fairly
sparse.  If someone wants to jump in and do something up for that it
would be appreciated.  Of course, where I make egregious errors
elsewhere feel
free to jump in and point them out.

cheers
j.

---- snip here -------------------------------------------

Loading and Unloading data with Informix databases

There are several facilities to allow you to get data into and out of
an
Informix database.  Each one has some advantage over the others which
keeps it from becoming totally obsolete.

LOAD is the simplest (and perhaps oldest) of these.  It is invoked
from
within SQL as:

LOAD FROM filename INSERT INTO table;

There is a corresponding UNLOAD statement:

UNLOAD TO filename SELECT * FROM table;

There are some other options that have been added to this command in
recent years, the ability to specify a delimiter and a limited ability
to map your destination columns:

LOAD FROM filename DELIMITER '|' INSERT INTO table(column1, column2,
column3);

LOAD is the easiest loader to script with, there is no setup required
to
make it work.  However, the entire contents of the load is handled as
one transaction.  For a large file this may overflow the transaction
logs on a logging database and run you into a long transaction.  Load
has no error handling ability, if there is a bad record in the load
file, the load will abort, leaving some data loaded and everything
from
the bad record on - not loaded.

It is also not exactly the fastest loader around, however if you
include
setup time in your load time calculation LOAD is very effective for
files under 1000 records.  Your mileage may vary, but you can expect a
load rate of 1GB/hour with this facility.  Load rates mentioned here
are
relative (especially to one another).

LOAD and UNLOAD are SQL statements and are documented in the SQL
Syntax
manual.

DBLOAD came around with Online 5.0 and resolves the long transaction
issue as records are committed at intervals specified by the user,
(default is every 100 rows).  It is more complex in that it requires a
command file to specify the load parameters.  This same command file
provides much better mapping between source and destination columns.
dbload also has an error handling capability.  Each bad record is
rejected to an error file along with a reason that record was
rejected.

I'm not going to go into syntax here.

This is documented in the Informix Migration Guide under the Utilities
chapter (11)

DBLOAD will run at a rate comparable to the LOAD statement.  (1GB/HR
here)

INSERT CURSOR. Moderately more difficult to work with, especially
since
this requires a procedural language like 4gl or esql/c.  The insert
cursor is faster than LOAD and DBLOAD because it opens a 'pipe' (if
you
will) directly to the table, the insert statement is parsed only once,
and data either goes in or doesn't - error handling is up to the
programmer.  I do not have a tasty simple example of one lying around,
I'll work on that.

The insert cursor will be documented under the language where it used.
It should have a separate topic since there is some work to using it,
declaring the cursor, (potentially describing it under esql/c) opening
it, putting to it, flushing, and closing.  This gives you the finest
level of control over your load.

The insert cursor is roughly twice as fast as dbload or load.  (2GB/HR
here).  As Obie-one has pointed out, you need to be a programmer to
use it.  He also points out that some people actually test stuff and
this chews up time.  (Not sure why you'd want to test something.)

dbimport/dbexport

If you need to unload an entire database (note not an instance) move
it
somewhere and re-import it, then the dbexport/dbimport pair are fairly
nice.  dbexport database will create a subdirectory from your current
location entitled database.exp and fill it with unload files named
with
the first 5(?) characters of the table name followed by the tabid.  It
will also generate a schema for the database in that directory entitle
database.sql.  There can be no active connections to the database
during
the export.  dbimport reads this directory and rebuilds the database.

These have the capability of writing directly to tape instead of disk.
dbimport also has the ability to specify the destination dbspace and
logging mode of the new database - which is key, dbimport is not smart
enough by itself to recreate the database with the same logging that
the
export read from.

These utilities are not available with Informix 8.X (XPS).  They are
documented in Informix Migration Guide under the utilities chapter
(11).

myexport/myimport

onload/onunload

High Performance Loader/Unloader (version 7.x and 9.x specific)

The High Performance Loader can take advantage of the full instance
and filesystem, provided things have been set up properly.  (Although
Obie-one just pointed out that you need an 'X'-station to run it which
is quite accurate),

HPL will initiate a separate thread for each component of your load,
so each separate table fragment get's it's own 'insert' thread, each
separate load or unload 'file' will get it's own read or write thread.
 Conversion threads between the two sets can be controlled (to some
degree) with a separate $PLCONFIG file.

In express mode HPL does not perform a true 'insert', instead it
avoids what I call the 'buffer wall' and writes pages directly.  These
pages are collected and, if the load is successful, they are appended
to the table.  This has some interesting implications:

    1 - in express mode, none of your special SQL tricks will work -
triggers, indices and referential constraints are not processed.  In
fact you have to turn them off to use express mode (which is what you
would want to do anyway, and then rebuild them after the fact).
    2 - Since new pages are appended, any existing free space within
your table IS NOT RE-USED.  SO if you delete * from table and then do
an express load you will have dead space in your table - this will be
re-used with standard inserts, but not by the express load..

Likewise, for unloads, you will get a separate scan thread for each
fragment and a separate write thread for each 'file' you are unloading
to.  Furthermore HPL will use a light scan - whch again avoids the
overhead associate with the buffers - to read your data.

HPL can also operated in 'deluxe' mode in which it goes through the
SQL buffers and maintains your indices, constraints and fires
triggers.  Of course this means that you've hobbled your load, but
that may be desirable.

HPL can read from or write to files, tapes or pipes.  These are set up
in devices, so you actually unload to a device.

Setup for HPL jobs is performed using a GUI which is fairly intuitive
given the many complexities of the job setup.  You are walked through
the five pieces of the process consisting of a query, (I'm drawing a
blank) a map, options and a device.  (for a load it is the reverse,
Device, filter, map, options, table).  You can easily 'generate' a
load/unload job to handle standard processes, although HPL has a lot
of flexibility built in if you want to use it - the ability to read
EBCDIC, not map fields to/from columns or map one to two places.  You
can even link in your own functions to the loader and perform custom
conversions (I have not done this personally).

To initiate the gui (and build the onpload database - which database
name you have control over with the environment variable $?????????)
invoke ipload from an X-station near you.  (has to be X).  Mind that
you've set up your $DISPLAY, xhosted the server, set your
$INFORMIXSERVER to the tcp connection.  While you can run the
load/unload jobs directly from teh interface, I do not recommend it.
You get a log message every 10,000 rows, the interface is not fast
enough to keep up with the display.  So while your job may have
finsihed in 30 minutes, it may take another 30 minutes for the log
messages to stop scrolling on your tube - and guess what - the job
ain't done until those log messages are complete.  Use the command
line interface 'onpload' to run things from the command line.

The bottleneck with HPL is generally NOT the cpu, but disk I/O, hence
to make things run as fast as possible it is useful to minimize this
I/O.

Recommendations for optimum performance:  (unload)
1 -  write to named pipes.  (use mknod -p to create these.  Your
device elements look like:  'cat > /tmp/pipe.1')
2 - have a second set of processes which read the pipes.  (gzip - >
file.gz)
3 - spread our unload files over multiple devices.
4 - make sure you have dirty read set under options.  (to enable light
scans).

(load)
1 - read from named pipes.  (Your device elements look like 'cat
/tmp/pipe.1')
2 - feed these pipes with an external process (gunzip -c file.gz >
/tmp/pipe.1)
(actually, I just set up the device as 'gunzip -c file.gz' - but to be
consitent I tried to spell it out this way).
3 - fragment your table over multiple dbspaces (2 per CPU).  This is a
major element to performance.  When you set up your dbspaces, do not
try to have big, or deep, dbspaces.  1 2GB chunk per dbspace is best.
Fragment your tables across dbspaces, not try to get 8GB on one
dbspace.  You will get more write threads.
4 - When creating the table, your initial extent should be the
minimum, the next extent should be your real first extent - alter the
table later to correct it.

With this facility you can expect load rates at a minimum of
2GB/CPU/HR.  For a 4CPU box this means 8GB/Hour.  If you follow the
directions above......  Unload rates should crank to around 4 or
5GB/CPU/HR.  This is an invaluable tool for re-organizing a table.  It
is also a cute trick to get around the buffer overhead when you want
to read from one table and insert into another, set up an unload job
to a pipe, set up the load job to read from the pipe and Bob's your
uncle.

HPL is documented in its own manual called, appropriately enough,
'High Performance Loader'.

Con.
The interface is a real pain.  HPL can 'fall over' easily if you get
too exotic.  It is better to drop and redfine a job than to try to
debug it.  As Kerry Smith pointed out - it's like a race car, finicky
but fast as h*ll.  You need an 'x' station or some form of x-software
on your PC to use this tool.

(I know I've missed a thing or to - jump in.  I'm writing this without
T.F.Manuella, so there a few things I'll have to go back and look up).

Parallel Loader (8.x XPS specific)

Imagine fixing the problems with HPL.  Welcome to the XPS parallel
loader.

For starters, there is no concept of a job with this loader.  In fact
you're not really aware that it is a loader at all.  You create
'external' tables which can represent files, tapes or pipes.  You then
treat these tables as though they were regular SQL tables.  A load is
therefore, 'select from external_table insert into internal_table;'
and unload is the reverse.  This makes it incredibly easy to set up
your load/unload processes, and lends itself well to scripting.  There
is new syntax to support the external table creation and the table
type is 'E'.  Beyond that there's not much to it, you can treat these
'tables' as though they were normal tables, perform joins with them or
whatnot - although be advised that there are no statistics for these
tables, so the optimizer will assume that there are 2 billion rows
(max int) rows in the table.

As with HPL, you want to make sure that you fragment your table
optimally as well as your output files or whatnot.  The load rate for
this loader is roughly comparable to HPL - again the bottleneck is not
CPU, but disk.  Since XPS servers tend to be larger than 7.x or 9.x
servers, the load seems to run faster, but the actual load rate is the
same - 2GB/CPU/HR or thereabouts.  With XPS you also have a 'raw'
table type which optimally supports the light appends used with XPS.
Once you've loaded your table you can alter the table type to whatever
you want (provided you've done a backup - or otherwise reset the
backup flags).

The Parallel Loader support the same features as HPL, EBCDIC,
express/deluxe load modes.  Mapping, mathematic calculations and so
forth you handle within your SQL select/insert statement.

The Parallel loader is documented in chapter 10 of the XPS Admin
manual.  (Better check that one).

Con.
Provided you don't do something silly, there aren't any real cons.
Make sure you have enough disk space to support an unload, make sure
the files exist with the proper names for a load.  A load job can
fail, but not as easily as with HPL.

The elegance and simplicity of using the existing SQL interface for
this loader makes it very simple to work with.  An SQL novice can
create an external table and utilize it.

=========================================================================

Subject: Re: Loading/Unloading - FAQ material - need assist (Art, David)]
From: "Andrew Hamm" <ahamm@sanderson.net.au>
Date: Wed, 4 Jul 2001 10:50:55 +1000

RE: UNLOAD command - may be wise to show optional WHERE clause, but without
explanation would probably be fine.

RE: DBLOAD
A bit of a tricky one to describe is the possibility that it may cause OTHER
users to suffer long transactions. It solves it's own long transaction
problem, but it can drag other users through the mud.

RE: LOAD and DBLOAD
mention of violations tables would be nice, especially since they gather the
dud rows into a place where they can easily be examined.

mention of raw vs. standard mode for tables would be useful, especially as
it affects the long transaction issue. Near the bottom of the FAQ you
mention raw tables for XPS, but they exist also in 7.30X ++ (?) and the 9's
(don't know from which version)

>INSERT CURSOR. Moderately more difficult to work with, especially
>since this requires a procedural language like 4gl or esql/c.
>
or Perl ;-)
Perl with DBD::Informix is actually quite excellent for the job because it
offers a huge amount of data massaging power including the ability to write
generic code which is harder in esql and damn near impossible in 4gl. If
you've already got perl scripts to process foreign data, it's only one step
further to insert directly to the database. I understand that Perl is fairly
popular with warehousers in the extract, transform and cleanse work? It
would certainly be my tool of choice - can't think of a better language for
the job when the data gets ugly.

I've been dabbling with a general purpose perl script which loads all sorts
of ugly formats but it's a really really REALLY low grade project... It
should generalise some specific code I used for a particular load project.

=======================================================================

http://search.cpan.org/Catalog/Database_Interfaces/

DBD::Informix - Informix Driver for DBI  http://search.cpan.org/search?module=DBD::Informix
DBD::Informix4 - DBI driver for Informix SE 4.10 http://search.cpan.org/search?module=DBD::Informix4
DBD::ODBC - ODBC Driver for DBI   http://search.cpan.org/search?module=DBD::ODBC

Pg - PostgreSQL SQL database interface http://search.cpan.org/search?module=Pg
Postgres - PostgreSQL interface with Perl5 coding style http://search.cpan.org/search?module=Postgres


===========================================================



PostgreSQL mailing list archive
Search  |   Search for selection   |   Fresh postings  |   About

Message basket: Add

Author: Art S. Kagel <kagel@bloomberg.net>
Date: Fri 10 Dec 10:15:57 1999 EST
Subject: RE: a comparison of 4 databases
Thread: 2 messages
As an, admittedly avid, and long time user of Informix database products I
felt I could not leave this shoddy comparison stand without comment.  There
are many errors concerning the features and capabilities of Informix database
servers and Mr. Kirkwood conducted several of his tests poorly which did not
fairly represent this fine set of database server products, nor, likely, the
other fine databases included in the comparison either.  Anyone interested in
his results should read on.  Since I have moused the original post I will
preceed my own comments with 'ASK -' and indent to make them clear.

A Comparison Of 4 Databases
---------------------------

Intro
-----

This paper shows the results of an evaluation of 4 databases. I am posting it
to this mail group as I think Postgresql emerged quite favourably.

The evaluated databases were Oracle, Informix, Mysql and Postgresql.

Features and performance were examined.

Hardware And Operating System
-----------------------------

2 x HP Vertra VE 7 each with 160M RAM + 1x3.2G + 1x13G Quantum IDE Drives were
used.
Redhat 6.0 was used as the operating system. No kernel changes were made.


Initial Experiences
-------------------

Mysql was obtained in rpm format and was amazingly easy to install. The
installation process created and started a database. The version was 3.22.27

Documentation was supplied and was good.

Postgresql was similarly elementary to install, and again a database was
created and started. The product comes with the flavour of Linux used and
was in rpm format. The version was 6.5.2

Documentation was supplied and was very good.

Informix was more cryptic to install. It was obtained in rpm format and
installed. However this merely installed an archive and the real installation
process had to be run thereafter. After this it had to be divined as to what
was required next  - the install does not create a database.

ASK -Indeed the install can be cryptic but there are detailed installation
instructions that can be downloaded from the Informix site as well
as an available How-To that explains how to make an initial
configuration and bring up the engine for the first time.  All of
which are also explained in detail in the Informix Administrators
Guide.

Using some of the (not supplied) documentation it was discovered how to create
and configure a database. The version was 7.30 ( This is old, but all they
are supplying on this platform - 9.x is current)

ASK -I assume Mr. Kirkwood downloaded the Informix Dynamic Server v7.30
which is NOT old.  The Informix server product line includes 4
different servers and Informix is in the process of merging the code
lines of some of these.  The Informix enterprise level engine for
transaction processing IS the IDS7.3x product the latest release of
which is 7.31 which IS available for Linux but the link that Mr.
Kirkwood followed took him to the older (by 3 months) 7.30 version.
The IDS/UDO v9.1x product is known as the Universal Data Option and
is Informix's Object Relational product descended ultimately, like
PostgreSQL, from the Postgres project.  UDO was based on the older
IDS 7.1x code base and some features needed for transaction oriented
applications were missing.  In the last 3 weeks, indeed on the same
day Mr. Kirkwood posted his report, Informix released IDS.2000 which
is IDS v9.20 and is a merger of the 7.31 and 9.1x code bases in a new
product promising Object Relational features, full transaction server
features, and enterprise quality performance.  But, this is a brand
new code base - and so - many users are waiting for IDS.2000 v9.21
or at least the first few maintenance releases of v9.20.  It is
important to note that Informix considers Linux a Tier I port and
released the IDS.2000 product on Linux on the same day as it did its
other Tier I ports like Sun/Solaris and HP/HP-UX.

Documentation was not supplied, it was available on the Informix web site. It is
ok.

ASK -The documentation is available for perusal online at the Informix
website from whence it can also be downloaded for local access or
you can purchase the docs on CD-ROM for $45US or in hard copy (I
think they are about $750US) from Informix.  Note that Informix's
documentation has won numerous awards for quality and clarity and
compared to Oracle's completely opaque docs I have always found it
a pleasure to use.

Oracle was difficult to judge as the author frequently installs it. However
pretending to be coming to it new, it would be very difficult to install.
It does not come in rpm format. It is downloadable from the Oracle web site.
The small amount of included documentation is sufficient to enable someone
to work out how to start the installer program. This program is a rudimentary
wizard that asks questions and presents a list of components to choose....
a newcomer would suffer confusion here. The installer can create a database as
part of the install. The version was 8.0.5 (this is slightly old - 8.1.5 is
Current but buggy, 8.0.5 is the latest stable release on this platform).

Documentation is not supplied, it is available from the Oracle web site. It is
ok.



Tests And results
-----------------

Database Feature
Comparison

Database   Cost    Trans   Row   Const   Program  Sec  Fail  Hot
                   actions Lock  raints  mable    ure  Safe  back

Mysql      0 /3000 No      No    No      Partial  Yes  No    No
Postgresql 0       Yes     Yes   Partial Yes      Yes  Yes   No
Oracle     3200    Yes     Yes   Yes     Yes      Yes  Yes   Yes
Informix   2000    Yes     No    Yes     Yes      Yes  No    No


ASK -See below.  ALL OF THE 'No's above should be 'Yes'es.  I address
each point below.

Cost

        NZ$ for 10 user license. Two prices mean that the product is charged
        for if resold as part of an application ( Mysql )
        Support is not included

Transactions

        Commit, rollback, isolation levels of at least read commited

ASK -Informix permits the user to create a database in one of four modes.
Three of these: Mode ANSI, Buffered Logged, and Unbuffered Logged
support multiple statement transactions with BEGIN WORK (ANSI mode
databases infer a BEGIN WORK with the first statement not in a
transaction, ie following a COMMIT or ROLLBACK).  The fourth, which
for historical reasons is the default mode, is non-logged which does
NOT support multiple statement transactions, though individual SQL
statements are treated as singleton transactions.  Based on the
results for Fail Safe I'd say that the database was created in
default mode without logging or perhaps in BUFFERED LOG mode and
the COMMIT record was still in the log buffer and had not flushed
to disk in which case Informix rightly rolled back the transaction
(this would be noted in the engine's message log at the time the
engine was restarted).  For this type of secure testing Mr. Kirkwood
should have beenusing an UNBUFFERED LOG mode database which
automatically flushes the log buffer when a commit record is written
to it.  There is an extensive discussion of these issues and their
ramifications for performance and safety in the Administrators
Guide.  Note that most Informix DBAs run their databases in
UNBUFFERED LOG mode.

Row Locking

        select for update that locks only the rows selected and does not
        block reads

ASK -Informix DOES indeed support row level locking though the default
for tables is page level locking.  One need only include the LOCK
MODE ROW clause in the CREATE TABLE statement or ALTER the table
afterward to have row level locks.

Constraints

        primary and foreign key, with ability to enable/ disable or drop / add
        existence will give ""Partial"" and enable etc will give "Yes"

Programmable

        create trigger, procedural language extensions to SQL
        A "Partial" means that external functions only are supported

Secure

        Requires username and password validation

Fail Safe

        delete of 100 out of 100000 rows, commit ( if have it ) then power
        off and on, check after power on - 999900 rows gets a "Yes"

ASK -If Mr. Kirkwood had created his database with one of the logged
transaction modes he would have had complete 'fail safe' behavior
from the Informix server.  Informix cannot recover transactions
that have not been checkpointed out to disk in a database without
logging (the default) but it can for a logged database.

Hot Backup

        Can a consistent backup of the database be run backup while it is up
        with transactions performed against it.

ASK -Informix was the first relational database to support online live
consistent backup of its database servers.  Indeed Informix provides
three archive products all of which can backup the server while being
actively updated.  Only one of these, ontape, is available on Linux
so far (due to some third party software the others, onarchive and
onbar, depend on which was not available for Linux at release time)
but that may soon change.

Database Performance Comparison - Data
Warehouse

Database    Bulk Load  Summarize 3%  Summarize 0.3%  Summarize 0.3%
            1M         of 3M         of 3M           of 3M
                       1 dim 1 fact  2 dim 1 fact    3 dim 1 fact

Mysql       20         14            90              57
Postgresql  420        16            4               7
Oracle      65         5             3               3
Informix    170        8             5               6

Notes

Bulk Load

        elapsed seconds to load 1000000 rows via whatever bulk load tool is
        supplied.

ASK -Informix has several bulk load utilities.  It would appear that Mr.
Kirkwood either did not use the ipoader or did not run it in either
of the higher speed modes which includes a mode which bypasses all
logging and is several times faster than logged modes.

ASK -On the performance tests, Informix performance is very dependent on
the tuning of the engine and the presence of proper database
statistics.  I cannot know how well or poorly Mr. Kirkwood tuned the
engine or whether he ran the recommended suite of UPDATE STATISTICS
commands after loading the database.  Without details of how well
he prepared the various servers and databases so the optimizers
could do their jobs properly one cannot evaluate the quality of
his results.  Note that I state all of this even though Informix
performed reasonably anyway.  I just wonder how much better ANY of
the tested server could have performed.

Summarize 3%
1 dim + 1 fact

        Measure elapsed seconds to display summarized count and one timelike
        dimension attribute for basic star query
        Access path can be via an index scan

Summarize 0.3%
2 dim + 1 fact

        Measure elapsed seconds to display summarized count and one non timelike
        dimesion attribute for less basic star query
        Access path can be via  index scans

Summarize 0.3%
3 dim + 1 fact

        Measure elapsed seconds to display a summarized count and 1 non timelike
        dimension attribute for more complex star query
        Access path can be via  index scans



Database Performance Comparison -
Online


Database    Create  Create  Query 1  Query 4  Query Summary
            10K     1M      of 10K   of 1M    10% of 1M

Mysql       7       891     0        0        1
Postgresql  21      4430    0        0        2
Oracle      31      3694    0        0        2
Informix                    0        0        10


Database    Tpm     Tpm     Tpm      Tpm
            1 sess. 2 sess. 4 sess.  8 sess.

Mysql       59/58   59/115  59/229   58/425
Postgresql  48      90      169      233
Oracle      55      108     180      291
Informix



Notes


        Unfortunately no Informix SDK was available, so there is no result for
        the first two or last tests.

ASK -Informix's SDK is not included in the basic engine download but IS
available for free download for Linux.  The SDK includes ESQL/C,
CLI/ODBC, JDBC, a C++ interface, and more.  Also available in
separate packages are I4GL (compiled version of Informix's award
winning 4th Generation Language), R4GL (pcode version of I4GL which
includes a source level pcode debugger), ISQL (Informix's forms,
menus, and report writer package), and D4GL (a GUI aware version of
I4GL).  All of these are available for download including free
evaluation licenses and most are available with a free single user
development license.  The SDK is free for all developers and the
runtime package, iConnect, is free for all users.  With VERY little
effort Mr. Kirkwood could have compiled and run his tests with
Informix.

Create 10K

        elapsed seconds for Php app to insert 10000 rows one by
one

Create 1M

        elapsed seconds for Php app to insert 1000000 rows one by one


Query 1

        0 seconds means that no delay was measurable
        Measure elapsed seconds to show master record 1 row located 70% though
        the table. Access path can be via an index scan

Query 4

        Measure elapsed seconds to display 4 detail rows for one of the master
        records in previous test. Access path can be via  index scans

Query Summary

        Measure elapsed seconds to display a summarized sum and count
        for 5% of 1000000 rows. This is a 2 table join . Access path can be via
        index scans

Tpm n sessions

        Transactions per minute for n sessions, achievable for lightweight Perl
        DBI application. Two results for Mysql refer to two possible locking
        schemes


Analysis
--------

Features

Oracle clearly has the most features. However it is Postgresql that is next in
line.

The features fail safe, transactions and security are seen as essential,
with row locking as highly desirable.

This means that  at face value only Oracle and Postgresql satisfy the criteria.

ASK -As does Informix if one takes the 10 seconds it takes to add the
WITH LOG clause to the CREATE DATABASE and LOCK MODE ROW clause to
the CREATE TABLE statements.  In several cases below Mr. Kirkwood
bothered to check the docs and even contact developers to find out
if or how he could get some feature he wanted that Oracle or
PostgreSQL did not seem to have could be made to work.  It is
suspect that he did not do the same for MySQL and Informix.  His
Informix download came with a free support contract so if reading
the docs or posting queries to comp.databases.informix did not get
the information he needed (and I assure you either the docs or the
newsgroup would have given him the answers) he could have called
tech support toll free.

Initially Postgresql did not force password entry and thus was not secure,
however it was discovered that access to the database is configured at install
time as trusted and has to be changed to require passwords.

It should be noted that Oracle needed a patch to be fail safe, and that this
was not advertised on the web site, thus is possible that Informix and Mysql
can also be similarly patched.

Repeated tests with Informix page level locks showed that readers were blocked
at this point. This was viewed as extremely undesirable.

ASK -In addition to setting row level locking mode for the tables Mr.
Kirkwood should note that Informix implements all of the ANSI
Isolation Modes.  The default for a logged database

Mysql's lack of transactions was a killer for it, the complexity of having to
programmatically undo an n-table operation was viewed as prohibitive.
( It was noted that the Mysql to do list had atomic operations - pseudo
transactions, on it .)

In conclusion on the features front, Oracle and Postgresql emerge as the
leaders.



Performance

1 Online operations

Initially Postgreql refused to use indexes to help with queries. A mail to one
of the Postgresql Development Team traced this to an unusual pickiness with
respect to the implied datatypes of constants in the where clause.


Informix had problems with the summary query, it would not go faster that 10s,
however it seemed to perform ok for the 10000 and 1000000 query searches.

Mysql demonstrates the overhead associated with multiple versioning and
transactions. It was obviously the fastest raw speed terms. It was in
general 4-5 times faster than anything else.

Postgresql was in general about 20% slower than Oracle.

The multiple session transaction test is most interesting. The idea was to
mimic a Tpc A style banking application with some user think time during the
transaction (1 second ).
Clearly Mysql with its table level locks could not scale at all. However it has
application locks that are nameable, so can mimic row locks - as long as every
access uses them. If these were turned on then a dramatic turnaround was
observed.

Thus Mysql is fastest, and most scalable if applications locks can be used.
Oracle and Postgreql are similar in scalability, but Postgresql begins to tail
off a little before Oracle does.


2 Data warehousing operations

Mysql has a very fast bulk load facility.
Oracle also has a very fast bulk load.
Infomix has a reasonably fast one.
Postgresql is noticeably slower than any of the others.

Mysql performed extremely poorly at the star type queries.
Oracle and Informix performed very well.
Postgresql performed very well in all but the first query - the simplest
(ironically), but it scanned the most data. This points to Oracle and Informix
having faster Nested Loop or Sort algorithms.

Both Oracle and Postgresql would experience a period of poor performance on a
table immediately after it was bulk loaded - typically until it was vacuumed or
analyzed.

In conclusion for this section Oracle, Informix are very good.
Postgresql is good but is hampered by slow bulk load and sorting of large
datasets.
Mysql can get the data in fast but is poor at querying it.


Overall
-------

Informix performs mostly ok, but its locking scheme precludes it for serious on
line use (it would have been interesting to test this).

ASK -Does this make sense?  There are literally thousands of mission
critical, speed dependent, multi-user applications running against
Informix engines.  It makes no sense that Informix's locking
prohibits reasonable performance.  Just this reasonablness test
should have clued the author in that he had missed something.

Oracle performs well.
Mysql's lack of transactions would have been ok for data warehousing, but it
could not do star queries. This rules it out.
Postgresql performed about 20% slower than Oracle, except for bulk loads and
large dataset sorts. These things mean that it is suitable for data warehousing
and on line operations, with the proviso that large data loads and some large
summary queries may be unpleasantly slow.

ASK -In brief, these tests need to be performed again, certainly for
Informix but most likely for Oracle and the rest as well, with
an eye to more accurately portraying the performance and features
of each.  More care is needed.

[Benchmark code SNIPPED]

Art S. Kagel


--------------------------------------------------------------------------------
Plain view
>> RE: a comparison of 4 databases by Art S. Kagel (10-12-1999; 18.5kb)
Re: [GENERAL] RE: a comparison of 4 databases from kaiq@realtyideas.com (10-12-1999; 19.8kb)
Search  |   Search for selection   |   Fresh postings  |   About

--------------------------------------------------------------------------------

Search engine provided by Xware team, 2001

======================================================



PostgreSQL mailing list archive
Search  |   Search for selection   |   Fresh postings  |   About

Message basket: Add

Author: Mark Kirkwood <markir@hnz.co.nz>
Date: Tue 16 Nov 18:38:46 1999 EST
Subject: a comparison of 4 databases

A Comparison Of 4 Databases
---------------------------



Intro
-----

This paper shows the results of an evaluation of 4 databases. I am posting it
to this mail group as I think Postgresql emerged quite favourably.

The evaluated databases were Oracle, Informix, Mysql and Postgresql.

Features and performance were examined.



Hardware And Operating System
-----------------------------

2 x HP Vertra VE 7 each with 160M RAM + 1x3.2G + 1x13G Quantum IDE Drives were used.
Redhat 6.0 was used as the operating system. No kernel changes were made.



Initial Experiences
-------------------

Mysql was obtained in rpm format and was amazingly easy to install. The
installation process created and started a database. The version was 3.22.27

Documentation was supplied and was good.


Postgresql was similarly elementary to install, and again a database was
created and started. The product comes with the flavour of Linux used and
was in rpm format. The version was 6.5.2

Documentation was supplied and was very good.


Informix was more cryptic to install. It was obtained in rpm format and
installed. However this merely installed an archive and the real installation
process had to be run thereafter. After this it had to be divined as to what
was required next  - the install does not create a database.
Using some of the (not supplied) documentation it was discovered how to create
and configure a database. The version was 7.30 ( This is old, but all they
are supplying on this platform - 9.x is current)

Documentation was not supplied, it was available on the Informix web site. It is ok.


Oracle was difficult to judge as the author frequently installs it. However
pretending to be coming to it new, it would be very difficult to install.
It does not come in rpm format. It is downloadable from the Oracle web site.
The small amount of included documentation is sufficient to enable someone
to work out how to start the installer program. This program is a rudimentary
wizard that asks questions and presents a list of components to choose....
a newcomer would suffer confusion here. The installer can create a database as
part of the install. The version was 8.0.5 (this is slightly old - 8.1.5 is
Current but buggy, 8.0.5 is the latest stable release on this platform).

Documentation is not supplied, it is available from the Oracle web site. It is
ok.



Tests And results
-----------------

Database Feature Comparison

Database   Cost   Trans   Row   Const   Program  Sec  Fail  Hot
                   actions Lock  raints  mable    ure  Safe  back

Mysql      0 /3000 No      No    No      Partial  Yes  No    No
Postgresql 0       Yes     Yes   Partial Yes      Yes  Yes   No
Oracle     3200    Yes     Yes   Yes     Yes      Yes  Yes   Yes
Informix   2000    Yes     No    Yes     Yes      Yes  No    No


Cost

NZ$ for 10 user license. Two prices mean that the product is charged
for if resold as part of an application ( Mysql )
Support is not included

Transactions

Commit, rollback, isolation levels of at least read commited

Row Locking

select for update that locks only the rows selected and does not
block reads

Constraints

primary and foreign key, with ability to enable/ disable or drop / add
existence will give ""Partial"" and enable etc will give "Yes"

Programmable

create trigger, procedural language extensions to SQL
A "Partial" means that external functions only are supported

Secure

Requires username and password validation

Fail Safe

delete of 100 out of 100000 rows, commit ( if have it ) then power
off andon, check after power on - 999900 rows gets a "Yes"

Hot Backup

Can a consistent backup of the database be run backup while it is up
with transactions performed against it.



Database Performance Comparison - Data Warehouse

Database    Bulk Load  Summarize 3%  Summarize 0.3%  Summarize 0.3%
            1M         of 3M         of 3M           of 3M
                       1 dim 1 fact  2 dim 1 fact    3 dim 1 fact

Mysql       20         14            90              57
Postgresql  420        16            4               7
Oracle      65         5             3               3
Informix    170        8             5               6

Notes



Bulk Load

elapsed seconds to load 1000000 rows via whatever bulk load tool is
supplied.

Summarize 3%
1 dim + 1 fact

Measure elapsed seconds to display summarized count and one timelike
dimension attribute for basic star query
Access path can be via an index scan

Summarize 0.3%
2 dim + 1 fact

Measure elapsed seconds to display summarized count and one non timelike
dimesion attribute for less basic star query
Access path can be via  index scans

Summarize 0.3%
3 dim + 1 fact

Measure elapsed seconds to display a summarized count and 1 non timelike
dimension attribute for more complex star query
Access path can be via  index scans



Database Performance Comparison - Online

Database    Create  Create  Query 1  Query 4  Query Summary
            10K     1M      of 10K   of 1M    10% of 1M

Mysql       7       891     0        0        1
Postgresql  21      4430    0        0        2
Oracle      31      3694    0        0        2
Informix                    0        0        10


Database    Tpm     Tpm     Tpm      Tpm
            1 sess. 2 sess. 4 sess.  8 sess.

Mysql       59/58   59/115  59/229   58/425
Postgresql  48      90      169      233
Oracle      55      108     180      291
Informix



Notes

Unfortunately no Informix SDK was available, so there is no result for
the first two or last tests.

Create 10K

elapsed seconds for Php app to insert 10000 rows one by one

Create 1M

elapsed seconds for Php app to insert 1000000 rows one by one


Query 1

0 seconds means that no delay was measurable
Measure elapsed seconds to show master record 1 row located 70% though
the table. Access path can be via an index scan

Query 4

Measure elapsed seconds to display 4 detail rows for one of the master
records in previous test. Access path can be via  index scans

Query Summary

Measure elapsed seconds to display a summarized sum and count
for 5% of 1000000 rows. This is a 2 table join . Access path can be via
index scans

Tpm n sessions

Transactions per minute for n sessions, achievable for lightweight Perl
DBI application. Two results for Mysql refer to two possible locking
schemes


Analysis
--------

Features

Oracle clearly has the most features. However it is Postgresql that is next in
line.

The features fail safe, transactions and security are seen as essential,
with row locking as highly desirable.

This means that  at face value only Oracle and Postgresql satisfy the criteria.

Initially Postgresql did not force password entry and thus was not secure,
however it was discovered that access to the database is configured at install
time as trusted and has to be changed to require passwords.

It should be noted that Oracle needed a patch to be fail safe, and that this
was not advertised on the web site, thus is possible that Informix and Mysql
can also be similarly patched.

Repeated tests with Informix page level locks showed that readers were blocked at this point. This was viewed as
extremely undesirable.

Mysql's lack of transactions was a killer for it, the complexity of having to
programmatically undo an n-table operation was viewed as prohibitive.
( It was noted that the Mysql to do list had atomic operations - pseudo
transactions, on it .)

In conclusion on the features front, Oracle and Postgresql emerge as the leaders.



Performance

1 Online operations

Initially Postgreql refused to use indexes to help with queries. A mail to one of the Postgresql Development Team
traced this to an unusual pickiness with respect to the implied datatypes of constants in the where clause.


Informix had problems with the summary query, it would not go faster that 10s, however it seemed to perform ok
for the 10000 and 1000000 query searches.

Mysql demonstrates the overhead associated with multiple versioning and
transactions. It was obviously the fastest raw speed terms. It was in
general 4-5 times faster than anything else.

Postgresql was in general about 20% slower than Oracle.

The multiple session transaction test is most interesting. The idea was to
mimic a Tpc A style banking application with some user think time during the
transaction (1 second ).
Clearly Mysql with its table level locks could not scale at all. However it has
application locks that are nameable, so can mimic row locks - as long as every
access uses them. If these were turned on then a dramatic turnaround was
observed.

Thus Mysql is fastest, and most scalable if applications locks can be used.
Oracle and Postgreql are similar in scalability, but Postgresql begins to tail off a little before Oracle does.


2 Data warehousing operations

Mysql has a very fast bulk load facility.
Oracle also has a very fast bulk load.
Infomix has a reasonably fast one.
Postgresql is noticeably slower than any of the others.

Mysql performed extremely poorly at the star type queries.
Oracle and Informix performed very well.
Postgresql performed very well in all but the first query - the simplest (ironically), but it scanned the most
data. This points to Oracle and Informix having faster Nested Loop or Sort algorithms.

Both Oracle and Postgresql would experience a period of poor performance on a table immediately after it was bulk
loaded - typically until it was vacuumed or analyzed.

In conclusion for this section Oracle, Informix are very good.
Postgresql is good but is hampered by slow bulk load and sorting of large datasets.
Mysql can get the data in fast but is poor at querying it.


Overall
-------

Informix performs mostly ok, but its locking scheme precludes it for serious on line use (it would have been interesting
to test this).
Oracle performs well.
Mysql's lack of transactions would have been ok for data warehousing, but it could not do star queries. This rules
it out.
Postgresql performed about 20% slower than Oracle, except for bulk loads and large dataset sorts. These things
mean that it is suitable for data warehousing and on line operations, with the proviso that large data loads and
some large summary queries may be unpleasantly slow.



Appendix

( database schemas and source for programs )

Schema and queries for on line tests

/* -------------------------------------------------------------------
   file     : createupdattables.sql
   does     : create tables for updat example...
   notes    : master has 10000 rows
              detail has 1000000 rows 100 for each master row
   ------------------------------------------------------------------*/

create table master
  (
   mas_id                         int4,
   mas_name                       varchar(100),
   mas_amt                        float8
  );

create table detail
  (
   det_id                          int4,
   det_mas_id                      int4,
   det_date                        datetime,
   det_amt                         float8
  );

create table masterlog
  (
    log_mas_id                   int4,
    log_date                     datetime);



/* -----------------------------------------------------------------
   file     : createupdatindexes.sql
   does     : create indexes and keys for tables...
   ----------------------------------------------------------------- */

create unique index mas_pk on master using btree (mas_id);

create index det_pk on detail using btree (det_id);
create index det_fk on detail using btree (det_mas_id);



/* -----------------------------------------------------------------
   file     : queries1-3.sql
   does     : the queries...
   ----------------------------------------------------------------- */



select *
from master
where mas_id = 7000;


select *
from detail
where det_mas_id = 7000
and   det_amt    > 960;



select sum(mas_amt),count(*)
from detail,master
where mas_id > 8000
and   mas_id < 9000
and mas_id = det_mas_id;



#!/usr/bin/perl
# -----------------------------------------------------------------
# file     : updat.pm
# does     : on line transactions test...
#
# notes    : postgres version
# -----------------------------------------------------------------

sub  dbconnect()
{
  # connect with no autocommit...
  #
  $dbh = DBI->connect('DBI:Pg:dbname=dev1',$user,$pwd,{AutoCommit =>
0})
              or die "Couldn't connect to database: " . DBI->errstr;
}


sub  dbdisconnect()
{
  #  disconnect...
  #
  $dbh->disconnect;
}


sub  dbparse()
{
   #  parse all statements here ( actually some databases do nothing
here...
   #

   #  master select and update...
   #
   $sthmsel = $dbh->prepare("select * from master where mas_id = ? for
update")
                or die "Couldn't prepare statement: " . $dbh->errstr;

   $sthmupd = $dbh->prepare("update master set mas_amt = mas_amt + ?
where mas_id = ?")
                or die "Couldn't prepare statement: " . $dbh->errstr;

   #  detail select and update...
   #
   $sthdsel = $dbh->prepare("select * from detail where det_mas_id = ?
and det_date > '1999-12-31' for update")
                or die "Couldn't prepare statement: " . $dbh->errstr;

   $sthdupd = $dbh->prepare("update detail set det_amt = det_amt + ?
where det_mas_id = ? and det_id =?")
                or die "Couldn't prepare statement: " . $dbh->errstr;

   #  log insert...
   #
   $sthlins = $dbh->prepare("insert into masterlog values(?,datetime
'now')")
                or die "Couldn't prepare statement: " . $dbh->errstr;
}


sub  dbfree()
{
   # free master and detail and log statements...
   #
   $sthmsel->finish;
   $sthmupd->finish;
   $sthdsel->finish;
   $sthdupd->finish;
   $sthlins->finish;
}


sub  putlog()
{
   # execute the log insert...
   #
   $sthlins->execute($masid);


}


sub  getdetail()
{
   #  execute and fetch detail query...
   #
   $sthdsel->execute($masid);
   my @data = $sthdsel->fetchrow_array();
   my $detid = $data[0];

   #  execute detail update...
   #
   $sthdupd->execute($amt,$masid,$detid);

}


sub  getmaster()
{

   #  execute and fetch master query...
   #
   $sthmsel->execute($masid);

   my @data = $sthmsel->fetchrow_array();

   #  user typing allowamce
   #
   if ( $sleep == 0 )
     {
     sleep(1);
     }


   # get and update the detail...
   #
   getdetail;


   #  execute master update...
   #
   $sthmupd->execute($amt,$masid);


   # log the transaction...
   #
   putlog;

   # commit...
   #
   my $rc = $dbh->commit
            or die $dbh->errstr;
}


sub  init()
{
  use DBI;

  #  two variables are "on" if set to zero
  #
  $debug    = 1;
  $sleep    = 0;

  $updatcnt = 0;
  $updatlim = 100;

  $amt      = 10;
  $maslim   = 10000;
  $masid    = 0;

  $begin    = 0;
  $end      = 0;
  $elapsed  = 0;

  $user     = "updat";
  $pwd      = "updat";
  $db       = "dev1";

  printf("  beginning $updatlim transactions...\n");
  $begin = time;

  #  connect ...
  #
  dbconnect;

  #  parse all statements...
  #
  dbparse;

  #  loop as required...
  #

  while ( $updatcnt < $updatlim )
  {
    #  get a random master id...
    #
    $masid     =  int ( rand $maslim ) + 1;
    if ( $debug == 0 )
      {
      printf("  processing master $masid \n");
      }
    getmaster;
    $updatcnt = $updatcnt + 1;

  }

  #  calculate stats...
  #
  $end = time;
  $elapsed = $end - $begin;
  printf("  tranasctions = $updatlim\n");
  printf("  elapsed      = $elapsed\n");

  #  free all statement handles...
  #
  dbfree;

  # disconnect...
  #
  dbdisconnect;
}

init;




Schema and queries for warehouse tests

/* -----------------------------------------------------------------
   file     : createwaretables.sql
   does     : create tables for ware example...
   notes    : dimension tables (dim0-2) have 900, 10000 and 1000
              rows resp.
              fact table (fact0) has 3000000 rows.
   ---------------------------------------------------------------- */

create table dim0
  (
   d0key                         int4,
   d0f1                          datetime,
   d0f2                          int4,
   d0f3                          int4,
   d0f4                          int4
  );

create table dim1
  (
   d1key                         int4,
   d1f1                          varchar(20),
   d1f2                          varchar(20)
  );

create table dim2
  (
   d2key                         int4,
   d2f1                          varchar(20),
   d2f2                          varchar(20)
  );

create table fact0
  (
  d0key                          int4,
  d1key                          int4,
  d2key                          int4,
  f1                             int4,
  f2                             int4
  );



/* -----------------------------------------------------------------
   file     : createwareindexes.sql
   does     : create indexes for ware example...
   ----------------------------------------------------------------- */

create unique index dim0_pk on dim0 using btree (d0key);
create unique index dim1_pk on dim1 using btree (d1key);
create unique index dim2_pk on dim2 using btree (d2key);
create index fact0_q1 on fact0 using btree (d0key);
create index fact0_q2 on fact0 using btree (d0key,d1key);
create index fact0_q3 on fact0 using btree (d0key,d1key,d2key);


/* -----------------------------------------------------------------
   file     : queries1-3.sql
   does     : star queries for warehouse...
   notes    : query 1 scans 100000 rows from fact0 and 30 rows
              from dim0

              query 2 scans 10000 rows from fact0 and
              30 rows from dim0 and 10 rows from dim2

              query 3 scans 10000 rows from fact0 and 30 rows
              from dim0 and 10 rows from dim2 and 100 rows from dim1
   ----------------------------------------------------------------- */


select
       d0.d0f1,
       count(f.f1)
from dim0 d0,
     fact0 f
where d0.d0key = f.d0key
and   d0.d0f1 between '1996-05-01' and '1996-05-31'
group by d0.d0f1
;


select
       d0.d0f1,
       d2.d2f2,
       count(f.f1)
from dim0 d0,
     dim2 d2,
     fact0 f
where d0.d0key = f.d0key
and   d2.d2key = f.d2key
and   d2.d2f2  = '90th att type'
and   d0.d0f1  between  '1996-05-01' and '1996-05-31'
group by d0.d0f1,d2.d2f2
;


select
       d0.d0f1,
       d1.d1f2,
       d2.d2f2,
       count(f.f1)
from dim0 d0,
     dim1 d1,
     dim2 d2,
     fact0 f
where d0.d0key = f.d0key
and   d1.d1key = f.d1key
and   d2.d2key = f.d2key
and   d2.d2f2 between '80th att type' and '90th att type'
and   d1.d1f2 between '10th att type' and '50th att type'
and   d0.d0f1 between '1996-05-01' and '1996-05-31'
group by d0.d0f1,d1.d1f2,d2.d2f2
;


Scripts to populate tables

Data Warehouse

#!/usr/bin/perl
#  --------------------------------------------------------------------------
#  file     : popdim0.pm
#  does     : populate the dim0 timelike dimension...
#  --------------------------------------------------------------------------


sub  adddim()
{
  #  parse and execute the insert...
  #
  $sthins = $dbh->prepare("insert into dim0 values (?,('1999-05-01'::datetime + ?)::datetime,date_part('DAY',('1999-05-01'::datetime
+ ?)::datetime),date_part('MONTH',('1999-05-01'::datetime + ?)::datetime) )")
            or die "  could not prepare \n";

  $sthins->execute($dimcnt,$dimcnt,$dimcnt,$dimcnt)
           or die "  failed to execute for $dimcnt\n";
}


sub  attachdb()
{
  #  connect to the database...
  #
  $dbh = DBI->connect($datasource, $user, $pwd,{ AutoCommit => 0 })
         or die "cannot connect to $datasource\n";

}


sub  unattachdb()
{
  #  commit and disconnect...
  #
  $dbh->commit;
  $dbh->disconnect();
}


sub  init()
{
  #  setup and insert $dimlim rows for the timelike
  #  dimension...
  #
  #
  use DBI;

  $datasource  = "DBI:Pg:dbname=dev1";
  $user        = "ware";
  $pwd         = "ware";
  $dbh         = 0;
  $sthins      = 0;

  $dimlim      = 900;
  $dimcnt      = 0;

  attachdb();

  while ( $dimcnt < $dimlim )
    {
    if ( $dimcnt%100 == 0 )
      {
      printf("processing ...$dimcnt\n");
      }
    adddim();
    $dimcnt = $dimcnt + 1;
    }

  unattachdb();
}

init();

#!/usr/bin/perl
#  --------------------------------------------------------------------------
#  file     : popdim1.pm
#  does     : populate the dim1 dimension...
#  --------------------------------------------------------------------------


sub  adddim()
{
  #  parse and execute the insert...
  #
  $sthins = $dbh->prepare("insert into dim1 values (?,? ||'th attribute',?%100 ||'th att type' )")
            or die "  could not prepare \n";

  $sthins->execute($dimcnt,$dimcnt,$dimcnt)
           or die "  failed to execute for $dimcnt\n";
}


sub  attachdb()
{
  #  connect to the database...
  #
  $dbh = DBI->connect($datasource, $user, $pwd,{ AutoCommit => 0 })
         or die "cannot connect to $datasource\n";

}


sub  unattachdb()
{
  #  commit and disconnect...
  #
  $dbh->commit;
  $dbh->disconnect();
}


sub  init()
{
  #  setup and insert $dimlim rows for the timelike
  #  dimension...
  #
  #
  use DBI;

  $datasource  = "DBI:Pg:dbname=dev1";
  $user        = "ware";
  $pwd         = "ware";
  $dbh         = 0;
  $sthins      = 0;

  $dimlim      = 10000;
  $dimcnt      = 0;

  attachdb();

  while ( $dimcnt < $dimlim )
    {
    if ( $dimcnt%1000 == 0 )
      {
      printf("processing ...$dimcnt\n");
      }
    adddim();
    $dimcnt = $dimcnt + 1;
    }

  unattachdb();
}

init();

#!/usr/bin/perl
#  --------------------------------------------------------------------------
#  file     : popdim2.pm
#  does     : populate the dim2 dimension...
#  --------------------------------------------------------------------------


sub  adddim()
{
  #  parse and execute the insert...
  #
  $sthins = $dbh->prepare("insert into dim2 values (?,? ||'th attribute',?%100 ||'th att type' )")
            or die "  could not prepare \n";

  $sthins->execute($dimcnt,$dimcnt,$dimcnt)
           or die "  failed to execute for $dimcnt\n";
}


sub  attachdb()
{
  #  connect to the database...
  #
  $dbh = DBI->connect($datasource, $user, $pwd,{ AutoCommit => 0 })
         or die "cannot connect to $datasource\n";

}


sub  unattachdb()
{
  #  commit and disconnect...
  #
  $dbh->commit;
  $dbh->disconnect();
}


sub  init()
{
  #  setup and insert $dimlim rows for the timelike
  #  dimension...
  #
  #
  use DBI;

  $datasource  = "DBI:Pg:dbname=dev1";
  $user        = "ware";
  $pwd         = "ware";
  $dbh         = 0;
  $sthins      = 0;

  $dimlim      = 1000;
  $dimcnt      = 0;

  attachdb();

  while ( $dimcnt < $dimlim )
    {
    if ( $dimcnt%100 == 0 )
      {
      printf("processing ...$dimcnt\n");
      }
    adddim();
    $dimcnt = $dimcnt + 1;
    }

  unattachdb();
}

init();

#!/usr/bin/perl
#  --------------------------------------------------------------------------
#  file     : popfact0.pm
#  does     : populate the fact0 fact...
#  --------------------------------------------------------------------------


sub  addfact()
{
  #  parse and execute the insert...
  #
  $sthins = $dbh->prepare("insert into fact0 values (?,?,?,100,100)")
            or die "  could not prepare \n";

  $sthins->execute($d0key,$d1key,$d2key)
           or die "  failed to execute for $factcnt\n";
}


sub  attachdb()
{
  #  connect to the database...
  #
  $dbh = DBI->connect($datasource, $user, $pwd,{ AutoCommit => 0 })
         or die "cannot connect to $datasource\n";

}


sub  unattachdb()
{
  #  disconnect...
  #
  $dbh->disconnect();
}


sub  commitdb()
{
  #  commit...
  #
  $dbh->commit;
}


sub  init()
{
  #  setup and insert $dimlim rows for the timelike
  #  dimension...
  #
  #
  use DBI;

  $datasource  = "DBI:Pg:dbname=dev1";
  $user        = "ware";
  $pwd         = "ware";
  $dbh         = 0;
  $sthins      = 0;

  #  set up to add  $dim0lim *  $dim1lim *  $dim2lim rows...
  #
  $dim0lim      = 30;
  $dim1lim      = 1000;
  $dim2lim      = 100;
  $dim0cnt      = 1;
  $dim1cnt      = 1;
  $dim2cnt      = 1;
  $factcnt      = 1;
  $begin        = time();
  $now          = 0;
  $elapsed      = 0;

  attachdb();

  #  do all the loops...
  #
  while ( $dim0cnt <=  $dim0lim )
    {
    $d0key = 30 * $dim0cnt;
    while (  $dim1cnt <=  $dim1lim )
      {
      $d1key = 10 * $dim1cnt;
      while (  $dim2cnt <=  $dim2lim )
        {
        $d2key = 10 * $dim2cnt;

        if ( $factcnt%10000 == 0 )
          {
          $now = time();
          $elapsed = ($now - $begin)/ 60;
          printf("processed ...$factcnt in $elapsed min\n");
          commitdb();
          }
        addfact();
        $factcnt = $factcnt + 1;

        $dim2cnt = $dim2cnt + 1;
        }
      $dim1cnt = $dim1cnt + 1;
      $dim2cnt = 1;
      }
    $dim0cnt = $dim0cnt + 1;
    $dim1cnt = 1;
    $dim2cnt = 1;
    }

  commitdb();
  unattachdb();
}

init();



More scripts to populate tables

On line tables










  Populate Master on
  --------------------------------------------------------------------------------
















  Populate Detail on
  --------------------------------------------------------------------------------








Search  |   Search for selection   |   Fresh postings  |   About

--------------------------------------------------------------------------------

Search engine provided by Xware team, 2001

========================================================================





PostgreSQL mailing list archive
Search  |   Search for selection   |   Fresh postings  |   About

Message basket: Add

Author: Sebastien FLAESCH <sf@4js.com>
Date: Tue 17 Oct 07:00:02 2000 EDT
Subject: Which API should I use ?

Hi all,

I am looking for the right PostgreSQL API (interface) to be used
to write a db driver for our 4gl virtual machine (www.4js.com).

As most database drivers, dynamic SQL must be supported, where SQL
parameters are unknown at (driver) compile time.

So I need some feature like ODBC's SQLBindCol()/SQLBindParameter()
to implement this driver.

I think the driver cannot be implemented with Postgre's E-SQL C,
because the current ecpg version does not support "DESCRIPTORs" or
"SQLDA" as INFORMIX ESQL/C, to manage SQL parameters dynamically.

I know PostgreSQL supports and ODBC interface for both UNIX and NT,
but I would like to use a native interface. I do not want to install
an ODBC driver manager like iodbc or ApplixWare.

I would like to use a native API like the Oracle Call Interface or
the IBM DB2 Call Level Interface.

Does this kind of interface exist for Postgre SQL ?
As far as I know, libpq is not the right way because you cannot
manage SQL parameters dynamically...

Current ODBC solution is ODBC 2 compliant, what about ODBC 3 ?
I found the 'src/cli' directory but these are only examples.
Is this an ODBC 3 project ?
Where is the interface library ?

Who can I contact to discuss or send my requets ?

Thanks!
--
Sebastien FLAESCH [sf@4js.com]
Four J's Development Tools [http://www.4js.com]
Tel: +33(0)3-88-18-61-24 Fax: +33(0)3-88-18-61-21

==========================================================



############################## EOF #############################


