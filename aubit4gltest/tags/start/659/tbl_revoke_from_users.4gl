
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
		secondColumn CHAR(10)
	)

  REVOKE ALL ON xpto FROM informix
  GRANT ALL ON xpto TO informix

  REVOKE ALL PRIVILEGES ON xpto FROM informix
  GRANT ALL PRIVILEGES ON xpto TO informix

  REVOKE ALL ON xpto FROM informix, root
  GRANT ALL ON xpto TO informix, root

  REVOKE ALL PRIVILEGES ON xpto FROM informix, root
  GRANT ALL PRIVILEGES ON xpto TO informix, root

	DROP TABLE xpto
END MAIN
