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
# $Id: newpanels.c,v 1.95 2004-09-27 17:13:23 mikeaubury Exp $
#*/
static char *module_id="$Id: newpanels.c,v 1.95 2004-09-27 17:13:23 mikeaubury Exp $";

/**
 * @file
 * Pannels implementation, like windows, prompts lines, etc
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
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



WINDOW * A4GL_window_on_top_ign_menu (void);
void A4GL_make_window_with_this_form_current(void *form);
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
extern int have_default_colors;
WINDOW *currwin;
int scr_width = -1;
int scr_height = -1;
int currwinno = -1;
int currattr = 0;
int
A4GL_decode_line_scr (int l);
PANEL *get_below_panel(PANEL *p) ;


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




static WINDOW *
A4GL_create_window (char *name, int x, int y, int w, int h,
               int iswindow,
               int form_line,
               int error_line,
               int prompt_line,
               int menu_line,
               int border, int comment_line, int message_line, int attrib);
static WINDOW *A4GL_display_form (struct s_form_dets *f,int attr);
static WINDOW *A4GL_display_form_new_win (char *name, struct s_form_dets *f, int x,
                              int y,int attr);
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/
/** @todo Take this prototypes of from here */

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
    //case MNWINCODE:
      //return "'Menu Window'";
    //case MNPARCODE:
      //return "'Menu Parent'";
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
  UILIB_A4GL_current_window ("screen");
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
  return A4GL_create_window (name, x, y, w, h, 1, 
		0xff, 0xff, 0xff, 0xff, border, 0xff, 0xff,
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
  A4GL_debug ("Creating window %s (%d %d %d %d) border=%d attrib=0x%x - error line=%d", name, x, y,
	 w, h, border, attrib,error_line);
#endif

 if (attrib!=0xffff) { // Strangely - informix resets the 'options' when you open a new window
		A4GL_set_option_value('d',0);
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
	if (A4GL_screen_width ()>255) {
		A4GL_exitwith("Screen too wide - maximum 255 characters");
		A4GL_chk_err(0,"");
		//A4GL_core_dump();
		return 0;
	}

      h = A4GL_screen_height () - 1;
      w = A4GL_screen_width () - 1;
      A4GL_debug ("Creating window : h=%d w=%d y=%d x=%d", h, w, y - 1, x - 1);
      A4GL_debug ("win = newwin (%d,%d,0,0)", A4GL_screen_height (), A4GL_screen_width ());

      win = newwin (0, 0, 0, 0);
      A4GL_debug ("Calling screen height");
      A4GL_debug ("h=%d", h);
      A4GL_debug ("Calling screen width");
      A4GL_debug ("w=%d", w);
      A4GL_gui_win (name, A4GL_screen_height (), A4GL_screen_width (), 1, 1, 0, (long) win);
      A4GL_add_pointer (name, WINCODE, win);
    }
  else
    {

      if (border == 1)
	{
	  win = newwin (h + 2, w + 2, y - 2, x - 2);
	  if (a4gl_toupper (name[0]) != name[0])
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
	}

      if (border == 0)
	{
	  win = newwin (h, w, y - 1, x - 1);
	  if (a4gl_toupper (name[0]) != name[0])
	    A4GL_gui_win (name, h, w, y - 1, x - 1, 0, (long) win);
	  A4GL_add_pointer (name, WINCODE, win);
	  A4GL_debug ("Window = %p name=%s", win,name);
	}

    }

#ifdef DEBUG
  A4GL_debug ("Window created");
#endif

  if (win == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Couldnt create window h=%d w=%d y=%d x=%d", h, w, y, x);
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

   if (A4GL_isyes(acl_getenv("SIMPLE_GRAPHICS")))  {
      wborder (win, '|', '|', '-', '-', '+','+', '+', '+');
   } else {
      wborder (win, 0, 0, 0, 0, 0, 0, 0, 0);
   }
      //wbkgdset (win, 0);
      A4GL_mja_wrefresh (win);
    }
  A4GL_debug("new_panel %p",win);
  pan = new_panel (win);
  A4GL_debug("New panel %p for window %p name '%s'  ",pan,win,name);
  set_panel_userptr (pan, strdup (name));
  A4GL_add_pointer (name, PANCODE, pan);

#ifdef DEBUG
  {
    A4GL_debug ("Panel created at %p for window %p", pan, win);
  }
#endif

  if (pan == 0)
    {
      A4GL_error_box ("Couldnt create panel",0);
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
	  windows[a].winattr.error_line = error_line;
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
  if (a4gl_toupper (name[0]) != name[0])
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

	A4GL_assertion(1, "Fake window - thought I'd got rid of these");
    }
  return win;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
 UILIB_A4GL_clr_window (char *win_name)
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
   if (A4GL_isyes(acl_getenv("SIMPLE_GRAPHICS")))  {
      wborder (w, '|', '|', '-', '-', '+','+', '+', '+');
   } else {
      wborder (w, 0, 0, 0, 0, 0, 0, 0, 0);
   }
    }
  UILIB_A4GL_zrefresh ();
  return;

  for (a = 0; a < MAXWIN; a++)
    {
      if (strcmp (windows[a].name, win_name) == 0)
	{
	  wclear (panel_window (windows[a].pan));
	  break;
	}
    }
  UILIB_A4GL_zrefresh ();
}



/**
 * 4GL CALL
 * @todo Describe function
 */
void
 UILIB_A4GL_remove_window (char *win_name)
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
	 A4GL_debug("delwin : %p",win);
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
  UILIB_A4GL_zrefresh ();
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
  UILIB_A4GL_zrefresh ();
  return 0;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
 UILIB_A4GL_current_window (char *win_name)
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
  UILIB_A4GL_zrefresh ();
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
 UILIB_A4GL_zrefresh (void)
{
  A4GL_gui_refresh ();
  if (A4GL_screen_mode (-1))
    {
      A4GL_chkwin ();

      //clearok(curscr,TRUE);

      update_panels ();
      doupdate ();

      /* A4GL_mja_wrefresh (currwin); */
      //A4GL_mja_refresh ();  // REMOVED MJA 12/12/2003
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

  if (A4GL_isyes(acl_getenv("REFRESH_AFTER_MOVE"))) {
  	A4GL_mja_refresh ();
  }
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
A4GL_debug("addsr : %s",buff);
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
A4GL_debug("delwin %p %p",s,w);
}
*/

/**
 *
 * @todo Describe function
 */
WINDOW *
A4GL_display_form (struct s_form_dets *f,int attrib)
{
  int rows, cols;
  char buff[80];
  int a;

  //int informix_behaviour = 1;
  WINDOW *w;
  WINDOW *drwin;
  /*  FIELD **p; */

  int fl;
  A4GL_chkwin ();
  A4GL_debug ("In display_form");
  w = currwin;

  sprintf(buff,"%p",f);
  A4GL_add_pointer (buff, ATTRIBUTE, (void *) attrib);

  if (w == 0)
    {
      A4GL_error_box ("NO WINDOW",0);
    }
  A4GL_debug ("scale form %p", f->form);

  fl = A4GL_getform_line ();
  for (a=fl;a<=A4GL_get_curr_height();a++) {
	A4GL_display_internal (1, a, " ", 0, 1);
  }
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
	A4GL_debug("%d - %d > %d + 1",rows,windows[currwinno].winattr.border , windows[currwinno].h );
      A4GL_exitwith ("Window is too small to display this form (too high)");
      return 0;
    }
  if (cols - windows[currwinno].winattr.border > windows[currwinno].w + 1)
    {
      A4GL_exitwith ("Window is too small to display this form (too wide)");
      return 0;
    }


  /* fix - not sure whats going on here bit form_details.border is set to 1 for the screen! */



// I can't seem to replicate this!
  //if (informix_behaviour)
    //{
	//if (currwin!= A4GL_find_pointer ("screen", WINCODE)) {
      		//rows = windows[currwinno].h - fl;
      		//cols = windows[currwinno].w;
	//}
    //}

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
      drwin = derwin (w, rows, cols, fl , 1);
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
   if (A4GL_isyes(acl_getenv("SIMPLE_GRAPHICS")))  {
      wborder (w, '|', '|', '-', '-', '+','+', '+', '+');
   } else {
      wborder (w, 0, 0, 0, 0, 0, 0, 0, 0);
   }
    }

  
  A4GL_debug ("start the form");
  A4GL_start_form (f);

  if ((attrib & 0xff) == 0 || (attrib & 0xff) == 0xff)
    {
      attrib = attrib + ' ';
      A4GL_debug ("Set pad char to space");
    }
  A4GL_debug ("Setting attribute for form to 0x%x \n", attrib);


  A4GL_set_bkg (drwin, attrib);



  A4GL_mja_wrefresh (w);
  A4GL_clr_form(0);
  A4GL_zrefresh();
  A4GL_debug ("And return");
  return w;
}


/**
 *
 * @todo Describe function
 */
WINDOW *
A4GL_display_form_new_win (char *name, struct s_form_dets * f, int x, int y,int attr)
{
  WINDOW *w;
  int nlines;
  int rows, cols;
  char buff[80];
  A4GL_chkwin ();
  A4GL_debug ("display_form_new_win - name=%s got errorline as %d\n", name,f->form_details.error_line);
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
  if (f->form_details.form_line!=0xff) {
  	nlines = rows + f->form_details.form_line - 1;
  } else {
  	nlines = rows + std_dbscr.form_line - 1;
  }
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
  if (A4GL_display_form (f,attr))
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
 UILIB_A4GL_get_curr_form (int warn_if_no_form)
{
  char buff[80];
  A4GL_chkwin();

  sprintf (buff, "currwinno=%d", currwinno);

#ifdef DEBUG
  {
    A4GL_debug ("currwinno=%d", currwinno);
  }
#endif

  /*error_box(buff); */
  if (windows[currwinno].form == 0)
    {
	if (warn_if_no_form)  {
      		A4GL_exitwith ("No current form");
	}
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
 UILIB_A4GL_get_curr_height (void)
{
	A4GL_debug("get_curr_height : %d = %d",currwinno,windows[currwinno].h);
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
 UILIB_A4GL_get_curr_width (void)
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
 UILIB_A4GL_get_currwin_name (void)
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
  A4GL_clr_error_nobox("A4GL_getch_win");
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
  //A4GL_reset_processed_onkey();
  A4GL_debug ("Reading from keyboard on window %p", window_ptr);
  A4GL_set_abort (0);
  a=A4GL_readkey();
  if (a!=0) {
		A4GL_debug("Read %d from keyfile",a);
		return a;
	}

  while (1)
    {
      halfdelay (1);
      //a = wgetch (window_ptr);
      a = getch (); // GETCH - getch_swin

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
  a=A4GL_curses_to_aubit (a); // Convert it to an aubit key...
  A4GL_chk_for_screen_print(a);
  A4GL_logkey(a);
  A4GL_debug ("Got char from keyboard : %d F2=%d LEFT=%d 4GL for f5 = %d", a,KEY_F(2),KEY_LEFT,A4GLKEY_F (5));
  return a;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_real_getch_swin (WINDOW * window_ptr)
{
  int a;
  if (A4GL_isgui ())
    {
      return A4GL_get_gui_char ();
    }

  A4GL_debug ("Reading from keyboard on window %p", window_ptr);
  A4GL_set_abort (0);
  a=A4GL_readkey();

  if (a!=0) {
                A4GL_debug("Read %d from keyfile",a);
                return a;
        }

  while (1)
    {
      halfdelay (1);
      if (window_ptr) {
  		keypad (window_ptr, TRUE);
		a = wgetch (window_ptr);
		A4GL_debug("WGETCH");
	}

      else {
		A4GL_debug("GETCH");
		a = getch (); // GETCH1 - A4GL_real_getch_swin
	}

	A4GL_debug("getch returns %d",a);

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
  A4GL_debug ("Got char from keyboard : %d LEFT=%d", a,KEY_LEFT);
  a=A4GL_curses_to_aubit (a);
  A4GL_chk_for_screen_print(a);
  A4GL_logkey(a);
  A4GL_debug (" = %d", a);
  return a;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_decode_line_scr (int l)
{
	A4GL_debug("decode_line_scr - l=%d",l);
  if (l > 0)
    {
		while (l>A4GL_screen_height()) l--;
	  return l;
    }  
	if (l<0)
	{
	A4GL_debug("l=%d",l);
	  l=A4GL_screen_height () + l +1;
	A4GL_debug("l=%d",l);	
	return l;
	}
  return 0;
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
	  A4GL_debug ("Decoded (1) line %d to %d (because of border)", l, l - 1);
		l--;
	  while (l>A4GL_get_curr_height()) l--;
	  return l;
	}
      else
	{
	  A4GL_debug ("Decoded (2) line %d to %d", l, l);
	  while (l>A4GL_get_curr_height()) l--;
	  return l;
	}
    }


/* -1 = last */
/* -2 = last -1 */


  if (A4GL_get_curr_border ())
    {
	  A4GL_debug ("Decoded (3) line %d to %d (because of border)", l, UILIB_A4GL_get_curr_height ());
	  l=0-l;
	  l--;
	  return UILIB_A4GL_get_curr_height () - l;
    }
  else
    {
	  l=0-l;
	  l--;
	  A4GL_debug ("Decoded (4) line %d to %d ", l, UILIB_A4GL_get_curr_height ());
	  return UILIB_A4GL_get_curr_height () - l +1;
    }


  return 0;
}



int
A4GL_decode_line_ib (int l)
{
  if (l > 0)
    {
      if (A4GL_get_curr_border ())
	{
	  A4GL_debug ("Decoded (1) line %d to %d (because of border)", l, l - 1);
	  while (l>A4GL_get_curr_height()) l--;
	  return l ;
	}
      else
	{
	  while (l>A4GL_get_curr_height()) l--;
	  A4GL_debug ("Decoded (2) line %d to %d", l, l);
	  return l;
	}
    }


/* -1 = last */
/* -2 = last -1 */


  if (A4GL_get_curr_border ())
    {
	  A4GL_debug ("Decoded (3) line %d to %d (because of border)", l, UILIB_A4GL_get_curr_height ());
	  l=0-l;
	  l--;
	  return UILIB_A4GL_get_curr_height () - l+1;
    }
  else
    {
	  l=0-l;
	  l--;
	  A4GL_debug ("Decoded (4) line %d to %d ", l, UILIB_A4GL_get_curr_height ());
	  return UILIB_A4GL_get_curr_height () - l +1;
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
int a;
  if (windows[currwinno].winattr.menu_line!=0xff) {
	a=A4GL_decode_line_ib (windows[currwinno].winattr.menu_line);
	if (a<=0) return 1;
	while (a>=A4GL_get_curr_height()) a--;
	return a;
  }
  a=A4GL_decode_line_ib (std_dbscr.menu_line);
	if (a<=0) return 1;
	while (a>=A4GL_get_curr_height()) a--;
	return a;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
 UILIB_A4GL_display_internal (int x, int y, char *s, int attr, int clr_line)
{
int nattr;
WINDOW *wot;
A4GL_debug("display_internal : %d %d %s %d %d",x,y,s,attr,clr_line);
A4GL_debug("determine_attribute seems to be returning %x\n",attr);

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
	int w;
	int h;
	w=A4GL_get_curr_width();
	h=A4GL_get_curr_height();
		A4GL_debug("h=%d\n",h);
	if (currwinno==0) {
		w=A4GL_screen_width();
		h=A4GL_screen_height();
		A4GL_debug("h=%d\n",h);
	}

      /* WINDOW *win; */
        A4GL_debug("DISPLAY @ %d %d %d %d - '%s' %d",x,y,w,h,s,currwinno);

	if (y<1|| y>h) {
		A4GL_exitwith("The row or column number in DISPLAY AT exceeds the limits of your terminal");
		return;
	}
	if (x<1|| x>w) {
		A4GL_exitwith("The row or column number in DISPLAY AT exceeds the limits of your terminal");
		return;
	}


	if (strlen(s)==0&&clr_line) {
			A4GL_debug("Just got a '' on its own ?");
			return;
	}

	A4GL_debug("Check we have CURSES env");
      A4GL_chkwin ();
	A4GL_debug("Done");
	nattr=A4GL_determine_attribute(FGL_CMD_DISPLAY_CMD, attr, 0,0);
	attr=nattr;
      b = A4GL_xwattr_get (currwin);
      wot=A4GL_window_on_top_ign_menu ();
      if (wot==0) { 
		A4GL_exitwith("Internal error - window on top =0");
		return ;
      }

      a4glattr_wattrset (wot, attr);
      A4GL_gui_print (attr, s);
      A4GL_mja_gotoxy (x, y);
      A4GL_debug("X=%d Y=%d",x,y);
      A4GL_tui_print ("%s", s);

      if (clr_line)
	{
	int sl;
	char buff[1024];
	memset(buff,' ',1024);
	sl=strlen(s);
	sl=w-sl;
	if (sl>=0) buff[sl]=0;
	buff[1023]=0;
	A4GL_debug("currwin=%p",currwin);
	A4GL_debug("Spacer..");
	A4GL_debug("Buff=%s",buff);
  	waddstr (currwin, buff);
	  A4GL_debug ("Clearing line...");
	}

      A4GL_debug (">> printed %s", s);

      /* b was got via curses - so we can use the curses version */
      wattrset (wot, b);
      A4GL_mja_wrefresh (wot);
      A4GL_mja_refresh ();
    }
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
 UILIB_A4GL_display_error (int a, int wait)
{
  char *s;
  A4GL_debug ("Cr string");
  s = A4GL_char_pop ();
  A4GL_chkwin();
  A4GL_debug ("ZZ2 going to print an error : %s", s);
  A4GL_trim (s);
  A4GL_debug ("trimmed -> %s", s);
  if (A4GL_isgui ())
    A4GL_gui_error (s, A4GL_geterror_line ());
  else
    {
      if (wait)
 		A4GL_error_box (s,a);
      else
 		A4GL_error_nobox (s,a);
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
 A4GL_debug("chkwin");
  if (A4GL_env_option_set ("NOCURSES"))
    {				/* FIXME: this is now A4GL_UI=CONSOLE */
      A4GL_exitwith ("NOCURSES Mode has been specified - operation not permitted");
      exit (0);
      return 0;
    }

  if (A4GL_islinemode ())
    {

	A4GL_debug(" API_ui Was linemode..");
	//clearok(curscr,1);
      	A4GL_init_curses_stuff ();


      	A4GL_set_scrmode ('S');

	if (A4GL_isyes(acl_getenv("INIT_COL_REFRESH"))) {
		A4GL_debug("INIT_COL_REFRESH2_0 TRIGGERED...");
		if (has_colors()) {
			A4GL_debug("init_col_refresh2_0 - init_colour_pairs");
			A4GL_init_colour_pairs ();
			A4GL_zrefresh();
			if (!A4GL_isyes(acl_getenv("NO_INIT_COL_CLR"))) {
				clearok(curscr,1);
			}
			A4GL_init_colour_pairs ();
		}
	}


	A4GL_zrefresh();
      	A4GL_mja_refresh ();


    } else {
	A4GL_debug("API_ui Was screen mode..");
	}
  return 1;
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void *
 UILIB_A4GL_cr_window (char *s,
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
 UILIB_A4GL_cr_window_form (char *namet,
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
  char name[256];
  struct s_form_dets *form;
  WINDOW *win;
  A4GL_debug ("cr_window_form(%s,%d,%d,%d,%d,%d,%d,%d,%d,%d)\n",
	 name, iswindow, form_line, error_line, prompt_line, menu_line,
	 border, comment_line, message_line, attrib);
  strcpy(name,namet);
  A4GL_trim(name);
  A4GL_chkwin();

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
  form->form_details.error_line = error_line;
  form->form_details.message_line = message_line;
  A4GL_debug ("border=%d\n", border);
  form->form_details.border = border;
  form->form_details.colour = attrib;
  A4GL_add_pointer (name, S_FORMDETSCODE, form);

  win = A4GL_display_form_new_win (name, form, x, y,attrib);
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
 UILIB_A4GL_open_form (char *name)
{
  int w, h;
  char *s;
  char buff[256];
  struct s_form_dets *form;


  A4GL_chkwin();
  s = A4GL_char_pop ();
  strncpy (buff, s, 256);
  buff[255] = 0;
  A4GL_trim (buff);
  //strcat (buff, acl_getenv ("A4GL_FRM_BASE_EXT"));
  A4GL_debug ("reading file %s ?", buff);
  A4GLSQL_set_status (0, 0);

  form = A4GL_read_form (buff, name);
  A4GL_debug ("Read form returns %d status = %d\n", form,a4gl_status);
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
 UILIB_A4GL_close_form (char *formname)
{
  void *ptr;
int a;
  A4GL_chkwin();
  //A4GL_debug ("FIXME : UILIB_A4GL_close_form not implemented");

  ptr=A4GL_find_pointer(formname,S_FORMDETSCODE);

  if (ptr==0) {
	A4GL_exitwith("Form not open");
	return;
  }


  A4GL_del_pointer (formname, S_FORMDETSCODE);

  for (a = 0; a < MAXWIN; a++) {
	if (windows[a].form==ptr) {
		windows[a].form=0;
	}
  }
  acl_free(ptr);
 
}


/**
 * 4GL CALL
 * @todo Describe function
 */
int
 UILIB_A4GL_disp_form (char *name, int attr)
{
  struct s_form_dets *f;
  WINDOW *w;
  char buff[80];
  A4GL_chkwin();
  A4GL_debug ("attr=%d\n", attr);
  //attr = A4GL_decode_aubit_attr (attr, 'w');

  A4GL_debug ("attr=%x\n", attr);

  A4GL_debug ("Disp_form_tui");
  f = (struct s_form_dets *) A4GL_find_pointer_val (name, S_FORMDETSCODE);
  A4GL_debug ("Got pointer to form as %p", f);
  if (f == 0)
    {
      A4GL_exitwith ("The form has not been opened");
      return 0;
    }
  w = A4GL_display_form (f,attr);
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
  UILIB_A4GL_current_window (windows[a].name);
/*error_box(windows[a].name); */
  return 0;
}


#ifdef OLD
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

  if (top) {
	A4GL_debug("top");
    rc = top_panel (ptr);
  }
  else {
	A4GL_debug("bottom");
    rc = bottom_panel (ptr);
  }

  A4GL_debug ("Rc=%d", rc);
  A4GL_debug ("Topped");

  make_error_panel_top();

/*
  if (curr_error_panel) {
	A4GL_debug("top_panel curr_error_panel : %p",curr_error_panel);
	top_panel(curr_error_panel);
  }
*/

  print_panel_stack ();
  A4GL_do_update_panels ();


#ifdef NDEF
  doupdate ();
  UILIB_A4GL_zrefresh ();
#endif
  print_panel_stack ();
  return 0;
}
#endif

/**
 *
 * @todo Describe function
 */
int
A4GL_subwin_gotoxy (WINDOW * win, int x, int y,int has_border)
{
  int a;
//if (has_border) y--;
	A4GL_debug("subwin_gotoxy - %d %d win=%p",y-1,x-1,win);
 if (y<1) y=1;
 if (x<1) x=1;
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
  va_start (args, fmt);
  A4GL_debug ("subwin_print '%s' on window %p", fmt, win);
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
A4GL_debug("subwin_printxy %d %d %s",x,y,fmt);
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
  char buff[10024];
  memset(buff,0,sizeof(buff));
  vsprintf (buff, fmt, *args);
	
  if (strlen(buff)>256) {
	char *ptr=0;
	printf("OOps...\n");fflush(stdout);
	*ptr=0;
  }
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
  A4GL_debug ("Attribute : %x on win %p - buff=%s\n", A4GL_xwattr_get (win), win,buff);
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
int bkgcolor;
int colors[8];
int bkg_def;
int bkg;
int fg;
int fg_def;
int a;
colors[0]=atoi(acl_getenv("COLOR_TUI_BLACK"));
colors[1]=atoi(acl_getenv("COLOR_TUI_RED"));
colors[2]=atoi(acl_getenv("COLOR_TUI_GREEN"));
colors[3]=atoi(acl_getenv("COLOR_TUI_YELLOW"));
colors[4]=atoi(acl_getenv("COLOR_TUI_BLUE"));
colors[5]=atoi(acl_getenv("COLOR_TUI_MAGENTA"));
colors[6]=atoi(acl_getenv("COLOR_TUI_CYAN"));
colors[7]=atoi(acl_getenv("COLOR_TUI_WHITE"));

bkg_def=atoi(acl_getenv("COLOR_TUI_BKG_DEF"));
bkg=atoi(acl_getenv("COLOR_TUI_BKG"));

fg_def=atoi(acl_getenv("COLOR_TUI_FG_DEF"));
fg=atoi(acl_getenv("COLOR_TUI_FG"));

for (a=0;a<=7;a++) {
	A4GL_debug("Colours : %d %d",a,colors[a]);
}
A4GL_debug("Background if we have defaults : %d",bkg_def);
A4GL_debug("Background if we dont have defaults : %d",bkg);
A4GL_debug("BLACK : %d %d",colors[0],COLOR_BLACK);
A4GL_debug("YELLOW : %d %d",colors[3],COLOR_YELLOW);
A4GL_debug("WHITE : %d %d",colors[7],COLOR_WHITE);


if (have_default_colors) {
	bkgcolor=bkg_def;
	fg=fg_def;
} else {
	bkgcolor=bkg;
}

A4GL_debug("Colours - BKG=%d\n",bkgcolor);
  init_pair (1, colors[0], bkgcolor);
  init_pair (2, colors[1], bkgcolor);
  init_pair (3, colors[2], bkgcolor);
  init_pair (4, colors[3], bkgcolor);
  init_pair (5, colors[4], bkgcolor);
  init_pair (6, colors[5], bkgcolor);
  init_pair (7, colors[6], bkgcolor);
  init_pair (8, colors[7], bkgcolor);




A4GL_debug("Assume default colors : %d %d",bkgcolor,fg);
#ifdef NCURSES_VERSION
  assume_default_colors(fg,bkgcolor);
#endif
  //assume_default_colors(COLOR_WHITE,COLOR_BLACK);

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
  if (p == 0) {
	A4GL_debug("find_win for panel_below(0)");
	p=get_below_panel(0);


/*
	p=panel_below(0);
	if (p==curr_error_panel) p=panel_below(p);
*/




        return A4GL_find_win (p);
  }
#ifdef DEBUG
  {
    A4GL_debug ("Finding window %p", p);
  }
#endif

  for (a = 0; a < MAXWIN; a++)
    {
	if (windows[a].pan==0) continue;
#ifdef DEBUG
      {
 A4GL_debug ("Checking windows   : %p %p %p", panel_window (windows[a].pan),
	       windows[a].pan, p);
      }
#endif

      if ((PANEL *) panel_window (windows[a].pan) == p
	  || (PANEL *) windows[a].pan == p)
	{


	  if (a4gl_toupper (windows[a].name[0]) == windows[a].name[0])
	    {
#ifdef DEBUG
	      {
	 A4GL_debug ("window is a menu - finding parent of %s",
		       windows[a].name);
	      }
#endif

		A4GL_assertion(1,"Fake window - thought i'd got rid of these");
	      //return A4GL_find_win (A4GL_find_pointer (windows[a].name, MNPARCODE));
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
 UILIB_A4GL_hide_window (char *winname)
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
 UILIB_A4GL_show_window (char *winname)
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
int a;
A4GL_debug("Get formline...%d",windows[currwinno].winattr.form_line);
  if (windows[currwinno].winattr.form_line!=0xff) {
	a=windows[currwinno].winattr.form_line;
  } else {
        a=std_dbscr.form_line;
  }

/* There seems to be some sort of bug in informix -
   if you have a window with a border - the form is shifted up 1 line...
   so a form line 3 would be displayed on line 2...

  if ( A4GL_get_curr_border ()) {
	a--;
  }
*/


 A4GL_debug("FORMLINE = %d",a);
  return a;

}

/**
 *
 * @todo Describe function
 */
int
A4GL_getcomment_line (void)
{
A4GL_debug("Comment line for currwin=%d std_dbscr=%d",windows[currwinno].winattr.comment_line,std_dbscr.comment_line);
  if (windows[currwinno].winattr.comment_line!=0xff) {
	return A4GL_decode_line_ib (windows[currwinno].winattr.comment_line);
  }
  return A4GL_decode_line_ib (std_dbscr.comment_line);
}

/**
 *
 * @todo Describe function
 */
int
A4GL_geterror_line (void)
{

  A4GL_debug ("geterror_line - %d (%d)", windows[currwinno].winattr.error_line,currwinno);
  if (windows[currwinno].winattr.error_line!=0xff) {
	A4GL_debug("Window specific...");
        return A4GL_decode_line_scr (windows[currwinno].winattr.error_line);
  }
  A4GL_debug ("geterror_line - from options : %d", std_dbscr);
   
  return A4GL_decode_line_scr (std_dbscr.error_line);
}


/**
 *
 * @todo Describe function
 */
int
A4GL_getmessage_line (void)
{
int a;
int b;
  A4GL_debug ("getmessage_line - %d", windows[currwinno].winattr.message_line);



  if (windows[currwinno].winattr.message_line!=0xff) {
        a=windows[currwinno].winattr.message_line;
        b=1;
  } else {
        a=std_dbscr.message_line; // MJAMJA
        b=2;
  }


  if (a<0) {
        A4GL_debug("a<0 - %d",a);
        a=0-a-1;
        A4GL_debug("a now %d",a);
        if (currwinno==0) {
                a=A4GL_screen_height()-a;
                A4GL_debug("a=%d from screen_height",a);
        } else {
                a=A4GL_get_curr_height()-a;
                A4GL_debug("a=%d from curr_height",a);
        }
        A4GL_debug("a=%d",a);
  }

  A4GL_debug("Thinking message_line should be %d - window height=%d",a,A4GL_get_curr_height());

  if (currwinno==0) {
        A4GL_debug("MSG SCR %d %d %d",a,A4GL_get_curr_height(),A4GL_iscurrborder());
  } else {
        A4GL_debug("MSG WIN %d %d %d",a,A4GL_get_curr_height(),A4GL_iscurrborder());
  }

  if (currwinno==0) {
         while (a>A4GL_screen_height()) {
                A4GL_debug("message_line line - Too far down screen - moving up %d>%d+%d", a,A4GL_get_curr_height(),A4GL_iscurrborder());
                a--;
        }
  } else {
        if (a>(A4GL_get_curr_height())) {
                a=2;
		if (a>A4GL_get_curr_height()-A4GL_iscurrborder()) a=1;
        }
  }


  if (a<=0) a=1;

  A4GL_debug("Msg line %d",a);
return a;

}


/**
 *
 * @todo Describe function
 */
int
A4GL_getprompt_line (void)
{
int a;
int b;
  A4GL_debug ("getprompt_line - %d", windows[currwinno].winattr.prompt_line);



  if (windows[currwinno].winattr.prompt_line!=0xff) {
	a=windows[currwinno].winattr.prompt_line;
	b=1;
  } else {
  	a=std_dbscr.prompt_line; // MJAMJA 
	b=2;
  }


  if (a<0) {
	A4GL_debug("a<0 - %d",a);
	a=0-a-1;
	A4GL_debug("a now %d",a);
	if (currwinno==0) {
		a=A4GL_screen_height()-a;
		A4GL_debug("a=%d from screen_height",a);
	} else {
		a=A4GL_get_curr_height()-a;
		A4GL_debug("a=%d from curr_height",a);
	}
	A4GL_debug("a=%d",a);
  }

  A4GL_debug("Thinking prompt should be %d - window height=%d",a,A4GL_get_curr_height());

  if (currwinno==0) {
	A4GL_debug("PROMPT SCR %d %d %d",a,A4GL_get_curr_height(),A4GL_iscurrborder());
  } else {
	A4GL_debug("PROMPT WIN %d %d %d",a,A4GL_get_curr_height(),A4GL_iscurrborder());
  }

  if (currwinno==0) {
	 while (a>A4GL_screen_height()) {
		A4GL_debug("prompt line - Too far down screen - moving up %d>%d+%d", a,A4GL_get_curr_height(),A4GL_iscurrborder());
		a--;
  	} 
  } else {
  	if (a>(A4GL_get_curr_height())) {
		a=1;
  	}
  }


  if (a<=0) a=1;
 
  A4GL_debug("Prompt line %d",a);
return a;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
LIBEXPORT int
 UILIB_A4GL_movewin (char *winname, int absol)
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
 UILIB_A4GL_iscurrborder (void)
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
  ptr=0;
  while (1) {
  	ptr = panel_below (ptr);
  	s = panel_userptr (ptr);	/* get name of panel */
	if (strcmp(s,"error window")==0) continue;
	if (s) break;
	
  }
  A4GL_debug("window_on_top - %s",s);
  winptr = A4GL_find_pointer (s, WINCODE);
  return winptr;
}


WINDOW *
A4GL_window_on_top_ign_menu (void)
{
  PANEL *ptr;
  char *s;
  void *winptr;
  int ok=0;
  ptr=0;

  while (1) {
  	ptr = panel_below (ptr);
	A4GL_debug("panel below=%p",ptr);
  	s = panel_userptr (ptr);	/* get name of panel */
	if (strcmp(s,"error window")==0) continue;
	A4GL_debug("userptr=%p",s);
	
	if (s) {
		A4GL_debug("Got an s = '%s'",s);
		ok=1;
		break;
	}
	
  }

  if (ok==0) {
	A4GL_debug("can't find window on top....");
  } else {
  	A4GL_debug("window_on_top - %s",s);
  }
/*
  if (A4GL_has_pointer (s, MNPARCODE)) {
		// Damn - its a menu - whats our parent ?
		A4GL_debug("Was menu window...");
		return A4GL_find_pointer (s, MNPARCODE);
  }
*/
  winptr = A4GL_find_pointer (s, WINCODE);
	A4GL_debug("Winptr=%p",winptr);
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
 UILIB_A4GL_sleep_i (void)
{
  int a;
  a = A4GL_pop_int ();
  sleep (a);
}


void A4GL_make_window_with_this_form_current(void *form) {
int a;
for (a=0;a<MAXWIN;a++) {
	if (windows[a].form==form) {
		A4GL_debug("Found it... @ %d",a);
  		UILIB_A4GL_current_window (windows[a].name);
		return;
	}
}

}

/* =============================== EOF =============================== */
