
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

  CREATE VIEW xptv AS 
    SELECT xpto.firstColumn, xpta.secondColumn FROM xpto, xpta
    WHERE xpto.firstColumn = xpta.firstColumn

  WHENEVER ERROR CONTINUE
  INSERT INTO xptv (firstColumn,secondColumn) VALUES (1,"Hello")
  WHENEVER ERROR STOP
  IF sqlca.sqlcode != 0 THEN
    DISPLAY "An error as ocurred as expected"
  ELSE
    DISPLAY "Error : An insert on multi table view was worked."
  END IF
  DROP VIEW xptv
  DROP TABLE xpta
  DROP TABLE xpto
END MAIN
