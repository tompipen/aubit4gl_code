{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlerrd[1] is assigned with NOTFOUND sql error.
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
  IF sqlca.sqlerrd[1] <= 0 THEN
	  DISPLAY "The estimated number of rows select was not positive"
		LET exitStatus = 1
	END IF
	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN


