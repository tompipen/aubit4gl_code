-- @(#)$Id: chtodec.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Convert string to decimal
-- @(#)Author: JL

{
MAIN

	DEFINE
		d	DECIMAL,
		s	CHAR(20)

	DISPLAY "Valid conversions"

	LET s = "12.34"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

	LET s = "0"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

	LET s = "-12.34"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

	LET s = "+12.34"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

	LET s = "+12.34e3"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

	LET s = "+12.34E-2"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

	DISPLAY "Invalid or dubious conversions"

	LET s = "+12.34X"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

	LET s = "+12.34 X"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

	LET s = "+ 12.34X"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

	LET s = "+ 12.34 X"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

	LET s = "X"
	LET d = char_to_decimal(s)
	DISPLAY "String ", s CLIPPED, " = ", d

END MAIN
}

FUNCTION char_to_decimal(s)

	DEFINE
		s		CHAR(20),
		d		DECIMAL,
		sccs	CHAR(1)

	WHENEVER ERROR CONTINUE
	LET d = s
	WHENEVER ERROR STOP

	IF STATUS != 0 THEN
		LET STATUS = 0
		LET d = NULL
		LET sccs = "@(#)$Id: chtodec.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
	END IF

	RETURN d

END FUNCTION {char_to_decimal}
