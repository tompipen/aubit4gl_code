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
# $Id: curslib.c,v 1.29 2003-05-15 07:10:45 mikeaubury Exp $
#*/

/**
 * @file
 * Curses middle level functions.
 *
 * I think it works as interface between i level like input, display,
 * input array and curses
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
                    Constants definitions
=====================================================================
*/

#define MAXFORM 8
#define A4GL_MAXWIDTH 80
#define MAXFIELDS 256
#define mja_strcmp(a,b) mja_strncmp(a,b,0)

#ifndef strnicmp		/* typically in /usr/include/string.h */
#define strnicmp(a,b,c) mja_strncmp(a,b,c)
#endif

#ifndef stricmp			/* typically in /usr/include/string.h */
#define stricmp(a,b) mja_strncmp(a,b,0)
#endif

//#define DEBUG
#define MAXENTS 1000
#define FILESIZE 64
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

int aborted;
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

int help_no, g_help_no;

int txtfcolour = COLOR_WHITE;
int txtbcolour = COLOR_BLACK;
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

char *A4GL_mfgets (char *s, int n, FILE * fp);
void *A4GL_decode_clicked (void);
int A4GL_mja_gotoxy (int x, int y);
char *A4GL_get_currwin_name (void);
int A4GL_gui_startmenu (char *s, long a);
void A4GL_size_menu (ACL_Menu * menu);
void A4GL_menu_setcolor (ACL_Menu * menu, int typ);
void A4GL_menu_attrib (ACL_Menu * menu, int attr, va_list ap);
void A4GL_set_value (int fno, char *buffer);
void A4GL_chktag (char *buff, int fno);
void A4GL_gsub (char *str);
int A4GL_load_formdata (char *fname2, char *ftitle, int fno);
int A4GL_find_shown (ACL_Menu * menu, int chk, int dir);
void A4GL_move_bar (ACL_Menu * menu, int a);
int A4GL_find_char (ACL_Menu * menu, int key);
void A4GL_clr_menu_disp (ACL_Menu * menu);
void A4GL_h_disp_more (ACL_Menu * menu, int offset, int y, int pos);
void A4GL_h_disp_title (ACL_Menu * menu, char *str);
void A4GL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y,
		 int type);
void A4GL_display_menu (ACL_Menu * menu);
void A4GL_clear_menu (ACL_Menu * menu);
int A4GL_new_do_keys (ACL_Menu * menu, int a);
int A4GL_menu_getkey (ACL_Menu * menu);
void A4GL_horiz_disp_opt (int row, int x, int y, int type);
void A4GL_puttext (int x1, int y1, int x2, int y2, char *buf);
int A4GL_endis_fields_ap (int en_dis, va_list * ap);
void A4GL_gettextinfo (struct text_info r);
static void a4gl_gettext (int l, int t, int r, int b, char *buf);
/* void    A4GL_strip_nl 		(char *str); */
/* void    A4GL_do_pause 			(void);  */
void A4GL_newbox (textarea * area, int l, int t, int r, int b, int typ);
void A4GL_combi_dispopts (int opt, char *lst, int lstwidth, int x, int y, int w,
		     int l, int h, int type);
void A4GL_copy_opts (int opt, int n, char *lst, int lstwidth, int x, int y, int w,
		int l, int h);
int A4GL_getkey (void);
/* void A4GL_disp_opt (int row, int x, int y, int l, int type); */
int A4GL_do_key_combi (int h);
int A4GL_set_combi_opts (int n, char *lst, int lstwidth, int scwidth, char *nme);
static void message (textarea * area, char *str, int x, int a);


char *A4GL_string_width (char *s);
void A4GL_combi_menu (char *dstn, char *str, int x, int y, int w, int h,
		 char *lst, int lstwidth, int nopts, char *nme, int border);
void A4GL_clearbox (textarea * area);
void acllib_pause (char *s);
void A4GL_ask_char (char *prompt, char *s, int a);
void A4GL_ask_cmdline (char *prompt, char *s, int a);
int A4GL_mjalen (char *str);
void A4GL_setreledit (int x, int y);
void A4GL_startit (void);
void A4GL_endit (void);
int A4GL_disp_horiz_menu (char *title, int y, int mn_type);

void A4GL_set_option (ACL_Menu * menu, int opt);
void A4GL_free_menu (ACL_Menu * menu);
void A4GL_disp_h_menu (ACL_Menu * menu);
int A4GL_menu_loop (ACL_Menu * menu);
int A4GL_seldir (char *filespec, char *filename);
//void curs_err (char *str);
int A4GL_load_form (char *fname2, int fno1, int fno);
void A4GL_stripbracket (char *str);
void A4GL_clrscr (void);
void A4GL_set_message (char *str, int x, int y);
void A4GL_clr_message (void);
void A4GL_chklistbox (char **arr, int elem, int mult, int x, int y, int w, int h);
int A4GL_isselected (int a);
//void A4GL_next_option (ACL_Menu * menu, char *nextopt);
void A4GL_menu_hide_ap (ACL_Menu * menu, va_list * ap);
void A4GL_menu_show (ACL_Menu * menu, ...);
//void aclfgli_pr_message (int attr, int wait);
//void A4GL_set_option_value (char type, int keyval);
//int A4GL_show_menu (void);
//int A4GL_endis_fields (int en_dis, ...);
ACL_Menu *A4GL_new_menu_tui_oldway (char *title, int x, int y, int mn_type,
			       int help_no, int nopts, va_list * ap);
ACL_Menu *A4GL_new_menu_create (char *title, int x, int y, int mn_type,
			   int help_no);
void A4GL_add_menu_option (ACL_Menu * menu, char *txt, char *keys, char *desc,
		      int helpno, int attr);
void A4GL_finish_create_menu (ACL_Menu * menu);
void A4GL_refresh_after_system (void);
WINDOW *A4GL_window_on_top (void);
void aclfgli_show_help (int n);
void A4GL_menu_show_ap (ACL_Menu * menu, va_list * ap);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
char *
A4GL_string_width (char *s)
{
  char buff[10];
  int a;
  static char buff2[132];

  a = A4GL_get_curr_width () - 2;
  sprintf (buff, "%%-%d.%ds", a, a);
  sprintf (buff2, buff, s);
  return buff2;
}



/**
 *
 * @todo Describe function
 */
/* not used
void
banner (str, a, b, c)
     char str[];
     int a, b, c;
{
  int pos;
  char disp[81];
  for (pos = 0; pos <= 79; pos++)
    disp[pos] = ' ';
  disp[80] = 0;
  pos = (c - strlen (str)) / 2;
  A4GL_mja_gotoxy (b, a);
  strcpy (&disp[pos], str);
  disp[pos + strlen (str)] = ' ';
  A4GL_mja_setcolor (TITLE_COL);
	// YELLOW ON CYAN
  A4GL_tui_print ("%s", disp);
  A4GL_mja_refresh ();
  A4GL_mja_setcolor (NORMAL_TEXT);
}
*/

/**
 *
 * @todo Describe function
 */
#ifdef NOT_USED_REMOVE_IT
void
title_box (str, a, x, l)
     char str[];
/*
   str - string to print
   a = y position
   x = x position
   l = length of limit
 */
     int a, x, l;
{
  int pos;
  pos = (l - strlen (str)) / 2;
  A4GL_mja_gotoxy (pos + x, a);
  A4GL_mja_setcolor (NORMAL_TEXT);
  /*YELLOW ON CYAN */
  A4GL_tui_print ("%s", str);
  A4GL_zrefresh ();
  A4GL_mja_setcolor (NORMAL_TEXT);
}
#endif


/**
 *
 * @todo Describe function
 */
static void
message (textarea * area, char *str, int x, int a)
{
  int pos;

  /*YELLOW ON CYAN */
  A4GL_mja_setcolor (TITLE_COL);
  pos = (A4GL_get_curr_width () - strlen (str)) / 2;
  A4GL_newbox (area, pos + x, a, pos + x + strlen (str) + 1, a, NORMAL_BOX);
  A4GL_mja_gotoxy (pos + x + 1, a);
  /* print ("%s", str); */
  A4GL_tui_print ("%s", str);
  A4GL_mja_refresh ();
  A4GL_mja_setcolor (NORMAL_TEXT);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_error_nobox (char *str)
{
  int a;
  A4GL_push_char (str);
  a = A4GL_geterror_line ();
  A4GL_debug ("Error line = %d", a);
  A4GL_push_int (a);
  A4GL_push_int (1);

#ifdef DEBUG
  A4GL_debug ("YY REVERSE");
#endif
  A4GL_display_at (1, AUBIT_ATTR_REVERSE);
}


/**
 * Used.
 * @todo Describe function
 */
void
A4GL_error_box (char *str)
{
  int a, pos;
  WINDOW *x;

  /*YELLOW ON RED */
  A4GL_mja_setcolor (ERROR_COL);
  a = 4;
  pos = (A4GL_screen_width () - (strlen (str))) / 2;

  A4GL_debug ("error_box - screen_width=%d pos=%d", A4GL_screen_width (), pos);

  x = A4GL_create_blank_window ("error", pos, a, strlen (str), 3, 1);
  /*wmove(x,2,2); */
  A4GL_mja_gotoxy (1, 1);
  /* print ("%s", str); */
  A4GL_tui_print ("%s", str);
  A4GL_zrefresh ();
  A4GL_do_pause ();
  A4GL_remove_window ("error");
  A4GL_zrefresh ();
  A4GL_debug ("All done in error box");
  A4GL_mja_setcolor (NORMAL_TEXT);
}


/**
 * dstn = destination string, menu option selected is copied into here
 * str  = prompt string
 * x = starting X location
 * y = starting Y location
 * w = width
 * h = height
 * lst = list of strings each are lstwidth long
 * eg. char opt[20][80]
 * opt would be passed as lst
 * 80 would be passed as lstwidth
 * nopts=total number of options
 *
 *
 * @todo Describe function
 */
void
A4GL_combi_menu (char *dstn, char *str, int x, int y, int w, int h,
	    char *lst, int lstwidth, int nopts, char *nme, int border)
{
  int a, pos;
  int fwidth, numdisp_opts;
  char st[80];
  static int last_opt = -1;

  st[0] = 0;
  A4GL_mja_setcolor (NORMAL_TEXT);
  a = y;
  pos = (A4GL_get_curr_width () - strlen (str)) / 2;
  A4GL_create_blank_window ("combI", x, y, x + w, y + h, border);
  A4GL_mja_gotoxy (1, 2);
  for (a = 0; a < w - 1; a++)
    {
      A4GL_mja_gotoxy (1 + a, 3);
      /* print ("-"); */
      A4GL_tui_print ("-");
    }
  fwidth = A4GL_set_combi_opts (nopts, lst, lstwidth, w - 2, nme) + 1;
  last_opt = curr_opt;
  numdisp_opts = (w - 2) / fwidth;
  numdisp_opts = numdisp_opts * (h - 4);
  if (numdisp_opts > nopts)
    numdisp_opts = nopts;
  A4GL_copy_opts (0, numdisp_opts, lst, lstwidth, x + 1, y + 3, w / fwidth, fwidth,
	     h);
  if (nopts > 0)
    A4GL_combi_dispopts (curr_opt, lst, lstwidth, x + 1, y + 3, w / fwidth, fwidth,
		    h, INVERT);
  A4GL_mja_gotoxy (1, 1);
  /* print ("%s > %s", str, st); */
  A4GL_tui_print ("%s > %s", str, st);
  A4GL_zrefresh ();
  max_opt = nopts - 1;
  abort_pressed = 0;
  while (1)
    {
      a = A4GL_do_key_combi (h - 4);
      if (abort_pressed || a == 1)
	break;
      if (a > 1000)
	{
	  a = a - 1000;
	  if ((a == 8 || a == 24 || a == 127) && strlen (st) >= 1)
	    {
	      st[strlen (st) - 1] = 0;
	      A4GL_mja_gotoxy (1, 1);
	      /* print ("%s > %s ", str, st); */
	      A4GL_tui_print ("%s > %s ", str, st);
	    }
	  else if (isprint (a) && strlen (st) <= (w - strlen (str) - 5))
	    sprintf (st, "%s%c", st, a);
	}
      if (last_opt != curr_opt)
	{
	  if (last_opt >= 0)
	    {
	      if (nopts > 0)
	 A4GL_combi_dispopts (last_opt, lst, lstwidth, 1, 3, w / fwidth,
				fwidth, h, NORM);
	    }
	  if (nopts > 0)
	    A4GL_combi_dispopts (curr_opt, lst, lstwidth, 1, 3, w / fwidth, fwidth,
			    h, INVERT);
	  last_opt = curr_opt;
	}
      A4GL_mja_gotoxy (1, 1);
      /* print ("%s > %s", str, st); */
      A4GL_tui_print ("%s > %s", str, st);
      A4GL_zrefresh ();
    }

  A4GL_remove_window ("combI");

  if (abort_pressed)
    dstn[0] = 0;
  else if (strlen (st) == 0)
    strcpy (dstn, opts[curr_opt]);
  else
    strcpy (dstn, st);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_copy_opts (int opt, int n, char *lst, int lstwidth, int x, int y, int w,
	   int l, int h)
{
  int a;
  for (a = 0; a < n; a++)
    {
      strcpy (opts[a], &lst[(a + opt) * lstwidth]);
      A4GL_combi_dispopts (a, lst, lstwidth, x, y, w, l, h, NORM);
    }
}

/**
 *
 * @todo Describe function
 */
void
A4GL_combi_dispopts (int opt, char *lst, int lstwidth, int x, int y, int w, int l,
		int h, int type)
{
  h = h - 4;
  A4GL_disp_opt (opt, ((opt / h) * l) + 1, (opt % h) + 4, l, type);
  A4GL_mja_setcolor (NORMAL_TEXT);
}


/**
 *
 * @todo Describe function
 */
int
A4GL_set_combi_opts (int n, char *lst, int lstwidth, int scwidth, char *nme)
{
  int a;
  int mlen = 0;
  int wid;
  char nm[80];
  curr_opt = 0;
  if (n == 0)
    return 1;
  for (a = 0; a < n; a++)
    {
      if (strlen (&lst[a * lstwidth]) > mlen)
	mlen = strlen (&lst[a * lstwidth]);
      strncpy (nm, &lst[a * lstwidth], lstwidth);
      if (strcmp (nm, nme) == 0)
	{
	  curr_opt = a;
	}
    }
  wid = scwidth / a;
  wid = scwidth / wid;
  return mlen;
}


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
  /*
     write ("if border");
     delwin (area->win_no);
     write ("Delwin");
   */
  A4GL_mja_wrefresh (area->win_no);
  area->x1 = l;
  area->x2 = r;
  area->y1 = t;
  area->y2 = b;
}




/**
 * 4GL CALL
 * @todo Describe function
 */
int
aclfgl_fgl_drawbox (int n)
{
  int x, y, w, h, c;
  int xx, yy;
//void *ptr=0;
  void *win;
  c = 0;
  if (n == 5)
    c = A4GL_pop_int ();
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
  w = A4GL_pop_int ();
  h = A4GL_pop_int ();
  A4GL_debug ("In fgl_drawbox");
  A4GL_debug ("h=%d y+h=%d", h, y + h);
  //win=curscr;
  win = A4GL_find_pointer ("screen", WINCODE);
  win = A4GL_window_on_top ();

#define PMOVE(x,y,c) 	mvwaddch(win,(y-1),(x-1),c)

  for (xx = x + 1; xx < x + w - 1; xx++)
    {
      PMOVE (xx, y, ACS_HLINE);

      PMOVE (xx, y + h - 1, ACS_HLINE);
    }

  for (yy = y + 1; yy < y + h - 1; yy++)
    {
      PMOVE (x, yy, ACS_VLINE);

      PMOVE (x + w - 1, yy, ACS_VLINE);
    }

  PMOVE (x, y, ACS_ULCORNER);
  PMOVE (x + w - 1, y, ACS_URCORNER);

  PMOVE (x, y + h - 1, ACS_LLCORNER);

  PMOVE (x + w - 1, y + h - 1, ACS_LRCORNER);

  A4GL_mja_refresh ();
  return 0;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_disp_opt (row, x, y, l, type)
     int row, x, y, l, type;
{
  char disopt[20];
  if (type == INVERT)
    A4GL_mja_setcolor (INVERT_MENU);
  else
    A4GL_mja_setcolor (NORMAL_MENU);
  A4GL_mja_gotoxy (x, y);
  sprintf (disopt, "%%-%d.%ds", l, l);
  /* print (disopt, opts[row]); */
  A4GL_tui_print (disopt, opts[row]);
  A4GL_mja_setcolor (NORMAL_MENU);

}

/**
 *
 * @todo Describe function
 */
int
A4GL_do_key_combi (int h)
{
  int a;
  abort_pressed = FALSE;
  a = A4GL_getkey ();
  if (a == UPKEY)
    {
      curr_opt = curr_opt - 1;
      if (curr_opt < 0)
	curr_opt = max_opt;
      a = 0;
    }

  if (a == LEFTKEY)
    {
      curr_opt = curr_opt - h;
      if (curr_opt < 0)
	curr_opt = max_opt;
      a = 0;
    }

  if (a == DOWNKEY)
    {
      curr_opt = curr_opt + 1;
      if (curr_opt > max_opt)
	curr_opt = 0;
      a = 0;
    }


  if (a == RIGHTKEY)
    {
      curr_opt = curr_opt + h;
      if (curr_opt > max_opt)
	curr_opt = 0;
      a = 0;
    }

  if (a == ESC)
    {
      abort_pressed = 1;
    }

  if (a == CR)
    {
      return 1;
    }

  return a + 1000;
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

  if (a == ESC || a == 'Q' || a == 'q')
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


/**
 *
 * @todo Describe function
 */
void
A4GL_clearbox (textarea * area)
{
  /*wclear(area->win_no); */
  delwin (area->win_no);
  A4GL_puttext (area->x1, area->y1, area->x2, area->y2, (area->buf));
}

/**
 *
 * @todo Describe function
 */
void
A4GL_do_pause (void)
{
  WINDOW *x;
  int w;
  int emw;
  char buff[80];

  w = A4GL_screen_width ();
  sprintf (buff, " %s ", acl_getenv ("ERROR_MSG"));
  emw = strlen (buff);
  x = A4GL_create_blank_window ("pause", ((w - emw) / 2), 20, emw, 3, 1);
  A4GL_mja_gotoxy (1, 2);
  A4GL_mja_setcolor (ERROR_COL);
  /* print ("%s",buff); */
  A4GL_tui_print ("%s", buff);
  A4GL_zrefresh ();
  abort_pressed = FALSE;
  doupdate ();
  A4GL_debug ("getch_win...");
  A4GL_getch_win ();
  A4GL_debug ("Done getch_win");
  A4GL_remove_window ("pause");
  A4GL_mja_setcolor (NORMAL_TEXT);
}


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
int
A4GL_edit (string, type, length, x, y)
     char *string;
     char type;
     int x, y, length;
{
  textarea area;
  int a;
  int len = 0;
  int flg = 0;

  if (abort_pressed)
    return 0;
  len = strlen (string);
  if (type == 'Y')
    len = 0;
  if (x == 0)
    x = (A4GL_get_curr_width () - length) / 2;

  /* textbackground(COLOR_BLACK); */

  /*A4GL_newbox (&area, x, y, x + length + 1, y + 2, NORMAL_BOX); */
#ifdef DEBUG
  A4GL_debug ("Box %d %d %d", x, y, x + length);
#endif
  A4GL_newbox (&area, x, y, x + length + 1, y + 1, NORMAL_BOX);
  wattron (area.win_no, A_NORMAL);

  /* A4GL_mja_setcolor (NORMAL_TEXT); */
  for (a = len; a < length; a++)
    string[a] = ' ';
  string[length] = 0;
  A4GL_mja_gotoxy (x + 1, y + 1);
  wprintw (area.win_no, "%s", string);
  A4GL_zrefresh ();
  while (1 == 1)
    {
      A4GL_mja_gotoxy (x + len + 1, y + 1);
      abort_pressed = FALSE;
      a = A4GL_getkey ();
      if (a == ESC)
	{
	  abort_pressed = 1;
	  A4GL_clearbox (&area);
	  A4GL_mja_setcolor (NORMAL_TEXT);
	  A4GL_error_box ("Operation Aborted");
	  string[0] = 0;
	  return 0;
	}
      if ((a == BS || a == 127 || a == KEY_DC || a == KEY_DL || a == 24
	   || a == KEY_BACKSPACE || a == 8) && len > 0)
	{
	  if (string[len - 1] == '.' && type == 'D')
	    flg = 0;
	  string[len - 1] = ' ';
	  len = len - 1;
	  A4GL_mja_gotoxy (x + 1 + len, y + 1);
	  wprintw (area.win_no, " ");
	  A4GL_zrefresh ();
	  continue;
	}
      if (a == CR)
	{
	  A4GL_clearbox (&area);
	  if (type != 'Y')
	    string[len] = 0;
	  else
	    string[1] = 0;
	  return 0;
	}
      if (A4GL_check_type (a, type, flg, len) && len < length)
	{
	  if (type == 'Y')
	    {
	      a = toupper (a);
	    }
	  string[len] = a;
	  len = len + 1;
	  if (a == '.' && type == 'D')
	    flg = 1;
	  A4GL_mja_gotoxy (x + len, y + 1);
	  wprintw (area.win_no, "%c", a);
	  A4GL_zrefresh ();
	  if (type == 'Y')
	    len = 0;
	}
    }
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_check_type (char c, char type, int flg, int len)
{


  if (type == 'N')
    {
      return (isdigit (c));
    }


  if (type == 'D')
    {
      return (isdigit (c) || (c == '.' && flg == 0)
	      || (c == '-' && len == 0));
    }


  if (type == 'A')
    {
      return (isprint (c));
    }

  if (type == 'Y')
    {
      c = toupper (c);
      return (c == 'Y' || c == 'y' || c == 'N' || c == 'n');
    }

  return 0;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_ask_char (char *prompt, char *s, int a)	/*  prompt for an integer from user  */
{
  char inbuf[80] = "";
  textarea area;
  textarea area2;
  inbuf[0] = 0;

  strcpy (inbuf, s);
  A4GL_newbox (&area2, (((80 - a) / 2) - 4), 11, (((80 - a) / 2) + a + 4), 15, 1);
  message (&area, prompt, 0, 10);
  A4GL_edit (inbuf, 'A', a, 0, 12);
  A4GL_clearbox (&area);
  A4GL_clearbox (&area2);
  strcpy (s, inbuf);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_ask_cmdline (char *prompt, char *s, int a)	/*  prompt for an integer from user  */
{
  char inbuf[80] = "";
  textarea area2;
  inbuf[0] = 0;

#ifdef DEBUG
  A4GL_debug ("in ask_cmdline");
#endif
  strcpy (inbuf, s);
#ifdef DEBUG
  A4GL_debug ("newbox");
#endif

  A4GL_newbox (&area2, 2, 20, 76, 24, BORDER_BOX);

  /*message (&area, prompt, 0, 10); */
  /*
     A4GL_mja_setcolor (NORMAL_TEXT);
     debug("printw");
     wprintw (area2.win_no,"$ ");
     debug("Set edit1");
   */

  A4GL_edit (inbuf, 'A', a, 3, 22);

#ifdef DEBUG
  A4GL_debug ("Done edit1");
#endif
  /* A4GL_mja_setcolor (NORMAL_TEXT); */
  /*A4GL_clearbox (&area); */

  A4GL_clearbox (&area2);
  strcpy (s, inbuf);
}

/**
 *
 * @todo Describe function
 */
int
A4GL_ask_int (prompt)		/*  prompt for an integer from user  */
     char *prompt;
{
  int i;
  char inbuf[80];
  textarea area;

  i = 0;
  inbuf[0] = 0;
  message (&area, prompt, 0, 9);
  A4GL_edit (inbuf, 'N', 10, 0, 12);
  sscanf (inbuf, "%d", &i);
  A4GL_clearbox (&area);
  return i;
}


/**
 *
 * @todo Describe function
 */
double
A4GL_ask_dbl (prompt)		/*  prompt for an integer from user  */
     char *prompt;
{
  double d;
  char inbuf[80];
  textarea area;

  d = 0.0;
  inbuf[0] = 0;
  message (&area, prompt, 0, 9);
  A4GL_edit (inbuf, 'D', 20, 0, 12);
  sscanf (inbuf, "%lf", &d);
  A4GL_clearbox (&area);
  return d;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_ask_verify (prompt)		/*  prompt for verification  */
     char *prompt;
{
  int i;
  char kch, inbuf[80];
  int rm_disp = 0;
  textarea area;
  textarea area1;

  if (abort_pressed)
    return 0;
  if (strlen (prompt) > 0)
    {
      message (&area1, prompt, 0, 5);
      rm_disp = 1;
    }
  message (&area, " ( Enter 'Y' for Yes 'N' for No ) ", 0, 9);
  strcpy (inbuf, "Y");
  A4GL_edit (inbuf, 'Y', 1, 0, 12);
  sscanf (inbuf, "%c", &kch);
  if (toupper (kch) == 'Y')
    i = 1;
  else
    i = 0;

  if (rm_disp)
    A4GL_clearbox (&area1);
  A4GL_clearbox (&area);
  return i;
}



/**
 *
 * @todo Describe function
 */
void
A4GL_strip_nl (str)
     char *str;
{
  int a;
  for (a = 0; a <= strlen (str); a++)
    {
      if (str[a] == '\n')
	{
	  str[a] = 0;
	  break;
	}
    }
}


/**
 *
 * @todo Describe function
 */
int
A4GL_mjalen (char *str)
{
  int a;
  if (strlen (str) == 0)
    return 0;
  for (a = strlen (str) - 1; a >= 0; a--)
    {
      if (str[a] != ' ')
	return a + 1;
    }
  return 0;
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


#ifdef REMOVE_SOMETIME
/**
 *
 * @todo Describe function
 */
int
show_help_old (int no)
{
  struct text_info t_info;
  int r_flg = 0;
  int cnt = 0;
  int pos;
  int height;
  WINDOW *w;
  int max_width;
  char buff[20];
  char hlptxt[256];

  strcpy (hlptxt, (char *) acl_getenv ("HELPTEXT"));
#ifdef DEBUG
  A4GL_debug ("Reading help file for %d", no);
#endif

  if (A4GL_has_helpfile () != 0)
    {
      cnt = A4GL_read_help_f (no, &max_width);	/* in libmsg/readmsg.c */
      if (cnt == 0)
	return 0;

      /* void    A4GL_gettextinfo        (struct text_info r); */
      A4GL_gettextinfo (t_info);	/* incompatible type for argument 1 of `gettextinfo' */
#ifdef DEBUG
      A4GL_debug ("Read textinfo...");
#endif
      if (cnt > 0)
	{
	  if (max_width < strlen (hlptxt))
	    max_width = strlen (hlptxt);

	  pos = (80 - max_width) / 2;
	  height = (22 - cnt) / 2;
	  w = A4GL_create_blank_window ("Help", pos, height, max_width, cnt, 1);
	  wmove (w, 0, ((max_width - strlen (hlptxt)) / 2) + 1);
	  wprintw (w, hlptxt);
#ifdef DEBUG
	  A4GL_debug ("YY REVERSE");
#endif
	  wattron (w, A_REVERSE);
	  sprintf (buff, "%%-%d.%ds", max_width, max_width);

	  for (r_flg = 0; r_flg < cnt; r_flg++)
	    {
	      wmove (w, 1 + r_flg, 1);
	      wprintw (w, buff, A4GL_get_help_disp (r_flg));
#ifdef DEBUG
	      A4GL_debug ("YY REVERSE");
#endif
	      wattroff (w, A_REVERSE);
	    }
#ifdef DEBUG
	  A4GL_debug ("YY REVERSE");
#endif
	  wattroff (w, A_REVERSE);
	  A4GL_mja_wrefresh (w);
	}
      abort_pressed = FALSE;
      A4GL_getkey ();
      A4GL_remove_window ("Help");
    }
  A4GL_mja_setcolor (NORMAL_TEXT);
  return 1;
}
#endif


/**
 *
 * @todo Describe function
 */
void
A4GL_gettextinfo (struct text_info r)
{
  getyx (stdscr, r.cury, r.curx);
  getmaxyx (stdscr, r.screenheight, r.screenwidth);
  getbegyx (stdscr, r.wintop, r.winleft);
  r.winright = r.winleft + r.screenwidth;
  r.winbottom = r.wintop + r.screenheight;
  r.attribute = txtfcolour + txtbcolour * 16;
}


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


/**
 * Initialization of curses enviornment
 */
void
A4GLUI_ui_init (int argc, char *argv[])
{
  A4GL_set_scrmode ('L');
  init_curses_mode = 0;
}


void
A4GL_init_curses_stuff ()
{
#define BLANK ' '

// Have we already done it ?
  if (init_curses_mode)
    return;
  init_curses_mode = 1;

#ifdef DEBUG
  A4GL_debug ("Initializing curses environment");
#endif
  initscr ();
  bkgdset (BLANK);
  start_color ();

#ifndef __sun__
#ifndef __sparc__
  //curses function not available on Solaris (!!!!?????)
  use_default_colors ();
#endif
#endif

  cbreak ();
  noecho ();
  nonl ();
  intrflush (stdscr, TRUE);
  keypad (stdscr, TRUE);

  start_color ();
  A4GL_init_colour_pairs ();
  A4GL_init_windows ();

  A4GL_mja_gotoxy (1, 1);
  A4GL_tui_print ("                                 ");
  A4GL_zrefresh ();


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
 *
 * @todo Describe function
 */
int
A4GL_disp_horiz_menu (char *title, int y, int mn_type)
{
  char disp_str[80];
  int disp_cnt;
  int posarr[20];
  textarea area;
  int row;
  int mn_offset;
  int old_opt;
  int num_rows = 0;

  if (mn_type == ACL_MN_HORIZ_BOXED)
    mn_offset = 1;
  else
    mn_offset = 0;
  disp_cnt = 0;

  for (row = 0; row < 10; row++)
    {
      if (opts[row][0] == 0)
	{
	  num_rows = row - 1;
	  break;
	}
      posarr[row] = disp_cnt;
      disp_cnt += strlen (opts[row]);
      disp_cnt += 1;
    }
  disp_str[0] = 0;
  disp_cnt = 2;
  A4GL_mja_setcolor (NORMAL_TEXT);
  if (strlen (title) > 0)
    {
      if (mn_type == 0)
	{
	  sprintf (disp_str, "%s:  ", title);
	  disp_cnt = strlen (disp_str) + 2;
	}
      else
	sprintf (disp_str, " %s ", title);
    }
  abort_pressed = 0;
  A4GL_mja_setcolor (NORMAL_TEXT);
/*YELLOW ON BLACK */
  A4GL_newbox (&area, 1, y, 80, y + 3, BORDER_BOX);
  A4GL_mja_gotoxy (1 + mn_offset * 2, y);
  printw (disp_str);
  for (row = 0; row <= num_rows; row++)
    {
      A4GL_horiz_disp_opt (row, posarr[row] + disp_cnt, y + mn_offset, NORM);
    }
  curr_opt = 0;
  max_opt = num_rows;
  A4GL_horiz_disp_opt (curr_opt, posarr[curr_opt] + disp_cnt, y + mn_offset,
		  INVERT);
  while (1 == 1)
    {
      old_opt = curr_opt;
      if (A4GL_do_key_menu ())
	break;
      if (abort_pressed)
	break;
      A4GL_horiz_disp_opt (old_opt, posarr[old_opt] + disp_cnt, y + mn_offset,
		      NORM);
      A4GL_horiz_disp_opt (curr_opt, posarr[curr_opt] + disp_cnt, y + mn_offset,
		      INVERT);
      A4GL_zrefresh ();
    }
  A4GL_clearbox (&area);
  A4GL_mja_setcolor (NORMAL_TEXT);
  if (abort_pressed)
    return max_opt;

  return curr_opt;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_horiz_disp_opt (row, x, y, type)
     int row, x, y, type;
{
  if (type == INVERT)
    A4GL_mja_setcolor (INVERT_MENU);
  else
    A4GL_mja_setcolor (NORMAL_MENU);
  A4GL_mja_gotoxy (x, y);
  printw ("%s", opts[row]);
  A4GL_mja_setcolor (NORMAL_MENU);
  printw (" ");
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_option (ACL_Menu * menu, int opt)
{
  int a;
  (ACL_Menu_Opts *) menu->curr_option = (ACL_Menu_Opts *) menu->first;
  for (a = 0; a < opt; a++)
    {
      (ACL_Menu_Opts *) menu->curr_option =
	(ACL_Menu_Opts *) ((ACL_Menu_Opts *) (menu->curr_option))->
	next_option;
    }
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_free_menu (ACL_Menu * menu)
{
  ACL_Menu_Opts *opt1, *opt2;
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
  A4GL_debug ("Attempting to delete window : %p", menu->menu_win);
#endif
  A4GL_clear_menu (menu);
  update_panels ();
  doupdate ();
  A4GL_zrefresh ();
#ifdef DEBUG
  A4GL_debug ("Menu=%p &Menu=%p", menu, &menu);
#endif
  A4GL_gui_rmmenu ((int) menu);
#ifdef DEBUG
  A4GL_debug ("Deleted window");
#endif
}

/**
 * 4GLCALL
 * @todo Describe function
 */
void
A4GL_disp_h_menu (ACL_Menu * menu)
{
  char disp_str[80];
  int disp_cnt;
  int disp_cnt2;
  int row;
  int cl, cpt, mnln, cw;
  char *parent_window;
  long attrib = 0;

#ifdef DEBUG
  A4GL_debug ("Adding window for menu");
  A4GL_debug ("Current metrics : %d %d %d", A4GL_get_curr_left (),
	 A4GL_get_curr_print_top () - 1, A4GL_get_curr_width ());
#endif
  if (menu->window_name[0] == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Glob Window!");
#endif
      cl = A4GL_get_curr_left ();
      cw = A4GL_get_curr_width ();
      cpt = A4GL_get_curr_print_top ();
      mnln = A4GL_getmenu_line () - 1;
      attrib = (long) A4GL_find_pointer (A4GL_get_currwin_name (), ATTRIBUTE);
      parent_window = A4GL_find_pointer (A4GL_get_currwin_name (), WINCODE);
#ifdef DEBUG
      {
 A4GL_debug ("cl=%d  cw=%d cpt=%d mnln=%d", cl, cw, cpt, mnln);
      }
#endif
      strcpy (menu->window_name, A4GL_glob_window (cl, cpt - 1 + mnln, cw, 2, 0));
#ifdef DEBUG
      {
 A4GL_debug ("Globbed");
      }
#endif
      menu->attrib = attrib;
#ifdef DEBUG
      A4GL_debug ("Menu Attribute %x", attrib);
#endif
      /* set_bkg(menu->menu_win,attrib); */
      menu->w = cw;
#ifdef DEBUG
      {
 A4GL_debug ("Got width again");
      }
#endif
      /*owin=get_curr_win(); */
      /* current_window(menu->window_name); */
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("No window created");
#endif
    }
#ifdef DEBUG
  A4GL_debug ("Menu window = %s", menu->window_name);
#endif

  menu->menu_win = A4GL_find_pointer (menu->window_name, MNWINCODE);	/* was 'm' */
#ifdef DEBUG
  A4GL_debug ("Parents attribute = 0x%x", attrib);
#endif
  if ((attrib & 0xff) == 0)
    attrib = attrib + 32;	/* -(attrib&0xff); */

  if (attrib)
    A4GL_set_bkg (menu->menu_win, attrib);


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
	  sprintf (disp_str, "%s:  ", menu->menu_title);
	  disp_cnt = strlen (disp_str) + 1;
	}
      else
	sprintf (disp_str, " %s ", menu->menu_title);
    }
  menu->menu_offset = disp_cnt;
#ifdef DEBUG
  {
    A4GL_debug ("Menu line set to %d", A4GL_getmenu_line ());
  }
#endif
  menu->menu_line = 1;
  abort_pressed = 0;
  A4GL_size_menu (menu);
  A4GL_display_menu (menu);
  /* zrefresh(); */
#ifdef DEBUG
  {
    A4GL_debug ("completed disp_h_menu");
  }
#endif
  /*set_window(owin); */
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_menu_loop (ACL_Menu * menu)
{
  ACL_Menu_Opts *old_option;
  int a;
  int key_pressed;


/*
   owin=get_curr_win();
 */
  A4GL_menu_setcolor (menu, NORMAL_TEXT);
  A4GL_gui_actmenu ((int) menu);
  /* display_menu(menu); */
  A4GL_refresh_menu_window (menu->window_name, 1);
  A4GL_debug ("Refreshed window - going into while loop");
  while (1 == 1)
    {
      A4GL_gui_setfocus ((int) menu->curr_option);
      old_option = (ACL_Menu_Opts *) menu->curr_option;
      abort_pressed = FALSE;
      /* A4GL_mja_gotoxy (menu->menu_offset , 1); */
      A4GL_menu_setcolor (menu, NORMAL_TEXT);
      A4GL_mja_gotoxy (1, 1);
      A4GL_debug ("Gone to 1,1");

      /* A4GL_subwin_gotoxy (menu->menu_win,menu->menu_offset - 1, menu->menu_line+1); */


#ifdef DEBUG
      A4GL_debug ("Moved cursor for menu to %d %d", menu->menu_offset - 1,
	     menu->menu_line);
#endif


      wmove (menu->menu_win, 0, 0);


#ifdef DEBUG
      A4GL_debug (">>>> Getting key from menu");
#endif

      a = A4GL_menu_getkey (menu);
#ifdef DEBUG
      A4GL_debug (">>>> KEY=%d", a);
#endif

      if (a == 23 || a == A4GL_key_val ("HELP"))
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

      key_pressed = A4GL_new_do_keys (menu, a);
      A4GL_h_disp_opt (menu, old_option, menu->menu_offset, menu->mn_offset, NORM);
      A4GL_h_disp_opt (menu, menu->curr_option, menu->menu_offset, menu->mn_offset,
		  INVERT);
      if (abort_pressed)
	{
	  A4GL_debug ("setting menu->abort_pressed");
	  menu->abort_pressed = 1;
	  break;
	}
      if (key_pressed)
	break;
      /* A4GL_zrefresh (); */
    }
  A4GL_menu_setcolor (menu, NORMAL_TEXT);
  /*set_window(owin); */
  A4GL_refresh_menu_window (menu->window_name, 0);

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
  char buff[256];
  int disp_cnt;
  int have_displayed = 0;

  A4GL_debug ("In display_menu");

  A4GL_clr_menu_disp (menu);
  if (strlen (menu->menu_title) > 0)
    {
      if (menu->menu_type == ACL_MN_HORIZ_NOTBOXED)
	{
	  sprintf (disp_str, "%s : ", menu->menu_title);
	  disp_cnt = strlen (disp_str) + 1;
	}
      else
	sprintf (disp_str, " %s ", menu->menu_title);
    }


  A4GL_debug ("Printing titles....");
  sprintf (buff, "Print : %s %p @%d, %d", disp_str, menu->menu_win,
	   menu->mn_offset * 2, menu->menu_line);
  A4GL_h_disp_title (menu, disp_str);


  A4GL_zrefresh ();
  opt1 = (ACL_Menu_Opts *) menu->first;

  while (opt1 != 0)
    {
      /* opt1->optpos = -9; */
      A4GL_debug ("Option %s  attributes %d %d %d ", opt1->opt_title,
	     opt1->attributes, ACL_MN_HIDE, opt1->attributes & ACL_MN_HIDE);
      if ((opt1->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
	{
#ifdef DEBUG
	  {
	    A4GL_debug ("OK to display - Page %d of %d", menu->curr_page,
		   opt1->page);
	  }
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
	      A4GL_debug ("disp=%d width=%d %d %s page %d", disp_cnt2, menu->w,
		     menu->menu_offset, opt1->opt_title, opt1->page);

	      if ((ACL_Menu_Opts *) menu->curr_option !=
		  (ACL_Menu_Opts *) opt1)
	 A4GL_h_disp_opt (menu, opt1, menu->menu_offset, menu->mn_offset,
			    NORM);
	      else
	 A4GL_h_disp_opt (menu, opt1, menu->menu_offset, menu->mn_offset,
			    INVERT);
	    }
	  else
	    {
	      A4GL_debug ("Option %s is out of view", opt1->opt_title);
	      if (prev_opt)
		{
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
A4GL_clear_menu (ACL_Menu * menu)
{
  PANEL *p;
  WINDOW *w;

  p = A4GL_find_pointer (menu->window_name, PANCODE);
  w = A4GL_find_pointer (menu->window_name, WINCODE);

#ifdef DEBUG
  {
    A4GL_debug ("Clearing Window..%p", w);
  }
  {
    A4GL_debug ("Clearing Panel %p", p);
  }
#endif

  del_panel (p);		/* this is causing problems INVESTIGATE */
  delwin (w);
  /* A4GL_remove_window (menu->window_name); */
  A4GL_mja_setcolor (NORMAL_TEXT);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_clear_prompt (struct s_prompt *prmt)
{
  PANEL *p;
#ifdef DEBUG
  {
    A4GL_debug ("Clearing prompt...");
  }
#endif
  p = prmt->win;
  delwin ((WINDOW *) p);
}




/**
 *
 * @todo Describe function
 */
void
A4GL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y,
	    int type)
{
  A4GL_debug ("Printing %s at %d %d", opt1->opt_title, opt1->optpos + offset, 1);


  if (opt1->page != menu->curr_page)
    return;

  A4GL_menu_setcolor (menu, NORMAL_MENU);


  if ((opt1->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
    {
      if (offset > 2)
 A4GL_subwin_gotoxy (menu->menu_win, 1, 2);
      else
 A4GL_subwin_gotoxy (menu->menu_win, offset, 2);


      A4GL_menu_setcolor (menu, NORMAL_MENU);
      if (type == INVERT)
	{
	  A4GL_debug ("Printing ...   %s", A4GL_string_width (opt1->shorthelp));
	  A4GL_subwin_print (menu->menu_win, "%s", A4GL_string_width (opt1->shorthelp));
	}



      A4GL_subwin_gotoxy (menu->menu_win, opt1->optpos + offset, 1);

      if (type == INVERT)
 A4GL_menu_setcolor (menu, INVERT_MENU);
      else
 A4GL_menu_setcolor (menu, NORMAL_MENU);

      A4GL_subwin_print (menu->menu_win, "%s", opt1->opt_title);
      A4GL_menu_setcolor (menu, NORMAL_MENU);
    }
#ifdef DEBUG
  {
    A4GL_debug ("Done");
  }
#endif
}

/**
 *
 * @todo Describe function
 */
void
A4GL_h_disp_title (ACL_Menu * menu, char *str)
{
  A4GL_subwin_gotoxy (menu->menu_win, 1, 1);
  A4GL_menu_setcolor (menu, NORMAL_MENU);
  A4GL_subwin_print (menu->menu_win, "%s", str);
  A4GL_menu_setcolor (menu, NORMAL_MENU);
  A4GL_zrefresh ();
}




/**
 *
 * @todo Describe function
 */
void
A4GL_h_disp_more (ACL_Menu * menu, int offset, int y, int pos)
{
  A4GL_debug ("MORE MARKERS : Displaying ... at %d %d", pos + offset, 1);
  A4GL_subwin_gotoxy (menu->menu_win, pos + offset, 1);
  A4GL_menu_setcolor (menu, NORMAL_MENU);
  A4GL_subwin_print (menu->menu_win, " ...");
}




/**
 *
 * @todo Describe function
 */
void
A4GL_clr_menu_disp (ACL_Menu * menu)
{
  /* needs fix on width */
  A4GL_menu_setcolor (menu, NORMAL_TEXT);
  A4GL_subwin_gotoxy (menu->menu_win, menu->menu_offset, menu->menu_line);
  A4GL_subwin_print (menu->menu_win,
		"                                                                                                                                                               ");
}




/**
 *
 * @todo Describe function
 */
int
A4GL_new_do_keys (ACL_Menu * menu, int a)
{
  ACL_Menu_Opts *opt1;

  opt1 = (ACL_Menu_Opts *) menu->curr_option;
  A4GL_debug ("new_do_keys A=%d", a);
  if (a == BS || a == ' ' || a == DOWNKEY || a == RIGHTKEY || a == UPKEY
      || a == LEFTKEY || a == 0xffff /* click */ )
    {
      A4GL_move_bar (menu, a);
      if (a == 0xffff)
	return 1;
      return 0;
    }

  if (a == ESC)
    {
      A4GL_debug ("Escape!");
      abort_pressed = 1;
      return 0;
    }

  if (a == CR)
    {
      A4GL_debug ("CR..");
      return 1;
    }
  A4GL_debug ("Dropped through");

  return A4GL_find_char (menu, a);
}


/**
 *
 * @todo Describe function
 */
int
A4GL_find_char (ACL_Menu * menu, int key)
{
  ACL_Menu_Opts *opt1, *opt2;
  int flg;
  opt2 = (ACL_Menu_Opts *) menu->curr_option;

  A4GL_debug ("ZZ : key = %d opt2->optkey=%s\n", key, opt2->optkey);

  if (strcmp (opt2->optkey, "EMPTY") != 0)
    {
      A4GL_debug ("defined keys only");
      flg = A4GL_check_keys (key, opt2->optkey);
    }
  else
    {
      A4GL_debug ("default key only");
      flg = A4GL_check_key (key, &opt2->opt_title[1], 1);
    }

  if (flg)
    {
      (ACL_Menu_Opts *) menu->curr_option = (ACL_Menu_Opts *) opt2;
      A4GL_debug ("We're on it!");
      return 1;
    }

  A4GL_debug ("Checking next option...");
  opt1 = (ACL_Menu_Opts *) opt2->next_option;

  if (opt1 == 0)
    opt1 = (ACL_Menu_Opts *) menu->first;

  while (opt2 != opt1)
    {
      A4GL_debug ("ZZ2 : key = %d opt1->optkey=%s\n", key, opt1->optkey);
      if (strcmp (opt1->optkey, "EMPTY"))
	{
	  A4GL_debug ("defined keys only");
	  flg = A4GL_check_keys (key, opt1->optkey);
	}
      else
	{
	  A4GL_debug ("default key only");
	  flg = A4GL_check_key (key, &opt1->opt_title[1], 1);
	}

      if (flg)
	{
	  (ACL_Menu_Opts *) menu->curr_option = (ACL_Menu_Opts *) opt1;
	  return 1;
	}
      opt1 = (ACL_Menu_Opts *) opt1->next_option;
      if (opt1 == 0)
	opt1 = (ACL_Menu_Opts *) menu->first;
    }
  return 0;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_move_bar (ACL_Menu * menu, int a)
{
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *opt2;
  int flg;
  int dir = 0;
  int opage, npage;
  void *z;
  opt1 = (ACL_Menu_Opts *) menu->curr_option;
  opage = opt1->page;
  flg = 0;
  opt2 = opt1;

  A4GL_debug ("In movebar curropt=%p", menu->curr_option);
  if (a == 0xffff)
    {
      A4GL_debug ("Decoding new option");
      z = A4GL_decode_clicked ();
      A4GL_debug ("Got z as %p", z);

      if (z)
	{
	  A4GL_debug ("Setting curropt to z");
	  opt2 = z;
	  menu->curr_option = ((ACL_Menu_Opts *) opt2);
	}
      dir = 1;
    }
  else
    {

      if (a == UPKEY || a == LEFTKEY || a == BS)
	{
	  A4GL_debug ("Left key");
	  opt2 = (ACL_Menu_Opts *) opt2->prev_option;
	  if (opt2 == 0)
	    {
	      A4GL_debug ("Move to last");
	      opt2 = (ACL_Menu_Opts *) menu->last;
	    }
	  menu->curr_option = ((ACL_Menu_Opts *) opt2);
	  dir = -1;
	}

      if (a == ' ' || a == DOWNKEY || a == RIGHTKEY)
	{
	  A4GL_debug ("Right Key");
	  opt2 = (ACL_Menu_Opts *) opt2->next_option;
	  if (opt2 == 0)
	    {
	      A4GL_debug ("Move to first");
	      opt2 = (ACL_Menu_Opts *) menu->first;
	    }
	  menu->curr_option = ((ACL_Menu_Opts *) opt2);
	  dir = 1;
	}
      A4GL_debug ("Calling find_down - dir = %d", dir);
      A4GL_find_shown (menu, 0, dir);
    }
  opt1 = (ACL_Menu_Opts *) menu->curr_option;
  npage = opt1->page;

  if (npage != opage)
    {
      A4GL_debug ("Page Changed on menu");
      menu->curr_page = npage;
      A4GL_display_menu (menu);
    }
  A4GL_gui_setfocus ((int) menu->curr_option);
  return;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_seldir (char *filespec, char *filename)
{
  int a;
  char b[80];
  char c[80];
  if (strlen (filename) <= strlen (filespec))
    return 0;
  strcpy (c, &filename[strlen (filename) - strlen (filespec)]);
  a = (strcmp (filespec, c));
  sprintf (b, "S=%s F=%s a=%d c=%s", filespec, filename, a, c);
  if (a == 0)
    {
      filename[strlen (filename) - strlen (filespec)] = 0;
      return 1;
    }
  return 0;
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
int
A4GL_load_form (char *fname2, int fno1, int fno)
{
  FILE *formfile;
  char buffer[133];
  char fname[32];
  int currno;
  char fname3[64];

  strcpy (fname3, fname2);
  strcat (fname3, acl_getenv ("A4GL_FRM_BASE_EXT"));
  formfile = A4GL_mja_fopen (fname3, "rt");
  currno = 0;
  if (formfile == 0)
    {
      printf ("Form couldn't be opened\n");
      exit (0);
    }

  while (!feof (formfile))
    {
      if (A4GL_mfgets (buffer, 132, formfile) == 0)
	break;
      if (buffer[0] == '[')
	{
	  strcpy (fname, buffer);
	  strcpy (formnames[fno], buffer);
	  currno++;
	  if (currno == fno1)
	    {
	      namescnt = 0;
	      formdetails[fno][0] = 0;
	      while (1)
		{
		  if (feof (formfile))
		    break;
		  if (A4GL_mfgets (buffer, 132, formfile) == 0)
		    break;
		  A4GL_stripnl (buffer);
		  if (buffer[0] == '[')
		    break;
		  A4GL_chktag (buffer, fno);
		  strcat (formdetails[fno], buffer);
		  if (strcmp (fname, "General") == 0)
		    {
		      if (strnicmp (buffer, "menu_line=", 9) == 0)
			{

			  sscanf (buffer, "menu_line=%d", &menu_line);

			}
		      if (strnicmp (buffer, "menutitle=", 10) == 0)
			{
			  A4GL_gsub (buffer);
			  sscanf (buffer, "menutitle=%s", menutitle);
			  A4GL_gsub (menutitle);
			}
		      if (strnicmp (buffer, "title=", 6) == 0)
			{
			  A4GL_gsub (buffer);
			  sscanf (buffer, "title=%s", titledesc);
			  A4GL_gsub (titledesc);
			}
		    }
		}
	      A4GL_load_formdata (fname2, fname, fno);
	      fclose (formfile);
	      if (stricmp (fname, "[General]\n") == 0)
		return -1;
	      else
		return 1;
	    }
	}
    }
  return 0;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_load_formdata (char *fname2, char *ftitle, int fno)
{
  FILE *formfile;
  char buffer[133];
  char fname[32];
  int currno;
  char fname3[64];
  strcpy (fname3, fname2);
  strcat (fname3, ".ini");
  formfile = A4GL_mja_fopen (fname3, "rt");
  currno = 0;
  if (formfile == 0)
    {
      return 1;
    }

  while (!feof (formfile))
    {
      if (A4GL_mfgets (buffer, 132, formfile) == 0)
	break;
      if (buffer[0] == '[')
	{
	  strcpy (fname, buffer);
	  currno++;
	  if (strcmp (fname, ftitle) == 0)
	    {
	      while (!feof (formfile))
		{
		  if (A4GL_mfgets (buffer, 132, formfile) == 0)
		    break;
		  A4GL_stripnl (buffer);
		  if (feof (formfile))
		    break;
		  if (buffer[0] == '[')
		    break;
		  A4GL_set_value (fno, buffer);
		}

	      fclose (formfile);
	      return 0;
	    }
	}
    }

  fclose (formfile);
  return 0;
}



/**
 *
 * @todo Describe function
 */
void
A4GL_stripbracket (char *str)
{
  int a;
  for (a = 0; a < strlen (str); a++)
    {
      if (str[a] == ']')
	{
	  str[a] = 0;
	  break;
	}
    }
}


/**
 *
 * @todo Describe function
 */
void
A4GL_gsub (char *str)
{
  int a;
  for (a = 0; a < strlen (str); a++)
    {
      if (str[a] == '_')
	str[a] = ' ';
      else if (str[a] == ' ')
	str[a] = '_';
    }
}

/**
 *
 * @todo Describe function
 */
void
A4GL_chktag (char *buff, int fno)
{
  char buff2[132];
  char *ptr, *ptr_end;
  strcpy (buff2, buff);
  ptr = strchr (buff2, '{');
  if (ptr == NULL)
    return;
  while (1)
    {
      ptr = strchr (buff2, '{');
      if (ptr == NULL)
	break;
      ptr_end = strchr (buff2, '}');
      *ptr_end = 0;
      *ptr = 0;
      if (namescnt == MAXFIELDS)
	{
	  printf ("Too Many field on single form - Max. of %d\n", MAXFIELDS);
	  exit (0);
	}
      strcpy (names[fno][namescnt++], ptr + 1);

      strcat (buff2, ptr_end + 1);
    }
  strcpy (buff, buff2);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_value (int fno, char *buffer)
{
  int a;
  char *name;
  char *value;
  name = buffer;
  value = strchr (buffer, '=');
  if (value == 0)
    return;
  *value = 0;
  value++;
  for (a = 0; a < MAXFIELDS; a++)
    {
      if (strcmp (names[fno][a], name) == 0)
	{
	  strcpy (arr[fno][a], value);
	  break;
	}
    }
}

/**
 *
 * @todo Describe function
 */
char *
A4GL_mfgets (char *s, int n, FILE * fp)
{
  char *z;
  while (1)
    {
      s[0] = 0;
      z = fgets (s, n, fp);
      if (feof (fp) || z == NULL)
	{
	  return 0;
	}
      if (s[0] == '#')
	continue;
      break;
    }
  return z;
}





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
 *
 * @todo Describe function
 */
void
A4GL_set_message (char *str, int x, int y)
{
  message (&set_mess, str, x, y);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_clr_message (void)
{
  A4GL_clearbox (&set_mess);
}


/**
 *
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
	      if (!abort_pressed)
		{
		  A4GL_mja_endwin ();
		  system (cmd);
		  sleep (1);
		  A4GL_mja_refresh ();
		}
	      inprompt = 0;
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


/**
 *
 * @todo Describe function
 */
void
A4GL_chklistbox (char **arr, int elem, int mult, int x, int y, int w, int h)
{
  int a;
  textarea area;
  int pg_top = 0;
  char pbuff[40];
  int sel;

#define pos_chklistbox(p) mja_gotoxy(x+1,y+1+p-pg_top)


  if (h > elem)
    h = elem;
  A4GL_newbox (&area, x, y, x + w + 1, y + h + 1, BORDER_BOX);

  A4GL_mja_gotoxy (x + 1, y + 1);
  sprintf (pbuff, "%%-%d.%ds %%c", w - 2, w - 2);
  for (a = 0; a < 1024; a++)
    selected[a] = ' ';

  curr_opt = 0;
  for (a = 0; a < h; a++)
    {
      if (a >= elem)
	break;
      if (curr_opt == a)
 A4GL_mja_setcolor (TITLE_COL);
      else
 A4GL_mja_setcolor (NORMAL_TEXT);
      pos_chklistbox (a);
      printw (pbuff, arr[a], selected[a]);
    }

  A4GL_mja_refresh ();
  abort_pressed = 0;
  max_opt = elem - 1;
  sel = 0;
  while (1)
    {

      a = curr_opt;

      if (A4GL_do_key_menu ())
	{
	  if (selected[a] == ' ')
	    {
	      selected[a] = 'X';
	      sel++;
	    }
	  else
	    {
	      selected[a] = ' ';
	      sel--;
	    }
	  if (mult == 0)
	    break;
	}

      if (abort_pressed)
	break;

      if (curr_opt - pg_top >= h)
	{
	  pg_top = curr_opt - h + 1;
	  for (a = 0; a < h; a++)
	    {
	      if (curr_opt == a + pg_top)
	 A4GL_mja_setcolor (TITLE_COL);
	      else
	 A4GL_mja_setcolor (NORMAL_TEXT);
	      pos_chklistbox (a + pg_top);
	      printw (pbuff, arr[a + pg_top], selected[a + pg_top]);
	    }
	  continue;
	}

      if (curr_opt - pg_top <= 0)
	{
	  pg_top = curr_opt;
	  for (a = 0; a < h; a++)
	    {
	      if (a >= elem + pg_top)
		break;
	      if (curr_opt == a + pg_top)
	 A4GL_mja_setcolor (TITLE_COL);
	      else
	 A4GL_mja_setcolor (NORMAL_TEXT);
	      pos_chklistbox (a + pg_top);
	      printw (pbuff, arr[a + pg_top], selected[a + pg_top]);
	    }
	  continue;
	}

      A4GL_mja_setcolor (NORMAL_TEXT);
      pos_chklistbox (a);
      printw (pbuff, arr[a], selected[a]);
      A4GL_mja_setcolor (TITLE_COL);
      pos_chklistbox (curr_opt);
      printw (pbuff, arr[curr_opt], selected[curr_opt]);
      A4GL_mja_setcolor (NORMAL_TEXT);
      A4GL_mja_refresh ();

    }
  A4GL_clearbox (&area);
  if (mult)
    {
      sprintf (pbuff, "%d rows selected", sel);
      A4GL_error_box (pbuff);
    }
}


/**
 *
 * @todo Describe function
 */
int
A4GL_isselected (int a)
{
  if (selected[a] == 'X')
    return 1;
  else
    return 0;
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_next_option (void *vmenu, char *nextopt)
{
  int a;
  int f = 0;
  ACL_Menu_Opts *option;
  ACL_Menu_Opts *old_option;
  char s[256];
  ACL_Menu *menu;
  menu = vmenu;
  A4GL_h_disp_opt (menu, menu->curr_option, menu->menu_offset, menu->mn_offset,
	      NORM);
  A4GL_trim (nextopt);
  old_option = (ACL_Menu_Opts *) menu->curr_option;
  option = (ACL_Menu_Opts *) menu->first;
  for (a = 0; a < menu->num_opts; a++)
    {
      strcpy (s, &option->opt_title[1]);
      A4GL_trim (s);

      A4GL_debug ("Testing '%s' = '%s'", s, nextopt);

      if (strcmp (s, nextopt) == 0)
	{
	  f = 1;
	  (ACL_Menu_Opts *) menu->curr_option = option;
	  break;
	}
      (ACL_Menu_Opts *) option =
	(ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
    }

  if (f == 0)
    {
      option = old_option;
      A4GL_debug ("Menu Option %s not found", nextopt);
    }

  A4GL_gui_setfocus ((int) menu->curr_option);
  A4GL_display_menu (menu);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_menu_hide_ap (ACL_Menu * menu, va_list * ap)
{
  A4GL_debug ("Menu hide\n");
  A4GL_menu_attrib (menu, 0, *ap);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_menu_show_ap (ACL_Menu * menu, va_list * ap)
{
  A4GL_debug ("Show");
  A4GL_menu_attrib (menu, 1, ap);
  A4GL_find_shown (menu, 0, 1);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_menu_attrib (ACL_Menu * menu, int attr, va_list ap)
{
  int a;
  ACL_Menu_Opts *option;
  char *argp;
  char s[256];
  int flg;
  A4GL_debug ("Menu attrib %d\n", attr);
  while ((argp = va_arg (ap, char *)))
    {
      A4GL_trim (argp);
      A4GL_debug ("change attrib to %d of %s", attr, argp);
      option = (ACL_Menu_Opts *) menu->first;
      for (a = 0; a < menu->num_opts; a++)
	{
	  A4GL_debug ("before copy");
	  strcpy (s, &option->opt_title[1]);
	  A4GL_debug ("after copy '%s' '%s'", s, option->opt_title);
	  A4GL_trim (s);
	  A4GL_debug ("trim %s", s);
	  flg = 0;

	  if (strcmp (argp, MENU_ALL) != 0)
	    {
	      A4GL_debug ("Cmp '%s' to '%s'", s, argp);
	      if (strcmp (s, argp) == 0)
		{
		  A4GL_debug ("Cmpok\n");
		  flg = 1;
		}
	      else
		{
		  A4GL_debug ("Cmpbad\n");
		}
	    }
	  else
	    flg = 1;

	  if (flg == 1)
	    {
	      A4GL_debug ("   FOund it : %s , %s (%x) %d", s, argp,
		     option->attributes & ACL_MN_HIDE, attr);
	      if (attr)
		{
		  A4GL_debug ("Attemp to turn on %d %d %d", option->attributes,
			 ACL_MN_HIDE, option->attributes & ACL_MN_HIDE);
		  if (option->attributes & ACL_MN_HIDE)
		    {
		      A4GL_debug ("Turn on");
		      option->attributes = option->attributes - ACL_MN_HIDE;
		    }
		}
	      else
		{
		  if (!(option->attributes & ACL_MN_HIDE))
		    {
		      A4GL_debug ("Turn off");
		      option->attributes = option->attributes + ACL_MN_HIDE;
		    }
		}
	    }
	  A4GL_debug ("chk next");
	  (ACL_Menu_Opts *) option =
	    (ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
	  A4GL_debug ("set next");
	}
    }
  A4GL_debug ("f1");
  A4GL_find_shown (menu, 0, 1);
  A4GL_debug ("f2");
  A4GL_size_menu (menu);		/* MJA 10/5/2000 */
  /*
     A4GL_clr_menu_disp (menu);
     A4GL_debug ("f3");
   */
  A4GL_display_menu (menu);
  A4GL_debug ("f4");
  va_end (ap);
}

/**
 *
 * @todo Describe function
 */
int
A4GL_find_shown (ACL_Menu * menu, int chk, int dir)
{
  ACL_Menu_Opts *opt;
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *lastopt;
  A4GL_debug ("In find_shown");

  opt = (ACL_Menu_Opts *) menu->curr_option;

  lastopt = (ACL_Menu_Opts *) menu->curr_option;

  A4GL_debug ("current item = (%s) %d", menu->curr_option->opt_title,
	 ((((ACL_Menu_Opts *) (menu->curr_option))->
	   attributes) & ACL_MN_HIDE));

  while ((((ACL_Menu_Opts *) (menu->curr_option))->attributes) & ACL_MN_HIDE)
    {
      opt1 = (ACL_Menu_Opts *) (menu->curr_option);
      if (dir == 1)
	{
	  menu->curr_option = (ACL_Menu_Opts *) opt1->next_option;
	  if (menu->curr_option == 0)
	    {
	      (ACL_Menu_Opts *) menu->curr_option =
		(ACL_Menu_Opts *) menu->first;
	    }
	}
      else
	{
	  (ACL_Menu_Opts *) menu->curr_option =
	    (ACL_Menu_Opts *) (menu->curr_option)->prev_option;
	  if (menu->curr_option == 0)
	    {
	      (ACL_Menu_Opts *) menu->curr_option =
		(ACL_Menu_Opts *) menu->last;
	    }
	}



      A4GL_debug ("A5  ");
      A4GL_debug ("A5a %p", ((ACL_Menu_Opts *) menu));
      A4GL_debug ("A5b %p %p", (ACL_Menu_Opts *) menu->curr_option,
	     (ACL_Menu_Opts *) lastopt);

      if (((ACL_Menu_Opts *) menu->curr_option == (ACL_Menu_Opts *) lastopt))
	{
	  if (chk)
	    {
	      A4GL_debug ("A6");
	      A4GL_exitwith ("No current option");
	      return 1;
	      break;
	    }
	  else
	    {
	      A4GL_gui_setfocus ((int) menu->curr_option);
	      A4GL_debug ("Return!");
	      return 1;
	    }
	}
      A4GL_debug ("A5c");
    }
  A4GL_debug ("A7");


  A4GL_gui_setfocus ((int) menu->curr_option);
  return 0;
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
aclfgli_pr_message (int attr, int wait)
{
  char p[2048];
  long w;
  int ml;
  int width;
  WINDOW *cw;
  char buff[256];
  static WINDOW *mw;

  A4GL_debug ("In message...");
  cw = (WINDOW *) A4GL_get_currwin ();
  ml = A4GL_getmessage_line ();
  A4GL_debug ("MJA - Got message line as %d\n", ml);
  width = A4GL_get_curr_width ();
  A4GL_pop_char (p, A4GL_get_curr_width ());

  if (strlen (p) == 0)
    {
      memset (p, ' ', sizeof (p));
      p[get_curr_width ()] = 0;

    }
  A4GL_debug ("Message : '%s'", p);
  A4GL_push_char (p);

  A4GL_debug (" Wait =%d\n", wait);
  if (wait == 0)
    {
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
    }

  return;			/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

  A4GL_debug (" NW PTR");
  sprintf (buff, "MS%p", cw);

  if (A4GL_has_pointer (buff, MESSAGEWIN))
    {
      mw = A4GL_find_pointer (buff, MESSAGEWIN);
      A4GL_debug ("Removing old message window... %p", mw);
      delwin (mw);
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
	derwin (cw, 1, width, ml - 1 + A4GL_iscurrborder () * 2, A4GL_iscurrborder ());
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
  A4GL_gui_message (p, A4GL_getmessage_line ());
}



/**
 *
 * @todo Describe function
 */
void
A4GL_size_menu (ACL_Menu * menu)
{
  ACL_Menu_Opts *opt1;
  int disp_cnt2 = 0;
  char disp_str[80];
  int disp_cnt;
  int s_length;
  int page = 0;

  A4GL_clr_menu_disp (menu);

#ifdef DEBUG
  {
    A4GL_debug ("Sizing Menu %s", menu->menu_title);
  }
#endif

  if (strlen (menu->menu_title) > 0)
    {
      if (menu->menu_type == ACL_MN_HORIZ_NOTBOXED)
	{
	  sprintf (disp_str, "%s : ", menu->menu_title);
	  disp_cnt = strlen (disp_str) + 1;
	}
      else
	sprintf (disp_str, " %s ", menu->menu_title);
    }

  opt1 = (ACL_Menu_Opts *) menu->first;

  while (opt1 != 0)
    {
#ifdef DEBUG
      {
 A4GL_debug ("Here... %p", opt1->opt_title);
      }
      {
 A4GL_debug ("Processing %s", opt1->opt_title);
      }
#endif
      if ((opt1->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
	{
	  A4GL_debug (" Show %s\n", opt1->opt_title);
	}
      else
	{
	  A4GL_debug (" HIdden %s\n", opt1->opt_title);
	}
      if ((opt1->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
	{
#ifdef DEBUG
	  {
	    A4GL_debug ("is shown %s", opt1->opt_title);
	  }
#endif
	  s_length = strlen (opt1->opt_title);
	  A4GL_debug ("disp=%d width=%d %d %s", disp_cnt2, menu->w,
		 menu->menu_offset, opt1->opt_title);

	  if (disp_cnt2 + menu->menu_offset + s_length + 2 >= menu->w)
	    {
#ifdef DEBUG
	      {
	 A4GL_debug ("New Page");
	      }
#endif
	      page++;
	      disp_cnt2 = 5;
	    }
#ifdef DEBUG
	  {
	    A4GL_debug ("Here");
	  }
#endif
	  opt1->page = page;


	  opt1->optpos = disp_cnt2;
	  disp_cnt2 += s_length;
	}
#ifdef DEBUG
      {
 A4GL_debug ("Here 2");
      }
#endif

      /*
         opt1->optpos = disp_cnt2;
         disp_cnt2 += s_length;
       */
#ifdef DEBUG
      {
 A4GL_debug ("Here 3 opt1=%p", opt1);
      }
#endif
      opt1 = (ACL_Menu_Opts *) opt1->next_option;
#ifdef DEBUG
      {
 A4GL_debug ("Here 4");
      }
#endif
    }
#ifdef DEBUG
  {
    A4GL_debug ("Here 5");
  }
#endif
  menu->max_page = page;
#ifdef DEBUG
  {
    A4GL_debug ("Done sizing");
  }
#endif
}



/**
 *
 * @todoindent: Standard input:3093: Warning:old style assignment ambiguity in "=-".  Assuming "= -"

 Describe function
 */
void
A4GL_set_bkg (WINDOW * win, int attr)
{

  wbkgd (win, A4GL_decode_aubit_attr (attr, 'w'));
  //wbkgdset (win, 0);
  wbkgdset (win, A4GL_decode_aubit_attr (attr, 'w'));

}


/* Menu color handling */


/**
 *
 * @todo Describe function
 */
void
A4GL_menu_setcolor (ACL_Menu * menu, int typ)
{
  WINDOW *currwin;
  long attr;
  long attr2;
  currwin = menu->menu_win;
  attr = menu->attrib;
  //if (attr & 255) attr = attr - (attr & 255);


  /* wbkgd(menu->menu_win,0); */

  A4GL_debug ("Window background = %x - window - %x", attr, currwin);

  if ((attr - (attr & 0xff)) == 0)
    {
      attr = A_NORMAL + (attr & 0xff);
    }

  if ((attr & 0xff) == 0)
    {
      A4GL_debug ("Nothing specified for the background..");
      attr += ' ';
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
int
A4GL_menu_getkey (ACL_Menu * menu)
{
  char cmd[60] = "";
  int a;
  A4GL_debug ("Getting character for menu from window %p", menu->menu_win);
  a = -1;
  A4GL_set_abort (0);
  while (1)
    {
      /* a = A4GL_getch_swin (menu->menu_win); */
      wprintw (menu->menu_win, "%s", menu->menu_title);
      wrefresh (menu->menu_win);
      doupdate ();
      a = wgetch (menu->menu_win);

      if (a == -1)
	{
	  if (abort_pressed)
	    {
	      A4GL_debug ("Got interrupt key pressed....");
	      a = A4GL_key_val ("INTERRUPT");	/* MJA 31/7/00 */
	      wgetch (menu->menu_win);
	      A4GL_set_abort (0);
	      return a;
	    }
	}

      A4GL_debug (">>>>>>>>>>>A=%d %c\n", a, isprint (a) ? a : '.');
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
	      A4GL_debug ("asking for cmdline");
	      A4GL_ask_cmdline ("Enter Command", cmd, 60);
	      if (!abort_pressed)
		{
		  A4GL_mja_endwin ();
		  system (cmd);
		  sleep (1);
		  A4GL_mja_refresh ();
		}
	      inprompt = 0;
	      continue;
	    }
	}

      A4GL_debug ("Returning A\n");
      return a;
    }
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_option_value (char type, int keyval)
{
  A4GL_debug ("Set option value : %c %d", type, keyval);
  switch (type)
    {
    case 'C':
      std_dbscr.comment_line = keyval;
      break;
    case 'E':
      std_dbscr.error_line = keyval;
      break;
    case 'F':
      std_dbscr.form_line = keyval;
      break;
    case 'M':
      std_dbscr.menu_line = keyval;
      break;
    case 'm':
      std_dbscr.message_line = keyval;
      break;
    case 'P':
      std_dbscr.prompt_line = keyval;
      break;
    case 'A':
      std_dbscr.acckey = keyval;
      break;
    case 'D':
      std_dbscr.delkey = keyval;
      break;
    case 'I':
      std_dbscr.inskey = keyval;
      break;
    case 'N':
      std_dbscr.nextkey = keyval;
      break;
    case 'p':
      std_dbscr.prevkey = keyval;
      break;
    case 'H':
      std_dbscr.helpkey = keyval;
      break;
    case 'd':
      std_dbscr.dispattr = keyval;
      break;
    case 'i':
      std_dbscr.inpattr = keyval;
      break;
    case 'W':
      std_dbscr.input_wrapmode = keyval;
      break;
    case 'f':
      std_dbscr.fieldconstr = keyval;
      break;
    case 'S':
      std_dbscr.sqlintr = keyval;
      break;
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
A4GL_endis_fields_ap (int en_dis, va_list * ap)
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
ACL_Menu *
A4GL_new_menu_tui_oldway (char *title,
		     int x, int y,
		     int mn_type, int help_no, int nopts, va_list * ap)
{
  int ret;
  char *argp_c = 0;
  char op1[256];
  char buff[256];
  int argp_i;
  ACL_Menu *menu;
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *opt2;

  if (nopts < 1)
    return 0;
  strcpy (buff, title);
  A4GL_trim (buff);
  A4GL_debug (" - Menu title : '%s'", title);
  menu = nalloc (ACL_Menu);
  strcpy (menu->menu_title, buff);
  A4GL_trim (menu->menu_title);


  menu->menu_type = mn_type;
  menu->help_no = help_no;
  menu->curr_option = 0;
  menu->window_name[0] = 0;
  menu->x = x;
  menu->y = y;
  menu->curr_page = 0;
  menu->mn_offset = 0;
  opt1 = nalloc (ACL_Menu_Opts);
  menu->first = (ACL_Menu_Opts *) opt1;
  opt1->prev_option = 0;
  /* va_start (ap, nopts); */
  A4GL_debug ("Menu=%p &Menu=%p", menu, &menu);
  A4GL_gui_startmenu (title, (long) menu);
  for (ret = 0; ret < nopts; ret++)
    {
      if (ret != 0)
	{
	  opt2 = nalloc (ACL_Menu_Opts);
	  (ACL_Menu_Opts *) opt2->prev_option = (ACL_Menu_Opts *) opt1;
	  (ACL_Menu_Opts *) opt1->next_option = (ACL_Menu_Opts *) opt2;
	  opt2->next_option = 0;
	  opt1 = opt2;
	}
      opt1->opt_no = ret;
      if (strlen (argp_c))
	{
	  strcpy (opt1->opt_title, " ");
	  strcpy (op1, argp_c);
	  A4GL_gui_menuopt (argp_c, (int) opt1);
	  A4GL_trim (op1);
	  strcat (opt1->opt_title, op1);
	  strcat (opt1->opt_title, " ");
	}
      else
	{
	  strcpy (opt1->opt_title, "");
	}

      opt1->optlength = strlen (opt1->opt_title);

      argp_c = va_arg (*ap, char *);
      strcpy (opt1->optkey, argp_c);

      argp_c = va_arg (*ap, char *);
      strcpy (opt1->shorthelp, argp_c);

      argp_i = va_arg (*ap, int);
      opt1->help_no = argp_i;
      A4GL_debug ("Help number for %s = %d", opt1->opt_title, argp_i);

      argp_i = va_arg (*ap, int);
      opt1->attributes = argp_i;

      if (opt1->optlength == 0)
	opt1->attributes |= ACL_MN_HIDE;
      /* gui_menuopt(opt1->opt_title,opt1->shorthelp,opt1->optkey,opt1->help_no,opt1->attributes); */
    }
  va_end (*ap);
  menu->last = (ACL_Menu_Opts *) opt1;

  (ACL_Menu_Opts *) menu->curr_option = (ACL_Menu_Opts *) menu->first;
  while (menu->curr_option->attributes & ACL_MN_HIDE)
    {
      if (menu->curr_option == menu->last)
	break;
      (ACL_Menu_Opts *) menu->curr_option =
	(ACL_Menu_Opts *) menu->curr_option->next_option;
    }


  A4GL_gui_setfocus ((int) menu->curr_option);
  menu->num_opts = nopts;
  A4GL_gui_endmenu ((int) menu);
  return menu;
}


/**
 * 4GL CALL
 * @todo Describe function
 */
ACL_Menu *
A4GL_new_menu_create (char *title, int x, int y, int mn_type, int help_no)
{
  char buff[256];
  ACL_Menu *menu;
  strcpy (buff, title);
  A4GL_trim (buff);
  menu = nalloc (ACL_Menu);
  strcpy (menu->menu_title, buff);
  A4GL_trim (menu->menu_title);
  menu->menu_type = mn_type;
  menu->help_no = help_no;
  menu->curr_option = 0;
  menu->window_name[0] = 0;
  menu->x = x;
  menu->y = y;
  menu->curr_page = 0;
  menu->mn_offset = 0;
  menu->first = 0;
  menu->num_opts = 0;
  A4GL_gui_startmenu (title, (long) menu);
  return menu;
}

/**
 *  4GL CALL
 * @todo Describe function
 */
void
A4GL_add_menu_option (ACL_Menu * menu, char *txt, char *keys, char *desc,
		 int helpno, int attr)
{
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *opt2;
  char op1[256];
  int nopts;
  opt1 = nalloc (ACL_Menu_Opts);
  A4GL_debug ("MJAMJA helpno=%d", helpno);

  opt1->next_option = 0;
  opt1->prev_option = 0;
  menu->num_opts++;

  A4GL_debug ("In add menu option : %s\n", txt);

  A4GL_debug ("MJAMJA helpno=%d", helpno);
  if (menu->first == 0)
    {
      A4GL_debug ("Setting first..\n");
      menu->first = opt1;
      menu->last = opt1;
    }


  nopts = menu->num_opts;
  opt2 = menu->last;
  opt1->opt_no = nopts - 1;
  A4GL_debug ("MJAMJA helpno=%d", helpno);
  if (opt1 != opt2)
    {
      opt2->next_option = opt1;
      opt1->prev_option = opt2;
    }

  A4GL_debug ("menu->first=%p opt1=%p opt2=%p ", menu->first, opt1, opt2);
  A4GL_debug ("opt1 : prev=%p next=%p", opt1->prev_option, opt1->next_option);
  A4GL_debug ("opt2 : prev=%p next=%p", opt2->prev_option, opt2->next_option);

  A4GL_debug ("MJAMJA helpno=%d", helpno);
  if (strlen (txt))
    {
      strcpy (opt1->opt_title, " ");
      strcpy (op1, txt);
      A4GL_trim (op1);
      strcat (opt1->opt_title, op1);
      strcat (opt1->opt_title, " ");
    }
  else
    {
      strcpy (opt1->opt_title, "");
    }

  A4GL_debug ("MJAMJA helpno=%d", helpno);
  opt1->optlength = strlen (opt1->opt_title);
  A4GL_debug ("MJAMJA helpno=%d", helpno);
  strcpy (opt1->optkey, keys);
  A4GL_debug ("MJAMJA helpno=%d", helpno);
  strcpy (opt1->shorthelp, desc);
  A4GL_debug ("MJA setting opt1->help_no = %d", helpno);
  opt1->help_no = helpno;
  opt1->attributes = attr;
  if (opt1->optlength == 0)
    opt1->attributes |= ACL_MN_HIDE;
  menu->last = (ACL_Menu_Opts *) opt1;
  menu->num_opts = nopts;
  A4GL_debug ("MJA opt1->help_no = %d", opt1->help_no);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_finish_create_menu (ACL_Menu * menu)
{
  (ACL_Menu_Opts *) menu->curr_option = (ACL_Menu_Opts *) menu->first;

  while (menu->curr_option->attributes & ACL_MN_HIDE)
    {
      if (menu->curr_option == menu->last)
	break;
      (ACL_Menu_Opts *) menu->curr_option =
	(ACL_Menu_Opts *) menu->curr_option->next_option;
    }

  A4GL_gui_setfocus ((int) menu->curr_option);
  A4GL_gui_endmenu ((int) menu);
  A4GL_debug ("Current option=%p", menu->curr_option);
  A4GL_debug ("Current option help=%d", menu->curr_option->help_no);
  return;
}





/**
 * 4GL CALL
 * @todo Describe function
 */
ACL_Menu *
A4GL_new_menu (char *title,
	  int x, int y, int mn_type, int help_no, int nopts, va_list * ap)
{
  int ret;
  char *argp_c;
  char op1[256];
  char buff[256];
  int argp_i;
  ACL_Menu *menu;
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *opt2;

  if (nopts < 1)
    return 0;
  strcpy (buff, title);
  A4GL_trim (buff);
  A4GL_debug (" Menu title : '%s'", title);
  menu = nalloc (ACL_Menu);
  strcpy (menu->menu_title, buff);
  A4GL_trim (menu->menu_title);


  menu->menu_type = mn_type;
  menu->help_no = help_no;
  menu->curr_option = 0;
  menu->window_name[0] = 0;
  menu->x = x;
  menu->y = y;
  menu->curr_page = 0;
  menu->mn_offset = 0;
  opt1 = nalloc (ACL_Menu_Opts);
  menu->first = (ACL_Menu_Opts *) opt1;
  opt1->prev_option = 0;
  /* va_start (ap, nopts); */
  A4GL_debug ("Menu=%p &Menu=%p", menu, &menu);
  A4GL_gui_startmenu (title, (long) menu);
  for (ret = 0; ret < nopts; ret++)
    {
      if (ret != 0)
	{
	  opt2 = nalloc (ACL_Menu_Opts);
	  (ACL_Menu_Opts *) opt2->prev_option = (ACL_Menu_Opts *) opt1;
	  (ACL_Menu_Opts *) opt1->next_option = (ACL_Menu_Opts *) opt2;
	  opt2->next_option = 0;
	  opt1 = opt2;
	}
      opt1->opt_no = ret;
      argp_c = va_arg (*ap, char *);
      A4GL_debug ("argp_c = %s\n", argp_c);
      if (strlen (argp_c))
	{
	  strcpy (opt1->opt_title, " ");
	  strcpy (op1, argp_c);
	  A4GL_gui_menuopt (argp_c, (int) opt1);
	  A4GL_trim (op1);
	  strcat (opt1->opt_title, op1);
	  strcat (opt1->opt_title, " ");
	}
      else
	{
	  strcpy (opt1->opt_title, "");

	}
      opt1->optlength = strlen (opt1->opt_title);

      argp_c = va_arg (*ap, char *);
      strcpy (opt1->optkey, argp_c);

      argp_c = va_arg (*ap, char *);
      strcpy (opt1->shorthelp, argp_c);

      argp_i = va_arg (*ap, int);
      opt1->help_no = argp_i;
      A4GL_debug ("Help number for %s = %d", opt1->opt_title, argp_i);

      argp_i = va_arg (*ap, int);
      opt1->attributes = argp_i;

      if (opt1->optlength == 0)
	opt1->attributes |= ACL_MN_HIDE;
      /* gui_menuopt(opt1->opt_title,opt1->shorthelp,opt1->optkey,opt1->help_no,opt1->attributes); */
    }
  va_end (*ap);
  menu->last = (ACL_Menu_Opts *) opt1;

  (ACL_Menu_Opts *) menu->curr_option = (ACL_Menu_Opts *) menu->first;
  while (menu->curr_option->attributes & ACL_MN_HIDE)
    {
      if (menu->curr_option == menu->last)
	break;
      (ACL_Menu_Opts *) menu->curr_option =
	(ACL_Menu_Opts *) menu->curr_option->next_option;
    }


  A4GL_gui_setfocus ((int) menu->curr_option);
  menu->num_opts = nopts;
  A4GL_gui_endmenu ((int) menu);
  return menu;
}

/**
 * 4GL CALL - also used in libaubit4gl via API_UI
 * exit CURSES mode and return in line terminal mode
 * @todo Describe function
 */
void
A4GL_gotolinemode (void)
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



/* ============================== EOF ============================== */
