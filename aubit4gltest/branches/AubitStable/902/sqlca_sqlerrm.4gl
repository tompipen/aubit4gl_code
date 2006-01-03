{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlerrm is assigned with an obvious sql error.
 *}
database test1
MAIN
  DEFINE lv_sql_str CHAR(64)
	DEFINE exitStatus SMALLINT

	WHENEVER ERROR CONTINUE
	LET exitStatus = 0
	
	LET lv_sql_str = "SELECT xx FROM a_missing_table WHERE col=8"
	PREPARE st_sql FROM lv_sql_str
  	IF sqlca.sqlerrm IS NULL THEN
	  	DISPLAY "SQL Error message is NULL"
		LET exitStatus = 1
	ELSE
		DISPLAY "sqlerrm=",sqlca.sqlerrm," - Good"
	END IF
	EXIT PROGRAM exitStatus
END MAIN
