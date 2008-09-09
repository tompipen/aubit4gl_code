{**
 * @file
 * Simple arithmetic test
 * @process TEST_GENERAL
 *}
 
main
define a, b, c, d decimal(4,2)
let a = 7.00
let b = 0.10
let c = a + b
let d = a + 0.10
if c <> d then
    display "c=", c, ",d=",d
    exit program 1
end if
display "ok"
end main
