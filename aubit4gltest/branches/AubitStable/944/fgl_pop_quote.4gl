{**
 * @file
 * @process TEST_STACK
 * Test if the stack function(s) for char(s) works
 * @todo : This test should be changed with extreme values of char(s).
 *}
MAIN
	DEFINE ok_code SMALLINT
	DEFINE a_char CHAR(64)
	DEFINE ret_char CHAR(28)
	DEFINE a_varchar VARCHAR(64)
	DEFINE ret_varchar VARCHAR(28)
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_char = "Hello world"
	LET  ret_char = pop_ret_char(a_char)
  IF ret_char != "Hello world" THEN
	  DISPLAY "The char pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF

	LET a_varchar = "Hello world"
	LET  ret_varchar = pop_ret_char(a_varchar)
  IF ret_varchar != "Hello world" THEN
	  DISPLAY "The varchar pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
