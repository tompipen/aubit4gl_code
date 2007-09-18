{**
 * Test the smallfloat variable limits.
 * @todo : This is not OK. I must discuss it on the developers list
 * @process DATA_TYPE
 *}

MAIN
  DEFINE smallfloat_var SMALLFLOAT
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0

  LET smallfloat_var = 999999999999999.999999999999999
	DISPLAY smallfloat_var 
	IF smallfloat_var - 999999999999999.1> 0.01 THEN
	  DISPLAY "Error on largest smallfloat comparison "
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN

