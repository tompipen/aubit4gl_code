{**
 * @file
 * @test
 * Check if a simple select with COUNT distinct in select list fetch the 
 * correct values.
 *}

DATABASE test1

MAIN
  DEFINE lv_count SMALLINT
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
    SELECT count(distinct dateColumn)
      FROM xpto
			--GROUP BY dateColumn
			ORDER BY 1

	OPEN cr_

  -- First iteration
	FETCH cr_ INTO lv_count
  IF lv_count != 5 THEN
    DISPLAY "Diferent count on first iteration <", 
		  lv_count USING "<<", ">!=<5>"
    LET exitStatus = 1
  END IF

  -- Second iteration
	FETCH cr_ INTO lv_count
  IF lv_count != 7 THEN
    DISPLAY "Diferent count on second iteration <", 
		  lv_count USING "<<", ">!=<7>"
    LET exitStatus = 1
  END IF

	CLOSE cr_
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
