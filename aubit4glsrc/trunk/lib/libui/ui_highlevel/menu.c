#include "a4gl_libaubit4gl.h"
#include "hl_proto.h"
#include "a4gl_lib_ui_int.h"
#include "a4gl_API_ui_lib.h"
#include "a4gl_API_lowlevel.h"
#include "lowlevel.h"
#include <ctype.h>


#ifndef lint
	static char const module_id[] =
		"$Id: menu.c,v 1.22 2005-06-14 22:05:30 mikeaubury Exp $";
#endif

static void A4GL_h_disp_more (ACL_Menu * menu, int offset, int y, int pos);
void A4GL_h_disp_title (ACL_Menu * menu, char *str);
//void A4GL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y, int type);
//void A4GL_clr_menu_disp (ACL_Menu * menu);
static int A4GL_menu_getkey (ACL_Menu * menu);
void A4GL_size_menu (ACL_Menu * menu);
void *A4GL_get_currwin (void);
int aclfgli_show_help(int n);
int A4GL_menu_loop_type_1(ACL_Menu *menu,int num_opts) ;


void
UILIB_A4GL_disp_h_menu (void *menuv)
{
  char disp_str[80];
  int disp_cnt;
  int disp_cnt2;
  int row;
  int cl, cpt, mnln, cw;
  //char *parent_window;
  long attrib = 0;

  ACL_Menu *menu;
  menu = menuv;


  /* Is the UI client going to do most of the work for us ? */
  if (A4GL_LL_menu_type()==1) {
	ACL_Menu_Opts *mo;
	int a;
	A4GL_LL_disp_h_menu(menu->num_opts);
	mo=menu->first;
	// Seems so...
	for (a=0;a<menu->num_opts;a++) {
		A4GL_LL_disp_h_menu_opt(a,menu->num_opts,mo->opt_title,mo->attributes);
		mo=mo->next_option;
	}
	A4GL_LL_screen_update();
	return;
  }

#ifdef DEBUG
  A4GL_debug ("Adding window for menu");
  A4GL_debug ("Current metrics : %d %d %d", A4GL_get_curr_left (),
	      A4GL_get_curr_print_top () - 1, UILIB_A4GL_get_curr_width ());
#endif
  mnln = A4GL_getmenu_line () ;
  if ( UILIB_A4GL_iscurrborder ()) mnln--;

  cl = A4GL_get_curr_left ();
  cw = UILIB_A4GL_get_curr_width ();
  menu->gw_b = UILIB_A4GL_iscurrborder ();
  cpt = A4GL_get_curr_print_top ();


  menu->gw_y = mnln + UILIB_A4GL_iscurrborder ();

  A4GL_debug ("Set menu->gw_y to %d", menu->gw_y);
  menu->gw_x = cl;


  attrib = attrib - (attrib & 0x20);

  menu->attrib = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, attrib, 0, 0);

  menu->w = cw;


  if ((attrib & 0xff) == 0)
    attrib = attrib + 32;	/* -(attrib&0xff); */

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
	  sprintf (disp_str, "%s:  ", menu->menu_title);
	  disp_cnt = strlen (disp_str) + 1;
	}
      else
	sprintf (disp_str, " %s ", menu->menu_title);
    }
  menu->menu_offset = disp_cnt;
#ifdef DEBUG
  A4GL_debug ("Menu line set to %d", A4GL_getmenu_line ());
#endif
  menu->menu_line = mnln;	// Shouldn't this be mnln - was 1
  abort_pressed = 0;
  A4GL_size_menu (menu);
  A4GL_display_menu (menu);
  /* zrefresh(); */
#ifdef DEBUG
  A4GL_debug ("completed disp_h_menu");
#endif
  /*set_window(owin); */
 if (menu->menu_offset>1000) {
	char *ptr=0;
	*ptr=0;
	}
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
  A4GL_LL_screen_update ();
  return 1;
}



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

  A4GL_debug ("In display_menu");
  if (menu->gw_x < 0)
    {
      //char *ptr = 0;
      //*ptr = 0;
    }
  A4GL_clr_menu_disp (menu);
  if (strlen (menu->menu_title) > 0)
    {
      if (menu->menu_type == ACL_MN_HORIZ_NOTBOXED)
	{
	  sprintf (disp_str, "%s: ", menu->menu_title);
	  disp_cnt = strlen (disp_str) + 1;
	}
      else
	sprintf (disp_str, " %s ", menu->menu_title);
    }

  A4GL_h_disp_title (menu, disp_str);


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
  if (menu->gw_x < 0)
    {
      //char *ptr = 0;
      //*ptr = 0;
    }

  A4GL_LL_screen_update ();
}

static void
A4GL_h_disp_more (ACL_Menu * menu, int offset, int y, int pos)
{
  A4GL_debug ("MORE MARKERS : Displaying ... at %d %d", pos + offset, 1);
  A4GL_chkwin();
  A4GL_wprintw ((void *)A4GL_get_currwin (), 0, pos + offset, menu->gw_y, UILIB_A4GL_get_curr_width(),UILIB_A4GL_get_curr_height(),UILIB_A4GL_iscurrborder (),A4GL_get_currwinno()," ...");

}


void
A4GL_h_disp_title (ACL_Menu * menu, char *str)
{
A4GL_LL_h_disp_title(menu,str,UILIB_A4GL_get_curr_width(),UILIB_A4GL_get_curr_height(),UILIB_A4GL_iscurrborder (),
A4GL_get_currwinno(),
A4GL_get_currwin(),
menu->gw_y

);
}


void
A4GL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y,
		 int type)
{
  int xx = 0;
  int yx = 0;
  //int col;
  A4GL_chkwin();
  A4GL_debug ("h_disp_opt");

  if (opt1->page != menu->curr_page)
    return;


  if ((opt1->attributes & ACL_MN_HIDE) != ACL_MN_HIDE)
    {



      A4GL_debug ("menu->gw_y=%d y=%d", menu->gw_y, y);

      if (offset > 2)
	{
	  xx = 1;
	  yx = menu->gw_y + y;
	}
      else
	{
	  xx = offset;
	  yx = menu->gw_y + y;
	}


      //A4GL_menu_setcolor (menu, NORMAL_MENU);

      A4GL_debug ("opt1->shorthelp = %s", opt1->shorthelp);


      A4GL_debug ("opt1->shorthelp = %s",
		  A4GL_string_width (opt1->shorthelp));


      if (type == INVERT)
	{
	  A4GL_debug ("xx=%d yx=%d", xx, yx);
	  A4GL_wprintw ((void *)A4GL_get_currwin (), 0, xx, yx + 1, UILIB_A4GL_get_curr_width(),UILIB_A4GL_get_curr_height(),UILIB_A4GL_iscurrborder (),A4GL_get_currwinno(),"%s",
			A4GL_string_width (opt1->shorthelp));
	}



      xx = opt1->optpos + offset;
      yx = 1;


      if (type == INVERT)
	A4GL_wprintw ((void *)A4GL_get_currwin (), AUBIT_ATTR_REVERSE, xx, menu->gw_y,UILIB_A4GL_get_curr_width(),UILIB_A4GL_get_curr_height(),
		      UILIB_A4GL_iscurrborder (),A4GL_get_currwinno(),"%s", opt1->opt_title);
      else
	A4GL_wprintw ((void *)A4GL_get_currwin (), 0, xx, menu->gw_y, UILIB_A4GL_get_curr_width(),UILIB_A4GL_get_curr_height(),UILIB_A4GL_iscurrborder (),A4GL_get_currwinno(),
			"%s", opt1->opt_title);



    }
#ifdef DEBUG
  {
    A4GL_debug ("Done");
  }
#endif
}


void A4GL_clr_menu_disp (ACL_Menu * menu)
{
//printf("clr_menu_disp\n");
A4GL_LL_clr_menu_disp (menu,UILIB_A4GL_get_curr_width(),UILIB_A4GL_get_curr_height(),UILIB_A4GL_iscurrborder (),A4GL_get_currwinno(), A4GL_get_currwin(),menu->menu_offset,menu->gw_y);
//printf("done clr_menu_disp\n");
}


int
A4GL_highlevel_menu_loop (void *menuv)
{
  ACL_Menu_Opts *old_option;
  int a;
  int key_pressed;
  ACL_Menu *menu;



  menu = menuv;
  A4GL_chkwin ();

  A4GL_current_window(menu->parent_window_name);
  if (A4GL_LL_menu_type()==1) {
  	a=A4GL_menu_loop_type_1(menu,menu->num_opts);
  	A4GL_clr_error_nobox ("menu_callback");
	printf("Return %d\n",a);
  	return a;
  }


  if (menu->gw_x < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }

/*
   owin=get_curr_win();
 */

  //A4GL_gui_actmenu ((int) menu);

  A4GL_display_menu (menu);

  A4GL_debug ("Refreshed window - going into while loop");
  while (1 == 1)
    {
      old_option = (ACL_Menu_Opts *) menu->curr_option;
      abort_pressed = FALSE;

      A4GL_h_disp_opt (menu, menu->curr_option, menu->menu_offset,
		       menu->mn_offset, INVERT);



      a = A4GL_menu_getkey (menu);
      A4GL_debug ("menu_getkey returns %d", a);
      if (a == 23 || A4GL_is_special_key(a,A4GLKEY_HELP))
	{
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
      A4GL_h_disp_opt (menu, old_option, menu->menu_offset, menu->mn_offset,
		       NORM);
      A4GL_h_disp_opt (menu, menu->curr_option, menu->menu_offset,
		       menu->mn_offset, INVERT);
      A4GL_LL_screen_update ();

      if (abort_pressed)
	{
	  A4GL_debug ("setting menu->abort_pressed");
	  menu->abort_pressed = 1;
	  break;
	}
      if (key_pressed)
	break;
    }


  if (menu->gw_x < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }

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
  if (menu->gw_x < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }

  old_option = (ACL_Menu_Opts *) menu->curr_option;
  A4GL_debug ("Returning %d", old_option->opt_no);
  return old_option->opt_no;

}


static int
A4GL_menu_getkey (ACL_Menu * menu)
{
  //char cmd[60] = "";
  char buff[80];
  int a;
  //A4GL_debug ("Getting character for menu from window %p", menu->menu_win);
  a = -1;
  A4GL_set_abort (0);
  while (1)
    {

      /* a = A4GL_getch_swin (menu->menu_win); */

	A4GL_debug("debugging - error box");
      A4GL_debug ("wprintw - printing menu title %s @ %d %d", menu->menu_title, menu->gw_x, menu->gw_y);

      sprintf (buff, "%s:", menu->menu_title);
      A4GL_h_disp_title (menu, buff);
      //A4GL_wprintw(A4GL_get_currwin(),0,1,menu->gw_y,"%s:",menu->menu_title);
      A4GL_LL_screen_update ();

      //a = wrapper_wgetch (menu->menu_win);
      a = A4GL_LL_getch_swin (A4GL_get_currwin ());
	A4GL_debug("Clearing error box");
      A4GL_clr_error_nobox ("Menu");
      if (a == -1)
	{
	  if (abort_pressed)
	    {
	      A4GL_debug ("Got interrupt key pressed....");
	      a = A4GLKEY_INTERRUPT;	/* MJA 31/7/00 */
	      A4GL_set_abort (0);
	      return a;
	    }
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
	  A4GL_LL_screen_redraw ();
	  continue;
	}


      A4GL_debug ("Returning A=%d\n", a);
      return a;
    }
}





int A4GL_menu_loop_type_1(ACL_Menu *menu,int num_opts) {
  int key;
  int menu_response=-1;
  A4GL_LL_disp_h_menu(num_opts);
  while (menu_response==-1) {
    A4GL_LL_screen_update();
    key=A4GL_LL_getch_swin(0);

    if(key==0) continue;

    if (key<0) {// button pressed
		printf("Key = %d\n",key);

		menu_response=(key*-1) -1000;
		printf("menu_response=%d\n",menu_response);
    } else {
      ACL_Menu_Opts *f=menu->first;
      int res=0;
        //A4GL_clr_error_nobox ("gtkmenu");
      /* first check optkey */

      while(f) {
        if(f->optkey[0]==key) {
          menu_response=res;
          break;
        }
        res++;
        f=f->next_option;
      }
      if(menu_response>=0)
        break;

      /* no matching KEY found, so check the first letter of each title */
      f=menu->first;
      res=0;
      while(f) {
        char a=0;
        int i;
        /* set a to the first non-space char in opt_title */
        for(i=0; i<sizeof(f->opt_title); i++)
          if(f->opt_title[i]>' ') {
            a=a4gl_tolower(f->opt_title[i]);
            break;
          }
        if(a==key) {
          menu_response=res;
          break;
        }
        res++;
        f=f->next_option;
      }
   }
      if(menu_response>=0)
        break;
    


  }

  A4GL_LL_hide_h_menu();
  return menu_response;
}

