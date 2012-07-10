{**
 * @file
 * Test FOR ASCII(10) AND ASCII(32) NOT RETURNING TRUE WHEN beeing tested against each other.
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE a CHAR(1)
DEFINE b CHAR(1)

LET a = ASCII(10)
LET b = ASCII(32)

IF a = b
   THEN DISPLAY "FALSE1"
	exit program 1
END IF

IF a = ASCII(10)
   THEN DISPLAY "TRUE1"
else
	exit program 1
END IF

IF a = ASCII(32)
   THEN DISPLAY "FALSE2"
	exit program 1
END IF

END MAIN
