{**
 * @file
 * Test if the conversion from SMALLINT to SMALLFLOAT work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_smallint SMALLINT
	DEFINE lv_smallfloat SMALLFLOAT

  LET exitStatus = 0

	INITIALIZE lv_smallint TO NULL
	LET lv_smallfloat = lv_smallint
	IF lv_smallfloat IS NOT NULL THEN
	   DISPLAY "A null smallint converted to smallfloat was not null"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = 32767
	LET lv_smallfloat = lv_smallint
	IF lv_smallfloat != 32767 OR lv_smallfloat IS NULL THEN
	   DISPLAY "The biggest smallint was not converted to smallfloat"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = -32767
	LET lv_smallfloat = lv_smallint
	IF lv_smallfloat != -32767 OR lv_smallfloat IS NULL THEN
	   DISPLAY "The smallest smallint was not converted to smallfloat"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = 0
	LET lv_smallfloat = lv_smallint
	IF lv_smallfloat != 0 OR lv_smallfloat IS NULL THEN
	   DISPLAY "A zero smallint converted to smallfloat was not converted"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
