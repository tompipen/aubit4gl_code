{**
 * Test the float variable limits.
 * @todo : This is not OK. I must discuss it on the developers list
 * @process DATA_TYPE
 *}

MAIN
  DEFINE float_var FLOAT
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0

  LET float_var = 999999999999999.999999999999999
	IF float_var != 999999999999999.1 THEN
	  DISPLAY "Error on largest smallfloat comparison "
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN

