
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

  DECLARE crUpd CURSOR FOR 
    SELECT secondColumn, thirdColumn FROM xpto
    FOR UPDATE
  OPEN crUpd
  FETCH crUpd 
  UPDATE xpto 
    SET secondColumn = "1 - Hello world",
        thirdColumn = 3
    WHERE CURRENT OF crUpd
  CLOSE crUpd
  DECLARE cr CURSOR FOR 
    SELECT secondColumn, thirdColumn
      FROM xpto
  FOREACH cr INTO str, sm
    DISPLAY str clipped, sm
  END FOREACH
  DROP TABLE xpto
END MAIN
