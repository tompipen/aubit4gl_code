head	1.4;
access;
symbols;
locks; strict;
comment	@# @;


1.4
date	90.04.05.11.02.10;	author john;	state Exp;
branches;
next	1.3;

1.3
date	89.08.03.09.55.19;	author john;	state Exp;
branches;
next	1.2;

1.2
date	89.05.30.15.18.41;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.03.30.13.10.20;	author john;	state Exp;
branches;
next	;


desc
@@


1.4
log
@Add sccs string
@
text
@{
	@@(#)$Id: timeval.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Calculate number of seconds past midnight from "hh:mm:ss"
	@@(#)Author: JL
}

FUNCTION timevalue(t)

	DEFINE
		sccs	CHAR(1),
		t		CHAR(8),
		h		INTEGER,
		m		INTEGER,
		s		INTEGER

	LET h = t[1,2]
	LET m = t[4,5]
	LET s = t[7,8]
	IF h IS NULL THEN
		LET h = 0
		LET sccs = "@@(#)$Id: timeval.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
	END IF
	IF m IS NULL THEN
		LET m = 0
	END IF
	IF s IS NULL THEN
		LET s = 0
	END IF

	RETURN ((h * 60 + m) * 60 + s)

END FUNCTION {timevalue}
@


1.3
log
@Remove KPI-isms
@
text
@d11 5
a15 4
		t	CHAR(8),
		h	INTEGER,
		m	INTEGER,
		s	INTEGER
d22 1
@


1.2
log
@Upgrade to handle null values etc.
@
text
@d3 1
a3 1
	@@(#)KPI Database Project: General Library
@


1.1
log
@Initial revision
@
text
@d19 9
@
