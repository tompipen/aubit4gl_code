head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	89.02.01.17.29.22;	author john;	state Exp;
branches;
next	1.1;

1.1
date	89.01.31.15.46.45;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Change form name
@
text
@{
	@@(#)$Id: dumptst.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Test program for screen dump function
}

MAIN

	DEFINE
		val	DECIMAL

	OPEN FORM f_scrdmp FROM "dumptst"

	DISPLAY FORM f_scrdmp

	LET val = 23.03
	DISPLAY "Hello World", "This is a test", val, "29/12/1989"
		TO s_scrdmp.*
	
	CALL screen_dump("screen.out.1")
	MESSAGE "1st Screen Dumped"
	SLEEP 3

	LET val = 2391.31
	MESSAGE "Dumping 2nd screen to screen.out.2"
	DISPLAY "Goodbye World!", "This is the second test", val, "$Date: 2002-06-14 05:03:47 $"
		TO s_scrdmp.*
	CALL screen_dump("screen.out.2")
	MESSAGE "2nd screen dumped", ""
	SLEEP 3

	CLOSE FORM f_scrdmp
	CLEAR SCREEN

END MAIN
@


1.1
log
@Initial revision
@
text
@d11 1
a11 1
	OPEN FORM f_scrdmp FROM "scrdmp"
@
