{**
 * @file
 * @process TEST_STACK
 * Test if the stack function(s) for date(s) works
 * @todo : This test should be changed with extreme values of date(s).
 *}
MAIN
	DEFINE ok_code SMALLINT
	DEFINE a_date DATE
	DEFINE ret_date DATE
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_date = mdy(31,12,1999)
	LET  ret_date = pop_ret_date(a_date)
  IF ret_date != mdy(31,12,1999) THEN
	  DISPLAY "The date pop(ed) to stack was not correctly return(ed)."
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
