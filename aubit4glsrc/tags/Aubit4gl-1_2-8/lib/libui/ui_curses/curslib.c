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
# $Id: curslib.c,v 1.167 2010-01-07 09:22:05 mikeaubury Exp $
#*/

/**
 * @file
 * Curses middle level functions.
 *
 * I think it works as interface between i level like input, display,
 * input array and curses
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */
#ifndef lint
static char const module_id[] =
  "$Id: curslib.c,v 1.167 2010-01-07 09:22:05 mikeaubury Exp $";
#endif
/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>
#include "a4gl_lib_ui_tui_int.h"
#include <ctype.h>
#include <locale.h>		/* utf8 */
//#include <term.h>

char *a_strchr (char *s, char c);
/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define BLANK ' '
#define MAXFORM 8
#define A4GL_MAXWIDTH 80
#define MAXFIELDS 256
#define mja_strcmp(a,b) A4GL_mja_strncmp(a,b,0)

#ifndef strnicmp		/* typically in /usr/include/string.h */
#define strnicmp(a,b,c) A4GL_mja_strncmp(a,b,c)
#endif

#ifndef stricmp			/* typically in /usr/include/string.h */
#define stricmp(a,b) A4GL_mja_strncmp(a,b,0)
#endif

#define MAXENTS 1000
#define FILESIZE 64
#define message ERROR ERROR
/*
   #define getbegyx(w,y,x)      ((y) = getbegy(w), (x) = getbegx(w))
   #define getmaxyx(w,y,x)      ((y) = getmaxy(w), (x) = getmaxx(w))
   #define getn_wstr(s,n)               wgetn_wstr(stdscr,s,n)
   #define getparyx(w,y,x)      ((y) = getpary(w), (x) = getparx(w))
   #define getnstr(ws,n)                wgetnstr(stdscr,ws,n)
 */

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

WINDOW *curr_error_window = 0;
PANEL *curr_error_panel = 0;
int curr_error_panel_visible = 0;
//void A4GL_do_pause (void);
static int A4GL_local_get_curr_window_attr (void);

int have_default_colors = 0;

/* int aborted;*/
char arr[MAXFORM][MAXFIELDS][A4GL_MAXWIDTH];
char names[MAXFORM][MAXFIELDS][20];
int namescnt = 0;
int maxforms;
char formnames[MAXFORM][80];
char titledesc[80] = "Configuration Options";
int menu_line = 5;
char menutitle[80] = "Select Data to Change";
int inprompt = 0;
int inwin;
int curr_opt, max_opt;
/*int currattr = 0; */
char dirstr[100];
//int A4GL_mja_strncmp (char *a, char *b, int c);

int help_no, g_help_no;

//int txtfcolour = COLOR_WHITE;
//int txtbcolour = COLOR_BLACK;
int m_formno;

textarea set_mess;

char lastspeccnt = 0;
char lastspec[20][2][80];
char selected[1024];

char formdetails[MAXFORM][2048];
int init_curses_mode = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/
WINDOW *A4GL_window_on_top_ign_menu (void);
void try_to_stop_alternate_view (void);
int UILIB_A4GLUI_initlib (void);
//void A4GL_refresh_error_window(void) ;
//int A4GL_has_timeout(int a) ;

//static void a4gl_gettext (int l, int t, int r, int b, char *buf);
//static void message (textarea * area, char *str, int x, int a);
//static void A4GL_chktag (char *buff, int fno);
static void A4GL_menu_setcolor (ACL_Menu * menu, int typ);
//static void A4GL_set_value (int fno, char *buffer);
static int A4GL_menu_getkey (ACL_Menu * menu);
//static void A4GL_clear_menu (ACL_Menu * menu);
static void A4GL_h_disp_more (ACL_Menu * menu, int offset, int y, int pos);
//static void A4GL_newbox (textarea * area, int l, int t, int r, int b, int typ);
//static int A4GL_set_combi_opts (int n, char *lst, int lstwidth, int scwidth, char *nme);
//static void A4GL_copy_opts (int opt, int n, char *lst, int lstwidth, int x, int y, int w, int l, int h);
//static int A4GL_do_key_combi (int h);
//static void A4GL_combi_dispopts (int opt, char *lst, int lstwidth, int x, int y, int w, int l, int h, int type);
static int A4GL_getkey (void);
//static void A4GL_puttext (int x1, int y1, int x2, int y2, char *buf);
//static void A4GL_horiz_disp_opt (int row, int x, int y, int type);
static void A4GL_h_disp_title (ACL_Menu * menu, char *str);
//static char *A4GL_mfgets (char *s, int n, FILE * fp);
//static int A4GL_load_formdata (char *fname2, char *ftitle, int fno);
//static int wrapper_wgetch (WINDOW * w);
//static void A4GL_flatten_menu (ACL_Menu * menu);
//void A4GL_tui_printr (int refreshwin, char *fmt, ...);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/



/**
 *
 * @todo Describe function
 */
void
A4GL_error_nobox (char *str_orig, int attr)
{
  int eline;
//WINDOW *w=0;
//PANEL *p;
//PANEL *o;
  char str[512];

  A4GL_chkwin ();
  A4GL_debug ("start");
  print_panel_stack ();

  if (curr_error_panel_visible)
    {
      A4GL_clr_error_nobox ("A4GL_error_nobox");
    }
  eline = A4GL_geterror_line () - 1;
  A4GL_debug ("Eline=%d\n", eline);



  if (curr_error_window == 0)
    {
      A4GL_debug ("%d %d %d %d", 1, A4GL_screen_width () - 1, eline, 0);
      curr_error_window = newwin (1, A4GL_screen_width () - 1, eline, 0);

      if (curr_error_window == 0)
	{
	  A4GL_exitwith ("Internal error - couldn't create error window");
	  return;
	}

      A4GL_debug ("new_panel using %p", curr_error_window);

      if (curr_error_panel == 0)
	{
	  A4GL_debug ("AAA");
	  print_panel_stack ();
	  curr_error_panel = new_panel (curr_error_window);
	  A4GL_debug ("BBB");
	  print_panel_stack ();
	  set_panel_userptr (curr_error_panel, "error window");
	  A4GL_debug ("CCC");
	  print_panel_stack ();
	}
    }

  A4GL_debug ("Before");
  print_panel_stack ();

  show_panel (curr_error_panel);
  werase (curr_error_window);

  A4GL_debug ("After");
  print_panel_stack ();
  strcpy (str, str_orig);

  A4GL_subwin_gotoxy (curr_error_window, 1, 1, 0);
  if (attr == 0 || attr == -1)
    attr = A_REVERSE;		//+A4GL_colour_code (COLOR_RED);
  else
    attr = A4GL_decode_aubit_attr (attr, 'w');

  wattrset (curr_error_window, attr);

  A4GL_debug ("Calling subwin_print...");

  A4GL_subwin_print (curr_error_window, "%s", str);

  A4GL_debug ("Beeping because of error : %s", str);



  A4GL_dobeep();

  curr_error_panel_visible = 1;

  print_panel_stack ();
  UILIB_A4GL_zrefresh ();
}

void A4GL_dobeep() {
  if (A4GL_isyes (acl_getenv ("BEEPONERROR")))
    {
      beep ();
    }
  if (A4GL_isyes (acl_getenv ("FLASHONERROR")))
    {
      flash ();
    }
}

void
A4GL_refresh_error_window (void)
{
  if (curr_error_panel_visible)
    {
      show_panel (curr_error_panel);
      update_panels ();
      doupdate ();
    }
}


void
A4GL_clr_error_nobox (char *dbg_fromwhere)
{
  int a;
  A4GL_chkwin ();
  A4GL_debug ("MJA clr_error_nobox called from %s", dbg_fromwhere);
  if (curr_error_window)
    {
      curr_error_panel_visible = 0;
      A4GL_debug ("MJA Clear error");
      hide_panel (curr_error_panel);
      UILIB_A4GL_zrefresh ();
      return;
    }

  return;



  A4GL_push_empty_char ();
  a = A4GL_geterror_line ();
  A4GL_debug ("Error line = %d", a);
  A4GL_push_int (a);
  A4GL_push_int (1);

#ifdef DEBUG
  A4GL_debug ("YY REVERSE");
#endif
  A4GL_display_at (1, AUBIT_ATTR_REVERSE);
  print_panel_stack ();
}



#ifdef OLD
/**
 *
 * @todo Describe function
 */
void
A4GL_newbox (textarea * area, int l, int t, int r, int b, int typ)
{
  a4gl_gettext (l, t, r, b, area->buf);
  area->win_no = subwin (stdscr, b - t + 1, r - l + 1, t - 1, l - 1);
  touchwin (stdscr);
  werase (area->win_no);
  if (typ == BORDER_BOX)
    wborder (area->win_no, 0, 0, 0, 0, 0, 0, 0, 0);
  A4GL_mja_wrefresh (area->win_no);
  area->x1 = l;
  area->x2 = r;
  area->y1 = t;
  area->y2 = b;
}
#endif



/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_aclfgl_fgl_drawbox (int n)
{
  int x, y, w, h, c;
  int xx, yy;
//void *ptr=0;
  void *win;
  int chars_simple[] = { '-', '|', '+', '+', '+', '+' };
  int chars_normal[6];
  int *chars;

  int infx_to_curses[8];

  A4GL_chkwin ();
  chars_normal[0] = ACS_HLINE;
  chars_normal[1] = ACS_VLINE;
  chars_normal[2] = ACS_ULCORNER;
  chars_normal[3] = ACS_URCORNER;
  chars_normal[4] = ACS_LLCORNER;
  chars_normal[5] = ACS_LRCORNER;

  infx_to_curses[0] = AUBIT_COLOR_WHITE;
  infx_to_curses[1] = AUBIT_COLOR_YELLOW;
  infx_to_curses[2] = AUBIT_COLOR_MAGENTA;
  infx_to_curses[3] = AUBIT_COLOR_RED;
  infx_to_curses[4] = AUBIT_COLOR_CYAN;
  infx_to_curses[5] = AUBIT_COLOR_GREEN;
  infx_to_curses[6] = AUBIT_COLOR_BLUE;
  infx_to_curses[7] = AUBIT_COLOR_BLACK;



  if (A4GL_isyes (acl_getenv ("SIMPLE_GRAPHICS")))
    {
      chars = chars_simple;
    }
  else
    {
      chars = chars_normal;
    }

  if (n == 5)
    {
      c = A4GL_pop_int ();
      c = infx_to_curses[c % 8];
      A4GL_debug ("drawbox Been passed a colour");
    }
  else
    {
      A4GL_debug ("drawbox No colour");
      c = 0;
    }



  //x = A4GL_pop_int ()+A4GL_get_curr_left()-2+A4GL_get_curr_border();
  //y = A4GL_pop_int ()+A4GL_get_curr_top()-3+A4GL_get_curr_border();

  x = A4GL_pop_int () + A4GL_get_curr_border ();
  y = A4GL_pop_int () + A4GL_get_curr_border ();
  w = A4GL_pop_int ();
  h = A4GL_pop_int ();
  A4GL_debug ("In fgl_drawbox c=%d x=%d y=%d w=%d h=%d", c, x, y, w, h);
  A4GL_debug ("h=%d y+h=%d", h, y + h);
  //win=curscr;
  //win = A4GL_find_pointer ("screen", WINCODE);
  win = A4GL_window_on_top_ign_menu ();
  A4GL_debug ("Got win as %p from window_on_top", win);
  A4GL_debug ("ATTR = %d", A4GL_decode_colour_attr_aubit (c));
#define PMOVE(x,y,ch) 	mvwaddch(win,(y-1),(x-1),ch+A4GL_decode_colour_attr_aubit(c))


  for (xx = x + 1; xx < x + w - 1; xx++)
    {
      PMOVE (xx, y, chars[0]);

      PMOVE (xx, y + h - 1, chars[0]);
    }

  for (yy = y + 1; yy < y + h - 1; yy++)
    {
      PMOVE (x, yy, chars[1]);

      PMOVE (x + w - 1, yy, chars[1]);
    }

  PMOVE (x, y, chars[2]);
  PMOVE (x + w - 1, y, chars[3]);
  PMOVE (x, y + h - 1, chars[4]);
  PMOVE (x + w - 1, y + h - 1, chars[5]);



  A4GL_mja_refresh ();
  return 0;
}




/**
 *
 * @todo Describe function
 */
int
A4GL_do_key_menu (void)
{
  int a;
  abort_pressed = FALSE;
  a = A4GL_getkey ();
#ifdef DEBUG
  A4GL_debug (" do_key_menu...A=%d", a);
#endif

  if (a == UPKEY || a == LEFTKEY)
    {
      curr_opt = curr_opt - 1;
      if (curr_opt < 0)
	curr_opt = max_opt;
    }

  if (a == DOWNKEY || a == RIGHTKEY)
    {
      curr_opt = curr_opt + 1;
      if (curr_opt > max_opt)
	curr_opt = 0;
    }

  if (a == ESC || a == 'Q' || a == 'q') // IGNORE - nothing to do with ACCEPT
    {
#ifdef DEBUG
      A4GL_debug ("Abort Pressed in menu");
#endif
      abort_pressed = 1;
    }

  if (a == CR)
    {
#ifdef DEBUG
      A4GL_debug ("Enter !");
#endif
      return 1;
    }

  return 0;
}


#ifdef DO_WE_NEED
/**
 *
 * @todo Describe function
 */
void A4GL_clearbox (textarea * area)
{
  /*wclear(area->win_no); */
  delwin (area->win_no);
  A4GL_debug ("delwin : %p", area->win_no);
  A4GL_puttext (area->x1, area->y1, area->x2, area->y2, (area->buf));
}
#endif




/**
 *
 * @todo Describe function
 */
void
acllib_pause (char *s)
{
  char buff[80] = "Pausing...";
  char *p;
#ifdef DEBUG
  A4GL_debug ("Pausing in report");
#endif
  p = acl_getenv ("PAUSE_MSG");
  if (p)
    strcpy (buff, p);
#ifdef DEBUG
  A4GL_debug ("Got default of %s", buff);
#endif
  if (s != 0)
    {
      if (strlen (s) > 0)
	{
	  strcpy (buff, s);
	}
    }
#ifdef DEBUG
  A4GL_debug ("Actual=%s", buff);
#endif
  /* buff now contains our message */
  strcat (buff, "\n");
  A4GL_push_char (buff);
  A4GL_push_int (-1);
  A4GL_push_int (-1);
  A4GL_display_at (1, 0);
  fflush (stdout);
#ifdef DEBUG
  A4GL_debug ("Printed");
#endif
  fgetc (stdin);
}








/**
 *
 * @todo Describe function
 */
void
A4GL_setreledit (int x, int y)
{
  relxedit = x;
  relyedit = y;
}




#ifdef OLD
/**
 *
 * @todo Describe function
 */
static void
a4gl_gettext (int l, int t, int r, int b, char *buf)
{
  int cnt = 0;
/*   a4gl_gettext(l,t,r,b,area->buf); */
  int x, y;
  chtype retval;

  for (x = l - 1; x < r; x++)
    {
      for (y = t - 1; y < b; y++)
	{
	  A4GL_mja_gotoxy (x, y);
	  retval = mvinch (y, x);
	  memcpy (&buf[cnt += sizeof (chtype)], &retval, sizeof (chtype));	/*there is probably a better way to do this */
	}
    }
}
#endif


#ifdef REMOVED
/**
 *
 * @todo Describe function
 */
void
A4GL_puttext (int x1, int y1, int x2, int y2, char *buf)
{
  int x, y;
  int cnt = 0;
  chtype retval;
  for (x = x1; x <= x2; x++)
    {
      for (y = y1; y <= y2; y++)
	{
	  memcpy (&retval, &buf[cnt += sizeof (chtype)], sizeof (chtype));	/*there is probably a better way to do this */
	  A4GL_mja_gotoxy (x, y);
	  stdscr->_attrs = retval & A_ATTRIBUTES;
	  printw ("%c", retval & A_CHARTEXT);
	}
    }
  A4GL_mja_refresh ();
}
#endif


/**
 * Initialization of curses enviornment
 */
int
UILIB_A4GLUI_ui_init (int argc, char *argv[])
{
  A4GL_set_scrmode ('L');
  init_curses_mode = 0;
  return 1;
}




void
A4GL_init_curses_stuff ()
{
// Have we already done it ?
  if (init_curses_mode)
    {
      A4GL_debug ("init_curses_stuff Already done - returning");
      return;
    }
  init_curses_mode = 1;

#ifdef DEBUG
  A4GL_debug ("Initializing curses environment");
#endif
  initscr ();
  //traceon();


  if (A4GL_isyes (acl_getenv ("NO_ALT_SCR")))
    {
      try_to_stop_alternate_view ();
    }

  if (has_colors () == FALSE);
  else
    {
      start_color ();
      refresh ();
#ifndef __sun__
#ifndef __sparc__
#ifndef __MINGW32__
      //curses function not available on Solaris (!!!!?????)
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
  A4GL_init_windows ();


  A4GL_mja_gotoxy (1, 1);
  A4GL_tui_printr (1,"                                 ");
  UILIB_A4GL_zrefresh ();


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

}


/**
 *
 * @todo Describe function
 */
void
A4GL_startit (void)
{
  inwin = 1;
  A4GL_mja_refresh ();
}

/**
 *
 * @todo Describe function
 */
void
A4GL_endit (void)
{
  inwin = 0;
  A4GL_mja_endwin ();
}





/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_free_menu (void *menuv)
{
  ACL_Menu *menu;
  ACL_Menu_Opts *opt1, *opt2;
  menu = menuv;
#ifdef DEBUG
  {
    A4GL_debug ("Freeing menu");
  }
#endif
  opt1 = (ACL_Menu_Opts *) menu->first;
  while (opt1 != 0)
    {
      opt2 = (ACL_Menu_Opts *) opt1->next_option;
      free (opt1);
      opt1 = opt2;
    }
#ifdef DEBUG
  //A4GL_debug ("Attempting to delete window : %p", menu->menu_win);
#endif
  //A4GL_flatten_menu (menu);
  //A4GL_clear_menu (menu);
  update_panels ();
  doupdate ();
  UILIB_A4GL_zrefresh ();
#ifdef DEBUG
  A4GL_debug ("Menu=%p &Menu=%p", menu, &menu);
#endif
#ifdef DEBUG
  A4GL_debug ("Deleted window");
#endif
  return 1;
}

/**
 * 4GLCALL
 * @todo Describe function
 */
void
UILIB_A4GL_disp_h_menu (void *menuv)
{
  char disp_str[80];
  int disp_cnt;
  int disp_cnt2;
  int row;
  int cl, cpt, mnln, cw;
  char *parent_window;
  long attrib = 0;

  ACL_Menu *menu;
  menu = menuv;
  memset (disp_str, 0, sizeof (disp_str));
#ifdef DEBUG
  A4GL_debug ("Adding window for menu");
  A4GL_debug ("Current metrics : %d %d %d", A4GL_get_curr_left (),
	      A4GL_get_curr_print_top () - 1, UILIB_A4GL_get_curr_width ());
#endif

  cl = A4GL_get_curr_left ();
  cw = UILIB_A4GL_get_curr_width ()+1;
  cpt = A4GL_get_curr_print_top ();
  mnln = A4GL_getmenu_line () - 1;
  menu->menu_line = mnln;
  A4GL_debug ("Current window : %s", UILIB_A4GL_get_currwin_name ());
  attrib = (long) A4GL_find_pointer (UILIB_A4GL_get_currwin_name (), ATTRIBUTE);
  A4GL_debug ("Current window attrib = %d", attrib);
  parent_window = A4GL_find_pointer (UILIB_A4GL_get_currwin_name (), WINCODE);
  menu->gw_b = UILIB_A4GL_iscurrborder ();
  menu->gw_y = mnln + UILIB_A4GL_iscurrborder ();
  A4GL_debug ("setting gw_y %d %d %d %d px)", menu->gw_y, cpt, mnln,
	      UILIB_A4GL_iscurrborder ());
  menu->gw_x = cl;


  //strcpy (menu->window_name, A4GL_glob_window (cl, cpt - 1 + mnln - UILIB_A4GL_iscurrborder (), cw, 2, 0));

  attrib = attrib - (attrib & 0x20);

  menu->attrib = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, attrib, 0, 0);

  menu->w = cw;
  if ((attrib & 0xff) == 0)
    attrib = attrib + 32;

  //if (attrib) A4GL_set_bkg (menu->menu_win, A4GL_decode_aubit_attr (attrib, 'w'));

  if (menu->menu_type == ACL_MN_HORIZ_BOXED)
    menu->mn_offset = 1;
  else
    menu->mn_offset = 0;


  disp_cnt = 0;
  row = 0;
  disp_str[0] = 0;
  disp_cnt = 2;
  disp_cnt2 = 0;
  if (strlen (menu->menu_title) > 0)
    {
      if (menu->menu_type == ACL_MN_HORIZ_NOTBOXED)
	{
	  SPRINTF1 (disp_str, "%s:  ", menu->menu_title);
	  disp_cnt = strlen (disp_str) + 1;
	}
      else
	SPRINTF1 (disp_str, " %s ", menu->menu_title);
    }
  menu->menu_offset = disp_cnt;

  menu->menu_line = mnln;	// Shouldn't this be mnln - was 1
  abort_pressed = 0;
  A4GL_size_menu (menu);
  A4GL_display_menu (menu);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_menu_loop_v2 (void *menuv, void *vevt)
{
  ACL_Menu_Opts *old_option;
  //struct aclfgl_event_list *evt;
  //WINDOW *w;
  int a;
  int key_pressed;
  //int lcnt = 0;
  ACL_Menu *menu;

  menu = menuv;
  A4GL_chkwin ();
  A4GL_menu_setcolor (menu, NORMAL_TEXT);
  A4GL_current_window (menu->parent_window_name);
  A4GL_disp_h_menu (menu);
  A4GL_debug ("Refreshed window - going into while loop");

  while (1 == 1)
    {
      old_option = (ACL_Menu_Opts *) menu->curr_option;
      abort_pressed = FALSE;
      A4GL_h_disp_opt (menu, menu->curr_option, menu->menu_offset,
		       menu->mn_offset, INVERT);
      A4GL_menu_setcolor (menu, NORMAL_TEXT);



#ifdef DEBUG
      A4GL_debug ("Moved cursor for menu to %d %d", menu->menu_offset - 1,
		  menu->menu_line);
#endif



#ifdef DEBUG
      A4GL_debug (">>>> Getting key from menu");
#endif

      while (1)
	{
	  if (menu->evt)
	    {
	      int blk;
	      blk = A4GL_has_evt_timeout (menu->evt);
	      if (blk)
		{
		  return blk - 1;	// menu options are numbered from 0
		}
	    }

	  a = A4GL_menu_getkey (menu);
		if (a==3006) abort_pressed++;
		//printf("%d\n",a);
	  if (abort_pressed) {
		int_flag=1;
		a=A4GLKEY_INTERRUPT;
		}
	  if (a )
	    break;
	}


      if (menu->evt)
	{
	  A4GL_evt_not_idle (menu->evt);
	}


#ifdef DEBUG
      A4GL_debug (">>>> KEY=%d %d %d", a, A4GLKEY_HELP,
		  A4GL_is_special_key (a, A4GLKEY_HELP));
#endif


      if (A4GL_is_special_key (a, A4GLKEY_HELP))
	{
#ifdef DEBUG
	  A4GL_debug ("....SHOWHELP.... menu->curr_option->help_no=%d",
		      menu->curr_option->help_no);
	  A4GL_debug ("menu->curr_option=%p", menu->curr_option);
#endif
	  if (menu->curr_option->help_no)
	    {
	      int hlp;
	      hlp = menu->curr_option->help_no;
	      A4GL_debug ("Curroption=%p", menu->curr_option);
	      A4GL_push_int (hlp);
	      aclfgli_show_help (1);
	      A4GL_debug ("After show help Curroption=%p", menu->curr_option);
	      continue;
	    }
	}
	A4GL_debug("a=%d abort_pressed=%d",a,abort_pressed);

      A4GL_set_last_key(0);
      key_pressed = A4GL_new_do_keys (menu, a);
      A4GL_h_disp_opt (menu, old_option, menu->menu_offset, menu->mn_offset, NORM);
      A4GL_h_disp_opt (menu, menu->curr_option, menu->menu_offset, menu->mn_offset, INVERT);

	
      if (abort_pressed) {
		if (!key_pressed) {
	  		A4GL_debug ("setting menu->abort_pressed");
	  		menu->abort_pressed = 1;
	  		break;
		} else {
			abort_pressed=0;
		}
	}
      if (key_pressed)
	break;
    }
  A4GL_menu_setcolor (menu, NORMAL_TEXT);


  //A4GL_refresh_menu_window (menu->window_name, 0);
  //A4GL_refresh_menu_window (menu->window_name, 1);




  /*
     ptr = A4GL_find_pointer (name, PANCODE);
     A4GL_debug ("refresh menu with pointer to %p", ptr);
     rc = top_panel (ptr);
   */

  if (abort_pressed)
    {
      A4GL_debug ("Returning aborted");
      return menu->num_opts + 1;
    }
  if (strcmp (menu->curr_option->optkey, "EMPTY") != 0)
    {
      int opt_no;
      opt_no = menu->curr_option->opt_no;
      menu->curr_option = old_option;	// We don't want to change option to a non-printing option
      return opt_no;

    }
  old_option = (ACL_Menu_Opts *) menu->curr_option;
  A4GL_debug ("Returning %d", old_option->opt_no);
  return old_option->opt_no;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_display_menu (ACL_Menu * menu)
{
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *prev_opt = 0;
  int disp_cnt2 = 0;
  char disp_str[80];
  //char buff[256];
  int disp_cnt;
  int have_displayed = 0;

  memset (disp_str, 0, 80);
  A4GL_debug ("In display_menu");
  A4GL_current_window (menu->parent_window_name);


  A4GL_clr_menu_disp (menu);
  if (strlen (menu->menu_title) > 0)
    {
      if (menu->menu_type == ACL_MN_HORIZ_NOTBOXED)
	{
	  SPRINTF1 (disp_str, "%s: ", menu->menu_title);
	  disp_cnt = strlen (disp_str) + 1;
	}
      else
	SPRINTF1 (disp_str, " %s ", menu->menu_title);
    }


  A4GL_debug ("Printing titles....");
  A4GL_h_disp_title (menu, disp_str);


  UILIB_A4GL_zrefresh ();
  opt1 = (ACL_Menu_Opts *) menu->first;

  while (opt1 != 0)
    {
      /* opt1->optpos = -9; */
      A4GL_debug ("Option %s  attributes %d %d %d ", opt1->opt_title,
		  opt1->attributes, ACL_MN_HIDE,
		  opt1->attributes & ACL_MN_HIDE);
      if ((opt1->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
	{
#ifdef DEBUG
	  A4GL_debug ("OK to display - Page %d of %d", menu->curr_page,
		      opt1->page);
#endif
	  if (menu->curr_page == opt1->page)
	    {
	      if (have_displayed == 0)
		{
		  /* first one displayed */
		  have_displayed = 1;
		  A4GL_debug ("First option is %s", opt1->opt_title);
		  if (menu->curr_page != 0)
		    {
		      /* its not the first page print the ... at the beginning */
		      A4GL_h_disp_more (menu, menu->menu_offset,
					menu->mn_offset, disp_cnt2);
		      disp_cnt2 += 5;
		    }
		}
	      /* opt1->optpos = disp_cnt2; */
	      disp_cnt2 += strlen (opt1->opt_title);
	      A4GL_debug ("disp=%d width=%d %d %s page %d", disp_cnt2,
			  menu->w, menu->menu_offset, opt1->opt_title,
			  opt1->page);

	      if ((ACL_Menu_Opts *) menu->curr_option !=
		  (ACL_Menu_Opts *) opt1)
		A4GL_h_disp_opt (menu, opt1, menu->menu_offset,
				 menu->mn_offset, NORM);
	      else
		A4GL_h_disp_opt (menu, opt1, menu->menu_offset,
				 menu->mn_offset, INVERT);
	    }
	  else
	    {
	      A4GL_debug ("Option %s is out of view", opt1->opt_title);
	      if (prev_opt)
		{
		  A4GL_debug ("prev option=%p menu=%p");
		  A4GL_debug (" -> %d \n", prev_opt->page);
		  A4GL_debug (" -> = %d \n", menu->curr_page);
		  if (prev_opt->page == menu->curr_page)
		    {
		      A4GL_debug ("More More More!!!");
		      A4GL_h_disp_more (menu, menu->menu_offset,
					menu->mn_offset, disp_cnt2);
		    }
		}
	    }
	}
      prev_opt = (ACL_Menu_Opts *) opt1;
      opt1 = (ACL_Menu_Opts *) opt1->next_option;
    }
#ifdef DEBUG
  {
    A4GL_debug ("Displayed Menu");
  }
#endif
  A4GL_mja_refresh ();
}








/**
 *
 * @todo Describe function
 */
void
A4GL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y,
		 int type)
{

// @ FIXME
  A4GL_debug ("Printing %s at %d %d", opt1->opt_title, opt1->optpos + offset,
	      1);

  if (opt1->page != menu->curr_page)
    return;

  A4GL_menu_setcolor (menu, NORMAL_MENU);
  if ((opt1->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
    {
      if (offset > 2)
	A4GL_mja_gotoxy (1, 2 + menu->menu_line);
      else
	A4GL_mja_gotoxy (offset, 2 + menu->menu_line);


      A4GL_menu_setcolor (menu, NORMAL_MENU);


      if (type == INVERT)
	{
	  A4GL_tui_printr (0, "%s", A4GL_string_width (opt1->shorthelp));
	}

      if (A4GL_isyes (acl_getenv ("BRACKETMENU")))
	{
	  if (type == INVERT)
	    {
	      char buff[256];
	      A4GL_mja_gotoxy (opt1->optpos + offset, 1 + menu->menu_line);
	      strcpy (buff, opt1->opt_title);
	      buff[0] = '<';
	      buff[strlen (buff) - 1] = '>';
	      A4GL_tui_printr (0, "%s", buff);
	    }
	  else
	    {
	      A4GL_mja_gotoxy (opt1->optpos + offset, 1 + menu->menu_line);
	      A4GL_tui_printr (0, "%s", opt1->opt_title);
	    }
	}
      else
	{
	  A4GL_mja_gotoxy (opt1->optpos + offset, 1 + menu->menu_line);

	  if (type == INVERT)
	    A4GL_menu_setcolor (menu, INVERT_MENU);
	  else
	    A4GL_menu_setcolor (menu, NORMAL_MENU);

	  A4GL_tui_printr (0, "%s", opt1->opt_title);
	}
      A4GL_menu_setcolor (menu, NORMAL_MENU);
    }
}

/**
 *
 * @todo Describe function
 */
void
A4GL_h_disp_title (ACL_Menu * menu, char *str)
{
  A4GL_debug ("h_disp_title : %s", str);
  A4GL_mja_gotoxy (1, 1 + menu->menu_line);
  A4GL_menu_setcolor (menu, NORMAL_MENU);
  A4GL_debug ("Calling subwin_print...");
  A4GL_tui_printr (0, "%s", str);
  A4GL_menu_setcolor (menu, NORMAL_MENU);
  UILIB_A4GL_zrefresh ();
}




/**
 *
 * @todo Describe function
 */
static void
A4GL_h_disp_more (ACL_Menu * menu, int offset, int y, int pos)
{
  A4GL_debug ("MORE MARKERS : Displaying ... at %d %d", pos + offset, 1);
  A4GL_mja_gotoxy (pos + offset, 1 + menu->menu_line);
  A4GL_menu_setcolor (menu, NORMAL_MENU);
  A4GL_debug ("Calling subwin_print...");
  A4GL_tui_printr (0, " ...");
}




/**
 *
 * @todo Describe function
 */
void
A4GL_clr_menu_disp (ACL_Menu * menu)
{
  static char *buff = 0;
  int w;
  w = UILIB_A4GL_get_curr_width ();
  A4GL_menu_setcolor (menu, NORMAL_TEXT);
  A4GL_mja_gotoxy (menu->menu_offset - 1, 1 + menu->menu_line);
  buff = realloc (buff, w + 1);
  memset (buff, ' ', w);

  buff[w - menu->menu_offset + 2] = 0;
  A4GL_tui_printr (0, buff);
A4GL_debug("Clr menu : %s\n",buff);
}







/**
 * Renamed from err to curs_err (conflict on Datwin in -lSystem
 * @todo Describe function
 */
/*
void
curs_err (char *str)
{
  gotoxy (1, 23);
  printw ("%s", str);
  A4GL_mja_refresh ();
}
*/






/**
 *
 * @todo Describe function
 */
void
A4GL_clrscr (void)
{
  clear ();
  A4GL_mja_refresh ();
}



/**
 * @todo Describe function
 */
int
A4GL_getkey (void)
{
  char cmd[60] = "";
  int a;

  while (1)
    {
      a = A4GL_getch_win ();
#ifdef WIN32_BROKEN
      if (a == KEY_MOUSE)
	{
	  request_mouse_pos ();
	  if (BUTTON_CHANGED (3))
	    {
	      return 27;
	    }
	}
#endif
      if (a == 18)
	{
		clearok(curscr,1);
	  A4GL_mja_refresh ();
	  continue;
	}

      /*
         Provides equivalent of Informix bang() functionality -
         User gets the shell prompt after the SHIFT+! key sequence while
         in MENU, or other input statement, and can enter single line command
         that will be passed to the shell for execution.

         FIXME: this should not use -D, but acl_getenv(A4GL_AUTOBANG) instead
       */
      /* #ifdef AUTOBANG */
      if (strcmp (acl_getenv ("A4GL_AUTOBANG"), "1") != 0)
	{
	  if (a == '!' && !inprompt)
	    {
	      inprompt = 1;
	      A4GL_ask_cmdline ("Enter Command", cmd, 60);

	      if (!abort_pressed && strlen (cmd))
		{
		  A4GL_mja_endwin ();
		  system (cmd);


		  PRINTF ("\n\nPress return to continue\n");
		  fflush (stdout);
		  while (getc (stdin) != '\n');

		  clearok (curscr, 1);
		  A4GL_mja_refresh ();
		}
	      inprompt = 0;
	      //return -1;
	      continue;
	    }
	}
      else
	{
	  /* #endif */
	  return a;
	}
    }				/* end while */
}

void
A4GL_ask_cmdline (char *prompt, char *s, int a)
{
  char lv_cmd[100 + 1];
  //int x;
  //int y;
  int_flag = 0;
  A4GL_push_long (UILIB_A4GL_get_curr_height ());
  A4GL_push_long (1);
  A4GL_push_long (1);
  A4GL_push_long (UILIB_A4GL_get_curr_width ());
  UILIB_A4GL_cr_window ("aclfgl_promptwin", 1, 255, 255, 1, 255, 0, 255, 255,
                        (0x0),0,0);
  A4GL_push_char ("!");
//START_BLOCK_1:
  {
    char _p[36];
    int _fld_dr;
    UILIB_A4GL_start_prompt (&_p, 0, 0, 0, 0,"","");
    while (GET_AS_INT ("s_prompt", _p, "mode") != 2)
      {
        static struct aclfgl_event_list _sio_evt[] = { {0} };

        _fld_dr = UILIB_A4GL_prompt_loop_v2 (&_p, 0, _sio_evt);
        //CONTINUE_BLOCK_1:;      /* add_continue */
      }
    A4GL_pop_var (&lv_cmd, 6553600);
  }
//END_BLOCK_1:;
  aclfgli_clr_err_flg ();
  if (int_flag)
    strcpy (lv_cmd, "");
  A4GL_trim (lv_cmd);
  lv_cmd[a] = 0;
  strcpy (s, lv_cmd);
  UILIB_A4GL_remove_window ("aclfgl_promptwin");
}



/**
 * 4GL CALL
 * @todo Describe function
 */
void
UILIB_aclfgli_pr_message_internal (int attr, int wait, char *s)
{
  char p[2048];
  long w;
  int ml;
  int width;
  char *beepchr;
  WINDOW *cw;
  char buff[512];
  static WINDOW *mw;
  A4GL_chkwin ();
  A4GL_debug ("In message...");
  cw = (WINDOW *) A4GL_get_currwin ();
  ml = A4GL_getmessage_line ();




  if (ml < 0)
    {
      A4GL_exitwith ("Internal error - negative messageline");
      return;
    }
  A4GL_debug ("MJA - Got message line as %d - %s\n", ml, s);
  width = UILIB_A4GL_get_curr_width ();

  strcpy (p, s);

  while (1)  {
          beepchr=strchr(p,'\007');
	          if (!beepchr) break;
		          *beepchr=' ';
			          A4GL_dobeep();
				    }



  if (strlen (p) == 0)
    {
      memset (p, ' ', sizeof (p));
      p[UILIB_A4GL_get_curr_width ()] = 0;

    }
  A4GL_debug ("Message : '%s'", p);
  A4GL_push_char (p);

  A4GL_debug (" Wait =%d\n", wait);

  if (wait == 0)
    {
      // Blank out the line...
      memset (buff, ' ', sizeof (buff));
      buff[UILIB_A4GL_get_curr_width ()] = 0;
      A4GL_push_char (buff);
      A4GL_push_int (ml);
      A4GL_push_int (1);
      A4GL_display_at (1, 0);

      A4GL_push_int (ml);
      A4GL_push_int (1);
      A4GL_display_at (1, attr);
    }
  else
    {
      /* Need to pad this out later... */
      A4GL_push_int (ml);
      A4GL_push_int (1);
      A4GL_display_at (1, attr);
		while (A4GL_getch_win()<=0) ;
    }
  return;			/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

  A4GL_debug (" NW PTR");
  SPRINTF1 (buff, "MS%p", cw);

  if (A4GL_has_pointer (buff, MESSAGEWIN))
    {
      mw = A4GL_find_pointer (buff, MESSAGEWIN);
      A4GL_debug ("Removing old message window... %p", mw);
      delwin (mw);
      A4GL_debug ("delwin : %p", mw);
      A4GL_del_pointer (buff, MESSAGEWIN);
      wsyncup (cw);
      touchwin (cw);
      wrefresh (cw);
      A4GL_mja_refresh ();
    }

  if (strlen (p))
    {
      A4GL_debug ("Creating new message window");
      mw =
	derwin (cw, 1, width, ml - 1 + UILIB_A4GL_iscurrborder () * 2,
		A4GL_iscurrborder ());
      A4GL_debug ("Created window %p", mw);
      touchwin (mw);
      A4GL_add_pointer (buff, MESSAGEWIN, mw);
      A4GL_debug ("Message String : %s", p);
      w = A4GL_xwattr_get (mw);
      A4GL_debug ("Got old attr");
      wattrset (mw, attr);
      wprintw (mw, "%s", p);
      wattrset (mw, w);
      A4GL_debug ("Reset attributes");
      wrefresh (mw);
      wrefresh (cw);
    }
  A4GL_mja_refresh ();
  //A4GL_gui_message (p, A4GL_getmessage_line ());
}






/**
 *
 * @todoindent: Standard input:3093: Warning:old style assignment ambiguity in "=-".  Assuming "= -"

 Describe function
 */
void
A4GL_set_bkg (WINDOW * win, int attr)
{
  if (attr != 0xff)
    {
      A4GL_debug ("MJAMJA set_bkg : %x\n", attr);
      wbkgd (win, A4GL_decode_aubit_attr (attr, 'w'));
      wbkgdset (win, A4GL_decode_aubit_attr (attr, 'w'));
    }
  else
    {
      A4GL_debug ("MJAMJA set_bkg : %x\n", 0);
      wbkgdset (win, 0);
    }

}


/* Menu color handling */


/**
 *
 * @todo Describe function
 */
static void
A4GL_menu_setcolor (ACL_Menu * menu, int typ)
{
  WINDOW *currwin;
  long attr;
  long attr2;




  currwin = A4GL_find_pointer (UILIB_A4GL_get_currwin_name (), WINCODE);
  A4GL_debug("%d\n",menu->attrib);
  attr = menu->attrib;
  //if (attr & 255) attr = attr - (attr & 255);


  /* wbkgd(menu->menu_win,0); */

  A4GL_debug ("Window background = %x - window - %x", attr, currwin);

  attr = A4GL_decode_colour_attr_aubit (attr);
  if ((attr - (attr & 0xff)) == 0)
    {
      attr = A_NORMAL + (attr & 0xff);
    }

  if ((attr & 0xff) == 0)
    {
      A4GL_debug ("Nothing specified for the background..");
      //attr += ' ';
    }

  A4GL_debug ("Subwin - setcolor - attr=%x", attr);
  switch (typ)
    {
    case NORMAL_TEXT:
    case NORMAL_MENU:
      A4GL_debug ("Normal : %x\n", attr);
      wattrset (currwin, attr);
      break;

    case INVERT_MENU:
      A4GL_debug ("Invert...");
      A4GL_debug ("YY REVERSE");

      if (attr & A_REVERSE)
	attr2 = attr - A_REVERSE;
      else
	attr2 = attr + A_REVERSE;

      A4GL_debug ("Reverse : %x\n", attr2);
      wattrset (currwin, attr2);
      break;
    }
}


/**
 *
 * @todo Describe function
 */
static int
A4GL_menu_getkey (ACL_Menu * menu)
{
  char cmd[60] = "";
  int a;
  a = -1;

  A4GL_set_abort (0);
  while (1)
    {


      A4GL_mja_gotoxy (1, 1 + menu->menu_line);
      /* pascal_v Do not print ":" if menu has no title */
      if (strlen(menu->menu_title) > 0)
        A4GL_tui_printr (1, "%s:", menu->menu_title);
      else
        A4GL_tui_printr (1, "%s", menu->menu_title);
      a = A4GL_getch_win ();

      if (a == -1) {
	A4GL_debug("Return 0");
	return 0;
	}

      if (a)
	{
	  A4GL_clr_error_nobox ("Menu");
	}

      if (a == -1)
	{


	  A4GL_assertion (1, "Fix me");
#ifdef FIXME
	  if (abort_pressed)
	    {
	      A4GL_debug ("Got interrupt key pressed....");
	      a = A4GLKEY_INTERRUPT;
	      wrapper_wgetch (menu->menu_win);
	      A4GL_set_abort (0);
	A4GL_debug("Return a=%d",a);
	      return a;
	    }
#endif



	}

      A4GL_debug (">>>>>>>>>>>A=%d %c\n", a, a_isprint (a) ? a : '.');
#ifdef WIN32_BROKEN
      if (a == KEY_MOUSE)
	{
	  request_mouse_pos ();
	  if (BUTTON_CHANGED (3))
	    {
	      return 27;
	    }
	}
#endif

      if (a == 18)
	{
		clearok(curscr,1);
	  A4GL_mja_refresh ();
	  continue;
	}

      /*
         Provides equivalent of Informix bang() functionality -
         User gets the shell prompt after the SHIFT+! key sequence while
         in MENU, or other input statement, and can enter single line command
         that will be passed to the shell for execution.

         FIXME: this should not use -D, but acl_getenv(A4GL_AUTOBANG) instead

       */

      A4GL_debug ("Check for autobang");

      if (strcmp (acl_getenv ("A4GL_AUTOBANG"), "1") != 0)
	{
	  if (a == '!' && !inprompt)
	    {
	      inprompt = 1;
	      A4GL_ask_cmdline ("Enter Command", cmd, 60);

	      if (!abort_pressed && strlen (cmd))
		{
		  A4GL_mja_endwin ();
		  system (cmd);


		  PRINTF ("\n\nPress return to continue\n");
		  fflush (stdout);
		  while (getc (stdin) != '\n');

		  clearok (curscr, 1);
		  A4GL_mja_refresh ();
		}
	      inprompt = 0;
	      continue;
	    }
	}

      A4GL_debug ("Returning A=%d abort_pressed=%d\n", a,abort_pressed);
      return a;
    }
}




/**
 * 4GL CALL
 * @todo Describe function
 */
/* now in API_menu

int
A4GL_show_menu (void)
{
  A4GL_exitwith ("Not available in TUI mode (show_menu)");
  return 0;
}

*/

/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_endis_fields_ap (int en_dis, va_list * ap)
{
  A4GL_exitwith ("Not available in TUI mode (enable/disable)");
  return 0;
}


/*******************************************************************************
new_menu
Menu handling entry point procedure
All menus are called with the following structure :
title,
starting X location (may be ignored), starting Y location (may be ignored)
Menu type (see menu.h),
Global Help number,
Number of following options,
Option 1, command key,short help text,help_no,attributes
------------------------------------------------------------------------------
eg.
new_menu(
"Main Menu",
1,1,
ACL_MN_HORIZ_BOXED,
100,
5,
"Option 1",(int)'1',"This is option 1",(int)101,(int)0,
"Option 2",(int)'2',"This is option 2",(int)102,(int)0,
"Option 3",(int)KEY_F(0),"This is option 3",(int)103,(int)ACL_MN_HIDE, press f1 for this option!
"Option 4", (int) '3', "This is option 4", (int) 104, (int) 0,
"Option 5", (int) '4', "This is option 5", (int) 105, (int) 0
)
*******************************************************************************/
/**
 *
 * @todo Describe function
 */



/**
 * 4GL CALL - also used in libaubit4gl via API_UI
 * exit CURSES mode and return in line terminal mode
 * @todo Describe function
 */
void
UILIB_A4GL_gotolinemode (void)
{
  A4GL_mja_endwin ();
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_refresh_after_system (void)
{
  A4GL_mja_refresh ();
}




/* same function exists in :

	lib/libui/ui_curses/curslib.c (this file)	as (struct struct_scr_field *fprop)
	lib/libui/ui_highlevel/formcntrl.c 			as (struct struct_scr_field *fprop)

	lib/libform/form_xdr/readforms.c			as (void *fprop)

	proto is defined in API_form.spec :
		//void A4GL_comments (struct struct_scr_field *fprop);
		A4GL_comments void* fprop -> void


*/
// This is called internally in ui_curses plug-in
void
A4GL_comments (struct struct_scr_field *fprop)
{
  int cline;
  char buff[256];
  int attr;

  if (!fprop)
    {
      strcpy (buff, " ");
    }
  else
    {
      if (!A4GL_has_str_attribute (fprop, FA_S_COMMENTS))
	{
	  strcpy (buff, "");
	}
      else
	{
	  strcpy (buff, A4GL_get_str_attribute (fprop, FA_S_COMMENTS));
	  A4GL_strip_quotes (buff);
	}
    }
  cline = A4GL_getcomment_line ();


  if (cline==0) { 	// Comment line off...
	  return;
  }


  buff[UILIB_A4GL_get_curr_width ()] = 0;
  A4GL_debug ("MJA COMMENTS 1,%d,%s", cline, buff);
  if (cline > UILIB_A4GL_get_curr_height ())
    {
      cline = UILIB_A4GL_get_curr_height ();
    }
  attr = A4GL_local_get_curr_window_attr ();
  if (!attr)
    {
      attr = A4GL_determine_attribute (FGL_CMD_INPUT, 0, 0, 0);
    }
  if (A4GL_isyes (acl_getenv ("COMMENT_LIKE_INPUT")))
    {
      attr = A4GL_determine_attribute (FGL_CMD_INPUT, 0, 0, 0);
    }
  if (A4GL_isyes (acl_getenv ("COMMENT_LIKE_DISPLAY")))
    {
      attr = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, 0, 0, 0);
    }

  UILIB_A4GL_display_internal (1, cline, buff, attr, 1);
  UILIB_A4GL_zrefresh ();
}

#ifdef NDEF
int
wrapper_wgetch (WINDOW * w)
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
#endif

int
UILIB_A4GL_open_gui_form_internal (long *form_variable, char *name_orig,
				   int absolute, int nat, char *like,
				   int disable, void *handler_e,
				   void *handler_c)
{
  // Not available in curses
  A4GL_exitwith ("Cant open gui form in curses mode..");
  return 0;
}


int
UILIB_A4GLUI_initlib (void)
{
  return 1;
}




int
UILIB_A4GL_get_key (int timeout)
{
  int x;
  abort_pressed = 0;

  if (A4GL_islinemode()) {
	  x=A4GL_readkey();
  	if (x!=0) {
                A4GL_debug("Read %d from keyfile",x);
                return x;
        }

	x=getchar();
	return x;
  }

  A4GL_chkwin ();

  if (timeout != -1)
    {
      A4GL_has_timeout (timeout);
    }

  x = A4GL_getch_win ();

  if (timeout)
    {
      A4GL_has_timeout (0);
    }

  A4GL_debug ("get_key returns %d (%x)", x, x);
  if (A4GL_is_special_key (x, A4GLKEY_ACCEPT))
    {
      A4GL_debug ("Looks like an accept - returning that instead");
      x = A4GLKEY_ACCEPT;
    }
  if (abort_pressed)
    {
      A4GL_debug ("Looks like an interrupt - returning that instead");
      x = A4GLKEY_INTERRUPT;
    }
  return x;
}


#ifdef NCURSES_VERSION
#include <term.h>
#define isprivate(s) ((s) != 0 && strstr(s, "\033[?") != 0)
#endif

void
try_to_stop_alternate_view ()
{
#ifdef NCURSES_VERSION
  /*
   * Cancel xterm's alternate-screen mode.
   */
  if (enter_ca_mode==0) return;
  if (exit_ca_mode==0) return;
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



void
make_error_panel_top (void)
{
  A4GL_debug ("make_Error_panel_top %p %p %d", curr_error_panel,
	      curr_error_window, curr_error_panel_visible);
  if (curr_error_panel_visible)
    {
      top_panel (curr_error_panel);
    }
}



PANEL *
get_below_panel (PANEL * p)
{
  PANEL *pl;
  A4GL_debug ("get_below_panel : %p", p);
  pl = panel_below (p);
  if (pl == curr_error_panel)
    {
      return get_below_panel (curr_error_panel);
    }
  return pl;
}


int
A4GL_has_timeout (int a)
{
  static int to = 0;
  if (a >= 0)
    to = a;
  if (a < 0)
    return to;
  return a;
}




//
// Called when SET PAUSE MODE ON/OFF is set
// and to check which is in effect (a==-1)
//
int
UILIB_A4GL_screen_mode (int a)
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
  A4GL_zrefresh ();
  return smode;
}





/* Dummy functions here - required by the API */
int UILIB_A4GL_widget_name_match(void* w,char* name) {
	return 0;
}
void UILIB_A4GL_clr_form_fields(int to_defaults,char* defs) {
}
void UILIB_A4GL_gui_run_til_no_more() {
}
int UILIB_aclfgl_a4gl_run_gui(int nargs)  {
	return 0;
}
int UILIB_A4GL_fgl_fieldnametoid(char* f,char* s,int n) {
	return 0;
}
int UILIB_aclfgl_set_window_title(int nargs) {
	return 0;

}
void* UILIB_A4GL_make_pixmap_gw(char* filename) {
	return 0;
}
void* UILIB_A4GL_create_menu(void* m,char* id,int mode,void* handler) {
	return 0;
}

int UILIB_UI_initlib() {
	return 1;

}


static int A4GL_local_get_curr_window_attr (void)
{
	  A4GL_debug ("30 XXX - get_curr_window_attr");
	    if (A4GL_has_pointer ((char *) A4GL_get_currwin_name (), ATTRIBUTE))
		        {
		      int a;
	            	a = (int) ((long)A4GL_find_pointer ((char *) A4GL_get_currwin_name (), ATTRIBUTE));
					          A4GL_debug ("30 Current window has an attribute %d", a);
						        return a;
							    }
	      A4GL_debug ("30 Current window has no attribute");
	        return 0;

}

int local_set_field_opts(FIELD *field, int opts) {
	int a;
	A4GL_debug("UUU SET %p %x",field,opts);
	a=set_field_opts(field,opts);
	A4GL_debug_print_field_opts(field);
	return  a;
}
int local_field_opts_on(FIELD *field, int opts) {
	int a;
	A4GL_debug("UUU ON %p %x",field,opts);
	A4GL_debug_print_field_opts(field);
	a=field_opts_on(field,opts);
	A4GL_debug_print_field_opts(field);
	return a;
}

int local_field_opts_off(FIELD *field, int opts) {
	int a;
	A4GL_debug("UUU OFF %p %x",field,opts);
	A4GL_debug_print_field_opts(field);
	a=field_opts_off(field,opts);
	A4GL_debug_print_field_opts(field);
	return a;
}

int local_field_opts(const FIELD *field) {
	A4GL_debug("UUU GOT %p %x",field,field_opts(field));
	A4GL_debug_print_field_opts((FIELD *)field);
	return field_opts(field);
}


/**
 * Used.
 * @todo Describe function
 */
void
A4GL_error_box (char *str, int attr)
{
  int a, pos;
  WINDOW *x;

  A4GL_chkwin ();
  /*YELLOW ON RED */
  //A4GL_mja_setcolor (ERROR_COL);
  a = 4;
  pos = (A4GL_screen_width () - (strlen (str))) / 2;

  A4GL_debug ("error_box - screen_width=%d pos=%d", A4GL_screen_width (),
              pos);

  x = A4GL_create_blank_window ("error", pos, a, strlen (str), 3, 1);
  /*wmove(x,2,2); */
  A4GL_mja_gotoxy (1, 1);
  /* print ("%s", str); */
  A4GL_tui_printr (1, "%s", str);
  UILIB_A4GL_zrefresh ();
  //A4GL_do_pause ();
  UILIB_A4GL_remove_window ("error");
  UILIB_A4GL_zrefresh ();
  A4GL_debug ("All done in error box");
  //A4GL_mja_setcolor (NORMAL_TEXT);
}


/* ============================== EOF ============================== */
