
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

  CREATE SYNONYM xpta FOR xpto

  INSERT INTO xpta (firstColumn,secondColumn) VALUES (1,"Hello")
  INSERT INTO xpta (firstColumn,secondColumn) VALUES (2,"Hello")
  DELETE FROM xpta WHERE firstColumn = 1
  DECLARE cr CURSOR FOR 
    SELECT secondColumn 
      FROM xpta
  FOREACH cr INTO str
    DISPLAY str clipped
  END FOREACH
  DROP SYNONYM xpta
  DROP TABLE xpto
END MAIN


