main 
 define d decimal(10,2), 
 n decimal(10,0) 
 
 let d = abc(18.50) 
 display "Retn :", d 
 let d = abc(0.90) 
 display "Retn :", d 
 let d = abc(8.50) 
 display "Retn :", d 
 let d = abc(9.49) 
 display "Retn :", d 
 let d = abc(9.59) 
 display "Retn :", d 
 let d = abc(9.99) 
 display "Retn :", d 
 end main 
 
 function abc (d) 
 define d decimal(10,2), 
 n decimal(10,0) 
 let n = d 
 display "" display "Fcn:d=",d, " n=",n 
 return n 
 end function 
