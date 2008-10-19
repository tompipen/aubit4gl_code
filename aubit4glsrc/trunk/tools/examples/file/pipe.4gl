main
define lv_s char(200)
call channel::open_pipe("pipename","ls -l","r")

while  channel::read("pipename",lv_s) 
code
A4GL_trim_nl(lv_s);
endcode

	display lv_s

end while

call channel::close("pipename")

end main
