{
	@(#)$Id: mthname.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Return full name of month for given date
	@(#)Jonathan Leffler
}

DEFINE
	month_names	ARRAY[12] OF CHAR(9),
	sccs		CHAR(1)

FUNCTION monthname(d)

	DEFINE
		d	DATE,
		i	INTEGER

	IF sccs IS NULL THEN
		LET sccs = "@(#)$Id: mthname.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		LET month_names[1]  = "January"
		LET month_names[2]  = "February"
		LET month_names[3]  = "March"
		LET month_names[4]  = "April"
		LET month_names[5]  = "May"
		LET month_names[6]  = "June"
		LET month_names[7]  = "July"
		LET month_names[8]  = "August"
		LET month_names[9]  = "September"
		LET month_names[10] = "October"
		LET month_names[11] = "November"
		LET month_names[12] = "December"
	END IF

	LET i = MONTH(d)

	RETURN month_names[i] CLIPPED

END FUNCTION {monthname}
