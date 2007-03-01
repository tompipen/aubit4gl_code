{**
 * @file
 * Use of \TAB , \UP & \DOWN in a multiline field
 * should move like in I(tm)-4GL
 *
 *  TAB: move to next 8 position tab stop, 
 *     if no more space in current line then
 *         go to first column of next line
 *         if no more lines in multiline then
 *             go to first column of next field
 *  DOWN: move to same column of next line
 *     if no more lines then
 *         go to first column of next field
 *  UP: move to same column of previous line
 *     if no previous lines then
 *         go to first column of previous field
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
#database test1
main

#It is recomended that you use temp tables
#	create temp table abc(x char(10), y char(10))

define input_str char(100), junk_str char(1)
open form test_form from "linetab"
display form test_form
input input_str, junk_str from test_field, other_field
#Use 	
{! call aclfgl_dump_screen("out") }
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"


end main
