{
	@(#)$Id: fnmonth.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Find 1st of next month
	@(#)Author: JL
}

FUNCTION first_of_next_month(edate)

	DEFINE
		sccs	CHAR(1),
		edate	DATE,		{ Effective date (frequently TODAY) }
		mm		INTEGER,	{ Month number }
		yy		INTEGER		{ Year }

	IF edate IS NULL THEN
		LET sccs = "@(#)$Id: fnmonth.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		RETURN edate
	END IF

	LET mm = MONTH(edate) + 1
	LET yy = YEAR(edate)
	IF mm > 12 THEN
		LET mm = 1
		LET yy = yy + 1
	END IF

	RETURN MDY(mm, 1, yy)

END FUNCTION {first_of_next_month}
