DATABASE test1

DEFINE r_ RECORD
     aInteger INTEGER,
     aInt INT,
     aSerial INT,
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

     #aDateTimeFF DATETIME FRACTION TO FRACTION,
     #aDateTimeFFScale DATETIME FRACTION TO FRACTION(3),
{
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
     #aIntervalFF INTERVAL FRACTION TO FRACTION,
     #aIntervalFFScale INTERVAL FRACTION TO FRACTION(3),
	}
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

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE all_datatypes
	DROP TABLE table_with_ser
  WHENEVER ERROR STOP
  CREATE TABLE all_datatypes (
     aInteger INTEGER,
     aInt INT,
		 aSerial SERIAL,
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
     #aDateTimeFF DATETIME FRACTION TO FRACTION,
     #aDateTimeFFScale DATETIME FRACTION TO FRACTION(3),
{
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
     #aIntervalFF INTERVAL FRACTION TO FRACTION,
     #aIntervalFFScale INTERVAL FRACTION TO FRACTION(3),
}
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
  LET r_.aDateTimeSF  = "59.9999"
  LET r_.aDateTimeSFScale  = "59.99"
  #r_.aDateTimeFF  = "9999"
  #r_.aDateTimeFFScale  = "99"
	 # Interval(s) =
{
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
  LET r_.aIntervalHPrecFScale  = "1:1:1.1"
  LET r_.aIntervalMinMin  = "1"
  LET r_.aIntervalMinPrecMin  = "1"
  LET r_.aIntervalMinS  = "1:1"
  LET r_.aIntervalMinPrecS  = "1:1"
  LET r_.aIntervalMinF  = "1:1.1"
  LET r_.aIntervalMinPrecF  = "1:1.1"
  LET r_.aIntervalMinFScale  = "1:1.1"
  LET r_.aIntervalMinPrecFScale  = "1:1.1"
  LET r_.aIntervalSS  = "1"
  LET r_.aIntervalSPrecS  = "1"
  LET r_.aIntervalSF  = "1.1"
  LET r_.aIntervalSPrecF  = "1.1"
  LET r_.aIntervalSFScale  = "1.1"
  LET r_.aIntervalSPrecFScale  = "1.1"
  #r_.aIntervalFF  = "1"
  #r_.aIntervalFFScale  = "1"
}
	# 
	LET r_.aCharacter = "C"
	LET r_.aCharacterWithSize = "Hello world"
	LET r_.aChar = "C"
	LET r_.aCharWithSize = "Hello world"
	LET r_.aVarchar = "Hello world"
	LET r_.aVarcharWithReserve = "Hello world"

	display "BEFORE INSERT"
	call display_it()
	# Insert 
	INSERT INTO all_datatypes VALUES (r_.*)
	
	# Select
	INITIALIZE r_.* TO NULL
	display "SET TO NULL"

	call display_it()
	INITIALIZE r_.* TO NULL
	SELECT * INTO r_.* FROM all_datatypes
	display "AFTER"
	call display_it()
	DROP TABLE table_with_ser
	DROP TABLE all_datatypes

END MAIN


function display_it()
	display "r_.aInteger=",r_.aInteger
	display "r_.aInt=",r_.aInt
	display "r_.aSmallint=",r_.aSmallint
	display "r_.aDecimal=",r_.aDecimal
	display "r_.aDec=",r_.aDec
	display "r_.aNumeric=",r_.aNumeric
	display "r_.aDecimalPrec=",r_.aDecimalPrec
	display "r_.aDecimalPrecScale=",r_.aDecimalPrecScale
	display "r_.aMoney=",r_.aMoney
	display "r_.aMoneyPrecision=",r_.aMoneyPrecision
	display "r_.aFloat=",r_.aFloat
	display "r_.aFloatWithPrecision=",r_.aFloatWithPrecision
	display "r_.aDouble=",r_.aDouble
	display "r_.aSmallFloat=",r_.aSmallFloat
	display "r_.aReal=",r_.aReal
	display "r_.aDate=",r_.aDate
	display "r_.aDateTimeYY=",r_.aDateTimeYY
	display "r_.aDateTimeYM=",r_.aDateTimeYM
	display "r_.aDateTimeYD=",r_.aDateTimeYD
	display "r_.aDateTimeYH=",r_.aDateTimeYH
	display "r_.aDateTimeYMin=",r_.aDateTimeYMin
	display "r_.aDateTimeYS=",r_.aDateTimeYS
	display "r_.aDateTimeYF=",r_.aDateTimeYF
	display "r_.aDateTimeYFScale=",r_.aDateTimeYFScale
	display "r_.aDateTimeMM=",r_.aDateTimeMM
	display "r_.aDateTimeMD=",r_.aDateTimeMD
	display "r_.aDateTimeMH=",r_.aDateTimeMH
	display "r_.aDateTimeMMin=",r_.aDateTimeMMin
	display "r_.aDateTimeMS=",r_.aDateTimeMS
	display "r_.aDateTimeMF=",r_.aDateTimeMF
	display "r_.aDateTimeMFScale=",r_.aDateTimeMFScale
	display "r_.aDateTimeDD=",r_.aDateTimeDD
	display "r_.aDateTimeDH=",r_.aDateTimeDH
	display "r_.aDateTimeDMin=",r_.aDateTimeDMin
	display "r_.aDateTimeDS=",r_.aDateTimeDS
	display "r_.aDateTimeDF=",r_.aDateTimeDF
	display "r_.aDateTimeDFScale=",r_.aDateTimeDFScale
	display "r_.aDateTimeHH=",r_.aDateTimeHH
	display "r_.aDateTimeHM=",r_.aDateTimeHM
	display "r_.aDateTimeHS=",r_.aDateTimeHS
	display "r_.aDateTimeHF=",r_.aDateTimeHF
	display "r_.aDateTimeHFScale=",r_.aDateTimeHFScale
	display "r_.aDateTimeMinMin=",r_.aDateTimeMinMin
	display "r_.aDateTimeMinS=",r_.aDateTimeMinS
	display "r_.aDateTimeMinF=",r_.aDateTimeMinF
	display "r_.aDateTimeMinFScale=",r_.aDateTimeMinFScale
	display "r_.aDateTimeSS=",r_.aDateTimeSS
	display "r_.aDateTimeSF=",r_.aDateTimeSF
	display "r_.aDateTimeSFScale=",r_.aDateTimeSFScale
{
	display "r_.aIntervalYY=",r_.aIntervalYY
	display "r_.aIntervalYY=",r_.aIntervalYY
	display "r_.aIntervalYPrecY=",r_.aIntervalYPrecY
	display "r_.aIntervalYM=",r_.aIntervalYM
	display "r_.aIntervalYPrecM=",r_.aIntervalYPrecM
	display "r_.aIntervalMM=",r_.aIntervalMM
	display "r_.aIntervalMPrecM=",r_.aIntervalMPrecM
	display "r_.aIntervalDD=",r_.aIntervalDD
	display "r_.aIntervalDPrecD=",r_.aIntervalDPrecD
	display "r_.aIntervalDH=",r_.aIntervalDH
	display "r_.aIntervalDPrecH=",r_.aIntervalDPrecH
	display "r_.aIntervalDMin=",r_.aIntervalDMin
	display "r_.aIntervalDPrecMin=",r_.aIntervalDPrecMin
	display "r_.aIntervalDS=",r_.aIntervalDS
	display "r_.aIntervalDPrecS=",r_.aIntervalDPrecS
	display "r_.aIntervalDF=",r_.aIntervalDF
	display "r_.aIntervalDPrecF=",r_.aIntervalDPrecF
	display "r_.aIntervalDFScale=",r_.aIntervalDFScale
	display "r_.aIntervalDPrecFScale=",r_.aIntervalDPrecFScale
	display "r_.aIntervalHH=",r_.aIntervalHH
	display "r_.aIntervalHPrecH=",r_.aIntervalHPrecH
	display "r_.aIntervalHM=",r_.aIntervalHM
	display "r_.aIntervalHPrecM=",r_.aIntervalHPrecM
	display "r_.aIntervalHS=",r_.aIntervalHS
	display "r_.aIntervalHPrecS=",r_.aIntervalHPrecS
	display "r_.aIntervalHF=",r_.aIntervalHF
	display "r_.aIntervalHPrecF=",r_.aIntervalHPrecF
	display "r_.aIntervalHFScale=",r_.aIntervalHFScale
	display "r_.aIntervalHPrecFScale=",r_.aIntervalHPrecFScale
	display "r_.aIntervalMinMin=",r_.aIntervalMinMin
	display "r_.aIntervalMinPrecMin=",r_.aIntervalMinPrecMin
	display "r_.aIntervalMinS=",r_.aIntervalMinS
	display "r_.aIntervalMinPrecS=",r_.aIntervalMinPrecS
	display "r_.aIntervalMinF=",r_.aIntervalMinF
	display "r_.aIntervalMinPrecF=",r_.aIntervalMinPrecF
	display "r_.aIntervalMinFScale=",r_.aIntervalMinFScale
	display "r_.aIntervalMinPrecFScale=",r_.aIntervalMinPrecFScale
	display "r_.aIntervalSS=",r_.aIntervalSS
	display "r_.aIntervalSPrecS=",r_.aIntervalSPrecS
	display "r_.aIntervalSF=",r_.aIntervalSF
	display "r_.aIntervalSPrecF=",r_.aIntervalSPrecF
	display "r_.aIntervalSFScale=",r_.aIntervalSFScale
	display "r_.aIntervalSPrecFScale=",r_.aIntervalSPrecFScale
}
	display "r_.aCharacter=",r_.aCharacter
	display "r_.aCharacterWithSize=",r_.aCharacterWithSize
	display "r_.aChar=",r_.aChar
	display "r_.aCharWithSize=",r_.aCharWithSize
	display "r_.aVarchar=",r_.aVarchar
	display "r_.aVarcharWithReserve=",r_.aVarcharWithReserve
end function
