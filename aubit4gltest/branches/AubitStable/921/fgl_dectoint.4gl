{**
 * @file
 * @process TEST_DECFUNC
 * Test if a decimal conversion to int with c function works ok
 *}
MAIN
  DEFINE a_decimal DECIMAL(5)
	DEFINE ok_code SMALLINT
	DEFINE an_int INTEGER
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_decimal = 31415 
	CALL convert_to_int(a_decimal) RETURNING ok_code, an_int
	IF ok_code != 0 THEN
	  DISPLAY "The dectoint returned an error"
		LET exitStatus = 1
	END IF
  IF an_int != 31415 THEN
	  DISPLAY "The dectoint did not return the correct value"
		LET exitStatus = 1
	END IF

	LET a_decimal = 32767 
	CALL convert_to_int(a_decimal) RETURNING ok_code, an_int
	IF ok_code != 0 THEN
	  DISPLAY "The dectoint returned an error"
		LET exitStatus = 1
	END IF
  IF an_int != 32767 THEN
	  DISPLAY "The dectoint did not return the correct value"
		LET exitStatus = 1
	END IF

	LET a_decimal = 32768 
	CALL convert_to_int(a_decimal) RETURNING ok_code, an_int
	IF ok_code = 0 THEN
	  DISPLAY "The dectoint did not returned an error"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
