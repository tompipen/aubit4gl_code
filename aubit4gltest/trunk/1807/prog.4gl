{**
 * @file
 * Format date in an input array -> 'error in field'
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE w array[10] of record
    d1, d2 date
    end record,
    w_i int

OPEN WINDOW v_win AT 3,10 WITH FORM "testwin" ATTRIBUTE(BORDER)
CALL set_count(0)
INPUT ARRAY w WITHOUT DEFAULTS FROM sa.*
CLOSE WINDOW v_win
LET w_i = arr_count()
IF w_i = 0 THEN DISPLAY "no rows!" EXIT PROGRAM -1 END IF
IF w[1].d1 IS NULL OR w[1].d1 <> '01/01/01' THEN 
    DISPLAY "1" 
    EXIT PROGRAM 1 
END IF
IF w[1].d2 IS NULL OR w[1].d2 <> '02/02/02' THEN 
    DISPLAY "2" 
    EXIT PROGRAM 2 
END IF
DISPLAY "0"
END MAIN
