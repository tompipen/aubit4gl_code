globals "g1.4gl"

define module1 integer
define mrec record
	aa char(10)
end record
main
	define local1 integer
define lrec record
	aa char(10)
end record


let lrec.aa="Hello"
let local1=1
let mrec.aa="Hello"
let module1=1

let grec.aa="Hello"
let global1=1

let int_flag=false


display today

end main


