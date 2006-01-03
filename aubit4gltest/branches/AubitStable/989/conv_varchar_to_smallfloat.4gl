{**
 * @file
 * Test if the conversion from varchar to a SMALLFLOAT work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_varchar VARCHAR(30)
	DEFINE lv_smallfloat SMALLFLOAT

  LET exitStatus = 0
	LET lv_varchar = "Hello aubit 4gl testing world"
	LET lv_smallfloat = lv_varchar
	IF lv_smallfloat != 0.0 THEN
	   DISPLAY "A varchar with alfanumeric characters to smallfloat was not zero",
		   lv_smallfloat
		 LET exitStatus = 1
	END IF

	LET lv_varchar = ""
	LET lv_smallfloat = lv_varchar
	IF lv_smallfloat IS NOT NULL THEN
	   DISPLAY "A varchar with empty string to smallfloat was not null"
		 LET exitStatus = 1
	END IF

	INITIALIZE lv_varchar TO NULL
	LET lv_smallfloat = lv_varchar
	IF lv_smallfloat IS NOT NULL THEN
	   DISPLAY "A varchar with null string to smallfloat was not null"
		 LET exitStatus = 1
	END IF

	LET lv_varchar = "2147483647"
	LET lv_smallfloat = lv_varchar
	# Precision on a smallfloat isn't great :-(
	IF lv_smallfloat <2147483646.0 OR lv_smallfloat >2147483649.0 OR lv_smallfloat IS NULL THEN
	   DISPLAY "The smallfloat was not converted ",lv_smallfloat
		 LET exitStatus = 1
	END IF

	LET lv_varchar = "1234.5678901234"
	LET lv_smallfloat = lv_varchar
	IF lv_smallfloat < 1234.567 OR lv_smallfloat >= 1234.568 OR lv_smallfloat IS NULL THEN
	   DISPLAY "A smallfloat on a string was not converted to smallfloat : ", 
		         lv_smallfloat 
		 LET exitStatus = 1
	END IF

	LET lv_varchar = "0"
	LET lv_smallfloat = lv_varchar
	IF lv_smallfloat != 0 OR lv_smallfloat IS NULL THEN
	   DISPLAY "A string with a zero converted to smallfloat was not"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
