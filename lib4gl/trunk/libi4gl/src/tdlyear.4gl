head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	90.05.21.13.42.52;	author john;	state Exp;
branches;
next	1.1;

1.1
date	90.01.17.16.55.58;	author john;	state Exp;
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
	@@(#)$Id: tdlyear.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Find the date of this day last year
	@@(#)Author: JL
}

FUNCTION this_date_last_year(edate)

	DEFINE
		edate	DATE,		{ Effective date (frequently TODAY) }
		dd		INTEGER,	{ Day number }
		mm		INTEGER,	{ Month number }
		yy		INTEGER,	{ Year }
		sccs	CHAR(1)

	IF edate IS NULL THEN
		RETURN edate
	END IF

	LET dd = DAY(edate)
	LET mm = MONTH(edate)
	LET yy = YEAR(edate) - 1
	IF mm = 2 AND dd = 29 THEN
		{ If this year was a leap year, last year wasn't.   }
		{ If you want the last day of this month regardless }
		{ call last_day_of_this_month with the return value }
		LET dd = 28
	END IF

	RETURN MDY(mm, dd, yy)

	LET sccs = "@@(#)$Id: tdlyear.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"

END FUNCTION {this_date_last_year}
@


1.1
log
@Initial revision
@
text
@d14 2
a15 1
		yy		INTEGER		{ Year }
d32 2
@
