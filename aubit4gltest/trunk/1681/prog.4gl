{**
 * @file
 * Compile error: two variables same name diferent type in a report conflict 
 *                A4GL_push_long
 * @process TEST_GENERAL
 *}
 
DATABASE test1

MAIN
display "none"
END MAIN

REPORT pushint_repo1(r)
DEFINE r RECORD
	      fech DATE,
	      peso DECIMAL(12,3)
	  END RECORD,
	  w_tpeso DECIMAL(12,3)

ORDER BY r.fech 

FORMAT
    ON EVERY ROW
       LET w_tpeso = w_tpeso + r.peso  

    AFTER GROUP OF r.fech
       PRINT "group ", w_tpeso USING "##,###,###.&&" 
END REPORT

REPORT pushint_repo2() 
DEFINE w_tpeso INT # This int in repo2 conflict with decimal in repo1
                   # compile error

FORMAT
    ON EVERY ROW
        PRINT "every row"
END REPORT
