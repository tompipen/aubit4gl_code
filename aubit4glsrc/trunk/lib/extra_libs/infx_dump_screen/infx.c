/*

just to help with testing (so one can use the same function to do a screen
dump for aubit and Informix)

*/


#include <stdio.h>
#include <ncurses.h>
#include "fglsys.h"

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

//w=find_pointer ("screen", WINCODE);
  w = curscr;

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
  trim (ptr);
  strcat (buffer, ".infx");

  if (mode == 3)
    {
      scr_dump (ptr);
      return 0;
    }

  sh = 24;
  sw = 80;

  f = fopen (ptr, "w");
  if (f == 0)
    return 0;

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
  return 0;
}


static char *
trim (char *s)
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
