{**
 * @file
 * @test
 * Check if a simple select with diferent the in where condition 
 * fetch the correct values.
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
  DROP TABLE xpta
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
    valueColumn CHAR(20),
    dateColumn DATE
  )
  LET dt = mdy(12,31,1999)

  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (1,"first",dt)

  LET dt = mdy(1,1,2000)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (2,"the second",dt)

  LET dt = mdy(1,1,2001)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (3,"the third",dt)

  LET dt = mdy(1,1,2002)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (4,"the forth",dt)
	
  LET dt = mdy(12,31,1999)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (5,"fift",dt)
	
	DECLARE cr_ CURSOR FOR
    SELECT keyColumn, valueColumn, dateColumn
      FROM xpto
      WHERE dateColumn <> dt 			# mdy(12,31,1999)
			ORDER BY 1

	OPEN cr_

	FETCH cr_ INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
	IF sqlca.sqlcode != 0 THEN
	  DISPLAY "Did not make the first iteration"
    LET exitStatus = 1
	END IF
  -- First iteration
  IF lv_keyColumn != 2 THEN
    DISPLAY "Diferent key value on first iteration <", 
		  lv_keycolumn USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "the second" THEN
    DISPLAY "Diferent string value on first iteration"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value  on first iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
  
	-- Second iteration
	IF sqlca.sqlcode != 0 THEN
	  DISPLAY "Did not make the second iteration"
    LET exitStatus = 1
	END IF
	FETCH cr_ INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
  IF lv_keyColumn != 3 THEN
    DISPLAY "Diferent key value on second iteration <", 
		  lv_keycolumn USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "the third" THEN
    DISPLAY "Diferent string value on second iteration"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2001)) THEN
    DISPLAY "Diferent date value on second iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

	-- Third iteration
	IF sqlca.sqlcode != 0 THEN
	  DISPLAY "Did not make the third iteration"
    LET exitStatus = 1
	END IF
	FETCH cr_ INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
  IF lv_keyColumn != 4 THEN
    DISPLAY "Diferent key value on third iteration <", 
		  lv_keycolumn USING "<<", ">!=<4>"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "the forth" THEN
    DISPLAY "Diferent string value on third iteration"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2002)) THEN
    DISPLAY "Diferent date value on third iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

	CLOSE cr_
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
