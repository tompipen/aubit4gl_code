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
code
void A4GLHELP_initlib() {
// Does nothing...
}
endcode


main
	define filename char(128)
	define  n integer
	define d integer

	let msgerrcnt = 0

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
		A4GL_push_char(buff2);
		A4GL_push_long(n);
		aclfgl_newshowhelp(2);
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

call openiem(filename,n) returning lv_char,lv_msgline

if lv_char then
	display filename clipped,":"
	display lv_msgline

	while lv_char!=0
		call fetchiem() returning lv_char,lv_msgline
		if lv_char!=0 then
			display lv_char," ",lv_msgline
		end if
	
	end while
end if

end function



{---------------------------------------------------------------

	openiem(filename, n) Open an iem (Informix error msg) file
		1. Open the file
		2. Check header 0xfe68 and len = no of messages
		3. Step through index block until msg n found or len read
		4. Seek beginning of message (using offset from record)
		5. read 1st line from message

	returns charcount, msgline

	Side effects static vars
		msgcount: No of messages in .iem file
		filenotfound: boolean
		msgno: Message No of current message
		msglen: Total number of chars in message
		charcount: number of chars read from message (1st line)

	Note the file I/O is done in code ... endcode blocks
-------------------------------------------------------------------------
}
local function openiem( filename, n )
	define filename char(128)
	define n integer

	define i integer
	define offset integer
	define ok integer
	define msgnotfound integer

	let msgerrcnt = 0
	let filenotfound = 0
	let msgnotfound = 0
code
{
	static unsigned char header[4];
	char errmsg[HELPMAXLEN];

	ok = 1;
	trim(filename);
		
	if (strlen(filename)) {
		infile = fopen( filename, "rb" );  
	} else {
		infile = NULL;
	}
	if(infile == NULL ) 
	{
		ok = 0;
		filenotfound = 1;
		sprintf(errmsg, "Cannot open %s \n", filename);
		myseterr(errmsg);
		
	}
	//fprintf(stderr, "opened %s;ok = %d\n", filename, ok);
		
	if(ok)
	{  
		if((len = fread(header,1,4, infile))< 4)
		{
			ok = 0;
			sprintf(errmsg, "Cannot read header %d bytes only\n", len);
			myseterr( errmsg );
		}
		else
		{
			//fprintf(stderr, "read header %d bytes\n", len);
		}
	}
	
	if(ok)
	{ 
		if(header[0] != (unsigned char)'\xFE' || header[1] != '\x68')
		{
			sprintf(errmsg, 
				"%s:Bad magic: %02X %02X Should be FE 68\n",
				filename, 
				header[0], 
				header[1]);
			myseterr(errmsg);
			ok = 0;
		}
		else
		{
			//fprintf(stderr, "Header OK\n");
		}
	}
	if( ok )
	{
		msgcount = header[2] * 256 + header[3];
		//fprintf(stderr, "Count = %d\nNow reading index block\n", 
		//	msgcount );
		for(i=0; i<msgcount; i++)
		{
			if(fread(indexrec,1,8,infile)< 8) ok = 0;
			if(ok ) {
				memcpy(&msgno,indexrec,2);
				msgno=ntohs(msgno);
				//msgno = indexrec[0]*256 + indexrec[1];
			}
			else
			{
				sprintf(errmsg, "Failed to get 8 byte rec\n");
				myseterr(errmsg);
				break;
			}

			//fprintf(stderr, "%d of %d msgno=%d wanting n=%d\n", i, msgcount, msgno, n);
			if(ok && msgno == n ) // found it!
			{
				break;
			}
		}
	}
	if( ok && msgno != n )
	{
		 msgnotfound=1;
		 ok = 0;
	}
	if( ok )
	{
		msglen = indexrec[2]*256 + indexrec[3];
		offset = indexrec[4] * 16777216	// 256 ^ 3
			+ indexrec[5] * 65536	// 256 ^ 2
			+ indexrec[6] * 256
			+ indexrec[7];
		/*
		fprintf(stderr, "%d: msglen %d offset:%08X\n",
				msgno, msglen, offset);
		 */
	}
	if(ok) fseek(infile,offset,SEEK_SET);
	if(ok && ( infile == 0 || ferror(infile)))
	{
		ok = 0;
		sprintf(errmsg, "Seek failed %d: msglen %d offset:%08X\n",
				msgno, msglen, offset);
		fileerror(infile, errmsg);
	}
	if(ok)
	{
		fgets(msgline, HELPMAXLEN, infile); 
		msgline[HELPMAXLEN] = 0;
		charcount = strlen(msgline);
	}
	else if( msgnotfound )
	{
		charcount = 0;
		//sprintf(errmsg, "Error: Message %d not found in '%s'", n,filename);
		//myseterr(errmsg);
	}
//	fprintf(stderr, "At end of openiem, msgline = \n %s;", msgline);
}
endcode
	let msgline = msgline clipped
	return charcount, msgline
end function {openiem}

local function closeiem()
	let msgno = 0
	let msgcount = 0
	let msglen = 0
	let charcount = 0
code
	if( infile != NULL )
		fclose(infile);
endcode
	return 0
end function {closeiem}


{---------------------------------------------------------------------

	fetchiem()	Read next line from .iem message
		returns charcount, msgline
	Side effects static vars: 
		charcount: No of chars read from message
		msgerrcnt: Incremented if error
		msgerror:  Error message if error
		msgline:   The line read

	Assumes the file has already been opened (by openiem) and the
	file pointer is somewhere within the message.
	Each call to fetchiem increases the static var charcount by the
	length of the line read from the message.
}
local function fetchiem()
	define ok integer
	
	let ok = true
	if charcount >= msglen then
		return 0, "End of help message"
	end if
code
{
	char *s = 0;

	if(msglen < 1 || charcount >= msglen) ok = 0;
	if(infile == NULL) ok = 0;
	if(ok && feof(infile) ) ok = 0;
	if(ok && (charcount < msglen) ) 
	{
		fgets(msgline, HELPMAXLEN, infile); 
		msgline[HELPMAXLEN] = 0;
	}
	if(ok && ferror(infile)) ok = -1;
	if( ok > 0)
	{
		charcount += strlen(msgline);
		//fprintf(stderr,"fetchiem()%s:\n",msgline );
	}
	else
	{
		//fprintf(stderr,"fetchiem()file error:\n");
	}
}
endcode
	if not ok then let charcount = 0 end if
	let msgline = msgline clipped
	return charcount, msgline
end function {fetchiem}

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
	s[HELPMAXLEN]=0;
	t=msgerror[msgerrcnt].errline;
	strncpy( t,s,HELPMAXLEN);
	++msgerrcnt;
}


/*****************************************************************
 *
 * trim(char *s, int n) trim filenames at 1st blank
 *	replace 1st blank with a null char
 *	Also put a null char at s[n] to ensure termination 
 *
 *	Need this while "let name = name clipped" does not work
 */
static int
xx_dont_need_thistrim(char *s, int len)
{
	int i=0;
	
	while(i<len)
	{
		if(s[i] == ' ')
		{
			s[i]='\0';
			break;
		}
		++i;
	}
	s[len-1]='\0';
	return(strlen(s));
}
endcode
