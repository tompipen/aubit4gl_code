-- @(#)$Id: instring.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)Purpose:     Find index of character in string
-- @(#)Author:      Jonathan Leffler
-- @(#)Product:     :PRODUCT:

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

	LET rcs = "@(#)$Id: instring.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"

END FUNCTION {instring}
