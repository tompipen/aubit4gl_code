{**
 * @file
 * Check if the ROLLFORWARD DATABASE statement works.
 * Note that this statement only works on Informix SE.
 * @todo : Have a way to check if we are not in SE.
 *}

MAIN 
  WHENEVER ERROR CONTINUE
# Make sure everything is nice and clean
	execute immediate "DROP DATABASE a_db"
	execute immediate "CREATE DATABASE a_db"
	execute immediate "CLOSE DATABASE "
	Execute immediate "DATABASE a_db"


WHENEVER ERROR continue

	ROLLFORWARD DATABASE a_db
	if sqlca.sqlcode=0 or sqlca.sqlcode=-554 then
	else
		exit program 1
	end if
	
	execute immediate "DROP DATABASE a_db"
END MAIN

FUNCTION drop_db()
	whenever error stop
	display "Error :",sqlca.sqlcode
	execute immediate "CLOSE DATABASE"
	EXECUTE IMMEDIATE "DROP DATABASE a_db"
	EXIT PROGRAM 1
END FUNCTION



