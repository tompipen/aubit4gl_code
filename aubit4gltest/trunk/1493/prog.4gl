main
define p_loads array[10] of record
	a,b,c integer
end record

let p_loads[1].a=1
let p_loads[1].b=2
let p_loads[1].c=3
open window w1 at 1,1 with form "f1"

display by name p_loads[1].a thru  p_loads[1].c

end main
