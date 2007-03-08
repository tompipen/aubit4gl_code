{**
 * @file
 * Memory corruption, content of a variable get NULL after printing a varchar
 *  with wordwrap right margin
 *
 * If variable define varchar(255) works fine, onlyfails if defined like table
 *
 * If worwrap removed also works fine
 *
 * @process TEST_GENERAL
 *}
 
database test1
main
DEFINE r RECORD
          vc LIKE temptable.vc,
          s SMALLINT
        END RECORD,
        w_file CHAR(50)
LET w_file = "out.expceted"
{! LET w_file = "out" }
START REPORT prog_report TO FILE w_file
LET r.vc = "test data"
FOR r.s = 1 TO 3
   OUTPUT TO REPORT prog_report(r.*)
END FOR
FINISH REPORT prog_report
END MAIN

REPORT prog_report(r)
DEFINE r RECORD
          vc LIKE temptable.vc,
          s SMALLINT
        END RECORD

OUTPUT LEFT MARGIN 0 TOP MARGIN 0 BOTTOM MARGIN 0 PAGE LENGTH 1

ORDER EXTERNAL BY r.s
FORMAT
   BEFORE GROUP OF r.s
      print "before s =", r.s
   AFTER GROUP OF r.s
      print "after s =", r.s
      IF r.s = 1 THEN
         PRINT COLUMN 5, "varchar:",
               COLUMN 21, r.vc  WORDWRAP RIGHT MARGIN 60
      END IF
   ON EVERY ROW
      print "every row s =", r.s
END REPORT
