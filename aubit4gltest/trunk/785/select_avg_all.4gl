{**
 * @file
 * @test
 * Check if a simple select with AVG(ALL) in select list fetch the correct 
 * values.
 *}

DATABASE test1

MAIN
  DEFINE lv_avg SMALLINT
  DEFINE lv_date DATE
	DEFINE dt DATE
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  DROP TABLE xpta
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

  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (3,4,dt)


	LET dt = MDY(1,1,2000)
  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (4,3,dt)

  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (5,4,dt)

  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (6,5,dt)

	DECLARE cr_ CURSOR FOR
    SELECT AVG(ALL intColumn), dateColumn
      FROM xpto
			GROUP BY dateColumn
			ORDER BY dateColumn

	OPEN cr_
	FETCH cr_ INTO lv_avg, lv_date

  -- First iteration
  IF lv_avg != 3 THEN
    DISPLAY "Diferent avg on first iteration <", 
		  lv_avg USING "<<", ">!=<3>"
    LET exitStatus = 1
  END IF
  IF lv_date != MDY(12,31,1999) THEN
    DISPLAY "Diferent date on first iteration <", 
		  lv_date, ">!=<1999-12-31>"
    LET exitStatus = 1
  END IF

	FETCH cr_ INTO lv_avg, lv_date
  -- Second iteration
  IF lv_avg != 4 THEN
    DISPLAY "Diferent avg on second iteration <", 
		  lv_avg USING "<<", ">!=<4>"
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
