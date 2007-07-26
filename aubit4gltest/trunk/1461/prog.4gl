DEFINE  # global to this module
       texto1,
       texto2     CHAR(800)
MAIN

#define confirm char

        OPTIONS
                INPUT WRAP,
        MESSAGE LINE 1,
        PROMPT LINE 23,
                COMMENT LINE 23,
                ERROR LINE 24,
        ACCEPT KEY CONTROL -N 

        LET texto1 = "xxxxxxxxxxxxxxxxxxxxxxxxx xxxxxxxxxxxxxxxxxxxxx xxxxxxxxxxxxxxxxxx xxxxxxxxxxxxxx",
                     "yyyyyyyyyyyyyyyyyyyyyyyyy yyyyyyyyyyyyyyyyyyyyy yyyyyyyyyyyyyyyyyy yyyyyyyyyyyyyy"

        LET texto2 = "aaaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaa",
                     "bbbbbbbbbbbbbbbbbbbbbbbbb bbbbbbbbbbbbbbbbbbbbb bbbbbbbbbbbbbbbbbb bbbbbbbbbbbbbb"

        START REPORT listado
           
        OUTPUT TO REPORT listado (texto1, texto2)
 
        FINISH REPORT listado

END MAIN

REPORT listado (r_texto1, r_texto2)

        DEFINE r_texto1,
               r_texto2    CHAR(800)

        
        OUTPUT
           REPORT TO "out"
           LEFT MARGIN 0
           TOP MARGIN 0
           BOTTOM MARGIN 0
           PAGE LENGTH 80

        FORMAT 
           ON EVERY ROW

              PRINT COLUMN 10, r_texto1 WORDWRAP RIGHT MARGIN 87 #CLIPPED WORDWRAP RIGHT MARGIN 87
              PRINT COLUMN 10, r_texto2 WORDWRAP RIGHT MARGIN 87 #CLIPPED WORDWRAP RIGHT MARGIN 87
END REPORT
