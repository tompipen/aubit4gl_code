{**
 * @file
 * Menu command name changed in before menu clause
 * In behalf of Gustavo Rosso
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE w_a char(10)
LET w_a = "original"
MENU "Menu"
    BEFORE MENU
       LET w_a = "changed"
    COMMAND w_a
	call aclfgl_dump_screen("out")
        EXIT MENU
END MENU
END MAIN
