
main
define a array[20] of char(20)
defer interrupt
open window x0 at 2,2 with 20 rows,70 columns attribute(border)
open form v1 from "v1"
display form v1
call set_count(0)
display "INP1" at 1,1
input array a from srec1.*
	on key(control-b)
		call dosubwin()
end input


let a[1]="Hello"
let a[2]="World"
call set_count(2)
display "DISP1" at 1,1
display array a to srec1.*
	on key(control-b)
		call dosubwin()
end display

exit program 99
end main

function dosubwin()
define b char(20)
	open window x1 at 3,3 with form "v2" attributes(border)
	input b from a
	close window x1
	current window is screen
	sleep 1
end function
