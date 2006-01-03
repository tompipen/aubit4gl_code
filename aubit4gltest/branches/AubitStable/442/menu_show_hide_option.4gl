
MAIN
  MENU "Menu"
	  COMMAND "Show hello"
		   SHOW OPTION "Hello"
		COMMAND "Hello"
		   ERROR "Hello"
	  COMMAND "Hide hello"
		   HIDE OPTION "Hello"
	  COMMAND "Exit" "Exit menu"
		  EXIT MENU
	END MENU
END MAIN
