head	1.7;
access;
symbols;
locks; strict;
comment	@# @;


1.7
date	91.10.12.07.38.37;	author jl;	state Exp;
branches;
next	1.6;

1.6
date	90.11.16.16.54.09;	author johnl;	state Exp;
branches;
next	1.5;

1.5
date	90.04.05.11.02.11;	author john;	state Exp;
branches;
next	1.4;

1.4
date	89.05.26.14.49.38;	author john;	state Exp;
branches;
next	1.3;

1.3
date	88.07.20.20.14.39;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.07.20.20.13.11;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.02.19.15.43.27;	author john;	state Exp;
branches;
next	;


desc
@@


1.7
log
@Prevent it from crashing
@
text
@-- @@(#)$Id: translog.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Handle transactions whether database has log or not
-- @@(#)Author: JL

DEFINE
	logstatus	INTEGER
	{ 0 => State of log unknown, 1 => Log absent, 2 => Log present }

{ Determine whether there is a transaction log }
FUNCTION	translog()

	DEFINE
		sccs	CHAR(1),
		logs	INTEGER

	IF logstatus = 0 THEN
		LET sccs = "@@(#)$Id: translog.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
		LET logs = get_databaselogs()
		IF logs = FALSE THEN
			LET logstatus = 1 { Log absent }
		ELSE
			LET logstatus = 2 { Log present }
		END IF
	END IF

	RETURN (logstatus = 2)

END FUNCTION {translog}

{ Begin a transaction if there is a log }
FUNCTION begin_work()

	IF translog() THEN
		WHENEVER ERROR CONTINUE
		BEGIN WORK
		WHENEVER ERROR STOP
	END IF

END FUNCTION {begin_work}

{ Commit a transaction if there is a log }
FUNCTION commit_work()

	IF translog() THEN
		WHENEVER ERROR CONTINUE
		COMMIT WORK
		WHENEVER ERROR STOP
	END IF

END FUNCTION {commit_work}

{ Rollback transaction if there is a log }
FUNCTION rollback_work()

	IF translog() THEN
		WHENEVER ERROR CONTINUE
		ROLLBACK WORK
		WHENEVER ERROR STOP
	END IF

END FUNCTION {rollback_work}

{ Terminate a transaction }
FUNCTION end_work(state)

	DEFINE
		state	INTEGER

	IF state != 0 THEN
		CALL rollback_work()
	ELSE
		CALL commit_work()
	END IF

END FUNCTION {end_work}
@


1.6
log
@Better testing for logging of database via get_databaselogs()
@
text
@d1 4
a4 6
{
	@@(#)$Id: translog.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Handle transactions whether database has log or not
	@@(#)Author: JL
}
a5 1
{ Global to this file -- not accessible outside }
d18 1
a23 1
			LET sccs = "@@(#)$Id: translog.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
d35 1
d37 1
d46 1
d48 1
d57 1
d59 1
@


1.5
log
@Add sccs string
@
text
@d18 1
a18 1
		junk	INTEGER
d21 2
a22 6
		WHENEVER ERROR CONTINUE
		SELECT Tabid
			INTO junk
			FROM Systables
			WHERE Systables.Tabtype = 'L'
		IF STATUS != 0 THEN
a27 1
		WHENEVER ERROR STOP
@


1.4
log
@Fix heading
@
text
@d17 1
d30 1
@


1.3
log
@Add some error protection
@
text
@d3 1
a3 1
	@@(#)KPI Database Project: General Library
@


1.2
log
@Remove database line -- unnecessary
@
text
@d20 1
d25 1
a25 1
		IF STATUS = NOTFOUND THEN
d30 1
@


1.1
log
@Initial revision
@
text
@a7 2
DATABASE KPI

@
