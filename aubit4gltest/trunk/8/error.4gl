main
	options error line 4
	error "Test - Normal"
	display "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" at 4,1
	call aclfgl_dump_screen("err1.out",0)
	error "Test Blue" attribute(blue)
	call aclfgl_dump_screen("err2.out",0)
	error "Test Blue Reverse" attribute(blue,reverse)
	call aclfgl_dump_screen("err3.out",0)
end main
