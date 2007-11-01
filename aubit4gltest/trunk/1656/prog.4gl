{**
 * @file
 * multiline field takes value only from first line
 * @process TEST_GENERAL
 *}
 
main
define input_str char(100), junk_str char(20)
open form test_form from "linetab"
display form test_form
input input_str, junk_str from test_field, other_field attribute(underline, reverse)
if input_str <> "a b c d e f g h i j k l m n o p q r s t u v w x y z" then
    display "bad ", input_str
    exit program 1
end if
exit program 0
end main
