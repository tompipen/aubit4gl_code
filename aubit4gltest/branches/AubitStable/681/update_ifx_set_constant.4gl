
DATABASE test1

MAIN
	DEFINE str CHAR(18)
	DEFINE sm SMALLINT
	DEFINE dt DATE

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP

	CREATE TABLE xpto (
	  firstColumn SMALLINT,
		secondColumn CHAR(20),
		thirdColumn INTEGER,
		aUser CHAR(10),
		aDate DATE,
		aToday DATE,
		aSingleQuoteStr VARCHAR(50,10)
	)

	INSERT INTO xpto (firstColumn,secondColumn,thirdColumn) VALUES (1,"Hello",1)

	UPDATE xpto 
	  SET (secondColumn,thirdColumn,aUser,aDate,
		     aToday,aSingleQuoteStr)
	   = ("Hello world",
				 1+1/2*5,
				 USER,
				 today+1,
				 TODAY,
				 'Single quote'
				)
	  WHERE firstColumn = 1

	DECLARE cr CURSOR FOR 
	  SELECT secondColumn, thirdColumn, aDate 
		  FROM xpto
	FOREACH cr INTO str, sm, dt
	  DISPLAY "<", str clipped, ">", "<", sm, ">", "<",  dt, ">"
	END FOREACH
	DROP TABLE xpto
END MAIN
