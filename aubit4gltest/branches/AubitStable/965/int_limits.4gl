{**
 * Test the integer variable limits.
 * @todo : This is not OK. I must discuss it on the developers list
 * @process DATA_TYPE
 *}

MAIN
  DEFINE int_var INTEGER
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0

  LET int_var = 2147483647
	IF int_var != 2147483647 THEN
	  DISPLAY "Error on largest integer comparison "
		LET exitStatus = 1
	END IF

  LET int_var = -2147483647
	IF int_var != -2147483647 THEN
	  DISPLAY "Error on smallest integer comparison "
		LET exitStatus = 1
	END IF

  LET int_var = 0
	IF int_var != 0 THEN
	  DISPLAY "Error on zero integer comparison "
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN

