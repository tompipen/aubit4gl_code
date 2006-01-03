{**
 * @file
 * @test
 * Check if a simple select with SUM in select list fetch the correct values.
 *}

DATABASE test1

MAIN
  DEFINE lv_sum SMALLINT
  DEFINE lv_date DATE
	DEFINE dt DATE
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
		intColumn INTEGER,
		dateColumn DATE
  )

	LET dt = MDY(12,31,1999)
  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (1,2,dt)

  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (2,3,dt)

	LET dt = MDY(1,1,2000)
  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (3,2,dt)

  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (3,1,dt)

  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (3,4,dt)

	DECLARE cr_ CURSOR FOR
    SELECT sum(intColumn), dateColumn
      FROM xpto
			GROUP BY dateColumn
			ORDER BY dateColumn

	OPEN cr_
	FETCH cr_ INTO lv_sum, lv_date

  -- First iteration
  IF lv_sum != 5 THEN
    DISPLAY "Diferent sum on first iteration <", 
		  lv_sum USING "<<", ">!=<5>"
    LET exitStatus = 1
  END IF
  IF lv_date != MDY(12,31,1999) THEN
    DISPLAY "Diferent date on first iteration <", 
		  lv_date, ">!=<1999-12-31>"
    LET exitStatus = 1
  END IF

	FETCH cr_ INTO lv_sum, lv_date
  -- Second iteration
  IF lv_sum != 7 THEN
    DISPLAY "Diferent sum on second iteration <", 
		  lv_sum USING "<<", ">!=<7>"
    LET exitStatus = 1
  END IF
  IF lv_date != MDY(1,1,2000) THEN
    DISPLAY "Diferent date on second iteration <", 
		  lv_date, ">!=<2000-01-01>"
    LET exitStatus = 1
  END IF

	CLOSE cr_
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
