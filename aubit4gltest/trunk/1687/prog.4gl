{**
 * @file
 * HL_TUI: segfault construct erasing all content in field
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE lv_cons CHAR(100)
OPEN WINDOW v_tele AT 1,1 WITH FORM "ctelef1" ATTRIBUTE(DIM)
CONSTRUCT BY NAME lv_cons ON telefech, telehora
CLOSE WINDOW v_tele
END MAIN
