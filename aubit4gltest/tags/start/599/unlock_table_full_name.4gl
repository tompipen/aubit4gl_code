
DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE test1@unstable:'informix'.xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)
	LOCK TABLE xpto IN SHARE MODE
	UNLOCK TABLE test1:xpto 
	LOCK TABLE xpto IN SHARE MODE
	UNLOCK TABLE test1:'informix'.xpto 
	LOCK TABLE xpto IN SHARE MODE
	UNLOCK TABLE test1@unstable:'informix'.xpto 
	DROP TABLE xpto
END MAIN
