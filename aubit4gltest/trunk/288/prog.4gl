MAIN 
 MENU "Test" 
 	BEFORE MENU 
 		SHOW OPTION ALL 

 	COMMAND "Aaaaa" "Option A" 
 		ERROR "Option A" 

 	COMMAND "Bbbbb" "Option B" 
 		ERROR "Option B" 

 	COMMAND KEY (ESC,E) "End" "End of program" 
 		EXIT MENU 

	command key(f5)
		call aclfgl_dump_screen("out")
		exit program
 	COMMAND KEY (F6) 
 		ERROR "Option F6" 

 	COMMAND KEY (F7) 
 		ERROR "Option F7" 
 END MENU 
END MAIN
