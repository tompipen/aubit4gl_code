head	2.2;
access;
symbols;
locks; strict;
comment	@# @;


2.2
date	90.04.05.11.02.06;	author john;	state Exp;
branches;
next	2.1;

2.1
date	89.08.17.15.38.02;	author john;	state Exp;
branches;
next	1.6;

1.6
date	89.08.17.15.36.45;	author john;	state Exp;
branches;
next	1.5;

1.5
date	89.08.17.15.32.48;	author john;	state Exp;
branches;
next	1.4;

1.4
date	88.09.27.09.19.05;	author john;	state Exp;
branches;
next	1.3;

1.3
date	88.07.24.19.46.54;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.07.24.18.38.14;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.07.24.18.17.34;	author john;	state Exp;
branches;
next	;


desc
@@


2.2
log
@Add sccs string
@
text
@{
	@@(#)$Id: opendb.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Open a database reliably
	@@(#)Author: JL
}

DEFINE
	current_database	CHAR(10)

FUNCTION open_db(dbase)

	DEFINE
		sccs	CHAR(1),
		dbase	CHAR(10),
		retval	INTEGER

	LET dbase  = DOWNSHIFT(dbase)
	LET retval = -1

	WHENEVER ERROR CONTINUE

	{ Close current database, if any, ignoring errors }
	CLOSE DATABASE
	LET current_database = NULL
	LET STATUS = 0

	{ Open new database }
	DATABASE dbase
	IF STATUS = 0 THEN
		{ DATABASE statement can fail and return zero status }
		SELECT COUNT(*)
			INTO retval
			FROM Systables
		IF STATUS = 0 THEN
			LET retval = 0
			LET current_database = dbase
			LET sccs = "@@(#)$Id: opendb.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
		END IF
	END IF
	WHENEVER ERROR STOP

	RETURN retval

END FUNCTION {open_db}
@


2.1
log
@Strip out code tut mucks abart wiv Systables
@
text
@d13 1
d36 2
@


1.6
log
@Run it through fglfmt and endfunc
@
text
@a13 1
		dbname	CHAR(10),
d16 1
a16 1
	LET dbase = DOWNSHIFT(dbase)
d19 1
a19 10
	{ Check whether new database is same as old one }
	IF current_database = dbase THEN
		SELECT tabname
			INTO dbname
			FROM Systables
			WHERE Tabtype = 'D'
		IF STATUS = 0 AND dbname = dbase THEN
			LET retval = 0
		END IF
	END IF
d21 4
a24 2
	IF retval != 0 THEN
		WHENEVER ERROR CONTINUE
d26 7
a32 7
		{ Close current database, if any, ignoring errors }
		CLOSE DATABASE
		LET current_database = NULL
		LET STATUS = 0

		{ Open new database }
		DATABASE dbase
d34 1
a34 8
			{ DATABASE statement can fail and return zero status }
			SELECT COUNT(*)
				INTO retval
				FROM Systables
			IF STATUS = 0 THEN
				LET retval = 0
				CALL mk_dbname(dbase) RETURNING current_database
			END IF
a35 1
		WHENEVER ERROR STOP
d37 1
a41 41

{ Give a database a name record in Systables }
FUNCTION mk_dbname(dbname)

	DEFINE
		dbname	CHAR(10),
		dbpath	CHAR(14),
		curname	CHAR(10)

	SELECT Tabname
		INTO curname
		FROM Systables
		WHERE tabtype = 'D'

	{ If the insert/update fail, so be it: user is not a DBA }
	LET dbpath = dbname CLIPPED, ".dbs"
	WHENEVER ERROR CONTINUE
	IF STATUS = 0 THEN
		IF (curname != dbname OR curname IS NULL) THEN
			UPDATE Systables
				SET Tabname = dbname,
					Dirpath = dbpath
				WHERE Tabtype = 'D'
		END IF
	ELSE
		INSERT INTO
			Systables(Tabname, Owner, Dirpath, Tabid, Rowsize,
					  Ncols, Nindexes, Nrows, Created, Version,
					  Tabtype, Audpath)
			VALUES (dbname, "informix", dbpath, 10, 0, 0, 0, 0,
					TODAY, 1, "D", "")
	END IF
	WHENEVER ERROR STOP

	IF STATUS != 0 THEN
		LET dbname = NULL
	END IF

	RETURN dbname

END FUNCTION {mk_dbname}
@


1.5
log
@Improve inserted row
@
text
@d48 1
a48 1
				CALL mk_dbname(dbase) returning current_database
@


1.4
log
@Ignore error in mk_dbname
@
text
@d7 2
a8 2
	DEFINE
		current_database	CHAR(10)
d63 1
d72 1
d77 2
a78 1
				SET Tabname = dbname
d86 2
a87 1
			VALUES (dbname, USER, "", 10, 0, 0, 0, 0, TODAY, 1, "D", "")
@


1.3
log
@Refine test in mk_dbname
@
text
@d69 3
d79 4
a82 1
		INSERT INTO Systables
d85 1
@


1.2
log
@Check for database name
@
text
@d65 1
a65 1
	SELECT tabname
d69 6
a74 4
	IF STATUS = 0 AND (curname != dbname OR curname IS NULL) THEN
		UPDATE Systables
			SET Tabname = dbname
			WHERE Tabtype = 'D'
@


1.1
log
@Initial revision
@
text
@d7 2
d14 1
d17 1
a17 1
	LET dbase = DOWNSHIFT(dbase) { Probably unecessary }
d20 11
d36 1
a45 1
				WHERE Tabtype = 'D'
d48 1
d57 28
@
