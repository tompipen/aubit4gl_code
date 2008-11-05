{**
 * @file
 * arithmethic with 12 decimals
 * @process TEST_GENERAL
 *}
 
main
define prec decimal(20,12),
       unid decimal(15,3),
       impo decimal(12,2)

let prec = 8.205333851012
let unid = 583374
let impo = prec * unid
if impo <> 4786778.43 then display impo exit program 1 end if
end main
