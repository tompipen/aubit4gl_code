{**
 * @file
 * @process TSTSQLCA
 * Test if the sqlca.sqlerrd[5] is assigned with the offset of an error in an
 * wrong sql statement.
 *}

DATABASE test1

MAIN
	DEFINE lv_sqlStr CHAR(256)
	DEFINE exitStatus SMALLINT

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  keyColumn INTEGER
	)
	LET exitStatus = 0
	WHENEVER ERROR CONTINUE
	LET lv_sqlStr = "SELECT * FRM xpto"
	PREPARE st FROM lv_sqlStr
  IF sqlca.sqlerrd[5] != 10 THEN
	  DISPLAY "The offset of the error in the string was wrong : ", 
		   sqlca.sqlerrd[5] USING "<<"
		LET exitStatus = 1
	END IF
	WHENEVER ERROR STOP
	DROP TABLE xpto
	EXIT PROGRAM exitStatus
END MAIN
