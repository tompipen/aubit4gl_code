{**
 * @file
 * Test if the conversion from SMALLINT to DECIMAL work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_smallint SMALLINT
	DEFINE lv_decimal DECIMAL

  LET exitStatus = 0

	INITIALIZE lv_smallint TO NULL
	LET lv_decimal = lv_smallint
	IF lv_decimal IS NOT NULL THEN
	   DISPLAY "A null smallint converted to decimal was not null"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = 32767
	LET lv_decimal = lv_smallint
	IF lv_decimal != 32767 OR lv_decimal IS NULL THEN
	   DISPLAY "The biggest smallint was not converted to decimal"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = -32767
	LET lv_decimal = lv_smallint
	IF lv_decimal != -32767 OR lv_decimal IS NULL THEN
	   DISPLAY "The smallest smallint was not converted to decimal"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = 0
	LET lv_decimal = lv_smallint
	IF lv_decimal != 0 OR lv_decimal IS NULL THEN
	   DISPLAY "A zero smallint converted to decimal was not converted"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
