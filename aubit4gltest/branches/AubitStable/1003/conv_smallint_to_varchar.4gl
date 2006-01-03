{**
 * @file
 * Test if the conversion from SMALLINT to a varchar work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_smallint SMALLINT
	DEFINE lv_char VARCHAR(20)

  LET exitStatus = 0

	INITIALIZE lv_smallint TO NULL
	LET lv_char = lv_smallint
	IF lv_smallint IS NOT NULL THEN
	   DISPLAY "A null smallint converted to char was not null"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = 32767
	LET lv_char = lv_smallint
	IF lv_char != "32767" OR lv_char IS NULL THEN
	   DISPLAY "The biggest smallint was not converted "
		 LET exitStatus = 1
	END IF

	LET lv_smallint = -32767
	LET lv_char = lv_smallint
	IF lv_char != "-32767" OR lv_char IS NULL THEN
	   DISPLAY "The smallest smallint was not converted"
		 LET exitStatus = 1
	END IF

	LET lv_smallint = 0
	LET lv_char = lv_smallint
	IF lv_char != "0" OR lv_char IS NULL THEN
	   DISPLAY "A string with a zero converted to smallint was not converted"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
