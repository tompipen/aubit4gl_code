{**
 * @file
 * Quick test of display at with nulls (1)
 * @process TEST_GENERAL
 *}
 
main

display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 1,1
display "HELLO","" at 1,1
call aclfgl_dump_screen("out")

end main
