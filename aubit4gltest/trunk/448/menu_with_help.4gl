

MAIN
	OPTIONS HELP FILE "help.iem"
  MENU "Menu"
		COMMAND "Hello" HELP 100
		  ERROR "Hello"
	  COMMAND "Exit" "Exit the menu"
		  EXIT MENU
	END MENU
END MAIN
