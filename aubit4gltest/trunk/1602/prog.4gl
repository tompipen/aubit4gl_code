{**
 * @file
 * MID 904
 * Converting string to int/smallint -> generate NULL if not valid number
 * @process TEST_GENERAL
 *}
 
main
define w_ch char(4), w_in int, w_sm smallint
let w_ch = "abcd"
let w_in = w_ch
if w_in is null then display "null" else display w_in end if
let w_ch = "efgh"
let w_sm = w_ch
if w_sm is null then display "null" else display w_sm end if
end main
