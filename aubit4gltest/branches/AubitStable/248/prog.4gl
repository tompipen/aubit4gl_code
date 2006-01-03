main 
define num decimal(13,0), 
num2 decimal(13,2), 
x char(13) 

let num = 1234567890.0 
display "A:",num 
let num = 12345678901.0 
display "B:",num 
let x = "12345678901" 
let num = x 
display "C:",num 


let num = 1234567890.9 
display "D:",num 
let num = 12345678901.9 
display "E:",num 
let x = "12345678901.9" 
let num = x 
display "F:",num 

let num2 = 1234567890.0 
display "G:",num2
let num2 = 12345678901.0 
display "H:",num2
let x = "12345678901" 
let num2 = x 
display "I:",num2


let num2 = 1234567890.995
display "J:",num2 
let num2 = 12345678901.995
display "K:",num2 
let x = "12345678901.995" 
let num2 = x 
display "L:",num2


end main 
