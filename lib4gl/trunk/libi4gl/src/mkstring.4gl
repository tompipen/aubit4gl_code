head	1.4;
access;
symbols;
locks; strict;
comment	@# @;


1.4
date	90.07.19.11.03.55;	author john;	state Exp;
branches;
next	1.3;

1.3
date	90.05.31.13.24.14;	author john;	state Exp;
branches;
next	1.2;

1.2
date	90.05.21.13.57.04;	author john;	state Exp;
branches;
next	1.1;

1.1
date	90.01.17.11.44.50;	author john;	state Exp;
branches;
next	;


desc
@@


1.4
log
@Previous version untested!?!!!
@
text
@{
	@@(#)$Id: mkstring.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Create a string of replicated characters
	@@(#)Author: JL
}

FUNCTION mkstring(c, n)

	DEFINE
		c		CHAR(1),
		n		INTEGER,
		i		INTEGER,
		s		CHAR(512),
		sccs	CHAR(1)

	IF n > 512 THEN
		LET n = 512
	END IF
	FOR i = 1 TO n
		LET s[i] = c
	END FOR

	RETURN s[1,n]

	LET sccs = "@@(#)$Id: mkstring.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"

END FUNCTION {mkstring}
@


1.3
log
@Improve
@
text
@d17 1
a17 1
	IF n > 512
@


1.2
log
@Add sccs
@
text
@d17 3
d24 1
a24 1
	RETURN s CLIPPED
@


1.1
log
@Initial revision
@
text
@d11 5
a15 4
		c	CHAR(1),
		n	INTEGER,
		i	INTEGER,
		s	CHAR(512)
d22 2
@
