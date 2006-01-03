{**
 * @file
 * @process TEST_DECFUNC
 * Test if a double conversion to decimal with c function works ok
 *}
MAIN
  DEFINE a_decimal DECIMAL(32,16)
	DEFINE ok_code SMALLINT
	DEFINE a_double FLOAT
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_double = 2949.3829398204382 
	CALL double_to_decimal(a_double) RETURNING ok_code, a_decimal
	IF ok_code != 0 THEN
	  DISPLAY "The deccvdbl returned an error"
		LET exitStatus = 1
	END IF
	IF a_decimal = 2949.3829398204382 THEN
	  DISPLAY "The deccvflo did not return the correct value"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
