MAIN 
 DEFINE i INT 
 START REPORT pru_repo TO "out" 
 FOR i = 1 TO 4 
 OUTPUT TO REPORT pru_repo() 
 END FOR 
 FINISH REPORT pru_repo 
END MAIN 
 
REPORT pru_repo() 
 OUTPUT 
 TOP MARGIN 0 
 BOTTOM MARGIN 0 
 LEFT MARGIN 0 
 PAGE LENGTH 10 
 
 FORMAT 
 PAGE HEADER 
 PRINT "lineno=", lineno 
 PRINT "---" 
 
 ON EVERY ROW 
 PRINT "lineno=", lineno 
END REPORT 
