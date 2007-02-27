{**
 * @file
 * Some arithmetic calculation, with rounding of decimals
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
#database test1
main

#It is recomended that you use temp tables
#	create temp table abc(x char(10), y char(10))

#Use 	
#	call aclfgl_dump_screen("out")
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"

define w_a, w_b money, w_c decimal(4,2)
let w_b = 6.63
let w_c = 15
let w_a = w_b * w_c / 100
display w_a

end main
