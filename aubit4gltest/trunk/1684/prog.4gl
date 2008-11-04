{**
 * @file
 * FR. Truncate datetime in form field
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE	w_a datetime year to second
LET w_a = "2008-06-26 10:17:01"
OPEN WINDOW v_tele AT 1,1 WITH FORM "timest" ATTRIBUTE(DIM)
DISPLAY w_a TO f1
DISPLAY w_a TO f2
DISPLAY w_a TO f3
DISPLAY w_a TO f4
DISPLAY w_a TO f5
DISPLAY w_a TO f6
DISPLAY w_a TO f7
call aclfgl_dump_screen("out")
CLOSE WINDOW v_tele
END MAIN
