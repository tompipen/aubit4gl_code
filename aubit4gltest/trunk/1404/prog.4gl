define a array[20] of chaR(10)
main
open window w1 at 2,2 with form "m1"
call set_count(10)

input array a from srec2.*
on key(control-b) call disp_arr()
end  input

if arr_curr()!=2 then
	exit program 1
else
	exit program 0
end if
end main


function disp_arr()
define b array[20] of char(10)
call set_count(10)
display array b to srec1.*

end function
