{**
 * @file
 * Test if C can call a 4gl function.
 *}

FUNCTION menu_function()
  MENU "A MENU"
	  COMMAND "First" "First option"
	  COMMAND "Exit" "Exit menu"
		  EXIT MENU
	END MENU
END FUNCTION
