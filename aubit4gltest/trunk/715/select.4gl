
DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT
  )
  INSERT INTO xpto (keyColumn) VALUES (1)
  SELECT keyColumn
    INTO lv_keyColumn
    FROM xpto
    WHERE keyColumn = 1
  DROP TABLE xpto
  IF lv_keyColumn != 1 THEN
    LET exitStatus = 1
  END IF
  EXIT PROGRAM exitStatus
END MAIN


