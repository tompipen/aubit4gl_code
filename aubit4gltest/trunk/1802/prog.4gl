{**
 * @file
 * Convertion from interval to char, truncation
 * @process TEST_GENERAL
 *}
 
main
define a_fech datetime year to fraction(5)
define a_c1 char(10)
define a_c2 char(13)
define a_c3 char(16)
define a_c4 char(19)
define a_c5 char(22)

define a_b1 char(11)
define a_b2 char(14)
define a_b3 char(17)
define a_b4 char(18)

let a_fech = "2009-03-02 09:58:01.12345"
let a_c1 = a_fech
let a_c2 = a_fech
let a_c3 = a_fech
let a_c4 = a_fech
let a_c5 = a_fech

let a_b1 = a_fech
let a_b2 = a_fech
let a_b3 = a_fech
let a_b4 = a_fech

display "a_fech= ", a_fech
display "a_c1  = ", a_c1
display "a_c2  = ", a_c2
display "a_c3  = ", a_c3
display "a_c4  = ", a_c4
display "a_c5  = ", a_c5

display "a_b1  = ", a_b1
display "a_b2  = ", a_b2
display "a_b3  = ", a_b3
display "a_b4  = ", a_b4

end main
