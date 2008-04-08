main
define a char(20)
define b integer
define d integer
let a=" - "
let b=1
call bibble("1") returning a[b]
if a!="h-" then
	display "Bad"
	exit program 1
end if


let b=3
call bibble("1") returning a[b]
if a!="h-h" then
	display "Bad"
	exit program 1
end if
let b=2
let d=4
call bibble2("1") returning a[b,d]
if a!="hxxx" then
	display "Bad"
	exit program 1
end if


display "Good"


end main


function bibble(c)
define c char(20)
return "h"
end function

function bibble2(c)
define c char(20)
return "xxx"
end function

