
main
	START EXTERNAL FUNCTION [1] FOR inc_by_1, inc_by_2, all_done
end main

function inc_by_1(a)
define a integer
display "SERVER Got       : ",a
let a=a+1
display "SERVER Returning : ",a
return a
end function

function inc_by_2(a)
define a integer
display "SERVER Got       : ",a
let a=a+2
display "SERVER Returning : ",a
return a
end function

function all_done()
exit program 0
end function
