main
define a integer
for a=0 to 7
	call fgl_drawbox(10,10,a*2+1,a*2+1,a)
end for
call aclfgl_dump_screen("fgldrawbox.out",0)
sleep 1
end main
