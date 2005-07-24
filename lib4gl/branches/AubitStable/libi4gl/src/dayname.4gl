{
	@(#)$Id: dayname.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Return full name of weekday for given date
	@(#)Jonathan Leffler
}

DEFINE
	day_names	ARRAY[7] OF CHAR(9),
	sccs		CHAR(1)

FUNCTION dayname(d)

	DEFINE
		d	DATE,
		i	INTEGER

	IF sccs IS NULL THEN
		LET sccs = "@(#)$Id: dayname.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		LET day_names[1] = "Sunday"
		LET day_names[2] = "Monday"
		LET day_names[3] = "Tuesday"
		LET day_names[4] = "Wednesday"
		LET day_names[5] = "Thursday"
		LET day_names[6] = "Friday"
		LET day_names[7] = "Saturday"
	END IF

	LET i = WEEKDAY(d) + 1

	RETURN day_names[i] CLIPPED

END FUNCTION {dayname}
