import package a4gl_glade
define aboutwin integer


function open_about()
if not form_is_open(aboutwin) then
	open form aboutwin using aboutwin_fh
end if
end function

formhandler aboutwin_fh
input
on b_ok
	close form aboutwin
end input
end formhandler
