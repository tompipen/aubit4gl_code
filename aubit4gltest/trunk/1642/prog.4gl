{**
 * @file
 * String to double , fails if trailing alpha chars
 * @process TEST_GENERAL
 *}
 
main
define w_i int, w_d double precision, w_r char(10)
let w_r = "123 aa"
let w_i = w_r
display w_i
let w_d = w_r
display w_d
end main
