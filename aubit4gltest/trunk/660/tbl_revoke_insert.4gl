{

To make this test executable, make sure users exist first 


}



DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
		secondColumn CHAR(10)
	)

  REVOKE INSERT ON xpto FROM informix
  GRANT INSERT ON xpto TO informix

  REVOKE INSERT ON xpto FROM informix, root
  GRANT INSERT ON xpto TO informix, root

	DROP TABLE xpto
END MAIN
