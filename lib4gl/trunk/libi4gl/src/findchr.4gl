head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	98.09.30.21.23.57;	author jleffler;	state Exp;
branches;
next	1.1;

1.1
date	98.09.30.21.21.25;	author jleffler;	state Exp;
branches;
next	;


desc
@I4GL find_character() analogue of strchr()
@


1.2
log
@Fix up.  Remove redundant variables.
@
text
@-- @@(#)$Id: findchr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)Purpose:     Find index of where string occurs in string
-- @@(#)Author:      Jonathan Leffler
-- @@(#)Product:     :PRODUCT:

FUNCTION find_character(str, c)

	DEFINE
		str		CHAR(80),	{ String to be searched }
		c		CHAR(1),	{ Character to be found }
		rcs     CHAR(1),
		len		INTEGER,
		i		INTEGER

	LET len = length(str)

	FOR i = 1 TO len
		IF str[i] = c THEN
			RETURN i
		END IF
	END FOR

	RETURN 0

	LET rcs = "@@(#)$Id: findchr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"

END FUNCTION {find_character}
@


1.1
log
@Initial revision
@
text
@d1 1
a1 1
-- @@(#)$Id: findchr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
d6 1
a6 1
FUNCTION find_character(str, s)
d11 3
a13 8
		c		CHAR(1),
		rcs		CHAR(1),
		l1		INTEGER,
		l2		INTEGER,
		f		INTEGER,
		i		INTEGER,
		j		INTEGER,
		k		INTEGER
d15 1
a15 2
	LET l1 = length(str)
	LET c  = s[1]
d17 1
a17 1
	FOR i = 1 TO l1
d25 1
a25 1
	LET rcs = "@@(#)$Id: findchr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@
