{**
 * @file
 * Negative money variables print with default format position of
 * '-' is before '$'. should be after
 * @process TEST_GENERAL
 *}
 
main
define w_mo money
let w_mo = -0.17
display w_mo
end main
