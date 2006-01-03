{**
 * @file
 * Test if the conversion from INTEGER to a DECIAL work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_int INTEGER
	DEFINE lv_decimal DECIMAL

  LET exitStatus = 0

	INITIALIZE lv_int TO NULL
	LET lv_decimal = lv_int
	IF lv_decimal IS NOT NULL THEN
	   DISPLAY "The conversion from null integer to decimal was not null"
		 LET exitStatus = 1
	END IF

	LET lv_int = 123446
	LET lv_decimal = lv_int
	IF lv_decimal != 123446 OR lv_int IS NULL THEN
	   DISPLAY "The integer was not converted "
		 LET exitStatus = 1
	END IF

	LET lv_int = 2000000000
	LET lv_decimal = lv_int
	IF lv_decimal != 2000000000 OR lv_int IS NULL THEN
	   DISPLAY "A big integer was not converted"
		 LET exitStatus = 1
	END IF

	LET lv_int = 0
	LET lv_decimal = lv_int
	IF lv_decimal != 0 OR lv_decimal IS NULL THEN
	   DISPLAY "A string with a zero converted to integer was not truncated"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
