{**
 * @file
 * display array inside input array, segfault in HL_TUI
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
for i = 1 to 2
    let wa2[i].d = "number ", i
end for
call set_count(3)
input array wa1 without defaults from sa1.*
    before row
       let i = arr_curr()
    after field t
       if wa1[i].t = "X" then
           call set_count(2)
           display array wa2 to sa2.*
       end if
end input
close form f_form
exit program 0
end main
