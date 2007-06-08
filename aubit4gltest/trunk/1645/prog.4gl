{**
 * @file
 * Use of large integer literals
 * Accept int8 as with 4GL 7.32
 * @process TEST_GENERAL
 *}
 
main
define a int8,
       b int
let a = 12345678901234
display a
let b = 12345678901234
display b
end main
