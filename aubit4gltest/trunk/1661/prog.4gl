{**
 * @file
 * CLEAR FORM erase part of ERROR LINE if switch WINDOW
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE w_a, w_b INT
OPTIONS ERROR LINE 3
OPEN WINDOW v_f1 AT 1,1 WITH FORM "errclrf1" 
INPUT BY NAME w_a WITHOUT DEFAULTS
OPEN WINDOW v_f2 AT 1,1 WITH FORM "errclrf2" 
INPUT BY NAME w_b WITHOUT DEFAULTS
ERROR "This should survive a clear form "
CURRENT WINDOW v_f1
CLEAR FORM
sleep 2
{! call aclfgl_dump_screen("out") !}
END MAIN
