main
define  f1 	decimal(6,0)
define  f2 	char(1)
define  f3 	char(1)

        options input wrap

	open window genparmwin at 8, 2 with 16 rows, 46 columns
		attribute (green, border)
	display "XXXX" at 1,1
	display "XXXX" at 2,1
	display "XXXX" at 3,1
	display "XXXX" at 4,1
	open form gen_form from "w1"
	display form gen_form attribute (cyan)

	let f1= 1234
	let f2= "x"

	input by name f1,f2 without defaults
	on key(f1)
		exit input
	end input

	sleep 1
	if f1=1234 then
		exit program 0
	else
		
		exit program 1
	end if
end main
