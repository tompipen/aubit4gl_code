{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlerrm is assigned with an obvious sql error.
 *}
MAIN
  DEFINE lv_sql_str CHAR(64)
	DEFINE exitStatus SMALLINT

	WHENEVER ERROR CONTINUE
	LET exitStatus = 0
	LET lv_sql_str = "SELECT xx FROM a_missing_table WHERE col=8"
	PREPARE st_sql FROM lv_sql_str
  IF sqlca.sqlcode >= 0 THEN
	  DISPLAY "Wrong sqlca it as not assigned sqlcode"
		LET exitStatus = 1
	END IF
	{ Informix 4gl does not assign sqlerrp. Shit
  IF sqlca.sqlerrp IS NULL THEN
	  DISPLAY "SQL Error parameter is NULL"
		LET exitStatus = 1
	END IF
	}
	EXIT PROGRAM exitStatus
END MAIN
