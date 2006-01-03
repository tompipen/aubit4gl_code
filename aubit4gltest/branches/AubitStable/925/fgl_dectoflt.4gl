{**
 * @file
 * @process TEST_DECFUNC
 * Test if a decimal conversion to float with c function works ok
 *}
MAIN
  DEFINE a_decimal DECIMAL(17,13)
	DEFINE ok_code SMALLINT
	DEFINE a_float SMALLFLOAT
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_decimal = 2949.3829398204382 
	CALL decimal_to_float(a_decimal) RETURNING ok_code, a_float
	IF ok_code != 0 THEN
	  DISPLAY "The dectoflt returned an error"
		LET exitStatus = 1
	END IF
	IF a_float != 2949.3829398204382  THEN
	  DISPLAY "The dectoflt did not return the correct value"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
