

code
#include <stdio.h>
endcode

function read_settings()
define lv_type  char(256)
let lv_type=fgl_getenv("A4GL_COMP_SETTINGS")
if lv_type is null or lv_type matches " " then
	return
end if
call read_pack(lv_type)
end function


function has_pack(lv_type)
define lv_type char(1024)
define lv_ok integer
let lv_type=fgl_getenv("AUBITDIR") clipped,"/tools/4glpc/settings/",lv_type clipped
code
{
FILE *fin;
lv_ok=1;
A4GL_trim(lv_type);
fin=fopen(lv_type,"r");
if (fin!=0) {fclose(fin); lv_ok=1;}
else {lv_ok=0;}
}
endcode
return lv_ok
end function




function read_pack(lv_type)
define lv_type char(1024)
define lv_has_pack integer
let lv_type=fgl_getenv("AUBITDIR") clipped,"/tools/4glpc/settings/",lv_type clipped
if isverbose(4) then
	display "Read pack : ",lv_type clipped
end if
let lv_has_pack=0;
code
{
FILE *fin;
char buff[512];
A4GL_trim(lv_type);
fin=fopen(lv_type,"r");
if (fin!=0) {
	char *ptr;
	lv_has_pack=1;
	while (fgets(buff,sizeof(buff),fin)) {
		A4GL_trim(buff);
		ptr=strchr(buff,'#');
		if (ptr) {
			 *ptr=0;
		}
		ptr=strchr(buff,'=');
		if (ptr==0) continue;
		*ptr=0;
		ptr++;
		if(isverbose_c(4)) {
			printf("Setting : '%s' = '%s'\n",buff,ptr);
		}

		//if (!getenv(buff)) {
			A4GL_setenv(buff, ptr, 1);
		//}
	}
}

}
endcode

if isverbose(4) then
	display "Has pack : ",lv_type clipped
end if

end function
		
	
