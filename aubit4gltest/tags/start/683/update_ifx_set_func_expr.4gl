
DATABASE test1

MAIN
  DEFINE _firstColumn SMALLINT
  DEFINE _aDay SMALLINT
  DEFINE _aMonth SMALLINT
  DEFINE _aWeekday SMALLINT
  DEFINE _aYear SMALLINT
  DEFINE _aDate DATE
  DEFINE _anExtendDate DATE
  DEFINE _anExtendeDatetime DATETIME YEAR TO SECOND
  DEFINE _anMdy DATE
  DEFINE _aLength SMALLINT
  DEFINE _anHex CHAR(5)
  DEFINE _aRound INTEGER
  DEFINE _aTrunc INTEGER
	DEFINE dt DATE

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP

	CREATE TABLE xpto (
	  firstColumn SMALLINT,
		aDay SMALLINT,
		aMonth SMALLINT,
		aWeekday SMALLINT,
		aYear SMALLINT,
		aDate DATE,
		anExtendDate DATE,
		anExtendeDatetime DATETIME YEAR TO SECOND,
		anMdy DATE,
		aLength SMALLINT,
		anHex CHAR(5),
    aRound INTEGER,
		aTrunc INTEGER
	)

	INSERT INTO xpto (firstColumn) VALUES (1)

	LET dt = mdy(12,31,1999)

	UPDATE xpto 
	  SET ( 
		  aDay,
		  aMonth,
		  aWeekday,
		  aYear,
		  aDate,
		  anExtendDate,
		  anExtendeDatetime,
		  anMdy,
		  aLength,
		  anHex,
      aRound,
		  aTrunc 
		) = (
		      day(mdy(12,31,1999)),
	        month(mdy(12,31,1999)),
	        weekday(mdy(12,31,1999)),
	        year(mdy(12,31,1999)),
	        date(mdy(12,31,1999)),
	        extend(dt, YEAR TO DAY),
					--dt,
                extend(datetime(1999-12-31) YEAR TO DAY, YEAR TO MINUTE) 
                   - INTERVAL(720) MINUTE(3) TO MINUTE,
					mdy(12,31,1999),
					length("Hello"),
					hex(16),
					round(1.6),
					trunc(1.6)
			)
	  WHERE firstColumn = 1

	DECLARE cr CURSOR FOR 
	  SELECT 
	    firstColumn,
		  aDay,
		  aMonth,
		  aWeekday,
		  aYear,
		  aDate,
		  anExtendDate,
		  anExtendeDatetime,
		  anMdy,
		  aLength,
		  anHex,
      aRound,
		  aTrunc 
		  FROM xpto
	FOREACH cr INTO 
	    _firstColumn,
		  _aDay,
		  _aMonth,
		  _aWeekday,
		  _aYear,
		  _aDate,
		  _anExtendDate,
		  _anExtendeDatetime,
		  _anMdy,
		  _aLength,
		  _anHex,
      _aRound,
		  _aTrunc 
	  DISPLAY 
	    _firstColumn,
		  _aDay,
		  _aMonth,
		  _aWeekday,
		  _aYear,
		  _aDate,
		  _anExtendDate,
		  _anExtendeDatetime,
		  _anMdy,
		  _aLength,
		  _anHex,
      _aRound,
		  _aTrunc 
	END FOREACH
	DROP TABLE xpto
END MAIN
