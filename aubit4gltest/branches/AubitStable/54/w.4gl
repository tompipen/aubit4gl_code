main
define  f1 	char(1)
define  f2 	char(1)
define  f3 	char(1)

        options input no wrap
	call startlog("w.out")
	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "w"
	display form gen_form attribute (cyan)

	input by name f1,f2,f3 without defaults
	before field f2
		next field next

	on key(f1)
		if infield(f1) then call errorlog("field f1") end if
		if infield(f2) then call errorlog("field f2") end if
		if infield(f3) then call errorlog("field f3") end if
		exit input
	end input
	call errorlog("Exited via noentry")

end main
