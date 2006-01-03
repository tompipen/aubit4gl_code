
MAIN
  MENU "Menu"
	  COMMAND "Hello" "Hello world"
		  DISPLAY "Hello"
		COMMAND "To Hello" "To hello world"
		  NEXT OPTION "Hello"
		COMMAND KEY('D') "To World" "To hello world"
		  NEXT OPTION "World"
		COMMAND "World"
		  DISPLAY "World"
	  COMMAND "Exit" "Exit the program"
		  EXIT MENU
	END MENU
END MAIN

