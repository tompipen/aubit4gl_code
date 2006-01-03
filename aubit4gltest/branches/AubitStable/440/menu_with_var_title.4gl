
MAIN
	DEFINE menu_name CHAR(10)

	LET menu_name = "Menu"
  MENU menu_name
	  COMMAND "Exit" "Exit menu"
		  EXIT MENU
	  COMMAND "Hello" "Display hello"
		  DISPLAY "Hello"
	END MENU
END MAIN
