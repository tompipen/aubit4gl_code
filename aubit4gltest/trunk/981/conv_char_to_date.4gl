{**
 * Test the conversion from CHAR to DATE
 * @todo : Get a way to test DBCENTURY
 * @todo : This should be tested using and setting DBDATE 
 * @process DATA_TYPE
 *}

MAIN
  DEFINE date_variable DATE
	DEFINE lv_char CHAR(10)
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0
	LET lv_char = "12-31-1899"
	LET date_variable = lv_char
	IF date_variable != mdy(12,31,1899) THEN
		DISPLAY "Error in julian zero"
	  LET exitStatus = 1
	END IF

	LET lv_char = "12-31-9999"
	LET date_variable = lv_char
	IF date_variable != mdy(12,31,9999) THEN
		DISPLAY "Error in biggest date"
	  LET exitStatus = 1
	END IF

	LET lv_char = "1-1-0001" # Y2K fixups would take 1 and make it 2001, so specify it in full
	LET date_variable = lv_char
	IF date_variable != mdy(1,1,1) THEN
		DISPLAY "Error in lowest date : ", date_variable
	  LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN

