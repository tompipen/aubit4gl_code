{**
 * @file
 * @process TEST_STACK
 * Test if the stack function(s) for decimal(s) works
 * @todo : This test should be changed with extreme values of decimal(s).
 *}
MAIN
	DEFINE ok_code SMALLINT
	DEFINE a_decimal DECIMAL(16,3)
	DEFINE ret_decimal DECIMAL(16,3)
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_decimal = 2949.382
	LET  ret_decimal = pop_ret_decimal(a_decimal)
  IF ret_decimal != 2949.382 THEN
	  DISPLAY "The float pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF

	LET a_decimal = 323829949
	LET  ret_decimal = pop_ret_decimal(a_decimal)
  IF ret_decimal != 323829949 THEN
	  DISPLAY "The float pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
