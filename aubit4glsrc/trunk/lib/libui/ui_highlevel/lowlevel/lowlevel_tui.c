static void A4GL_do_pause (void);
static int A4GL_curses_to_aubit (int a);
static int A4GL_curses_to_aubit_int (int a);
#include "a4gl_libaubit4gl.h"
#include "a4gl_incl_4gldef.h"
#include "lowlevel.h"
#include <curses.h>
#include <form.h>
#include <panel.h>
#include "formdriver.h"

int inprompt = 0;

int chars_normal[6];
int have_default_colors = 0;

static void A4GL_clear_prompt (struct s_prompt *prmt);
void A4GL_LL_screen_update (void);
void A4GL_LL_set_bkg (void *win, int attr);
int A4GL_LL_decode_aubit_attr (int a, char s);

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

static void A4GL_do_pause (void)
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
  endwin ();
  A4GL_set_scrmode ('L');
}




void *
A4GL_LL_create_window (int h, int w, int y, int x, int border)
{
  WINDOW *win;
  PANEL *pan;
  WINDOW *dswin;


  A4GL_debug ("%d %d %d %d %d", h, w, y, x, border);

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
      win = newwin (h + 2, w + 2, y - 2, x - 2);
      A4GL_debug ("newwin returns %p", win);
    }

  if (border == 2)
    {
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
  A4GL_debug ("pan=%p", pan);
  keypad (win, TRUE);
  top_panel (pan);
  A4GL_LL_screen_update ();
  return pan;
}



void
A4GL_LL_remove_window (void *x)
{
  WINDOW *w;
  w = panel_window (x);
  del_panel (x);
  delwin (w);
}

void
A4GL_LL_wadd_char_xy_col (void *win, int x, int y, int ch)
{
  int ch2;
  int attr;
  void *p;
  attr = A4GL_LL_decode_aubit_attr (ch & 0xffffff00, 'w');
  ch2 = ch & 0xff;
  //A4GL_debug ("x=%d y=%d ch2=%d", x, y, ch2);
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
A4GL_LL_screen_refresh (void)
{
// Blank the screen and redraw from scratch
A4GL_debug("CURSES : refresh");
  clearok (curscr, 1);
  A4GL_LL_screen_update ();
}

int
A4GL_LL_colour_code (int a)
{
  int z, b;
  z = 1;

  if (!has_colors () || A4GL_isyes (acl_getenv ("MONO")))
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
      if (!A4GL_isyes (acl_getenv ("CLASSIC_I4GL_MONO")))
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
  int nattr;
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
  A4GL_LL_screen_update ();
  A4GL_do_pause ();
  UILIB_A4GL_remove_window ("error");
  A4GL_LL_screen_update ();
  A4GL_debug ("All done in error box");
  //A4GL_mja_setcolor (NORMAL_TEXT);
}

void *
A4GL_LL_display_form (struct s_form_dets *f, int attrib)
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
	  A4GL_display_internal (1, a + 1, "", 0, 1);
	}
      else
	{
	  A4GL_display_internal (1, a, "", 0, 1);
	}
    }
  scale_form (f->form, &rows, &cols);
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
  if (a == E_POSTED)
    {
      unpost_form (f->form);
      a = set_form_win (f->form, panel_window(w));
    }

  a = set_form_sub (f->form, drwin);

  A4GL_debug ("setup windows");
  keypad (panel_window ((PANEL *) w), TRUE);
  sprintf (buff, "Currwinno=%d", A4GL_get_currwinno ());
  /*error_box(buff); */
  //windows[A4GL_get_currwinno()].form = f;

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
    }
//A4GL_debug("Returning ca = %d %x (visible=%d)",ca,ca,!(ca&A_INVIS));
  if (A4GL_isyes (acl_getenv ("NO_INVIS_ATTR")))
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

  f = new_field (rows, cols, frow, fcol, 0, 0);

  if (f)
    {
      A4GL_gui_mkfield (rows, cols, frow, fcol, f);
      A4GL_debug ("Field created - setting attributes");
      /*A4GL_set_field_attr (f); */
      A4GL_debug ("ZZZZ - SET OPTS");
      field_opts_off (f, O_ACTIVE);
      field_opts_off (f, O_EDIT);
      field_opts_off (f, O_BLANK);
      A4GL_debug ("STATIC ON");
      field_opts_on (f, O_STATIC);

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
      f = new_field (1, 1, frow, fcol, 0, 0);
    }
  else
    {
      A4GL_debug ("Making normal label '%s' @ frow=%d fcol=%d\n", label, frow,
		  fcol);
      f = new_field (1, l, frow, fcol, 0, 0);
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
	      set_field_back (f, A_ALTCHARSET);
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
	      set_field_back (f, A_ALTCHARSET);
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
	  set_field_opts (f, field_opts (f) & ~O_ACTIVE);
	  A4GL_debug ("SET FIELD OPTS : STATIC %x ",
		      field_opts (f) & O_STATIC);
	  return f;
	}
      else
	{
	  label[0] = label[1];
	  label[1] = label[0];
	}
    }


  A4GL_gui_mklabel (1, strlen (label), frow, fcol, label);

  if (f)
    {
      A4GL_debug ("99 set field buffer to label = **%s**", label);
      set_field_buffer (f, 0, label);
      //A4GL_mja_set_field_buffer (f, 0, label);
      set_field_opts (f, field_opts (f) & ~O_ACTIVE);
      A4GL_debug ("SET FIELD OPTS : STATIC %x ", field_opts (f) & O_STATIC);
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
  set_new_page (field, n);
}


void
A4GL_LL_set_field_userptr (void *field, void *ptr)
{
  set_field_userptr (field, ptr);
}

void *
A4GL_LL_get_field_userptr (void *field)
{
  return field_userptr (field);
}

void
A4GL_LL_set_field_attr (void *field)
{
  struct struct_scr_field *f;
  int bc;
  int fc;
  bc = field_back (field);
  fc = field_fore (field);

  A4GL_debug ("In set_field_attr");
  f = (struct struct_scr_field *) (field_userptr (field));
  if (f == 0)
    return;
  A4GL_debug ("Setting defs");
  A4GL_default_attributes (field, f->datatype);
  A4GL_debug ("Set defs");

  if (A4GL_has_bool_attribute (f, FA_B_AUTONEXT))
    {
      A4GL_debug ("Autoskip");
      A4GL_debug ("ZZZZ - SET OPTS");
      field_opts_on (field, O_AUTOSKIP);
    }

  if (A4GL_has_bool_attribute (f, FA_B_INVISIBLE))
    {
      A4GL_debug ("Invisible ***");
      A4GL_debug ("ZZZZ - SET OPTS");
      field_opts_off (field, O_PUBLIC);
    }

  if (f->dynamic != 0)
    {
      A4GL_debug ("ZZZZ - SET OPTS STATIC OFF");
      field_opts_off (field, O_STATIC);

      if (f->dynamic == -1)
	{
	  A4GL_debug ("Max size is lots CARAT");
	  set_max_field (field, 0);
	}
      else
	{
	  set_max_field (field, f->dynamic);
	  A4GL_debug ("Max size=%d CARAT", f->dynamic);
	}

    }
  else
    {
      field_opts_on (field, O_STATIC);
    }

  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY))
    {
      A4GL_debug ("No entry");
      A4GL_debug ("ZZZZ - SET OPTS");
      field_opts_off (field, O_ACTIVE);
      field_opts_off (field, O_EDIT);
    }
  if (A4GL_has_bool_attribute (f, FA_B_REQUIRED))
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      field_opts_off (field, O_NULLOK);
    }
  else
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      field_opts_on (field, O_NULLOK);
    }

  if (A4GL_has_bool_attribute (f, FA_B_COMPRESS))
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      field_opts_on (field, O_WRAP);
    }

  //A4GL_set_field_colour_attr (field, f->do_reverse, f->colour); // MJA REMOVE COLOUR FROM X

}




void *
A4GL_LL_new_form (void *vfd)
{
struct s_form_dets *fd;
fd=vfd;

  return new_form ((FIELD **) fd->form_fields);
}

void
A4GL_LL_set_form_userptr (void *form, void *data)
{
  set_form_userptr (form, data);
}

void *
A4GL_LL_get_form_userptr (void *form)
{
  form_userptr (form);
}



char *
A4GL_LL_field_buffer (void *field, int n)
{
  return field_buffer (field, n);
}


void
A4GL_LL_set_field_buffer (void *field, int n, char *str)
{
A4GL_debug("LL_set_field_buffer : %s",str);
  set_field_buffer (field, n, str);
}



int
A4GL_LL_field_opts (void *field)
{
  return field_opts (field);
}


int
A4GL_LL_set_field_opts (void *field, int oopt)
{
  A4GL_debug ("SET FIELD OPTS : STATIC %x ", oopt & O_STATIC);
  set_field_opts (field, oopt);

}


void
A4GL_LL_set_field_fore (void *field, int attr)
{
  set_field_fore (field, attr);
}


void
A4GL_LL_set_field_back (void *field, int attr)
{
  set_field_back (field, attr);
}


void
A4GL_LL_set_current_field (void *form, void *field)
{
  set_current_field (form, field);
}


void
A4GL_LL_set_carat (void *form)
{
PANEL *w;
  pos_form_cursor (form);
  A4GL_debug("CURSES : set_carat");
  A4GL_LL_screen_update();
  w = (PANEL *) A4GL_get_currwin ();
  wrefresh(panel_window(w));
}


int
A4GL_LL_getch_swin (void *window_ptr)
{
  int a;
  if (A4GL_isgui ())
    {
      return A4GL_get_gui_char ();
    }
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
  A4GL_debug ("get CARAT : %d in %p", mform->curcol, current_field (mform));
  return mform->curcol;
}

int
A4GL_LL_int_form_driver (void *mform, int mode)
{
  form_driver (mform, mode);
}

void *
A4GL_LL_current_field (void *form)
{
  return current_field (form);
}

void
A4GL_LL_set_form_page (void *form, int page)
{
  set_form_page (form, page);
}

void
A4GL_LL_form_page (void *form)
{
  form_page (form);
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
  A4GL_debug ("p=%p", p);
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
  return field_status (field);
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
      scr_dump (ptr);
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
	  f = fopen (ptr, "w");
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
  set_field_status (f, stat);
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

  if (has_colors () == FALSE);
  else
    {
      start_color ();
      refresh ();
#ifndef __sun__
#ifndef __sparc__
      //curses function not available on Solaris (!!!!?????)
      use_default_colors ();
      have_default_colors = 1;

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
A4GL_LL_prompt_loop (void *vprompt, int timeout,struct aclfgl_event_list *evt)
{
  int a;
  void *p;
  int was_aborted = 0;
int rblock;

  void *mform;

  struct s_prompt *prompt;
  prompt = vprompt;

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
      unpost_form (prompt->f);
      A4GL_clear_prompt (prompt);
      return 0;
    }

  if (prompt->mode > 0)
    return 0;

      pos_form_cursor (mform);
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
      	A4GL_set_last_key ( A4GL_key_val ("INTERRUPT"));
	prompt_last_key 	= A4GL_key_val ("INTERRUPT");;
	prompt->lastkey		= A4GL_key_val ("INTERRUPT");;
	}

      A4GL_debug ("No lastkey..");
      rblock=A4GL_has_event_for_keypress(prompt->lastkey,evt);
      if (rblock) { // We appear to be all done here...
      		A4GL_push_null (DTYPE_CHAR, 1);
      		prompt->mode = 2;
      		unpost_form (prompt->f);
      		A4GL_clear_prompt (prompt);
		return rblock;
      }

    a = A4GL_proc_key_prompt (a, mform, prompt);
    if (was_aborted)
    abort_pressed = 1;


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
      A4GL_zrefresh ();
      wrefresh (p);
      A4GL_debug ("Return pressed");
      prompt->mode = 1;
      return 0;
    }

  A4GL_debug ("Requesting Validation : %p %x %d", mform, a, a);
  if (isprint (a) && a < 0xff)
    {
      A4GL_LL_int_form_driver (mform, a);
      A4GL_debug ("Called int_form_driver");
      A4GL_LL_int_form_driver (mform, AUBIT_REQ_VALIDATION);
    }



  wrefresh (p);

  if (prompt->charmode)
    {
      if (isprint (a) && a < 0xff)
	{
	  A4GL_push_char (A4GL_LL_field_buffer (prompt->field, 0));

	  prompt->mode = 2;
	}
    }


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
  p =
    derwin (panel_window (cw), 1, width, promptline - 1,
	    UILIB_A4GL_iscurrborder ());


  if (p == 0)
    {
      A4GL_exitwith ("No prompt window created");
      return 0;
    }
  prompt->win = p;
  buff[width] = 0;
  wprintw (p, "%s", buff);
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
  A4GL_debug ("Creating field %d %d %d", strlen (promptstr) + 1, 1,
	      width - 1);
  set_new_page (sarr[field_cnt - 1], 1);
  sarr[field_cnt++] =
    (void *) A4GL_LL_make_field (0,0, strlen (promptstr), 1, width + 1);
  prompt->field = sarr[field_cnt - 1];
  sarr[field_cnt++] = 0;	/* (void *) A4GL_make_label (0, strlen(promptstr)+width-1,"|"); */

  /* set_field_pad(sarr[1],' '); */
  A4GL_debug ("set field to =%p", prompt->field);
  A4GL_debug ("Field=%p", prompt->field);

  /* A4GL_default_attributes (sarr[0], 0); */

  A4GL_default_attributes (prompt->field, 0);
  A4GL_debug ("STATIC OFF");
  field_opts_off (prompt->field, O_STATIC);

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
	  field_opts_off (prompt->field, O_PUBLIC);
	}

    }

  field_opts_on (prompt->field, AUBIT_O_NULLOK);
  A4GL_debug ("Set attributes");

  buff[0] = 0;			/* -2 */
  A4GL_debug ("Setting Buffer %p to '%s'", prompt->field, buff);
  A4GL_LL_set_field_buffer (prompt->field, 0, buff);
  A4GL_debug ("Set buffer ");

  //sarr[2] = 0;

  A4GL_debug ("Made fields");

  f = new_form ((FIELD **) &sarr);
  A4GL_debug ("Form f = %p", f);
  prompt->f = f;
  A4GLSQL_set_status (0, 0);

  if (a4gl_status != 0)
    return (prompt->mode = 2);

  d = derwin (p, 0, 0, width + 1, 1);
  set_form_win (f, p);
  set_form_sub (f, d);
  A4GL_debug ("Set form win");
  a = post_form (f);
  A4GL_debug ("Posted form=%d", a);



  A4GL_LL_int_form_driver (f, AUBIT_REQ_FIRST_FIELD);
  A4GL_LL_int_form_driver (f, AUBIT_REQ_OVL_MODE);
  A4GLSQL_set_status (0, 0);
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
  delwin ((WINDOW *) p);
  A4GL_LL_screen_refresh ();
}


void
A4GL_LL_scale_form (struct s_form_dets *f, int *y, int *x)
{
  scale_form (f->form, y, x);
  A4GL_debug ("y=%d x=%x", y, x);
}

int
A4GL_LL_get_field_width (void *f)
{
  int x, y, a;
  dynamic_field_info (f, &y, &x, &a);
  return x * y;
}


A4GL_LL_set_max_field (void *f, int n)
{
  set_max_field (f, n);
}


static void
A4GL_debug_print_field_opts (FIELD * a)
{
  long z;
  char str[8048] = "";
  z = field_opts (a);
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

A4GLHLUI_initlib() {
	
}


// Not available in TUI mode...
int
 A4GL_LL_endis_fields_ap (int en_dis, va_list * ap)
{
return 0;
}

