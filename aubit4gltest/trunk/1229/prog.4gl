main
define a,b char(20)
	open window w1 at 1,1 with form "bibble"
	input a,b from fld1,fld2
	if a="  -12-34" and b="  -12-34" then
		exit program 0
	else
		exit program 1
	end if

end main
