
DATABASE test1

MAIN
  DEFINE str CHAR(64)

  WHENEVER ERROR CONTINUE
	DROP VIEW xpta
	display sqlca.sqlcode
	DROP TABLE xpto
	display sqlca.sqlcode
  WHENEVER ERROR STOP
	display sqlca.sqlcode
	CREATE TABLE xpto (
	  firstColumn integer,
		secondColumn char(64)
	)
	display sqlca.sqlcode
	INSERT INTO xpto (firstColumn,secondColumn) VALUES (1,"Hello")
	display sqlca.sqlcode

	CREATE VIEW xptv AS SELECT * FROM xpto

	UPDATE xptv SET secondColumn = "1 - Hello world"
	  WHERE firstColumn = 1
	DECLARE cr CURSOR FOR 
	  SELECT secondColumn 
		  FROM xptv
	FOREACH cr INTO str
	  DISPLAY str clipped
	END FOREACH
	DROP VIEW xptv
	DROP TABLE xpto
END MAIN
