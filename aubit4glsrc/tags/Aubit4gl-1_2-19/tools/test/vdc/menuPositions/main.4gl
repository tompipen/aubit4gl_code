MAIN
IF aclfgl_sendfile_to_ui("menu.4st") THEN END IF

OPEN WINDOW menu AT 2,2 WITH FORM "form" ATTRIBUTES(STYLE = "right")

MENU "Menu Position"
   COMMAND "Top"
      CALL open_window_top()
   COMMAND "Bottom"
      CALL open_window_bottom()
   COMMAND "Left"
      CALL open_window_left()
   COMMAND "Right"
      CALL open_window_right()
   COMMAND "Exit"
      EXIT MENU
END MENU

END MAIN


FUNCTION open_window_left()

OPEN WINDOW w1 AT 2,2 WITH FORM "form" ATTRIBUTES(STYLE = "left")

MENU "EXIT"
	COMMAND "Command 1"
	EXIT MENU
	COMMAND "Command 2"
	EXIT MENU
   COMMAND "EXIT"
      EXIT MENU
END MENU

CLOSE WINDOW w1
  
END FUNCTION

FUNCTION open_window_right()

OPEN WINDOW w1 AT 2,2 WITH FORM "form" ATTRIBUTES(STYLE = "right")

MENU "EXIT"
	COMMAND "Command 1"
	EXIT MENU
	COMMAND "Command 2"
	EXIT MENU
   COMMAND "EXIT"
      EXIT MENU
END MENU

CLOSE WINDOW w1
  
END FUNCTION

FUNCTION open_window_top()

OPEN WINDOW w1 AT 2,2 WITH FORM "form" ATTRIBUTES(STYLE = "top")

MENU "EXIT"
	COMMAND "Command 1"
	EXIT MENU
	COMMAND "Command 2"
	EXIT MENU
   COMMAND "EXIT"
      EXIT MENU
END MENU

CLOSE WINDOW w1
  
END FUNCTION

FUNCTION open_window_bottom()

OPEN WINDOW w1 AT 2,2 WITH FORM "form" ATTRIBUTES(STYLE = "bottom")

MENU "EXIT"
	COMMAND "Command 1"
	EXIT MENU
	COMMAND "Command 2"
	EXIT MENU
   COMMAND "EXIT"
      EXIT MENU
END MENU

CLOSE WINDOW w1
  
END FUNCTION
