{
	@(#)$Id: rjust.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Right justify and truncate a string
	@(#)Author: JL
}

FUNCTION rjust(s, i)

	DEFINE
		sccs	CHAR(1),
		s		CHAR(512),
		i		INTEGER,
		len		INTEGER,
		t		CHAR(512),
		x		CHAR(512)

	LET len = LENGTH(s)
	IF len IS NULL OR len < 0 THEN
		LET len = 0
		LET sccs = "@(#)$Id: rjust.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $"
	END IF
	LET x = "   "
	CASE
	WHEN len >= i
		LET t =	s[1, i]
	WHEN len > 0
		LET t =	x[1, i-len], s[1, len]
	OTHERWISE
		LET t = x[1, i]
	END CASE

	RETURN t CLIPPED

END FUNCTION {rjust}
