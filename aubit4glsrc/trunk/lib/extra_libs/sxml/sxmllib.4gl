

code
#include "sxml.h"
endcode


function sxml_free_tree(lv_xml) 
define lv_xml integer
code
{
SXML *x;
x=(SXML *)lv_xml;
sxml_free_tree(&x);
}
endcode

end function

function sxml_readfile(fname)
define fname char(255)
define lv_xml integer
define lv_ok integer
code
{
SXML *x;
lv_ok=1;
A4GL_trim(fname);
x=(SXML *)lv_xml;
if (sxml_readfile(fname, &x)) lv_ok=0;
}
endcode
if lv_ok then
	return lv_xml
else
	return 0
end if
end function

function sxml_writefile(fname,lv_xml)
define fname char(255)
define lv_xml integer
define lv_ok integer
code
lv_ok=1;
A4GL_trim(fname);
if (sxml_writefile(fname, (SXML *)lv_xml)) lv_ok=0;
endcode
return lv_ok
end function


function sxml_get_next(lv_xml, lv_key,n)
define lv_xml,n integer
define lv_key char(255)
code
A4GL_trim(lv_key);
lv_xml=(int)sxml_get_next((SXML *)lv_xml,lv_key,n);
endcode
return lv_xml
end function




function sxml_get_sub(lv_xml, lv_key,n)
define lv_xml,n integer
define lv_key char(255)
code
A4GL_trim(lv_key);
lv_xml=(int)sxml_get_sub((SXML *)lv_xml,lv_key,n);
endcode
return lv_xml
end function


function sxml_get_value(lv_xml,lv_key,n)
define lv_xml,n integer
define lv_key char(255)
define lv_value char(1024)
code
{
char *ptr;
A4GL_trim(lv_key);
ptr=sxml_get_value((SXML *)lv_xml,lv_key,n);

if (ptr) strcpy(lv_value,ptr);
else strcpy(lv_value,"");

}
endcode
return lv_value
end function



function sxml_get_xml_as_text(lv_head,lv_xml) 
define lv_head char(512)
define lv_xml integer
define lv_rval char(32000)
let lv_rval=""
code
{
static char *ptr=0;

A4GL_trim(lv_head);
if (sxml_createbuf(&ptr,lv_head,(SXML *)lv_xml)>= 32000)  {
	strcpy(lv_rval,"");
} else {
	strcpy(lv_rval,ptr);
}

}
endcode
return lv_rval
end function


function sxml_put_next(lv_xml,name)
define lv_xml integer
define name char(255)
code
{
SXML *x;
A4GL_trim(name);
x=(SXML *)lv_xml;
lv_xml=(int)sxml_put_next(&x,name);
}
endcode
return lv_xml
end function




function sxml_put_sub(lv_xml,name)
define lv_xml integer
define name char(255)
code
{
SXML *x;
A4GL_trim(name);
x=(SXML*)lv_xml;
lv_xml=(int)sxml_put_sub(&x,name);
}
endcode
return lv_xml
end function



function sxml_put_value(lv_xml,value)
define lv_xml integer
define value char(255)
code
A4GL_trim(value);
sxml_put_value((SXML *)lv_xml,value);
endcode
end function



function sxml_curr_errstr()
define lv_errbuff char(255)
let lv_errbuff=sxml_errstr(sxml_get_errno())
return lv_errbuff
end function


function sxml_errstr(n)
define n integer
define lv_errbuff char(255)
code
strcpy(lv_errbuff,sxml_errstr(n));
endcode
return lv_errbuff
end function


function sxml_get_errno()
define n integer
code
n=sxml_errno;
endcode
return n
end function



