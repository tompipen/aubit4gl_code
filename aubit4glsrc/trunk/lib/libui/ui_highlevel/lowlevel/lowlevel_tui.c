// ,int currwinno//static void A4GL_do_pause (void);

#ifdef XCURSES
#include <xcurses.h>
#else
#include <curses.h>
#endif

static int A4GL_curses_to_aubit (int a);
static int A4GL_curses_to_aubit_int (int a);
#include "a4gl_libaubit4gl.h"
#include "a4gl_incl_4gldef.h"
#include "a4gl_API_ui_lib.h"
#include "hl_proto.h"
#include "lowlevel.h"
#include "a4gl_API_lowlevel.h"
#include <ctype.h>

#ifdef XCURSES
extern bool trace_on;
#endif
int scr_mode=0;
void A4GL_LL_ui_exit(void) ;
void A4GL_LL_enable_menu (void);
void A4GL_LL_disable_menu (void);

/*

Curses.h in Aubit tree (taken from Linux) has waddwstr:

#define NCURSES_VERSION_MAJOR 5
#define NCURSES_VERSION_MINOR 2
#define NCURSES_VERSION_PATCH 20001021

 #ifdef _XOPEN_SOURCE_EXTENDED
  extern int waddwstr (WINDOW *, const wchar_t *);	// missing 
  extern int waddnwstr (WINDOW *, const wchar_t *, int);	// missing 
  extern int wadd_wch (WINDOW *, const cchar_t *);	// missing 
  extern int wadd_wchnstr (WINDOW *, const cchar_t *, int);	// missing 
  extern int wadd_wchstr (WINDOW *, const cchar_t *);	// missing 
#endif				// _XOPEN_SOURCE_EXTENDED 

Assuming someone defined _XOPEN_SOURCE_EXTENDED...
(Ignore CVS ID there, it's ID of Aubit CVS)

My curses.h is:

 $Id: lowlevel_tui.c,v 1.92 2006-09-18 08:48:21 mikeaubury Exp $ 
 #define NCURSES_VERSION_MAJOR 5
 #define NCURSES_VERSION_MINOR 3 
 #define NCURSES_VERSION_PATCH 20030802

And has no waddwstr & friends at all...

Used to be there:

http://www.mit.edu/afs/athena/software/cygwin/cygwin_v1.3.2/usr/include/ncurses/curses.h

#define NCURSES_VERSION_MAJOR 5
#define NCURSES_VERSION_MINOR 2
#define NCURSES_VERSION_PATCH 20001021

Looks like it was removed in Curses 5.3???!
*/
//#ifndef WIN32
#if (! defined(__CYGWIN__))
//&& ! defined(__MINGW32__))
#define a4gl_mvwaddwstr mvwaddwstr
#else
#define a4gl_mvwaddwstr(win,y,x,wstr) (wmove(win,y,x) == ERR ? ERR : waddwstr(win,wstr))
#endif


#ifndef NO_CURSES_FORM
#include "aubit_form.h"
#include <form.h>
#else
#include "aubit_noform.h"
#endif


#ifdef XCURSES
#include <xpanel.h>
#else
#include <panel.h>
#endif

#include "formdriver.h"
#ifndef lint
static char const module_id[] =
  "$Id: lowlevel_tui.c,v 1.92 2006-09-18 08:48:21 mikeaubury Exp $";
#endif
int inprompt = 0;
static void A4GL_local_mja_endwin (void);

//static int A4GL_LL_field_opts (void *field);

//
// In order to get around a limitation of C not returning more than one value
// and without using a pointer to each of these values - we're just going to store them
// and return them when requested...
// These will be populated by the start_prompt function, and should be retrieved immediatelty afterwards...
FIELD *last_prompt_field = 0;
FORM *last_prompt_f = 0;
void *last_prompt_win = 0;
long last_prompt_mode = 0;





static int A4GL_mja_get_field_width (void *f);

void *last_construct_drwin = 0;



static void A4GL_default_attributes_in_ll (void *f, int dtype,
					   int has_picture);
void try_to_stop_alternate_view (void);
//int A4GL_has_event (int a, struct aclfgl_event_list *evt);
//int A4GL_has_event_for_keypress (int a, struct aclfgl_event_list *evt);
//int A4GL_has_event_for_field (int cat, char *a, struct aclfgl_event_list *evt);
int A4GL_LL_decode_colour_attr_aubit (int a);
//int A4GL_LL_get_field_width_dynamic (void *f);
int A4GL_LL_fieldnametoid (char *f, char *s, int n);
int A4GL_LL_disp_form_field_ap (int n, int attr, char *s, va_list * ap);
static void A4GL_debug_print_field_opts (FIELD * a);
int chars_normal[6];
int have_default_colors = 0;
//int A4GL_construct_large(char *orig, struct aclfgl_event_list *evt,int init_key,int initpos,char *l,char *r,int curr_width,int curr_height) ;


//-----------------------


void *curr_err_win = 0;

static int
A4GL_fld_opts_on (void *v, int n)
{

  if (A4GL_LL_field_opts (v) & n) return 1;
  A4GL_ll_set_field_opts (v, A4GL_LL_field_opts (v) + n);
  return 1;
}

#ifdef NDEF
static int
A4GL_fld_opts_off (void *v, int n)
{
  if (!(A4GL_LL_field_opts (v) & n)) return 1;
  A4GL_ll_set_field_opts (v, A4GL_LL_field_opts (v) - n);
  return 1;
}
#endif

void
A4GL_LL_beep (void)
{
#ifndef XCURSES
  if (A4GL_isyes (acl_getenv ("FLASHFORBEEP")))
    {
      flash ();
    }
  else
    {
      if (!A4GL_isyes (acl_getenv ("DISABLEBEEP")))
	beep ();
    }
#endif
}



int
A4GL_LL_set_chars_normal (int *n)
{
  n[0] = (ACS_HLINE & 0xff) + AUBIT_ATTR_ALTCHARSET;
  n[1] = (ACS_VLINE & 0xff) + AUBIT_ATTR_ALTCHARSET;
  n[2] = (ACS_ULCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  n[3] = (ACS_URCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  n[4] = (ACS_LLCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  n[5] = (ACS_LRCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  return 1;
}



static int
A4GL_init_colour_pairs (void)
{
  int bkgcolor;
  int colors[8];
  int bkg_def;
  int bkg;
  int fg;
  int fg_def;
  int a;
  colors[0] = atoi (acl_getenv ("COLOR_TUI_BLACK"));
  colors[1] = atoi (acl_getenv ("COLOR_TUI_RED"));
  colors[2] = atoi (acl_getenv ("COLOR_TUI_GREEN"));
  colors[3] = atoi (acl_getenv ("COLOR_TUI_YELLOW"));
  colors[4] = atoi (acl_getenv ("COLOR_TUI_BLUE"));
  colors[5] = atoi (acl_getenv ("COLOR_TUI_MAGENTA"));
  colors[6] = atoi (acl_getenv ("COLOR_TUI_CYAN"));
  colors[7] = atoi (acl_getenv ("COLOR_TUI_WHITE"));

  bkg_def = atoi (acl_getenv ("COLOR_TUI_BKG_DEF"));
  bkg = atoi (acl_getenv ("COLOR_TUI_BKG"));

  fg_def = atoi (acl_getenv ("COLOR_TUI_FG_DEF"));
  fg = atoi (acl_getenv ("COLOR_TUI_FG"));

  for (a = 0; a <= 7; a++)
    {
      A4GL_debug ("Colours : %d %d", a, colors[a]);
    }
  A4GL_debug ("Background if we have defaults : %d", bkg_def);
  A4GL_debug ("Background if we dont have defaults : %d", bkg);
  A4GL_debug ("BLACK : %d %d", colors[0], COLOR_BLACK);
  A4GL_debug ("YELLOW : %d %d", colors[3], COLOR_YELLOW);
  A4GL_debug ("WHITE : %d %d", colors[7], COLOR_WHITE);


  if (have_default_colors)
    {
      bkgcolor = bkg_def;
      fg = fg_def;
    }
  else
    {
      bkgcolor = bkg;
    }

  A4GL_debug ("Colours - BKG=%d\n", bkgcolor);
  init_pair (1, colors[0], bkgcolor);
  init_pair (2, colors[1], bkgcolor);
  init_pair (3, colors[2], bkgcolor);
  init_pair (4, colors[3], bkgcolor);
  init_pair (5, colors[4], bkgcolor);
  init_pair (6, colors[5], bkgcolor);
  init_pair (7, colors[6], bkgcolor);
  init_pair (8, colors[7], bkgcolor);


  A4GL_debug ("Assume default colors : %d %d", bkgcolor, fg);
#ifdef NCURSES_VERSION
  assume_default_colors (fg, bkgcolor);
#endif
  //assume_default_colors(COLOR_WHITE,COLOR_BLACK);

  return 0;
}

/**
 * Convert a curses key to 4gl key.
 *
 * @param The code of the curses key.
 * @return The 4gl code key.
 */
static int
A4GL_curses_to_aubit_int (int a)
{
  int b;
  static int env_cancel = -2;
  static int keycode_home = -1;
  static int keycode_end = -1;


  if (env_cancel == -2)
    {
      char *ptr;
      ptr = acl_getenv ("TUICANCELKEY");
      env_cancel = -1;
      if (ptr)
	{
	  if (strlen (ptr))
	    {
	      env_cancel = atoi (ptr);
	    }
	}
      A4GL_debug ("cancel = %d\n", env_cancel);
    }



  if (keycode_home == -1)
    {
      keycode_home = atoi (acl_getenv ("KEYCODE_HOME"));
    }

  if (keycode_end == -1)
    {
      keycode_end = atoi (acl_getenv ("KEYCODE_END"));
    }

  if (keycode_home == 0 || keycode_home == -1)
    {
      keycode_home = KEY_HOME;
    }
  if (keycode_end == 0 || keycode_end == -1)
    {
      keycode_end = KEY_END;
    }


  if (a == keycode_home)
    return A4GLKEY_HOME;
  if (a == keycode_end)
    return A4GLKEY_END;


  for (b = 0; b < 64; b++)
    {
      if (a == KEY_F (b))
	return A4GLKEY_F (b);
    }

  if (a == KEY_DOWN)
    return A4GLKEY_DOWN;
  if (a == KEY_UP)
    return A4GLKEY_UP;
  if (a == KEY_LEFT)
    return A4GLKEY_LEFT;
  if (a == KEY_RIGHT)
    return A4GLKEY_RIGHT;

  if (a == KEY_ENTER)
    return A4GLKEY_ENTER;
  if (a == 13)
    return A4GLKEY_ENTER;

  //if (a==KEY_PGDN) return A4GLKEY_PGDN;
  //if (a==KEY_PGUP) return A4GLKEY_PGUP;
  //if (a==KEY_INS) return A4GLKEY_INS;
  //if (a==KEY_DEL) return A4GLKEY_DEL;

  if (a == KEY_NPAGE)
    return A4GLKEY_PGDN;
  if (a == KEY_PPAGE)
    return A4GLKEY_PGUP;



  if (a == KEY_HOME)
    return A4GLKEY_HOME;
  if (a == KEY_END)
    return A4GLKEY_END;


  if (a == KEY_CANCEL || (a==env_cancel && env_cancel!=-1) ) {
	        A4GL_set_intr();
	        A4GL_debug("Got Cancel...");
	        return A4GLKEY_CANCEL;
  }




  if (a == KEY_DC)
    return A4GLKEY_DC;
  if (a == KEY_DL)
    return A4GLKEY_DL;
  if (a == KEY_BACKSPACE)
    return A4GLKEY_BACKSPACE;

  return a;
}
/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
static int
A4GL_curses_to_aubit (int a)
{
  int orig_a;
  orig_a = a;
  a = A4GL_curses_to_aubit_int (a);
  //a = A4GL_key_map (a);
  if (a == -1 && orig_a != a)
    {
      int_flag = 1;
    }				// A map to -1 is an interrupt...
  return a;
}



/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_switch_to_line_mode (void)
{
  A4GL_debug ("Switch to line mode");

  A4GL_local_mja_endwin ();

  // A4GL_set_scrmode ('L');
}




/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void *
A4GL_LL_create_window (int h, int w, int y, int x, int border)
{
  WINDOW *win = 0;
  PANEL *pan;
  WINDOW *dswin;


  A4GL_debug (" A4GL_LL_create_window %d %d %d %d %d", h, w, y, x, border);

  if (border == 0)
    {
      A4GL_debug ("newin 0 - %d %d %d %d", h, w, y, x);
      if (x || y || w || h)
	{
	  win = newwin (h, w, y - 1, x - 1);
	  A4GL_debug ("newwin returns %p", win);
	}
      else
	{
	  win = newwin (h, w, y, x);
	  A4GL_debug ("newwin returns %p", win);
	}
    }

  if (border == 1)
    {
      A4GL_debug ("border=1");
      win = newwin (h + 2, w + 2, y - 2, x - 2);
      A4GL_debug ("newwin returns %p", win);
    }

  if (border == 2)
    {
      A4GL_debug ("border=2");
      dswin = newwin (h + 4, w + 4, y - 2, x - 2);
      A4GL_debug ("newwin returns %p", win);
      win = newwin (h + 2, w + 2, y - 2, x - 2);
      A4GL_debug ("newwin returns %p", win);
      A4GL_LL_set_bkg (dswin, '+');
      A4GL_debug ("XX3 REVERSE");
      wbkgdset (dswin, COLOR_RED | A_REVERSE);
    }

  if (border == 3)
    {
      A4GL_debug ("border=3");
      dswin = newwin (h + 4, w + 4, y - 1, x - 1);
      A4GL_debug ("newwin returns %p", win);
      win = newwin (h, w, y - 2, x - 2);
      A4GL_debug ("newwin returns %p", win);
      A4GL_debug ("XX4 REVERSE");
      wbkgdset (dswin, COLOR_RED | A_REVERSE);
    }

  A4GL_debug ("win=%p", win);
  if (win == 0)
    return 0;
  if (border)
    {
      //wbkgdset (win, attrib);
      //A4GL_debug ("Adding border %x", attrib);

      //A4GL_LL_set_bkg (win, attrib);

      if (A4GL_isyes (acl_getenv ("SIMPLE_GRAPHICS")))
	{
	  wborder (win, '|', '|', '-', '-', '+', '+', '+', '+');
	}
      else
	{
	  wborder (win, 0, 0, 0, 0, 0, 0, 0, 0);
	}
    }
  pan = new_panel (win);
  A4GL_debug ("new_panel pan=%p", pan);
  keypad (win, TRUE);
  top_panel (pan);
  A4GL_debug ("su");
  A4GL_LL_screen_update ();
  return pan;
}



/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_remove_window (void *x)
{
  WINDOW *w;
  A4GL_debug ("remove window... del_panel : %p", x);
  w = panel_window (x);
  A4GL_debug ("w=%p", w);
  del_panel (x);
  A4GL_debug ("Deleted panel %p\n", x);
  delwin (w);
  A4GL_debug ("delwin %p", w);
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_wadd_char_xy_col (void *win, int x, int y, int ch, int curr_width,
			  int curr_height, int iscurrborder, int currwinno)
{
  int ch2;
  int attr;
  void *p;

  attr = ch & 0xffffff00;
  //A4GL_debug("attr before=%x",attr);
  attr = A4GL_LL_decode_aubit_attr (attr, 'w');
  //A4GL_debug("attr after=%x",attr);

  ch2 = ch & 0xff;
  //A4GL_debug ("x=%d y=%d ch2=%c", x, y, ch2);
  p = panel_window (win);
  if (!iscurrborder || currwinno == 0)
    {
      x--;
      y--;
    }
  if (x < 0 || y < 0 || x > curr_width || y > curr_height);
  else
    {
      if (ch2 == 0)
	ch2 = '*';
      //A4GL_debug("waddch  p=%p y=%d x=%d ch=%x ATTR=%x CH=%x",p,y,x,ch,attr,ch2);
      mvwaddch (p, y, x, attr | ch2);
    }
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_wadd_char_xy_col_w (void *win, int x, int y, int ch, int curr_width,
			    int curr_height, int iscurrborder, int currwinno)
{
  int ch2;
  int attr;
  void *p;
//A4GL_debug("A4GL_LL_wadd_char_xy_col_w called");
  attr = A4GL_LL_decode_aubit_attr (ch & 0xffffff00, 'w');
  ch2 = ch & 0xff;
  //A4GL_debug ("x=%d y=%d ch2=%c", x, y, ch2);
  p = win;
  if (!iscurrborder || currwinno == 0)
    {
      x--;
      y--;
    }
  if (x < 0 || y < 0 || x > curr_width || y > curr_height)
    {
      A4GL_debug ("Out of range:%d,%d curr_width=%d curr_height=%d", x, y,curr_width,curr_height);
    }
  else
    {
      if (ch2 == 0)
	ch2 = '*';
      //A4GL_debug("----> waddch  %p %d %d %x ATTR=%x CH=%d",p,y,x,ch,attr,ch2);
      mvwaddch (p, y, x, attr + ch2);
    }
  //wrefresh(p);
}



/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_screen_update (void)
{
  A4GL_debug ("CURSES : update");
// Update the physical screen
  if (A4GL_LL_pause_mode (-1))
    {
      update_panels ();
      doupdate ();
    }
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_screen_redraw (void)
{
// Blank the screen and redraw from scratch
  A4GL_debug ("CURSES : refresh");
  clearok (curscr, 1);
  A4GL_LL_screen_update ();
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_colour_code (int a)
{
  int z;
  static int ismono = -1;
  static int isclassic = -1;
  z = 1;
  if (ismono == -1)
    {
      ismono = A4GL_isyes (acl_getenv ("MONO"));
    }


  if (!has_colors () || ismono)
    {
      A4GL_debug ("MJA - STANDOUT");
      if (a == 7)
	return 0;
      if (a == 0)
	return 0;
      //z = A_STANDOUT;
      //for (b = 0; b <= a; b++)
      //{
      //z *= 2;
      //}
      if (isclassic == -1)
	{
	  isclassic = A4GL_isyes (acl_getenv ("CLASSIC_I4GL_MONO"));
	}
      if (!isclassic)
	{
	  if (a == 1)
	    z = A_BOLD;		// RED
	  if (a == 2)
	    z = A_DIM;		// GREEN
	  if (a == 3)
	    z = A_BOLD;		// YELLOW
	  if (a == 4)
	    z = A_DIM;		// BLUE
	  if (a == 5)
	    z = A_BOLD;		// MAGENTA
	  if (a == 6)
	    z = A_DIM;		// CYAN
	}
      else
	{
	  z = 0;
	}
      A4GL_debug ("colour code for mono for %d = %d", a, z);


      return z;
    }
  //A4GL_debug ("MJA Returning color code (%d+1)\n", a);
  if (a == 0)
    return 0;
  a = COLOR_PAIR (a + 1);
  //A4GL_debug ("MJA Returning color code = %d\n", a);
  return a;
}



/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void *
A4GL_LL_display_form (void *vf, int attrib, int curr_width, int curr_height,
		      int iscurrborder, int currwinno, int form_line,
		      void *currwin, void *f_form, int maxline, int maxcol)
{
  int rows, cols;
  char buff[80];
  int a;
  int nattr;

  //int informix_behaviour = 1;
  PANEL *w;
  WINDOW *drwin;
  /*  FIELD **p; */

  int fl;
  //f=vf;

  //A4GL_chkwin ();
  A4GL_debug ("In display_form");
  w = (PANEL *) currwin;	// A4GL_get_currwin ();

  sprintf (buff, "%p", vf);

  if (w == 0)
    {
      A4GL_LL_error_box ("NO WINDOW", 0);
    }
  
  fl = form_line;
  for (a = fl; a <= curr_height; a++)
    {
      if (iscurrborder)
	{
		char buff[2000];
		memset(buff,' ',curr_width);
		buff[curr_width]=0;

	  A4GL_wprintw (currwin, 0, 1, a + 1, curr_width, curr_height, iscurrborder, currwinno, buff);
	  //A4GL_display_internal (1, a + 1, " ", 0, 1);
	}
      else
	{
		char buff[2000];
		memset(buff,' ',curr_width);
		buff[curr_width]=0;
	  A4GL_wprintw (currwin, 0, 1, a, curr_width, curr_height,
			iscurrborder, currwinno, buff);
	  //A4GL_display_internal (1, a, " ", 0, 1);
	}
    }
  A4GL_form_scale_form (f_form, &rows, &cols);
  rows = maxline;
  cols = maxcol;

  A4GL_debug ("Form line=%d", fl);
  A4GL_debug ("Scale form returns %d %d", rows, cols);

  if (iscurrborder)
    {
      rows++;
    }
  else
    {
    }

  if (rows - iscurrborder > curr_width + 1)
    {
      A4GL_exitwith ("Window is too small to display this form (too high)");
      return 0;
    }
  if (cols - iscurrborder > curr_width + 1)
    {
      A4GL_exitwith ("Window is too small to display this form (too wide)");
      return 0;
    }


  //f->form_details.border = iscurrborder ;

  if (iscurrborder)
    {
      A4GL_debug ("Form details returns it has border");
    }
  else
    {
      A4GL_debug ("Form details returns it has *NO* border");
    }

  if (iscurrborder)
    {
      A4GL_debug ("Window details returns it has border");
    }
  else
    {
      A4GL_debug ("Window details returns it has *NO* border ");
    }
  A4GL_debug ("derwin - %d rows %d cols form line=%d", rows, cols, fl);

  if (iscurrborder)
    {
      drwin = derwin (panel_window ((PANEL *) w), rows, cols, fl + 1, 1);
    }
  else
    {
      A4GL_debug ("MJAPASS2 rows=%d cols=%d fl=%d", rows, cols, fl);
      drwin = derwin (panel_window ((PANEL *) w), rows, cols, fl - 1, 0);

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



  werase (drwin);
  a = A4GL_form_set_form_sub (f_form, drwin);


  if (a == E_POSTED)
    {
      WINDOW *olddrwin;
      A4GL_debug ("Deleteing old subwin");
      olddrwin = A4GL_form_form_sub (f_form);
      if (olddrwin)
	{
	  A4GL_debug ("delwin %p", olddrwin);
	  delwin (olddrwin);
	}
      A4GL_form_unpost_form (f_form);
      a = A4GL_form_set_form_sub (f_form, drwin);
    }

  a = A4GL_form_set_form_win (f_form, panel_window (w));
  if (a == E_POSTED)
    {
      A4GL_exitwith ("That shouldn't be posted by now...");
      exit (33);
    }


  A4GL_debug ("setup windows");
  keypad (panel_window ((PANEL *) w), TRUE);

  if (f_form == 0)
    {
      A4GL_exitwith ("Unable to create form");
      return 0;
    }

  a = A4GL_form_post_form (f_form);

  if (a == E_POSTED)
    {
      A4GL_debug ("Form posted already - dumping and re-doing");
      A4GL_form_unpost_form (f_form);
      a = A4GL_form_post_form (f_form);
      A4GL_debug ("Form was already posted - status now : %d", a);
    }

  if (iscurrborder)
    {
      A4GL_debug ("Form has border");
      if (A4GL_isyes (acl_getenv ("SIMPLE_GRAPHICS")))
	{
	  wborder (panel_window ((PANEL *) w), '|', '|', '-', '-', '+', '+',
		   '+', '+');
	}
      else
	{
	  wborder (panel_window ((PANEL *) w), 0, 0, 0, 0, 0, 0, 0, 0);
	}
    }


  A4GL_debug ("start the form");
  A4GL_start_form (f_form);

  if ((attrib & 0xff) == 0 || (attrib & 0xff) == 0xff)
    {
      attrib = attrib + ' ';
      A4GL_debug ("Set pad char to space");
    }
  A4GL_debug ("Setting attribute for form to 0x%x \n", attrib);

  nattr = A4GL_LL_decode_aubit_attr (attrib, 'w');
  wbkgd (drwin, nattr);
  wbkgdset (drwin, nattr);



  //A4GL_clr_form (0);
  //A4GL_LL_screen_update ();

  return w;
}




/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_out_linemode (char *s)
{
  PRINTF ("%s\n", s);
  fflush(stdout);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_sleep (int n)
{
  sleep (n);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_make_window_top (void *w)
{
  top_panel (w);
}

int scr_width = -1;
int scr_height = -1;

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_screen_width (void)
{
  if (scr_width == -1)
    {

      A4GL_debug ("Getting values");
      getmaxyx (stdscr, scr_height, scr_width);
      A4GL_debug ("%d %d\n", scr_height, scr_width);
      if (atoi (acl_getenv ("COLUMNS")))
	{
	  A4GL_debug ("Got COLUMNS ");
	  scr_width = atoi (acl_getenv ("COLUMNS"));
	  scr_height = atoi (acl_getenv ("LINES"));
	  A4GL_debug ("Got COLUMNS (%s %s)", acl_getenv ("COLUMNS"),
		      acl_getenv ("LINES"));
	}
    }
  A4GL_debug ("screen_width returning %d", scr_width);
  return scr_width;
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_screen_height (void)
{
  if (scr_width == -1)
    {
      A4GL_debug ("Getting values");
      getmaxyx (stdscr, scr_height, scr_width);
      A4GL_debug ("%d %d\n", scr_height, scr_width);

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
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_set_bkg (void *win, int attr)
{
  int nattr;
  nattr = A4GL_LL_decode_aubit_attr (attr, 'w');
  A4GL_debug ("A4GL_LL_set_bkg %p %x", panel_window (win), nattr);
  wbkgd (panel_window (win), nattr);
  wbkgdset (panel_window (win), nattr);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_decode_aubit_attr (int a, char s)
{
  char colour[20];
  char attr[256];
  int ca;			/* Curses attribute */
  static int noinvis = -1;

  A4GL_get_strings_from_attr (a, colour, attr);

  //A4GL_debug ("A=%d colour=%s attr=%s MJAMJAMJA", a, colour, attr);

  ca = A_NORMAL;
  if (s == 'w')
    {
      ca = A4GL_LL_decode_colour_attr_aubit (a);

      if (strstr (attr, "INVISIBLE"))
	ca += A_INVIS;

      if (strstr (attr, "NORMAL"))
	ca += A_NORMAL;
      if (strstr (attr, "REVERSE"))
	ca += A_REVERSE;
      if (strstr (attr, "UNDERLINE"))
	ca += A_UNDERLINE;
      if (strstr (attr, "BOLD"))
	ca += A_BOLD;
      if (strstr (attr, "BLINK"))
	ca += A_BLINK;
      if (strstr (attr, "DIM"))
	ca += A_DIM;
      if (strstr (attr, "ALT"))
	ca += A_ALTCHARSET;

    }
  if (s == 'f')
    {
      ca = A4GL_LL_decode_colour_attr_aubit (a);

      if (strstr (attr, "INVISIBLE"))
	ca += A_INVIS;

      if (strstr (attr, "NORMAL"))
	ca += A_NORMAL;
      if (strstr (attr, "REVERSE"))
	ca += A_REVERSE;
      if (strstr (attr, "UNDERLINE"))
	ca += A_UNDERLINE;
      if (strstr (attr, "BOLD"))
	ca += A_BOLD;
      if (strstr (attr, "BLINK"))
	ca += A_BLINK;
      if (strstr (attr, "DIM"))
	ca += A_DIM;
    }

  if (s == 'b')
    {
      ca = A4GL_LL_decode_colour_attr_aubit (a);
    }

  if (s == 'B')
    {
      ca = A4GL_LL_decode_colour_attr_aubit (a);
      if (strstr (attr, "REVERSE"))
	ca += A_REVERSE;
      if (strstr (attr, "INVISIBLE"))
	ca += A_INVIS;
      if (strstr (attr, "UNDERLINE"))
	ca += A_UNDERLINE;
    }
//A4GL_debug("Returning ca = %d %x (visible=%d)",ca,ca,!(ca&A_INVIS));
  if (noinvis == -1)
    {
      noinvis = A4GL_isyes (acl_getenv ("NO_INVIS_ATTR"));
    }
  if (noinvis)
    {
      if (ca & A_INVIS)
	ca -= A_INVIS;
    }

  return ca;
}



/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_decode_colour_attr_aubit (int a)
{
  char colour[20];
  char attr[256];
//int col;
  //A4GL_debug ("MJA Decoding %d",a);
  A4GL_get_strings_from_attr (a, colour, attr);

  //A4GL_debug ("MJA Got colour as : %s - %s", colour,attr);
  A4GL_trim (colour);

  if (strlen (colour) == 0)
    {
      A4GL_debug ("No colour..");
      return A4GL_LL_colour_code (COLOR_WHITE);
    }

  if (strcmp (colour, "BLACK") == 0)
    return A4GL_LL_colour_code (COLOR_BLACK);
  if (strcmp (colour, "RED") == 0)
    return A4GL_LL_colour_code (COLOR_RED);
  if (strcmp (colour, "GREEN") == 0)
    return A4GL_LL_colour_code (COLOR_GREEN);
  if (strcmp (colour, "YELLOW") == 0)
    return A4GL_LL_colour_code (COLOR_YELLOW);
  if (strcmp (colour, "BLUE") == 0)
    return A4GL_LL_colour_code (COLOR_BLUE);
  if (strcmp (colour, "MAGENTA") == 0)
    return A4GL_LL_colour_code (COLOR_MAGENTA);
  if (strcmp (colour, "CYAN") == 0)
    return A4GL_LL_colour_code (COLOR_CYAN);
  if (strcmp (colour, "WHITE") == 0)
    {
      A4GL_debug ("Its white.. %d", A4GL_LL_colour_code (COLOR_WHITE));
      return A4GL_LL_colour_code (COLOR_WHITE);
    }

  A4GL_debug ("No match for colour...");

  return 0;

}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void *
A4GL_LL_make_field (int frow, int fcol, int rows, int cols, char *widget,
		    char *config, char *incl, void *id,char *tab_and_col,char* action)
{
  FIELD *f;
  A4GL_debug ("Creating new field entry y=%d x=%d rows=%d width=%d\n", frow,
	      fcol, rows, cols);
  A4GL_debug ("Creating new field entry y=%d x=%d rows=%d width=%d\n", frow,
	      fcol, rows, cols);

  f = A4GL_form_new_field (rows, cols, frow, fcol, 0, 0);

  if (f)
    {
      //A4GL_gui_mkfield (rows, cols, frow, fcol, f);
      A4GL_debug ("Field created - setting attributes");
      /*A4GL_set_field_attr (f); */
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_off (f, O_ACTIVE);
      A4GL_form_field_opts_off (f, O_EDIT);
      A4GL_form_field_opts_off (f, O_BLANK);
      A4GL_debug ("STATIC ON");
      A4GL_form_field_opts_off (f, O_STATIC);
    }
  else
    {
      A4GL_exitwith ("Unable to create field");
      return 0;
    }

  return (f);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void *
A4GL_LL_make_label (int frow, int fcol, char *label)
{
  FIELD *f;
  int l;
  int is_graphics = 0;
  l = strlen (label);
  A4GL_debug ("A4GL_make_label : '%s'", label);

  if (l == 2 && label[0] == '\n')
    {
      A4GL_debug ("Making graphic character %c @ frow=%d fcol=%d\n", label[1],
		  frow, fcol);
      f = A4GL_form_new_field (1, 1, frow, fcol, 0, 0);
    }
  else
    {
      A4GL_debug ("Making normal label '%s' @ frow=%d fcol=%d\n", label, frow,
		  fcol);
      f = A4GL_form_new_field (1, l, frow, fcol, 0, 0);
    }

  if (f == 0)
    {
      A4GL_exitwith ("Unable to create field");
      return 0;
    }

  if (l == 2 && label[0] == '\n')
    {
      is_graphics = 1;

      if (A4GL_isyes (acl_getenv ("SIMPLE_GRAPHICS")))
	{
	  switch (label[1])
	    {
	    case 'p':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '+');
	      break;
	    case 'q':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '+');
	      break;
	    case 'b':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '+');
	      break;
	    case 'd':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '+');
	      break;
	    case '-':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '-');
	      break;
	    case '|':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '|');
	      break;
	    default:
	      A4GL_debug ("Unknown graphic : %c", label[1]);
	      is_graphics = 0;
	    }
	}
      else
	{
	  if (A4GL_isno (acl_getenv ("EXTENDED_GRAPHICS")))
	    {
	      A4GL_form_set_field_back (f, A_ALTCHARSET);
	      switch (label[1])
		{
		case 'p':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_ULCORNER);
		  break;
		case 'q':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_URCORNER);
		  break;
		case 'b':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LLCORNER);
		  break;
		case 'd':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LRCORNER);
		  break;
		case '-':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_HLINE);
		  break;
		case '|':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_VLINE);
		  break;
		default:
		  A4GL_debug ("Unknown graphic : %c", label[1]);
		  is_graphics = 0;
		}
	    }
	  else
	    {
	      A4GL_form_set_field_back (f, A_ALTCHARSET);
	      A4GL_debug ("Extended graphics : %c ACS_HLINE=%d", label[1],
			  ACS_HLINE);
	      switch (label[1])
		{
		case 'p':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_ULCORNER);
		  break;
		case 'q':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_URCORNER);
		  break;
		case 'b':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LLCORNER);
		  break;
		case 'd':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LRCORNER);
		  break;
		case '-':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_HLINE);
		  break;
		case '|':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_VLINE);
		  break;

		case '>':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LTEE);
		  break;
		case '<':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_RTEE);
		  break;
		case '^':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_BTEE);
		  break;
		case 'v':
		case 'V':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_TTEE);
		  break;
		case '+':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_PLUS);
		  break;
		default:
		  A4GL_debug ("Unknown graphic : %c", label[1]);
		  is_graphics = 0;
		}
	    }
	}
      if (is_graphics)
	{
	  A4GL_ll_set_field_opts (f, A4GL_form_field_opts (f) & ~O_ACTIVE);
	  A4GL_debug ("SET FIELD OPTS : STATIC %x ", A4GL_form_field_opts (f) & O_STATIC);
	  return f;
	}
      else
	{
	  label[0] = label[1];
	  label[1] = label[0];
	}
    }


  //A4GL_gui_mklabel (1, strlen (label), frow, fcol, label);

  if (f)
    {
      A4GL_debug ("99 set field buffer to label = **%s**", label);
      A4GL_form_set_field_buffer (f, 0, label);
      A4GL_ll_set_field_opts (f, A4GL_form_field_opts (f) & ~O_ACTIVE);
      A4GL_debug ("SET FIELD OPTS : STATIC %x ", A4GL_form_field_opts (f) & O_STATIC);
    }
  else
    {
#ifdef DEBUG
      {
	A4GL_debug ("FIeld not created!!!");
      }
#endif
    }
  return (f);
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_set_new_page (void *field, int n)
{
  return A4GL_form_set_new_page (field, n);
}


#ifdef REMOVED
/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_set_field_userptr (void *field, void *ptr)
{
  A4GL_form_set_field_userptr (field, ptr);
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void *
A4GL_LL_get_field_userptr (void *field)
{
  return A4GL_form_field_userptr (field);
}
#endif

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
long
A4GL_LL_set_field_attr (void *field, int dtype, int dynamic, int autonext,
			int invis, int reqd, int compress, int has_picture)
{
  //struct struct_scr_field *f;
  int bc;
  int fc;
  bc = A4GL_form_field_back (field);
  fc = A4GL_form_field_fore (field);

  A4GL_debug ("In set_field_attr");
  //f = (struct struct_scr_field *) (A4GL_form_field_userptr (field));
  //if (f == 0) return;


  A4GL_debug ("Setting defs");
  A4GL_default_attributes_in_ll (field, dtype, has_picture);
  A4GL_debug ("Set defs");

  if (autonext)
    {
      A4GL_debug ("Autoskip");
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_on (field, O_AUTOSKIP);
    }

  if (invis)
    {
      A4GL_debug ("Invisible ***");
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_off (field, O_PUBLIC);
    }

  if (dynamic != 0)
    {
      A4GL_debug ("ZZZZ - SET OPTS STATIC OFF");
      A4GL_form_field_opts_off (field, O_STATIC);

      if (dynamic == -1)
	{
	  A4GL_debug ("Max size is lots CARAT");
	  A4GL_form_set_max_field (field, 0);
	}
      else
	{
	  A4GL_debug ("set max field : %d\n", dynamic);
	  A4GL_form_set_max_field (field, dynamic);
	  A4GL_debug ("Max size=%d CARAT", dynamic);
	}

    }
  else
    {
      A4GL_form_field_opts_off (field, O_STATIC);
      A4GL_form_set_max_field (field, A4GL_mja_get_field_width (field));
    }

  if (reqd)
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_off (field, O_NULLOK);
    }
  else
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_on (field, O_NULLOK);
    }

  if (compress)
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_on (field, O_WRAP);
    }

  return A4GL_form_field_opts(field);
}




/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void *
A4GL_LL_new_form (list_of_fields * flist)
{
  FIELD **flds;
  void *frm;
  int a;
  flds = acl_malloc2 ((flist->a.a_len + 1) * sizeof (FIELD *));
  for (a = 0; a < flist->a.a_len; a++)
    {
      flds[a] = (FIELD *) flist->a.a_val[a];
    }
  flds[flist->a.a_len] = 0;
  frm = A4GL_form_new_form (flds);
  //free(flds); //@fixme - memory leak...
  return frm;
}

#ifdef REMOVED
/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_set_form_userptr (void *form, void *data)
{
  A4GL_form_set_form_userptr (form, data);
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void *
A4GL_LL_get_form_userptr (void *form)
{
  return A4GL_form_form_userptr (form);
}
#endif



/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
char *
A4GL_LL_field_buffer (void *field, int n)
{
  return A4GL_form_field_buffer (field, n);
}


void
A4GL_LL_set_field_buffer (void *field, int n, char *str)
{
  int a;
  A4GL_debug ("LL_set_field_buffer : '%s' from ", str,A4GL_form_field_buffer (field, n));

  a = A4GL_form_set_field_buffer (field, n, str);
  A4GL_debug ("set_field_buffer : %s returns %d field buffer=%s opts=%x", str, a, A4GL_form_field_buffer (field, n), A4GL_form_field_opts (field));
  A4GL_debug_print_field_opts (field);

}



/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int A4GL_LL_field_opts (void *field)
{
  return A4GL_form_field_opts (field);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_set_field_opts (void *field, int oopt)
{
	int a;
  A4GL_debug ("SET FIELD OPTS : %x ", oopt);
  a=A4GL_form_set_field_opts (field, oopt);
  A4GL_debug_print_field_opts (field);
  if (A4GL_form_field_opts(field)!=oopt) {
	  a=A4GL_form_field_opts(field);
	  A4GL_debug("Couldn't set field opts a=%d",a);
	  return a;
  }
	  A4GL_debug("set field opts a=%d",oopt);
  return oopt;
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_set_field_fore (void *field, int attr)
{
  A4GL_form_set_field_fore (field, attr);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_set_field_back (void *field, int attr)
{
  A4GL_form_set_field_back (field, attr);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_set_current_field (void *form, void *field)
{
	int a;
  a=A4GL_form_set_current_field (form, field);
  if (a!=E_OK) {
	  A4GL_debug("UUU FAILED %p %p",form,field);
	  A4GL_debug_print_field_opts(field);
	  if (A4GL_form_field_opts(field)&O_ACTIVE) ;
	  else {
		  A4GL_assertion(1,"Want to make current an inactive field");
		  //A4GL_pause_execution();
		  A4GL_debug("FIELD ISNT ACTIVE!");
	  }
  } else {
	  A4GL_debug("UUU PASSED %p %p",form,field);
	  A4GL_debug_print_field_opts(field);
  }
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_set_carat (void *form)
{
//PANEL *w;
  A4GL_form_pos_form_cursor (form);
  A4GL_debug ("CURSES : set_carat");


  A4GL_LL_screen_update ();

}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_getch_swin (void *window_ptr,char *why)
{
  int a;
  static int no_delay=-1;

  A4GL_debug ("Reading from keyboard on window %p", window_ptr);

  //A4GL_set_abort (0);

  //a = A4GL_readkey ();
  //if (a != 0)
  //{
  //A4GL_debug ("Read %d from keyfile", a);
  //return a;
  //}

  while (1)
    {

#ifndef XCURSES

      // Half delay seems to mess up pdcurses (at least under X)
      if (no_delay==-1) {
      	no_delay=(A4GL_isno(acl_getenv("HALFDELAY")));
      }
#else
	no_delay=1;
#endif
      if (!no_delay) {
      	halfdelay (10);
      }
      //a = wgetch (window_ptr);
      abort_pressed = 0;
      a = getch ();

#ifdef __MINGW32__
      // ^c
      if (a == 3)
	abort_pressed = 1;
#endif

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


      if (a==-1) {
  		cbreak ();
	      return 0;
      }
      if (a != -1)
	{
	  A4GL_debug ("MJAC Key Pressed %d", a);
	  break;
	} 
	

    }
  cbreak ();
  a = A4GL_curses_to_aubit (a);	// Convert it to an aubit key...
  //A4GL_chk_for_screen_print (a);
  //A4GL_logkey (a);
  A4GL_debug ("Got char from keyboard : %d F2=%d LEFT=%d 4GL for f5 = %d", a,
	      KEY_F (2), KEY_LEFT, A4GLKEY_F (5));
  return a;
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_get_carat (void *form)
{
  FORM *mform;
  mform = form;
  A4GL_debug ("get CARAT : %d in %p", mform->curcol,
	      A4GL_form_current_field (mform));
  return mform->curcol;
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_int_form_driver (void *mform, int mode)
{
  int a;
  int nmode;

  if (mode >= 0x6000)
    {
      A4GL_debug ("FX1 Should be called with AUBIT_REQ not REQ %x\n", mode);
      //A4GL_pause_execution ();
    }

  nmode = -1;

  switch (mode)
    {
    case AUBIT_REQ_BEG_FIELD:
      nmode = REQ_BEG_FIELD;
      break;
    case AUBIT_REQ_END_FIELD:
      nmode = REQ_END_FIELD;
      break;
    case AUBIT_REQ_CLR_EOF:
      nmode = REQ_CLR_EOF;
      break;
    case AUBIT_REQ_CLR_FIELD:
      nmode = REQ_CLR_FIELD;
      break;
    case AUBIT_REQ_DEL_CHAR:
      nmode = REQ_DEL_CHAR;
      break;
    case AUBIT_REQ_DEL_PREV:
      nmode = REQ_DEL_PREV;
      break;
    case AUBIT_REQ_FIRST_FIELD:
      nmode = REQ_FIRST_FIELD;
      break;
    case AUBIT_REQ_FIRST_PAGE:
      nmode = REQ_FIRST_PAGE;
      break;
    case AUBIT_REQ_INS_MODE:
      nmode = REQ_INS_MODE;
      break;
    case AUBIT_REQ_NEXT_CHAR:
      nmode = REQ_NEXT_CHAR;
      break;
    case AUBIT_REQ_OVL_MODE:
      nmode = REQ_OVL_MODE;
      break;
    case AUBIT_REQ_PREV_CHAR:
      nmode = REQ_PREV_CHAR;
      break;
    case AUBIT_REQ_VALIDATION:
      nmode = REQ_VALIDATION;
      break;
    default:
      nmode = mode;
    }
  if (mode == -1)
    return 0;
  a = A4GL_form_form_driver (mform, nmode);
  A4GL_debug ("int_form_Driver %p %x = %d", mform, nmode, a);
  return a;
  //return 1;
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void *
A4GL_LL_current_field (void *form)
{
  return A4GL_form_current_field (form);
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_set_form_page (void *form, int page)
{
  A4GL_form_set_form_page (form, page);
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_form_page (void *form)
{
  return A4GL_form_form_page (form);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void *
A4GL_LL_create_errorwindow (int h, int w, int y, int x, int attr, char *str)
{
  WINDOW *win;
  PANEL *p;
  char buff[255];
  if (str==0) return 0;
  if (strlen(str)==0) return 0;
  A4GL_debug ("Creating errorwindow h=%d w=%d y=%d x=%d attr=%d str=%s", h, w,
	      y, x, attr, str);
  win = newwin (h, w, y, x);
  A4GL_debug ("win=%p", win);
  p = new_panel (win);
  A4GL_debug ("new_panel p=%p", p);
  if (attr == 0 || attr == -1)
    attr = A_REVERSE;		//+A4GL_colour_code (COLOR_RED);
  else
    attr = A4GL_LL_decode_aubit_attr (attr, 'w');
  wattrset (win, attr);
  wprintw (win, "%s", str);

  strcpy (buff, str);
  A4GL_trim (buff);

  if (strlen (buff))
    {
      A4GL_LL_beep ();
    }

  curr_err_win = p;

  return p;
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_delete_errorwindow (void *curr_error_window)
{
  if (curr_err_win)
    {
      A4GL_LL_remove_window (curr_error_window);
    }
  curr_err_win = 0;
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_field_status (void *field)
{
  return A4GL_form_field_status (field);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
int
A4GL_LL_dump_screen (int n, char *ptr, int mode)
{
  FILE *f;
  int sh;
  int sw;
  int x, y;
  int attr;
  //char *ptr = 0;
  WINDOW *w;
  //int mode = 1;
  char *buff;
//  int is_line_drawing;


#ifdef DEBUG
  A4GL_debug ("Begin dump screen");
#endif

  //w=find_pointer ("screen", WINCODE);
  w = curscr;
/*
	if (n == 1) { ptr = A4GL_char_pop (); }

	if (n == 2) {
		mode = A4GL_pop_int ();
		ptr = A4GL_char_pop ();
    }
*/

  if (n != 0)
    {
      A4GL_trim (ptr);
    }


  if (mode == 3)
    {
#if (! defined(__MINGW32__) && ! defined (XCURSES))
      scr_dump (ptr);
      return 0;
#else
      A4GL_debug
	("scr_dump not implemented in PDcurses/Xcurses - try mode=1 instead");
      mode = 1;
#endif
      return 0;

    }

  sh = A4GL_LL_screen_height ();
  sw = A4GL_LL_screen_width ();

  if (A4GL_aubit_strcasecmp (acl_getenv ("TRIMDUMP"), "24x80") == 0)
    {
      if (sh > 24)
	sh = 24;
      if (sw > 80)
	sw = 80;
    }
  if (A4GL_aubit_strcasecmp (acl_getenv ("TRIMDUMP"), "25x80") == 0)
    {
      if (sh > 24)
	sh = 25;
      if (sw > 80)
	sw = 80;
    }
  if (A4GL_aubit_strcasecmp (acl_getenv ("TRIMDUMP"), "24x132") == 0)
    {
      if (sh > 24)
	sh = 24;
      if (sw > 132)
	sw = 132;
    }
  if (A4GL_aubit_strcasecmp (acl_getenv ("TRIMDUMP"), "25x132") == 0)
    {
      if (sh > 24)
	sh = 25;
      if (sw > 132)
	sw = 132;
    }

  if (n == 0)
    {
      A4GL_debug ("AUTO PRINT...");
      // We want to dump to to PRINTSCRFILE
      ptr = acl_getenv ("A4GL_PRINTSCRFILE");
      if (ptr)
	{
	  if (strlen (ptr) == 0)
	    ptr = 0;
	}
      if (ptr == 0)
	{
	  A4GL_debug ("No PRINTSCRFILE - ignored print dump request");
	  return 0;
	}
      if (ptr[0] == '|')
	{
	  f = popen (&ptr[1], "w");
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
    }
  else
    {
      f = fopen (ptr, "w");
    }
  if (f == 0)
    {
      A4GL_debug ("Unable to open A4GL_dump file");
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
	      FPRINTF (f, "%c%c", buff[2], attr & 255);
	    }

	  if (mode == 1)
	    {
	      // Translate line drawings chars into printable ones
	      if ((attr & 0xff) == (ACS_VLINE & 0xff)
#ifndef __PDCURSES__
		  && (attr & A_ALTCHARSET)
#endif
		)
		{
		  attr = (int) '|';
		}

	      if ((attr & 0xff) == (ACS_HLINE & 0xff)
#ifndef __PDCURSES__
		  && (attr & A_ALTCHARSET)
#endif
		)
		{
		  attr = (int) '-';
		}

	      if ((attr & 0xff) == (ACS_LLCORNER & 0xff)
#ifndef __PDCURSES__
		  && (attr & A_ALTCHARSET)
#endif
		)
		{
		  attr = (int) '+';
		}

	      if ((attr & 0xff) == (ACS_LRCORNER & 0xff)
#ifndef __PDCURSES__
		  && (attr & A_ALTCHARSET)
#endif
		)
		{
		  attr = (int) '+';
		}

	      if ((attr & 0xff) == (ACS_URCORNER & 0xff)
#ifndef __PDCURSES__
		  && (attr & A_ALTCHARSET)
#endif
		)
		{
		  attr = (int) '+';
		}

	      if ((attr & 0xff) == (ACS_ULCORNER & 0xff)
#ifndef __PDCURSES__
		  && (attr & A_ALTCHARSET)
#endif
		)
		{
		  attr = (int) '+';
		}

	      FPRINTF (f, "%c", attr & 255);
	    }
	}
      FPRINTF (f, "\n");
    }
  fclose (f);
  return 0;
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_set_field_status (void *f, int stat)
{
  A4GL_form_set_field_status (f, stat);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_move_window (void *w, int y, int x)
{
  move_panel (w, y, x);
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_hide_window (void *w)
{
  hide_panel (w);
}



/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_show_window (void *w)
{
  show_panel (w);

}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_gui_run_til_no_more ()
{
  // Not implemented in TUI MODE
}


/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_screen_mode ()
{
  A4GL_debug ("LL_screen_mode");
  if (A4GL_isyes (acl_getenv ("INIT_COL_REFRESH")))
    {
      A4GL_debug ("INIT_COL_REFRESH2_0 TRIGGERED...");
      if (has_colors ())
	{
	  A4GL_debug ("init_col_refresh2_0 - init_colour_pairs");
	  A4GL_init_colour_pairs ();
	  if (!A4GL_isyes (acl_getenv ("NO_INIT_COL_CLR")))
	    {
	      clearok (curscr, 1);
	    }
	  A4GL_init_colour_pairs ();
	}
    }
  update_panels ();
  doupdate ();


}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_initialize_display ()
{
#ifdef XCURSES
  char *argv[1];
#endif
#ifdef DEBUG
  A4GL_debug ("LL_initialize_display *************************");
#endif


  /*

     To use XCurses with an existing curses program, you need to make one
     change to your code:

     Call XCursesExit() just before exiting from your program. eg.

     #ifdef XCURSES
     XCursesExit();
     #endif
     exit(0);

     This call is required to enable the child X process to shut down cleanly
     and free up the shared memory it used.

     To get the most out of XCurses in your curses application you need
     to call Xinitscr() rather than initscr(). This allows you to pass
     your program name and resource overrides to XCurses.

     The program name is used as the title of the X window, and for defining X
     resources specific to your program.

     Resources may also be passed as a parameter to the Xinitscr() function.
     The parameter is a string in the form of switches. eg. to set the color
     "red" to "indianred", and the number of lines to 30, the string passed to 
     Xinitscr would be:
     "-colorRed indianred -lines 30"
     -colorBlack  midnightblue

   */

#ifdef XCURSES
#ifdef DEBUG
  //trace_on=1;
  //PDC_debug("Set trace_on=1 from Aubit lowlevel_tui.c\n");
  A4GL_debug ("calling Xinitscr()");
#endif
  /* PDC_debug defined in PDcurses pdcdebug.c - writes to ./trace file
     Note that PDcurses need to be compiled with -DPDCDEBUG for most
     of them to work
     #ifdef PDCDEBUG
     if (trace_on) PDC_debug("%s:shmid_Xcurscr %d shmkey_Xcurscr %d LINES %d COLS %d\n",(XCursesProcess)?"     X":"CURSES",shmid_Xcurscr,shmkey_Xcurscr,LINES,COLS);
     #endif
     #ifdef PDCDEBUG
     say ("cursesprocess exiting from Xinitscr\n");
     #endif
   */
  //Xinitscr is defined in PDcurses initscr.c
  //returns WINDOW*  stdscr=NULL;  - the default screen window  
  argv[0] = A4GL_get_running_program ();
  stdscr = Xinitscr (1, argv);	//(argc, argv);
#ifdef DEBUG
  A4GL_debug ("returned from Xinitscr()");
#endif
#else
  initscr ();
#endif


  if (A4GL_isyes (acl_getenv ("NO_ALT_SCR")))
    {
      /* 
         When using some terminals types in curses mode, an alternate screen is employed so that
         when the application finishes (or otherwise enters line mode), the original screen will 
         be redisplayed. Setting this option attempts to disable this screen swapping so that the
         original screen is used for the 4GL display.
       */
#ifdef DEBUG
      A4GL_debug ("calling try_to_stop_alternate_view()");
#endif

      try_to_stop_alternate_view ();
    }

  if (has_colors () == FALSE);
  else
    {
#ifdef DEBUG
      A4GL_debug ("setting up colors...");
#endif

      start_color ();
      refresh ();
#if (! defined(__sun__) && ! defined (__sparc__))
#if (! defined(__MINGW32__) && ! defined (XCURSES))
      //curses function not available on Solaris (!!!!?????) and PDcurses
      use_default_colors ();
      have_default_colors = 1;
#else
      A4GL_debug ("use_default_colors not available with PDcurses/Xcurses");
#endif
#else
      A4GL_debug ("use_default_colors not available on Solaris/Sparc");
#endif
    }
#ifdef DEBUG
  A4GL_debug ("calling cbreak()");
#endif
  cbreak ();
#ifdef DEBUG
  A4GL_debug ("calling noecho()");
#endif

  noecho ();
#ifdef DEBUG
  A4GL_debug ("calling nonl()");
#endif

  nonl ();
#ifdef DEBUG
  A4GL_debug ("calling intrflush()");
#endif

  intrflush (stdscr, TRUE);
  keypad (stdscr, TRUE);

#ifdef DEBUG
  A4GL_debug ("after call to keypad()");
#endif


  if (has_colors ())
    {
      //start_color ();
      A4GL_init_colour_pairs ();
    }
  chars_normal[0] = (ACS_HLINE & 0xff) + AUBIT_ATTR_ALTCHARSET;
  chars_normal[1] = (ACS_VLINE & 0xff) + AUBIT_ATTR_ALTCHARSET;
  chars_normal[2] = (ACS_ULCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  chars_normal[3] = (ACS_URCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  chars_normal[4] = (ACS_LLCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  chars_normal[5] = (ACS_LRCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  //A4GL_init_windows ();


  //A4GL_mja_gotoxy (1, 1);
  //A4GL_tui_print ("                                 ");
  //UILIB_A4GL_zrefresh ();


#ifdef NCURSES_MOUSE_VERSION
#ifdef DEBUG
  A4GL_debug ("Turning Mouse on");
#endif
#ifdef WIN32
#if (! defined(__CYGWIN__) && ! defined(__MINGW32__))
#ifdef DEBUG
  A4GL_debug ("Turning WIN32 mouse on\n");
#endif
  if (A4GL_env_option_set ("ACL_MOUSE") mouse_on (ALL_MOUSE_EVENTS);
#endif
#else
  if (A4GL_env_option_set ("ACL_MOUSE"))
    {
#ifdef DEBUG
      A4GL_debug ("Turning UNIX mouse on\n");
#endif
      {
	int mcode;
	mcode = mousemask (ALL_MOUSE_EVENTS, 0);
#ifdef DEBUG
	A4GL_debug ("Turned on %d (%d)", mcode, ALL_MOUSE_EVENTS);
#endif
      }
    }
#endif
#endif
  refresh ();

#ifdef DEBUG
  A4GL_debug ("LL_initialize_display - done");
#endif

}

/************* PROMPT IMPLEMENTATION ************/

int prompt_last_key = 0;




int
A4GL_LL_start_prompt (void *vprompt, char *promptstr, int prompt_attribute, int c, int h,
		      int field_attribute, int curr_width, int iscurrborder,
		      int prompt_line, void *currwin, int prompt_mode)
{
  //char *promptstr;
  int promptline;
  //struct s_prompt *promptx;
  FIELD *sarr[3];
  void *p;
  void *d;
  void *cw;
  void *f;
  WINDOW *pp;
  int width;
  char buff[300];
  FIELD *prompt_field;
  list_of_fields flist;
  int a;
  int field_cnt = 0;
  //A4GL_chkwin ();
  //promptx = vprompt;
  //A4GL_debug ("In start prompt %p %d %d %d %d", prompt, ap, c, h, field_attribute);
  prompt_last_key = 0;
  memset (buff, ' ', 255);
  promptline = prompt_line;	// A4GL_getprompt_line ();
  A4GL_debug ("promptline=%d", promptline);
  width = curr_width;
  A4GL_debug ("create window %d %d", 1, promptline);
  A4GL_debug ("%d %d", width - 1, 2);
  cw = (void *) currwin;	// A4GL_get_currwin ();
  if (iscurrborder)
    promptline++;

  last_prompt_mode = prompt_mode;

  A4GL_debug
    ("panel_window (cw)=%d , width=%d, promptline - 1 =%d UILIB_A4GL_iscurrborder ()=%d",
     panel_window (cw), width, promptline - 1, iscurrborder);

  p = derwin (panel_window (cw), 1, width, promptline - 1, iscurrborder);


  if (p == 0)
    {
A4GL_debug("no prompt window");
      A4GL_exitwith ("No prompt window created");
      return 0;
    }


  //promptx->win = p;
  last_prompt_win = p;



  buff[width] = 0;

  wprintw (p, "%s", buff);
  A4GL_LL_screen_update ();

  width -= strlen (promptstr);
  width--;
  if (width<=0) {
A4GL_debug("Too small");
	  A4GL_exitwith("Prompt message is too long to fit in the window.");
	  return 0;
  }
  if (strlen (promptstr))
    {
      sarr[field_cnt++] = (void *) A4GL_LL_make_label (0, 0, promptstr);
    }

  A4GL_debug ("Creating field %d %d %d", strlen (promptstr) + 1, 1,
	      width - 1);
  A4GL_form_set_new_page (sarr[field_cnt - 1], 1);

  sarr[field_cnt++] =
    (void *) A4GL_LL_make_field (0, strlen (promptstr), 1, width + 1, 0, 0,0,
				 0,"","");


  last_prompt_field = sarr[field_cnt - 1];


  //promptx->field = sarr[field_cnt - 1];


  prompt_field = sarr[field_cnt - 1];



  sarr[field_cnt++] = 0;	/* (void *) A4GL_make_label (0, strlen(promptstr)+width-1,"|"); */




  flist.a.a_len = field_cnt;
  flist.a.a_val = (long *) sarr;


  A4GL_default_attributes_in_ll (prompt_field, 0, 0);
  A4GL_debug ("STATIC OFF");
  A4GL_form_field_opts_off (prompt_field, O_STATIC);

  A4GL_debug ("ap=%d(%x) field_attribute=%d(%x)", prompt_attribute, prompt_attribute, field_attribute, field_attribute);
  //ap = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, ap, 0, 0);
  //field_attribute = A4GL_determine_attribute (FGL_CMD_INPUT, field_attribute, 0, 0);

  if (prompt_attribute)
    {
      A4GL_debug ("AP...");
      if (strlen (promptstr))
	{
	  A4GL_LL_set_field_fore (sarr[0], A4GL_LL_decode_aubit_attr (prompt_attribute, 'f'));
	  A4GL_LL_set_field_back (sarr[0], A4GL_LL_decode_aubit_attr (prompt_attribute, 'b'));	// maybe need 'B' for whole field..
	}
    }

  if (field_attribute)
    {
      A4GL_debug ("AF... %d", field_attribute);
      A4GL_LL_set_field_back (prompt_field, A4GL_LL_decode_aubit_attr (field_attribute, 'b'));
      A4GL_LL_set_field_fore (prompt_field, A4GL_LL_decode_aubit_attr (field_attribute, 'f'));	// maybe need 'B' for whole field..

      if (field_attribute & AUBIT_ATTR_INVISIBLE)
	{
	  A4GL_debug ("Invisible");
	  A4GL_form_field_opts_off (prompt_field, O_PUBLIC);
	}

    } else {
      A4GL_LL_set_field_back (prompt_field, A4GL_LL_colour_code (COLOR_BLACK));
      A4GL_LL_set_field_fore (prompt_field, A4GL_LL_colour_code (COLOR_BLACK));	// maybe need 'B' for whole field..
    }

  A4GL_form_field_opts_on (prompt_field, AUBIT_O_NULLOK);
  A4GL_debug ("Set attributes");

  buff[0] = 0;			/* -2 */
  A4GL_debug ("Setting Buffer %p to '%s'", prompt_field, buff);
  A4GL_LL_set_field_buffer (prompt_field, 0, buff);
  A4GL_debug ("Set buffer ");

  A4GL_debug ("Made fields");

  f = A4GL_form_new_form (sarr);
  A4GL_debug ("Form f = %p", f);


  last_prompt_f = f;
  //promptx->f = f;


  //A4GLSQL_set_status (0, 0);

  if (a4gl_status != 0)
    {
      return 2;
    }


  pp = (WINDOW *) p;
  d = derwin (pp, 0, 0, width + 1, 1);
  A4GL_form_set_form_win (f, d);
  A4GL_form_set_form_sub (f, p);
  A4GL_debug ("Set form win");
  a = A4GL_form_post_form (f);
  A4GL_debug ("Posted form=%d", a);



  A4GL_LL_int_form_driver (f, AUBIT_REQ_FIRST_FIELD);
  A4GL_LL_int_form_driver (f, AUBIT_REQ_OVL_MODE);
  //A4GLSQL_set_status (0, 0);
  A4GL_debug ("su");

  A4GL_LL_set_carat (f);
  A4GL_LL_screen_update ();
  return 1;
}




void
A4GL_LL_clear_prompt (void *f, void *p)
{
  if (f)
    {
      A4GL_form_unpost_form ((FORM *) f);
    }

  delwin ((WINDOW *) p);
}


void
A4GL_LL_scale_form (void *vf, int *y, int *x)
{
  struct s_form_dets *f;
  f = vf;
  A4GL_form_scale_form (f->form, y, x);
  A4GL_debug ("y=%d x=%x", y, x);
}

int
A4GL_LL_get_field_width_dynamic (void *f)
{
  int x, y, a;
  A4GL_form_dynamic_field_info (f, &y, &x, &a);
  return x * y;
}



int
A4GL_mja_get_field_width (void *f)
{
  //int x, y, a;
  //int w;
  //int rows;
  //int cols;
  //int frow;
  //int fcol;
  //int nrow;
  //int nbuf;
  //struct struct_scr_field *fprop;

  return A4GL_LL_get_field_width_dynamic (f);




  //A4GL_form_field_info (f, &rows, &cols, &frow, &fcol, &nrow, &nbuf);
  //return cols;
}






void
A4GL_LL_set_max_field (void *f, int n,void *frm)
{
  int a;
  A4GL_debug ("set max field : %d\n", n);
  if (n == 0)
    {
      a = A4GL_form_set_max_field (f, 0);
    }
  else
    {
      FIELD *rfield;
      rfield = f;
      if (rfield->dcols > n)
	rfield->dcols = n;
      a = A4GL_form_set_max_field (f, n);
    }
}


static void
A4GL_debug_print_field_opts (FIELD * a)
{
  long z;
  char str[8048] = "";
  z = A4GL_form_field_opts (a);
  if (z & O_VISIBLE)
    strcat (str, " O_VISIBLE");
  if (z & O_ACTIVE)
    strcat (str, " O_ACTIVE");
  if (z & O_PUBLIC)
    strcat (str, " O_PUBLIC");
  if (z & O_EDIT)
    strcat (str, " O_EDIT");
  if (z & O_WRAP)
    strcat (str, " O_WRAP");
  if (z & O_BLANK)
    strcat (str, " O_BLANK");
  if (z & O_AUTOSKIP)
    strcat (str, " O_AUTOSKIP");
  if (z & O_NULLOK)
    strcat (str, " O_NULLOK");
  if (z & O_STATIC)
    strcat (str, " O_STATIC");
  if (z & O_PASSOK)
    strcat (str, " O_PASSOK");
  A4GL_debug ("Field %p attribs= %s:", a, str);
}

int
A4GLHLUI_initlib (void)
{
  return 0;
}


// Not available in TUI mode...
int
A4GL_LL_endis_fields_ap (int n, void *ap)
{
  return 0;
}


int
A4GL_LL_open_gui_form (char *name_orig, int absolute, int nat, char *like,
		       int disable, void *handler_e, void *phandler_c)
{
// Not in TUI mode you don't....
  return 0;
}





int
A4GL_LL_disp_form_fields_ap (int n, int attr, char *formname, va_list * ap)
{
  return 0;
}


int
A4GL_LL_set_window_title (void *currwin, char *s)
{

  return 0;
}




int
A4GL_LL_widget_name_match (void *w, char *name)
{
  return 0;
}




int
A4GL_LL_fieldnametoid (char *f, char *s, int n)
{
  return 0;
}

void
A4GL_LL_clr_form_fields (int to_defaults, char *defs)
{
  return;
}


/* 
** orig     = original string
** evt      = original event list from contruct..
** init_key = initial keystroke that caused us to be here.. (0 for before field)
** init_pos = position in field as retrived from the original field..
*/
void *
A4GL_LL_construct_large (char *orig,
			 void *vevt, int init_key, int initpos, char *left,
			 char *right, int curr_width, int curr_height, int fl,
			 void *currwin, int isborder)
{
  static char rbuff[1024];
  FIELD *buff[4];
  PANEL *cwin;
  WINDOW *drwin;
  FORM *f;
  //int ins_ovl='o';
  //int looping=1;
  int fwidth;
  int a;
  struct aclfgl_event_list *evt;
  evt = vevt;
  A4GL_debug ("In construct_large");

  strcpy (rbuff, orig);
  A4GL_trim (rbuff);
  fwidth = curr_width;
  if (fwidth > 80)
    fwidth = 80;
  cwin = (PANEL *) currwin;	// A4GL_get_currwin ();
  if (fl > curr_height)
    fl = curr_height;

  drwin = derwin (panel_window ((PANEL *) cwin), 1, fwidth, fl - 1, isborder);
  last_construct_drwin = drwin;
  buff[0] = A4GL_LL_make_label (0, 0, left);
  buff[1] = A4GL_LL_make_field (0, 1, 1, fwidth - 2, 0, 0, 0,0,"","");


  A4GL_fld_opts_on (buff[1], AUBIT_O_ACTIVE);
  A4GL_fld_opts_on (buff[1], AUBIT_O_EDIT);
  A4GL_fld_opts_on (buff[1], AUBIT_O_BLANK);

  buff[2] = A4GL_LL_make_label (0, fwidth - 1, right);
  buff[3] = 0;

  f = A4GL_form_new_form (buff);

  A4GL_form_set_form_win (f, panel_window (cwin));
  A4GL_form_set_form_sub (f, drwin);

  a = A4GL_form_post_form (f);
  A4GL_debug ("construct - post_form = %d", a);
  A4GL_LL_set_field_buffer (buff[1], 0, rbuff);

  A4GL_debug ("su");
  A4GL_LL_screen_update ();

  A4GL_LL_int_form_driver (f, AUBIT_REQ_FIRST_FIELD);
  A4GL_LL_int_form_driver (f, AUBIT_REQ_OVL_MODE);

  if (f->current == 0)
    {
      A4GL_debug ("Still not current...");
    }

  if (initpos)
    {
      A4GL_LL_int_form_driver (f, AUBIT_REQ_END_FIELD);
    }
  return f;

}




char *
A4GL_LL_construct_large_finished (void *f)
{
  static char orig[2000];
  WINDOW *w;
  A4GL_LL_int_form_driver (f, AUBIT_REQ_VALIDATION);
  w = A4GL_form_form_sub (f);
  strcpy (orig, A4GL_LL_field_buffer (A4GL_form_current_field (f), 0));
  A4GL_debug ("Unpost and delete...");
  A4GL_form_unpost_form (f);
  A4GL_debug ("delwin %p", w);
  if (w != last_construct_drwin)
    {
      A4GL_assertion (1, "Very confused...");
    }
  delwin (w);
  A4GL_debug ("su");
  A4GL_LL_screen_update ();
  //A4GL_comments(0);
  return orig;
}





#ifdef NCURSES_VERSION
#include <term.h>
#define isprivate(s) ((s) != 0 && strstr(s, "\033[?") != 0)
#endif

void
try_to_stop_alternate_view (void)
{
#ifdef NCURSES_VERSION
  /*
   * Cancel xterm's alternate-screen mode.
   */
  if (isprivate (enter_ca_mode) && isprivate (exit_ca_mode))
    {
      /*
       * initscr() or newterm() already did putp(enter_ca_mode) as a side
       * effect of initializing the screen.  It would be nice to not even
       * do that, but we do not really have access to the correct copy of
       * the terminfo description until those functions have been invoked.
       */
      (void) putp (exit_ca_mode);
      (void) putp (clear_screen);
      /*
       * Prevent ncurses from switching "back" to the normal screen when
       * exiting from dialog.  That would move the cursor to the original
       * location saved in xterm.  Normally curses sets the cursor position
       * to the first line after the display, but the alternate screen
       * switching is done after that point.
       *
       * Cancelling the strings altogether also works around the buggy
       * implementation of alternate-screen in rxvt, etc., which clear
       * more of the display than they should.
       */
      enter_ca_mode = 0;
      exit_ca_mode = 0;
    }
#endif
}



/* This is a copy & paste of the function from lowlevel_gtk.c

  Function is called from misc.c

  It is here because Windows do't allow unresolved sibmols when linking.

  I do not know if it is actially needed (an needs to be adapted for TUI)

  or if it is used only for GTK

*/
int
A4GL_LL_disp_form_field_ap (int n, int attr, char *s, va_list * ap)
{

#ifdef FIX_THIS_C_AND_P_FROM_GTK
  int a;
  int flg;
  struct s_form_dets *formdets;
  void **field_list;
  int nofields;
  void *w;
  struct struct_scr_field *fprop;
  a4gl_status = 0;

  //A4GL_chkwin ();
  A4GL_debug ("In disp_fields");
  w = A4GL_find_pointer (s, WINCODE);

  formdets = (struct s_form_dets *) A4GL_find_form_for_win (w);

#ifdef DEBUG
  {
    A4GL_debug ("Status=%d formdets=%p", a4gl_status, formdets);
  }
#endif
  if (a4gl_status != 0)
    return 0;
  flg = 0;

  A4GL_debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {
    A4GL_debug ("Genfldlist 2");
  }
#endif
  A4GL_debug ("disp_fields");
  nofields = A4GL_gen_field_list (&field_list, formdets, n, ap);
  A4GL_debug ("Number of fields=%d ", nofields, n);

  if (nofields < 0)
    {
      A4GL_debug ("Failed to find fields");
      return 0;
    }

  for (a = nofields; a >= 0; a--)
    {

      A4GL_set_field_pop_attr (field_list[a], attr, FGL_CMD_DISPLAY_CMD);
      fprop =
	(struct struct_scr_field
	 *) (A4GL_LL_get_field_userptr (field_list[a]));
      fprop->flags |= 2;



    }
  A4GL_debug ("su");
  A4GL_LL_screen_update ();
#else


  A4GL_debug ("FIXME: A4GL_LL_disp_form_field_ap() not implemented for TUI");

#endif


  return 0;
}


int
A4GL_LL_disp_h_menu (int num_opts)
{
  return 0;
}


int
A4GL_LL_menu_loop (void *menu)
{
  return -1;
}


int
A4GL_LL_menu_type (void)
{
  /* let the high level stuff do all the processing... */
  return 0;
}


#ifdef WIDEC
void
A4GL_LL_wadd_wchar_xy_col (void *win, int x, int y, int oattr, wchar_t ch,
			   int curr_width, int curr_height, int iscurrborder,
			   int currwinno)
{
  int ch2;
  int attr;
  void *p;
  wchar_t buff[2];
  A4GL_debug ("xy_col");
  attr = A4GL_LL_decode_aubit_attr (oattr & 0xffffff00, 'w');
  buff[0] = ch;
  buff[1] = 0;


  p = panel_window (win);
  if (!iscurrborder || currwinno == 0)
    {
      x--;
      y--;
    }
  if (x < 0 || y < 0 || x > curr_width || y > curr_height);
  else
    {
      wattrset ((WINDOW *) p, attr & 0xffffff00);
      mvwaddwstr (p, y, x, buff);
    }
}

void
A4GL_LL_wadd_wchar_xy_col_w (void *win, int x, int y, int oattr, wchar_t ch,
			     int curr_width, int curr_height,
			     int iscurrborder, int currwinno)
{
  int ch2;
  int attr;
  void *p;
  wchar_t buff[2];
  A4GL_debug ("xy_col_w");
  attr = A4GL_LL_decode_aubit_attr (oattr & 0xffffff00, 'w');
  buff[0] = ch;
  buff[1] = 0;


  p = win;
  if (!iscurrborder || currwinno == 0)
    {
      x--;
      y--;
    }
  if (x < 0 || y < 0 || x > curr_width || y > curr_height);
  else
    {
      wattrset ((WINDOW *) p, attr & 0xffffff00);
      mvwaddwstr (p, y, x, buff);
    }
}
#else

#endif


void *
A4GL_LL_create_menu (void *m, char *id, int mode, void *handler)
{
  A4GL_exitwith ("Not in TUI mode");
  return 0;
}



void
A4GL_LL_clr_menu_disp (void *menu, int curr_width, int curr_height,
		       int iscurrborder, int currwinno, void *cw,
		       int menu_offset, int gw_y)
{
  static char buff[1025];
  int off;
  int w;
  //void *cw;
  int y;

  A4GL_debug ("Clearing menu clr_menu_disp - %p", menu);
  memset (buff, ' ', 1023);
  buff[1024] = 0;

  w = curr_width;
  off = menu_offset;
  buff[w - off + 1] = 0;
  y = gw_y;
  A4GL_wprintw (cw, 0, off - 1, y, curr_width, curr_height, iscurrborder,
		currwinno, "%s", buff);
}


void
A4GL_LL_h_disp_title (void *menu, char *str, int curr_width, int curr_height,
		      int iscurrborder, int currwinno, void *cw, int gw_y)
{
  A4GL_wprintw ((void *) cw, 0, 1, gw_y, curr_width, curr_height,
		iscurrborder, currwinno, "%s", str);
}


void
A4GL_LL_set_acc_intr_keys (int n)
{
/* does nothing - required as it will be called from the HL driver */
}




// In order to get around a limitation of C not returning more than one value
// and without using a pointer to each of these values - we're just going to store them
// and return them when requested...
// (the reason for not using pointers to return the values is that we can then split
// this over the network using RPC calls...)
void *
A4GL_LL_get_value (char *s)
{
  if (strcmp (s, "prompt.field") == 0)
    return (void *) last_prompt_field;
  if (strcmp (s, "prompt.f") == 0)
    return (void *) last_prompt_f;
  if (strcmp (s, "prompt.win") == 0)
    return (void *) last_prompt_win;
  if (strcmp (s, "prompt.mode") == 0)
    return (void *) last_prompt_mode;
  PRINTF ("Unknown value...%s\n", s);
  return (void *) 0;
}

void
A4GL_LL_disp_h_menu_opt (int a, int n, char *title, char *shorthelp, int attr)
{
  // Does nothing - but is required by the API...
  return ;
}



int
A4GL_LL_hide_h_menu (void)
{
  // Does nothing - but is required by the API...
  return 0;
}






static void
A4GL_do_pause (int curr_width, int curr_height, int iscurrborder,
	       int currwinno)
{
  PANEL *x;
  int w;
  int emw;
  char buff[80];
  char buff_b[80];
  w = A4GL_LL_screen_width ();
  sprintf (buff, " %s ", acl_getenv ("ERROR_MSG"));
  emw = strlen (buff);
  memset (buff_b, ' ', 80);
  buff_b[strlen (buff)] = 0;
  x = (PANEL *) A4GL_LL_create_window (3, emw, 20, ((w - emw) / 2), 1);
//A4GL_create_blank_window ("pause", ((w - emw) / 2), 20, emw, 3, 1);

  wattrset (panel_window (x), A4GL_LL_colour_code (COLOR_RED) | A_REVERSE);
  mvwaddstr (panel_window (x), 1, 1, buff_b);
  mvwaddstr (panel_window (x), 2, 1, buff);
  mvwaddstr (panel_window (x), 3, 1, buff_b);
  A4GL_LL_screen_update ();
  abort_pressed = FALSE;
  A4GL_LL_getch_swin (0,"pause");
  A4GL_LL_remove_window (x);
  A4GL_LL_screen_update ();
}

/**
 * PLEASE DESCRIBE THE BL*** FUNCTION!
 *
 * @param 
 * @return 
 */
void
A4GL_LL_error_box (char *str, int attr)
{
  int a, pos;
  //int nattr;
  PANEL *x;
  a = 4;
  pos = (A4GL_LL_screen_width () - (strlen (str))) / 2;
  x = (PANEL *) A4GL_LL_create_window (3, strlen (str), a, pos, 1);
  wattrset ((WINDOW *) x, attr & 0xffffff00);
  mvwaddstr (panel_window (x), 2, 1, str);
  A4GL_LL_screen_update ();
  A4GL_do_pause (80, 4, 1, 999);
  A4GL_LL_remove_window (x);
  A4GL_LL_screen_update ();
}



void *
UILIB_A4GL_make_pixmap_gw (char *fname)
{
  //
  return 0;

}


static void
A4GL_default_attributes_in_ll (void *f, int dtype, int has_picture)
{
  int done = 0;

  A4GL_debug ("In def attrib f=%p", f);



  if (has_picture)
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_ll_set_field_opts (f, AUBIT_O_VISIBLE | AUBIT_O_ACTIVE | AUBIT_O_PUBLIC | AUBIT_O_EDIT);
      done = 1;
    }





  if (done == 0)
    {

      A4GL_debug ("MMMM DTYPE & 255 = %d", dtype);

      if ((dtype & 255) == 0)
	{
	  A4GL_debug ("ZZZZ - SET OPTS");
	  A4GL_ll_set_field_opts (f, AUBIT_O_VISIBLE | AUBIT_O_ACTIVE | AUBIT_O_PUBLIC | AUBIT_O_EDIT);



	  //A4GL_field_opts_off (f, AUBIT_O_BLANK); @todo     is it ok to remove this ?

	}
      else
	{
	  A4GL_debug ("ZZZZ - SET OPTS");
	  A4GL_debug ("BLANK BLANK");
	  A4GL_ll_set_field_opts (f,
				  AUBIT_O_VISIBLE | AUBIT_O_ACTIVE |
				  AUBIT_O_PUBLIC | AUBIT_O_EDIT |
				  AUBIT_O_BLANK);
	}

    }

  A4GL_debug ("STATIC");
  A4GL_LL_set_field_fore (f, A4GL_LL_colour_code (7));
  A4GL_LL_set_field_back (f, A4GL_LL_colour_code (7));
  A4GL_LL_set_max_field (f,A4GL_mja_get_field_width(f) ,0);

}


//
// Called when SET PAUSE MODE ON/OFF is set
// and to check which is in effect (a==-1)
//
int
A4GL_LL_pause_mode (int a)
{
  static int smode = 1;
  if (a == -1)
    return smode;

  if (a == smode)
    return smode;
  if (a == 0)
    {
      smode = 0;
      return smode;
    }
  smode = 1;

  A4GL_LL_screen_update ();

  return smode;
}


int A4GL_LL_can_show_comments(char *s) {
	return 0;
}

int A4GL_LL_can_show_message(int ml,char *s,int wait) {
	        return 0;
}

void A4GL_LL_init_color(int c,int r,int g, int b) {
	// Does nothing yet..
}

void
A4GL_LL_submit_event (int a, void *s, int event_type, int block, int keycode,
		      char *field)
{
  // Does nothing in TUI mode..
}


void
A4GL_LL_activate_events (void *s)
{
  // Does nothing in TUI mode..
}

void
A4GL_LL_finished_with_events (void *s)
{
  // Does nothing in TUI mode..
}

int A4GL_LL_get_triggered_event() {
	        return -1; /* Does nothing in tui mode */
}


static void A4GL_local_mja_endwin (void)
{
  if (A4GL_isscrmode ())
	      {
		            A4GL_set_scrmode ('L');
			          PRINTF ("\n");
				        fflush (stdout);
					      endwin ();
					          }

}



void A4GL_LL_ui_exit(void) {
A4GL_LL_switch_to_line_mode ();
	        // Does nothing - required by api..
}

void A4GL_LL_enable_menu (void)
{
  // Does nothing - required by api..
}

void
A4GL_LL_disable_menu (void)
{
  // Does nothing - required by api..
}
// --------------------------------------------------------------------------------------
// FIXMEs...
// --------------------------------------------------------------------------------------
