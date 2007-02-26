{**
 * @file
 * Converting string to int/smallint -> generate NULL if not valid number
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

define w_ch char(4), w_in int, w_sm smallint
let w_ch = "abcd"
let w_in = w_ch
if w_in is null then display "null" else display w_in end if
let w_ch = "efgh"
let w_sm = w_ch
if w_sm is null then display "null" else display w_sm end if

end main
