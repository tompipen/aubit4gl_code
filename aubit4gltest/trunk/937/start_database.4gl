{**
 * @file
 * Test if the START DATABASE 4gl statement works OK.
 * Note - This test only works with SE engine
 *}

DATABASE test1

MAIN
  DEFINE exitStatus SMALLINT

	LET exitStatus = 0
	CLOSE DATABASE 
  WHENEVER ERROR CONTINUE
	START DATABASE test1 WITH LOG IN "/tmp/test1.tr"
	IF sqlca.sqlcode != 0 THEN
	  DISPLAY "Start database statement returned the error ", sqlca.sqlcode
		LET exitStatus = 1
	END IF

	CLOSE DATABASE
	START DATABASE test1 WITH LOG IN "/tmp/test1.tr" MODE ANSI
	IF sqlca.sqlcode != 0 THEN
	  DISPLAY "Start database statement returned the error ", sqlca.sqlcode
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN


