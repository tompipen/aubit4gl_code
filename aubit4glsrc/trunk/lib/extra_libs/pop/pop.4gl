# This module required libspopc
# http://brouits.free.fr/libspopc/
code
#include "libspopc.h"
char *errmsg;
static popsession *lv_mysession=0;
void A4GLUI_initlib() {
}
endcode


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
