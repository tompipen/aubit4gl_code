
{---------------------------------------------------------------------help.4gl	Aubit4GL help routines (work with Informix .iem files)

2003-4-2	John O'Gorman john.ogorman@zombie.co.nz +64 (9) 521-0336

		First working version

		Note: Uses inline C code for I/O
}
---------   Module (static) Vars  ------------------------------------
#define no integer	-- message no we are seeking
-- message no found (while looping thru index)
-- length of full message (while looping)
-- length of full message (when found)
-- count of messages in helpfile
--current count of chars read from message
DEFINE charcount          INTEGER
DEFINE filenotfound       INTEGER
DEFINE helpmaxlen         CONSTANT 256
DEFINE len                INTEGER
DEFINE msgcount           INTEGER
DEFINE msgerrcnt          INTEGER

DEFINE msgerror ARRAY[20] OF RECORD
       errline            CHAR(256)
END RECORD

DEFINE msglen             INTEGER
DEFINE msgline            CHAR(255)
DEFINE msgno              SMALLINT

code
#include "a4gl_API_help_lib.h"
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
			#ifndef __WIN32__
				#define htonl(x) (x)
				#define htons(x) (x)
				#define ntohl(x) (x)
				#define ntohs(x) (x)
			#else
				#define htons(x) win_htons(x)
				#define ntohs(x) win_ntohs(x)
			#endif
		#endif
	#endif


	#define HELPMAXLEN 256
	static FILE * infile;
	unsigned char indexrec[8];

	static void myseterr( char *s);
	static void fileerror(FILE *f, char *s);

endcode


code

int  HELPLIB_HELP_initlib(void) {
// Does nothing - required by the API
return 1;
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
	aclfgl_fetchiem()	Read next line from .iem message
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
FUNCTION local_aclfgl_fetchiem ()
DEFINE ok                 INTEGER

    LET ok=TRUE

    IF charcount>=msglen THEN
        RETURN 0,"End of help message"
    END IF


code
{
	/*char *s = 0; */

	if(msglen < 1 || charcount >= msglen) ok = 0;
	if(infile == NULL) ok = 0;
	if(ok && feof(infile) ) ok = 0;
	if(ok && (charcount < msglen) )
	{
		fgets(msgline, 255, infile);
		msgline[HELPMAXLEN-1] = 0;
                // Trimming the newline with A4GL_trim_nl() causes
                // the help message to also display the first few lines
                // of the next help message from the help file.
                // fgets() already adds a terminating  null  byte ('\0').
		//A4GL_trim_nl(msgline);
		A4GL_debug(">>>%s<<<",msgline); fflush(stdout);
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

    IF NOT(ok) THEN
        LET charcount=0
    END IF

    LET msgline=msgline CLIPPED

    RETURN charcount,msgline[1,80]

END FUNCTION

{fetchiem}



{-------------------------------------------------------------------------
	myshowerrors()	display errors (if any) in lines of help form

}
LOCAL FUNCTION myshowerrors ()
DEFINE i                  INTEGER
DEFINE l_msg              CHAR(36)

    #clear form
    SET PAUSE MODE ON

    LET i=1
    LET msgerror[1].errline=msgerror[1].errline CLIPPED

    # to s_help[1].helpline
    DISPLAY msgerror[1].errline AT 3,1

    WHILE TRUE
        LET i=i+1

        IF i>msgerrcnt THEN
            EXIT WHILE
        END IF

        IF i>20 THEN
            EXIT WHILE
        END IF

        LET msgerror[i].errline=msgerror[i].errline CLIPPED

        # to s_help[i].helpline
        DISPLAY msgerror[i].errline,"" AT i+3,1
    END WHILE

    WHILE i<=20

        # to s_help[i].helpline
        DISPLAY " ","" AT i+3,1

        LET i=i+1
    END WHILE

    SET PAUSE MODE OFF

END FUNCTION



{----------------------------------------------------------

	mynextpage()	Display up to 20 lines of help on form

}
LOCAL FUNCTION mynextpage (l_count,l_msg)
# Parameters
DEFINE l_count            INTEGER
DEFINE l_msg              CHAR(256)

# Normal Variables
DEFINE i                  INTEGER

    SET PAUSE MODE ON

    LET i=0

    WHILE TRUE
        LET i=i+1

        IF msgerrcnt THEN
            CALL myshowerrors()

            RETURN

            EXIT WHILE
        END IF

        # Put last line of previous page on 1st line
        IF i=1 THEN

            # to s_help[i].helpline
            DISPLAY msgline,"" AT i+3,1
        ELSE

            # to s_help[i].helpline
            DISPLAY l_msg,"" AT i+3,1
        END IF

        IF l_count>=msglen OR i>=20 THEN
            EXIT WHILE
        END IF

        CALL aclfgl_fetchiem()
         RETURNING l_count,l_msg

    END WHILE

    IF charcount>=msglen THEN
        display "End of help message" AT 24,1 attribute(reverse)
    END IF

    SET PAUSE MODE OFF

END FUNCTION



{---------------------------------------------------------------
	aclfgl_openiem(filename, n) Open an iem (Informix error msg) file
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
FUNCTION local_aclfgl_openiem (filename,n)
# Parameters
DEFINE filename           CHAR(128)
DEFINE n                  INTEGER

# Normal Variables
DEFINE i                  INTEGER
DEFINE msgnotfound        INTEGER
DEFINE offset             INTEGER
DEFINE ok                 INTEGER

    LET msgerrcnt=0
    LET filenotfound=0
    LET msgnotfound=0


code
{
	static unsigned char header[4];
	char errmsg[HELPMAXLEN];

	ok = 1;
	A4GL_trim(filename);

	if (strlen(filename)) {
		infile = A4GL_open_file_dbpath( filename );
	} else {
		infile = NULL;
	}

	if(infile == NULL )
	{
		ok = 0;
		filenotfound = 1;

		snprintf(errmsg, HELPMAXLEN-1,"Cannot open %s \n", filename);
		myseterr(errmsg);

	}

	if(ok)
	{
		if((len = fread(header,1,4, infile))< 4)
		{
			ok = 0;
			snprintf(errmsg, HELPMAXLEN-1,"Cannot read header %ld bytes only\n", len);
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
			snprintf(errmsg, HELPMAXLEN-1,
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
			if(fread(&indexrec[0],1,8,infile)< 8) ok = 0;

			if(ok ) {
				A4GL_debug("%02x %02x %02x %02x %02x %02x %02x %02x",
indexrec[0],
indexrec[1],
indexrec[2],
indexrec[3],
indexrec[4],
indexrec[5],
indexrec[6],
indexrec[7]);


                                memcpy(&msgno,&indexrec[0],2);
				A4GL_debug("now msgno=%d (n=%d)",msgno,n);
                                msgno=ntohs(msgno);
				A4GL_debug("now msgno=%d (n=%d)",msgno,n);

			}
			else
			{
				sprintf(errmsg, "Failed to get 8 byte rec\n");
				myseterr(errmsg);
				break;
			}
			A4GL_debug("msgno=%d n=%d",msgno,n);
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
		fgets(msgline, 255, infile);
		msgline[HELPMAXLEN-1] = 0;
		//A4GL_trim_nl(msgline);
		charcount = strlen(msgline);
		//A4GL_trim_nl(msgline);
	}
	else if( msgnotfound )
	{
		charcount = 0;
		snprintf(errmsg, HELPMAXLEN-1, "Error: Message %ld not found in '%s'", n,filename);
		myseterr(errmsg);
	}
//	fprintf(stderr, "At end of aclfgl_openiem, msgline = \n %s;", msgline);
}

endcode

    LET msgline=msgline CLIPPED

    RETURN charcount,msgline

END FUNCTION

{aclfgl_openiem}



{---------------------------------------------------------------------
	myshowhelp(f, n)  use this to implement 4GL showhelp(n)

}
FUNCTION local_libhelp_showhelp (filename,n)
# Parameters
DEFINE filename           CHAR(128)
DEFINE n                  INTEGER

# Normal Variables
DEFINE i                  INTEGER
DEFINE l_count            INTEGER
DEFINE l_msg              CHAR(256)

    #define c char(1)
    LET msgerrcnt=0
    LET filename=filename CLIPPED


code
A4GL_debug("filename=%s",filename);
	A4GL_trim(filename);
	/* A4GL_debug("compiled_form_a4gl_xxhelp=%p",&compiled_form_a4gl_xxhelp); */

endcode

    #options menu line 1 # In case the running program has something else set
    OPEN WINDOW a4gl_helpw1 AT 1,1 WITH 24 ROWS, 80 COLUMNS ATTRIBUTES (menu line 1)

    CALL aclfgl_openiem(filename,n)
     RETURNING l_count,l_msg

    IF filenotfound OR msgerrcnt>0 THEN
        CALL myshowerrors()
    ELSE
        CALL mynextpage(l_count,l_msg)

        IF msgerrcnt>0 THEN
            CALL myshowerrors()
        END IF

    END IF

    SET PAUSE MODE OFF

    MENU "Help"
        before menu
            if charcount>=msglen then
                next option "Resume"
            end if

        COMMAND "Screen" "Displays next page of help"

            IF charcount>=msglen THEN
                NEXT OPTION "Resume"

                CONTINUE MENU
            ELSE
                CALL mynextpage(l_count,l_msg)
            END IF

            IF msgerrcnt>0 THEN
                CALL myshowerrors()

                NEXT OPTION "Resume"
            END IF

            IF charcount>=msglen THEN
                NEXT OPTION "Resume"
            END IF

        COMMAND "Resume" "Ends this help session"
            EXIT MENU

    END MENU

    CLOSE WINDOW a4gl_helpw1

END FUNCTION



FUNCTION local_aclfgl_closeiem ()

    LET msgno=0
    LET msgcount=0
    LET msglen=0
    LET charcount=0


code
	if( infile != NULL )
		fclose(infile);

endcode

    RETURN 0

END FUNCTION

{closeiem}
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
	A4GL_debug("myseterr : %s (%d)",s,msgerrcnt);
	s[HELPMAXLEN]=0;
	t=msgerror[msgerrcnt].errline;
	strncpy( t,s,HELPMAXLEN);
	++msgerrcnt;
	//fprintf(stderr, "%s\n", t );
}

#ifdef REMOVED

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
#endif


int HELPLIB_aclfgl_aclfgl_libhelp_showhelp(int n) {
	return HELPLIB_aclfgl_local_libhelp_showhelp(n);
}

int HELPLIB_aclfgl_aclfgl_openiem(int n) {
	return HELPLIB_aclfgl_local_aclfgl_openiem(n);
}

int HELPLIB_aclfgl_aclfgl_closeiem(int n) {
	return HELPLIB_aclfgl_local_aclfgl_closeiem(n);
}

int HELPLIB_aclfgl_aclfgl_fetchiem(int n) {
	return HELPLIB_aclfgl_local_aclfgl_fetchiem(n);
}


endcode

