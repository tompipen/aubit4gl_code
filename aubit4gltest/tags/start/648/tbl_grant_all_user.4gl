
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
		secondColumn CHAR(10)
	)

  GRANT ALL ON xpto TO informix
  GRANT ALL ON xpto TO informix, root
  GRANT ALL PRIVILEGES ON xpto TO informix
  GRANT ALL PRIVILEGES ON xpto TO informix, root
	DROP TABLE xpto
END MAIN
