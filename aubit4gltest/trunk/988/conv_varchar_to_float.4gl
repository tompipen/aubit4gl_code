{**
 * @file
 * Test if the conversion from varchar to a float work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_varchar VARCHAR(30)
	DEFINE lv_float FLOAT

  LET exitStatus = 0
	LET lv_varchar = "Hello aubit 4gl testing world"
	LET lv_float = lv_varchar
	IF lv_float != 0.0 THEN
	   DISPLAY "A varchar with alfanumeric characters to float was not null"
		 LET exitStatus = 1
	END IF

	LET lv_varchar = ""
	LET lv_float = lv_varchar
	IF lv_float IS NOT NULL THEN
	   DISPLAY "A varchar with empty string to float was not null"
		 LET exitStatus = 1
	END IF

	INITIALIZE lv_varchar TO NULL
	LET lv_float = lv_varchar
	IF lv_float IS NOT NULL THEN
	   DISPLAY "A varchar with null string to float was not null"
		 LET exitStatus = 1
	END IF

	LET lv_varchar = "2147483647"
	LET lv_float = lv_varchar
	IF lv_float != 2147483647 OR lv_float IS NULL THEN
	   DISPLAY "The float was not converted "
		 LET exitStatus = 1
	END IF

	LET lv_varchar = "1234,5678901234"
	LET lv_float = lv_varchar
	IF lv_float != 1234.5678901234 OR lv_float IS NULL THEN
	   DISPLAY "A float on a string was not converted to float : ", 
		         lv_float 
		 LET exitStatus = 1
	END IF

	LET lv_varchar = "0"
	LET lv_float = lv_varchar
	IF lv_float != 0 OR lv_float IS NULL THEN
	   DISPLAY "A string with a zero converted to float was not"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
