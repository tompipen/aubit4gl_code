
DATABASE test1

MAIN
  DEFINE pr RECORD
    firstColumn integer,
    secondColumn char(64),
    thirdColumn smallint,
    forthColumn DATE
  END RECORD

  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    firstColumn integer,
    secondColumn char(64),
    thirdColumn smallint,
    forthColumn DATE
  )
  INSERT INTO xpto (firstColumn,secondColumn) VALUES (1,"Hello")


  LET pr.secondColumn = "1 - Hello world"
  LET pr.thirdColumn = 3
  LET pr.forthColumn = mdy(12,31,1999)
  UPDATE xpto 
    SET (secondColumn,thirdColumn,forthColumn) =
     ( pr.secondColumn THRU pr.forthColumn)
    WHERE firstColumn = 1
  INITIALIZE pr.* TO NULL

  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    firstColumn integer,
    secondColumn char(64),
    thirdColumn smallint,
    forthColumn DATE
  )
  INSERT INTO xpto (firstColumn,secondColumn) VALUES (1,"Hello")


  LET pr.secondColumn = "1 - Hello world"
  LET pr.thirdColumn = 3
  LET pr.forthColumn = mdy(12,31,1999)
  UPDATE xpto 
    SET (secondColumn,thirdColumn,forthColumn) =
     ( pr.secondColumn THRU pr.forthColumn)
    WHERE firstColumn = 1
  DECLARE cr CURSOR FOR 
    SELECT secondColumn, thirdColumn, forthColumn
      FROM xpto
  FOREACH cr INTO 
      pr.secondColumn,
      pr.thirdColumn,
      pr.forthColumn
    DISPLAY 
      "<", pr.secondColumn, ">",
      "<", pr.thirdColumn, ">",
      "<", pr.forthColumn, ">"
  END FOREACH
  DROP TABLE xpto
END MAIN
