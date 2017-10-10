
#database syspgma4gl

define lc_max_password_length constant 48

main
char lv_dbname(64)
defer interrupt
let lv_dbname=get_syspgma4gl_dbname()
database lv_dbname
#options form line 5
options message line last

call form_is_compiled(f_webapp)
call form_is_compiled(f_webserver)
call form_is_compiled(f_webusers)
call form_is_compiled(finditnosql)
call form_is_compiled(findit)


call edit_web_settings()
end main


function edit_web_settings() 

--call clear_screen_portion()

menu "Web config"
	command "Web-Urls" "Setup configuration for web URLs"
		call web_urls()
	command "Applications" "Configure applications"
		call web_apps()
	command "Users" "Setup users/passwords for web use"
		call web_users()
	command "Exit" exit menu

end menu

end function



function dump_web_users(lv_urlId)
define lv_urlId char(18)
define lv_web_serverUrl record like web_serverUrl.*
define lv_web_perms record like web_perms.*
define lv_user record like  web_user.*
define lv_filename_passwd char(255)
define lv_filename_access char(255)
define lv_filename_xml char(255)
define lv_username char(18)
define lv_password char(18)
define lv_users chaR(2048)
define lv_first integer
define lv_runstr chaR(512)
define app_buff char(1024)
define lv_web_application record like web_application.*

select * into lv_web_serverUrl.* 
from web_serverUrl 
where Url_Id=lv_urlId

if sqlca.sqlcode=100 then
	error "Server : ",lv_urlId clipped," not found"
	sleep 1
	return
end if

let lv_first=true

let lv_filename_xml= lv_web_serverUrl.xmlfile

if lv_filename_xml is null or lv_filename_xml matches " " then
	let lv_filename_xml="fglaccess_",lv_urlId clipped,".xml"
end if

if lv_web_serverUrl.AuthMode="W" then
	let lv_filename_passwd=lv_web_serverUrl.htpasswdfile
	let lv_filename_access=lv_web_serverUrl.htaccessfile
	
	if lv_filename_passwd is null or lv_filename_passwd matches " " then
		let lv_filename_passwd="htpasswd_",lv_urlId clipped
	end if
	if lv_filename_access is null or lv_filename_access matches " " then
		let lv_filename_access="htaccess_",lv_urlId clipped
	end if

	let lv_users=" "

	# Get rid of any existing files...
	call aclfgl_delete_file(lv_filename_passwd);
	call aclfgl_delete_file(lv_filename_access);

	declare c_wpweb cursor for 
		select distinct username from web_perms where lv_urlId matches Url_Id

	foreach c_wpweb into lv_username
		
		declare c_wusers cursor for
			select * from web_user 
				where username matches lv_username

		foreach c_wusers into lv_user.* 
			let lv_password=aclfgl_tea_string_decipher(lv_user.password)


			# If a user is allocated to multiple applications - then this will execute multiple times..
			# atm - we dont care - but we might want to filter it out later one....

			# Add our new entry in 'batch' mode...
			if lv_first then
				let lv_runstr= "htpasswd -c -b '"||lv_filename_passwd clipped||"' '"||lv_user.username clipped||"' '"||lv_password clipped||"'"
				let lv_first=false
			else
				let lv_runstr= "htpasswd -b '"||lv_filename_passwd clipped||"' '"||lv_user.username clipped||"' '"||lv_password clipped||"'"
			end if

			display lv_runstr clipped
			run lv_runstr clipped

			#sleep 1

			let lv_users=lv_users clipped, " ",lv_user.username
		end foreach

	end foreach

	call channel::open_file("htaccess", lv_filename_access clipped,"w")
	call channel::write("htaccess","AuthType Basic")
	call channel::write("htaccess","AuthName \"4GL Application ACL for " || lv_urlId clipped||"\"")
	call channel::write("htaccess","AuthUserFile "||lv_filename_passwd)
	#call channel::write("htaccess","Require user "||lv_users)
	call channel::write("htaccess","Require valid-user")
	call channel::close("htaccess")
end if
sleep 1

call channel::open_file("fglaccess",lv_filename_xml,"w")

declare c_wp cursor for 
	select distinct web_application.application 
	from web_perms, web_application  
	where lv_urlId matches Url_Id 
	and web_application.application matches web_perms.application

call channel::write("fglaccess","<?xml version=\"1.0\"?>")
call channel::write("fglaccess","<Configuration Name=\""||lv_urlId clipped||"\" AuthMode=\""||lv_web_serverUrl.AuthMode||"\">")
call channel::write("fglaccess"," <Applications>");

foreach c_wp into lv_web_perms.application

	if lv_web_perms.application="*" then
		error "Unexpected..." sleep 10
		continue foreach
	end if

	initialize lv_web_application.* to null

	select * into lv_web_application.* 
	from web_application
	where application=lv_web_perms.application

	case lv_web_application.connmode

		when "P" 
			let app_buff="connMode=\"", lv_web_application.connMode,"\"",
					" ProgramName=\"", xml_encode(lv_web_application.pxy_ProgramName),"\"",
					" Server=\"", xml_encode(lv_web_application.pxy_server),"\"",
					" Port=\"", xml_encode(lv_web_application.pxy_port),"\"",
					" Username=\"", xml_encode(lv_web_application.pxy_username),"\"",
					" Password=\"", xml_encode(lv_web_application.pxy_password),"\""

		when "S" 
			let app_buff="connMode=\"", lv_web_application.connMode,"\"",
					" ProgramName=\"", xml_encode(lv_web_application.pxy_ProgramName),"\"",
					" Server=\"", xml_encode(lv_web_application.pxy_server),"\"",
					" Port=\"", xml_encode(lv_web_application.pxy_port),"\"",
					" Username=\"", xml_encode(lv_web_application.pxy_username),"\"",
					" Password=\"", xml_encode(lv_web_application.pxy_password),"\""
		when "C"
			let app_buff="connMode=\"", lv_web_application.connMode,"\" cmdLine=\"",xml_encode(lv_web_application.auth_cmdline),"\""

		otherwise 
			error "Invalid connection mode"
	end case
			
		

	call channel::write("fglaccess","  <Application Name=\""||lv_web_perms.application clipped||"\" "||app_buff clipped||">")
	call channel::write("fglaccess","   <Users>");

	#call channel::write("fglaccess","   <!-- "|| lv_urlId clipped ||","|| lv_web_perms.application ||","||lv_web_application.application||" --!>")

	declare c_wp2 cursor for
		select distinct web_user.username,password from web_perms,web_user 
			where lv_urlId matches Url_Id
			and lv_web_perms.application matches application
			and web_user.username matches web_perms.username

	foreach c_wp2 into lv_username,lv_password
			call channel::write("fglaccess","    <User Name=\""||lv_username clipped||"\" Password=\""||xml_encode(lv_password clipped)||"\"/>")
	end foreach

	call channel::write("fglaccess","   </Users>");
	call channel::write("fglaccess","  </Application>")

	# Dump the stuff...

end foreach
call channel::write("fglaccess"," </Applications>");
call channel::write("fglaccess","</Configuration>")

call channel::close("fglaccess")
message "File(s) have been dumped"
end function





function web_users() 
define lv_arr array[100] of record
	username char(18),
	password char(lc_max_password_length)
end record
define lv_cnt integer
define lv_arrline integer
define lv_val char(lc_max_password_length)
define lv_newval char(lc_max_password_length)

open window w_users at 4,1 with form "f_webusers"
declare c_loadusrs cursor for
	select * from web_user
	order by username
let lv_cnt=1
foreach c_loadusrs into lv_arr[lv_cnt].*
	let lv_cnt=lv_cnt+1
end foreach

let lv_cnt=lv_cnt-1


let int_Flag=false
call set_count(lv_cnt)

options message line 1
input array lv_arr without defaults from srec1.*

before field password
	let lv_arrline=arr_curr()
	let lv_val=lv_arr[lv_arrline].password

on key(control-b)
	if infield(password) then
		let lv_arrline=arr_curr()
		let lv_newval=lv_arr[lv_arrline].password 
		message "Password:",aclfgl_tea_string_decipher(lv_newval) attribute(blue)
		sleep 1
	end if

after field password
	let lv_arrline=arr_curr()
	let lv_newval=lv_arr[lv_arrline].password 


		if lv_val is null then
			let lv_val=" "
		end if
		if lv_newval is null then
			let lv_newval=" " 
		end if
	if lv_val!=lv_newval then

			if length(aclfgl_tea_string_encipher(lv_newval)) > lc_max_password_length then
				error "Password is too long :", length(aclfgl_tea_string_encipher(lv_newval))
				next field password
			end if

		if length(lv_newval)> 18 then
			error "Field is too long -  Unencrypted password must be <= 18 characters"
			next field password
		else
			let lv_val= aclfgl_tea_string_encipher(lv_newval)
			let lv_arr[lv_arrline].password=lv_val
			display lv_val to srec1[scr_line()].password
		end if
	end if
end input

if int_flag=false then
	delete from web_user

	for lv_cnt=1 to arr_count()

		if lv_arr[lv_cnt].password is not null and lv_arr[lv_cnt].password not matches " " 
			and  lv_arr[lv_cnt].username is not null and lv_arr[lv_cnt].username not matches " " then 
				insert into web_user values( lv_arr[lv_cnt].username, lv_arr[lv_cnt].password)
		end if
	end for
end if

close window w_users

end function


################################################################################

function web_perms(lv_urlId,lv_editmode)
define lv_urlId char(18)
define lv_arrline integer
define lv_newval char(256)
define lv_editmode char(1)

define lv_arr array[100] of record
	application char(18),
	username char(18)
end record
define lv_cnt integer


declare c_loadperms cursor for
	select application,username from web_perms
	where url_id=lv_urlid
	order by application,username


for lv_cnt=1 to 6 
	clear srec_perms[lv_cnt].*
end for


let lv_cnt=1

foreach c_loadperms into lv_arr[lv_cnt].*
	if lv_cnt<6 then
		display lv_arr[lv_cnt].* to srec_perms[lv_cnt].*
	end if
	let lv_cnt=lv_cnt+1
end foreach

let lv_cnt=lv_cnt-1

if lv_editmode="N" then
	return
end if

let int_Flag=false
call set_count(lv_cnt)

INPUT ARRAY lv_arr WITHOUT DEFAULTS FROM srec_perms.*

	ON KEY(f1,control-b)
		IF INFIELD(username) THEN
			LET lv_arrline=arr_curr()
			LET lv_newval=lv_arr[lv_arrline].username
			CALL zoom("username", get_fldbuf(username)) RETURNING lv_newval
			LET lv_arr[lv_arrline].username=lv_newval
			DISPLAY lv_arr[lv_arrline].username TO srec_perms[scr_line()].username
		END IF
	
		IF INFIELD(application) then
			LET lv_arrline=arr_curr()
			LET lv_newval=lv_arr[lv_arrline].application
			CALL zoom("application", get_fldbuf(application)) RETURNING lv_newval
			LET lv_arr[lv_arrline].application=lv_newval
			DISPLAY lv_arr[lv_arrline].application TO srec_perms[scr_line()].application
		END IF

          AFTER FIELD username
			LET lv_arrline=arr_curr()
                    IF NOT validate_column("username*",lv_arr[lv_arrline].username,1) THEN
                       NEXT FIELD username
                    END IF

          AFTER FIELD application
			LET lv_arrline=arr_curr()
                    IF NOT validate_column("application*",lv_arr[lv_arrline].application,1) THEN
                       NEXT FIELD application
                    END IF


	AFTER INPUT
		IF int_flag=false THEN
			LET lv_arrline=arr_curr()
                    IF NOT validate_column("username*",lv_arr[lv_arrline].username,1) THEN
                       NEXT FIELD username
                    END IF
                    IF NOT validate_column("application*",lv_arr[lv_arrline].application,1) THEN
                       NEXT FIELD application
                    END IF
		END IF
END INPUT

if int_flag=false then 

	delete from web_perms where url_id=lv_urlId

	for lv_cnt=1 to arr_count()
		if lv_arr[lv_cnt].application is not null and lv_arr[lv_cnt].application not matches " " 
			and  lv_arr[lv_cnt].username is not null and lv_arr[lv_cnt].username not matches " " then 
				insert into web_perms values( lv_urlId, lv_arr[lv_cnt].application, lv_arr[lv_cnt].username)
		end if

	end for
end if



end function


code
static char *
xml_escape_int (char *s)
{
  static char *buff = 0;
  static int last_len = 0;
  int c;
  int a;
  int l;
  int b;
  int allocated;


  c = 0;
  //if (s==0) return "";

  if (strchr (s, '&'))
    c++;
  if (strchr (s, '<'))
    c++;
  if (strchr (s, '>'))
    c++;
  if (strchr (s, '"'))
    c++;
  if (strchr (s, '\''))
    c++;
  if (strchr (s, '\n'))
    c++;
  if (strchr (s, '\r'))
    c++;


  if (c == 0)
    {
      return s;
    }

  l = strlen (s);
  allocated = (l * 6) + 1;

  if (l > last_len)
    {
      buff = realloc (buff, allocated);
      last_len = l;
    }

  b = 0;
  for (a = 0; a < l; a++)
    {
      if (s[a] == '>')
	{
	  buff[b++] = '&';
	  buff[b++] = 'g';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '<')
	{
	  buff[b++] = '&';
	  buff[b++] = 'l';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '&')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'm';
	  buff[b++] = 'p';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '"')
	{
	  buff[b++] = '&';
	  buff[b++] = 'q';
	  buff[b++] = 'u';
	  buff[b++] = 'o';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '\'')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'p';
	  buff[b++] = 'o';
	  buff[b++] = 's';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] < 31 || s[a] > 126)
	{
	  int z1;
	  char buff2[20];
	  z1 = ((unsigned char) s[a]);
	  sprintf (buff2, "&#x%02X;", z1);
	  for (z1 = 0; z1 < strlen (buff2); z1++)
	    {
	      buff[b++] = buff2[z1];
	    }
	  continue;
	}
      buff[b++] = s[a];
    }
if (b>=allocated) {

fprintf(stderr,"b=%d allocated=%d l=%d\n", b,allocated,l);
}
  if (b >= allocated ) {
	fprintf(stderr, "XML escape buffer too small") ;
	exit(2);
  }
  buff[b] = 0;
  return buff;
}
endcode


function xml_encode(lv_s)
define lv_s char(512)
define lv_snew char(1024)
code
	A4GL_trim(lv_s);
	strcpy(lv_snew,xml_escape_int(lv_s));
endcode
return lv_snew clipped
end function
