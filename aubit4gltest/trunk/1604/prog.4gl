{**
 * @file
 * Some arithmetic calculation, with rounding of decimals
 * @process TEST_GENERAL
 *}
 
main
define w_a, w_b money, w_c decimal(4,2)
let w_b = 6.63
let w_c = 15
let w_a = w_b * w_c / 100
display w_a
end main
