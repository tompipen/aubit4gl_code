-- @(#)$Id: findstr.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)Purpose:     Find index of where string occurs in string
-- @(#)Author:      Jonathan Leffler
-- @(#)Product:     :PRODUCT:

FUNCTION find_string(str, s)

	DEFINE
		str		CHAR(80),	{ String to be searched }
		s		CHAR(80),	{ String to be found (more than 1 char please) }
		c		CHAR(1),
		rcs		CHAR(1),
		l1		INTEGER,
		l2		INTEGER,
		f		INTEGER,
		i		INTEGER,
		j		INTEGER,
		k		INTEGER

	LET l1 = length(str)
	LET l2 = length(s)
	LET c  = s[1]

	FOR i = 1 TO l1 - l2 + 1
		IF str[i] = c THEN
			LET k = i + 1
			LET j = 2
			LET f = TRUE
			WHILE j <= l2
				IF str[k] != s[j] THEN
					LET f = FALSE
					EXIT WHILE
				END IF
				LET j = j + 1
				LET k = k + 1
			END WHILE
			IF f = TRUE THEN
				RETURN i
			END IF
		END IF
	END FOR

	RETURN 0

	LET rcs = "@(#)$Id: findstr.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"

END FUNCTION {find_string}
