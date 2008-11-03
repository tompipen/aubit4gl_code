{**
 * @file
 * FR. Truncate datetime in form field
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE	w_a datetime year to minute
LET w_a = "2008-06-26 10:17"
OPEN WINDOW v_tele AT 1,1 WITH FORM "timest" ATTRIBUTE(DIM)
DISPLAY w_a TO f1
DISPLAY w_a TO f2
DISPLAY w_a TO f3
DISPLAY w_a TO f4
call aclfgl_dump_screen("out")
CLOSE WINDOW v_tele
END MAIN
