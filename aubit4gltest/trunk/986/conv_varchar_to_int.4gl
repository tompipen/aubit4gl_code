{**
 * @file
 * Test if the conversion from varchar to an integer work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_varchar VARCHAR(20)
	DEFINE lv_int INTEGER

  LET exitStatus = 0
	LET lv_varchar = "Hello aubit 4gl testing world"
	LET lv_int = lv_varchar
	IF lv_int IS NOT NULL THEN
	   DISPLAY "A varchar with alfanumeric characters to integer was not null"
		 LET exitStatus = 1
	END IF

	LET lv_varchar = ""
	LET lv_int = lv_varchar
	IF lv_int IS NOT NULL THEN
	   DISPLAY "A varchar with empty string to integer was not null"
		 LET exitStatus = 1
	END IF

	INITIALIZE lv_varchar TO NULL
	LET lv_int = lv_varchar
	IF lv_int IS NOT NULL THEN
	   DISPLAY "A varchar with null string to integer was not null"
		 LET exitStatus = 1
	END IF

	LET lv_varchar = "123446"
	LET lv_int = lv_varchar
	IF lv_int != 123446 OR lv_int IS NULL THEN
	   DISPLAY "The integer was not converted "
		 LET exitStatus = 1
	END IF

	LET lv_varchar = "2000000000"
	LET lv_int = lv_varchar
	IF lv_int != 2000000000 OR lv_int IS NULL THEN
	   DISPLAY "A big integer was not converted"
		 LET exitStatus = 1
	END IF

	LET lv_varchar = "0"
	LET lv_int = lv_varchar
	IF lv_int != 0 OR lv_int IS NULL THEN
	   DISPLAY "A string with a zero converted to integer was not truncated"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
