DATABASE test1

MAIN

DEFINE l_parm INT
DEFINE w_fech CHAR(20),
       w_file CHAR(50)

    CREATE TEMP TABLE testunlo (f1 int, f2 char(10))
    INSERT INTO testunlo VALUES (1, "a")
    INSERT INTO testunlo VALUES (2, "b")
    LET l_parm = 1
    UNLOAD TO "./testunlo2.unl" SELECT * FROM testunlo WHERE f1 > l_parm
	
	
END MAIN

