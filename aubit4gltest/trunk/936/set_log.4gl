{**
 * @file
 * Test if the SET LOG 4gl statement works OK.
 *}

DATABASE test1

MAIN
  DEFINE exitStatus SMALLINT

	LET exitStatus = 0
  WHENEVER ERROR CONTINUE
	SET LOG
	IF sqlca.sqlcode != 0 THEN
	  DISPLAY "Set log statement returned the error ", sqlca.sqlcode
		LET exitStatus = 1
	END IF

	SET BUFFERED LOG
	IF sqlca.sqlcode != 0 THEN
	  DISPLAY "Set buffered log statement returned the error ", sqlca.sqlcode
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN
