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
NOTE: There is a similar environment variable called DBSCREENDUMP which includes some ESCape sequencing, so isn't as readable.
http://www1.4js.com/html/mlarchive/msg06037.html

http://www1.4js.com/html/mlarchive/msg01421.html

http://www1.4js.com/html/mlarchive/msg06753.html

If anyone is interested, we have sucessfully built a work around to the
screen capture in ASCII mode (i.e. FGLGUI=0).  It involves some C code
but it works.


"Joe Lewinski" <lewinski@icanon.com>

ICANON Associates, Inc.
215.653.0754 x 115
Fax:  215.653.0829


*/


#include <stdio.h>
#include <curses.h>

#ifdef C4GL
	#this header is apprently only present in Infomix-4GL C compiler - not in 
	#RDS (p-code) version of 4gl
	#include "fglsys.h"
//#else
//	#include "fgicfunc.h"
#endif

FILE *f;

int scr_width = 80;
int scr_height = 24;

static char * local_trim (char *s);


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

/*w=find_pointer ("screen", WINCODE);*/
  
  w = curscr;

#ifndef FOURJS
  refresh(); //we crash here when using 4Js
#endif

  if (n == 1)
    {
      popquote (buffer, 255);
    }

  if (n == 2)
    {
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



