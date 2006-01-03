
DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE test1@unstable:'informix'.xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)
	LOCK TABLE test1:xpto IN SHARE MODE
	LOCK TABLE test1:'informix'.xpto IN SHARE MODE
	LOCK TABLE test1@unstable:'informix'.xpto IN SHARE MODE
	DROP TABLE xpto
END MAIN



