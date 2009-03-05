{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlawarn[4] is assigned with a W after a select with more 
 * on a select list then on into
 *}

DATABASE test1

MAIN
	DEFINE exitStatus SMALLINT
	DEFINE lv_key SMALLINT
	DEFINE lv_value INTEGER

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  keyColumn SMALLINT,
		a_column INTEGER,
		other_column CHAR(5)
	)
	LET exitStatus = 0
	INSERT INTO xpto VALUES (1,1,"Hello")
	SELECT keyColumn, a_column, other_column
	  INTO lv_key, lv_value
		FROM xpto
  IF sqlca.sqlawarn[4] != "W" THEN
	  DISPLAY 
		"An warning was not issued after a select with less variables then into"
	display sqlca.sqlawarn
		LET exitStatus = 1
	END IF
	
	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
