{**
 * @file
 * Test if the conversion from char to another char works.
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_char CHAR(20)
	DEFINE lv_smallchar CHAR(10)

  LET exitStatus = 0
	LET lv_char = "Hello aubit 4gl testing world"
	LET lv_smallchar = lv_char
	IF lv_smallchar != "Hello aubi" THEN
	   DISPLAY "The char was not truncated"
		 LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
