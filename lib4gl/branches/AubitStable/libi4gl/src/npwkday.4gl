{
	@(#)$Id: npwkday.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Next/Previous Working Day
}

FUNCTION prev_working_day(e_date)

	DEFINE
		e_date	DATE,
		r_date	DATE,
		n		INTEGER

	LET r_date = e_date - 1
	LET n = WEEKDAY(r_date)
	IF n = 0 THEN
		LET r_date = r_date - 2
	END IF
	IF n = 6 THEN
		LET r_date = r_date -1
	END IF

	RETURN r_date

END FUNCTION {prev_working_day}

FUNCTION next_working_day(e_date)

	DEFINE
		e_date	DATE,
		r_date	DATE,
		n		INTEGER

	LET r_date = e_date + 1
	LET n = WEEKDAY(r_date)
	IF n = 0 THEN
		LET r_date = r_date + 1
	END IF
	IF n = 6 THEN
		LET r_date = r_date + 2
	END IF

	RETURN r_date

END FUNCTION {next_working_day}
