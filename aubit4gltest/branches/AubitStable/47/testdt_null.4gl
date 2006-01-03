main
define xdt date 
define xdttm datetime year to second 
define i interval day(3) to day
let xdttm = null 

let xdt = extend(xdttm, year to day) #OK, returns null 

if xdt is null then
	display "Its null"
else
	display xdt
end if


let xdt = extend(xdttm, year to day) - 1 units day #seg fault,shoud return null 

if xdt is null then
	display "Its null"
else
	display xdt
end if


let i=1 units day

display "i=",i


let xdttm="1970-02-13 11:22:00"
let xdt=xdttm - i

if xdt is null then
	display "Its null"
else
	display xdt
end if


end main
