{**
 * @file
 * @process TEST_STACK
 * Test if the stack function(s) for datetime(s) works
 * @todo : This test should be changed with extreme values of datetime(s).
 *}
MAIN
	DEFINE ok_code SMALLINT
	DEFINE a_datetime DATETIME YEAR TO FRACTION
	DEFINE ret_datetime DATETIME YEAR TO FRACTION
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  LET a_datetime  = "1999-12-31 23:59:59:99"
	LET  ret_datetime = pop_ret_datetime(a_datetime)
  IF ret_datetime != "1999-12-31 23:59:59:99" THEN
	  DISPLAY "The datetime pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
