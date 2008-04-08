{**
 * @file
 * Arithmetic negative int/decimal -> smallint
 * @process TEST_GENERAL
 *}
 
main
define w_sald int,
       w_prom decimal(6,1),
       w_dias smallint

let w_sald = -174
let w_prom = 375.0
let w_dias = w_sald / w_prom
if w_dias = 0 then  
	display "ok" exit program 0
else   
	display "bad:", w_dias
	 exit program 1
end if
end main
