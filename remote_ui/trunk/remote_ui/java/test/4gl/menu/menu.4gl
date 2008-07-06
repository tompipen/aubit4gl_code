{**
 * 4gl to test the menu instruction in the context of the remote UI
 *}

MAIN
  MENU "Options"
    COMMAND "First command" "First description"
      DISPLAY "First command choosed"
    COMMAND "Exit menu" "Exit description"
      EXIT MENU
    COMMAND KEY CONTROL-W
      DISPLAY "Control w hitted"
  END MENU
END MAIN

