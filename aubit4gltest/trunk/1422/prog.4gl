define astring char(2047)

main
	let astring="123456"

        call myfunc2() returning astring[2] 

	if astring!="1X3456" THEN
		display "FAILED 1: ",astring clipped
		exit program 1
	end if

	let astring="123456"


        call myfunc2a() returning astring[2]
	if astring!="1X3456" THEN
		display "FAILED 2"
		exit program 1
	end if


	let astring="123456"

        call myfunc2a() returning astring[3,4]

	if astring!="12XY56" THEN
		display "FAILED 3: ",astring clipped
		exit program 1
	end if

	DISPLAY "SUCCESS"
end main

function myfunc2()
	return "X"
end function


function myfunc2a()
	return "XY"
end function
