main
define a datetime year to  second
define xdate date

whenever error continue

let a="2000-12-31 00:00:61"
	if a is null then
	display "a is null"
else
	display "a=",a
end if

let a="2000-12-31 00:60:00"
	if a is null then
	display "a is null"
else
	display "a=",a
end if


let a="2000-12-31 25:00:00"
	if a is null then
	display "a is null"
else
	display "a=",a
end if

let a="2001-02-29 25:00:00"
	if a is null then
	display "a is null"
else
	display "a=",a
end if

let a="2001-00-23 25:00:00"
	if a is null then
	display "a is null"
else
	display "a=",a
end if



let xdate = "12/01/2003" 
let xdate = xdate + 1 units day 

display "xdate=",xdate

end main
