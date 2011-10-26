{
	@(#)$Id: instring.4gl,v 1.1.1.1 2001-08-20 02:37:08 afalout Exp $
	@(#)JLSS Informix Tools: General Library
	@(#)Find index of character in string
	@(#)Author: JL
}

FUNCTION instring(str, c)

	DEFINE
		str		CHAR(80),
		c		CHAR(1),
		rcs		CHAR(1),
		l		INTEGER,
		i		INTEGER

	LET l = length(str)

	FOR i = 1 TO l
		IF str[i] = c THEN
			RETURN i
		END IF
	END FOR

	RETURN 0

	LET rcs = "@(#)$Id: instring.4gl,v 1.1.1.1 2001-08-20 02:37:08 afalout Exp $"

END FUNCTION {instring}

