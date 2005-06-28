DEFINE mainwin integer
DEFINE dbselect integer
define mv_curr_db char(256)
define mv_username,mv_passwd char(255)

code
int fetchFirst;
int fgl_callback(int argc,char *argv[]) {
	printf("Hello World\n");
	A4GL_setenv("A4GL_UI","GLADE",1);
	printf("-->%s\n",acl_getenv("A4GL_UI"));
}
endcode


main
	call init()
end main

function init()

        hide window _variable("screen")
	call select_db() 
	if has_db() then
		call open_sqleditor()
	end if
	call a4gl_run_gui()
end function




formhandler dbselect_fh
define lv_lc integer
define lv_clicks integer
define lv_db integer
define lv_dbn char(255)

	before open form
		call load_databases()
	
input lv_clicks from dblist

	on b_quit
		exit program

	on dblist
		let lv_db=A4GL_GLADE::list_current_get(dbselect,id_to_int(dblist))
		close form dbselect

	on b_ok
		let lv_db=A4GL_GLADE::list_current_get(dbselect,id_to_int(dblist))
		if lv_db<1 then
			message "No database selected" 
		else
			let lv_dbn=A4GL_GLADE::list_text_get(dbselect,id_to_int(dblist),lv_db)
			call open_db(lv_dbn)
			if has_db() then
				call open_sqleditor()
			else 	
				message "Error opening database"
			end if
			
		end if
		close form dbselect
end input
end formhandler


function load_databases() 
define lv_cnt integer
define lv_curr_db char(255)
define lv_name char(255)
define lv_newname char(255)
define ndbs integer
define lv_ok integer
define a integer
call A4GL_GLADE::sbar_text_set(mainwin,id_to_int(statusbar1),"Getting database names - please wait")
#let lv_curr_db=get_db();

code
{
#define MAXDBS 100
#define FASIZ (MAXDBS * 19)
char *dbsname[MAXDBS+1];
char            dbsarea[FASIZ];

 sqlca.sqlcode = sqgetdbs(&ndbs, dbsname, MAXDBS, dbsarea, FASIZ);

endcode

if sqlca.sqlcode!=0 then
        return
end if

# Clear our list down..
while true
	call A4GL_GLADE::list_count_get(dbselect,Id_To_Int(dblist)) returning lv_ok
	if lv_ok then
		call A4GL_GLADE::list_delete(dbselect,Id_To_Int(dblist),1)
	else
		exit while
	end if
end while


for a=1 to ndbs
code
        strcpy(lv_name,dbsname[a-1]);
	printf("Append : %s\n",lv_name);
endcode
	call A4GL_GLADE::list_append(dbselect,Id_To_Int(dblist),lv_name)
        #call add_to_list(a,lv_name)
end for
code
}
endcode
call A4GL_GLADE::sbar_text_set(mainwin,id_to_int(statusbar1),"")
end function


function sbar(lv_txt)
define lv_txt char(80)
#call A4GL_GLADE::sbar_text_set(mainwin,id_to_int(statusbar1),lv_txt)
end function



function check_and_report_error()
define lv_a integer
define lv_err1 char(255)
define lv_err2 char(255)

if sqlca.sqlcode>=0 then
        return 0
end if

let lv_err2=get_db_err_msg(sqlca.sqlcode)

message lv_err2 clipped
return 1
end function


function has_db()
        if mv_curr_db is null then
                return 0
        else
                return 1
        end if
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
