define eprog integer
import package a4gl_glade


function open_edit_program()
if not form_is_open(eprog) then
	open form eprog using editprog_fh
end if
end function


formhandler editprog_fh
end formhandler
