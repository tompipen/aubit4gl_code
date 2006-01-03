{ 

To make this test executable, make sure users exist 


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

  GRANT INDEX ON xpto TO informix
  REVOKE INDEX ON xpto FROM informix

  GRANT INDEX ON xpto TO informix, root
  REVOKE INDEX ON xpto FROM informix, root

	DROP TABLE xpto
END MAIN
