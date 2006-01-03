main
call test1()
call test2()
end main


function test1()
define a char(10)
define c char(20)
define b integer
let b=1
let a="####&"
let c=b using "####& ",":"
display "c using ####& string   -", c
let c=b using a,":"
display "c using ####& variable -", c
end function




function test2()
define num_x int 
define string_x char(200) 

let num_x=24 

let string_x=num_x using "john && ",num_x using "j &&" 

display string_x clipped
display "john 24 j 24" 
end function

