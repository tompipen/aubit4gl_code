{**
 * Test the conversion from VARCHAR to DATE
 * @todo : Get a way to test DBCENTURY
 * @todo : This should be tested using and setting DBDATE 
 * @process DATA_TYPE
 *}

MAIN
  DEFINE date_variable DATE
	DEFINE lv_varchar VARCHAR(10)
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0
	LET lv_varchar = "12-31-1899"
	LET date_variable = lv_varchar
	IF date_variable != mdy(12,31,1899) THEN
		DISPLAY "Error in julian zero"
	  LET exitStatus = 1
	END IF

	LET lv_varchar = "12-31-9999"
	LET date_variable = lv_varchar
	IF date_variable != mdy(12,31,9999) THEN
		DISPLAY "Error in biggest date"
	  LET exitStatus = 1
	END IF

	LET lv_varchar = "1-1-1"
	LET date_variable = lv_varchar
	IF date_variable != mdy(1,1,1) THEN
		DISPLAY "Error in lowest date : ", date_variable
	  LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN

