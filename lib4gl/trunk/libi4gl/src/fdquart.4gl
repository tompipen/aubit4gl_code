{
    @(#)$Id: fdquart.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
    @(#)Sphinx Informix Tools: General Library
    @(#)Find the first day of a quarter containing a given date
    @(#)Author: JL
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

	LET sccs = "@(#)$Id: fdquart.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"

END FUNCTION {first_day_of_quarter}
