{**
 * @file
 * @process TEST_DECFUNC
 * Test if a long conversion to decimal with c function works ok
 *}
MAIN
  DEFINE a_decimal DECIMAL(10)
	DEFINE ok_code SMALLINT
	DEFINE a_long INTEGER
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_long = 2147483646 
	CALL long_to_decimal(a_long) RETURNING ok_code, a_long
	IF ok_code != 0 THEN
	  DISPLAY "The dectoint returned an error"
		LET exitStatus = 1
	END IF
	IF a_decimal != 2147483646 THEN
	  DISPLAY "The deccvlong did not return the correct value"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
