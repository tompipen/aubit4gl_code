

import package a4gl_glade

DEFINE mainwin integer
define mv_curr_db char(256)
define mv_username,mv_passwd char(255)

code
int fetchFirst;
endcode

main
        hide window _variable("screen")
	open form mainwin USING mainwin_fh
	call a4gl_run_gui()
end main



formhandler mainwin_fh
	before open form
		call sbar_text_set(mainwin,id_to_int(statusbar1),"4GL IDE (c) 2004 Aubit Computing Ltd")

input

	on sql1
		run "sqleditor" without waiting

	on mn_edit
		call open_edit_program()

	on mn_settings
		call open_Settings()

	on about1
		call open_about()
	on quit1
		exit program
end input

end formhandler





function has_db()
        if mv_curr_db is null then
                return 0
        else
                return 1
        end if
end function



function sbar(lv_txt)
define lv_txt char(80)
call sbar_text_set(mainwin,id_to_int(statusbar1),lv_txt)
end function




function get_db()
        if mv_curr_db is null then
                return ""
        else
                return mv_curr_db
        end if
end function

function open_db()
        whenever error continue
        database mv_curr_db

        if sqlca.sqlcode<0 then
                error "Unable to connect to database ",mv_curr_db
        else
                call set_curr_db(mv_curr_db)
        end if
end function



function set_curr_db(p_dbname)
define p_dbname char(255)
if p_dbname is null or length(p_dbname)=0 then
        initialize mv_curr_db to null
else
        let mv_curr_db=p_dbname
end if
end function




function set_username(p_username,p_passwd)
define p_username,p_passwd char(255)
let mv_username=p_username
let mv_passwd=p_passwd
end function
