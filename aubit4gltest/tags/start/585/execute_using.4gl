
DATABASE test1

MAIN
  DEFINE intVar INTEGER
	DEFINE chVar CHAR(10)

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn integer,
		secondColumn CHAR(10)
	)
	PREPARE st FROM "INSERT INTO xpto (firstColumn,secondColumn) VALUES (?,?)"
	# This just works in aubit 4gl.
	EXECUTE st USING 1, "Hello"
	LET intVar = 2
	LET chVar = "Hello"
	EXECUTE st USING intVar, chVar
	DROP TABLE xpto
END MAIN
