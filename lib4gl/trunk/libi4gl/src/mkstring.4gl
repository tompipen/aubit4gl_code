{
	@(#)$Id: mkstring.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Create a string of replicated characters
	@(#)Author: JL
}

FUNCTION mkstring(c, n)

	DEFINE
		c		CHAR(1),
		n		INTEGER,
		i		INTEGER,
		s		CHAR(512),
		sccs	CHAR(1)

	IF n > 512 THEN
		LET n = 512
	END IF
	FOR i = 1 TO n
		LET s[i] = c
	END FOR

	RETURN s[1,n]

	LET sccs = "@(#)$Id: mkstring.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"

END FUNCTION {mkstring}
