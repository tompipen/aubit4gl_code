head	1.5;
access;
symbols;
locks; strict;
comment	@# @;


1.5
date	90.04.05.11.02.08;	author john;	state Exp;
branches;
next	1.4;

1.4
date	90.03.22.09.32.06;	author john;	state Exp;
branches;
next	1.3;

1.3
date	90.02.09.08.30.15;	author john;	state Exp;
branches;
next	1.2;

1.2
date	90.01.22.18.42.13;	author john;	state Exp;
branches;
next	1.1;

1.1
date	89.12.16.18.50.25;	author john;	state Exp;
branches;
next	;


desc
@@


1.5
log
@Add sccs string
@
text
@{
	@@(#)$Id: scrndump.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Interface to Screen Dump Utility
}

FUNCTION do_screen_dump()

	DEFINE
		sccs		CHAR(1),
		filename	CHAR(64),
		ans			CHAR(1)

	LET INT_FLAG = FALSE

	OPEN WINDOW w_screen_dump AT 2, 2
		WITH 2 ROWS, 78 COLUMNS
		ATTRIBUTE (BORDER, FORM LINE FIRST, COMMENT LINE LAST)
	OPEN FORM f_screen_dump FROM "scrndump"
	DISPLAY FORM f_screen_dump

	OPTIONS INPUT NO WRAP
	INPUT BY NAME filename
	OPTIONS INPUT WRAP

	IF INT_FLAG THEN
		ERROR "Not doing screen dump"
		LET sccs = "@@(#)$Id: scrndump.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
		LET INT_FLAG = FALSE
		CLOSE WINDOW w_screen_dump
		CLOSE FORM   f_screen_dump
		RETURN
	END IF

	IF filename IS NULL THEN
		LET filename = mkfilename("/tmp/scrdumpXXXXXX")
		DISPLAY "Your dump file is: ", filename
		PROMPT "Hit return to continue" FOR CHAR ans
	END IF

	CLOSE WINDOW w_screen_dump
	CLOSE FORM   f_screen_dump

	CALL screendump(filename)

END FUNCTION {do_screen_dump}
@


1.4
log
@Adjust comment line
@
text
@d9 1
d27 1
@


1.3
log
@Use window small enough to overlap menu in SPI
@
text
@d16 1
a16 1
		ATTRIBUTE (BORDER, FORM LINE FIRST)
@


1.2
log
@Change name of form
@
text
@d15 4
a18 2
		WITH FORM "scrndump"
		ATTRIBUTE (BORDER)
d28 1
d39 1
@


1.1
log
@Initial revision
@
text
@d15 1
a15 1
		WITH FORM "scrdump"
@
