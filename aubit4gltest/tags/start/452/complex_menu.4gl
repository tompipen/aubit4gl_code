
MAIN
  MENU "Menu"
		BEFORE MENU 
		  HIDE OPTION "Hello"
		COMMAND "Hello" "Hello world"
		  DISPLAY "Hello world" AT 10,1
			NEXT OPTION "Exit"
		COMMAND "World" "World"
		  DISPLAY "World" AT 10,1
			NEXT OPTION "Exit"
		COMMAND KEY ("V")
		  DISPLAY "Key V" AT 10,1
		COMMAND "Hide"
		  HIDE OPTION "Hello", "World"
		COMMAND "Show"
		  SHOW OPTION "Hello", "World"
			CONTINUE MENU
	  COMMAND "Exit" "Exit menu"
		  EXIT MENU
	END MENU
END MAIN
