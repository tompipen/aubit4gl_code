{**
 * @file
 * This is a test for the unload problems reported by Fernando Ortiz
 * @process TEST_GENERAL
 *}
 
database test1


MAIN

DEFINE l_parm INT
    CREATE TEMP TABLE testunlo (f1 serial, f2 decimal,
                                f3 money, f4 date,
                                f5 int)
    INSERT INTO testunlo (f2, f3, f4, f5) VALUES (1, 1, today, 1)
    INSERT INTO testunlo (f2, f3, f4, f5) VALUES (2, 2, today, 2)
    LET l_parm = 1
    DISPLAY "UNLOAD START"
    UNLOAD TO "out" SELECT * FROM testunlo WHERE f1 > l_parm
    DISPLAY "UNLOAD completed"
    exit program 0
END MAIN
