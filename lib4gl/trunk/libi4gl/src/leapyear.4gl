-- @(#)$Id: leapyear.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Determine whether given date is in a leap year
-- @(#)Author: JL

FUNCTION is_leap_year(d)

	DEFINE d	DATE
	DEFINE yyyy INTEGER

	LET yyyy = YEAR(d)

	CASE
	WHEN yyyy MOD   4 != 0 RETURN FALSE
	WHEN yyyy MOD 400 == 0 RETURN TRUE
	WHEN yyyy MOD 100 == 0 RETURN FALSE
	OTHERWISE              RETURN TRUE
	END CASE

END FUNCTION
