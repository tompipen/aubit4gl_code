# test for conactination of substrings of empty strings
# Expected output:
#   "Numbers:  123-456-789-00   Ok!"
#   "Empty:       -   -   -     Ok!"
#   "NULL:        -   -   -     Ok!"

MAIN
DEFINE 
    s1 CHAR(100)
   ,s2 CHAR(100)

    LET s1 = "12345678900"
    LET s2 = s1[1,3], "-", s1[4,6], "-", s1[7,9], "-", s1[10,11]
    IF s2 = "123-456-789-00" THEN
        DISPLAY "Numbers:  ", s2 CLIPPED, "   Ok!"
    ELSE
        DISPLAY "Numbers:  ", s2 CLIPPED, "   ERROR!"
    END IF

    LET s1 = ""
    LET s2 = s1[1,3], "-", s1[4,6], "-", s1[7,9], "-", s1[10,11]
    IF s2 = "   -   -   -" THEN
        DISPLAY "Empty:    ", s2 CLIPPED, "   Ok!"
    ELSE
        DISPLAY "Empty:    ", s2 CLIPPED, "   ERROR!"
    END IF

    INITIALIZE s1 TO NULL
    LET s2 = s1[1,3], "-", s1[4,6], "-", s1[7,9], "-", s1[10,11]
    IF s2 = "   -   -   -" THEN
        DISPLAY "NULL:     ", s2 CLIPPED, "   Ok!"
    ELSE
        DISPLAY "NULL:     ", s2 CLIPPED, "   ERROR!"
    END IF

END MAIN
