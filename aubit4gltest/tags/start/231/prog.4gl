main
define a array[20] of char(20)
define b integer
open form f from "v"
display form f

for b=1 to 8
	let a[b]="Line ", b using "<<<"
end for

call set_Count(8)
display array a to srec1.*
on key(f1)
	call aclfgl_dump_screen("out")
end display

end main
