{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlawarn[5] is assigned with a W after a select from a 
 * float to a decimal.
 *}

DATABASE test1

MAIN
	DEFINE exitStatus SMALLINT
	DEFINE lv_key SMALLINT
	DEFINE lv_value DECIMAL(10,2)

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  keyColumn SMALLINT,
		a_column FLOAT
	)
	LET exitStatus = 0
	INSERT INTO xpto VALUES (1,3.141516)
	SELECT keyColumn, a_column
	  INTO lv_key, lv_value
		FROM xpto
  IF sqlca.sqlawarn[5] != "W" THEN
	  DISPLAY 
		"An warning was not issued after a select with convertion from float to dec"
		LET exitStatus = 1
	END IF

	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
