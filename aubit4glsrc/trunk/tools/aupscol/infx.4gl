function select_db()
define lv_cnt integer
define lv_curr_db char(255)
define lv_name char(255)
define lv_newname char(255)
define ndbs integer
define a integer
let lv_curr_db=get_db();
clear screen
call display_banner()
#database aubit4gl
#call set_curr_db("aubit4gl")
#return

if fgl_getenv("A4GL_LEXDIALECT") != "INFORMIX" then
	call aclfgl_setenv("A4GL_LEXDIALECT","INFORMIX")
end if

display "Please wait..." at 2,1
code
{
#define MAXDBS 100
#define FASIZ (MAXDBS * 19)
char *dbsname[MAXDBS+1];
char            dbsarea[FASIZ];

 sqlca.sqlcode = sqgetdbs(&ndbs, dbsname, MAXDBS, dbsarea, FASIZ);

endcode

if sqlca.sqlcode!=0 then
        call check_and_report_error()
        return
end if
for a=1 to ndbs
code
        strcpy(lv_name,dbsname[a-1]);
endcode
        call set_pick(a,lv_name)
end for
code
}
endcode

call set_pick_cnt(ndbs)

display  "Choose a database with the arrow keys, or type one in" at 2,1
let lv_newname=prompt_pick("SELECT DATABASE >>","")
if lv_newname is null then
        let lv_newname=lv_curr_db
end if

if lv_newname is not null and lv_newname not matches " " then
        whenever error continue

        close database
        database lv_newname
        whenever error stop

        if sqlca.sqlcode=0 then
                call set_curr_db(lv_newname)
                call display_banner()
                message "Database Opened"
        else
                call check_and_report_error()
        end if
end if

end function



function choose_table()
define lv_name char(40)
define a integer
declare c_choose_tab cursor for
	select tabname from systables
	where tabid>99
	order by tabname
let a=1
clear screen
call display_banner()
foreach c_choose_tab into lv_name
        call set_pick(a,lv_name)
	let a=a+1
end foreach
call set_pick_cnt(a-1)

display  "Choose a table with the arrow keys, or type one in" at 2,1
let lv_name=prompt_pick("SELECT TABLE >>","")
if lv_name is null or lv_name matches " " then
	return 0
else
	call set_tabname(lv_name)
	return 1
end if
end function



function choose_column()
define lv_name char(40)
define a integer
define lv_str char(255)
define lv_tabname char(30)
clear screen
call display_banner()
let lv_tabname=get_curr_tab()

if lv_tabname is null or lv_tabname matches " " then
	error "No table selected"
	return 0
end if
let a=1
let lv_str="select colname,colno from syscolumns,systables where tabname=? and systables.tabid=syscolumns.tabid order by 2"
prepare p_choose_col from lv_str
declare c_choose_col cursor for p_choose_col
foreach c_choose_col using lv_tabname into lv_name
        call set_pick(a,lv_name)
	let a=a+1
end foreach

if a<=1 then
	error "No columns found for table ",lv_tabname
	return 0
end if
call set_pick_cnt(a-1)

display  "Choose a column with the arrow keys, or type one in" at 2,1
let lv_name=prompt_pick("SELECT COLUMN >>","")
if lv_name is null or lv_name matches " " then
	return 0
else
	call set_colname(lv_name)
	call display_banner()
	return 1
end if
end function


FUNCTION get_rowid()
return "rowid"
END FUNCTION
