{**
 * @file
 * Quick test of passing null strings to a function
 * @process TEST_GENERAL
 *}
 
main
call myfunc(NULL)
call myfunc("")
call myfunc(" ")
call myfunc("ABC")


end main

function myfunc(a)
define a char(20)
if a is null then
	display "a is null"
else
	display "a is ",a
end if
end function
