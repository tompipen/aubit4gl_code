MAIN 
 DEFINE w_date DATE 
 --!call aclfgl_setenv("DBDATE","DMY4/")
 --!call aclfgl_setenv("A4GL_DBDATE","DMY4/")
 LET w_date = "24/12/2004" DISPLAY w_date USING "dd/mm/yyyy" 
 LET w_date = "24/12/04" DISPLAY w_date USING "dd/mm/yyyy" 
 LET w_date = "24122004" DISPLAY w_date USING "dd/mm/yyyy" 
 LET w_date = "241204" DISPLAY w_date USING "dd/mm/yyyy" 
 LET w_date = mdy(1,1,2004) 
 IF w_date < "01/02/2004" THEN DISPLAY "OK" ELSE DISPLAY "Fail!" END IF 
 IF w_date < "01/02/04" THEN DISPLAY "OK" ELSE DISPLAY "Fail!" END IF 
 IF w_date < "01022004" THEN DISPLAY "OK" ELSE DISPLAY "Fail!" END IF 
 IF w_date < "010204" THEN DISPLAY "OK" ELSE DISPLAY "Fail!" END IF 
END MAIN 
