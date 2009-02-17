{**
 * @file
 * datetime with fraction, can't by assigned if many decimals
 * @process TEST_GENERAL
 *}
 
main
define w_d1 datetime year to minute,
       w_d2 datetime year to second,
       w_d3 datetime year to fraction,
       a_dt datetime year to fraction

let a_dt = '2009-02-17 12:09:45.123456'
let w_d1 = a_dt    display w_d1
let w_d2 = a_dt    display w_d2
let w_d3 = a_dt    display w_d3
let a_dt = '2009-02-17 12:09:45.123'
let w_d1 = a_dt    display w_d1
let w_d2 = a_dt    display w_d2
let w_d3 = a_dt    display w_d3
end main
