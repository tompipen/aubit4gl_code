{**
 * @file
 * @test
 * Check if the SET CONSTRAINTS ALL IMEDIATE statement works
 *}

DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE lv_valueColumn CHAR(20)
	DEFINE lv_str CHAR(50)
  DEFINE exitStatus SMALLINT
	DEFINE strSql CHAR(1024)

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
    valueColumn CHAR(20)
  )

	LET strSql="ALTER TABLE xpto ADD CONSTRAINT CHECK (valueColumn IS NOT NULL)",
	  " CONSTRAINT null_val "
	PREPARE stNullConst FROM strSql
	EXECUTE stNullConst 
	LET strSql = "ALTER TABLE xpto ADD CONSTRAINT CHECK (keyColumn > 0) ",
	  " CONSTRAINT positiveKey "
	PREPARE stGtZero FROM strSql
	EXECUTE stGtZero

  SET CONSTRAINTS ALL IMMEDIATE
	BEGIN WORK
	LET lv_str = NULL
	WHENEVER ERROR CONTINUE
  INSERT INTO xpto (keyColumn,valueColumn)
    VALUES (2,lv_str)
	IF sqlca.sqlcode = 0 THEN
    DISPLAY "NULL constraint was violated but not an error issued"
	  LET exitStatus = 1
	END IF

  INSERT INTO xpto (keyColumn,valueColumn)
    VALUES (-1,"Hello world")
	IF sqlca.sqlcode = 0 THEN
    DISPLAY "NULL constraint was violated but not an error issued"
	  LET exitStatus = 1
	END IF

	COMMIT WORK
	
	CLOSE cr_
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN
