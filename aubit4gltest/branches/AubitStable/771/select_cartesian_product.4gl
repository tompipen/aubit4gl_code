{**
 * @file
 * @test
 * Check if a select without a join between two tables fetch the 
 * correct cartesian product.
 *}
DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE lv_string CHAR(20)
	DEFINE a_float FLOAT
	DEFINE a_rowid INTEGER
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  DROP TABLE xpta
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT
  )
	CREATE TABLE xpta (
    keyColumn SMALLINT,
		a_string CHAR(20),
		a_float FLOAT
	)
  INSERT INTO xpto (keyColumn) VALUES (1)
  INSERT INTO xpto (keyColumn) VALUES (2)
  INSERT INTO xpta (keyColumn,a_string,a_float) VALUES (1,"a string",45.56)
  INSERT INTO xpta (keyColumn,a_string,a_float) VALUES (1,"other string",54)
	DECLARE cr CURSOR FOR
    SELECT xpto.keyColumn, a_string, @a_float
      INTO lv_keycolumn, lv_string, a_float
      FROM xpto, xpta
			ORDER BY 1, 2
#What does this select have to do with cartesian product?
			

	OPEN cr
	FETCH cr
  IF lv_keyColumn != 1 THEN
    DISPLAY "Diferent key value on first iteration"
    LET exitStatus = 1
  END IF
  IF lv_string != "a string" THEN
    DISPLAY "Diferent string value on first iteration"
    LET exitStatus = 1
  END IF
  IF a_float != 45.56 THEN
    DISPLAY "Diferent float value on first iteration"
    LET exitStatus = 1
  END IF

	FETCH cr
	IF sqlca.sqlcode != 0 THEN
    DISPLAY "Did not make second iteration"
	END IF
  IF lv_keyColumn != 1 THEN
    DISPLAY "Diferent key value on second iteration"
    LET exitStatus = 1
  END IF
  IF lv_string != "other string" THEN
    DISPLAY "Diferent string value on second iteration"
    LET exitStatus = 1
  END IF
  IF a_float != 54 THEN
    DISPLAY "Diferent float value on second iteration"
    LET exitStatus = 1
  END IF

	FETCH cr
	IF sqlca.sqlcode != 0 THEN
    DISPLAY "Did not make third iteration"
	END IF
  IF lv_keyColumn != 2 THEN
    DISPLAY "Diferent key value on third iteration"
    LET exitStatus = 1
  END IF
  IF lv_string != "a string" THEN
    DISPLAY "Diferent string value on third iteration"
    LET exitStatus = 1
  END IF
  IF a_float != 45.56 THEN
    DISPLAY "Diferent float value on third iteration"
    LET exitStatus = 1
  END IF

	FETCH cr
	IF sqlca.sqlcode != 0 THEN
    DISPLAY "Did not make forth iteration"
	END IF
  IF lv_keyColumn != 2 THEN
    DISPLAY "Diferent key value on forth iteration"
    LET exitStatus = 1
  END IF
  IF lv_string != "other string" THEN
    DISPLAY "Diferent string value on forth iteration"
    LET exitStatus = 1
  END IF
  IF a_float != 54 THEN
    DISPLAY "Diferent float value on forth iteration"
    LET exitStatus = 1
  END IF
	CLOSE cr

  DROP TABLE xpto
  DROP TABLE xpta
  EXIT PROGRAM exitStatus
END MAIN
