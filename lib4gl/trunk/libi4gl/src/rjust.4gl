head	1.4;
access;
symbols;
locks; strict;
comment	@# @;


1.4
date	90.04.05.11.02.07;	author john;	state Exp;
branches;
next	1.3;

1.3
date	89.12.08.15.33.21;	author john;	state Exp;
branches;
next	1.2;

1.2
date	89.08.03.09.31.05;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.05.05.10.08.10;	author john;	state Exp;
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
	@@(#)$Id: rjust.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Right justify and truncate a string
	@@(#)Author: JL
}

FUNCTION rjust(s, i)

	DEFINE
		sccs	CHAR(1),
		s		CHAR(512),
		i		INTEGER,
		len		INTEGER,
		t		CHAR(512),
		x		CHAR(512)

	LET len = LENGTH(s)
	IF len IS NULL OR len < 0 THEN
		LET len = 0
		LET sccs = "@@(#)$Id: rjust.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
	END IF
	LET x = "   "
	CASE
	WHEN len >= i
		LET t =	s[1, i]
	WHEN len > 0
		LET t =	x[1, i-len], s[1, len]
	OTHERWISE
		LET t = x[1, i]
	END CASE

	RETURN t CLIPPED

END FUNCTION {rjust}
@


1.3
log
@Revamp header; use len instead of l
@
text
@d11 6
a16 5
		s	CHAR(512),
		i	INTEGER,
		len	INTEGER,
		t	CHAR(512),
		x	CHAR(512)
d19 4
a22 1
	IF len IS NULL OR len < 0 THEN LET len = 0 END IF
@


1.2
log
@Return string which is truncated/clipped to correct length
@
text
@d3 2
a4 2
	@@(#)KPI Database Project: General Library
	@@(#)Right justify (and truncate) a character string to x characters
d11 5
a15 5
		s CHAR(512),
		i INTEGER,
		l INTEGER,
		t CHAR(512),
		x CHAR(512)
d17 2
a18 2
	LET l = LENGTH(s)
	IF l IS NULL OR l < 0 THEN LET l = 0 END IF
d21 1
a21 1
	WHEN l >= i
d23 2
a24 2
	WHEN l > 0
		LET t =	x[1, i-l], s[1, l]
@


1.1
log
@Initial revision
@
text
@d11 1
a11 1
		s CHAR(80),
d14 2
a15 2
		t CHAR(80),
		x CHAR(80)
d29 1
a29 1
	RETURN t
@
