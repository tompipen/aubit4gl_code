# @(#)$Id: reptest.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
# @(#)Test program for REPORT_DESTINATION

MAIN

	DEFINE i INTEGER, s CHAR(40)
	DEFER INTERRUPT

	LET i = 0
	WHILE i >= 0 AND i <= 3
		CALL report_destination() RETURNING i, s
		IF i >= 0 AND i <= 3 THEN
			SLEEP 1
			MESSAGE "Again!"
		END IF
	END WHILE

END MAIN
