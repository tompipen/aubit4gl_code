main
define abc char(20)
	menu "Hello"
		before menu
			display "Before" at 5,1
			call aclfgl_dump_screen("menu_bef.out")
		
		command "Yes"
			display "Yes" at 3,1

		command "No"
			display "No"  at 4,1

		command "Exit"
			exit menu
	end menu

	call aclfgl_dump_screen("menu.out")

	clear screen

	prompt "Enter 123" for abc
		on key(f2)
			display "F2" at 10,10
	end prompt

	if abc!="123" then
		display "Bad:",abc at 5,1
	else
		display "Good" at 5,1
	end if

	call aclfgl_dump_screen("prompt.out")

	open window w0 at 10,10 with 10 rows,10 columns attribute(border)
	open window w1 at 2,2 with form "form" attribute(border)

	call aclfgl_dump_screen("open_window_form.out")
	input abc from a
		on key (f3)
			display "F3 hit" at 3,1
		after input
			display "AfterInp" at 3,10
	end input
	display "abc=",abc clipped  at 1,1
	display "abc=",abc  at 2,1
	call aclfgl_dump_screen("input.out")

end main

