main
 define w_a decimal(5,2)
 OPEN WINDOW v_disp AT 2,2 WITH FORM "dispdec"
 let w_a = 123.45
 display w_a, w_a, w_a to a1, a2, a3
 sleep 1

call aclfgl_dump_screen("out")

 CLOSE WINDOW v_disp

end main
