#include "a4gl_lib_ui_tui_int.h"
#ifndef lint
	static char const module_id[] =
		"$Id: generic_ui.c,v 1.36 2006-11-16 13:03:40 mikeaubury Exp $";
#endif

static int A4GL_find_shown (ACL_Menu * menu, int chk, int dir);
static void A4GL_menu_attrib (ACL_Menu * menu, int attr, va_list *ap);


char *
A4GL_string_width (char *s)
{
  char buff[10];
  int a;
  static char buff2[10024];

  a = UILIB_A4GL_get_curr_width () - 2;
  A4GL_debug("String width=%d",a);
  sprintf (buff, "%%-%d.%ds", a, a);
  A4GL_debug("Buff=%s - s=%s",buff,s);
  sprintf (buff2, buff, s);
  A4GL_debug("Buff2=%s",buff2);
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


  if (a==13) {
		a=A4GLKEY_ENTER;
  }
  opt1 = (ACL_Menu_Opts *) menu->curr_option;
  A4GL_debug ("new_do_keys A=%d", a);

  fc= A4GL_find_char (menu, a);

  if (fc) return 1;



  if (a == 8 || a==A4GLKEY_BACKSPACE || a == ' ' || a == A4GLKEY_DOWN || a == A4GLKEY_RIGHT || a == A4GLKEY_UP || a == A4GLKEY_LEFT || a == 0xffff /* click */ ) // BACKSPACE ?
    {
      A4GL_move_bar (menu, a);
      if (a == 0xffff)
        return 1;
      return 0;
    }

  if (a == A4GLKEY_ESCAPE)
    {
      A4GL_debug ("Escape!");
      abort_pressed = 1;
      return 0;
    }

  if (a == A4GLKEY_ENTER)
    {
      A4GL_debug ("CR..");
      return 1;
    }

    A4GL_debug ("Dropped through");

    if (A4GL_isyes(acl_getenv("BEEP_BADMENUKEY"))) {
  	 beep();
    }

    if (A4GL_isyes(acl_getenv("FLASH_BADMENUKEY"))) {
  	flash();
    }

  return fc;
}

int
A4GL_find_char (ACL_Menu * menu, int key)
{
  ACL_Menu_Opts *opt1, *opt2;
  int flg = 0;
  opt2 = (ACL_Menu_Opts *) menu->curr_option;

  A4GL_debug ("ZZ : key = %d opt2->optkey=%s\n", key, opt2->optkey);


  if (!opt2->attributes & ACL_MN_HIDE) // Is it hidden ? 
    {				
	    // No - its not hidden...
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
    }
  else
    {
      // It is hidden - but it might be a command key(..)
	if (strlen (opt2->opt_title)==0)
	{
	  A4GL_debug ("defined keys only");
	  flg = A4GL_check_keys (key, opt2->optkey);
	}
    }

  if (flg)
    {
      menu->curr_option = (ACL_Menu_Opts *) opt2;
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

      flg = 0;

      if (!opt1->attributes & ACL_MN_HIDE)
	{
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
	} else {
	  if (strlen (opt1->opt_title)==0)
	    {
	      A4GL_debug ("defined keys only");
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
  return 0;
}



void
A4GL_move_bar (ACL_Menu * menu, int a)
{
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *opt2;
  int flg;
  int dir = 0;
  int opage, npage;
  opt1 = (ACL_Menu_Opts *) menu->curr_option;
  opage = opt1->page;
  flg = 0;
  opt2 = opt1;

  A4GL_debug ("In movebar curropt=%p", menu->curr_option);
#ifdef OLDCODE
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
#endif

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
#ifdef OLDCODE
    }
#endif
  opt1 = (ACL_Menu_Opts *) menu->curr_option;
  npage = opt1->page;

  if (npage != opage)
    {
      A4GL_debug ("Page Changed on menu");
      menu->curr_page = npage;
      A4GL_display_menu (menu);
    }
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
  int matches=0;
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

      if (A4GL_menu_opts_compare (s, nextopt,MENU_COMPARE_NEXT_OPTION) == 0)
        {
          f = 1;
	  matches++;
          menu->curr_option = option;
	  	menu->curr_page =option->page;
          break;
        }
      option =
        (ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
    }

  if (f == 0)
    {
      option = old_option;
      A4GL_debug ("Menu Option %s not found", nextopt);
    }

  if (matches==0) { A4GL_exitwith("The NEXT OPTION name is not in the menu"); }

  A4GL_display_menu (menu);
}


int
 UILIB_A4GL_menu_hide_ap (void * menuv, va_list * ap)
{
 ACL_Menu *menu;
  menu=menuv;
  A4GL_debug ("Menu hide\n");
  A4GL_menu_attrib (menu, 0, ap);
return 1;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int 
 UILIB_A4GL_menu_show_ap (void * menuv, va_list * ap)
{
 ACL_Menu *menu;
  menu=menuv;
  A4GL_debug ("Show");
  A4GL_menu_attrib (menu, 1, ap);
  A4GL_find_shown (menu, 0, 1);
return 1;
}


static void A4GL_menu_attrib (ACL_Menu * menu, int attr, va_list *ap)
{
  int a;
  ACL_Menu_Opts *option;
  char *argp;
  char s[256];
  int flg;
  int matches;
  A4GL_debug ("Menu attrib %d\n", attr);
  while ((argp = va_arg (*ap, char *)))
    {
      A4GL_trim (argp);
      A4GL_debug ("change attrib to %d of %s", attr, argp);
      option = (ACL_Menu_Opts *) menu->first;
      matches=0;
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
              if (A4GL_menu_opts_compare (s, argp,MENU_COMPARE_SHOWHIDE) == 0)
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
                  A4GL_debug ("Attemp to turn on %d %d %d", option->attributes,
                         ACL_MN_HIDE, option->attributes & ACL_MN_HIDE);
                  if (option->attributes & ACL_MN_HIDE && option->optlength)
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
          option =
            (ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
          A4GL_debug ("set next");
        }


      	if (matches==0) {
		// Informix doesn't seem to mind - so we'll need a switch
		// to force an error...
		if (A4GL_env_option_set("ERRBADOPTION")) {
			A4GL_exitwith("Menu option not found");
		}
	}
    }
  A4GL_debug ("f1");
  A4GL_find_shown (menu, 0, 1);
  A4GL_debug ("f2");
  A4GL_size_menu (menu);                /* MJA 10/5/2000 */
  A4GL_display_menu (menu);
  A4GL_debug ("f4");

#if ! defined (__CYGWIN__)
  //On CygWin: generic_ui.c:469: error: incompatible type for argument 1 of `__builtin_va_end'
  va_end (*ap);
#else
  A4GL_debug ("*******************************");
  A4GL_debug ("FIXME: va_end problem on CygWin");
  A4GL_debug ("*******************************");
#endif

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
               menu->curr_option =
                (ACL_Menu_Opts *) menu->first;
            }
        }
      else
        {
           menu->curr_option =
            (ACL_Menu_Opts *) (menu->curr_option)->prev_option;
          if (menu->curr_option == 0)
            {
               menu->curr_option =
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
              A4GL_debug ("Return!");
              return 1;
            }
        }
      A4GL_debug ("A5c");
    }
  A4GL_debug ("A7");


  return 0;
}


void
A4GL_size_menu (ACL_Menu * menu)
{
  ACL_Menu_Opts *opt1;
  int disp_cnt2 = 0;
  char disp_str[800];
  int disp_cnt;
  int s_length;
  int s_off;
  int page = 0;
  int something_else_printable;
  memset(disp_str,0,sizeof(disp_str));
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
          A4GL_debug ("GREPME disp=%d width=%d %d %s .. %d > %d ", disp_cnt2, menu->w, menu->menu_offset, opt1->opt_title,disp_cnt2 + menu->menu_offset + s_length  , menu->w);



	  something_else_printable=0;
	  s_off=0;
          if (disp_cnt2 + menu->menu_offset + s_length  + 4 > menu->w) { // was 5
  		ACL_Menu_Opts *po;
      		po = (ACL_Menu_Opts *) opt1->next_option;
		while(po!=0) {
      			if ((po->attributes & ACL_MN_HIDE) != ACL_MN_HIDE) {
				something_else_printable=1;
				break;
			}
			po=(ACL_Menu_Opts *)po->next_option;
		}
		if (something_else_printable) s_off=5;
	  }





// We need some space for the ellipses...
          if (disp_cnt2 + menu->menu_offset + s_length +s_off  > menu->w)
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



void *
 UILIB_A4GL_new_menu_create (char *title, int x, int y, int mn_type, int help_no)
{
  char buff[256];
  ACL_Menu *menu;
  A4GL_chkwin();
  strcpy (buff, title);
  A4GL_trim (buff);
  menu = nalloc (ACL_Menu);
  strcpy (menu->menu_title, buff);
  A4GL_trim (menu->menu_title);
  menu->menu_type = mn_type;
  menu->help_no = help_no;
  menu->curr_option = 0;
  strcpy(menu->parent_window_name, UILIB_A4GL_get_currwin_name());
  menu->x = x;
  menu->y = y;
  menu->curr_page = 0;
  menu->mn_offset = 0;
  menu->first = 0;
  menu->num_opts = 0;
  menu->evt=0;
  menu->nevt=0;
  menu->attrib=A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD,0, 0, 0);
  return (void *)menu;
}

void
 UILIB_A4GL_add_menu_option (void* menuv, char *txt, char *keys, char *desc,
                 int helpno, int attr)
{
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *opt2;
  ACL_Menu *menu;
  char op1[256];
  int nopts;
   menu=menuv;
  memset(op1,0,256);
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
  memset(opt1->opt_title,0,sizeof(opt1->opt_title));
  if (strlen (txt))
    {
      strcpy (opt1->opt_title, " ");
      strcpy (op1, txt);
      A4GL_trim (op1);
	if (strlen(op1)>77) op1[77]=0;
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
  strncpy (opt1->shorthelp, desc,80);
  opt1->shorthelp[79]=0;

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
 UILIB_A4GL_finish_create_menu (void* menuv)
{
 ACL_Menu *menu;

 menu=menuv;


 if (menu->curr_option) {
 	if (menu->curr_option->attributes & ACL_MN_HIDE) {
   		menu->curr_option = (ACL_Menu_Opts *) menu->first;
 	}
 } else {
   		menu->curr_option = (ACL_Menu_Opts *) menu->first;
 }

  while (menu->curr_option->attributes & ACL_MN_HIDE)
    {
      if (menu->curr_option == menu->last)
        break;
      menu->curr_option =
        (ACL_Menu_Opts *) menu->curr_option->next_option;
    }


 if (menu->evt) { A4GL_clr_evt_timeouts(menu->evt); }



  A4GL_debug ("Current option=%p", menu->curr_option);
  A4GL_debug ("Current option help=%d", menu->curr_option->help_no);
  return;
}


void UILIB_A4GL_add_menu_timeout(void *vmenu,char timeout_type,int timeout_len,int cmd_on_timeout,long *timeoutvar) {
		ACL_Menu *menu;
		menu=vmenu;
		menu->nevt++;
		menu->evt=realloc(menu->evt,sizeof(struct aclfgl_event_list)*(menu->nevt+1));


		if (timeout_type=='D') { menu->evt[menu->nevt-1].event_type=A4GL_EVENT_ON_IDLE;     }
		if (timeout_type=='V') { menu->evt[menu->nevt-1].event_type=A4GL_EVENT_ON_INTERVAL; }
		menu->evt[menu->nevt-1].block=cmd_on_timeout+1; // menu options are numbered from 0 - but event blocks are from 1...
		menu->evt[menu->nevt-1].keycode=timeout_len;
		menu->evt[menu->nevt-1].field=(void *)timeoutvar;


		menu->evt[menu->nevt].event_type=0; // We deliberatly made the evt record 1 more than nevt - so this should be ok
}



void UILIB_A4GL_add_menu_action(void *vmenu,char *action,int cmd_on_timeout) {
		ACL_Menu *menu;
		menu=vmenu;
		menu->nevt++;
		menu->evt=realloc(menu->evt,sizeof(struct aclfgl_event_list)*(menu->nevt+1));
		menu->evt[menu->nevt].event_type=0; // We deliberatly made the evt record 1 more than nevt - so this should be ok
}




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

  A4GL_chkwin();
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
  menu->x = x;
  menu->y = y;
  menu->curr_page = 0;
  menu->mn_offset = 0;
  menu->evt=0;
  opt1 = nalloc (ACL_Menu_Opts);
  menu->first = (ACL_Menu_Opts *) opt1;
  opt1->prev_option = 0;
  A4GL_debug ("Menu=%p &Menu=%p", menu, &menu);
  for (ret = 0; ret < nopts; ret++)
    {
      if (ret != 0)
        {
          opt2 = nalloc (ACL_Menu_Opts);
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
      menu->curr_option =
        (ACL_Menu_Opts *) menu->curr_option->next_option;
    }


  menu->num_opts = nopts;
  return menu;
}

char *UILIB_A4GL_ui_fgl_winquestion(char *title,char *text,char *def,char *pos,char *icon,int danger,int winbutton) {
	return "Nope";
}

void UILIB_A4GLUI_set_intr(void) {
	// Does nothing - required by the API - called if a program issues DEFER INTERRUPT
}

void UILIB_A4GL_ui_exit(void) {
        // Does nothing - required by the API
	  if (A4GL_isscrmode ())
		      {
#ifdef DEBUG
			            A4GL_debug ("In screen mode - ending curses...");
#endif
				          A4GL_gotolinemode ();
					      }

}



