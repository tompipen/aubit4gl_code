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
date	90.08.14.11.09.21;	author john;	state Exp;
branches;
next	;


desc
@@


2.3
log
@Detab new headers
@
text
@-- @@(#)$Id: findstr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)Purpose:     Find index of where string occurs in string
-- @@(#)Author:      Jonathan Leffler
-- @@(#)Product:     :PRODUCT:

FUNCTION find_string(str, s)

	DEFINE
		str		CHAR(80),	{ String to be searched }
		s		CHAR(80),	{ String to be found (more than 1 char please) }
		c		CHAR(1),
		rcs		CHAR(1),
		l1		INTEGER,
		l2		INTEGER,
		f		INTEGER,
		i		INTEGER,
		j		INTEGER,
		k		INTEGER

	LET l1 = length(str)
	LET l2 = length(s)
	LET c  = s[1]

	FOR i = 1 TO l1 - l2 + 1
		IF str[i] = c THEN
			LET k = i + 1
			LET j = 2
			LET f = TRUE
			WHILE j <= l2
				IF str[k] != s[j] THEN
					LET f = FALSE
					EXIT WHILE
				END IF
				LET j = j + 1
				LET k = k + 1
			END WHILE
			IF f = TRUE THEN
				RETURN i
			END IF
		END IF
	END FOR

	RETURN 0

	LET rcs = "@@(#)$Id: findstr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"

END FUNCTION {find_string}
@


2.2
log
@Revamp headers with :PRODUCT: information.
@
text
@d1 4
a4 4
-- @@(#)$Id: findstr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)Purpose:		Find index of where string occurs in string
-- @@(#)Author:		Jonathan Leffler
-- @@(#)Product:		:PRODUCT:
d45 1
a45 1
	LET rcs = "@@(#)$Id: findstr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


2.1
log
@Change sccs to rcs and Sphinx to JLSS
@
text
@d1 4
a4 6
{
	@@(#)$Id: findstr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)JLSS Informix Tools: General Library
	@@(#)Find index of where string occurs in string
	@@(#)Author: JL
}
d45 1
a45 1
	LET rcs = "@@(#)$Id: findstr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


1.1
log
@Initial revision
@
text
@d2 2
a3 2
	@@(#)$Id: findstr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
d14 1
a14 1
		sccs	CHAR(1),
d47 1
a47 1
	LET sccs = "@@(#)$Id: findstr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@
