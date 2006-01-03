{**
 * @file
 * Test if the conversion from INTEGER to a varchar work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_int INTEGER
	DEFINE lv_varchar VARCHAR(20)

  LET exitStatus = 0

	INITIALIZE lv_int TO NULL
	LET lv_varchar = lv_int
	IF lv_varchar IS NOT NULL THEN
	   DISPLAY "A varchar with null string to integer was not null"
		 LET exitStatus = 1
	END IF

	LET lv_int = 123446
	LET lv_varchar = lv_int
	IF lv_varchar != "123446" OR lv_varchar IS NULL THEN
	   DISPLAY "The integer was not converted "
		 LET exitStatus = 1
	END IF

	LET lv_int = 2000000000
	LET lv_varchar = lv_int
	IF lv_varchar != "2000000000" OR lv_varchar IS NULL THEN
	   DISPLAY "A big integer was not converted"
		 LET exitStatus = 1
	END IF

	LET lv_int = 0
	LET lv_varchar = lv_int
	IF lv_varchar != "0" OR lv_varchar IS NULL THEN
	   DISPLAY "A string with a zero converted to integer was not truncated"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
