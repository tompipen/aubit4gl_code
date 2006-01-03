{**
 * @file
 * @test
 * Check if constant strings double and single quoted on select
 * are correctly received.
 *}
DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE lv_singleQuoted CHAR(20)
  DEFINE lv_doubleQuoted CHAR(20)
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT
  )
  INSERT INTO xpto (keyColumn) VALUES (1)
  SELECT 3 AS KEY_COLUMN, "Double quoted" VALUE_COLUMN, 'Single quoted'
    INTO lv_keyColumn, lv_doubleQuoted, lv_singleQuoted
    FROM xpto
    WHERE keyColumn = 1
  DROP TABLE xpto

  IF lv_keyColumn != 3 THEN
    DISPLAY "Diferent key value"
    LET exitStatus = 1
  END IF
  IF lv_doubleQuoted != "Double quoted" THEN
    DISPLAY "Diferent DQ string value : ",lv_doubleQuoted
    LET exitStatus = 1
  END IF
  IF lv_singleQuoted != "Single quoted" THEN
    DISPLAY "Diferent SQ string value ",lv_singleQuoted
    LET exitStatus = 1
  END IF
  EXIT PROGRAM exitStatus
END MAIN
