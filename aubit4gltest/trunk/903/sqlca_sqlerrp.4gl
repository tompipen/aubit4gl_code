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
	LET lv_sql_str = "SELEC xx FRM a_table WHRE col=8"
	PREPARE st_sql FROM lv_sql_str
  IF sqlca.sqlerrp IS NULL THEN
	  DISPLAY "SQL Error parameter is NULL"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
