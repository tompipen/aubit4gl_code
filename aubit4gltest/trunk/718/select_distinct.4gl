
DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE lv_valueColumn CHAR(10)
  DEFINE lv_dateColumn DATE
  DEFINE dt DATE
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
    valueColumn CHAR(10),
    dateColumn DATE
  )
  LET dt = mdy(12,31,1999)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (1,"Hello",dt)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (1,"Hello",dt)
  SELECT DISTINCT keyColumn, valueColumn, dateColumn
    INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
    FROM xpto
    WHERE keyColumn = 1
  DROP TABLE xpto

  IF lv_keyColumn != 1 THEN
    DISPLAY "Diferent key value"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "Hello" THEN
    DISPLAY "Diferent string value"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(12,31,1999)) THEN
    DISPLAY "Diferent date value <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
  EXIT PROGRAM exitStatus
END MAIN
