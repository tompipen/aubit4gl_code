
code
#include <ncurses.h>
#include <form.h>
#include "simple.h"
int init_filename=1;
endcode

# We need to store the filename
# a user types in for choose/save/load
define mv_filename char(255)

# we also need to store our current SQL
# somewhere
# so we'll create a temp file that
# we can edit
define mv_tmpinfile char(255) # Filename
define mv_fin integer         # fopen file handle
define mv_qry char(32000)
define frm_is_open integer

# We need to define this for 4GL
define form_line_width constant 75
# And for C
code
#define form_line_width 75


char **read_directory(char *dir,char *spec);
endcode


################################################################################
function remove_tmpfile()
code
if (init_filename==0) {
	unlink(mv_tmpinfile);
}
endcode
end function


################################################################################
function open_tmpfile()
code
mv_fin=(long)fopen(mv_tmpinfile,"w");
endcode
end function

################################################################################
function open_read_tmpfile()
code
mv_fin=(long)fopen(mv_tmpinfile,"r");
A4GL_assertion(mv_fin==0,"Tried to read tmpfile failed");
endcode
end function


################################################################################
function close_tmpfile()
if mv_fin then
code
	fclose((FILE *)mv_fin);
	mv_fin=0;
endcode
end if
end function




################################################################################
function init_filename()
define do_init integer
define fin integer


code
{
do_init=init_filename;
mv_fin=0;
init_filename=0;
frm_is_open=0;
sprintf(mv_tmpinfile,"/tmp/a4gl_%d",getpid());
endcode

call open_tmpfile()

if mv_fin=0 then
	error "Unable to write temporary file",mv_tmpinfile
	exit program
end if

call close_tmpfile()


if do_init then
	initialize mv_filename to null
	let mv_qry=""
end if
code
}
endcode

end function

################################################################################
function write_tmpfile()
call open_tmpfile()
if mv_fin=0 then
	return
end if
code
{
char *qry;
char qry_orig[32000];
char buff[255];
int buffshort;
memset(qry_orig,0,32000);
strcpy(qry_orig,mv_qry);
qry=qry_orig;

A4GL_trim(qry);
while (1) {
	memset(buff,0,255);
	strncpy(buff,qry,form_line_width+1);
	buff[form_line_width+1]=0;
	if (strlen(buff)==0) break;
	
	buffshort=strlen(buff);
	if (buff[form_line_width]==' ') {
		A4GL_trim(buff);
		fprintf((FILE*)mv_fin,"%s\n",buff);
	} else {
		fprintf((FILE*)mv_fin,"%s",buff);
	}
	qry+=form_line_width+1;
	if (buffshort<form_line_width+1) break;
}
//free(qry_orig);
}
endcode
call close_tmpfile();

end function





################################################################################
function query_menu()
	call init_filename()

	
	if not has_db() then
		call select_db()
	end if

	call display_qry()

	menu "SQL"
		command "New" "Type in new SQL commands"
			if qry_new() then
				next option "Run"
			end if

		command "Run" "Run the SQL commands"
			Call set_exec_mode(0)
			call qry_run()

		command "Modify" "Modify the SQL commands"
			if qry_modify() then
				next option "Run"
			end if

		command "Use-editor" "Use the editor to modify SQL"
			if qry_edit() then
				next option "Run"
			end if

		command "Output" "Output the results of the SQL"
			call qry_output()

		command "Choose" "Choose an SQL file"
			if qry_choose() then
				next option "Run"
			end if

		command "Save" "Save an SQL file"
			call qry_save()

		command "Info" "Info for tables"
			call qry_info()

		command "Drop" "Drop an SQL file"
			call qry_drop()

		command "Exit" "Return to ADBACCESS menu" exit menu
	end menu

	call clear_screen_portion()
end function




################################################################################
function qry_new()
	# Clear down our temporary file
	call open_tmpfile()
	call close_tmpfile()
	return qry_modify()
end function

################################################################################
function read_file(lv_fname)
define lv_fname char(256)
code
A4GL_trim(lv_fname);

mv_fin=(long)fopen(lv_fname,"r");
endcode

if mv_fin=0 then
	error "Unable to open file : ",lv_fname
	sleep 1
	return
end if
code
{
char *qry;
char qry_orig[32000];
char buff[255];
int buffshort;
memset(mv_qry,0,sizeof(mv_qry));
strcpy(mv_qry,"");
while (1) {
	if (feof((FILE *)mv_fin)) break;
	memset(buff,0,255);
	fgets(buff,255,(FILE *)mv_fin);
	// Our current line is too short
	// pad it with spaces
	if (strlen(buff)<form_line_width) {
		memset(&buff[strlen(buff)],' ',255);
		buff[form_line_width+1]=0;
	}
	strcat(mv_qry,buff);
}
}
fclose((FILE *)mv_fin);
A4GL_debug("--->%s",mv_qry);
endcode

end function

################################################################################
function read_tmpfile()
call open_read_tmpfile()
if mv_fin=0 then
	error "Unable to open tmpfile"
	return
end if
code
{
char *qry;
char qry_orig[32000];
char buff[255];
int buffshort;
strcpy(mv_qry,"");
while (1) {
	if (feof((FILE *)mv_fin)) break;
	memset(buff,0,255);
	fgets(buff,255,(FILE *)mv_fin);
	if (feof((FILE *)mv_fin)) break;
	// Our current line is too short
	// pad it with spaces
	if (buff[strlen(buff)-1]=='\n')
		buff[strlen(buff)-1]=0;

	if (strlen(buff)<form_line_width) {
		memset(&buff[strlen(buff)],' ',255);
		buff[form_line_width+1]=0;
	}
	strcat(mv_qry,buff);
	A4GL_debug("Added : %s to mv_qry",buff);
}
}
endcode
let mv_qry=mv_qry
call close_tmpfile();
end function

################################################################################
function qry_modify()
	call read_tmpfile()

	if not frm_is_open then
		open window w1 at 6,1 with form "qryfrm" attributes(form line 1)
	end if

	let int_flag=false

	let mv_qry=mv_qry clipped
	input mv_qry without defaults from info_line  attribute(green)

	on key(up)
code
		A4GL_int_form_driver(GET("s_screenio",_inp_io,"cform"),REQ_PREV_LINE);
endcode


	on key(down)
code
		A4GL_int_form_driver(GET("s_screenio",_inp_io,"cform"),REQ_NEXT_LINE);
endcode
	on key(return)
code
		A4GL_int_form_driver(GET("s_screenio",_inp_io,"cform"),REQ_NEW_LINE);
endcode



	end input
	
	close window w1
	let frm_is_open=0
	if int_flag=true then
		error "INT PRESSED"
		call read_tmpfile()
		call display_qry()
		return 0
	else
		error "WRITING"
		call write_tmpfile()
		call display_qry()
		return 1
	end if

end function


################################################################################
function display_qry()
define lv_a,lv_b,lv_c integer
	call clear_screen_portion()
	let mv_qry=mv_qry clipped

	if mv_qry is not null and mv_qry!=" " then
		let lv_a=1
		for lv_c=1 to 16
			if lv_a > length(mv_qry) then
				exit for
			end if
			let lv_b=lv_a+form_line_width
			display mv_qry[lv_a,lv_b] at 5+lv_c,2
			let lv_a=lv_b+1
		end for
	end if
end function





################################################################################
function qry_run()
define a integer
call open_read_tmpfile()
code
{
extern FILE *yyin;
extern struct element *list;
extern int list_cnt;

A4GL_assertion(mv_fin==0,"No input tmp file");

yyin=(FILE *)mv_fin;
clr_stmt();
a=yyparse();
a=list_cnt;
}
endcode

if get_exec_mode()=0 then
message a using "<<<<"," statements to execute"

end if
if not execute_queries() then
	if get_exec_mode()=0 then
		error "Error Executing.."
	end if
end if

end function


################################################################################
function qry_edit()
define lv_systemstr char(255)
define lv_stat integer
let lv_systemstr=fgl_getenv("DBEDIT")
if lv_systemstr is null or lv_systemstr is null matches " " then
	let lv_systemstr="vi"
end if
let lv_systemstr=lv_systemstr clipped," ", mv_tmpinfile
run lv_systemstr returning lv_stat

call read_tmpfile()
call display_qry()

return 1
end function


################################################################################
function qry_output()
end function


################################################################################
function qry_choose()
define lv_fname char(255)
define a integer

display "Choose a file to load","" at 2,1

code
{
	char **dir;
	dir=read_directory(".",".sql");
        if (dir) {
		for (a=0;dir[a];a++) {
			strcpy(lv_fname,dir[a]);
endcode
			call set_pick(a+1,lv_fname);
code
		}
		free_directory(dir);
	}
}
endcode

call set_pick_cnt(a);

call prompt_pick("CHOOSE >> ",mv_filename) returning lv_fname
if lv_fname is not null then
	let lv_fname=lv_fname clipped,".sql"
	error "Filename : ",lv_fname
	let mv_filename=lv_fname
	call read_file(lv_fname)
	call write_tmpfile()
	call display_qry()
	return 1
end if
return 0

end function


function execute_file(lv_fname)
define lv_fname char(255)
call init_filename()
	display "EXECUTING FILE..."
	call set_exec_mode(1)
	call read_file(lv_fname)
	display mv_qry clipped
	call write_tmpfile()
	display "---"
	display mv_qry clipped
	call open_read_tmpfile()
	call qry_run()
end function

################################################################################
function qry_save()
define lv_fname char(255)
call set_pick_cnt(0)
call prompt_pick("SAVE >> ",mv_filename) returning lv_fname

end function

################################################################################
function qry_info()
end function

################################################################################
function qry_drop()
define lv_fname char(255)
define a integer

display "Choose a file to drop","" at 2,1

code
{
	char **dir;
	dir=read_directory(".",".sql");
        if (dir) {
		for (a=0;dir[a];a++) {
			strcpy(lv_fname,dir[a]);
endcode
			call set_pick(a+1,lv_fname);
code
		}
		free_directory(dir);
	}
}
endcode

call set_pick_cnt(a);

call prompt_pick("DROP >> ",mv_filename) returning lv_fname


if lv_fname is not null then
	let lv_fname=lv_fname clipped,".sql"
menu "CONFIRM" 
	command "No" "No - I don't want to drop it"
		exit menu
	command "Yes" "Yes - I do want to drop it"
	
code
	A4GL_trim(lv_fname);
	unlink(lv_fname);
endcode
	exit menu
end menu
end if

end function





