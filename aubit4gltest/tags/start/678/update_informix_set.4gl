
DATABASE test1

MAIN
  DEFINE str CHAR(64)

  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn integer,
		secondColumn char(64)
	)
	INSERT INTO xpto (firstColumn,secondColumn) VALUES (1,"Hello")


	UPDATE xpto SET (secondColumn) = ("1 - Hello world")
	  WHERE firstColumn = 1
	DECLARE cr CURSOR FOR 
	  SELECT secondColumn 
		  FROM xpto
	FOREACH cr INTO str
	  DISPLAY str clipped
	END FOREACH
	DROP TABLE xpto
END MAIN
