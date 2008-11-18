define lv_r array[1000] of char(128)
DEFINE mv_rowid CHAR(30)

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

display "Please wait..." at 2,1
code
ndbs=A4GLSQL_fill_array(1000,lv_r,sizeof(lv_r[0])-1,0,0,"DATABASES",0,0);
endcode

for a=1 to ndbs
        call set_pick(a,lv_r[a])
end for
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
define ntab integer
code
	ntab=A4GLSQL_fill_array(1000,lv_r,sizeof(lv_r[0])-1,0,0,"TABLES",1,0);
endcode

clear screen

call display_banner()

for a=1 to ntab
        call set_pick(a,lv_r[a])
end for
call set_pick_cnt(ntab)

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
define ncol integer
clear screen
call display_banner()
let lv_tabname=get_curr_tab()

if lv_tabname is null or lv_tabname matches " " then
	error "No table selected"
	return 0
end if
let a=1

code
A4GL_trim(lv_tabname);
ncol=A4GLSQL_fill_array(1000,lv_r,sizeof(lv_r[0])-1,0,0,"COLUMNS",1,lv_tabname);
endcode

clear screen

call display_banner()


if ncol<=0 then
	error "No columns found for table ",lv_tabname
	return 0
end if

for a=1 to ncol
        call set_pick(a,lv_r[a])
end for
call set_pick_cnt(ncol)

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
if mv_rowid IS NULL THEN
code
	strcpy(mv_rowid,A4GLSQLCV_get_sqlconst ("ROWID"));
endcode
end if

return mv_rowid clipped
END FUNCTION
