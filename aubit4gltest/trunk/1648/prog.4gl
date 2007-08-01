{**
 * @file
 * Rounding problems decimals and moneys
 * @process TEST_GENERAL
 *}
 
main
# Witch decimals works fine
# define neto, impu decimal,
define neto, impu money,
       poim decimal(5,2)

let neto = 33.3
let poim = 15.0
let impu = neto * poim / 100
if impu <> 5 then display "bad ", impu exit program 1 end if
display impu
end main
