MAIN
DEFINE file_name CHAR(10)
DEFINE more_command CHAR(10)

	LET file_name = "xpta.rep"
	
	#LET more_command = "more"
	#Using -ifx-p 'more' waits for user input
	LET more_command = "cat"
	

display "1"
	
  START REPORT simpleReport
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport

display "2"
  START REPORT simpleReport TO "xpto.rep"
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport

display "3"
  START REPORT simpleReport TO file_name
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport

display "4"
  START REPORT simpleReport TO PRINTER
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport

display "5"
  	START REPORT simpleReport TO PIPE "cat"
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport

display "6"
  START REPORT simpleReport TO PIPE more_command
	OUTPUT TO REPORT simpleReport()
	FINISH REPORT simpleReport
display "7"
END MAIN

REPORT simpleReport()
  FORMAT EVERY ROW 
END REPORT
