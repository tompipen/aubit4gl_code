head	1.6;
access;
symbols;
locks; strict;
comment	@# @;


1.6
date	91.11.02.23.44.08;	author jl;	state Exp;
branches;
next	1.5;

1.5
date	91.08.19.22.25.29;	author jl;	state Exp;
branches;
next	1.4;

1.4
date	91.06.24.22.31.57;	author jl;	state Exp;
branches;
next	1.3;

1.3
date	91.05.09.17.32.36;	author johnl;	state Exp;
branches;
next	1.2;

1.2
date	90.11.28.11.28.19;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	89.12.15.10.30.27;	author john;	state Exp;
branches;
next	;


desc
@@


1.6
log
@Remove most of routines.  Replace by equivalent functionality
in errmsg.4gl
@
text
@-- @@(#)$Id: interr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Record internal, fatal, and program errors
-- @@(#)Author: JL

{ Record irrecoverable error }
FUNCTION fatal_error(s)

	DEFINE
		s		CHAR(512),
		sccs	CHAR(1)

	LET sccs = "@@(#)$Id: interr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
	CALL logerror(s)
	ERROR "A serious internal error has occurred -- please report to DBA"
	SLEEP 5
	EXIT PROGRAM 1

END FUNCTION {fatal_error}

{ Record error which can be survived }
FUNCTION internal_error(s)

	DEFINE
		s	CHAR(512)

	CALL logerror(s)
	ERROR "An internal error has been detected -- please report to DBA"
	SLEEP 3

END FUNCTION {internal_error}
@


1.5
log
@Add internal_msg*
@
text
@a31 74

{ Terminal error to be displayed to user }
FUNCTION program_error(s)

	DEFINE
		s		CHAR(512)

	ERROR s
	SLEEP 5
	CALL logerror(s)
	ERROR "Program terminating"
	SLEEP 3
	EXIT PROGRAM 1

END FUNCTION {program_error}

{ Report error with no delay }
FUNCTION immediate_error(s)

	DEFINE
		s	CHAR(78)

	ERROR s CLIPPED

END FUNCTION {immediate_error}

{ Report error with delay }
FUNCTION notify_error(s)

	DEFINE
		s	CHAR(78)

	ERROR s CLIPPED
	SLEEP 3

END FUNCTION {notify_error}

{ Report error number with delay }
FUNCTION notify_errno(s)

	DEFINE
		s	INTEGER

	CALL ERR_PRINT(s)
	SLEEP 3

END FUNCTION {notify_errno}

{ Report error number with delay }
FUNCTION notify_msgno(s)

	DEFINE
		s	INTEGER,
		m	CHAR(512)

	LET m = fgl_msgread(s)
	ERROR m CLIPPED
	SLEEP 3

END FUNCTION {notify_msgno}

{ Record error which can be survived }
FUNCTION internal_msgno(s)

	DEFINE
		s	INTEGER,
		m	CHAR(512)

	LET m = fgl_msgread(s)
	CALL logerror(m)
	ERROR m CLIPPED
	SLEEP 3

END FUNCTION {internal_msgno}
@


1.4
log
@Add more functions
@
text
@d79 27
@


1.3
log
@Update
@
text
@d47 32
@


1.2
log
@Improve
@
text
@d1 4
a4 7
{
	@@(#)$Id: interr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx informix Tools: Error handling
	@@(#)Record internal, fatal, and program errors
	@@(#)Assumes use of std_options
	@@(#)Author: JL
}
d37 1
a37 2
		s		CHAR(512),
		sccs	CHAR(1)
a38 1
	LET sccs = "@@(#)$Id: interr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


1.1
log
@Initial revision
@
text
@d4 1
a4 1
	@@(#)Record internal and fatal errors
d35 17
@
