

code
int A4GL_dl_haslibrary (char *type, char *p);
endcode

define lv_msglines array[30] of char(80)

define mv_left integer
define mv_top integer
define mv_width integer
define mv_height integer

define mv_screenwidth integer
define mv_screenheight integer

define mv_dbtype char(50)
define mv_dbname char(50)
define mv_username char(40)
define mv_password char(40)
define mv_server char(40)
define mv_aclfile integer
define mv_lextype char(40)
define mv_lexdialect char(40)
define mv_need_wide integer
define mv_ui char(30)


################################################################################
main
	define lv_aubitdir char(2000)
	define lv_aubitetc char(2000)
	define lv_run integer

	define lv_cnt integer

	defer interrupt

# Lets start with some basic checks
# These program probably wont even work if these
# are not set though!
	options prompt line 2
	options menu line 4

	let mv_need_wide=0
	let lv_aubitdir=fgl_getenv("AUBITDIR")
	if lv_aubitdir is null or lv_aubitdir="" then
		call fail("$AUBITDIR is not set")
	end if

	if not directory_exists(lv_aubitdir) then
		call fail("$AUBITDIR does not point to a directory")
	end if
	 
	let lv_aubitetc=fgl_getenv("AUBITETC")

	if directory_exists(lv_aubitetc) then
		# Good...
	else
		let lv_aubitetc=lv_aubitdir clipped,"/etc"
		if directory_exists(lv_aubitetc) then
			# Good too..
		else
			call fail("Neither $AUBITETC nor $AUBITDIR/etc point to a directories")
		end if
	end if

	let lv_run=1

# Check for TUI mode..
	if not has_plugin("UI","TUI") then
		display "The TUI plugin was not found - this will mean you might not be able"
		display "to run programs in TEXT mode (ie. using CURSES)"

		if not has_plugin("UI","HL_TUI") then
			display "The HL_TUI plugin was not found - this will mean you might not be able"
			display "to run programs in TEXT mode (ie. using CURSES)"
			let lv_run=0
		end if
	end if

# Check for UTF encoding
	if fgl_getenv("LANG") matches "*utf*" then
		display "You are using a UTF Locale setting ($LANG) - you will need to ensure"
		display "you are using TUI_wide if you want to use extended/accented characters"
		display "ie. those with an ascii value  >127"

		if not has_plugin("UI","TUI_wide") then
			display "*** The TUI_wide plugin was not found"
			display "please either :"
			display "    ensure you have ncursesw installed and rerun the ./configure"
			display "or "
			display "    set $LANG to be a non UTF locale"
			let lv_run=0
		end if

		display "You're using a utf locale - please ensure your database is set to use a utf"
		display "character set - or reset your $LANG variable"
		let mv_need_wide=1
	end if

	if fgl_getenv("A4GL_UI")="TUI"  OR fgl_getenv("A4GL_UI")="HL_TUI"  OR fgl_getenv("A4GL_UI")="HL_GTK"  OR fgl_getenv("A4GL_UI")="TUI_wide" THEN
	ELSE
		let lv_run=0
		display "Please ensure A4GL_UI is set to TUI, HL_TUI or HL_GTK before continuing"
		
	end if
code
{
char buff[2000];
printf("Completed pre-checks\nPress return to continue\n");
fgets(buff,200,stdin);
}
endcode

if not lv_run then
	exit program
end if


start report r_settings to "settings.env"

let mv_screenwidth=aclfgl_get_curr_width()
let mv_screenheight=aclfgl_get_curr_height()
let mv_width=mv_screenwidth
let mv_height=mv_screenheight

call banner("Aubit4GL Initial Configuration","REVERSE,CYAN")



call info(set_lines(
	"Hello - Welcome to the Aubit4GL quick setup program",
	 " ",
	"This program should ease you through the initial configuration",
	"of Aubit4GL",
	"If you have any questions please join the aubit4gl-discuss",
	"mailing list on sourceforge : ",
	"https://lists.sourceforge.net/lists/listinfo/aubit4gl-discuss"
	))

call info(set_lines(
	"Aubit4GL is configured by settings in the environment",
	"or in the aubitrc files",
	" ",
	"You can specify the AUBITRC file explicitly by setting $AUBITRC",
	"or Aubit4GL will try to find them",
	" ",
	"In these instructions we'll refer to the settings as ",
	"using the Unix environment variable typography : '$NAME'",
	"but as they can also be reade from the aubitrc files",
	"these are not always environment variables!"
	))


let lv_msglines[1]="These are the files Aubit4GL tried to read when running this program:"
let lv_cnt=2
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_0")) returning lv_cnt
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_1")) returning lv_cnt
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_2")) returning lv_cnt
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_3")) returning lv_cnt
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_4")) returning lv_cnt
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_5")) returning lv_cnt
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_6")) returning lv_cnt
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_7")) returning lv_cnt
call info( set_line_sizes(lv_cnt-1))
	
let lv_msglines[1]="These are the files Aubit4GL that actually exist :"
let lv_cnt=2

if file_exists(fgl_getenv("AUBITRC_READ_0")) then
	call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_0")) returning lv_cnt
end if

if file_exists(fgl_getenv("AUBITRC_READ_1")) then
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_1")) returning lv_cnt
end if

if file_exists(fgl_getenv("AUBITRC_READ_2")) then
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_2")) returning lv_cnt
end if

if file_exists(fgl_getenv("AUBITRC_READ_3")) then
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_3")) returning lv_cnt
end if

if file_exists(fgl_getenv("AUBITRC_READ_4")) then
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_4")) returning lv_cnt
end if

if file_exists(fgl_getenv("AUBITRC_READ_5")) then
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_5")) returning lv_cnt
end if

if file_exists(fgl_getenv("AUBITRC_READ_6")) then
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_6")) returning lv_cnt
end if

if file_exists(fgl_getenv("AUBITRC_READ_7")) then
call add_line(lv_cnt, fgl_getenv("AUBITRC_READ_7")) returning lv_cnt
end if

call info( set_line_sizes(lv_cnt-1))
	


call get_db_settings()
call code_generation()
call ui_detection()

case mv_dbtype
	when "Informix"
		call set("A4GL_SQLTYPE","esql")
	when "MYSQL"
		call set("A4GL_SQLTYPE","mysql")
	when "Postgresql"
		call set("A4GL_SQLTYPE","pg8")
	when "SQLite"
		call set("A4GL_SQLTYPE","sqlite3")
	when "Other"
		if has_plugin("SQL","unixodbc") then
			call set("A4GL_SQLTYPE","unixodbc")
		else
			if has_plugin("SQL","iodbc") then
				call set("A4GL_SQLTYPE","unixodbc")
			else
				if has_plugin("SQL","odbc32") then
					call set("A4GL_SQLTYPE","odbc32")
				end if
			end if
		end if
end case
			
call set("A4GL_LEXTYPE",mv_lextype)

if mv_lexdialect!=" " then
	call set("A4GL_LEXDIALECT",mv_lexdialect)
end if
			
call set("A4GL_UI",mv_ui)

if not mv_aclfile then
	if mv_username!=" " then
		call set("A4GL_SQLUID",mv_username)
	end if
	if mv_password!=" " then
		call set("A4GL_SQLPWD",mv_password)
	end if
end if

call misc()

call set("AUBITDIR",fgl_getenv("AUBITDIR"))

if is_windows() then
	call set("PATH",fgl_getenv("PATH") clipped||";"||fgl_getenv("AUBITDIR")||"/bin;"||fgl_getenv("AUBITDIR") clipped||"/lib")
else
	if fgl_getenv("TARGET_OS") matches "*darwin*" then
		call set("PATH",fgl_getenv("PATH")||":"||fgl_getenv("AUBITDIR")||"/bin")
		call set("DYLD_LIBRARY_PATH",fgl_getenv("DYLD_LIBRARY_PATH")||":"||fgl_getenv("AUBITDIR")||"/lib")
	else
		call set("PATH",fgl_getenv("PATH")||":"||fgl_getenv("AUBITDIR")||"/bin")
		call set("LD_LIBRARY_PATH",fgl_getenv("LD_LIBRARY_PATH")||":"||fgl_getenv("AUBITDIR")||"/lib")
	end if
end if

finish report r_settings

call info(set_lines(
	"That should do for now!",
	"Your settings should have been saved in",
	"a file called 'settings.env'",
	"If you want to use then in the aubitrc",
	"remember to remove the 'export' lines!"
	))

call hint(set_lines(
	"If you want to rerun this program",
	"just run 'make config in the aubit4glsrc directory'",
	"or invoke it directly $AUBITDIR/bin/quickguide.4ae"))
end main
 
################################################################################
function get_db_settings()
# Now - go to screen mode..
menu "Which database do you want to connect to?"

command "Informix"
	let mv_dbtype="Informix"
	exit menu


command "Postgresql"
	let mv_dbtype="Postgresql"
	exit menu

command "MYSQL"
	let mv_dbtype="MYSQL"
	exit menu

command "SQLite"
	let mv_dbtype="SQLite"
	exit menu

command "Other"
	let mv_dbtype="Other"
	exit menu
end menu

if mv_dbtype="Other" then
	if is_windows() then
		call warn(set_lines(
			"You will need to set up an ODBC connection",
			"in order to use other databases as there is",
			"no builtin connector",
			"Please use UnixODBC to setup the connection ",
			"and ensure it works using the UnixODBC 'isql'",
			"utility. If that doesn't connect then Aubit4GL",
			"wont be able to!!"
		))
	else 
		call warn(set_lines(
			"You will need to set up an ODBC connection",
			"in order to use other databases as there is",
			"no builtin connector"))
	end if
end if



if mv_dbtype="MYSQL"  then
		call prompt_for("Please enter the Username you want to use","Username >>") returning mv_username
		call prompt_for("Please enter the Password you want to use","Password >>") returning mv_password
		call hint(set_lines(
			"Remember - you must be able to connect to the MYSQL database",
			"using that username and password using a standard Mysql client",
			"such as 'mysql --user="||mv_username clipped||" --password="||mv_password clipped||" db_name"
		))
end if


if mv_dbtype="Informix" then
		if is_windows() then
			call warn(set_lines(
					"Please make sure you can connect to the Informix database",
					"using the Informix ILOGIN demo program",
					" ",
					"You will need :",
					" the Informix ClientSDK to develop/run Aubit4GL applications",
					" or  Informix Connect to just run Aubit4GL applications"
				))

			call prompt_for("Please enter the Username you want to use","Username >>") returning mv_username
			call prompt_for("Please enter the Password you want to use","Password >>") returning mv_password
		else
			call info(set_lines("You dont need to set up a username or password",
				"to use Informix - as Informix will run using the current unix username"
			))
			
		end if
end if


if mv_dbtype="Postgresql" then
	if yes_no("Is the database server on the same machine as Aubit4GL ?","Y")="N" then
			call info(set_lines("You can set the database server name by setting $PG_HOST"))
			call prompt_for("Please enter hostname/IP address of the Postgresql servere","Server >>") returning mv_server
			if mv_server is not null and mv_server!=" " then
				call set("PG_HOST",mv_server)
			end if
	end if
	call prompt_for("Please enter the Username you want to use","Username >>") returning mv_username
	call prompt_for("Please enter the Password you want to use","Password >>") returning mv_password

	call hint(set_lines(
			"Remember - you must be able to connect to the Postgresql database",
			"using that username and password using a standard Postgresql client",
			"such as 'psql -U "||mv_username clipped||" db_name'",
			" ",
			"You may also wish to use PGDATABASE, PGHOST, PGPORT and/or PGUSER",
			"environment variables which are used internall by libpq",
			" ",
			"The passwords may be stored in the Postgresql ~/.pgpass or ",
			"in Aubit4GLs A4GL_SQLPWD, or ACL file",
			"Note: Aubit4GL is not automatically prompt for a password!!"
	))

end if


if mv_username is not null then
	if ask("Use ACL", "Do you want to use an ACL file ?","Y", set_lines("You can store the username/password in Environment variables",
				"*OR* you can save them in an Access Control List (ACL) file"," "))="Y" then
			let mv_aclfile=true
	else
			let mv_aclfile=false
	end if

	if mv_aclfile then
		if ask("ACLFILE", "Do you want to create an entry now (this will replace any existing file) ?","Y", 
			set_lines(	
			"Using an ACL file - you will need to create entries",
			"(one per line) which contain a database:username:password",
			"as soon as the file is read - the passwords will be",
			"encrypted using a weak encryption (dont store important",
			"password in the ACL file!)", " "
		))="Y" then

			call prompt_for("Please enter the database you want to use","Database >>") returning mv_dbname
			if not create_aclfile() then
				let mv_aclfile=false
				call warn(set_lines("Unable to create the ACLFILE for some reason",
						"We'll write them to the environment instead.."))
			end if
		end if
			
	end if
		
end if
end function




################################################################################
function code_generation()
define lv_ecpg char(50)
define lv_stat integer
#set the defaults...
let mv_lextype="C"
let mv_lexdialect=""

if mv_dbtype="Postgresql" then
	call info(set_lines(
			"Using Postgresql - you can get Aubit4GL to generate C or ESQL/C code",
			"ESQL/C uses Postgresql's 'ecpg' preprocessor to convert the ",
			"ESQL/C code into C code - which then runs using 'ecpg' libraries.",	
			" ",
			"C code generation will use the native database communicator.",
			" ",
			"We recommend you use 'C' generation UNLESS :",
			"   1) you are using the 'Patched' Postgresql version (7.4 - very old)",
			"OR 2) you are integrating with other ESQL/C code"
			))

	menu "Do you want to use 'C' generation"
		command "Use C"
			let mv_lextype="C"
			exit menu

		command "Use ESQL/C with 'ecpg'"
			let mv_lextype="EC"
			let mv_lexdialect="POSTGRES"


			let lv_ecpg=fgl_getenv("PG_ESQLC")
			if lv_ecpg!=" " then
			else
				let lv_ecpg="ecpg"
			end if

			run lv_ecpg||" --version" returning lv_stat
			
			if lv_stat>255 then
				let lv_stat=lv_stat/255
			end if

			if lv_stat then
				call err(set_lines("Unable to locate ecpg!",
					"Please find your 'ecpg' executable manually",
					"and set PG_ESQLC in the environment before running",
					"this program again"))

				 let mv_lextype="C"
				let mv_lexdialect=""
			end if
			CALL set("PG_ESQLC",lv_ecpg)
			exit menu

	end menu
end if

if mv_dbtype="Informix" then
	call info(set_lines(
			"Using Informix - you can get Aubit4GL to generate C or ESQL/C code",
			"ESQL/C uses Informix's 'esql' preprocessor to convert the ESQL/C code",
			"into C code - which then runs using native Informix libraries.",	
			" ",
			"C code generation will use the native database communicator.",
			" ",
			"We recommend you use 'EC' as it should be faster"
			))

	menu "Do you want to use 'EC' generation"
		
		command "Use ESQL/C"
			let mv_lextype="EC"
			let mv_lexdialect="INFORMIX"
			exit menu

		command "Use C"
			let mv_lextype="C"
			exit menu

	end menu
end if



end function


################################################################################
function has_plugin(lv_type,lv_value)
define lv_type,lv_value char(50)
define lv_ok integer
code
{
A4GL_trim(lv_type);
A4GL_trim(lv_value);
lv_ok=A4GL_dl_has_library(lv_type,lv_value);
}
endcode
return lv_ok
end function


################################################################################
function fail(lv_str)
define lv_str char(80)
display lv_str  clipped
exit program 2
end function

################################################################################
function file_exists(lv_name)
define lv_name char(256)
define lv_ok integer
code
{
A4GL_trim(lv_name);
lv_ok=A4GL_file_exists(lv_name);
}
endcode
return lv_ok
end function

################################################################################
function directory_exists(lv_name)
define lv_name char(256)
define lv_ok integer
code
{
A4GL_trim(lv_name);
lv_ok=A4GL_directory_exists(lv_name);
}
endcode
return lv_ok
end function


################################################################################
function warn(lv_nlines)
define lv_nlines integer
define a integer
define lv_dummy integer
display " ","" at 2,1
display " ","" at 4,1
open window w_warn at mv_top,mv_left with (mv_height+3) rows, (mv_width) columns attribute(border)

call banner("WARNING","MAGENTA,REVERSE")

for a=1 to lv_nlines
	display lv_msglines[a] at a+2,1
end for
call button("[ OK ]","MAGENTA,REVERSE")
call fgl_getkey() returning lv_dummy
close window w_warn
end function

################################################################################
function hint(lv_nlines)
define lv_nlines integer
define a integer
define lv_dummy integer
display " ","" at 2,1
display " ","" at 4,1
open window w_hint at mv_top,mv_left with (mv_height+3) rows, (mv_width) columns attribute(border)

call banner("Hint","GREEN,REVERSE")

for a=1 to lv_nlines
	display lv_msglines[a] at a+2,1
end for
call button("[ OK ]","GREEN,REVERSE")
call fgl_getkey() returning lv_dummy
close window w_hint
end function

################################################################################
function err(lv_nlines)
define lv_nlines integer
define a integer
define lv_dummy integer
display " ","" at 2,1
display " ","" at 4,1
open window w_err at mv_top,mv_left with (mv_height+3) rows, (mv_width) columns attribute(border)

call banner("ERROR","RED,REVERSE")

for a=1 to lv_nlines
	display lv_msglines[a] at a+2,1
end for
call button("[ OK ]","RED,REVERSE")
call fgl_getkey() returning lv_dummy
close window w_err
end function


################################################################################
function ask(lv_caption, lv_question,lv_default, lv_nlines)
define lv_nlines integer
define lv_default char(3)
define lv_caption,lv_question char(80)
define a integer
define lv_dummy integer
define lv_answer char(1)
display " ","" at 2,1
display " ","" at 4,1
if length(lv_caption)>mv_width then
	let mv_width=length(lv_caption)
end if
if (length(lv_question)+14)>mv_width then
	let mv_width=length(lv_question)+14
end if

open window w_ask at mv_top,mv_left with (mv_height+4) rows, (mv_width) columns attribute(border, menu line last -1)

call banner(lv_caption,"CYAN,REVERSE")
for a=1 to lv_nlines
	display lv_msglines[a] at a+2,1
end for
call yes_no(lv_question,lv_default) returning lv_answer
close window w_ask
return lv_answer
end function

################################################################################
function info(lv_nlines)
define lv_nlines integer
define a integer
define lv_dummy integer
display " ","" at 2,1
display " ","" at 4,1
open window w_info at mv_top,mv_left with (mv_height+3) rows, (mv_width) columns attribute(border)

call banner("INFO","CYAN,REVERSE")

for a=1 to lv_nlines
	display lv_msglines[a] at a+2,1
end for
call button("[ OK ]","CYAN,REVERSE")
call fgl_getkey() returning lv_dummy
close window w_info
end function


################################################################################
function banner(lv_txt,lv_colour) 
define lv_left integer
define lv_txt char(400)
define lv_colour char(80)
define lv_title char(400)
let lv_title=" "
let lv_left=(mv_width-length(lv_txt))/2
let lv_title[lv_left,400]=lv_txt
display lv_title[1,mv_width] at 1,1 attribute(lv_colour)
end function

################################################################################
function button(lv_txt,lv_colour) 
define lv_colour char(80)
define lv_txt char(400)
define lv_left integer

let lv_left=(mv_width-length(lv_txt))/2
display lv_txt clipped at mv_height+3,lv_left attribute(lv_colour)

end function

################################################################################
function is_windows() 
if fgl_getenv("COMSPEC")!="" then
	return 1
end if

return 0
end function

code


int aclfgl_set_line_sizes(int n) {
int ntop;
int a;
int maxwidth=10;
int nlines;

	nlines=A4GL_pop_int();
	for (a=0;a<nlines;a++) {
		char buff[200];
		strcpy(buff, lv_msglines[a]);
		A4GL_trim(buff);
	        if (strlen(buff)>maxwidth) {
                	maxwidth=strlen(buff);
        	}

	}
mv_left=(mv_screenwidth-(maxwidth+2))/2;
mv_width=maxwidth;
mv_height=nlines;
A4GL_push_int(nlines);
return 1;

}


//################################################################################
int aclfgl_set_lines(int nlines) {
int ntop;
int a;
int maxwidth=10;
// +5 = 1 for title, +2 for border +2 for spacer line and 'continue button'..
mv_top=(mv_screenheight-(nlines+5))/2;


for (a=0;a<30;a++) {
	strcpy(lv_msglines[a],"    ");
}

for (a=1;a<=nlines;a++) {
	char *p;
	p=A4GL_char_pop();
	A4GL_assertion(strlen(p)>70,"string too long for aclfgl_set_lines");
	strcpy(lv_msglines[nlines-a],p);
	if (strlen(p)>maxwidth) {
		maxwidth=strlen(p);
	}
	free(p);
}
mv_left=(mv_screenwidth-(maxwidth+2))/2;
mv_width=maxwidth;
mv_height=nlines;
A4GL_push_int(nlines);
return 1;
}

endcode


################################################################################
function prompt_for(lv_asklong,lv_askshort)
define lv_askshort char(80)
define lv_asklong char(80)
define lv_response char(40)
let lv_response=" "
let int_flag=false
open window w_prompt at 3,2 with 4 rows, mv_screenwidth-2 columns attribute(border)
let mv_width=mv_screenwidth-2
call banner(lv_asklong,"CYAN,REVERSE")
prompt lv_askshort clipped for lv_response
if int_flag then
	let lv_response=" "
end if
close window w_prompt
return lv_response
end function




################################################################################
## Add a line to our msg buffer
## skip empty lines
## and lines that are already in the list
## return the next empty slot in the message buffer
## 
## This routine can be used when we want to hand code
## the exact lines - and not use 'warn' or 'info' etc..
################################################################################

function add_line(lv_startcnt,lv_str) 
define lv_startcnt integer
define lv_str char(80)
define a integer

if lv_str is null or lv_str matches " " then
	return lv_startcnt
end if

# is that string already there ? 
for a=1 to lv_startcnt-1
	if lv_str=lv_msglines[a] then
		return lv_startcnt
	end if
end for

let lv_msglines[lv_startcnt]=lv_str
return lv_startcnt+1
end function


################################################################################
function create_aclfile() 
define lv_db, lv_user,lv_pass char(100)
define lv_fname char(200)
define lv_ok integer

let lv_db=mv_dbname
let lv_user=mv_username
let lv_pass=mv_password
let lv_fname=fgl_getenv("A4GL_SQLACL")

if lv_fname is null or lv_fname=" " then
	let lv_fname=fgl_getenv("A4GL_ACLFILE")
end if

if lv_fname is null or lv_fname=" " then
	if is_windows() then
		# On windows the ACLFILE is stored in $AUBITDIR/etc/aubit4gl.acl, or c:\\aubit4gl\\aubit4gl.acl
		let lv_fname=fgl_getenv("AUBITDIR") clipped,"/etc/aubit4gl.acl"
	else
		if fgl_getenv("HOME")!=" " then
			let lv_fname=fgl_getenv("HOME") clipped,"/.aubit4gl.acl"
		else
			let lv_fname="/etc/aubit4gl.acl"
		end if
	end if
end if

if lv_fname is null or lv_fname=" "  then
	call warn(set_lines("Unable to determine a file location to store the ACLFILE!"))
	return 0
end if

if file_exists(lv_fname) then
	call warn(set_lines("The file : ",
		lv_fname clipped,
		"already exists - I'm not going to overwrite it!",
		"You should manually edit the file and add a line : ",
		lv_db clipped||":"||lv_user clipped||":"||lv_pass clipped
		))
		return 0
end if

code
{
FILE *f;
A4GL_trim(lv_fname);
A4GL_trim(lv_db);
A4GL_trim(lv_user);
A4GL_trim(lv_pass);

lv_ok=0;
f=fopen(lv_fname,"w");
if (f) {
	fprintf(f,"%s:%s:%s\n",lv_db,lv_user,lv_pass);
	fclose(f);
	lv_ok=1;
}
}
endcode
return lv_ok

end function



function yes_no(lv_txt,lv_default)
define lv_yn char(1)
define lv_txt char(80)
define lv_default char(3)

menu lv_txt 
	before menu
		if lv_default[1]="Y" then
			next option "Yes"
		end if
		if lv_default[1]="N" then
			next option "No"
		end if
	
	command "Yes"
		let lv_yn="Y"
		exit menu
	command "No"
		let lv_yn="N"
		exit menu
end menu

return lv_yn
end function




function ui_detection()
define lv_ui char(30)
menu "Do you want to run in Text Mode or GUI mode ?"
	command "Text Mode"
		let lv_ui="tui"
		exit menu

	command "GUI Mode"
		let lv_ui="gui"
		exit menu
	command "Batch Mode" "This mode can be used for batch jobs (cron/cgi-bin etc)"
		let lv_ui="CONSOLE"
			exit menu
end menu


if lv_ui="gui" then
	call info(set_lines(
			"There are two GUI options",
			" " ,
			"A 'thick' client front end written using GTK",
			" ",
			"or a thin client GUI using an XML protocol",
			"with this UI - the 4GL application and the display may",
			"be on different machines"
		))

	menu "Which GUI do you want to use ? "
			command "GTK"
				if has_plugin("UI","HL_GTK") then
					let lv_ui="HL_GTK"
					exit menu
				else
					call err(set_lines( "The HL_GTK module doesn't exist!"))
				end if

			command "Thin Client"
				if has_plugin("UI","XML") then
					let lv_ui="XML"
					exit menu
				else
					call err(set_lines( "The XML module doesn't exist!"))
				end if

			command "Use Text mode"
				let lv_ui="tui"
				exit menu
	end menu
end if

if lv_ui="tui" then
	if mv_need_wide then
		if has_plugin("UI","TUI_wide") and lv_ui="tui" then
			let lv_ui="TUI_wide"
		end if
	else
		## Dont need wide characters..
		if has_plugin("UI","TUI") and lv_ui="tui" then
			let lv_ui="TUI"
		end if

		if has_plugin("UI","HL_TUI") and lv_ui="tui" then
				let lv_ui="HL_TUI"
		end if

		if has_plugin("UI","HL_TUIw") and lv_ui="tui" then # Windows TUI
				let lv_ui="HL_TUIw"
		end if
		
	end if
end if

if lv_ui="tui" or lv_ui="gui" then
		call warn(set_lines(
				"Unable to determine the UI module to use!!"
			))
		let lv_ui="CONSOLE"
end if
let mv_ui=lv_ui
end function



function misc() 
define lv_keyname char(20)
define lv_keyvalue integer
define lv_mantis_user,lv_mantis_pass,lv_mantis_proj char(40)
define lv_filename char(80)
	if has_plugin("PACKER","PACKED") then
		call set ("A4GL_PACKER","PACKED")
		call set ("A4GL_FORMTYPE","GENERIC")
	else
		if has_plugin("FORMTYPE","XDR") then
			call set("A4GL_FORMTYPE","XDR")
		end if
	end if

	if mv_lextype="EC" then
		# Probably a good idea to have these too...
		call set("A4GL_ESQL_UNLOAD","N")
		call set("A4GL_USE_INDICATOR","Y")
	end if

	if yes_no("Do you want to set some of the more advanced settings?","Y")="Y" then
		if yes_no("Do you want to attach to GDB whenever there is a segfault?","N")="Y" then
			call set ("A4GL_GDB_ATTACH","Y")
		else
			call set ("A4GL_GDB_ATTACH","Y")
		end if

		if yes_no("Do you want to auto-intialize variables to NULL/0 as per Informix RDS","Y")="Y" then
			call set("A4GL_AUTONULL","Y")
		else
			call set("A4GL_AUTONULL","N")
		end if
		
		if ask("Function renaming", "Do you wan to disable function renaming","N", set_lines(
					" ",
					"Aubit4GL will normally automatically prepend function names with ",
					"'aclfgl_'  - this is done to ensure that functions do not clash ",
					"with the standard functions built into C. ",
					" ",
					"However - if you are linking with 'C' routines then you will ",
					"typically need to rename these to have the same 'aclfgl_' prefix, ",
					"or use 'IMPORT INFORMIX C FUNCTION' in your 4gl module to create a ",
					"marshalling function.",
					" ",
					"Alternatively - You can disable this feature by setting ",
					"A4GL_NOCLOBBER' and then no function renaming will be done -",
					 "but no protection is then provided",
					" "
				))="Y"  then

			call set("A4GL_NOCLOBBER","Y")
		else
			call hint(set_lines(
				"Remember!",
				"If you get problems with linking to C function - you might need ",
				"to set this - or generate function linkages ",
				"(or compile with 4glpc -N etc)"
			))
			call set("A4GL_NOCLOBBER","N")
		end if


		if yes_no("Do you want to emulate the Informix Form extensions (.frm) ?","N")="Y" then
			call set("A4GL_FRM_BASE_EXT",".frm")
			call set("A4GL_PACKED_EXT","")
		end if
		

		if ask ("Error Logging","Do you want to enable extended error file logging ?","Y",set_lines(
				"Aubit4GL can write backtraces etc to the error log file",
				"when an error occurs",
				"This is normally a 'good' thing unless you have a program or process",
				"that reads these files and looks for the Informix4GL style files",
				" "
		))="Y" then
				call set("EXTENDED_ERRORLOG","Y")
		end if

		let lv_keyvalue=0
		if yes_no("Do you want to enable an automatic 'Print Screen' key ?","N")="Y" then
			while true
				call prompt_for("Enter key name for Print Screen","Key ?") returning lv_keyname
				if lv_keyname is null or lv_keyname=" " then
					let lv_keyvalue=0
					exit while
				end if
				let lv_keyvalue=fgl_keyval(lv_keyname)
				if lv_keyvalue<=0 then
					call err (set_lines("That isn't a valid key!"))
				else
					call set("A4GL_PRINTSCRKEY",lv_keyname)
					exit while
				end if
			end while
			
			if lv_keyvalue>0 then
				menu "Where do you want the print to go ? "
				command "A file"
					call prompt_for("Enter filename to write to","File >>") returning lv_filename
					if lv_filename!=" " then
						call set("A4GL_PRINTSCRFILE",lv_filename)
					else 
						call err(set_lines("Not set.",
								"You can manually set A4GL_PRINTSCRFILE..."))
					end if
					exit menu

				command "A command pipe"
					call prompt_for("Enter filename to write to","File >>") returning lv_filename
					if lv_filename!=" " then
						call set("A4GL_PRINTSCRFILE","|"||lv_filename)
					else 
						call err(set_lines("Not set.",
								"You can manually set A4GL_PRINTSCRFILE..."))
					end if
					exit menu
				end menu
			end if
		end if


		if ask("Mantis Integration", "Do you want to enable automatic error logging into Mantis","N",set_lines(
					"Aubit4GL can automatically add bugs to a bug tracking system for",
					"handling application errors.",
					"this logs a screen dump, function backtrace, last key pressed etc",
					" ",
					"Automatic Mantis entry requires a valid support contract",
					"with Aubit Computing Ltd",
					"You will also require a valid 'errhook_mantis' plugin", " "
		))="Y" then
		
		
				if yes_no("Do you have a valid support contract?","Y")="Y" then
					call set("CALLERRHOOK","errhook_mantis")
					call prompt_for("Please enter your mantis Username",   "Username >>") returning lv_mantis_user
					call prompt_for("Please enter your mantis Password",   "Password >>") returning lv_mantis_pass
					call prompt_for("Please enter your mantis Project ID", "ProjID   >>") returning lv_mantis_proj

					call set("MANTIS_USERNAME", lv_mantis_user)
					call set("MANTIS_PASSWORD", lv_mantis_pass)
					call set("MANTIS_PROJECTID", lv_mantis_proj)
				end if
		end if

		if ask("ERRORLOG", "Do you want the files restarted each run","N",set_lines(
			######################################################################
			"Informix4GL appens to the Error log each time an application",
			"is run.",
			"Aubit4GL can replicate this behaviour - but the error log files",
			"can quickly become quite large. Aubit4GL can therefore 'restart'",
			" the log files each time the program starts that way, the file ",
			"will only contain the latest details"," "))="Y" then

			call set("A4GL_RESTARTLOG","Y")
		end if

	end if # Advanced options



	if yes_no("Want to know about some advanced features?","Y")="Y" then

		if ask("Extra Logging", "Do you want to set ERRLOG_CONTINUE_ERRORS","N", set_lines(
			"Aubit4GL has some advanced features to help you debug your ",
			"applications.",
			" ",
			"Setting ERRLOG_CONTINUE_ERRORS will log *all* SQL errors",
			"to the errorlog - even when you have WHENEVER ERROR CONTINUE set"," "))="Y" then
			
			call set("ERRLOG_CONTINUE_ERRORS","Y")
		end if

		call hint(set_lines(
				######################################################################
				"              Automatic key logging/replay",
				" ",
				"Aubit4GL can record and replay keystrokes in your 4gl application",
				"Simply set A4GL_KEYLOG to point to a file to write the key",
				"strokes to",
				"*Or* set A4GL_KEYFILE to the file containing the keystrokes you",
				"need to replay. If you need to slow down the keystrokes - set",
				"A4GL_KEYDELAY=1000000 (or the number of microseconds between",
				"keystrokes)"
		))
			
		call hint(set_lines(
			"Setting TRACE4GLEXEC to a filename will store a live call tree history",
			"when a 4gl application runs",
			"You can use the program 'dot' from the 'graphviz' package to produce",
			"some nice and useful diagrams that show how the program executed - ",
			"which functions were called in which order etc"))

		call hint(set_lines(
			"Aubit4GL will automatically record a 'hash' code for all the",
			"tables used in a DEFINE RECORD LIKE or a DEFINE LIKE",
			"These are used to ensure that the table has not changed",
			"between when the program is compiled and when the program is run",
			"You can disable this check by setting CHECKTABLEVERSIONS=N"))

		call hint(set_lines(
			"When you compile a 4gl module - Aubit4GL will embed an 'ident'",
			"string in the code.",
			"You can read the ident strings from the compiled application",
			"by using the 'ident' program available on most Unix/Linux",
			"machines",
			"You can embed your own project details in the ident string",
			"by setting the LOG_TEXT variable."
		))


		call hint(set_lines(
			"You can use 'gdb' to debug your 4gl application",
			"Just set INCLINES=Y and Aubit4GL will include line",
			"information needed by gdb.",
			"Then use '-g' when you compile your application to",
			"include the C debugging symbols and your should be",
			"able to trace through your application"
			))

	end if

end function


function set(lv_n,lv_v)
define lv_n,lv_v char(2000)
output to report r_settings (lv_n,lv_v)
end function


report r_settings(lv_n,lv_v)
define  lv_n,lv_v char(2000)
output
	top margin 0
	bottom margin 0
	page length 1
	left margin 0
format
	on every row
		print lv_n clipped,"=",lv_v clipped
		print "export ",lv_n clipped
end report

