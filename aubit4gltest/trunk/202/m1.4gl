define  dt 	date
main
define  xdummy	smallint

	call startlog("m1.out")

	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "d3"
	display form gen_form attribute (cyan)

	let dt = "02/04/2003"
	input dt without defaults from sdt attribute(white)
	on key(f1)
		exit input
	end input
	call testx() returning xdummy



	input dt without defaults from sdt attribute(white)
	on key(f1)
		exit input
	end input
	call errorlog(dt)
	
end main

function testx()
        define  xnumber decimal(8,2)

	let xnumber = 1

        return  xnumber

end     function
