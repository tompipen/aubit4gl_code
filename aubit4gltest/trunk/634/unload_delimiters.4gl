
DATABASE test1

MAIN
  DEFINE r RECORD
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	END RECORD
	DEFINE fileName CHAR(25)
	DEFINE delimiterStr CHAR

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
	INSERT INTO xpto VALUES (1,"Xpto")
	LET fileName = "unlfile.unl"
	UNLOAD TO fileName DELIMITER ":" SELECT * FROM xpto
	DELETE FROM xpto
	LOAD FROM fileName DELIMITER ":" INSERT INTO xpto 
	SELECT * INTO r.* FROM xpto
	DISPLAY r.*

	LET fileName = "unlfile.unl"
	LET delimiterStr = ";"
	UNLOAD TO fileName DELIMITER delimiterStr SELECT * FROM xpto
	DELETE FROM xpto
	LOAD FROM fileName DELIMITER delimiterStr INSERT INTO xpto 
	SELECT * INTO r.* FROM xpto
	DISPLAY r.*
	DROP TABLE xpto
END MAIN
