{
TEST IS INVALID
cannot unlock table within transaction
but commit or rollback will unlock the table anyway, so when we reach 
UNLOCK we will get error
}


DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	UNLOCK TABLE xpto  
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)
	begin work
	LOCK TABLE xpto IN SHARE MODE
	
	WHENEVER ERROR CONTINUE
		UNLOCK TABLE xpto
	WHENEVER ERROR STOP
	commit work
	DROP TABLE xpto
END MAIN


