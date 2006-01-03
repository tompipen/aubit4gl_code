{**
 * @file
 * Display some Portuguese Characters because they  are displayed in reverse
 * with HL_TUI.
 * @process TEST_GENERAL
 *}
 
main
  DEFINE lv_answer CHAR

  DISPLAY "-�-�-�-�-�-�-�-�-" AT 2,2
  DISPLAY "-�-�-�-�-�-�-" AT 3,2 attribute(blue)
  DISPLAY "-�-�-�-�-�-�-�-�-" AT 4,2 attribute(green,reverse)
sleep 1
  DISPLAY "-�-�-�-�-�-�-" AT 5,2
  DISPLAY "-�-�-�-�-�-�-" AT 6,2
  DISPLAY "-�-�-�-�-" AT 7,2
sleep 1
  call aclfgl_dump_screen("out")

#Use 	
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"

  #PROMPT "" FOR CHAR lv_answer
end main
