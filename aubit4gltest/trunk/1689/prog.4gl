{**
 * @file
 * DBDATE=DMY2/ Input field format="DMY4/", invalid dates
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE d1, d2, d3, d4, d5 DATE
OPEN WINDOW v_f AT 1,1 WITH FORM "a" ATTRIBUTE(DIM)
INPUT BY NAME d1, d2, d3, d4, d5
call aclfgl_dump_screen("out")
CLOSE WINDOW v_f
END MAIN
