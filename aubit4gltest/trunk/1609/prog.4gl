{**
 * @file
 * Load of a text file without EOL fails to load
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
database test1
main
CALL noeol_proc("noeol.prn")
CALL noeol_proc("witheol.prn")
END MAIN

FUNCTION noeol_proc(p_file)
DEFINE  p_file, w_all, w_f1 CHAR(80)
CREATE TEMP TABLE tempchar (f1 char(80))
LOAD FROM p_file INSERT INTO tempchar
LET w_all = NULL
DECLARE c_desc CURSOR FOR SELECT f1 FROM tempchar
FOREACH c_desc INTO w_f1
    LET w_all = w_all CLIPPED, " ", w_f1
END FOREACH
FREE c_desc
DISPLAY p_file CLIPPED, "->", w_all CLIPPED
DROP TABLE tempchar
END FUNCTION
