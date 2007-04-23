{**
 * @file
 * Memory corruption, repeating declare cursor with binding, pre-prepared
 * @process TEST_GENERAL
 *}
 
DATABASE test1

MAIN
DEFINE w_prep CHAR(80)
CREATE TEMP TABLE testtab (p1 int, p2 int)
INSERT INTO testtab values (2,2)
LET w_prep = "SELECT p1, p2 FROM testtab WHERE p1 = ? AND p2 = ? "
PREPARE ex_entr FROM w_prep
CALL entmentr_pinta(2, 2)
CALL entmentr_pinta(2, 2)
CALL entmentr_pinta(2, 2)
FREE ex_entr
END MAIN

FUNCTION entmentr_pinta(p_p1, p_p2)
DEFINE p_p1, p_p2, w_p1, w_p2 INT
DECLARE c_entr CURSOR FOR ex_entr
OPEN c_entr USING p_p1, p_p2
FETCH c_entr INTO w_p1, w_p2
FREE c_entr
RETURN
END FUNCTION
