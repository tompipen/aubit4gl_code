#############################################
# This ensures that the error is 
# display and cleared during a prompt
# and that on key seems to work
#############################################
main
define a char(20)
options error line 5
	display " " at 1,1
	error "This is an error"
	sleep 1
	call aclfgl_dump_screen("prompt_1.out")
	prompt "Enter some text" for a
	on key(f2) call aclfgl_dump_screen("prompt_2.out")
	end prompt
	call aclfgl_dump_screen("prompt_3.out")
end main
