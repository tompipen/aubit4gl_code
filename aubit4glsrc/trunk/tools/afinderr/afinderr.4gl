{---------------------------------------------------------------------
help.4gl	Aubit4GL help routines (work with Informix .iem files)

2003-4-2	John O'Gorman john.ogorman@zombie.co.nz +64 (9) 521-0336

		First working version

		Note: Uses inline C code for I/O 
}
code
	#include <errno.h>
	#include <sys/types.h>
	#include <dirent.h>

	#define HELPMAXLEN 78
	static FILE * infile;
	unsigned char indexrec[8];

	static void myseterr( char *s);
	static void fileerror(FILE *f, char *s);
endcode

define constant HELPMAXLEN 78
---------   Module (static) Vars  ------------------------------------
#define no integer	-- message no we are seeking
define msgno smallint	-- message no found (while looping thru index)
define len integer	-- length of full message (while looping)
define msglen integer	-- length of full message (when found)
define msgcount integer -- count of messages in helpfile
define charcount integer --current count of chars read from message
define filenotfound integer
define msgline char(HELPMAXLEN)

define msgerror array[17] of record errline char(HELPMAXLEN) end record
define msgerrcnt integer


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
strcat(buff,"/help");
d=(DIR *)opendir(buff);

if (d!=0) {
	while (1) {
		de=readdir(d);
		if (!de) break;
		if (!strstr(de->d_name,".iem")) {
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


function newshowhelp(filename,n)
define filename char(128)
define n integer
define lv_char integer
define lv_msgline char(256)

call aclfgl_openiem(filename,n) returning lv_char,lv_msgline

if lv_char then
	display filename clipped,":"
	display lv_msgline

	while lv_char!=0
		call aclfgl_fetchiem() returning lv_char,lv_msgline
		if lv_char!=0 then
			display lv_char," ",lv_msgline
		end if
	
	end while
end if

end function




{-------------------------------------------------------------------------

	myshowerrors()	display errors (if any) in lines of help form

}

local function myshowerrors()
	define i integer
	define l_msg char(36)
	#clear form
	
	let i = 0
		let msgerror[1].errline = msgerror[1].errline clipped
		display msgerror[1].errline to s_help[1].helpline
	while true
		let i = i + 1
		if i > msgerrcnt then exit while end if
		if i > 16 then exit while end if
		let msgerror[i].errline = msgerror[i].errline clipped
		display msgerror[i].errline to s_help[i].helpline
	end while
	while i <= 17
		display " " to s_help[i].helpline
		let i = i + 1
	end while
end function
{-------------------------------------------------------------------}

code

static void
fileerror(FILE *f, char *s)
{
	int e;

	myseterr( s );
	if( f == NULL )
		myseterr( strerror(errno));
	else if( (e = ferror(f)) != 0)
	{
		myseterr( strerror(e));
	}
}

/******************************************************************
 *
 *	myseterr(s)  insert string s into msgerror array and
 *			increment msgerrcnt (which servers as a
 *			stackpointer)
 *
 */
static void
myseterr( char *s)
{
	int e;
	char *t;

	fprintf(stderr, "%s\n", s );
	//s[HELPMAXLEN]=0;
	//t=msgerror[msgerrcnt].errline;
	//strncpy( t,s,HELPMAXLEN);
	//++msgerrcnt;
}

