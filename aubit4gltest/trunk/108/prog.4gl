DATABASE test1

MAIN

DEFINE l_parm INT
DEFINE w_fech CHAR(20),
       w_file CHAR(50)

#Testing for invalid file name

    CREATE TEMP TABLE testunlo (f1 int, f2 char(10))
    INSERT INTO testunlo VALUES (1, "a")
    INSERT INTO testunlo VALUES (2, "b")

    LET w_fech = date
    LET w_file = "testunlo.unl.", "09/" # w_fech[1,3]
    DISPLAY "unload to ", w_file
    UNLOAD TO w_file SELECT * FROM testunlo
    DISPLAY "unload completed"
	
END MAIN

