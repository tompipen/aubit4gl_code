
DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)
	begin work
	LOCK TABLE xpto IN SHARE MODE
	rollback work
	DROP TABLE xpto
END MAIN
