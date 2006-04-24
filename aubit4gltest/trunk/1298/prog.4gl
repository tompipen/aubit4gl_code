
main

	options menu line first, form line first, prompt line last


	options comment line last
	call do_input("last")

	options comment line last-1
	call do_input("last-1")

	options comment line 10
	call do_input("toobig")

	options comment line 1
	call do_input("1")

	options comment line 2
	call do_input("2")



	options form line 3


	options comment line last
	call do_input("last")

	options comment line last-1
	call do_input("last-1")

	options comment line 10
	call do_input("toobig")

	options comment line 1
	call do_input("1")

	options comment line 2
	call do_input("2")

end main

function  do_input(a)
	define txt char(50)
define a char(20)
define b char(20)

let b=a clipped,"N"
		open window w1 at 2,2 with form "cline" attribute(reverse,blue) # border)
		input txt from t
		on key (control-b)
			call aclfgl_dump_screen( b )
		end input

		close window w1
let b=a clipped,"B"
		open window w1 at 2,2 with form "cline" attribute(reverse,blue,border)
		input txt from t
		on key (control-b)
			call aclfgl_dump_screen( b )
		end input
		close window w1

end function

