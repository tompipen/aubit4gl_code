/*

just to help with testing (so one can use the same function to do a screen
dump for aubit and Informix)

4Js apparently does not use curses

According to Jonathan Leffler do:
export DBSCREENDUMP=/tmp/x1
or
export DBSCREENOUT=/tmp/x2

In the apllication press CONTROL P

the  screen is copied to the mentioned files, check which one you like.

I tested it in D4gl 2.10 so I assume it will also work in 4JS version.
NOTE: There is a similar environment variable called DBSCREENDUMP which 
includes some ESCape sequencing, so isn't as readable.

http://www1.4js.com/html/mlarchive/msg06037.html
http://www1.4js.com/html/mlarchive/msg01421.html
http://www1.4js.com/html/mlarchive/msg06753.html

*/


static char * local_trim (char *s);

#ifndef I4GL_RDS

#include <stdio.h>
#ifdef XCURSES
	#include <xcurses.h>
#else
	#include <curses.h>
#endif

#include <errno.h>

#ifndef QUERIX  
	#ifndef FOURJS
		#ifndef I4GL_RDS
			// ...so it must be Informix C compiled 4GL:
			//This header is apprently only present in Infomix-4GL C compiler - not in 
			//RDS (p-code) version of 4gl
			#include "fglsys.h"
		#endif
	#endif
#endif

FILE *f;

int scr_width = 80;
int scr_height = 24;

int
aclfgl_dump_screen (int n)
{
int sh;
int sw;
int x, y;
int attr;
char *ptr = 0;
WINDOW *w;
int mode = 1;
char buffer[255];
char *buff;

//#define DEBUG 1

#ifdef DEBUG
	long cur_date;
	//extern int errno;
	FILE *fptr;
	time(&cur_date);
	//fptr = fopen("time_file.tmp","a");
	fptr = fopen("dump_screen.log","w");
	fprintf(fptr,"Started at %s\n", ctime(&cur_date));
	//printf("\nStarted at %s\n", ctime(&cur_date));
	//fclose(fptr);
#endif

/*w=find_pointer ("screen", WINCODE);*/
  
  w = curscr;
  refresh(); 
  if (n == 1) {
      popquote (buffer, 255);
  }

  if (n == 2) {
      popint (&mode);
      popquote (buffer, 255);
  }

  ptr = buffer;
  local_trim (ptr);

#ifndef QUERIX  
	#ifndef FOURJS
	  //default
	  strcat (buffer, ".infx");
	#else
	  strcat (buffer, ".4js");
	#endif
#else
	  strcat (buffer, ".querix");
#endif

  if (mode == 3)
    {
      scr_dump (ptr);
      return 0;
    }

  sh = 24;
  sw = 80;

  f = fopen (ptr, "w");
  if (f == 0) {
	  #ifdef DEBUG
	  	fprintf(fptr,"Failed to open %s\n", ptr);
		fclose(fptr);
	  #endif
	  return 0;
  }

  for (y = 0; y < sh; y++)
    {
      for (x = 0; x < sw; x++)
	{
	  attr = mvwinch (w, y, x);
	  if (mode == 0)
	    {
	      buff = (char *) &attr;
	      /* @todo - Fix for different ENDISMS */
	      fprintf (f, "%c%c", buff[2], attr & 255);
	    }

	  if (mode == 1)
	    {
			#ifdef QUERIX
				/* 
					Querix translates some characters to more graphical ones
					to make display nicer so we must translate them back to 
					what was orriginally in .per file
				*/
					
				buff = (char *) &attr;
				#ifdef DEBUG
					//fprintf(fptr,"attr=%c full=%c buff=%c\n",attr, attr & 255,buff[2]);
				#endif
				if ( buff[2] == '@' ) {
					if ( (char) attr == 'q' ) {
						attr='-';
					}
				}
			#endif
			
	      fprintf (f, "%c", attr & 255);
	    }
	}
      fprintf (f, "\n");
    }
  fclose (f);
  
#ifdef DEBUG  
  fprintf(fptr,"Finished at %s\n", ctime(&cur_date));
  fclose(fptr);
#endif
  
  return 0;
}

#else		//#ifndef I4GL_RDS

/*
**	Screen Dump for Informix 4GL in P-code (RDS) mode
**	This relies on Informix-4GL essentially
**	still using Curses(3X) primitives
** From 4Js mailing list
*/

#ifdef XCURSES
	#include <xcurses.h>
#else
	#include <curses.h>
#endif

#include <stdio.h>

int	
//scrdump(int argc)
aclfgl_dump_screen (int n)
{
extern	FILE	*popen() ;
extern	char	*getenv() ;
FILE	*fp ;
char	*indent, *spooler, *output_to ;
register int	ch, col, row ;
int mode = 1;
char buffer[255];
char *buff;
char *ptr = 0;

	if ((output_to = getenv("A4GL_SCRDUMP")) == (char *) NULL) {
		output_to="file";	
	}
	
	if (strcmp (output_to, "file") != 0) {
		printf ("Output to spooler");
		/** determine spooler **/
		if ((spooler = getenv("SPOOLER")) == (char *) NULL) {
			spooler = "lp -s" ;
		}
	
		/** open pipe to spooler **/
		if ((fp = popen(spooler, "w")) == (FILE *) NULL) {
			fprintf(stderr, "\r\nFATAL : cannot connect to spooler\n") ;
			sleep(3) ;
			return 0 ;
		}
	} else {
		printf ("Output to file");
		if (n == 1) {
			popquote (buffer, 255);
		}
		if (n == 2) {
			popint (&mode);
			popquote (buffer, 255);
		}
		
		ptr = buffer;
		local_trim (ptr);
		strcat (buffer, ".infx");
		
		fp = fopen (ptr, "w");
		if (fp == 0) {
			#ifdef DEBUG
				fprintf(fptr,"Failed to open %s\n", ptr);
				fclose(fptr);
			#endif
			return 0;
		}
	}

	/*
	**	UNIPLEX II Format
	**
	**	Graphics are static but
	**	other attributes should be user definable
	*/

	if (strcmp (output_to, "file") != 0) {
		if (strcmp (spooler, "lp -s") != 0) {
			fprintf (fp,"<Next centre><UL on>SAMPLE SCREEN<UL off>\n\n") ;
			fprintf (fp,"<Screen>\n") ;
		}
	}

	/** now scan through screen and dump **/
	for (row = 0 ; row < LINES ; row++) {
		if (strcmp (output_to, "file") != 0) {		
			if ((strcmp (spooler, "lp -s") != 0) && ((row == 2) || (row == 22))) {
				fprintf (fp,"<Gs,24p>") ;
			}
		}
		/** output text on this line **/
		for (col = 0 ; col < COLS ; col++) {
			ch = mvwinch(curscr, row, col) & 0x7f ;
		if (
				(strcmp(spooler, "lp -s") != 0) 
				&& (ch == ' ') 
				&& (strcmp (output_to, "file") != 0)
			) {
				fputc('~', fp) ;
			} else {
				fputc(ch, fp) ;
			}
		}
		fputc('\n', fp) ;
	}

	if (strcmp (output_to, "file") != 0) {	
		if (spooler != "lp -s") {
			fprintf (fp,"\n<End screen>\n") ;
		}
	}

	/** and end it **/
	if (strcmp (output_to, "file") != 0) {	
		pclose(fp) ;
	} else {
		fclose(fp) ;		
	}

	return 0 ;
}

#endif



static char *
local_trim (char *s)
{
  int a;
  for (a = strlen (s) - 1; a >= 0; a--)
    {
      if (s[a] == ' ')
	s[a] = 0;
      else
	break;
    }
  return s;
}

