
{**
 * @file
 * This test is not complete because i think that the syntax for procedures is
 * not suported by 4gl
 *}
DATABASE test1

MAIN
  DEFINE r RECORD
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	END RECORD
	DEFINE str CHAR(128)

	WHENEVER ERROR CONTINUE
	#DROP PROCEDURE x
	DROP TABLE xpta
	WHENEVER ERROR STOP
	LET str = "CREATE PROCEDURE x () RETURNING SMALLINT,CHAR(10) ;",
		"  RETURN 1,'Xpto';",
	  " END PROCEDURE"
	PREPARE st FROM str
	CREATE TABLE xpta (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
  #INSERT INTO xpta VALUES (1,"XPTO")
	#SELECT * INTO r.* FROM xpta
	#DISPLAY r.*
	#DROP PROCEDURE x 
	DROP TABLE xpta
END MAIN
