main 
define xdttm datetime year to second 
define xdt date 
let xdt = today + 1 
#OK 
let xdttm = xdt 
#OK 
let xdttm = today 
#conversion error 30089 
let xdttm = today+1
end main 
