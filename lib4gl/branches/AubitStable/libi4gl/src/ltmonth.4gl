{
	@(#)$Id: ltmonth.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Find last day of this month
	@(#)Author: JL
}

FUNCTION last_of_this_month(edate)

	DEFINE
		sccs	CHAR(1),
		edate	DATE		{ Effective date (frequently TODAY) }

	IF edate IS NULL THEN
		LET sccs = "@(#)$Id: ltmonth.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		RETURN edate
	END IF

	RETURN first_of_next_month(edate) - 1

END FUNCTION {last_of_this_month}
