
main
define  dt 	date
define  xdummy	smallint

	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	let dt = today

	display dt

	if testx() then let xdummy = 1 end if

	display dt


end main

function testx()
        define  xnumber         decimal(7,2)

	let xnumber = 1

        return  xnumber

end     function
