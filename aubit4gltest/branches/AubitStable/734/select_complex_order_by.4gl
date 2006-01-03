
DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE lv_valueColumn CHAR(20)
  DEFINE lv_dateColumn DATE
  DEFINE dt DATE
	DEFINE lv_decimal DECIMAL(4,2)
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
    valueColumn CHAR(20),
    dateColumn DATE,
		a_decimal DECIMAL(4,2)
  )

  LET dt = mdy(12,31,1999)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn,a_decimal) 
    VALUES (1,"A",dt,20.01)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn,a_decimal) 
    VALUES (2,"B",dt,22.41)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn,a_decimal) 
    VALUES (3,"A",dt,15.9)
  LET dt = mdy(1,1,2000)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn,a_decimal) 
    VALUES (4,"A",dt,78.76)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn,a_decimal) 
    VALUES (5,"C",dt,78.76)

	DECLARE cr CURSOR FOR 
    SELECT keyColumn, valueColumn, dateColumn, a_decimal
      FROM xpto
		  ORDER BY 2 ASC, 4 DESC, dateColumn, keyColumn DESC

  OPEN cr

  -- First iteration
	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn, lv_decimal
  IF lv_keyColumn != 4 THEN
    DISPLAY "Diferent key value on first fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "A" THEN
    DISPLAY "Diferent string value on first fetch "
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value  on first fetch <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
  IF lv_decimal != 78.76 THEN
    DISPLAY "Diferent decimal value on first fetch "
    LET exitStatus = 1
  END IF

  -- Second iteration
	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn, lv_decimal
  IF lv_keyColumn != 1 THEN
    DISPLAY "Diferent key value on second fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "A" THEN
    DISPLAY "Diferent string value on second fetch "
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(12,31,1999)) THEN
    DISPLAY "Diferent date value  on second fetch <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
  IF lv_decimal != 20.01 THEN
    DISPLAY "Diferent decimal value on second fetch "
    LET exitStatus = 1
  END IF

  -- Third iteration
	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn, lv_decimal
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
  IF lv_decimal != 15.9 THEN
    DISPLAY "Diferent decimal value on third fetch "
    LET exitStatus = 1
  END IF

  -- Forth iteration
	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn, lv_decimal
  IF lv_keyColumn != 2 THEN
    DISPLAY "Diferent key value on forth fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "B" THEN
    DISPLAY "Diferent string value on forth fetch "
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(12,31,1999)) THEN
    DISPLAY "Diferent date value  on forth fetch <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
  IF lv_decimal != 22.41 THEN
    DISPLAY "Diferent decimal value on forth fetch "
    LET exitStatus = 1
  END IF

  -- Fift iteration
	FETCH cr INTO lv_keyColumn, lv_valueColumn, lv_dateColumn, lv_decimal
  IF lv_keyColumn != 5 THEN
    DISPLAY "Diferent key value on fift fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "C" THEN
    DISPLAY "Diferent string value on fift fetch "
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value  on fift fetch <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
  IF lv_decimal != 78.76 THEN
    DISPLAY "Diferent decimal value on fift fetch "
    LET exitStatus = 1
  END IF

  CLOSE cr
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
