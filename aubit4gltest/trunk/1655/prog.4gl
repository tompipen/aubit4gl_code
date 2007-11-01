{**
 * @file
 * autonext mixed with multiline isn't going to next line
 * @process TEST_GENERAL
 *}
 
main
define input_str char(100), junk_str char(20)
open form test_form from "linetab"
display form test_form
input input_str, junk_str from test_field, other_field attribute(underline, reverse)
{! call aclfgl_dump_screen("out") }
end main
