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
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
    keyColumn SMALLINT,
		a_string CHAR(20),
		a_float FLOAT
	)
  INSERT INTO xpto (keyColumn,a_string,a_float) VALUES (1,"a string",45.56)

  SELECT x.keyColumn, x.a_string, @x.a_float
    INTO lv_keycolumn, lv_string, a_float
    FROM xpto AS x
    WHERE x.keyColumn = 1
  IF lv_keyColumn != 1 THEN
    DISPLAY "Different key value"
    LET exitStatus = 1
  END IF
  IF lv_string != "a string" THEN
    DISPLAY "Different string value"
    LET exitStatus = 1
  END IF
  IF fgl_round(a_float,2) != 45.56 THEN
    DISPLAY "Different float value",a_float
    LET exitStatus = 1
  END IF

  SELECT x.keyColumn, x.a_string, @x.a_float
    INTO lv_keycolumn, lv_string, a_float
    FROM xpto x
    WHERE x.keyColumn = 1
  IF lv_keyColumn != 1 THEN
    DISPLAY "Different key value"
    LET exitStatus = 1
  END IF
  IF lv_string != "a string" THEN
    DISPLAY "Different string value"
    LET exitStatus = 1
  END IF
  IF fgl_round(a_float,2) != 45.56 THEN
    DISPLAY "Different float value : ",a_float
    LET exitStatus = 1
  END IF

  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
