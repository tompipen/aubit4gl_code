
DATABASE test1

MAIN
	DEFINE str CHAR(18)
	DEFINE sm SMALLINT
	DEFINE dt DATE
	DEFINE dtt DATETIME YEAR TO MINUTE
	DEFINE it INTERVAL HOUR TO MINUTE

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP

	CREATE TABLE xpto (
	  firstColumn SMALLINT,
		secondColumn CHAR(20),
		thirdColumn INTEGER,
		aUser CHAR(10),
		aDate DATE,
		aDateTime DATETIME YEAR TO MINUTE,
		anInterval INTERVAL HOUR TO MINUTE,
		aToday DATE,
		aCurrent DATETIME YEAR TO FRACTION(3),
		aSingleQuoteStr VARCHAR(50,10)
	)

	INSERT INTO xpto (firstColumn,secondColumn,thirdColumn) VALUES (1,"Hello",1)

	UPDATE xpto 
	  SET (secondColumn,thirdColumn,aUser,aDate,aDatetime,anInterval,
		     aToday,aCurrent,aSingleQuoteStr)
	   = ("Hello world",
				 1+1/2*5,
				 USER,
				 mdy(12,31,1999)+1,
				 datetime(1999-12-31 23:59) YEAR TO MINUTE,
				 interval(48:01) HOUR TO MINUTE,
				 TODAY,
				 CURRENT YEAR TO FRACTION(3),
				 'Single quote'
				)
	  WHERE firstColumn = 1

	DECLARE cr CURSOR FOR 
	  SELECT secondColumn, thirdColumn, aDate, aDateTime, anInterval
		  FROM xpto
	FOREACH cr INTO str, sm, dt, dtt, it
	  DISPLAY "<", str clipped, ">", "<", sm, ">", "<",  dt, ">", "<", dtt, ">",
		  "<", it, ">"
	END FOREACH
	DROP TABLE xpto
END MAIN
