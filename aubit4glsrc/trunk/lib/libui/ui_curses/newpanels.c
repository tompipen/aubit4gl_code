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
# $Id: newpanels.c,v 1.39 2003-06-06 09:52:37 mikeaubury Exp $
#*/

/**
 * @file
 * Pannels implementation, like windows, prompts lines, etc
 *
 * @todo Add Doxygen A4GL_comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_ui_tui_int.h"
#include <ctype.h>

/*
=====================================================================
                Platform specific definitions
=====================================================================
*/


#ifdef __CYGWIN__
dll_import struct s_form_attr std_dbscr;
dll_import sqlca_struct sqlca;
#endif

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define MAXWIN 200
#define MAXPOINTERS 2000

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

WINDOW *currwin;
int scr_width = -1;
int scr_height = -1;
int currwinno = -1;
int currattr = 0;

/*
   struct ptrs
   {
   char ptr_type;
   char name[20];
   void *ptr;
   }
   pointers[MAXPOINTERS];
 */

struct s_windows
{
  int x, y, w, h;
  PANEL *pan;
  WINDOW *win;
  char name[20];
  struct s_form_dets *form;
  struct s_form_attr winattr;
};


struct s_windows windows[MAXWIN];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/
/** @todo Take this prototypes of from here */

int A4GL_mja_vwprintw (WINDOW * win, char *fmt, va_list * args);
//int   A4GL_current_window          (char *win_name);
void print_panel_stack (void);
void A4GL_init_stddbscr (void);
void A4GL_do_update_panels (void);
void A4GL_change_currwinno (int a, char *s);
void A4GL_change_currwin (WINDOW * a, char *s);
void A4GL_inc_winname (char *b);
int A4GL_getch_swin (WINDOW * window_ptr);
int A4GL_getform_line (void);
int A4GL_find_win (PANEL * p);
int A4GL_chkwin (void);
int A4GL_screen_height (void);
int A4GL_top_win (PANEL * p);
char *A4GL_pointer_code (int c);
//void  A4GL_clr_window                      (char *win_name);
int A4GL_int_current_window (char *win_name);
int A4GL_get_curr_win (void);
int A4GL_get_curr_height (void);
int A4GL_get_curr_top (void);
char *A4GL_get_currwin_name (void);
int A4GL_get_curr_border (void);
void display_at2 (char *z, int x, int y, int a);
int A4GL_decode_line (int l);
//void  A4GL_display_error           (int a,int wait);
//void A4GL_add_compiled_form (char *s, char *frm);
//int   A4GL_open_form                       (char *name);
//void  A4GL_close_form                      (char *formname);
//int   A4GL_disp_form                       (char *name, int attr);
int A4GL_set_window (int a);
int A4GL_subwin_printxy (WINDOW * win, int x, int y, char *fmt, ...);
int A4GL_subwin_setcolor (WINDOW * win, int typ);
int A4GL_getcomment_line (void);
void A4GL_set_attr_win (char s, int wattr);
char *A4GL_windowname_on_top (void);
int A4GL_invert_color (int a);
//void  A4GL_sleep_i                         (void);

WINDOW *A4GL_window_on_top (void);
WINDOW *A4GL_display_form_new_win (char *name, struct s_form_dets *f, int x,
			      int y);
WINDOW *A4GL_display_form (struct s_form_dets *f);
WINDOW *A4GL_create_window (char *name, int x, int y, int w, int h, int iswindow,
		       int form_line, int error_line, int prompt_line,
		       int menu_line, int border, int comment_line,
		       int message_line, int attrib);
WINDOW *A4GL_display_form_win (WINDOW * w, char *name, struct s_form_dets *f);

//void *        A4GL_cr_window                       (char *s,int iswindow,int form_line,int error_line,int prompt_line,
					//int menu_line,int border,int comment_line,int message_line,int attrib);
//int   A4GL_cr_window_form          (char *name,int iswindow,int form_line,int error_line,
					//int prompt_line,int menu_line,int border,int comment_line,int message_line,
					//int attrib);


//void *A4GL_read_form (char *fname, char *formname);
//LIBEXPORT void A4GL_hide_window    (char *winname);
//LIBEXPORT void A4GL_show_window    (char *winname);
//LIBEXPORT int A4GL_movewin                 (char *winname, int absol);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/



/**
 * Find the description of the pointer type
 *
 * @todo Understand and fix the duplicate definition of CODE(s) in pointers.h
 * and dbforms.h.
 *
 * @param c The pointer type in integer (described by some defines 
 * from pointers.h and dbforms.h)
 * @return a string that identifies the pointer type
 */
char *
A4GL_pointer_code (int c)
{
  switch (c)
    {

    case PANCODE:
      return "'panel'";
    case WINCODE:
      return "'window'";
    case CURCODE:
      return "'cursor'";
    case PRECODE:
      return "'prepare statement'";
    case MNWINCODE:
      return "'Menu Window'";
    case MNPARCODE:
      return "'Menu Parent'";
    case FORMCODE:
      return "'form'";
    case S_WINDOWSCODE:
      return "'windows information'";
    case S_FORMDETSCODE:
      return "'form details'";
    case SESSCODE:
      return "'session'";
    case RPC_FUNC:
      return "'RPC Function'";
    }
  return "Unknown";
}

/**
 *
 * @todo Describe function
 */
LIBUSEONLY int
A4GL_init_windows (void)
{
  int a;
  for (a = 0; a < MAXWIN; a++)
    {
      windows[a].name[0] = 0;
    }
  A4GL_create_blank_window ("screen", 1, 1, 79, 23, 0);
  A4GL_current_window ("screen");
  /*error_box("Currwin=screen"); */
  A4GL_init_stddbscr ();
  return 0;

}

/**
 *
 * @todo Describe function
 */
LIBUSEONLY void *
A4GL_create_blank_window (char *name, int x, int y, int w, int h, int border)
{
  A4GL_chkwin();
  return A4GL_create_window (name, x, y, w, h, 1, 1, 1, 1, 1, border, 1, 1,
			0xffff);
}

/**
 *
 * @todo Describe function
 */
WINDOW *
A4GL_create_window (char *name, int x, int y, int w, int h,
	       int iswindow,
	       int form_line,
	       int error_line,
	       int prompt_line,
	       int menu_line,
	       int border, int comment_line, int message_line, int attrib)
{
  WINDOW *win = 0;
  WINDOW *dswin;
  PANEL *pan;
  int a;
  A4GL_chkwin ();

#ifdef DEBUG
  A4GL_debug ("Creating window %s (%d %d %d %d) border=%d attrib=0x%x", name, x, y,
	 w, h, border, attrib);
#endif

  if (form_line == 0xff)
    {
      form_line = std_dbscr.form_line;
    }
  if (menu_line == 0xff)
    {
      menu_line = std_dbscr.menu_line;
    }
  if (comment_line == 0xff)
    {
      comment_line = std_dbscr.comment_line;
    }
  if (message_line == 0xff)
    {
      message_line = std_dbscr.comment_line;
    }
  if (error_line == 0xff)
    {
      error_line = std_dbscr.error_line;
    }
  if (prompt_line == 0xff)
    {
      prompt_line = std_dbscr.prompt_line;
    }

  if (attrib == 0xffff)
    {
      char *s;
      int a;
      int n;
      s = acl_getenv ("BACKGROUND");
      if (strlen (s))
	{
	  n = sscanf (s, "%x", &a);
	  if (n)
	    {
	      attrib = a;
	    }
	}
      else
	{
	  attrib = 0x0;
	}

    }


  if (strcmp (name, "screen") == 0)
    {
      h = A4GL_screen_height () - 1;
      w = A4GL_screen_width () - 1;
      A4GL_debug ("Creating window : h=%d w=%d y=%d x=%d", h, w, y - 1, x - 1);
      A4GL_debug ("win = newwin (%d,%d,0,0)", A4GL_screen_height (), A4GL_screen_width ());
      win = newwin (A4GL_screen_height (), A4GL_screen_width (), 0, 0);
      A4GL_debug ("Calling screen height");
      A4GL_debug ("h=%d", h);
      A4GL_debug ("Calling screen width");
      A4GL_debug ("w=%d", w);
      A4GL_set_bkg (win, attrib);

      A4GL_gui_win (name, A4GL_screen_height (), A4GL_screen_width (), 1, 1, 0, (long) win);
      A4GL_add_pointer (name, WINCODE, win);
    }
  else
    {

      if (border == 1)
	{
	  win = newwin (h + 2, w + 2, y - 2, x - 2);
	  if (toupper (name[0]) != name[0])
	    A4GL_gui_win (name, h + 2, w + 2, y - 2, x - 2, 1, (long) win);
	  A4GL_add_pointer (name, WINCODE, win);
	}

      if (border == 2)
	{
	  dswin = newwin (h + 4, w + 4, y - 2, x - 2);
	  win = newwin (h + 2, w + 2, y - 2, x - 2);
	  A4GL_add_pointer (name, WINCODE, win);
	  A4GL_add_pointer (name, DROPSHADOW, dswin);
	  A4GL_set_bkg (dswin, '+');
	  A4GL_debug ("XX3 REVERSE");
	  wbkgdset (dswin, COLOR_RED | A_REVERSE);
	  A4GL_mja_wrefresh (dswin);
	  sleep (2);
	}

      if (border == 3)
	{
	  dswin = newwin (h + 4, w + 4, y - 1, x - 1);
	  win = newwin (h, w, y - 2, x - 2);
	  A4GL_add_pointer (name, WINCODE, win);
	  A4GL_add_pointer (name, DROPSHADOW, dswin);
	  A4GL_debug ("XX4 REVERSE");
	  wbkgdset (dswin, COLOR_RED | A_REVERSE);
	  A4GL_mja_wrefresh (dswin);
	  sleep (2);
	}

      if (border == 0)
	{
	  win = newwin (h, w, y - 1, x - 1);
	  if (toupper (name[0]) != name[0])
	    A4GL_gui_win (name, h, w, y - 1, x - 1, 0, (long) win);
	  A4GL_add_pointer (name, WINCODE, win);
	  A4GL_debug ("Window = %p", win);
	}

    }

#ifdef DEBUG
  A4GL_debug ("Window created");
#endif

  if (win == 0)
    {
#ifdef DEBUG
      A4GL_debug ("COuldnt create window h=%d w=%d y=%d x=%d", h, w, y, x);
#endif
      A4GL_exitwith ("Couldnt create window");
      return 0;
    }

  A4GL_mja_wrefresh (win);

  //attrib=attrib&0xff00;

  if ((attrib & 0xff) == 0 || (attrib & 0xff) == 0xff)
    {
      attrib = attrib + ' ';
      A4GL_debug ("Set pad char to space");
    }
  A4GL_debug ("Setting attribute for window to 0x%x for %s\n", attrib, name);



  A4GL_set_bkg (win, attrib);


  A4GL_add_pointer (name, ATTRIBUTE, (void *) attrib);
  if (border)
    {
      //wbkgdset (win, attrib);
      A4GL_debug ("Adding border %x", attrib);

      A4GL_set_bkg (win, attrib);

      wborder (win, 0, 0, 0, 0, 0, 0, 0, 0);
      //wbkgdset (win, 0);
      A4GL_mja_wrefresh (win);
    }

  pan = new_panel (win);
  set_panel_userptr (pan, strdup (name));
  A4GL_add_pointer (name, PANCODE, pan);

#ifdef DEBUG
  {
    A4GL_debug ("Panel created at %p for window %p", pan, win);
  }
#endif

  if (pan == 0)
    {
      A4GL_error_box ("Couldnt create panel");
    }


  for (a = 0; a < MAXWIN; a++)
    {
      if (windows[a].name[0] == 0)
	{
#ifdef DEBUG
	  {
	    A4GL_debug ("Adding window at %d panel id = %p", a, pan);
	  }
#endif
	  strcpy (windows[a].name, name);
	  A4GL_add_pointer (name, S_WINDOWSCODE, &windows[a]);
	  windows[a].pan = pan;
	  windows[a].form = 0;
	  windows[a].winattr.comment_line = comment_line;
	  windows[a].winattr.menu_line = menu_line;
	  A4GL_debug ("Setting prompt line to %d", prompt_line);
	  windows[a].winattr.prompt_line = prompt_line;
	  windows[a].winattr.form_line = form_line;
	  windows[a].winattr.message_line = message_line;
	  windows[a].winattr.border = border;
	  windows[a].winattr.colour = attrib;
	  windows[a].x = x;
	  windows[a].y = y;
	  windows[a].w = w;
	  windows[a].h = h;
	  windows[a].win = win;
	  /* A4GL_change_currwin (win); */
	  break;
	}
    }
  if (!(A4GL_has_pointer (name, S_WINDOWSCODE)))
    {
      A4GL_exitwith ("No spare windows left...");
      return 0;
    }

  keypad (win, TRUE);

  A4GL_debug ("Deciding what to do... %s\n", name);
  if (toupper (name[0]) != name[0])
    {
#ifdef DEBUG
      {
 A4GL_debug ("Making proper window....for %s", name);
      }
#endif
      A4GL_change_currwin (win, "Marker 1");
      A4GL_change_currwinno (a, "Marker 2");
      top_panel (pan);

      if (A4GL_screen_mode (-1))
	{
	  update_panels ();
	  doupdate ();
	}
#ifdef DEBUG
      {
 A4GL_debug ("Adding new pointer to window...");
      }
      {
 A4GL_debug ("Done...");
      }
#endif
    }
  else
    {
#ifdef DEBUG
      {
 A4GL_debug ("Adding window pointers for menu %p > %p", currwin, win);
      }
#endif
      A4GL_add_pointer (name, MNPARCODE, currwin);
      A4GL_add_pointer (name, MNWINCODE, win);

      top_panel (pan);
      if (A4GL_screen_mode (-1))
	{
	  update_panels ();
	  doupdate ();
	}

    }
  return win;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_clr_window (char *win_name)
{
  int a;
  WINDOW *w;
  struct s_windows *win;
  A4GL_chkwin ();
  if (!(A4GL_has_pointer (win_name, WINCODE)))
    {
      A4GL_set_error ("Window not found %s", win_name);
      A4GL_exitwith ("Window not found");
      A4GL_set_errm (win_name);
      return;
    }
#ifdef DEBUG
  {
    A4GL_debug ("Clr window .... %s", win_name);
  }
#endif
  w = A4GL_find_pointer (win_name, WINCODE);
  win = A4GL_find_pointer (win_name, S_WINDOWSCODE);
  wclear (w);

  if (win->winattr.border)
    {
      A4GL_debug ("Clr screen - redraw border");
      wborder (w, 0, 0, 0, 0, 0, 0, 0, 0);
    }
  A4GL_zrefresh ();
  return;

  for (a = 0; a < MAXWIN; a++)
    {
      if (strcmp (windows[a].name, win_name) == 0)
	{
	  wclear (panel_window (windows[a].pan));
	  break;
	}
    }
  A4GL_zrefresh ();
}



/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_remove_window (char *win_name)
{
  int a;
  WINDOW *win = 0;
  PANEL *panel = 0;
  A4GL_chkwin ();
#ifdef DEBUG
  A4GL_gui_closewin (win_name);
  {
    A4GL_debug ("Remove Window : %s", win_name);
  }
#endif

  if (!(A4GL_has_pointer (win_name, WINCODE)))
    {
      A4GL_set_error ("Window not found %s", win_name);
      A4GL_exitwith ("Window not found");
      A4GL_set_errm (win_name);
      return;
    }

  for (a = 0; a < MAXWIN; a++)
    {
      if (strcmp (windows[a].name, win_name) == 0)
	{
	  win = panel_window (windows[a].pan);
	  panel = windows[a].pan;
#ifdef DEBUG
	  {
	    A4GL_debug ("Deleting window and panel at %d", a);
	  }
	  {
	    A4GL_debug ("Window found ... deleting... %p", win);
	  }
	  {
	    A4GL_debug ("Deleted window.. deleting panel %p", panel);
	  }
#endif
	  del_panel (panel);
#ifdef DEBUG
	  {
	    A4GL_debug ("Deleted panel ... removing window");
	  }
#endif
	  delwin (win);
#ifdef DEBUG
	  {
	    A4GL_debug ("Here...");
	  }
#endif
	  windows[a].name[0] = 0;
	  break;
	}
    }
#ifdef DEBUG
  {
    A4GL_debug ("Finding top window number");
  }
#endif
  A4GL_top_win (0);
  update_panels ();
  doupdate ();
  refresh ();
  A4GL_zrefresh ();
#ifdef DEBUG
  {
    A4GL_debug ("Deleting pointer %s", win_name);
  }
#endif
  A4GL_del_pointer (win_name, WINCODE);

}

/**
 *
 * @todo Describe function
 */
int
A4GL_int_current_window (char *win_name)
{
  PANEL *p;
  WINDOW *w;
  A4GL_chkwin ();
  p = A4GL_find_pointer (win_name, PANCODE);
  w = A4GL_find_pointer (win_name, WINCODE);
  if (!(p))
    {
      A4GL_set_error ("%s", win_name);
      A4GL_exitwith ("Window not found");
      A4GL_set_errm (win_name);
      return 0;
    }
  top_panel (p);

  if (A4GL_screen_mode (-1))
    {
      update_panels ();
      doupdate ();
    }
  A4GL_zrefresh ();
  return 0;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_current_window (char *win_name)
{
  int a = 0;
  PANEL *p;
  WINDOW *w;
  A4GL_debug ("Current window....");
  A4GL_debug ("currwinno=%d currwin=%p", currwinno, currwin);

  A4GL_chkwin ();
#ifdef DEBUG
  {
    A4GL_debug ("In current window %s", win_name);
  }
#endif
  p = A4GL_find_pointer (win_name, PANCODE);
  w = A4GL_find_pointer (win_name, WINCODE);
  if (!(p))
    {
      A4GL_set_error ("%s", win_name);
      A4GL_exitwith ("Window not found");
      A4GL_set_errm (win_name);
      return 0;
    }
  top_panel (p);
#ifdef DEBUG
  {
    A4GL_debug ("Resetting current window %d", a);
  }
#endif
  A4GL_change_currwin (panel_window (p), "Marker 5");
  A4GL_change_currwinno (A4GL_find_win (p), "Marker 6");
#ifdef DEBUG
  {
    A4GL_debug ("Changed windows...");
  }
#endif
  if (A4GL_screen_mode (-1))
    {
      update_panels ();
      doupdate ();
    }
#ifdef DEBUG
  {
    A4GL_debug ("Updated screen %p", currwin);
  }
#endif
  A4GL_mja_wrefresh (currwin);
#ifdef DEBUG
  {
    A4GL_debug ("wrefresh");
  }
#endif
  A4GL_zrefresh ();
  A4GL_mja_refresh ();
#ifdef DEBUG
  {
    A4GL_debug ("Refreshed screen");
  }
#endif
  return 0;

}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_zrefresh (void)
{
  A4GL_gui_refresh ();
  if (A4GL_screen_mode (-1))
    {
      A4GL_chkwin ();
      update_panels ();
      doupdate ();
      /* A4GL_mja_wrefresh (currwin); */
      A4GL_mja_refresh ();
    }
}

/**
 *
 * @todo Describe function
 */
void
A4GL_mja_gotoxy (int x, int y)
{
  int a;
  A4GL_chkwin ();

  A4GL_debug ("In move - %d %d current window=%p", x, y, A4GL_window_on_top ());
  A4GL_gui_move (x, y);
  A4GL_debug ("In move - %d %d", x, y);
  if (windows[currwinno].winattr.border)
    {
      A4GL_debug ("In move border - %d %d", x, y);
      a = wmove (currwin, y, x);
    }
  else
    {
      A4GL_debug ("In move no border - %d %d", x, y);
      a = wmove (currwin, y - 1, x - 1);
    }
  A4GL_debug ("In move - %d %d", x, y);
  if (a == OK)
    {
      A4GL_debug ("Move to %d,%d - %d", x, y, a);
    }
  else
    {
      A4GL_debug ("Move to %d %d fails", x, y);
    }
  A4GL_mja_refresh ();
}

/**
 * Renamed from 'print' to 'tui_print'
 * @todo Describe function
 */
void
A4GL_tui_print (char *fmt, ...)
{
  va_list args;
  char buff[256];
#ifdef DEBUG
  {
    A4GL_debug ("In tui_print");
  }
#endif
  A4GL_chkwin ();
  va_start (args, fmt);
  vsprintf (buff, fmt, args);
  //wprintw (currwin, "%s", buff);
  waddstr (currwin, buff);

  A4GL_mja_wrefresh (currwin);
}

/**
 * Not used
 * @todo Describe function
 */
/*
static void
erase_form (FORM * f)
{
  WINDOW *w = form_win (f);
  WINDOW *s = form_sub (f);
  A4GL_chkwin ();
  unpost_form (f);
  werase (w);
  A4GL_mja_wrefresh (w);
#ifdef DEBUG
  {    A4GL_debug ("Removing Window %p", s);  }
  {    A4GL_debug ("Removing Window %w", s);  }
#endif
  delwin (s);
  delwin (w);
}
*/

/**
 *
 * @todo Describe function
 */
WINDOW *
A4GL_display_form (struct s_form_dets *f)
{
  int rows, cols;
  char buff[80];
  int a;
  int informix_behaviour = 1;
  WINDOW *w;
  WINDOW *drwin;
  /*  FIELD **p; */

  int fl;
  A4GL_chkwin ();
  A4GL_debug ("In display_form");
  w = currwin;

  if (w == 0)
    {
      A4GL_error_box ("NO WINDOW");
    }
  A4GL_debug ("scale form %p", f->form);

  fl = A4GL_getform_line ();
  scale_form (f->form, &rows, &cols);
  rows = f->fileform->maxline - 1;
  cols = f->fileform->maxcol;

  A4GL_debug ("Form line=%d", fl);
  A4GL_debug ("Scale form returns %d %d", rows, cols);
  A4GL_debug ("Current window %d %d", windows[currwinno].h, windows[currwinno].w);

  if (windows[currwinno].winattr.border)
    {
      rows++;
    }
  else
    {
    }

  if (rows - windows[currwinno].winattr.border > windows[currwinno].h + 1)
    {
      A4GL_exitwith ("Window is too small to display this form (too high)");
      return 0;
    }
  if (cols - windows[currwinno].winattr.border > windows[currwinno].w + 1)
    {
      A4GL_exitwith ("Window is too small to display this form (too wide)");
      return 0;
    }


  /* fix - not sure whats going on here bit form_details.border is set to 1 for the screen! */


  if (informix_behaviour)
    {
      rows = windows[currwinno].h - fl;
      cols = windows[currwinno].w;
    }

  f->form_details.border = windows[currwinno].winattr.border;

  if (f->form_details.border)
    {
      A4GL_debug ("Form details returns it has border");
    }
  else
    {
      A4GL_debug ("Form details returns it has *NO* border");
    }

  if (windows[currwinno].winattr.border)
    {
      A4GL_debug ("Window details returns it has border");
    }
  else
    {
      A4GL_debug ("Window details returns it has *NO* border ");
    }
  A4GL_debug ("derwin - %d rows %d cols form line=%d", rows, cols, fl);

  if (windows[currwinno].winattr.border)
    {
      A4GL_debug ("MJAPASS1");
      drwin = derwin (w, rows, cols, fl + 1, 1);
    }
  else
    {
      A4GL_debug ("MJAPASS2 rows=%d cols=%d fl=%d", rows, cols, fl);
      drwin = derwin (w, rows, cols, fl - 1, 0);

    }

#ifdef DEBUG
  {
    A4GL_debug ("drwin=%p", drwin);
  }
#endif

  if (drwin == 0)
    {
      A4GL_exitwith ("Window is too small to display this form");
      return 0;
    }

  wclear (drwin);
  a = set_form_win (f->form, w);

  if (a == E_POSTED)
    {
      unpost_form (f->form);
      a = set_form_win (f->form, w);
    }

  a = set_form_sub (f->form, drwin);

  A4GL_debug ("setup windows");
  keypad (w, TRUE);
  sprintf (buff, "Currwinno=%d", currwinno);
  /*error_box(buff); */
  windows[currwinno].form = f;

  if (f->form == 0)
    {
      A4GL_exitwith ("Unable to create form");
      return 0;
    }

  A4GL_debug ("post the form s_form_dets=%p form=%p", f, f->form);
  a = post_form (f->form);

  if (a == E_POSTED)
    {
      A4GL_debug ("Form posted already - dumping and re-doing");
      unpost_form (f->form);
      a = post_form (f->form);
    }

  if (f->form_details.border)
    {
      A4GL_debug ("Form has border");
      wborder (currwin, 0, 0, 0, 0, 0, 0, 0, 0);
    }
  A4GL_debug ("start the form");
  A4GL_start_form (f);

  A4GL_mja_wrefresh (w);
  A4GL_debug ("And return");
  return w;
}


/**
 *
 * @todo Describe function
 */
WINDOW *
A4GL_display_form_new_win (char *name, struct s_form_dets * f, int x, int y)
{
  WINDOW *w;
  int nlines;
  int rows, cols;
  char buff[80];
  A4GL_chkwin ();
  A4GL_debug ("display_form_new_win - name=%s\n", name);
  A4GL_chkwin();
  scale_form (f->form, &rows, &cols);
  if (f->form_details.border)
    {
      rows = f->fileform->maxline - 1;
    }
  else
    {
      rows = f->fileform->maxline;
    }
  cols = f->fileform->maxcol;
  A4GL_debug ("display_form_new_win : %d rows %d cols at %d,%d x,y", rows, cols, x,
	 y);

  A4GL_debug ("display_form_new_win - border=%d", f->form_details.border);
  sprintf (buff, "%d %d", cols, rows);
#ifdef DEBUG
  {				/*debug("Rows=%d formline=%d f2 = %d",rows,getform_line(),f->form_details.form_line); */
  }
#endif
  nlines = rows + f->form_details.form_line - 1;
  if (f->form_details.border)
    {
      nlines++;
    }
  w = A4GL_create_window (name, x, y, cols, nlines,
		     1,
		     f->form_details.form_line,
		     f->form_details.error_line,
		     f->form_details.prompt_line,
		     f->form_details.menu_line,
		     f->form_details.border,
		     f->form_details.comment_line,
		     f->form_details.message_line, f->form_details.colour);

  A4GL_gui_dispform (name, A4GL_getform_line ());
  if (A4GL_display_form (f))
    return w;
  else
    return 0;
}

/**
 *
 * @todo Describe function
 */
WINDOW *
A4GL_display_form_win (WINDOW * w, char *name, struct s_form_dets * f)
{
  A4GL_chkwin ();
#ifdef DEBUG
  {
    A4GL_debug ("setting form window for %p to %p", f->form, w);
  }
#endif

  set_form_win (f->form, w);
  set_form_sub (f->form, derwin (w, 8, 58, 1, 1));
  keypad (w, TRUE);
  A4GL_gui_dispform (name, A4GL_getform_line ());
  post_form (f->form);
  A4GL_start_form (f->form);
  return w;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_win (void)
{
  return currwinno;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void *
A4GL_get_curr_form (void)
{
  char buff[80];
  sprintf (buff, "currwinno=%d", currwinno);

#ifdef DEBUG
  {
    A4GL_debug ("currwinno=%d", currwinno);
  }
#endif

  /*error_box(buff); */
  if (windows[currwinno].form == 0)
    {
      A4GL_exitwith ("No current form");
      return 0;
    }
  return windows[currwinno].form;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_left (void)
{
  return windows[currwinno].x;
/* + windows[currwinno].winattr.border; */
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_height (void)
{
  return windows[currwinno].h;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_print_top (void)
{
#ifdef DEBUG
  {
    A4GL_debug ("In curr_print_top %d %d", windows[currwinno].winattr.border,
	   windows[currwinno].y);
  }
#endif

  return windows[currwinno].y + windows[currwinno].winattr.border;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_top (void)
{
  return windows[currwinno].y;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_width (void)
{
  A4GL_chkwin ();
  A4GL_debug ("get curr width, currwinno=%d windows name =%s %d", currwinno,
	 windows[currwinno].name, windows[currwinno].w);
  return windows[currwinno].w;
}

/**
 *
 * @todo Describe function
 */
char *
A4GL_get_currwin_name (void)
{
  return windows[currwinno].name;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_border (void)
{
  A4GL_debug ("get curr border, currwinno=%d windows name =%s %d", currwinno,
	 windows[currwinno].name, windows[currwinno].winattr.border);
  return windows[currwinno].winattr.border;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_mja_setcolor (int typ)
{
  A4GL_gui_setcolor (typ);
  A4GL_debug ("Set color.");
  if (has_colors ())
    {
      A4GL_debug ("Has color\n");
      switch (typ)
	{
	case ERROR_COL:
	  A4GL_debug ("XX4 REVERSE");
	  currwin->_attrs = A4GL_colour_code (COLOR_RED) | A_REVERSE;
	  break;
	case MESSAGE:
	  A4GL_debug ("XX4 REVERSE");
	  currwin->_attrs = A4GL_colour_code (COLOR_CYAN) | A_REVERSE;
	  break;
	case NORMAL_MENU:
	  standend ();
	  /* currwin->_attrs = A4GL_colour_code (COLOR_WHITE); */
	  break;
	case INVERT_MENU:
	  standout ();
	  A4GL_debug ("XX4 REVERSE");
	  /* currwin->_attrs = A4GL_colour_code (COLOR_WHITE) | A_REVERSE; */
	  break;
	case TITLE_COL:
	  currwin->_attrs = A4GL_colour_code (COLOR_WHITE);
	  break;
	case EDIT_FIELD:
	  currwin->_attrs = A4GL_colour_code (COLOR_WHITE);
	  break;
	case NORMAL_TEXT:
	  /* currwin->_attrs = A4GL_colour_code (COLOR_WHITE); */
	  standend ();
	  break;
	}
      currattr = typ;
    }
  else
    {
      switch (typ)
	{
	case ERROR_COL:
	  A4GL_debug ("XX4 REVERSE");
	  currwin->_attrs = A_REVERSE;
	  break;
	case MESSAGE:
	  standend ();
	  break;
	case NORMAL_MENU:
	  standend ();
	  break;
	case INVERT_MENU:
	  standout ();
	  A4GL_debug ("XX4 REVERSE");
	  /* currwin->_attrs = A_REVERSE; */
	  break;
	case TITLE_COL:
	  A4GL_debug ("XX4 REVERSE");
	  currwin->_attrs = A_REVERSE;
	  break;
	case EDIT_FIELD:
	  A4GL_debug ("XX4 REVERSE");
	  currwin->_attrs = A_REVERSE;
	  break;
	case NORMAL_TEXT:
	  standend ();
	  break;
	}
    }
  A4GL_debug ("Done..");
}


/**
 *
 * @todo Describe function
 */
int
A4GL_getch_win (void)
{
int a;
  A4GL_debug ("getch_win called...");
  a=A4GL_getch_swin (A4GL_window_on_top ());
  A4GL_clr_error_nobox();
  return a;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_getch_swin (WINDOW * window_ptr)
{
  int a;
  if (A4GL_isgui ())
    {
      return A4GL_get_gui_char ();
    }

  A4GL_debug ("Reading from keyboard on window %p", window_ptr);
  A4GL_set_abort (0);

  while (1)
    {
      halfdelay (1);
      //a = wgetch (window_ptr);
      a = getch ();

      if (a == KEY_MOUSE)
	{
	  A4GL_debug ("Mouse event...");
	}

      if (abort_pressed)
	{
	  A4GL_debug ("MJAC Aborted!");
	  a = KEY_CANCEL;
	  break;
	}

      if (a != -1)
	{
	  A4GL_debug ("MJAC Key Pressed %d", a);
	  break;
	}

    }
  cbreak ();
  A4GL_debug ("Got char from keyboard : %d", a);
  return a;
}



/**
 *
 * @todo Describe function
 */
int
A4GL_decode_line (int l)
{
  if (l > 0)
    {
      if (A4GL_get_curr_border ())
	{
	  A4GL_debug ("Decoded line %d to %d (because of border)", l, l - 1);
	  return l - 1;
	}
      else
	{
	  A4GL_debug ("Decoded line %d to %d", l, l);
	  return l;
	}
    }
/* -1 = last */
/* -2 = last -1 */
  if (A4GL_get_curr_border ())
    {
      if (l < 0)
	{
	  A4GL_debug ("Decoded line %d to %d  %d ", l, A4GL_get_curr_height ());
	  return A4GL_get_curr_height () + l;
	}

    }
  else
    {
      if (l < 0)
	{
	  A4GL_debug ("Decoded line %d to %d  %d ", l, A4GL_get_curr_height ());
	  return A4GL_get_curr_height () + l + 1;
	}

    }
  return 0;
}

/**
 *
 * @todo Describe function
 */
char *
A4GL_glob_window (int x, int y, int w, int h, int border)
{
  static char winname[20];
  int f;
#ifdef DEBUG
  {
    A4GL_debug ("In glob_window");
  }
#endif
  A4GL_chkwin ();
  memset (winname, 'A', 19);
  f = 1;
  winname[19] = 0;

#ifdef DEBUG
  {
    A4GL_debug ("Finding free window ... starting with %s", winname);
  }
#endif

  while (A4GL_has_pointer (winname, WINCODE))
    {
      A4GL_inc_winname (winname);
    }
  A4GL_create_blank_window (winname, x, y + 1, w, h, border);
#ifdef DEBUG
  {				/*debug("Adding window @ %d %s",a,winname); */
  }
#endif
  /*A4GL_add_pointer (winname, WINCODE, win); */
  return winname;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_inc_winname (char *b)
{
  int a;
  for (a = 0; a < 10; a++)
    {
      b[a]++;
      if (b[a] > 'Z')
	b[a] = 'A';
      else
	break;
    }
}


/**
 *
 * @todo Describe function
 */
int
A4GL_getmenu_line (void)
{
#ifdef DEBUG
    A4GL_debug ("In menu line... currwinno=%d ", currwinno);
    A4GL_debug ("name=%s ", windows[currwinno].name);
#endif

  if (strcmp (windows[currwinno].name, "screen") == 0)
    {
      /* use screen default */
      return A4GL_decode_line (std_dbscr.menu_line);
    }

  A4GL_debug ("form=%p", windows[currwinno].form);
  A4GL_debug ("menu line=%d (%s)", windows[currwinno].winattr.menu_line,
	 windows[currwinno].name);
  return A4GL_decode_line (windows[currwinno].winattr.menu_line);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_display_internal (int x, int y, char *s, int a, int clr_line)
{
  if (x == -1 && y == -1)
    {
      A4GL_debug ("Line mode display");
      if (A4GL_isscrmode ())
	{
	  A4GL_mja_endwin ();
	}
      printf ("%s\n", s);
      fflush (stdout);
    }
  else
    {
      int b;
      int line_length;
      /* WINDOW *win; */

      A4GL_chkwin ();
      b = A4GL_xwattr_get (currwin);
      a4glattr_wattrset (A4GL_window_on_top (), a);
      A4GL_gui_print (a, s);
      A4GL_mja_gotoxy (x, y);
      A4GL_tui_print ("%s", s);
      if (clr_line)
	{
	  A4GL_debug ("Clearing line...");
	  wclrtoeol (A4GL_window_on_top ());
	}

      A4GL_debug (">> printed %s", s);

      /* b was got via curses - so we can use the curses version */
      wattrset (A4GL_window_on_top (), b);
      A4GL_mja_wrefresh (A4GL_window_on_top ());
      A4GL_mja_refresh ();
    }
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_display_error (int a, int wait)
{
  char *s;
  A4GL_debug ("Cr string");
  s = A4GL_char_pop ();
  A4GL_debug ("ZZ2 going to print an error : %s", s);
  A4GL_trim (s);
  A4GL_debug ("trimmed -> %s", s);
  if (A4GL_isgui ())
    A4GL_gui_error (s, A4GL_geterror_line ());
  else
    {
      if (wait)
 A4GL_error_box (s);
      else
 A4GL_error_nobox (s);
    }
  A4GL_debug ("error_box done");
  acl_free (s);
  a4gl_status = 0;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_mja_endwin (void)
{
  if (A4GL_isscrmode ())
    {
      A4GL_set_scrmode ('L');
      printf ("\n");
      fflush (stdout);
      endwin ();
    }
}

/**
 *
 * @todo Describe function
 */
int
A4GL_chkwin (void)
{
  if (A4GL_env_option_set ("NOCURSES"))
    {				/* FIXME: this is now A4GL_UI=CONSOLE */
      A4GL_exitwith ("NOCURSES Mode has been specified - operation not permitted");
      exit (0);
      return 0;
    }

  if (A4GL_islinemode ())
    {
      A4GL_init_curses_stuff ();
      A4GL_set_scrmode ('S');
      A4GL_mja_refresh ();
    }
  return 1;
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void *
A4GL_cr_window (char *s,
	   int iswindow,
	   int form_line,
	   int error_line,
	   int prompt_line,
	   int menu_line,
	   int border, int comment_line, int message_line, int attrib)
{
  WINDOW *win;
  int x, y, w, h;
  w = A4GL_pop_int ();
  h = A4GL_pop_int ();
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
  A4GL_chkwin();
  if (A4GL_has_pointer (s, WINCODE))
    {
#ifdef DEBUG
      {
 A4GL_debug ("Window already exists");
      }
#endif
      A4GL_set_errm (s);
      A4GL_exitwith ("Window already exists (%s)");
      return 0;
    }
  win = A4GL_create_window (s, x, y, w, h,
		       iswindow,
		       form_line,
		       error_line,
		       prompt_line,
		       menu_line, border, comment_line, message_line, attrib);

  return win;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_cr_window_form (char *name,
		int iswindow,
		int form_line,
		int error_line,
		int prompt_line,
		int menu_line,
		int border, int comment_line, int message_line, int attrib)
{
  int x, y, w, h;
  char *s;
  char buff[132];
  struct s_form_dets *form;
  WINDOW *win;
  A4GL_debug ("cr_window_form(%s,%d,%d,%d,%d,%d,%d,%d,%d,%d)\n",
	 name, iswindow, form_line, error_line, prompt_line, menu_line,
	 border, comment_line, message_line, attrib);

  A4GL_chkwin();
  if (form_line == 0xff)
    {
	A4GL_debug("Defaulting form_line from std_dbscr... %d",std_dbscr.form_line);
      form_line = std_dbscr.form_line;
    }
  if (menu_line == 0xff)
    {
      menu_line = std_dbscr.menu_line;
    }
  if (comment_line == 0xff)
    {
      comment_line = std_dbscr.comment_line;
    }
  if (error_line == 0xff)
    {
      error_line = std_dbscr.error_line;
    }
  if (prompt_line == 0xff)
    {
      prompt_line = std_dbscr.prompt_line;
    }

  s = A4GL_char_pop ();
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
  strcpy (buff, s);
  A4GL_trim (buff);
  //strcat (buff, acl_getenv ("A4GL_FRM_BASE_EXT"));

  A4GL_debug ("reading file %s - name=%s", buff, name);
  a4gl_status = 0;
  form = A4GL_read_form (buff, name);
  if (a4gl_status != 0)
    return 0;

  if (form == 0)
    {
      A4GL_exitwith ("Unable to create form");
      return 0;
    }
  else
    {
      A4GL_debug ("Created form %p", form);
    }

  scale_form (form->form, &w, &h);

  w = form->fileform->maxcol;
  h = form->fileform->maxline;
  A4GL_debug ("Scaling on %s gives %d %d border = %d", buff, w, h, border);

  /* ignore error line for now */

  form->form_details.comment_line = comment_line;
  form->form_details.menu_line = menu_line;
  A4GL_debug ("Setting prompt line to ", prompt_line);
  form->form_details.prompt_line = prompt_line;
  form->form_details.form_line = form_line;
  form->form_details.message_line = message_line;
  A4GL_debug ("border=%d\n", border);
  form->form_details.border = border;
  form->form_details.colour = attrib;
  A4GL_add_pointer (name, S_FORMDETSCODE, form);

  win = A4GL_display_form_new_win (name, form, x, y);
  if (win)
    {
      A4GL_add_pointer (name, WINCODE, win);
      A4GL_mja_wrefresh (currwin);
    }
  else
    {
      A4GL_exitwith ("Error displaying form in window");
    }
  acl_free (s);
  return 0;
}






/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_open_form (char *name)
{
  int w, h;
  char *s;
  char buff[256];
  struct s_form_dets *form;
  s = A4GL_char_pop ();
  strncpy (buff, s, 256);
  buff[255] = 0;
  A4GL_trim (buff);
  //strcat (buff, acl_getenv ("A4GL_FRM_BASE_EXT"));
  A4GL_debug ("reading file %s ?", buff);
  A4GLSQL_set_status (0, 0);

  form = A4GL_read_form (buff, name);
  A4GL_debug ("Read form returns %d status = %d\n", form);
  if (a4gl_status != 0)
    {
      A4GL_debug ("Some problem opening form...");
      acl_free (s);
      return -1;
    }
  A4GL_set_default_form (&form->form_details);
  scale_form (form->form, &h, &w);
  /*
     form->w=w; // MJA 2707
     form->h=h; // MJA 2707
   */
  A4GL_debug ("adding pointer F to %s", name);
  A4GL_add_pointer (name, S_FORMDETSCODE, form);
  A4GL_debug ("Freeing s");
  acl_free (s);
  A4GL_debug ("Freed - form has been opened");
  return 0;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_close_form (char *formname)
{
  A4GL_debug ("FIXME : A4GL_close_form not implemented");
}


/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_disp_form (char *name, int attr)
{
  struct s_form_dets *f;
  WINDOW *w;
  char buff[80];

  A4GL_debug ("attr=%d\n", attr);
  attr = A4GL_decode_aubit_attr (attr, 'w');

  A4GL_debug ("attr=%x\n", attr);

  A4GL_debug ("Disp_form_tui");
  f = (struct s_form_dets *) A4GL_find_pointer_val (name, S_FORMDETSCODE);
  A4GL_debug ("Got pointer to form as %p", f);
  if (f == 0)
    {
      A4GL_exitwith ("The form has not been opened");
      return 0;
    }
  w = A4GL_display_form (f);
  if (w == 0)
    {
#ifdef DEBUG
/* {DEBUG} */
      {
 A4GL_debug ("Error display window");
      }
#endif
      return 0;
    }

  windows[currwinno].form = f;
  sprintf (buff, "currwinno=%d f=%p", currwinno, f);
  /*error_box(buff); */
  A4GL_mja_wrefresh (currwin);
  A4GL_gui_dispform (name, A4GL_getform_line ());
  A4GL_debug ("Diplay form");
  A4GL_mja_refresh ();
  return 0;
}




/**
 *
 * @todo Describe function
 */
int
A4GL_set_window (int a)
{
  A4GL_current_window (windows[a].name);
/*error_box(windows[a].name); */
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_refresh_menu_window (char *name, int top)
{
  PANEL *ptr;
  int rc;
  char nm[40];
  char s;

  A4GL_debug ("In A4GL_refresh_menu_window %s", name);
  print_panel_stack ();
  ptr = A4GL_find_pointer (name, MNPARCODE);
  A4GL_find_pointer_ptr (nm, &s, ptr);

  if (nm)
    {
      A4GL_debug ("Making menus parent window current %s", nm);
      ptr = A4GL_find_pointer (nm, PANCODE);
      A4GL_debug ("Parent window=%p", ptr);
      rc = top_panel (ptr);

      A4GL_debug ("Rc=%d", rc);
    }
  else
    {
      A4GL_debug ("Not found parent window - %p", ptr);
    }

  A4GL_debug ("Setting menu (%s) panel to top", name);
  ptr = A4GL_find_pointer (name, PANCODE);
  A4GL_debug ("refresh menu with pointer to %p", ptr);
  if (top)
    rc = top_panel (ptr);
  else
    rc = bottom_panel (ptr);
  A4GL_debug ("Rc=%d", rc);
  A4GL_debug ("Topped");
  update_panels ();
  doupdate ();
  A4GL_zrefresh ();
  print_panel_stack ();
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_subwin_gotoxy (WINDOW * win, int x, int y)
{
  int a;
  a = wmove (win, y - 1, x - 1);
  if (a == ERR)
    {
      A4GL_debug ("Failed to move cursor!");
    }
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_subwin_print (WINDOW * win, char *fmt, ...)
{
  va_list args;
  A4GL_chkwin ();
  A4GL_debug ("subwin_print '%s' on window %p", fmt, win);
  va_start (args, fmt);
  A4GL_mja_vwprintw (win, fmt, &args);	/*  MJAMJAMJA */
  A4GL_mja_wrefresh (win);
  return 0;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_subwin_printxy (WINDOW * win, int x, int y, char *fmt, ...)
{
  va_list args;
  A4GL_chkwin ();
  va_start (args, fmt);
  wmove (win, y - 1, x - 1);
  A4GL_mja_vwprintw (win, fmt, &args);
  A4GL_mja_wrefresh (win);
  return 0;
}



/**
 *
 * @todo Describe function
 */
int
A4GL_subwin_setcolor (WINDOW * win, int typ)
{
  WINDOW *currwin;
  long attr;
  currwin = win;
  attr = getbkgd (currwin);
  A4GL_debug ("Window background = %x", attr);
  if (attr == 0)
    {
      attr = A_NORMAL & ' ';
    }
  A4GL_debug ("Subwin - setcolor");
  if (has_colors ())
    {
      A4GL_debug ("XX4 REVERSE");
      A4GL_debug ("Color display - %d current attrib is reverse %d", typ,
	     attr & A_REVERSE);
      switch (typ)
	{
	case NORMAL_TEXT:
	case NORMAL_MENU:
	  wattrset (currwin, attr);

	  break;
	case INVERT_MENU:
	  A4GL_debug ("Invert...");
	  if (attr & A_REVERSE)
	    {
	      A4GL_debug ("XX4 REVERSE");
	      if (((attr) & (A4GL_colour_code (COLOR_WHITE))) ==
		  A4GL_colour_code (COLOR_WHITE))
		{
		  A4GL_debug ("Use red %x", A4GL_colour_code (COLOR_RED));
		  A4GL_debug ("XX4 REVERSE");
		  wattrset (currwin, A_REVERSE | A4GL_colour_code (COLOR_RED));
		}
	      else
		{
		  A4GL_debug ("Ops - try green instead of red...\n");
		  A4GL_debug ("XX4 REVERSE");
		  wattrset (currwin, A_REVERSE + A4GL_colour_code (COLOR_WHITE));
		}
	    }
	  else
	    {
	      A4GL_debug ("Off for invert");
	      A4GL_debug ("XX4 REVERSE");
	      wattron (currwin, A_REVERSE);
	    }

	  break;
	case TITLE_COL:
	  wattrset (currwin, A4GL_colour_code (COLOR_WHITE));
	  break;
	case EDIT_FIELD:
	  wattrset (currwin, A4GL_colour_code (COLOR_WHITE));
	  break;
	}
      currattr = typ;
    }
  else
    {
      switch (typ)
	{
	case ERROR_COL:
	  A4GL_debug ("XX4 REVERSE");
	  wattron (currwin, A_REVERSE);
	  break;
	case MESSAGE:
	  A4GL_debug ("XX4 REVERSE");
	  wattroff (currwin, A_REVERSE);
	  break;
	case NORMAL_MENU:
	  A4GL_debug ("XX4 REVERSE");
	  wattroff (currwin, A_REVERSE);
	  break;
	case INVERT_MENU:
	  A4GL_debug ("XX4 REVERSE");
	  wattron (currwin, A_REVERSE);
	  break;
	case TITLE_COL:
	  A4GL_debug ("XX4 REVERSE");
	  wattron (currwin, A_REVERSE);
	  break;
	case EDIT_FIELD:
	  wattron (currwin, A_REVERSE);
	  break;
	case NORMAL_TEXT:
	  wattroff (currwin, A_REVERSE);
	  break;
	}
    }
  return 0;
}




/**
 *
 * @todo Describe function
 */
int
A4GL_mja_vwprintw (WINDOW * win, char *fmt, va_list * args)
{
  char buff[256];
  vsprintf (buff, fmt, *args);
  A4GL_debug ("mja_vwprintw..> '%s' attribute %x", buff, A4GL_xwattr_get (win));
  if (A4GL_xwattr_get (win) == 0x20)
    {
      wattrset (win, 0);
    }
  else
    {
      int a;
      a = A4GL_xwattr_get (win);
      a = a - (a & 0xff);
      wattrset (win, a);
    }
  A4GL_debug ("Attribute : %x on win %p\n", A4GL_xwattr_get (win), win);
  wprintw (win, "%s", buff);
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_init_colour_pairs (void)
{

#ifndef WIN32
  A4GL_debug ("Non WIN32 color scheme");
  init_pair (1, COLOR_BLACK, COLOR_BLACK);
  init_pair (2, COLOR_RED, COLOR_BLACK);
  init_pair (3, COLOR_GREEN, COLOR_BLACK);
  init_pair (4, COLOR_YELLOW, COLOR_BLACK);
  init_pair (5, COLOR_BLUE, COLOR_BLACK);
  init_pair (6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair (7, COLOR_CYAN, COLOR_BLACK);
  init_pair (8, COLOR_WHITE, COLOR_BLACK);

#else

  A4GL_debug ("WIN32 color scheme");
  init_pair (1, COLOR_BLACK, COLOR_BLACK);
  init_pair (2, COLOR_BLUE, COLOR_BLACK);
  init_pair (3, COLOR_GREEN, COLOR_BLACK);
  init_pair (4, COLOR_CYAN, COLOR_BLACK);
  init_pair (5, COLOR_RED, COLOR_BLACK);
  init_pair (6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair (7, COLOR_YELLOW, COLOR_BLACK);
  init_pair (8, COLOR_WHITE, COLOR_BLACK);

#endif
  return 0;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_mja_wrefresh (WINDOW * w)
{
  if (A4GL_screen_mode (-1) && w)
    {
      update_panels ();
      doupdate ();
      wrefresh (w);
    }
  A4GL_gui_wrefresh (w);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_mja_refresh (void)
{
  if (A4GL_screen_mode (-1))
    {
      update_panels ();
      doupdate ();
      refresh ();
    }
  A4GL_gui_refresh ();
}

/**
 *
 * @todo Describe function
 */
void
A4GL_change_currwin (WINDOW * a, char *s)
{
#ifdef DEBUG
  {
    A4GL_debug ("Changing currwin to %p (%s)", a, s);
  }
#endif
  A4GL_gui_currwin ((long) a);
  currwin = a;

}

/**
 *
 * @todo Describe function
 */
void
A4GL_change_currwinno (int a, char *s)
{
#ifdef DEBUG
  {
    A4GL_debug ("Changing currwinno to %d (%s)", a, s);
  }
#endif
  currwinno = a;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_top_win (PANEL * p)
{
  int a;
  PANEL *z;
  a = A4GL_find_win (0);		/* current window top window */

  if (a == -1)
    return 1;

  /* a is now the top window */

  z = windows[a].pan;
  A4GL_change_currwin (panel_window (z), "Marker 3");
  A4GL_change_currwinno (a, "Marker 4");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_find_win (PANEL * p)
{
  int a;
  if (p == 0)
    return A4GL_find_win (panel_below (0));
#ifdef DEBUG
  {
    A4GL_debug ("Finding window %p", p);
  }
#endif

  for (a = 0; a < MAXWIN; a++)
    {
#ifdef DEBUG
      {
 A4GL_debug ("Checking windows   : %p %p %p", panel_window (windows[a].pan),
	       windows[a].pan, p);
      }
#endif

      if ((PANEL *) panel_window (windows[a].pan) == p
	  || (PANEL *) windows[a].pan == p)
	{
	  if (toupper (windows[a].name[0]) == windows[a].name[0])
	    {
#ifdef DEBUG
	      {
	 A4GL_debug ("window is a menu - finding parent of %s",
		       windows[a].name);
	      }
#endif
	      return A4GL_find_win (A4GL_find_pointer (windows[a].name, MNPARCODE));
	    }
	  return a;
	}
    }
  A4GL_exitwith ("Panel not found....");
  return -1;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
LIBEXPORT void
A4GL_hide_window (char *winname)
{
  PANEL *p;
  int a;
  p = A4GL_find_pointer (winname, PANCODE);
#ifdef DEBUG
  {
    A4GL_debug ("hiding window %s %p", winname, p);
  }
#endif
  if (p)
    {
      a = hide_panel (p);
#ifdef DEBUG
      {
 A4GL_debug ("a=%d", a);
      }
#endif
    }
  A4GL_do_update_panels ();
  A4GL_top_win (0);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
LIBEXPORT void
A4GL_show_window (char *winname)
{
  PANEL *p;
  p = A4GL_find_pointer (winname, PANCODE);
#ifdef DEBUG
  {
    A4GL_debug ("showing window %s %p", winname, p);
  }
#endif
  if (p)
    show_panel (p);
  A4GL_do_update_panels ();
  A4GL_top_win (0);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_do_update_panels (void)
{
  if (A4GL_screen_mode (-1))
    {
      update_panels ();
      doupdate ();
    }
}

/**
 *
 * @todo Describe function
 */
int
A4GL_getform_line (void)
{
  if (strcmp (windows[currwinno].name, "screen") == 0)
    {
      return A4GL_decode_line (std_dbscr.form_line);
    }
#ifdef DEBUG
  {
    A4GL_debug ("Use window value of : %d", windows[currwinno].winattr.form_line);
  }
#endif
  return A4GL_decode_line (windows[currwinno].winattr.form_line);
}

/**
 *
 * @todo Describe function
 */
int
A4GL_getcomment_line (void)
{
  if (windows[currwinno].form == 0)
    {				/* use screen default */
      return A4GL_decode_line (std_dbscr.comment_line);
    }
  return A4GL_decode_line (windows[currwinno].form->form_details.comment_line);
}

/**
 *
 * @todo Describe function
 */
int
A4GL_geterror_line (void)
{
  if (windows[currwinno].form == 0)
    {				/* use screen default */
      A4GL_debug ("Get error line - no form\n");
      return A4GL_decode_line (std_dbscr.error_line);
    }
  A4GL_debug ("Get error line - form : %d",
	 windows[currwinno].form->form_details.error_line);
  if (currwinno == 0)
    {
      return A4GL_decode_line (std_dbscr.error_line);
    }
  return A4GL_decode_line (windows[currwinno].form->form_details.error_line);
}


/**
 *
 * @todo Describe function
 */
int
A4GL_getmessage_line (void)
{
  A4GL_debug ("getmessage_line - %d", windows[currwinno].winattr.message_line);
  if (windows[currwinno].form == 0)
    {				/* use screen default */
      A4GL_debug ("getmessage_line - std_dbscr...");
      return A4GL_decode_line (std_dbscr.message_line);
    }
  A4GL_debug ("getmessage_line - window...");
  return windows[currwinno].winattr.message_line;
  //return A4GL_decode_line (windows[currwinno].form->form_details.message_line);
}


/**
 *
 * @todo Describe function
 */
int
A4GL_getprompt_line (void)
{
  A4GL_debug (">> %p ", windows[currwinno].name);
  A4GL_debug (">> %s ", windows[currwinno].name);
  if (strcmp (windows[currwinno].name, "screen") == 0)
    {
      A4GL_debug ("...std_dbscr");
      return A4GL_decode_line (std_dbscr.prompt_line);
    }
  A4GL_debug ("...windows");
  return A4GL_decode_line (windows[currwinno].winattr.prompt_line);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
LIBEXPORT int
A4GL_movewin (char *winname, int absol)
{
  PANEL *p;
  int x, y;
  int r = 0;
  int nx, ny;
  struct s_windows *w;
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
#ifdef DEBUG
  {
    A4GL_debug ("x=%d y=%d winname=%s", x, y, winname);
  }
#endif
  w = A4GL_find_pointer (winname, S_WINDOWSCODE);
#ifdef DEBUG
  {
    A4GL_debug ("w=%p", w);
  }
#endif
  if (w)
    {
      p = w->pan;
      if (w->winattr.border)
	{
	  x--;
	  y--;
	}

      if (absol)
	{
#ifdef DEBUG
	  {
	    A4GL_debug ("Moving absolute to %d %d", y - 1, x - 1);
	  }
#endif
	  r = move_panel (p, y - 1, x - 1);
	  nx = x;
	  ny = y;
	}
      else
	{
#ifdef DEBUG
	  {
	    A4GL_debug ("Moving relative by %d %d", y, x);
	  }
#endif
	  r = move_panel (p, w->y + y - 1, w->x + x - 1);
	  nx = w->x + x + 1;
	  ny = w->y + y + 1;
	}
      A4GL_do_update_panels ();
    }
  else
    {
      A4GL_exitwith ("Window to move was not found");
      return 0;
    }
#ifdef DEBUG
  {
    A4GL_debug ("r=%d", r);
  }
#endif

  if (r != 0)
    {
      A4GL_exitwith ("Couldnt move window");
      return 0;
    }

#ifdef DEBUG
  {
    A4GL_debug ("Old %d %d  new %d %d", x, y, nx, ny);
  }
#endif

  w->x = nx;
  w->y = ny;
  return 0;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_find_ptr_debug (void *ptr)
{
  return 0;
}


#ifdef MOVED_TO_KEYS_C

/**
 *
 * @todo Describe function
 */
void
A4GL_init_stddbscr (void)
{
A4GL_debug("init_stddbscr - form_line");
  std_dbscr.mode = 0;
  std_dbscr.colour = 0;
  std_dbscr.border = 0;
  std_dbscr.inpattr = 0;
  std_dbscr.dispattr = 0;
  std_dbscr.nextkey = KEY_F (4);
  std_dbscr.prevkey = KEY_F (3);
  std_dbscr.acckey = 27;
  std_dbscr.helpkey = 22;
  std_dbscr.input_wrapmode = 0;
  std_dbscr.comment_line = -2;
  std_dbscr.form_line = 3;
  std_dbscr.menu_line = 1;
  std_dbscr.message_line = 2;
  std_dbscr.prompt_line = 1;
  std_dbscr.fcnt = 0;
  std_dbscr.insmode = 0;
  std_dbscr.error_line = -1;
  std_dbscr.inskey = KEY_F (1);
  std_dbscr.delkey = KEY_F (2);
}

#endif
/**
 *
 * @todo Describe function
 */
WINDOW *
A4GL_get_currwin (void)
{
  return currwin;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_iscurrborder (void)
{
  A4GL_debug ("currwinno=%d", currwinno);
  A4GL_debug ("Winattr=%p", windows[currwinno].winattr);
  A4GL_debug ("border=%p", windows[currwinno].winattr.border);
  return windows[currwinno].winattr.border;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_attr_win (char s, int wattr)
{
  A4GL_set_bkg (currwin, wattr);
}


/**
 *
 * @todo Describe function
 */
void
print_panel_stack (void)
{
  PANEL *ptr;
  A4GL_debug ("Printing panel stack");
  ptr = panel_below (0);
  while (ptr != 0)
    {
      A4GL_debug ("Panel : %p (%s)", ptr, panel_userptr (ptr));
      ptr = panel_below (ptr);
    }
}



/**
 *
 * @todo Describe function
 */
char *
A4GL_windowname_on_top (void)
{
  PANEL *ptr;
  char *s;
  ptr = panel_below (0);
  s = (char *) panel_userptr (ptr);	/* get name of panel */
  return s;
}


/**
 *
 * @todo Describe function
 */
WINDOW *
A4GL_window_on_top (void)
{
  PANEL *ptr;
  const char *s;
  void *winptr;
  ptr = panel_below (0);
  s = panel_userptr (ptr);	/* get name of panel */
  winptr = A4GL_find_pointer (s, WINCODE);
  return winptr;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_invert_color (int a)
{
  return 7 - a;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_xwattr_get (WINDOW * w)
{
  return getattrs (w);
}


/**
 *
 * @todo Describe function
 */
int
A4GL_screen_width (void)
{
  if (scr_width == -1)
    {

      getmaxyx (stdscr, scr_height, scr_width);
      if (atoi (acl_getenv ("COLUMNS")))
	{
	  scr_width = atoi (acl_getenv ("COLUMNS"));
	  scr_height = atoi (acl_getenv ("LINES"));
	}
    }
  A4GL_debug ("screen_width returning %d", scr_width);
  return scr_width;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_screen_height (void)
{
  if (scr_width == -1)
    {
      getmaxyx (stdscr, scr_height, scr_width);
      if (atoi (acl_getenv ("COLUMNS")))
	{
	  scr_width = atoi (acl_getenv ("COLUMNS"));
	  scr_height = atoi (acl_getenv ("LINES"));
	}

    }
  A4GL_debug ("screen_height returning %d", scr_height);
  return scr_height;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_sleep_i (void)
{
  int a;
  a = A4GL_pop_int ();
  sleep (a);
}




/* =============================== EOF =============================== */
