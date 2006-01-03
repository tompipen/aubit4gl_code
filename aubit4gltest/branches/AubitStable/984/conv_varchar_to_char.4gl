{**
 * @file
 * Test if the conversion from a varchar to a char work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_varchar VARCHAR(10)
	DEFINE lv_char CHAR(20)

  LET exitStatus = 0
	LET lv_varchar = "Hello aubit 4gl testing world"
	LET lv_char = lv_varchar
	IF lv_char != "Hello aubi" THEN
	   DISPLAY "The char was not truncated"
		 LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
