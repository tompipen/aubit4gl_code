{**
 * @file
 * cant't leave from display array in HL_TUI
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE lra_call ARRAY[20] OF RECORD
           id int,
           name char(10)
       END RECORD,
       l_k SMALLINT

OPEN WINDOW v_st AT 4, 10 WITH FORM "disphl" 
FOR l_k = 1 TO 5
    LET lra_call[l_k].id = l_k 
    LET lra_call[l_k].name = "Desc"
END FOR
CALL set_count(5)
DISPLAY ARRAY lra_call TO sa_call.* 
     ON KEY(CONTROL-B)
         DISPLAY "bad"
          EXIT PROGRAM 1
END DISPLAY
CLOSE WINDOW v_st
display "ok"
EXIT PROGRAM 0
END MAIN
