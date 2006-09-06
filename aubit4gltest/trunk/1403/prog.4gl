define a array[20] of chaR(10)
main
open window w1 at 2,2 with form "m1"
call set_count(10)

display array a to srec2.*
on key(control-b) call disp_arr()
end display

if arr_curr()!=2 then
	exit program 1
else
	exit program 0
end if
end main


function disp_arr()
define b array[20] of char(10)
call set_count(10)
input array b from srec1.*
end input

end function
