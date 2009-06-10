{**
 * @file
 * @process TEST_STACK
 * Test if the stack function(s) for long(s) works
 * @todo : This test should be changed with extreme values of long(s).
 *}
MAIN
	DEFINE ok_code SMALLINT
	DEFINE a_float FLOAT
	DEFINE ret_float FLOAT
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_float = 2949.3829398204382
	LET  ret_float = pop_ret_double(a_float)
  IF ret_float != 2949.3829398204382 THEN
	  DISPLAY "The float pop(ed) to stack was not correctly return(ed).", ret_float
		LET exitStatus = 1
	END IF

	LET a_float = 323829949
	LET  ret_float = pop_ret_double(a_float)
  IF ret_float != 323829949 THEN
	  DISPLAY "The float pop(ed) to stack was not correctly return(ed).", ret_float
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
