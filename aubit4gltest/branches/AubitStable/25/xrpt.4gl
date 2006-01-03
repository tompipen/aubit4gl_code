
MAIN

	START REPORT xrpt TO "xjunk"
	FINISH REPORT xrpt

	START REPORT xrpt TO "xok"
	OUTPUT TO REPORT xrpt()
	FINISH REPORT xrpt

END MAIN

REPORT xrpt ()

	FORMAT

		PAGE HEADER
			PRINT "x header"

		ON EVERY ROW
			PRINT "x row"

		ON LAST ROW
			PRINT "x last row"

END REPORT
