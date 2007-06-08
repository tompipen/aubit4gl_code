{**
 * @file
 * String to various numeric types , fails if trailing alpha chars
 * @process TEST_GENERAL
 *}
 
main
define w_i int, 
       w_dp double precision, 
       w_sf smallfloat, 
       w_m money,
       w_d decimal,
       w_si smallint,
       w_r char(10)
let w_r = "123 aa"
let w_i = w_r
display "int=", w_i
let w_dp = w_r
display "double=", w_dp
let w_sf = w_r
display "smallfloat=", w_sf
let w_m = w_r
display "money=", w_m
let w_d = w_r
display "decimal=", w_d
let w_si = w_r
display "smallint=", w_si
end main
