{**
 * @file
 * @test
 * Check if column expressions is correctly fetched.
 *}
DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE lv_keyColumn2 SMALLINT
  DEFINE lv_string CHAR(3)
  DEFINE lv_string2 CHAR(5)
	DEFINE a_float FLOAT
	DEFINE a_float2 FLOAT
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
	-- View
	-- Synonym
  SELECT keyColumn, xpto.keyColumn, 
	       a_string[1,3], xpto.a_string[1,5],
				 @a_float, @xpto.a_float,
				 ROWID
    INTO lv_keyColumn, lv_keyColumn2, 
		     lv_string, lv_string2,
	       a_float, a_float2,
				 a_rowid
    FROM xpto
    WHERE keyColumn = 1

  IF lv_keyColumn != 1 THEN
    DISPLAY "Diferent key value"
    LET exitStatus = 1
  END IF
  IF lv_keyColumn2 != 1 THEN
    DISPLAY "Diferent key value"
    LET exitStatus = 1
  END IF
  IF lv_string != "a s" THEN
    DISPLAY "Diferent substring value"
    LET exitStatus = 1
  END IF
  IF lv_string2 != "a str" THEN
    DISPLAY "Diferent substring value"
    LET exitStatus = 1
  END IF
  IF a_float != 45.56 THEN
    DISPLAY "Diferent float value"
    LET exitStatus = 1
  END IF
  IF a_float2 != 45.56 THEN
    DISPLAY "Diferent float value"
    LET exitStatus = 1
  END IF

  DROP VIEW v_xpto
  DROP SYNONYM s_xpto
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
