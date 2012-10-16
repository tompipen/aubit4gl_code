#include "a4gl_lib_ui_tui_int.h"
#ifndef lint
	static char const module_id[] =
		"$Id: generic_ui.c,v 1.71 2012-10-16 06:51:44 mikeaubury Exp $";
#endif

static int A4GL_find_shown (ACL_Menu * menu, int chk, int dir);
static void A4GL_menu_attrib (ACL_Menu * menu, int attr, va_list *ap);


char *
A4GL_string_width (char *s)
{
  char buff[20];
  int a;
  static char buff2[10024];

  a = UILIB_A4GL_get_curr_width () ;
#ifdef DEBUG
  A4GL_debug("String width=%d",a);
#endif
  SPRINTF2 (buff, "%%-%d.%ds", a, a);
#ifdef DEBUG
  A4GL_debug("Buff=%s - s=%s",buff,s);
#endif
  SPRINTF1 (buff2, buff, s);
#ifdef DEBUG
  A4GL_debug("Buff2=%s",buff2);
#endif
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


  if (a==13) {
		a=A4GLKEY_ENTER;
  }
  opt1 = (ACL_Menu_Opts *) menu->curr_option;
#ifdef DEBUG
  A4GL_debug ("new_do_keys A=%d", a);
#endif

  fc= A4GL_find_char (menu, a);

  if (fc) {
      		//A4GL_display_menu (menu);
		return 1;
  }



  if (a == 8 || a==A4GLKEY_BACKSPACE || a == ' ' || a == A4GLKEY_DOWN || a == A4GLKEY_RIGHT || a == A4GLKEY_UP || a == A4GLKEY_LEFT || a == 0xffff /* click */ ) // BACKSPACE ?
    {
      A4GL_move_bar (menu, a);
      if (a == 0xffff)
        return 1;
      return 0;
    }

  if (a == A4GLKEY_ESCAPE)
    {
#ifdef DEBUG
      A4GL_debug ("Escape!");
#endif
      abort_pressed = 1;
      return 0;
    }

  if (a == A4GLKEY_ENTER)
    {
#ifdef DEBUG
      A4GL_debug ("CR..");
#endif
      return 1;
    }

#ifdef DEBUG
    A4GL_debug ("Dropped through");
#endif

    if (A4GL_isyes(acl_getenv("BEEP_BADMENUKEY"))) {
  	 beep();
    }

    if (A4GL_isyes(acl_getenv("FLASH_BADMENUKEY"))) {
  	flash();
    }

  return fc;
}




static ACL_Menu_Opts *show_menu_large(ACL_Menu *menu, int key) {
char buff[256];
char disp[1024];
int a;
int cnt;
int cw;
ACL_Menu_Opts *uniq;
buff[0]=key;
buff[1]=0;

	while (1) {
		int l;
		memset(disp,' ',sizeof(disp));
		cw=UILIB_A4GL_get_curr_width();

		// Clear the line first...
		disp[cw]=0;
		A4GL_mja_gotoxy (1, 2 + menu->menu_line);
		A4GL_tui_printr (0,"%s", disp);
		
		SPRINTF1(disp,"Select: %s",buff);
		l=strlen(disp);
		cw-=l;
		A4GL_mja_gotoxy (3+l, 2 + menu->menu_line);
		A4GL_tui_printr (0,"%s", A4GL_show_menu_large_get_matches(menu, buff, cw, &cnt,0));
		A4GL_assertion(cnt==0,"cnt should not be zero at this point");
		A4GL_mja_gotoxy (1, 2 + menu->menu_line);
		A4GL_tui_printr (1,"%s", disp);
		a=0;
		while (a==0)  {
			a=A4GL_getch_win();
		}

		if (a_isprint(a)) {
			char b[2];
			b[0]=a;
			b[1]=0;
			strcat(buff,b);
			A4GL_show_menu_large_get_matches(menu, buff,cw, &cnt,&uniq);
			
#ifdef DEBUG
			A4GL_debug("got %d matches", cnt);
#endif
			if (cnt==0) { // bad character...
				A4GL_dobeep();
				l=strlen(buff);
				buff[l-1]=0;
			}
			if (cnt==1) { // Now its unique!
				return uniq;
			}
			continue;
		}

		if (a==A4GLKEY_LEFT) {
			int l;
			l=strlen(buff);
			if (l>1) {
				buff[l-1]=0;
			}
			
#ifdef DEBUG
			A4GL_debug("menu_large - LEFT (%s)", buff);
#endif
			continue;
		}

		if (a==A4GLKEY_ENTER) {
			return menu->curr_option;
		}
	}
}


int
A4GL_find_char (ACL_Menu * menu, int key)
{
  ACL_Menu_Opts *opt1, *opt2;
  int flg = 0;
  opt2 = (ACL_Menu_Opts *) menu->curr_option;

#ifdef DEBUG
  A4GL_debug ("ZZ : key = %d opt2->optkey=%s\n", key, opt2->optkey);
#endif

  if (!opt2->attributes & ACL_MN_HIDE)	// Is it hidden ? 
    {
      // No - its not hidden...
      if (strcmp (opt2->optkey, "EMPTY") != 0)
	{
#ifdef DEBUG
	  A4GL_debug ("defined keys only");
#endif
	  flg = A4GL_check_keys (key, opt2->optkey);
	}
      else
	{
#ifdef DEBUG
	  A4GL_debug ("default key only");
#endif
	  if (A4GL_is_unique_menu_key (menu, key)==1)
	    {
	      flg = A4GL_check_key (key, &opt2->opt_title[1], 1);
	    }
	}
    }
  else
    {
      // It is hidden - but it might be a command key(..)
      if (strlen (opt2->opt_title) == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("defined keys only");
#endif
	  flg = A4GL_check_keys (key, opt2->optkey);
	}
    }

  if (flg)
    {
      menu->curr_option = (ACL_Menu_Opts *) opt2;
	  	menu->curr_page =menu->curr_option->page;
      A4GL_display_menu (menu);
#ifdef DEBUG
      A4GL_debug ("We're on it!");
#endif
      return 1;
    }


  if (A4GL_is_unique_menu_key (menu, key)>1) {
		void *p;
		p=show_menu_large(menu, key);
		if (p) {
			menu->curr_option=p;
  			menu->curr_page =menu->curr_option->page;
      			A4GL_display_menu (menu);
			return 1;
		}
		return 0;
  } else {
#ifdef DEBUG
      A4GL_debug ("Checking next option...");
#endif
      opt1 = (ACL_Menu_Opts *) opt2->next_option;

      if (opt1 == 0)
	opt1 = (ACL_Menu_Opts *) menu->first;

      while (opt2 != opt1)
	{
#ifdef DEBUG
	  A4GL_debug ("ZZ2 : key = %d opt1->optkey=%s\n", key, opt1->optkey);
#endif

	  flg = 0;

	  if (!opt1->attributes & ACL_MN_HIDE)
	    {
	      if (strcmp (opt1->optkey, "EMPTY"))
		{
#ifdef DEBUG
		  A4GL_debug ("defined keys only");
#endif
		  flg = A4GL_check_keys (key, opt1->optkey);
		}
	      else
		{
#ifdef DEBUG
		  A4GL_debug ("default key only");
#endif
		  flg = A4GL_check_key (key, &opt1->opt_title[1], 1);
		}
	    }
	  else
	    {
	      if (strlen (opt1->opt_title) == 0)
		{
#ifdef DEBUG
		  A4GL_debug ("defined keys only");
#endif
		  flg = A4GL_check_keys (key, opt1->optkey);
		}

	    }

	  if (flg)
	    {
	      menu->curr_option = (ACL_Menu_Opts *) opt1;
	  	menu->curr_page =menu->curr_option->page;
      A4GL_display_menu (menu);
	      return 1;
	    }

	  opt1 = (ACL_Menu_Opts *) opt1->next_option;

	  if (opt1 == 0)
	    opt1 = (ACL_Menu_Opts *) menu->first;
	}
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

#ifdef DEBUG
  A4GL_debug ("In movebar curropt=%p", menu->curr_option);
#endif
#ifdef OLDCODE
  if (a == 0xffff)
    {
#ifdef DEBUG
      A4GL_debug ("Decoding new option");
#endif
      z = A4GL_decode_clicked ();
#ifdef DEBUG
      A4GL_debug ("Got z as %p", z);
#endif

      if (z)
	{
#ifdef DEBUG
	  A4GL_debug ("Setting curropt to z");
#endif
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
#ifdef DEBUG
	  A4GL_debug ("Left key");
#endif
	  opt2 = (ACL_Menu_Opts *) opt2->prev_option;
	  if (opt2 == 0)
	    {
#ifdef DEBUG
	      A4GL_debug ("Move to last");
#endif
	      opt2 = (ACL_Menu_Opts *) menu->last;
	    }
	  menu->curr_option = ((ACL_Menu_Opts *) opt2);
	  dir = -1;
	}

      if (a == ' ' || a == A4GLKEY_DOWN || a == A4GLKEY_RIGHT)
	{
#ifdef DEBUG
	  A4GL_debug ("Right Key");
#endif
	  opt2 = (ACL_Menu_Opts *) opt2->next_option;
	  if (opt2 == 0)
	    {
#ifdef DEBUG
	      A4GL_debug ("Move to first");
#endif
	      opt2 = (ACL_Menu_Opts *) menu->first;
	    }
	  menu->curr_option = ((ACL_Menu_Opts *) opt2);
	  dir = 1;
	}
#ifdef DEBUG
      A4GL_debug ("Calling find_down - dir = %d", dir);
#endif
      A4GL_find_shown (menu, 0, dir);
#ifdef OLDCODE
    }
#endif
  opt1 = (ACL_Menu_Opts *) menu->curr_option;
  npage = opt1->page;

  if (npage != opage)
    {
#ifdef DEBUG
      A4GL_debug ("Page Changed on menu");
#endif
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
  ACL_Menu_Opts *option;
  ACL_Menu_Opts *old_option;
  char s[256];
  ACL_Menu *menu;
  int matches=0;
  menu = vmenu;

  menu->explicitFirstOption=1;
  A4GL_h_disp_opt (menu, menu->curr_option, menu->menu_offset, menu->mn_offset,
              NORM);
  A4GL_trim (nextopt);
  old_option = (ACL_Menu_Opts *) menu->curr_option;
  option = (ACL_Menu_Opts *) menu->first;
  for (a = 0; a < menu->num_opts; a++)
    {
      strcpy (s, &option->opt_title[1]);
      A4GL_trim (s);

#ifdef DEBUG
      A4GL_debug ("Testing '%s' = '%s'", s, nextopt);
#endif

      if (A4GL_menu_opts_compare (s, nextopt,MENU_COMPARE_NEXT_OPTION) == 0)
        {
          f = 1;
	  matches++;
          menu->curr_option = option;
	  	menu->curr_page =option->page;
      A4GL_display_menu (menu);
          break;
        }
      option =
        (ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
    }

  if (f == 0)
    {
      option = old_option;
#ifdef DEBUG
      A4GL_debug ("Menu Option %s not found", nextopt);
#endif
    }

  if (matches==0) { A4GL_exitwith("The NEXT OPTION name is not in the menu"); }

  A4GL_display_menu (menu);
}


int
 UILIB_A4GL_menu_hide_ap (void * menuv, va_list * ap)
{
 ACL_Menu *menu;
  menu=menuv;
#ifdef DEBUG
  A4GL_debug ("Menu hide\n");
#endif
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
#ifdef DEBUG
  A4GL_debug ("Show");
#endif
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
#ifdef DEBUG
  A4GL_debug ("Menu attrib %d\n", attr);
#endif
  while ((argp = va_arg (*ap, char *)))
    {
	char buff[3000];
	strcpy(buff,argp);
      A4GL_trim (buff);
#ifdef DEBUG
      A4GL_debug ("change attrib to %d of %s", attr, buff);
#endif
      option = (ACL_Menu_Opts *) menu->first;
      matches=0;
      for (a = 0; a < menu->num_opts; a++)
        {
#ifdef DEBUG
          A4GL_debug ("before copy");
#endif
          //strcpy (s, &option->opt_title[1]);

          if (option->opt_title && strlen(option->opt_title)) {
                strcpy (s, &option->opt_title[1]);
          }  else {
                        option = (ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
                        continue;
          }


#ifdef DEBUG
          A4GL_debug ("after copy '%s' '%s'", s, option->opt_title);
#endif
          A4GL_trim (s);
#ifdef DEBUG
          A4GL_debug ("trim %s", s);
#endif
          flg = 0;

          if (strcmp (buff, MENU_ALL) != 0)
            {
#ifdef DEBUG
              A4GL_debug ("Cmp '%s' to '%s'", s, buff);
#endif
              if (A4GL_menu_opts_compare (s, buff,MENU_COMPARE_SHOWHIDE) == 0)
                {
#ifdef DEBUG
                  A4GL_debug ("Cmpok\n");
#endif
                  flg = 1;
                }
              else
                {
#ifdef DEBUG
                  A4GL_debug ("Cmpbad\n");
#endif
                }
            }
          else
            flg = 1;

          if (flg == 1)
            {
		    matches++;
#ifdef DEBUG
              A4GL_debug ("   FOund it : %s , %s (%x) %d", s, buff,
                     option->attributes & ACL_MN_HIDE, attr);
#endif
              if (attr)
                {
#ifdef DEBUG
                  A4GL_debug ("Attemp to turn on %d %d %d", option->attributes,
                         ACL_MN_HIDE, option->attributes & ACL_MN_HIDE);
#endif
                  if (option->attributes & ACL_MN_HIDE && option->optlength)
                    {
#ifdef DEBUG
                      A4GL_debug ("Turn on");
#endif
                      option->attributes = option->attributes - ACL_MN_HIDE;
                    }
                }
              else
                {
                  if (!(option->attributes & ACL_MN_HIDE))
                    {
#ifdef DEBUG
                      A4GL_debug ("Turn off");
#endif
                      option->attributes = option->attributes + ACL_MN_HIDE;
                    }
                }
            }
#ifdef DEBUG
          A4GL_debug ("chk next");
#endif
          option =
            (ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
#ifdef DEBUG
          A4GL_debug ("set next");
#endif
        }


      	if (matches==0) {
		// Informix doesn't seem to mind - so we'll need a switch
		// to force an error...
		if (A4GL_env_option_set("ERRBADOPTION")) {
			A4GL_exitwith("Menu option not found");
		}
	}
    }
#ifdef DEBUG
  A4GL_debug ("f1");
#endif
  A4GL_find_shown (menu, 0, 1);
#ifdef DEBUG
  A4GL_debug ("f2");
#endif
  A4GL_size_menu (menu);                /* MJA 10/5/2000 */
  A4GL_display_menu (menu);
#ifdef DEBUG
  A4GL_debug ("f4");
#endif

#if ! defined (__CYGWIN__)
  //On CygWin: generic_ui.c:469: error: incompatible type for argument 1 of `__builtin_va_end'
  va_end (*ap);
#else
#ifdef DEBUG
  A4GL_debug ("*******************************");
  A4GL_debug ("FIXME: va_end problem on CygWin");
  A4GL_debug ("*******************************");
#endif
#endif

}

static int
A4GL_find_shown (ACL_Menu * menu, int chk, int dir)
{
  ACL_Menu_Opts *opt;
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *lastopt;
#ifdef DEBUG
  A4GL_debug ("In find_shown");
#endif

  opt = (ACL_Menu_Opts *) menu->curr_option;

  lastopt = (ACL_Menu_Opts *) menu->curr_option;

#ifdef DEBUG
  A4GL_debug ("current item = (%s) %d", menu->curr_option->opt_title,
         ((((ACL_Menu_Opts *) (menu->curr_option))->
           attributes) & ACL_MN_HIDE));
#endif

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



#ifdef DEBUG
      A4GL_debug ("A5  ");
      A4GL_debug ("A5a %p", ((ACL_Menu_Opts *) menu));
      A4GL_debug ("A5b %p %p", (ACL_Menu_Opts *) menu->curr_option,
             (ACL_Menu_Opts *) lastopt);
#endif

      if (((ACL_Menu_Opts *) menu->curr_option == (ACL_Menu_Opts *) lastopt))
        {
          if (chk)
            {
#ifdef DEBUG
              A4GL_debug ("A6");
#endif
              A4GL_exitwith ("No current option");
              return 1;
              break;
            }
          else
            {
#ifdef DEBUG
              A4GL_debug ("Return!");
#endif
              return 1;
            }
        }
#ifdef DEBUG
      A4GL_debug ("A5c");
#endif
    }
#ifdef DEBUG
  A4GL_debug ("A7");
#endif


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
 A4GL_debug ("Processing %s", opt1->opt_title);
      }
#endif
      if ((opt1->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
        {
#ifdef DEBUG
          A4GL_debug (" Show %s\n", opt1->opt_title);
#endif
        }
      else
        {
#ifdef DEBUG
          A4GL_debug (" HIdden %s\n", opt1->opt_title);
#endif
        }
      if ((opt1->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
        {
#ifdef DEBUG
          {
            A4GL_debug ("is shown %s", opt1->opt_title);
          }
#endif
          s_length = strlen (opt1->opt_title);
#ifdef DEBUG
          A4GL_debug ("GREPME disp=%d width=%d %d %s .. %d > %d ", disp_cnt2, menu->w, menu->menu_offset, opt1->opt_title,disp_cnt2 + menu->menu_offset + s_length  , menu->w);
#endif



	  something_else_printable=0;
	  s_off=0;

          if ((disp_cnt2 + menu->menu_offset + s_length  + 5) > menu->w) { 
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
 UILIB_A4GL_new_menu_create_with_attr (char *title, int x, int y, int mn_type, int help_no,char *mn_comment, char*mn_style, char *mn_image,char *mn_normal, char* mn_highlight)
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
  menu->mnstyle=mn_style;
  menu->mncomment=mn_comment;
  menu->mnimage=mn_image;
  menu->mnnormal=mn_normal;
  menu->mnhighlight=mn_highlight;
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
#ifdef DEBUG
  A4GL_debug ("MJAMJA helpno=%d", helpno);
#endif

  opt1->next_option = 0;
  opt1->page = 0;
  opt1->prev_option = 0;
  menu->num_opts++;

#ifdef DEBUG
  A4GL_debug ("In add menu option : %s\n", txt);
#endif

#ifdef DEBUG
  A4GL_debug ("MJAMJA helpno=%d", helpno);
#endif
  if (menu->first == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Setting first..\n");
#endif
      menu->first = opt1;
      menu->last = opt1;
    }


  nopts = menu->num_opts;
  opt2 = menu->last;
  opt1->opt_no = nopts - 1;
#ifdef DEBUG
  A4GL_debug ("MJAMJA helpno=%d", helpno);
#endif
  if (opt1 != opt2)
    {
      opt2->next_option = opt1;
      opt1->prev_option = opt2;
    }

#ifdef DEBUG
  A4GL_debug ("menu->first=%p opt1=%p opt2=%p ", menu->first, opt1, opt2);
  A4GL_debug ("opt1 : prev=%p next=%p", opt1->prev_option, opt1->next_option);
  A4GL_debug ("opt2 : prev=%p next=%p", opt2->prev_option, opt2->next_option);
  
  A4GL_debug ("MJAMJA helpno=%d", helpno);
#endif
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

#ifdef DEBUG
  A4GL_debug ("MJAMJA helpno=%d", helpno);
#endif
  opt1->optlength = strlen (opt1->opt_title);
#ifdef DEBUG
  A4GL_debug ("MJAMJA helpno=%d", helpno);
#endif
  strcpy (opt1->optkey, keys);
#ifdef DEBUG
  A4GL_debug ("MJAMJA helpno=%d", helpno);
#endif
  strncpy (opt1->shorthelp, desc,80);
  opt1->shorthelp[79]=0;

#ifdef DEBUG
  A4GL_debug ("MJA setting opt1->help_no = %d", helpno);
#endif
  opt1->help_no = helpno;
  opt1->attributes = attr;
  if (opt1->optlength == 0)
    opt1->attributes |= ACL_MN_HIDE;
  menu->last = (ACL_Menu_Opts *) opt1;
  menu->num_opts = nopts;
#ifdef DEBUG
  A4GL_debug ("MJA opt1->help_no = %d", opt1->help_no);
#endif
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
#ifdef DEBUG
		A4GL_debug("Changed helpno");
#endif
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
#ifdef DEBUG
		A4GL_debug("Title changed");
#endif
		strcpy(opt1->opt_title,opt_title);	
		opt1->optlength = strlen (opt1->opt_title);
   }
  if (opt1->optlength == 0) {
		attr |= ACL_MN_HIDE;
  }

  if (opt1->attributes!=attr) {

#ifdef DEBUG
                A4GL_debug("Changed attributes");
#endif
		// Dont change the attributes - it will mess up the option hiding
  		//opt1->attributes=attr;
  }
  if (strcmp(opt1->shorthelp,desc)!=0) {
#ifdef DEBUG
	A4GL_debug("shorthelp changed");
#endif
  	strncpy (opt1->shorthelp, desc,80);
  	opt1->shorthelp[79]=0;
  }
  if (strcmp(opt1->optkey,keys)!=0) {
  	strcpy (opt1->optkey, keys);
  }


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


  menu->explicitFirstOption=0;

#ifdef DEBUG
  A4GL_debug ("Current option=%p", menu->curr_option);
  A4GL_debug ("Current option help=%d", menu->curr_option->help_no);
#endif
  return;
}


void UILIB_A4GL_add_menu_timeout(void *vmenu,char timeout_type,int timeout_len,int cmd_on_timeout,long *timeoutvar) {
		ACL_Menu *menu;
		menu=vmenu;
		menu->nevt++;
		menu->evt=realloc(menu->evt,sizeof(struct aclfgl_event_list)*(menu->nevt+1));


		 menu->evt[menu->nevt-1].event_type=-1;
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
		menu->evt[menu->nevt-1].event_type=-1; 

		menu->evt[menu->nevt].event_type=0; // We deliberatly made the evt record 1 more than nevt - so this should be ok
			//if (menu->nevt==1) {
				//menu->evt[0].event_type=0;
			//}
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
#ifdef DEBUG
  A4GL_debug (" Menu title : '%s'", title);
#endif
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
#ifdef DEBUG
  A4GL_debug ("Menu=%p &Menu=%p", menu, &menu);
#endif
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
#ifdef DEBUG
      A4GL_debug ("argp_c = %s\n", argp_c);
#endif
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
#ifdef DEBUG
      A4GL_debug ("Help number for %s = %d", opt1->opt_title, argp_i);
#endif

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

void UILIB_A4GL_ui_exit(int exitstatus) {
        // Does nothing - required by the API
	  if (A4GL_isscrmode ())
		      {
#ifdef DEBUG
			            A4GL_debug ("In screen mode - ending curses...");
#endif
				          UILIB_A4GL_gotolinemode ();
					      }

}


int UILIB_aclfgl_aclfgl_add_to_toolbar (int n) {
	// does nothing for this UI client...
	return 0;
}

void UILIB_A4GL_ui_cancel(int type){
	A4GL_assertion(1,"CANCEL INSERT/CANCEL DELETE not implemented for this UI");
	// does nothing for this UI 
}

void UILIB_A4GL_ui_frontcall(char* module,char* name,void* vibind,int ni,void* vobind,int no) {
struct BINDING *ibind;
struct BINDING *obind;
//char buff[100000];
//char smbuff[20000];
obind=vobind;
ibind=vibind;
	if (strcmp(module,"INTERNAL")==0 && strcmp(name,"ui.curses.fgl_setsize")==0 ) {
			int w;
			int h;
		if (ni==2) {
			// fgl_setsize(h,w);
                	A4GL_push_param (ibind[0].ptr, ibind[0].dtype + ENCODE_SIZE (ibind[0].size));
                	h=A4GL_pop_long();
                	A4GL_push_param (ibind[1].ptr, ibind[1].dtype + ENCODE_SIZE (ibind[1].size));
                	w=A4GL_pop_long();
			// Control codes to resize the screen
			printf("\x1b[8;%d;%dt", h, w); fflush(stdout);
			resize_screen_window(w,h);


			//windows[0].w=w;
			//windows[0].h=h;
			//wresize(windows[0].win,h,w);
			//A4GL_pause_execution();

		}  else {
			A4GL_set_status(-3002,0);
		}
	}

	if (strcmp(module,"INTERNAL")==0 && strcmp(name,"ui.curses.getkey")==0 ) {
		int a=0;
		while (a==0) {
			a=A4GL_get_key_no_transform(-1);
		}
		A4GL_push_int(a);
		A4GL_pop_param(obind[0].ptr, obind[0].dtype , obind[0].size);
	}
	if (strcmp(module,"INTERNAL")==0 && strcmp(name,"ui.curses.setovr")==0 ) {
		struct s_form_dets *s;
		s=UILIB_A4GL_get_curr_form(0);
		if (s) {
			A4GL_int_form_driver (s->form, REQ_OVL_MODE);
		}
	}
	if (strcmp(module,"INTERNAL")==0 && strcmp(name,"ui.curses.setins")==0 ) {
		struct s_form_dets *s;
		s=UILIB_A4GL_get_curr_form(0);
		if (s) {
			A4GL_int_form_driver (s->form, REQ_INS_MODE);
		}
	}

	if (strcmp(module,"INTERNAL")==0 && strcmp(name,"ui.curses.define_key")==0 ) {
		if (ni==2) {
			char *keydef;
			int keycode;
                	A4GL_push_param (ibind[0].ptr, ibind[0].dtype + ENCODE_SIZE (ibind[0].size));
                	keydef=A4GL_char_pop();
                	A4GL_push_param (ibind[1].ptr, ibind[1].dtype + ENCODE_SIZE (ibind[1].size));
                	keycode=A4GL_pop_long();
			if (keycode) {
#ifdef NO_DEFINE_KEY
		A4GL_assertion(1,"No 'define_key' on windows...");
#else
				define_key(keydef,keycode);
#endif
				//printf("Keyname : %s Keycode %d\n", keydef, keycode);
			}
		}  else {
			A4GL_set_status(-3002,0);
		}
	}
}





int UILIB_A4GL_ui_send_report_to_ui(char *filename, int linesPerPage,char *mode) {
	return 0;
}
