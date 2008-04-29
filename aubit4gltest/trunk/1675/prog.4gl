{**
 * @file
 * HL_TUI : Construct, field with inavlid can continue, at end
 *          null string as condition
 * @process TEST_GENERAL
 *}
 
DATABASE test1
MAIN
DEFINE w_cons CHAR(80)
OPEN WINDOW v_cheq AT 1,1 WITH FORM "rcheqf1" ATTRIBUTE(DIM)
CONSTRUCT w_cons ON polcfpol, polcncta, polcscta FROM s_opci.*
	ON KEY(CONTROL-B)
            display "ok, ^Y"
	    EXIT PROGRAM 1 # expected result
    BEFORE CONSTRUCT
	DISPLAY "", "", ""
	    TO s_opci.polcfpol, s_opci.polcncta, s_opci.polcscta
END CONSTRUCT
CLOSE WINDOW v_cheq
display "bad, end construct"
EXIT PROGRAM 0 # Error shouldn't reach this point
END MAIN
