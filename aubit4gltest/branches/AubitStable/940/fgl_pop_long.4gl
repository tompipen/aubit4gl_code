{**
 * @file
 * @process TEST_STACK
 * Test if the stack function(s) for long(s) works
 * @todo : This test should be changed with extreme values of long(s).
 *}
MAIN
	DEFINE ok_code SMALLINT
	DEFINE an_int INTEGER
	DEFINE ret_int INTEGER
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET an_int = 32767
	LET  ret_int = pop_ret_long(an_int)
  IF ret_int != 32767 THEN
	  DISPLAY "The integer pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF

	LET an_int = -32767
	LET  ret_int = pop_ret_long(an_int)
  IF ret_int != -32767 THEN
	  DISPLAY "The integer pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
