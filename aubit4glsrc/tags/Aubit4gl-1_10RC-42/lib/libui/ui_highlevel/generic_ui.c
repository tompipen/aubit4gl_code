#include "a4gl_libaubit4gl.h"
#include "a4gl_lib_ui_int.h"
#include "hl_proto.h"
#include "a4gl_API_ui_lib.h"
#include "a4gl_API_lowlevel.h"
#include "formdriver.h"
#include "input_array.h"
#include "formcntrl.h"

#ifndef lint
static char const module_id[] =
  "$Id: generic_ui.c,v 1.146 2008-11-17 10:03:21 mikeaubury Exp $";
#endif

static int A4GL_ll_field_opts_i (void *f);
static int A4GL_prompt_loop_v2_int (void *vprompt, int timeout, void *evt);
int A4GL_field_is_noentry (int doing_construct, struct struct_scr_field *f);
static int A4GL_find_shown (ACL_Menu * menu, int chk, int dir);
static void A4GL_menu_attrib (ACL_Menu * menu, int attr, va_list * ap);
static void A4GL_move_bar (ACL_Menu * menu, int a);
int A4GL_gen_field_list_from_slist_internal (void ***field_list,
					     struct s_form_dets *formdets,
					     int a,
					     struct s_field_name_list *list);
void A4GL_debug_print_field_opts (void *a);
//int A4GL_has_event_for_keypress (int a, struct aclfgl_event_list *evt);
//int UILIB_A4GL_gen_field_list_from_slist (void *field_listv, void *formdetsv, void *listv);


void A4GL_debug_print_opts (long z);
//void *A4GL_get_currwin (void);
static int started = -1;
int A4GL_find_attrib_from_metric (struct_form * f, int metric_no);
int A4GL_find_fields_no_metric (struct_form * f, int metric_no);
int A4GL_find_attrib_from_field (struct_form * f, int field_no);

//void A4GL_LL_ui_exit (void);
int field_status_strip_tabname=0;
static char *set_current_display_delims=0;


int aclfgl_a4gl_show_help (int n);
//int UILIB_A4GLUI_initlib (void);
int A4GL_UI_int_get_inc_quotes (int a);
//int A4GL_conversion_ok(int);

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

void *curr_error_window = 0;


void A4GL_size_menu (ACL_Menu * menu);

static char *
A4GL_decode_str_fprop (struct_scr_field * fprop, int type)
{
  int b;
  if (fprop == 0)
    return 0;
  if (fprop->str_attribs.str_attribs_val == 0)
    return 0;
  for (b = 0; b < fprop->str_attribs.str_attribs_len; b++)
    {
      if (fprop->str_attribs.str_attribs_val[b].type == type)
	{
	  return fprop->str_attribs.str_attribs_val[b].value;
	}
    }
  return "";
}

char *
A4GL_string_width (char *s)
{
  char buff[20];
  int a;
  static char buff2[10024];

  a = UILIB_A4GL_get_curr_width () - 2;
  A4GL_debug ("String width=%d", a);
  SPRINTF2 (buff, "%%-%d.%ds", a, a);
  A4GL_debug ("Buff=%s - s=%s", buff, s);
  SPRINTF1 (buff2, buff, s);
  A4GL_debug ("A4GL_string_width returns Buff2=%s", buff2);
  return buff2;
}

void
A4GL_strip_nl (char *str)
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
  menu->curr_option = (ACL_Menu_Opts *) menu->first;
  for (a = 0; a < opt; a++)
    {
      menu->curr_option =
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

  if (a == 13 || a == A4GLKEY_ENTER)
    {
      A4GL_debug ("CR..");
      return 1;
    }
  A4GL_debug ("Dropped through");
  A4GL_LL_beep ();
  return fc;
}

int
A4GL_find_char (ACL_Menu * menu, int key)
{
  ACL_Menu_Opts *opt1, *opt2;
  int flg = 0;
  opt2 = (ACL_Menu_Opts *) menu->curr_option;

  A4GL_debug ("ZZ : key = %d opt2->optkey=%s\n", key, opt2->optkey);

  if (!opt2->attributes & ACL_MN_HIDE)
    {
      if (strcmp (opt2->optkey, "EMPTY") != 0)
	{
	  A4GL_debug ("defined keys only");
	  flg = A4GL_check_keys (key, opt2->optkey);
	}
      else
	{
	  A4GL_debug ("default key only");
          if (A4GL_is_unique_menu_key (menu, key)==1)
            {

	  flg = A4GL_check_key (key, &opt2->opt_title[1], 1);
		}
	}
    }
  else
    {
      if (strlen (opt2->opt_title) == 0)
	{
	  flg = A4GL_check_keys (key, opt2->optkey);
	}
    }

  if (flg)
    {
      menu->curr_option = (ACL_Menu_Opts *) opt2;
      A4GL_debug ("We're on it!");
      return 1;
    }
  if (A4GL_is_unique_menu_key (menu, key) > 1)
    {
      void *p;
      p = A4GL_LL_show_menu_large (menu, key);
      if (p)
	{
	  menu->curr_option = p;
	  return 1;
	}
      return 0;
    }
  else
    {


      A4GL_debug ("Checking next option...");
      opt1 = (ACL_Menu_Opts *) opt2->next_option;

      if (opt1 == 0)
	opt1 = (ACL_Menu_Opts *) menu->first;

      while (opt2 != opt1)
	{
	  A4GL_debug ("ZZ2 : key = %d opt1->optkey=%s\n", key, opt1->optkey);
	  flg = 0;

	  if (!opt1->attributes & ACL_MN_HIDE)
	    {
	      if (strcmp (opt1->optkey, "EMPTY") != 0)
		{
		  A4GL_debug ("defined keys only");
		  flg = A4GL_check_keys (key, opt1->optkey);
		}
	      else
		{
		  A4GL_debug ("default key only");
		  flg = A4GL_check_key (key, &opt1->opt_title[1], 1);
		}
	    }
	  else
	    {
	      if (strlen (opt1->opt_title) == 0)
		{
		  flg = A4GL_check_keys (key, opt1->optkey);
		}
	    }

	  if (flg)
	    {
	      menu->curr_option = (ACL_Menu_Opts *) opt1;
	      return 1;
	    }
	  opt1 = (ACL_Menu_Opts *) opt1->next_option;
	  if (opt1 == 0)
	    opt1 = (ACL_Menu_Opts *) menu->first;
	}
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
  //A4GL_gui_setfocus ((int) menu->curr_option);
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
  SPRINTF4 (b, "S=%s F=%s a=%d c=%s", filespec, filename, a, c);
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
  int matches = 0;
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

      if (A4GL_menu_opts_compare (s, nextopt, MENU_COMPARE_NEXT_OPTION) == 0)
	{
	  f = 1;
	  matches++;
	  menu->curr_option = option;
	  menu->curr_page = option->page;
	  break;
	}
      option = (ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
    }

  if (f == 0)
    {
      option = old_option;
      A4GL_debug ("Menu Option %s not found", nextopt);
    }

  A4GL_assertion (menu->gw_x < 0, "gw_x out of range");

  if (matches == 0)
    {
      A4GL_exitwith ("The NEXT OPTION name is not in the menu");
    }
  A4GL_display_menu (menu);
  A4GL_assertion (menu->gw_x < 0, "Corruption in menu->gw_x");
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
      int matches = 0;
      A4GL_trim (argp);
      A4GL_debug ("change attrib to %d of %s", attr, argp);
      option = (ACL_Menu_Opts *) menu->first;
      for (a = 0; a < menu->num_opts; a++)
	{
	  A4GL_debug ("before copy");
	  if (option->opt_title && strlen(option->opt_title)) {
	  	strcpy (s, &option->opt_title[1]);
	  }  else {
	  		option = (ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
			continue;
		}


	  A4GL_debug ("after copy '%s' '%s'", s, option->opt_title);
	  A4GL_trim (s);
	  A4GL_debug ("trim %s", s);
	  flg = 0;

	  if (strcmp (argp, MENU_ALL) != 0)
	    {
	      A4GL_debug ("Cmp '%s' to '%s'", s, argp);
	      if (A4GL_menu_opts_compare (s, argp, MENU_COMPARE_SHOWHIDE) ==
		  0)
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
	      matches++;
	      A4GL_debug ("   FOund it : %s , %s (%x) %d", s, argp,
			  option->attributes & ACL_MN_HIDE, attr);
	      if (attr)
		{
		  A4GL_debug ("Attemp to turn on %d %d %d",
			      option->attributes, ACL_MN_HIDE,
			      option->attributes & ACL_MN_HIDE);
		  if ((option->attributes & ACL_MN_HIDE)
		      && (option->optlength))
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
	  option = (ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
	  A4GL_debug ("set next");
	}

      if (matches == 0)
	{
	  // Informix doesn't seem to mind - so we'll need a switch
	  // to force an error...
	  if (A4GL_env_option_set ("ERRBADOPTION"))
	    {
	      A4GL_exitwith ("Menu option not found");
	    }
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
      A4GL_debug
	("gw_x is less than zero!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
      //char *ptr = 0;
      //*ptr = 0;
    }

  A4GL_display_menu (menu);
  if (menu->gw_x < 0)
    {
      A4GL_debug
	("gw_x is less than zero!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
      //char *ptr = 0;
      //*ptr = 0;
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
	      menu->curr_option = (ACL_Menu_Opts *) menu->first;
	    }
	}
      else
	{
	  menu->curr_option =
	    (ACL_Menu_Opts *) (menu->curr_option)->prev_option;
	  if (menu->curr_option == 0)
	    {
	      menu->curr_option = (ACL_Menu_Opts *) menu->last;
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
	      //A4GL_gui_setfocus ((int) menu->curr_option);
	      A4GL_debug ("Return!");
	      return 1;
	    }
	}
      A4GL_debug ("A5c");
    }
  A4GL_debug ("A7");


  //A4GL_gui_setfocus ((int) menu->curr_option);
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
  int s_off;
  int something_else_printable = 0;
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
	  SPRINTF1 (disp_str, "%s : ", menu->menu_title);
	  disp_cnt = strlen (disp_str) + 1;
	}
      else
	SPRINTF1 (disp_str, " %s ", menu->menu_title);
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

	  something_else_printable = 0;
	  s_off = 0;

	  if (disp_cnt2 + menu->menu_offset + s_length + 5 > menu->w)
	    {
	      ACL_Menu_Opts *po;
	      po = (ACL_Menu_Opts *) opt1->next_option;
	      while (po != 0)
		{
		  if ((po->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
		    {
		      something_else_printable = 1;
		      break;
		    }
		  po = (ACL_Menu_Opts *) po->next_option;
		}
	      if (something_else_printable)
		s_off = 5;
	    }



	  if (xxx + s_off > menu->w)
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
UILIB_A4GL_new_menu_create_with_attr (char *title, int x, int y, int mn_type,
			    int help_no, char *mn_comment, char*mn_style, char *mn_image)
{
  char buff[256];
  ACL_Menu *menu;
  A4GL_chkwin ();
  strcpy (buff, title);
  A4GL_trim (buff);
  menu = acl_malloc2 (sizeof (ACL_Menu) + 0);
  strcpy (menu->menu_title, buff);
  A4GL_trim (menu->menu_title);
  menu->menu_type = mn_type;
  menu->help_no = help_no;
  menu->curr_option = 0;
  strcpy (menu->parent_window_name, UILIB_A4GL_get_currwin_name ());
  //menu->window_name[0] = 0;
  menu->w = 0;
  menu->gw_x = 0;
  menu->gw_y = 0;
  menu->x = x;
  menu->y = y;
  menu->curr_page = 0;
  menu->menu_offset = 0;
  menu->mn_offset = 0;
  menu->first = 0;
  menu->num_opts = 0;
  menu->evt = 0;
  menu->nevt = 0;
  menu->mnstyle=strdup(mn_style);
  menu->mncomment=strdup(mn_comment);
  menu->mnimage=strdup(mn_image);
  //A4GL_gui_startmenu (title, (long) menu);
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
  opt1 = acl_malloc2 (sizeof (ACL_Menu_Opts));
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
      if (strlen (op1) > 77)
	op1[77] = 0;

      strcat (opt1->opt_title, op1);
      strcat (opt1->opt_title, " ");
    }
  else
    {
      strcpy (opt1->opt_title, "");
    }

  A4GL_debug ("MJAMJA helpno=%d", helpno);
  opt1->page = 1;
  opt1->optlength = strlen (opt1->opt_title);
  A4GL_debug ("MJAMJA helpno=%d", helpno);
  strcpy (opt1->optkey, keys);
  A4GL_debug ("MJAMJA helpno=%d", helpno);
  strncpy (opt1->shorthelp, desc, 80);

  opt1->shorthelp[79] = 0;
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



  if (menu->curr_option)
    {
      if (menu->curr_option->attributes & ACL_MN_HIDE)
	{
	  menu->curr_option = (ACL_Menu_Opts *) menu->first;
	}
    }
  else
    {
      menu->curr_option = (ACL_Menu_Opts *) menu->first;
    }

  while (menu->curr_option->attributes & ACL_MN_HIDE)
    {
      if (menu->curr_option == menu->last)
	break;
      menu->curr_option = (ACL_Menu_Opts *) menu->curr_option->next_option;
    }
  if (menu->evt)
    {
      A4GL_clr_evt_timeouts (menu->evt);
    }
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
  menu = acl_malloc2 (sizeof (ACL_Menu) + 100);
  strcpy (menu->menu_title, buff);
  A4GL_trim (menu->menu_title);


  menu->menu_type = mn_type;
  menu->help_no = help_no;
  menu->curr_option = 0;
  //menu->window_name[0] = 0;
  menu->w = 0;
  menu->x = x;
  menu->y = y;

  menu->gw_x = 0;
  menu->gw_y = 0;

  menu->curr_page = 0;
  menu->mn_offset = 0;
  opt1 = acl_malloc2 (sizeof (ACL_Menu_Opts));
  menu->first = (ACL_Menu_Opts *) opt1;
  opt1->prev_option = 0;
  A4GL_debug ("Menu=%p &Menu=%p", menu, &menu);
  //A4GL_gui_startmenu (title, (long) menu);
  for (ret = 0; ret < nopts; ret++)
    {
      if (ret != 0)
	{
	  opt2 = acl_malloc2 (sizeof (ACL_Menu_Opts));
	  opt2->prev_option = (ACL_Menu_Opts *) opt1;
	  opt1->next_option = (ACL_Menu_Opts *) opt2;
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
	  //A4GL_gui_menuopt (argp_c, (int) opt1);
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

  menu->curr_option = (ACL_Menu_Opts *) menu->first;
  while (menu->curr_option->attributes & ACL_MN_HIDE)
    {
      if (menu->curr_option == menu->last)
	break;
      menu->curr_option = (ACL_Menu_Opts *) menu->curr_option->next_option;
    }


  menu->num_opts = nopts;
  return menu;
}







int
UILIB_A4GLUI_ui_init (int argc, char *argv[])
{
  A4GL_set_scrmode ('L');
  started = 1;
return 1;
}


int
UILIB_UI_initlib (void)
{
  A4GL_set_scrmode ('L');
  started = 1;
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
UILIB_A4GL_menu_loop_v2 (void *menuv, void *evt)
{
  return A4GL_highlevel_menu_loop (menuv);

}






static char *
make_tab_and_col (char *t, char *c)
{
  static char buff[256];
  SPRINTF2 (buff, "%s.%s", t, c);
  return buff;
}

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
  struct struct_scr_field *fprop = 0;
  int n;
  int metric_no;
  int last_field = -1;
  int cnt = 0;
  int lscr = 1;
  int lfieldscr = -1;
  char delims[3][2];
  char *widget;
  char *config;
  char *include;
  char *action;
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


  for (metric_no = 0; metric_no < n; metric_no++)
    {
      widget = 0;
      config = 0;
      include = 0;

      formdets->fileform->metrics.metrics_val[metric_no].pos_code = 0;




      A4GL_debug ("checking label '%s' (%d)\n",
		  formdets->fileform->metrics.metrics_val[metric_no].label,
		  metric_no);


      if (strlen (formdets->fileform->metrics.metrics_val[metric_no].label) !=
	  0)
	{
	  A4GL_debug ("Its just a label");

	  formdets->fileform->metrics.metrics_val[metric_no].field =
	    (long) A4GL_LL_make_label (formdets->fileform->metrics.
				       metrics_val[metric_no].y,
				       formdets->fileform->metrics.
				       metrics_val[metric_no].x,
				       formdets->fileform->metrics.
				       metrics_val[metric_no].label);
	  formdets->form_fields[cnt++] = (void *)
	    formdets->fileform->metrics.metrics_val[metric_no].field;
A4GL_assertion(cnt>=MAX_FORM_FIELDS,"Ran out of form_fields...");

	  formdets->form_fields[cnt] = 0;
	}
      else
	{
	  A4GL_debug ("Making field : %d", metric_no);

	  attr_no =
	    A4GL_find_attrib_from_metric (formdets->fileform, metric_no);
	  if (attr_no == -1)
	    continue;
	  if (attr_no >= 0)
	    {
	      fprop = &formdets->fileform->attributes.attributes_val[attr_no];
	      A4GL_debug ("attr_no=%d fprop=%p", attr_no, fprop);

	      widget = A4GL_decode_str_fprop (fprop, FA_S_WIDGET);
	      config = A4GL_decode_str_fprop (fprop, FA_S_CONFIG);
	      include = 0;
	      if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
		{
		  include = A4GL_get_str_attribute (fprop, FA_S_INCLUDE);
		}
	      else
		{
		  include = 0;
		}
	      action = 0;
	      if (A4GL_has_str_attribute (fprop, FA_S_ACTION))
		{
		  action = A4GL_get_str_attribute (fprop, FA_S_ACTION);
		}
	      else
		{
		  action = 0;
		}
	    }
	  else
	    {
	      widget = 0;
	      config = 0;
	      include = 0;
	      action = 0;
	    }

	  if (widget == 0)
	    widget = "";
	  if (config == 0)
	    config = "";
	  if (include == 0)
	    include = "";
	  if (action == 0)
	    action = "";


	  formdets->fileform->metrics.metrics_val[metric_no].field =
	    (long) A4GL_LL_make_field (formdets->fileform->metrics.
				       metrics_val[metric_no].y,
				       formdets->fileform->metrics.
				       metrics_val[metric_no].x,
				       formdets->fileform->metrics.
				       metrics_val[metric_no].h,
				       formdets->fileform->metrics.
				       metrics_val[metric_no].w, widget,
				       config, include, fprop,
				       make_tab_and_col (fprop->tabname,
							 fprop->colname),
				       action);

	  A4GL_debug ("Making field 2");


	  formdets->form_fields[cnt++] =
	    (void *) formdets->fileform->metrics.metrics_val[metric_no].field;
A4GL_assertion(cnt>=MAX_FORM_FIELDS,"Ran out of form_fields...");

	  formdets->form_fields[cnt] = 0;


	  formdets->fileform->metrics.metrics_val[metric_no].dlm1 =
	    (long) A4GL_LL_make_label (formdets->fileform->metrics.
				      metrics_val[metric_no].y,
				      formdets->fileform->metrics.
				      metrics_val[metric_no].x - 1,
				      delims[0]);
	  A4GL_debug ("Making field 3");
	  if (formdets->fileform->metrics.metrics_val[metric_no].dlm1)
	    formdets->form_fields[cnt++] =
	      (void *) formdets->fileform->metrics.metrics_val[metric_no].
	      dlm1;
A4GL_assertion(cnt>=MAX_FORM_FIELDS,"Ran out of form_fields...");


	  formdets->fileform->metrics.metrics_val[metric_no].dlm2 =
	    (long) A4GL_LL_make_label (formdets->fileform->metrics.
				      metrics_val[metric_no].y,
				      formdets->fileform->metrics.
				      metrics_val[metric_no].x +
				      formdets->fileform->metrics.
				      metrics_val[metric_no].w, delims[1]);
	  A4GL_debug ("Making field 4");

	  if (formdets->fileform->metrics.metrics_val[metric_no].dlm1)
	    formdets->form_fields[cnt++] =
	      (void *) formdets->fileform->metrics.metrics_val[metric_no].
	      dlm2;
A4GL_assertion(cnt>=MAX_FORM_FIELDS,"Ran out of form_fields...");

	  A4GL_debug ("Making field 5");

	  formdets->form_fields[cnt] = 0;
	  A4GL_debug ("Made field : %p",
		      formdets->fileform->metrics.metrics_val[metric_no].
		      field);
	}


      if (lscr != formdets->fileform->metrics.metrics_val[metric_no].scr)
	{
	  lscr = formdets->fileform->metrics.metrics_val[metric_no].scr;
	  A4GL_LL_set_new_page ((void *) formdets->fileform->metrics.
				metrics_val[metric_no].field, 1);
	}



      if (strlen (formdets->fileform->metrics.metrics_val[metric_no].label) ==
	  0)
	{
	  if (last_field == -1)
	    {
	      formdets->fileform->metrics.metrics_val[metric_no].pos_code +=
		POS_VERY_FIRST;
	    }
	}

      if (lfieldscr != formdets->fileform->metrics.metrics_val[metric_no].scr
	  && strlen (formdets->fileform->metrics.metrics_val[metric_no].
		     label) == 0)
	{

	  formdets->fileform->metrics.metrics_val[metric_no].pos_code +=
	    POS_FIRST;

	  if (last_field != -1)
	    {
	      formdets->fileform->metrics.metrics_val[last_field].pos_code +=
		POS_LAST;
	    }
	  lfieldscr = formdets->fileform->metrics.metrics_val[metric_no].scr;
	}
      A4GL_debug ("LAST_FIELD3 -CHK111 a=%d label='%s'", metric_no,
		  formdets->fileform->metrics.metrics_val[metric_no].label);
      if (strlen (formdets->fileform->metrics.metrics_val[metric_no].label) ==
	  0)
	last_field = metric_no;
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
  struct list_of_fields lof;
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
		  A4GL_ll_set_field_userptr ((void *) formdets->fileform-> metrics.metrics_val[metric_no].  field, ptr);
		  A4GL_set_field_attr_for_ll (formdets, (void *) formdets->fileform-> metrics.metrics_val[metric_no].field);
		  A4GL_debug ("Done\n");
		}
	    }
	}
    }
  A4GL_debug ("formdets->form_fields=%p", formdets->form_fields);

  lof.a.a_len = 0;
  lof.a.a_val = (long *) formdets->form_fields;
  while (lof.a.a_val[lof.a.a_len])
    lof.a.a_len++;
  formdets->form = A4GL_LL_new_form (&lof);
  if (formdets->form == 0)
    {
      A4GL_exitwith ("Failed to create the loaded the form");
      return 0;
    }
  A4GL_ll_set_form_userptr (formdets->form, formdets);
  A4GL_debug ("Loaded form...");
  return 1;
}

/* 
 This function sets a value which is used for the
 beginning and end of field delimiters (normally [ and ] )
 so that they can be easily changed from the 4gl code

 This is normally done to emulate the isql perform action
 where only the fields for the current form have their '[' and ']'
 displayed.

 In order to use this value - you have to DISPLAY something to the field

	Example usage : 


	call aclfgl_set_display_field_delimiters("  ")
	display "hh" to tabname
	call aclfgl_set_display_field_delimiters("[]")
	display "hh" to tabname
*/
int UILIB_aclfgl_aclfgl_set_display_field_delimiters(int n) {
        if (set_current_display_delims) free(set_current_display_delims);
        set_current_display_delims=A4GL_char_pop();
        return 0;
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
  formdets = (struct s_form_dets *) UILIB_A4GL_get_curr_form (1);
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
  nofields = A4GL_gen_field_list (&field_list, formdets, n, ap,0);
  A4GL_debug ("Number of fields=%d ", nofields, n);

  if (nofields < 0)
    {
      A4GL_debug ("Failed to find fields");
      return 0;
    }

  for (a = nofields; a >= 0; a--)
    {

      A4GL_set_field_pop_attr (field_list[a], attr, FGL_CMD_DISPLAY_CMD);
      fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (field_list[a]));
 	A4GL_fprop_flag_set(field_list[a],FLAG_FIELD_TOUCHED);

        if (set_current_display_delims) {
                int dl;
                // Search through our fields and get our metrics_val - that way
                // we can change our delimiters
                for (dl=0;dl<formdets->fileform->metrics.metrics_len;dl++) {
                        if ((void *)formdets->fileform->metrics.metrics_val[dl].field==(void *)field_list[a]) {
                                        char buff[2];
                                        buff[1]=0;
                                        buff[0]=set_current_display_delims[0];
					if (formdets->fileform->metrics.metrics_val[dl].dlm1) {
                                        	A4GL_LL_set_field_buffer((void*)formdets->fileform->metrics.metrics_val[dl].dlm1,0,buff, buff);
					}
                                        buff[0]=set_current_display_delims[1];
					if (formdets->fileform->metrics.metrics_val[dl].dlm2) {
                                        	A4GL_LL_set_field_buffer((void*)formdets->fileform->metrics.metrics_val[dl].dlm2,0,buff, buff);
					}
                        }
                }
        }


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
  long oopt_orig;
  int d1;
  int s1;
  void *ptr1;
  char *currbuff;


  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);


  f = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (field));

  if (A4GL_has_bool_attribute (f, FA_B_REVERSE))
    a = 1;
  else
    a = 0;

  A4GL_debug ("f->do_reverse=%d attr=%x", a, attr);

  currbuff = A4GL_display_field_contents (field, d1, s1, ptr1);

  A4GL_debug ("set f->do_reverse to %d ", f->do_reverse);

  oopt_orig = A4GL_ll_field_opts (field);
  oopt = oopt_orig;

  A4GL_set_field_attr_for_ll (0,field);
  if (currbuff == 0)
    {
      currbuff = A4GL_LL_field_buffer (field, 0);
    }
  A4GL_debug ("Determining attribute - field_buffer=%s", currbuff);
  attr = A4GL_determine_attribute (cmd_type, attr, f, currbuff);

  if (attr != 0)
    {
      A4GL_debug ("calling set_field_attr_with_attr : %x", attr);
      A4GL_set_field_attr_with_attr (field, attr, cmd_type);
    }


  A4GL_debug ("set field attr");
  fff = (struct s_form_dets *) UILIB_A4GL_get_curr_form (1);
  A4GL_debug ("set field");
  A4GL_debug ("set field buffer setting do_reverse=%d", a);

  f->do_reverse = a;
  A4GL_debug ("done ");

  if (oopt != oopt_orig)
    {
      A4GL_ll_set_field_opts (field, oopt);
    }
  A4GL_debug ("ZZZZ - SET OPTS");
  A4GL_debug ("Calling display_field_contents");




}


int
UILIB_A4GL_gen_field_list_from_slist (void *field_listv, void *formdetsv,
				      void *listv)
{
  int a;
  void ***field_list;
  struct s_form_dets *formdets;
  struct s_field_name_list *list;

  field_list = field_listv;
  formdets = formdetsv;
  list = listv;

  a =
    A4GL_gen_field_list_from_slist_internal (field_list, formdets, 9999,
					     list);
  return a;
}

// MID 1014 - The things we do in the name of compatibility....
static void remove_tables_from_list(struct s_field_name_list *list) { // MID 1014
int a;                                                                // MID 1014
for (a=0;a<list->nfields;a++) {                                       // MID 1014
        char *ptr;                                                    // MID 1014
        ptr=strchr(list->field_name_list[a].fname,'.');               // MID 1014
        if (ptr) {                                                    // MID 1014
                        list->field_name_list[a].fname=ptr+1;         // MID 1014
                }                                                     // MID 1014
}                                                                     // MID 1014
} 


int
A4GL_gen_field_list (void ***field_list, struct s_form_dets *formdets,
		     int max_number, va_list * ap,int replace_0)
{
  struct s_field_name_list list;
  int n;
  list.field_name_list = 0;

  A4GL_make_field_slist_from_ap (&list, ap, replace_0);
  n=A4GL_gen_field_list_from_slist_internal (field_list, formdets, max_number, &list);

  if (field_status_strip_tabname && n==-1 && !A4GL_isno(acl_getenv("FIELDTOUCHEDTABLEFIXUP"))) { // MID 1014
        remove_tables_from_list(&list);                                                          // MID 1014
        n=A4GL_gen_field_list_from_slist_internal (field_list, formdets, max_number, &list);     // MID 1014
   }


   free(list.field_name_list);


  return n;

}



int
A4GL_gen_field_list_from_slist_internal (void ***field_list,
					 struct s_form_dets *formdets, int a,
					 struct s_field_name_list *list)
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
  int fmetric;
  struct struct_metrics *k;
  int attr_no;
  int srec_no;
  int cnt = 0;
  if (formdets == 0)
    {
      A4GL_exitwith ("No form displayed");
      return -1;
    }

#ifdef DEBUG
#endif
  A4GL_debug ("field_list=%p", field_list);
  A4GL_debug ("Here 2");

  for (z1 = 0; z1 <= a; z1++)
    {
      A4GL_debug ("Getting first %d", z1);

      if (z1 >= list->nfields)
	break;
      s = list->field_name_list[z1].fname;
      if (s == 0)
	{
	  break;
	}

      fmetric = list->field_name_list[z1].fpos;
      A4GL_debug (" got field number as %d ", fmetric);


      ff = 0;

      /* get screen record/table name */
      memset (tabname, 0, sizeof (tabname));
      memset (colname, 0, sizeof (colname));

      A4GL_bname (s, tabname, colname);
      srec_no = A4GL_find_srec (formdets->fileform, tabname);

      if (strlen (tabname) && strlen (colname) && srec_no == -1)
	{
	  if (!field_status_strip_tabname ) {
		A4GL_exitwith ("Table/Screen record does not exist in form");
		}
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
		    metric_val[fmetric];
		  A4GL_debug ("fno=%d f=%d mno=%d metric_no=%d\n", fno,
			      fmetric, mno, metric_no);
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
			      metric.metric_len, fmetric);
		  if (formdets->fileform->fields.fields_val[fno].metric.
		      metric_len <= fmetric || fmetric < 0)
		    {
		      A4GL_exitwith ("Field subscript out of bounds");
		      return -1;
		    }
		  metric_no =
		    formdets->fileform->fields.fields_val[fno].metric.
		    metric_val[fmetric];
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
		  if (fmetric == 0 && strlen (tabname) == 0)
		    {
		      A4GL_debug ("Are you Test 278...?");
		      z = formdets->fileform->attributes.attributes_len + 1;
		    }

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


  *field_list = calloc (cnt + 1, sizeof (void *));
  memcpy (*field_list, flist, sizeof (void *) * (cnt + 1));
  return cnt - 1;
}


static void A4GL_replace_tab_with_spaces_on_stack(void) {
char *s;
char buff[20480];
int b=0;
int a;
int d1;
int s1;
void *ptr1;

  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
if (ptr1==NULL) return;
if ((d1&DTYPE_MASK)==DTYPE_CHAR || (d1&DTYPE_MASK)==DTYPE_VCHAR) {

        if (strchr(ptr1,'\t')==NULL) {
                return;
        }
        s=A4GL_char_pop();

        for (a=0;a<strlen(s);a++) {
                if (s[a]=='\t') {
                        buff[b++]=' ';
                        buff[b++]=' ';
                        buff[b++]=' ';
                } else {
                        buff[b++]=s[a];
                }
        }
        A4GL_assertion(b>sizeof(buff),"Buffer too small in replace_tab_with_spaces_on_stack");
        buff[b]=0;
        A4GL_push_char(buff);
        acl_free(s);
        }
}





char *
A4GL_display_field_contents (void *field, int d1, int s1, char *ptr1)
{
  int field_width;
  int has_format;
  int ignore_formatting = 0;
  struct struct_scr_field *f;
  char *ff;
  static char *buff = 0;
  char *orig=0;
int height;
int width;




  A4GL_debug ("In display_field_contents");
  f = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (field));
  height=A4GL_get_field_height(field);
 
  width=A4GL_get_field_width (field)*height;
  ff = A4GL_new_string (width);
 
  if ((d1 & DTYPE_MASK)==DTYPE_CHAR ) {
		orig=A4GL_char_pop();
		A4GL_push_char(orig);
  }

  field_width = width;
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
	  A4GL_drop_param ();
	  return 0;
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


  if (f->dynamic==0) {
        A4GL_replace_tab_with_spaces_on_stack();
        A4GL_pop_char (ff, field_width);
  }  else {
          A4GL_debug("Its a dynamic field.... %d",f->dynamic);
          acl_free(ff);
          ff=A4GL_char_pop();
          A4GL_debug("Got : %s instead..\n",ff);
  }

  A4GL_debug ("set_field_contents : '%s'", ff);
  A4GL_add_recall_value (f->colname, ff);
  A4GL_mja_set_field_buffer (field, 0, ff,orig);
  if (buff)
    free (buff);
  buff = strdup (ff);
  free (ff);
  return buff;

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
  A4GL_debug ("Error Window=%p", w);
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

      A4GL_debug ("clr error window");
      A4GL_LL_delete_errorwindow (curr_error_window);
      curr_error_window = 0;
      A4GL_LL_screen_update ();
      A4GL_debug ("done...");
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
	 *) (A4GL_ll_get_field_userptr (s->field_list[a]));

      if (!A4GL_field_is_noentry ((s->mode == MODE_CONSTRUCT), fprop)
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
	if (A4GL_ll_get_field_userptr (form->currentfield) != 0)
	  {
	    A4GL_debug ("Is a proper field");
	    fprop =
	      (struct struct_scr_field
	       *) (A4GL_ll_get_field_userptr (form->currentfield));
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
                                  A4GL_fprop_flag_clear(sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
                                  A4GL_fprop_flag_set(sio->currform->currentfield, FLAG_MOVING_TO_FIELD);

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
                                A4GL_fprop_flag_clear(sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
                                A4GL_fprop_flag_set(sio->currform->currentfield, FLAG_MOVING_TO_FIELD);

				return -4;
			      }
			  }


			return 0;
		      }


		    A4GL_debug ("Pushing to validate : %s\n", buff2);

		    pprval =
		      A4GL_check_and_copy_field_to_data_area (form, fprop,
							      buff2, buff);




		    A4GL_debug ("pprval = %d\n", pprval);
		    if (!pprval)
		      {
			A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
                        A4GL_fprop_flag_clear(sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
                        A4GL_fprop_flag_set(sio->currform->currentfield, FLAG_MOVING_TO_FIELD);

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
                        A4GL_fprop_flag_clear(sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
                        A4GL_fprop_flag_set(sio->currform->currentfield, FLAG_MOVING_TO_FIELD);
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
                        A4GL_fprop_flag_clear(sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
                        A4GL_fprop_flag_set(sio->currform->currentfield, FLAG_MOVING_TO_FIELD);
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
local_chk_field (struct s_form_dets *form, void *f)
{
  char buff[8000] = "";
  char buff2[8000] = "";
  char buff3[8000] = "";
  void *mform=0;
  int pprval;
  //int x, y;
  //int flg = 0;
  //struct s_form_dets *form;
  struct struct_scr_field *fprop;
  mform=form->form;
  if (A4GL_ll_get_field_userptr (f) != 0)
    {
      A4GL_debug ("Is a proper field");
      fprop =
	(struct struct_scr_field
	 *) (A4GL_ll_get_field_userptr (f));
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
					    (form, f)].w);

	      strcpy (&buff[4], A4GL_LL_field_buffer (f, 0));

	      strcpy (buff2, &buff[4]);

	      if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
		{
		  int a;
		  int blank = 1;
		  char *picture;
		  picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
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
			  A4GL_error_nobox (acl_getenv ("FIELD_REQD_MSG"), 0);
                     A4GL_fprop_flag_clear(f, FLAG_MOVED_IN_FIELD);
                     A4GL_fprop_flag_set(f, FLAG_MOVING_TO_FIELD);
			  //A4GL_LL_set_current_field (mform, form->currentfield);
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
			  A4GL_debug ("X2222 Check for include has null...");
			  A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
                     A4GL_fprop_flag_clear(f, FLAG_MOVED_IN_FIELD);
                     A4GL_fprop_flag_set(f, FLAG_MOVING_TO_FIELD);
                                  if (fprop != 0)
                                    A4GL_comments (fprop);

			  return -4;
			}
		    }


		  return 0;
		}


	      A4GL_debug ("Pushing to validate : %s\n", buff2);

	      pprval =
		A4GL_check_and_copy_field_to_data_area (form, fprop,
							buff2, buff);



	      A4GL_debug ("pprval = %d\n", pprval);
	      if (!pprval)
		{
		  A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
                          if (fprop != 0)
                            A4GL_comments (fprop);
                     A4GL_fprop_flag_clear(f, FLAG_MOVED_IN_FIELD);
                     A4GL_fprop_flag_set(f, FLAG_MOVING_TO_FIELD);

		  if (A4GL_isyes (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
		    {
		      A4GL_clr_field (f);
		    }
		  else
		    {
		      if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
			{
                         A4GL_fprop_flag_clear(f, FLAG_MOVED_IN_FIELD);
                         A4GL_fprop_flag_set(f, FLAG_MOVING_TO_FIELD);

			  A4GL_LL_int_form_driver (mform, AUBIT_REQ_BEG_FIELD);
			}

		    }


		  //A4GL_LL_set_current_field (mform, form->currentfield);
		  return -4;
		}
	      else
		{
		  A4GL_debug ("pop_param returns ok...");
		}
	    }


	  strcpy (buff3, A4GL_LL_field_buffer (f, 0));

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
                                  A4GL_fprop_flag_clear(f, FLAG_MOVED_IN_FIELD);
                                  A4GL_fprop_flag_set(f, FLAG_MOVING_TO_FIELD);
			  A4GL_LL_int_form_driver (mform, AUBIT_REQ_BEG_FIELD);

	      A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
	      //A4GL_LL_set_current_field (mform, form->currentfield);
	      return -4;
	    }


	  if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED))
	    {
	      char buff[8024];
	      strcpy (buff, A4GL_LL_field_buffer (f, 0));
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
		      A4GL_error_nobox (acl_getenv ("FIELD_REQD_MSG"), 0);
		      //A4GL_LL_set_current_field (mform, form->currentfield);
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
	  && (A4GL_ll_get_field_userptr (form->currentfield) != 0))
	{
	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_ll_get_field_userptr (form->currentfield));
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
	 *) (A4GL_ll_get_field_userptr (A4GL_LL_current_field (mform)));
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
	 *) (A4GL_ll_get_field_userptr (form->currentfield));
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
     *) (A4GL_ll_get_field_userptr (form->currentfield));
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




/// This fuction extracts the portion of 'fmt' in 'str' for the search term 'srch'
/// eg get_data_from_formatted_field("dd","01/01/2002","dd/mm/yyyy")
/// this has a sideeffect in that the format will have any matching terms replaced by spaces.
/// so - after this call - fmt will be "  /01/2002"
/// this is done so you can search for longer terms first - like mmm or ddd and not have them confused a
/// later search for mm or dd...
static char *get_data_from_formatted_field(char *srch,char *str, char *fmt_orig) {
char *ptr;
int offset;
static char buff[200];
static char fmt[200];

strcpy(fmt,fmt_orig);
for (offset=0;offset<=strlen(fmt);offset++) {
        fmt[offset]=tolower(fmt[offset]);
}

A4GL_debug("get_data_from_formatted_field called with '%s' '%s' '%s'", srch,str,fmt);
ptr=strstr(fmt,srch);
if (ptr==0) {
                A4GL_debug("Searching for %s failed in %s", srch,fmt);
                return 0;
}
offset=ptr-fmt;
A4GL_debug("Offset=%d\n",offset);
strncpy(buff,&str[offset],strlen(srch));
buff[strlen(srch)]=0;
A4GL_debug("Searching for %s in %s got %s", srch,fmt, buff);
memset(fmt+offset,' ',strlen(srch));
return buff;
}

static int matched_date_format(char *fmt,char *data) {
int a;
        for (a=0;a<strlen(data);a++) {
                if (fmt[a]==0) return 0; // Reached the end unexpectedly


                if (data[a]>='0'&&data[a]<='9')  {
                        // Have we got a digit where we'd expect one ?
                        if (tolower(fmt[a])=='d'|| tolower(fmt[a])=='m' || tolower(fmt[a])=='y') ;
                        else {
                                return 0;
                        }
                } else {
                        // Have we got a non-digit where we'd expect a digit ?
                        if (tolower(fmt[a])=='d'|| tolower(fmt[a])=='m' || tolower(fmt[a])=='y') return 0;
                }
        }
        A4GL_debug("Got what looks like a valid date for the format");
        // Excellent
        return 1;
}






char *
A4GL_fld_data_ignore_format (struct struct_scr_field *fprop, char *fld_data)
{
  char *ptr;
  ptr = A4GL_get_str_attribute (fprop, FA_S_FORMAT);
  A4GL_debug ("FLD_DATA_IGNORE_FORMAT : %s\n", fld_data);
//  if (ptr)
//    {
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
	      if ( ! A4GL_is_meaningful_in_decfmt(A4GL_get_convfmts()->ui_decfmt, fld_data[a]))
	        continue;
	      if (fld_data[a] == A4GL_get_convfmts()->ui_decfmt.decsep)
	      {
	        buff_new[c++] = A4GL_get_convfmts()->posix_decfmt.decsep;
	        continue;
	      }
	      buff_new[c++] = fld_data[a];
	    }
	  fld_data = buff_new;
	  A4GL_debug ("COPY -> %s instead", fld_data);
	}


  if (fprop->datatype == DTYPE_DATE)
    {
      int adate;
      int done=0;
      
	  if (ptr)
	    {
	      char tmpbuff[200];
		char format[256];
	      static char buff_new[256];
	      //int mm;
	      int rval;
	      char *mmm_s;
	      int mmm;
	      int dd;
	      //int yyyy;
	      int yy;
	      char *d;

		if (!matched_date_format(ptr,fld_data)) {
      				if (A4GL_stod (fld_data, &adate, 0) == 1 )
					{
	  				char *d;
	  				static char buff_new[256];
	  				A4GL_push_date (adate);
	  				d = A4GL_char_pop ();
	  				strcpy (buff_new, d);
	  				free (d);
	  				fld_data = buff_new;
				
				}
				return fld_data;
		}

	      memset (buff_new, 0, 255);
		strcpy(format,ptr); // 'format' will get changed by the calls to get_data_from_formatted_field
		A4GL_debug("fld_data=%s\n",fld_data);
	      strcpy (tmpbuff, fld_data);
	      mmm_s = get_data_from_formatted_field ("mmm", tmpbuff, format);
	      if (mmm_s)
		{
		  int a;
		  for (a = 1; a <= 12; a++)
		    {
		      if (strcmp (A4GL_find_str_resource_int ("_MON", a), mmm_s) == 0)
			{
			  mmm = a;
			  break;
			}
		    }
		}
	      else
		{
	      d = get_data_from_formatted_field ("mm", tmpbuff, format);

	      if (d)
		mmm = atol (d);
	      else
		mmm = -1;
		}

	      // Just removed any 'ddd' - they are ignored...
	      d = get_data_from_formatted_field ("ddd", tmpbuff, format);

	      d = get_data_from_formatted_field ("dd", tmpbuff, format);
	      if (d)
		dd = atol (d);
	      else
		dd = -1;
	      d = get_data_from_formatted_field ("yyyy", tmpbuff, format);
	      if (d)
		yy = atol (d);
	      else{
	      d = get_data_from_formatted_field ("yy", tmpbuff, format);
	      if (d)
		yy = A4GL_modify_year (atol (d));
	      else
		yy = -1;
		}

		if (dd==-1 || mmm==-1 || yy==-1) {
			// Couldn't figure  out one of them...
			A4GL_exitwith("Unable to determine date from format");
			return "";
		}
		A4GL_debug("Got dd=%d mmm=%d yy=%d",dd,mmm,yy);

	      rval = A4GL_gen_dateno (dd, mmm, yy);
	      A4GL_push_date (rval);
	      d = A4GL_char_pop ();
	      strcpy (buff_new, d);
		done++;
	      free (d);
	      fld_data = buff_new;
	    }
      if (!done) {
      if (A4GL_stod (fld_data, &adate, 0) == 1 )
	{
	  char *d;
	  static char buff_new[256];
	  A4GL_push_date (adate);
	  d = A4GL_char_pop ();
	  strcpy (buff_new, d);
	  free (d);
	  fld_data = buff_new;

	}
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
	   || fprop->datatype == DTYPE_SERIAL) && strchr (fld_data, A4GL_get_convfmts()->ui_decfmt.decsep))
	{
	  A4GL_debug ("Looks like a decimal in an integer field");
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
  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));

  w = A4GL_get_field_width (f);
  str = acl_malloc2 (w + 1);
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
  A4GL_mja_set_field_buffer (f, 0, str,0);
}


int
A4GL_do_after_field (void *f, struct s_screenio *sio)
{
  int a;
  char *ptr;
  struct struct_scr_field *fprop;
  void *mform=0;


  a = A4GL_find_field_no (f, sio);

	  mform = sio->currform->form;

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
      fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));
      A4GL_push_char (A4GL_fld_data_ignore_format
		      (fprop, A4GL_LL_field_buffer (f, 0)));
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
	  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));

	  A4GL_debug ("Got form %p", sio->currform->form);
	  if (A4GL_check_field_for_include
	      (A4GL_LL_field_buffer (sio->currform->currentfield, 0),
	       A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
	       fprop->datatype) == 0)
	    {
             A4GL_fprop_flag_clear(sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
             A4GL_fprop_flag_set(sio->currform->currentfield, FLAG_MOVING_TO_FIELD);

	      A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
	      A4GL_LL_set_current_field (mform, sio->currform->currentfield);
	    }
	}

      A4GL_pop_var2 (sio->vars[a].ptr, sio->vars[a].dtype, sio->vars[a].size);

    }
  else
    {
      fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));
      if (fprop != 0)
	{
	  if (fprop->colname != 0)
	    {
                char *fbuf;
                fbuf=A4GL_LL_field_buffer(f,0);

                if (sio->constr[a].value) {
                        fbuf=sio->constr[a].value;
                }

	      A4GL_debug ("Calling constr with : '%s' '%s'",
			  sio->constr[a].tabname, sio->constr[a].colname);


	      ptr =
		(char *) A4GL_construct (sio->constr[a].tabname,
					 sio->constr[a].colname,
					 fbuf,
					 A4GL_UI_int_get_inc_quotes (fprop->
								     datatype), fprop->datatype, fprop->dtype_size, sio->callback_function);
	      A4GL_debug ("ptr=%s", ptr);
	      if (ptr == 0)
		{
		  A4GL_error_nobox (acl_getenv ("FIELD_CONSTR_EXPR"), 0);
			A4GL_fprop_flag_clear(f, FLAG_MOVED_IN_FIELD);
		  	A4GL_fprop_flag_set(f, FLAG_MOVING_TO_FIELD);
                  	A4GL_LL_int_form_driver (mform, AUBIT_REQ_BEG_FIELD);

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


int
UILIB_A4GL_prompt_loop_v2 (void *vprompt, int timeout, void *evt)
{
  int a;
  A4GL_debug ("Prompt loop\n");
  ActivateToolbar("Prompt",evt,vprompt);
  a = A4GL_prompt_loop_v2_int (vprompt, timeout, evt);
  A4GL_debug ("Returns %d\n", a);
  ActivateToolbar(0,0,0);
  return a;
}

static int
A4GL_prompt_loop_v2_int (void *vprompt, int timeout, void *evt)
{
  int a;
  int was_aborted = 0;
  void *p;
  struct s_prompt *promptx;
  int rblock;
  promptx = vprompt;
  A4GL_chkwin ();

  A4GL_set_abort (0);

  p = promptx->win;



  if (promptx->mode == -1)
    {				// Initialize prompt...
      A4GL_clr_evt_timeouts (evt);
      A4GL_submit_events (vprompt, evt);
      promptx->mode = 0;
      return 0;
    }



  if (promptx->mode == 1)
    {
      char buff[10024];
      A4GL_debug ("Think we're done here...");
      strcpy (buff, A4GL_LL_field_buffer (promptx->field, 0));
      A4GL_debug ("prompt buff=%s", buff);
      A4GL_trim (buff);
      A4GL_debug ("prompt buff=%s", buff);

      A4GL_push_char (buff);
      promptx->mode = 2;

      if (promptx->f)
	{
	  A4GL_LL_clear_prompt (promptx->f, promptx->win);
	  A4GL_LL_screen_update ();
	}
      return 0;
    }

  if (promptx->mode > 0)
    {
      return 0;
    }

  abort_pressed = 0;
  was_aborted = 0;
  A4GL_LL_set_carat (promptx->f);
  A4GL_LL_screen_update ();

  while (1)
    {
      int blk;
      blk = A4GL_has_evt_timeout (evt);
      if (blk)
	{
	  return blk;
	}

      A4GL_LL_activate_events (vprompt);

      a = A4GL_getch_internal (p, "prompt");

      if (a == A4GLKEY_EVENT)
	{
	  A4GL_debug ("prompt fired event...");
	  A4GL_evt_not_idle (evt);
	  return A4GL_LL_get_triggered_event ();
	}



      if (abort_pressed)
	break;
      if (a != -1)
	break;
    }

  if (a)
    A4GL_clr_error_nobox ("prompt");

  promptx->processed_onkey = a;

  //prompt_last_key = a;
  A4GL_set_last_key (a);
  if (a != 0 && a != -1)
    {
      A4GL_evt_not_idle (evt);
    }


  promptx->lastkey = A4GL_get_lastkey ();


  if (abort_pressed)
    {
      A4GL_set_last_key (A4GL_key_val ("INTERRUPT"));
      promptx->lastkey = A4GL_key_val ("INTERRUPT");;

      if (!A4GL_has_event_for_keypress (promptx->lastkey, evt))
	{
	  A4GL_push_null (DTYPE_CHAR, 1);
	  promptx->mode = 2;
	  A4GL_LL_clear_prompt (promptx->f, promptx->win);
	  A4GL_LL_screen_update ();
	  return 0;
	}
    }

  A4GL_debug ("No lastkey..");
  rblock = A4GL_has_event_for_keypress (promptx->lastkey, evt);


  if (rblock)
    {				// We appear to be all done here...
      A4GL_push_null (DTYPE_CHAR, 1);
      promptx->mode = 2;
      A4GL_LL_clear_prompt (promptx->f, promptx->win);
      A4GL_LL_screen_update ();
      promptx->f = 0;
      return rblock;
    }


  if (was_aborted)
    {
      promptx->mode = 2;
      return 0;
    }


  a = A4GL_proc_key_prompt (a, promptx->f, promptx);

  if (a == 0)
    {
      return 0;
    }

  if (a < 0)
    return a;

  A4GL_debug ("Requested..");

  if (a == 10 || a == 13)
    {
      //prompt_last_key = 0;
      A4GL_LL_int_form_driver (promptx->f, AUBIT_REQ_VALIDATION);
      A4GL_debug ("su");
      A4GL_LL_screen_update ();
      A4GL_debug ("Return pressed");
      promptx->mode = 1;
      return 0;
    }

  A4GL_debug ("Requesting Validation : %p %x %d", promptx->f, a, a);
  if ((a_isprint (a)))
    {
      A4GL_debug ("Printable");
      A4GL_LL_int_form_driver (promptx->f, a);
      A4GL_debug
	("Called int_form_driver - now calling REQ VALIDATION (%d) PREV_CHAR (%d)",
	 AUBIT_REQ_VALIDATION, AUBIT_REQ_PREV_CHAR);
      A4GL_LL_int_form_driver (promptx->f, AUBIT_REQ_VALIDATION);
      A4GL_debug ("Called int_form_driver - REQ VALIDATION");
    }



  A4GL_debug ("su");
  A4GL_LL_screen_update ();

  if (promptx->charmode)
    {
      if ((a_isprint (a)))
	{
	  A4GL_push_char (A4GL_LL_field_buffer (promptx->field, 0));
	  A4GL_LL_clear_prompt (promptx->f, promptx->win);
	  A4GL_LL_screen_update ();
	  promptx->f = 0;
	  promptx->mode = 2;
	}
    }

  A4GL_debug ("Done..");
  return -1000;

}

int
UILIB_A4GL_start_prompt (void *vprompt, int ap, int c, int h, int af,char *text,char *style)
{
  char *promptstr;
  struct s_prompt *promptx;
  int x;
  char *beepchr;


  promptx = vprompt;

  A4GL_chkwin ();
  promptstr = A4GL_char_pop ();


  //
  // Some mad people put \007 in the prompt strings
  // to force a terminal beep....
  //
  while (1)
    {
      beepchr = strchr (promptstr, '\007');
      if (!beepchr)
	break;
      *beepchr = ' ';
      A4GL_LL_beep ();
    }


  promptx->mode = -1;
  promptx->h = h;
  promptx->insmode = 0;
  promptx->charmode = c;
  promptx->promptstr = promptstr;
  promptx->lastkey = 0;


  ap = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, ap, 0, 0);
  af = A4GL_determine_attribute (FGL_CMD_INPUT, af, 0, 0);

  A4GLSQL_set_status (0, 0);
  x =
    A4GL_LL_start_prompt (vprompt, promptstr, ap, c, h, af,
			  UILIB_A4GL_get_curr_width (),
			  UILIB_A4GL_iscurrborder (), A4GL_getprompt_line (),
			  (void *) A4GL_get_currwin (), promptx->mode);
  promptx->field = A4GL_LL_get_value ("prompt.field");
  promptx->f = A4GL_LL_get_value ("prompt.f");
  promptx->win = A4GL_LL_get_value ("prompt.win");


  if (x == 2)
    {
      promptx->mode = 2;
      return 2;
    }
  A4GL_debug ("Start prompt returning : %d", x);
  return x;
}



int
UILIB_A4GL_get_key (int timeout)
{
  return A4GL_getch_internal ((void *) A4GL_window_on_top (), "A4GL_get_key");
}



void
UILIB_A4GL_acli_scroll_ap (int n, va_list * ap)
{
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
  arr = va_arg (*ap, char *);

  if (n < 0)
    {
      dir = -1;
      n = 0 - n;
    }
  else
    {
      dir = 1;
    }


  if (n > 1)
    {
      int cnt;
      for (cnt = 0; cnt < n; cnt++)
	{
	  A4GL_acli_scroll (dir, arr, 0, 0, 0);
	}
      return;
    }


  f = (struct s_form_dets *) UILIB_A4GL_get_curr_form (1);
  strcpy (barr, arr);

  ptr = strchr (barr, '.');

  if (ptr == 0)
    {
      A4GL_exitwith ("Internal error - expected a .* in screen record");
      return;
    }

  *ptr = 0;

  A4GL_debug ("barr=%s", barr);
  srec_no = A4GL_find_srec (f->fileform, barr);

  if (srec_no == -1)
    {
      A4GL_exitwith ("Unknown screen record");
      return;
    }

  A4GL_debug ("srec_no=%d nrows=%d attribs=%d", srec_no,
	      f->fileform->records.records_val[srec_no].dim,
	      f->fileform->records.records_val[srec_no].attribs.attribs_len);
  buff =
    acl_malloc2 (sizeof (char *) *
		 f->fileform->records.records_val[srec_no].dim);


  for (a = 0; a < f->fileform->records.records_val[srec_no].dim; a++)
    {
      buff[a] =
	acl_malloc2 (sizeof (char *) *
		     f->fileform->records.records_val[srec_no].attribs.
		     attribs_len);
    }

  dim = f->fileform->records.records_val[srec_no].dim;
  nfields = f->fileform->records.records_val[srec_no].attribs.attribs_len;
  for (b = 0; b < nfields; b++)
    {
      for (a = 0; a < dim; a++)
	{
	  attr =
	    f->fileform->records.records_val[srec_no].attribs.attribs_val[b];
	  fno = f->fileform->attributes.attributes_val[attr].field_no;
	  mno = f->fileform->fields.fields_val[fno].metric.metric_val[a];
	  field = (void *) f->fileform->metrics.metrics_val[mno].field;
	  A4GL_debug ("SCROLL %s [ %d] . %d = %p (%s)", barr, a, b, field,
		      A4GL_LL_field_buffer (field, 0));
	  buff[a][b] = field;
	}
    }

  if (dir == -1)
    {
      for (a = dim - 1; a > 0; a--)
	{
	  for (b = 0; b < nfields; b++)
	    {
	      A4GL_debug ("field[%d][%d] = buffer[%d][%d]", a, b, a - 1, b);
	      ptr = A4GL_LL_field_buffer (buff[a - 1][b], 0);
	      A4GL_debug ("              = %s", ptr);
	      A4GL_LL_set_field_buffer (buff[a][b], 0, ptr,0);
	    }
	}
      for (b = 0; b < nfields; b++)
	{
	  A4GL_LL_set_field_buffer (buff[0][b], 0, "",0);
	}
    }

  if (dir == 1)
    {
      for (a = 0; a < dim - 1; a++)
	{
	  for (b = 0; b < nfields; b++)
	    {
	      A4GL_debug ("field[%d][%d] = buffer[%d][%d]", a, b, a + 1, b);
	      ptr = A4GL_LL_field_buffer (buff[a + 1][b], 0);
	      A4GL_debug ("              = %s", ptr);
	      A4GL_LL_set_field_buffer (buff[a][b], 0, ptr,0);
	    }
	}
      for (b = 0; b < nfields; b++)
	{
	  A4GL_LL_set_field_buffer (buff[dim - 1][b], 0, "",0);
	}
    }






}
int
A4GL_find_attrib_from_metric (struct_form * f, int metric_no)
{
  return A4GL_find_attrib_from_field (f,
				      A4GL_find_fields_no_metric (f,
								  metric_no));
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
  A4GL_debug ("BB - Looking for metric : %d\n", metric_no);
  for (a = 0; a < f->fields.fields_len; a++)
    {
      for (b = 0; b < f->fields.fields_val[a].metric.metric_len; b++)
	{
	  if (f->fields.fields_val[a].metric.metric_val[b] == metric_no)
	    {
	      A4GL_debug ("Found metric : %d\n", f);
	      return a;
	    }
	}
    }
  //A4GL_assertion(1,"Field for metric not found");
  A4GL_debug ("Metric not found %d", metric_no);
  return -1;
}


int
A4GL_find_attrib_from_field (struct_form * f, int field_no)
{
  int a;
  A4GL_debug ("AA\n");
  A4GL_debug ("field_no=%d\n", field_no);
  if (field_no == -1)
    return -1;
  for (a = 0; a < f->attributes.attributes_len; a++)
    {
      if (f->attributes.attributes_val[a].field_no == field_no)
	{
	  A4GL_debug ("Found field %d @ %d - %s\n", field_no, a,
		      f->attributes.attributes_val[a].colname);
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
	  A4GL_set_scrmode ('L');
	}
      A4GL_LL_out_linemode (s);
      return;
    }
  else
    {
      int w;
      int h;
      w = UILIB_A4GL_get_curr_width ();
      h = UILIB_A4GL_get_curr_height ();
      A4GL_debug ("got w=%d want %d", w, x);
      A4GL_debug ("got y=%d want %d", h, y);

      if (y < 1 || y > h)
	{
	  A4GL_exitwith
	    ("The row or column number in DISPLAY AT exceeds the limits of your terminal 1");
	  return;
	}
      if (x < 1 || x > w)
	{
	  A4GL_exitwith
	    ("The row or column number in DISPLAY AT exceeds the limits of your terminal 2");
	  return;
	}

      if (strlen (s) == 0 && clr_line)
	return;

      A4GL_chkwin ();
      nattr = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, a, 0, 0);
      a = nattr;

      wot = (void *) A4GL_window_on_top_ign_menu ();

      A4GL_debug ("CURR=%d", UILIB_A4GL_get_curr_height ());


      A4GL_wprintw (wot, a, x, y, UILIB_A4GL_get_curr_width (),
		    UILIB_A4GL_get_curr_height (), UILIB_A4GL_iscurrborder (),
		    A4GL_get_currwinno (), "%s", s);

      if (clr_line)
	{
	  int sl;
	  char buff[1024];
	  memset (buff, ' ', 1024);
	  A4GL_debug ("strlen=%d", strlen (s));
	  sl = strlen (s);
	  sl = A4GL_get_curr_width () - sl - x + 1;
	  A4GL_debug ("sl=%d spaces required", sl);
	  if (sl >= 0)
	    {
	      buff[sl] = 0;
	      buff[1023] = 0;
	      A4GL_debug ("wprintw : %s\n", buff);
	      A4GL_wprintw (wot, (a & 0xffffff00), x + strlen (s), y,
			    UILIB_A4GL_get_curr_width (),
			    UILIB_A4GL_get_curr_height (),
			    UILIB_A4GL_iscurrborder (), A4GL_get_currwinno (),
			    "%s", buff);
	    }
	}
      A4GL_LL_screen_update ();
    }
  A4GL_debug ("Done Display");

}


void
UILIB_A4GL_reset_state_for (void *sio, char *siotype)
{
  static void *last_sio = 0;

  if (strcmp (siotype, "s_inp_arr") == 0)
    {
      struct s_inp_arr *s;
      s = sio;
      if (last_sio != sio)
	{
	  // May need to do a full redraw..
	  last_sio = sio;
	  if (sio)
	    A4GL_idraw_arr_all (s);
	}
      if (s)
	{
	  A4GL_set_arr_curr (s->arr_line);
	  A4GL_set_scr_line (s->scr_line);
	  A4GL_set_arr_count (s->no_arr);
	}

    }

  if (strcmp (siotype, "s_disp_arr") == 0)
    {
      //static void *last_sio = 0;
      struct s_disp_arr *s;
      s = sio;

      if (s)
	{
	  A4GL_set_arr_curr (s->arr_line);
	  A4GL_set_scr_line (s->scr_line);
	  A4GL_set_arr_count (s->no_arr);
	}

    }


      if (strcmp(siotype, "s_screenio")==0) {
                struct s_screenio *s;
		void *f;
                s=sio;
		f=s->field_list[s->curr_attrib];
                A4GL_set_fields_sio(s);
                s->currform->currentfield=f;
                s->currentfield=f;
                A4GL_mja_set_current_field(s->currform->form, f);

      }




}




int
A4GL_UI_int_get_inc_quotes (int a)
{
  if ((a & DTYPE_MASK) == DTYPE_CHAR || (a & DTYPE_MASK) == DTYPE_VCHAR)
    return 1;
  if ((a & DTYPE_MASK) == DTYPE_DATE)
    return 2;

  if ((a & DTYPE_MASK) == DTYPE_DTIME) return 3;
  if ((a & DTYPE_MASK) == DTYPE_INTERVAL) return 4;
  return 0;
}






















int
A4GL_proc_key_prompt (int a, void *mform, struct s_prompt *prompt)
{
  //void *current_field;

  //current_field = A4GL_LL_current_field (mform);


  A4GL_debug ("In proc_key_prompt.... for %d", a);
  switch (a)
    {
    case 18:
      A4GL_LL_screen_redraw ();
      break;

    case -1:
      abort_pressed = 1;
      return 0;

    case 27:
      return 0;

    case 26:
      return 0;

    case 127:
    case 8:
    case A4GLKEY_DC:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
      if (A4GL_LL_get_carat (mform))
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_DEL_PREV);
	}
      return 0;

    case 24:
      A4GL_LL_int_form_driver (mform, AUBIT_REQ_DEL_CHAR);
      return 0;

    case '\t':
    case A4GLKEY_DOWN:
      if (prompt->charmode == 0)
	return 10;
      else
	return 0;


      //case A4GLKEY_ENTER:
    case 13:
    case 10:
      return 10;
    case A4GLKEY_LEFT:
      A4GL_LL_int_form_driver (mform, AUBIT_REQ_PREV_CHAR);
      return 0;

    case A4GLKEY_RIGHT:
      A4GL_LL_int_form_driver (mform, AUBIT_REQ_NEXT_CHAR);
      return 0;
    case 4:
      A4GL_LL_int_form_driver (mform, AUBIT_REQ_CLR_FIELD);
      return 0;

    case 1:			// Control - A
      prompt->insmode = prompt->insmode ? 0 : 1;
      if (prompt->insmode)
	A4GL_LL_int_form_driver (mform, AUBIT_REQ_INS_MODE);
      else
	A4GL_LL_int_form_driver (mform, AUBIT_REQ_OVL_MODE);
      return 0;
    }
  if (A4GL_is_special_key (a, A4GLKEY_HELP))
    {
	A4GL_push_int(prompt->h);
      aclfgl_a4gl_show_help (1);
      a = 0;
    }
  return a;
}

 void
A4GL_set_field_attr_for_ll (void *formdets, void *field)
{
  struct struct_scr_field *fprop;
  int autonext;
  int invis;
  int reqd;
  int compress;
  int has_picture;
  long a;

  fprop = (struct struct_scr_field *) A4GL_ll_get_field_userptr (field);

  autonext = A4GL_has_bool_attribute (fprop, FA_B_AUTONEXT);
  invis = A4GL_has_bool_attribute (fprop, FA_B_INVISIBLE);
  reqd = A4GL_has_bool_attribute (fprop, FA_B_REQUIRED);
  compress = A4GL_has_bool_attribute (fprop, FA_B_COMPRESS);
  has_picture = A4GL_has_str_attribute (fprop, FA_S_PICTURE);
  A4GL_default_attributes (field, fprop->datatype, has_picture,formdets);


  a = A4GL_LL_set_field_attr (field, fprop->datatype, fprop->dynamic, autonext, invis, reqd, compress, has_picture);
  	A4GL_ll_set_field_opts (field, a);


	//UILIB_A4GL_zrefresh(); // <-just for debugging...
	//sleep (2);
 
}


// int A4GL_get_field_width (void *field) { return A4GL_LL_get_field_width (field); }


void
A4GL_mja_set_field_buffer (void *field, int nbuff, char *buff,char *orig)
{
  char buff2[8024];
  int a;
  int b;
  int width;
  b = A4GL_get_field_width (field);
  strcpy (buff2, buff);
  a = strlen (buff2);
  b = A4GL_get_field_width (field);
  A4GL_debug ("YYZ field_buffer %p %d %s", field, nbuff, buff);
  width = A4GL_get_field_width (field);
  if (width > 2048)
    {
      char *ptr = 0;
      A4GL_debug ("Field too big...");
      *ptr = 0;

    }
  if (a < A4GL_get_field_width (field))
    {
      A4GL_debug ("Adding padding");
      A4GL_pad_string (buff2, A4GL_get_field_width (field));
    }
  else
    {
      A4GL_debug ("No padding required '%s'", buff);
    }


  A4GL_LL_set_field_buffer (field, nbuff, buff2,orig);
}



int
A4GL_field_opts_on (void *v, int n)
{
  int curr;
  curr = A4GL_ll_field_opts (v);

  if (curr & n)
    return 1;
  A4GL_debug ("Turning %p %x on :%x", v, curr, curr + n);
  curr += n;
  A4GL_ll_set_field_opts (v, curr);
  return 1;
}

int
A4GL_field_opts_off (void *v, int n)
{
  int curr;
  curr = A4GL_ll_field_opts (v);

  if ((curr & n) == 0)
    {
      return 1;
    }

  A4GL_debug ("Turning %p %x off :%x", v, curr, curr - n);
  A4GL_ll_set_field_opts (v,curr - n);

  return 1;
}



int
A4GL_getch_internal (void *win, char *why)
{
  int a;
  A4GL_set_abort (0);
  a = A4GL_readkey ();
  if (a != 0)
    {
      A4GL_debug ("Read %d from keyfile", a);
      return a;
    }
  a = A4GL_LL_getch_swin (win, why);
  a = A4GL_key_map (a);
  A4GL_chk_for_screen_print (a);
  A4GL_logkey (a);

  return a;
}


void
UILIB_A4GLUI_set_intr ()
{
  // Does nothing yet - called if DEFER INTERRUPT has been called...
}




void
A4GL_default_attributes (void *f, int dtype, int has_picture,void *formdets)
{
  int done = 0;

  A4GL_debug ("In def attrib f=%p", f);



  if (has_picture)
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      //A4GL_ll_set_field_opts (f, AUBIT_O_VISIBLE | AUBIT_O_ACTIVE | AUBIT_O_PUBLIC | AUBIT_O_EDIT);
      A4GL_ll_set_field_opts (f, AUBIT_O_VISIBLE |AUBIT_O_PUBLIC );
      done = 1;
    }

  if (done == 0)
    {

      A4GL_debug ("MMMM DTYPE & 255 = %d", dtype);

      if ((dtype & 255) == DTYPE_CHAR || (dtype & 255) == DTYPE_VCHAR)
	{
	  A4GL_debug ("ZZZZ - SET OPTS");
	  //A4GL_ll_set_field_opts (f, AUBIT_O_VISIBLE | AUBIT_O_ACTIVE | AUBIT_O_PUBLIC | AUBIT_O_EDIT);
	  A4GL_ll_set_field_opts (f, AUBIT_O_VISIBLE | AUBIT_O_PUBLIC );



	  //A4GL_field_opts_off (f, AUBIT_O_BLANK); @todo     is it ok to remove this ?

	}
      else
	{
	  A4GL_debug ("ZZZZ - SET OPTS");
	  A4GL_debug ("BLANK BLANK");
	  //A4GL_ll_set_field_opts (f, AUBIT_O_VISIBLE | AUBIT_O_ACTIVE | AUBIT_O_PUBLIC | AUBIT_O_EDIT | AUBIT_O_BLANK);
	  A4GL_ll_set_field_opts (f, AUBIT_O_VISIBLE | AUBIT_O_PUBLIC | AUBIT_O_BLANK);
	}

    }

  A4GL_debug ("STATIC");


  //A4GL_LL_set_field_fore (f, A4GL_LL_colour_code (7));
  //A4GL_LL_set_field_back (f, A4GL_LL_colour_code (7));
  //A4GL_LL_set_max_field (f, A4GL_get_field_width_with_form (formdets,f),formdets);

}



//
// Called when SET PAUSE MODE ON/OFF is set
// and to check which is in effect (a==-1)
//
int
UILIB_A4GL_screen_mode (int a)
{
  return A4GL_LL_pause_mode (a);
}


void
UILIB_A4GL_ui_exit (int exit_status)
{
  A4GL_LL_ui_exit ();
}



void *
A4GL_ll_get_field_userptr (void *f)
{
  char buff[256];
  SPRINTF1 (buff, "PFLD_%p", f);
  if (A4GL_has_pointer (buff, USERPTR))
    {
      return A4GL_find_pointer (buff, USERPTR);
    }
  return 0;
}

void
A4GL_ll_set_field_userptr (void *f, void *r)
{
  char buff[256];
  SPRINTF1 (buff, "PFLD_%p", f);
  if (A4GL_has_pointer (buff, USERPTR))
    {
      A4GL_del_pointer (buff, USERPTR);
    }
  A4GL_add_pointer (buff, USERPTR, r);
  //return 0;
}


void *
A4GL_ll_get_form_userptr (void *f)
{
  char buff[256];
  SPRINTF1 (buff, "PFRM_%p", f);
  if (A4GL_has_pointer (buff, USERPTR))
    {
      return A4GL_find_pointer (buff, USERPTR);
    }
  return 0;
}

void
A4GL_ll_set_form_userptr (void *f, void *r)
{
  char buff[256];

  SPRINTF1 (buff, "PFRM_%p", f);
  if (A4GL_has_pointer (buff, USERPTR))
    {
      A4GL_del_pointer (buff, USERPTR);
    }
  A4GL_add_pointer (buff, USERPTR, r);
  //return 0;
}


void
A4GL_ll_set_field_opts (void *f, int l)
{
  char buff[30];
  int hadit = 0;
  int last = -1;
  //long a;

  A4GL_debug_print_opts(l);
  SPRINTF1 (buff, "%p", f);

  // has pointer won't work with 0 - so we'll use -9997 to mean 0... 
  if ((int)A4GL_has_pointer (buff, FIELDOPTS))
    {
      last = (long) A4GL_find_pointer (buff, FIELDOPTS);
      // has pointer won't work with 0 - so we'll use -9997 to mean 0... 
      if (last == -9997)
	{
	  last = 0;
	}
      hadit = 1;
    }
  else
    {
      // Lets make certain that 'last' and 'l' are different and force the set
      if (l == -1)
	{
	  last = -2;
	}
      else
	{
	  last = -1;
	}
    }


  if (last != l)
    {
      if (hadit)
	{
	  A4GL_del_pointer (buff, FIELDOPTS);
	}



      // has pointer won't work with 0 - so we'll use -9997 to mean 0... 
      A4GL_assertion (l < 0, "'l' can't be less than zero");

      A4GL_LL_set_field_opts (f, l);	// OK

/*
      if (a != l)
	{			// Failed...
	  A4GL_debug ("Failed - Wanted %d got %d", l, a);
	  l = a;
	}
*/

      if (l != 0)
	{
	  A4GL_debug ("Adding pointer to %d", l);
	  A4GL_add_pointer (buff, FIELDOPTS, (void *) ((long)l));
	}
      else
	{
	  A4GL_debug ("Adding pointer to -9997 because we cant store 0");
	  A4GL_add_pointer (buff, FIELDOPTS, (void *) ((long)-9997));
	}

      // We'll mark this as OK - so if we grep for A4GL_LL_set_field_opts - we'll know this is ok...
      // we should be using A4GL_ll_set_field_opts everywhere else so we'll hit this code...

    }
A4GL_debug_print_field_opts(f);
}






int
A4GL_ll_field_opts (void *f)
{
  int a;
  int curr;
  a = A4GL_ll_field_opts_i (f);

  if (strcmp (acl_getenv ("A4GL_UI"), "pipeclient") == 0)
    {
      return a;
    }


  curr = A4GL_LL_field_opts (f);

  if (a != curr)
    {
      A4GL_debug ("field_opt caching failed for %p - Cached =%d Actual=%d", f,
		  a, curr);
      A4GL_debug ("Cached:");
      A4GL_debug_print_opts (a);
      A4GL_debug ("Actual:");
      A4GL_debug_print_opts (A4GL_LL_field_opts (f));
      //A4GL_assertion (1, "fail");
      return curr;	// Caching has failed for some reason
    }
  return a;
}


int A4GL_ll_field_opts_i (void *f)
{
  char buff[30];

  // Lets cache our result - might save a round trip or two...
  //
  static int last = 0;
  static void *lastf = 0;

  if (f == lastf && 0)
    {
      A4GL_debug ("Last field! - %d", last);
      return last;
    }

  SPRINTF1 (buff, "%p", f);

  last = 0;
  lastf = f;

  if (A4GL_has_pointer (buff, FIELDOPTS))
    {
      last = (long) A4GL_find_pointer (buff, FIELDOPTS);
      if (last == -9997)
	{
	  last = 0;
	}
      A4GL_debug ("has pointer - %d", last);
      return last;
    }
  else
    {
      return 0;
      A4GL_assertion (1, "Cant find fieldopts");
    }


  A4GL_debug ("drop through %d", last);
  return last;

}


void
A4GL_debug_print_opts (long z)
{
  char str[2000] = "";
  if (z & AUBIT_O_VISIBLE)
    strcat (str, " O_VISIBLE");
  if (z & AUBIT_O_ACTIVE)
    strcat (str, " O_ACTIVE");
  if (z & AUBIT_O_PUBLIC)
    strcat (str, " O_PUBLIC");
  if (z & AUBIT_O_EDIT)
    strcat (str, " O_EDIT");
  if (z & AUBIT_O_WRAP)
    strcat (str, " O_WRAP");
  if (z & AUBIT_O_BLANK)
    strcat (str, " O_BLANK");
  if (z & AUBIT_O_AUTOSKIP)
    strcat (str, " O_AUTOSKIP");
  if (z & AUBIT_O_NULLOK)
    strcat (str, " O_NULLOK");
  if (z & AUBIT_O_STATIC)
    strcat (str, " O_STATIC");
  if (z & AUBIT_O_PASSOK)
    strcat (str, " O_PASSOK");
  A4GL_debug ("FIELD OPTS : %s (%x)", str, z);
  
}


char *
UILIB_A4GL_ui_fgl_winquestion (char *title, char *text, char *def, char *pos,
			       char *icon, int danger, int winbutton)
{
  return "nope";
}



void UILIB_A4GL_direct_to_ui(char *t,char *s) {
	A4GL_LL_direct_to_ui(t, s);
}



int UILIB_aclfgl_aclfgl_add_acs_mapping(int n) {
return 0;
}





void UILIB_A4GL_ensure_menu_option (int optno, void* menuv, char *txt, char *keys, char *desc, int helpno, int attr) {
  ACL_Menu_Opts *opt1;
  //ACL_Menu_Opts *opt2;
  ACL_Menu *menu;
  char opt_title[200];
  menu=menuv;
  opt1=menu->first;
  A4GL_assertion (menu->num_opts<optno,"Invalid option number");
  while (optno) {
		opt1=opt1->next_option;
		optno--;
  }

  if (opt1->help_no!=helpno) {
		A4GL_debug("Changed helpno");
		opt1->help_no=helpno;
  }


  memset(opt_title,0,sizeof(opt_title));
  if (strlen (txt))
    {
  	char op1[256];
  memset(op1,0,256);
      strcpy (opt_title, " ");
      strcpy (op1, txt);
      A4GL_trim (op1);
        if (strlen(op1)>77) op1[77]=0;
      strcat (opt_title, op1);
      strcat (opt_title, " ");
    }
  else
    {
      strcpy (opt_title, "");
    }

   if (strcmp(opt_title, opt1->opt_title)!=0) {
		A4GL_debug("Title changed");
		strcpy(opt1->opt_title,opt_title);	
		opt1->optlength = strlen (opt1->opt_title);
   }


  if (opt1->optlength == 0) {
                attr |= ACL_MN_HIDE;
  }

  if (opt1->attributes!=attr) {
                A4GL_debug("Changed attributes");
		// Dont change the attributes - it will mess up the option hiding
  		//opt1->attributes=attr;
  }

  if (strcmp(opt1->shorthelp,desc)!=0) {
	A4GL_debug("shorthelp changed");
  	strncpy (opt1->shorthelp, desc,80);
  	opt1->shorthelp[79]=0;
  }
  if (strcmp(opt1->optkey,keys)!=0) {
  	strcpy (opt1->optkey, keys);
  }


}

