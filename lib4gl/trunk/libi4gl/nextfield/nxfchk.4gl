head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	88.09.23.16.39.38;	author john;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@{
	@@(#)$Id: nxfchk.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Program to test whether next_field works
}

MAIN

	DEFINE
		field1	CHAR(4),
		field2	CHAR(4),
		field3	CHAR(4),
		field4	CHAR(4),
		field5	CHAR(4)

	OPEN FORM f_nxfchk FROM "nxfchk"
	DISPLAY FORM f_nxfchk

	MESSAGE "Default sequence is 1,3,5,4,2"

	INPUT field1, field2, field3, field4, field5 FROM FORMONLY.*
	AFTER FIELD field1
		CALL next_field("field3")
	AFTER FIELD field2
		CALL next_field("field1")
	AFTER FIELD field3
		CALL next_field("field5")
	AFTER FIELD field4
		CALL next_field("field2")
	AFTER FIELD field5
		CALL next_field("field4")
	END INPUT

	CLOSE FORM f_nxfchk
	CLEAR SCREEN

END MAIN
@
