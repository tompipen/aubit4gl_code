MAIN 
 DEFINE l INT, f CHAR(15) 
#LET f = "out.expected" 
LET f = "out" 
 START REPORT pru_repo TO f 
 FOR l = 1 TO 15 
 OUTPUT TO REPORT pru_repo(l) 
 END FOR 
 FINISH REPORT pru_repo 
END MAIN 
 
REPORT pru_repo(l) 
 DEFINE l int 
 OUTPUT 
 TOP MARGIN 0 BOTTOM MARGIN 0 LEFT MARGIN 0 PAGE LENGTH 10 
 FORMAT 
 PAGE HEADER 
	PRINT "ph" 

 ON EVERY ROW 
 	NEED 2 LINES 
 	PRINT "l=", l ," ",lineno

 PAGE TRAILER 
	PRINT "pt1" 
	PRINT "pt2" 
	PRINT "pt3" 

END REPORT 
