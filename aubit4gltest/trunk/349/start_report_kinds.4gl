MAIN
DEFINE file_name CHAR(10)
DEFINE more_command CHAR(10)

	LET file_name = "xpta.rep"
	
	#LET more_command = "more"
	#Using -ifx-p 'more' waits for user input
	LET more_command = "cat"
	
	
  START REPORT simpleReport
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport

  START REPORT simpleReport TO "xpto.rep"
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport

  START REPORT simpleReport TO file_name
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport

  START REPORT simpleReport TO PRINTER
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport

  START REPORT simpleReport TO PIPE "cat" #"more"
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport

  START REPORT simpleReport TO PIPE more_command
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport
END MAIN

REPORT simpleReport()
  FORMAT EVERY ROW 
END REPORT
