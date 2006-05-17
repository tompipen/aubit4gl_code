main

define lv_str char(80)
define lv_substr char(10)

let lv_str="The quick brown fox jumps over the lazy dog. 1234567890"
initialize lv_substr to null

--OK this works
let lv_substr=lv_str[3]
if lv_substr="e" then
  display "OK the third character is e"
else
  display "ERR the third character is NOT e"
end if

--OK this works, too
let lv_substr=lv_str[3,3]
if lv_substr="e" then
  display "OK the third character is e"
else
  display "ERR the third character is NOT e"
end if

--But this does not work
case 
  when lv_str[3]='e'
    display "OK the third character is e"
  when lv_str[5,5]="q"
    display "OK the fifth character is q"
  when lv_str[5,9]="quick"
    display "OK the second word is quick"
  otherwise
    display "ERR searching characters/words NOT found"
end case

end main
