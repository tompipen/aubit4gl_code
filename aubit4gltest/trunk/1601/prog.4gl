{**
 * @file
 * Decribe the test here
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

define a money
let a = -10234.56
display a using "(((,((&)", " ", a using "---,--&"
display a using "(((,((&.)", " ", a using "---,--&."
display a using "(((,((&.&)", " ", a using "---,--&.&"
end main
