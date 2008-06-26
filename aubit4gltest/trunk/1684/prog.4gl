{**
 * @file
 * Check generated datetime schema with adbschema
 * @process TEST_GENERAL
 *}
 
DATABASE test1

MAIN
DEFINE	w_a like tbltest.dt
CREATE TEMP TABLE temptbl (id int, b datetime year to minute)
INSERT INTO temptbl VALUES (1, "2008-06-26 10:17")
OPEN WINDOW v_tele AT 1,1 WITH FORM "timest" ATTRIBUTE(DIM)
SELECT b INTO w_a FROM temptbl WHERE id = 1
DISPLAY w_a TO f1
DISPLAY w_a TO f2
DISPLAY w_a TO f3
DISPLAY w_a TO f4
call aclfgl_dump_screen("out")
CLOSE WINDOW v_tele
END MAIN
