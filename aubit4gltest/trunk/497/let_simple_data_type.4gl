
MAIN
  DEFINE aInteger INTEGER
  DEFINE aInt INT
  DEFINE aSmallint SMALLINT
  DEFINE aDecimal DECIMAL
  DEFINE aDec DEC
  DEFINE aNumeric NUMERIC
  DEFINE aDecimalPrec DECIMAL(16)
  DEFINE aDecimalPrecScale DECIMAL(16,3)
  DEFINE aMoney MONEY
  DEFINE aMoneyPrecision MONEY(16)
  DEFINE aFloat FLOAT
  DEFINE aFloatWithPrecision FLOAT(8)
  DEFINE aDouble DOUBLE PRECISION
  DEFINE aSmallFloat SMALLFLOAT
  DEFINE aReal REAL
  DEFINE aDate Date

	# Datetimes
  DEFINE aDateTimeYY DATETIME YEAR TO YEAR
  DEFINE aDateTimeYM DATETIME YEAR TO MONTH
  DEFINE aDateTimeYD DATETIME YEAR TO DAY
  DEFINE aDateTimeYH DATETIME YEAR TO HOUR
  DEFINE aDateTimeYMin DATETIME YEAR TO MINUTE
  DEFINE aDateTimeYS DATETIME YEAR TO SECOND
  DEFINE aDateTimeYF DATETIME YEAR TO FRACTION
  DEFINE aDateTimeYFScale DATETIME YEAR TO FRACTION(2)
  DEFINE aDateTimeMM DATETIME MONTH TO MONTH
  DEFINE aDateTimeMD DATETIME MONTH TO DAY
  DEFINE aDateTimeMH DATETIME MONTH TO HOUR
  DEFINE aDateTimeMMin DATETIME MONTH TO MINUTE
  DEFINE aDateTimeMS DATETIME MONTH TO SECOND
  DEFINE aDateTimeMF DATETIME MONTH TO FRACTION
  DEFINE aDateTimeMFScale DATETIME MONTH TO FRACTION(1)
  DEFINE aDateTimeDD DATETIME DAY TO DAY
  DEFINE aDateTimeDH DATETIME DAY TO HOUR
  DEFINE aDateTimeDMin DATETIME DAY TO MINUTE
  DEFINE aDateTimeDS DATETIME DAY TO SECOND
  DEFINE aDateTimeDF DATETIME DAY TO FRACTION
  DEFINE aDateTimeDFScale DATETIME DAY TO FRACTION(2)
  DEFINE aDateTimeHH DATETIME HOUR TO HOUR
  DEFINE aDateTimeHM DATETIME HOUR TO MINUTE
  DEFINE aDateTimeHS DATETIME HOUR TO SECOND
  DEFINE aDateTimeHF DATETIME HOUR TO FRACTION
  DEFINE aDateTimeHFScale DATETIME HOUR TO FRACTION(2)
  DEFINE aDateTimeMinMin DATETIME MINUTE TO MINUTE
  DEFINE aDateTimeMinS DATETIME MINUTE TO SECOND
  DEFINE aDateTimeMinF DATETIME MINUTE TO FRACTION
  DEFINE aDateTimeMinFScale DATETIME MINUTE TO FRACTION(1)
  DEFINE aDateTimeSS DATETIME SECOND TO SECOND
  DEFINE aDateTimeSF DATETIME SECOND TO FRACTION
  DEFINE aDateTimeSFScale DATETIME SECOND TO FRACTION(2)
  DEFINE aDateTimeFF DATETIME FRACTION TO FRACTION
  DEFINE aDateTimeFFScale DATETIME FRACTION TO FRACTION(3)

	# Interval(s)
  DEFINE aIntervalYY INTERVAL YEAR TO YEAR
  DEFINE aIntervalYPrecY INTERVAL YEAR (4) TO YEAR
  DEFINE aIntervalYM INTERVAL YEAR TO MONTH
  DEFINE aIntervalYPrecM INTERVAL YEAR (4) TO MONTH
  DEFINE aIntervalMM INTERVAL MONTH TO MONTH
  DEFINE aIntervalMPrecM INTERVAL MONTH(2) TO MONTH
  DEFINE aIntervalDD INTERVAL DAY TO DAY
  DEFINE aIntervalDPrecD INTERVAL DAY (2) TO DAY
  DEFINE aIntervalDH INTERVAL DAY TO HOUR
  DEFINE aIntervalDPrecH INTERVAL DAY (2) TO HOUR
  DEFINE aIntervalDMin INTERVAL DAY TO MINUTE
  DEFINE aIntervalDPrecMin INTERVAL DAY (2) TO MINUTE
  DEFINE aIntervalDS INTERVAL DAY TO SECOND
  DEFINE aIntervalDPrecS INTERVAL DAY (2) TO SECOND
  DEFINE aIntervalDF INTERVAL DAY TO FRACTION
  DEFINE aIntervalDPrecF INTERVAL DAY (2) TO FRACTION
  DEFINE aIntervalDFScale INTERVAL DAY TO FRACTION(2)
  DEFINE aIntervalDPrecFScale INTERVAL DAY (2) TO FRACTION(2)
  DEFINE aIntervalHH INTERVAL HOUR TO HOUR
  DEFINE aIntervalHPrecH INTERVAL HOUR (2) TO HOUR
  DEFINE aIntervalHM INTERVAL HOUR TO MINUTE
  DEFINE aIntervalHPrecM INTERVAL HOUR (2) TO MINUTE
  DEFINE aIntervalHS INTERVAL HOUR TO SECOND
  DEFINE aIntervalHPrecS INTERVAL HOUR (2) TO SECOND
  DEFINE aIntervalHF INTERVAL HOUR TO FRACTION
  DEFINE aIntervalHPrecF INTERVAL HOUR (2) TO FRACTION
  DEFINE aIntervalHFScale INTERVAL HOUR TO FRACTION(2)
  DEFINE aIntervalHPrecFScale INTERVAL HOUR (2) TO FRACTION(2)
  DEFINE aIntervalMinMin INTERVAL MINUTE TO MINUTE
  DEFINE aIntervalMinPrecMin INTERVAL MINUTE (2) TO MINUTE
  DEFINE aIntervalMinS INTERVAL MINUTE TO SECOND
  DEFINE aIntervalMinPrecS INTERVAL MINUTE (2) TO SECOND
  DEFINE aIntervalMinF INTERVAL MINUTE TO FRACTION
  DEFINE aIntervalMinPrecF INTERVAL MINUTE (2) TO FRACTION
  DEFINE aIntervalMinFScale INTERVAL MINUTE (2) TO FRACTION(1)
  DEFINE aIntervalMinPrecFScale INTERVAL MINUTE (2) TO FRACTION(1)
  DEFINE aIntervalSS INTERVAL SECOND TO SECOND
  DEFINE aIntervalSPrecS INTERVAL SECOND (2) TO SECOND
  DEFINE aIntervalSF INTERVAL SECOND TO FRACTION
  DEFINE aIntervalSPrecF INTERVAL SECOND (2) TO FRACTION
  DEFINE aIntervalSFScale INTERVAL SECOND TO FRACTION(2)
  DEFINE aIntervalSPrecFScale INTERVAL SECOND (2) TO FRACTION(2)
  DEFINE aIntervalFF INTERVAL FRACTION TO FRACTION
  DEFINE aIntervalFFScale INTERVAL FRACTION TO FRACTION(3)
	
	#
	DEFINE aCharacter CHARACTER
	DEFINE aCharacterWithSize CHARACTER(30)
	DEFINE aChar CHAR
	DEFINE aCharWithSize CHARACTER(20)
	DEFINE aVarchar VARCHAR(20)
	DEFINE aVarcharWithReserve VARCHAR(20,10)

	# Assignment(s)
  LET aInteger  = 20000000
  LET aInt  = -20000000
  LET aSmallint  = 32767
  LET aDecimal  = 123456789012345.0
  LET aDec  = 123456789012345.0
  LET aNumeric  = 123456789012345.0
  LET aDecimalPrec  = 123456789012345.0
  LET aDecimalPrecScale  = 1234567890123.45
  LET aMoney  = 123456789012345.0
  LET aMoneyPrecision  = 123456789012345.0
  LET aFloat  = 123456789012345.0
  LET aFloatWithPrecision  = 123456789012345.0
  LET aDouble  = 123456789012345.0
  LET aSmallFloat  = 123456789012345.0
  LET aReal  = 123456789012345.0
  LET aDate  = mdy(12,31,1999)
 
	# Datetimes =
  LET aDateTimeYY  = "1999"
  LET aDateTimeYM  = "1999-12"
  LET aDateTimeYD  = "1999-12-31"
  LET aDateTimeYH  = "1999-12-31 23"
  LET aDateTimeYMin  = "1999-12-31 23:59"
  LET aDateTimeYS  = "1999-12-31 23:59:59"
  LET aDateTimeYF  = "1999-12-31 23:59:59:999"
  LET aDateTimeYFScale  = "1999-12-31 23:59:59:99"
  LET aDateTimeMM  = "12"
  LET aDateTimeMD  = "12-31"
  LET aDateTimeMH  = "12-31 23"
  LET aDateTimeMMin  = "12-31 23:59"
  LET aDateTimeMS  = "12-31 23:59:59"
  LET aDateTimeMF  = "12-31 23:59:59:9999"
  LET aDateTimeMFScale  = "12-31 23:59:59:99"
  LET aDateTimeDD  = "31"
  LET aDateTimeDH  = "31 23"
  LET aDateTimeDMin  = "31 23:59"
  LET aDateTimeDS  = "31 23:59:59"
  LET aDateTimeDF  = "31 23:59:59:9999"
  LET aDateTimeDFScale  = "31 23:59:59:99"
  LET aDateTimeHH  = "23"
  LET aDateTimeHM  = "23:59"
  LET aDateTimeHS  = "23:59:59"
  LET aDateTimeHF  = "23:59:59:9999"
  LET aDateTimeHFScale  = "23:59:59:99"
  LET aDateTimeMinMin  = "59"
  LET aDateTimeMinS  = "59:59"
  LET aDateTimeMinF  = "59:59:9999"
  LET aDateTimeMinFScale  = "59:59:99"
  LET aDateTimeSS  = "59"
  LET aDateTimeSF  = "59:9999"
  LET aDateTimeSFScale  = "59:99"
  LET aDateTimeFF  = "9999"
  LET aDateTimeFFScale  = "99"
 
	# Interval(s) =
  LET aIntervalYY  = "1"
  LET aIntervalYY  = "-1"
  LET aIntervalYPrecY  = "1"
  LET aIntervalYM  = "1"
  LET aIntervalYPrecM  = "1"
  LET aIntervalMM  = "1"
  LET aIntervalMPrecM  = "1"
  LET aIntervalDD  = "1"
  LET aIntervalDPrecD  = "1"
  LET aIntervalDH  = "1 1"
  LET aIntervalDPrecH  = "1 1"
  LET aIntervalDMin  = "1 1:1"
  LET aIntervalDPrecMin  = "1 1:1"
  LET aIntervalDS  = "1 1:1:1"
  LET aIntervalDPrecS  = "1 1:1:1"
  LET aIntervalDF  = "1 1:1:1:1"
  LET aIntervalDPrecF  = "1 1:1:1:1"
  LET aIntervalDFScale  = "1 1:1:1:1"
  LET aIntervalDPrecFScale  = "1 1:1:1:1"
  LET aIntervalHH  = "1"
  LET aIntervalHPrecH  = "1"
  LET aIntervalHM  = "1:1"
  LET aIntervalHPrecM  = "1:1"
  LET aIntervalHS  = "1:1:1"
  LET aIntervalHPrecS  = "1:1:1"
  LET aIntervalHF  = "1:1:1:1"
  LET aIntervalHPrecF  = "1:1:1:1"
  LET aIntervalHFScale  = "1:1:1:1"
  LET aIntervalHPrecFScale  = "1:1:1:1"
  LET aIntervalMinMin  = "1"
  LET aIntervalMinPrecMin  = "1"
  LET aIntervalMinS  = "1:1"
  LET aIntervalMinPrecS  = "1:1"
  LET aIntervalMinF  = "1:1:1"
  LET aIntervalMinPrecF  = "1:1:1"
  LET aIntervalMinFScale  = "1:1:1"
  LET aIntervalMinPrecFScale  = "1:1:1"
  LET aIntervalSS  = "1"
  LET aIntervalSPrecS  = "1"
  LET aIntervalSF  = "1:1"
  LET aIntervalSPrecF  = "1:1"
  LET aIntervalSFScale  = "1:1"
  LET aIntervalSPrecFScale  = "1:1"
  LET aIntervalFF  = "1"
  LET aIntervalFFScale  = "1"

	# 
	LET aCharacter = "C"
	LET aCharacterWithSize = "Hello world"
	LET aChar = "C"
	LET aCharWithSize = "Hello world"
	LET aVarchar = "Hello world"
	LET aVarcharWithReserve = "Hello world"

	# Display(s)
  DISPLAY aInteger 
  DISPLAY aInt 
  DISPLAY aSmallint 
  DISPLAY aDecimal 
  DISPLAY aDec 
  DISPLAY aNumeric 
  DISPLAY aDecimalPrec 
  DISPLAY aDecimalPrecScale 
  DISPLAY aMoney 
  DISPLAY aMoneyPrecision 
  DISPLAY aFloat 
  DISPLAY aFloatWithPrecision 
  DISPLAY aDouble 
  DISPLAY aSmallFloat 
  DISPLAY aReal 
  DISPLAY aDate 

	# Datetimes
  DISPLAY aDateTimeYY 
  DISPLAY aDateTimeYM 
  DISPLAY aDateTimeYD 
  DISPLAY aDateTimeYH 
  DISPLAY aDateTimeYMin 
  DISPLAY aDateTimeYS 
  DISPLAY aDateTimeYF 
  DISPLAY aDateTimeYFScale 
  DISPLAY aDateTimeMM 
  DISPLAY aDateTimeMD 
  DISPLAY aDateTimeMH 
  DISPLAY aDateTimeMMin 
  DISPLAY aDateTimeMS 
  DISPLAY aDateTimeMF 
  DISPLAY aDateTimeMFScale 
  DISPLAY aDateTimeDD 
  DISPLAY aDateTimeDH 
  DISPLAY aDateTimeDMin 
  DISPLAY aDateTimeDS 
  DISPLAY aDateTimeDF 
  DISPLAY aDateTimeDFScale 
  DISPLAY aDateTimeHH 
  DISPLAY aDateTimeHM 
  DISPLAY aDateTimeHS 
  DISPLAY aDateTimeHF 
  DISPLAY aDateTimeHFScale 
  DISPLAY aDateTimeMinMin 
  DISPLAY aDateTimeMinS 
  DISPLAY aDateTimeMinF 
  DISPLAY aDateTimeMinFScale 
  DISPLAY aDateTimeSS 
  DISPLAY aDateTimeSF 
  DISPLAY aDateTimeSFScale 
  DISPLAY aDateTimeFF 
  DISPLAY aDateTimeFFScale 

	# Interval(s)
  DISPLAY aIntervalYY 
  DISPLAY aIntervalYPrecY 
  DISPLAY aIntervalYM 
  DISPLAY aIntervalYPrecM 
  DISPLAY aIntervalMM 
  DISPLAY aIntervalMPrecM 
  DISPLAY aIntervalDD 
  DISPLAY aIntervalDPrecD 
  DISPLAY aIntervalDH 
  DISPLAY aIntervalDPrecH 
  DISPLAY aIntervalDMin 
  DISPLAY aIntervalDPrecMin 
  DISPLAY aIntervalDS 
  DISPLAY aIntervalDPrecS 
  DISPLAY aIntervalDF 
  DISPLAY aIntervalDPrecF 
  DISPLAY aIntervalDFScale 
  DISPLAY aIntervalDPrecFScale 
  DISPLAY aIntervalHH 
  DISPLAY aIntervalHPrecH 
  DISPLAY aIntervalHM 
  DISPLAY aIntervalHPrecM 
  DISPLAY aIntervalHS 
  DISPLAY aIntervalHPrecS 
  DISPLAY aIntervalHF 
  DISPLAY aIntervalHPrecF 
  DISPLAY aIntervalHFScale 
  DISPLAY aIntervalHPrecFScale 
  DISPLAY aIntervalMinMin 
  DISPLAY aIntervalMinPrecMin 
  DISPLAY aIntervalMinS 
  DISPLAY aIntervalMinPrecS 
  DISPLAY aIntervalMinF 
  DISPLAY aIntervalMinPrecF 
  DISPLAY aIntervalMinFScale 
  DISPLAY aIntervalMinPrecFScale 
  DISPLAY aIntervalSS 
  DISPLAY aIntervalSPrecS 
  DISPLAY aIntervalSF 
  DISPLAY aIntervalSPrecF 
  DISPLAY aIntervalSFScale 
  DISPLAY aIntervalSPrecFScale 
  DISPLAY aIntervalFF 
  DISPLAY aIntervalFFScale 
	
	#
	DISPLAY aCharacter 
	DISPLAY aCharacterWithSize 
	DISPLAY aChar 
	DISPLAY aCharWithSize 
	DISPLAY aVarchar 
	DISPLAY aVarcharWithReserve 
END MAIN
