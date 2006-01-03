{**
 * @file
 * @process TEST_DECFUNC
 * Test if a char conversion to decimal with c function works ok
 *}
MAIN
  DEFINE a_decimal DECIMAL(7,6)
	DEFINE an_int SMALLINT
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET an_int = 3141516 
	LET a_decimal = convert_to_decimal(an_int)
  IF a_decimal != 3141516 THEN
	  DISPLAY "The deccvint did not return the correct value"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
