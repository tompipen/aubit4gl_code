{**
 * @file
 * @test
 * Check if a select into temp with no log insert the correct values, and
 * if a delete in a rolled back transaction delete a row and then they are 
 * correctly fetched.
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
    VALUES (1,"A",dt)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (2,"B",dt)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (3,"A",dt)
  LET dt = mdy(1,1,2000)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (4,"A",dt)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (5,"C",dt)

  SELECT keyColumn, valueColumn, dateColumn
    FROM xpto
		INTO TEMP t_xpto WITH NO LOG

	BEGIN WORK
	DELETE FROM t_xpto WHERE valueColumn = "C"
	ROLLBACK WORK

	DECLARE cr CURSOR FOR 
    SELECT keyColumn, valueColumn, dateColumn
      FROM t_xpto
		  ORDER BY keyColumn ASC, valueColumn DESC, dateColumn
  OPEN cr

  -- First iteration
	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
  IF lv_keyColumn != 1 THEN
    DISPLAY "Diferent key value on first fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "A" THEN
    DISPLAY "Diferent string value on first fetch "
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(12,31,1999)) THEN
    DISPLAY "Diferent date value  on first fetch <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

  -- Second iteration
	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
  IF lv_keyColumn != 2 THEN
    DISPLAY "Diferent key value on second fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "B" THEN
    DISPLAY "Diferent string value on second fetch "
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(12,31,1999)) THEN
    DISPLAY "Diferent date value  on second fetch <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

  -- Third iteration
	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
  IF lv_keyColumn != 3 THEN
    DISPLAY "Diferent key value on third fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "A" THEN
    DISPLAY "Diferent string value on third fetch "
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(12,31,1999)) THEN
    DISPLAY "Diferent date value  on third fetch <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

  -- Forth iteration
	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
  IF lv_keyColumn != 4 THEN
    DISPLAY "Diferent key value on forth fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "A" THEN
    DISPLAY "Diferent string value on forth fetch "
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value  on forth fetch <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
	IF SQLCA.SQLCODE != 100 THEN
    DISPLAY "A row was deleted from a temp table with no log "
    LET exitStatus = 1
	END IF

  CLOSE cr
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
