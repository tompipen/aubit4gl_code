head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	91.05.09.18.12.18;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	90.10.04.17.06.04;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Upgrade
@
text
@-- @@(#)$Id: chtoint.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Convert string to integer
-- @@(#)Author: JL

{
MAIN

	DEFINE
		i	INTEGER,
		s	CHAR(20)

	DISPLAY "Valid conversions"

	LET s = "1234"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "0"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "-1234"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "+1234"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	DISPLAY "Invalid or dubious conversions"

	LET s = "+1234X"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "+1234 X"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "+ 1234X"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "+ 1234 X"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "X"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

END MAIN
}

FUNCTION char_to_integer(s)

	DEFINE
		s		CHAR(20),
		i		INTEGER,
		sccs	CHAR(1)

	WHENEVER ERROR CONTINUE
	LET i = s
	WHENEVER ERROR STOP

	IF STATUS != 0 THEN
		LET STATUS = 0
		LET i = NULL
		LET sccs = "@@(#)$Id: chtoint.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
	END IF

	RETURN i

END FUNCTION {char_to_integer}
@


1.1
log
@Initial revision
@
text
@d1 4
a4 6
{
	@@(#)$Id: chtoint.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools
	@@(#)Convert string to integer
	@@(#)Author: JL
}
d59 3
a61 2
		s	CHAR(20),
		i	INTEGER
d70 1
@
