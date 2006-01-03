{**
 * @file
 * @process TEST_DECFUNC
 * Test if a char conversion to decimal with c function works ok
 *}
MAIN
  DEFINE a_decimal DECIMAL(7,6)
	DEFINE a_char CHAR(8)
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_char = "3.141516" 
	LET a_decimal = convert_to_decimal(a_char)
  IF a_decimal != 3.141516 THEN
	  DISPLAY "The dectoasc did not return the correct value"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
