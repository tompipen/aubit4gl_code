main
#	sleep 1
display "STarting"
menu "Hello test"
    command "window" "Open a new window"
	display "Window"
		open window w1 at 10,30 with 3 rows,20 columns attribute(border)
		display "   Hello  World   " at 2,2 attribute(cyan,reverse)
        sleep 2
		close window w1

	command "form" "Open a form "
	display "Form"
        	open window w2 at 2,2 with form "form" attribute(border)

        display "This is a line in the form" to s_info[1].info_line
		sleep 2
        display "This is line 2 in the form" to s_info[2].info_line
        sleep 2
		close window w2


	command "exit"
	display "Exit"

        exit menu
end menu

message "Exiting.."
end main



