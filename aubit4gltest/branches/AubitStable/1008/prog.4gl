{**
 * @file
 * Display some Portuguese Characters because they  are displayed in reverse
 * with HL_TUI.
 * @process TEST_GENERAL
 *}
 
main
  DEFINE lv_answer CHAR

  DISPLAY "-á-Á-à-À-ã-Ã-â-Â-" AT 2,2
  DISPLAY "-é-Á-è-È-ê-Ê-" AT 3,2 attribute(blue)
  DISPLAY "-ó-Ó-ò-Ò-õ-Õ-ô-Ô-" AT 4,2 attribute(green,reverse)
sleep 1
  DISPLAY "-í-Í-ì-Ì-î-Î-" AT 5,2
  DISPLAY "-ú-Ú-ù-Ù-û-Û-" AT 6,2
  DISPLAY "-ç-Ç-ª-º-" AT 7,2
sleep 1
  call aclfgl_dump_screen("out")

#Use 	
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"

  #PROMPT "" FOR CHAR lv_answer
end main
