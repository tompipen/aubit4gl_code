head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	90.05.21.13.42.50;	author john;	state Exp;
branches;
next	1.1;

1.1
date	90.05.21.13.18.52;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Add SCCS tags
@
text
@{
    @@(#)$Id: fdquart.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
    @@(#)Sphinx Informix Tools: General Library
    @@(#)Find the first day of a quarter containing a given date
    @@(#)Author: JL
}

{ Quarter days are 1st January, 1st April, 1st July and 1st October }

FUNCTION first_day_of_quarter(edate)

	DEFINE
		edate	DATE,		{ Effective date }
		qdate	DATE,		{ 1st day of quarter containing effective date }
		mm		INTEGER,	{ Month number }
		qn		INTEGER,	{ Quarter number }
		sccs	CHAR(1)

	LET qn    = (MONTH(edate) + 2) / 3		{ 1..4 }
	LET mm    = (qn - 1) * 3 + 1			{ 1,4,7,10 }
	LET qdate = MDY(mm, 1, YEAR(edate))

	RETURN qdate

	LET sccs = "@@(#)$Id: fdquart.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"

END FUNCTION {first_day_of_quarter}
@


1.1
log
@Initial revision
@
text
@d16 2
a17 1
		qn		INTEGER		{ Quarter number }
d24 2
@
