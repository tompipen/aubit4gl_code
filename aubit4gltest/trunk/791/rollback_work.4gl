{**
 * @file
 * @test
 * Check if a ROLLBACK WORK works ok.
 *}

DATABASE test1

MAIN
  DEFINE lv_count SMALLINT
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
    valueColumn CHAR(20)
  )

	BEGIN WORK
  INSERT INTO xpto (keyColumn,valueColumn) 
    VALUES (1,"A")
  INSERT INTO xpto (keyColumn,valueColumn) 
    VALUES (2,"B")
	ROLLBACK WORK

  SELECT COUNT(*)
		INTO lv_count
    FROM xpto

	IF lv_count > 0 THEN
    DISPLAY "Data inserted with a rollback"
    LET exitStatus = 1
	END IF
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
