//static void A4GL_do_pause (void);
#include <curses.h>
static int A4GL_curses_to_aubit (int a);
static int A4GL_curses_to_aubit_int (int a);
#include "a4gl_libaubit4gl.h"
#include "a4gl_incl_4gldef.h"
#include "a4gl_API_ui_lib.h"
#include "hl_proto.h"
#include "lowlevel.h"
#include "a4gl_API_lowlevel.h"
#include <ctype.h>

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

 $Id: lowlevel_tui.c,v 1.38 2004-12-08 13:07:38 mikeaubury Exp $ 
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

#include <panel.h>
#include "formdriver.h"
static char *module_id="$Id: lowlevel_tui.c,v 1.38 2004-12-08 13:07:38 mikeaubury Exp $";
int inprompt = 0;
void *A4GL_get_currwin (void);
void try_to_stop_alternate_view(void) ;
int A4GLHLUI_initlib(void) ;
int A4GL_has_event(int a,struct aclfgl_event_list *evt) ;
int A4GL_has_event_for_keypress(int a,struct aclfgl_event_list *evt) ;
int A4GL_has_event_for_field(int cat,char *a,struct aclfgl_event_list *evt) ;
int A4GL_LL_decode_colour_attr_aubit(int a) ;
int A4GL_LL_get_field_width_dynamic (void *f);
int A4GL_LL_fieldnametoid(char* f,char* s,int n) ;
int A4GL_LL_disp_form_field_ap(int n,int attr,char* s,va_list* ap) ;
static void
A4GL_debug_print_field_opts (FIELD * a);
int chars_normal[6];
int have_default_colors = 0;
int A4GL_LL_construct_large(char *orig, struct aclfgl_event_list *evt,int init_key,int initpos,char *l,char *r) ;

static void A4GL_clear_prompt (struct s_prompt *prmt);
//void A4GL_LL_screen_update (void);
//void A4GL_LL_set_bkg (void *win, int attr);
//int A4GL_LL_decode_aubit_attr (int a, char s);

//-----------------------


void A4GL_LL_beep(void) {
  if (A4GL_isyes(acl_getenv("FLASHFORBEEP"))) {flash();}
  else {
	if (!A4GL_isyes(acl_getenv("DISABLEBEEP"))) beep();
  }
}


/*
int
A4GL_LL_wrapper_wgetch (WINDOW * w)
{
  int a;
  a = A4GL_readkey ();
  if (a != 0)
    {
      A4GL_debug ("Read %d from keyfile", a);
      return a;
    }
  return A4GL_curses_to_aubit (wgetch (w));
}
*/


int A4GL_LL_set_chars_normal(int* n) {
  n[0] = (ACS_HLINE & 0xff) + AUBIT_ATTR_ALTCHARSET;
  n[1] = (ACS_VLINE & 0xff) + AUBIT_ATTR_ALTCHARSET;
  n[2] = (ACS_ULCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  n[3] = (ACS_URCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  n[4] = (ACS_LLCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
  n[5] = (ACS_LRCORNER & 0xff) + AUBIT_ATTR_ALTCHARSET;
return 1;
}



static int A4GL_init_colour_pairs (void)
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

void A4GL_do_pause (void)
{
  WINDOW *x;
  int w;
  int emw;
  char buff[80];

  w = A4GL_LL_screen_width ();
  sprintf (buff, " %s ", acl_getenv ("ERROR_MSG"));
  emw = strlen (buff);
  x = A4GL_create_blank_window ("pause", ((w - emw) / 2), 20, emw, 3, 1);
  A4GL_wprintw (x, A4GL_LL_colour_code (COLOR_RED) | A_REVERSE, 1, 2, "%s",
		buff);
	A4GL_debug("su");
  A4GL_LL_screen_update ();
  abort_pressed = FALSE;
  if (A4GL_screen_mode (-1))
    {
      doupdate ();
    }
  A4GL_debug ("getch_win...");
  A4GL_getch_win ();
  A4GL_debug ("Done getch_win");
  UILIB_A4GL_remove_window ("pause");
}

/**
 * Convert a curses key to 4gl key.
 *
 * @param The code of the curses key.
 * @return The 4gl code key.
 */
static int A4GL_curses_to_aubit_int (int a)
{
  int b;
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
  if (a == KEY_CANCEL)
    return A4GLKEY_CANCEL;

  if (a == KEY_DC)
    return A4GLKEY_DC;
  if (a == KEY_DL)
    return A4GLKEY_DL;
  if (a == KEY_BACKSPACE)
    return A4GLKEY_BACKSPACE;

  return a;
}

static int A4GL_curses_to_aubit (int a)
{
  int orig_a;
  orig_a = a;
  a = A4GL_curses_to_aubit_int (a);
  a = A4GL_key_map (a);
  if (a == -1 && orig_a != a)
    {
      int_flag = 1;
    }				// A map to -1 is an interrupt...
  return a;
}





//-----------------------

void
A4GL_LL_switch_to_line_mode (void)
{
  A4GL_debug("Switch to line mode");
  endwin ();
  A4GL_set_scrmode ('L');
}




void *
A4GL_LL_create_window (int h, int w, int y, int x, int border)
{
  WINDOW *win=0;
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
	A4GL_debug("border=1");
      win = newwin (h + 2, w + 2, y - 2, x - 2);
      A4GL_debug ("newwin returns %p", win);
    }

  if (border == 2)
    {
	A4GL_debug("border=2");
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
	A4GL_debug("border=3");
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
	A4GL_debug("su");
  A4GL_LL_screen_update ();
  return pan;
}



void
A4GL_LL_remove_window (void *x)
{
  WINDOW *w;
	A4GL_debug("remove window... del_panel : %p",x);
  w = panel_window (x);
	A4GL_debug("w=%p",w);
  del_panel (x);
	A4GL_debug("Deleted panel %p\n",x);
  delwin (w);
 	A4GL_debug("delwin %p",w);
}

void A4GL_LL_wadd_char_xy_col (void *win, int x, int y, int ch)
{
  int ch2;
  int attr;
  void *p;
  attr = A4GL_LL_decode_aubit_attr (ch & 0xffffff00, 'w');
  ch2 = ch & 0xff;
  //A4GL_debug ("x=%d y=%d ch2=%c", x, y, ch2);
  p = panel_window (win);
  if (!UILIB_A4GL_iscurrborder () || A4GL_get_currwinno () == 0)
    {
      x--;
      y--;
    }
  if (x < 0 || y < 0 || x > UILIB_A4GL_get_curr_width ()
      || y > UILIB_A4GL_get_curr_height ());
  else {
		if (ch2==0) ch2='*';
		//A4GL_debug("waddch  %p %d %d %x ATTR=%x CH=%d",p,y,x,ch,attr,ch2);
    		mvwaddch (p, y, x, attr + ch2);
	}
}

void A4GL_LL_wadd_char_xy_col_w (void *win, int x, int y, int ch)
{
  int ch2;
  int attr;
  void *p;
//A4GL_debug("A4GL_LL_wadd_char_xy_col_w called");
  attr = A4GL_LL_decode_aubit_attr (ch & 0xffffff00, 'w');
  ch2 = ch & 0xff;
  //A4GL_debug ("x=%d y=%d ch2=%c", x, y, ch2);
  p =win;
  if (!UILIB_A4GL_iscurrborder () || A4GL_get_currwinno () == 0)
    {
      x--;
      y--;
    }
  if (x < 0 || y < 0 || x > UILIB_A4GL_get_curr_width ()
      || y > UILIB_A4GL_get_curr_height ()) {
		A4GL_debug("Out of range:%d,%d ",x,y);
	}
  else {
		if (ch2==0) ch2='*';
		//A4GL_debug("----> waddch  %p %d %d %x ATTR=%x CH=%d",p,y,x,ch,attr,ch2);
    		mvwaddch (p, y, x, attr + ch2);
	}
	wrefresh(p);
}



void A4GL_LL_screen_update (void)
{
A4GL_debug("CURSES : update");
// Update the physical screen
  if (A4GL_screen_mode (-1))
    {
      update_panels ();
      doupdate ();
    }
}

void
A4GL_LL_screen_redraw (void)
{
// Blank the screen and redraw from scratch
A4GL_debug("CURSES : refresh");
  clearok (curscr, 1);
  A4GL_LL_screen_update ();
}

int
A4GL_LL_colour_code (int a)
{
  int z;
  static int ismono=-1;
  static int isclassic=-1;
  z = 1;
  if (ismono==-1) {
  	ismono=A4GL_isyes (acl_getenv ("MONO"));
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
      if (isclassic==-1) {
		isclassic=A4GL_isyes (acl_getenv ("CLASSIC_I4GL_MONO"));
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



void
A4GL_LL_error_box (char *str, int attr)
{
  int a, pos;
  //int nattr;
  WINDOW *x;

  A4GL_chkwin ();
  /*YELLOW ON RED */
  //A4GL_mja_setcolor (ERROR_COL);
  a = 4;
  pos = (A4GL_LL_screen_width () - (strlen (str))) / 2;

  A4GL_debug ("error_box - LL_screen_width=%d pos=%d",
	      A4GL_LL_screen_width (), pos);

  x = A4GL_create_blank_window ("error", pos, a, strlen (str), 3, 1);
  /*wmove(x,2,2); */
  /* print ("%s", str); */
  A4GL_wprintw (x, A4GL_LL_colour_code (COLOR_RED) | A_REVERSE, 1, 1, "%s",
		str);
	A4GL_debug("su");
  A4GL_LL_screen_update ();
  A4GL_do_pause ();
  UILIB_A4GL_remove_window ("error");
	A4GL_debug("su");
  A4GL_LL_screen_update ();
  A4GL_debug ("All done in error box");
  //A4GL_mja_setcolor (NORMAL_TEXT);
}

void *
A4GL_LL_display_form (void *vf, int attrib)
{
  int rows, cols;
  char buff[80];
  int a;
  int nattr;
  struct s_form_dets *f;

  //int informix_behaviour = 1;
  PANEL *w;
  WINDOW *drwin;
  /*  FIELD **p; */

  int fl;
  f=vf;
  A4GL_chkwin ();
  A4GL_debug ("In display_form");
  w = (PANEL *) A4GL_get_currwin ();

  sprintf (buff, "%p", f);
  A4GL_add_pointer (buff, ATTRIBUTE, (void *) attrib);

  if (w == 0)
    {
      A4GL_LL_error_box ("NO WINDOW", 0);
    }
  A4GL_debug ("scale form %p", f->form);

  fl = A4GL_getform_line ();
  for (a = fl; a <= UILIB_A4GL_get_curr_height (); a++)
    {
      if (UILIB_A4GL_iscurrborder ())
	{
	  A4GL_display_internal (1, a + 1, " ", 0, 1);
	}
      else
	{
	  A4GL_display_internal (1, a, " ", 0, 1);
	}
    }
  A4GL_form_scale_form (f->form, &rows, &cols);
  rows = f->fileform->maxline - 1;
  cols = f->fileform->maxcol;

  A4GL_debug ("Form line=%d", fl);
  A4GL_debug ("Scale form returns %d %d", rows, cols);

  if (UILIB_A4GL_iscurrborder ())
    {
      rows++;
    }
  else
    {
    }

  if (rows - UILIB_A4GL_iscurrborder () > A4GL_get_curr_width () + 1)
    {
      A4GL_exitwith ("Window is too small to display this form (too high)");
      return 0;
    }
  if (cols - UILIB_A4GL_iscurrborder () > A4GL_get_curr_width () + 1)
    {
      A4GL_exitwith ("Window is too small to display this form (too wide)");
      return 0;
    }


  /* fix - not sure whats going on here bit form_details.border is set to 1 for the screen! */

// I can't seem to replicate this!
  //if (informix_behaviour)
  //{
  //if (currwin!= A4GL_find_pointer ("screen", WINCODE)) {
  //rows = windows[A4GL_get_currwinno()].h - fl;
  //cols = windows[A4GL_get_currwinno()].w;
  //}
  //}


  f->form_details.border = UILIB_A4GL_iscurrborder ();

  if (f->form_details.border)
    {
      A4GL_debug ("Form details returns it has border");
    }
  else
    {
      A4GL_debug ("Form details returns it has *NO* border");
    }

  if (UILIB_A4GL_iscurrborder ())
    {
      A4GL_debug ("Window details returns it has border");
    }
  else
    {
      A4GL_debug ("Window details returns it has *NO* border ");
    }
  A4GL_debug ("derwin - %d rows %d cols form line=%d", rows, cols, fl);

  if (UILIB_A4GL_iscurrborder ())
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



  wclear (drwin);
  a = A4GL_form_set_form_sub (f->form, drwin);


  if (a == E_POSTED)
    {
        WINDOW *olddrwin;
	A4GL_debug("Deleteing old subwin");
        olddrwin=A4GL_form_form_sub(f->form);
	if (olddrwin) {
		A4GL_debug("delwin %p",olddrwin);
		delwin(olddrwin);
	}
        A4GL_form_unpost_form (f->form);
  	a = A4GL_form_set_form_sub (f->form, drwin);
    }

  a = A4GL_form_set_form_win (f->form, panel_window(w));
  if (a == E_POSTED)
    {
	A4GL_exitwith("That shouldn't be posted by now...");
	exit(33);
    }


  A4GL_debug ("setup windows");
  keypad (panel_window ((PANEL *) w), TRUE);
  sprintf (buff, "Currwinno=%d", A4GL_get_currwinno ());

  if (f->form == 0)
    {
      A4GL_exitwith ("Unable to create form");
      return 0;
    }

  A4GL_debug ("post the form s_form_dets=%p form=%p", f, f->form);
  a = A4GL_form_post_form (f->form);

  if (a == E_POSTED)
    {
      A4GL_debug ("Form posted already - dumping and re-doing");
      A4GL_form_unpost_form (f->form);
      a = A4GL_form_post_form (f->form);
      A4GL_debug ("Form was already posted - status now : %d",a);
    }

  if (f->form_details.border)
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
  A4GL_start_form (f);

  if ((attrib & 0xff) == 0 || (attrib & 0xff) == 0xff)
    {
      attrib = attrib + ' ';
      A4GL_debug ("Set pad char to space");
    }
  A4GL_debug ("Setting attribute for form to 0x%x \n", attrib);

  nattr = A4GL_LL_decode_aubit_attr (attrib, 'w');
  wbkgd (drwin, nattr);
  wbkgdset (drwin, nattr);



  A4GL_clr_form (0);
  A4GL_debug ("And return");
	A4GL_debug("su");
  A4GL_LL_screen_update ();
  return w;
}




void
A4GL_LL_out_linemode (char *s)
{
  printf ("%s\n", s);
}


void
A4GL_LL_sleep (int n)
{
  sleep (n);
}


void
A4GL_LL_make_window_top (void *w)
{
  top_panel (w);
}






int scr_width = -1;
int scr_height = -1;



int
A4GL_LL_screen_width (void)
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

int
A4GL_LL_screen_height (void)
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

void
A4GL_LL_set_bkg (void *win, int attr)
{
  int nattr;
  nattr = A4GL_LL_decode_aubit_attr (attr, 'w');
  A4GL_debug ("A4GL_LL_set_bkg %p %x", panel_window (win), nattr);
  wbkgd (panel_window (win), nattr);
  wbkgdset (panel_window (win), nattr);
}


int A4GL_LL_decode_aubit_attr (int a, char s)
{
  char colour[20];
  char attr[256];
  int ca;			/* Curses attribute */
  static int noinvis=-1;

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
      ca = A4GL_decode_colour_attr_aubit (a);
      if (strstr (attr, "REVERSE"))
	ca += A_REVERSE;
      if (strstr (attr, "INVISIBLE"))
	ca += A_INVIS;
      if (strstr (attr, "UNDERLINE"))
	ca += A_UNDERLINE;
    }
//A4GL_debug("Returning ca = %d %x (visible=%d)",ca,ca,!(ca&A_INVIS));
  if (noinvis==-1) {
	noinvis=A4GL_isyes (acl_getenv ("NO_INVIS_ATTR"));
  }
  if (noinvis) 
    {
      if (ca & A_INVIS)
	ca -= A_INVIS;
    }

  return ca;
}



int A4GL_LL_decode_colour_attr_aubit(int a) {
  char colour[20];
  char attr[256];
//int col;
  //A4GL_debug ("MJA Decoding %d",a);
  A4GL_get_strings_from_attr (a, colour, attr);

  //A4GL_debug ("MJA Got colour as : %s - %s", colour,attr);
  A4GL_trim(colour);

  if (strlen(colour)==0) {
	A4GL_debug("No colour..");
		return A4GL_LL_colour_code(COLOR_WHITE);
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
  if (strcmp (colour, "WHITE") == 0) {
		A4GL_debug("Its white.. %d",A4GL_LL_colour_code (COLOR_WHITE));
    return A4GL_LL_colour_code (COLOR_WHITE);
	}

A4GL_debug("No match for colour...");

  return 0;

}

void *
A4GL_LL_make_field (void *prop,int frow, int fcol, int rows, int cols)
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
	  if (!A4GL_isyes (acl_getenv ("EXTENDED_GRAPHICS")))
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
	  A4GL_form_set_field_opts (f, A4GL_form_field_opts (f) & ~O_ACTIVE);
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
      //A4GL_mja_set_field_buffer (f, 0, label);
      A4GL_form_set_field_opts (f, A4GL_form_field_opts (f) & ~O_ACTIVE);
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

int
A4GL_LL_set_new_page (void *field, int n)
{
  return A4GL_form_set_new_page (field, n);
}


void
A4GL_LL_set_field_userptr (void *field, void *ptr)
{
  A4GL_form_set_field_userptr (field, ptr);
}

void *
A4GL_LL_get_field_userptr (void *field)
{
  return A4GL_form_field_userptr (field);
}

void
A4GL_LL_set_field_attr (void *field)
{
  struct struct_scr_field *f;
  int bc;
  int fc;
  bc = A4GL_form_field_back (field);
  fc = A4GL_form_field_fore (field);

  A4GL_debug ("In set_field_attr");
  f = (struct struct_scr_field *) (A4GL_form_field_userptr (field));
  if (f == 0)
    return;
  A4GL_debug ("Setting defs");
  A4GL_default_attributes (field, f->datatype);
  A4GL_debug ("Set defs");

  if (A4GL_has_bool_attribute (f, FA_B_AUTONEXT))
    {
      A4GL_debug ("Autoskip");
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_on (field, O_AUTOSKIP);
    }

  if (A4GL_has_bool_attribute (f, FA_B_INVISIBLE))
    {
      A4GL_debug ("Invisible ***");
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_off (field, O_PUBLIC);
    }

  if (f->dynamic != 0)
    {
      A4GL_debug ("ZZZZ - SET OPTS STATIC OFF");
      A4GL_form_field_opts_off (field, O_STATIC);

      if (f->dynamic == -1)
	{
	  A4GL_debug ("Max size is lots CARAT");
	  A4GL_form_set_max_field (field, 0);
	}
      else
	{
	A4GL_debug("set max field : %d\n",f->dynamic);
	  A4GL_form_set_max_field (field, f->dynamic);
	  A4GL_debug ("Max size=%d CARAT", f->dynamic);
	}

    }
  else
    {
      A4GL_form_field_opts_off (field, O_STATIC);
      A4GL_form_set_max_field (field, A4GL_get_field_width(field));
      //field_opts_on (field, O_STATIC);
    }

  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY))
    {
      A4GL_debug ("No entry");
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_off (field, O_ACTIVE);
      A4GL_form_field_opts_off (field, O_EDIT);
    }
  if (A4GL_has_bool_attribute (f, FA_B_REQUIRED))
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_off (field, O_NULLOK);
    }
  else
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_on (field, O_NULLOK);
    }

  if (A4GL_has_bool_attribute (f, FA_B_COMPRESS))
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_form_field_opts_on (field, O_WRAP);
    }

  //A4GL_set_field_colour_attr (field, f->do_reverse, f->colour); // MJA REMOVE COLOUR FROM X

}




void *
A4GL_LL_new_form (void *vfd)
{
struct s_form_dets *fd;
fd=vfd;

  return A4GL_form_new_form ((FIELD **) fd->form_fields);
}

void
A4GL_LL_set_form_userptr (void *form, void *data)
{
  A4GL_form_set_form_userptr (form, data);
}

void *
A4GL_LL_get_form_userptr (void *form)
{
  return A4GL_form_form_userptr (form);
}



char *
A4GL_LL_field_buffer (void *field, int n)
{
  return A4GL_form_field_buffer (field, n);
}


void
A4GL_LL_set_field_buffer (void *field, int n, char *str)
{
int a;
A4GL_debug("LL_set_field_buffer : '%s' ",str);
  a=A4GL_form_set_field_buffer (field, n, str);
A4GL_debug("set_field_buffer : %s returns %d field buffer=%s opts=%x",str,a,A4GL_form_field_buffer(field,n),A4GL_form_field_opts(field));
A4GL_debug_print_field_opts(field);

}



int
A4GL_LL_field_opts (void *field)
{
  return A4GL_form_field_opts (field);
}


int
A4GL_LL_set_field_opts (void *field, int oopt)
{
  A4GL_debug ("SET FIELD OPTS : STATIC %x ", oopt & O_STATIC);
  A4GL_form_set_field_opts (field, oopt);
return A4GL_LL_field_opts(field);
}


void
A4GL_LL_set_field_fore (void *field, int attr)
{
  A4GL_form_set_field_fore (field, attr);
}


void
A4GL_LL_set_field_back (void *field, int attr)
{
  A4GL_form_set_field_back (field, attr);
}


void
A4GL_LL_set_current_field (void *form, void *field)
{
  A4GL_form_set_current_field (form, field);
}


void
A4GL_LL_set_carat (void *form)
{
PANEL *w;
  A4GL_form_pos_form_cursor (form);
  A4GL_debug("CURSES : set_carat");


  //w = (PANEL *) A4GL_get_currwin ();
  //wrefresh(panel_window(w));
  //A4GL_LL_screen_update();
  
}


int
A4GL_LL_getch_swin (void *window_ptr)
{
  int a;
  //if (A4GL_isgui ()) { return A4GL_get_gui_char (); }
  //A4GL_reset_processed_onkey();
  A4GL_debug ("Reading from keyboard on window %p", window_ptr);
  A4GL_set_abort (0);
  a = A4GL_readkey ();
  if (a != 0)
    {
      A4GL_debug ("Read %d from keyfile", a);
      return a;
    }

  while (1)
    {
      halfdelay (1);
      //a = wgetch (window_ptr);
      a = getch ();
#ifdef __MINGW32__
if (a==3) abort_pressed=1;
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

      if (a != -1)
	{
	  A4GL_debug ("MJAC Key Pressed %d", a);
	  break;
	}

    }
  cbreak ();
  a = A4GL_curses_to_aubit (a);	// Convert it to an aubit key...
  A4GL_chk_for_screen_print (a);
  A4GL_logkey (a);
  A4GL_debug ("Got char from keyboard : %d F2=%d LEFT=%d 4GL for f5 = %d", a,
	      KEY_F (2), KEY_LEFT, A4GLKEY_F (5));
  return a;
}


int
A4GL_LL_get_carat (void *form)
{
  FORM *mform;
  mform = form;
  A4GL_debug ("get CARAT : %d in %p", mform->curcol, A4GL_form_current_field (mform));
  return mform->curcol;
}

int
A4GL_LL_int_form_driver (void *mform, int mode)
{
int a;
  a=A4GL_form_form_driver (mform, mode);
  A4GL_debug("int_form_Driver %p %x = %d",mform,mode,a);
	return a;
	//return 1;
}

void *
A4GL_LL_current_field (void *form)
{
  return A4GL_form_current_field (form);
}

void
A4GL_LL_set_form_page (void *form, int page)
{
  A4GL_form_set_form_page (form, page);
}

int
A4GL_LL_form_page (void *form)
{
  return A4GL_form_form_page (form);
}


void *
A4GL_LL_create_errorwindow (int h, int w, int y, int x, int attr, char *str)
{
  WINDOW *win;
  PANEL *p;
char buff[255];
  A4GL_debug ("Creating errorwindow h=%d w=%d y=%d x=%d attr=%d str=%s", h, w,
	      y, x, attr, str);
  win = newwin (h, w, y, x);
  A4GL_debug ("win=%p", win);
  p = new_panel (win);
  A4GL_debug ("new_panel p=%p", p);
  if (attr == 0)
    attr = A_REVERSE;		//+A4GL_colour_code (COLOR_RED);
  else
    attr = A4GL_LL_decode_aubit_attr (attr, 'w');
  wattrset (win, attr);
  wprintw (win, "%s", str);

  strcpy(buff,str);
  A4GL_trim(buff);

  if (strlen(buff)) {
	A4GL_LL_beep();
  }

  return p;
}

void
A4GL_LL_delete_errorwindow (void *curr_error_window)
{
  A4GL_LL_remove_window (curr_error_window);

}

int
A4GL_LL_field_status (void *field)
{
  return A4GL_form_field_status (field);
}


int
A4GL_LL_dump_screen (int n)
{
  FILE *f;
  int sh;
  int sw;
  int x, y;
  int attr;
  char *ptr = 0;
  WINDOW *w;
  int mode = 1;
  char *buff;

	#ifdef DEBUG
		A4GL_debug ("Begin dump screen");
	#endif
  
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

  if (n != 0)
    {
      A4GL_trim (ptr);
    }

  if (mode == 3)
    {
	#if ! defined(__MINGW32__)
		scr_dump (ptr);
	#else
		A4GL_debug ("scr_dump not implemented in PDcurses");
	#endif
      return 0;
    }

  sh = A4GL_LL_screen_height ();
  sw = A4GL_LL_screen_width ();

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
      A4GL_debug ("AUTO PRINT...");
      // We want to dump to to PRINTSCRFILE
      ptr = acl_getenv ("PRINTSCRFILE");
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
      	if (ptr[0] == '+') {
	  f = fopen (&ptr[1], "a");
	} else {
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
	      fprintf (f, "%c%c", buff[2], attr & 255);
	    }

	  if (mode == 1)
	    {


	      if ((attr & 0xff) == (ACS_VLINE & 0xff)
		  && (attr & A_ALTCHARSET))
		{
		  attr = (int) '|';
		}
	      if ((attr & 0xff) == (ACS_HLINE & 0xff)
		  && (attr & A_ALTCHARSET))
		{
		  attr = (int) '-';
		}
	      if ((attr & 0xff) == (ACS_LLCORNER & 0xff)
		  && (attr & A_ALTCHARSET))
		{
		  attr = (int) '+';
		}
	      if ((attr & 0xff) == (ACS_LRCORNER & 0xff)
		  && (attr & A_ALTCHARSET))
		{
		  attr = (int) '+';
		}
	      if ((attr & 0xff) == (ACS_URCORNER & 0xff)
		  && (attr & A_ALTCHARSET))
		{
		  attr = (int) '+';
		}
	      if ((attr & 0xff) == (ACS_ULCORNER & 0xff)
		  && (attr & A_ALTCHARSET))
		{
		  attr = (int) '+';
		}
	      fprintf (f, "%c", attr & 255);
	    }
	}
      fprintf (f, "\n");
    }
  fclose (f);
  return 0;
}

int
A4GL_LL_set_field_status (void *f, int stat)
{
  return A4GL_form_set_field_status (f, stat);
}


void
A4GL_LL_move_window (void *w, int y, int x)
{
  move_panel (w, y, x);
}


void
A4GL_LL_hide_window (void *w)
{
  hide_panel (w);
}



void
A4GL_LL_show_window (void *w)
{
  show_panel (w);

}

void
A4GL_LL_gui_run_til_no_more ()
{
  // Not implemented in TUI MODE
}


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

void
A4GL_LL_initialize_display ()
{
  A4GL_debug ("LL_initialize_display *************************");
  initscr ();
  if (A4GL_isyes(acl_getenv("NO_ALT_SCR"))) {
  	try_to_stop_alternate_view();
  }

  if (has_colors () == FALSE);
  else
    {
      start_color ();
      refresh ();
#ifndef __sun__
#ifndef __sparc__
#if ! defined(__MINGW32__)
		A4GL_debug ("use_default_colors not available");
      //curses function not available on Solaris (!!!!?????) and PDcurses
      use_default_colors ();
      have_default_colors = 1;
#endif
#endif
#endif
    }

  cbreak ();
  noecho ();
  nonl ();
  intrflush (stdscr, TRUE);
  keypad (stdscr, TRUE);
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
}






/************* PROMPT IMPLEMENTATION ************/

int prompt_last_key = 0;


int
A4GL_LL_prompt_loop (void *vprompt, int timeout,void *vevt)
{
  int a;
  void *p;
  int was_aborted = 0;
  struct aclfgl_event_list *evt;
int rblock;

  void *mform;

  struct s_prompt *prompt;
  prompt = vprompt;
  evt=vevt;

  A4GL_chkwin ();
  mform = prompt->f;

  A4GL_set_abort (0);

  p = prompt->win;

  if (prompt->mode == 1)
    {
      char buff[10024];
      strcpy (buff, A4GL_LL_field_buffer (prompt->field, 0));
      A4GL_trim (buff);

      A4GL_push_char (buff);
      prompt->mode = 2;

      if (prompt->f) {
		A4GL_form_unpost_form (prompt->f);
      		A4GL_clear_prompt (prompt);
	}
      return 0;
    }

  if (prompt->mode > 0)
    return 0;

      A4GL_form_pos_form_cursor (mform);
	A4GL_debug("su");
      A4GL_LL_screen_update ();
      abort_pressed = 0;
      was_aborted = 0;
      a = A4GL_LL_getch_swin (p);
      A4GL_clr_error_nobox ("prompt");

      prompt->processed_onkey = a;
      prompt_last_key = a;
      A4GL_set_last_key (a);

      prompt->lastkey = A4GL_get_lastkey ();

      if (abort_pressed) {
	//printf("INTERRUPT!");
      	A4GL_set_last_key ( A4GL_key_val ("INTERRUPT"));
	prompt_last_key 	= A4GL_key_val ("INTERRUPT");;
	prompt->lastkey		= A4GL_key_val ("INTERRUPT");;

      		if (!A4GL_has_event_for_keypress(prompt->lastkey,evt)) {
      			A4GL_push_null (DTYPE_CHAR, 1);
      			prompt->mode = 2;
      			A4GL_form_unpost_form (prompt->f);
      			A4GL_clear_prompt (prompt);
			return 0;
		}
	}

      A4GL_debug ("No lastkey..");
      rblock=A4GL_has_event_for_keypress(prompt->lastkey,evt);

      if (rblock) { // We appear to be all done here...
      		A4GL_push_null (DTYPE_CHAR, 1);
      		prompt->mode = 2;
      		A4GL_form_unpost_form (prompt->f);
      		A4GL_clear_prompt (prompt);
		prompt->f=0;
		return rblock;
      } 
      
    if (was_aborted)  {
		prompt->mode=2;
		return 0;
	}
    
    a = A4GL_proc_key_prompt (a, mform, prompt);


  if (a == 0)
    {
#ifdef DEBUG
      {
	A4GL_debug ("a==0");
      }
#endif
      return 0;
    }
#ifdef DEBUG
  {
    A4GL_debug ("a==%d", a);
  }
#endif

  if (a < 0)
    return a;

  A4GL_debug ("Requested..");
  //if (prompt->lastkey == 10 || prompt->lastkey == 13)
  if (a == 10 || a == 13)
    {
      prompt_last_key = 0;
      A4GL_LL_int_form_driver (mform, AUBIT_REQ_VALIDATION);
      //A4GL_zrefresh ();
      //wrefresh (p);
	A4GL_debug("su");
      A4GL_LL_screen_update();
      A4GL_debug ("Return pressed");
      prompt->mode = 1;
      return 0;
    }

  A4GL_debug ("Requesting Validation : %p %x %d", mform, a, a);
  if ((a_isprint (a) ))
    {
	A4GL_debug("Printable");
      A4GL_LL_int_form_driver (mform, a);
      A4GL_debug ("Called int_form_driver");
      A4GL_LL_int_form_driver (mform, AUBIT_REQ_VALIDATION);
    }



	A4GL_debug("su");
      A4GL_LL_screen_update();

  if (prompt->charmode)
    {
  	if ((isprint (a)))
	{
	  A4GL_push_char (A4GL_LL_field_buffer (prompt->field, 0));
   	  A4GL_form_unpost_form (prompt->f);
      	  A4GL_clear_prompt (prompt);
	  prompt->f=0;
	  prompt->mode = 2;
	}
    }

A4GL_debug("Done..");
  return -1000;
}



int
A4GL_LL_start_prompt (void *vprompt, int ap, int c, int h, int af)
{
  char *promptstr;
  int promptline;
  struct s_prompt *prompt;
  void *sarr[3];
  void *p;
  void *d;
  void *cw;
  void *f;
  WINDOW *pp;
  int width;
  char buff[300];
  int a;
  int field_cnt = 0;
  A4GL_chkwin ();
  prompt = vprompt;
  A4GL_debug ("In start prompt %p %d %d %d %d", prompt, ap, c, h, af);
  prompt_last_key = 0;
  memset (buff, ' ', 255);
  promptline = A4GL_getprompt_line ();
  A4GL_debug ("promptline=%d", promptline);
  width = UILIB_A4GL_get_curr_width ();
  A4GL_debug ("create window %d %d", 1, promptline);
  A4GL_debug ("%d %d", width - 1, 2);
  cw = (void *) A4GL_get_currwin ();
  if (UILIB_A4GL_iscurrborder ())
    promptline++;


 A4GL_debug("panel_window (cw)=%d , width=%d, promptline - 1 =%d UILIB_A4GL_iscurrborder ()=%d", panel_window (cw), width, promptline - 1, UILIB_A4GL_iscurrborder ());

  p = derwin (panel_window (cw), 1, width, promptline - 1, UILIB_A4GL_iscurrborder ());


  if (p == 0)
    {
      A4GL_exitwith ("No prompt window created");
      return 0;
    }
  prompt->win = p;
  buff[width] = 0;
	A4GL_debug("su");
  wprintw (p, "%s", buff); A4GL_LL_screen_update();
  promptstr = A4GL_char_pop ();
  prompt->mode = 0;
  prompt->h = h;
  prompt->insmode = 0;
  prompt->charmode = c;
  prompt->promptstr = promptstr;
  prompt->lastkey = 0;
  width -= strlen (promptstr);
  width--;

  if (strlen (promptstr))
    {
      sarr[field_cnt++] = (void *) A4GL_LL_make_label (0, 0, promptstr);
    }

  A4GL_debug ("Creating field %d %d %d", strlen (promptstr) + 1, 1, width - 1);
  A4GL_form_set_new_page (sarr[field_cnt - 1], 1);
  sarr[field_cnt++] = (void *) A4GL_LL_make_field (0,0, strlen (promptstr), 1, width + 1);
  prompt->field = sarr[field_cnt - 1];
  sarr[field_cnt++] = 0;	/* (void *) A4GL_make_label (0, strlen(promptstr)+width-1,"|"); */

  /* set_field_pad(sarr[1],' '); */
  A4GL_debug ("set field to =%p", prompt->field);
  A4GL_debug ("Field=%p", prompt->field);

  /* A4GL_default_attributes (sarr[0], 0); */

  A4GL_default_attributes (prompt->field, 0);
  A4GL_debug ("STATIC OFF");
  A4GL_form_field_opts_off (prompt->field, O_STATIC);

  A4GL_debug ("ap=%d(%x) af=%d(%x)", ap, ap, af, af);
  ap = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, ap, 0, 0);
  af = A4GL_determine_attribute (FGL_CMD_INPUT, af, 0, 0);

  if (ap)
    {
      A4GL_debug ("AP...");
      if (strlen (promptstr))
	{
	  A4GL_LL_set_field_fore (sarr[0], A4GL_LL_decode_aubit_attr (ap, 'f'));
	  A4GL_LL_set_field_back (sarr[0], A4GL_LL_decode_aubit_attr (ap, 'b'));	// maybe need 'B' for whole field..
	}
    }

  //A4GL_LL_set_field_back (prompt->field, A4GL_LL_colour_code (0));
  //A4GL_LL_set_field_fore (prompt->field, A4GL_LL_colour_code (7));

  if (af)
    {
      A4GL_debug ("AF... %d",af);
      A4GL_LL_set_field_back (prompt->field, A4GL_LL_decode_aubit_attr (af, 'b'));
      A4GL_LL_set_field_fore (prompt->field, A4GL_LL_decode_aubit_attr (af, 'f'));	// maybe need 'B' for whole field..
      if (af & AUBIT_ATTR_INVISIBLE)
	{
	  A4GL_debug ("Invisible");
	  A4GL_form_field_opts_off (prompt->field, O_PUBLIC);
	}

    }

  A4GL_form_field_opts_on (prompt->field, AUBIT_O_NULLOK);
  A4GL_debug ("Set attributes");

  buff[0] = 0;			/* -2 */
  A4GL_debug ("Setting Buffer %p to '%s'", prompt->field, buff);
  A4GL_LL_set_field_buffer (prompt->field, 0, buff);
  A4GL_debug ("Set buffer ");

  //sarr[2] = 0;

  A4GL_debug ("Made fields");

  f = A4GL_form_new_form ((FIELD **) &sarr);
  A4GL_debug ("Form f = %p", f);
  prompt->f = f;
  A4GLSQL_set_status (0, 0);

  if (a4gl_status != 0)
    return (prompt->mode = 2);

/*
	When compiling with PDcurses:
	lowlevel/lowlevel_tui.c: In function `A4GL_LL_start_prompt':
	lowlevel/lowlevel_tui.c:2087: warning: dereferencing `void *' pointer
	lowlevel/lowlevel_tui.c:2087: request for member `_begy' in something not a structure or union
	lowlevel/lowlevel_tui.c:2087: warning: dereferencing `void *' pointer
	lowlevel/lowlevel_tui.c:2087: request for member `_begx' in something not a structure or union
*/


  pp=(WINDOW *) p;
  d = derwin (pp, 0, 0, width + 1, 1);
  A4GL_form_set_form_win (f, d);
  A4GL_form_set_form_sub (f, p);
  A4GL_debug ("Set form win");
  a = A4GL_form_post_form (f);
  A4GL_debug ("Posted form=%d", a);



  A4GL_LL_int_form_driver (f, AUBIT_REQ_FIRST_FIELD);
  A4GL_LL_int_form_driver (f, AUBIT_REQ_OVL_MODE);
  A4GLSQL_set_status (0, 0);
	A4GL_debug("su");
  A4GL_LL_screen_update ();
  return 1;
}




static void A4GL_clear_prompt (struct s_prompt *prmt)
{
  PANEL *p;
#ifdef DEBUG
  A4GL_debug ("Clearing prompt...");
#endif
  p = prmt->win;
		A4GL_debug("delwin %p",p);
  delwin ((WINDOW *) p);
	A4GL_debug("su");
  A4GL_LL_screen_update ();
}


void
A4GL_LL_scale_form (void *vf, int *y, int *x)
{
  struct s_form_dets *f;
	f=vf;
  A4GL_form_scale_form (f->form, y, x);
  A4GL_debug ("y=%d x=%x", y, x);
}

int A4GL_LL_get_field_width_dynamic (void *f)
{
  int x, y, a;
  A4GL_form_dynamic_field_info (f, &y, &x, &a);
  return x * y;
}

int
A4GL_LL_get_field_width (void *f)
{
  //int x, y, a;
	int w;
  struct s_form_dets *formdets;
  struct s_scr_field *fprop;
  fprop = (struct s_scr_field *) (A4GL_LL_get_field_userptr (f));
  formdets = (struct s_form_dets *)A4GL_get_curr_form (0); 
  if (formdets==0||fprop==0) {
	return A4GL_LL_get_field_width_dynamic(f);
  }

  w=formdets->fileform->metrics. metrics_val[A4GL_get_metric_for (formdets, f)].w;

  return w;
}


void A4GL_LL_set_max_field (void *f, int n)
{
int a;
	A4GL_debug("set max field : %d\n",n);
	if (n==0)  {
  		a=A4GL_form_set_max_field (f, 0);
	} else {
		FIELD *rfield;
		rfield=f;
		if (rfield->dcols>n) rfield->dcols=n;
  		a=A4GL_form_set_max_field (f, n);
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

int A4GLHLUI_initlib(void) {
	return 0;
}


// Not available in TUI mode...
int A4GL_LL_endis_fields_ap(int n,void* ap)
{
return 0;
}


int A4GL_LL_open_gui_form (char *name_orig, int absolute, int nat, char *like, int disable, void *handler_e, void *phandler_c) {
// Not in TUI mode you don't....
return 0;
}





int A4GL_LL_disp_form_fields_ap(int n,int attr,char* formname,va_list* ap) {
	return 0;
}


int A4GL_LL_set_window_title(int nargs) {
	return 0;
}




int A4GL_LL_widget_name_match(void* w,char* name) {
	return 0;
}




int A4GL_LL_fieldnametoid(char* f,char* s,int n) {
	return 0;
}

void A4GL_LL_clr_form_fields(int to_defaults,char* defs) {
return ;
}


/* 
** orig     = original string
** evt      = original event list from contruct..
** init_key = initial keystroke that caused us to be here.. (0 for before field)
** init_pos = position in field as retrived from the original field..
*/
int A4GL_LL_construct_large(char *orig, struct aclfgl_event_list *evt,int init_key,int initpos,char *left,char *right) {
	static char rbuff[1024];
	//static char rbuff2[1024];
	FIELD *buff[4];
	PANEL *cwin;
	WINDOW *drwin;
	FORM *f;
	int ins_ovl='o';
	int looping=1;
	int fl=0; // comment line...
	int fwidth;
	int a;
	A4GL_debug("In construct_large");

	strcpy(rbuff,orig);
	A4GL_trim(rbuff);
	fwidth=UILIB_A4GL_get_curr_width (); 
	if (fwidth>80) fwidth=80;
        cwin = (PANEL *) A4GL_get_currwin ();
  	fl = A4GL_getcomment_line ();
  	if (fl > UILIB_A4GL_get_curr_height ()) fl = UILIB_A4GL_get_curr_height ();
        drwin = derwin (panel_window ((PANEL *) cwin), 1, fwidth, fl-1, 0);

	buff[0]=A4GL_LL_make_label(0,0,left);
	buff[1]=A4GL_LL_make_field(0,0,1,1,fwidth-2);
        A4GL_field_opts_on (buff[1], AUBIT_O_ACTIVE);
        A4GL_field_opts_on (buff[1], AUBIT_O_EDIT);
        A4GL_field_opts_on (buff[1], AUBIT_O_BLANK);
        //set_max_field(buff[1],fwidth-2);


	buff[2]=A4GL_LL_make_label(0,fwidth-1,right);
	buff[3]=0;

	f=A4GL_form_new_form(buff);

        A4GL_form_set_form_win (f, panel_window(cwin));
        A4GL_form_set_form_sub (f, drwin);
	a=A4GL_form_post_form(f);
	A4GL_debug("construct - post_form = %d",a);
	A4GL_mja_set_field_buffer(buff[1],0,rbuff);

	A4GL_debug("su");
	A4GL_LL_screen_update();

	A4GL_LL_int_form_driver(f,AUBIT_REQ_FIRST_FIELD);
	A4GL_LL_int_form_driver(f,AUBIT_REQ_OVL_MODE);
	if (f->current==0) {
		A4GL_debug("Still not current...");
	}
	if (initpos) {
		//for (a=0;a<=initpos;a++) {
			//A4GL_LL_int_form_driver(f,AUBIT_REQ_NEXT_CHAR);
		//}
		A4GL_LL_int_form_driver(f,AUBIT_REQ_END_FIELD);
	}
			


	while (looping) {
		A4GL_LL_set_carat(f);
	A4GL_debug("su");
		A4GL_LL_screen_update();
		a=A4GL_LL_getch_swin (panel_window(cwin));
		A4GL_debug("construct_large a=%d abort_pressed=%d",a,abort_pressed);
		if (abort_pressed||a==A4GLKEY_INTERRUPT || a==A4GLKEY_CANCEL) {break;}
		if (A4GL_has_event_for_keypress(a,evt)) return a;



		switch (a) {

			case 1: 
				if (ins_ovl=='o') {	
					ins_ovl='i';	
					A4GL_LL_int_form_driver(f,AUBIT_REQ_INS_MODE);
				} else {
					ins_ovl='o';	
					A4GL_LL_int_form_driver(f,AUBIT_REQ_OVL_MODE);
				}
				
			case 27:
			case A4GLKEY_DOWN:
			case A4GLKEY_UP: 
			case A4GLKEY_ENTER:
			case '\t': looping=0; break;

			case A4GLKEY_LEFT:
				if (A4GL_LL_get_carat(f)==0)  {looping=0;break;}
          			A4GL_LL_int_form_driver (f, AUBIT_REQ_PREV_CHAR);
				break;


    			case 127:
    			case 8:
    			case A4GLKEY_DC:
    			case A4GLKEY_DL:
    			case A4GLKEY_BACKSPACE: A4GL_LL_int_form_driver (f, AUBIT_REQ_DEL_PREV); break;
	
    			case 24: 		A4GL_LL_int_form_driver (f, AUBIT_REQ_DEL_CHAR);break;
			case A4GLKEY_RIGHT: 	A4GL_LL_int_form_driver (f, AUBIT_REQ_NEXT_CHAR);break;
			default : 		A4GL_LL_int_form_driver (f, a);break;
		}
		
	}

	A4GL_LL_int_form_driver(f,AUBIT_REQ_VALIDATION);
	strcpy(orig,A4GL_LL_field_buffer(buff[1],0));

	A4GL_debug("Unpost and delete...");
        A4GL_form_unpost_form(f);
 	A4GL_debug("delwin %p",drwin);
	delwin(drwin);
	A4GL_debug("su");
	A4GL_LL_screen_update();
	A4GL_comments(0);
	return a;
}

#ifdef NCURSES_VERSION
	#include <term.h>
	#define isprivate(s) ((s) != 0 && strstr(s, "\033[?") != 0)
#endif

void try_to_stop_alternate_view(void) {
#ifdef NCURSES_VERSION
    /*
     * Cancel xterm's alternate-screen mode.
     */
        if ( isprivate(enter_ca_mode) && isprivate(exit_ca_mode)) {
        /*
         * initscr() or newterm() already did putp(enter_ca_mode) as a side
         * effect of initializing the screen.  It would be nice to not even
         * do that, but we do not really have access to the correct copy of
         * the terminfo description until those functions have been invoked.
         */
        (void) putp(exit_ca_mode);
        (void) putp(clear_screen);
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
int A4GL_LL_disp_form_field_ap(int n,int attr,char* s,va_list* ap) {
  
#ifdef FIX_THIS_C_AND_P_FROM_GTK
  int a;
  int flg;
  struct s_form_dets *formdets;
  void **field_list;
  int nofields;
  void *w;
  struct struct_scr_field *fprop;
  a4gl_status = 0;

  A4GL_chkwin ();
  A4GL_debug ("In disp_fields");
  w = A4GL_find_pointer (s, WINCODE);

  formdets = (struct s_form_dets *)A4GL_find_form_for_win(w);

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
	A4GL_debug("su");
  A4GL_LL_screen_update ();
#else


  A4GL_debug ("FIXME: A4GL_LL_disp_form_field_ap() not implemented for TUI");

#endif


  return 0;
}


int A4GL_LL_disp_h_menu( ACL_Menu *menu) {
	return 0;
}


int A4GL_LL_menu_loop(ACL_Menu *menu) {
	return -1;
}



#ifdef WIDEC
void
A4GL_LL_wadd_wchar_xy_col (void *win, int x, int y, int oattr, wchar_t ch)
{
  int ch2;
  int attr;
  void *p;
  wchar_t buff[2];
  attr = A4GL_LL_decode_aubit_attr (oattr& 0xffffff00, 'w');
  buff[0]=ch;
  buff[1]=0;


  p = panel_window (win);
  if (!UILIB_A4GL_iscurrborder () || A4GL_get_currwinno () == 0)
    {
      x--;
      y--;
    }
  if (x < 0 || y < 0 || x > UILIB_A4GL_get_curr_width () || y > UILIB_A4GL_get_curr_height ());
  else {
		wattrset((WINDOW *)p,attr&0xffffff00);
		mvwaddwstr(p,  y, x, buff);
	}
}

void
A4GL_LL_wadd_wchar_xy_col_w (void *win, int x, int y, int oattr, wchar_t ch)
{
  int ch2;
  int attr;
  void *p;
  wchar_t buff[2];
  attr = A4GL_LL_decode_aubit_attr (oattr& 0xffffff00, 'w');
  buff[0]=ch;
  buff[1]=0;


  p = win;
  if (!UILIB_A4GL_iscurrborder () || A4GL_get_currwinno () == 0)
    {
      x--;
      y--;
    }
  if (x < 0 || y < 0 || x > UILIB_A4GL_get_curr_width () || y > UILIB_A4GL_get_curr_height ());
  else {
		wattrset((WINDOW *)p,attr&0xffffff00);
		mvwaddwstr(p,  y, x, buff);
	}
}

#endif


void * A4GL_LL_create_menu (void * m, char *id, int mode, void *handler) {
	A4GL_exitwith("Not in TUI mode");
	return 0;
}
