
function errlog(ln,mod,err,errmsg)
define ln integer
define mod char(64)
define errmsg char(1024)
define err integer
define lv_cline char(2000)
define lv_continue integer
define a integer
define lv_fname_scrdump char(300)
define lv_l text
let lv_fname_scrdump="/tmp/scr.out.err_", fgl_getpid() using "<<<<<<"



call aclfgl_dump_screen(lv_fname_scrdump)
locate lv_l in file lv_fname_scrdump
display "********************************************"
display "*                 ERRHOOK                   "
display "********************************************"
display "* User    : ", aclfgl_get_user()
display "* Time    : ", current year to second
display "* Module  : ",mod clipped
display "* Line    : ",ln
display "* Error   : ",err
display "* PID     : ",fgl_getpid()
display "* lastkey : ",fgl_lastkey()
display "********************************************"
display "* ScrDump : ",lv_fname_scrdump clipped
display "********************************************"
display lv_l
display "********************************************"
display "* Errmsg :"


# The error message contains embedded \n's which mess up 
# the display..
# here we're just searching for them and using them as delimiters
let lv_continue=1
while lv_continue
	let lv_continue=0
	for a=1 to length(errmsg)
		if ord(errmsg[a])=13 then
			let errmsg[a]=' '
		end if

		if ord(errmsg[a])=10 then
			if a>1 then
				display "* ", errmsg[1,a-1]
			else
				display "*"
			end if
			let errmsg=errmsg[a+1,1024]
			let lv_continue=1
			exit for
		end if
	end for
end while

if length(errmsg) then
	display "* ", errmsg clipped
end if
display "********************************************"

end function

