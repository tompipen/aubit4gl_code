{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlawarn[3] is assigned with a W after a null in an 
 * agregate function of a select.
 *}

DATABASE test1

MAIN
	DEFINE exitStatus SMALLINT
	DEFINE lv_sum INTEGER

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  keyColumn SMALLINT,
		a_column INTEGER
	)
	LET exitStatus = 0
	INSERT INTO xpto VALUES (1,1)
	INSERT INTO xpto VALUES (2,NULL)
	INSERT INTO xpto VALUES (3,3)
	SELECT sum(a_column)
	  INTO lv_sum
		FROM xpto
  IF sqlca.sqlawarn[3] != "W" THEN
	  DISPLAY "An warning was not issued after an agregate with null values"
		LET exitStatus = 1
	END IF
  IF lv_sum != 4 THEN
	  DISPLAY "The sum give a wrong result"
		LET exitStatus = 1
	END IF

	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
