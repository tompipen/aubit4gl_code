DATABASE test1

MAIN

DEFINE l_parm INT
DEFINE w_fech CHAR(20),
       w_file CHAR(50)

{	   
define 	lv_str char(40)
	
	let lv_str=1 using "<<<<<", ",", 0 using "<<<<<"
	display ">",lv_str clipped,"<"
	let lv_str=1 using "<<<<<", ",", 0 using "<<<<&"
	display ">",lv_str clipped,"<"

	
	
	exit program	   
}	   
	   
	   
	   
    CREATE TEMP TABLE testunlo (f1 int, f2 char(10))
    INSERT INTO testunlo VALUES (1, "a")
    INSERT INTO testunlo VALUES (2, "b")
    LET l_parm = 1
    UNLOAD TO "/tmp/testunlo2.unl" SELECT * FROM testunlo WHERE f1 > l_parm
	
	
END MAIN



