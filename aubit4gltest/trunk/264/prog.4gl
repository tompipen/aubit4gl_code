main 
 define n integer 
 define x char(10) 
 define i smallint 
 
 let n = 1 
 let x = "1" 
 for i = 1 to 10
 if n = x then 
 display x," Length is ", i, ":equal" 
 else 
 display x," Length is ", i, ":not equal" 
	exit program 1
 end if 
 let x = "0", x 
 end for 
exit program 0
 end main 
