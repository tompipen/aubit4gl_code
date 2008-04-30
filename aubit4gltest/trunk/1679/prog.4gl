{**
 * @file
 * Compile error : FOR ... PRINT ;  END FOR : IN page trailer fails
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE i SMALLINT
START REPORT liqusemi_repor TO "out"
FOR i = 1 TO 10
    OUTPUT TO REPORT liqusemi_repor(i)
END FOR
FINISH REPORT liqusemi_repor
END MAIN

REPORT liqusemi_repor(h)
DEFINE  i, h SMALLINT

FORMAT
   PAGE HEADER
      PRINT "Header"
      FOR i = 1 TO 10
         PRINT "_";
      END FOR
      PRINT

   ON EVERY ROW
      PRINT COLUMN   1, "every"

   PAGE TRAILER
      FOR i = 1 TO 10
         PRINT "_";
      END FOR
      PRINT
      PRINT "Footer"
END REPORT
