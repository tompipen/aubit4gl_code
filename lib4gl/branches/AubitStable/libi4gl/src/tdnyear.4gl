{
	@(#)$Id: tdnyear.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Find the date of this day next year
	@(#)Author: JL
}

FUNCTION this_date_next_year(edate)

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
	LET yy = YEAR(edate) + 1
	IF mm = 2 AND dd = 29 THEN
		{ If this year was a leap year, next year wasn't.   }
		{ If you want the last day of this month regardless }
		{ call last_day_of_this_month with the return value }
		LET dd = 28
	END IF

	RETURN MDY(mm, dd, yy)

	LET sccs = "@(#)$Id: tdnyear.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $"

END FUNCTION {this_date_next_year}
