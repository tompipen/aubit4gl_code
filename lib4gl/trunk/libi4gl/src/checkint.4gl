head	2.6;
access;
symbols;
locks; strict;
comment	@# @;


2.6
date	98.08.20.20.39.48;	author jleffler;	state Exp;
branches;
next	2.5;

2.5
date	98.07.08.18.56.30;	author jleffler;	state Exp;
branches;
next	2.4;

2.4
date	90.04.05.11.02.02;	author john;	state Exp;
branches;
next	2.3;

2.3
date	89.08.03.09.55.14;	author john;	state Exp;
branches;
next	2.2;

2.2
date	88.02.19.15.12.52;	author john;	state Exp;
branches;
next	2.1;

2.1
date	88.02.08.13.05.46;	author john;	state Exp;
branches;
next	;


desc
@@


2.6
log
@Revamp header
@
text
@-- @@(#)$Id: checkint.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)Purpose:     Interrupt checker
-- @@(#)Author:      Jonathan Leffler
-- @@(#)Product:     :PRODUCT:

{ Warn about ignored interrupt if interrupt has occurred }
FUNCTION check_interrupt()

	DEFINE rcs CHAR(1)

	IF int_flag != 0 THEN
		LET rcs = "@@(#)$Id: checkint.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
		ERROR "Interrupt detected -- ignored"
		LET int_flag = 0
	END IF

END FUNCTION {check_interrupt}
@


2.5
log
@Change sccs to rcs and Sphinx to JLSS
@
text
@d1 4
a4 6
{
	@@(#)$Id: checkint.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)JLSS Informix Tools: General Library
	@@(#)Interrupt checker
	@@(#)Author: JL
}
d12 1
a12 1
		LET rcs = "@@(#)$Id: checkint.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


2.4
log
@Add sccs string
@
text
@d2 2
a3 2
	@@(#)$Id: checkint.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
d11 1
a11 2
	DEFINE
		sccs	CHAR(1)
d14 1
a14 1
		LET sccs = "@@(#)$Id: checkint.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


2.3
log
@Remove KPI-isms
@
text
@d11 3
d15 1
@


2.2
log
@Ignore interrupts
@
text
@d3 1
a3 1
	@@(#)KPI Database Project: General Library
@


2.1
log
@Initial revision
@
text
@d3 1
a3 1
	@@(#)KPI Database Project: Data Dictionary
d8 1
a8 1
{ Exit program if interrupt has occurred }
d12 2
a13 2
		ERROR "Interrupt detected -- exiting"
		EXIT PROGRAM 1
@
