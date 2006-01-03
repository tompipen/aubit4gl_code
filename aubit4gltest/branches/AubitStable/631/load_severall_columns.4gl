
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
	LOAD FROM "unlfile.unl" INSERT INTO xpto (firstColumn,secondColumn)
	SELECT * INTO r.* FROM xpto
	DISPLAY r.*
	DROP TABLE xpto
	CALL load2()
END MAIN
