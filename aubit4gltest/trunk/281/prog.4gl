main
define lv_a smallint

 let lv_a = null
 display "let .. = null"
 call f_test(lv_a)
 initialize lv_a to null
 display "initialize to .. null"
 call f_test(lv_a)
 display "direct call"
 call f_test(null)

end main

function f_test(v)
define v smallint

display "called f_test()"
if v is null then
 display ".. arg: NULL"
else
 display ".. arg NOT NULL"
 end if
end function
