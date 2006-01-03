{**
 * @file
 * Test if the conversion from char to a smallint work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_char CHAR(20)
	DEFINE lv_smallint SMALLINT

  LET exitStatus = 0
	LET lv_char = "Hello aubit 4gl testing world"
	LET lv_smallint = lv_char
	IF lv_smallint IS NOT NULL THEN
	   DISPLAY "A char with alfanumeric characters to smallint was not null"
		 LET exitStatus = 1
	END IF

	LET lv_char = ""
	LET lv_smallint = lv_char
	IF lv_smallint IS NOT NULL THEN
	   DISPLAY "A char with empty string to smallint was not null"
		 LET exitStatus = 1
	END IF

	INITIALIZE lv_char TO NULL
	LET lv_smallint = lv_char
	IF lv_smallint IS NOT NULL THEN
	   DISPLAY "A char with null string to smallint was not null"
		 LET exitStatus = 1
	END IF

	LET lv_char = "32767"
	LET lv_smallint = lv_char
	IF lv_smallint != 32767 OR lv_smallint IS NULL THEN
	   DISPLAY "The smallint was not converted "
		 LET exitStatus = 1
	END IF

	LET lv_char = "-32767"
	LET lv_smallint = lv_char
	IF lv_smallint != -32767 OR lv_smallint IS NULL THEN
	   DISPLAY "The lowest SMALLINT on a sring was not converted to smallint"
		 LET exitStatus = 1
	END IF

	LET lv_char = "0"
	LET lv_smallint = lv_char
	IF lv_smallint != 0 OR lv_smallint IS NULL THEN
	   DISPLAY "A string with a zero converted to smallint was not"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
