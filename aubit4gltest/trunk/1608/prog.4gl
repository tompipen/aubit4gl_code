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
 
main
define input_str char(100), junk_str char(1)
open form test_form from "linetab"
display form test_form
input input_str, junk_str from test_field, other_field attribute(underline, reverse)
#Use 	
{! call aclfgl_dump_screen("out") }
end main
