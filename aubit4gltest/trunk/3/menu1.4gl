main
	menu "Hello"
		command "Yes"
			display "Yes" at 4,1

		command "No"
			display "No " at 4,1

		command "Exit"
			display "Exit " at 4,1
			exit menu
	end menu
	sleep 1
end main
