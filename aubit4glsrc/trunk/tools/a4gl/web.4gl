database syspgma4gl

define lc_max_password_length constant 48

main
defer interrupt
options form line 5

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
		
		select * into lv_user from web_user where username matches lv_username

		let lv_password=aclfgl_tea_string_decipher(lv_user.password)

		# Add our new entry in 'batch' mode...
		if lv_first then
			let lv_runstr= "htpasswd -c -b '"||lv_filename_passwd clipped||"' '"||lv_username clipped||"' '"||lv_password clipped||"'"
			let lv_first=false
		else
			let lv_runstr= "htpasswd -b '"||lv_filename_passwd clipped||"' '"||lv_username clipped||"' '"||lv_password clipped||"'"
		end if
		display lv_runstr
		run lv_runstr

		sleep 4

		let lv_users=lv_users clipped, " ",lv_username

	end foreach

	call channel::open_file("htaccess", lv_filename_access clipped,"w")
	call channel::write("htaccess","AuthType Basic")
	call channel::write("htaccess","AuthName \"4GL Application ACL for " || lv_urlId clipped||"\"")
	call channel::write("htaccess","AuthUserFile "||lv_filename_passwd)
	#call channel::write("htaccess","Require user "||lv_users)
	call channel::write("htaccess","Require valid-user")
	call channel::close("htaccess")
end if

call channel::open_file("fglaccess",lv_filename_xml,"w")

declare c_wp cursor for 
	select distinct application from web_perms where lv_urlId matches Url_Id

foreach c_wp into lv_web_perms.application

	call channel::write("fglaccess","<Application Name=\""||lv_web_perms.application clipped||"\">")

	declare c_wp2 cursor for
		select distinct web_user.username,password from web_perms,web_user 
			where lv_urlId matches Url_Id
			and application=lv_web_perms.application
			and web_user.username matches web_perms.username

	foreach c_wp2 into lv_username,lv_password
			call channel::write("fglaccess","<User Name=\""||lv_username clipped||"\" Password=\""||lv_password clipped||"\"/>")
	end foreach

	call channel::write("fglaccess","</Application>")

	# Dump the stuff...

end foreach

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

input array lv_arr without defaults from srec1.*

before field password
	let lv_arrline=arr_curr()
	let lv_val=lv_arr[lv_arrline].password

on key(control-b)
	if infield(password) then
		let lv_arrline=arr_curr()
		let lv_newval=lv_arr[lv_arrline].password 
		message aclfgl_tea_string_decipher(lv_newval)
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

let lv_cnt=1

clear srec_perms.*
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

