{**
 * @file
 * Test if the conversion from char to a SMALLFLOAT work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_char CHAR(30)
	DEFINE lv_smallfloat SMALLFLOAT

  LET exitStatus = 0
	LET lv_char = "Hello aubit 4gl testing world"
	LET lv_smallfloat = lv_char
	IF lv_smallfloat != 0.0 THEN
	   DISPLAY "A char with alfanumeric characters to smallfloat was not null",
		   lv_smallfloat
		 LET exitStatus = 1
	END IF

	LET lv_char = ""
	LET lv_smallfloat = lv_char
	IF lv_smallfloat IS NOT NULL THEN
	   DISPLAY "A char with empty string to smallfloat was not null"
		 LET exitStatus = 1
	END IF

	INITIALIZE lv_char TO NULL
	LET lv_smallfloat = lv_char
	IF lv_smallfloat IS NOT NULL THEN
	   DISPLAY "A char with null string to smallfloat was not null"
		 LET exitStatus = 1
	END IF

	LET lv_char = "2147483647"
	LET lv_smallfloat = lv_char
	IF lv_smallfloat < 2147483645.0 OR lv_smallfloat > 2147483649.0 or lv_smallfloat IS NULL THEN
	   DISPLAY "The smallfloat was not converted ",lv_smallfloat
		 LET exitStatus = 1
	END IF

	LET lv_char = "1234.5678901234"
	LET lv_smallfloat = lv_char
	IF lv_smallfloat < 1234.5678 or lv_smallfloat > 1234.5679 OR lv_smallfloat IS NULL THEN
	   DISPLAY "A smallfloat on a string was not converted to smallfloat : ", 
		         lv_smallfloat 
		 LET exitStatus = 1
	END IF

	LET lv_char = "0"
	LET lv_smallfloat = lv_char
	IF lv_smallfloat != 0 OR lv_smallfloat IS NULL THEN
	   DISPLAY "A string with a zero converted to smallfloat was not"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
