
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
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
  INSERT INTO xpto VALUES (1,"XPTO")
	DELETE FROM xpto WHERE firstColumn = 1
	SELECT * INTO r.* FROM xpto
	DISPLAY sqlca.sqlcode
	DROP TABLE xpto
END MAIN


