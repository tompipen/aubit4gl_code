{**
 * @file
 * segfault with some forms
 * @process TEST_GENERAL
 *}
 
DATABASE test1
MAIN
DEFINE w_acep  CHAR(500)
OPEN WINDOW v_cheq AT 1,1 WITH FORM "rcheqf1" ATTRIBUTE(DIM)
CONSTRUCT w_acep ON polcfpol, polcncta, polcscta FROM s_opci.*
	ON KEY(ESC)
	    LET int_flag = TRUE
	    EXIT CONSTRUCT
    BEFORE CONSTRUCT
	DISPLAY "", "", ""
	    TO s_opci.polcfpol, s_opci.polcncta, s_opci.polcscta
END CONSTRUCT
CLOSE WINDOW v_cheq
END MAIN
