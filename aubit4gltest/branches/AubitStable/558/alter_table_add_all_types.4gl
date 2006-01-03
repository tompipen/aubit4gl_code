
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
  CREATE TABLE xpto (
	  aColumn CHAR(5),
		secondColumn INTEGER
	)
	ALTER TABLE xpto ADD (
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
	   aNVarcharWithRes NVARCHAR(20,10),
		 aText TEXT,
		 aByte BYTE
	)
	DROP TABLE xpto
END MAIN


