{**
 * @file
 * @test
 * Check if a select with over two tables with two outer fetch the correct 
 * values.
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
  DROP TABLE xptb
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT
  )
	CREATE TABLE xpta (
    keyColumn SMALLINT,
		a_string CHAR(20),
		a_float FLOAT
	)
	CREATE TABLE xptb (
    keyColumn SMALLINT
	)
  INSERT INTO xpto (keyColumn) VALUES (1)
  SELECT xpto.keyColumn, a_string, @a_float
    INTO lv_keycolumn, lv_string, a_float
    FROM xpto, outer (xpta, outer xptb)
    WHERE xpto.keyColumn = xpta.keyColumn
      AND xpta.keyColumn = xptb.keyColumn

  IF lv_keyColumn != 1 THEN
    DISPLAY "Diferent key value"
    LET exitStatus = 1
  END IF
  IF lv_string IS NOT NULL THEN
    DISPLAY "String value of outer was not null "
    LET exitStatus = 1
  END IF
  IF a_float IS NOT NULL THEN
    DISPLAY "float value of outer was not null "
    LET exitStatus = 1
  END IF

  DROP TABLE xpto
  DROP TABLE xpta
  DROP TABLE xptb
  EXIT PROGRAM exitStatus
END MAIN
