{**
 * @file
 * @test
 * Check if a numbered group by fetches the correct values.
 *}

DATABASE test1

MAIN
  DEFINE lv_count SMALLINT
  DEFINE lv_valueColumn CHAR(20)
  DEFINE lv_int INTEGER
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
    valueColumn CHAR(20),
    int_column SMALLINT
  )

  INSERT INTO xpto (keyColumn,valueColumn,int_column) VALUES (1,"A",1)
  INSERT INTO xpto (keyColumn,valueColumn,int_column) VALUES (2,"B",2)
  INSERT INTO xpto (keyColumn,valueColumn,int_column) VALUES (3,"A",1)
  INSERT INTO xpto (keyColumn,valueColumn,int_column) VALUES (4,"A",1)
  INSERT INTO xpto (keyColumn,valueColumn,int_column) VALUES (5,"C",3)

	DECLARE cr CURSOR FOR 
    SELECT count(*), valueColumn, int_column
      FROM xpto
			GROUP BY 2, 3
			ORDER BY 2

  OPEN cr

  -- First iteration
	FETCH cr INTO lv_count, lv_valueColumn, lv_int
  IF lv_count != 3 THEN
    DISPLAY "Diferent key count on first fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "A" THEN
    DISPLAY "Diferent string value on first fetch "
    LET exitStatus = 1
  END IF
  IF lv_int != 1 THEN
    DISPLAY "Diferent integer value on first fetch "
    LET exitStatus = 1
  END IF

  -- Second iteration
	FETCH cr INTO lv_count, lv_valueColumn, lv_int
  IF lv_count != 1 THEN
    DISPLAY "Diferent count value on second fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "B" THEN
    DISPLAY "Diferent string value on second fetch "
    LET exitStatus = 1
  END IF
  IF lv_int != 2 THEN
    DISPLAY "Diferent integer value on second fetch "
    LET exitStatus = 1
  END IF

  -- Third iteration
	FETCH cr INTO lv_count, lv_valueColumn, lv_int
  IF lv_count != 1 THEN
    DISPLAY "Diferent count value on third fetch "
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "C" THEN
    DISPLAY "Diferent string value on third fetch "
    LET exitStatus = 1
  END IF
  IF lv_int != 3 THEN
    DISPLAY "Diferent integer value on third fetch "
    LET exitStatus = 1
  END IF

  CLOSE cr
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
