main 
open window main_win at 3, 2 with 20 rows, 78 columns attribute (green, border) 
CALL fgl_drawbox(10,30,1,1,0) 
call aclfgl_dump_screen("w1.out")
close window main_win

open window main_win at 3, 2 with 20 rows, 78 columns attribute (green) 
CALL fgl_drawbox(10,30,1,1,0) 
call aclfgl_dump_screen("w2.out")
close window main_win


open window main_win at 10, 10 with  13 rows, 48 columns attribute (green,border) 

CALL fgl_drawbox(10,30,1,1,0) 
call aclfgl_dump_screen("w3.out")
close window main_win


open window main_win at 10, 10 with 13 rows, 48 columns attribute (green) 
CALL fgl_drawbox(10,30,1,1,0) 
call aclfgl_dump_screen("w4.out")
end main 
