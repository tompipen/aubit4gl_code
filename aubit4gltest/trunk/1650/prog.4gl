{**
 * @file
 * display a decimal to a 'small' field fails if beteween 0 and 1
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE lv_dens decimal(8,6)
OPEN WINDOW v_win AT 3,10 WITH FORM "dispocr" 
LET lv_dens = 0.9141
display lv_dens to d_dens
call aclfgl_dump_screen("out")
sleep  1
CLOSE WINDOW v_win
END MAIN
