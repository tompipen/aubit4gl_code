{**
 * @file
 * Test if the conversion from INTEGER to a char work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_int INTEGER
	DEFINE lv_char CHAR(20)

  LET exitStatus = 0

	INITIALIZE lv_int TO NULL
	LET lv_char = lv_int
	IF lv_int IS NOT NULL THEN
	   DISPLAY "A char with null string to integer was not null"
		 LET exitStatus = 1
	END IF

	LET lv_int = 123446
	LET lv_char = lv_int
	IF lv_char != "123446" OR lv_char IS NULL THEN
	   DISPLAY "The integer was not converted "
		 LET exitStatus = 1
	END IF

	LET lv_int = 2000000000
	LET lv_char = lv_int
	IF lv_char != "2000000000" OR lv_char IS NULL THEN
	   DISPLAY "A big integer was not converted"
		 LET exitStatus = 1
	END IF

	LET lv_int = 0
	LET lv_char = lv_int
	IF lv_char != "0" OR lv_char IS NULL THEN
	   DISPLAY "A string with a zero converted to integer was not truncated"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
