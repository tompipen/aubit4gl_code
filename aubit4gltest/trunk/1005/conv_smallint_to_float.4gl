{**
 * @file
 * Test if the conversion from SMALLINT to FLOAT work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_smallint SMALLINT
	DEFINE lv_float FLOAT

  LET exitStatus = 0

	INITIALIZE lv_smallint TO NULL
	LET lv_float = lv_smallint
	IF lv_float IS NOT NULL THEN
	   DISPLAY "A null smallint converted to float was not null"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = 32767
	LET lv_float = lv_smallint
	IF lv_float != 32767 OR lv_float IS NULL THEN
	   DISPLAY "The biggest smallint was not converted to float"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = -32767
	LET lv_float = lv_smallint
	IF lv_float != -32767 OR lv_float IS NULL THEN
	   DISPLAY "The smallest smallint was not converted to float"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = 0
	LET lv_float = lv_smallint
	IF lv_float != 0 OR lv_float IS NULL THEN
	   DISPLAY "A zero smallint converted to float was not converted"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
