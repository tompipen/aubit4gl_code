{**
 * @file
 * Test if the conversion from char to a money work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_char CHAR(33)
	DEFINE lv_DefMoney MONEY
	DEFINE lv_Money_3216 MONEY(32,16)
	DEFINE lv_Money_one MONEY(1,0)
	DEFINE lv_Money_zero_one MONEY(1,1)
	DEFINE lv_Money_32 MONEY(32,1)

  LET exitStatus = 0
	LET lv_char = "Hello aubit 4gl testing world"
	LET lv_DefMoney = lv_char
	IF lv_DefMoney IS NOT NULL AND lv_DefMoney != 0.0 THEN
	   DISPLAY "A char with alfanumeric characters to money was not null :",
		         lv_DefMoney
		 LET exitStatus = 1
	END IF

	LET lv_char = ""
	LET lv_DefMoney = lv_char
	IF lv_DefMoney IS NOT NULL THEN
	   DISPLAY "A char with empty string to money was not null"
		 LET exitStatus = 1
	END IF

	INITIALIZE lv_char TO NULL
	LET lv_DefMoney = lv_char
	IF lv_DefMoney IS NOT NULL THEN
	   DISPLAY "A char with null string to decimal was not null"
		 LET exitStatus = 1
	END IF

	LET lv_char = "1234567890123456.1234567890123456"
	LET lv_Money_3216 = lv_char
	IF lv_Money_3216 != 1234567890123456.1234567890123456
	   OR lv_Money_3216 IS NULL 
	THEN
	   DISPLAY "The Money(32,16) was not converted <", lv_Money_3216, ">"
		 LET exitStatus = 1
	END IF

	LET lv_char = "1234567890123456789012345678901.0"
	LET lv_Money_32 = lv_char
	IF lv_Money_32 != 1234567890123456789012345678901.0
	   OR lv_Money_32 IS NULL 
	THEN
	   DISPLAY "The Money(32) was not converted <", lv_Money_32, ">"
		 LET exitStatus = 1
	END IF

	LET lv_char = "0"
	LET lv_Money_one = lv_char
	IF lv_Money_one != 0 OR lv_Money_one IS NULL THEN
	   DISPLAY "A string with a zero converted to money was not"
		 LET exitStatus = 1
	END IF

	LET lv_char = "9"
	LET lv_Money_one = lv_char
	IF lv_Money_one != 9 OR lv_Money_one IS NULL THEN
	   DISPLAY "A string with a zero was not converted to money "
		 LET exitStatus = 1
	END IF

	LET lv_char = "0.9"
	LET lv_Money_zero_one = lv_char
	IF lv_Money_zero_one != 0.9 OR lv_Money_one IS NULL THEN
	   DISPLAY "A string with a zero dot nine was not converted to money ", 
		         lv_money_zero_one
		 LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
