
DATABASE test1

MAIN
  DEFINE str CHAR(64)
	DEFINE sm SMALLINT

  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn integer,
		secondColumn char(64),
		thirdColumn smallint
	)
	INSERT INTO xpto (firstColumn,secondColumn) VALUES (1,"Hello")


	UPDATE xpto SET (secondColumn,thirdColumn) = ("1 - Hello world",3)
	  WHERE firstColumn = 1
	DECLARE cr CURSOR FOR 
	  SELECT secondColumn, thirdColumn
		  FROM xpto
	FOREACH cr INTO str, sm
	  DISPLAY str clipped, sm
	END FOREACH
	DROP TABLE xpto
END MAIN
