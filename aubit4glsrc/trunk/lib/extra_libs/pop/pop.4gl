# This module required libspopc
# http://brouits.free.fr/libspopc/

code
#include "libspopc.h"
char *errmsg;
static popsession *lv_mysession=0;
void A4GLUI_initlib(void) ;
void A4GLUI_initlib(void) {
}

endcode

define msg_split_no integer
define msg_from char(256)
define msg_subject char(256)
define msg_to char(256)
define msg_cc char(256)
define msg_date char(256)

function popget(lv_msg,p_a)
define lv_msg integer
define p_a char(20)
let p_a=upshift(p_a)
call split_message(lv_msg)
case p_a
	when "FROM" 	return msg_from
	when "TO" 	return msg_to
	when "SUBJECT" 	return msg_subject
	when "CC" 	return msg_cc
	when "DATE" 	return msg_date
	when "SIZE" 	return popmsgsize(lv_msg)
end case
end function

function split_message(lv_msg) 
define lv_msg integer
define msg char(1000)

if msg_split_no=lv_msg then
	return
else
	let msg_split_no=lv_msg
	let msg=popgethead(lv_msg)
	
code
	A4GL_debug("MSG=%s",msg);
endcode
end if

let msg_subject="No subject"
let msg_from="No From"
let msg_to="No To"
let msg_cc=" "
let msg_date=" "

code
{
int markers[1000];
int a;
int c;
int l;
c=0;
markers[c++]=0;
l=strlen(msg);
for (a=0;a<l;a++) {
	if (msg[a]=='\n'||msg[a]=='\r') {
		A4GL_debug("MJA Found end... %d %d",markers[c-1],a);
		msg[a]=0;
		if (markers[c-1]==a) {markers[c-1]++;continue;}
		markers[c++]=a+1;
	}
}

A4GL_debug("%d newlines found",c);

for (a=0;a<c;a++) {
	if (strncasecmp(&msg[markers[a]],"Subject:",8)==0) 	{ strncpy(msg_subject,&msg[markers[a]+8],255); continue; }
	if (strncasecmp(&msg[markers[a]],"To:",3)==0) 		{ strncpy(msg_to,&msg[markers[a]+3],255); continue; }
	if (strncasecmp(&msg[markers[a]],"Date:",5)==0) 	{ strncpy(msg_date,&msg[markers[a]+5],255); continue; }
	if (strncasecmp(&msg[markers[a]],"CC:",3)==0) 		{ strncpy(msg_cc,&msg[markers[a]+3],255); continue; }
	if (strncasecmp(&msg[markers[a]],"From:",5)==0) 	{ strncpy(msg_from,&msg[markers[a]+5],255); continue; }
A4GL_debug("Unrecognised : %s",&msg[markers[a]]);
}

msg_subject[255]=0;
msg_to[255]=0;
msg_cc[255]=0;
msg_date[255]=0;
msg_from[255]=0;
}
endcode
	
	


end function


function poperr() 
define lv_errmsg char(256)
code
strcpy(lv_errmsg,errmsg);
endcode
return lv_errmsg
end function


function popbegin(p_server,p_user,p_password)
define p_server char(256)
define p_user,p_password char(64)
define lv_ok integer
code
A4GL_trim(p_server);
A4GL_trim(p_user);
A4GL_trim(p_password);
errmsg=popbegin(p_server,p_user,p_password,&lv_mysession);
if (errmsg==0&&lv_mysession) {
	lv_ok=1;
} else {
	lv_ok=0;
}
endcode
return lv_ok
end function


function popnum()
define a integer
code
if (lv_mysession) {
	a=popnum(lv_mysession);
} else {
	a=0;
}
endcode
return a
end function


function popbytes()
define lv_bytes integer
code
lv_bytes=popbytes(lv_mysession);
endcode
return lv_bytes

end function

function popmsgsize(lv_msg)
define lv_msg integer
define lv_size integer
code
lv_size=popmsgsize(lv_mysession,lv_msg);
endcode
return lv_size
end function

function popmsguid(lv_msg)
define lv_msg integer
define lv_str char(256)
code
strcpy(lv_str,popmsguid(lv_mysession,lv_msg));
endcode
return lv_str
end function


function popgetmsg(lv_msg)
define lv_msg integer
define lv_msgtxt char(255);
code
{
char *ptr;
ptr=popgetmsg(lv_mysession,lv_msg);
A4GL_push_param(ptr,256);
A4GLSTK_popFunction();
return 1;
}
endcode
return lv_msgtxt
end function

function popgethead(lv_msg)
define lv_msg integer
code
{
char *ptr;
ptr=popgethead(lv_mysession,lv_msg);
A4GL_push_param(ptr,256);
A4GLSTK_popFunction();
return 1;
}
endcode
end function


function popcancel()
code
popcancel(lv_mysession);
endcode
end function


function popend()
code
popend(lv_mysession);
lv_mysession=0;
endcode
end function


function popdelmsg(lv_msg)
define lv_msg integer
code
popdelmsg(lv_mysession,lv_msg);
endcode
end function
