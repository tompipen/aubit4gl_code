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
     aMoneyPrec MONEY(16),
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
     aIntervalSPFS INTERVAL SECOND (2) TO FRACTION(2),
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
	   aVarcharWithRes VARCHAR(20,10),
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
     aMoneyPrec MONEY(16),
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
     aIntervalSPFS INTERVAL SECOND (2) TO FRACTION(2),
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
  LET r_.aMoneyPrec  = 123456789012345.0
  LET r_.aFloat  = 123456789012345.0
  LET r_.aFloatWithPrec  = 123456789012345.0
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
  LET r_.aIntervalDF  = "1 1:1:1.1"
  LET r_.aIntervalDPrecF  = "1 1:1:1.1"
  LET r_.aIntervalDFScale  = "1 1:1:1.1"
  LET r_.aIntervalDPrecFScale  = "1 1:1:1.1"
  LET r_.aIntervalHH  = "1"
  LET r_.aIntervalHPrecH  = "1"
  LET r_.aIntervalHM  = "1:1"
  LET r_.aIntervalHPrecM  = "1:1"
  LET r_.aIntervalHS  = "1:1:1"
  LET r_.aIntervalHPrecS  = "1:1:1"
  LET r_.aIntervalHF  = "1:1:1.1"
  LET r_.aIntervalHPrecF  = "1:1:1.1"
  LET r_.aIntervalHFScale  = "1:1:1.1"
  LET r_.aIntervalHPFS  = "1:1:1.1"
  LET r_.aIntervalMinMin  = "1"
  LET r_.aIntervalMinPrecMin  = "1"
  LET r_.aIntervalMinS  = "1:1"
  LET r_.aIntervalMinPrecS  = "1:1"
  LET r_.aIntervalMinF  = "1:1.1"
  LET r_.aIntervalMinPrecF  = "1:1.1"
  LET r_.aIntervalMinFScale  = "1:1.1"
  LET r_.aIntervalMinPFS  = "1:1.1"
  LET r_.aIntervalSS  = "1"
  LET r_.aIntervalSPrecS  = "1"
  LET r_.aIntervalSF  = "1.1"
  LET r_.aIntervalSPrecF  = "1.1"
  LET r_.aIntervalSFScale  = "1.1"
  LET r_.aIntervalSPFS  = "1.1"
  LET r_.aIntervalFF  = "1"
  LET r_.aIntervalFFScale  = "1"

	# 
	LET r_.aCharacter = "C"
	LET r_.aCharacterWithSize = "Hello world"
	LET r_.aChar = "C"
	LET r_.aCharWithSize = "Hello world"
	LET r_.aVarchar = "Hello world"
	LET r_.aVarcharWithRes = "Hello world"

	# Insert 
	INSERT INTO all_datatypes VALUES (r_.*)
	UPDATE all_datatypes SET  (
aInteger,
aInt,
aSmallint,
aDecimal,
aDec,
aNumeric,
aDecimalPrec,
aDecimalPrecScale,
aMoney,
aMoneyPrec,
aMoneyPrecScale,
aFloat,
aFloatWithPrec,
aDouble,
aSmallFloat,
aReal,
aDate,
aDateTimeYY,
aDateTimeYM,
aDateTimeYD,
aDateTimeYH,
aDateTimeYMin,
aDateTimeYS,
aDateTimeYF,
aDateTimeYFScale,
aDateTimeMM,
aDateTimeMD,
aDateTimeMH,
aDateTimeMMin,
aDateTimeMS,
aDateTimeMF,
aDateTimeMFScale,
aDateTimeDD,
aDateTimeDH,
aDateTimeDMin,
aDateTimeDS,
aDateTimeDF,
aDateTimeDFScale,
aDateTimeHH,
aDateTimeHM,
aDateTimeHS,
aDateTimeHF,
aDateTimeHFScale,
aDateTimeMinMin,
aDateTimeMinS,
aDateTimeMinF,
aDateTimeMinFScale,
aDateTimeSS,
aDateTimeSF,
aDateTimeSFScale,
aDateTimeFF,
aDateTimeFFScale,
aIntervalYY,
aIntervalYPrecY,
aIntervalYM,
aIntervalYPrecM,
aIntervalMM,
aIntervalMPrecM,
aIntervalDD,
aIntervalDPrecD,
aIntervalDH,
aIntervalDPrecH,
aIntervalDMin,
aIntervalDPrecMin,
aIntervalDS,
aIntervalDPrecS,
aIntervalDF,
aIntervalDPrecF,
aIntervalDFScale,
aIntervalDPrecFS,
aIntervalHH,
aIntervalHPrecH,
aIntervalHM,
aIntervalHPrecM,
aIntervalHS,
aIntervalHPrecS,
aIntervalHF,
aIntervalHPrecF,
aIntervalHFScale,
aIntervalHPFS,
aIntervalMinMin,
aIntervalMinPrecMin,
aIntervalMinS,
aIntervalMinPrecS,
aIntervalMinF,
aIntervalMinPrecF,
aIntervalMinFScale,
aIntervalMinPFS,
aIntervalSS,
aIntervalSPrecS,
aIntervalSF,
aIntervalSPrecF,
aIntervalSFScale,
aIntervalSPFS,
aIntervalFF,
aIntervalFFScale,
aCharacter,
aCharacterWithSize,
aNChar,
aChar,
aCharWithSize,
aNCharWithSize,
aVarchar,
aNVarchar,
aVarcharWithRes,
aNVarcharWithRes)
 = (r_.*)
	
	# Select
	INITIALIZE r_.* TO NULL
	DISPLAY "<", r_.*, ">"
	SELECT * INTO r_.* FROM all_datatypes
	DISPLAY "<", r_.*, ">"
	DROP TABLE table_with_ser
	DROP TABLE all_datatypes

END MAIN
{
aInteger,
aInt,
aSmallint,
aDecimal,
aDec,
aNumeric,
aDecimalPrec,
aDecimalPrecScale,
aMoney,
aMoneyPrec,
aMoneyPrecScale,
aFloat,
aFloatWithPrec,
aDouble,
aSmallFloat,
aReal,
aDate,
,
#,
aDateTimeYY,
aDateTimeYM,
aDateTimeYD,
aDateTimeYH,
aDateTimeYMin,
aDateTimeYS,
aDateTimeYF,
aDateTimeYFScale,
aDateTimeMM,
aDateTimeMD,
aDateTimeMH,
aDateTimeMMin,
aDateTimeMS,
aDateTimeMF,
aDateTimeMFScale,
aDateTimeDD,
aDateTimeDH,
aDateTimeDMin,
aDateTimeDS,
aDateTimeDF,
aDateTimeDFScale,
aDateTimeHH,
aDateTimeHM,
aDateTimeHS,
aDateTimeHF,
aDateTimeHFScale,
aDateTimeMinMin,
aDateTimeMinS,
aDateTimeMinF,
aDateTimeMinFScale,
aDateTimeSS,
aDateTimeSF,
aDateTimeSFScale,
aDateTimeFF,
aDateTimeFFScale,
,
#,
aIntervalYY,
aIntervalYPrecY,
aIntervalYM,
aIntervalYPrecM,
aIntervalMM,
aIntervalMPrecM,
aIntervalDD,
aIntervalDPrecD,
aIntervalDH,
aIntervalDPrecH,
aIntervalDMin,
aIntervalDPrecMin,
aIntervalDS,
aIntervalDPrecS,
aIntervalDF,
aIntervalDPrecF,
aIntervalDFScale,
aIntervalDPrecFScale,
aIntervalHH,
aIntervalHPrecH,
aIntervalHM,
aIntervalHPrecM,
aIntervalHS,
aIntervalHPrecS,
aIntervalHF,
aIntervalHPrecF,
aIntervalHFScale,
aIntervalHPFS,
aIntervalMinMin,
aIntervalMinPrecMin,
aIntervalMinS,
aIntervalMinPrecS,
aIntervalMinF,
aIntervalMinPrecF,
aIntervalMinFScale,
aIntervalMinPFS,
aIntervalSS,
aIntervalSPrecS,
aIntervalSF,
aIntervalSPrecF,
aIntervalSFScale,
aIntervalSPFS,
aIntervalFF,
aIntervalFFScale,
,
#,
aCharacter,
aCharacterWithSize,
aNChar,
aChar,
aCharWithSize,
aNCharWithSize,
aVarchar,
aNVarchar,
aVarcharWithRes,
aNVarcharWithRes,
,}
