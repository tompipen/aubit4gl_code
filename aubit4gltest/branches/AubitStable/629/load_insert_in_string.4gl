
DATABASE test1

MAIN
  DEFINE r RECORD
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	END RECORD
	DEFINE unlFileName CHAR(16)
	DEFINE strInsert CHAR(128)

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
	LET unlFileName = "unlfile.unl"
	LET strInsert = "INSERT INTO xpto"
	LOAD FROM unlFileName strInsert
	SELECT * INTO r.* FROM xpto
	DISPLAY r.*
	DROP TABLE xpto
END MAIN
