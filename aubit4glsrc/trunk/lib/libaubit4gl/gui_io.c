/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: gui_io.c,v 1.10 2003-05-12 14:24:17 mikeaubury Exp $
#
*/

/**
 * @file
 * GUI user interface IO with a thin client.
 *
 * The purpose of this file is to implement a comunication layer with a
 * thin client.
 *
 * It is necessary make some restructuring in order to put this to work.
 * In the meanwhile this is a begining.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/



#ifdef OLD_INCL

#include <stdarg.h>
#include <stdio.h>
#include <string.h>		/* strcpy() */


#include "a4gl_aubit_lib.h"
#include "a4gl_debug.h"

#else

#include "a4gl_libaubit4gl_int.h"

#endif

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static void gui_send (char *c, char *s);
void gui_startmenu (char *mnname, long mn);
void gui_user (char *txt);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/



/**
 * Send a message to the TCP client.
 * @param c The comand to send.
 * @param s The parameters of the comand.
 */
static void
gui_send (char *c, char *s)
{
  char buff[25600];
  sprintf (buff, "%s %s\n", c, s);
  proc_it (buff);

  /*
     strcat(buffer,buff);
     if (strcmp(c,"REFRESH")==0||strcmp(c,"WREFRESH")==0||strcmp(c,"ERROR")==0) {
     debug("Calling proc_it with %s",buff);
     proc_it(buffer);
     buffer[0]=0;
     }
   */
  debug ("Sent");
}

/**
 * Send the COLOUR modification to the client.
 *
 * @param a The color code to send to the client.
 */
void
gui_setcolor (int a)
{
  char buff[256];
  sprintf (buff, "%d", a);
  gui_send ("COLOUR", buff);
  debug ("Set color..");
}

/**
 *
 *
 * @param
 */
void
gui_actmenu (long ld)
{
  char buff[256];
  sprintf (buff, "%lx", ld);
  gui_send ("MENUACT", buff);
}

/**
 *
 *
 * @param
 */
void
gui_mkfield (int h, int w, int y, int x, void *p)
{
  char buff[256];
  sprintf (buff, "%lx %d %d %d %d", (long unsigned int) p, x, y, w, h);
  debug ("gui_mkfield:Make field");
  gui_send ("MKFIELD", buff);
}

/**
 *
 *
 * @param
 */
void
gui_mklabel (int h, int w, int y, int x, char *s)
{
  char buff[256];
  sprintf (buff, "\"%s\" %d %d %d %lx", s, x, y, w, (long unsigned int) h);
  gui_send ("MKLABEL", buff);
}


/**
 *
 *
 * @param
 */
void
gui_wrefresh (void *d)
{
  char buff[256];
  sprintf (buff, "%lx", (long unsigned int) d);
#ifdef DEBUG
  /* {DEBUG} */
  {
    debug ("gui_refresh");
  }
#endif
  gui_send ("WREFRESH", buff);
}


/**
 *
 *
 * @param
 */
void
gui_refresh (void)
{
#ifdef DEBUG
  /* {DEBUG} */
  {
    debug ("gui_refresh");
  }
#endif
  gui_send ("REFRESH", "");
}

/**
 *
 *
 * @param
 */
void
gui_print (int a, char *fmt, ...)
{
  va_list args;
  char buff[25600];
  char buff2[25600];
  return;
#ifdef DEBUG
  /* {DEBUG} */
  {
    debug ("Format =%s", fmt);
  }
#endif
  va_start (args, fmt);
  vsprintf (buff, fmt, args);
  va_end (args);
  sprintf (buff2, "%d \"%s\"", a, buff);
#ifdef DEBUG
  /* {DEBUG} */
  {
    debug ("Sending %s", buff2);
  }
#endif
  gui_send ("PRINT", buff2);
}


/**
 *
 *
 * @param
 */
void
gui_move (int x, int y)
{
  char buff[256];
  sprintf (buff, "%d %d", x, y);
  gui_send ("MOVE", buff);
}

/**
 *
 *
 * @param
 */
void
gui_win (char *name, int h, int w, int y, int x, int b, long d)
{
  char buff[256];
  sprintf (buff, "%s %d %d %d %d %d %lx", name, x, y, w, h, b, d);
  debug ("Sending %s", buff);
  gui_send ("MKWIN", buff);
}

/**
 *
 *
 * @param
 */
void
gui_endmenu (long ld)
{
  char buff[256];
  sprintf (buff, "%lx", ld);
  gui_send ("ENDMENU", buff);
}

/**
 *
 *
 * @param
 */
void
gui_startform (char *name)
{
  char buff[256];

  sprintf (buff, "%s", name);

  gui_send ("STARTFORM", buff);
}

/**
 *
 *
 * @param
 */
void
gui_endform (void)
{
  gui_send ("ENDFORM", "");
}

/**
 *
 *
 * @param
 */
void
gui_startmenu (char *mnname, long mn)
{
  char buff[256];
  sprintf (buff, "\"%s\" %lx", mnname, mn);
  gui_send ("MKMENU", buff);
}

/**
 *
 *
 * @param
 */
void
gui_rmmenu (long ld)
{
  char buff[256];
  sprintf (buff, "%lx", ld);
  gui_send ("RMMENU", buff);
}


/**
 *
 *
 * @param
 */
void
gui_menuopt (char *title, long id)
{
  char buff[256];

  sprintf (buff, "\"%s\" %lx", title, id);
  debug ("Menu opt %s ", buff);
  gui_send ("MKOPT", buff);
}

/**
 *
 *
 * @param
 */
void
gui_dispform (char *s, int line)
{
  char buff[256];
  sprintf (buff, "%s %d", s, line);
  gui_send ("DISPFORM", buff);
}

/**
 *
 *
 * @param
 */
void
gui_setbuff (void *a, char *n)
{
  char buff[1024];
  sprintf (buff, "%lx %s", (long unsigned int) a, n);
  gui_send ("SETBUFF", buff);
}

/**
 *
 *
 * @param
 */
void
gui_closewin (char *name)
{
  gui_send ("RMWIN", name);
}

/**
 *
 *
 * @param
 */
void
gui_currwin (long a)
{
  char buff[1024];
  sprintf (buff, "%lx", a);
  gui_send ("CURRWIN", buff);
}

/**
 *
 *
 * @param
 */
void
gui_scroll (int a)
{
  char buff[1024];
  sprintf (buff, "%d", a);
  gui_send ("SCROLL", buff);
}

/**
 *
 *
 * @param
 */
void
gui_scrollpos (int a)
{
  char buff[1024];
  sprintf (buff, "%d", a);
  gui_send ("SCROLLPOS", buff);
}

/**
 *
 *
 * @param
 */
void
gui_setattr (long a, int f, int b)
{
  char buff[256];
  sprintf (buff, "%lx %d %d", a, f, b);
  gui_send ("SETATTR", buff);
}

/**
 *
 *
 * @param
 */
void
gui_startprompt (long ld)
{
  char buff[256];
  sprintf (buff, "%lx", ld);
  gui_send ("STARTPROMPT", buff);
}


/**
 *
 *
 * @param
 */
void
gui_endprompt (long ld)
{
  char buff[256];
  sprintf (buff, "%lx", ld);
  gui_send ("ENDPROMPT", buff);
}

/**
 *
 *
 * @param
 */
void
gui_setfocus (long ld)
{
  char buff[256];
  debug ("gui_set focus %lx", ld);
  sprintf (buff, "%lx", ld);
  gui_send ("SETFOCUS", buff);
}

/**
 *
 *
 * @param
 */
void
gui_setposition (long ld)
{
  char buff[256];
  debug ("gui_set position %lx", ld);
  sprintf (buff, "%lx", ld);
  gui_send ("SETPOSITION", buff);
}

/**
 *
 *
 * @param
 */
void
gui_message (char *txt, int msgline)
{
  char buff[256];
  char buff2[256];
  strcpy (buff2, txt);
  trim (buff2);
  sprintf (buff, "\"%s\" %d", buff2, msgline);
  gui_send ("MESSAGE", buff);
}


/**
 * Send an error to the client.
 *
 * @param txt The error text.
 * @param errline The place where the error ocurred.
 */
void
gui_error (char *txt, int errline)
{
  char buff[256];
  char buff2[256];
  strcpy (buff2, txt);
  trim (buff2);
  debug ("In gui_error");
  sprintf (buff, "\"%s\" %d", buff2, errline);
  gui_send ("ERROR", buff);
}


/**
 *
 *
 * @param
 */
void
gui_user (char *txt)
{
  gui_send ("USER", txt);
}


/* ============================= EOF =============================== */
