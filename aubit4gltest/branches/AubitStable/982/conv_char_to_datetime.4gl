{**
 * Test the conversion from char(s) to datetime(s).
 * @process DATA_TYPE_CONVERSION
 *}

MAIN
	DEFINE lv_char CHAR(24)
  DEFINE lv_dtyy DATETIME YEAR TO YEAR
  DEFINE lv_dtymo DATETIME YEAR TO MONTH
  DEFINE lv_dtyd DATETIME YEAR TO DAY
  DEFINE lv_dtyh DATETIME YEAR TO HOUR
  DEFINE lv_dtymin DATETIME YEAR TO MINUTE
  DEFINE lv_dtys DATETIME YEAR TO SECOND
  DEFINE lv_dtyf DATETIME YEAR TO FRACTION
  DEFINE lv_dtyfprec DATETIME YEAR TO FRACTION(4)
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0

	LET lv_char = "0"
	LET lv_dtyy = lv_char
	IF lv_dtyy != DATETIME(0) YEAR TO YEAR OR lv_dtyy IS NULL THEN
		DISPLAY "Error DATETIME 0"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9999" 
	LET lv_dtyy = lv_char
	IF lv_dtyy != DATETIME(9999) YEAR TO YEAR THEN
		DISPLAY "Error DATETIME 9999"
	  LET exitStatus = 1
	END IF

	-- YEAR TO MONTH
	LET lv_char = "0001-01" 
	LET lv_dtymo = lv_char
	IF lv_dtymo != DATETIME(0001-01) YEAR TO MONTH THEN
		DISPLAY "Error DATETIME 0001-01"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9999-01"
	LET lv_dtymo = lv_char
	IF lv_dtymo != DATETIME(9999-01) YEAR TO MONTH THEN
		DISPLAY "Error DATETIME 9999-01"
	  LET exitStatus = 1
	END IF

	LET lv_char = "0001-12"
	LET lv_dtymo = lv_char
	IF lv_dtymo != DATETIME(0001-12) YEAR TO MONTH THEN
		DISPLAY "Error DATETIME 0001-12"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9999-12"
	LET lv_dtymo = lv_char
	IF lv_dtymo != DATETIME(9999-12) YEAR TO MONTH THEN
		DISPLAY "Error DATETIME 9999-12"
	  LET exitStatus = 1
	END IF

	-- YEAR TO DAY
	LET lv_char = "0001-01-01"
	LET lv_dtyd = lv_char
	IF lv_dtyd != DATETIME(0001-01-01) YEAR TO DAY THEN
		DISPLAY "Error DATETIME 0001-01-01"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9999-12-31"
	LET lv_dtyd = lv_char
	IF lv_dtyd != DATETIME(9999-12-31) YEAR TO DAY THEN
		DISPLAY "Error DATETIME 9999-12-31"
	  LET exitStatus = 1
	END IF

	-- YEAR TO HOUR
	LET lv_char = "0001-01-01 00"
	LET lv_dtyh = lv_char
	IF lv_dtyh != DATETIME(0001-01-01 00) YEAR TO HOUR THEN
		DISPLAY "Error DATETIME 0001-01-01 00"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9999-12-31 23"
	LET lv_dtyh = lv_char
	IF lv_dtyh != DATETIME(9999-12-31 23) YEAR TO HOUR THEN
		DISPLAY "Error DATETIME 9999-12-31 23"
	  LET exitStatus = 1
	END IF

	-- YEAR TO MINUTE
	LET lv_char = "0001-01-01 00:00"
	LET lv_dtymin = lv_char
	IF lv_dtymin != DATETIME(0001-01-01 00:00) YEAR TO MINUTE THEN
		DISPLAY "Error DATETIME 0001-01-01 00:00"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9999-12-31 23:59"
	LET lv_dtymin = lv_char
	IF lv_dtymin != DATETIME(9999-12-31 23:59) YEAR TO MINUTE THEN
		DISPLAY "Error DATETIME 9999-12-31 23 59"
	  LET exitStatus = 1
	END IF

	-- YEAR TO SECOND
	LET lv_char = "0001-01-01 00:00:00"
	LET lv_dtys = lv_char
	IF lv_dtys != DATETIME(0001-01-01 00:00:00) YEAR TO SECOND THEN
		DISPLAY "Error DATETIME 0001-01-01 00:00:00"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9999-12-31 23:59:59"
	LET lv_dtys = lv_char
	IF lv_dtys != DATETIME(9999-12-31 23:59:59) YEAR TO SECOND THEN
		DISPLAY "Error DATETIME 9999-12-31 23 59"
	  LET exitStatus = 1
	END IF

	-- YEAR TO FRACTION
	LET lv_char = "0001-01-01 00:00:00.000"
	LET lv_dtyf = lv_char
	IF lv_dtyf != DATETIME(0001-01-01 00:00:00.000) YEAR TO FRACTION THEN
		DISPLAY "Error DATETIME 0001-01-01 00:00:00.00"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9999-12-31 23:59:59.999"
	LET lv_dtyf = lv_char
	IF lv_dtyf != DATETIME(9999-12-31 23:59:59.999) YEAR TO FRACTION THEN
		DISPLAY "Error DATETIME 9999-12-31 23 59.999"
	  LET exitStatus = 1
	END IF

	-- YEAR TO FRACTION(4)
	LET lv_char = "0001-01-01 00:00:00.0000"
	LET lv_dtyfprec = lv_char
	IF lv_dtyfprec != DATETIME(0001-01-01 00:00:00.0000) YEAR TO FRACTION(4) THEN
		DISPLAY "Error DATETIME 0001-01-01 00:00:00.0000"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9999-12-31 23:59:59.9999"
	LET lv_dtyfprec = lv_char
	IF lv_dtyfprec != DATETIME(9999-12-31 23:59:59.9999) YEAR TO FRACTION(4) THEN
		DISPLAY "Error DATETIME 9999-12-31 23 59.9999"
	  LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN

