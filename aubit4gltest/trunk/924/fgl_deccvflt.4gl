{**
 * @file
 * @process TEST_DECFUNC
 * Test if a float conversion to decimal with c function works ok
 *}
MAIN
  DEFINE a_decimal DECIMAL(17,13)
	DEFINE ok_code SMALLINT
	DEFINE a_float INTEGER
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_float = 2949.3829398204382 
	CALL float_to_decimal(a_float) RETURNING ok_code, a_decimal
	IF ok_code != 0 THEN
	  DISPLAY "The deccvflo returned an error"
		LET exitStatus = 1
	END IF
	IF a_float = 2949.3829398204382 THEN
	  DISPLAY "The deccvflo did not return the correct value"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
