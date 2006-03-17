MAIN
define a datetime year to second
let a=current year to second
display a

if a > date("10/10/2004") then
	display "Pass"
else
	display "Fail1"
	exit program 1
end if

if  date("10/10/2004")<a then
	display "Pass"
else
	display "Fail2"
	exit program 1
end if


if status!=0 then 
	exit program 1 
end if



END MAIN
