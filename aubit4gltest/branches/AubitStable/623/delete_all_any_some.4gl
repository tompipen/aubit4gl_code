
{**
 * @file
 *}
DATABASE test1

MAIN
  DEFINE r RECORD
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	END RECORD
	DEFINE str CHAR(128)

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
  INSERT INTO xpto VALUES (1,"XPTO")
  INSERT INTO xpta VALUES (1,"XPTO")
	DELETE FROM xpto 
	  WHERE firstColumn = ALL (SELECT firstColumn FROM xpta )
	SELECT * INTO r.* FROM xpto
	DISPLAY sqlca.sqlcode

  INSERT INTO xpto VALUES (1,"XPTO")
	DELETE FROM xpto 
	  WHERE firstColumn = ANY (SELECT firstColumn FROM xpta )
	SELECT * INTO r.* FROM xpto
	DISPLAY sqlca.sqlcode

  INSERT INTO xpto VALUES (1,"XPTO")
	DELETE FROM xpto 
	  WHERE firstColumn = SOME (SELECT firstColumn FROM xpta )
	SELECT * INTO r.* FROM xpto
	DISPLAY sqlca.sqlcode

	DROP TABLE xpto
	DROP TABLE xpta
END MAIN



