{
TEST IS INVALID
cannot unlock table within transaction
but commit or rollback will unloak the table anyway, so when we reach 
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
	commit work
	
	WHENEVER ERROR CONTINUE
		UNLOCK TABLE xpto
	WHENEVER ERROR STOP
	DROP TABLE xpto
END MAIN
