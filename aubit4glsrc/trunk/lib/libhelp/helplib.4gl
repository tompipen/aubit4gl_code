{---------------------------------------------------------------------
help.4gl	Aubit4GL help routines (work with Informix .iem files)

2003-4-2	John O'Gorman john.ogorman@zombie.co.nz +64 (9) 521-0336

		First working version

		Note: Uses inline C code for I/O
}
code
	#include <errno.h>


	/*
	-----------------------------------------------------------------------------
	 PORTABLE
	   Set if we are going to use network style integers
	   Not set if we are going to use native integers
	 (On some platforms these may be the same, on others they won't be)
	-----------------------------------------------------------------------------
	*/

	#if defined (PORTABLE) && ! defined(__MINGW32__)
		//#ifdef __MINGW32__
			//#define __INSIDE_MSYS__
			//#include <winsock.h>
        //#else
			#include <netinet/in.h>
        //#endif
	#else
		#ifndef htonl
			#define htonl(x) (x)
			#define htons(x) (x)
			#define ntohl(x) (x)
			#define ntohs(x) (x)
		#endif
	#endif


	#define HELPMAXLEN 78
	static FILE * infile;
	unsigned char indexrec[8];

	static void myseterr( char *s);
	static void fileerror(FILE *f, char *s);
void A4GLHELP_initlib(void) ;
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
void A4GLHELP_initlib(void) {
// Does nothing...
}
endcode
----------------------------------------------------------------------
{  main section: comment this out when linking into libaubit  }
{
main
	define filename char(128)
	define  n integer

	options
		help file "fred.iem",
		message line 2,
		prompt line 22,
		form line 3

	let msgerrcnt = 0
	prompt "Filename? " for filename
	while true
		prompt "Help No? (0 to quit) " for n
		if n = 0 then exit while end if
		call myshowhelp(filename, n)
	end while
end main
}




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
	/*char *s = 0; */

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





{----------------------------------------------------------


	mynextpage()	Display up to 16 lines of help on form
		
}

local function mynextpage(l_count, l_msg)
	define l_count integer
	define l_msg char(HELPMAXLEN)

	define i integer

	let i = 0
	while true
		let i = i + 1
		if msgerrcnt then
			call myshowerrors()
			return
			exit while
		end if
		if i = 1 then # Put last line of previous page on 1st line
			display msgline to s_help[i].helpline
		else
			display l_msg to s_help[i].helpline
		end if
		if l_count >= msglen or i >= 16 then
			exit while
		end if
		call fetchiem() returning l_count, l_msg
	end while
	while i < 16
		let i = i + 1
		#clear s_help[i].helpline -- doesn't work?
		display "  " to s_help[i].helpline
	end while
	if charcount >= msglen then
		display "(End of help message)" to s_help[17].helpline
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
	A4GL_trim(filename);
		
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
			sprintf(errmsg, "Cannot read header %ld bytes only\n", len);
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
			A4GL_debug("Header OK");
			//fprintf(stderr, "Header OK\n");
		}
	}
	if( ok )
	{
		msgcount = header[2] * 256 + header[3];
		A4GL_debug("Count=%d",msgcount);
		//fprintf(stderr, "Count = %d\nNow reading index block\n", 
		//	msgcount );
		for(i=0; i<msgcount; i++)
		{
			if(fread(indexrec,1,8,infile)< 8) ok = 0;

			if(ok ) {
				A4GL_debug("%d %d %d %d %d %d %d %d",
indexrec[0],
indexrec[1],
indexrec[2],
indexrec[3],
indexrec[4],
indexrec[5],
indexrec[6],
indexrec[7]);
                                memcpy(&msgno,indexrec,2);
                                //msgno=ntohs(msgno);
				//A4GL_debug("msgno=%d",msgno);
                                msgno=ntohs(msgno);
				A4GL_debug("now msgno=%d (n=%d)",msgno,n);

			}
			else
			{
				sprintf(errmsg, "Failed to get 8 byte rec\n");
				myseterr(errmsg);
				break;
			}

			//fprintf(stderr, "%d of %d msgno=%d wanting n=%d\n",
			//		i, msgcount, msgno, n);
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
		fprintf(stderr, "%d: msglen %d offset:%08lX\n",
				msgno, msglen, offset);
		 */
	}
	if(ok) fseek(infile,offset,SEEK_SET);
	if(ok && ( infile == 0 || ferror(infile)))
	{
		ok = 0;
		sprintf(errmsg, "Seek failed %d: msglen %ld offset:%08lX\n",
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
		sprintf(errmsg, "Error: Message %d not found in '%s'",
				 n,filename);
		myseterr(errmsg);
	}
//	fprintf(stderr, "At end of openiem, msgline = \n %s;", msgline);
}
endcode
	let msgline = msgline clipped
	return charcount, msgline
end function {openiem}







{---------------------------------------------------------------------

	myshowhelp(f, n)  use this to implement 4GL showhelp(n)

}

function libhelp_showhelp(filename, n)
	define filename char(128)
	define n integer

	define l_count integer
	define l_msg char(HELPMAXLEN)
	define i integer
	#define c char(1)

	let msgerrcnt = 0
	let filename = filename clipped
code
A4GL_debug("filename=%s",filename);
	A4GL_trim(filename);
	A4GL_debug("compiled_form_a4gl_xxhelp=%p",&compiled_form_a4gl_xxhelp);
endcode

	call form_is_compiled(a4gl_xxhelp,"MEMPACKED","GENERIC");

	open window w1 at 1,1 with form "a4gl_xxhelp"

	call openiem(filename, n ) returning l_count, l_msg

	if filenotfound or msgerrcnt > 0 then
		call myshowerrors()
	else
		call mynextpage(l_count, l_msg)
		if msgerrcnt > 0 then
			call myshowerrors()
		end if
	end if

	menu "Help"
			
		command "Screen" "Displays next page of help"
			if charcount >= msglen then
				next option "Resume"
				continue menu
			else
				call mynextpage(l_count, l_msg)
			end if
			if msgerrcnt > 0 then
				call myshowerrors()
				next option "Resume"
			end if
			if charcount >= msglen then
				next option "Resume"
			end if
		command "Resume" "Ends this help session"
			exit menu
	end menu
	close window w1
end function
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
	/* int e; */
	char *t;

	s[HELPMAXLEN]=0;
	t=msgerror[msgerrcnt].errline;
	strncpy( t,s,HELPMAXLEN);
	++msgerrcnt;
	//fprintf(stderr, "%s\n", t );
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
