
DATABASE test1

MAIN
  DEFINE str CHAR(64)

  WHENEVER ERROR CONTINUE
	DROP VIEW xptv
	DROP TABLE xpto
	DROP TABLE xpta
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn integer,
		secondColumn char(64)
	)
	CREATE TABLE xpta (
	  firstColumn integer,
		secondColumn char(64)
	)
	INSERT INTO xpto (firstColumn,secondColumn) VALUES (1,"Hello")
	INSERT INTO xpta (firstColumn,secondColumn) VALUES (1,"Hello")

	CREATE VIEW xptv AS 
	  SELECT xpto.firstColumn, xpta.secondColumn FROM xpto, xpta
	  WHERE xpto.firstColumn = xpta.firstColumn

	WHENEVER ERROR CONTINUE
	UPDATE xptv SET secondColumn = "1 - Hello world"
	  WHERE firstColumn = 1
	WHENEVER ERROR STOP
	IF sqlca.sqlcode != 0 THEN
	  DISPLAY "An error as ocurred as expected"
	ELSE
	  DISPLAY "An update on multi table view was worked."
	END IF
	DROP VIEW xptv
	DROP TABLE xpta
	DROP TABLE xpto
END MAIN
