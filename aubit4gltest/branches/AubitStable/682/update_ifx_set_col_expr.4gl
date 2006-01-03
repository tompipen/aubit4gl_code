
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

	INSERT INTO xpto 
	    (firstColumn,secondColumn,thirdColumn,aUser,aDate,
		     aToday,aSingleQuoteStr)
	   VALUES (1,"Hello world",
				 5,
				 USER,
				 "12/31/1999",
				 TODAY,
				 'Single quote'
				)

	UPDATE xpto 
	    SET (secondColumn,thirdColumn,aUser,aDate,
			     aToday,aSingleQuoteStr)
	   = (aUser,
				 firstColumn+1/2*5,
				 secondColumn,
				 aDate-1,
				 aToday - 1,
				 'Single quote'
				)
	  WHERE firstColumn = 1

	DECLARE cr CURSOR FOR 
	  SELECT secondColumn, thirdColumn, aDate
		  FROM xpto
	FOREACH cr INTO str, sm, dt, dtt, it
	  DISPLAY "<", str clipped, ">", "<", sm, ">", "<",  dt, ">"
	END FOREACH
	DROP TABLE xpto
END MAIN
