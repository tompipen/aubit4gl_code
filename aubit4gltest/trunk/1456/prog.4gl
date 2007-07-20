#database cassens

main

open window win1 at 2,3 with 24 rows, 70 columns
   attribute (border, red)
options delete key control-b
open form test2 from "test2"
display form test2

call do_input()

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

call set_count(2)

input array i_arr without defaults from s_arr.*

before row
   message "before row"

after row
   message "after row"
   open window win3 at 2,3 with 22 rows, 74 columns
   message "new window 2"
   close window win3

before insert
   message "before insert"

after insert
   message "after insert"

before field col2
   message "before col2"

after field col2
   message "after col2"
   open window win2 at 2,3 with 22 rows, 74 columns
   message "new window 1"
   close window win2

after field col3
   next field col5

end input

end function
