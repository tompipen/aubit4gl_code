{**
 * @file
 * Test if the conversion from char to a decimal work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_char CHAR(33)
	DEFINE lv_DefDec DECIMAL
	DEFINE lv_Dec_3216 DECIMAL(32,16)
	DEFINE lv_Dec_one DECIMAL(1)
	DEFINE lv_Dec_32 DECIMAL(32)

  LET exitStatus = 0
	LET lv_char = "Hello aubit 4gl testing world"
	LET lv_DefDec = lv_char
	IF lv_DefDec IS NOT NULL AND lv_DefDec != 0.0 THEN
	   DISPLAY "A char with alfanumeric characters to decimal was not null :",
		         lv_DefDec
		 LET exitStatus = 1
	END IF

	LET lv_char = ""
	LET lv_DefDec = lv_char
	IF lv_DefDec IS NOT NULL THEN
	   DISPLAY "A char with empty string to decimal was not null"
		 LET exitStatus = 1
	END IF

	INITIALIZE lv_char TO NULL
	LET lv_DefDec = lv_char
	IF lv_DefDec IS NOT NULL THEN
	   DISPLAY "A char with null string to decimal was not null"
		 LET exitStatus = 1
	END IF

	LET lv_char = "1234567890123456.1234567890123456"
	LET lv_Dec_3216 = lv_char
	IF lv_Dec_3216 != 1234567890123456.1234567890123456
	   OR lv_Dec_3216 IS NULL 
	THEN
	   DISPLAY "The Decimal(32,16) was not converted <", lv_Dec_3216, ">"
		 LET exitStatus = 1
	END IF

	LET lv_char = "1234567890123456789012345678901.0"
	LET lv_Dec_32 = lv_char
	IF lv_Dec_32 != 1234567890123456789012345678901.0
	   OR lv_Dec_32 IS NULL 
	THEN
	   DISPLAY "The Decimal(32) was not converted <", lv_Dec_32, ">"
		 LET exitStatus = 1
	END IF

	LET lv_char = "0"
	LET lv_Dec_one = lv_char
	IF lv_Dec_one != 0 OR lv_Dec_one IS NULL THEN
	   DISPLAY "A string with a zero converted to float was not"
		 LET exitStatus = 1
	END IF

	LET lv_char = "9"
	LET lv_Dec_one = lv_char
	IF lv_Dec_one != 9 OR lv_Dec_one IS NULL THEN
	   DISPLAY "A string with a zero converted to float was not"
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
