
DATABASE test1

MAIN
  DEFINE r RECORD
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	END RECORD
	DEFINE unlFileName CHAR(64)
	DEFINE strDelimiter CHAR

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
	LET unlFileName = "unldelimitercolon.unl"
	LOAD FROM unlFileName DELIMITER ":" INSERT INTO xpto 
	SELECT * INTO r.* FROM xpto
	DISPLAY r.*
	DELETE FROM xpto

	LET unlFileName = "unldelsemicolon.unl"
	LET strDelimiter = ";"
	LOAD FROM unlFileName DELIMITER strDelimiter INSERT INTO xpto 
	SELECT * INTO r.* FROM xpto
	DISPLAY r.*

	DROP TABLE xpto
END MAIN
