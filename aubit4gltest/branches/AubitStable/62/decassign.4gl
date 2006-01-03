main
define n integer
initialize n to null

#call display_it1(n)

call display_it1(14)
call display_it1(-14)

#call display_it0(n)

call display_it0(14)
call display_it0(-14)


end main


function display_it1(n)
define n decimal(16,2)
define a1 decimal(5,1), 
a2 char(20), 
a3 char(100) 
let a1 = n
display "A:",a1
let a2=a1
display "B:",a2
let a2 = "def" 
let a3 = "C:",a1, "|", a2, "|" 
display a3 

end function


function display_it0(n)
define n decimal(16,2)
define a1 decimal(5,0), 
a2 char(20), 
a3 char(100) 
let a1 = n
display "D:",a1
let a2=a1
display "E:",a2
let a2 = "def" 
let a3 = "F:",a1, "|", a2, "|" 
display a3 

end function
