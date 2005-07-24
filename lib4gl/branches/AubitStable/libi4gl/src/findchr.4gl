-- @(#)$Id: findchr.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)Purpose:     Find index of where string occurs in string
-- @(#)Author:      Jonathan Leffler
-- @(#)Product:     :PRODUCT:

FUNCTION find_character(str, c)

	DEFINE
		str		CHAR(80),	{ String to be searched }
		c		CHAR(1),	{ Character to be found }
		rcs     CHAR(1),
		len		INTEGER,
		i		INTEGER

	LET len = length(str)

	FOR i = 1 TO len
		IF str[i] = c THEN
			RETURN i
		END IF
	END FOR

	RETURN 0

	LET rcs = "@(#)$Id: findchr.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"

END FUNCTION {find_character}
