main
display "STarting"
menu "WIN Hello test"
	before menu 
		hide option "Close Form"
    	command "Window" "Open a new window"
		display "Window"
		open window w1 at 10,30 with 3 rows,20 columns attribute(border)
		display "   Hello  World   " at 2,2 attribute(cyan,reverse)
        	sleep 2
		close window w1

	command "Form" "Open a form "
		display "Form"
        	open window w2 at 2,2 with form "form-gui" attribute(border)

        	display "This is a line in the form" to s_info[1].info_line
        	display "This is line 2 in the form" to s_info[2].info_line

		show option "Close Form"
		hide option "Form"
		enable cal

	command "Close Form" "Close the form"
		close window w2
		hide option "Close Form"
		show option "Form"


	command "Exit" "Exit demo"
		display "Exit"
        exit menu
end menu

message "Exiting.."
end main


