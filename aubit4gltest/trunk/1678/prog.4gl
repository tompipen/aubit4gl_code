{**
 * @file
 * Compile only : CASE inside page header last for ever
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
DEFINE  h SMALLINT,
        r_refe CHAR(20)

FORMAT
   PAGE HEADER
      CASE h
	 WHEN 1 LET r_refe = "uno"
	 WHEN 2 LET r_refe = "dos"
	 WHEN 3 LET r_refe = "tres"
      END CASE

   ON EVERY ROW
      PRINT COLUMN   1, "every"

END REPORT
