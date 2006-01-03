{**
 * @file
 * @test
 * Check if a simple select with AVG in select list 
 * fetch the correct values.
 *}

DATABASE test1

MAIN
  DEFINE lv_avg SMALLINT
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  DROP TABLE xpta
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
		intColumn INTEGER
  )

  INSERT INTO xpto (keyColumn,intColumn) 
    VALUES (1,2)

  INSERT INTO xpto (keyColumn,intColumn) 
    VALUES (2,3)

  INSERT INTO xpto (keyColumn,intColumn) 
    VALUES (3,4)

	DECLARE cr_ CURSOR FOR
    SELECT avg(intColumn)
      FROM xpto

	OPEN cr_
	FETCH cr_ INTO lv_avg

  -- First iteration
  IF lv_avg != 3 THEN
    DISPLAY "Diferent count on first iteration <", 
		  lv_avg USING "<<", ">!=<1>"
    LET exitStatus = 1
  END IF
	CLOSE cr_
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
