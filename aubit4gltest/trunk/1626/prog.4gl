{**
 * @file
 * moving (without editing) for fields with content larger than display width
 * should preserve full content
 * @process TEST_GENERAL
 *}
 
main
define wa array[8] of record obs varchar(255) end record,
       i, l int

options next key control-a,
        previous key control-b
open form f_ivch from "ivch"
display form f_ivch
let wa[1].obs = "12345678"
let wa[2].obs = "123456789"
let wa[3].obs = "1234567890"
call set_count(3)
input array wa without defaults from sa.*
close form f_ivch
display wa[1].obs
display wa[2].obs
display wa[3].obs

let l = length(wa[1].obs)
if l <> 8 then exit program 1 end if
let l = length(wa[2].obs)
if l <> 9 then exit program 2 end if
let l = length(wa[3].obs)
if l <> 10 then exit program 3 end if
exit program 0
end main
