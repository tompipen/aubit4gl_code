
DATABASE test1

MAIN
  DEFINE r RECORD
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	END RECORD
	DEFINE fileName CHAR(20)
	DEFINE queryStr CHAR(128)
	DEFINE delimiterStr CHAR

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	DROP TABLE xpta
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
	CREATE TABLE xpta (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
	INSERT INTO xpto VALUES (1,"Xpto")
	INSERT INTO xpta VALUES (1,"Xpta")
	LET fileName = "unlfile.unl"
	LET queryStr = "SELECT xpto.firstColumn,xpta.secondColumn FROM xpto, xpta",
	  " where xpto.firstColumn = xpta.firstColumn "
	LET delimiterStr = "!"
	UNLOAD TO fileName DELIMITER delimiterStr queryStr
	DELETE FROM xpto
	LOAD FROM fileName DELIMITER "!" INSERT INTO xpto 
	SELECT * INTO r.* FROM xpto
	DISPLAY r.*
	DROP TABLE xpto
	DROP TABLE xpta
END MAIN
