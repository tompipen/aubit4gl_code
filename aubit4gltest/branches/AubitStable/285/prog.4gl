main
call bibble(null)

end main

function bibble(a)
define a char(20)
if a is null then
	display "A is null"
	exit program 0
else
	display "A is not null"
	exit program 1
end if
end function
