/**
 * @file
 * Several utility functions.
 *
 * This utility functions are not agregated by type. When necessary are added
 * to this module.
 *
 * The kinds identificated are:
 *   - Parser utility functions
 *   - String format and transformation
 *
 */

/*
 *
 * Moredata - Lisboa, PORTUGAL
 *
 * $Author: afalout $
 * $Revision: 1.7 $
 * $Date: 2003-12-10 11:48:07 $
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include "p4gl_symtab.h"
#include "p4gl.h"
#include "malloc.h"
#include <stdlib.h>			/* free() exit()*/

//	#ifndef WIN32
//		#include <string.h>
//	#endif
//	#include <assert.h>		/* assert() */
//	#include <time.h>
//	#include <math.h>		/* pow() */
//	#include <locale.h>		/* setlocale() */
//	#include <unistd.h>		/* sleep() close() write() usleep() */
//	#include <signal.h>		/* SIGINT */
//	#include <sys/types.h>



/*
p4gl_util.c:54: warning: implicit declaration of function `RegisterErrorInDb'
p4gl_util.c:63: warning: implicit declaration of function `CleanP4gl'
p4gl_util.c:64: warning: implicit declaration of function `exit'
p4gl_util.c:91: warning: implicit declaration of function `RegisterWarningInDb'
p4gl_util.c:156: warning: implicit declaration of function `strlen'
p4gl_util.c:205: warning: implicit declaration of function `strcpy'
p4gl_util.c:242: warning: implicit declaration of function `malloc'
p4gl_util.c:256: warning: implicit declaration of function `realloc'
p4gl_util.c:259: warning: implicit declaration of function `strdup'
p4gl_util.c:298: warning: implicit declaration of function `strncpy'
*/



/**
 *  Write the parsing erros in the error file and in standard output.
 *
 *  Its an variable argument function.
 *
 *  @param errorType The type of the error:
 *     - 0 : Exit the program
 *     - otherwise : Do not exit
 *  @param fmt The format of the message to sprintf
 */
void 
P4glError(int errorType,char *fmt,...)
{
	va_list args;
	char  ErroTemporario[256];
	char *NmDir;

	va_start(args,fmt);

  NmDir = getcwd((char *)0,256);
	(void)vsprintf(ErroTemporario,fmt,args);
	va_end(args);

	if ( P4glCb.errorToDb == 1 )
    RegisterErrorInDb(ErroTemporario);
	fprintf(stdout,"p4gl: %s, %s",FicheiroInput,ErroTemporario);
	/* ??? Devia meter a data */
	fprintf(Log,"p4gl: Directoria: %s - Ficheiro: %s - %s",
			  NmDir,FicheiroInput,ErroTemporario);

	exit_stat = 1;
	if ( errorType == 0 )
	{
    CleanP4gl();
		exit(1);
	}
}


/**
 * Warning utility function.
 *
 * The function use variable arguments.
 *
 *  @param Level The level of the warning:
 *     - 0 : Exit the program
 *     - otherwise : Do not exit
 *  @param fmt The format of the message to sprintf
 */
void
P4glWarning(int errorLevel,char *fmt,...)
{
	va_list args;
	char  ErroTemporario[512];

	va_start(args,fmt);

	if ( errorLevel > WarningLevel ) return;

	(void)vsprintf(ErroTemporario,fmt,args);
	va_end(args);
	if ( P4glCb.errorToDb == 1 )
    RegisterWarningInDb(ErroTemporario);

	fprintf(stdout,"Warning: %s",ErroTemporario);
	fprintf(P4glCb.fl_erros_ptr,"Warning: %s",ErroTemporario);
}

/**
 * Sending verbose messages to standard output.
 *
 * It uses variable arguments.
 *
 * @param fmt The format of the message to sprintf
 */
void 
P4glVerbose(char *fmt,...)
{
	va_list args;
	char  ErroTemporario[128];

	if (!verbose)
		return;
	va_start(args,fmt);

	(void)vsprintf(ErroTemporario,fmt,args);
	va_end(args);

	fprintf(stdout,"%s",ErroTemporario);
}

/**
 * Sending debug messages to standard output.
 *
 * It works only when the debug flag is on.
 *
 * @param fmt The format of the message to sprintf
 */
void 
P4glDebug(char *fmt,...)
{
	va_list args;
	char  ErroTemporario[128];

   if (dbug == 0 )
		return;

	va_start(args,fmt);

	(void)vsprintf(ErroTemporario,fmt,args);
	va_end(args);

	printf("DEBUG: %s",ErroTemporario);
	fflush(stdout);
}


/**
 * Remove spaces in the end of the string.
 *
 * It does not alocate space to do it. The work is done in the original string.
 *
 * @param str The String to be trimmed
 */
void
RClipp(char *str)
{
   register int i;
	int len;

	len = strlen(str);
	for (i=len-1 ; i >= 0 ;i--)
		if ( str[i] != ' ' )
			break;
	str[i+1]='\0';
}

/**
 * Remove spaces in the begenning of the string.
 *
 * It does not alocate space to do it. The work is done in the original string.
 *
 * @param str The String to be trimmed
 */
void
LClipp(char *str)
{
   register int i;
	int len, firstChar;
    char *str2;

	len = strlen(str);


	for (i=0 ; str[i] != '\0' ; i++)
    {
		if ( str[i] != ' ' )
        {
            firstChar=i;
            break;
        }
    }

//	P4glDebug("first = -%d-%d-\n",firstChar,len);

    if (firstChar == 0)
	{
        //nothing to do - characters already start at the first possition
    } else {
		str2 = substr(str, firstChar, len);
		//P4glDebug("got -%s-\n",str2);
	    //str=strdup(str2);
    	strcpy(str,str2);
    }
}

int
IsTerminated(char *str)
{
int len;

	len = strlen(str);

	if ( str[len] == '\0' )
    {
		return (1);
	}

	return (0);
}


/**
 * Upshift the characters of a string.
 *
 * @param str The string to uppered
 */
void
Upshift(char *str)
{
  register int i;

	for (i=0 ; str[i] != '\0' ; i++)
		str[i] = toupper(str[i]);
}

/**
 * Makes downshift in all characters of a string
 *
 * @param str The string to be lowered
 */
void 
Downshift(char *str)
{
  register int i;

	for (i=0 ; str[i] != '\0' ; i++)
		str[i] = tolower(str[i]);
}
   
   
/**
 * Copy the content of a string into another one.
 *
 * Assume that the destination string have enough space to put the original
 * string.
 *
 * @param StrDest The destination string.
 * @param StrOrig The origin string.
 */
void 
copystr(char *StrDest,char *StrOrig)
{
   if (StrOrig == (char*)0 )
		StrDest = (char *)0;
	else
		strcpy(StrDest,StrOrig);
}


/**
 * Strip the quotes that are in the beginning and end of a string.
 *
 * @param str The string where to strip the quotes.
 */
void 
tiraAspas(char *str)
{
	if ( str[0] == '"' || str[0] == '\'' ) {
	  str[0] = ' ';
    }

	if ( str[strlen(str)-1] == '"' || str[strlen(str)-1] == '\'' ) {
	  str[strlen(str)-1] = '\0';
    }

    //now remove leading space
    LClipp(str);

}


/**
 *  Allocate space to the destination string and insert it the variable
 *  arguments received.
 *  
 *  The deallocation process is a task for the calling functions.
 *
 *  @todo : Testar se memória acabou
 *  @todo The cicle in va_start is a possible cause of errors
 *
 *  @param fmt The format to sprintf.
 *  @return A pointer to the allocated string.
 */
char *
CpStr(char *fmt,...)
{
	va_list args;
	char *destinoTemporario;
	char *RetStr;
	int size = 2048;
	int n;


	destinoTemporario = (char *)malloc(size);
	while (1)
  {
	  va_start(args,fmt);
	  n = vsnprintf(destinoTemporario,size,fmt,args);
	  va_end(args);

		if ( n > -1 && n < size )
      break;

		if ( n > -1 )
      size = n + 1;
		else
      size *= 2;
		destinoTemporario = (char *)realloc(destinoTemporario,size);
  }

	RetStr = (char *)strdup(destinoTemporario);
	return(RetStr);
}


/*
 * Finds a takes the basename in a string content.
 * The basename is the name before "." or "[".
 *
 * @param str The string to be transformated just for having basename
 */
void 
BaseName(char *str)
{
   register int i;

	for ( i = 0 ; str[i] != '\0' ;i++)
		if ( str[i] == '.' || str[i] == '[' )
			break;

   str[i] = '\0';
}

/**
 * Gets the name of a file without the extension (if so).
 *
 * Note that the returned string is allocated dynamicaly.
 * It is responsability of the calling function to free the memory when doesent
 * need it anymore.
 *
 * @param str The string with the file name.
 * @return The extension stripped file name.
 */
char *
fileWithoutExtension(char *str)
{
  register int i;
	char *retStr;

	for ( i = strlen(str) ; i > 0 && str[i] != '.' ; i-- );
	retStr = (char *)malloc(i+1);
	strncpy(retStr,str,i);
	retStr[i] = '\0';
	return retStr;
}


/**
 * Find possition of x-th / in string, from right to left
 *
 *
 * @param str The string with the file name.
 * @return
 */
short
RightPos(char *str,int count, char lookfor)
{
  register int i;
//	char *retStr;
    int found = 0;

	for ( i = strlen(str) ; i > 0 ; i-- )
    {
		if (str[i] == lookfor)
        {
            found++;

            if (found == count)
            {
                return (short)i;

            }
        }
    }

	/*
	retStr = (char *)malloc(i+1);
	strncpy(retStr,str,i);
	retStr[i] = '\0';
	return retStr;
    */

    return (short)0;
}


/**
 * Returns the substring of str, starting in start a finishing in finish
 *
 * Note that the returned string is allocated dynamicaly. The free of the
 * memory is calling function responsability.
 *
 * @param str The string to substring.
 * @param start Start index of the substring wanted.
 * @param finish finishing index of the substring wanted.
 * @return A pointer substring allocated and extracted.
 */
char *
substr(char *str, short start, short finish)
{
//   register sh;
	char *retstr;

	if ( start > finish)
		return (char *)0;

//P4glDebug("A1\n");
	retstr = (char *)malloc(finish-start+2); //core dumps here when start = 0
//P4glDebug("A2\n");
	strncpy(retstr,str+start,finish-start+1);
//P4glDebug("A3\n");

	return retstr;
}


/**
 * Verify if a substring is empty.
 * It is considered empty with spaces and tab(s).
 *
 *
 * @param The string to be verified
 * @return - 1 The string is empty
 *         - 0 Otherwise
 */
int
IsEmpty(char *Str)
{
   register int i, len;

	len = strlen(Str);
	for ( i = 0 ; i <= len; i++)
	{
/*
		if ( Str[i] != ' ' && Str[i] != '\t' )
			if ( Str[i] == '\0' )
            {
				return(1);
            }
			else
            {
				return(0);
            }
*/
		if ( Str[i] != ' ' && Str[i] != '\t' && Str[i] != '\0' ) {
				// this char is not space,tab or terminator, so it must
                //be something in this striong - return false
				return(0);
        }



	}
	//we found nothing except maybe spaces,tabs and terminator, string is empty,
    //return true
	return(1);
}
