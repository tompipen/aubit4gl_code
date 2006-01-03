{**
 * @file
 * @test
 * Check if a simple select with a simple comparison condition fetch the 
 * correct values.
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

  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (3,"Hello world",dt)

	DECLARE cr_ CURSOR FOR
    SELECT keyColumn, valueColumn, dateColumn
      FROM xpto
      WHERE keyColumn > 1 and valueColumn = "Hello world"

	OPEN cr_
	FETCH cr_ INTO lv_keyColumn, lv_valueColumn, lv_dateColumn

  -- First iteration
  IF lv_keyColumn != 2 THEN
    DISPLAY "Diferent key value on first iteration"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "Hello world" THEN
    DISPLAY "Diferent string value on first iteration"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value  on first iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

	FETCH cr_ INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
  IF lv_keyColumn != 3 THEN
    DISPLAY "Diferent key value on second iteration"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "Hello world" THEN
    DISPLAY "Diferent string value on second iteration"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value on second iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
	CLOSE cr_
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
