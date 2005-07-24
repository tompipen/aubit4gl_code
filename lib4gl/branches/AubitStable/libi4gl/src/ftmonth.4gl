{
	@(#)$Id: ftmonth.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Find first of this month
	@(#)Author: JL
}

FUNCTION first_of_this_month(edate)

	DEFINE
		sccs	CHAR(1),
		edate	DATE,		{ Effective date (frequently TODAY) }
		mm		INTEGER,	{ Month number }
		yy		INTEGER		{ Year }

	IF edate IS NULL THEN
		LET sccs = "@(#)$Id: ftmonth.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		RETURN edate
	END IF

	LET mm = MONTH(edate)
	LET yy = YEAR(edate)

	RETURN MDY(mm, 1, yy)

END FUNCTION {first_of_this_month}
