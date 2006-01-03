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
	LET dt = MDY(1,2,2000)

  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (3,4,dt)

  SELECT count(distinct dateColumn)
		INTO lv_count
    FROM xpto
		--GROUP BY dateColumn
		ORDER BY 1

  IF lv_count != 3 THEN
    DISPLAY "Diferent count of distinct values <", 
		  lv_count USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF

  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
