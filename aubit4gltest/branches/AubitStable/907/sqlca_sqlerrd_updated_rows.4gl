{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlerrd[3] is assigned with the number of rows inserted
 * updated and deleted.
 *}

DATABASE test1

MAIN
	DEFINE exitStatus SMALLINT

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  keyColumn INTEGER,
		valueColumn CHAR(20)
	)
	LET exitStatus = 0
	INSERT INTO xpto VALUES (1,"Hello")
	INSERT INTO xpto VALUES (2,"World")
	INSERT INTO xpto VALUES (3,"Hello")
	INSERT INTO xpto VALUES (4,"World")
	INSERT INTO xpto VALUES (5,"Hello")
  IF sqlca.sqlerrd[3] != 1 THEN
	  DISPLAY "The number of rows inserted was wrong"
		LET exitStatus = 1
	END IF
	UPDATE xpto SET valueColumn = "Hello world" WHERE valueColumn = "World"
  IF sqlca.sqlerrd[3] != 2 THEN
	  DISPLAY "The number of rows updated was wrong"
		LET exitStatus = 1
	END IF
	DELETE FROM xpto WHERE valueColumn = "Hello"
  IF sqlca.sqlerrd[3] != 3 THEN
	  DISPLAY "The number of rows deleted was wrong"
		LET exitStatus = 1
	END IF
	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
