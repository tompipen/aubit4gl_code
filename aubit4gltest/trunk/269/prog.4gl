database test1
main
define xupc char(13) 
create temp table abc(upc char(13)) 
select upc 
into xupc 
from abc 
where upc = 'x' 
display "Status=",status 

let xupc = "a 4gl statement" 
display "Status again=", status 
end main 


