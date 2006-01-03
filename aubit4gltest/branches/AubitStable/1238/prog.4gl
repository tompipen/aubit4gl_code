 
 
MAIN
 DEFINE i INT, f CHAR(12)
 LET f = "out.expected"
 --!LET f = "out"
 START REPORT repo TO FILE f
 FOR i = 0 TO 10 OUTPUT TO REPORT repo(i,0) END FOR
 FINISH REPORT repo
 END MAIN
 
 REPORT repo(i,j)
 DEFINE i,j INT, l_date date
 OUTPUT TOP MARGIN 0 BOTTOM MARGIN 0 PAGE LENGTH 1 LEFT MARGIN 0
 FORMAT
     ON LAST ROW
         LET l_date = mdy(2,3,2005)

         PRINT "date: ", l_date, "<<<"
         PRINT "last i ", i USING "##&.&&"
         PRINT "sum where NULL ..", sum(j) WHERE i > 20 USING "##&.&&"
         PRINT "sum where ZERO ..", sum(j) WHERE i < 20 USING "##&.&&"
         PRINT "date: ", l_date, "<<<",":"
         PRINT "last i ", i USING "##&.&&",":"
         PRINT "sum where NULL ..", sum(j) WHERE i > 20 USING "##&.&&",":"
         PRINT "sum where ZERO ..", sum(j) WHERE i < 20 USING "##&.&&",":"
END REPORT
