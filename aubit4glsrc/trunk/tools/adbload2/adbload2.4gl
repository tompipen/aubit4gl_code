pragma force ui "CONSOLE"

GLOBALS 
define lv_testmode integer
define lv_errs integer
define lv_commit integer
define lv_lockit integer
define lv_skip integer
END GLOBALS


define lv_dbname char(256)
define lv_cmdfile char(256)
define lv_logfile char(256)

define lv_promptifbad integer
define lv_allowhex integer

code
FILE *logfile=0;
endcode

main
define a integer
define lv_open integer
let lv_errs=10
let lv_skip=0
let lv_lockit=0
let lv_commit=100
let lv_promptifbad=0
let lv_testmode=0
let lv_allowhex=0



for a=1 to num_args()

	if arg_val(a)="-k" then
		let lv_lockit=1
		continue for
	end if
	
	if arg_val(a)="-r" then
		let lv_lockit=-1
		continue for
	end if
	
	if arg_val(a)="-p" then
		let lv_promptifbad=1
		continue for
	end if
	
	if arg_val(a)="-s" then
		let lv_testmode=1
		continue for
	end if

	if arg_val(a)="-X" then
		let lv_allowhex=1
		continue for
	end if
	
	if arg_val(a)="-e" then
		let a=a+1
		let lv_errs=arg_val(a)
		continue for
	end if

	if arg_val(a)="-d" then
		let a=a+1
		let lv_dbname=arg_val(a)
		continue for
	end if

	if arg_val(a)="-c" then
		let a=a+1
		let lv_cmdfile=arg_val(a)
		continue for
	end if

	if arg_val(a)="-n" then
		let a=a+1
		let lv_commit=arg_val(a)
		continue for
	end if
	
	if arg_val(a)="-l" then
		let a=a+1
		let lv_logfile=arg_val(a)
		continue for
	end if
	
	if arg_val(a)="-V" then
		display "A-DBLOAD: V1.0"
		exit program
	end if


	display "Unexpected option : ", arg_val(a)
	exit program 1
end for

if lv_dbname is null then
	prompt "Please enter database name : " for lv_dbname
end if

if lv_cmdfile is null then
	prompt "Please enter command file name : " for lv_cmdfile
end if

if lv_logfile is null then
	prompt "Please enter error log file name : " for lv_logfile
end if

if lv_logfile is null or lv_logfile matches " " then
	display "No logfile"
	exit program
end if

if lv_cmdfile is null or lv_cmdfile matches " " then
	display "No cmdfile"
	exit program
end if

if lv_dbname is null or lv_dbname matches " " then
	display "No database"
	exit program
end if

whenever error continue
database lv_dbname
whenever error stop

if sqlca.sqlcode!=0 then
	display "Unable to connect to database:",sqlca.sqlcode
	exit program 1
end if






if not open_logfile() then
	display "Unable to open logfile"
	exit program 2
end if

if process(lv_cmdfile) then
	# all done ok...
else
	display "Some problems with file"
	exit program 3
end if


code
	A4GL_assertion(logfile==0,"Log file not open");
	fclose(logfile);
endcode

if lv_errs then
	display "File(s) loaded but with some errors"
end if
end main



code
void logerr(char *fname,int n, int cmdline, char *s) {
	A4GL_assertion(logfile==0,"Log file not open");
	fprintf(logfile,"Error Command file line %d, Load File:%s,Load Line:%d - %s\n",
		cmdline,fname,n,s);
}
endcode


function open_logfile()
define lv_open integer
code
	A4GL_trim(lv_logfile);
	logfile=fopen(lv_logfile,"w");
	if (logfile) lv_open=1;
	else lv_open=0;
endcode
return lv_open
end function


function unlock_table(lv_tabname) 
define lv_tabname char(256)
define lv_str char(156)

if lv_lockit!=-1 then
	let lv_str="UNLOCK TABLE ",lv_tabname
	PREPARE p_unlockit FROM lv_str
	EXECUTE p_unlockit
end if

end function

function lock_table(lv_tabname)
define lv_tabname char(256)
define lv_str char(256)
if lv_lockit!=-1 then
	if lv_lockit=0 then
		let lv_str="LOCK TABLE ",lv_tabname," IN SHARE MODE"
	else
		let lv_str="LOCK TABLE ",lv_tabname," IN EXCLUSIVE MODE"
	end if
	WHENEVER ERROR CONTINUE
	PREPARE p_lockit FROM lv_str
	if sqlca.sqlcode<0 then
		return 0
	end if

	EXECUTE lv_str
	if sqlca.sqlcode<0 then
		return 0
	end if
	WHENEVER ERROR STOP
end if
RETURN 1
end function
