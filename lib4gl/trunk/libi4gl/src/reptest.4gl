head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	89.10.10.09.47.21;	author john;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@# @@(#)$Id: reptest.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
# @@(#)Test program for REPORT_DESTINATION

MAIN

	DEFINE i INTEGER, s CHAR(40)
	DEFER INTERRUPT

	LET i = 0
	WHILE i >= 0 AND i <= 3
		CALL report_destination() RETURNING i, s
		IF i >= 0 AND i <= 3 THEN
			SLEEP 1
			MESSAGE "Again!"
		END IF
	END WHILE

END MAIN
@
