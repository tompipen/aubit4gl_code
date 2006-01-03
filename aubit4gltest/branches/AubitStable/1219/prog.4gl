MAIN 
 DEFINE i INT, f CHAR(12) 
 LET f = "out.expected" 
 --!LET f = "out" 
 START REPORT repo TO FILE f 
 FOR i = 0 TO 10 OUTPUT TO REPORT repo(i) END FOR 
 FINISH REPORT repo 
END MAIN 
 
REPORT repo(i) 
 DEFINE i INT, d1, d2 DECIMAL(16,2) 
 OUTPUT TOP MARGIN 0 BOTTOM MARGIN 0 PAGE LENGTH 1 LEFT MARGIN 0 
 FORMAT 
 ON EVERY ROW 
 LET d1 = 10 ** i 
 LET d2 = d1 * -1 
 PRINT COLUMN 1, i USING "#&", 
 COLUMN 10, d1 USING "-,---,---,---.&&", 
 COLUMN 30, d2 USING "-,---,---,---.&&" 
 ON LAST ROW 
 PRINT "sum where ..", sum(i) WHERE i > 20 USING "##&.&&" 
END REPORT 
