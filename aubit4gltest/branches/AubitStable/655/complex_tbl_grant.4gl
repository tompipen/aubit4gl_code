
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
		secondColumn CHAR(10)
	)

  GRANT 
		INSERT,
		DELETE,
		SELECT,
	  SELECT (secondColumn,firstColumn),
	  UPDATE,
	  UPDATE (secondColumn,firstColumn),
		INDEX,
		ALTER
		ON xpto TO informix, root
	DROP TABLE xpto
END MAIN
