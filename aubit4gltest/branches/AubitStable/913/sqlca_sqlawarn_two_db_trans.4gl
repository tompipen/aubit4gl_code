{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlarn[2] is assigned with a W after using a database 
 * without transactions.
 *}


MAIN
	DEFINE exitStatus SMALLINT
	DEFINE lv_char CHAR(5)

  DATABASE test1
  
  #Set to W when the database now open
  #uses a transaction log.
  
  IF sqlca.sqlawarn[2] != "W" 
   OR sqlca.sqlawarn[2] IS NULL THEN
	  DISPLAY "An warning was not issued with a DB with transactions"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
