{**
 * @file
 * @test
 * Check if a select with over two tables fetch the correct values.
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
  INSERT INTO xpta (keyColumn,a_string,a_float) VALUES (1,"a string",45.56)
  SELECT xpto.keyColumn, a_string, @a_float
    INTO lv_keycolumn, lv_string, a_float
    FROM xpto, xpta
    WHERE xpto.keyColumn = xpta.keyColumn

  IF lv_keyColumn != 1 THEN
    DISPLAY "Diferent key value"
    LET exitStatus = 1
  END IF
  IF lv_string != "a string" THEN
    DISPLAY "Diferent string value"
    LET exitStatus = 1
  END IF
  IF a_float != 45.56 THEN
    DISPLAY "Diferent float value"
    LET exitStatus = 1
  END IF

  DROP TABLE xpto
  DROP TABLE xpta
  EXIT PROGRAM exitStatus
END MAIN
