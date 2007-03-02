{**
 * @file
 * ERror concatenating substrings, mantis bug 916
 * @process TEST_GENERAL
 *}
 
main
define w_a char(15),
       w_b char(30)
let w_a = "94-91-72-2810-1"
display w_a
LET w_b = w_a[1,2]
display w_b
LET w_b = w_a[1,2], w_a[4,5]
display w_b
LET w_b = w_a[1,2], w_a[4,5], w_a[7,8], w_a[10,13], w_a[15,15]
display w_b
let w_a = w_b
display w_a
end main
