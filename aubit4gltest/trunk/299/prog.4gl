MAIN 
 DEFINE wa_ls ARRAY[20] OF RECORD 
 trap CHAR(1), 
 refe char(10) 
 END RECORD, 
 i, k SMALLINT 
 
 LET k = 3 
 FOR i = 1 TO k 
 LET wa_ls[i].refe = "val ", i USING "<<", "!!" 
 END FOR 
 OPEN WINDOW v_win AT 3,10 WITH FORM "testwin" ATTRIBUTE(BORDER) 
 CALL set_count(k) 
 DISPLAY ARRAY wa_ls TO sa_ls.* ATTRIBUTE(DIM, CURRENT ROW DISPLAY="REVERSE") 
 	ON KEY(ESCAPE) 
 		LET int_flag = TRUE 
	on key(f10) 
			call aclfgl_dump_screen("out_1")
	on key(f11) 
			call aclfgl_dump_screen("out_2")
 EXIT DISPLAY 
 END DISPLAY 
 CLOSE WINDOW v_win 
END MAIN 
