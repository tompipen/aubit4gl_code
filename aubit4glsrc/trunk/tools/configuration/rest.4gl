
function change(x,id)
define x char(30)
define id integer
define oldval char(255)
define newval char(255)

open window shadow at 12,5 with 11 rows, 76 columns attribute(black,reverse)
open window w2 at 12,4 with form "change"  attribute(border,magenta,reverse,form line 1)

display "Variable : ",x,"" at 1,1 attribute (reverse,cyan)

let oldval=fgl_getenv(x)

if (oldval is null or oldval=" ") and x[1,5]="A4GL_" then
	let x=x[6,30]
	let oldval=fgl_getenv(x)
end if

let newval=oldval
let int_flag=false

display by name oldval
input newval without defaults from newval 
on key(f1) 
	exit input
on key(f2,control-b)
	call possible_values(id,newval) returning newval
	display newval to newval
end input 

close window w2
close window shadow

if int_flag=false then
	return newval
else
	return oldval
end if

end function
