
function connection_menu()
menu "CONNECTION" 
        BEFORE MENU
                call display_banner()

	command "Connect" 	"Connect to a database environment."
		call connection_connect()

	command "Disconnect" 	"Disconnect from the current database environment."
		call connection_disconnect()

	command "Exit" 		"Returns to the DB-Access Menu."
	exit menu

end menu
end function


function connection_disconnect()
menu "DISCONNECT" 
	command "Yes" "Disconnect from current database environment."
		call do_disconnect()
		exit menu

	command "No"  "Do not disconnect from current database environment."
		exit menu
end menu
end function

function do_disconnect()
	whenever error continue
	close database
	call check_and_report_error()
	call set_curr_db("")
	call display_banner()
end function	



function connection_connect()
define lv_informixdir char(255)
define lv_passwd char(255)
define lv_username char(255)
define lv_cnt integer
define lv_server char(80)
define a,x,y integer
define buff char(255)
let lv_informixdir=fgl_getenv("INFORMIXDIR")
let lv_cnt=1
clear screen
call display_banner()
#
# In order to find out what connections are available
# Have a look in the sqlhosts file
#
code
{
char fname[1024];
FILE *f_in;
char *ptr;
A4GL_trim(lv_informixdir);
sprintf(fname,"%s/etc/sqlhosts",lv_informixdir);
f_in=fopen(fname,"r");
if (f_in!=0)  {
	while (1) {
		if (feof(f_in)) break;
		fgets(buff,sizeof(buff),f_in);
		ptr=strchr(buff,'#'); if (ptr) {*ptr=0;}
		ptr=strchr(buff,' '); if (ptr) {*ptr=0;}
		ptr=strchr(buff,'\t'); if (ptr) {*ptr=0;}
		A4GL_trim(buff);
		if (strlen(buff)) {
			A4GL_debug("SQLHOSTS - buff='%s' (%d)",buff,strlen(buff));
endcode
				call  set_pick(lv_cnt,buff)
code
			//strcpy(mv_arr[lv_cnt-1],buff);
			lv_cnt++;
		}
	}
}
fclose(f_in);
}
endcode
call set_pick_cnt(lv_cnt-1)
if lv_cnt=1 then
	error "Either the SQLHOSTS file cannot be read - or it is empty"
end if

let lv_server=prompt_pick("SELECT DATABASE SERVER >>","")

if lv_server is null or lv_server matches " " then
	return
end if

prompt "USER NAME >> " for lv_username

if lv_username is null or lv_username=" " then
else
	prompt "PASSWORD >> " for lv_passwd
	if lv_passwd is null or lv_passwd matches " " then
		initialize lv_username to null
	end if
end if


# 



code
{
static char buff[1024];
A4GL_trim(lv_server);
sprintf(buff,"INFORMIXSERVER=%s",lv_server);
putenv(buff);
}
endcode

call set_username(lv_username,lv_passwd)

call select_db()
end function

