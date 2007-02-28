{**
 * @file
 * Compile error in EC, undefined function A4GL_int_out_byte().
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
database test1
main

#It is recomended that you use temp tables
#	create temp table abc(x char(10), y char(10))

#Use 	
#	call aclfgl_dump_screen("out")
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"

DEFINE w_byte BYTE
LOCATE w_byte IN MEMORY
SELECT bytefield into w_byte from bytetable

end main
