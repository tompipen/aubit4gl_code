{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlcode is assigned with NOTFOUND sql error.
 *}

DATABASE test1

MAIN
	DEFINE exitStatus SMALLINT

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  keyColumn SMALLINT
	)
	LET exitStatus = 0
	SELECT keyColumn FROM xpto
  IF sqlca.sqlcode != 100 THEN
	  DISPLAY "A select did not returned 100"
		LET exitStatus = 1
	END IF
  IF sqlca.sqlcode != NOTFOUND THEN
	  DISPLAY "A select did not returned NOTFOUND"
		LET exitStatus = 1
	END IF
	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
