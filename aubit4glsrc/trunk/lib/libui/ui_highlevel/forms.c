static char *module_id="$Id: forms.c,v 1.7 2004-01-23 10:10:45 mikeaubury Exp $";

#include "forms.h"
#include "a4gl_API_ui_lib.h"
#include "a4gl_API_lowlevel_lib.h"

void *A4GL_create_window (char *name, int x, int y, int w, int h,
			  int iswindow,
			  int form_line,
			  int error_line,
			  int prompt_line,
			  int menu_line,
			  int border, int comment_line, int message_line,
			  int attrib);


#include "a4gl_libaubit4gl.h"
#include "a4gl_API_ui.h"
#include "forms.h"
int A4GL_decode_line_ib (int l);
void A4GL_dump_winstack (void);
void * A4GL_window_on_top (void);
void * A4GL_window_on_top_ign_menu (void);

#define MAXWIN 200
#define MAXPOINTERS 2000

/*
struct s_windows
{
  int x, y, w, h;
  void *win;
  char name[20];
  struct s_form_dets *form;
  struct s_form_attr winattr;
};
*/


struct s_windows windows[MAXWIN];
void *A4GL_display_form_new_win (char *name, struct s_form_dets *f, int x,
				 int y, int attr);
void A4GL_win_stack (struct s_windows *w, int op);
void *A4GL_get_currwin (void);



void *
UILIB_A4GL_cr_window (char *s,
		      int iswindow,
		      int form_line,
		      int error_line,
		      int prompt_line,
		      int menu_line,
		      int border, int comment_line, int message_line,
		      int attrib)
{
  void *win;
  int x, y, w, h;
  w = A4GL_pop_int ();
  h = A4GL_pop_int ();
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
  A4GL_chkwin ();
  if (A4GL_has_pointer (s, WINCODE))
    {
#ifdef DEBUG
      {
	A4GL_debug ("Window already exists");
      }
#endif
      A4GL_set_errm (s);
      A4GL_exitwith ("Window already exists (%s)");
      return 0;
    }
  win = (void *) A4GL_create_window (s, x, y, w, h,
				     iswindow,
				     form_line,
				     error_line,
				     prompt_line,
				     menu_line, border, comment_line,
				     message_line, attrib);

  return win;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_cr_window_form (char *namet,
			   int iswindow,
			   int form_line,
			   int error_line,
			   int prompt_line,
			   int menu_line,
			   int border, int comment_line, int message_line,
			   int attrib)
{
  int x, y, w, h;
  char *s;
  char buff[132];
  char name[256];
  struct s_form_dets *form;
  void *win;
  A4GL_debug ("cr_window_form(%s,%d,%d,%d,%d,%d,%d,%d,%d,%d)\n",
	      name, iswindow, form_line, error_line, prompt_line, menu_line,
	      border, comment_line, message_line, attrib);
  strcpy (name, namet);
  A4GL_trim (name);
  A4GL_chkwin ();

  s = A4GL_char_pop ();
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
  strcpy (buff, s);
  A4GL_trim (buff);
  //strcat (buff, acl_getenv ("A4GL_FRM_BASE_EXT"));

  A4GL_debug ("reading file %s - name=%s", buff, name);
  a4gl_status = 0;
  form = A4GL_read_form (buff, name);
  if (a4gl_status != 0)
    return 0;

  if (form == 0)
    {
      A4GL_exitwith ("Unable to create form");
      return 0;
    }
  else
    {
      A4GL_debug ("Created form %p", form);
    }

  w = form->fileform->maxcol;
  h = form->fileform->maxline;
  A4GL_debug ("Scaling on %s gives %d %d border = %d", buff, w, h, border);


  form->form_details.comment_line = comment_line;
  form->form_details.menu_line = menu_line;
  A4GL_debug ("Setting prompt line to ", prompt_line);
  form->form_details.prompt_line = prompt_line;
  form->form_details.form_line = form_line;
  form->form_details.error_line = error_line;
  form->form_details.message_line = message_line;
  A4GL_debug ("border=%d\n", border);
  form->form_details.border = border;
  form->form_details.colour = attrib;
  A4GL_add_pointer (name, S_FORMDETSCODE, form);

  win = (void *) A4GL_display_form_new_win (name, form, x, y, attrib);
  if (win)
    {
      A4GL_add_pointer (name, WINCODE, win);
      A4GL_LL_screen_update ();
    }
  else
    {
      A4GL_exitwith ("Error displaying form in window");
    }
  acl_free (s);
  return 0;
}


int
UILIB_A4GL_open_form (char *name)
{
  int w, h;
  char *s;
  char buff[256];
  struct s_form_dets *form;


  A4GL_chkwin ();
  s = A4GL_char_pop ();
  strncpy (buff, s, 256);
  buff[255] = 0;
  A4GL_trim (buff);
  //strcat (buff, acl_getenv ("A4GL_FRM_BASE_EXT"));
  A4GL_debug ("reading file %s ?", buff);
  A4GLSQL_set_status (0, 0);

  form = A4GL_read_form (buff, name);
  A4GL_debug ("Read form returns %d status = %d\n", form, a4gl_status);
  if (a4gl_status != 0)
    {
      A4GL_debug ("Some problem opening form...");
      acl_free (s);
      return -1;
    }
  A4GL_set_default_form (&form->form_details);
  /*
     form->w=w; // MJA 2707
     form->h=h; // MJA 2707
   */
  A4GL_debug ("adding pointer F to %s", name);
  A4GL_add_pointer (name, S_FORMDETSCODE, form);
  A4GL_debug ("Freeing s");
  acl_free (s);
  A4GL_debug ("Freed - form has been opened");
  return 0;
}


void
UILIB_A4GL_close_form (char *formname)
{
  void *ptr;
  int a;
  A4GL_chkwin ();
  //A4GL_debug ("FIXME : UILIB_A4GL_close_form not implemented");

  ptr = A4GL_find_pointer (formname, S_FORMDETSCODE);

  if (ptr == 0)
    {
      A4GL_exitwith ("Form not open");
      return;
    }


  A4GL_del_pointer (formname, S_FORMDETSCODE);

  for (a = 0; a < MAXWIN; a++)
    {
      if (windows[a].form == ptr)
	{
	  windows[a].form = 0;
	}
    }
  acl_free (ptr);

}



int
UILIB_A4GL_disp_form (char *name, int attr)
{
  struct s_form_dets *f;
  void *w;
  char buff[80];
  A4GL_chkwin ();
  A4GL_debug (" IN UILIB_A4GL_disp_form  %d\n", attr);
  //attr = A4GL_decode_aubit_attr (attr, 'w');

  A4GL_debug ("attr=%x\n", attr);

  A4GL_debug ("Disp_form_tui");
  f = (struct s_form_dets *) A4GL_find_pointer_val (name, S_FORMDETSCODE);
  A4GL_debug ("Got pointer to form as %p", f);
  if (f == 0)
    {
      A4GL_exitwith ("The form has not been opened");
      return 0;
    }
  A4GL_debug ("get_currwinno = %d f= %p setting form", A4GL_get_currwinno (),
	      f);

  windows[A4GL_get_currwinno ()].form = f;
  w = (void *) A4GL_LL_display_form (f, attr);

  if (w == 0)
    {
      windows[A4GL_get_currwinno ()].form = 0;
      return 0;
    }


  A4GL_debug ("Set windows [%d].form to %p", A4GL_get_currwinno (), f);
  A4GL_LL_screen_update ();
  return 0;
}







/**
 *
 * @todo Describe function
 */
int
UILIB_A4GL_iscurrborder (void)
{

  A4GL_chkwin ();

  //A4GL_debug ("A4GL_get_currwinno()=%d", A4GL_get_currwinno ());
  //A4GL_debug ("Winattr=%p", windows[A4GL_get_currwinno ()].winattr);
  //A4GL_debug ("border=%p", windows[A4GL_get_currwinno ()].winattr.border);
  return windows[A4GL_get_currwinno ()].winattr.border;
}


int
A4GL_getprompt_line (void)
{
int a;
int b;
  A4GL_debug ("getprompt_line - %d", windows[A4GL_get_currwinno()].winattr.prompt_line);



  if (windows[A4GL_get_currwinno()].winattr.prompt_line!=0xff) {
        a=windows[A4GL_get_currwinno()].winattr.prompt_line;
        b=1;
  } else {
        a=std_dbscr.prompt_line; // MJAMJA
        b=2;
  }


  if (a<0) {
        A4GL_debug("a<0 - %d",a);
        a=0-a-1;
        A4GL_debug("a now %d",a);
        if (A4GL_get_currwinno()==0) {
                a=A4GL_LL_screen_height()-a;
                A4GL_debug("a=%d from screen_height",a);
        } else {
                a=UILIB_A4GL_get_curr_height()-a;
                A4GL_debug("a=%d from curr_height",a);
        }
        A4GL_debug("a=%d",a);
  }

  A4GL_debug("Thinking prompt should be %d - window height=%d",a,UILIB_A4GL_get_curr_height());

  if (A4GL_get_currwinno()==0) {
        A4GL_debug("PROMPT SCR %d %d %d",a,UILIB_A4GL_get_curr_height(),UILIB_A4GL_iscurrborder());
  } else {
        A4GL_debug("PROMPT WIN %d %d %d",a,UILIB_A4GL_get_curr_height(),UILIB_A4GL_iscurrborder());
  }

  if (A4GL_get_currwinno()==0) {
         while (a>A4GL_LL_screen_height()) {
                A4GL_debug("prompt line - Too far down screen - moving up %d>%d+%d", a,UILIB_A4GL_get_curr_height(),UILIB_A4GL_iscurrborder());
                a--;
        }
  } else {
        if (a>(UILIB_A4GL_get_curr_height())) {
                a=1;
        }
  }


  if (a<=0) a=1;

  A4GL_debug("Prompt line %d",a);
return a;
}



int
A4GL_getcomment_line (void)
{
  A4GL_debug ("Comment line for currwin=%d std_dbscr=%d",
	      windows[A4GL_get_currwinno ()].winattr.comment_line,
	      std_dbscr.comment_line);
  if (windows[A4GL_get_currwinno ()].winattr.comment_line != 0xff)
    {
      return A4GL_decode_line_ib (windows[A4GL_get_currwinno ()].winattr.
				  comment_line);
    }
  return A4GL_decode_line_ib (std_dbscr.comment_line);
}

/**
 *
 * @todo Describe function
 */
int
A4GL_geterror_line (void)
{

  A4GL_debug ("geterror_line - %d (%d)",
	      windows[A4GL_get_currwinno ()].winattr.error_line,
	      A4GL_get_currwinno ());
  if (windows[A4GL_get_currwinno ()].winattr.error_line != 0xff)
    {
      A4GL_debug ("Window specific...");
      return A4GL_decode_line_scr (windows[A4GL_get_currwinno ()].winattr.
				   error_line);
    }
  A4GL_debug ("geterror_line - from options : %d", std_dbscr);

  return A4GL_decode_line_scr (std_dbscr.error_line);
}


/**
 *
 * @todo Describe function
 */
int
A4GL_getmessage_line (void)
{
int a;
int b;
  A4GL_debug ("getmessage_line - %d", windows[A4GL_get_currwinno()].winattr.message_line);



  if (windows[A4GL_get_currwinno()].winattr.message_line!=0xff) {
        a=windows[A4GL_get_currwinno()].winattr.message_line;
        b=1;
  } else {
        a=std_dbscr.message_line; // MJAMJA
        b=2;
  }


  if (a<0) {
        A4GL_debug("a<0 - %d",a);
        a=0-a-1;
        A4GL_debug("a now %d",a);
        if (A4GL_get_currwinno()==0) {
                a=A4GL_LL_screen_height()-a;
                A4GL_debug("a=%d from screen_height",a);
        } else {
                a=UILIB_A4GL_get_curr_height()-a;
                A4GL_debug("a=%d from curr_height",a);
        }
        A4GL_debug("a=%d",a);
  }

  A4GL_debug("Thinking message_line should be %d - window height=%d",a,UILIB_A4GL_get_curr_height());

  if (A4GL_get_currwinno()==0) {
        A4GL_debug("MSG SCR %d %d %d",a,UILIB_A4GL_get_curr_height(),UILIB_A4GL_iscurrborder());
  } else {
        A4GL_debug("MSG WIN %d %d %d",a,UILIB_A4GL_get_curr_height(),UILIB_A4GL_iscurrborder());
  }

  if (A4GL_get_currwinno()==0) {

         while (a>A4GL_LL_screen_height()) {
                A4GL_debug("message_line line - Too far down screen - moving up %d>%d+%d", a,A4GL_get_curr_height(),A4GL_iscurrborder());
                a--;
        }
  } else {
        if (a>(UILIB_A4GL_get_curr_height())) {
                a=2;
                if (a>UILIB_A4GL_get_curr_height()) a=1;
        }
  }


  if (a<=0) a=1;

  A4GL_debug("Msg line %d",a);
return a;

}


int
A4GL_getform_line (void)
{
  int a;
  A4GL_debug ("Get formline...%d",
	      windows[A4GL_get_currwinno ()].winattr.form_line);
  if (windows[A4GL_get_currwinno ()].winattr.form_line != 0xff)
    {
      a = windows[A4GL_get_currwinno ()].winattr.form_line;
    }
  else
    {
      a = std_dbscr.form_line;
    }

/* There seems to be some sort of bug in informix -
   if you have a window with a border - the form is shifted up 1 line...
   so a form line 3 would be displayed on line 2...
*/
  if (A4GL_get_curr_border ())
    {
      a--;
    }
  return a;
}





int
A4GL_chkwin (void)
{

  //A4GL_debug ("chkwin");

  if (A4GL_islinemode ())
    {

      //A4GL_debug (" API_ui Was linemode..");
      A4GL_switch_to_scr_mode ();
      A4GL_set_scrmode ('S');
      A4GL_LL_screen_update ();
    }
  else
    {
      //A4GL_debug ("API_ui Was screen mode..");
    }
  return 1;
}

void
A4GL_mja_endwin (void)
{
  if (A4GL_isscrmode ())
    {
      A4GL_set_scrmode ('L');
      A4GL_LL_switch_to_line_mode ();
    }
}


void
UILIB_A4GL_display_error (int a, int wait)
{
  char *s;
  A4GL_debug ("Cr string");
  s = A4GL_char_pop ();
  A4GL_chkwin ();
  A4GL_debug ("ZZ2 going to print an error : %s", s);
  A4GL_trim (s);
  A4GL_debug ("trimmed -> %s", s);
  if (A4GL_isgui ())
    A4GL_gui_error (s, A4GL_geterror_line ());
  else
    {
      if (wait)
	A4GL_LL_error_box (s, a);
      else
	A4GL_error_nobox (s, a);
    }
  A4GL_debug ("error_box done");
  acl_free (s);
  a4gl_status = 0;
}

int
A4GL_getmenu_line (void)
{
  int a;
/*
  if (windows[A4GL_get_currwinno ()].winattr.menu_line != 0xff)
    {
      //a = A4GL_decode_line_ib (windows[A4GL_get_currwinno ()].winattr.  menu_line);
      a =
	A4GL_decode_line (windows[A4GL_get_currwinno ()].winattr.menu_line -
			  1);

      if (a <= 0)
	return 1;
      while (a >= UILIB_A4GL_get_curr_height ())
	a--;
      return a;
    }
  a = A4GL_decode_line_ib (std_dbscr.menu_line);
  if (a <= 0)
    return 1;
  while (a >= UILIB_A4GL_get_curr_height ())
    a--;
  return a;
*/



  if (windows[A4GL_get_currwinno()].winattr.menu_line!=0xff) {
        a=A4GL_decode_line_ib (windows[A4GL_get_currwinno()].winattr.menu_line);
        if (a<=0) return 1;
        while (a>=UILIB_A4GL_get_curr_height()) a--;
		A4GL_debug("MENU LINE : %d",a);
        return a;
  }
  a=A4GL_decode_line_ib (std_dbscr.menu_line);
        if (a<=0) return 1;
        while (a>=UILIB_A4GL_get_curr_height()) a--;
	A4GL_debug("MENU LINE : %d",a);
        return a;




}


/**
 *
 * @todo Describe function
 */
void
A4GL_inc_winname (char *b)
{
  int a;
  for (a = 0; a < 10; a++)
    {
      b[a]++;
      if (b[a] > 'Z')
	b[a] = 'A';
      else
	break;
    }
}

#ifdef CRAP
char *
A4GL_glob_window (int x, int y, int w, int h, int border)
{
  static char winname[20];
  int f;
#ifdef DEBUG
  {
    A4GL_debug ("In glob_window");
  }
#endif
  A4GL_chkwin ();
  memset (winname, 'A', 19);
  f = 1;
  winname[19] = 0;

#ifdef DEBUG
  {
    A4GL_debug ("Finding free window ... starting with %s", winname);
  }
#endif

  while (A4GL_has_pointer (winname, WINCODE))
    {
      A4GL_inc_winname (winname);
    }
  A4GL_create_blank_window (winname, x, y + 1, w, h, border);
#ifdef DEBUG
  {				/*debug("Adding window @ %d %s",a,winname); */
  }
#endif
  /*A4GL_add_pointer (winname, WINCODE, win); */
  return winname;
}
#endif

int A4GL_decode_line_ib (int l)
{
  if (l > 0)
    {
      if (A4GL_get_curr_border ())
	{
	  A4GL_debug ("Decoded (1) line %d to %d (because of border)", l,
		      l - 1);
	  while (l > UILIB_A4GL_get_curr_height ())
	    l--;
	  return l;
	}
      else
	{
	  while (l > UILIB_A4GL_get_curr_height ())
	    l--;
	  A4GL_debug ("Decoded (2) line %d to %d", l, l);
	  return l;
	}
    }


/* -1 = last */
/* -2 = last -1 */


  if (A4GL_get_curr_border ())
    {
      A4GL_debug ("Decoded (3) line %d to %d (because of border)", l,
		  UILIB_A4GL_get_curr_height ());
      l = 0 - l;
      l--;
      return UILIB_A4GL_get_curr_height () - l + 1;
    }
  else
    {
      l = 0 - l;
      l--;
      A4GL_debug ("Decoded (4) line %d to %d ", l,
		  UILIB_A4GL_get_curr_height ());
      return UILIB_A4GL_get_curr_height () - l + 1;
    }


  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_decode_line (int l)
{
  if (l > 0)
    {
      if (A4GL_get_curr_border ())
	{
	  A4GL_debug ("Decoded (1) line %d to %d (because of border)", l,
		      l - 1);
	  l--;
	  while (l > UILIB_A4GL_get_curr_height ())
	    l--;
	  return l;
	}
      else
	{
	  A4GL_debug ("Decoded (2) line %d to %d", l, l);
	  while (l > UILIB_A4GL_get_curr_height ())
	    l--;
	  return l;
	}
    }


/* -1 = last */
/* -2 = last -1 */


  if (A4GL_get_curr_border ())
    {
      A4GL_debug ("Decoded (3) line %d to %d (because of border)", l,
		  UILIB_A4GL_get_curr_height ());
      l = 0 - l;
      l--;
      return UILIB_A4GL_get_curr_height () - l;
    }
  else
    {
      l = 0 - l;
      l--;
      A4GL_debug ("Decoded (4) line %d to %d ", l,
		  UILIB_A4GL_get_curr_height ());
      return UILIB_A4GL_get_curr_height () - l + 1;
    }


  return 0;
}


int
A4GL_decode_line_scr (int l)
{
  A4GL_debug ("decode_line_scr - l=%d", l);
  if (l > 0)
    {
      while (l > A4GL_LL_screen_height ())
	l--;
      return l;
    }
  if (l < 0)
    {
      A4GL_debug ("l=%d", l);
      l = A4GL_LL_screen_height () + l + 1;
      A4GL_debug ("l=%d", l);
      return l;
    }
  return 0;
}


int
A4GL_get_curr_border (void)
{
  A4GL_debug ("get curr border, A4GL_get_currwinno()=%d windows name =%s %d",
	      A4GL_get_currwinno (), windows[A4GL_get_currwinno ()].name,
	      windows[A4GL_get_currwinno ()].winattr.border);
  return windows[A4GL_get_currwinno ()].winattr.border;
}


/**
 *
 * @todo Describe function
 */
char *
UILIB_A4GL_get_currwin_name (void)
{

  //printf("get currwin= %s\n",windows[A4GL_get_currwinno ()].name);
  return windows[A4GL_get_currwinno ()].name;
}

/**
 *
 * @todo Describe function
 */
int
UILIB_A4GL_get_curr_width (void)
{
  A4GL_chkwin ();
  //A4GL_debug ("get curr width, A4GL_get_currwinno()=%d windows name =%s %d", A4GL_get_currwinno (), windows[A4GL_get_currwinno ()].name, windows[A4GL_get_currwinno ()].w);
  return windows[A4GL_get_currwinno ()].w;
}




/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_top (void)
{
  return windows[A4GL_get_currwinno ()].y;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_print_top (void)
{
#ifdef DEBUG
  {
    A4GL_debug ("In curr_print_top %d %d",
		windows[A4GL_get_currwinno ()].winattr.border,
		windows[A4GL_get_currwinno ()].y);
  }
#endif

  return windows[A4GL_get_currwinno ()].y +
    windows[A4GL_get_currwinno ()].winattr.border;
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void *
UILIB_A4GL_get_curr_form (int warn_if_no_form)
{
  char buff[80];
  sprintf (buff, "A4GL_get_currwinno()=%d", A4GL_get_currwinno ());

#ifdef DEBUG
  {
    A4GL_debug ("A4GL_get_currwinno()=%d", A4GL_get_currwinno ());
  }
#endif

  /*error_box(buff); */
  if (windows[A4GL_get_currwinno ()].form == 0)
    {
      if (warn_if_no_form)
	{
	  A4GL_exitwith ("No current form");
	}
      return 0;
    }
  return windows[A4GL_get_currwinno ()].form;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_left (void)
{
  return windows[A4GL_get_currwinno ()].x;
/* + windows[A4GL_get_currwinno()].winattr.border; */
}

/**
 *
 * @todo Describe function
 */
int
UILIB_A4GL_get_curr_height (void)
{
  return windows[A4GL_get_currwinno ()].h;
}




void *
A4GL_display_form_new_win (char *name, struct s_form_dets *f, int x, int y,
			   int attr)
{
  void *w;
  int nlines;
  int rows, cols;
  char buff[80];
  A4GL_chkwin ();
  A4GL_debug ("display_form_new_win - name=%s got errorline as %d\n", name,
	      f->form_details.error_line);
  A4GL_LL_scale_form (f, &rows, &cols);
  if (f->form_details.border)
    {
      rows = f->fileform->maxline - 1;
    }
  else
    {
      rows = f->fileform->maxline;
    }
  cols = f->fileform->maxcol;
  A4GL_debug ("display_form_new_win : %d rows %d cols at %d,%d x,y", rows,
	      cols, x, y);

  A4GL_debug ("display_form_new_win - border=%d", f->form_details.border);
  sprintf (buff, "%d %d", cols, rows);
#ifdef DEBUG
  {				/*debug("Rows=%d formline=%d f2 = %d",rows,getform_line(),f->form_details.form_line);
				 */
  }
#endif
  if (f->form_details.form_line != 0xff)
    {
      nlines = rows + f->form_details.form_line - 1;
    }
  else
    {
      nlines = rows + std_dbscr.form_line - 1;
    }
  if (f->form_details.border)
    {
      nlines++;
    }
  w = (void *) A4GL_create_window (name, x, y, cols, nlines,
				   1,
				   f->form_details.form_line,
				   f->form_details.error_line,
				   f->form_details.prompt_line,
				   f->form_details.menu_line,
				   f->form_details.border,
				   f->form_details.comment_line,
				   f->form_details.message_line,
				   f->form_details.colour);

  A4GL_gui_dispform (name, A4GL_getform_line ());


  windows[A4GL_get_currwinno ()].form = f;

  if (A4GL_LL_display_form (f, attr))
    return w;
  else
    return 0;
}



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
  int offset;

  int infx_to_curses[8];
  A4GL_chkwin ();

  A4GL_LL_set_chars_normal(chars_normal);


//chars_normal[0]=ACS_HLINE;
//chars_normal[1]=ACS_VLINE;
//chars_normal[2]=ACS_ULCORNER;
//chars_normal[3]=ACS_URCORNER;
//chars_normal[4]=ACS_LLCORNER;
//chars_normal[5]=ACS_LRCORNER;



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
      A4GL_debug ("drawbox Been passes a colour");
    }
  else
    {
      A4GL_debug ("drawbox No colour");
      c = infx_to_curses[7];
    }



  x = A4GL_pop_int () + A4GL_get_curr_border ();
  y = A4GL_pop_int () + A4GL_get_curr_border ();
  w = A4GL_pop_int ();
  h = A4GL_pop_int ();

  A4GL_debug ("In fgl_drawbox c=%d x=%d y=%d w=%d h=%d", c, x, y, w, h);
  A4GL_debug ("h=%d y+h=%d", h, y + h);
  win = (void *) A4GL_window_on_top_ign_menu ();
  A4GL_debug ("Got win as %p from window_on_top", win);

//  The add_Char routine will take into account whether
//  the current window has a border
//  fgl_drawbox ignores this as its direct to the screen

  if (!UILIB_A4GL_iscurrborder () || A4GL_get_currwinno () == 0)
    offset = 0;
  else
    offset = -1;

#define PMOVE(x,y,ch)   A4GL_LL_wadd_char_xy_col(win,x+offset,y+offset,ch|c)

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

  A4GL_LL_screen_update ();
  return 0;
}


void *
A4GL_create_blank_window (char *name, int x, int y, int w, int h, int border)
{
  void *p;
  A4GL_chkwin ();
  A4GL_debug ("Creating blank window..");
  p =
    (void *) A4GL_create_window (name, x, y, w, h, 1, 0xff, 0xff, 0xff, 0xff,
				 border, 0xff, 0xff, 0xffff);
  A4GL_debug ("window=%p", p);


  return p;
}




int
A4GL_init_windows (void)
{
  int a;
  void *p;
  for (a = 0; a < MAXWIN; a++)
    {
      windows[a].name[0] = 0;
    }
  A4GL_debug ("Creating screen");
  p = A4GL_create_blank_window ("screen", 1, 1, 79, 23, 0);
  A4GL_debug ("Made...");
  if (p)
    {
      UILIB_A4GL_current_window ("screen");
      A4GL_debug ("Made current");
      A4GL_init_stddbscr ();
      A4GL_debug ("initstd");
    }
  return 0;

}





int
A4GL_find_win (void *w)
{
  int a;
  for (a = 0; a < MAXWIN; a++)
    {
      if (windows[a].win == w)
	{
	  return a;
	}
    }
  return 0;
}

void *
A4GL_find_form_for_win (void *w)
{
  int a;
  for (a = 0; a < MAXWIN; a++)
    {
      if (windows[a].win == w)
	{
	  return windows[a].form;
	}
    }
  return 0;
}




int
UILIB_A4GL_current_window (char *win_name)
{
  int a = 0;
  void *w;
A4GL_debug("Current window : %s",win_name);
  A4GL_chkwin ();

//printf("CURRENT WINDOW : %s\n",win_name);
  
  w = A4GL_find_pointer (win_name, WINCODE);
  if (A4GL_get_currwin()==w)  return 0;

  if (!(w))
    {
      A4GL_set_error ("%s", win_name);
      A4GL_exitwith ("Window not found");
      A4GL_set_errm (win_name);
      return 0;
    }

  A4GL_win_stack (&windows[A4GL_find_win (w)], '^');
  A4GL_LL_make_window_top (w);

  //if (A4GL_screen_mode (-1))
    //{
      //A4GL_LL_screen_update ();
    //}

  return 0;

}



LIBEXPORT void
UILIB_A4GL_hide_window (char *winname)
{
  void *w;
  int a=0;
  A4GL_chkwin();
  w = A4GL_find_pointer (winname, WINCODE);


#ifdef DEBUG
  {
    //A4GL_debug ("hiding window %s %p", winname, p);
    A4GL_debug ("hiding window %s", winname);
  }
#endif
  if (w)
    {
       A4GL_LL_hide_window (w);
      A4GL_win_stack (w, 'v');
    }

}





void *
A4GL_create_window (char *name, int x, int y, int w, int h,
		    int iswindow,
		    int form_line,
		    int error_line,
		    int prompt_line,
		    int menu_line,
		    int border, int comment_line, int message_line,
		    int attrib)
{
  void *win = 0;
  int a;
  A4GL_chkwin ();


  if (attrib != 0xffff)
    {				// Strangely - informix resets the 'options' when you open a new window
      A4GL_set_option_value ('d', 0);
    }

  if (attrib == 0xffff)
    {
      char *s;
      int a;
      int n;
      s = acl_getenv ("BACKGROUND");
      if (strlen (s))
	{
	  n = sscanf (s, "%x", &a);
	  if (n)
	    {
	      attrib = a;
	    }
	}
      else
	{
	  attrib = 0x0;
	}

    }


  if (strcmp (name, "screen") == 0)
    {

      A4GL_debug ("Creating screen window..");

      if (A4GL_LL_screen_width () > 255)
	{
	  A4GL_exitwith ("Screen too wide - maximum 255 characters");
	  A4GL_chk_err (0, "");
	  return 0;
	}

      h = A4GL_LL_screen_height () - 1;
      w = A4GL_LL_screen_width () - 1;

      A4GL_debug ("Creating win..");
      //win=newwin(0,0,0,0);
      win = (void *) A4GL_LL_create_window (0, 0, 0, 0, 0);
      A4GL_debug ("Creating win.. %p", win);
      if (win) A4GL_add_pointer (name, WINCODE, win);

    }
  else
    {
      win = (void *) A4GL_LL_create_window (h, w, y, x, border);
      A4GL_add_pointer (name, WINCODE, win);

    }

  if (win == 0)
    {
      A4GL_exitwith ("Couldnt create window");
      return 0;
    }


  if ((attrib & 0xff) == 0 || (attrib & 0xff) == 0xff)
    {
      attrib = attrib + ' ';
      A4GL_debug ("Set pad char to space");
    }
  A4GL_debug ("Setting attribute for window to 0x%x for %s\n", attrib, name);



  A4GL_LL_set_bkg (win, attrib);


  A4GL_add_pointer (name, ATTRIBUTE, (void *) attrib);


  for (a = 0; a < MAXWIN; a++)
    {
      if (windows[a].name[0] == 0)
	{
	  strcpy (windows[a].name, name);
	  A4GL_add_pointer (name, S_WINDOWSCODE, &windows[a]);
	  windows[a].form = 0;
	  windows[a].winattr.comment_line = comment_line;
	  windows[a].winattr.menu_line = menu_line;
	  A4GL_debug ("Setting prompt line to %d", prompt_line);
	  windows[a].winattr.prompt_line = prompt_line;
	  windows[a].winattr.form_line = form_line;
	  windows[a].winattr.message_line = message_line;
	  windows[a].winattr.error_line = error_line;
	  windows[a].winattr.border = border;
	  windows[a].winattr.colour = attrib;
	  windows[a].x = x;
	  windows[a].y = y;
	  windows[a].w = w;
	  windows[a].h = h;
	  windows[a].win = win;

	  break;
	}
    }


  if (!(A4GL_has_pointer (name, S_WINDOWSCODE)))
    {
      A4GL_exitwith ("No spare windows left...");
      return 0;
    }


  A4GL_debug ("Deciding what to do... %s\n", name);

  //if (toupper (name[0]) == name[0])
  //{
  //A4GL_add_pointer (name, MNPARCODE, (void *) A4GL_get_currwin ());
  //A4GL_add_pointer (name, MNWINCODE, win);
  //}

  A4GL_win_stack (&windows[a], '+');

  A4GL_LL_make_window_top (win);

  A4GL_LL_screen_update ();
  return win;
}




void
UILIB_A4GL_remove_window (char *win_name)
{
  int a;
  void *win = 0;
  A4GL_chkwin ();

  if (!(A4GL_has_pointer (win_name, WINCODE)))
    {
      A4GL_set_error ("Window not found %s", win_name);
      A4GL_exitwith ("Window not found");
      A4GL_set_errm (win_name);
      return;
    }

  for (a = 0; a < MAXWIN; a++)
    {
      if (strcmp (windows[a].name, win_name) == 0)
	{
	  win = windows[a].win;
	  A4GL_LL_remove_window (win);
	  A4GL_win_stack (&windows[a], '-');
	  windows[a].name[0] = 0;
	  break;
	}
    }

  A4GL_LL_screen_update ();
  A4GL_del_pointer (win_name, WINCODE);

}




/** The windows stack */
static struct s_windows *win_stack[1024];
/** The windows stack counter / index */
static int win_stack_cnt = 0;

int A4GL_win_stack_cnt (void ) {
	return win_stack_cnt;
}

void *A4GL_window_on_stack(int cnt) {
	return win_stack[cnt]->win;
}

void
A4GL_win_stack (struct s_windows *w, int op)
{
  int a;
  int b;

  A4GL_debug ("win_stack : %p %c", w, op);

  if (op == '+')
    {
      win_stack[win_stack_cnt++] = w;
      A4GL_LL_make_window_top (win_stack[win_stack_cnt - 1]->win);
    }

  if (op == '-')
    {
      for (a = 0; a < win_stack_cnt; a++)
	{
	  if (win_stack[a] == w)
	    {
	      win_stack[a] = 0;
	      for (b = a + 1; b < win_stack_cnt; b++)
		{
		  win_stack[b - 1] = win_stack[b];
		}
	      win_stack_cnt--;
	      A4GL_debug ("win_stack_cnt=%d", win_stack_cnt);
	      break;
	    }
	}


    }

  if (op == '^')
    {
      A4GL_win_stack (w, '-');
      A4GL_win_stack (w, '+');
    }
}


void A4GL_dump_winstack (void)
{
  int a;
  for (a = 0; a < win_stack_cnt; a++)
    {
      A4GL_debug ("Winstack : %d %p", a, win_stack[a]);
    }
}


void *
A4GL_get_currwin (void)
{
  return win_stack[win_stack_cnt - 1]->win;
}


int
A4GL_get_currwinno (void)
{
  void *w;
  w = A4GL_get_currwin ();
  return A4GL_find_win (w);
}



void * A4GL_window_on_top (void)
{
  return A4GL_get_currwin ();
}


void * A4GL_window_on_top_ign_menu (void)
{
  int a;
  for (a = win_stack_cnt - 1; a >= 0; a--)
    {
      if (win_stack[win_stack_cnt - 1]->name[0] >= 'A'
	  && win_stack[win_stack_cnt - 1]->name[0] <= 'Z')
	continue;
      return win_stack[win_stack_cnt - 1]->win;
    }
}



void
A4GL_mja_set_field_buffer (void *field, int nbuff, char *buff)
{
  char buff2[8024];
  int a;
  int b;
  int errno;
  int width;
  b = A4GL_get_field_width (field);
  strcpy (buff2, buff);
  a = strlen (buff2);
  b = A4GL_get_field_width (field);
  A4GL_debug ("field_buffer %p %d %s", field, nbuff, buff);
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

//printf("call LL_set_field_buffer : '%s'\n",buff2);

  A4GL_LL_set_field_buffer (field, nbuff, buff2);
}



void
A4GL_set_field_attr_with_attr (void *field, int attr, int cmd_type)
{
  int r;
  int nattr;
  struct struct_scr_field *f;
  f = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (field));

  nattr = A4GL_determine_attribute (cmd_type, attr, f, 0);
  A4GL_debug ("Passed in attribute: %x, determined attribute should be %x",
	      attr, nattr);
  attr = nattr;

  if (attr & AUBIT_ATTR_REVERSE)
    r = 1;
  else
    r = 0;
  A4GL_debug
    ("MJA Calling A4GL_set_field_colour_attr - do_reverse=%d attr=%d", r,
     attr);
//printf("set_field_colour_attr 1\n");
  A4GL_set_field_colour_attr (field, r, attr);
}


void
A4GL_set_field_colour_attr (void *field, int do_reverse, int colour)
{
  struct struct_scr_field *f;
  int fg;
  int bg;
  f = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (field));
  A4GL_debug ("set_field_colour_attr - do_reverse=%d colour=%d - %d\n",
	      do_reverse, colour, A4GL_decode_colour_attr_aubit (colour));

  if (colour & AUBIT_ATTR_REVERSE && do_reverse == 0)
    {;
    }				// Maybe we should warn on these
  if (!(colour & AUBIT_ATTR_REVERSE) && do_reverse == 1)
    {;
    }				// Maybe we should warn on these

  fg = A4GL_LL_decode_aubit_attr (colour, 'f');
  bg = A4GL_LL_decode_aubit_attr (colour, 'B');


  A4GL_LL_set_field_fore (field, fg);
  A4GL_LL_set_field_back (field, bg);

  A4GL_debug ("FG=%x BG=%x", fg, bg);

  return;


  colour = colour & 0xff00;


  if (do_reverse && colour == AUBIT_COLOR_WHITE)
    {
      A4GL_debug ("XX1 REVERSE");
      A4GL_debug ("DOINGREVERSE");
      A4GL_LL_set_field_fore (field, AUBIT_ATTR_REVERSE);
      A4GL_LL_set_field_back (field, AUBIT_ATTR_REVERSE);
    }


  if (do_reverse && colour != AUBIT_COLOR_WHITE)
    {
      A4GL_debug ("XX2 REVERSE");
      A4GL_debug ("DOINGREVERSE");
      A4GL_LL_set_field_back (field,
			      A4GL_decode_colour_attr_aubit (colour) |
			      AUBIT_ATTR_REVERSE);
      A4GL_LL_set_field_fore (field,
			      A4GL_decode_colour_attr_aubit (colour) |
			      AUBIT_ATTR_REVERSE);
    }

  if (do_reverse == 0 && colour != AUBIT_COLOR_WHITE)
    {
      A4GL_debug ("XX3 NO REVERSE & COLOUR %d", colour);
      A4GL_LL_set_field_fore (field, A4GL_decode_colour_attr_aubit (colour));
      A4GL_LL_set_field_back (field, A4GL_decode_colour_attr_aubit (colour));
    }

  if (do_reverse == 0 && colour == AUBIT_COLOR_WHITE)
    {
      A4GL_debug ("XX3 NO REVERSE & NO COLOUR");
      A4GL_LL_set_field_fore (field, A4GL_decode_colour_attr_aubit (colour));
      A4GL_LL_set_field_back (field, A4GL_decode_colour_attr_aubit (colour));
    }

  A4GL_debug ("Returning");
}



LIBEXPORT void
UILIB_A4GL_show_window (char *winname)
{
  void *p;
  A4GL_chkwin();
  p = A4GL_find_pointer (winname, WINCODE);
#ifdef DEBUG
  {
    A4GL_debug ("showing window %s %p", winname, p);
  }
#endif
  if (p)
    A4GL_LL_show_window (p);
  A4GL_win_stack (&windows[A4GL_find_win (p)], '^');
}



LIBEXPORT int
UILIB_A4GL_movewin (char *winname, int absol)
{
  void *p;
  int x, y;
  int r = 0;
  int nx, ny;
  struct s_windows *w;
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
  w = A4GL_find_pointer (winname, S_WINDOWSCODE);
#ifdef DEBUG
  {
    A4GL_debug ("w=%p", w);
  }
#endif


  if (w)
    {
      p = w->win;
      if (w->winattr.border)
	{
	  x--;
	  y--;
	}

      if (absol)
	{
#ifdef DEBUG
	  {
	    A4GL_debug ("Moving absolute to %d %d", y - 1, x - 1);
	  }
#endif
	   A4GL_LL_move_window (p, y - 1, x - 1);
	  nx = x;
	  ny = y;
	}
      else
	{
#ifdef DEBUG
	  {
	    A4GL_debug ("Moving relative by %d %d", y, x);
	  }
#endif
	   A4GL_LL_move_window (p, w->y + y - 1, w->x + x - 1);
	  nx = w->x + x + 1;
	  ny = w->y + y + 1;
	}
    }
  else
    {
      A4GL_exitwith ("Window to move was not found");
      return 0;
    }
#ifdef DEBUG
  {
    A4GL_debug ("r=%d", r);
  }
#endif


  w->x = nx;
  w->y = ny;
  A4GL_LL_screen_update ();
  return 0;
}




void
UILIB_A4GL_clr_window (char *win_name)
{
  int a;
  void *w;
  struct s_windows *win;
  char buff[1024];

  A4GL_chkwin ();
  if (!(A4GL_has_pointer (win_name, WINCODE)))
    {
      A4GL_set_error ("Window not found %s", win_name);
      A4GL_exitwith ("Window not found");
      A4GL_set_errm (win_name);
      return;
    }
#ifdef DEBUG
  {
    A4GL_debug ("Clr window .... %s", win_name);
  }
#endif
  w = A4GL_find_pointer (win_name, WINCODE);
  win = A4GL_find_pointer (win_name, S_WINDOWSCODE);
  memset (buff, ' ', 1024);
  buff[win->w] = 0;
  for (a = 0; a <= win->h; a++)
    {
      //if (win->winattr.border) {
      //A4GL_wprintw(w,0,1,a+1,"%s",buff);
      //} else {
      A4GL_wprintw (w, 0, 1, a+1, "%s", buff);
      //}
    }

  UILIB_A4GL_zrefresh ();

}


void A4GL_make_window_with_this_form_current(void *form) {
int a;
for (a=0;a<MAXWIN;a++) {
        if (windows[a].form==form) {
                A4GL_debug("Found it... @ %d",a);
                UILIB_A4GL_current_window (windows[a].name);
                return;
        }
}

}



A4GL_add_window(int x,int y,int w,int h,char *name,void *fd, void *win) {
int a;
void *ww=0;


//printf("Add window : %s %p %p",name,fd,win);


  for (a = 0; a < MAXWIN; a++)
    {
      if (windows[a].name[0] == 0)
        {
          strcpy (windows[a].name, name);
          A4GL_add_pointer (name, S_WINDOWSCODE, &windows[a]);
	printf("Setting form to %p\n",fd);
          windows[a].form = fd;
          windows[a].winattr.comment_line = 0; //comment_line;
          windows[a].winattr.menu_line = 0; //menu_line;
          windows[a].winattr.prompt_line = 0;  //prompt_line;
          windows[a].winattr.form_line = 0; //form_line;
          windows[a].winattr.message_line = 0; //message_line;
          windows[a].winattr.error_line = 0; //error_line;
          windows[a].winattr.border = 0; //border;
          windows[a].winattr.colour = 0; //attrib;
          windows[a].x = x;
          windows[a].y = y;
          windows[a].w = w;
          windows[a].h = h;
          windows[a].win = win;
	ww=&windows[a];

          break;
        }
    }
      A4GL_add_pointer (name, WINCODE, win);
return ww;
}
