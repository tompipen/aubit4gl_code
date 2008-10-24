{**
 * @file
 * Autonext in input array
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE w array[5] of record a int end record
OPEN WINDOW v1 AT 1,1 WITH FORM "anext" 
CALL set_count(0)
INPUT ARRAY w FROM sa.*
CLOSE WINDOW v1
IF w[1].a <> 123 THEN EXIT PROGRAM 1 END IF
IF w[2].a <> 456 THEN EXIT PROGRAM 2 END IF
END MAIN
