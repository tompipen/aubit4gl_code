{**
 * Test if the conversion from an integer to a date works
 *}
MAIN
  DEFINE exitStatus SMALLINT
	DEFINE lv_int INTEGER
	DEFINE lv_date DATE

	LET exitStatus = 0 
	LET lv_int = 1
	LET lv_date = lv_int
	IF lv_date != mdy(01,01,1900) THEN
	  DISPLAY "The conversion from integer one to date was not correct"
	END IF

	LET lv_int = 2958464
	LET lv_date = lv_int
	IF lv_date != mdy(12,31,9999) THEN
	  DISPLAY "The conversion from biggest date from integer one was not correct"
	END IF

	LET lv_int = 0
	LET lv_date = lv_int
	IF lv_date != mdy(12,31,1899) THEN
	  DISPLAY "The conversion from integer zero to date one was not correct"
	END IF

	LET lv_int = -693594
	LET lv_date = lv_int
	IF lv_date != mdy(1,1,1) THEN
	  DISPLAY "The conversion from lowest date from integer one was not correct"
	END IF
	EXIT PROGRAM exitStatus
END MAIN
