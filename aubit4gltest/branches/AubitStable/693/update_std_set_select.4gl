
DATABASE test1

MAIN
  DEFINE str CHAR(64)
  DEFINE sm SMALLINT

  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  DROP TABLE xpta
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    firstColumn integer,
    secondColumn char(64),
    thirdColumn smallint
  )
  CREATE TABLE xpta (
    firstColumn integer,
    secondColumn char(64)
  )
  INSERT INTO xpto (firstColumn,secondColumn) VALUES (1,"Hello")
  INSERT INTO xpta (firstColumn,secondColumn) VALUES (2,"2 - Hello")


  UPDATE xpto 
    SET secondColumn = (SELECT secondColumn FROM xpta WHERE firstColumn=2),
        thirdColumn =  (SELECT firstColumn FROM xpta)
    WHERE firstColumn = 1
  DECLARE cr CURSOR FOR 
    SELECT secondColumn, thirdColumn
      FROM xpto
  FOREACH cr INTO str, sm
    DISPLAY str clipped, sm
  END FOREACH
  DROP TABLE xpto
  DROP TABLE xpta
END MAIN
