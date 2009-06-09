{**
 * @file
 * Invalid conversion, function month()
 * @process TEST_GENERAL
 *}
 
main
define lv_mes char(10)
define lv_dt datetime year to minute
define lv_d date
let lv_d = mdy(0,6,2009)
let lv_mes = elemes(month(lv_d))
display lv_mes
let lv_dt = "2009-06-09 08:40"
let lv_mes = elemes(month(lv_dt))
display lv_mes
end main

FUNCTION elemes(p_mes)
DEFINE p_mes SMALLINT,
       w_mes CHAR(12)

LET w_mes = NULL
CASE p_mes
    WHEN  1 LET w_mes = "ENERO"
    WHEN  2 LET w_mes = "FEBRERO"
    WHEN  3 LET w_mes = "MARZO"
    WHEN  4 LET w_mes = "ABRIL"
    WHEN  5 LET w_mes = "MAYO"
    WHEN  6 LET w_mes = "JUNIO"
    WHEN  7 LET w_mes = "JULIO"
    WHEN  8 LET w_mes = "AGOSTO"
    WHEN  9 LET w_mes = "SEPTIEMBRE"
    WHEN 10 LET w_mes = "OCTUBRE"
    WHEN 11 LET w_mes = "NOVIEMBRE"
    WHEN 12 LET w_mes = "DICIEMBRE"
END CASE
RETURN w_mes
END FUNCTION
