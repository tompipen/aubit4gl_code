{**
 * @file
 * @process TEST_DECFUNC
 * Test if a decimal conversion to ascii with c function works ok
 *}
MAIN
  DEFINE a_decimal DECIMAL(32,16)
	DEFINE ok_code SMALLINT
	DEFINE a_char CHAR(32)
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_decimal = 2949.3829398204382 
	CALL decimal_to_double(a_decimal) RETURNING ok_code, a_char
	IF ok_code != 0 THEN
	  DISPLAY "The dectodbl returned an error"
		LET exitStatus = 1
	END IF
	IF a_char != 2949.3829398204382  THEN
	  DISPLAY "The dectodbl did not return the correct value"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
