{**
 * @file
 * @test
 * Check if a select with * fetch all correct values.
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
  DROP VIEW v_xpto
  DROP SYNONYM s_xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
		a_string CHAR(20),
		a_float FLOAT
  )
	CREATE VIEW v_xpto AS SELECT * FROM xpto
	CREATE SYNONYM s_xpto FOR xpto
  INSERT INTO xpto (keyColumn,a_string,a_float) VALUES (1,"a string",45.56)
  SELECT * 
    INTO lv_keycolumn, lv_string, a_float
    FROM xpto
    WHERE keyColumn = 1

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

  SELECT * 
    INTO lv_keycolumn, lv_string, a_float
    FROM v_xpto
    WHERE keyColumn = 1
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

  SELECT * 
    INTO lv_keycolumn, lv_string, a_float
    FROM s_xpto
    WHERE keyColumn = 1
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

  DROP VIEW v_xpto
  DROP SYNONYM s_xpto
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
