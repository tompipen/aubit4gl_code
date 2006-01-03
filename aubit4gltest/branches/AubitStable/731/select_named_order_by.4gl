
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
  LET dt = mdy(12,31,1999)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (2,"Hello world",dt)

	DECLARE cr CURSOR FOR 
    SELECT ALL keyColumn, valueColumn, dateColumn
      FROM xpto
		  ORDER BY keyColumn

  OPEN cr

	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
  IF lv_keyColumn != 1 THEN
    DISPLAY "Diferent key value on first fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "Hello" THEN
    DISPLAY "Diferent string value on first fetch "
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(12,31,1999)) THEN
    DISPLAY "Diferent date value  on first fetch <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
  IF lv_keyColumn != 2 THEN
    DISPLAY "Diferent key value on second fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "Hello world" THEN
    DISPLAY "Diferent string value on second fetch "
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(12,31,1999)) THEN
    DISPLAY "Diferent date value  on second fetch <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

  CLOSE cr
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
