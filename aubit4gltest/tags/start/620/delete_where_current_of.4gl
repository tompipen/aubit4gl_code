
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
  
  begin work
  
	DECLARE cr CURSOR FOR SELECT * INTO r.* FROM xpto FOR UPDATE
	OPEN cr
	FETCH cr 
	DELETE FROM xpto WHERE CURRENT OF cr
	CLOSE cr
	SELECT * INTO r.* FROM xpto
	DISPLAY sqlca.sqlcode
	
  rollback work
	
	DROP TABLE xpto
END MAIN
