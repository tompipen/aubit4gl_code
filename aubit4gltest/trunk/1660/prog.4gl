{**
 * @file
 * ERROR in input array goes to wrong following line 
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE ma ARRAY[20] OF record
            f1, f2, f3 int,
            trap char(1)
        END RECORD,
        i INT

OPEN WINDOW v_iarr AT 1,1 WITH FORM "iarrf1" 
CALL set_count(0)
INPUT ARRAY ma WITHOUT DEFAULTS FROM sa.* 
     AFTER ROW
        LET i = arr_curr()
        IF ma[i].f2 > ma[i].f1 THEN
            ERROR "f2 greater than f1"
            NEXT FIELD f1
        END IF
    BEFORE FIELD f3
        NEXT FIELD trap # this is a noentry field should move to next row
    ON KEY (CONTROL-W)
        {! call aclfgl_dump_screen("out") }
END INPUT
END MAIN
