
main


options menu line 1
menu "Close"
	command key(control-b) call aclfgl_dump_screen("a0")
	command "Menu"
		exit menu
end menu

options menu line 2

menu "Close"
	command key(control-b) call aclfgl_dump_screen("a1")
	command "Menu"
		exit menu
end menu

open window w1 at 1,1 with 10 rows,40 columns 

options menu line 1
menu "Close"
	command key(control-b) call aclfgl_dump_screen("a2")
	command "Menu"
		exit menu
end menu

options menu line 2

menu "Close"
	command key(control-b) call aclfgl_dump_screen("a3")
	command "Menu"
		exit menu
end menu

close window w1

open window w1 at 12,2 with 10 rows,40 columns attribute(border)

options menu line 1
menu "Close 1"
	command key(control-b) call aclfgl_dump_screen("a4")
	command "Menu"
		exit menu
end menu

options menu line 2

menu "Close 2"
	command key(control-b) call aclfgl_dump_screen("a5")
	command "Menu"
		exit menu
end menu

options menu line 3

menu "Close 3"
	command key(control-b) call aclfgl_dump_screen("a6")
	command "Menu"
		exit menu
end menu


options menu line 8
open window menu_win at 3, 2 with 13 rows, 78 columns attribute(green, border,menu line 2)
menu "Close"
	command key(control-b) call aclfgl_dump_screen("a7")
	command "Menu"
		exit menu
end menu



end main
