{**
 * @file
 * @test
 * Check if a simple select with a NOT condition fetch the correct values.
 *}

DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE lv_valueColumn CHAR(20)
  DEFINE lv_dateColumn DATE
  DEFINE dt DATE
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
    valueColumn CHAR(20),
    dateColumn DATE
  )
  LET dt = mdy(12,31,1999)

  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (1,"Hello",dt)

  LET dt = mdy(1,1,2000)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (2,"Hello world",dt)

  SELECT keyColumn, valueColumn, dateColumn
    INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
    FROM xpto
    WHERE NOT keyColumn = 1
  DROP TABLE xpto

  IF lv_keyColumn != 2 THEN
    DISPLAY "Diferent key value"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "Hello world" THEN
    DISPLAY "Diferent string value"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
  EXIT PROGRAM exitStatus
END MAIN
