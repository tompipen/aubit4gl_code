{**
 * @file
 * @process TEST_DECFUNC
 * Test if a decimal multiplication C function works OK
 *}
MAIN
  DEFINE a_decimal DECIMAL(32,16)
  DEFINE other_decimal DECIMAL(32,16)
  DEFINE result DECIMAL(32,16)
	DEFINE ok_code SMALLINT
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_decimal = 3.3
	LET other_decimal = 2.2
	CALL decimal_mul(a_decimal,other_decimal) RETURNING ok_code, result
	IF ok_code != 0 THEN
	  DISPLAY "The decmul returned an error"
		LET exitStatus = 1
	END IF
	IF result != 7.26 THEN
	  DISPLAY "The decmul did not return the correct value"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
