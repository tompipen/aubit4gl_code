{**
 * @file
 * @process TEST_STACK
 * Test if the stack function(s) for interval(s) works
 * @todo : This test should be changed with extreme values of interval(s).
 *}
MAIN
	DEFINE ok_code SMALLINT
	DEFINE an_interval INTERVAL HOUR TO SECOND
	DEFINE ret_interval INTERVAL HOUR TO SECOND
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  LET an_interval  = "23:59:59"
	LET  ret_interval = pop_ret_interval(an_interval)
  IF ret_interval != "23:59:59" THEN
	  DISPLAY "The interval(s) pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
