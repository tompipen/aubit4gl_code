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
# $Id: newpanels.c,v 1.7 2003-01-21 08:25:56 afalout Exp $
#*/

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
int scr_width 	= -1;
int scr_height 	= -1;
int currwinno 	= -1;
int currattr 	= 0;

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

int 	mja_vwprintw 		(WINDOW * win, char *fmt,va_list *args);
int 	current_window 		(char *win_name);
void 	print_panel_stack 	(void);
void 	init_stddbscr 		(void);
void 	do_update_panels 	(void);
void 	change_currwinno 	(int a, char *s);
void 	change_currwin 		(WINDOW * a, char *s);
void 	inc_winname 		(char *b);
int 	getch_swin 			(WINDOW * window_ptr);
int 	getform_line 		(void);
int 	find_win 			(PANEL * p);
int 	chkwin 				(void);
int 	screen_height 		(void);
int 	top_win 			(PANEL * p);
char * 	pointer_code 		(int c);
void 	clr_window 			(char *win_name);
int 	int_current_window 	(char *win_name);
void 	mja_gotoxy 			(int x, int y);
int 	get_curr_win 		(void);
int 	get_curr_height 	(void);
int 	get_curr_top 		(void);
char * 	get_currwin_name 	(void);
int 	get_curr_border 	(void);
void 	display_at2 		(char *z, int x, int y, int a);
int 	decode_line 		(int l);
void 	display_error 		(int a,int wait);
void 	add_compiled_form	(char *s,char *frm);
int  	open_form 			(char *name);
void 	close_form 			(char *formname);
int  	disp_form 			(char *name, int attr);
int  	set_window 			(int a);
int 	subwin_printxy 		(WINDOW * win, int x, int y, char *fmt,...);
int 	subwin_setcolor 	(WINDOW * win, int typ);
int 	getcomment_line 	(void);
void 	set_attr_win 		(char s, int wattr);
char * 	windowname_on_top 	(void);
int 	invert_color 		(int a);
void 	sleep_i				(void);

WINDOW *window_on_top 		(void);
WINDOW *display_form_new_win (char *name, struct s_form_dets *f, int x, int y);
WINDOW * display_form 		(struct s_form_dets *f);
WINDOW *create_window 		(char *name, int x, int y, int w, int h, int iswindow, int form_line, int error_line, int prompt_line, int menu_line, int border, int comment_line, int message_line, int attrib);
WINDOW * display_form_win 	(WINDOW * w, char *name, struct s_form_dets * f);

void * 	cr_window 			(char *s,int iswindow,int form_line,int error_line,int prompt_line,
	  				int menu_line,int border,int comment_line,int message_line,int attrib);
int 	cr_window_form 		(char *name,int iswindow,int form_line,int error_line,
					int prompt_line,int menu_line,int border,int comment_line,int message_line,
					int attrib);


LIBEXPORT void hide_window 	(char *winname);
LIBEXPORT void show_window 	(char *winname);
LIBEXPORT int movewin 		(char *winname, int absol);


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
pointer_code (int c)
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
init_windows (void)
{
  int a;
  for (a = 0; a < MAXWIN; a++)
    {
      windows[a].name[0] = 0;
    }
  create_blank_window ("screen", 1, 1, 79, 23, 0);
  current_window ("screen");
  /*error_box("Currwin=screen"); */
  init_stddbscr ();
  return 0;

}

/**
 *
 * @todo Describe function
 */
LIBUSEONLY void *
create_blank_window (char *name, int x, int y, int w, int h, int border)
{
  return create_window (name, x, y, w, h, 1, 1, 1, 1, 1, border, 1, 1, 0);
}

/**
 *
 * @todo Describe function
 */
WINDOW *
create_window (char *name, int x, int y, int w, int h,
	       int iswindow,
	       int form_line,
	       int error_line,
	       int prompt_line,
	       int menu_line,
	       int border,
	       int comment_line,
	       int message_line,
	       int attrib
)
{
  WINDOW *win = 0;
  WINDOW *dswin;
  PANEL *pan;
  int a;
  chkwin ();
  #ifdef DEBUG
  	debug ("Creating window %s (%d %d %d %d) %d attrib=0x%x", name, x, y, w, h, border, attrib);
  #endif

	if (form_line==0xff) { form_line=std_dbscr.form_line; }
	if (menu_line==0xff) { menu_line=std_dbscr.menu_line; }
	if (comment_line==0xff) { comment_line=std_dbscr.comment_line; }
	if (error_line==0xff) { error_line=std_dbscr.error_line; }
	if (prompt_line==0xff) { prompt_line=std_dbscr.prompt_line; }
	if (strcmp (name, "screen") == 0)
    {
      h = screen_height () - 1;
      w = screen_width () - 1;
      debug ("Creating window : h=%d w=%d y=%d x=%d", h, w, y - 1, x - 1);
      debug ("win = newwin (%d,%d,0,0)", screen_height (), screen_width ());
      win = newwin (screen_height (), screen_width (), 0, 0);
      debug ("Calling screen height");
      debug ("h=%d", h);
      debug ("Calling screen width");
      debug ("w=%d", w);

      gui_win (name, screen_height (), screen_width (), 1, 1, 0, (long)win);
      add_pointer (name, WINCODE, win);
    }
	else
    {

    	if (border==1)
		{
		  win = newwin (h + 2, w + 2, y - 2, x - 2);
		  if (toupper (name[0]) != name[0])
	    	gui_win (name, h + 2, w + 2, y - 2, x - 2, 1, (long)win);
		  add_pointer (name, WINCODE, win);
		}

      	if (border==2)
		{
			dswin = newwin (h + 4, w + 4, y - 2, x - 2);
			win = newwin (h + 2, w + 2, y - 2, x - 2);
			add_pointer (name, WINCODE, win);
			add_pointer (name, DROPSHADOW, dswin);
	  		set_bkg (dswin, '+');
			debug("XX3 REVERSE");
	      	  wbkgdset (dswin, COLOR_RED|A_REVERSE);
	  		mja_wrefresh (dswin);
			sleep(2);
		}

		if (border==3)
		{
		  	dswin = newwin (h + 4, w + 4, y - 1, x - 1);
		  	win = newwin (h, w, y - 2, x - 2);
		  	add_pointer (name, WINCODE, win);
		  	add_pointer (name, DROPSHADOW, dswin);
		  	debug("XX4 REVERSE");
	      	wbkgdset (dswin, COLOR_RED|A_REVERSE);
	  		mja_wrefresh (dswin);
			sleep(2);
	    }

		if (border==0)
		{
		  win = newwin (h, w, y - 1, x - 1);
		  if (toupper (name[0]) != name[0]) gui_win (name, h, w, y - 1, x - 1, 0, (long)win);
		  add_pointer (name, WINCODE, win);
		  debug ("Window = %p", win);
		}

    }

	#ifdef DEBUG
		debug ("Window created");
	#endif

	if (win == 0)
    {
	  #ifdef DEBUG
    	debug ("COuldnt create window h=%d w=%d y=%d x=%d", h, w, y, x);
	  #endif
      exitwith ("Couldnt create window");
      return 0;
    }

  mja_wrefresh (win);

  if ((attrib & 0xff) == 0)
    {
      attrib = attrib + ' ';
      debug ("Set pad char to space");
    }
  debug ("Setting attribute for window to 0x%x\n", attrib);
  set_bkg (win, attrib);
  add_pointer (name, ATTRIBUTE, (void *) attrib);
  if (border)
    {
      wbkgdset (win, attrib);
      debug ("Adding border %x", attrib);
      wborder (win, 0, 0, 0, 0, 0, 0, 0, 0);
      wbkgdset (win, 0);
      mja_wrefresh (win);
    }

  pan = new_panel (win);
  set_panel_userptr (pan, strdup (name));
  add_pointer (name, PANCODE, pan);

#ifdef DEBUG
  {     debug ("Panel created at %p for window %p", pan, win);  }
#endif

  if (pan == 0)
    {
      error_box ("Couldnt create panel");
    }


  for (a = 0; a < MAXWIN; a++)
    {
      if (windows[a].name[0] == 0)
	{
#ifdef DEBUG
	  {	    debug ("Adding window at %d panel id = %p", a, pan);	  }
#endif
	  strcpy (windows[a].name, name);
	  add_pointer (name, S_WINDOWSCODE, &windows[a]);
	  windows[a].pan = pan;
	  windows[a].form = 0;
	  windows[a].winattr.comment_line = comment_line;
	  windows[a].winattr.menu_line = menu_line;
	  debug ("Setting prompt line to %d", prompt_line);
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
	  /* change_currwin (win); */
	  break;
	}
    }
  if (!(has_pointer (name, S_WINDOWSCODE)))
    {
      exitwith ("No spare windows left...");
      return 0;
    }

  keypad (win, TRUE);
  if (toupper (name[0]) != name[0])
    {
#ifdef DEBUG
      {	debug ("Making proper window....for %s", name);      }
#endif
      change_currwin (win, "Marker 1");
      change_currwinno (a, "Marker 2");
      top_panel (pan);

      if (screen_mode (-1))
	{
	  update_panels ();
	  doupdate ();
	}
#ifdef DEBUG
      {	debug ("Adding new pointer to window...");      }
      {	debug ("Done...");      }
#endif
    }
  else
    {
#ifdef DEBUG
      {	debug ("Adding window pointers for menu %p > %p", currwin, win);      }
#endif
      add_pointer (name, MNPARCODE, currwin);
      add_pointer (name, MNWINCODE, win);

      top_panel (pan);
      if (screen_mode (-1))
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
clr_window (char *win_name)
{
  int a;
  WINDOW *w;
  struct s_windows *win;
  chkwin ();
  if (!(has_pointer (win_name, WINCODE)))
    {
      set_error ("Window not found %s", win_name);
      exitwith ("Window not found");
      set_errm (win_name);
      return;
    }
#ifdef DEBUG
  {    debug ("Clr window .... %s", win_name);  }
#endif
  w = find_pointer (win_name, WINCODE);
  win = find_pointer (win_name, S_WINDOWSCODE);
  wclear (w);

  if (win->winattr.border)
    {
      debug ("Clr screen - redraw border");
      wborder (w, 0, 0, 0, 0, 0, 0, 0, 0);
    }
  zrefresh ();
  return;

  for (a = 0; a < MAXWIN; a++)
    {
      if (strcmp (windows[a].name, win_name) == 0)
	{
	  wclear (panel_window (windows[a].pan));
	  break;
	}
    }
  zrefresh ();
}



/**
 * 4GL CALL
 * @todo Describe function
 */
void
remove_window (char *win_name)
{
  int a;
  WINDOW *win;
  PANEL *panel;
  chkwin ();
#ifdef DEBUG
  gui_closewin (win_name);
  {     debug ("Remove Window : %s", win_name);  }
#endif

  if (!(has_pointer (win_name, WINCODE)))
    {
      set_error ("Window not found %s", win_name);
      exitwith ("Window not found");
      set_errm (win_name);
      return;
    }

  for (a = 0; a < MAXWIN; a++)
    {
      if (strcmp (windows[a].name, win_name) == 0)
	{
	  win = panel_window (windows[a].pan);
	  panel = windows[a].pan;
#ifdef DEBUG
	  {	    debug ("Deleting window and panel at %d", a);	  }
	  {	    debug ("Window found ... deleting... %p", win);	  }
	  {	    debug ("Deleted window.. deleting panel %p", panel);	  }
#endif
	  del_panel (panel);
#ifdef DEBUG
	  {	    debug ("Deleted panel ... removing window");	  }
#endif
	  delwin (win);
#ifdef DEBUG
	  {	    debug ("Here...");	  }
#endif
	  windows[a].name[0] = 0;
	  break;
	}
    }
#ifdef DEBUG
  {    debug ("Finding top window number");  }
#endif
  top_win (0);
  update_panels ();
  doupdate ();
  refresh ();
  zrefresh ();
#ifdef DEBUG
  {    debug ("Deleting pointer %s", win_name);  }
#endif
  del_pointer (win_name, WINCODE);

}

/**
 *
 * @todo Describe function
 */
int
int_current_window (char *win_name)
{
  PANEL *p;
  WINDOW *w;
  chkwin ();
  p = find_pointer (win_name, PANCODE);
  w = find_pointer (win_name, WINCODE);
  if (!(p))
    {
      set_error ("%s", win_name);
      exitwith ("Window not found");
      set_errm (win_name);
      return 0;
    }
  top_panel (p);

  if (screen_mode (-1))
    {
      update_panels ();
      doupdate ();
    }
  zrefresh ();
  return 0;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
current_window (char *win_name)
{
  int a = 0;
  PANEL *p;
  WINDOW *w;
  debug ("Current window....");
  debug ("currwinno=%d currwin=%p", currwinno, currwin);

  chkwin ();
#ifdef DEBUG
  {    debug ("In current window %s", win_name);  }
#endif
  p = find_pointer (win_name, PANCODE);
  w = find_pointer (win_name, WINCODE);
  if (!(p))
    {
      set_error ("%s", win_name);
      exitwith ("Window not found");
      set_errm (win_name);
      return 0;
    }
  top_panel (p);
#ifdef DEBUG
  {    debug ("Resetting current window %d", a);  }
#endif
  change_currwin (panel_window (p), "Marker 5");
  change_currwinno (find_win (p), "Marker 6");
#ifdef DEBUG
  {    debug ("Changed windows...");  }
#endif
  if (screen_mode (-1))
    {
      update_panels ();
      doupdate ();
    }
#ifdef DEBUG
  {    debug ("Updated screen %p", currwin);  }
#endif
  mja_wrefresh (currwin);
#ifdef DEBUG
  {    debug ("wrefresh");  }
#endif
  zrefresh ();
  mja_refresh ();
#ifdef DEBUG
  {    debug ("Refreshed screen");  }
#endif
  return 0;

}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
zrefresh (void)
{
  gui_refresh ();
  if (screen_mode (-1))
    {
      chkwin ();
      update_panels ();
      doupdate ();
      /* mja_wrefresh (currwin); */
      mja_refresh ();
    }
}

/**
 *
 * @todo Describe function
 */
void
mja_gotoxy (int x, int y)
{
  int a;
  chkwin ();

  debug ("In move - %d %d current window=%p", x, y, window_on_top ());
  gui_move (x, y);
  debug ("In move - %d %d", x, y);
  if (windows[currwinno].winattr.border)
    {
      debug ("In move border - %d %d", x, y);
      a = wmove (currwin, y, x);
    }
  else
    {
      debug ("In move no border - %d %d", x, y);
      a = wmove (currwin, y - 1, x - 1);
    }
  debug ("In move - %d %d", x, y);
  if (a == OK)
    {
      debug ("Move to %d,%d - %d", x, y, a);
    }
  else
    {
      debug ("Move to %d %d fails", x, y);
    }
  mja_refresh ();
}

/**
 * Renamed from 'print' to 'tui_print'
 * @todo Describe function
 */
void
tui_print (char *fmt,...)
{
  va_list args;
  char buff[256];
#ifdef DEBUG
  {    debug ("In tui_print");  }
#endif
  chkwin ();
  va_start (args, fmt);
  vsprintf (buff, fmt, args);
  wprintw (currwin, "%s", buff);
  mja_wrefresh (currwin);
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
  chkwin ();
  unpost_form (f);
  werase (w);
  mja_wrefresh (w);
#ifdef DEBUG
  {    debug ("Removing Window %p", s);  }
  {    debug ("Removing Window %w", s);  }
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
display_form (struct s_form_dets *f)
{
  int rows, cols;
  char buff[80];
  int a;
  WINDOW *w;
  WINDOW *drwin;
	/*  FIELD **p; */

  int fl;
  chkwin ();
  debug ("In display_form");
  w = currwin;

  if (w == 0)
    {
      error_box ("NO WINDOW");
    }
  debug ("scale form %p", f->form);

  fl = getform_line ();
  scale_form (f->form, &rows, &cols);
  rows = f->fileform->maxline-1;
  cols = f->fileform->maxcol;

  debug ("Form line=%d", fl);
  debug ("Scale form returns %d %d", rows, cols);
  debug ("Current window %d %d", windows[currwinno].h,
	 windows[currwinno].w);
  /* rows+=fl; */
  rows++;

  if (rows - windows[currwinno].winattr.border > windows[currwinno].h + 1)
    {
      exitwith ("Window is too small to display this form (too high)");
      return 0;
    }
  if (cols - windows[currwinno].winattr.border > windows[currwinno].w + 1)
    {
      exitwith ("Window is too small to display this form (too wide)");
      return 0;
    }


	/* fix - not sure whats going on here bit form_details.border is set to 1
   for the screen! */
  f->form_details.border = windows[currwinno].winattr.border;

  if (f->form_details.border)
    {
      debug ("Form details returns it has border");
    }
  else
    {
      debug ("Form details returns it has *NO* border");
    }

  if (windows[currwinno].winattr.border)
    {
      debug ("Window details returns it has border");
    }
  else
    {
      debug ("Window details returns it has *NO* border ");
    }

  debug("derwin - %d rows %d cols form line=%d",rows,cols,fl);
  if (windows[currwinno].winattr.border)
    drwin = derwin (w, rows, cols, fl, 1);
  else
    drwin = derwin (w, rows, cols, fl - 1, 0);

#ifdef DEBUG
  {    debug ("drwin=%p", drwin);  }
#endif

  if (drwin == 0)
    {
      exitwith ("Window is too small to display this form");
      return 0;
    }
  a = set_form_win (f->form, w);

  if (a == E_POSTED)
    {
      unpost_form (f->form);
      a = set_form_win (f->form, w);
    }

  a = set_form_sub (f->form, drwin);

  debug ("setup windows");
  keypad (w, TRUE);
  sprintf (buff, "Currwinno=%d", currwinno);
  /*error_box(buff); */
  windows[currwinno].form = f;

  if (f->form == 0) {
	exitwith("Unable to create form");
	return 0;
  }

  debug ("post the form s_form_dets=%p form=%p", f, f->form);
  a = post_form (f->form);

  if (a == E_POSTED)
    {
      debug ("Form posted already - dumping and re-doing");
      unpost_form (f->form);
      a = post_form (f->form);
    }

  if (f->form_details.border)
    {
      debug ("Form has border");
      wborder (currwin, 0, 0, 0, 0, 0, 0, 0, 0);
    }
  debug ("start the form");

  start_form (f);

  mja_wrefresh (w);
  debug ("And return");
  return w;
}


/**
 *
 * @todo Describe function
 */
WINDOW *
display_form_new_win (char *name, struct s_form_dets * f, int x, int y)
{
  WINDOW *w;
  int rows, cols;
  char buff[80];
  chkwin ();

  scale_form (f->form, &rows, &cols);
  rows = f->fileform->maxline;
  cols = f->fileform->maxcol;
  debug ("display_form_new_win : %d rows %d cols at %d,%d x,y", rows, cols, x, y);

  debug ("display_form_new_win - border=%d", f->form_details.border);
  sprintf (buff, "%d %d", cols, rows);
#ifdef DEBUG
  {				/*debug("Rows=%d formline=%d f2 = %d",rows,getform_line(),f->form_details.form_line); */  }
#endif
  w = create_window (name, x, y, cols, rows + f->form_details.form_line,
		     1,
		     f->form_details.form_line,
		     f->form_details.error_line,
		     f->form_details.prompt_line,
		     f->form_details.menu_line,
		     f->form_details.border,
		     f->form_details.comment_line,
		     f->form_details.message_line,
		     f->form_details.colour
    );

  gui_dispform (name, getform_line ());
  if (display_form (f)) return w;
  else return 0;
}

/**
 *
 * @todo Describe function
 */
WINDOW *
display_form_win (WINDOW * w, char *name, struct s_form_dets * f)
{
  chkwin ();
#ifdef DEBUG
  {    debug ("setting form window for %p to %p", f->form, w);  }
#endif

  set_form_win (f->form, w);
  set_form_sub (f->form, derwin (w, 8, 58, 1, 1));
  keypad (w, TRUE);
  gui_dispform (name, getform_line ());
  post_form (f->form);
  start_form (f->form);
  return w;
}

/**
 *
 * @todo Describe function
 */
int
get_curr_win (void)
{
  return currwinno;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void *
get_curr_form (void)
{
  char buff[80];
  sprintf (buff, "currwinno=%d", currwinno);

#ifdef DEBUG
  {    debug ("currwinno=%d", currwinno);  }
#endif

  /*error_box(buff); */
  if (windows[currwinno].form == 0)
    {
      exitwith ("No current form");
      return 0;
    }
  return windows[currwinno].form;
}

/**
 *
 * @todo Describe function
 */
int
get_curr_left (void)
{
  return windows[currwinno].x;
/* + windows[currwinno].winattr.border; */
}

/**
 *
 * @todo Describe function
 */
int
get_curr_height (void)
{
  return windows[currwinno].h;
}

/**
 *
 * @todo Describe function
 */
int
get_curr_print_top (void)
{
#ifdef DEBUG
  {    debug ("In curr_print_top %d %d", windows[currwinno].winattr.border, windows[currwinno].y);  }
#endif

  return windows[currwinno].y + windows[currwinno].winattr.border;
}

/**
 *
 * @todo Describe function
 */
int
get_curr_top (void)
{
  return windows[currwinno].y;
}

/**
 *
 * @todo Describe function
 */
int
get_curr_width (void)
{
  debug ("get curr width, currwinno=%d windows name =%s %d", currwinno,
	 windows[currwinno].name,
	 windows[currwinno].w);
  return windows[currwinno].w;
}

/**
 *
 * @todo Describe function
 */
char *
get_currwin_name (void)
{
  return windows[currwinno].name;
}


/**
 *
 * @todo Describe function
 */
int
get_curr_border (void)
{
  debug ("get curr border, currwinno=%d windows name =%s %d", currwinno,
	 windows[currwinno].name,
	 windows[currwinno].winattr.border);
  return windows[currwinno].winattr.border;
}


/**
 *
 * @todo Describe function
 */
void
mja_setcolor (int typ)
{
  gui_setcolor (typ);
  debug ("Set color.");
  if (has_colors ())
    {
      debug ("Has color\n");
      switch (typ)
	{
	case ERROR_COL:
	debug("XX4 REVERSE");
	  currwin->_attrs = colour_code (COLOR_RED) | A_REVERSE;
	  break;
	case MESSAGE:
	debug("XX4 REVERSE");
	  currwin->_attrs = colour_code (COLOR_CYAN) | A_REVERSE;
	  break;
	case NORMAL_MENU:
	  standend ();
	  /* currwin->_attrs = colour_code (COLOR_WHITE); */
	  break;
	case INVERT_MENU:
	  standout ();
	debug("XX4 REVERSE");
	  /* currwin->_attrs = colour_code (COLOR_WHITE) | A_REVERSE; */
	  break;
	case TITLE_COL:
	  currwin->_attrs = colour_code (COLOR_WHITE);
	  break;
	case EDIT_FIELD:
	  currwin->_attrs = colour_code (COLOR_WHITE);
	  break;
	case NORMAL_TEXT:
	  /* currwin->_attrs = colour_code (COLOR_WHITE); */
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
	debug("XX4 REVERSE");
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
	debug("XX4 REVERSE");
	  /* currwin->_attrs = A_REVERSE; */
	  break;
	case TITLE_COL:
	debug("XX4 REVERSE");
	  currwin->_attrs = A_REVERSE;
	  break;
	case EDIT_FIELD:
	debug("XX4 REVERSE");
	  currwin->_attrs = A_REVERSE;
	  break;
	case NORMAL_TEXT:
	  standend ();
	  break;
	}
    }
  debug ("Done..");
}

/**
 *
 * @todo Describe function
 */
void
display_at2 (char *z, int x, int y, int a)
{
  int b;
  WINDOW *cwin;
  cwin = window_on_top ();
  b = xwattr_get (cwin);
  mja_gotoxy (x, y);
  a4glattr_wattrset (cwin, a);
  gui_print (a, z);
  tui_print ("%s", z);
  wattrset (cwin, b);
  mja_wrefresh (cwin);
}


/**
 *
 * @todo Describe function
 */
int
getch_win (void)
{
  return getch_swin (window_on_top ());
}

/**
 *
 * @todo Describe function
 */
int
getch_swin (WINDOW * window_ptr)
{
  int a;
  if (isgui ())
    {
      return get_gui_char ();
    }

  debug ("Reading from keyboard on window %p", window_ptr);
  set_abort (0);

  while (1)
    {
      halfdelay (1);
      a = wgetch (window_ptr);
      if (a == KEY_MOUSE)
	{
	  debug ("Mouse event...");
	}
      if (aborted)
	{
	  debug ("Aborted!");
	  a = KEY_CANCEL;
	  break;
	}

      if (a != -1)
	{
	  debug ("Key Pressed");
	  break;
	}

    }
  cbreak ();
  debug ("Got char from keyboard : %d", a);
  return a;
}



/**
 *
 * @todo Describe function
 */
int
decode_line (int l)
{
  if (l > 0)
  {
    if (get_curr_border ())
      {
	debug ("Decoded line %d to %d (because of border)", l, l - 1);
	return l - 1;
      }
    else
      {
	debug ("Decoded line %d to %d", l, l);
	return l;
      }
  }
/* -1 = last */
/* -2 = last -1 */
  if (get_curr_border ())
    {
      if (l < 0)
	{
	  debug ("Decoded line %d to %d  %d ", l, get_curr_height ());
	  return get_curr_height () + l;
	}

    }
  else
    {
      if (l < 0)
	{
	  debug ("Decoded line %d to %d  %d ", l, get_curr_height ());
	  return get_curr_height () + l + 1;
	}

    }
return 0;
}

/**
 *
 * @todo Describe function
 */
char *
glob_window (int x, int y, int w, int h, int border)
{
  static char winname[20];
  int f;
#ifdef DEBUG
  {    debug ("In glob_window");  }
#endif
  chkwin ();
  memset (winname, 'A', 19);
  f = 1;
  winname[19] = 0;

#ifdef DEBUG
  {    debug ("Finding free window ... starting with %s", winname);  }
#endif

  while (has_pointer (winname, WINCODE))
    {
      inc_winname (winname);
    }
  create_blank_window (winname, x, y + 1, w, h, border);
#ifdef DEBUG
  {				/*debug("Adding window @ %d %s",a,winname); */  }
#endif
  /*add_pointer (winname, WINCODE, win); */
  return winname;
}

/**
 *
 * @todo Describe function
 */
void
inc_winname (char *b)
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
getmenu_line (void)
{
#ifdef DEBUG
  {    debug ("In menu line... currwinno=%d ", currwinno);  }
  {    debug ("name=%s ", windows[currwinno].name);  }
#endif

  if (strcmp (windows[currwinno].name, "screen") == 0)
    {
      /* use screen default */
      return decode_line (std_dbscr.menu_line);
    }

  debug ("form=%p", windows[currwinno].form);
  debug ("menu line=%d (%s)", windows[currwinno].winattr.menu_line,
	 windows[currwinno].name
    );
  return decode_line (windows[currwinno].winattr.menu_line);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
display_at (int n, int a)
{
int b;
int z;
int x, y;
char *s=0;
char *ptr;
char *buff=0;

/* MJA Fix clear to end of line bug */

int tos_size;
int tos_dtype;
void *tos_ptr;
int clr_end_of_line=0;



    /*
  debug("Colors = %d pairs = %d ",COLORS,COLOR_PAIRS);
  debug("CHYYPE_LONG = %d",CHTYPE_LONG);
  */
    debug ("Color pair for attribute=%d", PAIR_NUMBER (a));


 

//debug_print_stack();
  debug ("***************************** popx");
  x = 0;
  y = 0;

  x = pop_int ();
  debug ("x=%d", x);
  debug ("***************************** popy");
  y = pop_int ();
  debug ("y=%d", y);
  debug (">display_at x=%d y=%d attribute %x", x, y, a);
  s=malloc(2);
  s[0]=0;







  get_top_of_stack (1, &tos_dtype, &tos_size, (void **) &tos_ptr);


  debug("TOP1 = %d %d %p\n",tos_dtype%256,tos_size,tos_ptr);

  if (tos_dtype%256==0 && tos_size==0) {
	clr_end_of_line=1;
  }


  debug("Got %d arguments");

  for (z = 0; z <= n - 1; z++)
    {
	ptr=char_pop();
	debug("DISPLAY_AT : '%s'\n",ptr);
	buff=realloc(buff,strlen(s)+strlen(ptr)+1);
	s=realloc(s,strlen(s)+strlen(ptr)+1);
	sprintf(buff,"%s%s",ptr,s);
	strcpy(s,buff);
	debug("s='%s' %p\n",s,s);
    }

  debug ("display_at: Popped  '%s'", s);

  if (x == -1 && y == -1)
    {
      debug ("Line mode display");
      if (isscrmode ())
	{
	  debug ("In screen mode");
	  mja_endwin ();
#ifdef DEBUG
	  {	    debug ("display_at... '%s'", s);	  }
#endif
	  printf ("%s\n", s);
	  fflush (stdout);
#ifdef DEBUG
	  {	    debug ("Printed");	  }
#endif
	  gui_print (a, s);
#ifdef DEBUG
	  {	    debug ("printed it");	  }
#endif
	}
      else
	{
	  gui_print (a, s);
	  printf ("%s\n", s);
	  fflush (stdout);
	  debug ("Linemode display %s\n", s);
	}
    }
  else
    {
      /* WINDOW *win; */
      chkwin ();
      debug ("Screen mode");
      b = xwattr_get (currwin);
	debug("XX4 REVERSE");
      debug ("changed attribute from %x to %x reverse=%x", b, a, A_REVERSE);
      a4glattr_wattrset (window_on_top (), a);
      gui_print (a, s);
      mja_gotoxy (x, y);
	debug("s='%s'",s);

	tui_print ("%s", s);
	if (clr_end_of_line) {
		debug("Clearing line...");
		wclrtoeol(window_on_top());
	}

      debug (">> printed %s", s);

      /* b was got via curses - so we can use the curses version */
      wattrset (window_on_top (), b);
      mja_wrefresh (window_on_top ());
      mja_refresh ();
    }
#ifdef DEBUG
  {    debug ("End of display");  }
#endif
 debug("Free-ing");
	debug("s='%s' %p\n",s,s);
  free (s);
 debug("Freed");
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
display_error (int a,int wait)
{
  char *s;
  debug ("Cr string");
  s = char_pop ();
  debug ("ZZ2 going to print an error : %s", s);
  trim (s);
  debug ("trimmed -> %s", s);
  if (isgui ())
    gui_error (s, geterror_line ());
  else {
	if (wait) error_box (s);
	else error_nobox(s);
  }
  debug ("error_box done");
  acl_free (s);
  status = 0;
}


/**
 *
 * @todo Describe function
 */
void
mja_endwin (void)
{
  set_scrmode('L');
  printf ("\n");
  fflush (stdout);
  endwin ();
}

/**
 *
 * @todo Describe function
 */
int
chkwin (void)
{
  if (env_option_set("NOCURSES")) {       /* FIXME: this is now A4GL_UI=CONSOLE */
	exitwith("NOCURSES Mode has been specified - operation not permitted");
	exit(0);
	return 0;
  }

  if (islinemode ())
    {
      set_scrmode('S');
      mja_refresh ();
    }
  return 1;
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void *
cr_window (char *s,
	   int iswindow,
	   int form_line,
	   int error_line,
	   int prompt_line,
	   int menu_line,
	   int border,
	   int comment_line,
	   int message_line,
	   int attrib)

{
WINDOW *win;
int x, y, w, h;
  w = pop_int ();
  h = pop_int ();
  x = pop_int ();
  y = pop_int ();
  if (has_pointer (s, WINCODE))
    {
#ifdef DEBUG
      {	debug ("Window already exists");      }
#endif
      set_errm (s);
      exitwith ("Window already exists (%s)");
      return 0;
    }
  win = create_window (s, x, y, w, h,
		       iswindow,
		       form_line,
		       error_line,
		       prompt_line,
		       menu_line,
		       border,
		       comment_line,
		       message_line,
		       attrib);

    return win;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
cr_window_form (char *name,
		int iswindow,
		int form_line,
		int error_line,
		int prompt_line,
		int menu_line,
		int border,
		int comment_line,
		int message_line,
		int attrib)
{
  int x, y, w, h
   ;
  char *s;
  char buff[132];
  struct s_form_dets *form;
  WINDOW *win;
  debug ("cr_window_form(%s,%d,%d,%d,%d,%d,%d,%d,%d,%d)\n",
	 name, iswindow, form_line, error_line, prompt_line, menu_line, border, comment_line, message_line, attrib);

if (form_line==0xff) { form_line=std_dbscr.form_line; }
if (menu_line==0xff) { menu_line=std_dbscr.menu_line; }
if (comment_line==0xff) { comment_line=std_dbscr.comment_line; }
if (error_line==0xff) { error_line=std_dbscr.error_line; }
if (prompt_line==0xff) { prompt_line=std_dbscr.prompt_line; }

  s = char_pop ();
  x = pop_int ();
  y = pop_int ();
  strcpy (buff, s);
  trim(buff);
  strcat (buff, acl_getenv ("A4GL_FRM_BASE_EXT"));

  debug ("reading file %s - name=%s", buff,name);
  status = 0;
  form = read_form (buff, name);
  if (status != 0) return 0;

  if (form==0) {
	exitwith("Unable to create form");
	return 0;
	}
  else {
	debug("Created form %p",form);
	}

  scale_form (form->form, &w, &h);

  w = form->fileform->maxcol;
  h = form->fileform->maxline;
  debug ("Scaling on %s gives %d %d border = %d", buff, w, h, border);

  /* ignore error line for now */

  form->form_details.comment_line = comment_line;
  form->form_details.menu_line = menu_line;
  debug ("Setting prompt line to ", prompt_line);
  form->form_details.prompt_line = prompt_line;
  form->form_details.form_line = form_line;
  form->form_details.message_line = message_line;
  debug ("border=%d\n", border);
  form->form_details.border = border;
  form->form_details.colour = attrib;
  add_pointer (name, S_FORMDETSCODE, form);

  win = display_form_new_win (name, form, x, y);
  if (win) {
  	add_pointer (name, WINCODE, win);
  	mja_wrefresh (currwin);
  } else {
	 exitwith("Error displaying form in window");
	}
  acl_free (s);
  return 0;
}



/**
 *
 * @todo Describe function
 */
void
add_compiled_form(char *s,char *frm)
{
	debug("Adding compiled form name='%s' ptr=%p\n",s,frm);
	if (!(has_pointer(s,COMPILED_FORM))) add_pointer(s,COMPILED_FORM,frm);
}



/**
 * 4GL CALL
 * @todo Describe function
 */
int
open_form (char *name)
{
  int w, h;
  char *s;
  char buff[256];
  struct s_form_dets *form;
  s = char_pop ();
  strncpy (buff, s,256);
  buff[255]=0;
  trim (buff);
  strcat (buff, acl_getenv ("A4GL_FRM_BASE_EXT"));
  debug ("reading file %s ?", buff);
  A4GLSQL_set_status (0,0);

  form = read_form (buff, name);
  debug("Read form returns %d status = %d\n",form);
  if (status != 0)
    {
	debug("Some problem opening form...");
      acl_free (s);
      return -1;
    }
  set_default_form (&form->form_details);
  scale_form (form->form, &h, &w);
  /*
  form->w=w; // MJA 2707
  form->h=h; // MJA 2707
  */
  debug ("adding pointer F to %s", name);
  add_pointer (name, S_FORMDETSCODE, form);
  debug("Freeing s");
  acl_free (s);
  debug("Freed - form has been opened");
  return 0;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
close_form (char *formname)
{
	debug("FIXME : close_form not implemented");
}


/**
 * 4GL CALL
 * @todo Describe function
 */
int
disp_form (char *name, int attr)
{
  struct s_form_dets *f;
  WINDOW *w;
  char buff[80];

  debug("attr=%d\n",attr);
  attr=decode_aubit_attr(attr,'w');

  debug("attr=%x\n",attr);

  debug("Disp_form_tui");
  f = (struct s_form_dets *) find_pointer_val (name, S_FORMDETSCODE);
  debug ("Got pointer to form as %p", f);
  if (f == 0)
    {
      exitwith ("The form has not been opened");
      return 0;
    }
  w = display_form (f);
  if (w == 0)
    {
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Error display window");
      }
#endif
      return 0;
    }

  windows[currwinno].form = f;
  sprintf (buff, "currwinno=%d f=%p", currwinno, f);
  /*error_box(buff); */
  mja_wrefresh (currwin);
  gui_dispform (name, getform_line ());
  debug ("Diplay form");
  mja_refresh ();
  return 0;
}




/**
 *
 * @todo Describe function
 */
int
set_window (int a)
{
  current_window (windows[a].name);
/*error_box(windows[a].name); */
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
refresh_menu_window (char *name,int top)
{
  PANEL *ptr;
  int rc;
  char nm[40];
  char s;

  debug ("In refresh_menu_window %s", name);
  print_panel_stack ();
  ptr = find_pointer (name, MNPARCODE);
  find_pointer_ptr (nm, &s, ptr);

  if (nm)
    {
      debug ("Making menus parent window current %s", nm);
      ptr = find_pointer (nm, PANCODE);
      debug ("Parent window=%p", ptr);
      rc = top_panel (ptr);

      debug ("Rc=%d", rc);
    }
  else
    {
      debug ("Not found parent window - %p", ptr);
    }

  debug ("Setting menu (%s) panel to top", name);
  ptr = find_pointer (name, PANCODE);
  debug ("refresh menu with pointer to %p", ptr);
if (top) 
  rc = top_panel (ptr);
else
  rc = bottom_panel (ptr);
  debug ("Rc=%d", rc);
  debug ("Topped");
  update_panels ();
  doupdate ();
  zrefresh ();
  print_panel_stack ();
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
subwin_gotoxy (WINDOW * win, int x, int y)
{
  int a;
  a = wmove (win, y - 1, x - 1);
  if (a == ERR)
    {
      debug ("Failed to move cursor!");
    }
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
subwin_print (WINDOW * win, char *fmt,...)
{
  va_list args;
  chkwin ();
  debug ("subwin_print '%s'", fmt);
  va_start (args, fmt);
  mja_vwprintw (win, fmt, &args); /*  MJAMJAMJA */
  mja_wrefresh (win);
  return 0;
}


/**
 *
 * @todo Describe function
 */
int
subwin_printxy (WINDOW * win, int x, int y, char *fmt,...)
{
  va_list args;
  chkwin ();
  va_start (args, fmt);
  wmove (win, y - 1, x - 1);
  mja_vwprintw (win, fmt, &args);
  mja_wrefresh (win);
  return 0;
}



/**
 *
 * @todo Describe function
 */
int
subwin_setcolor (WINDOW * win, int typ)
{
  WINDOW *currwin;
  long attr;
  currwin = win;
  attr = getbkgd (currwin);
  debug ("Window background = %x", attr);
  if (attr == 0)
    {
      attr = A_NORMAL & ' ';
    }
  debug ("Subwin - setcolor");
  if (has_colors ())
    {
	debug("XX4 REVERSE");
      debug ("Color display - %d current attrib is reverse %d", typ, attr & A_REVERSE);
      switch (typ)
	{
	case NORMAL_TEXT:
	case NORMAL_MENU:
	  wattrset (currwin, attr);

	  break;
	case INVERT_MENU:
	  debug ("Invert...");
	  if (attr & A_REVERSE)
	    {
	debug("XX4 REVERSE");
	      if (((attr) & (colour_code (COLOR_WHITE))) == colour_code (COLOR_WHITE))
		{
		  debug ("Use red %x", colour_code (COLOR_RED));
	debug("XX4 REVERSE");
		  wattrset (currwin, A_REVERSE | colour_code (COLOR_RED));
		}
	      else
		{
		  debug ("Ops - try green instead of red...\n");
	debug("XX4 REVERSE");
		  wattrset (currwin, A_REVERSE + colour_code (COLOR_WHITE));
		}
	    }
	  else
	    {
	      debug ("Off for invert");
	debug("XX4 REVERSE");
	      wattron (currwin, A_REVERSE);
	    }

	  break;
	case TITLE_COL:
	  wattrset (currwin, colour_code (COLOR_WHITE));
	  break;
	case EDIT_FIELD:
	  wattrset (currwin, colour_code (COLOR_WHITE));
	  break;
	}
      currattr = typ;
    }
  else
    {
      switch (typ)
	{
	case ERROR_COL:
	debug("XX4 REVERSE");
	  wattron (currwin, A_REVERSE);
	  break;
	case MESSAGE:
	debug("XX4 REVERSE");
	  wattroff (currwin, A_REVERSE);
	  break;
	case NORMAL_MENU:
	debug("XX4 REVERSE");
	  wattroff (currwin, A_REVERSE);
	  break;
	case INVERT_MENU:
	debug("XX4 REVERSE");
	  wattron (currwin, A_REVERSE);
	  break;
	case TITLE_COL:
	debug("XX4 REVERSE");
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
mja_vwprintw (WINDOW * win, char *fmt,va_list *args)
{
  char buff[256];
  vsprintf (buff, fmt, *args);
  debug ("mja_vwprintw..> '%s' attribute %x", buff, xwattr_get (win));
  if (xwattr_get (win) == 0x20)
    {
      wattrset (win, 0);
    }
  wprintw (win, "%s", buff);
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
init_colour_pairs (void)
{
  
#ifndef WIN32
    debug ("Non WIN32 color scheme");
  init_pair (1, COLOR_BLACK, COLOR_BLACK);
  init_pair (2, COLOR_RED, COLOR_BLACK);
  init_pair (3, COLOR_GREEN, COLOR_BLACK);
  init_pair (4, COLOR_YELLOW, COLOR_BLACK);
  init_pair (5, COLOR_BLUE, COLOR_BLACK);
  init_pair (6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair (7, COLOR_CYAN, COLOR_BLACK);
  init_pair (8, COLOR_WHITE, COLOR_BLACK);
  
#else

    debug ("WIN32 color scheme");
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
mja_wrefresh (WINDOW * w)
{
  if (screen_mode (-1) && w)
    {
      update_panels ();
      doupdate ();
      wrefresh (w);
    }
  gui_wrefresh (w);
}

/**
 *
 * @todo Describe function
 */
void
mja_refresh (void)
{
  if (screen_mode (-1))
    {
      update_panels ();
      doupdate ();
      refresh ();
    }
  gui_refresh ();
}

/**
 *
 * @todo Describe function
 */
void
change_currwin (WINDOW * a, char *s)
{
#ifdef DEBUG
  {    debug ("Changing currwin to %p (%s)", a, s);  }
#endif
  gui_currwin ((long)a);
  currwin = a;

}

/**
 *
 * @todo Describe function
 */
void
change_currwinno (int a, char *s)
{
#ifdef DEBUG
  {    debug ("Changing currwinno to %d (%s)", a, s);  }
#endif
  currwinno = a;
}


/**
 *
 * @todo Describe function
 */
int
top_win (PANEL * p)
{
  int a;
  PANEL *z;
  a = find_win (0);		/* current window top window */

  if (a == -1)
    return 1;
	
	/* a is now the top window */

  z = windows[a].pan;
  change_currwin (panel_window (z), "Marker 3");
  change_currwinno (a, "Marker 4");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
find_win (PANEL * p)
{
  int a;
  if (p == 0)
    return find_win (panel_below (0));
#ifdef DEBUG
  {    debug ("Finding window %p", p);  }
#endif

  for (a = 0; a < MAXWIN; a++)
    {
#ifdef DEBUG
      {	debug ("Checking windows   : %p %p %p", panel_window (windows[a].pan), windows[a].pan, p);      }
#endif

      if ((PANEL *) panel_window (windows[a].pan) == p || (PANEL *) windows[a].pan == p)
	{
	  if (toupper (windows[a].name[0]) == windows[a].name[0])
	    {
#ifdef DEBUG
	      {		debug ("window is a menu - finding parent of %s", windows[a].name);	      }
#endif
	      return find_win (find_pointer (windows[a].name, MNPARCODE));
	    }
	  return a;
	}
    }
  exitwith ("Panel not found....");
  return -1;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
LIBEXPORT void
hide_window (char *winname)
{
  PANEL *p;
  int a;
  p = find_pointer (winname, PANCODE);
#ifdef DEBUG
  {    debug ("hiding window %s %p", winname, p);  }
#endif
  if (p)
    {
      a = hide_panel (p);
#ifdef DEBUG
      {	debug ("a=%d", a);      }
#endif
    }
  do_update_panels ();
  top_win (0);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
LIBEXPORT void
show_window (char *winname)
{
  PANEL *p;
  p = find_pointer (winname, PANCODE);
#ifdef DEBUG
  {    debug ("showing window %s %p", winname, p);  }
#endif
  if (p)
    show_panel (p);
  do_update_panels ();
  top_win (0);
}

/**
 *
 * @todo Describe function
 */
void
do_update_panels (void)
{
  if (screen_mode (-1))
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
getform_line (void)
{
  if (strcmp (windows[currwinno].name, "screen") == 0)
    {
      return decode_line (std_dbscr.form_line);
    }
#ifdef DEBUG
  {    debug ("Use window value of : %d", windows[currwinno].winattr.form_line);  }
#endif
  return decode_line (windows[currwinno].winattr.form_line);
}

/**
 *
 * @todo Describe function
 */
int
getcomment_line (void)
{
  if (windows[currwinno].form == 0)
    {				/* use screen default */
      return decode_line (std_dbscr.comment_line);
    }
  return decode_line (windows[currwinno].form->form_details.comment_line);
}

/**
 *
 * @todo Describe function
 */
int
geterror_line (void)
{
  if (windows[currwinno].form == 0)
    {				/* use screen default */
      return decode_line (std_dbscr.error_line);
    }
  return decode_line (windows[currwinno].form->form_details.error_line);
}


/**
 *
 * @todo Describe function
 */
int
getmessage_line (void)
{
  if (windows[currwinno].form == 0)
    {				/* use screen default */
      return decode_line (std_dbscr.message_line);
    }
  return decode_line (windows[currwinno].form->form_details.message_line);
}


/**
 *
 * @todo Describe function
 */
int
getprompt_line (void)
{
  debug (">> %p ", windows[currwinno].name);
  debug (">> %s ", windows[currwinno].name);
  if (strcmp (windows[currwinno].name, "screen") == 0)
    {
      debug ("...std_dbscr");
      return decode_line (std_dbscr.prompt_line);
    }
  debug ("...windows");
  return decode_line (windows[currwinno].winattr.prompt_line);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
LIBEXPORT int
movewin (char *winname, int absol)
{
  PANEL *p;
  int x, y;
  int r = 0;
  int nx, ny;
  struct s_windows *w;
  x = pop_int ();
  y = pop_int ();
#ifdef DEBUG
  {    debug ("x=%d y=%d winname=%s", x, y, winname);  }
#endif
  w = find_pointer (winname, S_WINDOWSCODE);
#ifdef DEBUG
  {    debug ("w=%p", w);  }
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
	  {	    debug ("Moving absolute to %d %d", y - 1, x - 1);	  }
#endif
	  r = move_panel (p, y - 1, x - 1);
	  nx = x;
	  ny = y;
	}
      else
	{
#ifdef DEBUG
	  {	    debug ("Moving relative by %d %d", y, x);	  }
#endif
	  r = move_panel (p, w->y + y - 1, w->x + x - 1);
	  nx = w->x + x + 1;
	  ny = w->y + y + 1;
	}
      do_update_panels ();
    }
  else
    {
      exitwith ("Window to move was not found");
      return 0;
    }
#ifdef DEBUG
  {    debug ("r=%d", r);  }
#endif

  if (r != 0)
    {
      exitwith ("Couldnt move window");
      return 0;
    }

#ifdef DEBUG
  {    debug ("Old %d %d  new %d %d", x, y, nx, ny);  }
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
find_ptr_debug (void *ptr)
{
  return 0;
}


/**
 *
 * @todo Describe function
 */
void
init_stddbscr (void)
{
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

/**
 *
 * @todo Describe function
 */
WINDOW *
get_currwin (void)
{
  return currwin;
}

/**
 *
 * @todo Describe function
 */
int
iscurrborder (void)
{
  debug ("currwinno=%d", currwinno);
  debug ("Winattr=%p", windows[currwinno].winattr);
  debug ("border=%p", windows[currwinno].winattr.border);
  return windows[currwinno].winattr.border;
}


/**
 *
 * @todo Describe function
 */
void
set_attr_win (char s, int wattr)
{
  set_bkg (currwin, wattr);
}


/**
 *
 * @todo Describe function
 */
void
print_panel_stack (void)
{
  PANEL *ptr;
  debug ("Printing panel stack");
  ptr = panel_below (0);
  while (ptr != 0)
    {
      debug ("Panel : %p (%s)", ptr, panel_userptr (ptr));
      ptr = panel_below (ptr);
    }
}



/**
 *
 * @todo Describe function
 */
char *
windowname_on_top (void)
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
window_on_top (void)
{
  PANEL *ptr;
  const char *s;
  void *winptr;
  ptr = panel_below (0);
  s = panel_userptr (ptr);	/* get name of panel */
  winptr = find_pointer (s, WINCODE);
  return winptr;
}

/**
 *
 * @todo Describe function
 */
int
invert_color (int a)
{
  return 7 - a;
}

/**
 *
 * @todo Describe function
 */
int
xwattr_get (WINDOW * w)
{
    return getattrs(w);
}


/**
 *
 * @todo Describe function
 */
int
screen_width (void)
{
  if (scr_width == -1)
    {
      getmaxyx (stdscr, scr_height, scr_width);
    }
  debug ("screen_width returning %d", scr_width);
  return scr_width;
}

/**
 *
 * @todo Describe function
 */
int
screen_height (void)
{
  if (scr_width == -1)
    {
      getmaxyx (stdscr, scr_height, scr_width);
    }
  debug ("screen_height returning %d", scr_height);
  return scr_height;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
sleep_i(void)
{
int a;
	a=pop_int();
	sleep(a);
}


/* =============================== EOF =============================== */

