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

  GRANT SELECT ON xpto TO informix
  REVOKE SELECT ON xpto FROM informix

  GRANT SELECT ON xpto TO informix, root
  REVOKE SELECT ON xpto FROM informix, root

	DROP TABLE xpto
END MAIN
