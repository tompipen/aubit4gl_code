{**
 * @file
 * @process TEST_STACK
 * Test if the stack function(s) for short(s) works
 *}
MAIN
	DEFINE ok_code SMALLINT
	DEFINE a_smallint SMALLINT
	DEFINE ret_smallint SMALLINT
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_smallint = 32767
	LET  ret_smallint = pop_ret_short(a_smallint)
  IF ret_smallint != 32767 THEN
	  DISPLAY "The smallint pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF

	LET a_smallint = -32767
	LET  ret_smallint = pop_ret_short(a_smallint)
  IF ret_smallint != -32767 THEN
	  DISPLAY "The smallint pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
