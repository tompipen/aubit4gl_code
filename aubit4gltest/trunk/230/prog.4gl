main
define q1 char(1)


options message line 2,prompt line 2
call clr_scr()
display "A" at 23,1
display "B" at 24,1

prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screenS1_P")
call clr_scr()
message "message"
call aclfgl_dump_screen("screenS2_M")
clear screen
open window x1 at 10, 5 with 5 rows, 72 columns attribute(border)
call clr_scr()
prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screenW1_P")
call clr_scr()
message "message"
call aclfgl_dump_screen("screenW2_M")
close window x1


options message line 250,prompt line 250
call clr_scr()
display "A" at 23,1
display "B" at 24,1

prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screenT1_P")
call clr_scr()
message "message"
call aclfgl_dump_screen("screenT2_M")
clear screen
open window y1 at 10, 5 with 5 rows, 72 columns attribute(border)
call clr_scr()
prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screenT3_P")
call clr_scr()
message "message"
call aclfgl_dump_screen("screenT4_M")
close window y1




options message line last-1,prompt line last-1
call clr_scr()

display "A" at 23,1
display "B" at 24,1
prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screenS3_P")
call clr_scr()
message "message"
call aclfgl_dump_screen("screenS4_M")
clear screen

open window x2 at 10, 5 with 5 rows, 72 columns attribute(border)
call clr_scr()
prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screenW3_P")
call clr_scr()
message "message"
call aclfgl_dump_screen("screenW4_M")
close window x2


open window rptwin at 10, 5 with 5 rows, 72 columns
     attribute (green, border, message line 2, prompt line 2)

	call clr_scr()

prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screen1_P")

message "message"
call aclfgl_dump_screen("screen2_M")
close window rptwin




open window rptwin2 at 10, 5 with 5 rows, 72 columns
     attribute (green, message line 2, prompt line 2)

	call clr_scr()
prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screen3_P")

message "message"
call aclfgl_dump_screen("screen4_M")
close window rptwin2

open window rptwin3 at 10, 5 with 5 rows, 72 columns
     attribute (green, border, message line last-1, prompt line last-1)

	call clr_scr()

prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screen5_P")

message "message"
call aclfgl_dump_screen("screen6_M")
close window rptwin3

open window rptwin4 at 10, 5 with 5 rows, 72 columns
     attribute (green, message line last-1, prompt line last-1)

	call clr_scr()
prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screen7_P")

message "message"
call aclfgl_dump_screen("screen8_M")

close window rptwin4

open window rptwin5 at 10, 5 with 5 rows, 72 columns
     attribute (green, border, message line 250, prompt line 250)

	call clr_scr()

prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screen9_P")

message "message"
call aclfgl_dump_screen("screen10_M")
close window rptwin5




open window rptwin6 at 10, 5 with 5 rows, 72 columns
     attribute (green, message line 250, prompt line 250)

	call clr_scr()
prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screen11_P")

message "message"
call aclfgl_dump_screen("screen12_M")
close window rptwin6


open window rptwin9 at 10, 5 with 5 rows, 72 columns
     attribute (green, message line last, prompt line last)

	call clr_scr()
prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screen13_P")

message "message"
call aclfgl_dump_screen("screen13_M")

close window rptwin9

open window rptwin10 at 10, 5 with 5 rows, 72 columns
     attribute (green, message line last, prompt line last,border)

	call clr_scr()
prompt "prompt : " for char q1 attribute (blue)
call aclfgl_dump_screen("screen14_P")

message "message"
call aclfgl_dump_screen("screen14_M")



close window rptwin10


end main

function clr_scr()
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 1,1
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 2,1
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 3,1
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 4,1
display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 5,1
end function
