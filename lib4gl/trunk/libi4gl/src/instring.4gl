head	2.3;
access;
symbols;
locks; strict;
comment	@# @;


2.3
date	98.08.20.20.19.20;	author jleffler;	state Exp;
branches;
next	2.2;

2.2
date	98.08.20.20.17.48;	author jleffler;	state Exp;
branches;
next	2.1;

2.1
date	98.07.08.18.56.30;	author jleffler;	state Exp;
branches;
next	1.1;

1.1
date	90.07.19.10.59.22;	author john;	state Exp;
branches;
next	;


desc
@@


2.3
log
@Detab new headers
@
text
@-- @@(#)$Id: instring.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)Purpose:     Find index of character in string
-- @@(#)Author:      Jonathan Leffler
-- @@(#)Product:     :PRODUCT:

FUNCTION instring(str, c)

	DEFINE
		str		CHAR(80),
		c		CHAR(1),
		rcs		CHAR(1),
		l		INTEGER,
		i		INTEGER

	LET l = length(str)

	FOR i = 1 TO l
		IF str[i] = c THEN
			RETURN i
		END IF
	END FOR

	RETURN 0

	LET rcs = "@@(#)$Id: instring.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"

END FUNCTION {instring}
@


2.2
log
@Revamp headers with :PRODUCT: information.
@
text
@d1 4
a4 4
-- @@(#)$Id: instring.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)Purpose:		Find index of character in string
-- @@(#)Author:		Jonathan Leffler
-- @@(#)Product:		:PRODUCT:
d25 1
a25 1
	LET rcs = "@@(#)$Id: instring.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


2.1
log
@Change sccs to rcs and Sphinx to JLSS
@
text
@d1 4
a4 6
{
	@@(#)$Id: instring.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)JLSS Informix Tools: General Library
	@@(#)Find index of character in string
	@@(#)Author: JL
}
d25 1
a25 1
	LET rcs = "@@(#)$Id: instring.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


1.1
log
@Initial revision
@
text
@d2 2
a3 2
	@@(#)$Id: instring.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
d13 1
a13 1
		sccs	CHAR(1),
d27 1
a27 1
	LET sccs = "@@(#)$Id: instring.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@
