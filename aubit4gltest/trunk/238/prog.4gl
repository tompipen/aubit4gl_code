
main
define lv_rec record
	a char(10),
	b char(10),
	c char(10),
	d char(10)
end record

defer interrupt


call startlog("errlog.out")

open window w1 at 1,1 with form "m1"
input by name lv_rec.*

before input 
	call errorlog("before input")


before field a
	call errorlog("before field a")

after field a
	call errorlog("after field a")

before field b
	call errorlog("before field b")

after field b
	call errorlog("after field b")

before field c
	call errorlog("before field c")

after field c
	call errorlog("after field c")

before field d
	call errorlog("before field d")

after field d
	call errorlog("after field d")

on key(f1)
	call errorlog("f1")

on key(interrupt)
	call errorlog("interrupt")

after input
	error "HERE" sleep 2
	if fgl_lastkey()=fgl_keyval("DOWN") then
		error "DOWN !!"
	sleep 2
		continue input
	else
		message "lastkey=",fgl_lastkey()
		sleep 2
	end if
	call errorlog("after input x2")

end input


end main
