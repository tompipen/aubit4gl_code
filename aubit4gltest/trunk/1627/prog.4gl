{**
 * @file
 * If in and input array execute another input array, the second takes the 
 * value of arr_count() from the first
 * @process TEST_GENERAL
 *}
 
main
define wa1 array[5] of record
        a char(10),
        t char(1)
       end record,
       wa2 array[3] of record d char(10) end record,
       i, l1, l2 int

open form f_form from "arrcount"
display form f_form
for i = 1 to 3
    let wa1[i].a = "the ", i
    let wa1[i].t = " "
end for
call set_count(3)
input array wa1 without defaults from sa1.*
    before row
       let i = arr_curr()
    after field t
       if wa1[i].t = "X" then
           call set_count(0)
           input array wa2 without defaults from sa2.*
           let l2 = arr_count()
       end if
end input
close form f_form
let l1 = arr_count()
if l1 <> 3 then exit program 1 end if
if l2 <> 1 then exit program 2 end if
exit program 0
end main
