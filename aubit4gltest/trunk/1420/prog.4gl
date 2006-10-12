    DATABASE test1
 
 MAIN
 DEFINE w_prod INT,
         w_copi SMALLINT,
         i, j SMALLINT
 
 START REPORT errline_list TO "errline.out"
 FOR w_copi = 1 TO 2
    FOR w_prod = 1 TO 33
        OUTPUT TO REPORT errline_list(w_prod, w_copi)
    END FOR
 END FOR
 FINISH REPORT errline_list
 END MAIN
 
 REPORT errline_list(r_prod, r_copi)
 DEFINE r_prod INT,
         r_copi int,
         w_line float
 
 OUTPUT
     TOP MARGIN 0
     LEFT MARGIN 0
     BOTTOM MARGIN 0
     PAGE LENGTH 66
 
 ORDER BY r_copi, r_prod
 
 FORMAT
     PAGE HEADER
         PRINT "page ",pageno
 
     BEFORE GROUP OF r_copi
         SKIP TO TOP OF PAGE
 
     AFTER GROUP OF r_prod
         let w_line = lineno
         display "after prod=", r_prod, " line=", w_line
         IF lineno > 56 THEN
             SKIP 4 LINES
             PRINT COLUMN 20, "CONTINUA SIGUIENTE HOJA"
             let w_line = lineno
             display "continue line=", w_line
             SKIP TO TOP OF PAGE
         END IF
         PRINT COLUMN 3, r_prod
         PRINT
 END REPORT
