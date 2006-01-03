{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlerrd[2] is assigned with last serial inserted.
 *}

DATABASE test1

MAIN
	DEFINE exitStatus SMALLINT

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  keyColumn SERIAL
	)
	LET exitStatus = 0
	INSERT INTO xpto VALUES (0)
  IF sqlca.sqlerrd[2] != 1 THEN
	  DISPLAY "The Serial inserted was wrong"
		LET exitStatus = 1
	END IF
	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
