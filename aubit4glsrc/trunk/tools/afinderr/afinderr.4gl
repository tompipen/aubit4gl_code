{---------------------------------------------------------------------

2003-4-2	John O'Gorman john.ogorman@zombie.co.nz +64 (9) 521-0336

Note: Uses inline C code for I/O

}
code
	#include <errno.h>
	#include <sys/types.h>
	#include <dirent.h>

	#define HELPMAXLEN 78
	static FILE * infile;
	unsigned char indexrec[8];

endcode

define constant HELPMAXLEN 78
---------   Module (static) Vars  ------------------------------------
#define no integer	-- message no we are seeking
define 
	msgno smallint,	-- message no found (while looping thru index)
	len integer,	-- length of full message (while looping)
	msglen integer,	-- length of full message (when found)
	msgcount integer, -- count of messages in helpfile
	charcount integer, --current count of chars read from message
	filenotfound integer,
	msgline char(HELPMAXLEN),
	msgerror array[17] of record 
		errline char(HELPMAXLEN) 
	end record,
	msgerrcnt integer


main
	define filename char(128)
	define  n integer
	define d integer

	let msgerrcnt = 0
	if num_args()=0 then
		display "Usage : afinderr number"
		exit program 0
	end if
	let n=arg_val(1)
code
{
char buff[256];
char buff2[256];
struct dirent *de;
strcpy(buff,(char *)acl_getenv("AUBITDIR"));
#ifdef SIMPLIFIED
strcat(buff,"/share");
#else
strcat(buff,"/etc");
#endif

d=(DIR *)opendir(buff);

	if (d!=0) {
		while (1) {
			de=readdir(d);
			if (!de) break;
		
			if (!strstr(de->d_name,".iem") 
				&& ! strstr(de->d_name,".hlp") 
				&& ! strstr(de->d_name,acl_getenv("A4GL_HLP_EXT")))	
			{
				continue;
			}
			strcpy(buff2,buff);
			strcat(buff2,"/");
			strcat(buff2,de->d_name);
			if (strlen(de->d_name)) {
				A4GL_push_char(buff2);
				A4GL_push_long(n);
				aclfgl_newshowhelp(2);
			} else {
				printf("Can't readdir\n");
				exit(2);
			}
		}
	}
}
endcode
end main


{*
 * 
 *	
 *
 *}
function newshowhelp(filename,n)
define 
	filename char(128),
	n, lv_char integer,
	lv_msgline char(256)


	call aclfgl_openiem(filename,n) returning lv_char,lv_msgline
	
	if lv_char then
		display filename clipped,":"
		if n<0 then
			display n using "-<<<<<<&"," ",lv_msgline
		else
			display n using "<<<<<<&"," ",lv_msgline
		end if
	
		while lv_char!=0
			call aclfgl_fetchiem() returning lv_char,lv_msgline
		
			if lv_char!=0 then
				let lv_msgline=aclfgl_trim_nl(lv_msgline)
				display lv_msgline clipped
			end if
		end while
		return
	end if

	if n>0 then
		call newshowhelp(filename,0-n)
	end if

end function

