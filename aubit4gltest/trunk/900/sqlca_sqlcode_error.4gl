{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlcode is assigned with an obvious sql error.
 *}
MAIN
  DEFINE lv_sql_str CHAR(64)
	DEFINE exitStatus SMALLINT

	WHENEVER ERROR CONTINUE
	LET exitStatus = 0
	LET lv_sql_str = "SELEC xx FRM a_table WHRE col=8"
	PREPARE st_sql FROM lv_sql_str
  IF sqlca.sqlcode = 0 THEN
	  DISPLAY "A wrong select give a zero sqlca"
		LET exitStatus = 1
	END IF
  IF sqlca.sqlcode > 0 THEN
	  DISPLAY "A wrong select give a positive sqlca"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN
