{**
 * @file
 * Test if the conversion from SMALLINT to INTEGER work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_smallint SMALLINT
	DEFINE lv_int INTEGER

  LET exitStatus = 0

	INITIALIZE lv_smallint TO NULL
	LET lv_int = lv_smallint
	IF lv_int IS NOT NULL THEN
	   DISPLAY "A null smallint converted to int was not null"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = 32767
	LET lv_int = lv_smallint
	IF lv_int != 32767 OR lv_int IS NULL THEN
	   DISPLAY "The biggest smallint was not converted to integer"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = -32767
	LET lv_int = lv_smallint
	IF lv_int != -32767 OR lv_int IS NULL THEN
	   DISPLAY "The smallest smallint was not converted to integer"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = 0
	LET lv_int = lv_smallint
	IF lv_int != 0 OR lv_int IS NULL THEN
	   DISPLAY "A zero smallint converted to integer was not converted"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
