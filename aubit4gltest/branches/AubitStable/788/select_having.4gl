{**
 * @file
 * @test
 * Check if a simple select with HAVING condition using a variable
 * fetch the correct values.
 *}

DATABASE test1

MAIN
  DEFINE lv_count SMALLINT
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
    VALUES (1,"first",dt)

  LET dt = mdy(1,1,2000)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (2,"the second",dt)

  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (3,"the third",dt)

  LET dt = mdy(1,2,2000)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (4,"the forth",dt)
	
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (5,"fift",dt)
	
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (6,"sixt",dt)
	
	DECLARE cr_ CURSOR FOR
    SELECT count(*) , dateColumn
      FROM xpto
			GROUP BY dateColumn
			HAVING COUNT(*) > 1
			ORDER BY dateColumn

	OPEN cr_

  -- First iteration
	FETCH cr_ INTO lv_count, lv_dateColumn
  IF lv_count != 2 THEN
    DISPLAY "Diferent key value on first iteration <", 
		  lv_count USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value  on first iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
  
	-- Second iteration
	FETCH cr_ INTO lv_count, lv_dateColumn
  IF lv_count != 3 THEN
    DISPLAY "Diferent key value on second iteration <", 
		  lv_count USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,2,2000)) THEN
    DISPLAY "Diferent date value on second iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

	CLOSE cr_
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
