main
define xdate date 
define xdttm datetime year to second 


let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) - 1 units day #OK 
display "0 ", xdate


let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) + 0 units day #Wrong. Result is NULL 

display "1 ",xdate




let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) + 1 units day #Wrong. Result is "30/12/2003", should be "31/12/2003". 

display "2 ",xdate
let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) + 2 units day #Wrong. Result is "01/02/2004", should be "01/01/2004". 

display "3 ",xdate
let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) + 0 units Month#Wrong. Result is "01/02/2004", should be "01/01/2004". 

display "4 ",xdate
let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) - 0 units Month #OK 

display "5 ",xdate
let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) + 0 units Month #Wrong. Result is NULL. 

display "6 ",xdate
let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) + 1 units Month #Wrong. Result is NULL. 

display "7 ",xdate
let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) + 0 units Year #Wrong. Result is "01/02/2004", should be "01/01/2004". 

display "8 ",xdate
let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) - 0 units Year #OK 

display "9 ",xdate
let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) + 0 units Year #Wrong. Result is NULL. 

display "10 ",xdate
let xdttm = "2003-12-30 00:00:00" 
let xdate = extend(xdttm, year to day) + 1 units Year #Wrong. Result is NULL. 

display "11 ",xdate

let xdttm="2003-11-30 00:00:00"
let xdate=xdttm+2 units day
display "12 ",xdate



let xdate = null 
let xdate = xdate + 1 units day # Originally - Seg Fault 
display "13 ",xdate

let xdttm = null 
let xdttm = xdttm + 1 units day # Originally - Seg Fault 
display "14 ",xdttm

let xdate = "12/31/2003" 
let xdate = xdate - 299 units day  #Originally - OK
display "15 ",xdate

let xdate = "12/31/2003" 
let xdate = xdate - 300 units day  # Originally - No change
display "16 ",xdate

let xdate = "12/31/2003" 
let xdate = xdate + 1 units month # Originally - OK 
display "17 ",xdate

let xdate = "12/31/2003" 
let xdate = xdate - 1 units month # Originally - xdate not change 
display "18 ",xdate

let xdate="31/31/3004"
display "19 ",xdate

let xdttm="20-30-30 11:22:33"
display "20 ",xdttm  # Very wrong

let xdttm="2003-30-30 11:22:33"
display "21 ",xdttm  # Invalid Month
end main
