main
define  f1 	char(1)
define  f2 	char(1)
define  f3 	char(1)

        options input no wrap,
	accept key f36

	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "w"
	display form gen_form attribute (cyan)

	input by name f1,f2,f3 without defaults
	on key(f2)
		call press_enter()
	on key(f1)
		exit input

	on key(f3) exit program 0

	on key(return)
		exit program 1
		sleep 1

	on key(esc)
		error "esc pressed"
		sleep 1
	end input

end main

function press_enter()

	define	xans		char(1)

	open window genparmwin2 at 6, 6 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form2 from "w"
	display form gen_form2 attribute (cyan)

	prompt "Press Any..." clipped for char xans attribute(white)

	close window genparmwin2

end function
