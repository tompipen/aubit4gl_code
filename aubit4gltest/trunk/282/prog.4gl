database  test1

main

start report report1 to  "test.txt"
output to report report1 ("CH","  S0093")
finish report report1

end main

report report1 (a, b)
define a,b char(20)
define str char(255)
define lv_r record like testtable.*
format
first page header

let str = "select * from testtable"
display "first page header"
prepare open_customer_s from str
declare open_customer cursor for open_customer_s


on every row
	display "On every row"
   open open_customer 
   fetch open_customer into lv_r.*
   print column   1, a,b,lv_r.*

end report
