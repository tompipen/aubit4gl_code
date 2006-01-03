
MAIN
  START REPORT simpleReport
	OUTPUT TO REPORT simpleReport(1,"Hello")
	FINISH REPORT simpleReport
END MAIN

REPORT simpleReport(I,str)
	DEFINE i INTEGER
	define str char(10)
  FORMAT EVERY ROW 
END REPORT
