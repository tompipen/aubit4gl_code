{**
 * @file
 * MID 939
 * printing a long_text_with_spaces with wordwrap, only prints last part
 * @process TEST_GENERAL
 *}
 
database test1
main
DEFINE vc varchar(80),
        w_file CHAR(50)
LET w_file = "out.expected"
{! LET w_file = "out" }
START REPORT prog_report TO FILE w_file
LET vc = "long_text_without_spaces_only_prints_last_line"
OUTPUT TO REPORT prog_report(vc)
FINISH REPORT prog_report
END MAIN

REPORT prog_report(vc)
DEFINE vc varchar(80)

OUTPUT LEFT MARGIN 0 TOP MARGIN 0 BOTTOM MARGIN 0 PAGE LENGTH 5

FORMAT
   ON EVERY ROW
       PRINT vc WORDWRAP RIGHT MARGIN 15
END REPORT
