
DATABASE test1

MAIN
  DEFINE r RECORD
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	END RECORD
	DEFINE unlFileName CHAR(16)

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
	LET unlFileName = "unlfile.unl"
	LOAD FROM unlFileName INSERT INTO xpto 
	SELECT * INTO r.* FROM xpto
	DISPLAY r.*
	DROP TABLE xpto
END MAIN
