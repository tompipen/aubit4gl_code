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
# $Id: console.c,v 1.4 2003-04-23 16:37:22 mikeaubury Exp $
#*/

/**
 * @file
 *
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#ifdef OLD_INCL

	#include <unistd.h> 			/* sleep() */

	#include "a4gl_dbform.h"
	#include "a4gl_aubit_lib.h"
	#include "a4gl_runtime_tui.h"   /* puch_char() */
	#include "a4gl_debug.h"

#else

    #include "a4gl_lib_ui_console_int.h"

#endif



/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void menu_attrib (ACL_Menu * menu, int attr, va_list ap);

void A4GL_ui_init(int argc,char *argv[]);
//void aclfgli_pr_message (int attr,int wait);
//void display_error (int a,int wait);
ACL_Menu * new_menu_create(char *title, int x, int y, int mn_type, int help_no);
void add_menu_option(ACL_Menu *menu,char *txt,char *keys,char *desc,int help_no,int attr);
void finish_create_menu(ACL_Menu *menu);
char * disp_h_menu(ACL_Menu *menu);
void redisplay_menu(ACL_Menu *menu);
int menu_loop (ACL_Menu * menu);
void free_menu (ACL_Menu * menu);
//void sleep_i(void);
void menu_hide (ACL_Menu * menu,va_list *ap);
void menu_show (ACL_Menu * menu,va_list *ap);
//void start_prompt (struct s_prompt *prompt, int ap, int c, int h,int af);
//void prompt_loop(struct s_prompt * prompt);

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
A4GLUI_ui_init (int argc,char *argv[])
{

    return;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_ui_init(int argc,char *argv[])
{

}

/**
 *
 * @todo Describe function
 */
void
aclfgli_pr_message (int attr,int wait)
{
char *s;
	s=char_pop();
	trim(s);
	printf("%s\n",s);
	free(s);
}

/**
 *
 * @todo Describe function
 */
void
display_error (int a,int wait)
{
char *s;
	s=char_pop();
	trim(s);
	printf("%s\n",s);
	free(s);

}

/**
 *
 * @todo Describe function
 */
void
display_at (int n, int a)
{
int x;
int y;
int z;
char *s=0;
char *ptr = 0;
char *buff=0;

debug("In display : ");
debug_print_stack();
x=pop_int();
y=pop_int();
debug("Popped X & Y");
s=malloc(2);
s[0]=0;



  for (z = 0; z <= n - 1; z++)
    {
  	debug("POP %d of %d",z,n-1);
        ptr=char_pop();
        debug("DISPLAY_AT : '%s'\n",ptr);
        buff=realloc(buff,strlen(s)+strlen(ptr)+1);
        s=realloc(s,strlen(s)+strlen(ptr)+1);
        sprintf(buff,"%s%s",ptr,s);
        strcpy(s,buff);
        debug("s='%s' %p\n",s,s);
    }
    printf("%s\n",s);
    free(ptr);
    free(s);
    free(buff);
}


/**
 * 4GL CALL
 * @todo Describe function
 */
ACL_Menu *
new_menu_create(char *title, int x, int y, int mn_type, int help_no)
{
char buff[256];
ACL_Menu *menu;
  
  strcpy(buff,title);
  trim(buff);
  menu = nalloc (ACL_Menu);
  strcpy (menu->menu_title,buff);
  trim (menu->menu_title);
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
  return menu;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
add_menu_option(ACL_Menu *menu,char *txt,char *keys,char *desc,int help_no,int attr)
{
  ACL_Menu_Opts *opt1;
  ACL_Menu_Opts *opt2;
  char op1[256];
  int nopts;
  opt1 = nalloc (ACL_Menu_Opts);

  opt1->next_option=0;
  opt1->prev_option=0;
  menu->num_opts++;

  debug("In add menu option : %s\n",txt);

  if (menu->first==0) {
        debug("Setting first..\n");
        menu->first=opt1;
        menu->last=opt1;
  }


  nopts=menu->num_opts;
  opt2=menu->last;
  opt1->opt_no = nopts-1;
  if (opt1!=opt2) {
          opt2->next_option = opt1;
        opt1->prev_option = opt2;
  }

  debug("menu->first=%p opt1=%p opt2=%p ",menu->first,opt1,opt2);
  debug("opt1 : prev=%p next=%p",opt1->prev_option,opt1->next_option);
  debug("opt2 : prev=%p next=%p",opt2->prev_option,opt2->next_option);

  if (strlen(txt)) {
      strcpy (opt1->opt_title, " ");
      strcpy (op1, txt);
      trim (op1);
      strcat (opt1->opt_title, op1);
      strcat (opt1->opt_title, " ");
  } else {
      strcpy (opt1->opt_title, "");
  }

  opt1->optlength = strlen (opt1->opt_title);
  strcpy (opt1->optkey, keys);
  strcpy (opt1->shorthelp, desc);
  opt1->help_no = help_no;
  opt1->attributes = attr;
  if (opt1->optlength==0) opt1->attributes|=ACL_MN_HIDE;
  menu->last = (ACL_Menu_Opts *) opt1;
  menu->num_opts = nopts;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
finish_create_menu(ACL_Menu *menu)
{
  (ACL_Menu_Opts *) menu->curr_option = (ACL_Menu_Opts *) menu->first;

  while (menu->curr_option->attributes&ACL_MN_HIDE) {
        if (menu->curr_option==menu->last) break;
        (ACL_Menu_Opts *) menu->curr_option = (ACL_Menu_Opts *) menu->curr_option->next_option;
  }

  return;
}



/**
 *
 * @todo Describe function
 */
char *
disp_h_menu(ACL_Menu *menu)
{
/* Does nothing */
return 0;
}


/**
 *
 * @todo Describe function
 */
void
redisplay_menu(ACL_Menu *menu)
{
ACL_Menu_Opts *opt1;
int cnt=1;


  if (strlen (menu->menu_title) > 0)
    {
	  printf("\n\n\n\n");
          printf ("%s\n\n", menu->menu_title);
    }

  opt1 = (ACL_Menu_Opts *) menu->first;

  while (opt1 != 0)
    {
      if ((opt1->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
        {
		if (strlen(opt1->shorthelp))
	  		printf("%d. %s (%s)\n",cnt,opt1->opt_title,opt1->shorthelp);
		else
	  		printf("%d. %s \n",cnt,opt1->opt_title);

		opt1->optpos=cnt;
		cnt++;

        } else {
		opt1->optpos=-1;
	}
          opt1 = (ACL_Menu_Opts *) opt1->next_option;
	
    }

}

/**
 *
 * @todo Describe function
 */
int
menu_loop (ACL_Menu * menu)
{
char buff[21];
int a;
int r;
ACL_Menu_Opts *opt1;

	redisplay_menu(menu);
	fgets(buff,20,stdin);
	a=atoi(buff);
	opt1 = (ACL_Menu_Opts *) menu->first;
	r=-1;
	while (opt1 != 0)
	    {
		if (opt1->optpos==a) {r=opt1->opt_no;break;}
	        opt1 = (ACL_Menu_Opts *) opt1->next_option;
	    }

	if (r!=-1)  return r;
	else {
		printf("Option out of range\n");
		return -1010;
	}
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
free_menu (ACL_Menu * menu)
{
  ACL_Menu_Opts *opt1, *opt2;
  opt1 = (ACL_Menu_Opts *) menu->first;
  while (opt1 != 0)
    {
      opt2 = (ACL_Menu_Opts *) opt1->next_option;
      free (opt1);
      opt1 = opt2;
    }
}

/**
 *
 * @todo Describe function
 */
void
sleep_i(void)
{
int a;
	a=pop_int();
	sleep(a);
}



/**
 *
 * @todo Describe function
 */
void
gotolinemode(void)
{
/* Does nothing - we are already in line mode when using UI=CONSOLE
but we need dummy finction to satisfy API_ui
*/
    debug ("in console gotolinemode...");
	return;
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
menu_hide (ACL_Menu * menu,va_list *ap)
{
  menu_attrib (menu, 0, *ap);
}

/**
 * 4GL CALL
 * @todo Describe function
 */
void
menu_show (ACL_Menu * menu,va_list *ap)
{
  menu_attrib (menu, 1, *ap);
}

/**
 *
 * @todo Describe function
 */
void
menu_attrib (ACL_Menu * menu, int attr, va_list ap)
{
int a;
ACL_Menu_Opts *option;
char *argp;
char s[256];
int flg;
  
  debug ("Menu attrib %d\n", attr);
  while ((argp = (va_arg (ap, char *))))
    {
      trim (argp);
      debug ("change attrib to %d of %s", attr, argp);
      option = (ACL_Menu_Opts *) menu->first;
      for (a = 0; a < menu->num_opts; a++)
        {
          debug ("before copy");
          strcpy (s, &option->opt_title[1]);
          debug ("after copy '%s' '%s'", s, option->opt_title);
          trim (s);
          debug ("trim %s", s);
          flg = 0;

          if (strcmp (argp, MENU_ALL) != 0)
            {
              debug ("Cmp '%s' to '%s'", s, argp);
              if (strcmp (s, argp) == 0)
                {
                  debug ("Cmpok\n");
                  flg = 1;
                }
              else
                {
                  debug ("Cmpbad\n");
                }
            }
          else
            flg = 1;

          if (flg == 1)
            {
              debug ("   FOund it : %s , %s (%x) %d", s, argp, option->attributes & ACL_MN_HIDE, attr);
              if (attr)
                {
		  debug("Turn On ?");
                  debug ("Attemp to turn on %d %d %d", option->attributes, ACL_MN_HIDE, option->attributes & ACL_MN_HIDE);
                  if (option->attributes & ACL_MN_HIDE)
                    {
                      debug ("Turn on");
                      option->attributes = option->attributes - ACL_MN_HIDE;
                    }
                }
              else
	        {
                  debug("Turn off ?");
                  if (!(option->attributes & ACL_MN_HIDE))
                    {
                      debug ("Turn off");
                      option->attributes = option->attributes + ACL_MN_HIDE;
                    }
                }
            }
          debug ("chk next");
          (ACL_Menu_Opts *) option = (ACL_Menu_Opts *) ((ACL_Menu_Opts *) (option))->next_option;
          debug ("set next");
        }
    }
  va_end (ap);
}


/**
 *
 * @todo Describe function
 */
int start_prompt (void *vprompt , int ap, int c, int h,int af)
{
char *promptstr;
int width;
struct s_prompt *prompt;
prompt=vprompt;

  promptstr = char_pop ();
  prompt->mode = 0;
  prompt->h=h;
  prompt->charmode=c;
  prompt->promptstr = promptstr;
  prompt->lastkey = 0;
  width -= strlen (promptstr);
  width--;
  A4GLSQL_set_status (0, 0);
  printf("%s",promptstr);
  fflush(stdout);
return 1;
}


/**
 *
 * @todo Describe function
 */
int
prompt_loop(void *vprompt)
{
  char buff[256];
  struct s_prompt * prompt;
prompt=vprompt;
  fgets(buff,256,stdin);
  prompt->mode =2;
  stripnl(buff);
  push_char(buff);
return 1;
}


/* ========================== EOF =============================== */
