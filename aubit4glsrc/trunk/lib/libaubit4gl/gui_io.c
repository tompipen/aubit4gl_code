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
# $Id: gui_io.c,v 1.11 2003-05-15 07:10:40 mikeaubury Exp $
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
 * @todo Doxygen A4GL_comments to add to functions
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
void A4GL_gui_startmenu (char *mnname, long mn);
void A4GL_gui_user (char *txt);

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
  A4GL_proc_it (buff);

  /*
     strcat(buffer,buff);
     if (strcmp(c,"REFRESH")==0||strcmp(c,"WREFRESH")==0||strcmp(c,"ERROR")==0) {
     A4GL_debug("Calling A4GL_proc_it with %s",buff);
     proc_it(buffer);
     buffer[0]=0;
     }
   */
  A4GL_debug ("Sent");
}

/**
 * Send the COLOUR modification to the client.
 *
 * @param a The color code to send to the client.
 */
void
A4GL_gui_setcolor (int a)
{
  char buff[256];
  sprintf (buff, "%d", a);
  gui_send ("COLOUR", buff);
  A4GL_debug ("Set color..");
}

/**
 *
 *
 * @param
 */
void
A4GL_gui_actmenu (long ld)
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
A4GL_gui_mkfield (int h, int w, int y, int x, void *p)
{
  char buff[256];
  sprintf (buff, "%lx %d %d %d %d", (long unsigned int) p, x, y, w, h);
  A4GL_debug ("gui_mkfield:Make field");
  gui_send ("MKFIELD", buff);
}

/**
 *
 *
 * @param
 */
void
A4GL_gui_mklabel (int h, int w, int y, int x, char *s)
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
A4GL_gui_wrefresh (void *d)
{
  char buff[256];
  sprintf (buff, "%lx", (long unsigned int) d);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("gui_refresh");
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
A4GL_gui_refresh (void)
{
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("gui_refresh");
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
A4GL_gui_print (int a, char *fmt, ...)
{
  va_list args;
  char buff[25600];
  char buff2[25600];
  return;
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Format =%s", fmt);
  }
#endif
  va_start (args, fmt);
  vsprintf (buff, fmt, args);
  va_end (args);
  sprintf (buff2, "%d \"%s\"", a, buff);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Sending %s", buff2);
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
A4GL_gui_move (int x, int y)
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
A4GL_gui_win (char *name, int h, int w, int y, int x, int b, long d)
{
  char buff[256];
  sprintf (buff, "%s %d %d %d %d %d %lx", name, x, y, w, h, b, d);
  A4GL_debug ("Sending %s", buff);
  gui_send ("MKWIN", buff);
}

/**
 *
 *
 * @param
 */
void
A4GL_gui_endmenu (long ld)
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
A4GL_gui_startform (char *name)
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
A4GL_gui_endform (void)
{
  gui_send ("ENDFORM", "");
}

/**
 *
 *
 * @param
 */
void
A4GL_gui_startmenu (char *mnname, long mn)
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
A4GL_gui_rmmenu (long ld)
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
A4GL_gui_menuopt (char *title, long id)
{
  char buff[256];

  sprintf (buff, "\"%s\" %lx", title, id);
  A4GL_debug ("Menu opt %s ", buff);
  gui_send ("MKOPT", buff);
}

/**
 *
 *
 * @param
 */
void
A4GL_gui_dispform (char *s, int line)
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
A4GL_gui_setbuff (void *a, char *n)
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
A4GL_gui_closewin (char *name)
{
  gui_send ("RMWIN", name);
}

/**
 *
 *
 * @param
 */
void
A4GL_gui_currwin (long a)
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
A4GL_gui_scroll (int a)
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
A4GL_gui_scrollpos (int a)
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
A4GL_gui_setattr (long a, int f, int b)
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
A4GL_gui_startprompt (long ld)
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
A4GL_gui_endprompt (long ld)
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
A4GL_gui_setfocus (long ld)
{
  char buff[256];
  A4GL_debug ("gui_set focus %lx", ld);
  sprintf (buff, "%lx", ld);
  gui_send ("SETFOCUS", buff);
}

/**
 *
 *
 * @param
 */
void
A4GL_gui_setposition (long ld)
{
  char buff[256];
  A4GL_debug ("gui_set position %lx", ld);
  sprintf (buff, "%lx", ld);
  gui_send ("SETPOSITION", buff);
}

/**
 *
 *
 * @param
 */
void
A4GL_gui_message (char *txt, int msgline)
{
  char buff[256];
  char buff2[256];
  strcpy (buff2, txt);
  A4GL_trim (buff2);
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
A4GL_gui_error (char *txt, int errline)
{
  char buff[256];
  char buff2[256];
  strcpy (buff2, txt);
  A4GL_trim (buff2);
  A4GL_debug ("In gui_error");
  sprintf (buff, "\"%s\" %d", buff2, errline);
  gui_send ("ERROR", buff);
}


/**
 *
 *
 * @param
 */
void
A4GL_gui_user (char *txt)
{
  gui_send ("USER", txt);
}


/* ============================= EOF =============================== */
