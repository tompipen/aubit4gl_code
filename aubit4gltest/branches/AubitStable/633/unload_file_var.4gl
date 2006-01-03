
DATABASE test1

MAIN
  DEFINE r RECORD
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	END RECORD
	DEFINE fileName CHAR(25)

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
	INSERT INTO xpto VALUES (1,"Xpto")
	LET fileName = "unlfile.unl"
	UNLOAD TO fileName SELECT * FROM xpto
	DELETE FROM xpto
	LOAD FROM fileName INSERT INTO xpto 
	SELECT * INTO r.* FROM xpto
	DISPLAY r.*
	DROP TABLE xpto
END MAIN
