main
define c integer
let c="3" + "2" display c
let c="3" * "2" display c
let c="2" / "2" display c
let c="3" - "2" display c
let c="2" - "3" display c
let c="2" ** "3" display c

if "abc" < "def" then
        display "OK"
else
        display "BAD"
end if

if "abcd" > "abc" then
        display "OK"
else
        display "BAD"
end if

if "abcd" <= "abc" then
        display "BAD"
else
        display "OK"
end if

end main

