
DATABASE test1

MAIN
  DEFINE str CHAR(64)

  WHENEVER ERROR CONTINUE
	DROP SYNONYM xpta
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn integer,
		secondColumn char(64)
	)
	INSERT INTO xpto (firstColumn,secondColumn) VALUES (1,"Hello")

	CREATE SYNONYM xpta FOR xpto

	UPDATE xpta SET secondColumn = "1 - Hello world"
	  WHERE firstColumn = 1
	DECLARE cr CURSOR FOR 
	  SELECT secondColumn 
		  FROM xpta
	FOREACH cr INTO str
	  DISPLAY str clipped
	END FOREACH
	DROP SYNONYM xpta
	DROP TABLE xpto
END MAIN

sql_features_used:
	@echo "DROP_TABLE DROP_SYNONYM CREATE_TABLE META_UPDATE_SYNONYM"

