{**
 * Test the integer variable limits.
 * @todo : This is not OK. I must discuss it on the developers list
 * @process DATA_TYPE
 *}

MAIN
  DEFINE smallint_var SMALLINT
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0

  LET smallint_var = 32767
	IF smallint_var != 32767 THEN
	  DISPLAY "Error on largest small integer comparison "
		LET exitStatus = 1
	END IF

  LET smallint_var = -32767
	IF smallint_var != -32767 THEN
	  DISPLAY "Error on smallest small integer comparison "
		LET exitStatus = 1
	END IF

  LET smallint_var = 0
	IF smallint_var != 0 THEN
	  DISPLAY "Error on zero small integer comparison "
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN

