{
    @(#)$Id: ldquart.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
    @(#)SPhinx Informix Tools: General Library
    @(#)Find the last day of a quarter containing a given date
    @(#)Author: JL
}

{ Quarter days are: 1st January, 1st April, 1st July, 1st October }
{ Return values are: 31st March, 30th June, 30th September, 31st December }

FUNCTION last_day_of_quarter(edate)

	DEFINE
		edate	DATE,		{ Effective date }
		fdate	DATE,		{ Last day of quarter containing supplied date }
		qn		INTEGER,	{ Quarter number }
		mm		INTEGER,	{ Month number }
		sccs	CHAR(1)

	LET qn = (MONTH(edate) + 2) / 3		{ 1..4 }
	LET mm = qn * 3						{ 3, 6, 9, 12 }
	LET fdate = MDY(mm, 1, YEAR(edate))	{ 1st day of last month in quarter }

	RETURN last_of_this_month(fdate)	{ Last day of last month in quarter }

	LET sccs = "@(#)$Id: ldquart.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"

END FUNCTION {last_day_of_quarter}
