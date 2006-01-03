main
define  f1 	decimal(13,2)
define  f2 	char(1)
define  f3 	char(1)
define  xans 	char(1)


        options input no wrap,
		insert key f36

	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "w3"
	display form gen_form attribute (cyan)

	input by name f1,f2,f3 without defaults
	before input
		prompt "Press Any..." for char xans attribute(white) 
		let f1 = 100.00
		display by name f1
		prompt "Press Any..." for char xans attribute(white) 
		let f1 = -100.00
		display by name f1
	on key(f1)
		exit input
	end input

end main


