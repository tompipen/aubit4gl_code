main
define  f1 	char(3)
define  f2 	char(1)
define  f3 	char(1)

        options input no wrap

	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "w"
	display form gen_form attribute (cyan)

	input by name f1,f2,f3 #without defaults
	{
	before field f2
		next field next
	}
	on key(f1)
		exit input
	end input

call startlog("w.out")
call errorlog(f1)
end main
