/*
 * 
 * screen capture in ASCII mode, for 4Js compiler / Informix D4GL
 * 
 * Temporarily redirects the output of the screen to a file, and prompt the 
 * user to hit control-R and Return.
 * 
 * The file is sent through a program called 'decap' that strips
 * away the termcap escape sequences.
 * 
 * Part of the code is in the runner, and the decap is stand alone,
 * and some of the code is in wrappers.c
 *  
 * Really all it does is set up the file name and the temporary 
 * redirection of standard output for the user-prompted redraw.
 *  
 * 
 *	Code donated by ICANON Associates Incorporated http://www.icanon.com 
 *  by Joe Lewinski <lewinski@icanon.com>
 */

#ifdef __hpux
	#define _HPUX_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h> 
#include <fcntl.h>
#include "decimal.h"

#ifdef C4GL
	#ifdef OBSOLETE
		#include <tools/sqlfm.h>
	#endif
	/* not part of Informix or 4js - what is it?
	
	This is part of Informix esql I do not believe you need it.   Before
	our little trick with the I/O, we used to map onto a curses-like
	window structure referenced by an external declaration in this file.
	You can probably remove it, and perhaps any references of variables
	or constants that it defines.
	
	*/
	#define bool char
	#define CHAR short
	#define _ATTRIBUTE	(0x7f00)
	#define _CHARACTER	(0x00ff)
	#define _GRAPHMODE (0x8000)
	
	typedef	struct	window	
	{
		short	_cury, _curx;
		short	_maxy, _maxx;
		short	_begy,	_begx;
		short	_flags;
		bool	_clear;
		bool	_leave;
		bool	_scroll;
		CHAR	**_y;
		short	*_firstch;
		short	*_lastch;
		short	_attr;
	} WINDOW;
#ifdef OBSOLETE	
	extern	_EFwindow	*topwin, *botwin, *_Wscreen;
#endif
	extern	WINDOW	*_efbigwin;

#ifdef OBSOLETE
	/*
	That part of the code should be #ifdef'd out.   I would even
	go as far as removing it, as the external symbols are no
	longer available in 4Js post 3.10.
	*/
	extern	char	*GB;
#endif
#endif
static int fd1, fd3;
#define FRAME

/*
 *
 *
 *
 *
 *
 *
 *
 */
int 
//fgl_prtscr(int pcnt)
aclfgl_dump_screen (int pcnt)
{
#if C4GL
	register FILE	*fp;
	#ifdef OBSOLETE
	register	_EFwindow	*scr;
	#endif	
	register	WINDOW	*win;
	register	CHAR	**line,	*data;
	register	int y,x;
	register	char	c;
	int i; 
#endif
	char filnam [256]; 
	char cmdstring [1028]; 
	char pipestring [256]; 
	int ret;
#ifdef DEBUG
	long cur_date;
	extern int errno;
	FILE *fptr;
	time(&cur_date);
	//fptr = fopen("time_file.tmp","a");
	fptr = fopen("dump_screen.log","w");
	fprintf(fptr,"Started at %s\n", ctime(&cur_date));
	//printf("\nStarted at %s\n", ctime(&cur_date));
	//fclose(fptr);
#endif
	
	popquote (pipestring, 80);
	clip(pipestring);
	strcat (pipestring, ".4js");
	
#ifdef DEBUG  
	fprintf(fptr,"Destination file is %s\n",pipestring);
#endif
	
	

#if C4GL
#ifdef OBSOLETE
	if (topwin == _Wscreen) {
		/* The user is looking at the "screen" */
		win=(WINDOW *) _Wscreen->win;
	} else {
		/* the user is looking at the one or more "windows" */
		win=_efbigwin;
		for (scr=botwin; scr!=(_EFwindow *)0; scr=(_EFwindow *)scr->upper) {
			overwrite ((WINDOW *) scr->win, win);
		}
	}
#endif
	sprintf(filnam, "/tmp/%d.out", getpid());
#ifdef DEBUG  
	fprintf(fptr,"Temp file is %s\n",filnam);
#endif
	
	if ((fp=fopen(filnam, "w")) != (FILE *)0) {
		#ifdef DEBUG
			fprintf(fptr,"Opened %s for writing\n",filnam);
		#endif
		#ifdef FRAME
			/* Added for screen box */
			fputc ('+', fp);
			for (i=0; i<78; i++) {
				fputc ('-', fp);
			}
			fputc ('+', fp);
			fputc ('\n', fp);
		#endif
		#ifdef DEBUG
			fprintf(fptr,"line(win->_y)=%d y(win->_maxy)=%d\n",win->_y,win->_maxy);
			//win->_y=1097253761 win->_maxy=-931 - always the same
			//

		#endif
		for (y=0, line=win->_y; y<win->_maxy; y++, line++) {
			#ifdef DEBUG
				fprintf(fptr,"for level 1\n");
			#endif
			/* fputc ('|', fp);*/ 
			for (x=0, data=*line; x < win->_maxx; x++, data++) {
				#ifdef DEBUG
					fprintf(fptr,"for level 2\n");
				#endif
				c=(char) *data & _CHARACTER;
#ifdef OBSOLETE				
				if ((*data &_GRAPHMODE) && *GB) {
					if      (c==GB[0]) c='+';
					else if (c==GB[1]) c='+';
					else if (c==GB[2]) c='+';
					else if (c==GB[3]) c='+';
					else if (c==GB[4]) c='-';
					else if (c==GB[5]) c='|';
					else c=' ';
				}
#endif				
				fputc (c, fp);
			}
			/* fputc ('|', fp);*/ 
			fputc ('\n', fp);
		}
		
		#ifdef FRAME
			fputc ('+', fp); 
			for (i=0; i<78; i++) {
				fputc ('-', fp);
			}
			fputc ('+', fp); 
			fputc ('\n', fp);
		#endif

		fclose (fp);
		#ifdef DEBUG
	  		fprintf(fptr,"Closed %s\n", filnam);
		#endif
		
	} else {
		//printf ("Cannot open file %s for writing",filnam);
	  #ifdef DEBUG
	  	fprintf(fptr,"Failed to open %s\n", filnam);
		fclose(fptr);
	  #endif
		return 1;
	}

	sprintf (cmdstring, "%s %s > %s", 
		"cat", 			//
		filnam, 		//file we just created
		pipestring);	//filename in function call
		
	//sprintf (cmdstring, "%s %s %s",cmdstring,"; rm -f",filnam);
	
#else //#if C4GL
	// /tmp/prtscr.32766out: No such file or directory
	// the dot between pid and 'out' dissapeared?
	sprintf(filnam, "/tmp/prtscr.%d", getpid());
	sprintf (cmdstring, "%s < %s%s%s%s", 
		"../decap ", filnam, pipestring, "; rm -f ", filnam); 
#endif
	#ifdef DEBUG  
		fprintf(fptr,"Running: >%s<\n",cmdstring);
	#endif

	ret = system (cmdstring);
	//system (cmdstring);
	#ifdef DEBUG
		fprintf(fptr,"Command returned code %d\n", ret);	
	#endif
	
	
#ifdef DEBUG  
	fprintf(fptr,"Finished at %s\n", ctime(&cur_date));
	fclose(fptr);
#endif
	
	return 0;
}

/* 
 * Check if file is writable
 */
int
file_writable(int pcnt)
{
register FILE	*write_fp;
char path_nm [81];

	popquote (path_nm, 80);
	clip(path_nm);
	if ((write_fp=fopen(path_nm, "w")) != (FILE *)0) {
		fclose(write_fp);
		retint(1);
	} else {
		retint(0);
	}
	return(1);
}

/*
 * swap the file descriptors to fool the refresh
 */
void
fgl_swapio( int nargs )
{
int flg;
char file[30];

	popint(&flg);
	/*
	 * If passed a TRUE, it will swap the stdout(1) to a new file descriptor
	 */
	if (flg)
	{
		static char *mess = "[0m(B     Type <Ctrl-R>, Then <ENTER> ";
		sprintf(file, "/tmp/prtscr.%d", getpid());
		fd3 = dup(1);
		if (fd3 < 0)
		{
			retint(-1);
			return(1);
		}
		close(1);
		fd1 = open( file, O_CREAT|O_WRONLY, 0777 );
		if (fd1 < 0)
		{
			retint(-2);
			return(1);
		}
		clrscreen();
		write(2, mess, STRLEN(mess));
	}
	else	/* If passwd a FALSE, it swaps them back */
	{
		static char *mess = "[0m(B\r\n     Type <Ctrl-R> Again Now To Redraw Screen ";
		close(fd1);
		dup(fd3); /* to 1 */
		close(fd3);
		fd1 = fd3 = -1;

		clrscreen();
		write(2, mess, STRLEN(mess));
	}
	retint(0);
	return(1);
}


/*
 * Clear the screen
 */
void
clrscreen(void)
{
	static char *str = "[0;0H[J";
	write(2, str, STRLEN(str));
}

/*
 * Remove training spaces
 */
//static char *
static void
clip (char *s)
{
int a;
  for (a = strlen (s) - 1; a >= 0; a--)
    {
      if (s[a] == ' ')
		  s[a] = 0;
      else
		  break;
    }
  //return s;
}

/*
 * ============================== UTILITY FUNCTIONS ========================== 
 */

double dectodbl2(np) dec_t np;
{
	double dbl;

	dectodbl(&np,&dbl);
	return dbl;
}      
       
dec_t deccvdbl2(dbl) double dbl;
{
	dec_t n;
       
	deccvdbl(dbl,&n);
	return n;
}

char *nw_datestr(pv_date)
long    pv_date;
{
	char *STRNCPY();
	static char fmt[11], res[11];
	STRNCPY(fmt, "mm/dd/yyyy", 10); fmt[10] = '\0';
	rfmtdate(pv_date, fmt, res);
	return(res);
}


/* STRLEN() - on Linux, STRLEN(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
int STRLEN(char *buf)
{     
	if (buf == NULL)       
		return(0);         
	else                   
		return(strlen(buf));
}                          

/* STRCPY() - on Linux, STRCPY(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
extern char *strcpy(), *strncpy(), *memcpy();

char *STRCPY(char *dest, char *src)
{     
	if (dest == NULL)       
		return( (char *) "");         
	else                   
	{
		if (src == NULL)
		{
			*dest = '\0';
			return( (char *) "");         
		}
		return(strcpy(dest, src));
	}
}                          
/* STRNCPY() - on Linux, STRNCPY(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
char *STRNCPY(char *dest, char *src, int n)
{     
	if (dest == NULL)       
		return( (char *) "");         
	else                   
	{
		if (src == NULL)
		{
			*dest = '\0';
			return( (char *) "");         
		}
		return(strncpy(dest, src, n));
	}
}                          
/* STRNCMP() - on Linux, STRNCMP(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
int STRNCMP(char *str1, char *str2, int n)
{     
	if (str1 == NULL)       
		return(-1);
	else                   
	{
		if (str2 == NULL)
		{
			return(1);
		}
		return(strncmp(str1, str2, n));
	}
}                          
/* STRCMP() - on Linux, STRCMP(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
int STRCMP(char *str1, char *str2)
{     
	if (str1 == NULL)       
		return(-1);
	else                   
	{
		if (str2 == NULL)
		{
			return(1);
		}
		return(strcmp(str1, str2));
	}
}                          
/* MEMCPY() - on Linux, MEMCPY(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
char *MEMCPY(char *dest, char *src, int n)
{     
	if (dest == NULL)       
		return( (char *) "");         
	else                   
	{
		if (src == NULL)
		{
			*dest = '\0';
			return( (char *) "");         
		}
		return(memcpy(dest, src, n));
	}
}                          

/* ATOI() - on Linux, ATOI(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real ATOI()
 */
int ATOI(char *src)
{
	if (src == NULL)
		return( atoi((char *) ""));
	else
	{
		return(atoi(src));
	}
}

/* ATOF() - on Linux, ATOF(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real ATOF()
 */
double ATOF(char *src)
{
	double atof();
	if (src == NULL)
		return( atof((char *) ""));
	else
	{
		return(atof(src));
	}
}

extern char *strcat(), *strncat();

/* STRCAT() - on Linux, STRCAT(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real strcat()
 */
char *
STRCAT(char *dest, char *src)
{     
	if (dest == NULL)       
		return( (char *) "");         
	else                   
	{
		if (src == NULL)
		{
			*dest = '\0';
			return( (char *) "");         
		}
		return(strcat(dest, src));
	}
}                          

/* STRNCAT() - on Linux, STRNCAT(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real strncat()
 */
char *
STRNCAT(char *dest, char *src, int n)
{     
	if (dest == NULL)       
		return( (char *) "");         
	else                   
	{
		if (src == NULL)
		{
			*dest = '\0';
			return( (char *) "");         
		}
		return(strncat(dest, src, n));
	}
}                          

/* ===================================== EOF ============================= */

