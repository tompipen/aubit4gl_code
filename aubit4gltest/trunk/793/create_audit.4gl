{**
 * @file
 * Check if the create audit statement works.
 * Note that this statement only works on Informix SE.
 * @todo : Have a way to check if we are not in SE.
 *}

DATABASE test1

MAIN 
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  keyColumn SMALLINT,
		char_column CHAR(10)
	)
	CREATE AUDIT FOR xpto IN "/tmp/xx"

	DROP TABLE xpto
END MAIN
