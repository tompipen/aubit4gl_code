main
define a char(20)
defer interrupt
open window x0 at 2,2 with 20 rows,70 columns attribute(border)
open form v1 from "v1"
display form v1
input a from a
	on key(f2)
		call dosubwin()
end input



end main

function dosubwin()
define b char(20)
	open window x1 at 3,3 with form "v2" attributes(border)
	input b from a
	close window x1
	current window is screen
	sleep 1
end function
