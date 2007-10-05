{**
 * @file
 * Check bigint limits
 * @process TEST_GENERAL
 *}
 
main
define w_bi1, w_bi2, w_a bigint

let w_bi1 = -9223372036854775807 
let w_bi2 =  9223372036854775807
let w_a = w_bi1 * w_bi2
display w_bi1, " * ", w_bi2, " = ", w_a
let w_a = w_bi2 * 10
display w_bi2, " * 10 = ", w_a
let w_a =  w_bi2 + 1
display w_bi2, " + 1 = ", w_a
let w_a =  w_bi2 + 10
display w_bi2, " + 10 = ", w_a
let w_a =  w_bi1 - 1
display w_bi1, " - 1 = ", w_a
let w_a = w_bi1 - 10
display w_bi1, " - 10 = ", w_a
end main
