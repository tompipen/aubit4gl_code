{**
 * @file
 * \down in input array should go to first field next row
 * @process TEST_GENERAL
 *}
 
DEFINE ma ARRAY[20] OF record
            t1, t2 CHAR(5)
        END RECORD,
        k SMALLINT

MAIN
OPEN WINDOW v_iarr AT 1,1 WITH FORM "lastkey" ATTRIBUTE(DIM)
LET k = 1
CALL set_count(k)
INPUT ARRAY ma WITHOUT DEFAULTS FROM sa_head.* ATTRIBUTE(BOLD)
    ON KEY(CONTROL-B)
        EXIT INPUT
END INPUT
LET k = arr_count()
IF k <> 4 THEN DISPLAY "k=", k EXIT PROGRAM 1 END IF
IF ma[1].t1 <> 1 THEN DISPLAY "t1[1]=", ma[1].t1 EXIT PROGRAM 1 END IF
IF ma[1].t2 <> " " THEN DISPLAY "t2[1]=", ma[1].t2 EXIT PROGRAM 1 END IF
IF ma[2].t1 <> 2 THEN DISPLAY "t1[2]=", ma[2].t1 EXIT PROGRAM 1 END IF
IF ma[2].t2 <> " " THEN DISPLAY "t2[2]=", ma[2].t2 EXIT PROGRAM 1 END IF
IF ma[3].t1 <> 3 THEN DISPLAY "t1[3]=", ma[3].t1 EXIT PROGRAM 1 END IF
IF ma[3].t2 <> " " THEN DISPLAY "t2[3]=", ma[3].t2 EXIT PROGRAM 1 END IF
END MAIN
