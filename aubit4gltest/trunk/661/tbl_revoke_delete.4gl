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

  GRANT DELETE ON xpto TO auser
  REVOKE DELETE ON xpto FROM auser

  GRANT DELETE ON xpto TO auser, root
  REVOKE DELETE ON xpto FROM auser, root

	DROP TABLE xpto
END MAIN
