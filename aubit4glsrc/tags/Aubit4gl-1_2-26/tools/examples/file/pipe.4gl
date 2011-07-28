main
define lv_s char(200)
call channel::open_pipe("pipename","ls -l","r")

while  channel::read("pipename",lv_s) 
	display lv_s clipped

end while

call channel::close("pipename")

end main
