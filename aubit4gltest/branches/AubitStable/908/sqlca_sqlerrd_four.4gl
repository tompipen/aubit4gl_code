{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlerrd[4] is assigned with the estimated cost of query.
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
	INSERT INTO xpto VALUES (1)
	INSERT INTO xpto VALUES (2)
	INSERT INTO xpto VALUES (3)
	DECLARE cr CURSOR FOR
	  SELECT keyColumn FROM xpto
  IF sqlca.sqlerrd[4] <= 0 THEN
	  DISPLAY "The estimated cost of query was not positive : ", 
		  sqlca.sqlerrd[4] USING "<<<<"
		LET exitStatus = 1
	END IF
	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
