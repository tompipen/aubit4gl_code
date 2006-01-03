{**
 * Test the date variable limits.
 * @todo : Get a way to test DBCENTURY
 * @process DATA_TYPE
 *}

MAIN
  DEFINE date_variable DATE
	DEFINE i INTEGER
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0
	LET i = 0
	LET date_variable = mdy(12,31,1899)
	IF date_variable != mdy(12,31,1899) THEN
		DISPLAY "Error in julian zero"
	  LET exitStatus = 1
	END IF

	LET date_variable = mdy(12,31,9999)
	IF date_variable != mdy(12,31,9999) THEN
		DISPLAY "Error in biggest date"
	  LET exitStatus = 1
	END IF

	LET date_variable = date_variable + 1
	IF date_variable != mdy(12,31,1899) THEN
		DISPLAY "Error suming 1 to biggest date"
	  LET exitStatus = 1
	END IF

	LET date_variable = mdy(1,1,1)
	IF date_variable != mdy(1,1,1) THEN
		DISPLAY "Error in lowest date"
	  LET exitStatus = 1
	END IF

	LET date_variable = date_variable - 1
	IF date_variable >= mdy(1,1,1) THEN
		DISPLAY "Error subtracting a date"
	  LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN

