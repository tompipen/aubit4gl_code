{**
 * @file
 * @test
 * Check if a simple select with ALL subquery in where condition 
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
  CREATE TABLE xpta (
    smint_column SMALLINT
  )
  LET dt = mdy(12,31,1999)

  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (1,"first",dt)

  LET dt = mdy(1,1,2000)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (2,"second",dt)

  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (3,"third",dt)

  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (4,"forth",dt)
	
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (5,"fift",dt)
	
	INSERT into xpta (smint_column) VALUES (2)
	INSERT into xpta (smint_column) VALUES (3)

	DECLARE cr_ CURSOR FOR
    SELECT keyColumn, valueColumn, dateColumn
      FROM xpto
      WHERE keyColumn > ALL (select smint_column FROM xpta )
			ORDER BY 1

	OPEN cr_
	FETCH cr_ INTO lv_keyColumn, lv_valueColumn, lv_dateColumn

  -- First iteration
  IF lv_keyColumn != 4 THEN
    DISPLAY "Diferent key value on first iteration <", 
		  lv_keycolumn USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "forth" THEN
    DISPLAY "Diferent string value on first iteration"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value  on first iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
  
	-- Second iteration
	FETCH cr_ INTO lv_keyColumn, lv_valueColumn, lv_dateColumn
  IF lv_keyColumn != 5 THEN
    DISPLAY "Diferent key value on second iteration <", 
		  lv_keycolumn USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "fift" THEN
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
