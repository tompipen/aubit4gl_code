main 
define i int 
for i = 1 to 2
	call testrpt(i) 
end for 
end main 

function testrpt(i) 
define i int 

start report rpt to 'zero.out' 
if i != 2 then 
output to report rpt() 
end if 
finish report rpt 
end function 

report rpt() 
format 
page header 
print "header" 

on every row 
print "abc" 
end report 
