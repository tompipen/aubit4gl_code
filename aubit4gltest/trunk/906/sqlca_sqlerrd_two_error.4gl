{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlerrd[2] is assigned with the ISAM error with a lock
 *}

DATABASE test1

MAIN
	DEFINE exitStatus SMALLINT

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  keyColumn INTEGER,
		value CHAR(2) NOT NULL
	)
	LET exitStatus = 0
	WHENEVER ERROR CONTINUE
	INSERT INTO xpto (keyColumn) VALUES (1)
  IF sqlca.sqlerrd[2] != 0 THEN
	  DISPLAY "The isam error was not assigned"
		LET exitStatus = 1
	END IF
	WHENEVER ERROR STOP
	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
