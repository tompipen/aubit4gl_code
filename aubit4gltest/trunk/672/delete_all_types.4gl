DATABASE test1

MAIN
	DEFINE r_ RECORD
     aInteger INTEGER,
     aInt INT,
     aSmallint SMALLINT,
     aDecimal DECIMAL,
     aDec DEC,
     aNumeric NUMERIC,
     aDecimalPrec DECIMAL(16),
     aDecimalPrecScale DECIMAL(16,3),
     aMoney MONEY,
     aMoneyPrecision MONEY(16),
     aMoneyPrecScale MONEY(16,3),
     aFloat FLOAT,
     aFloatWithPrecision FLOAT(8),
     aDouble DOUBLE PRECISION,
     aSmallFloat SMALLFLOAT,
     aReal REAL,
     aDate Date,

	   # Datetimes
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
     aDateTimeMF DATETIME MONTH TO FRACTION,
     aDateTimeMFScale DATETIME MONTH TO FRACTION(1),
     aDateTimeDD DATETIME DAY TO DAY,
     aDateTimeDH DATETIME DAY TO HOUR,
     aDateTimeDMin DATETIME DAY TO MINUTE,
     aDateTimeDS DATETIME DAY TO SECOND,
     aDateTimeDF DATETIME DAY TO FRACTION,
     aDateTimeDFScale DATETIME DAY TO FRACTION(2),
     aDateTimeHH DATETIME HOUR TO HOUR,
     aDateTimeHM DATETIME HOUR TO MINUTE,
     aDateTimeHS DATETIME HOUR TO SECOND,
     aDateTimeHF DATETIME HOUR TO FRACTION,
     aDateTimeHFScale DATETIME HOUR TO FRACTION(2),
     aDateTimeMinMin DATETIME MINUTE TO MINUTE,
     aDateTimeMinS DATETIME MINUTE TO SECOND,
     aDateTimeMinF DATETIME MINUTE TO FRACTION,
     aDateTimeMinFScale DATETIME MINUTE TO FRACTION(1),
     aDateTimeSS DATETIME SECOND TO SECOND,
     aDateTimeSF DATETIME SECOND TO FRACTION,
     aDateTimeSFScale DATETIME SECOND TO FRACTION(2),
     aDateTimeFF DATETIME FRACTION TO FRACTION,
     aDateTimeFFScale DATETIME FRACTION TO FRACTION(3),

	   # Interval(s)
     aIntervalYY INTERVAL YEAR TO YEAR,
     aIntervalYPrecY INTERVAL YEAR (4) TO YEAR,
     aIntervalYM INTERVAL YEAR TO MONTH,
     aIntervalYPrecM INTERVAL YEAR (4) TO MONTH,
     aIntervalMM INTERVAL MONTH TO MONTH,
     aIntervalMPrecM INTERVAL MONTH(2) TO MONTH,
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
     aIntervalHPrecFScale INTERVAL HOUR (2) TO FRACTION(2),
     aIntervalMinMin INTERVAL MINUTE TO MINUTE,
     aIntervalMinPrecMin INTERVAL MINUTE (2) TO MINUTE,
     aIntervalMinS INTERVAL MINUTE TO SECOND,
     aIntervalMinPrecS INTERVAL MINUTE (2) TO SECOND,
     aIntervalMinF INTERVAL MINUTE TO FRACTION,
     aIntervalMinPrecF INTERVAL MINUTE (2) TO FRACTION,
     aIntervalMinFScale INTERVAL MINUTE (2) TO FRACTION(1),
     aIntervalMinPrecFScale INTERVAL MINUTE (2) TO FRACTION(1),
     aIntervalSS INTERVAL SECOND TO SECOND,
     aIntervalSPrecS INTERVAL SECOND (2) TO SECOND,
     aIntervalSF INTERVAL SECOND TO FRACTION,
     aIntervalSPrecF INTERVAL SECOND (2) TO FRACTION,
     aIntervalSFScale INTERVAL SECOND TO FRACTION(2),
     aIntervalSPrecFScale INTERVAL SECOND (2) TO FRACTION(2),
     aIntervalFF INTERVAL FRACTION TO FRACTION,
     aIntervalFFScale INTERVAL FRACTION TO FRACTION(3),
	
	   # CHARS
	   aCharacter CHARACTER,
	   aCharacterWithSize CHARACTER(20),
	   aNChar NCHAR,
	   aChar CHAR,
	   aCharWithSize CHARACTER(20),
	   aNCharWithSize NCHAR(10),
	   aVarchar VARCHAR(20),
	   aNVarchar NVARCHAR(20),
	   aVarcharWithReserve VARCHAR(20,10),
	   aNVarcharWithRes NVARCHAR(20,10)
	END RECORD

  WHENEVER ERROR CONTINUE
	DROP TABLE all_datatypes
	DROP TABLE table_with_ser
  WHENEVER ERROR STOP
  CREATE TABLE all_datatypes (
     aInteger INTEGER,
     aInt INT,
     aSmallint SMALLINT,
     aDecimal DECIMAL,
     aDec DEC,
     aNumeric NUMERIC,
     aDecimalPrec DECIMAL(16),
     aDecimalPrecScal DECIMAL(16,3),
     aMoney MONEY,
     aMoneyPrecision MONEY(16),
     aMoneyPrecScale MONEY(16,3),
     aFloat FLOAT,
     aFloatWithPrec FLOAT(8),
     aDouble DOUBLE PRECISION,
     aSmallFloat SMALLFLOAT,
     aReal REAL,
     aDate Date,

	   # Datetimes
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
     aDateTimeMF DATETIME MONTH TO FRACTION,
     aDateTimeMFScale DATETIME MONTH TO FRACTION(1),
     aDateTimeDD DATETIME DAY TO DAY,
     aDateTimeDH DATETIME DAY TO HOUR,
     aDateTimeDMin DATETIME DAY TO MINUTE,
     aDateTimeDS DATETIME DAY TO SECOND,
     aDateTimeDF DATETIME DAY TO FRACTION,
     aDateTimeDFScale DATETIME DAY TO FRACTION(2),
     aDateTimeHH DATETIME HOUR TO HOUR,
     aDateTimeHM DATETIME HOUR TO MINUTE,
     aDateTimeHS DATETIME HOUR TO SECOND,
     aDateTimeHF DATETIME HOUR TO FRACTION,
     aDateTimeHFScale DATETIME HOUR TO FRACTION(2),
     aDateTimeMinMin DATETIME MINUTE TO MINUTE,
     aDateTimeMinS DATETIME MINUTE TO SECOND,
     aDateTimeMinF DATETIME MINUTE TO FRACTION,
     aDateTimeMinFSca DATETIME MINUTE TO FRACTION(1),
     aDateTimeSS DATETIME SECOND TO SECOND,
     aDateTimeSF DATETIME SECOND TO FRACTION,
     aDateTimeSFScale DATETIME SECOND TO FRACTION(2),
     aDateTimeFF DATETIME FRACTION TO FRACTION,
     aDateTimeFFScale DATETIME FRACTION TO FRACTION(3),

	   # Interval(s)
     aIntervalYY INTERVAL YEAR TO YEAR,
     aIntervalYPrecY INTERVAL YEAR (4) TO YEAR,
     aIntervalYM INTERVAL YEAR TO MONTH,
     aIntervalYPrecM INTERVAL YEAR (4) TO MONTH,
     aIntervalMM INTERVAL MONTH TO MONTH,
     aIntervalMPrecM INTERVAL MONTH(2) TO MONTH,
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
     aIntervalDPrecFS INTERVAL DAY (2) TO FRACTION(2),
     aIntervalHH INTERVAL HOUR TO HOUR,
     aIntervalHPrecH INTERVAL HOUR (2) TO HOUR,
     aIntervalHM INTERVAL HOUR TO MINUTE,
     aIntervalHPrecM INTERVAL HOUR (2) TO MINUTE,
     aIntervalHS INTERVAL HOUR TO SECOND,
     aIntervalHPrecS INTERVAL HOUR (2) TO SECOND,
     aIntervalHF INTERVAL HOUR TO FRACTION,
     aIntervalHPrecF INTERVAL HOUR (2) TO FRACTION,
     aIntervalHFScale INTERVAL HOUR TO FRACTION(2),
     aIntervalHPrecFS INTERVAL HOUR (2) TO FRACTION(2),
     aIntervalMinMin INTERVAL MINUTE TO MINUTE,
     aIntervalMinPreM INTERVAL MINUTE (2) TO MINUTE,
     aIntervalMinS INTERVAL MINUTE TO SECOND,
     aIntervalMinPrecS INTERVAL MINUTE (2) TO SECOND,
     aIntervalMinF INTERVAL MINUTE TO FRACTION,
     aIntervalMinPrecF INTERVAL MINUTE (2) TO FRACTION,
     aIntervalMinFSce INTERVAL MINUTE (2) TO FRACTION(1),
     aIntervalMinPrFS INTERVAL MINUTE (2) TO FRACTION(1),
     aIntervalSS INTERVAL SECOND TO SECOND,
     aIntervalSPrecS INTERVAL SECOND (2) TO SECOND,
     aIntervalSF INTERVAL SECOND TO FRACTION,
     aIntervalSPrecF INTERVAL SECOND (2) TO FRACTION,
     aIntervalSFScale INTERVAL SECOND TO FRACTION(2),
     aIntervalSPrecFS INTERVAL SECOND (2) TO FRACTION(2),
     aIntervalFF INTERVAL FRACTION TO FRACTION,
     aIntervalFFScale INTERVAL FRACTION TO FRACTION(3),
	   aCharacter CHARACTER,
	   aCharacterWithSz CHARACTER(30),
	   aChar CHAR,
	   aCharWithSize CHARACTER(20),
	   aNChar NCHAR,
	   aNCharWithSize NCHAR(10),
	   aVarchar VARCHAR(20),
	   aVarcharWithRes VARCHAR(20,10),
	   aNVarchar NVARCHAR(20),
	   aNVarcharWithRes NVARCHAR(20,10)
	)
	CREATE TABLE table_with_ser (
		 aSerialWithStart SERIAL(20)
	)

	# Assignment(s)
  LET r_.aInteger  = 20000000
  LET r_.aInt  = -20000000
  LET r_.aSmallint  = 32767
  LET r_.aDecimal  = 123456789012345.0
  LET r_.aDec  = 123456789012345.0
  LET r_.aNumeric  = 123456789012345.0
  LET r_.aDecimalPrec  = 123456789012345.0
  LET r_.aDecimalPrecScale  = 1234567890123.45
  LET r_.aMoney  = 123456789012345.0
  LET r_.aMoneyPrecision  = 123456789012345.0
  LET r_.aFloat  = 123456789012345.0
  LET r_.aFloatWithPrecision  = 123456789012345.0
  LET r_.aDouble  = 123456789012345.0
  LET r_.aSmallFloat  = 123456789012345.0
  LET r_.aReal  = 123456789012345.0
  LET r_.aDate  = mdy(12,31,1999)
 
	# Datetimes =
  LET r_.aDateTimeYY  = "1999"
  LET r_.aDateTimeYM  = "1999-12"
  LET r_.aDateTimeYD  = "1999-12-31"
  LET r_.aDateTimeYH  = "1999-12-31 23"
  LET r_.aDateTimeYMin  = "1999-12-31 23:59"
  LET r_.aDateTimeYS  = "1999-12-31 23:59:59"
  LET r_.aDateTimeYF  = "1999-12-31 23:59:59:999"
  LET r_.aDateTimeYFScale  = "1999-12-31 23:59:59:99"
  LET r_.aDateTimeMM  = "12"
  LET r_.aDateTimeMD  = "12-31"
  LET r_.aDateTimeMH  = "12-31 23"
  LET r_.aDateTimeMMin  = "12-31 23:59"
  LET r_.aDateTimeMS  = "12-31 23:59:59"
  LET r_.aDateTimeMF  = "12-31 23:59:59:9999"
  LET r_.aDateTimeMFScale  = "12-31 23:59:59:99"
  LET r_.aDateTimeDD  = "31"
  LET r_.aDateTimeDH  = "31 23"
  LET r_.aDateTimeDMin  = "31 23:59"
  LET r_.aDateTimeDS  = "31 23:59:59"
  LET r_.aDateTimeDF  = "31 23:59:59:9999"
  LET r_.aDateTimeDFScale  = "31 23:59:59:99"
  LET r_.aDateTimeHH  = "23"
  LET r_.aDateTimeHM  = "23:59"
  LET r_.aDateTimeHS  = "23:59:59"
  LET r_.aDateTimeHF  = "23:59:59:9999"
  LET r_.aDateTimeHFScale  = "23:59:59:99"
  LET r_.aDateTimeMinMin  = "59"
  LET r_.aDateTimeMinS  = "59:59"
  LET r_.aDateTimeMinF  = "59:59:9999"
  LET r_.aDateTimeMinFScale  = "59:59:99"
  LET r_.aDateTimeSS  = "59"
  LET r_.aDateTimeSF  = "59:9999"
  LET r_.aDateTimeSFScale  = "59:99"
  LET r_.aDateTimeFF  = "9999"
  LET r_.aDateTimeFFScale  = "99"
 
	# Interval(s) =
  LET r_.aIntervalYY  = "1"
  LET r_.aIntervalYY  = "-1"
  LET r_.aIntervalYPrecY  = "1"
  LET r_.aIntervalYM  = "1"
  LET r_.aIntervalYPrecM  = "1"
  LET r_.aIntervalMM  = "1"
  LET r_.aIntervalMPrecM  = "1"
  LET r_.aIntervalDD  = "1"
  LET r_.aIntervalDPrecD  = "1"
  LET r_.aIntervalDH  = "1 1"
  LET r_.aIntervalDPrecH  = "1 1"
  LET r_.aIntervalDMin  = "1 1:1"
  LET r_.aIntervalDPrecMin  = "1 1:1"
  LET r_.aIntervalDS  = "1 1:1:1"
  LET r_.aIntervalDPrecS  = "1 1:1:1"
  LET r_.aIntervalDF  = "1 1:1:1:1"
  LET r_.aIntervalDPrecF  = "1 1:1:1:1"
  LET r_.aIntervalDFScale  = "1 1:1:1:1"
  LET r_.aIntervalDPrecFScale  = "1 1:1:1:1"
  LET r_.aIntervalHH  = "1"
  LET r_.aIntervalHPrecH  = "1"
  LET r_.aIntervalHM  = "1:1"
  LET r_.aIntervalHPrecM  = "1:1"
  LET r_.aIntervalHS  = "1:1:1"
  LET r_.aIntervalHPrecS  = "1:1:1"
  LET r_.aIntervalHF  = "1:1:1:1"
  LET r_.aIntervalHPrecF  = "1:1:1:1"
  LET r_.aIntervalHFScale  = "1:1:1:1"
  LET r_.aIntervalHPrecFScale  = "1:1:1:1"
  LET r_.aIntervalMinMin  = "1"
  LET r_.aIntervalMinPrecMin  = "1"
  LET r_.aIntervalMinS  = "1:1"
  LET r_.aIntervalMinPrecS  = "1:1"
  LET r_.aIntervalMinF  = "1:1:1"
  LET r_.aIntervalMinPrecF  = "1:1:1"
  LET r_.aIntervalMinFScale  = "1:1:1"
  LET r_.aIntervalMinPrecFScale  = "1:1:1"
  LET r_.aIntervalSS  = "1"
  LET r_.aIntervalSPrecS  = "1"
  LET r_.aIntervalSF  = "1:1"
  LET r_.aIntervalSPrecF  = "1:1"
  LET r_.aIntervalSFScale  = "1:1"
  LET r_.aIntervalSPrecFScale  = "1:1"
  LET r_.aIntervalFF  = "1"
  LET r_.aIntervalFFScale  = "1"

	# 
	LET r_.aCharacter = "C"
	LET r_.aCharacterWithSize = "Hello world"
	LET r_.aChar = "C"
	LET r_.aCharWithSize = "Hello world"
	LET r_.aVarchar = "Hello world"
	LET r_.aVarcharWithReserve = "Hello world"

	# Insert 
	INSERT INTO all_datatypes VALUES (r_.*)
	DELETE FROM  all_datatypes 
	  WHERE
	    r_.aInteger  = 20000000
      AND r_.aInt  = -20000000
      AND r_.aSmallint  = 32767
      AND r_.aDecimal  = 123456789012345.0
      AND r_.aDec  = 123456789012345.0
      AND r_.aNumeric  = 123456789012345.0
      AND r_.aDecimalPrec  = 123456789012345.0
      AND r_.aDecimalPrecScale  = 1234567890123.45
      AND r_.aMoney  = 123456789012345.0
      AND r_.aMoneyPrecision  = 123456789012345.0
      AND r_.aFloat  = 123456789012345.0
      AND r_.aFloatWithPrecision  = 123456789012345.0
      AND r_.aDouble  = 123456789012345.0
      AND r_.aSmallFloat  = 123456789012345.0
      AND r_.aReal  = 123456789012345.0
      AND r_.aDate  = mdy(12,31,1999)
 
	# Datetimes =
      AND r_.aDateTimeYY  = "1999"
      AND r_.aDateTimeYM  = "1999-12"
      AND r_.aDateTimeYD  = "1999-12-31"
      AND r_.aDateTimeYH  = "1999-12-31 23"
      AND r_.aDateTimeYMin  = "1999-12-31 23:59"
      AND r_.aDateTimeYS  = "1999-12-31 23:59:59"
      AND r_.aDateTimeYF  = "1999-12-31 23:59:59:999"
      AND r_.aDateTimeYFScale  = "1999-12-31 23:59:59:99"
      AND r_.aDateTimeMM  = "12"
      AND r_.aDateTimeMD  = "12-31"
      AND r_.aDateTimeMH  = "12-31 23"
      AND r_.aDateTimeMMin  = "12-31 23:59"
      AND r_.aDateTimeMS  = "12-31 23:59:59"
      AND r_.aDateTimeMF  = "12-31 23:59:59:9999"
      AND r_.aDateTimeMFScale  = "12-31 23:59:59:99"
      AND r_.aDateTimeDD  = "31"
      AND r_.aDateTimeDH  = "31 23"
      AND r_.aDateTimeDMin  = "31 23:59"
      AND r_.aDateTimeDS  = "31 23:59:59"
      AND r_.aDateTimeDF  = "31 23:59:59:9999"
      AND r_.aDateTimeDFScale  = "31 23:59:59:99"
      AND r_.aDateTimeHH  = "23"
      AND r_.aDateTimeHM  = "23:59"
      AND r_.aDateTimeHS  = "23:59:59"
      AND r_.aDateTimeHF  = "23:59:59:9999"
      AND r_.aDateTimeHFScale  = "23:59:59:99"
      AND r_.aDateTimeMinMin  = "59"
      AND r_.aDateTimeMinS  = "59:59"
      AND r_.aDateTimeMinF  = "59:59:9999"
      AND r_.aDateTimeMinFScale  = "59:59:99"
      AND r_.aDateTimeSS  = "59"
      AND r_.aDateTimeSF  = "59:9999"
      AND r_.aDateTimeSFScale  = "59:99"
      AND r_.aDateTimeFF  = "9999"
      AND r_.aDateTimeFFScale  = "99"
 
	# Interval(s) =
      AND r_.aIntervalYY  = "1"
      AND r_.aIntervalYY  = "-1"
      AND r_.aIntervalYPrecY  = "1"
      AND r_.aIntervalYM  = "1"
      AND r_.aIntervalYPrecM  = "1"
      AND r_.aIntervalMM  = "1"
      AND r_.aIntervalMPrecM  = "1"
      AND r_.aIntervalDD  = "1"
      AND r_.aIntervalDPrecD  = "1"
      AND r_.aIntervalDH  = "1 1"
      AND r_.aIntervalDPrecH  = "1 1"
      AND r_.aIntervalDMin  = "1 1:1"
      AND r_.aIntervalDPrecMin  = "1 1:1"
      AND r_.aIntervalDS  = "1 1:1:1"
      AND r_.aIntervalDPrecS  = "1 1:1:1"
      AND r_.aIntervalDF  = "1 1:1:1:1"
      AND r_.aIntervalDPrecF  = "1 1:1:1:1"
      AND r_.aIntervalDFScale  = "1 1:1:1:1"
      AND r_.aIntervalDPrecFScale  = "1 1:1:1:1"
      AND r_.aIntervalHH  = "1"
      AND r_.aIntervalHPrecH  = "1"
      AND r_.aIntervalHM  = "1:1"
      AND r_.aIntervalHPrecM  = "1:1"
      AND r_.aIntervalHS  = "1:1:1"
      AND r_.aIntervalHPrecS  = "1:1:1"
      AND r_.aIntervalHF  = "1:1:1:1"
      AND r_.aIntervalHPrecF  = "1:1:1:1"
      AND r_.aIntervalHFScale  = "1:1:1:1"
      AND r_.aIntervalHPrecFScale  = "1:1:1:1"
      AND r_.aIntervalMinMin  = "1"
      AND r_.aIntervalMinPrecMin  = "1"
      AND r_.aIntervalMinS  = "1:1"
      AND r_.aIntervalMinPrecS  = "1:1"
      AND r_.aIntervalMinF  = "1:1:1"
      AND r_.aIntervalMinPrecF  = "1:1:1"
      AND r_.aIntervalMinFScale  = "1:1:1"
      AND r_.aIntervalMinPrecFScale  = "1:1:1"
      AND r_.aIntervalSS  = "1"
      AND r_.aIntervalSPrecS  = "1"
      AND r_.aIntervalSF  = "1:1"
      AND r_.aIntervalSPrecF  = "1:1"
      AND r_.aIntervalSFScale  = "1:1"
      AND r_.aIntervalSPrecFScale  = "1:1"
      AND r_.aIntervalFF  = "1"
      AND r_.aIntervalFFScale  = "1"

	# 
	    AND r_.aCharacter = "C"
	    AND r_.aCharacterWithSize = "Hello world"
	    AND r_.aChar = "C"
	    AND r_.aCharWithSize = "Hello world"
	    AND r_.aVarchar = "Hello world"
	    AND r_.aVarcharWithReserve = "Hello world"
	
	# Select
	SELECT * INTO r_.* FROM all_datatypes
	DISPLAY sqlca.sqlcode
	DROP TABLE table_with_ser
	DROP TABLE all_datatypes

END MAIN

