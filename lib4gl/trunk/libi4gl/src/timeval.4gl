{
	@(#)$Id: timeval.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Calculate number of seconds past midnight from "hh:mm:ss"
	@(#)Author: JL
}

FUNCTION timevalue(t)

	DEFINE
		sccs	CHAR(1),
		t		CHAR(8),
		h		INTEGER,
		m		INTEGER,
		s		INTEGER

	LET h = t[1,2]
	LET m = t[4,5]
	LET s = t[7,8]
	IF h IS NULL THEN
		LET h = 0
		LET sccs = "@(#)$Id: timeval.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $"
	END IF
	IF m IS NULL THEN
		LET m = 0
	END IF
	IF s IS NULL THEN
		LET s = 0
	END IF

	RETURN ((h * 60 + m) * 60 + s)

END FUNCTION {timevalue}
