{**
 * @file
 * FINISH REPORT without OUTPUT TO REPORT
 * @process TEST_GENERAL
 *}
 
DATABASE test1
MAIN
define w_a int
create temp table tbl1 (a int)
START REPORT pagranal_entr TO "file"
DECLARE c_entr CURSOR FOR
   SELECT a FROM tbl1 WHERE a > 100
FOREACH c_entr INTO w_a
    OUTPUT TO REPORT pagranal_entr(w_a)
END FOREACH
FREE c_entr
FINISH REPORT pagranal_entr
END MAIN

REPORT pagranal_entr(a)
DEFINE a INT
OUTPUT
   LEFT MARGIN 00 TOP MARGIN 0 BOTTOM MARGIN 0 PAGE LENGTH 1
ORDER BY a
FORMAT
   ON EVERY ROW
      PRINT a
END REPORT
