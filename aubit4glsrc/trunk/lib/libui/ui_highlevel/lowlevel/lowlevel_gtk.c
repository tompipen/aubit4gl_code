
#if (defined(WIN32) && ! defined(__CYGWIN__))
	//BOOL __stdcall
	//set_intr_win32 (DWORD type)
	int set_intr_win32 (int type);
#endif


#include "a4gl_libaubit4gl.h"
#include "hl_proto.h"
#include "a4gl_API_lowlevel.h"
#include "a4gl_API_ui_lib.h"
#include "a4gl_incl_4gldef.h"
#include "../hl_forms.h"

#include "lowlevel.h"
#include "formdriver.h"
#include "low_gtk.h"
#include <ctype.h>
#ifndef lint
static char const module_id[] =
  "$Id: lowlevel_gtk.c,v 1.123 2007-07-08 16:13:01 mikeaubury Exp $";
#endif


#define A4GL_GTK_FONT_FIXED "Fixed 10"
int gui_yheight = 20;		// 25
static int has_stock_item (char *s);
static int stock_item (char *name, char*txt, char*img,GtkWidget **w);
int gui_xwidth = 9;
void textField_focus(GtkWidget * w, char *mode) ;
static int menu_response = -1;
void A4GL_gui_prompt_style (int a);
//static void register_my_stock_icons_in_dir (char *baseDir);
//void *A4GL_get_currwin (void);
//int A4GLHLUI_initlib(void);
void tstamp (char *s);
int A4GL_LL_disp_form_field_ap (int n, int attr, char *s, va_list * ap);
static char A4GL_menu_pos (void);
static void setup_ok_cancel (GtkWidget * ok_cancel);
//int A4GL_LL_construct_large(char *orig, struct aclfgl_event_list *evt,int init_key,int initpos) ;
int A4GL_LL_fieldnametoid (char *f, char *s, int n);
void A4GL_win_stack (struct s_windows *w, int op);
int A4GL_display_generic (GtkWidget * k, char *s,char *orig);
//int A4GL_has_event (int a, struct aclfgl_event_list *evt);
//int A4GL_has_event_for_keypress (int a, struct aclfgl_event_list *evt);
//int A4GL_has_event_for_field (int cat, char *a, struct aclfgl_event_list *evt);
GtkWidget *A4GL_make_widget (char *widget, char *config, int w,int h);
//void A4GL_clear_prompt(struct s_prompt *prmt) ;
void A4GL_getxy_coords (int *x, int *y);
void A4GL_show_console (void);
void A4GL_hide_console (void);
int A4GL_getx_coords (int x);
int A4GL_gety_coords (int x);
void A4GL_console_toggle (void);
void setMenu(GtkWidget *w,int on) ;
void A4GL_add_to_console (char *s);
void A4GL_clear_console (char *s);
void A4GL_create_console (void);
static void SetMenuButton(GtkWidget *b, char *txt,GtkWidget *i) ;
//int A4GL_LL_field_opts (void *field);
static int use_frames(void) ;
char *thisApp=0;
static void register_my_stock_icons (void);
static void SetButton(GtkWidget *b, char *txt,GtkWidget *i,char orientation, int isToolbarItem) ;
//void A4GL_logkey(long a);
//

#define NTOOLBARITEMS 2000
void *toolbarItems[NTOOLBARITEMS];
int toolbarItemsCnt=0;

struct sAubitStock {
	char *txt;
	char *name;
	char *img;
	GtkWidget *loadedImage;
};

struct sAubitStock *AubitStock=0;
int nAubitStock=0;
void AddAubitStock(char *name, char *txt, char *img) ;

char *currentCmd=0;
void *currentSio=0;


//void ActivateToolbar(char *cmd, struct aclfgl_event_list *list) ;
int A4GL_gtkdialog (char *caption, char *icon, int buttons, int defbutt,
		    int dis, char *msg);
int KeySnooper (GtkWidget * grab_widget, GdkEventKey * event,
		gpointer func_data);
int A4GL_which_key_aubit (int gdk_key);
char *A4GL_decode_str_fprop (struct_scr_field * fprop, int type);
void MyStyleSetItemColor (GdkColor color,	/* The allocated color to be added to the style */
			  char item,	/* the item to which the color is to be applied */
			  /* 'f' = foreground; 'b' = background; */
			  /* 'l' = light;      'd' = dark; */
			  /* 'm' = mid;        't' = text; */
			  /* 's' = base. */
			  GtkStyle * style	/* The old style - changes made to a copy */
  );
void A4GL_alloc_colors (void);
void A4GL_gui_set_active (GtkWidget * w, int en_dis);
void *AddButtonToolbar(GtkWidget *toolbar, char *tag, char *buttonText,char *Stock, char *toolTip, int keyval) ;
GtkWidget *last_construct_drwin = 0;
static void A4GL_dobeep(void ) ;

int window_frame_type = 0;
char *A4GL_fld_val_generic (GtkWidget * k);
void *win_screen;
int frame_style = GTK_SHADOW_IN;
int A4GL_delete_event (GtkWidget * widget, GdkEvent * event, gpointer data);
int A4GL_destroy_event (GtkWidget * widget, gpointer data);
int A4GL_keypress (GtkWidget * widget, GdkEventKey * event, gpointer user_data);
void A4GL_run_gtkrc (void);
void A4GL_decode_gui_winname (char *name);
int menu_callback (gpointer data);
//int A4GL_LL_hide_h_menu(ACL_Menu *menu);
void A4GL_LL_screen_refresh (void);
static int cancel_callback (gpointer data);
static int ok_callback (gpointer data);
static int A4GL_show_ok_cancel (int n);
int A4GL_fake_a_keypress (GtkWidget * widget, int key);
static void A4GL_default_attributes_in_ll (void *f, int dtype,
					   int has_picture);
#if GTK_CHECK_VERSION(2,0,0)
#else
#define gunichar unsigned int
#endif

GtkWindow *appWin=0;

void A4GL_LL_wadd_gunichar_xy_col (void *win, int x, int y, gunichar ch,
				   int curr_width, int curr_height,
				   int iscurrborder, int currwinno);

#define KEY_BUFFER_SIZE 256
int keybuffer[KEY_BUFFER_SIZE];
int keybuffer_cnt = 0;


void *last_prompt_field = 0;
void *last_prompt_f = 0;
void *last_prompt_win = 0;
long last_prompt_mode = 0;
GtkWidget *toolbar=0;



GtkWidget *tooltips = 0;	/** Tooltip widget */
GtkWindow *console = 0;
GtkWidget *console_list;
static int allocated_colors = 0;
GdkColormap *colormap;
GdkColor gdkColors[8] = {
  {0, 0, 0, 0},
  {0, 0xffff, 0, 0},
  {0, 0, 0xffff, 0},
  {0, 0xffff, 0xffff, 0},
  {0, 0, 0, 0xffff},
  {0, 0xffff, 0, 0xffff},
  {0, 0, 0xffff, 0xffff},
  {0, 0xffff, 0xffff, 0xffff}
};


GtkStyle *colorStyles[8];
GtkStyle *rcolorStyles[8];
GtkWidget *actionfield = 0;
int keypressed = 0;
GtkWidget *errorWindow = 0;


struct s_a4gl_gtk_form
{
  int frmMagic;
  int nwidgets;
  int npages;
  int currentpage;
  int currentfield;
  int curcol;
  int ovlins;

  GtkWidget **widgets;
  GtkWidget *notebook;
  void *userptr;
};


/****************************************************************************/



static int
A4GL_fld_opts_on (void *v, int n)
{

  if (A4GL_LL_field_opts (v) & n) return 1;
  A4GL_LL_set_field_opts (v, A4GL_LL_field_opts (v) + n); return 1;
}

static int
A4GL_fld_opts_off (void *v, int n)
{
  if (!(A4GL_LL_field_opts (v) & n))
    return 1;
  A4GL_LL_set_field_opts (v, A4GL_LL_field_opts (v) - n);
  return 1;
}

/**
 * 
 * 
 * @todo : Please describe this function.
 */
int
A4GL_getx_coords (int x)
{
  int x1;
  int y1;
  x1 = x - 1;
  y1 = 0;
  A4GL_getxy_coords (&x1, &y1);
  return x1;
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
int
A4GL_gety_coords (int y)
{
  int x1;
  int y1;
  x1 = 0;
  y1 = y - 1;
  A4GL_getxy_coords (&x1, &y1);
  return y1;
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
void
A4GL_getxy_coords (int *x, int *y)
{
  *x = (*x) * XWIDTH;
  *y = (*y) * YHEIGHT;
}



/**
 * 
 * 
 * @todo : Please describe this function.
 */
static int
get_keypress_from_buffer ()
{
  int cp[KEY_BUFFER_SIZE - 1];
  int k;
  if (keybuffer_cnt == 0)
    {
      return -1;
    }
  memcpy (&cp[0], &keybuffer[1], sizeof (cp));
  k = keybuffer[0];
  memcpy (&keybuffer[0], &cp[0], sizeof (cp));
  keybuffer_cnt--;
  return k;
}



/**
 * 
 * 
 * @todo : Please describe this function.
 */
static void
add_keypress (int a)
{
  if (keybuffer_cnt >= KEY_BUFFER_SIZE)
    {
      A4GL_LL_beep ();
      return;
    }
  keybuffer[keybuffer_cnt++] = a;
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
static int
ok_callback (gpointer data)
{
  add_keypress (std_dbscr.acckey);
  return TRUE;
}

/**
 * 
 * 
 * @todo : Please describe this function.
 */
static int
cancel_callback (gpointer data)
{
#if (defined(WIN32) && ! defined(__CYGWIN__))
  set_intr_win32 (SIGINT);
#else
  kill (0, SIGINT);
#endif
  add_keypress (3);
  return TRUE;
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
static void
setup_ok_cancel (GtkWidget * ok_cancel)
{
#if GTK_CHECK_VERSION(2,0,0)
#else
  GtkWidget *l;
#endif
  GtkWidget *b;

#if GTK_CHECK_VERSION(2,0,0)
  b = gtk_button_new_from_stock (GTK_STOCK_OK);
#else
  b = gtk_button_new ();
  l = gtk_label_new ("OK");
  gtk_container_add (GTK_CONTAINER (b), l);
  gtk_widget_set_name (GTK_WIDGET (b), "OK");
  gtk_object_set_data (GTK_OBJECT (b), "LABEL", l);
  gtk_widget_show (l);
#endif
  gtk_signal_connect_object (GTK_OBJECT (b), "clicked",
			     GTK_SIGNAL_FUNC (ok_callback), 0);
  gtk_widget_show (b);

  gtk_container_add (GTK_CONTAINER (ok_cancel), b);

  // Set up the Cancel Button

#if GTK_CHECK_VERSION(2,0,0)
  b = gtk_button_new_from_stock (GTK_STOCK_CANCEL);
#else
  b = gtk_button_new ();
  l = gtk_label_new ("Cancel");
  gtk_container_add (GTK_CONTAINER (b), l);
  gtk_widget_set_name (GTK_WIDGET (b), "Cancel");
  gtk_object_set_data (GTK_OBJECT (b), "LABEL", l);
  gtk_widget_show (l);
#endif
  gtk_signal_connect_object (GTK_OBJECT (b), "clicked",
			     GTK_SIGNAL_FUNC (cancel_callback), 0);
  gtk_widget_show (b);
  gtk_container_add (GTK_CONTAINER (ok_cancel), b);

}

/**
 * 
 * 
 * @todo : Please describe this function.
 */
int
A4GL_keypress (GtkWidget * widget, GdkEventKey * event, gpointer user_data)
{

  if (event->state & 4)
    {				/*  Control key held down... */
      if (a4gl_tolower (event->keyval) >= 'a'
	  && a4gl_tolower (event->keyval) <= 'z')
	keypressed = a4gl_tolower (event->keyval) - 'a' + 1;
      else
	keypressed = -1;
    }
  else
    {
      keypressed = event->keyval;
    }

  add_keypress (keypressed);
  actionfield = widget;
  return keypressed;
}


int
A4GL_fake_a_keypress (GtkWidget * widget, int key)
{
  keypressed = key;
  add_keypress (keypressed);
  return keypressed;
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
void
A4GL_console_toggle (void)
{
  static int shown = 0;
  shown = 1 - shown;
  if (shown)
    A4GL_show_console ();
  else
    A4GL_hide_console ();
}


/**
 * Show the console widget.
 */
void
A4GL_show_console (void)
{
  gtk_widget_show (GTK_WIDGET (console));
}


/**
 * Hide the console widget.
 */
void
A4GL_hide_console (void)
{
  gtk_widget_hide (GTK_WIDGET (console));
}

/**
 * Append a string to the console list widget.
 */
void
A4GL_add_to_console (char *s)
{
  char *utf;

		//printf("txt=%s\n",s);
  utf = g_locale_to_utf8 (s, -1, NULL, NULL, NULL);
  gtk_clist_append (GTK_CLIST (console_list), &utf);
  g_free (utf);
}

/**
 * Clear the data showed n the console.
 */
void
A4GL_clear_console (char *s)
{
  gtk_clist_clear (GTK_CLIST (console_list));
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
gint
A4GL_delete_event (GtkWidget * widget, GdkEvent * event, gpointer data)
{

  //g_print ("delete event occurred\n");

  /* Change TRUE to FALSE and the main window will be destroyed with
   * a "delete_event". */
  return (FALSE);
}

/**
 * 
 * 
 * @todo : Please describe this function.
 */
int
A4GL_destroy_event (GtkWidget * widget, gpointer data)
{
  A4GL_debug (" A4GL_destroy_event : widget=%p data=%x\n", widget, data);
  //gtk_main_quit ();
  A4GL_fgl_end_4gl_0 ();

  return FALSE;
}


/**
 * Create the console widget.
 *
 * @todo : Define what is the console widget.
 */
void
A4GL_create_console (void)
{


  GtkWidget *scroll;

  A4GL_debug ("A4GL_create_console");

  console = (GtkWindow *) gtk_window_new (GTK_WINDOW_TOPLEVEL);
  if (!console)
    A4GL_debug ("gtk_window_new: NULL");

  scroll = gtk_scrolled_window_new (NULL, NULL);
  if (!scroll)
    A4GL_debug ("gtk_scrolled_window_new: NULL");

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

/*
  gdk_window_set_functions ((GdkWindow *) console,
                            GDK_FUNC_RESIZE + GDK_FUNC_MOVE +
                            GDK_FUNC_MINIMIZE + GDK_FUNC_MAXIMIZE);
*/

  A4GL_debug ("console created");

}

/**
 * 
 * 
 * @todo : Please describe this function.
 */
static void
dialog_callback (GtkWidget * widget, gpointer data)
{
  GtkObject *win;
  win = GTK_OBJECT (widget);
  A4GL_debug ("Win=%p\n", win);
  gtk_object_set_data (GTK_OBJECT (win), "RETURNS",
		       gtk_object_get_data (data, "BUTCODE"));
  A4GL_debug ("Set code to %d\n", gtk_object_get_data (win, "RETURNS"));
  /* gtk_main_quit(); */
}


/**
 * Add a new button to the dialog.
 *
 * @param win A pointer to the dialog widget.
 * @param but_code The button type code.
 */
static void
add_button (GtkDialog * win, int but_code)
{
  char *txt;
  char *txt_utf=0;
  GtkButton *but;

  switch (but_code)
    {
    case BUTTON_OK:
      txt = acl_getenv ("A4GL_DIALOG_OK");
      break;
    case BUTTON_CANCEL:
      txt = acl_getenv ("A4GL_DIALOG_CANCEL");
      break;
    case BUTTON_ABORT:
      txt = acl_getenv ("A4GL_DIALOG_ABORT");
      break;
    case BUTTON_RETRY:
      txt = acl_getenv ("A4GL_DIALOG_RETRY");
      break;
    case BUTTON_IGNORE:
      txt = acl_getenv ("A4GL_DIALOG_IGNORE");
      break;
    case BUTTON_YES:
      txt = acl_getenv ("A4GL_DIALOG_YES");
      break;
    case BUTTON_NO:
      txt = acl_getenv ("A4GL_DIALOG_NO");
      break;
    default:
      txt = "FIXME: unknown Button";
      A4GL_debug ("add_button: unknown button-code: %d\n", but_code);
    }

		//printf("txt=%s\n",txt);
  txt_utf = g_locale_to_utf8 (txt, -1, NULL, NULL, NULL);

  gtk_object_set_data (GTK_OBJECT (win), "RETURNS", 0);
  but = (GtkButton *) gtk_button_new_with_label (txt_utf);
  g_free (txt_utf);

  gtk_object_set_data (GTK_OBJECT (but), "BUTCODE", (gpointer) but_code);
  gtk_object_set_data (GTK_OBJECT (but), "DIALOGWIN", win);
  gtk_container_add (GTK_CONTAINER (GTK_DIALOG (win)->action_area),
		     (GtkWidget *) but);
  gtk_signal_connect_object (GTK_OBJECT (but), "clicked",
			     GTK_SIGNAL_FUNC (dialog_callback),
			     GTK_OBJECT (win));
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
int
A4GL_gtkdialog (char *caption, char *icon, int buttons, int defbutt, int dis,
		char *msg)
{
  int rval;
  GtkDialog *win;
  GtkLabel *label;
  char *label_utf;

/* Only do modal for now... */
  dis = DIALOG_DISABLE_ALL;
  win = (GtkDialog *) gtk_dialog_new ();
  A4GL_debug ("In A4GL_gtkdialog msg=%s\n", msg);

  gtk_window_set_modal ((GtkWindow *) win, 1);

  gtk_signal_connect (GTK_OBJECT (win),
		      "delete_event", GTK_SIGNAL_FUNC (gtk_true), NULL);
  if (msg) {
		//printf("txt=%s\n",msg);
    label_utf = g_locale_to_utf8 (msg, -1, NULL, NULL, NULL);
	}
  else {
    label_utf = NULL;
	}
  label = (GtkLabel *) gtk_label_new (label_utf);
#if GTK_CHECK_VERSION(2,0,0)
  if (A4GL_isyes (acl_getenv ("A4GL_USE_PANGO_ML")))
    {
      A4GL_debug ("using PANGO ML for Label '%s'\n", msg);
      gtk_label_set_use_markup (GTK_LABEL (label), TRUE);
    }
#endif
  g_free (label_utf);
  gtk_container_add (GTK_CONTAINER (GTK_DIALOG (win)->vbox),
		     GTK_WIDGET (label));

  if (strlen (caption))
    {
		//printf("txt=%s\n",caption);
      label_utf = g_locale_to_utf8 (caption, -1, NULL, NULL, NULL);
      gtk_window_set_title (GTK_WINDOW (win), label_utf);
      g_free (label_utf);
    }

  switch (buttons)
    {
    case BUTTONS_OK:
      add_button (win, BUTTON_OK);
      break;
    case BUTTONS_OK_CANCEL:
      add_button (win, BUTTON_OK);
      add_button (win, BUTTON_CANCEL);
      break;
    case BUTTONS_RETRY_CANCEL:
      add_button (win, BUTTON_RETRY);
      add_button (win, BUTTON_CANCEL);
      break;
    case BUTTONS_ABORT_RETRY_IGNORE:
      add_button (win, BUTTON_ABORT);
      add_button (win, BUTTON_RETRY);
      add_button (win, BUTTON_IGNORE);
      break;

    case BUTTONS_YES_NO:
      add_button (win, BUTTON_YES);
      add_button (win, BUTTON_NO);
      break;

    case BUTTONS_YES_NO_CANCEL:
      add_button (win, BUTTON_YES);
      add_button (win, BUTTON_NO);
      add_button (win, BUTTON_CANCEL);
      break;
    }
  gtk_widget_show_all (GTK_WIDGET (win));
  rval = 0;
  while (1)
    {
      a4gl_usleep (100);
      rval = (int) gtk_object_get_data (GTK_OBJECT (win), "RETURNS");
      if (rval)
	break;
      while (gtk_events_pending ())
	gtk_main_iteration ();
    }

  gtk_widget_destroy (GTK_WIDGET (win));

  return rval;
}



/**
 * 
 * 
 * @todo : Please describe this function.
 */
int
KeySnooper (GtkWidget * grab_widget, GdkEventKey * event, gpointer func_data)
{
  A4GL_debug ("Key Snooper... %p %p %p\n", grab_widget, event, func_data);
  A4GL_debug ("Key Pressed! %x %x (%s)\n", event->keyval, event->state,
	      gtk_accelerator_name (event->keyval, event->state));

  if (event->keyval == 0xffbe && event->state == 1)
    {
      A4GL_debug ("Toggle console...");
      A4GL_console_toggle ();
    }

  fflush (stdout);
  if (strcmp
      (gtk_accelerator_name (event->keyval, event->state), "<Control>c") == 0)
    {
      A4GL_keypress (grab_widget, event, func_data);
    }



  /*
     if (strcmp (gtk_accelerator_name (event->keyval, event->state), "Escape") == 0)
     {
     //event->keyval=27;
     A4GL_keypress (grab_widget, event, func_data);
     }
   */
  //A4GL_clr_error_gtk ();
  //
  //
  //
  return 0;
}

void MyStyleSetItemColor (GdkColor color,	/* The allocated color to be added to the style */
			  char item,	/* the item to which the color is to be applied */
			  /* 'f' = foreground; 'b' = background; */
			  /* 'l' = light;      'd' = dark; */
			  /* 'm' = mid;        't' = text; */
			  /* 's' = base. */
			  GtkStyle * style	/* The old style - changes made to a copy */
  )
{
  int i;
  switch (item)
    {
    case 'f':
    case 'F':
      for (i = 0; i < 5; i++)
	style->fg[i] = color;
      break;
    case 'b':
    case 'B':
      for (i = 0; i < 5; i++)
	style->bg[i] = color;
      break;
    case 'l':
    case 'L':
      for (i = 0; i < 5; i++)
	style->light[i] = color;
      break;
    case 'd':
    case 'D':
      for (i = 0; i < 5; i++)
	style->dark[i] = color;
      break;
    case 'm':
    case 'M':
      for (i = 0; i < 5; i++)
	style->mid[i] = color;
      break;
    case 't':
    case 'T':
      for (i = 0; i < 5; i++)
	for (i = 0; i < 5; i++)
	  style->text[i] = color;
      break;
    case 's':
    case 'S':
      for (i = 0; i < 5; i++)
	style->base[i] = color;
      break;
    }
}



/**
 * 
 * 
 * @todo : Please describe this function.
 */
void
A4GL_alloc_colors (void)
{
  int a;
  GtkStyle *default_style;

  return;
  colormap = gdk_colormap_get_system ();
  default_style = gtk_widget_get_default_style ();

  /* Allocate the colors first... */
  for (a = 0; a < 8; a++)
    {
      gdk_colormap_alloc_color (colormap, &gdkColors[a], FALSE, TRUE);
      colorStyles[a] = gtk_style_copy (default_style);
      rcolorStyles[a] = gtk_style_copy (default_style);

      MyStyleSetItemColor (gdkColors[a], 'f', colorStyles[a]);
      MyStyleSetItemColor (gdkColors[a], 'b', rcolorStyles[a]);



    }

  allocated_colors = 1;
}

/**
 * 
 * 
 * @todo : Please describe this function.
 */
int
A4GL_LL_colour_code (int a)
{
  return a;
}

/**
 * 
 * 
 * @todo : Please describe this function.
 */
void *
A4GL_LL_create_window (int h, int w, int y, int x, int border)
{
  GtkWidget *fixed = 0;
  GtkWidget *win = 0;
  GtkWidget *frame = 0;
  GtkWidget *wxx = 0;
  GtkWidget *MainFrame=0;
  int useToolbar=1;
	int additional_y;

  if (x == 0 && y == 0 && h == 0 && w == 0)
    {
      int additional;
      GtkWidget *hbox;
      GtkWidget *fglmenu_bb;
      GtkWidget *ok_cancel;
      GtkWidget *frame;

      additional = 0;
      additional_y = 0;
      if (!A4GL_isyes (acl_getenv ("TRADMENU")))
	{
	  additional = 15;
	}

      if (useToolbar) {
		additional_y+=50;
	}
      win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

      //FPRINTF (stderr, "Screen size : %d %d\n",
	       //(A4GL_LL_screen_width () + additional) * gui_xwidth,
	       //(A4GL_LL_screen_height () + 1) * gui_yheight +additional_y);
      gtk_window_set_default_size (GTK_WINDOW (win), (A4GL_LL_screen_width () + additional) * gui_xwidth, (A4GL_LL_screen_height () + 1) * gui_yheight + additional_y);
      gtk_window_set_title (GTK_WINDOW (win), "4GL Application");
  	thisApp=A4GL_get_running_program();
	appWin=(GtkWindow *)win;

  	if (has_stock_item(thisApp)) {
		char AppText[256]="";
		char AppImg[256]="";
		stock_item(thisApp,AppText,AppImg,NULL);
		if (strlen(AppText)) {
      			gtk_window_set_title (GTK_WINDOW (win), AppText);
		}
		if (strlen(AppImg)) {
			gtk_window_set_icon_from_file  (GTK_WINDOW (win), AppImg, NULL);
		}
		
	
  	}
      gtk_widget_set_name (GTK_WIDGET (win), "AppWindow");

      if (A4GL_menu_pos () == 'T' || A4GL_menu_pos () == 'B')
	{
	  hbox = gtk_vbox_new (0, 3);
	}
      else
	{
	  hbox = gtk_hbox_new (0, 3);
	}
      if (A4GL_menu_pos () == 'T' || A4GL_menu_pos () == 'B')
	{
	  fglmenu_bb = gtk_hbutton_box_new ();
	  ok_cancel = gtk_hbutton_box_new ();
	}
      else
	{
	  fglmenu_bb = gtk_vbutton_box_new ();
	  ok_cancel = gtk_vbutton_box_new ();
	}
      gtk_widget_set_name (GTK_WIDGET (fglmenu_bb), "MenuButtons");
      gtk_widget_set_name (GTK_WIDGET (ok_cancel), "OKCancel");
      setup_ok_cancel (ok_cancel);
      gtk_button_box_set_layout (GTK_BUTTON_BOX (fglmenu_bb), GTK_BUTTONBOX_START);
      gtk_button_box_set_layout (GTK_BUTTON_BOX (ok_cancel), GTK_BUTTONBOX_START);

	if (useToolbar) {
      		gtk_widget_hide (ok_cancel);	
	}

      gtk_widget_set_name (GTK_WIDGET (hbox), "MenuButtons");
      gtk_widget_show (hbox);
      if (!A4GL_isyes (acl_getenv ("TRADMENU")))
	{
	  gtk_widget_set_name (GTK_WIDGET (fglmenu_bb), "MenuButtons");
		setMenu(fglmenu_bb,1);
	  //gtk_widget_show (fglmenu_bb);
	}

      fixed = gtk_fixed_new ();
      gtk_widget_set_name (GTK_WIDGET (fixed), "AppWindow");
#if GTK_CHECK_VERSION(2,0,0)
      gtk_fixed_set_has_window (GTK_FIXED (fixed), 1);
#endif
      gtk_widget_show (GTK_WIDGET (fixed));
      if (use_frames()) {
	  frame = gtk_frame_new (0);
	}
      else
	{
	  frame = gtk_handle_box_new ();
	}
      gtk_widget_set_name (GTK_WIDGET (frame), "AppWindow");

      if (A4GL_menu_pos () == 'L' || A4GL_menu_pos () == 'R')
	{
	  gtk_box_set_child_packing (GTK_BOX (hbox), frame, 1, 1, 2, GTK_PACK_START);
	}
      else
	{
	  gtk_box_set_child_packing (GTK_BOX (hbox), frame, 1, 1, 0,
				     GTK_PACK_START);
	}

      gtk_widget_show (frame);
      gtk_container_add (GTK_CONTAINER (frame), fixed);

      if (!A4GL_isyes (acl_getenv ("TRADMENU")))
	{
	  GtkWidget *f;
	  GtkWidget *vbox;

	  if (use_frames())
	    {
	      f = gtk_frame_new (0);
	    }
	  else
	    {
	      f = gtk_handle_box_new ();
	    }
	  gtk_widget_set_name (GTK_WIDGET (f), "MenuButtons");
	  vbox = gtk_vbox_new (0, 0);
	  if (A4GL_menu_pos () == 'L' || A4GL_menu_pos () == 'R')
	    {
	      gtk_widget_set_usize (GTK_WIDGET (vbox),
				    additional * gui_xwidth,
				    (A4GL_LL_screen_height () +
				     1) * gui_yheight);
	    }
	  else
	    {
	      gtk_widget_set_usize (GTK_WIDGET (vbox),
				    (A4GL_LL_screen_width () +
				     1) * gui_xwidth, 2 * gui_yheight);
	    }
	  gtk_widget_show (f);
	  gtk_widget_set_name (GTK_WIDGET (f), "MenuButtons");
	  gtk_widget_show (vbox);
	  gtk_container_add (GTK_CONTAINER (vbox), fglmenu_bb);
		gtk_box_pack_end (GTK_BOX(vbox), ok_cancel, FALSE, FALSE, 0);
	  //gtk_container_add (GTK_CONTAINER (vbox), ok_cancel);
	  gtk_container_add (GTK_CONTAINER (f), vbox);

	  if (A4GL_menu_pos () == 'T' || A4GL_menu_pos () == 'L')
	    {
	      gtk_container_add (GTK_CONTAINER (hbox), f);
	      gtk_container_add (GTK_CONTAINER (hbox), frame);
	    }
	  else
	    {
	      gtk_container_add (GTK_CONTAINER (hbox), frame);
	      gtk_container_add (GTK_CONTAINER (hbox), f);
	    }
	}

      gtk_box_set_spacing (GTK_BOX (hbox), 0);
      if (useToolbar) {
	int a;
      	MainFrame=gtk_vbox_new (0, 1);
  	toolbar = gtk_toolbar_new ();
	for (a=0;a< NTOOLBARITEMS;a++) {
		toolbarItems[a]=0;
	}
	toolbarItemsCnt=0;
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "Help", "HELP",	"help", 		"help", A4GLKEY_HELP);

	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F1", "F1",		"F1", 		"F1", A4GLKEY_F(1));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F2", "F2",		"F2", 		"F2", A4GLKEY_F(2));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F3", "F3",		"F3", 		"F3", A4GLKEY_F(3));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F4", "F4",		"F4", 		"F4", A4GLKEY_F(4));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F5", "F5",		"F5",		"F5", A4GLKEY_F(5));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F6", "F6",		"F6", 		"F6", A4GLKEY_F(6));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F7", "F7",		"F7", 		"F7", A4GLKEY_F(7));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F8", "F8",		"F8", 		"F8", A4GLKEY_F(8));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F9", "F9",		"F9", 		"F9",  A4GLKEY_F(9));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F10", "F10",		"F10", 		"F10", A4GLKEY_F(10));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F11", "F11",		"F11", 		"F11", A4GLKEY_F(11));
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "F12", "F12",		"F12", 		"F12", A4GLKEY_F(12));


	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "Up", "Up",		"up", 	"Up", A4GLKEY_UP);
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "Down","Down",	"down", 	"Down", A4GLKEY_DOWN);
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "Left", "Left",	"left", 	"Left", A4GLKEY_LEFT);
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "Right","Right",	"right", 	"Right", A4GLKEY_RIGHT);

	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "PgUp", "PgUp",	"rewind", 	"PgUp", A4GLKEY_PGUP);
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "PgDn", "PgDn",	"forwind", 	"PgDn", A4GLKEY_PGDN);

	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "Enter", "Enter",	"enter", 	"Enter", A4GLKEY_ENTER);
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "Accept","Accept",	"accept", 	"Accept", A4GLKEY_ACCEPT);
	toolbarItems[toolbarItemsCnt++]=AddButtonToolbar(toolbar, "Interrupt", "Interrupt",	"interrupt", 	"Cancel", A4GLKEY_INTERRUPT);


	gtk_widget_show(MainFrame);
	gtk_widget_show(toolbar);

  	gtk_toolbar_set_orientation (GTK_TOOLBAR (toolbar), GTK_ORIENTATION_HORIZONTAL);

	if (strcmp(acl_getenv("TOOLBARSTYLE"),"ICONSONLY")==0) {
  	 	gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_ICONS);
	} else {
		if (strcmp(acl_getenv("TOOLBARSTYLE"),"TEXTONLY")==0) {
  	 		gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_TEXT);
		} else {
			if (strcmp(acl_getenv("TOOLBARSTYLE"),"BOTHHORIZ")==0) {
  	 			gtk_toolbar_set_style (GTK_TOOLBAR (toolbar),  GTK_TOOLBAR_BOTH_HORIZ);
			} else {
  	 			gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_BOTH);
			}
		}
	}
  	gtk_container_set_border_width (GTK_CONTAINER (toolbar), 2);
  	//gtk_toolbar_set_space_size (GTK_TOOLBAR (toolbar), 5);
      	gtk_container_add (GTK_CONTAINER (MainFrame), toolbar);
      	gtk_container_add (GTK_CONTAINER (MainFrame), hbox);
		ActivateToolbar(0,0,0);
      } else {
	MainFrame=hbox;
      }

      gtk_container_add (GTK_CONTAINER (win), MainFrame);
      win_screen = fixed;
      gtk_widget_set_usize (GTK_WIDGET (fixed), (A4GL_LL_screen_width ()) * gui_xwidth, (A4GL_LL_screen_height ()) * gui_yheight);
      gtk_object_set_data (GTK_OBJECT (win_screen), "BB", fglmenu_bb);
	if (!useToolbar) {
      		gtk_object_set_data (GTK_OBJECT (win_screen), "OKCANCEL", ok_cancel);
	}
      gtk_object_set_data (GTK_OBJECT (win), "FIXED", fixed);
      gtk_signal_connect (GTK_OBJECT (win), "delete_event",
			  GTK_SIGNAL_FUNC (A4GL_delete_event), win);
      gtk_signal_connect (GTK_OBJECT (win), "destroy",
			  GTK_SIGNAL_FUNC (A4GL_destroy_event), win);
    }
  else
    {
      h = h * gui_yheight;
      y = (y - 1) * gui_yheight;
      w = w * gui_xwidth;
      x = (x - 1) * gui_xwidth;

      A4GL_debug ("w=%d h=%d\n", w / XWIDTH, h / YHEIGHT);
      win = gtk_fixed_new ();
#if GTK_CHECK_VERSION(2,0,0)
      gtk_fixed_set_has_window (GTK_FIXED (win), 1);
#endif
      gtk_widget_set_usize (GTK_WIDGET (win), w + gui_xwidth,
			    h + gui_yheight);
      gtk_object_set_data (GTK_OBJECT (win), "FIXED", fixed);
      if (border)
	{
	  A4GL_debug ("Creating bordered window...");
	  wxx = 0;
	  if (window_frame_type == 0)
	    {
	      wxx = gtk_event_box_new ();
	    }
	  if (window_frame_type == 99)
	    {
	      wxx = gtk_handle_box_new ();
	    }
	  if (wxx == 0)
	    {
	      A4GL_exitwith ("Invalid window style type");
	      return 0;
	    }
	  // Add the event box as top of our window...
	  gtk_fixed_put (GTK_FIXED (win_screen), wxx, x - XWIDTH,
			 y - YHEIGHT);
	  // Create a frame to go in our eventbox
	  if (use_frames())
	    {

	      frame = (GtkWidget *) gtk_frame_new (0);
	      gtk_frame_set_shadow_type (GTK_FRAME (frame), frame_style);
	    }
	  else
	    {
	      frame = (GtkWidget *) gtk_handle_box_new ();
	      gtk_handle_box_set_shadow_type (GTK_HANDLE_BOX (frame),
					      frame_style);
	    }
	  gtk_widget_set_usize (GTK_WIDGET (frame), w + XWIDTH, h + YHEIGHT);
	  // Add our frame to the eventbox
	  gtk_container_add (GTK_CONTAINER (wxx), GTK_WIDGET (frame));
	  gtk_widget_show (GTK_WIDGET (wxx));
	  gtk_widget_show (GTK_WIDGET (frame));
	  gtk_container_add (GTK_CONTAINER (frame), win);
	  gtk_object_set_data (GTK_OBJECT (win), "FIXED", win);
	  // Add a fixed to our frame..
	  /*
	     fixed = gtk_fixed_new ();
	     gtk_widget_set_usize (GTK_WIDGET (fixed), w , h);
	     gtk_container_add (GTK_CONTAINER (frame), fixed);
	     gtk_widget_show(GTK_WIDGET(fixed));
	     gtk_fixed_put (GTK_FIXED (fixed), win, XWIDTH, YHEIGHT);
	   */
	  gtk_object_set_data (GTK_OBJECT (win), "TOP", wxx);
	}
      else
	{
#if GTK_CHECK_VERSION(2,0,0)
	  gtk_fixed_set_has_window (GTK_FIXED (win), 1);
#endif
	  gtk_fixed_put (GTK_FIXED (win_screen), win, x, y);
	  gtk_object_set_data (GTK_OBJECT (win), "FIXED", win);
	  gtk_object_set_data (GTK_OBJECT (win), "TOP", win);
	}
    }
  gtk_widget_show (win);
  gtk_signal_connect (GTK_OBJECT (win), "key-press-event",
		      GTK_SIGNAL_FUNC (A4GL_keypress), win);
  A4GL_debug ("Created window %p for h=%d w=%d y=%d x=%d b=%d", win, h, w, y,
	      x, border);
  A4GL_LL_gui_run_til_no_more ();
  return win;
}

void
A4GL_LL_error_box (char *str, int attr)
{
  char *error = acl_getenv ("A4GL_DIALOG_ERROR");
  A4GL_gtkdialog (error, "", BUTTONS_OK, BUTTON_OK, 0, str);
}

char *
A4GL_LL_field_buffer (void *field, int n)
{
  char *ptr;
  ptr = A4GL_fld_val_generic (field);
  return ptr;
}


int
A4GL_LL_getch_swin (void *window_ptr,char *why)
{
  int a;
  //GtkWidget *f;

  A4GL_set_abort (0);

  //a = A4GL_readkey ();
  //if (a != 0) {
  //A4GL_debug ("Read %d from keyfile", a);
  //A4GL_LL_gui_run_til_no_more();
  //return a;
  //}

  keypressed = 0;
  while (1)
    {
      if (menu_response != -1)
	{
	  FPRINTF (stderr, "MENU RESPONSE : %d\n", menu_response);
	  a = 0 - (menu_response + 1000);
	  menu_response = -1;
	  FPRINTF (stderr, "Returning : %d\n", a);
	  return a;
	}
      a = get_keypress_from_buffer ();
      if (a != -1)
	break;
      gtk_main_iteration ();
    }
  keypressed = 0;
  if (a == 3)
    {
#if (defined(WIN32) && ! defined(__CYGWIN__))
      set_intr_win32 (SIGINT);
#else
      kill (0, SIGINT);
#endif

    }

  a = A4GL_which_key_aubit (a);

  return a;
}


/*
kill() call is supposed to call the signal handler as if ^c had been pressed (under linux
- by sending the SIGINT signal...)

I'm trying to figure out what to call instead - but fglwrap.c looks a little
complicated to follow.

(I'm not sure the ungetch is required...)

So it should probably call set_intr_win32(CTRL_C_EVENT) instead of kill...

Under mingw I think it should be calling :
*/
#if (defined(WIN32) && ! defined(__CYGWIN__))
/**
 * Initilaizes the signals in windows systems.
 *
 * @param type
 * @return
 */
//BOOL __stdcall
//set_intr_win32 (DWORD type)
int set_intr_win32 (int type)
{
  if (type == CTRL_C_EVENT || type == CTRL_BREAK_EVENT)
    {
#ifdef DEBUG
      A4GL_debug ("-------------INTERRUPT----------------");
#endif
      int_flag = TRUE;
      errno = -1;
      ungetch (A4GLKEY_CANCEL);
      A4GL_set_abort (1);
    }
  return TRUE;
}
#endif

int
A4GL_which_key_aubit (int gdk_key)
{
  int a;
  a = gdk_key;
  if (a == GDK_F12)
    {
      gtk_rc_reparse_all ();
      //A4GL_run_gtkrc();
      return A4GLKEY_F (12);
    }
  if (a == 3)
    return -1;
  if (a == GDK_Escape)
    return 27;
  if (a == GDK_Down)
    return A4GLKEY_DOWN;
  if (a == GDK_Up)
    return A4GLKEY_UP;
  if (a == GDK_Left)
    return A4GLKEY_LEFT;
  if (a == GDK_Right)
    return A4GLKEY_RIGHT;
  if (a == GDK_Return)
    return A4GLKEY_ENTER;
  if (a == GDK_Tab)
    return 9;
  if (a == GDK_ISO_Left_Tab)
    return A4GLKEY_SHTAB;
  if (a == GDK_F1)
    return A4GLKEY_F (1);
  if (a == GDK_F2)
    return A4GLKEY_F (2);
  if (a == GDK_F3)
    return A4GLKEY_F (3);
  if (a == GDK_F4)
    return A4GLKEY_F (4);
  if (a == GDK_F5)
    return A4GLKEY_F (5);
  if (a == GDK_F6)
    return A4GLKEY_F (6);
  if (a == GDK_F7)
    return A4GLKEY_F (7);
  if (a == GDK_F8)
    return A4GLKEY_F (8);
  if (a == GDK_F9)
    return A4GLKEY_F (9);
  if (a == GDK_F10)
    return A4GLKEY_F (10);
  if (a == GDK_F11)
    return A4GLKEY_F (11);
  if (a == GDK_F12)
    return A4GLKEY_F (12);
  if (a == GDK_F13)
    return A4GLKEY_F (13);
  if (a == GDK_F14)
    return A4GLKEY_F (14);
  if (a == GDK_F15)
    return A4GLKEY_F (15);
  if (a == GDK_F16)
    return A4GLKEY_F (16);
  if (a == GDK_F17)
    return A4GLKEY_F (17);
  if (a == GDK_F18)
    return A4GLKEY_F (18);
  if (a == GDK_F19)
    return A4GLKEY_F (19);
  if (a == GDK_F20)
    return A4GLKEY_F (20);
  if (a == GDK_F21)
    return A4GLKEY_F (21);
  if (a == GDK_F22)
    return A4GLKEY_F (22);
  if (a == GDK_F23)
    return A4GLKEY_F (23);
  if (a == GDK_F24)
    return A4GLKEY_F (24);
  if (a == GDK_F25)
    return A4GLKEY_F (25);
  if (a == GDK_F26)
    return A4GLKEY_F (26);
  if (a == GDK_F27)
    return A4GLKEY_F (27);
  if (a == GDK_F28)
    return A4GLKEY_F (28);
  if (a == GDK_F29)
    return A4GLKEY_F (29);
  if (a == GDK_F30)
    return A4GLKEY_F (30);
  if (a == GDK_F31)
    return A4GLKEY_F (31);
  if (a == GDK_F32)
    return A4GLKEY_F (32);
  if (a == GDK_F33)
    return A4GLKEY_F (33);
  if (a == GDK_F34)
    return A4GLKEY_F (34);
  if (a == GDK_F35)
    return A4GLKEY_F (35);

  if (a == GDK_KP_0)
    return '0';
  if (a == GDK_KP_1)
    return '1';
  if (a == GDK_KP_2)
    return '2';
  if (a == GDK_KP_3)
    return '3';
  if (a == GDK_KP_4)
    return '4';
  if (a == GDK_KP_5)
    return '5';
  if (a == GDK_KP_6)
    return '6';
  if (a == GDK_KP_7)
    return '7';
  if (a == GDK_KP_8)
    return '8';
  if (a == GDK_KP_9)
    return '9';

  if (a == GDK_KP_Space)
    return ' ';
  if (a == GDK_KP_Tab)
    return 9;
  if (a == GDK_KP_Enter)
    return A4GLKEY_ENTER;

  if (a == GDK_KP_F1)
    return A4GLKEY_F (1);
  if (a == GDK_KP_F2)
    return A4GLKEY_F (2);
  if (a == GDK_KP_F3)
    return A4GLKEY_F (3);
  if (a == GDK_KP_F4)
    return A4GLKEY_F (4);
  if (a == GDK_KP_Left)
    return A4GLKEY_LEFT;
  if (a == GDK_KP_Up)
    return A4GLKEY_UP;
  if (a == GDK_KP_Right)
    return A4GLKEY_RIGHT;
  if (a == GDK_KP_Down)
    return A4GLKEY_DOWN;
  if (a == GDK_KP_Equal)
    return '=';
  if (a == GDK_KP_Multiply)
    return '*';
  if (a == GDK_KP_Add)
    return '+';
  if (a == GDK_KP_Subtract)
    return '-';
  if (a == GDK_KP_Decimal)
    return '.';
  if (a == GDK_KP_Divide)
    return '/';
  if (a == GDK_KP_Page_Up)
    return A4GLKEY_PGUP;
  if (a == GDK_KP_Page_Down)
    return A4GLKEY_PGDN;
  if (a == GDK_KP_Home)
    return A4GLKEY_HOME;
  if (a == GDK_KP_End)
    return A4GLKEY_END;



  if (a == 0xff08)
    return A4GLKEY_DC;
  return a;
}




void
A4GL_LL_gui_run_til_no_more (void)
{
  //A4GL_debug("A4GL_LL_gui_run_til_no_more");
  if (A4GL_LL_pause_mode (-1))
    {
      while (gtk_events_pending ())
	gtk_main_iteration ();
      if (keypressed == 3)
	{



#if (defined(WIN32) && ! defined(__CYGWIN__))
	  set_intr_win32 (SIGINT);
#else
	  kill (0, SIGINT);
#endif

	}
    }
  else
    {
      A4GL_debug ("Skipping run_til_no_more - in pause mode");
    }
}



void
A4GL_LL_hide_window (void *w)
{
  gtk_widget_hide (w);
}


void
A4GL_run_gtkrc (void)
{
  char *gtkrc;
  char buff[255];
  char buff2[255];

  A4GL_debug ("A4GL_run_gtkrc");

  gtkrc = acl_getenv ("GTKRC");
  if (gtkrc == 0)
    {
      gtkrc = "";
    }

  if (strlen (gtkrc) == 0)
    {
      SPRINTF1 (buff2, "%s/etc/gtkrc", acl_getenv ("AUBITDIR"));
      gtkrc = buff2;
    }

#if GTK_CHECK_VERSION(2,0,0)
  SPRINTF1 (buff, "%s_2", gtkrc);
#else
  SPRINTF1 (buff, "%s", gtkrc);
#endif

  A4GL_debug ("Reading RC File (gtk_rc_parse('%s')", buff);
  gtk_rc_parse (buff);
  A4GL_debug ("done");
}




void
A4GL_LL_initialize_display (void)
{
  //char *argvv[]={};
  //char *gtkrc;
  //char buff[255];
  //char buff2[255];

  A4GL_debug ("A4GL_LL_initialize_display");

#if GTK_CHECK_VERSION(2,0,0)
  gtk_disable_setlocale ();	/* tell GTK to NOT call setlocale(LC_ALL,"")! */
  /* the only place where setlocate() should */
  /* be called is lib/libaubit4gl/fglwrap.c */
#else
#ifdef DEBUG
  A4GL_debug ("gtk_disable_setlocale() skipped - using GTK+ v 1.2");
#endif
#endif
  gtk_init (0, 0);
  register_my_stock_icons();

  if (acl_getenv ("CELL_HEIGHT"))
    {
      if (strlen (acl_getenv ("CELL_HEIGHT")))
	gui_yheight = atoi (acl_getenv ("CELL_HEIGHT"));
    }
  if (acl_getenv ("CELL_WIDTH"))
    {
      if (strlen (acl_getenv ("CELL_WIDTH")))
	gui_xwidth = atoi (acl_getenv ("CELL_WIDTH"));
    }

  A4GL_debug ("gui_xwidth:%d  gui_yheight:%d", gui_xwidth, gui_yheight);

  A4GL_run_gtkrc ();

#ifdef DEBUG
  g_log_set_always_fatal (G_LOG_FLAG_RECURSION |
			  G_LOG_FLAG_FATAL |
			  G_LOG_LEVEL_ERROR |
			  G_LOG_LEVEL_CRITICAL | G_LOG_LEVEL_WARNING);
#endif /*DEBUG*/
    A4GL_alloc_colors ();
  gtk_key_snooper_install (KeySnooper, 0);
  A4GL_create_console ();

  if (tooltips == 0)
    tooltips = (GtkWidget *) gtk_tooltips_new ();


  A4GL_LL_gui_run_til_no_more ();

}






void
A4GL_LL_make_window_top (void *w)
{
  static GtkWidget *b = 0;

  /* If we are not using formhandlers then we need to
     ensure modality with the currwindow...
   */

  b = gtk_object_get_data (GTK_OBJECT (w), "FRAME");
  if (b)
    {
      gtk_widget_hide (b);
      gtk_widget_show (b);
      return;
    }

  b = gtk_object_get_data (GTK_OBJECT (w), "TOP");
  if (b)
    {
      gtk_widget_hide (b);

      //gtk_widget_show_all (b);
      gtk_widget_show (b);

      return;
    }


  gtk_widget_hide (w);
  //gtk_widget_show_all (w);
  gtk_widget_show (w);
}

void
A4GL_LL_move_window (void *w, int y, int x)
{
  int yo;
  int xo;
  yo = (int) gtk_object_get_data (GTK_OBJECT (w), "Y_OFF");
  xo = (int) gtk_object_get_data (GTK_OBJECT (w), "X_OFF");
  gtk_fixed_move ((GtkFixed *) win_screen, w, (x - 1) * XWIDTH + xo,
		  (y - 1) * YHEIGHT + yo);
}




void
A4GL_LL_remove_window (void *x)
{
  void *xx;
  xx = gtk_object_get_data (GTK_OBJECT (x), "TOP");
  if (xx)
    {
      gtk_widget_destroy (xx);
    }
  else
    {
      gtk_widget_destroy (x);
    }
}


int
A4GL_LL_screen_height (void)
{
  char *ptr;
  ptr = acl_getenv ("LINES");
  if (ptr == 0 || strlen (ptr) == 0)
    return 25;
  return atoi (ptr);
}

void
A4GL_LL_screen_mode (void)
{
  A4GL_hide_console ();
}

void
A4GL_LL_screen_refresh (void)
{
  A4GL_LL_gui_run_til_no_more ();
}

void
A4GL_LL_screen_redraw (void)
{
  A4GL_LL_gui_run_til_no_more ();
}

void
A4GL_LL_screen_update (void)
{
  A4GL_LL_gui_run_til_no_more ();
}



int
A4GL_LL_screen_width (void)
{
  int w = 80;
  if (acl_getenv ("COLUMNS"))
    {
      if (strlen (acl_getenv ("COLUMNS")))
	w = atoi (acl_getenv ("COLUMNS"));
    }
  return w;
}







void
A4GL_LL_set_current_field (void *vform, void *field)
{
  struct s_a4gl_gtk_form *form;
  int a;
  form = vform;

  if (field)
    {
      gtk_widget_grab_focus (GTK_WIDGET (field));
      for (a = 0; a < form->nwidgets; a++)
	{
	  if (form->widgets[a] == field)
	    {
	      if (form->currentfield != a)
		{
		  form->curcol = 0;
		}
	      form->currentfield = a;
	      break;
	    }
	}
    }
}





void
A4GL_LL_set_field_back (void *field, int attr)
{
  char buff[255];
  if (allocated_colors == 0)
    A4GL_alloc_colors ();
  //gtk_widget_set_style (field, rcolorStyles[attr & 7]);

  attr = attr & 0xffffff00;
  SPRINTF1 (buff, "%x", attr >> 8);
  gtk_widget_set_name (GTK_WIDGET (field), buff);



/*
  if (attr & AUBIT_ATTR_REVERSE)
    {
      A4GL_debug ("REVERSE VIDEO!!!");
      gtk_widget_set_style (field, rcolorStyles[A4GL_decode_colour_attr_aubit(attr) & 7]);
    }
  else {
    gtk_widget_set_style (field, colorStyles[A4GL_decode_colour_attr_aubit(attr) & 7]);
	}
*/

}





void
A4GL_LL_set_field_fore (void *field, int attr)
{
  char buff[255];
  char *ptr;
  ptr = gtk_object_get_data (field, "WIDGETSNAME");
  if (allocated_colors == 0)
    A4GL_alloc_colors ();
  attr = attr & 0xffffff00;
  SPRINTF1 (buff, "%x", attr >> 8);
  gtk_widget_set_name (GTK_WIDGET (field), buff);

  /*
     if (attr & AUBIT_ATTR_REVERSE)
     {
     A4GL_debug ("REVERSE VIDEO FG!!!");
     if (A4GL_decode_colour_attr_aubit(attr)!=0) {
     gtk_widget_set_style (field, colorStyles[0]);
     } else {
     gtk_widget_set_style (field, colorStyles[7]);
     }
     }
     else
     gtk_widget_set_style (field, colorStyles[A4GL_decode_colour_attr_aubit(attr) & 7]);
   */


}



int
A4GL_LL_set_field_opts (void *field, int oopt)
{
  char *wtype;
  gtk_object_set_data (GTK_OBJECT ((GtkWidget *) field), "FIELD_OPTS",
		       (void *) oopt);

  if (oopt & AUBIT_O_ACTIVE || oopt & AUBIT_O_EDIT)
    {
      A4GL_gui_set_active (field, 1);
    }
  else
    {
      wtype = gtk_object_get_data (GTK_OBJECT (field), "WIDGETSNAME");
      if (gtk_object_get_data (GTK_OBJECT (field), "MF_ISLABEL")
	  || gtk_object_get_data (GTK_OBJECT (field), "DISPLAY_LABEL")
	  || A4GL_aubit_strcasecmp (wtype, "pixmap") == 0)
	{
	  // Labels are always active :)
	  A4GL_gui_set_active (field, 1);
	}
      else
	{
	  A4GL_gui_set_active (field, 0);
	}
    }
  return oopt;
}

void
A4GL_LL_show_window (void *w)
{
  gtk_widget_show (w);
}


void
A4GL_LL_sleep (int n)
{
  int c;
  int b;
  for (c = 0; c < n; c++)
    {
      for (b = 0; b <= 9; b++)
	{
	  a4gl_usleep (100000);
	  A4GL_LL_gui_run_til_no_more ();
	}
    }
}

int
A4GLHLUI_initlib (void)
{
  return 0;
}

void
A4GL_LL_switch_to_line_mode (void)
{
  A4GL_show_console ();
}


void
A4GL_LL_wadd_char_xy_col (void *win, int x, int y, int ch, int curr_width,
			  int curr_height, int iscurrborder, int currwinno)
{
  GtkFixed *cwin;
  GtkEventBox *e;
  GtkLabel *lab;



  char buff_label[256];
  char buff_evt[256];
  char buff_char[256];
  char buff_attr[256];

  long old_attr = 0;
  long has_old_attr = 0;
  char cbuff[10];
  cbuff[0] = ch & 0xff;
  cbuff[1] = 0;
  
  A4GL_debug ("Wadd_char to window %p %d %d %x", win, x, y);

  SPRINTF3 (buff_label, "LABEL_%p_%d_%d", win, x, y);
  SPRINTF3 (buff_char, "LABEL_%p_%d_%d_C", win, x, y);
  SPRINTF3 (buff_evt, "EVENTBOX_%p_%d_%d", win, x, y);
  SPRINTF3 (buff_attr, "ATTR_%p_%d_%d", win, x, y);

  cwin = gtk_object_get_data (GTK_OBJECT (win), "FIXED");
  lab = (GtkLabel *) gtk_object_get_data (GTK_OBJECT (cwin), buff_label);
  e = (GtkEventBox *) gtk_object_get_data (GTK_OBJECT (cwin), buff_evt);
  old_attr = (long) gtk_object_get_data (GTK_OBJECT (cwin), buff_attr);


  if (old_attr == ch && lab && e)
    return;
  gtk_object_set_data (GTK_OBJECT (cwin), buff_attr, (void *) ch);


  // It did have...
  if (ch == 32 || ch == 0 || ch == 0x10720 || ch == 0x10700)
    {

      if (lab == 0 && e == 0)
	{
	  return;
	}

#ifdef XXX
      if (lab)
	{
	  gtk_widget_destroy (GTK_WIDGET (lab));
	  gtk_object_set_data (GTK_OBJECT (cwin), buff_label, 0);
	}

      if (e)
	{
	  gtk_widget_destroy (GTK_WIDGET (e));
	  gtk_object_set_data (GTK_OBJECT (cwin), buff_evt, 0);
	}
      return;
#endif
    }



  if (!lab)
    {
      char *lab_utf ;
		//printf("txt=%s\n",cbuff);
	lab_utf= g_locale_to_utf8 (cbuff, -1, NULL, NULL, NULL);
      lab = (GtkLabel *) gtk_label_new (lab_utf);
      g_free (lab_utf);
      e = (GtkEventBox *) gtk_event_box_new ();
      gtk_fixed_put (GTK_FIXED (cwin), GTK_WIDGET (e), A4GL_getx_coords (x), A4GL_gety_coords (y));
      gtk_container_add (GTK_CONTAINER (e), GTK_WIDGET (lab));

      gtk_object_set_data (GTK_OBJECT (cwin), buff_label, lab);
      gtk_object_set_data (GTK_OBJECT (cwin), buff_char,
			   (void *) (ch & 0xff));

      gtk_object_set_data (GTK_OBJECT (cwin), buff_evt, e);

      //gtk_label_set_justify( lab,GTK_JUSTIFY_CENTER);
      //gtk_misc_set_alignment(GTK_MISC(lab), 0.5f, 0.5f);
      gtk_misc_set_alignment (GTK_MISC (lab), 0.5f, 0.5f);
#if GTK_CHECK_VERSION(2,0,0)
      gtk_widget_set_size_request (GTK_WIDGET (e), gui_xwidth, gui_yheight);
      gtk_widget_set_size_request (GTK_WIDGET (lab), gui_xwidth, gui_yheight);

#endif

      has_old_attr = 0;

      gtk_widget_show (GTK_WIDGET (lab));
      gtk_widget_show (GTK_WIDGET (e));

    }
  else
    {
      char *txt_utf ;
		//printf("txt=%s\n",cbuff);
		txt_utf= g_locale_to_utf8 (cbuff, -1, NULL, NULL, NULL);
      has_old_attr = 1;
      gtk_label_set_text (lab, txt_utf);
      g_free (txt_utf);
#if GTK_CHECK_VERSION(2,0,0)
      gtk_widget_set_size_request (GTK_WIDGET (lab), gui_xwidth, gui_yheight);
#endif


    }

  if ((old_attr & 0xffffff00) == (ch & 0xffffff00) && has_old_attr);
  else
    {
      A4GL_LL_set_field_back ((GtkWidget *) e, ch);
      A4GL_LL_set_field_fore ((GtkWidget *) lab, ch);
    }
}


void
A4GL_LL_wadd_gunichar_xy_col (void *win, int x, int y, gunichar ch,
			      int curr_width, int curr_height,
			      int iscurrborder, int currwinno)
{
  GtkFixed *cwin;
  GtkEventBox *e;
  GtkLabel *lab;

  gchar label_text[256];

  char buff_label[256];
  char buff_evt[256];
  char buff_char[256];
  char buff_attr[256];

  long old_attr = 0;
  long has_old_attr = 0;

  A4GL_debug ("UNICHAR %d %d %x (%lc)", x, y, ch, ch);

  g_snprintf (label_text, sizeof (label_text), "%lc", ch);

  SPRINTF2 (buff_label, "LABEL_%d_%d", x, y);
  SPRINTF2 (buff_char, "LABEL_%d_%d_C", x, y);
  SPRINTF2 (buff_evt, "EVENTBOX_%d_%d", x, y);
  SPRINTF2 (buff_attr, "ATTR_%d_%d", x, y);

  cwin = gtk_object_get_data (GTK_OBJECT (win), "FIXED");
  lab = (GtkLabel *) gtk_object_get_data (GTK_OBJECT (cwin), buff_label);
  e = (GtkEventBox *) gtk_object_get_data (GTK_OBJECT (cwin), buff_evt);
  old_attr = (long) gtk_object_get_data (GTK_OBJECT (cwin), buff_attr);


  if (old_attr == ch && lab && e)
    return;
  gtk_object_set_data (GTK_OBJECT (cwin), buff_attr, (void *) ch);


  // It did have...
  if (ch == 32 || ch == 0 || ch == 0x10720 || ch == 0x10700)
    {

      if (lab == 0 && e == 0)
	{
	  return;
	}
    }

  if (!lab)
    {
      lab = (GtkLabel *) gtk_label_new (label_text);

      e = (GtkEventBox *) gtk_event_box_new ();
      gtk_fixed_put (GTK_FIXED (cwin), GTK_WIDGET (e), A4GL_getx_coords (x),
		     A4GL_gety_coords (y));
      gtk_container_add (GTK_CONTAINER (e), GTK_WIDGET (lab));

      gtk_object_set_data (GTK_OBJECT (cwin), buff_label, lab);
      gtk_object_set_data (GTK_OBJECT (cwin), buff_char,
			   (void *) (ch & 0xff));

      gtk_object_set_data (GTK_OBJECT (cwin), buff_evt, e);
      gtk_misc_set_alignment (GTK_MISC (lab), 0.5f, 0.5f);
#if GTK_CHECK_VERSION(2,0,0)
      gtk_widget_set_size_request (GTK_WIDGET (e), gui_xwidth, gui_yheight);
      gtk_widget_set_size_request (GTK_WIDGET (lab), gui_xwidth, gui_yheight);

#endif

      has_old_attr = 0;

      gtk_widget_show (GTK_WIDGET (lab));
      gtk_widget_show (GTK_WIDGET (e));

    }
  else
    {
      has_old_attr = 1;
      gtk_label_set_text (lab, label_text);
#if GTK_CHECK_VERSION(2,0,0)
      gtk_widget_set_size_request (GTK_WIDGET (lab), gui_xwidth, gui_yheight);
#endif

    }

  if ((old_attr & 0xffffff00) == (ch & 0xffffff00) && has_old_attr);
  else
    {
      A4GL_LL_set_field_back ((GtkWidget *) e, ch);
      A4GL_LL_set_field_fore ((GtkWidget *) lab, ch);
    }
}


#ifdef REMOVED
void
A4GL_LL_set_form_userptr (void *vform, void *data)
{
  struct s_a4gl_gtk_form *form;
  form = vform;
  form->userptr = data;
}
#endif


int
A4GL_LL_set_chars_normal (int *n)
{
  return 0;
}

void
A4GL_LL_beep ()
{
  gdk_beep ();
}


#ifdef REMOVED
void *
A4GL_LL_get_field_userptr (void *field)
{
  return gtk_object_get_data (GTK_OBJECT (field), "USERPTR");
}
#endif

int
A4GL_LL_get_field_width_dynamic (void *f)
{
  return (int) gtk_object_get_data (GTK_OBJECT ((GtkWidget *) f), "MF_COLS");
}

int
A4GL_LL_get_field_height_dynamic (void *f)
{
  return (int) gtk_object_get_data (GTK_OBJECT ((GtkWidget *) f), "MF_ROWS");
}

#ifdef REMOVED
void *
A4GL_LL_get_form_userptr (void *vform)
{
  struct s_a4gl_gtk_form *form;
  form = vform;
  return form->userptr;
}
#endif

int
A4GL_LL_field_status (void *field)
{
  return (int) gtk_object_get_data (GTK_OBJECT (field), "STATUS");
}


#ifdef REMOVED
void
A4GL_LL_set_field_userptr (void *field, void *ptr)
{
  return gtk_object_set_data (GTK_OBJECT (field), "USERPTR", ptr);
}
#endif

void
A4GL_LL_set_field_status (void *f, int stat)
{
  gtk_object_set_data (GTK_OBJECT (f), "STATUS", (void *) stat);
}

void
A4GL_LL_out_linemode (char *s)
{
  A4GL_add_to_console (s);
}


int
A4GL_LL_field_opts (void *field)
{
  return (int) gtk_object_get_data (GTK_OBJECT (field), "FIELD_OPTS");
}

int
A4GL_LL_decode_aubit_attr (int a, char s)
{
  /* CHECK IMPLEMENTATION */
  return a;
}

void *
A4GL_LL_current_field (void *vform)
{
  struct s_a4gl_gtk_form *form;
  form = vform;
  return form->widgets[form->currentfield];
}

void
A4GL_LL_set_max_field (void *f, int n,void *frm)
{
  gtk_object_set_data (GTK_OBJECT (f), "MAXFIELD", (void *) n);
  if (strcmp (gtk_object_get_data (GTK_OBJECT (f), "WIDGETSNAME"), "ENTRY") == 0)
    {
	 if (gtk_object_get_data (GTK_OBJECT (f), "ISTEXTVIEW")) {

	 } else {
      		gtk_entry_set_max_length (f, n);
	 }
    }

  // NEED MORE HERE...
}

int
A4GL_LL_set_new_page (void *field, int n)
{
  gtk_object_set_data (GTK_OBJECT (field), "NEWPAGE", (void *) 1);
  return 1;
}

/******************************************************************************
 *  ERROR HANDLING
 *****************************************************************************/
void
A4GL_LL_delete_errorwindow (void *curr_error_window)
{
  A4GL_debug ("error window : removing %p", curr_error_window);
  gtk_widget_destroy (curr_error_window);
}


void *
A4GL_LL_create_errorwindow (int h, int w, int y, int x, int attr, char *str)
{
  GtkWidget *frame;		// We want it in a nice frame
  GtkWidget *label;		// With some text
  GtkWidget *evt;		// And we'll use this to get a background colour...
  char buff[80];
  char *lab_utf ;
	//printf("txt=%s\n",str);
	lab_utf= g_locale_to_utf8 (str, -1, NULL, NULL, NULL);
  A4GL_debug ("Create error window");
  if (str == 0)
    return 0;
  if (strlen (str) == 0)
    return 0;
  frame = gtk_frame_new (0);

  label = gtk_label_new (lab_utf);

#if GTK_CHECK_VERSION(2,0,0)
  if (A4GL_isyes (acl_getenv ("A4GL_USE_PANGO_ML")))
    {
      A4GL_debug ("using PANGO ML for Label '%s'\n", str);
      gtk_label_set_use_markup (GTK_LABEL (label), TRUE);
    }
#endif
  g_free (lab_utf);
  evt = gtk_event_box_new ();

  if (A4GL_isyes (acl_getenv ("FITOSIZE_ERRWIN")));
  else
    {
      gtk_widget_set_usize (GTK_WIDGET (frame), w * gui_xwidth,
			    h * gui_yheight + 2);
    }

  errorWindow = frame;
  gtk_container_add (GTK_CONTAINER (frame), evt);
  gtk_container_add (GTK_CONTAINER (evt), label);
  gtk_fixed_put (win_screen, errorWindow, x * gui_xwidth, y * gui_yheight);
// Align it halfway through the frame vertically, but on the left
//
  gtk_misc_set_alignment (GTK_MISC (label), 0, 0.5f);
  if (attr == 0 || attr == -1)
    {
      SPRINTF0 (buff, "Error");
      FPRINTF (stderr, "Error string : '%s'\n", str);
      gtk_widget_set_name (GTK_WIDGET (frame), buff);
      gtk_widget_set_name (GTK_WIDGET (evt), buff);
      gtk_widget_set_name (GTK_WIDGET (label), buff);
    }
  else
    {
      FPRINTF (stderr, "ATTR = %x\n", attr);
      SPRINTF1 (buff, "%x", attr >> 8);
      gtk_widget_set_name (GTK_WIDGET (frame), buff);
      gtk_widget_set_name (GTK_WIDGET (evt), buff);
      gtk_widget_set_name (GTK_WIDGET (label), buff);
    }




//if (attr&0xffffff00) { A4GL_LL_set_field_back ((GtkWidget *) evt  , attr&0xffffff00); A4GL_LL_set_field_fore ((GtkWidget *) label, attr&0xffffff00); }

  gtk_widget_show (evt);
  gtk_widget_show (label);
  gtk_widget_show (errorWindow);
  A4GL_debug ("error window : Returning %p", errorWindow);
  return errorWindow;
}


#ifdef XDEF
char *
A4GL_decode_str_fprop (struct_scr_field * fprop, int type)
{
  int b;
  for (b = 0; b < fprop->str_attribs.str_attribs_len; b++)
    {
      if (fprop->str_attribs.str_attribs_val[b].type == type)
	{
	  return fprop->str_attribs.str_attribs_val[b].value;
	}
    }
  return "";
}
#endif

/******************************************************************************
 *   Not Implemented Yet...
 *****************************************************************************/

/******************************************************************************
 *   MISC
 *****************************************************************************/
void
A4GL_LL_set_bkg (void *win, int attr)
{
  char buff[256];
  void *x;
  char *ptr;
  SPRINTF1 (buff, "%x", attr >> 8);
  ptr = (char *) gtk_widget_get_name (GTK_WIDGET (win));
  // If its an appwindow - we don't want to rename it..
  if (strcmp (ptr, "AppWindow") == 0)
    return;

  gtk_widget_set_name (GTK_WIDGET (win), buff);
  x = gtk_object_get_data (GTK_OBJECT (win), "FIXED");
  if (x)
    {
      gtk_widget_set_name (GTK_WIDGET (x), buff);
    }
  x = gtk_object_get_data (GTK_OBJECT (win), "TOP");
  if (x)
    {
      gtk_widget_set_name (GTK_WIDGET (x), buff);
    }




}

int
A4GL_LL_dump_screen (int n, char *fname, int mode)
{
  return 0;
// NIY
}

/******************************************************************************
 *   PROMPT
 *****************************************************************************/

int prompt_style = 0;
int prompt_last_key = 0;

/**
 * Implementation in GTK GUI mode of the first part of C version PROMPT
 * 4gl statement.
 *
 * @param prompt A pointer to the prompt identifier structure where this
 *   function initialize the values.
 * @param ap The attributes for the message.
 * @param c Prompt for char (cbreak()) flag.
 * @param h The help number.
 * @param af The attributes.
 */
int
A4GL_LL_start_prompt (void *vprompt, char *promptstr, int ap, int c, int h,
		      int af, int curr_width, int iscurrborder,
		      int prompt_line, void *currwin, int prompt_mode)
{
  int promptline;
  void *p;
  void *cw;
  struct s_a4gl_gtk_form *f;
  int width;
  char buff[300];
  int a;
  int field_cnt = 0;
  GtkWidget **widgets;
  list_of_fields lof;
  A4GL_debug ("In start prompt %d %d %d %d", ap, c, h, af);
  last_prompt_mode = prompt_mode;

A4GL_LL_gui_run_til_no_more(); // <---------------------------------------------------------------------

  widgets = acl_malloc2 (sizeof (GtkWidget *) * 10);

  prompt_last_key = 0;
  memset (buff, ' ', 255);
  promptline = prompt_line;
  A4GL_debug ("promptline=%d", promptline);
  width = curr_width;
  A4GL_debug ("create window %d %d", 1, promptline);
  A4GL_debug ("%d %d", width - 1, 2);
  cw = (void *) currwin;

  cw = gtk_object_get_data (GTK_OBJECT (cw), "FIXED");
  if (cw == 0)
    {
      FPRINTF (stderr, "NO FIXED...\n");
    }

  if (iscurrborder)
    promptline++;


  p = gtk_fixed_new ();
  gtk_object_set_data (GTK_OBJECT (p), "FIXED", p);
	//A4GL_pause_execution();

A4GL_LL_gui_run_til_no_more(); // <---------------------------------------------------------------------



#if GTK_CHECK_VERSION(2,0,0)
  gtk_fixed_set_has_window (GTK_FIXED (p), 1);
#endif
  gtk_widget_show (p);
  gtk_widget_set_usize (GTK_WIDGET (p), width * gui_xwidth, 1 * gui_yheight);
  gtk_fixed_put (GTK_FIXED (cw), p, iscurrborder,
		 (promptline - 1) * gui_yheight);

  if (p == 0)
    {
      A4GL_exitwith ("No prompt window created");
      FPRINTF (stderr, "Nope1\n");
      return 0;
    }
  last_prompt_win = p;

  width -= strlen (promptstr);
  width--;


  if (strlen (promptstr))
    {
      GtkWidget *evt;
      evt = gtk_event_box_new ();
      widgets[field_cnt++] = (void *) A4GL_LL_make_label (0, 0, promptstr);
      gtk_container_add (GTK_CONTAINER (evt), widgets[field_cnt - 1]);
      gtk_widget_show (evt);
      gtk_misc_set_alignment (GTK_MISC (widgets[field_cnt - 1]), 0.0f, 0.5f);
      gtk_fixed_put (GTK_FIXED (p), evt, 0, 0);


	      A4GL_LL_set_field_back (widgets[0], A4GL_LL_colour_code (0));
	      A4GL_LL_set_field_fore (widgets[0], A4GL_LL_colour_code (7));
      //ap = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, ap, 0, 0);
      if (ap)
	{
		
	  A4GL_debug ("AP...");
	  if (strlen (promptstr))
	    {
		

	      A4GL_LL_set_field_fore (widgets[0], A4GL_LL_decode_aubit_attr (ap, 'f'));
	      A4GL_LL_set_field_back (evt, A4GL_LL_decode_aubit_attr (ap, 'b'));
	    }
	}
	  else
	    {
	      A4GL_LL_set_field_back (widgets[0], A4GL_LL_colour_code (0));
	      A4GL_LL_set_field_fore (widgets[0], A4GL_LL_colour_code (7));
	    }
    }
  A4GL_debug ("Creating field %d %d %d", strlen (promptstr) + 1, 1,
	      width - 1);
A4GL_LL_gui_run_til_no_more(); // <---------------------------------------------------------------------

  A4GL_LL_set_new_page (widgets[field_cnt - 1], 1);

  widgets[field_cnt++] =
    (GtkWidget *) A4GL_LL_make_field (0, strlen (promptstr), 1, width - 1, 0,0,
				      0, 0,"","");


  gtk_fixed_put (GTK_FIXED (p), widgets[field_cnt - 1], (strlen (promptstr) + 1) * gui_xwidth, 0);
  last_prompt_field = widgets[field_cnt - 1];

  for (a = 0; a < field_cnt; a++)
    {
      if (widgets[a]) {
	gtk_widget_show (GTK_WIDGET (widgets[a]));
	
	}
    }


  A4GL_default_attributes_in_ll (last_prompt_field, 0, 0);
  A4GL_fld_opts_off (last_prompt_field, AUBIT_O_STATIC);
  //gtk_widget_show (last_prompt_field);

  if (af)
    {
      A4GL_debug ("AF...");
      A4GL_LL_set_field_back (last_prompt_field, A4GL_LL_decode_aubit_attr (af, 'f'));
      A4GL_LL_set_field_fore (last_prompt_field, A4GL_LL_decode_aubit_attr (af, 'b'));	// maybe need 'B' for whole field..
      if (af & AUBIT_ATTR_INVISIBLE)
	{
	  A4GL_debug ("Invisible");
	  A4GL_fld_opts_off (last_prompt_field, AUBIT_O_PUBLIC);
	}

    }
  A4GL_fld_opts_on (last_prompt_field, AUBIT_O_NULLOK);
  A4GL_debug ("Set attributes");

  buff[0] = 0;			/* -2 */
  A4GL_debug ("Setting Buffer %p to '%s'", last_prompt_field, buff);
  A4GL_LL_set_field_buffer (last_prompt_field, 0, buff,0);
  A4GL_debug ("Set buffer ");


  A4GL_debug ("Made fields");

  lof.a.a_len = field_cnt;
  lof.a.a_val = (long *) widgets;

  f = A4GL_LL_new_form (&lof);
  f->currentfield = f->nwidgets - 1;
  A4GL_debug ("Form f = %p", f);
  last_prompt_f = f;
  //A4GLSQL_set_status (0, 0);
  

  for (a=0;a< f->nwidgets;a++) { 
		A4GL_gui_set_active(widgets[a],1); 
  }


  free (widgets);

  if (a4gl_status != 0)
    {
      //last_prompt_mode = 2;
      FPRINTF (stderr, "Nope2\n");
      return 2;
    }

  A4GL_debug ("Set form win");
  A4GL_debug ("Posted form=%d", a);
  A4GL_LL_int_form_driver (f, AUBIT_REQ_FIRST_FIELD);
  A4GL_LL_int_form_driver (f, AUBIT_REQ_OVL_MODE);
  //A4GLSQL_set_status (0, 0);
  A4GL_LL_screen_update ();
  FPRINTF (stderr, "All ok\n"); 

  return 1;
}



void
A4GL_LL_clear_prompt (void *f, void *w)
{
  gtk_widget_destroy (w);
}








/**
 * Set the GUI prompt style.
 *
 * @param a The prompt style
 */
void
A4GL_gui_prompt_style (int a)
{
  if (a >= 0 && a <= 3)
    prompt_style = a;
  else
    prompt_style = 0;
}


/* ================================== EOF =========================== */





















/******************************************************************************
 *   FORM HANDLING
 *****************************************************************************/
void *
A4GL_LL_display_form (void *fd, int attrib, int curr_width, int curr_height,
		      int iscurrborder, int currwinno, int form_line,
		      void *currwin, void *frm, int maxline, int maxcol, char *name)
{

  int rows, cols;
  int b;
  //char buff[80];
  int a;
  GtkWidget *w;
  GtkWidget *drwin;
  GtkFixed *cwin;
  int x, y;


  int fl;
  struct s_a4gl_gtk_form *form;
  GtkWidget *labwidget;
  char buff_label[50];

  form = frm;			// f->form;

  A4GL_debug ("In display_form");


  w = (GtkWidget *) currwin;
  cwin = gtk_object_get_data (GTK_OBJECT (w), "FIXED");


  if (w == 0)
    {
      A4GL_LL_error_box ("NO WINDOW", 0);
    }

  A4GL_debug ("scale form %p", frm);

  fl = form_line;
  for (a = fl; a <= curr_height; a++)
    {
      for (x = 0; x < 255; x++)
	{
	  SPRINTF2 (buff_label, "LABEL_%d_%d", x, a);
	  labwidget = gtk_object_get_data (GTK_OBJECT (w), buff_label);
	  if (labwidget)
	    {
	      gtk_widget_destroy (labwidget);
	    }
	}
    }
  drwin = gtk_object_get_data (GTK_OBJECT (cwin), "FORMWINDOW");
  if (drwin)
    {
      gtk_widget_destroy (drwin);
      drwin = 0;
    }


  //A4GL_LL_scale_form (fd, &rows, &cols);

  rows = maxline;		//f->fileform->maxline - 1;
  cols = maxcol;		//f->fileform->maxcol;

  A4GL_debug ("Form line=%d", fl);
  A4GL_debug ("Scale form returns %d %d", rows, cols);

  if (iscurrborder)
    {
      rows++;
    }
  else
    {
    }

  if (rows - iscurrborder > curr_width + 1)
    {
      A4GL_exitwith ("Window is too small to display this form (too high)");
      return 0;
    }


  if (cols - iscurrborder > curr_width + 1)
    {
      A4GL_exitwith ("Window is too small to display this form (too wide)");
      return 0;
    }

  //f->form_details.border = iscurrborder ;

  if (iscurrborder)
    {
      A4GL_debug ("Form details returns it has border");
    }
  else
    {
      A4GL_debug ("Form details returns it has *NO* border");
    }

  if (iscurrborder)
    {
      A4GL_debug ("Window details returns it has border");
    }
  else
    {
      A4GL_debug ("Window details returns it has *NO* border ");
    }

  if (form->notebook)
    {
      drwin = form->notebook;
    }
  else
    {
      drwin = gtk_fixed_new ();
    }

  if (iscurrborder)
    {
      //gtk_fixed_put (cwin, drwin, 1, (fl + 1) * gui_yheight);
      gtk_fixed_put (cwin, drwin, 1, (fl) * gui_yheight);
    }
  else
    {
      gtk_fixed_put (cwin, drwin, 0, (fl - 1) * gui_yheight);
      //A4GL_debug ("MJAPASS2 rows=%d cols=%d fl=%d", rows, cols, fl);
      //drwin = derwin (panel_window ((PANEL *) w), rows, cols, fl - 1, 0);
    }


  gtk_object_set_data (GTK_OBJECT (cwin), "FORMWINDOW", (void *) drwin);
  gtk_object_set_data (GTK_OBJECT (drwin), "FIXED", (void *) drwin);

  A4GL_start_form (frm);
  A4GL_clr_form (0);
  A4GL_debug ("And return");
  A4GL_LL_screen_update ();
  if (!form->notebook)
    {
      for (a = 0; a < form->nwidgets; a++)
	{
	  if (gtk_object_get_data
	      (GTK_OBJECT (form->widgets[a]), "MF_ISLABEL"))
	    {
	      char *ptr;
	      x =
		(int) gtk_object_get_data (GTK_OBJECT (form->widgets[a]),
					   "MF_FCOL") + 1;
	      y =
		(int) gtk_object_get_data (GTK_OBJECT (form->widgets[a]),
					   "MF_FROW") + 1;
	      ptr =
		gtk_object_get_data (GTK_OBJECT (form->widgets[a]),
				     "MF_LABELSTR");
	      if (strlen (ptr))
		{

		  /*
		     for (b = 0; b < strlen (ptr); b++)
		     {
		     int c = ptr[b] & 0xff;
		     A4GL_LL_wadd_char_xy_col (drwin, x + b, y, c,
		     curr_width, curr_height,
		     iscurrborder, currwinno);
		     }
		   */

		  /* wh: allow non-ascii labels */
		  gchar *utf ;
	//printf("txt=%s\n",ptr);
			utf= g_locale_to_utf8 (ptr, -1, NULL, NULL, NULL);
		  for (b = 0; b < g_utf8_strlen (utf, -1); b++)
		    {
		      gunichar uni =
			g_utf8_get_char_validated (g_utf8_offset_to_pointer
						   (utf, b), -1);
		      A4GL_LL_wadd_gunichar_xy_col (drwin, x + b, y, uni,
						    curr_width, curr_height,
						    iscurrborder, currwinno);
		    }
		  g_free (utf);
		}

	    }
	  else
	    {
	      x =
		(int) gtk_object_get_data (GTK_OBJECT (form->widgets[a]),
					   "MF_FCOL") * gui_xwidth;
	      y =
		(int) gtk_object_get_data (GTK_OBJECT (form->widgets[a]),
					   "MF_FROW") * gui_yheight;
	      gtk_fixed_put (GTK_FIXED (drwin), form->widgets[a], x, y);
	      gtk_widget_ref (form->widgets[a]);
	    }
	  gtk_widget_show (form->widgets[a]);

	  gtk_widget_show (drwin);
	}
    }

  return drwin;
}


#ifdef NO_LONGER_REQUIRED
void
A4GL_LL_scale_form (void *vfd, int *y, int *x)
{
  struct s_form_dets *f;
  struct s_a4gl_gtk_form *form;
  //struct s_form_dets *fd;
  GtkWidget *widget;
  int a;
  int max_x = 0;
  int max_y = 0;
  int wx, wy, ww, wh;


  f = vfd;
//fd=vfd;

  if (f == 0)
    {
      A4GL_exitwith ("INTERNAL ERROR BAD FORM");
      return;
    }
  form = f->form;
  if (form == 0)
    {
      A4GL_exitwith ("INTERNAL ERROR BAD FORM");
      return;
    }




  A4GL_assertion (form->nwidgets
		  && form->widgets == 0, "No widgets on the form");

  for (a = 0; a < form->nwidgets; a++)
    {
      widget = form->widgets[a];
      wx = (int) gtk_object_get_data (GTK_OBJECT (widget), "MF_FCOL");
      wy = (int) gtk_object_get_data (GTK_OBJECT (widget), "MF_FROW");
      if (gtk_object_get_data (GTK_OBJECT (widget), "MF_ISLABEL"))
	{
	  ww =
	    strlen ((char *)
		    gtk_object_get_data (GTK_OBJECT (widget), "MF_LABELSTR"));
	  wh = 1;
	}
      else
	{
	  ww = (int) gtk_object_get_data (GTK_OBJECT (widget), "MF_COLS");
	  wh = (int) gtk_object_get_data (GTK_OBJECT (widget), "MF_ROWS");
	}
      wx += ww;
      wy += wh;
      if (wx > max_x)
	max_x = wx;
      if (wy > max_y)
	max_y = wy;

    }
  *y = max_y;
  *x = max_x;

}

#endif


int
A4GL_LL_form_page (void *vform)
{
  return 1;
}


int
A4GL_LL_get_carat_y (void *vform) {
	return 1;
}

int
A4GL_LL_get_carat (void *vform)
{
  struct s_a4gl_gtk_form *form;
  form = vform;

  return form->curcol;
}


void *
A4GL_LL_make_field (int frow, int fcol, int rows, int cols, char *widget_str,
		    char *config, char *incl, void *id,char *tab_and_col,char* action)
{
  //struct struct_scr_field *fprop;
  void *widget;
  char *config_str;


  if (widget_str == 0)
    widget_str = "";
  config_str = config;

  if (strlen (widget_str) == 0)
    widget_str = "ENTRY";
  if (config_str == 0)
    config_str = "";


  widget = (void *) A4GL_make_widget (widget_str, config_str, cols,rows);
  if (widget == 0)
    {
      // Ooops - didn't make a widget...
      widget = (void *) A4GL_make_widget ("ENTRY", "", cols,rows);
      FPRINTF (stderr,
	       "WARNING - Coulnd't make widget as %s %s, made an entry field instead\n",
	       widget_str, config_str);
      if (widget == 0)
	{			// Couldn't even fake one..
	  A4GL_assertion (1, "Failed to make a widget");
	}
    }
  A4GL_LL_set_field_opts (widget, 0);

  gtk_object_set_data (GTK_OBJECT (widget), "Attribute", (void *) id);
  gtk_object_set_data (GTK_OBJECT (widget), "MF_FROW", (void *) frow);
  gtk_object_set_data (GTK_OBJECT (widget), "MF_FCOL", (void *) fcol);
  gtk_object_set_data (GTK_OBJECT (widget), "MF_ROWS", (void *) rows);
  gtk_object_set_data (GTK_OBJECT (widget), "MF_COLS", (void *) cols);
  gtk_object_set_data (GTK_OBJECT (widget), "MF_ISLABEL", (void *) 0);
	//printf("---->%s\n", tab_and_col);
  gtk_object_set_data (GTK_OBJECT (widget), "TAB_AND_COL", strdup(tab_and_col));

  if (A4GL_aubit_strcasecmp ("LABEL", widget_str) == 0)
    {
      gtk_object_set_data (GTK_OBJECT (widget), "DISPLAY_LABEL", (void *) 1);
      gtk_widget_set_name (GTK_WIDGET (widget), "AppWindow");
#if GTK_CHECK_VERSION(2,0,0)
      if (A4GL_isyes (acl_getenv ("A4GL_USE_PANGO_ML")))
	gtk_label_set_use_markup (GTK_LABEL (widget), TRUE);
#endif
    }

  return widget;
}

void *
A4GL_LL_make_label (int frow, int fcol, char *label)
{
  GtkWidget *widget = 0;
  char *label_utf;

  if (strcmp (label, "[") == 0)
    {
      A4GL_debug("Wimping out and not making a '[' label\n");
      return 0;
    }
  if (strcmp (label, "]") == 0)
    {
      A4GL_debug ("Wimping out and not making a ']' label\n");
      return 0;
    }

	//printf("txt=%s\n",label);
  label_utf = g_locale_to_utf8 (label, -1, NULL, NULL, NULL);
  widget = gtk_label_new (label_utf);

#if GTK_CHECK_VERSION(2,0,0)
  if (A4GL_isyes (acl_getenv ("A4GL_USE_PANGO_ML")))
    {
      A4GL_debug ("using PANGO ML for Label '%s'\n", label);
      gtk_label_set_use_markup (GTK_LABEL (widget), TRUE);
    }
#endif
  g_free (label_utf);


  gtk_widget_set_name (GTK_WIDGET (widget), "FormLabel");

  gtk_object_set_data (GTK_OBJECT (widget), "MF_FROW", (void *) frow);
  gtk_object_set_data (GTK_OBJECT (widget), "MF_FCOL", (void *) fcol);
  gtk_object_set_data (GTK_OBJECT (widget), "MF_ISLABEL", (void *) 1);
  gtk_object_set_data (GTK_OBJECT (widget), "MF_LABELSTR", strdup (label));

  return widget;

}


void
A4GL_LL_set_carat (void *vform)
{
  struct s_a4gl_gtk_form *form;
  char *s;
  GtkWidget *w;
  form = vform;
  w = form->widgets[form->currentfield];

  gtk_widget_grab_focus (GTK_WIDGET (w));
  s = gtk_object_get_data (GTK_OBJECT (w), "WIDGETSNAME");

  if (s)
    {
      if (strcmp (s, "ENTRY") == 0)
	{
	 if (gtk_object_get_data (GTK_OBJECT (w), "ISTEXTVIEW")) {
	 } else {
	  gtk_editable_set_position (GTK_EDITABLE
				     (form->widgets[form->currentfield]),
				     form->curcol);
	  }
	}
    }
}


void
A4GL_LL_set_field_buffer (void *field, int n, char *str,char *orig)
{
  A4GL_display_generic (field, str,orig);
}

void
A4GL_LL_set_form_page (void *vform, int page)
{
//struct s_a4gl_gtk_form *form;
}

void *
A4GL_LL_new_form (list_of_fields * vfd)
{
  struct s_a4gl_gtk_form *form;
  int a;



  form = acl_malloc2 (sizeof (struct s_a4gl_gtk_form));

/* Set everything up.. */
  form->frmMagic = 0xABC123;
  form->nwidgets = 0;
  form->npages = 1;
  form->currentpage = 1;
  form->curcol = 0;
  form->currentfield = 0;
  form->widgets = 0;
  form->notebook = 0;
  form->userptr = 0;

  for (a = 0; a < vfd->a.a_len; a++)
    {
      if (gtk_object_get_data (GTK_OBJECT (vfd->a.a_val[a]), "NEWPAGE"))
	form->npages++;
    }


  form->nwidgets = vfd->a.a_len;
  form->widgets = acl_malloc2 (sizeof (void *) * vfd->a.a_len);

  if (form->npages > 1)
    {
      form->notebook = gtk_notebook_new ();
      gtk_widget_show (form->notebook);
    }
  else
    {
      form->notebook = 0;
    }

  for (a = 0; a < vfd->a.a_len; a++)
    {
      form->widgets[a] = (void *) vfd->a.a_val[a];
      A4GL_gui_set_active (form->widgets[a], 0);
    }
  return form;
}


int
A4GL_LL_int_form_driver (void *vform, int mode)
{
  struct s_a4gl_gtk_form *form;
  GtkWidget *cwidget;
  int a = 0;
  form = vform;

  A4GL_assertion (form->currentfield < 0
		  || form->currentfield > form->nwidgets,
		  "Invalid current field");

  cwidget = form->widgets[form->currentfield];

  if (mode <= 255 && a_isprint (mode) && mode >= ' ')
    {
      gint iopos;
      char buff[2];
      char *utf;
      //struct struct_scr_field *fprop;

      int m;
      int autonext;

      autonext = A4GL_LL_field_opts (cwidget) & AUBIT_O_AUTOSKIP;
      //fprop = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (cwidget));


      m = (int) gtk_object_get_data (GTK_OBJECT (cwidget), "MAXFIELD");
      buff[0] = mode;
      buff[1] = 0;
	//printf("txt=%s\n",buff);
      utf = g_locale_to_utf8 (buff, -1, NULL, NULL, NULL);

      if (A4GL_LL_field_opts (cwidget) & AUBIT_O_BLANK && form->curcol == 0)
	{
	  //A4GL_clr_field(cwidget);
	  A4GL_LL_set_field_buffer (cwidget, 0, " ", 0);
	}


      if (gtk_object_get_data (GTK_OBJECT (cwidget), "ISTEXTVIEW"))
	{

	  // Needs implementing...
	}
      else
	{


	  if (form->ovlins == 1)
	    {
	      iopos = form->curcol;
	      gtk_editable_insert_text (GTK_EDITABLE (cwidget), utf,
					strlen (utf), &iopos);
	      form->curcol++;
	      if (form->curcol >= m && autonext)
		form->curcol = 0;
	    }
	  else
	    {
	      gtk_editable_delete_text (GTK_EDITABLE (cwidget), form->curcol,
					form->curcol + 1);
	      iopos = form->curcol;
	      gtk_editable_insert_text (GTK_EDITABLE (cwidget), utf,
					strlen (utf), &iopos);
	      form->curcol++;
	      if (form->curcol >= m && autonext)
		form->curcol = 0;
	      //form->curcol+=strlen(utf);
	    }


	}
      g_free (utf);
    }
  else
    {
      switch (mode)
	{
	case AUBIT_REQ_BEG_FIELD:
	  form->curcol = 0;
	  break;

	case AUBIT_REQ_END_FIELD:
	  {
	    char *x =
	      g_locale_from_utf8 (gtk_entry_get_text (GTK_ENTRY (cwidget)),
				  -1, NULL, NULL, NULL);
	    if (x)
	      {
		A4GL_trim (x);
		form->curcol = strlen (x);
		g_free (x);
	      }
	  }
	  break;


	case AUBIT_REQ_CLR_EOF:
	  gtk_editable_delete_text (GTK_EDITABLE (cwidget), form->curcol, -1);
	  break;


	case AUBIT_REQ_CLR_FIELD:
	  gtk_editable_delete_text (GTK_EDITABLE (cwidget), 0, -1);
	  break;


	case AUBIT_REQ_DEL_CHAR:
	  gtk_editable_delete_text (GTK_EDITABLE (cwidget), form->curcol,
				    form->curcol + 1);
	  break;


	case AUBIT_REQ_DEL_PREV:
	  if (form->curcol > 0)
	    {
	      gtk_editable_delete_text (GTK_EDITABLE (cwidget),
					form->curcol - 1, form->curcol);
	      form->curcol--;
	    }
	  break;

	case AUBIT_REQ_FIRST_FIELD:
	  for (a = 0; a < form->nwidgets; a++)
	    {
	      cwidget = form->widgets[a];
	      if (gtk_object_get_data (GTK_OBJECT (cwidget), "MF_ISLABEL"))
		continue;
	      form->currentfield = a;
	      break;
	    }
	  break;



	case AUBIT_REQ_FIRST_PAGE:
	  break;


	case AUBIT_REQ_INS_MODE:
	  form->ovlins = 1;
	  break;


	case AUBIT_REQ_NEXT_CHAR:
	  form->curcol++;
	  break;


	case AUBIT_REQ_OVL_MODE:
	  form->ovlins = 0;
	  break;


	case AUBIT_REQ_PREV_CHAR:
	  form->curcol--;
	  if (form->curcol < 0)
	    form->curcol = 0;
	  break;


	case AUBIT_REQ_VALIDATION:
	  break;


	default:
	  if (mode > 255)
	    {
	      FPRINTF (stderr, "Unknown mode : %d\n", mode);
	      {
		char *ptr = 0;
		*ptr = 0;
	      }
	    }
	}
    }
  return 0;
}

long
A4GL_LL_set_field_attr (void *field, int dtype, int dynamic, int autonext, int invis, int reqd, int compress, int has_picture)
{
  A4GL_debug ("Setting defs");


  A4GL_default_attributes_in_ll (field, dtype, has_picture);


  A4GL_debug ("Set defs");

  if (autonext)
    {
      A4GL_debug ("Autoskip");
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_fld_opts_on (field, AUBIT_O_AUTOSKIP);
    }

  if (invis)
    {
      A4GL_debug ("Invisible ***");
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_fld_opts_off (field, AUBIT_O_PUBLIC);
    }

  if (dynamic != 0)
    {
      A4GL_debug ("ZZZZ - SET OPTS STATIC OFF");
      A4GL_fld_opts_off (field, AUBIT_O_STATIC);

      if (dynamic == -1)
	{
	  A4GL_LL_set_max_field (field, 0,0);
	}
      else
	{
	  A4GL_LL_set_max_field (field, dynamic,0);
	}

    }
  else
    {
      A4GL_fld_opts_on (field, AUBIT_O_STATIC);
    }

  if (reqd)
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_fld_opts_off (field, AUBIT_O_NULLOK);
    }
  else
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_fld_opts_on (field, AUBIT_O_NULLOK);
    }

  if (compress)
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_fld_opts_on (field, AUBIT_O_WRAP);
    }

  return A4GL_LL_field_opts(field);
}


#include <sys/timeb.h>



void
tstamp (char *s)
{
  static FILE *ts = 0;
  static double ltime = 0;
  static double lltime = 0;
  double ntime = 0;
  struct timeb tp;
  return;

  ftime (&tp);
  ntime = (double) tp.time;
  ntime = ntime + (double) tp.millitm / 1000.0;

  if (ts == 0)
    {
      ts = fopen ("timings.out", "w");
    }
  if (ts == 0)
    return;

  if (strcmp (s, "START") == 0)
    {
      ltime = ntime;
      lltime = ntime;
      return;
    }
  FPRINTF (ts, "%s Since START %f Since Last TS %f\n", s, ntime - ltime,
	   ntime - lltime);
  lltime = ntime;
}







void
A4GL_decode_gui_winname (char *name)
{
  char buff[256];
  char *ptr;
  strcpy (buff, name);
  ptr = strchr (name, '_');
  A4GL_debug ("Decoding name %s - ptr=%p", name, ptr);
  if (ptr)
    {
      strcpy (buff, ptr + 1);
      A4GL_debug ("Buff=%s\n", buff);
      strcpy (name, buff);
    }
}







static void *
find_curr_window (void *currwin)
{
  void *w;
  w = (void *) currwin;
  if (gtk_object_get_data (w, "TOP"))
    {
      A4GL_debug ("Has parent...");
      w = gtk_object_get_data (w, "TOP");
    }
  return w;
}

int
A4GL_LL_set_window_title (void *currwin, char *s)
{
  A4GL_trim (s);
  gtk_window_set_title (GTK_WINDOW (find_curr_window (currwin)), s);
  /* End of code */
  return 0;
}




int
A4GL_LL_widget_name_match (void *wv, char *name)
{

  GtkWidget *w;
  void *s;
  w = wv;
  if (w == 0)
    return 0;

  s = gtk_object_get_data (GTK_OBJECT (w), "Attribute");

  if (s == 0)
    {
      return 0;
    }
  return A4GL_attr_name_match (s, name);

}


void
A4GL_LL_clr_form_fields (int to_defaults, char *defs)
{
  return;
}




/*
** orig     = original string
** evt      = original event list from contruct..
** init_key = initial keystroke that caused us to be here.. (0 for before field)
** init_pos = position in field as retrived from the original field..
*/
void *
A4GL_LL_construct_large (char *orig, void *vevt, int init_key, int initpos,
			 char *l, char *r, int curr_width, int curr_height,
			 int fl, void *currwin, int isborder)
{
  static char rbuff[1024];
  //static char rbuff2[1024];
  struct s_form_dets fd;
  void *cwin;
  GtkWidget *drwin;
  GtkWidget *v;
  struct s_a4gl_gtk_form *f;
  list_of_fields lof;
  //int ins_ovl = 'o';
  //int looping = 1;
  int fwidth;
  int a;
  struct aclfgl_event_list *evt;
  evt = vevt;
  A4GL_debug ("In construct_large");

  strcpy (rbuff, orig);

  fwidth = curr_width;
  if (fwidth > 80)
    fwidth = 80;
  cwin = currwin;
  if (fl > curr_height)
    fl = curr_height;
  drwin = gtk_fixed_new ();
  v = gtk_hbox_new (0, 1);

  //fd.form_fields[0]=gtk_label_new("[");
  //fd.form_fields[2]=gtk_label_new("]");

  fd.form_fields[0] = A4GL_LL_make_field (0, 0, 0, fwidth, 0, 0, 0, 0,"","");	// gtk_entry_new();

  fd.form_fields[1] = 0;

  //gtk_object_set_data(GTK_OBJECT(fd.form_fields[0]),"WIDGETSNAME","LABEL");
  //gtk_object_set_data(GTK_OBJECT(fd.form_fields[2]),"WIDGETSNAME",(void *)"LABEL");

  A4GL_fld_opts_on (fd.form_fields[0], AUBIT_O_ACTIVE);
  A4GL_fld_opts_on (fd.form_fields[0], AUBIT_O_EDIT);
  A4GL_fld_opts_on (fd.form_fields[0], AUBIT_O_BLANK);
  gtk_object_set_data (GTK_OBJECT (fd.form_fields[0]), "WIDGETSNAME",
		       (void *) "ENTRY");
  gtk_widget_show (fd.form_fields[0]);

  //gtk_widget_show(fd.form_fields[1]);
  //gtk_widget_show(fd.form_fields[2]);


  lof.a.a_len = 1;
  lof.a.a_val = (long *) fd.form_fields;
  f = A4GL_LL_new_form (&lof);

  f->currentfield = 0;
  A4GL_LL_set_field_buffer (fd.form_fields[0], 0, rbuff,0);

  gtk_container_add (GTK_CONTAINER (v), fd.form_fields[0]);

  //gtk_container_add(GTK_CONTAINER(v),fd.form_fields[1]);
  //gtk_container_add(GTK_CONTAINER(v),fd.form_fields[2]);

  gtk_widget_set_sensitive (fd.form_fields[0], 1);
  //gtk_widget_set_sensitive(fd.form_fields[1],1);
  //gtk_widget_set_sensitive(fd.form_fields[2],1);
  cwin = gtk_object_get_data (GTK_OBJECT (cwin), "FIXED");
  gtk_fixed_put (GTK_FIXED (cwin), GTK_WIDGET (drwin), 0, (fl) * gui_yheight);
  gtk_fixed_put (GTK_FIXED (drwin), GTK_WIDGET (v), 0, 0);
  last_construct_drwin = drwin;

  gtk_widget_show_all (drwin);
  A4GL_LL_screen_update ();
  A4GL_LL_int_form_driver (f, AUBIT_REQ_OVL_MODE);

  if (initpos)
    {
      A4GL_LL_int_form_driver (f, AUBIT_REQ_END_FIELD);
    }

  a = 0;
  return f;
}

char *
A4GL_LL_construct_large_finished (void *f)
{
  static char orig[2000];
  A4GL_LL_int_form_driver (f, AUBIT_REQ_VALIDATION);
  strcpy (orig, A4GL_LL_field_buffer (A4GL_LL_current_field (f), 0));
  gtk_widget_destroy (last_construct_drwin);
  A4GL_LL_screen_update ();
  return orig;
}




int
A4GL_LL_disp_form_fields_ap (int n, int attr, char *formname, va_list * ap)
{
  return 0;
}





int
menu_callback (gpointer data)
{
  //int nbutton;
  //A4GL_debug("Widget=%p data=%d\n",widget,data);
  //nbutton=(int)gtk_object_get_data(GTK_OBJECT(widget),"BUTTON");
  menu_response = (int) data;

  // A4GL_clr_error_nobox ("menu_callback");

  keybuffer_cnt = 0;		/* throw away buffered keys when menuoption is selected */
  return TRUE;
}


int
A4GL_LL_hide_h_menu (void)
{
  GtkWidget *bb;
  bb = gtk_object_get_data (GTK_OBJECT (win_screen), "BB");
  if (bb == 0)
    return 0;
  A4GL_debug ("HIDE hide_h_menu\n");
	setMenu(bb,0);
  return 1;
}


static int
A4GL_show_ok_cancel (int n)
{
  static int shown=-1;
  GtkWidget *bb;
  GtkWidget *okcancel;

  if (n==shown) return 1;  // already doing that...

  shown=n;

  if (n)
    {
      okcancel = gtk_object_get_data (GTK_OBJECT (win_screen), "OKCANCEL");
      bb = gtk_object_get_data (GTK_OBJECT (win_screen), "BB");
      if (okcancel == 0) return 0;
      //if (bb ) { gtk_widget_hide (bb); }
      gtk_widget_show (okcancel);
      gtk_widget_set_sensitive(okcancel,1);
	//gtk_widget_set_sensitive(bb,0);
    }
  else
    {
      okcancel = gtk_object_get_data (GTK_OBJECT (win_screen), "OKCANCEL");
      bb = gtk_object_get_data (GTK_OBJECT (win_screen), "BB");
      if (okcancel == 0) return 0;

	gtk_widget_set_sensitive(okcancel,0);
        gtk_widget_show (okcancel);
	//gtk_widget_set_sensitive(bb,1);
        //gtk_widget_hide (okcancel);
        //if (bb) { gtk_widget_show (bb); }
    }
  return 1;
}


int
A4GL_LL_disp_h_menu (int num_opts, char *title, char* style,char* comment,char* image )
{
  GtkWidget *bb;
  GtkWidget *b;
  int nbuttons;
  int a;
  char buff[255];
  //FPRINTF (stderr, "disp_h_menu\n");
  if (A4GL_isyes (acl_getenv ("TRADMENU")))
    return 0;

  bb = gtk_object_get_data (GTK_OBJECT (win_screen), "BB");
  if (bb == 0)
    return 0;
  setMenu(bb,1);
	//gtk_widget_set_sensitive(bb,1);
  //gtk_widget_show (bb);
  nbuttons = (int) gtk_object_get_data (GTK_OBJECT (bb), "NBUTTONS");

  while (nbuttons < num_opts)
    {
      GtkWidget *b;
      //GtkWidget *l;
      //GtkWidget *v;
      //GtkWidget *i;
      SPRINTF1 (buff, "BUTTON_%d", nbuttons);
      //l = gtk_label_new (" ");
      b = gtk_button_new ();
      //v=gtk_vbox_new(0,0);
      //i=gtk_image_new();
	 
      //gtk_container_add (GTK_CONTAINER (b), v);
	SetMenuButton(b," ",0) ;

      //gtk_container_add (GTK_CONTAINER (v), i);

      //gtk_container_add (GTK_CONTAINER (v), l);

      gtk_widget_set_name (GTK_WIDGET (b), "MenuButtons");


      gtk_signal_connect_object (GTK_OBJECT (b), "clicked", GTK_SIGNAL_FUNC (menu_callback), (void *) nbuttons);
      gtk_widget_show (b);
      gtk_object_set_data (GTK_OBJECT (bb), buff, b);
      gtk_object_set_data (GTK_OBJECT (b), "BUTTON", (void *) nbuttons++);
      gtk_object_set_data (GTK_OBJECT (b), "OPT", 0);
      gtk_object_set_data (GTK_OBJECT (bb), "NBUTTONS", (void *) nbuttons);
      gtk_object_set_data (GTK_OBJECT (bb), "NBUTTONS", (void *) nbuttons);
      gtk_container_add (GTK_CONTAINER (bb), b);
    }

  for (a = 0; a < nbuttons; a++)
    {
      SPRINTF1 (buff, "BUTTON_%d", a);
      b = gtk_object_get_data (GTK_OBJECT (bb), buff);
      if (a >= num_opts)
	{
	  A4GL_debug ("Hide b\n");
	  gtk_widget_hide (b);
	}
      else
	{
	  gtk_widget_show (b);
	}
    }

  return 1;

}

static void SetMenuButton(GtkWidget *b, char *txt,GtkWidget *i) {
	SetButton(b,txt,i,'H',0);
}

static void SetToolbarButton(GtkWidget *b, char *txt,GtkWidget *i) {
	if (i==0 && strlen(txt)==0) {
		gtk_widget_hide(b);
	} else {
		gtk_widget_show(b);
	}
	SetButton(b,txt,i,'V',1);
}


static void SetButton(GtkWidget *b, char *txt,GtkWidget *i,char orientation,int isToolbarItem) {
GtkWidget *l=0;
GtkWidget *v=0;
char *current=0;
int isdiff=0;
GtkWidget *oldi=0;

current=gtk_object_get_data(GTK_OBJECT (b),"TEXT");

if (current==0) {
	isdiff=1;
} else {
	//printf("Current=%s\n",current);
	//printf("txt=%s\n",txt);
      if (strcmp(current,txt)!=0) {
		isdiff=1;
	}
}

if (isdiff==0) {
	//printf("SAME!!!\n");
	return ;
}

oldi=gtk_object_get_data (GTK_OBJECT (b), "IMAGE");

if (oldi==0 && i==0) { 	// No images :-) 
			// Just change the text...
		GtkWidget *l;
		if (isToolbarItem) {
			l=gtk_tool_button_get_label_widget(GTK_TOOL_BUTTON (b));
		}  else {
			l=gtk_object_get_data (GTK_OBJECT (b), "LABEL");
		}

		if (l) {
			//printf("Just Change Label %s %s \n",current,txt);
			free(current);
			//printf("Setting : %s\n", txt);
			gtk_label_set_text(GTK_LABEL(l),txt);
			//printf("Setting TEXT %s\n",txt);
			gtk_object_set_data (GTK_OBJECT (b), "TEXT",strdup(txt));
			return;
		}
}


if (isdiff) {
	GtkWidget *oldv=0;
	//printf("Change label with image '%s'\n",txt);
	
	if (current) free(current);
		gtk_object_set_data (GTK_OBJECT (b), "TEXT",strdup(txt));

	if (isToolbarItem) {
		GtkWidget *l;
		l=gtk_tool_button_get_label_widget(GTK_TOOL_BUTTON (b));
			//printf("Setting : %s\n", txt);
		gtk_label_set_text(GTK_LABEL(l),txt);
		if (i) {
			//l=gtk_tool_button_get_icon_widget(GTK_OBJECT (b));
			gtk_tool_button_set_icon_widget(GTK_TOOL_BUTTON (b), GTK_WIDGET (i));
		}
		return;
	}

			//printf("Setting : %s\n", txt);
      	l=gtk_label_new (txt);

      	gtk_widget_show (l);

	if (orientation=='H')  {
      		v=gtk_hbox_new(0,0);
	} else {
      		v=gtk_vbox_new(0,0);
	}

	gtk_widget_show(v);
	oldv=gtk_object_get_data (GTK_OBJECT (b), "BOX");
	if (oldv) {
		gtk_container_remove(GTK_CONTAINER (b),oldv); 
	}

      	gtk_container_add (GTK_CONTAINER (b), v);	
      	if (i) {
      		gtk_widget_show (i);
		gtk_box_pack_start (GTK_BOX(v), i, FALSE, FALSE, 2);
		gtk_box_pack_start (GTK_BOX(v), l, FALSE, FALSE, 0);
      	} else {
		gtk_box_pack_start (GTK_BOX(v), l, FALSE, FALSE, 0);
	}
	
	//printf("Setting Label (%p) = %p\n",b,l);
      	gtk_object_set_data (GTK_OBJECT (b), 	"LABEL", l);
      	gtk_object_set_data (GTK_OBJECT (b), 	"IMAGE", i);
     	gtk_object_set_data (GTK_OBJECT (b), 	"BOX", v);
			//printf("Setting TEXT %s\n",txt);
      	gtk_object_set_data(GTK_OBJECT(b),	"TEXT",strdup(txt));
	
			//printf("Setting : %s\n", txt);
      	gtk_label_set_text(GTK_LABEL (l), txt);
      //gtk_button_set_image(GTK_BUTTON (b), i);
}
}




void
A4GL_LL_disp_h_menu_opt (int opt_num, int num_opts, char *opt_title,char*shorthelp,
			 int attributes)
{
  GtkWidget *b;
  GtkWidget *bb;
  //GtkWidget *l = 0;
  char buff[255];
  //FPRINTF (stderr, "disp_h_menu_opt\n");
  bb = gtk_object_get_data (GTK_OBJECT (win_screen), "BB");
  if (bb == 0) return ;
  SPRINTF1 (buff, "BUTTON_%d", opt_num);
  b = gtk_object_get_data (GTK_OBJECT (bb), buff);




  //FPRINTF (stderr, "option %d =%s\n", opt_num, opt_title);


  if (has_stock_item (opt_title))
    {
		char txt[255];
		char img[255];
      		char *label_utf ;
		GtkWidget *i;
		stock_item (opt_title, txt,img,0);

		if (strlen(img)) {
			i=gtk_image_new_from_file (img);
			gtk_widget_show(i);
		}
		//printf("txt=%s\n",txt);
		label_utf = g_locale_to_utf8 (txt, -1, NULL, NULL, NULL);
		SetMenuButton(b, label_utf,i);
      		g_free (label_utf);
    }
  else
    {
      		char *label_utf ;
		//printf("txt=%s\n",opt_title);
		label_utf= g_locale_to_utf8 (opt_title, -1, NULL, NULL, NULL);
      		//l = gtk_object_get_data (GTK_OBJECT (b), "LABEL");
		
		SetMenuButton(b, label_utf,0);

      		//gtk_label_set_text (GTK_LABEL (l), label_utf);
		//gtk_button_set_image(GTK_BUTTON (b), 0);
      		//FPRINTF (stderr, "Set text (%s)\n", opt_title);
      		//gtk_button_set_label(GTK_BUTTON(b), label_utf);
      		g_free (label_utf);
    }

  if (attributes & ACL_MN_HIDE)
    gtk_widget_hide (b);
  else
    gtk_widget_show (b);


}



int
A4GL_LL_menu_type (void)
{
  return (!A4GL_isyes (acl_getenv ("TRADMENU")));

}




void
A4GL_LL_wadd_char_xy_col_w (void *win, int x, int y, int ch, int curr_width,
			    int curr_height, int iscurrborder, int currwinno)
{
  A4GL_assertion (1, "Not implemented A4GL_LL_wadd_char_xy_col_w");
}


int A4GL_LL_can_show_comments(char *s) {
	return 0;
}

int A4GL_LL_can_show_message(int ml,char *s,int wait) {
	return 0;
}


void
A4GL_LL_clr_menu_disp (void *menu, int curr_width, int curr_height,
		       int iscurrborder, int currwinno, void *cw,
		       int menu_offset, int gw_y)
{
  static char buff[1025];
  int off;
  int w;
  //void *cw;
  int y;

  if (A4GL_isyes (acl_getenv ("TRADMENU")))
    {

      A4GL_debug ("Clearing menu clr_menu_disp - %p", menu);
      memset (buff, ' ', 1023);
      buff[1024] = 0;

      w = curr_width;
      off = menu_offset;
      buff[w - off + 1] = 0;
      y = gw_y;
      A4GL_wprintw (cw, 0, off - 1, y, curr_width, curr_height, iscurrborder,
		    currwinno, buff);
    }
}


void
A4GL_LL_h_disp_title_with_attr (void *menu, char *str, int curr_width, int curr_height,
		      int iscurrborder, int currwinno, void *cw, int gw_y,char *style, char*comment, char*image)
{

  if (A4GL_isyes (acl_getenv ("TRADMENU")))
    {
      A4GL_wprintw (cw, 0, 1, gw_y, curr_width, curr_height, iscurrborder,
		    currwinno, "%s", str);
    }


}



static char
A4GL_menu_pos (void)
{
  static char pos = 0;
  char *c;
  if (pos == 0)
    {

      /*
         if (A4GL_isyes (acl_getenv ("MENUTOP")))
         {
         pos = 'T';
         return pos;
         }
         if (A4GL_isyes (acl_getenv ("MENUBOTTOM")))
         {
         pos = 'B';
         return pos;
         }
         if (A4GL_isyes (acl_getenv ("MENULEFT")))
         {
         pos = 'L';
         return pos;
         }
         if (A4GL_isyes (acl_getenv ("MENURIGHT")))
         {
         pos = 'R';
         return pos;
         }
       */

      c = acl_getenv ("MENUPOSITION");

      if (c == 0)
	{
	  pos = 'R';
	  return pos;
	}
      if (strlen (c) == 0)
	{
	  pos = 'R';
	  return pos;
	}
      if (toupper (c[0]) == 'T')
	{
	  pos = 'T';
	  return pos;
	}
      if (toupper (c[0]) == 'L')
	{
	  pos = 'L';
	  return pos;
	}
      if (toupper (c[0]) == 'B')
	{
	  pos = 'B';
	  return pos;
	}
      if (toupper (c[0]) == 'R')
	{
	  pos = 'R';
	  return pos;
	}
      pos = 'R';
    }

  return pos;
}



void
A4GL_LL_set_acc_intr_keys (int n)
{
  A4GL_show_ok_cancel (n);
}


static int
has_stock_item (char *s)
{
  if (stock_item (s,0,0,0))
    return 1;
  else
    return 0;
}

int stock_item (char *s, char *txt, char *img,GtkWidget **w)
{
int a;
  //char *ptr;
  char buff[256];
  //char buff2[256];
  if (s[0] == ' ')
    {
      strcpy (buff, &s[1]);
    }
  else
    {
      strcpy (buff, s);
    }
  A4GL_trim (buff);
  a4gl_upshift (buff);
  for (a=0;a<nAubitStock;a++) {
	if (A4GL_aubit_strcasecmp(buff,AubitStock[a].name)==0) { //
		if (txt) strcpy(txt, AubitStock[a].txt);
		if (img) strcpy(img, AubitStock[a].img);
		if (w) *w=AubitStock[a].loadedImage;
		return 1;
	}
  }
  return 0;
}










void *
A4GL_LL_get_value (char *s)
{
  if (strcmp (s, "prompt.field") == 0)
    {
      FPRINTF (stderr, "last_prompt_field : %p\n", last_prompt_field);
      return (void *) last_prompt_field;
    }
  if (strcmp (s, "prompt.f") == 0)
    return (void *) last_prompt_f;
  if (strcmp (s, "prompt.win") == 0)
    return (void *) last_prompt_win;
  if (strcmp (s, "prompt.mode") == 0)
    return (void *) last_prompt_mode;
  FPRINTF (stderr, "Unknown value...%s\n", s);
  return (void *) 0;
}




//
// ********************************************************************************
//



// @ FIXME's.................

int
A4GL_LL_open_gui_form (char *name_orig, int absolute, int nat, char *like,
		       int disable, void *handler_e, void *phandler_c)
{
#ifdef FIXME
  GtkWindow *win;
  void (*handler_c) ();
  GtkFixed *fixed;
  //GtkFixed *form;
  char name[256];
  char formname[256];
  //struct struct_form *the_form;
  struct s_form_dets *form_dets;
  struct s_window *w;
  struct s_a4gl_gtk_form *gtk_f;
  int a;
  w = acl_malloc2 (sizeof (struct s_windows));

  handler_c = phandler_c;

  strcpy (name, name_orig);
  A4GL_decode_gui_winname (name);
  if (like && strlen (like))
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
      A4GL_debug ("No window created!");
      A4GL_exitwith ("Unable to create new window");
      return 0;
    }

  fixed = (GtkFixed *) gtk_fixed_new ();


  gtk_container_add (GTK_CONTAINER (win), GTK_WIDGET (fixed));


  gtk_signal_connect (GTK_OBJECT (win), "delete_event",
		      GTK_SIGNAL_FUNC (handler_e), win);
  gtk_signal_connect (GTK_OBJECT (win), "destroy",
		      GTK_SIGNAL_FUNC (handler_e), win);
  //gtk_signal_connect (GTK_OBJECT (win), "focus_in_event", GTK_SIGNAL_FUNC (handler_e), win);

  form_dets = A4GL_read_form (formname, "uhmmm");

  w =
    (struct s_window *) A4GL_add_window (0, 0, 0, 0, formname, form_dets,
					 win);


  A4GL_win_stack ((void *) w, '+');
  if (form_dets == 0)
    {
      A4GL_exitwith ("Unable to open form");
      return 0;
    }

  gtk_f = A4GL_LL_new_form (form_dets);

  for (a = 0; a < gtk_f->nwidgets; a++)
    {
      int x, y;
      x =
	(int) gtk_object_get_data (GTK_OBJECT (gtk_f->widgets[a]),
				   "MF_FCOL") * gui_xwidth;
      y =
	(int) gtk_object_get_data (GTK_OBJECT (gtk_f->widgets[a]),
				   "MF_FROW") * gui_yheight;
      gtk_fixed_put (GTK_FIXED (fixed), gtk_f->widgets[a], x, y);
      gtk_object_set_data (GTK_OBJECT (gtk_f->widgets[a]), "HANDLER",
			   (void *) handler_c);
      gtk_widget_ref (gtk_f->widgets[a]);
      gtk_widget_show (gtk_f->widgets[a]);
    }




  gtk_widget_show_all (GTK_WIDGET (win));
  //gtk_widget_show (GTK_WIDGET (win));
  handler_c (0, 0);
  gtk_widget_show (GTK_WIDGET (win));
#endif
  return 1;
}


int
A4GL_LL_fieldnametoid (char *f, char *s, int n)
{
  //GtkWidget *formdets;
  GtkWidget *w = 0;
#ifdef FIXME
  //int nofields;
  GtkWidget **field_list = 0;


  A4GL_debug ("fgl_fieldnametoid (%p,%d)", s, n);


  formdets = (GtkWidget *) UILIB_A4GL_get_curr_form (1);
  A4GL_debug ("Getting field list formdets=%p parent=%p", formdets,
	      gtk_object_get_data ((GtkObject *) formdets, "PARENT"));

  /* debug("Getting field list formdets=%p parent=%p",formdets,gtk_object_get_data(formdets,"TOP")); */


  //A4GL_exitwith ("serious bug in widget.c");

  nofields =
    A4GL_gen_field_chars ((void *) &field_list, (GtkWindow *) formdets, s, n,
			  0);

  A4GL_debug ("done Getting field list - nofields=%d", nofields);

  if (nofields != -1)
    w = field_list[0];
  else
    w = 0;
  A4GL_debug ("field_list=%p\n", field_list);
  free (field_list);
#endif
  return (int) w;
}

int
A4GL_LL_disp_form_field_ap (int n, int attr, char *s, va_list * ap)
{
  //int a;
#ifdef FIXME
  int flg;
  struct s_form_dets *formdets;
  void **field_list;
  int nofields;
  void *w;
  struct struct_scr_field *fprop;
  a4gl_status = 0;

  //A4GL_chkwin ();
  A4GL_debug ("In disp_fields");
  w = A4GL_find_pointer (s, WINCODE);

  formdets = (struct s_form_dets *) A4GL_find_form_for_win (w);

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
      fprop = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (field_list[a]));
      fprop->flags |= 2;



    }
  A4GL_LL_screen_update ();
#endif
  return 1;
}


int
A4GL_LL_endis_fields_ap (int en_dis, void *vap)
{
#ifdef FIXME
  GtkWidget *formdets;
  int a;
  va_list *ap;
  int nofields;
  GtkWidget **field_list;
  ap = vap;
  formdets = A4GL_get_curr_form (1);


  A4GL_debug ("Formdets = %p\n", formdets);

  nofields =
    A4GL_gen_field_list ((void *) &field_list, (void *) formdets, 9999, ap);
  A4GL_debug ("nofields=%d\n", nofields);

  for (a = 0; a <= nofields; a++)
    {
      A4GL_debug ("Doing something to %p %d\n", field_list[a], en_dis);
      A4GL_gui_set_active (field_list[a], en_dis);
    }
#endif
  return 1;
}

//
// Called when SET PAUSE MODE ON/OFF is set
// and to check which is in effect (a==-1)
//
int
A4GL_LL_pause_mode (int a)
{
  static int smode = 1;
  if (a == -1)
    return smode;

  if (a == smode)
    return smode;
  if (a == 0)
    {
      smode = 0;
      return smode;
    }
  smode = 1;
  A4GL_LL_screen_refresh();
  //A4GL_zrefresh ();
  return smode;
}

static void
A4GL_default_attributes_in_ll (void *f, int dtype, int has_picture)
{
  int done = 0;

  A4GL_debug ("In def attrib f=%p", f);



  if (has_picture)
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_LL_set_field_opts (f,
			      AUBIT_O_VISIBLE | AUBIT_O_ACTIVE |
			      AUBIT_O_PUBLIC | AUBIT_O_EDIT);
      done = 1;
    }





  if (done == 0)
    {

      A4GL_debug ("MMMM DTYPE & 255 = %d", dtype);

      if ((dtype & 255) == 0)
	{
	  A4GL_debug ("ZZZZ - SET OPTS");
	/*
	  A4GL_LL_set_field_opts (f, AUBIT_O_VISIBLE | AUBIT_O_ACTIVE); 
				  | AUBIT_O_PUBLIC | AUBIT_O_EDIT); 
	*/



	  //A4GL_field_opts_off (f, AUBIT_O_BLANK); @todo     is it ok to remove this ?

	}
      else
	{
	  A4GL_debug ("ZZZZ - SET OPTS");
	  A4GL_debug ("BLANK BLANK");
	/*
	  A4GL_LL_set_field_opts (f,
				  AUBIT_O_VISIBLE | AUBIT_O_ACTIVE |
				  AUBIT_O_PUBLIC | AUBIT_O_EDIT |
				  AUBIT_O_BLANK);
	*/
	}

    }

  A4GL_debug ("STATIC");
  A4GL_LL_set_field_fore (f, A4GL_LL_colour_code (7));
  A4GL_LL_set_field_back (f, A4GL_LL_colour_code (7));
  A4GL_LL_set_max_field (f,
			 (int)
			 gtk_object_get_data (GTK_OBJECT ((GtkWidget *) f),
					      "MF_COLS"),0);

}


void
A4GL_LL_init_color (int c, int r, int g, int b)
{
  // Does nothing yet
}



int use_frames(void) {
      if (A4GL_isno (acl_getenv ("GTKUSEFRAMES"))) {
	      	return 0;
      }

      return 1;
}


void
A4GL_LL_submit_event (int a, void *s, int event_type, int block, int keycode,
		      char *field)
{
  // Does nothing in GTK mode..
}


void
A4GL_LL_activate_events (void *s)
{
  // Does nothing in GTK mode..
}

void
A4GL_LL_finished_with_events (void *s)
{
  // Does nothing in GTK mode..
}

int A4GL_LL_get_triggered_event() {
	return -1; /* Does nothing in GTK mode */
}


void A4GL_LL_ui_exit() {
	// Does nothing - required by api..
}

void A4GL_LL_enable_menu() {
	// Does nothing - required by api..
}
void A4GL_LL_disable_menu() {
	// Does nothing - required by api..
}

void A4GL_LL_opening_form(char *a,char *b) {
  // Does nothing - required by api..
}
  
 
void A4GL_LL_direct_to_ui(char *t, char *s) {
  /* Does nothing - required by api.. */
}




ACL_Menu_Opts *A4GL_LL_show_menu_large(ACL_Menu *menu, int key) {
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
	  	A4GL_wprintw ((void *) A4GL_get_currwin (), 0, 1, menu->gw_y+1, UILIB_A4GL_get_curr_width (), UILIB_A4GL_get_curr_height (), UILIB_A4GL_iscurrborder (), A4GL_get_currwinno (), disp);

		
		sprintf(disp,"Select: %s",buff);
		l=strlen(disp);
		cw-=l;
	  	A4GL_wprintw ((void *) A4GL_get_currwin (), 0, 3+l, menu->gw_y+1, UILIB_A4GL_get_curr_width (), UILIB_A4GL_get_curr_height (), UILIB_A4GL_iscurrborder (), A4GL_get_currwinno (), A4GL_show_menu_large_get_matches(menu, buff, cw, &cnt,0));
		//A4GL_mja_gotoxy (3+l, 2 + menu->menu_line);
		//A4GL_tui_printr (0,"%s", A4GL_show_menu_large_get_matches(menu, buff, cw, &cnt,0));
		A4GL_assertion(cnt==0,"cnt should not be zero at this point");
	  	A4GL_wprintw ((void *) A4GL_get_currwin (), 0, 1, menu->gw_y+1, UILIB_A4GL_get_curr_width (), UILIB_A4GL_get_curr_height (), UILIB_A4GL_iscurrborder (), A4GL_get_currwinno (), disp);

		//A4GL_mja_gotoxy (1, 2 + menu->menu_line);
		//A4GL_tui_printr (1,"%s", disp);

		a=0;
  		A4GL_LL_screen_update ();
		while (a==0)  {
			a=A4GL_LL_getch_swin(0,0);
		}

		if (a_isprint(a)) {
			char b[2];
			b[0]=a;
			b[1]=0;
			strcat(buff,b);
			A4GL_show_menu_large_get_matches(menu, buff,cw, &cnt,&uniq);
			
			A4GL_debug("got %d matches", cnt);
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
			
			A4GL_debug("menu_large - LEFT (%s)", buff);
			continue;
		}

		if (a==A4GLKEY_ENTER) {
			return menu->curr_option;
		}
	}
}

static void FakeKeyToolbarEvent( GtkWidget *widget,
                         gpointer data )
{
  if ((long)data==A4GLKEY_INTERRUPT) {
	cancel_callback(0);
  } else {
  	add_keypress ((long)data);
  }
}



static void register_my_stock_icons (void)
{
   static int loaded=0;
   GtkIconFactory *icon_factory;
   GtkIconSet *icon_set; 
   GtkIconSource *icon_source;
   //gint i;
   //static gint n_stock_icons=0;
   char buff[2560];
   char buff2[2560];
   char buff3[2560];
   char name[256];
   char txt[256];
   char extraDir[2000];
   char filePath[2000]="";
   FILE *f;
   char *imgdir;
   if (loaded) return;
   loaded++;

   imgdir=acl_getenv_not_set_as_0("AUBITIMAGES");

   if (imgdir) {
   	sprintf(extraDir,"%s;%s/images", imgdir,acl_getenv("AUBITDIR"));
   } else {
   	sprintf(extraDir,"%s/images", acl_getenv("AUBITDIR"));
   }

   sprintf(buff,"%s.lst",A4GL_get_running_program());

   // Is there an application specific image file ? 
   //
   f=A4GL_open_file_dbpath_plus_path (buff, extraDir,filePath);
   if (f==0) {
 	strcpy(buff,"stock.lst");
   	f=A4GL_open_file_dbpath_plus_path (buff, extraDir,filePath);
	if (f==0) {
		printf("********************************************************************************\n");
		printf("WARNING : Cannot find any image files\n");
		printf("Please ensure that you have\n");
		printf("1) A $AUBITDIR/images directory with the required 'stock.lst' file, or\n");
		printf("2) A $AUBITIMAGES directory with the required 'stock.lst' file, or\n");
		printf("3) A stock.lst file somewhere in the DBPATH\n");
		printf("(The images themselves should be in the same directory as the 'stock.lst' file)\n");
		printf("\nCurrently - the image directory is not created or installed by default\n");
		printf("but sample images should be available from the aubit4glsrc \n");
		printf("or aubit4glbin directory which you installed from.\n");
		printf("********************************************************************************\n");
		
		return ; // Cant find any .lst files...
	}
   }


   if(strlen(filePath)) { // trim off the filename portion..
		char *p;
		p=strrchr(filePath,'/');
		if (p) *p=0;
		p=strrchr(filePath,'\\'); // dos paths...
		if (p) *p=0;
   }


   // if we got to here - we found our file...

   icon_factory = gtk_icon_factory_new ();
   
   while (1) {
	//char *p1;
	char *p2;
	char *p3;
	strcpy(buff3,"");
	if (feof(f)) break;
      	fgets(buff3,255,f);
	A4GL_trim_nl(buff3);
	if (buff3[0]=='#') continue;
	//printf("Buff3=%s\n",buff3);
	p2=strchr(buff3,'\t');
	if (p2==0) continue;
	*p2=0;
	p2++;
	//printf("Buff3 now : %s\n",buff3);
	p3=strchr(p2,'\t');
	if (p3==0) continue;
	*p3=0;
	p3++;
	strcpy(buff2,p3);
	strcpy(name,buff3);
	strcpy(txt,p2);

	//printf("buff2=%s\n",buff2);
      icon_set = gtk_icon_set_new ();
      icon_source = gtk_icon_source_new ();

	if (strchr(buff2,'/')) {
      		sprintf(buff,"%s", buff2);
		//strcpy(name,strrchr(buff2,'/')+1);
	} else {
      		sprintf(buff,"%s/%s", filePath,buff2);
	}
 
      if (!A4GL_file_exists(buff)) continue;
      if (has_stock_item(name)) continue; // don't overwrite something we've already loaded...


      //printf("Loading : %s from %s\n", name, buff);
      gtk_icon_source_set_filename (icon_source, buff);
      gtk_icon_set_add_source (icon_set, icon_source);
      gtk_icon_source_free (icon_source);
      gtk_icon_factory_add (icon_factory, name, icon_set);
      gtk_icon_set_unref (icon_set);
	AddAubitStock(name, txt, buff);
    }

   gtk_icon_factory_add_default (icon_factory); 

   g_object_unref (icon_factory);
}


void *AddButtonToolbar(GtkWidget *toolbar, char *tag, char *buttonText,char *stock, char *toolTip, int keyval) {
  GtkWidget *iconw=0;
  GtkWidget *button=0;
  char buff[256];
  char btn[256];
  char txt[256];
  char *displayedText;	
  GtkWidget *l; // Label for button


  register_my_stock_icons();
  strcpy(btn,buttonText);
  A4GL_make_downshift(btn);

   //if (stock) {
   	//iconw=gtk_image_new_from_stock(stock, GTK_ICON_SIZE_SMALL_TOOLBAR);
   	//printf("Widget=%p\n",iconw);
   //} else {
	//iconw=0;
   //}
  //iconw = gtk_image_new_from_file (buff); /* icon widget */

   //sprintf(buff,"%s.png",buttonText);
  //iconw = gtk_image_new_from_file (buff); /* icon widget */
  //if (iconw!=0) {
		//printf("Loaded image : %s\n",buff);
  //}
  displayedText=buttonText;
  if (has_stock_item (buttonText)) {
		char img[256]="";
		stock_item(buttonText,txt,img,0);
		if (strlen(img)) {
			iconw=gtk_image_new_from_file (img);
			gtk_widget_show(iconw);
		}
		displayedText=txt;
  }


  l=gtk_label_new(displayedText);
  gtk_widget_show(l);
  button=(GtkWidget*)gtk_tool_button_new(0, 0);
  gtk_tool_button_set_label_widget(GTK_TOOL_BUTTON(button),l);
  gtk_tool_button_set_icon_widget(GTK_TOOL_BUTTON(button),iconw);

  //SetToolbarButton(button, displayedText,iconw);
  gtk_widget_show(button);
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(FakeKeyToolbarEvent), (void *)keyval);
	gtk_tool_item_set_homogeneous (GTK_TOOL_ITEM(button),0);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), GTK_TOOL_ITEM(button), -1);

  gtk_object_set_data(GTK_OBJECT(button), "KEY", (void *)keyval);
  gtk_object_set_data(GTK_OBJECT(button), "TITLE", (void *)buttonText);

  gtk_object_set_data(GTK_OBJECT(button), "TAG", (void *)tag);
//gtk_tool_item_set_expand(GTK_TOOL_ITEM(button),0);
  //gtk_toolbar_append_space (GTK_TOOLBAR (toolbar)); /* space after item */

  sprintf(buff,"TOOLBAR_%s",buttonText);
  gtk_object_set_data(GTK_OBJECT(appWin),buff,button);

return button;

}



void textField_focus(GtkWidget * w, char *mode) {
if (strcmp(mode,"on")==0) return;
if (currentCmd==0) return;
if (strcmp(currentCmd,"Input")==0) {
	struct s_screenio *s;
	s=(struct s_screenio *)currentSio;
	if (w!=s->currentfield) { // we can ignore it if its the current field
		char *tandc;
		tandc=gtk_object_get_data(GTK_OBJECT(w),"TAB_AND_COL");
		if (!A4GL_isyes(acl_getenv("NOGTKFIELDCLICK")))  {
			A4GL_req_field(currentSio,'I','!',tandc,1,NULL,0); // Need this actioned - so fake a key press
			A4GL_fake_a_keypress(w,A4GLKEY_FIELD_CLICKED);
		}
	}
}

}


void ActivateToolbar(char *cmd, struct aclfgl_event_list *list,void *sio) {
	currentCmd=cmd;
	currentSio=sio;

	if (cmd==NULL) {
		if (toolbar) {
			int a;
			gtk_widget_show(toolbar);
			for (a=0;a< toolbarItemsCnt;a++) {
			int key=0;
					if (gtk_object_get_data(toolbarItems[a],"ALWAYSON")) {
						continue;
					}
					key=(int)gtk_object_get_data(GTK_OBJECT(toolbarItems[a]),"KEY");
					if (key==A4GLKEY_HELP) {
						gtk_widget_show(toolbarItems[a]);
					} else {
						gtk_widget_hide(toolbarItems[a]);
					}
			}
		}
	} else {
		if (toolbar) {
			int a;
			int ncnt=0;
			int key=0;
			char *title=0;
			//printf("Enabling toolbar items : %s\n", cmd);
			for (a=0;a< toolbarItemsCnt;a++) {
				int ok=0;
				key=(int) gtk_object_get_data(GTK_OBJECT(toolbarItems[a]),"KEY");
				title=gtk_object_get_data(GTK_OBJECT(toolbarItems[a]),"TITLE");

				if ( strcmp(cmd,"InputArray")==0 ||strcmp(cmd,"Input")==0 ||strcmp(cmd,"DisplayArray")==0) {
					if (key==A4GLKEY_ACCEPT) 	ok=1;
					if (key==A4GLKEY_INTERRUPT) 	ok=1;
				}

				if (key==A4GLKEY_UP) 		ok=1;
				if (key==A4GLKEY_DOWN) 		ok=1;
				if (key==A4GLKEY_HELP) ok=1;
				if (strcmp(cmd,"InputArray")==0 && key==A4GLKEY_PGUP) ok=1;
				if (strcmp(cmd,"InputArray")==0 && key==A4GLKEY_PGDN) ok=1;
				if (strcmp(cmd,"DisplayArray")==0 && key==A4GLKEY_PGUP) ok=1;
				if (strcmp(cmd,"DisplayArray")==0 && key==A4GLKEY_PGDN) ok=1;
				if (strcmp(cmd,"Prompt")==0 && key==A4GLKEY_ENTER) ok=1;
			
				if (list) {
					int a;
					for (a=0;list[a].event_type;a++) {	
						if (list[a].event_type==A4GL_EVENT_KEY_PRESS) {		
							//printf("Looking for key press : %d\n",list[a].keycode);
							if (list[a].keycode==key) {
								ok=1;
								break;
							}
						}
					}
				}

				if(ok) {
					ncnt++;
				
					if (!gtk_object_get_data(toolbarItems[a],"ALWAYSON")) {
						//printf("SHOW %s\n",title);
						gtk_widget_show(toolbarItems[a]);	
					}
				} else {
					if (!gtk_object_get_data(toolbarItems[a],"ALWAYSON")) {
						//printf("HIDE %s\n",title);
						gtk_widget_hide(toolbarItems[a]);
					} else {
						//printf("Not hidden - always on %s\n",title);
					}
				}
			}
	
			if (ncnt) {
				gtk_widget_show(toolbar);
			} else {
				gtk_widget_show(toolbar); // HIDE !!!
			}
		}

	}

}

void LL_AddButtonToolbar(char *tag, char *Text,char *imgPassedIn, char *toolTip, int keyval,int alwaysShow) {
int a;
int found=0;
char txt[255]="";
char img[255]="";
int hasItem;

hasItem=stock_item (Text, txt,img,0);

if (!hasItem) {
	strcpy(txt,Text);
	strcpy(img,imgPassedIn);
}

	for (a=0;a<toolbarItemsCnt;a++) {
		char *ctag;
		ctag=gtk_object_get_data(toolbarItems[a],"TAG");
		if (strcmp(ctag,tag)==0) { // Found it already...
				GtkWidget *i=0;
				if (strlen(img)) {
					i=gtk_image_new_from_file (img);
					gtk_widget_show(i);
				} 
				//printf("SetToolbarButton: %s\n",txt);
				SetToolbarButton(toolbarItems[a], txt,i) ;
				found++;

		}
	}

	if (found) return;

	toolbarItems[toolbarItemsCnt++]= AddButtonToolbar(toolbar,tag, txt,img, toolTip,  keyval) ;
	if (alwaysShow) {
  		gtk_object_set_data(GTK_OBJECT(toolbarItems[toolbarItemsCnt-1]),"ALWAYSON",(void *)1);
		gtk_widget_show(toolbarItems[toolbarItemsCnt-1]);
	}
}

void setMenu(GtkWidget *w,int on) {
if (on) {
	gtk_widget_set_sensitive(w,1);
  	gtk_widget_show (w);
} else {
	gtk_widget_set_sensitive(w,0);
  	gtk_widget_hide (w);
}
}

void AddAubitStock(char *name, char *txt, char *img) {
	nAubitStock++;
	AubitStock=realloc(AubitStock, sizeof(struct sAubitStock)*nAubitStock);
	AubitStock[nAubitStock-1].txt=strdup(txt);
	AubitStock[nAubitStock-1].name=strdup(name);
	
	AubitStock[nAubitStock-1].img=strdup(img);
	AubitStock[nAubitStock-1].loadedImage=0;
	if (strlen(img) && A4GL_file_exists(img)) {
		AubitStock[nAubitStock-1].loadedImage=gtk_image_new_from_file (img);
		g_object_ref(AubitStock[nAubitStock-1].loadedImage);
	}
}

void A4GL_LL_init_form(void *f) {
struct s_a4gl_gtk_form *form;
form=f;
form->curcol=0;
form->currentfield=0;
}

static void A4GL_dobeep(void ) {
}
// --------------------------------------------------------------------------------------
// FIXMEs...
// --------------------------------------------------------------------------------------
