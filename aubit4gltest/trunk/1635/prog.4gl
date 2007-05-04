{**
 * @file
 * negative intervals not calculated subtracting datetimes
 * @process TEST_GENERAL
 *}
 
main
define w_dif interval day to minute,
       w_di, w_df datetime year to second

let w_di = "2007-05-03 12:40:05"
let w_df = "2007-05-04 15:15:08"
let w_dif = w_di - w_df
display w_dif
let w_dif = w_df - w_di
display w_dif
end main
