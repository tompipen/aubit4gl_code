{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlawarn[6] is assigned with a W after an update with
 * non ansi syntax.
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
		a_column CHAR(20)
	)
	LET exitStatus = 0
	INSERT INTO xpto VALUES (1,"Hello world")
	UPDATE xpto set (a_column) = ("Hello")
  IF sqlca.sqlawarn[6] != "W" THEN
	  DISPLAY "An warning was not issued after non ansi update"
		LET exitStatus = 1
	END IF

	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
