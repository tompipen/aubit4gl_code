head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	88.09.09.12.31.44;	author john;	state Exp;
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
	@@(#)$Id: phlpchk.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools
	@@(#)Test help file stack
	@@(#)Author: JL
}

MAIN

	OPTIONS HELP FILE "phlpchk1.iem"

	CALL SHOWHELP(100)

	CALL push_helpfile()

	OPTIONS HELP FILE "phlpchk2.iem"

	CALL SHOWHELP(100)

	CALL pop_helpfile()

	CALL SHOWHELP(100)

END MAIN

@
