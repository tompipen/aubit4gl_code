
DATABASE test1

MAIN
  DEFINE r RECORD
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	END RECORD

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
	INSERT INTO xpto VALUES (1,"Xpto")
	UNLOAD TO "unlfile.unl" SELECT * FROM xpto
	DELETE FROM xpto
	LOAD FROM "unlfile.unl" INSERT INTO xpto 
	SELECT * INTO r.* FROM xpto
	DISPLAY r.*
	DROP TABLE xpto
END MAIN
