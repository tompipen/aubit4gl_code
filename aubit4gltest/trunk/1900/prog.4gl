{**
 * @file
 * Test if getCharAt FOR Strings works
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE s1 String

LET s1 = "HEY THERE!"

IF s1.getCharAt(5) != "T"
   THEN EXIT PROGRAM 1
END IF

END MAIN
