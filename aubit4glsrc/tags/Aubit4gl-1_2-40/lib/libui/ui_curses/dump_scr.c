#include <stdio.h>
#include "a4gl_lib_ui_tui_int.h"

#ifndef lint
	static char const module_id[] =
		"$Id: dump_scr.c,v 1.16 2016-10-06 07:16:53 siverly Exp $";
#endif

FILE *f;


int
UILIB_aclfgl_aclfgl_dump_screen (int n)
{
  int sh;
  int sw;
  int x, y;
  int attr;
  char *ptr = 0;
  WINDOW *w;
  int mode = 1;
  char *buff;
  int needPclose = 0;
  int starty = 0;
  int stopy=0;

//w=find_pointer ("screen", WINCODE);
  w = curscr;



  if (n == 1)
    {
      ptr = A4GL_char_pop ();
    }

  if (n == 2)
    {
      mode = A4GL_pop_int ();
      ptr = A4GL_char_pop ();
    }


  if (n == 3)
    {
      starty = A4GL_pop_int ();
      mode = A4GL_pop_int ();
      ptr = A4GL_char_pop ();
    }
  if (n == 4)
    {
      stopy = A4GL_pop_int ()+1;
      starty = A4GL_pop_int ();
      mode = A4GL_pop_int ();
      ptr = A4GL_char_pop ();
    }

  if (n != 0)
    {
	A4GL_assertion(!ptr,"ptr not set");
      	A4GL_trim (ptr);
    }

  if (mode == 3)
    {
      scr_dump (ptr);
      return 0;
    }

  sh = A4GL_screen_height ();
  sw = A4GL_screen_width ();

  if (strcasecmp (acl_getenv ("TRIMDUMP"), "24x80") == 0)
    {
      if (sh > 24)
	sh = 24;
      if (sw > 80)
	sw = 80;
    }
  if (strcasecmp (acl_getenv ("TRIMDUMP"), "25x80") == 0)
    {
      if (sh > 24)
	sh = 25;
      if (sw > 80)
	sw = 80;
    }
  if (strcasecmp (acl_getenv ("TRIMDUMP"), "24x132") == 0)
    {
      if (sh > 24)
	sh = 24;
      if (sw > 132)
	sw = 132;
    }
  if (strcasecmp (acl_getenv ("TRIMDUMP"), "25x132") == 0)
    {
      if (sh > 24)
	sh = 25;
      if (sw > 132)
	sw = 132;
    }

  if (n == 0)
    {
#ifdef DEBUG
      A4GL_debug ("AUTO PRINT...");
#endif
      // We want to dump to to PRINTSCRFILE
      ptr = acl_getenv ("A4GL_PRINTSCRFILE");

      if (strcmp(ptr,":dumpCurrentFormInfo")==0) {
		dumpCurrentFormInfo();
		return 0;
      }


      if (ptr)
	{
	  if (strlen (ptr) == 0)
	    ptr = 0;
	}
      if (ptr == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("No PRINTSCRFILE - ignored print dump request");
#endif
	  return 0;
	}
    }

  if (ptr[0] == '|')
    {
      f = popen (&ptr[1], "w");
      needPclose = 1;
    }
  else
    {
      if (ptr[0] == '+')
	{
	  f = fopen (&ptr[1], "a");
	}
      else
	{
	  f = fopen (ptr, "w");
	}
    }


  if (f == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Unable to open A4GL_dump file");
#endif
      return 0;
    }


//fprintf(f, "---> %d %d\n", starty, stopy);


  for (y = starty; y < sh-stopy; y++)
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


	      if ((attr & 0xff) == (ACS_VLINE & 0xff) && (attr & A_ALTCHARSET))
		{
		  attr = (int) '|';
		}
	      if ((attr & 0xff) == (ACS_HLINE & 0xff) && (attr & A_ALTCHARSET))
		{
		  attr = (int) '-';
		}
	      if ((attr & 0xff) == (ACS_LLCORNER & 0xff) && (attr & A_ALTCHARSET))
		{
		  attr = (int) '+';
		}
	      if ((attr & 0xff) == (ACS_LRCORNER & 0xff) && (attr & A_ALTCHARSET))
		{
		  attr = (int) '+';
		}
	      if ((attr & 0xff) == (ACS_URCORNER & 0xff) && (attr & A_ALTCHARSET))
		{
		  attr = (int) '+';
		}
	      if ((attr & 0xff) == (ACS_ULCORNER & 0xff) && (attr & A_ALTCHARSET))
		{
		  attr = (int) '+';
		}
	      fprintf (f, "%c", attr & 255);
	    }
	}
      fprintf (f, "\n");
    }


  if (needPclose)
    {
      pclose (f);
    }
  else
    {
      fclose (f);
    }
  return 0;
}
