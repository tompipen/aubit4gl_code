{**
 * @file
 * This is a test for the unload problems reported by Fernando Ortiz
 * @process TEST_GENERAL
 *}
 
database test1


MAIN

DEFINE l_parm INT
define lv_d date

    let lv_d=mdy(2,13,1970)

    CREATE TEMP TABLE testunlo (f1 serial, f2 decimal,
                                f3 money, f4 date,
                                f5 int,f6 char(10))
    INSERT INTO testunlo (f2, f3, f4, f5,f6) VALUES (1, 1, lv_d, 1,"Hello")
    INSERT INTO testunlo (f2, f3, f4, f5,f6) VALUES (2, 2, lv_d, 2,"  ")
    LET l_parm = 1
    DISPLAY "UNLOAD START"
    UNLOAD TO "out" SELECT * FROM testunlo WHERE f1 > l_parm
    DISPLAY "UNLOAD completed"
    exit program 0
END MAIN
