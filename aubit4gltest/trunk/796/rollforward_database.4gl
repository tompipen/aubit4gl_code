{**
 * @file
 * Check if the create audit statement works.
 * Note that this statement only works on Informix SE.
 * @todo : Have a way to check if we are not in SE.
 *}

MAIN 
  WHENEVER ERROR CONTINUE
	DROP DATABASE a_db
  WHENEVER ERROR CALL drop_db
	CREATE DATABASE a_db

	ROLLFORWARD DATABASE a_db

	DROP DATABASE a_db
END MAIN

FUNCTION drop_db()
	CLOSE DATABASE
  DROP DATABASE a_db
	EXIT PROGRAM 1
END FUNCTION
