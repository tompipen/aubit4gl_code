

MAIN

	DEFINE
		a		INTEGER,
		b		INTEGER,
		c		INTEGER

	LET b = 0

	START REPORT rg TO "rg1.out"

	FOR a = 1 TO 3
		FOR c = 1 TO 5
			OUTPUT TO REPORT rg (c, b, a)
		END FOR
	END FOR
				
	FINISH REPORT rg

END MAIN

REPORT rg (c, b, a)

	DEFINE
		c	INTEGER,
		b	INTEGER,
		a	INTEGER

	OUTPUT
		TOP MARGIN 1
		BOTTOM MARGIN 1
		PAGE LENGTH 20

	FORMAT

	PAGE HEADER
		PRINT "PAGE HEADER"

	BEFORE GROUP OF a
		PRINT "BEFORE GROUP a:", " a = ", a, " b = ", b, " c = ", c

	BEFORE GROUP OF b
		PRINT "BEFORE GROUP b:", " a = ", a, " b = ", b, " c = ", c

	ON EVERY ROW
		PRINT "ROW:           ", " a = ", a, " b = ", b, " c = ", c

	AFTER GROUP OF b
		PRINT "AFTER GROUP b: ", " a = ", a, " b = ", b, " c = ", c
			, " count = ", GROUP COUNT (*) USING "####", " sum = ", GROUP SUM (c) USING "####"

	AFTER GROUP OF a
		PRINT "AFTER GROUP a: ", " a = ", a, " b = ", b, " c = ", c
			, " count = ", GROUP COUNT (*) USING "####", " sum = ", GROUP SUM (c) USING "####"

	ON LAST ROW
		PRINT "GRAND count = ", COUNT (*) USING "####", " GRAND sum = ", SUM (c) USING "####"

END REPORT

