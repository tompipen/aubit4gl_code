{**
 * @file
 * Test if the conversion from a varchar to a varchar work
 * @process TEST_CONV
 *}

MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_smallvarchar VARCHAR(10)
	DEFINE lv_varchar VARCHAR(20)

  LET exitStatus = 0
	LET lv_varchar = "Hello aubit 4gl testing world"
	LET lv_smallvarchar = lv_varchar
	IF lv_smallvarchar != "Hello aubi" THEN
	   DISPLAY "The char was not truncated"
		 LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
