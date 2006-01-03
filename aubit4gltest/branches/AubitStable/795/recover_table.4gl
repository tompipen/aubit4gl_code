{**
 * @file
 * Check if the RECOVER TABLE statement works.
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
  whenever error continue
	RECOVER TABLE xpto
     if sqlca.sqlcode!=0 and sqlca.sqlcode!=-554 then exit program 1 end if

whenever error stop

	DROP TABLE xpto
END MAIN
