
DATABASE test1

MAIN
	DEFINE pr RECORD
	  aSmallint SMALLINT,
		aChar CHAR(64)
	END RECORD
	DEFINE pa ARRAY[3] OF DATE
	DEFINE par ARRAY[2] OF RECORD
	  aFloat FLOAT,
		aDecimal DECIMAL(16,2)
	END RECORD
	DEFINE _aSmallint SMALLINT
	DEFINE _aChar CHAR(64)
	DEFINE _aDate DATE
	DEFINE _aFloat FLOAT
	DEFINE _aDecimal DECIMAL(16,2)

  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn INTEGER,
		aSmallint SMALLINT,
		aChar CHAR(64),
		aDate DATE,
		aFloat FLOAT,
		aDecimal DECIMAL(16,2)
	)
	INSERT INTO xpto (firstColumn) VALUES (1)

  LET pr.aSmallint = 30000
	LET pr.aChar = "Hello"
	LET pa[1] = mdy(12,31,1999)
	LET par[1].aFloat = 12.6
	LET par[2].aDecimal = 6667.8777
	UPDATE xpto 
	  SET (
			aSmallint,
		  aChar,
			aDate,
		  aFloat,
		  aDecimal
		)
		=  (
      pr.aSmallint,
	    pr.aChar,
	    pa[1],
	    par[1].aFloat,
	    par[2].aDecimal
		)
	  WHERE firstColumn = 1
	DECLARE cr CURSOR FOR 
	  SELECT 
			aSmallint,
		  aChar,
			aDate,
		  aFloat,
		  aDecimal
		  FROM xpto
	FOREACH cr INTO 
			_aSmallint,
		  _aChar,
			_aDate,
		  _aFloat,
		  _aDecimal
	  DISPLAY 
			_aSmallint,
		  _aChar,
			_aDate,
		  _aFloat,
		  _aDecimal
	END FOREACH
	DROP TABLE xpto
END MAIN
