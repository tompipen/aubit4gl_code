{**
 * @file
 * Decribe the test here
 * @process TEST_GENERAL
 *}
 
main

 DEFINE 
 o_float SMALLFLOAT, 
 o_decimal DECIMAL, 
 o_money MONEY 
 
 LET o_float = 1 
 LET o_decimal = 2 
 LET o_money = 3 
 DISPLAY '------assignment from constant------' 
 DISPLAY o_float 
 DISPLAY '------assignment from decimal------' 
 LET o_float = o_decimal 
 DISPLAY o_float 
 DISPLAY '------assignment from money------' 
 LET o_float = o_money 
 DISPLAY o_float 

end main
