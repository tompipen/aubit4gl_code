-- @(#)$Id: chtoint.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Convert string to integer
-- @(#)Author: JL

{
MAIN

	DEFINE
		i	INTEGER,
		s	CHAR(20)

	DISPLAY "Valid conversions"

	LET s = "1234"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "0"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "-1234"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "+1234"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	DISPLAY "Invalid or dubious conversions"

	LET s = "+1234X"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "+1234 X"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "+ 1234X"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "+ 1234 X"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

	LET s = "X"
	LET i = char_to_integer(s)
	DISPLAY "String ", s CLIPPED, " = ", i

END MAIN
}

FUNCTION char_to_integer(s)

	DEFINE
		s		CHAR(20),
		i		INTEGER,
		sccs	CHAR(1)

	WHENEVER ERROR CONTINUE
	LET i = s
	WHENEVER ERROR STOP

	IF STATUS != 0 THEN
		LET STATUS = 0
		LET i = NULL
		LET sccs = "@(#)$Id: chtoint.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
	END IF

	RETURN i

END FUNCTION {char_to_integer}
