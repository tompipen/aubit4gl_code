
function change(x)
define x char(30)
define oldval char(255)
define newval char(255)

open window shadow at 12,5 with 11 rows, 76 columns attribute(black,reverse)
open window w2 at 12,4 with form "change"  attribute(border,magenta,reverse,form line 1)

display "Variable : ",x,"" at 1,1 attribute (reverse,cyan)

let oldval=fgl_getenv(x)
let newval=oldval
let int_flag=false

display by name oldval
input newval without defaults from newval 
on key(f1) 
	exit input
end input 

close window w2
close window shadow

if int_flag=false then
	return newval
else
	return oldval
end if

end function
