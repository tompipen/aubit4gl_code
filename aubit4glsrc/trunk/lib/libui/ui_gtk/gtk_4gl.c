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
# $Id: gtk_4gl.c,v 1.12 2003-04-07 18:20:46 mikeaubury Exp $
#*/

/**
 * @file
 * General functions to implement the 4gl UI in GUI GTK mode.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define DECLARE_DIMENSIONS

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_ui_gtk_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

#ifdef __MINGW32__
	typedef void *pthread_t;
#endif


GtkWidget *tooltips = 0;        /** Tooltip widget */
int window_frame_type = 0;
pthread_t thread;
GtkWidget *windows[256];        /** The 4gl window stack */
GtkWidget *win_screen;          /** The 4gl special principal window (SCREEN) */
int frame_style = GTK_SHADOW_IN;/** The frame style used in the GUI */
GtkWindow *currwindow = 0;      /** The 4gl current window */
void *argcv;
void *argvv;
int wait = 0;
int mfrm_width;			/* set to the width of the last opened form */
int mfrm_height;		/* set to the height of the last opened form */
extern int ui_mode;     /** User interface used (GUI or TUI) */
GtkWindow *console = 0;
GtkWidget *console_list;
char currwinname[256];
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


void show_console (void);
void hide_console (void);
void add_to_console (char *s);
void create_console (void);
void decode_gui_winname(char *name);

GtkWindow *
cr_window (char *s, int iswindow, int form_line, int error_line,	/*  Ignored */
	       int prompt_line,	/* Ignored */
	       int menu_line,	/* Ignored */
	       int border,	/* Ignored */
	       int comment_line,	/* Ignored */
	       int message_line, int attrib) ;
//GtkFixed * read_form_gtk (char *fname);
void show_form (GtkWindow * mainfrm, GtkFixed * form);
void cr_window_form (char *s,
		    int iswindow,
		    int form_line,
		    int error_line,
		    int prompt_line,
		    int menu_line,
		    int border,
		    int comment_line, int message_line, int attrib);

void open_form (char *form_id);
int disp_form (char *form_id, int a);
void current_window (char *s);
void sleep_i (void);
void clear_console (char *s);
int close_form (char *name);
/* int open_gui_form (char *name_orig, int absolute,int nat, char *like, int disable, void *handler_e,void (*handler_c())); */
int open_gui_form (char *name_orig, int absolute,int nat, char *like, int disable, void *handler_e,void (*handler_c(int a, int b)));
struct struct_screen_record * get_srec_gtk (char *name);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 */
void
gui_run_til_no_more (void)
{

  if (screen_mode (-1) )
    {
      while (gtk_events_pending ())
	gtk_main_iteration ();
    } else {
	debug("Skipping run_til_no_more - in pause mode");
    }

}

/**
 * Create a window in GTK GUI mode.
 *
 * @param name The 4gl name of the window
 * @param x The column of the upper left corner of the window.
 * @param y The line of the upper left corner where the window should be 
 *   rendered.
 * @param w The width of the window.
 * @param h The heigth of the window.
 * @param iswindow
 * @param form_line The line where the eventual forms are opened.
 * @param error_line The line where the errors are displayed.
 * @param prompt_line The line where the PROMPT statement is prcessed.
 * @param menu_line The line where the 4gl MENU statement is displayed.
 * @param border Flag that indicate if the window should have a border.
 * @param comment_line The line the comments are showed (form comments).
 * @param message_line The line where the messages from MESSAGE statement is
 *   showed.
 * @param attrib The attributes used
 * @return The widget window created.
 */
static GtkWindow *
create_window_gtk (char *name, int x, int y, int w, int h,
		   int iswindow,
		   int form_line,
		   int error_line,
		   int prompt_line,
		   int menu_line,
		   int border, int comment_line, int message_line, int attrib)
{
  GtkWidget *fixed;
  GtkWidget *win; /* Should this not be GtkWindow *win; - not GtkWidget ? */
  GtkFrame *frame = 0;
  GtkWidget *wxx = 0;
  int isscreenwin = 0;

debug("AAA - Message Line %d\n",message_line);
if (form_line==0xff) { form_line=std_dbscr.form_line; }
if (menu_line==0xff) { 
		menu_line=std_dbscr.menu_line; 
}
if (comment_line==0xff) { comment_line=std_dbscr.comment_line; }
if (error_line==0xff) { error_line=std_dbscr.error_line; }
if (prompt_line==0xff) { prompt_line=std_dbscr.prompt_line; }
if (message_line==0xff) {message_line=std_dbscr.message_line;
debug("Setting message line to default : %d\n",message_line);
 }


  debug ("gui_create_window %s %d %d %d %d", name, x, y, w, h);

  if (strcmp (name, "screen") == 0)	/* Background screen */
    {
      x = 0;			/* Default size is 24x80 */
      y = 0;
      h = 24;
      w = 80;
      debug ("h=%d w=%d\n", h, w);
      isscreenwin = 1;
    }
  else
    {
      isscreenwin = 0;
    }

	/* Make the dimensions into gtk sizes (pixels ?) rather than characters */
  w = w * XWIDTH;
  x = x * XWIDTH;
  y = y * YHEIGHT;
  h = h * YHEIGHT;

	/* Are we making the main screen ? */
  if (isscreenwin == 1)
    {
      win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	strcpy(currwinname,"SCREEN");
      gtk_window_set_title (GTK_WINDOW (win), name);

      if (win == 0)
	{
	  debug ("No window created!");
	  exitwith ("Unable to create new window");
	  return 0;
	}
      fixed = gtk_fixed_new ();
      win_screen = fixed;
      gtk_widget_show (GTK_WIDGET(fixed));
      gtk_container_add (GTK_CONTAINER (win), fixed);
      gtk_widget_set_usize (GTK_WIDGET (win), w, h);
      gtk_object_set_data (GTK_OBJECT (fixed), "TOP", win);
      gtk_widget_show (GTK_WIDGET(win));
      win = fixed;
      win_screen = win;
    }
  else
    {
	strcpy(currwinname,name);
      if (border)
	{

	  wxx = 0;
	  if (window_frame_type == 0)
	    wxx = gtk_event_box_new ();

	  if (window_frame_type == 99)
	    wxx = gtk_handle_box_new ();


	  if (wxx == 0)
	    {
	      exitwith ("Invalid window style type");
	      return 0;
	    }

	  debug ("Event box=%p\n", wxx);


	  gtk_fixed_put (GTK_FIXED (win_screen), wxx, x - XWIDTH,
			 y - YHEIGHT / 2);


	  frame = (GtkFrame *) gtk_frame_new (0);
	  debug ("Frame=%p\n", frame);
	  gtk_frame_set_shadow_type (GTK_FRAME (frame), frame_style);

	  gtk_widget_set_usize (GTK_WIDGET (frame), w + 2 * XWIDTH,
				h + YHEIGHT);

	  gtk_container_add (GTK_CONTAINER (wxx), GTK_WIDGET (frame));
	  gtk_widget_show (GTK_WIDGET (frame));
	  fixed = gtk_fixed_new ();
	  gtk_widget_show (fixed);
	  gtk_widget_show (wxx);
	  gtk_container_add (GTK_CONTAINER (frame), fixed);
	}
      else
	{
	  fixed = win_screen;
	}

      debug ("w=%d h=%d\n", w / XWIDTH, h / YHEIGHT);
      win = gtk_fixed_new ();
      gtk_widget_set_usize (GTK_WIDGET (win), w, h);

      if (border)
	{
	  gtk_fixed_put (GTK_FIXED (fixed), win, XWIDTH, YHEIGHT / 2);
	}
      else
	{
	  gtk_fixed_put (GTK_FIXED (fixed), win, x, y);
	  fixed = win;
	}


      gtk_object_set_data (GTK_OBJECT (win), "BORDER", (void *) border);


      gtk_object_set_data (GTK_OBJECT (win), "XPOS", (void *) (x / XWIDTH));
      gtk_object_set_data (GTK_OBJECT (win), "YPOS", (void *) (y / YHEIGHT));
      gtk_object_set_data (GTK_OBJECT (win), "Y_OFF",
			   (void *) (0 - (YHEIGHT / 2)));
      gtk_object_set_data (GTK_OBJECT (win), "X_OFF", (void *) (0 - XWIDTH));


      gtk_object_set_data (GTK_OBJECT (win), "TOPWIN", frame);

      if (border)
	{
	  gtk_object_set_data (GTK_OBJECT (win), "TOP", wxx);
	  gtk_object_set_data (GTK_OBJECT (win), "FRAME", frame);
	}
      else
	gtk_object_set_data (GTK_OBJECT (win), "TOP", fixed);

    }

  gtk_object_set_data (GTK_OBJECT (win), "WIDTH", (void *) (w / XWIDTH));
  gtk_object_set_data (GTK_OBJECT (win), "HEIGHT", (void *) (h / YHEIGHT));

  gtk_object_set_data (GTK_OBJECT (win), "FORM_LINE", (void *) form_line);
  gtk_object_set_data (GTK_OBJECT (win), "ERROR_LINE", (void *) error_line);
  gtk_object_set_data (GTK_OBJECT (win), "PROMPT_LINE", (void *) prompt_line);
  gtk_object_set_data (GTK_OBJECT (win), "MENU_LINE", (void *) menu_line);
  gtk_object_set_data (GTK_OBJECT (win), "COMMENT_LINE",
		       (void *) comment_line);
  gtk_object_set_data (GTK_OBJECT (win), "MESSAGE_LINE",
		       (void *) message_line);
  gtk_object_set_data (GTK_OBJECT (win), "ATTRIB", (void *) attrib);

  add_pointer (name, WINCODE, win);
  /*
  vbox = gtk_vbox_new (0, 0);
  gtk_container_add (fixed, vbox);
  gtk_object_set_data (win, "vbox", vbox);
   */

  gtk_widget_show (win);

  gtk_signal_connect (GTK_OBJECT (win), "delete_event",
		      GTK_SIGNAL_FUNC (delete_event), win);

if (isscreenwin == 1) {
  gtk_signal_connect (GTK_OBJECT (win), "destroy",
		      GTK_SIGNAL_FUNC (destroy_event), win);
}

  gtk_signal_connect (GTK_OBJECT (win), "key-press-event",
		      GTK_SIGNAL_FUNC (keypress), win);

  debug ("Currwindow=%p MJA MJAMJA\n", win);

  set_current_window(GTK_WINDOW(win));


  gtkwin_stack((GtkWindow *)win,'+');
  gui_run_til_no_more ();
  gtk_object_set_data (GTK_OBJECT (win), "FORM_LINE", (void *) form_line);
  return currwindow;
}

/**
 * Initialization of all the gtk stuff to work in GUI mode.
 *
 * Reads the GTKRC environment variable in order to read some GTK
 * initializations like the themes.
 *
 * Receives the parameters passed to 4gl.
 *
 * @param argc The argument count
 * @param argv The argument values
 */
void
A4GLUI_ui_init (int argc, char *argv[])
{
  argcv = &argc;
  argvv = &argv;

  gtk_init (argcv, argvv);
  ui_mode = 1;

    /*
 shouldn't need this any more as we won't be starting curses mode
 in the first place
  mja_endwin ();
 */

  if (acl_getenv ("GTKRC"))
    {
      char buff[256];
      debug ("Read GTKRC\n");
      sprintf (buff, "/usr/share/themes/%s/gtk/gtkrc", acl_getenv ("GTKRC"));
      gtk_rc_parse (buff);
    }
  alloc_colors ();

  debug ("******************Done\n");
  create_window_gtk ("screen", 0, 0, 80, 24, 1, 3, -1, -2, 1, 0, -2, 1,
		     (0x0));
  wait = 1;
  gui_run_til_no_more ();

  gtk_key_snooper_install (KeySnooper, 0);
  create_console ();

  if (tooltips == 0)
    tooltips = (GtkWidget *) gtk_tooltips_new ();
}


/**
 * Create a new 4gl window in GTK GUI mode.
 *
 * Eg. cr_window_form("m1:a1", 1,3,-1,-2,1,0,-2,1,(0x0))
 *
 * @param s The 4gl name of the window
 * @param iswindow
 * @param form_line The line where the eventual forms are opened.
 * @param error_line The line where the errors are displayed. Ignored.
 * @param prompt_line The line where the PROMPT statement is prcessed. Ignored.
 * @param menu_line The line where the 4gl MENU statement is displayed. Ignored.
 * @param border Flag that indicate if the window should have a border. Ignored.
 * @param comment_line The line the comments are showed (form comments). 
 *   Ignored.
 * @param message_line The line where the messages from MESSAGE statement is 
 *   showed. Ignored.
 * @param attrib The attributes used Ignored.
 * @return The widget window created.
 */
GtkWindow *
cr_window (char *s, int iswindow, int form_line, int error_line,	/* Ignored */
	       int prompt_line,	/* Ignored */
	       int menu_line,	/* Ignored */
	       int border,	/* Ignored */
	       int comment_line,	/* Ignored */
	       int message_line, int attrib)
{


  GtkWindow *win;


  int x, y, w, h;
  w = pop_int ();
  h = pop_int ();
  x = pop_int ();
  y = pop_int ();



if (form_line==0xff) { form_line=std_dbscr.form_line; }
if (menu_line==0xff) { menu_line=std_dbscr.menu_line; }
if (comment_line==0xff) { comment_line=std_dbscr.comment_line; }
if (error_line==0xff) { error_line=std_dbscr.error_line; }
if (prompt_line==0xff) { prompt_line=std_dbscr.prompt_line; }

  if (has_pointer (s, WINCODE))
    {
#ifdef DEBUG
	/* {DEBUG} */{debug ("Window already exists"); }
#endif
      set_errm (s);
      exitwith ("Window already exists (%s)");
      return 0;
    }

  win = create_window_gtk (s, x - 1, y - 1, w, h,
			   iswindow,
			   form_line,
			   error_line,
			   prompt_line,
			   menu_line,
			   border, comment_line, message_line, attrib);
  gui_run_til_no_more ();
  return win;

}

/** 
 * Read a form from the compiled form file and display it in a panel.
 *
 * @param fname The file form name without frm extension.
 * @return The panel where the form is showed.
 */
void *
read_form_gtk (char *fname,char *formname)
{
struct s_form_dets *f;
  struct struct_form *the_form;
  //FILE *f;
  //XDR xdrp;
  int a;
  GtkWidget *rwindow;
  GtkWidget *fixed;

  /*

  debug ("Opening file %s\n", fname);
  f = (FILE *) open_file_dbpath (fname);

  if (f == 0)
    {
      exitwith ("Unable to open file.\n");
      return 0;
    }
  debug ("Clearing memory...");
  */

  f=read_form(fname,formname);

  the_form = f->fileform;
  //malloc (sizeof (struct_form));

  //memset (the_form, 0, sizeof (struct_form));

  //a=read_data_from_file("struct_form",the_form,fname);
  


   //xdrstdio_create (&xdrp, f, XDR_DECODE);
   //a = xdr_struct_form (&xdrp, the_form);
   /*
	this is just a workaround - it still keep libUI_GTK dependent on
    libFORM_XDR, and therefore Sun RPC XDR functions:
	a=isolated_xdr_struct_form(&xdrp,the_form); //in lib/libform/form_xdr/formwrite2.c
    */


  if (!a)
    {
      debug ("Bad form file format, form returned=%d\n", a);
      exitwith ("Bad form file format\n");
      exit (27);
	  /* return 0; */
    }

  debug ("XDR form read");
  debug ("DB         : '%s'\n", the_form->dbname);
  debug ("Delimiters : '%s'\n", the_form->delim);
  debug ("maxcol     : %d\n", the_form->maxcol);
  debug ("Here\n");

	/* How many screens ? */
  if (the_form->snames.snames_len > 1)
    {				/* More than one - create a notebook */
      int a;
      GtkWidget *notebook;
      GtkWidget *label;
      GtkFixed *fixedpage;
      notebook = gtk_notebook_new ();
      rwindow = notebook;
      debug ("Made notebook");
      gtk_widget_show (notebook);
      for (a = 0; a < the_form->snames.snames_len; a++)
	{
	  char buff[256];
	  debug ("Making page %d\n", a);
	  fixedpage = (GtkFixed *) gtk_fixed_new ();
          gtk_widget_set_usize (GTK_WIDGET (fixedpage), the_form->maxcol*XWIDTH, the_form->maxline*YHEIGHT);


	  gtk_widget_show (GTK_WIDGET (fixedpage));
	  label = gtk_label_new (the_form->snames.snames_val[a].name);
	  gtk_notebook_insert_page (GTK_NOTEBOOK (notebook),
				    GTK_WIDGET (fixedpage), label, a + 1);
	  sprintf (buff, "Screen%d", a + 1);
	  windows[a] = (GtkWidget *) fixedpage;

	}
    }
  else
    {
      debug ("Creating new fixed container for widgets\n");
      fixed = gtk_fixed_new ();
      windows[0] = fixed;
      rwindow = fixed;
    }

  if (tooltips == 0)
    tooltips = (GtkWidget *) gtk_tooltips_new ();

  debug ("Making widgets\n");

  mfrm_width = the_form->maxcol;
  mfrm_height = the_form->maxline;

  debug ("maxline    : %d\n", the_form->maxline);
  make_widgets (the_form, rwindow);
  debug_last_field_created ("after make_widgets");
  debug ("Done\n");
  gui_run_til_no_more ();
  debug ("adding ref from %p (rwindow) to %p xdr_form", rwindow, the_form);
  debug_last_field_created ("after make_widgets 2");
  gtk_object_set_data (GTK_OBJECT (rwindow), "xdr_form", the_form);
  debug_last_field_created ("after make_widgets 3");
  return (GtkFixed *) rwindow;
}

/**
 * Change the current window.
 *
 * The current window is the one that is at front.
 *
 * @param w A pointer to the GTK window to be made current.
 */
void
set_current_window (GtkWindow * w)
{

    /*
  if (currwindow)
  {                         // IF NOT USING FORMHANDLER
  gtk_window_set_modal (currwindow, 0);
  }
  */

  debug("setting current window=%p from %p",w,currwindow);
  currwindow = w;


  /* gtk_window_set_modal (currwindow, 1); */
}


/**
 * Show a form in a window...
 *
 * @param mainform The window where the form should be rendered.
 * @param form The form to paint.
 */
void
show_form (GtkWindow * mainfrm, GtkFixed * form)
{
GtkObject *a;
int off;

  debug ("SHow form mainfrm=%p form=%p", mainfrm, form);
  debug ("Foreach..");
  debug ("Remove old\n");

/* Is there a form there already ? */
  a = gtk_object_get_data (GTK_OBJECT (mainfrm), "currform");

  /* v = gtk_object_get_data (mainfrm, "vbox"); */

  if (a)
    {
      debug ("gtk_remove\n");
      gtk_container_remove (GTK_CONTAINER (mainfrm), GTK_WIDGET (a));
      debug ("done gtk_remove\n");
    }

  debug ("Add %p %p", mainfrm, form);
  debug ("Add %p %p", mainfrm, form);


  /* gtk_box_pack_end_defaults (v, form); */
  off = (int) gtk_object_get_data (GTK_OBJECT (mainfrm), "FORM_LINE");
  debug("Off [FORM_LINE] = %d\n",off);
  gtk_fixed_put (GTK_FIXED (mainfrm), GTK_WIDGET (form), 0, (off-1) * YHEIGHT);

  debug ("Added mainfrm=%p form =%p as currform\n", mainfrm, form);
  gtk_object_set_data (GTK_OBJECT (mainfrm), "currform", form);


  debug ("Show");
  gtk_widget_show (GTK_WIDGET (form));
  debug ("Done");
  gtk_widget_show_all (GTK_WIDGET (mainfrm));
  debug ("Shown");

  set_current_window (mainfrm);
  gui_run_til_no_more ();
  debug ("Finished showing");
}

/**
 * Create a window with form in GTK GUI mode.
 *
 * The form name is passed by the stack.
 *
 * @param s The 4gl name of the window
 * @param iswindow
 * @param form_line The line where the eventual forms are opened.
 * @param error_line The line where the errors are displayed.
 * @param prompt_line The line where the PROMPT statement is prcessed.
 * @param menu_line The line where the 4gl MENU statement is displayed.
 * @param border Flag that indicate if the window should have a border.
 * @param comment_line The line the comments are showed (form comments). 
 * @param message_line The line where the messages from MESSAGE statement is 
 *   showed.
 * @param attrib The attributes used.
 */
void
cr_window_form (char *s,
		    int iswindow,
		    int form_line,
		    int error_line,
		    int prompt_line,
		    int menu_line,
		    int border,
		    int comment_line, int message_line, int attrib)
{
  char *fname;
  int x, y;
  char buff[256];
  GtkFixed *form;
  GtkWindow *win;

if (form_line==0xff) { form_line=std_dbscr.form_line; }
if (menu_line==0xff) { menu_line=std_dbscr.menu_line; }
if (comment_line==0xff) { comment_line=std_dbscr.comment_line; }
if (error_line==0xff) { error_line=std_dbscr.error_line; }
if (prompt_line==0xff) { prompt_line=std_dbscr.prompt_line; }

  fname = char_pop ();
  trim(fname);
  debug ("fname=%s", fname);
  x = pop_long ();
  y = pop_long ();
  debug ("x,y=%d,%d", x, y);

  debug ("Create window & form");
  //sprintf (buff, "%s%s", fname,acl_getenv ("A4GL_FRM_BASE_EXT"));
  //
  form = (GtkFixed *) read_form_gtk (fname,s);
  debug_last_field_created ("read form");

  gui_run_til_no_more ();

  debug ("Read form");

  win =
    create_window_gtk (s, x, y, mfrm_width, mfrm_height + form_line, iswindow, form_line, error_line,	/* Ignored */
		       prompt_line,	/* Ignored */
		       menu_line,	/* Ignored */
		       border,	/* Ignored */
		       comment_line,	/* Ignored */
		       message_line, attrib);
  debug ("Made window win=%p", win);
  debug_last_field_created ("make window");

  show_form (win, form);
  debug_last_field_created ("after show_form");
  debug ("SHown form");
}

/**
 * Open a form in GTK GUI mode.
 *
 * Executed by the generated from the OPEN FORM 4gl statement.
 *
 * @param form_id The form file name.
 */
void
open_form (char *form_id)
{
  char *filename;
  GtkFixed *form;
  char buff[256];
  filename = char_pop ();
  trim(filename);
  //sprintf (buff, "%s%s", filename,acl_getenv ("A4GL_FRM_BASE_EXT"));
  form = read_form_gtk (filename,form_id);
  debug_last_field_created ("after reading form");
  debug ("Adding form code for %s", form_id);
  gtk_object_ref (GTK_OBJECT (form));
  add_pointer (form_id, FORMCODE, form);
  gui_run_til_no_more ();
  debug_last_field_created ("form is open");
  debug ("Form has been opened form=%p\n", form);
}

/**
 * Implementation of OPEN FORM 4gl statement in GTK GUI mode.
 *
 * @param form_id The form file name.
 * @param a Attributes. Ignored
 */
int
disp_form (char *form_id, int a)
{
  GtkFixed *ptr;
  debug ("Disp form\n");
  debug ("Displaying form\n");
  ptr = (GtkFixed *) find_pointer (form_id, FORMCODE);
  debug_last_field_created ("disp_form 1");
  if (ptr == 0)
    {
      exitwith ("Form not open");
      return 0;
    }
  debug ("Showing form...%p MJA MJAMJA", ptr);
  show_form (currwindow, ptr);

  debug ("Done");
  gtk_widget_show_all (GTK_WIDGET (currwindow));
  debug_last_field_created ("disp_form 2");
  gui_run_til_no_more ();
  return 1;
}

/**
 * Get a GTK GUI window.
 *
 * @param a The window number.
 */
GtkWidget *
get_window_gtk (int a)
{
  debug ("Looking up window for screen %d\n", a);
  return windows[a - 1];
}

/**
 * Make a refresh in the windows in GUI mode in the z axys.
 */
void
zrefresh (void)
{
  if (screen_mode(-1)) {
  	gui_run_til_no_more ();
  }

}


/**
 * GTK GUI implementation of CURRENT WINDOW IS 4gl statement.
 *
 * @param s The window name.
 */
void
current_window (char *s)
{
GtkWindow *w;
static GtkWidget *b=0;

	/* If we are not using formhandlers then we need to
	   ensure modality with the currwindow...
	*/
  debug ("Finding window to make current %s\n", s);
  w = find_pointer (s, WINCODE);

  debug(" Found : %p\n",w);
  gtkwin_stack(w,'^');

  if (!has_pointer (s, WINCODE))
    {
      exitwith ("Window is not open");
      return;
    }

	debug("Set_current %p",w);
	set_current_window (w);

strcpy(currwinname,s);
  if (strcmp (s, "screen") != 0)
    {
strcpy(currwinname,"SCREEN");

      if (b)
	{
	  b = gtk_object_get_data (GTK_OBJECT (w), "FRAME");
	  debug ("2. Hiding (%s) %p\n", s, b);
	  gtk_widget_hide (b);
	  gtk_widget_show (b);
	}

      b = gtk_object_get_data (GTK_OBJECT (w), "TOP");
      debug ("1.Hiding (%s) %p\n", s, b);
      if (b==0) b=(GtkWidget*)w;

        /*
		  GtkWindow *w;
		  static GtkWidget *b=0;
        */


      gtk_widget_hide (b);
      gtk_widget_show_all (b);
    }
  gui_run_til_no_more ();
}


/**
 * Finds the 4gl current window
 *
 * @return The current window
 */
GtkWindow *
get_curr_win_gtk (void)
{
  debug("Current window : %p",currwindow);
  return GTK_WINDOW(currwindow);
}


/**
 * GTK GUI implementation of DISPLAY AT 4gl statement.
 *
 * @param n The row where the display is made.
 * @param a The column where the display is made.
 */
void
display_at (int n, int a)
{
int x, y;
int z;
char *s=0;
char *ptr; char *buff2=0;
GtkFixed *cwin;
GtkLabel *lab;
char buff[256];

  x = pop_int ();
  y = pop_int ();
  s=malloc(2);
  s[0]=0;
  debug("Got %d arguments");
  for (z = 0; z <= n - 1; z++)
    {
        ptr=char_pop();
        debug("DISPLAY_AT : '%s'\n",ptr);
        buff2=realloc(buff2,strlen(s)+strlen(ptr)+1);
        s=realloc(s,strlen(s)+strlen(ptr)+1);
        sprintf(buff2,"%s%s",ptr,s);
        strcpy(s,buff2);
        debug("s='%s' %p\n",s,s);
    }
  debug ("Display @ x=%d y=%d s=%s\n", x, y, s);

  if (x == -1 && y == -1)
    {
      printf ("%s\n", s);
      add_to_console (s);
    }
  else
    {
      x--;
      y--;
      cwin = (GtkFixed *) get_curr_win_gtk ();
      sprintf (buff, "LABEL_%d_%d", x, y);
      lab = (GtkLabel *) gtk_object_get_data (GTK_OBJECT (cwin), buff);

      if (lab)
	{
	  if (strlen (s))
	    {

      		gui_set_field_fore((GtkWidget *)lab, decode_colour_attr_aubit(a));

	      gtk_label_set_text (lab, s);
	      gtk_widget_show (GTK_WIDGET (lab));
	    }
	  else
	    {
	      gtk_widget_destroy (GTK_WIDGET (lab));

	      gtk_object_set_data (GTK_OBJECT (cwin), buff, 0);
	    }
	}
      else
	{

	  if (strlen (buff))
	    {
	      lab = (GtkLabel *) gtk_label_new (s);
      	gui_set_field_fore((GtkWidget *)lab, decode_colour_attr_aubit(a));

		  gtk_fixed_put (GTK_FIXED (cwin), GTK_WIDGET (lab), x * XWIDTH,
			     y * YHEIGHT);
	      gtk_object_set_data (GTK_OBJECT (cwin), buff, lab);
	      gtk_widget_show (GTK_WIDGET (lab));
	    }
	}

    }
  gui_run_til_no_more ();

  free (s);

}

/**
 * GTK GUI implementation of SLEEP 4gl statement.
 */
void
sleep_i (void)
{
  int a;
  int c;
  int b;
  a = pop_int ();

  for (c = 0; c < a; c++)
    {
      for (b = 0; b <= 9; b++)
	{
	  a4gl_usleep (100000);
	  gui_run_til_no_more ();
	}
    }

}

/**
 * Change the shown of the console.
 *
 * If its shown hide it, otherwise show it.
 */
void
console_toggle (void)
{
  static int shown = 0;
  shown = 1 - shown;
  if (shown)
    show_console ();
  else
    hide_console ();
}

/**
 * Show the console widget.
 */
void
show_console (void)
{
  gtk_widget_show (GTK_WIDGET (console));
}


/**
 * Hide the console widget.
 */
void
hide_console (void)
{
  gtk_widget_hide (GTK_WIDGET (console));
}

/**
 * Append a string to the console list widget.
 */
void
add_to_console (char *s)
{
  gtk_clist_append (GTK_CLIST (console_list), &s);
}

/**
 * Clear the data showed n the console.
 */
void
clear_console (char *s)
{
  gtk_clist_clear (GTK_CLIST (console_list));
}


/**
 * Create the console widget.
 *
 * @todo : Define what is the console widget.
 */
void
create_console (void)
{
  GtkWidget *scroll;

  console = (GtkWindow *) gtk_window_new (GTK_WINDOW_TOPLEVEL);
  scroll = gtk_scrolled_window_new (NULL, NULL);

  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scroll),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  gtk_widget_show (scroll);

  console_list = gtk_clist_new (1);	/* 1 column for now.... */

  gtk_clist_set_selection_mode (GTK_CLIST (console_list),
				GTK_SELECTION_SINGLE);
  gtk_clist_set_shadow_type (GTK_CLIST (console_list), GTK_SHADOW_IN);

  gtk_container_add (GTK_CONTAINER (scroll), console_list);
  gtk_container_add (GTK_CONTAINER (console), scroll);
  gtk_widget_show (console_list);
  gtk_window_set_title (console, "4GL Console");

  gtk_signal_connect (GTK_OBJECT (console), "delete_event",
		      GTK_SIGNAL_FUNC (gtk_widget_hide), NULL);
  gdk_window_set_functions ((GdkWindow *) console,
			    GDK_FUNC_RESIZE + GDK_FUNC_MOVE +
			    GDK_FUNC_MINIMIZE + GDK_FUNC_MAXIMIZE);
}

/**
 * GTK GUI implementation of CLEAR FORM 4gl statement.
 *
 * @param The form name.
 */
int
close_form (char *name)
{
  debug ("close_form_gtk: Not implemented");
  return 0;
}

/**
 * @todo 
 */
int
/* open_gui_form (char *name_orig, int absolute,int nat, char *like, int disable, void *handler_e,void (*handler_c())) */
open_gui_form (char *name_orig, int absolute,int nat, char *like, int disable, void *handler_e,void (*handler_c(int a, int b)))
{
  GtkWindow *win;
  GtkFixed *fixed;
  GtkFixed *form;
  char name[256];
  char formname[256];
  struct struct_form *the_form;
  int a;

  strcpy(name,name_orig);
  decode_gui_winname(name);
  if (like&&strlen(like))
    {
      strcpy (formname, like);
    }
  else
    {
      strcpy (formname, name);
    }


  //strcat (formname, acl_getenv ("A4GL_FRM_BASE_EXT"));

  win = (GtkWindow *) gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (win), "");

  if (win == 0)
    {
      debug ("No window created!");
      exitwith ("Unable to create new window");
      return 0;
    }

  fixed = (GtkFixed *) gtk_fixed_new ();

  gtk_widget_show (GTK_WIDGET (fixed));

  gtk_container_add (GTK_CONTAINER (win), GTK_WIDGET (fixed));


  set_current_window (win);
  /* win = fixed; */

  /* add_pointer (name, WINCODE, fixed); */
  add_pointer (name, WINCODE, win);

  gtk_signal_connect (GTK_OBJECT (win), "delete_event", GTK_SIGNAL_FUNC (handler_e), win);
  gtk_signal_connect (GTK_OBJECT (win), "destroy", GTK_SIGNAL_FUNC (handler_e), win);
  /*
  gtk_signal_connect (GTK_OBJECT (win), "motion_notify", GTK_SIGNAL_FUNC (handler_e), win);
  gtk_signal_connect (GTK_OBJECT (win), "key_press_event", GTK_SIGNAL_FUNC (handler_e), win);
  gtk_signal_connect (GTK_OBJECT (win), "key_release_event", GTK_SIGNAL_FUNC (handler_e), win);
  */
  gtk_signal_connect (GTK_OBJECT (win), "focus_in_event", GTK_SIGNAL_FUNC (handler_e), win);
  /*
  gtk_signal_connect (GTK_OBJECT (win), "focus_out_event", GTK_SIGNAL_FUNC (handler_e), win);
  gtk_signal_connect (GTK_OBJECT (win), "other_event", GTK_SIGNAL_FUNC (handler_e), win);
  gtk_signal_connect (GTK_OBJECT (win), "enter_notify_event", GTK_SIGNAL_FUNC (handler_e), win);
  gtk_signal_connect (GTK_OBJECT (win), "leave_notify_event", GTK_SIGNAL_FUNC (handler_e), win);
  gtk_signal_connect (GTK_OBJECT (win), "key-press-event",
		      GTK_SIGNAL_FUNC (handler_e), win);
  */

  form = (GtkFixed *) read_form_gtk (formname,"uhmmm");
  printf(">>>>      Setting currform...\n");
  debug(">>>>      Setting currform... for %p  to %p\n",fixed,form);
  if (form==0) {
	exitwith("Unable to open form");
	return 0;
  }
  gtk_object_set_data (GTK_OBJECT (win), "currform", form);

  gtk_fixed_put (GTK_FIXED (fixed), GTK_WIDGET (form), 0, 0);
  gtk_widget_show (GTK_WIDGET (form));
  gtk_widget_show_all (GTK_WIDGET (win));

  handler_c(0,0);

  the_form = gtk_object_get_data (GTK_OBJECT (form), "xdr_form");

  for (a = 0; a < the_form->metrics.metrics_len; a++)
  {
    debug ("%p -> ", the_form->metrics.metrics_val[a].field);
	  gtk_object_set_data(
		  (GtkObject *)the_form->metrics.metrics_val[a].field,
			"HANDLER",
			handler_c
		);
  }


  gtk_widget_show (GTK_WIDGET (win));

  gui_run_til_no_more ();

  return 1;
}

/**
 *
 */
void
decode_gui_winname(char *name)
{
char buff[256];
char *ptr;
	strcpy(buff,name);
	ptr=strchr(name,'_');
	debug("Decoding name %s - ptr=%p",name,ptr);
	if (ptr) {
		strcpy(buff,ptr+1);
		debug("Buff=%s\n",buff);
		strcpy(name,buff);
	}
}

/**
 * Does nothing for a gui - it is used in CURSES mode to drop into
 * line mode, but we need it for API_ui
 *
 */
void
gotolinemode(void)
{
	debug("Set gotolinemode");
}

/**
 *
 */
int
decode_colour_attr_aubit(int a)
{
char colour[20];
char attr[256];
	get_strings_from_attr(a,colour,attr);
	if (strcmp(colour,"BLACK")==0)   return 0;
	if (strcmp(colour,"RED")==0)     return 1;
	if (strcmp(colour,"GREEN")==0)   return 2;
	if (strcmp(colour,"YELLOW")==0)  return 3;
	if (strcmp(colour,"BLUE")==0)    return 4;
	if (strcmp(colour,"MAGENTA")==0) return 5;
	if (strcmp(colour,"CYAN")==0)    return 6;
	if (strcmp(colour,"WHITE")==0)   return 7;
	return 0;
}

/**
 *
 */
struct struct_screen_record *
get_srec_gtk (char *name)
{
int a;
struct_form *formdets;
void *fd1;
void *cwin;

  cwin = (GtkFixed *) get_curr_win_gtk ();
  fd1 = gtk_object_get_data(GTK_OBJECT(cwin), "currform");
  debug ("fd1=%p\n", fd1);
  formdets = gtk_object_get_data (fd1, "xdr_form");

  a = find_srec (formdets, name);

  debug ("Got %d", a);

  if (a == -1)
    return (struct struct_screen_record *) 0;
  else
    return (struct struct_screen_record *) &formdets->records.records_val[a];
}



char *get_currwin_name() {
	return currwinname;
}
/* ================================ EOF ================================ */



void dump_object(GtkObject *o) {
	debug("Object : %p\n");
/*
	debug("type:%d ",o->klass->type);

gtk_4gl.c: In function `dump_object':
gtk_4gl.c:1296: structure has no member named `klass'

*/


}
