#include "a4gl_libaubit4gl.h"
#include "a4gl_lib_ui_int.h"
#include "a4gl_API_ui_lib.h"
#include "a4gl_API_lowlevel.h"
#include "formdriver.h"
#include "hl_proto.h"

static char *module_id="$Id: generic_ui.c,v 1.19 2004-05-19 15:10:03 mikeaubury Exp $";
//#include "generic_ui.h"


static int A4GL_find_shown (ACL_Menu * menu, int chk, int dir);
static void A4GL_menu_attrib (ACL_Menu * menu, int attr, va_list * ap);
static void A4GL_move_bar (ACL_Menu * menu, int a);
static int started = -1;
int
A4GL_find_attrib_from_metric (struct_form * f, int metric_no);
int
A4GL_find_fields_no_metric (struct_form * f, int metric_no);
int
A4GL_find_attrib_from_field (struct_form * f, int field_no);
int UILIB_A4GLUI_initlib (void);
int A4GL_conversion_ok(int);

#define COLOR_BLACK     0
#define COLOR_RED       1
#define COLOR_GREEN     2
#define COLOR_YELLOW    3
#define COLOR_BLUE      4
#define COLOR_MAGENTA   5
#define COLOR_CYAN      6
#define COLOR_WHITE     7

#define POS_FIRST               1
#define POS_VERY_FIRST  2
#define POS_VERY_LAST   4
#define POS_LAST                8

void *curr_error_window;


void A4GL_size_menu (ACL_Menu * menu);

char *
A4GL_string_width (char *s)
{
  char buff[10];
  int a;
  static char buff2[10024];

  a = UILIB_A4GL_get_curr_width () - 2;
  A4GL_debug ("String width=%d", a);
  sprintf (buff, "%%-%d.%ds", a, a);
  A4GL_debug ("Buff=%s - s=%s", buff, s);
  sprintf (buff2, buff, s);
  A4GL_debug ("A4GL_string_width returns Buff2=%s", buff2);
  return buff2;
}

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

int
A4GL_new_do_keys (ACL_Menu * menu, int a)
{
  ACL_Menu_Opts *opt1;
  int fc;

  //if (A4GL_is_special_key(a,A4GLKEY_LEFT)) a = A4GLKEY_LEFT;
  //if (A4GL_is_special_key(a,A4GLKEY_RIGHT)) a = A4GLKEY_RIGHT;
  //if (A4GL_is_special_key(a,A4GLKEY_UP)) a = A4GLKEY_UP;
  //if (A4GL_is_special_key(a,A4GLKEY_DOWN)) a = A4GLKEY_DOWN;
  //if (A4GL_is_special_key(a,A4GLKEY_LEFT)) a = A4GLKEY_LEFT;
  //if (A4GL_is_special_key(a,A4GLKEY_ENTER)) a = 13;


  opt1 = (ACL_Menu_Opts *) menu->curr_option;
  A4GL_debug ("new_do_keys A=%d", a);

  fc = A4GL_find_char (menu, a);

  if (fc)
    return 1;



  if (a == 8 || a == ' ' || a == A4GLKEY_DOWN || a == A4GLKEY_RIGHT || a == A4GLKEY_UP || a == A4GLKEY_LEFT || a == 0xffff /* click */ )	// BACKSPACE ?
    {
      A4GL_move_bar (menu, a);
      if (a == 0xffff)
	return 1;
      return 0;
    }

  if (a == 27)
    {
      A4GL_debug ("Escape!");
      abort_pressed = 1;
      return 0;
    }

  if (a == 13 || a==A4GLKEY_ENTER )
    {
      A4GL_debug ("CR..");
      return 1;
    }
  A4GL_debug ("Dropped through");
  A4GL_LL_beep();
  return fc;
}

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



static void
A4GL_move_bar (ACL_Menu * menu, int a)
{
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *opt2;
  int flg;
  int dir = 0;
  int opage, npage;
  void *z;
  if (menu->gw_x < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }

  opt1 = (ACL_Menu_Opts *) menu->curr_option;
  opage = opt1->page;
  flg = 0;
  opt2 = opt1;

  A4GL_debug ("In movebar curropt=%p", menu->curr_option);


  if (a == 0xffff)
    {
      A4GL_debug ("Decoding new option");
      z = (void *) A4GL_decode_clicked ();
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

      if (a == A4GLKEY_UP || a == A4GLKEY_LEFT || a == 8)
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

      if (a == ' ' || a == A4GLKEY_DOWN || a == A4GLKEY_RIGHT)
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
  if (menu->gw_x < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }

  if (npage != opage)
    {
      A4GL_debug ("Page Changed on menu");
      menu->curr_page = npage;
      if (menu->gw_x < 0)
	{
	  char *ptr = 0;
	  *ptr = 0;
	}
      A4GL_display_menu (menu);
      if (menu->gw_x < 0)
	{
	  char *ptr = 0;
	  *ptr = 0;
	}
    }
  A4GL_gui_setfocus ((int) menu->curr_option);
  return;
}

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


void
UILIB_A4GL_next_option (void *vmenu, char *nextopt)
{
  int a;
  int f = 0;
  ACL_Menu_Opts *option;
  ACL_Menu_Opts *old_option;
  char s[256];
  ACL_Menu *menu;
  menu = vmenu;
  A4GL_h_disp_opt (menu, menu->curr_option, menu->menu_offset,
		   menu->mn_offset, NORM);
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
  if (menu->gw_x < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }
  A4GL_gui_setfocus ((int) menu->curr_option);

  A4GL_display_menu (menu);
  if (menu->gw_x < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }
}


int
UILIB_A4GL_menu_hide_ap (void *menuv, va_list * ap)
{
  ACL_Menu *menu;
  menu = menuv;
  A4GL_debug ("Menu hide\n");
  A4GL_menu_attrib (menu, 0, ap);
  return 1;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_menu_show_ap (void *menuv, va_list * ap)
{
  ACL_Menu *menu;
  menu = menuv;
  A4GL_debug ("Show");
  A4GL_menu_attrib (menu, 1, ap);
  A4GL_find_shown (menu, 0, 1);
  return 1;
}


static void
A4GL_menu_attrib (ACL_Menu * menu, int attr, va_list * ap)
{
  int a;
  ACL_Menu_Opts *option;
  char *argp;
  char s[256];
  int flg;
  A4GL_debug ("Menu attrib %d\n", attr);
  while ((argp = va_arg (*ap, char *)))
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
		  A4GL_debug ("Attemp to turn on %d %d %d",
			      option->attributes, ACL_MN_HIDE,
			      option->attributes & ACL_MN_HIDE);
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
  A4GL_size_menu (menu);	/* MJA 10/5/2000 */
  /*
     A4GL_clr_menu_disp (menu);
     A4GL_debug ("f3");
   */
  if (menu->gw_x < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }
  A4GL_display_menu (menu);
  if (menu->gw_x < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }
  A4GL_debug ("f4");

  va_end (*ap);

}

static int
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


void
A4GL_size_menu (ACL_Menu * menu)
{
  ACL_Menu_Opts *opt1;
  int disp_cnt2 = 0;
  char disp_str[80];
  int disp_cnt;
  int s_length;
  int page = 0;
  int xxx;

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

	  A4GL_debug ("AAAA %d", disp_cnt2);
	  A4GL_debug ("AAAA %d", menu->menu_offset);
	  A4GL_debug ("AAAA %d", s_length);
	  A4GL_debug ("AAAA %d", menu->w);


	  xxx = disp_cnt2;
	  xxx += menu->menu_offset;
	  xxx += s_length;

	  if (xxx > menu->w)
	    {
	      page++;
	      disp_cnt2 = 5;
	    }
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



void *
UILIB_A4GL_new_menu_create (char *title, int x, int y, int mn_type,
			    int help_no)
{
  char buff[256];
  ACL_Menu *menu;
  A4GL_chkwin ();
  strcpy (buff, title);
  A4GL_trim (buff);
  menu = malloc (sizeof (ACL_Menu) + 0);
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
  return (void *) menu;
}

void
UILIB_A4GL_add_menu_option (void *menuv, char *txt, char *keys, char *desc,
			    int helpno, int attr)
{
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *opt2;
  ACL_Menu *menu;
  char op1[256];
  int nopts;
  menu = menuv;
  opt1 = malloc (sizeof (ACL_Menu_Opts));
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

void
UILIB_A4GL_finish_create_menu (void *menuv)
{
  ACL_Menu *menu;
  menu = menuv;
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


ACL_Menu *
A4GL_new_menu (char *title,
	       int x, int y, int mn_type, int help_no, int nopts,
	       va_list * ap)
{
  int ret;
  char *argp_c;
  char op1[256];
  char buff[256];
  int argp_i;
  ACL_Menu *menu;
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *opt2;

  A4GL_chkwin ();
  if (nopts < 1)
    return 0;
  strcpy (buff, title);
  A4GL_trim (buff);
  A4GL_debug (" Menu title : '%s'", title);
  menu = malloc (sizeof (ACL_Menu) + 100);
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
  opt1 = malloc (sizeof (ACL_Menu_Opts));
  menu->first = (ACL_Menu_Opts *) opt1;
  opt1->prev_option = 0;
  A4GL_debug ("Menu=%p &Menu=%p", menu, &menu);
  A4GL_gui_startmenu (title, (long) menu);
  for (ret = 0; ret < nopts; ret++)
    {
      if (ret != 0)
	{
	  opt2 = malloc (sizeof (ACL_Menu_Opts));
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



int
A4GL_decode_colour_attr_aubit (int a)
{
  char colour[20];
  char attr[256];
//int col;
  A4GL_debug ("MJA Decoding %d", a);
  A4GL_get_strings_from_attr (a, colour, attr);

  A4GL_debug ("MJA Got colour as : %s - %s", colour, attr);
  A4GL_trim (colour);

  if (strlen (colour) == 0)
    return A4GL_LL_colour_code (COLOR_WHITE);
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
    return A4GL_LL_colour_code (COLOR_WHITE);

  

  return 0;
}


void
UILIB_A4GLUI_ui_init (int argc, char *argv[])
{
  A4GL_set_scrmode ('L');
  started = 1;
}


int UILIB_A4GLUI_initlib (void)
{
  return 1;
}



void
UILIB_A4GL_gotolinemode ()
{
  A4GL_LL_switch_to_line_mode ();
  A4GL_set_scrmode ('L');
}



void
UILIB_A4GL_sleep_i (void)
{
  int a;
  a = A4GL_pop_int ();
  A4GL_LL_sleep (a);
}



int
UILIB_A4GL_menu_loop_v2 (void *menuv,void *evt)
{
  return A4GL_highlevel_menu_loop (menuv);
  
}




#ifdef MOVED_TO_WIDTH
void
A4GL_wprintw (void *win, int attr, int x, int y, char *fmt, ...)
{
  va_list args;
  int a;
  unsigned char buff[2048];
  A4GL_chkwin ();
  va_start (args, fmt);
  vsprintf (buff, fmt, args);


//A4GL_debug("win=%p attr=%p x=%d y=%d fmt=%s",win,attr,x,y,fmt);
//A4GL_debug("wprintw passed : %s",buff);


  for (a = 0; a < strlen (buff); a++)
    {
      A4GL_LL_wadd_char_xy_col (win, x, y, buff[a] + attr);
      x++;
/*
      if (x >= UILIB_A4GL_get_curr_width ())
	{
	  x = 0;
	  y++;
	}
      if (y > UILIB_A4GL_get_curr_height ())
	{
	  break;
	}
*/
    }
}
#endif






/**
 *
 * @todo Describe function
 *  @todo Validate the calls to A4GL_make_label that alocates space to a FIELD
 *  struct and assigns the pointer to integers.
 */
int
UILIB_A4GL_read_metrics (void *formdetsv)
{
  struct s_form_dets *formdets;
  struct struct_scr_field *fprop;
  int a, n;
  int last_field = -1;
  int cnt = 0;
  int lscr = 1;
  int lfieldscr = -1;
  char delims[3][2];
  int attr_no;

  formdets = formdetsv;
  delims[0][0] = formdets->fileform->delim[0];
  delims[1][0] = formdets->fileform->delim[1];
  delims[2][0] = formdets->fileform->delim[2];
  delims[0][1] = 0;
  delims[1][1] = 0;
  delims[2][1] = 0;
  n = formdets->fileform->metrics.metrics_len;
  A4GL_debug ("metrics len=%d", n);
  for (a = 0; a < n; a++)
    {


      formdets->fileform->metrics.metrics_val[a].pos_code = 0;
      A4GL_debug ("checking label %s\n",
		  formdets->fileform->metrics.metrics_val[a].label);


      if (strlen (formdets->fileform->metrics.metrics_val[a].label) != 0)
	{


	  formdets->fileform->metrics.metrics_val[a].field =
	    (int) A4GL_LL_make_label (formdets->fileform->metrics.
				      metrics_val[a].y,
				      formdets->fileform->metrics.
				      metrics_val[a].x,
				      formdets->fileform->metrics.
				      metrics_val[a].label);
	  formdets->form_fields[cnt++] = (void *)
	    formdets->fileform->metrics.metrics_val[a].field;
	  formdets->form_fields[cnt] = 0;
	}
      else
	{
	  A4GL_debug ("Making field");

	  attr_no=A4GL_find_attrib_from_metric (formdets->fileform, a);
	  fprop=&formdets->fileform->attributes.attributes_val[attr_no];
	  A4GL_debug("attr_no=%d fprop=%p",attr_no,fprop);


	  formdets->fileform->metrics.metrics_val[a].field =
	    (int) A4GL_LL_make_field (fprop,formdets->fileform->metrics.metrics_val[a].y,
				      formdets->fileform->metrics.metrics_val[a].x,
				      formdets->fileform->metrics.metrics_val[a].h,
				      formdets->fileform->metrics.metrics_val[a].w);
	  A4GL_debug ("Making field 2");


	  formdets->form_fields[cnt++] =
	    (void *) formdets->fileform->metrics.metrics_val[a].field;
	  formdets->form_fields[cnt] = 0;


	  formdets->fileform->metrics.metrics_val[a].dlm1 =
	    (int) A4GL_LL_make_label (formdets->fileform->metrics.
				      metrics_val[a].y,
				      formdets->fileform->metrics.
				      metrics_val[a].x - 1, delims[0]);
	  A4GL_debug ("Making field 3");
	if ( formdets->fileform->metrics.metrics_val[a].dlm1) 
	  formdets->form_fields[cnt++] = (void *) formdets->fileform->metrics.metrics_val[a].dlm1;


	  formdets->fileform->metrics.metrics_val[a].dlm2 =
	    (int) A4GL_LL_make_label (formdets->fileform->metrics.
				      metrics_val[a].y,
				      formdets->fileform->metrics.
				      metrics_val[a].x +
				      formdets->fileform->metrics.
				      metrics_val[a].w, delims[1]);
	  A4GL_debug ("Making field 4");

	if ( formdets->fileform->metrics.metrics_val[a].dlm1) formdets->form_fields[cnt++] = (void *) formdets->fileform->metrics.metrics_val[a].dlm2;

	  A4GL_debug ("Making field 5");

	  formdets->form_fields[cnt] = 0;
	  A4GL_debug ("Made field : %p",
		      formdets->fileform->metrics.metrics_val[a].field);
	}


      if (lscr != formdets->fileform->metrics.metrics_val[a].scr)
	{
	  lscr = formdets->fileform->metrics.metrics_val[a].scr;
	  A4GL_LL_set_new_page ((void *) formdets->fileform->metrics.
				metrics_val[a].field, 1);
	}



      if (strlen (formdets->fileform->metrics.metrics_val[a].label) == 0)
	{
	  if (last_field == -1)
	    {
	      formdets->fileform->metrics.metrics_val[a].pos_code +=
		POS_VERY_FIRST;
	    }
	}

      if (lfieldscr != formdets->fileform->metrics.metrics_val[a].scr
	  && strlen (formdets->fileform->metrics.metrics_val[a].label) == 0)
	{

	  formdets->fileform->metrics.metrics_val[a].pos_code += POS_FIRST;

	  if (last_field != -1)
	    {
	      formdets->fileform->metrics.metrics_val[last_field].pos_code +=
		POS_LAST;
	    }
	  lfieldscr = formdets->fileform->metrics.metrics_val[a].scr;
	}
      A4GL_debug ("LAST_FIELD3 -CHK111 a=%d label='%s'", a,
		  formdets->fileform->metrics.metrics_val[a].label);
      if (strlen (formdets->fileform->metrics.metrics_val[a].label) == 0)
	last_field = a;
    }

  A4GL_debug ("Last_field=%d\n", last_field);
  if (last_field < 0)
    {
      A4GL_exitwith ("Internal Error");
      return 0;
    }

  formdets->fileform->metrics.metrics_val[last_field].pos_code +=
    POS_VERY_LAST;

  return 1;
}



int
UILIB_A4GL_read_fields (void *formdetsv)
{
  struct s_form_dets *formdets;
  int a, n;
  int n1, a1;
  int metric_no;
  char *ptr;
  formdets = formdetsv;
  A4GL_chkwin ();
  n = formdets->fileform->fields.fields_len;
  A4GL_debug ("Got %d fields\n", n);

  formdets->fields_cnt = n;

  for (a = 0; a < n; a++)
    {
      ptr = A4GL_find_attribute (formdets, a);
      n1 = formdets->fileform->fields.fields_val[a].metric.metric_len;

      for (a1 = 0; a1 < n1; a1++)
	{
	  metric_no =
	    formdets->fileform->fields.fields_val[a].metric.metric_val[a1];
	  A4GL_debug ("Metric number read as %d\n", metric_no);

	  if (formdets->fileform->metrics.metrics_val[metric_no].field != 0)
	    {
	      A4GL_debug ("Has an associated field");
	      if (ptr != 0)
		{
		  A4GL_debug ("Has associated attribute!");
		  A4GL_LL_set_field_userptr ((void *) formdets->fileform->
					     metrics.metrics_val[metric_no].
					     field, ptr);
		  A4GL_LL_set_field_attr ((void *) formdets->fileform->
					  metrics.metrics_val[metric_no].
					  field);
		  A4GL_debug ("Done\n");
		}
	    }
	}
    }
  A4GL_debug ("formdets->form_fields=%p", formdets->form_fields);
  formdets->form = A4GL_LL_new_form ((void *)formdets);
  if (formdets->form == 0)
    {
      A4GL_exitwith ("Failed to create the loaded the form");
      return 0;
    }
  A4GL_LL_set_form_userptr (formdets->form, formdets);
  A4GL_debug ("Loaded form...");
  return 1;
}




int
UILIB_A4GL_disp_fields_ap (int n, int attr, va_list * ap)
{
  int a;
  int flg;
  struct s_form_dets *formdets;
  void **field_list;
  int nofields;
  struct struct_scr_field *fprop;
  a4gl_status = 0;

  A4GL_chkwin ();
  A4GL_debug ("In disp_fields");
  formdets = (struct s_form_dets *)UILIB_A4GL_get_curr_form (1);
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
  A4GL_LL_screen_update ();
  return 1;
}

void
A4GL_set_field_pop_attr (void *field, int attr, int cmd_type)
{
  struct struct_scr_field *f;
  struct s_form_dets *fff;
  int a;
  //int field_width;
  long oopt;
  int d1;
  int s1;
  void *ptr1;


  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);


  f = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (field));

  if (A4GL_has_bool_attribute (f, FA_B_REVERSE))
    a = 1;
  else
    a = 0;

  A4GL_debug ("f->do_reverse=%d attr=%x", a, attr);

  A4GL_display_field_contents (field, d1, s1, ptr1);

  A4GL_debug ("set f->do_reverse to %d ", f->do_reverse);
  oopt = A4GL_LL_field_opts (field);
  A4GL_LL_set_field_attr (field);
  A4GL_debug ("Determining attribute - field_buffer=%s",
	      A4GL_LL_field_buffer (field, 0));
  attr =
    A4GL_determine_attribute (cmd_type, attr, f,
			      A4GL_LL_field_buffer (field, 0));

  if (attr != 0)
    {
      A4GL_debug ("calling set_field_attr_with_attr : %x", attr);
      A4GL_set_field_attr_with_attr (field, attr, cmd_type);
    }


  A4GL_debug ("set field attr");
  fff = (struct s_form_dets *)UILIB_A4GL_get_curr_form (1);
  A4GL_debug ("set field");
  A4GL_debug ("set field buffer setting do_reverse=%d", a);

  f->do_reverse = a;
  A4GL_debug ("done ");
  A4GL_LL_set_field_opts (field, oopt);
  A4GL_debug ("ZZZZ - SET OPTS");
  A4GL_debug ("Calling display_field_contents");




}



int
A4GL_gen_field_list (void ***field_list, struct s_form_dets *formdets,
		     int a, va_list * ap)
{
  int z;
  int z1;
  int ff;
  int fno;
  int metric_no;
  int mno;
  char colname[40];
  char tabname[40];
  void *flist[1024];
  char *s;
  int f;
  struct struct_metrics *k;
  int attr_no;
  int srec_no;
  int cnt = 0;
  if (formdets==0) return 0;
#ifdef DEBUG
  {
    A4GL_debug ("gen_field_list - %p %p %d %p", field_list, formdets, a, ap);
  }
#endif
  A4GL_debug ("field_list=%p", field_list);
  A4GL_debug ("Here 2");
  /*
     *field_list = calloc (a, sizeof (FIELD *));
     *field_list = calloc (1024, sizeof (FIELD *));

     A4GL_dump_srec (&formdets);
   */

  for (z1 = 0; z1 <= a; z1++)
    {
      A4GL_debug ("Getting first %d", z1);
      s = va_arg (*ap, char *);	/* This is suspect.... */

      if (s == 0)
	break;

      A4GL_debug ("Got first %s", s);

      f = (int) va_arg (*ap, int *);
      A4GL_debug ("f=%d\n", f);
      if (f > 0)
	f--;

      A4GL_debug (" got field number as %d ", f);


      ff = 0;

      /* get screen record/table name */

      A4GL_bname (s, tabname, colname);
      srec_no = A4GL_find_srec (formdets->fileform, tabname);

      if (strlen (tabname) && strlen (colname) && srec_no == -1)
	{
	  A4GL_exitwith ("Table/Screen record does not exist in form");
	  return -1;
	}



      A4GL_debug ("srec_no=%d", srec_no);
      if (srec_no != -1)
	{
	  for (z = 0;
	       z <
	       formdets->fileform->records.records_val[srec_no].attribs.
	       attribs_len; z++)
	    {
	      A4GL_debug ("srec_no=%d", srec_no);
	      attr_no =
		formdets->fileform->records.records_val[srec_no].attribs.
		attribs_val[z];
	      A4GL_debug ("attr_no=%d", attr_no);
#ifdef DEBUG
	      {
		A4GL_debug ("Attr 1");
	      }
#endif
	      A4GL_debug ("attr_no=%d s=%s\n", attr_no, s);
	      mno =
		A4GL_attr_name_match (&formdets->fileform->attributes.
				      attributes_val[attr_no], s);
	      A4GL_debug ("mno=%d\n", mno);

	      if (mno)
		{
		  fno =
		    formdets->fileform->attributes.attributes_val[attr_no].
		    field_no;
		  A4GL_debug ("Matched to field no %d", fno);
		  if (fno >= formdets->fileform->fields.fields_len)
		    {
		      A4GL_exitwith ("Dubious form\n");
		      return -1;	// Was 0
		    }
		  metric_no =
		    formdets->fileform->fields.fields_val[fno].metric.
		    metric_val[f];
		  A4GL_debug ("fno=%d f=%d mno=%d metric_no=%d\n", fno, f,
			      mno, metric_no);
		  k = &formdets->fileform->metrics.metrics_val[metric_no];
#ifdef DEBUG
		  {
		    A4GL_debug ("cnt=%d a=%d", cnt, a);
		  }
#endif

		  if (cnt >= a)
		    {
		      A4GL_debug ("cnt=%d a=%d", cnt, a);
		      A4GL_exitwith
			("Too few variables for the number of fields");
		      return -1;
		    }
		  A4GL_debug ("Setting flist[%d] to %p", cnt, k);
		  flist[cnt++] = (void *) k->field;
		  A4GL_debug ("Set");
		  ff = 1;
		}

	    }
	}
      else
	{
	  for (z = 0; z < formdets->fileform->attributes.attributes_len; z++)
	    {
	      attr_no = z;
	      A4GL_debug ("attr_no=%d", attr_no);
#ifdef DEBUG
	      {
		A4GL_debug ("Attr 2");
	      }
#endif
	      mno =
		A4GL_attr_name_match (&formdets->fileform->attributes.
				      attributes_val[attr_no], s);
	      if (mno)
		{
		  fno =
		    formdets->fileform->attributes.attributes_val[attr_no].
		    field_no;
		  A4GL_debug ("Matched to field no %d - len=%d f=%d", fno,
			      formdets->fileform->fields.fields_val[fno].
			      metric.metric_len, f);
		  if (formdets->fileform->fields.fields_val[fno].metric.
		      metric_len <= f || f < 0)
		    {
		      A4GL_exitwith ("Field subscript out of bounds");
		      return -1;
		    }
		  metric_no =
		    formdets->fileform->fields.fields_val[fno].metric.
		    metric_val[f];
		  k = &formdets->fileform->metrics.metrics_val[metric_no];
#ifdef DEBUG
		  {
		    A4GL_debug ("cnt=%d a=%d", cnt, a);
		  }
#endif
		  if (cnt >= a)	/* was >= */
		    {
		      A4GL_debug ("cnt=%d a=%d", cnt, a);
		      A4GL_debug ("Too few variables");
		      A4GL_exitwith
			("Too few variables for the number of fields");
		      return -1;
		    }
		  A4GL_debug ("Setting flist[%d] to %p", cnt, k);
		  flist[cnt++] = (void *) k->field;
		  A4GL_debug ("aa");
		  ff = 1;
		}
	      A4GL_debug ("aa");
	    }
	  A4GL_debug ("aa");

	}
      A4GL_debug ("aa");
      if (ff == 0)
	{
	  A4GL_exitwith ("Field name not found");
	  return -1;
	}

    }
/*
  s = va_arg (*ap, char *);
  if (s != 0)
    A4GL_debug ("Trailing fields ignored");
*/


  *field_list = calloc (cnt + 1, sizeof (void *));
  memcpy (*field_list, flist, sizeof (void *) * (cnt + 1));
  return cnt - 1;
}


int
A4GL_get_field_width (void *field)
{
  return A4GL_LL_get_field_width (field);
}


void
A4GL_display_field_contents (void *field, int d1, int s1, char *ptr1)
{
  int field_width;
  int has_format;
  int ignore_formatting = 0;
  struct struct_scr_field *f;
  char *ff;


//printf("display_field_contents");


  A4GL_debug ("In display_field_contents");
  f = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (field));
  ff = A4GL_new_string (A4GL_get_field_width (field));

  field_width = A4GL_get_field_width (field);
  has_format = A4GL_has_str_attribute (f, FA_S_FORMAT);
  A4GL_debug ("Has format : %d  ", has_format);

// 'Format' is valid for a lot of datatypes -
// but not all...
// If we are passing **IN** a character string
// for example - we'll omit the formatting...

  switch (d1 & DTYPE_MASK)
    {
    case DTYPE_CHAR:
    case DTYPE_BYTE:
    case DTYPE_TEXT:
    case DTYPE_VCHAR:
      ignore_formatting = 1;
    }

  if (has_format && ignore_formatting)
    {
      A4GL_debug ("Which I'm going to ignore..");
    }

  if (has_format && !ignore_formatting)
    {
      A4GL_debug ("Has specified format..");
      if (strlen (A4GL_get_str_attribute (f, FA_S_FORMAT)) > field_width)
	{
	  A4GL_exitwith ("Format is wider than the field");
	  return;
	}

// I think these 2 can be removed...
      //A4GL_pop_char (ff, field_width );
      //A4GL_push_char (ff);
      A4GL_push_char (A4GL_get_str_attribute (f, FA_S_FORMAT));
      A4GL_pushop (OP_USING);
      //A4GL_debug_print_stack();
    }
  if (!has_format && !ignore_formatting)
    {
      A4GL_debug ("Has no format.. d1=%d", d1 & DTYPE_MASK);
      if (A4GL_has_datatype_function_i (d1 & DTYPE_MASK, "DISPLAY"))
	{
	  char *ptr;
	  char *(*function) (void *, int, int, struct struct_scr_field *,
			     int);
	  A4GL_debug ("check for specific display routine");
	  function =
	    A4GL_get_datatype_function_i (d1 & DTYPE_MASK, "DISPLAY");
	  if (function)
	    {
	      A4GL_debug
		("Has a function - calling XXXX - size=%d decode_size=%d", s1,
		 DECODE_SIZE (d1));
	      ptr =
		function (ptr1, s1, field_width, f, DISPLAY_TYPE_DISPLAY_TO);
	      A4GL_debug ("Returns %p\n", ptr);
	    }
	  else
	    {
	      ptr = 0;
	    }
	  if (ptr != 0)
	    {
	      A4GL_debug ("Here.. %s", ptr);
	      A4GL_drop_param ();
	      A4GL_debug ("Dropped - pushing mine..");
	      A4GL_push_char (ptr);
	    }
	}

    }

  A4GL_pop_char (ff, field_width);
  A4GL_debug ("set_field_contents : '%s'", ff);
  A4GL_mja_set_field_buffer (field, 0, ff);
  free (ff);

}


void
A4GL_error_nobox (char *str, int attr)
{
  int eline;
  void *w;

  A4GL_chkwin ();
  if (curr_error_window)
    {
      A4GL_clr_error_nobox ("A4GL_error_nobox");
    }

  eline = A4GL_geterror_line () - 1;
  A4GL_debug ("Eline=%d\n", eline);


  w =
    A4GL_LL_create_errorwindow (1, A4GL_LL_screen_width () - 1, eline, 0,
				attr, str);

  curr_error_window = w;
  A4GL_LL_screen_update ();
}



void
A4GL_clr_error_nobox (char *dbg_fromwhere)
{
  //int a;
  A4GL_chkwin ();
  A4GL_debug ("MJA clr_error_nobox called from %s", dbg_fromwhere);

  if (curr_error_window)
    {

      A4GL_LL_delete_errorwindow (curr_error_window);
      curr_error_window = 0;
      A4GL_LL_screen_update ();
      return;
    }

  return;
}



int
A4GL_curr_metric_is_used_last_s_screenio (struct s_screenio *s, void *f)
{
  int a;
  int fno = -1;
  int last_usable = -1;
  struct struct_scr_field *fprop;

  for (a = 0; a <= s->nfields; a++)
    {
      A4GL_debug ("MMM a=%d Current field=%p field_list=%p", a, f,
		  s->field_list[a]);
      if (f == s->field_list[a])
	fno = a;

      fprop =
	(struct struct_scr_field
	 *) (A4GL_LL_get_field_userptr (s->field_list[a]));

      if (!A4GL_has_bool_attribute (fprop, FA_B_NOENTRY)
	  || (fprop->datatype == DTYPE_SERIAL && s->mode != MODE_CONSTRUCT))
	{
	  A4GL_debug ("Field is not noentry");
	  last_usable = a;
	}
      else
	{
	  A4GL_debug ("MMM Field is noentry");
	}
    }

  A4GL_debug ("MMM curr_metric_is_used_last_s_screenio fno=%d nfields=%d",
	      fno, s->nfields);

  if (fno == last_usable)
    {
      A4GL_debug ("MMM Is last");
      return 1;
    }

  A4GL_debug ("MMM Not last");
  return 0;
}



int
A4GL_form_field_chk (struct s_screenio *sio, int m)
{
  char buff[8000] = "";
  char buff2[8000] = "";
  char buff3[8000] = "";
  void *mform;
  int pprval;
  //int x, y;
  //int flg = 0;
  struct s_form_dets *form;
  struct struct_scr_field *fprop;

  mform = sio->currform->form;
  A4GL_debug ("CHeck fields 1 m=%d", m);
  form = sio->currform;
  //A4GL_debug ("CHeck fields 2 currentfield=%p status = %d", form->currentfield, field_status (form->currentfield));

  fprop = 0;
  if (m > 0)
    {
      A4GL_debug ("CHeck fields 3");
      form->currentfield = 0;
      form->currentmetrics = 0;
      A4GL_debug (" m ");
      return 0;
    }


  if ((form->currentfield != A4GL_LL_current_field (mform)) || m < 0)
    {
      /*
         A4GL_debug ("Setting focus");
         A4GL_gui_setfocus (A4GL_LL_current_field (mform));
       */
      A4GL_debug ("Is different");
      fprop = 0;

      if (form->currentfield != 0)
	if (A4GL_LL_get_field_userptr (form->currentfield) != 0)
	  {
	    A4GL_debug ("Is a proper field");
	    fprop =
	      (struct struct_scr_field
	       *) (A4GL_LL_get_field_userptr (form->currentfield));
	    A4GL_debug ("fprop=%p", fprop);
	    if (fprop != 0)
	      {

		//int d1,s1;
		//char *ptr1;

		if ((fprop->datatype & DTYPE_MASK) != DTYPE_CHAR)
		  {



		    A4GL_modify_size (&buff[4],
				      form->fileform->metrics.
				      metrics_val[A4GL_get_metric_for
						  (form,
						   form->currentfield)].w);

		    strcpy (&buff[4],
			    A4GL_LL_field_buffer (form->currentfield, 0));

		    strcpy (buff2, &buff[4]);

		    if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
		      {
			int a;
			int blank = 1;
			char *picture;
			picture =
			  A4GL_get_str_attribute (fprop, FA_S_PICTURE);
			A4GL_debug ("HAS PICTURE MJA123 : %s", buff2);
			for (a = 0; a < strlen (buff2); a++)
			  {
			    if (picture[a] == 'X' && buff2[a] != ' ')
			      {
				blank = 0;
				break;
			      }
			    if (picture[a] == 'A' && buff2[a] != ' ')
			      {
				blank = 0;
				break;
			      }
			    if (picture[a] == '#' && buff2[a] != ' ')
			      {
				blank = 0;
				break;
			      }
			  }
			if (blank)
			  strcpy (buff2, "");
		      }


		    A4GL_trim (buff2);
		    //getsyx (y, x);
		    A4GL_trim (buff2);
		    if (strlen (buff2) == 0)
		      {

			if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED))
			  {
			    int allow_it_anyway = 0;

			    // We'll still allow it - so long as there is null in the include list
			    if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			      {
				if (A4GL_check_field_for_include
				    ("",
				     A4GL_get_str_attribute (fprop,
							     FA_S_INCLUDE),
				     fprop->datatype))
				  {
				    allow_it_anyway = 1;
				  }
			      }

			    if (!allow_it_anyway)
			      {
				// Well there wasn't - so it is required....
				A4GL_error_nobox (acl_getenv
						  ("FIELD_REQD_MSG"), 0);
				A4GL_LL_set_current_field (mform,
							   form->
							   currentfield);
				return -4;
			      }


			  }

			// Could still be thrown out if we have an include without a null in it....
			A4GL_debug ("X2222 MAYBE");
			if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			  {
			    if (A4GL_check_field_for_include
				("",
				 A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
				 fprop->datatype))
			      {
				return 1;
			      }
			    else
			      {
				A4GL_debug
				  ("X2222 Check for include has null...");
				A4GL_error_nobox (acl_getenv
						  ("FIELD_INCL_MSG"), 0);
				return -4;
			      }
			  }


			return 0;
		      }


		    A4GL_debug ("Pushing to validate : %s\n", buff2);

		    pprval =
		      A4GL_check_and_copy_field_to_data_area (form, fprop,
							      buff2, buff);

/*
                    A4GL_push_param (buff2, DTYPE_CHAR);
                    pprval=A4GL_pop_param (buff, fprop->datatype, A4GL_get_field_width (form->currentfield));
                    if (pprval) {
                                A4GL_debug("Looks like pprval is ok ... ");


                                if (A4GL_isnull(fprop->datatype,buff)) {
                                        A4GL_debug("But I got a null back - strlen = %d fprop->datatype=%x %d",strlen(buff2),fprop->datatype,DTYPE_DTIME);
                                        if (strlen(buff2)) {
                                                pprval=0;
                                        }
                                }
                                if (!A4GL_conversion_ok(-1)) { pprval=0; }


                                if ( (fprop->datatype==DTYPE_INT|| fprop->datatype==DTYPE_SMINT|| fprop->datatype==DTYPE_SERIAL) && strchr(buff2,'.') ) {
                                                A4GL_debug("Looks like a decimal in a numeric field");
                                                pprval=0;
                                }
                        }

*/



		    A4GL_debug ("pprval = %d\n", pprval);
		    if (!pprval)
		      {
			A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);

			if (A4GL_isyes
			    (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
			  {
			    A4GL_clr_field (form->currentfield);
			  }
			else
			  {
			    if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
			      {
				A4GL_LL_int_form_driver (mform,
							 AUBIT_REQ_BEG_FIELD);
			      }

			  }


			A4GL_LL_set_current_field (mform, form->currentfield);
			return -4;
		      }
		    else
		      {
			A4GL_debug ("pop_param returns ok...");
		      }
		  }


		strcpy (buff3,
			A4GL_LL_field_buffer (sio->currform->currentfield,
					      0));

		if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
		  {
		    int a;
		    int blank = 1;
		    char *picture;
		    picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
		    for (a = 0; a < strlen (buff3); a++)
		      {
			if (picture[a] == 'X' && buff3[a] != ' ')
			  {
			    blank = 0;
			    break;
			  }
			if (picture[a] == 'A' && buff3[a] != ' ')
			  {
			    blank = 0;
			    break;
			  }
			if (picture[a] == '#' && buff3[a] != ' ')
			  {
			    blank = 0;
			    break;
			  }
		      }
		    if (blank)
		      strcpy (buff3, "");
		  }


		if (A4GL_check_field_for_include
		    (buff3, A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
		     fprop->datatype) == 0)
		  {
		    A4GL_debug ("Not in include list");
		    A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
		    A4GL_LL_set_current_field (mform, form->currentfield);
		    return -4;
		  }


		if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED))
		  {
		    char buff[8024];
		    strcpy (buff,
			    A4GL_LL_field_buffer (sio->currform->currentfield,
						  0));
		    A4GL_trim (buff);
		    //

		    if (strlen (buff) == 0)
		      {
			int allow_it_anyway = 0;

			// We'll still allow it - so long as there is null in the include list
			if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			  {
			    if (A4GL_check_field_for_include
				("",
				 A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
				 fprop->datatype))
			      {
				allow_it_anyway = 1;
			      }
			  }
			if (!allow_it_anyway)
			  {
			    A4GL_error_nobox (acl_getenv ("FIELD_REQD_MSG"),
					      0);
			    A4GL_LL_set_current_field (mform,
						       form->currentfield);
			    return -4;
			  }

		      }
		  }

		// Could still be thrown out if we have an include without a null in it....
		if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
		  {
		    if (A4GL_check_field_for_include
			("", A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
			 fprop->datatype))
		      {
			return 1;
		      }
		    else
		      {
			return 0;
		      }
		  }




		return 0;





	      }
	  }
    }


  return 0;
}




int
A4GL_form_field_constr (struct s_screenio *sio, int m)
{
  char buff[8000];
  char buff2[8000];
  void *mform;

//int x, y;
  int flg = 0;
  struct s_form_dets *form;
  struct struct_scr_field *fprop;
  mform = sio->currform->form;
  form = sio->currform;

  if (m)
    {
      form->currentfield = 0;
      form->currentmetrics = 0;
      return 0;
    }


  if (form->currentfield != A4GL_LL_current_field (mform))
    {
      /* fprop = 0; */
      if (form->currentfield != 0
	  && (A4GL_LL_get_field_userptr (form->currentfield) != 0))
	{
	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_LL_get_field_userptr (form->currentfield));
	  if (fprop != 0)
	    {
	      if ((fprop->datatype != (DTYPE_CHAR & DTYPE_MASK))
		  && (A4GL_LL_field_status (form->currentfield)))
		{
		  strcpy (buff, A4GL_LL_field_buffer (form->currentfield, 0));
		  strcpy (buff2, buff);
		  A4GL_debug ("CHeckit here");
		  //getsyx (y, x);
		}
	    }
	}
    }

  if (form->currentfield != A4GL_LL_current_field (mform))
    {
      fprop =
	(struct struct_scr_field
	 *) (A4GL_LL_get_field_userptr (A4GL_LL_current_field (mform)));
      A4GL_debug ("Moving to %s", fprop->colname);
      if (fprop != 0)
	{
	  A4GL_push_long ((long) A4GL_LL_current_field (mform));
	  A4GL_push_char (fprop->colname);
	}
      else
	{
	  A4GL_push_long (0);
	  A4GL_push_char ("THIS FIELD IS AT THE START");
	}

      fprop =
	(struct struct_scr_field
	 *) (A4GL_LL_get_field_userptr (form->currentfield));
      if (fprop != 0)
	{
	  if (fprop->colname != 0)
	    {
	      A4GL_debug ("Moving from %s", fprop->colname);
	    }
	  else
	    {
	      A4GL_debug ("Blank colname");
	    }
	}
      if (fprop != 0)
	{
	  A4GL_do_after_field (form->currentfield, sio);
	  A4GL_push_long ((long) form->currentfield);
	  A4GL_push_char (fprop->colname);
	}
      else
	{
	  A4GL_push_long (0);
	  A4GL_push_char ("THIS FIELD IS AT THE START");
	}
      flg = -1;
    }
  A4GL_debug ("Setting currentfield entry on form...");
  form->currentfield = A4GL_LL_current_field (mform);


  fprop =
    (struct struct_scr_field
     *) (A4GL_LL_get_field_userptr (form->currentfield));
  if (fprop != 0)
    A4GL_comments (fprop);

  A4GL_LL_set_carat (mform);

  return flg;
}


int
A4GL_get_metric_no (struct s_form_dets *form, void *f)
{
  int a;
  A4GL_debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (f == (void *) form->fileform->metrics.metrics_val[a].field)
	{
	  A4GL_debug ("Returning %d\n", a);
	  return a;
	}
    }
  A4GL_debug ("NO current metric !");
  return -1;
}




int
A4GL_get_metric_for (struct s_form_dets *form, void *f)
{
  int a;

  A4GL_debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (f == (void *) form->fileform->metrics.metrics_val[a].field)
	{
	  A4GL_debug ("Returning %d\n", a);
	  return a;
	}
    }
  A4GL_debug ("NO current metric !");
  return -1;
}




char *
A4GL_fld_data_ignore_format (struct struct_scr_field *fprop, char *fld_data)
{
  char *ptr;
  ptr = A4GL_get_str_attribute (fprop, FA_S_FORMAT);
  A4GL_debug ("FLD_DATA_IGNORE_FORMAT : %s\n", fld_data);
  if (ptr)
    {
      // It could the that there are some literals or other characters
      // in fld_data that we need to take out first...
      //
      A4GL_debug ("Has format");
      if (fprop->datatype == DTYPE_SMINT || fprop->datatype == DTYPE_INT
	  || fprop->datatype == DTYPE_DECIMAL
	  || fprop->datatype == DTYPE_MONEY || fprop->datatype == DTYPE_FLOAT
	  || fprop->datatype == DTYPE_SMFLOAT)
	{
	  static char buff_new[256];
	  int a;
	  int c = 0;
	  memset (buff_new, 0, 255);
	  for (a = 0; a < strlen (fld_data); a++)
	    {
	      if (fld_data[a] == '$' || fld_data[a] == ','
		  || fld_data[a] == '£')
		continue;
	      buff_new[c++] = fld_data[a];
	    }
	  fld_data = buff_new;
	  A4GL_debug ("COPY -> %s instead", fld_data);
	}

    }
  A4GL_debug ("Returning : %s", fld_data);
  return fld_data;
}



int
A4GL_check_and_copy_field_to_data_area (struct s_form_dets *form,
					struct struct_scr_field *fprop,
					char *fld_data, char *data_area)
{
  int pprval;

  fld_data = A4GL_fld_data_ignore_format (fprop, fld_data);
  A4GL_debug ("Got fld_data as : %s", fld_data);


  A4GL_push_param (fld_data, DTYPE_CHAR);
  pprval = A4GL_pop_param (data_area, fprop->datatype, fprop->dtype_size);

  //A4GL_get_field_width (form->currentfield));

  if (pprval)
    {
      if (A4GL_isnull (fprop->datatype, data_area))
	{
	  A4GL_debug
	    ("But I got a null back - strlen = %d fprop->datatype=%x %d",
	     strlen (fld_data), fprop->datatype, DTYPE_DTIME);
	  if (strlen (fld_data))
	    {
	      pprval = 0;
	    }
	}

      if (!A4GL_conversion_ok (-1))
	{
	  pprval = 0;
	}

      if ((fprop->datatype == DTYPE_INT || fprop->datatype == DTYPE_SMINT
	   || fprop->datatype == DTYPE_SERIAL) && strchr (fld_data, '.'))
	{
	  A4GL_debug ("Looks like a decimal in a numeric field");
	  pprval = 0;
	}
    }

  return pprval;

}


void
A4GL_clr_field (void *f)
{
  char *picture;
  char *str;
  int w;
  struct struct_scr_field *fprop;
  fprop = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (f));

  w = A4GL_get_field_width (f);
  str = malloc (w + 1);
  memset (str, ' ', w);
  str[w] = 0;

  A4GL_debug ("field width=%d", A4GL_get_field_width (f));

  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
    {
      int a;
      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
      for (a = 0; a < strlen (picture); a++)
	{
	  if (a > w)
	    break;
	  if (picture[a] == 'X')
	    {
	      str[a] = ' ';
	      continue;
	    }
	  if (picture[a] == 'A')
	    {
	      str[a] = ' ';
	      continue;
	    }
	  if (picture[a] == '#')
	    {
	      str[a] = ' ';
	      continue;
	    }
	  str[a] = picture[a];
	}
    }
  A4GL_mja_set_field_buffer (f, 0, str);
}


int
A4GL_do_after_field (void *f, struct s_screenio *sio)
{
  int a;
  char *ptr;
  struct struct_scr_field *fprop;
  void *mform;


  a = A4GL_find_field_no (f, sio);

  if (a == -1)
    {
      A4GL_exitwith ("after field : field number not found!");
      return 0;
      //A4GL_bomb_out ();
    }

  if (sio->mode != MODE_CONSTRUCT)
    {
#ifdef DEBUG
      {
	A4GL_debug ("   Field buffer = %s", A4GL_LL_field_buffer (f, 0));
      }
#endif
  fprop = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (f));
      A4GL_push_char ( A4GL_fld_data_ignore_format(fprop, A4GL_LL_field_buffer (f, 0)));
#ifdef DEBUG
      {
	A4GL_debug ("   Ptr=%p dtype=%d size=%d", sio->vars[a].ptr,
		    sio->vars[a].dtype, sio->vars[a].size);
      }
#endif

      /* now check that the form corresponds to the includes */
      if (sio->currform->currentfield)
	{
	  A4GL_debug ("Got current field %p\n", sio->currform->currentfield);
	  mform = sio->currform->form;
	  fprop = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (f));

	  A4GL_debug ("Got form %p", sio->currform->form);
	  if (A4GL_check_field_for_include
	      (A4GL_LL_field_buffer (sio->currform->currentfield, 0),
	       A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
	       fprop->datatype) == 0)
	    {
	      A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
	      A4GL_LL_set_current_field (mform, sio->currform->currentfield);
	    }
	}

      A4GL_pop_var2 (sio->vars[a].ptr, sio->vars[a].dtype, sio->vars[a].size);

    }
  else
    {
      fprop = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (f));
      if (fprop != 0)
	{
	  if (fprop->colname != 0)
	    {
	      A4GL_debug ("Calling constr with : '%s' '%s'",
			  sio->constr[a].tabname, sio->constr[a].colname);


	      ptr =
		(char *) A4GL_construct (sio->constr[a].tabname,
					 sio->constr[a].colname,
					 A4GL_LL_field_buffer (f, 0),
					 (fprop->datatype == 0)
					 || (fprop->datatype == 8));
	      A4GL_debug ("ptr=%s", ptr);
	      if (ptr == 0) {
		A4GL_error_nobox (acl_getenv ("FIELD_CONSTR_EXPR"), 0);
		return 0;
		}
	    }
	}
    }
	return 1;
}


int
A4GL_find_field_no (void *f, struct s_screenio *sio)
{
  int a;
#ifdef DEBUG
  {
    A4GL_debug ("Finding field %p", f);
  }
#endif
  for (a = 0; a <= sio->nfields; a++)
    {
#ifdef DEBUG
      {
	A4GL_debug ("Checking against %p", sio->field_list[a]);
      }
#endif

      if (sio->field_list[a] == f)
	return a;

    }
#ifdef DEBUG
  {
    A4GL_debug ("Its not there!");
  }
#endif
  return -1;
}


int UILIB_A4GL_prompt_loop_v2 (void *vprompt, int timeout,void *evt) {
	return A4GL_LL_prompt_loop(vprompt,timeout,evt);
}

int UILIB_A4GL_start_prompt (void *vprompt, int ap, int c, int h, int af) {
	return A4GL_LL_start_prompt(vprompt,ap,c,h,af);
}

int UILIB_A4GL_get_key(int timeout) {
	return A4GL_LL_getch_swin ((void *)A4GL_window_on_top ());
}



void UILIB_A4GL_acli_scroll_ap(int n,va_list *ap) {
struct s_form_dets *f;
int a;
int srec_no;
char barr[256];
char *ptr;
void ***buff;
int b;
int attr;
void *field;
int fno;
int mno;
int dim;
int nfields;
int dir;
char *arr;
arr=va_arg(*ap,char *);

if (n<0) {
	dir=-1;
	n=0-n;
} else {
	dir=1;
}
	

if (n>1) {
        int cnt;
        for (cnt=0;cnt<n;cnt++) {
             A4GL_acli_scroll(dir,arr,0,0,0);
        }
        return;
}


f=(struct s_form_dets *)UILIB_A4GL_get_curr_form (1);
strcpy(barr,arr);

ptr=strchr(barr,'.');

if (ptr==0) {
        A4GL_exitwith("Internal error - expected a .* in screen record");
        return;
}

*ptr=0;

A4GL_debug("barr=%s",barr);
srec_no=A4GL_find_srec(f->fileform,barr);

if (srec_no==-1) {
        A4GL_exitwith("Unknown screen record");
        return;
}

A4GL_debug("srec_no=%d nrows=%d attribs=%d",srec_no,
f->fileform->records.records_val[srec_no].dim,
f->fileform->records.records_val[srec_no].attribs.attribs_len);
buff=malloc(sizeof(char *) * f->fileform->records.records_val[srec_no].dim);


for (a=0;a<f->fileform->records.records_val[srec_no].dim;a++) {
        buff[a]=malloc(sizeof(char *) * f->fileform->records.records_val[srec_no].attribs.attribs_len);
}

dim=f->fileform->records.records_val[srec_no].dim;
nfields=f->fileform->records.records_val[srec_no].attribs.attribs_len;
for (b=0;b<nfields;b++) {
        for (a=0;a<dim;a++) {
                attr=f->fileform->records.records_val[srec_no].attribs.attribs_val[b];
                fno = f->fileform->attributes.attributes_val[attr].field_no;
                mno=f->fileform->fields.fields_val[fno].metric.metric_val[a];
                field=(void *)f->fileform->metrics.metrics_val[mno].field;
                A4GL_debug("SCROLL %s [ %d] . %d = %p (%s)",barr,a,b,field,A4GL_LL_field_buffer(field,0));
                buff[a][b]=field;
        }
}

if (dir==-1) {
        for (a=dim-1;a>0;a--) {
                for (b=0;b<nfields;b++) {
                        A4GL_debug("field[%d][%d] = buffer[%d][%d]",a,b,a-1,b);
                        ptr=A4GL_LL_field_buffer(buff[a-1][b],0);
                        A4GL_debug("              = %s",ptr);
                        A4GL_LL_set_field_buffer(buff[a][b],0,ptr);
                }
        }
        for (b=0;b<nfields;b++) {
                        A4GL_LL_set_field_buffer(buff[0][b],0,"");
        }
}

if (dir==1) {
        for (a=0;a<dim-1;a++) {
                for (b=0;b<nfields;b++) {
                        A4GL_debug("field[%d][%d] = buffer[%d][%d]",a,b,a+1,b);
                        ptr=A4GL_LL_field_buffer(buff[a+1][b],0);
                        A4GL_debug("              = %s",ptr);
                        A4GL_LL_set_field_buffer(buff[a][b],0,ptr);
                }
        }
        for (b=0;b<nfields;b++) {
                        A4GL_LL_set_field_buffer(buff[dim-1][b],0,"");
        }
}






}
int
A4GL_find_attrib_from_metric (struct_form * f, int metric_no)
{
  return A4GL_find_attrib_from_field (f, A4GL_find_fields_no_metric (f, metric_no));
}

/**
 * Find fields
 *
 * @param f A pointer to a form describing strucutre.
 * @param metric_no The metric sequence number.
 * @return The metric number.
 */
int
A4GL_find_fields_no_metric (struct_form * f, int metric_no)
{
  int a, b;
  A4GL_debug ("BB\n");
  for (a = 0; a < f->fields.fields_len; a++)
    {
      for (b = 0; b < f->fields.fields_val[a].metric.metric_len; b++)
        {
          if (f->fields.fields_val[a].metric.metric_val[b] == metric_no)
            {
              return a;
            }
        }
    }

  return 0;
}


int
A4GL_find_attrib_from_field (struct_form * f, int field_no)
{
  int a;
  A4GL_debug ("AA\n");
  A4GL_debug ("field_no=%d\n", field_no);

  for (a = 0; a < f->attributes.attributes_len; a++)
    {
      A4GL_debug ("   a=%d\n", a);
      if (f->attributes.attributes_val[a].field_no == field_no)
        {
          A4GL_debug ("Found field %d @ %d\n", field_no, a);
          return a;
        }
    }
  A4GL_debug ("Not found\n");
  return -1;

}




void
UILIB_A4GL_display_internal (int x, int y, char *s, int a, int clr_line)
{
  int nattr;
  void *wot;
  A4GL_debug ("display_internal : %d %d %s %d %d", x, y, s, a, clr_line);
  A4GL_debug ("determine_attribute seems to be returning %x\n", a);

  if (x == -1 && y == -1)
    {
      A4GL_debug ("Line mode display");
      if (A4GL_isscrmode ())
	{
	  A4GL_LL_switch_to_line_mode ();
	}
      A4GL_LL_out_linemode (s);
    }
  else
    {
      int b;
      A4GL_chkwin ();
      nattr = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, a, 0, 0);
      a = nattr;

      wot = (void *) A4GL_window_on_top_ign_menu ();
      A4GL_wprintw(wot,a,x,y,"%s",s);

      if (clr_line)
	{
	  int sl;
	  char buff[1024];
	  memset (buff, ' ', 1024);
	  A4GL_debug("strlen=%d",strlen(s));
	  sl = strlen (s);
	  sl = A4GL_get_curr_width () - sl;
	  A4GL_debug("sl=%d spaces required",sl);
	  if (sl >= 0) {
	    	buff[sl] = 0;
	  	buff[1023] = 0;
		A4GL_wprintw(wot,x,y,(a&0xffffff00),buff);
		}
	}
  A4GL_LL_screen_update ();
    }
A4GL_debug("DOne display");
}


 void UILIB_A4GL_reset_state_for(void *sio, char *siotype) {

       if (strcmp(siotype,"s_inp_arr")==0) {
               static void* last_sio=0;
               struct s_inp_arr *s;
               s=sio;
               if (last_sio!=sio) {
                       // May need to do a full redraw..
                       last_sio=sio;
                       if (sio) A4GL_idraw_arr_all(s);
               }
               if (s) {
                       A4GL_set_arr_curr (s->arr_line);
                               A4GL_set_scr_line (s->scr_line);
               }

       }

       if (strcmp(siotype, "s_screenio")==0) {
       }

 }

