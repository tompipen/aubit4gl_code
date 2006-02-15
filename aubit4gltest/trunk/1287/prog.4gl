main

#open window win1 at 2,3 with 24 rows, 80 columns
   #attribute (border, red)
open form test2 from "test2"
display form test2

start report r1 to "out"
call do_input()
finish report r1

end main

function do_input()
define
   i_arr   array[10] of record
      col1   char(07),
      col2   char(07),
      col3   char(07),
      col4   char(07),
      col5   char(07)
   end record
define ac,acount integer
define b char(20)

options insert key control-e,
        delete key control-f

let i_arr[1].col1 = "field11"
let i_arr[1].col2 = "field12"
let i_arr[1].col3 = "field13"
let i_arr[1].col4 = "field14"
let i_arr[1].col5 = "field15"

let i_arr[2].col1 = "field21"
let i_arr[2].col2 = "field22"
let i_arr[2].col3 = "field23"
let i_arr[2].col4 = "field24"
let i_arr[2].col5 = "field25"
let i_arr[3].col1 = "field31"
let i_arr[3].col2 = "field32"
let i_arr[3].col3 = "field33"
let i_arr[3].col4 = "field34"
let i_arr[3].col5 = "field35"
let i_arr[4].col1 = "field41"
let i_arr[4].col2 = "field42"
let i_arr[4].col3 = "field43"
let i_arr[4].col4 = "field44"
let i_arr[4].col5 = "field45"

call set_count(4)

options insert key control-e,
        delete key control-f

input array  i_arr without defaults from s_arr.*

before row
   let ac=arr_curr()
   let acount=arr_count()
   let b="before row : ",ac using "<<<<&"," ",acount using "<<<<&"
   output to report r1( b )

after row
   let ac=arr_curr()
   let acount=arr_count()
   let b="after row : ",ac using "<<<<&"," ",acount using "<<<<&"
   output to report r1( b )
   open window win3 at 2,3 with 22 rows, 74 columns
   message "new window 2"
   close window win3

before insert
   let ac=arr_curr()
   let acount=arr_count()
   let b="before insert : ",ac using "<<<<&"," ",acount using "<<<<&"
   output to report r1( b)

after insert
   let ac=arr_curr()
   let acount=arr_count()
   let b="after insert : ",ac using "<<<<&"," ",acount using "<<<<&"
   output to report r1( b)

before field col2
   output to report r1( "before col2")

after field col2
   output to report r1( "after col2")
   open window win2 at 2,3 with 22 rows, 74 columns
   message "new window 1"
   close window win2

after field col3
   next field col5

end input

let acount=arr_count()
display "Arr_count=",acount
sleep 1
if acount!=4 then
	exit program 1
else
	exit program 0
end if
end function

report r1 (a)
define a char(20)
format
on every row 
print a
end report
