{**
 * @file
 * Check bound in screen record array
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE w record
           x char(10)
       end record,
       w_i int
OPEN WINDOW v1 AT 1,1 WITH FORM "disa" ATTRIBUTE(DIM)
FOR w_i = 1 TO 4 # in form only 3 rows,  on 4th should abort
    LET w.x = w_i USING "&"
    DISPLAY w.* TO sa_query[w_i].*
END FOR
CLOSE WINDOW v1
END MAIN
