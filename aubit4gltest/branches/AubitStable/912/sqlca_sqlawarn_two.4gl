{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlarn[2] is assigned with a W after a truncation in a 
 * select.
 *}

DATABASE test1

MAIN
	DEFINE exitStatus SMALLINT
	DEFINE lv_char CHAR(5)

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  keyColumn SMALLINT,
		a_column CHAR(20)
	)
	LET exitStatus = 0
	INSERT INTO xpto VALUES (1,"HELLO BIG WORLD PHRASE")
	SELECT a_column
	  INTO lv_char
		FROM xpto
  IF sqlca.sqlawarn[2] != "W" THEN
	  DISPLAY "An warning was not issued with truncation"
		LET exitStatus = 1
	END IF
	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
