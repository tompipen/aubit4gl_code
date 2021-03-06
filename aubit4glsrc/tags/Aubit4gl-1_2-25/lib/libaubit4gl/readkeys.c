/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: readkeys.c,v 1.18 2010-02-16 13:16:31 mikeaubury Exp $
#*/

/**
 * @file
 * This file can be used for batch processing a series of
 * keystrokes (mainly intended for testing purposes)
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"
#include <ctype.h>

static int have_keyfile = -1;
static FILE *keyfile;
static void open_keyfile (void);

static int have_keylog = -1;
static FILE *keylog;
static void open_keylog (void);
long key_delay = 100000;


static void
open_keyfile (void)
{
  char *fname;
  char *delay;
  have_keyfile = 0;

  fname = acl_getenv ("KEYFILE");
#ifdef DEBUG
  A4GL_debug ("Keyfilename= %s", fname);
#endif
  if (fname == 0)
    return;
  if (strlen (fname) == 0)
    return;
  keyfile = (FILE *) A4GL_open_file_dbpath (fname);

  if (keyfile == 0)
    {
      A4GL_set_errm (fname);
      A4GL_exitwith ("Unable to open key file");
      A4GL_chk_err (0, "Unknown");
      return;
    }

  have_keyfile = 1;
  delay = acl_getenv ("KEYDELAY");
  if (delay)
    {
      key_delay = atol (delay);
    }
}


int
A4GL_readkey (void)
{
  int a;
  char buff[256];
  static int ignore_keyfile=0;

  if (have_keyfile == -1)
    {
      open_keyfile ();
    }

  if (!have_keyfile || ignore_keyfile) {
    	return 0;
  }

  a = 0;
  while (a == 0)
    {
      a = fgetc (keyfile);
      if (feof (keyfile))
	{

	  if (A4GL_isyes (acl_getenv ("NEEDALLKEYS")))
	    {
	      A4GL_set_errm ("");
	      A4GL_exitwith ("Ran out of keys");
	      A4GL_chk_err (0, "Unknown");
	    }
	  have_keyfile = 0;
	  return 0;
	}
      if (a == '\r')
	a = 0;
      if (a == '\t')
	a = 0;
      if (a == '\n')
	a = 0;
    }

  if (a == '\\')
    {
      int cnt = 0;
#ifdef DEBUG
      A4GL_debug ("Getting keyval");
#endif
      while (1)
	{
	  buff[cnt] = fgetc (keyfile);
	  if (buff[cnt] == ';' || buff[cnt] == '\n' || buff[cnt] == '\r' || buff[cnt] == ' ' || buff[cnt] == ','
	      || buff[cnt] == '\\' || feof (keyfile))
	    {
	      buff[cnt] = 0;
	      break;
	    }
	  cnt++;
	  buff[cnt] = 0;
	}
#ifdef DEBUG
      A4GL_debug ("Getting keyval - %s", buff);
#endif
      if (strcmp(buff,"PAUSE")==0) {
		char str[2000];
		// We need to prompt the user to wait or do something
		// this always requires that we read direct from the keyboard 
		// and not from the keylog file!
		fgets(str,sizeof(str),keyfile);
		A4GL_trim_nl(str);
		A4GL_push_char(str);
		ignore_keyfile++;
   		A4GL_display_error(-1,1);
		ignore_keyfile--;
		return A4GL_readkey();
      }

      a = A4GL_key_val (buff);
      if (a == -1)
	{
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Unknown Key");
	  A4GL_chk_err (0, "Unknown");
	  return 0;
	}

    }
  // no usleep on Windows - usleep(key_delay);
  a4gl_usleep (key_delay);
  return a;
}








static void
open_keylog (void)
{
  char *fname;
  //char *delay;
  have_keylog = 0;

  fname = acl_getenv ("KEYLOG");
  if (fname == 0)
    return;
  if (strlen (fname) == 0)
    return;

  if (keyfile)
    {
      if (strcmp ((char *) acl_getenv ("KEYLOG"), (char *) acl_getenv ("KEYFILE")) == 0)
	{
	  A4GL_exitwith ("A4GL_KEYLOG and A4GL_KEYFILE both point to the same file");
	  return;
	}
    }

  keylog = fopen (fname, "w");

  if (keylog == (FILE *) 0)
    {
      A4GL_set_errm (fname);
      A4GL_exitwith ("Unable to open key logging file");
      A4GL_chk_err (0, "Unknown");
      return;
    }

  have_keylog = 1;
}


void
A4GL_logkey (long a)
{
  //char buff[256];
  int k;
  char *keys[] = {
    "ACCEPT",
    "DELETE",
    "INSERT",
    "HELP",
    "NEXT",
    "NEXTPAGE",
    "PREV",
    "PREVPAGE",
    "ACCEPT",
    "INTERRUPT",
    "RETURN",
    "ENTER",
    "TAB",
    "DOWN",
    "UP",
    "LEFT",
    "RIGHT",
    "ESCAPE",
    "BACKSPACE",
    "PGUP",
    "PGDN",
    0
  };


  if (have_keylog == -1)
    {
      open_keylog ();
    }

  if (!have_keylog)
    return;



  for (k = 1; k <= 36; k++)
    {
      char buff[256];
      SPRINTF1 (buff, "F%d", k);
      if (a == A4GL_key_val (buff))
	{
	  FPRINTF (keylog, "\\%s\n", buff);
	  fflush (keylog);
	  return;
	}
    }

  for (k = 0; keys[k]; k++)
    {
#ifdef DEBUG
      A4GL_debug ("Checking against built in key for %s - %d %d", keys[k], a, A4GL_key_val (keys[k]));
#endif

      if (a == A4GL_key_val (keys[k]))
	{
#ifdef DEBUG
	  A4GL_debug ("Log keypress %s in file %p", keys[k], keylog);
#endif
	  FPRINTF (keylog, "\\%s\n", keys[k]);
	  fflush (keylog);
	  return;
	}
    }

  if (a >= 1 && a <= 26)
    {
      FPRINTF (keylog, "\\CONTROL-%c\n", (char) a + 'A' - 1);
      fflush (keylog);
      return;
    }
  if ((a_isprint (a) && a != '\\') || A4GL_isyes (acl_getenv ("LOGALL")))
    {
      FPRINTF (keylog, "%c", (char) a);
      fflush (keylog);
      return;
    }

  // Darn - couldn't detect what the key was...

#ifdef DEBUG
  A4GL_debug ("Unknown key %d", a);
#endif
}
