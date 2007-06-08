{**
 * @file
 * Long numeric literal can't be procesed nor stored in double
 * @process TEST_GENERAL
 *}
 
main
define w_dbl double precision, w_dec decimal(16,0), w_c char(14)
let w_dbl = 12345678901234
display "dbl=", w_dbl
let w_dec = 12345678901234
display "dec=", w_dec
let w_c = "12345678901234"
let w_dbl = w_c
display "dbl=", w_dbl
let w_dec = w_c
display "dec=", w_dec
end main
