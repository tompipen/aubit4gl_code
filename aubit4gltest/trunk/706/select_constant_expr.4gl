
DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE lv_singleQuoted CHAR(10)
  DEFINE lv_doubleQuoted CHAR(10)
  DEFINE exitStatus SMALLINT
	DEFINE r_ RECORD
	  doubleQuotedStr CHAR(20),
		singleQuotedStr VARCHAR(20,10),
		userStr CHAR(10),
		-- Literal numbers
		aNegativeInteger INTEGER,
		aPlusInteger SMALLINT,
		anInteger INTEGER,
    aPositiveFloat FLOAT,
		aNegativeSmallfloat SMALLFLOAT,
		aDecimal DECIMAL(3,2),
		aNegNumExpThree FLOAT,
		aNegFltExpNegThree FLOAT,
		aNegSmftExpThree SMALLFLOAT,
    aFltExpThree FLOAT,
		aSmftExpNegThree SMALLFLOAT,
		aNumExpThree REAL,
		aNumExpPlusThree REAL,
		aFltExpNegThree FLOAT,
    aFloatExpThree FLOAT,
    aNegFloatExpThree FLOAT,
		aNegDecExpNegThree SMALLFLOAT,
		aNegFltExpThree FLOAT,
		aPlusNumExpPlusThree REAL,
		aPlusDecExpNegThree FLOAT,
		aPlusDecExpThree SMALLFLOAT,
		aDecExpThree REAL,
		aDecExpNegThree FLOAT,
		aDecExpPlusThree SMALLFLOAT,

	  # Datetimes
		aDate DATE,
		-- Current(s)
		currYearYear	DATETIME YEAR TO YEAR, 
		currYearMonth	DATETIME YEAR TO MONTH, 
		currYearDay	DATETIME YEAR TO DAY,
		currYearHour	DATETIME YEAR TO HOUR, 
		currYearMinute	DATETIME YEAR TO MINUTE, 
		currYearSecond	DATETIME YEAR TO SECOND,
		currYearFraction	DATETIME YEAR TO FRACTION, 
		currMonthMonth	DATETIME MONTH TO MONTH, 
		currMonthDay	DATETIME MONTH TO DAY, 
		currMonthHour	DATETIME MONTH TO HOUR, 
		currMonthMinute	DATETIME MONTH TO MINUTE, 
		currMonthSecond	DATETIME MONTH TO SECOND,
		currMonthFraction	DATETIME MONTH TO FRACTION, 
		currDayDay	DATETIME DAY TO DAY, 
		currDayHour	DATETIME DAY TO HOUR, 
		currDayMinute	DATETIME DAY TO MINUTE, 
		currDaySecond	DATETIME DAY TO SECOND,
		currDayFraction	DATETIME DAY TO FRACTION, 
		currHourHour	DATETIME HOUR TO HOUR, 
		currHourMinute	DATETIME HOUR TO MINUTE, 
		currHourSecond	DATETIME HOUR TO SECOND,
		currHourFraction	DATETIME HOUR TO FRACTION, 
		currMinuteMinute	DATETIME MINUTE TO MINUTE, 
		currMinuteSecond	DATETIME MINUTE TO SECOND,
		currMinuteFraction	DATETIME MINUTE TO FRACTION, 
		currSecondSecond	DATETIME SECOND TO SECOND, 
		currSecondFraction	DATETIME SECOND TO FRACTION,
		--
     aDateTimeYY DATETIME YEAR TO YEAR,
     aDateTimeYM DATETIME YEAR TO MONTH,
     aDateTimeYD DATETIME YEAR TO DAY,
     aDateTimeYH DATETIME YEAR TO HOUR,
     aDateTimeYMin DATETIME YEAR TO MINUTE,
     aDateTimeYS DATETIME YEAR TO SECOND,
     aDateTimeYF DATETIME YEAR TO FRACTION,
     aDateTimeYFScale DATETIME YEAR TO FRACTION(2),
     aDateTimeMM DATETIME MONTH TO MONTH,
     aDateTimeMD DATETIME MONTH TO DAY,
     aDateTimeMH DATETIME MONTH TO HOUR,
     aDateTimeMMin DATETIME MONTH TO MINUTE,
     aDateTimeMS DATETIME MONTH TO SECOND,
     --aDateTimeMF DATETIME MONTH TO FRACTION,
     aDateTimeMFScale DATETIME MONTH TO FRACTION(2),
     aDateTimeDD DATETIME DAY TO DAY,
     aDateTimeDH DATETIME DAY TO HOUR,
     aDateTimeDMin DATETIME DAY TO MINUTE,
     aDateTimeDS DATETIME DAY TO SECOND,
     --aDateTimeDF DATETIME DAY TO FRACTION,
     aDateTimeDFScale DATETIME DAY TO FRACTION(2),
     aDateTimeHH DATETIME HOUR TO HOUR,
     aDateTimeHM DATETIME HOUR TO MINUTE,
     aDateTimeHS DATETIME HOUR TO SECOND,
     --aDateTimeHF DATETIME HOUR TO FRACTION,
     aDateTimeHFScale DATETIME HOUR TO FRACTION(2),
     aDateTimeMinMin DATETIME MINUTE TO MINUTE,
     aDateTimeMinS DATETIME MINUTE TO SECOND,
     --aDateTimeMinF DATETIME MINUTE TO FRACTION,
     aDateTimeMinFScale DATETIME MINUTE TO FRACTION(2),
     aDateTimeSS DATETIME SECOND TO SECOND,
     --aDateTimeSF DATETIME SECOND TO FRACTION,
     aDateTimeSFScale DATETIME SECOND TO FRACTION(2),
     --aDateTimeFF DATETIME FRACTION TO FRACTION,
     --aDateTimeFFScale DATETIME FRACTION TO FRACTION(3),

	   # Interval(s)
     aIntervalYY INTERVAL YEAR TO YEAR,
     aIntervalYPrecY INTERVAL YEAR (4) TO YEAR,
     aIntervalYM INTERVAL YEAR TO MONTH,
     aIntervalYPrecM INTERVAL YEAR (4) TO MONTH,
     aIntervalMM INTERVAL MONTH TO MONTH,
     --aIntervalMPrecM INTERVAL MONTH(2) TO MONTH,
     aIntervalDD INTERVAL DAY TO DAY,
     aIntervalDPrecD INTERVAL DAY (2) TO DAY,
     aIntervalDH INTERVAL DAY TO HOUR,
     aIntervalDPrecH INTERVAL DAY (2) TO HOUR,
     aIntervalDMin INTERVAL DAY TO MINUTE,
     aIntervalDPrecMin INTERVAL DAY (2) TO MINUTE,
     aIntervalDS INTERVAL DAY TO SECOND,
     aIntervalDPrecS INTERVAL DAY (2) TO SECOND,
     aIntervalDF INTERVAL DAY TO FRACTION,
     aIntervalDPrecF INTERVAL DAY (2) TO FRACTION,
     aIntervalDFScale INTERVAL DAY TO FRACTION(2),
     aIntervalDPrecFScale INTERVAL DAY (2) TO FRACTION(2),
     aIntervalHH INTERVAL HOUR TO HOUR,
     aIntervalHPrecH INTERVAL HOUR (2) TO HOUR,
     aIntervalHM INTERVAL HOUR TO MINUTE,
     aIntervalHPrecM INTERVAL HOUR (2) TO MINUTE,
     aIntervalHS INTERVAL HOUR TO SECOND,
     aIntervalHPrecS INTERVAL HOUR (2) TO SECOND,
     aIntervalHF INTERVAL HOUR TO FRACTION,
     aIntervalHPrecF INTERVAL HOUR (2) TO FRACTION,
     aIntervalHFScale INTERVAL HOUR TO FRACTION(2),
     aIntervalHPFS INTERVAL HOUR (2) TO FRACTION(2),
     aIntervalMinMin INTERVAL MINUTE TO MINUTE,
     aIntervalMinPrecMin INTERVAL MINUTE (2) TO MINUTE,
     aIntervalMinS INTERVAL MINUTE TO SECOND,
     aIntervalMinPrecS INTERVAL MINUTE (2) TO SECOND,
     aIntervalMinF INTERVAL MINUTE TO FRACTION,
     aIntervalMinPrecF INTERVAL MINUTE (2) TO FRACTION,
     aIntervalMinFScale INTERVAL MINUTE (2) TO FRACTION(1),
     aIntervalMinPFS INTERVAL MINUTE (2) TO FRACTION(1),
     aIntervalSS INTERVAL SECOND TO SECOND,
     aIntervalSPrecS INTERVAL SECOND (2) TO SECOND,
     aIntervalSF INTERVAL SECOND TO FRACTION,
     aIntervalSPrecF INTERVAL SECOND (2) TO FRACTION,
     aIntervalSFScale INTERVAL SECOND TO FRACTION(2),
     aIntervalSPFS INTERVAL SECOND (2) TO FRACTION(2)
     --aIntervalFF INTERVAL FRACTION TO FRACTION,
     --aIntervalFFScale INTERVAL FRACTION TO FRACTION(3),
	END RECORD

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE all_datatypes
  WHENEVER ERROR STOP
  CREATE TABLE all_datatypes (
		keyColumn SMALLINT
	)
  INSERT INTO all_datatypes (keyColumn) VALUES (1)
  SELECT 
	  "Double quoted" , 
		'Single quoted', 
		USER, 
		-- Literal numbers
	  -1, 
		+1, 
		1, 
		+1.01, 
		-1.01, 
		1.01, 
		-1E+3, 
		-1E-3, 
		-1E3, 
		+1E+3, 
		+1E-3, 
		+1E3, 
		1E+3, 
		1E-3, 
		1E3,
		-1.01E+3, 
		-1.01E-3, 
		-1.01E3, 
		+1.01E+3, 
		+1.01E-3, 
		+1.01E3, 
		1.01E+3, 
		1.01E-3, 
		1.01E3,

		# Datetimes
		TODAY,
		-- Combination of possible currents
		CURRENT YEAR TO YEAR, 
		CURRENT YEAR TO MONTH, 
		CURRENT YEAR TO DAY,
		CURRENT YEAR TO HOUR, 
		CURRENT YEAR TO MINUTE, 
		CURRENT YEAR TO SECOND,
		CURRENT YEAR TO FRACTION, 
		CURRENT MONTH TO MONTH, 
		CURRENT MONTH TO DAY, 
		CURRENT MONTH TO HOUR, 
		CURRENT MONTH TO MINUTE, 
		CURRENT MONTH TO SECOND,
		CURRENT MONTH TO FRACTION, 
		CURRENT DAY TO DAY, 
		CURRENT DAY TO HOUR, 
		CURRENT DAY TO MINUTE, 
		CURRENT DAY TO SECOND,
		CURRENT DAY TO FRACTION, 
		CURRENT HOUR TO HOUR, 
		CURRENT HOUR TO MINUTE, 
		CURRENT HOUR TO SECOND,
		CURRENT HOUR TO FRACTION, 
		CURRENT MINUTE TO MINUTE, 
		CURRENT MINUTE TO SECOND,
		CURRENT MINUTE TO FRACTION, 
		CURRENT SECOND TO SECOND, 
		CURRENT SECOND TO FRACTION,
		-- Literal datetime(s)
    datetime(1999) YEAR TO YEAR,
    datetime(1999-12) YEAR TO MONTH,
    datetime(1999-12-31) YEAR TO DAY,
    datetime(1999-12-31 23) YEAR TO HOUR,
    datetime(1999-12-31 23:59) YEAR TO MINUTE,
    datetime(1999-12-31 23:59:59) YEAR TO SECOND,
    datetime(1999-12-31 23:59:59.999) YEAR TO FRACTION,
    datetime(1999-12-31 23:59:59.99) YEAR TO FRACTION(2),
    datetime(12) MONTH TO MONTH,
    datetime(12-31) MONTH TO DAY,
    datetime(12-31 23) MONTH TO HOUR,
    datetime(12-31 23:59) MONTH TO MINUTE,
    datetime(12-31 23:59:59) MONTH TO SECOND,
    --datetime(12-31 23:59:59.9999) MONTH TO FRACTION,
    datetime(12-31 23:59:59.99) MONTH TO FRACTION(2),
    datetime(31) DAY TO DAY,
    datetime(31 23) DAY TO HOUR,
    datetime(31 23:59) DAY TO MINUTE,
    datetime(31 23:59:59) DAY TO SECOND,
    --datetime(31 23:59:59.9999) DAY TO FRACTION,
    datetime(31 23:59:59.99) DAY TO FRACTION(2),
    datetime(23) HOUR TO HOUR,
    datetime(23:59) HOUR TO MINUTE,
    datetime(23:59:59) HOUR TO SECOND,
    --datetime(23:59:59.9999) HOUR TO FRACTION,
    datetime(23:59:59.99) HOUR TO FRACTION(2),
    datetime(59) MINUTE TO MINUTE,
    datetime(59:59) MINUTE TO SECOND,
    --datetime(59:59.9999) MINUTE TO FRACTION,
    datetime(59:59.99) MINUTE TO FRACTION(2),
    datetime(59) SECOND TO SECOND,
    --datetime(59.9999) SECOND TO FRACTION,
    datetime(59.99) SECOND TO FRACTION(2),
    --datetime(9999) FRACTION TO FRACTION,
    --datetime(99) FRACTION TO FRACTION(2),
	  # Literal Interval(s) =
    INTERVAL(1) YEAR TO YEAR,
    INTERVAL(1) YEAR(4) TO YEAR,
    INTERVAL(1-1) YEAR TO MONTH,
    INTERVAL (1-1) YEAR(4) TO MONTH,
    INTERVAL (1) MONTH TO MONTH,
    --interval (1) MONTH(2) TO MONTH,
    interval (1) DAY TO DAY,
    interval (1) DAY(2) TO DAY,
    interval (1 1) DAY TO HOUR,
    interval (1 1) DAY(2) TO HOUR,
    interval (1 1:1) DAY TO MINUTE,
    interval (1 1:1) DAY(2) TO MINUTE,
    interval (1 1:1:1) DAY TO SECOND,
    interval (1 1:1:1) DAY(2) TO SECOND,
    interval (1 1:1:1.1) DAY TO FRACTION,
    interval (1 1:1:1.1) DAY(2) TO FRACTION,
    interval (1 1:1:1.1) DAY TO FRACTION(2),
    interval (1 1:1:1.1) DAY(2) TO FRACTION(2),
    interval (1) HOUR TO HOUR,
    interval (1) HOUR(2) TO HOUR,
    interval (1:1) HOUR TO MINUTE,
    interval (1:1) HOUR(2) TO MINUTE,
    interval (1:1:1) HOUR TO SECOND,
    interval (1:1:1) HOUR(2) TO SECOND,
    interval (1:1:1.1) HOUR TO FRACTION,
    interval (1:1:1.1) HOUR(2) TO FRACTION,
    interval (1:1:1.1) HOUR TO FRACTION(2),
    interval (1:1:1.1)  HOUR(2) TO FRACTION(2),
    interval (1) MINUTE TO MINUTE,
    interval (1) MINUTE(2) TO MINUTE,
    interval (1:1) MINUTE TO SECOND,
    interval (1:1) MINUTE(2) TO SECOND,
    interval (1:1.1) MINUTE TO FRACTION,
    interval (1:1.1) MINUTE(2) TO FRACTION,
    interval (1:1.1) MINUTE(2) TO FRACTION(1),
    interval (1:1.1) MINUTE(2) TO FRACTION(1),
    interval (1) SECOND TO SECOND,
    interval (1) SECOND(2) TO SECOND,
    interval (1.1) SECOND TO FRACTION,
    interval (1.1) SECOND(2) TO FRACTION,
    interval (1.1) SECOND TO FRACTION(2),
    interval (1.1) SECOND(2) TO FRACTION(2)
    --interval (1) FRACTION TO FRACTION,
    --interval (1) FRACTION TO FRACTION(3)
  INTO r_.*
  FROM all_datatypes 
  WHERE keyColumn = 1
  DROP TABLE all_datatypes

  IF r_.doubleQuotedStr != 	"Double quoted"   THEN
    DISPLAY "Diferent value 1"
    LET exitStatus = 1
  END IF
  IF r_.singleQuotedStr != 	'Single quoted'  THEN
    DISPLAY "Diferent value 2"
    LET exitStatus = 1
  END IF
  --IF r_.-- Literal numbers != 	-- Literal numbers THEN
  IF r_.aNegativeInteger != 	-1  THEN
    DISPLAY "Diferent value 3"
    LET exitStatus = 1
  END IF
  IF r_.aPlusInteger != 	+1  THEN
    DISPLAY "Diferent value 4"
    LET exitStatus = 1
  END IF
  IF r_.anInteger != 	1  THEN
    DISPLAY "Diferent value 5"
    LET exitStatus = 1
  END IF
  IF r_.aPositiveFloat != 	+1.01  THEN
    DISPLAY "Diferent value 6"
    LET exitStatus = 1
  END IF
  IF r_.aNegativeSmallfloat != 	-1.01  THEN
    DISPLAY "Diferent value 7 ",r_.aNegativeSmallfloat using "--&.&&&&&"," != -1.01"
    LET exitStatus = 1
  END IF
  IF r_.aDecimal != 	1.01  THEN
    DISPLAY "Diferent value 8"
    LET exitStatus = 1
  END IF
  IF r_.aNegNumExpThree != 	-1E+3  THEN
    DISPLAY "Diferent value 9"
    LET exitStatus = 1
  END IF
  IF r_.aNegFltExpNegThree != 	-1E-3  THEN
    DISPLAY "Diferent value 10"
    LET exitStatus = 1
  END IF
  IF r_.aNegSmftExpThree != 	-1E3  THEN
    DISPLAY "Diferent value 11"
    LET exitStatus = 1
  END IF
  IF r_.aFltExpThree != 	+1E+3  THEN
    DISPLAY "Diferent value 12"
    LET exitStatus = 1
  END IF
  IF r_.aSmftExpNegThree != 	+1E-3  THEN
    DISPLAY "Diferent value 13 ",r_.aSmftExpNegThree using "--&.&&&&&", " != 1E-3"
    LET exitStatus = 1
  END IF
  IF r_.aNumExpThree != 	+1E3  THEN
    DISPLAY "Diferent value 14"
    LET exitStatus = 1
  END IF
  IF r_.aNumExpPlusThree != 	1E+3  THEN
    DISPLAY "Diferent value 15"
    LET exitStatus = 1
  END IF
  IF r_.aFltExpNegThree != 	1E-3  THEN
    DISPLAY "Diferent value 16"
    LET exitStatus = 1
  END IF
  IF r_.aFloatExpThree != 	1E3 THEN
    DISPLAY "Diferent value 17"
    LET exitStatus = 1
  END IF
  IF r_.aNegFloatExpThree != 	-1.01E+3  THEN
    DISPLAY "Diferent value 18"
    LET exitStatus = 1
  END IF
  IF r_.aNegDecExpNegThree != 	-1.01E-3  THEN
    DISPLAY "Diferent value 19 ",r_.aNegDecExpNegThree using "--&.&&&&&"," != -1.01E-3"
    LET exitStatus = 1
  END IF
  IF r_.aNegFltExpThree != 	-1.01E3  THEN
    DISPLAY "Diferent value 20a"
    LET exitStatus = 1
  END IF
  IF r_.aPlusNumExpPlusThree != 	+1.01E+3  THEN
    DISPLAY "Diferent value 20b"
    LET exitStatus = 1
  END IF
  IF r_.aPlusDecExpNegThree != 	+1.01E-3  THEN
    DISPLAY "Diferent value 21"
    LET exitStatus = 1
  END IF
  IF r_.aPlusDecExpThree != 	+1.01E3  THEN
    DISPLAY "Diferent value 22"
    LET exitStatus = 1
  END IF
  IF r_.aDecExpThree != 	1.01E+3  THEN
    DISPLAY "Diferent value 23"
    LET exitStatus = 1
  END IF
  IF r_.aDecExpNegThree != 	1.01E-3  THEN
    DISPLAY "Diferent value 24"
    LET exitStatus = 1
  END IF
  IF r_.aDecExpPlusThree != 	1.01E3 THEN
    DISPLAY "Diferent value 25"
    LET exitStatus = 1
  END IF
  --IF r_.  # Datetimes != 	# Datetimes THEN
  IF r_.aDate != 	TODAY THEN
    DISPLAY "Diferent value 26"
    LET exitStatus = 1
  END IF
  --IF r_.-- Current(s) != 	-- Combination of possible currents THEN
  IF r_.currYearYear != 	CURRENT YEAR TO YEAR  THEN
    DISPLAY "Diferent value 27"
    LET exitStatus = 1
  END IF
  IF r_.currYearMonth != 	CURRENT YEAR TO MONTH  THEN
    DISPLAY "Diferent value 28"
    LET exitStatus = 1
  END IF
  IF r_.currYearDay != 	CURRENT YEAR TO DAY THEN
    DISPLAY "Diferent value 29"
    LET exitStatus = 1
  END IF
  IF r_.currYearHour != 	CURRENT YEAR TO HOUR  THEN
    DISPLAY "Diferent value 30"
    LET exitStatus = 1
  END IF
  IF r_.currYearMinute != 	CURRENT YEAR TO MINUTE  THEN
    DISPLAY "Diferent value 31"
    LET exitStatus = 1
  END IF
  IF r_.currYearSecond != 	CURRENT YEAR TO SECOND THEN
    DISPLAY "Diferent value 32 : ",r_.currYearSecond," ",CURRENT YEAR TO SECOND
    LET exitStatus = 1
  END IF
  IF r_.currMonthMonth != 	CURRENT MONTH TO MONTH  THEN
    DISPLAY "Diferent value 34"
    LET exitStatus = 1
  END IF
  IF r_.currMonthDay != 	CURRENT MONTH TO DAY  THEN
    DISPLAY "Diferent value 35"
    LET exitStatus = 1
  END IF
  IF r_.currMonthHour != 	CURRENT MONTH TO HOUR  THEN
    DISPLAY "Diferent value 36"
    LET exitStatus = 1
  END IF
  IF r_.currMonthMinute != 	CURRENT MONTH TO MINUTE  THEN
    DISPLAY "Diferent value 37"
    LET exitStatus = 1
  END IF

  IF r_.currMonthSecond != 	CURRENT MONTH TO SECOND THEN
    DISPLAY "Diferent value 38 ", r_.currMonthSecond," ",CURRENT MONTH TO SECOND
    LET exitStatus = 1
  END IF
  IF r_.currDayDay != 	CURRENT DAY TO DAY  THEN
    DISPLAY "Diferent value 40"
    LET exitStatus = 1
  END IF
  IF r_.currDayHour != 	CURRENT DAY TO HOUR  THEN
    DISPLAY "Diferent value 41"
    LET exitStatus = 1
  END IF
  IF r_.currDayMinute != 	CURRENT DAY TO MINUTE  THEN
    DISPLAY "Diferent value 42"
    LET exitStatus = 1
  END IF
  IF r_.currDaySecond != 	CURRENT DAY TO SECOND THEN
    DISPLAY "Diferent value 43"
    LET exitStatus = 1
  END IF
  IF r_.currHourHour != 	CURRENT HOUR TO HOUR  THEN
    DISPLAY "Diferent value 45"
    LET exitStatus = 1
  END IF
  IF r_.currHourMinute != 	CURRENT HOUR TO MINUTE  THEN
    DISPLAY "Diferent value 46"
    LET exitStatus = 1
  END IF
  IF r_.currHourSecond != 	CURRENT HOUR TO SECOND THEN
    DISPLAY "Diferent value 47"
    LET exitStatus = 1
  END IF
  IF r_.currMinuteMinute != 	CURRENT MINUTE TO MINUTE  THEN
    DISPLAY "Diferent value 49"
    LET exitStatus = 1
  END IF
  IF r_.currMinuteSecond != 	CURRENT MINUTE TO SECOND THEN
    DISPLAY "Diferent value 50"
    LET exitStatus = 1
  END IF
  IF r_.currSecondSecond != 	CURRENT SECOND TO SECOND  THEN
    DISPLAY "Diferent value 52"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeYY != 	datetime(1999) YEAR TO YEAR THEN
    DISPLAY "Diferent value 54"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeYM != 	datetime(1999-12) YEAR TO MONTH THEN
    DISPLAY "Diferent value 55"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeYD != 	datetime(1999-12-31) YEAR TO DAY THEN
    DISPLAY "Diferent value 56"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeYH != 	datetime(1999-12-31 23) YEAR TO HOUR THEN
    DISPLAY "Diferent value 57x"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeYMin != 	datetime(1999-12-31 23:59) YEAR TO MINUTE THEN
    DISPLAY "Diferent value 58"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeYS != 	datetime(1999-12-31 23:59:59) YEAR TO SECOND THEN
    DISPLAY "Diferent value 59"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeYF != 	datetime(1999-12-31 23:59:59.999) YEAR TO FRACTION THEN
    DISPLAY "Diferent value 60"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeYFScale != 	datetime(1999-12-31 23:59:59.99) YEAR TO FRACTION(2) THEN
    DISPLAY "Diferent value 61"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeMM != 	datetime(12) MONTH TO MONTH THEN
    DISPLAY "Diferent value 62"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeMD != 	datetime(12-31) MONTH TO DAY THEN
    DISPLAY "Diferent value 63"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeMH != 	datetime(12-31 23) MONTH TO HOUR THEN
    DISPLAY "Diferent value 64"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeMMin != 	datetime(12-31 23:59) MONTH TO MINUTE THEN
    DISPLAY "Diferent value 65"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeMS != 	datetime(12-31 23:59:59) MONTH TO SECOND THEN
    DISPLAY "Diferent value 66"
    LET exitStatus = 1
  END IF
  --IF r_.--aDateTimeMF != 	--datetime(12-31 23:59:59.9999) MONTH TO FRACTION THEN
  IF r_.aDateTimeMFScale != 	datetime(12-31 23:59:59.99) MONTH TO FRACTION(2) THEN
    DISPLAY "Diferent value 67"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeDD != 	datetime(31) DAY TO DAY THEN
    DISPLAY "Diferent value 68"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeDH != 	datetime(31 23) DAY TO HOUR THEN
    DISPLAY "Diferent value 69"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeDMin != 	datetime(31 23:59) DAY TO MINUTE THEN
    DISPLAY "Diferent value 70"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeDS != 	datetime(31 23:59:59) DAY TO SECOND THEN
    DISPLAY "Diferent value 61"
    LET exitStatus = 1
  END IF
  --IF r_.--aDateTimeDF != 	--datetime(31 23:59:59.9999) DAY TO FRACTION THEN
  IF r_.aDateTimeDFScale != 	datetime(31 23:59:59.99) DAY TO FRACTION(2) THEN
    DISPLAY "Diferent value 62"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeHH != 	datetime(23) HOUR TO HOUR THEN
    DISPLAY "Diferent value 63"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeHM != 	datetime(23:59) HOUR TO MINUTE THEN
    DISPLAY "Diferent value 64"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeHS != 	datetime(23:59:59) HOUR TO SECOND THEN
    DISPLAY "Diferent value 65"
    LET exitStatus = 1
  END IF
  --IF r_.--aDateTimeHF != 	--datetime(23:59:59.9999) HOUR TO FRACTION THEN
  IF r_.aDateTimeHFScale != 	datetime(23:59:59.99) HOUR TO FRACTION(2) THEN
    DISPLAY "Diferent value 66"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeMinMin != 	datetime(59) MINUTE TO MINUTE THEN
    DISPLAY "Diferent value 67"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeMinS != 	datetime(59:59) MINUTE TO SECOND THEN
    DISPLAY "Diferent value 68"
    LET exitStatus = 1
  END IF
  --IF r_.--aDateTimeMinF != 	--datetime(59:59.9999) MINUTE TO FRACTION THEN
  IF r_.aDateTimeMinFScale != 	datetime(59:59.99) MINUTE TO FRACTION(2) THEN
    DISPLAY "Diferent value 69"
    LET exitStatus = 1
  END IF
  IF r_.aDateTimeSS != 	datetime(59) SECOND TO SECOND THEN
    DISPLAY "Diferent value 70"
    LET exitStatus = 1
  END IF
  --IF r_.--aDateTimeSF != 	--datetime(59.9999) SECOND TO FRACTION THEN
  IF r_.aDateTimeSFScale != 	datetime(59.99) SECOND TO FRACTION(2) THEN
    DISPLAY "Diferent value 71"
    LET exitStatus = 1
  END IF
  --IF r_.--aDateTimeFF != 	--datetime(9999) FRACTION TO FRACTION THEN
  --IF r_.--aDateTimeFFScale != 	--datetime(99) FRACTION TO FRACTION(2) THEN
  # Interval(s) != 	# Literal Interval(s) = THEN
  IF r_.aIntervalYY != 	INTERVAL(1) YEAR TO YEAR THEN
    DISPLAY "Diferent value 72 1 year to year : ",r_.aIntervalYY
    LET exitStatus = 1
  END IF
  IF r_.aIntervalYPrecY != 	INTERVAL(1) YEAR(4) TO YEAR THEN
    DISPLAY "Diferent value 73"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalYM != 	INTERVAL(1-1) YEAR TO MONTH THEN
    DISPLAY "Diferent value 74"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalYPrecM != 	INTERVAL (1-1) YEAR(4) TO MONTH THEN
    DISPLAY "Diferent value 75"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalMM != 	INTERVAL (1) MONTH TO MONTH THEN
    DISPLAY "Diferent value 76"
    LET exitStatus = 1
  END IF
  --IF r_.--aIntervalMPrecM != 	--interval (1) MONTH(2) TO MONTH THEN
  IF r_.aIntervalDD != 	interval (1) DAY TO DAY THEN
    DISPLAY "Diferent value 77"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDPrecD != 	interval (1) DAY(2) TO DAY THEN
    DISPLAY "Diferent value 78"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDH != 	interval (1 1) DAY TO HOUR THEN
    DISPLAY "Diferent value 79"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDPrecH != 	interval (1 1) DAY(2) TO HOUR THEN
    DISPLAY "Diferent value 80"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDMin != 	interval (1 1:1) DAY TO MINUTE THEN
    DISPLAY "Diferent value 81"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDPrecMin != 	interval (1 1:1) DAY(2) TO MINUTE THEN
    DISPLAY "Diferent value 82"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDS != 	interval (1 1:1:1) DAY TO SECOND THEN
    DISPLAY "Diferent value 83"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDPrecS != 	interval (1 1:1:1) DAY(2) TO SECOND THEN
    DISPLAY "Diferent value 84"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDF != 	interval (1 1:1:1.1) DAY TO FRACTION THEN
    DISPLAY "Diferent value 85"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDPrecF != 	interval (1 1:1:1.1) DAY(2) TO FRACTION THEN
    DISPLAY "Diferent value 86"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDFScale != 	interval (1 1:1:1.1) DAY TO FRACTION(2) THEN
    DISPLAY "Diferent value 87"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalDPrecFScale != 	interval (1 1:1:1.1) DAY(2) TO FRACTION(2) THEN
    DISPLAY "Diferent value 88"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalHH != 	interval (1) HOUR TO HOUR THEN
    DISPLAY "Diferent value 89"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalHPrecH != 	interval (1) HOUR(2) TO HOUR THEN
    DISPLAY "Diferent value 90"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalHM != 	interval (1:1) HOUR TO MINUTE THEN
    DISPLAY "Diferent value 91"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalHPrecM != 	interval (1:1) HOUR(2) TO MINUTE THEN
    DISPLAY "Diferent value 92"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalHS != 	interval (1:1:1) HOUR TO SECOND THEN
    DISPLAY "Diferent value 93"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalHPrecS != 	interval (1:1:1) HOUR(2) TO SECOND THEN
    DISPLAY "Diferent value 94"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalHF != 	interval (1:1:1.1) HOUR TO FRACTION THEN
    DISPLAY "Diferent value 95"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalHPrecF != 	interval (1:1:1.1) HOUR(2) TO FRACTION THEN
    DISPLAY "Diferent value 96"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalHFScale != 	interval (1:1:1.1) HOUR TO FRACTION(2) THEN
    DISPLAY "Diferent value 97"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalHPFS != 	interval (1:1:1.1)  HOUR(2) TO FRACTION(2) THEN
    DISPLAY "Diferent value 98"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalMinMin != 	interval (1) MINUTE TO MINUTE THEN
    DISPLAY "Diferent value 99"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalMinPrecMin != 	interval (1) MINUTE(2) TO MINUTE THEN
    DISPLAY "Diferent value 100"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalMinS != 	interval (1:1) MINUTE TO SECOND THEN
    DISPLAY "Diferent value 101"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalMinPrecS != 	interval (1:1) MINUTE(2) TO SECOND THEN
    DISPLAY "Diferent value 102"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalMinF != 	interval (1:1.1) MINUTE TO FRACTION THEN
    DISPLAY "Diferent value 103"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalMinPrecF != 	interval (1:1.1) MINUTE(2) TO FRACTION THEN
    DISPLAY "Diferent value 104"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalMinFScale != 	interval (1:1.1) MINUTE(2) TO FRACTION(1) THEN
    DISPLAY "Diferent value 105"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalMinPFS != 	interval (1:1.1) MINUTE(2) TO FRACTION(1) THEN
    DISPLAY "Diferent value 106"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalSS != 	interval (1) SECOND TO SECOND THEN
    DISPLAY "Diferent value 107"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalSPrecS != 	interval (1) SECOND(2) TO SECOND THEN
    DISPLAY "Diferent value 108"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalSF != 	interval (1.1) SECOND TO FRACTION THEN
    DISPLAY "Diferent value 109"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalSPrecF != 	interval (1.1) SECOND(2) TO FRACTION THEN
    DISPLAY "Diferent value 110"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalSFScale != 	interval (1.1) SECOND TO FRACTION(2) THEN
    DISPLAY "Diferent value 111"
    LET exitStatus = 1
  END IF
  IF r_.aIntervalSPFS != 	interval (1.1) SECOND(2) TO FRACTION(2) THEN
    DISPLAY "Diferent value 112"
    LET exitStatus = 1
  END IF
  --IF r_.aIntervalFF != 	--interval (1) FRACTION TO FRACTION THEN
  --IF r_.aIntervalFFScale != 	--interval (1) FRACTION TO FRACTION(3) THEN
  EXIT PROGRAM exitStatus
END MAIN
