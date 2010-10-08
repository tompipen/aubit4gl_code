
MAIN
define a integer

initialize a to null

call disp( " blah"=0)
call disp( " blah"<0)
call disp( " blah">0)
call disp( " blah"+0)

call disp( " blah"=a)
call disp( " blah"<a)
call disp( " blah">a)

call disp( 0=" blah")
call disp( 0<" blah")
call disp( 0>" blah")
call disp( 0+" blah")

call disp( a=" blah")
call disp( a<" blah")
call disp( a>" blah")



call disp( " 1"=0)
call disp( " 1"<0)
call disp( " 1">0)
call disp( " 1"+0)

call disp( " 1"=a)
call disp( " 1"<a)
call disp( " 1">a)

call disp( 0=" 1")
call disp( 0<" 1")
call disp( 0>" 1")
call disp( 0+" 1")

call disp( a=" 1")
call disp( a<" 1")
call disp( a>" 1")

END MAIN

function disp(a)
define a integer
if a is null then
	display "Null"
	return
end if

if a then
	display "True"
else
	
	display "False"
end if
end function


