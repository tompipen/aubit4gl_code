
MAIN
  DEFINE aInteger ARRAY[10] OF INTEGER
  DEFINE aInt ARRAY[10] OF INT
  DEFINE aSmallint ARRAY[10] OF SMALLINT
  DEFINE aDecimal ARRAY[10] OF DECIMAL
  DEFINE aDec ARRAY[10] OF DEC
  DEFINE aNumeric ARRAY[10] OF NUMERIC
  DEFINE aDecimalPrec ARRAY[10] OF DECIMAL(16)
  DEFINE aDecimalPrecScale ARRAY[10] OF DECIMAL(16,3)
  DEFINE aMoney ARRAY[10] OF MONEY
  DEFINE aMoneyPrecision ARRAY[10] OF MONEY(16)
  DEFINE aFloat ARRAY[10] OF FLOAT
  DEFINE aFloatWithPrecision ARRAY[10] OF FLOAT(8)
  DEFINE aDouble ARRAY[10] OF DOUBLE PRECISION
  DEFINE aSmallFloat ARRAY[10] OF SMALLFLOAT
  DEFINE aReal ARRAY[10] OF REAL
  DEFINE aDate ARRAY[10] OF DATE

	# Datetimes
  DEFINE aDateTimeYY ARRAY[10] OF DATETIME YEAR TO YEAR
  DEFINE aDateTimeYM ARRAY[10] OF DATETIME YEAR TO MONTH
  DEFINE aDateTimeYD ARRAY[10] OF DATETIME YEAR TO DAY
  DEFINE aDateTimeYH ARRAY[10] OF DATETIME YEAR TO HOUR
  DEFINE aDateTimeYMin ARRAY[10] OF DATETIME YEAR TO MINUTE
  DEFINE aDateTimeYS ARRAY[10] OF DATETIME YEAR TO SECOND
  DEFINE aDateTimeYF ARRAY[10] OF DATETIME YEAR TO FRACTION
  DEFINE aDateTimeYFScale ARRAY[10] OF DATETIME YEAR TO FRACTION(2)
  DEFINE aDateTimeMM ARRAY[10] OF DATETIME MONTH TO MONTH
  DEFINE aDateTimeMD ARRAY[10] OF DATETIME MONTH TO DAY
  DEFINE aDateTimeMH ARRAY[10] OF DATETIME MONTH TO HOUR
  DEFINE aDateTimeMMin ARRAY[10] OF DATETIME MONTH TO MINUTE
  DEFINE aDateTimeMS ARRAY[10] OF DATETIME MONTH TO SECOND
  DEFINE aDateTimeMF ARRAY[10] OF DATETIME MONTH TO FRACTION
  DEFINE aDateTimeMFScale ARRAY[10] OF DATETIME MONTH TO FRACTION(1)
  DEFINE aDateTimeDD ARRAY[10] OF DATETIME DAY TO DAY
  DEFINE aDateTimeDH ARRAY[10] OF DATETIME DAY TO HOUR
  DEFINE aDateTimeDMin ARRAY[10] OF DATETIME DAY TO MINUTE
  DEFINE aDateTimeDS ARRAY[10] OF DATETIME DAY TO SECOND
  DEFINE aDateTimeDF ARRAY[10] OF DATETIME DAY TO FRACTION
  DEFINE aDateTimeDFScale ARRAY[10] OF DATETIME DAY TO FRACTION(2)
  DEFINE aDateTimeHH ARRAY[10] OF DATETIME HOUR TO HOUR
  DEFINE aDateTimeHM ARRAY[10] OF DATETIME HOUR TO MINUTE
  DEFINE aDateTimeHS ARRAY[10] OF DATETIME HOUR TO SECOND
  DEFINE aDateTimeHF ARRAY[10] OF DATETIME HOUR TO FRACTION
  DEFINE aDateTimeHFScale ARRAY[10] OF DATETIME HOUR TO FRACTION(2)
  DEFINE aDateTimeMinMin ARRAY[10] OF DATETIME MINUTE TO MINUTE
  DEFINE aDateTimeMinS ARRAY[10] OF DATETIME MINUTE TO SECOND
  DEFINE aDateTimeMinF ARRAY[10] OF DATETIME MINUTE TO FRACTION
  DEFINE aDateTimeMinFScale ARRAY[10] OF DATETIME MINUTE TO FRACTION(1)
  DEFINE aDateTimeSS ARRAY[10] OF DATETIME SECOND TO SECOND
  DEFINE aDateTimeSF ARRAY[10] OF DATETIME SECOND TO FRACTION
  DEFINE aDateTimeSFScale ARRAY[10] OF DATETIME SECOND TO FRACTION(2)
  DEFINE aDateTimeFF ARRAY[10] OF DATETIME FRACTION TO FRACTION
  DEFINE aDateTimeFFScale ARRAY[10] OF DATETIME FRACTION TO FRACTION(3)

	# Interval(s)
  DEFINE aIntervalYY ARRAY[10] OF INTERVAL YEAR TO YEAR
  DEFINE aIntervalYPrecY ARRAY[10] OF INTERVAL YEAR (4) TO YEAR
  DEFINE aIntervalYM ARRAY[10] OF INTERVAL YEAR TO MONTH
  DEFINE aIntervalYPrecM ARRAY[10] OF INTERVAL YEAR (4) TO MONTH
  DEFINE aIntervalMM ARRAY[10] OF INTERVAL MONTH TO MONTH
  DEFINE aIntervalMPrecM ARRAY[10] OF INTERVAL MONTH(2) TO MONTH
  DEFINE aIntervalDD ARRAY[10] OF INTERVAL DAY TO DAY
  DEFINE aIntervalDPrecD ARRAY[10] OF INTERVAL DAY (2) TO DAY
  DEFINE aIntervalDH ARRAY[10] OF INTERVAL DAY TO HOUR
  DEFINE aIntervalDPrecH ARRAY[10] OF INTERVAL DAY (2) TO HOUR
  DEFINE aIntervalDMin ARRAY[10] OF INTERVAL DAY TO MINUTE
  DEFINE aIntervalDPrecMin ARRAY[10] OF INTERVAL DAY (2) TO MINUTE
  DEFINE aIntervalDS ARRAY[10] OF INTERVAL DAY TO SECOND
  DEFINE aIntervalDPrecS ARRAY[10] OF INTERVAL DAY (2) TO SECOND
  DEFINE aIntervalDF ARRAY[10] OF INTERVAL DAY TO FRACTION
  DEFINE aIntervalDPrecF ARRAY[10] OF INTERVAL DAY (2) TO FRACTION
  DEFINE aIntervalDFScale ARRAY[10] OF INTERVAL DAY TO FRACTION(2)
  DEFINE aIntervalDPrecFScale ARRAY[10] OF INTERVAL DAY (2) TO FRACTION(2)
  DEFINE aIntervalHH ARRAY[10] OF INTERVAL HOUR TO HOUR
  DEFINE aIntervalHPrecH ARRAY[10] OF INTERVAL HOUR (2) TO HOUR
  DEFINE aIntervalHM ARRAY[10] OF INTERVAL HOUR TO MINUTE
  DEFINE aIntervalHPrecM ARRAY[10] OF INTERVAL HOUR (2) TO MINUTE
  DEFINE aIntervalHS ARRAY[10] OF INTERVAL HOUR TO SECOND
  DEFINE aIntervalHPrecS ARRAY[10] OF INTERVAL HOUR (2) TO SECOND
  DEFINE aIntervalHF ARRAY[10] OF INTERVAL HOUR TO FRACTION
  DEFINE aIntervalHPrecF ARRAY[10] OF INTERVAL HOUR (2) TO FRACTION
  DEFINE aIntervalHFScale ARRAY[10] OF INTERVAL HOUR TO FRACTION(2)
  DEFINE aIntervalHPrecFScale ARRAY[10] OF INTERVAL HOUR (2) TO FRACTION(2)
  DEFINE aIntervalMinMin ARRAY[10] OF INTERVAL MINUTE TO MINUTE
  DEFINE aIntervalMinPrecMin ARRAY[10] OF INTERVAL MINUTE (2) TO MINUTE
  DEFINE aIntervalMinS ARRAY[10] OF INTERVAL MINUTE TO SECOND
  DEFINE aIntervalMinPrecS ARRAY[10] OF INTERVAL MINUTE (2) TO SECOND
  DEFINE aIntervalMinF ARRAY[10] OF INTERVAL MINUTE TO FRACTION
  DEFINE aIntervalMinPrecF ARRAY[10] OF INTERVAL MINUTE (2) TO FRACTION
  DEFINE aIntervalMinFScale ARRAY[10] OF INTERVAL MINUTE (2) TO FRACTION(1)
  DEFINE aIntervalMinPrecFScale ARRAY[10] OF INTERVAL MINUTE (2) TO FRACTION(1)
  DEFINE aIntervalSS ARRAY[10] OF INTERVAL SECOND TO SECOND
  DEFINE aIntervalSPrecS ARRAY[10] OF INTERVAL SECOND (2) TO SECOND
  DEFINE aIntervalSF ARRAY[10] OF INTERVAL SECOND TO FRACTION
  DEFINE aIntervalSPrecF ARRAY[10] OF INTERVAL SECOND (2) TO FRACTION
  DEFINE aIntervalSFScale ARRAY[10] OF INTERVAL SECOND TO FRACTION(2)
  DEFINE aIntervalSPrecFScale ARRAY[10] OF INTERVAL SECOND (2) TO FRACTION(2)
  DEFINE aIntervalFF ARRAY[10] OF INTERVAL FRACTION TO FRACTION
  DEFINE aIntervalFFScale ARRAY[10] OF INTERVAL FRACTION TO FRACTION(3)
	
	#
	DEFINE aCharacter CHARACTER
	DEFINE aCharacterWithSize CHARACTER(30)
	DEFINE aChar CHAR
	DEFINE aCharWithSize CHARACTER(20)
	DEFINE aVarchar VARCHAR(20)
	DEFINE aVarcharWithReserve VARCHAR(20,10)
END MAIN
