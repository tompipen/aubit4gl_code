{**
 * @file
 * Assertion failure with invalid mdy() arguments (year = 0)
 * @process TEST_GENERAL
 *}
 
main
define w_d date, w_c char(10)
let w_d = mdy(1,1,0)
# if this let is commented the program runs ok!
let w_c = w_d
#
if w_d is null then exit program 0 end if
exit program 1
end main
