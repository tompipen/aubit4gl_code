{**
 * @file
 * @test
 * Check if select with substring fecth the correct values.
 *}
DATABASE test1

MAIN
  DEFINE lv_string CHAR(3)
  DEFINE lv_string2 CHAR(5)
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
		a_string CHAR(20)
  )
  INSERT INTO xpto (keyColumn,a_string) VALUES (1,"a string")
  SELECT a_string[3,6], xpto.a_string[1,8]
    INTO lv_string, lv_string2
    FROM xpto
    WHERE keyColumn = 1

  IF lv_string != "str" THEN
    DISPLAY "Diferent substring value (1):'",lv_string,"'"
    LET exitStatus = 1
  END IF
  IF lv_string2 != "a string" THEN
    DISPLAY "Diferent substring value (2):'",lv_string2,"'"
    LET exitStatus = 1
  END IF
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
