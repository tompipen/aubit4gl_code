define lv_bad integer
main
let lv_bad=0
call test("X",0)
call test("W",1)

call test1("abc","a*",1)
call test1("abc","*c",1)
call test1("abc","*b*",1)

call test1("abc","*b",0)
call test1("abc","b*",0)

call test1("abc","a[bc]*",1)
if lv_bad then
	exit program 1
else
	exit program 0
end if

end main


function test(c,r)
define c char(10)
define r integer
define e integer

if c matches "[QW]" then 
	let e=1
	
else 
	let e=0
end if 

if e=r then
	display "OK"
else
	let lv_bad=1
	display "NOT OK (test) - ",c
end if

end function

function test1(c,m,r)
define c char(3)
define m char(10)
define  r integer
define e integer
if c matches m then
	let e=1
else
	let e=0
end if

if e=r then
	display "OK"
else
	let lv_bad=1
	display "NOT OK (test2) -",c," ",m
end if
end function
