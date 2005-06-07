
#include "a4gl_libaubit4gl.h"
#include "a4gl_API_lowlevel.h"
#include "a4gl_API_ui_lib.h"
#include "a4gl_incl_4gldef.h"
#include "../hl_forms.h"

#include "lowlevel.h"
#include "formdriver.h"
#include "low_gtk.h"
#include "hl_proto.h"
#include <ctype.h>
#ifndef lint
	static char const module_id[] =
		"$Id: lowlevel_gtk.c,v 1.65 2005-06-07 16:16:03 mikeaubury Exp $";
#endif


#define A4GL_GTK_FONT_FIXED "Fixed 10"
int gui_yheight=20; // 25
#if GTK_CHECK_VERSION(2,0,0)
	static int has_stock_item(char *s) ;
	static char *stock_item(char *s) ;
#endif
int gui_xwidth=9;
static int menu_response=-1;
void A4GL_gui_prompt_style (int a);
void *A4GL_get_currwin (void);
//int A4GLHLUI_initlib(void);
void tstamp(char *s) ;
int A4GL_LL_disp_form_field_ap(int n,int attr,char* s,va_list* ap) ;
static char A4GL_menu_pos(void) ;
static void setup_ok_cancel(GtkWidget *ok_cancel) ;
//int A4GL_LL_construct_large(char *orig, struct aclfgl_event_list *evt,int init_key,int initpos) ;
int A4GL_LL_fieldnametoid(char* f,char* s,int n) ;
void A4GL_win_stack (struct s_windows *w, int op);
int A4GL_display_generic(GtkWidget *k, char *s);
int A4GL_has_event(int a,struct aclfgl_event_list *evt) ;
int A4GL_has_event_for_keypress(int a,struct aclfgl_event_list *evt) ;
int A4GL_has_event_for_field(int cat,char *a,struct aclfgl_event_list *evt) ;
GtkWidget *A4GL_make_widget(char *widget, char *config, int w);
void A4GL_clear_prompt(struct s_prompt *prmt) ;
void A4GL_getxy_coords(int *x,int *y) ;
void A4GL_show_console (void);
void A4GL_hide_console (void);
int A4GL_getx_coords(int x) ;
int A4GL_gety_coords(int x) ;
void A4GL_console_toggle (void);
void A4GL_add_to_console (char *s);
void A4GL_clear_console (char *s);
void A4GL_create_console (void);
//void A4GL_logkey(long a);
int A4GL_gtkdialog (char *caption, char *icon, int buttons, int defbutt, int dis, char *msg);
int KeySnooper (GtkWidget * grab_widget, GdkEventKey * event, gpointer func_data);
int A4GL_which_key_aubit(int gdk_key);
char * A4GL_decode_str_fprop (struct_scr_field * fprop, int type);
void MyStyleSetItemColor (GdkColor color,       /* The allocated color to be added to the style */
                          char item,    /* the item to which the color is to be applied */
                          /* 'f' = foreground; 'b' = background; */
                          /* 'l' = light;      'd' = dark; */
                          /* 'm' = mid;        't' = text; */
                          /* 's' = base. */
                          GtkStyle * style      /* The old style - changes made to a copy */
  );
void A4GL_alloc_colors (void);
void A4GL_gui_set_active (GtkWidget * w, int en_dis);


int window_frame_type=0;
char *A4GL_fld_val_generic (GtkWidget * k);
void *win_screen;
int frame_style = GTK_SHADOW_IN;
int A4GL_delete_event (GtkWidget * widget, GdkEvent * event, gpointer data);
int A4GL_destroy_event (GtkWidget * widget, gpointer data);
int A4GL_keypress (GtkWidget * widget, GdkEventKey * event, gpointer user_data);
void A4GL_run_gtkrc(void) ;
void A4GL_decode_gui_winname (char *name);
int menu_callback (gpointer data);
int A4GL_LL_hide_h_menu(ACL_Menu *menu);
void A4GL_LL_screen_refresh(void);
static int cancel_callback (gpointer data) ;
static int ok_callback (gpointer data) ;
static int A4GL_show_ok_cancel(int n) ;
int A4GL_fake_a_keypress (GtkWidget *widget, int key);

#define KEY_BUFFER_SIZE 256 
int keybuffer[KEY_BUFFER_SIZE];
int keybuffer_cnt=0;


GtkWindow *screenwindow;
GtkWidget *tooltips = 0;        /** Tooltip widget */
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
int keypressed=0;
GtkWidget *errorWindow=0;


struct s_a4gl_gtk_form {
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

/**
 * 
 * 
 * @todo : Please describe this function.
 */
int 
A4GL_getx_coords(int x) {
int x1;
int y1;
x1=x-1;
y1=0;
A4GL_getxy_coords(&x1,&y1);
return x1;
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
int 
A4GL_gety_coords(int y) {
int x1;
int y1;
x1=0;
y1=y-1;
A4GL_getxy_coords(&x1,&y1);
return y1;
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
void 
A4GL_getxy_coords(int *x,int *y) {
        *x=(*x)*XWIDTH;
        *y=(*y)*YHEIGHT;
}



/**
 * 
 * 
 * @todo : Please describe this function.
 */
static int 
get_keypress_from_buffer() {
  int cp[KEY_BUFFER_SIZE-1];
  int k;
  if (keybuffer_cnt==0) {
    return -1;
  }
  memcpy(&cp[0],&keybuffer[1],sizeof(cp));
  k=keybuffer[0];
  memcpy(&keybuffer[0],&cp[0],sizeof(cp));
  keybuffer_cnt--;
  return k;
}



/**
 * 
 * 
 * @todo : Please describe this function.
 */
static void 
add_keypress(int a) {
  if (keybuffer_cnt>=KEY_BUFFER_SIZE) {
    A4GL_LL_beep();
    return;
  }
  keybuffer[keybuffer_cnt++]=a;
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
static int 
ok_callback (gpointer data) {
	add_keypress(27);
  	return TRUE;
}

/**
 * 
 * 
 * @todo : Please describe this function.
 */
static int 
cancel_callback (gpointer data) {
#if (defined(WIN32) && ! defined(__CYGWIN__))
		set_intr_win32 (SIGINT);
#else
		kill(0,SIGINT);
#endif
	add_keypress(3);
  	return TRUE;
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
static void 
setup_ok_cancel(GtkWidget *ok_cancel) {
#if GTK_CHECK_VERSION(2,0,0)
#else
	GtkWidget *l;
#endif
GtkWidget *b;

	#if GTK_CHECK_VERSION(2,0,0)
		b=gtk_button_new_from_stock(GTK_STOCK_OK);
	#else
		b=gtk_button_new();
		l=gtk_label_new("OK");
		gtk_container_add(GTK_CONTAINER(b),l);
		gtk_widget_set_name(GTK_WIDGET(b), "OK"); 
		gtk_object_set_data(GTK_OBJECT(b),"LABEL",l);
		gtk_widget_show(l);
	#endif
    gtk_signal_connect_object (GTK_OBJECT (b), "clicked", GTK_SIGNAL_FUNC (ok_callback), 0);
    gtk_widget_show(b);

    gtk_container_add(GTK_CONTAINER(ok_cancel),b);

	// Set up the Cancel Button

	#if GTK_CHECK_VERSION(2,0,0)
		b=gtk_button_new_from_stock(GTK_STOCK_CANCEL);
	#else
		b=gtk_button_new();
		l=gtk_label_new("Cancel");
		gtk_container_add(GTK_CONTAINER(b),l);
		gtk_widget_set_name(GTK_WIDGET(b), "Cancel"); 
		gtk_object_set_data(GTK_OBJECT(b),"LABEL",l);
		gtk_widget_show(l);
	#endif
    gtk_signal_connect_object (GTK_OBJECT (b), "clicked", GTK_SIGNAL_FUNC (cancel_callback), 0);
    gtk_widget_show(b);
    gtk_container_add(GTK_CONTAINER(ok_cancel),b);

}

/**
 * 
 * 
 * @todo : Please describe this function.
 */
int
A4GL_keypress (GtkWidget * widget, GdkEventKey * event, gpointer user_data)
{

  // printf ("Key Pressed! %x %x (%s) widget=%p user_data=%p\n", event->keyval, event->state, gdk_keyval_name (event->keyval),widget,user_data);

  if (event->state & 4)
    {                           /*  Control key held down... */
      if (a4gl_tolower (event->keyval) >= 'a' && a4gl_tolower (event->keyval) <= 'z')
        keypressed = a4gl_tolower (event->keyval) - 'a' + 1;
      else
        keypressed = -1;
    }
  else
    {
      keypressed = event->keyval;
    }

  add_keypress(keypressed);
  actionfield = widget;
  return keypressed;
}


int
A4GL_fake_a_keypress (GtkWidget *widget,int key)
{
  // printf ("Key Pressed! %x %x (%s) widget=%p user_data=%p\n", event->keyval, event->state, gdk_keyval_name (event->keyval),widget,user_data);
	keypressed=key;
  add_keypress(keypressed);
  return keypressed;
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
void 
A4GL_console_toggle (void) {
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
void A4GL_show_console (void)
{
  gtk_widget_show (GTK_WIDGET (console));
}


/**
 * Hide the console widget.
 */
void A4GL_hide_console (void)
{
  gtk_widget_hide (GTK_WIDGET (console));
}

/**
 * Append a string to the console list widget.
 */
void A4GL_add_to_console (char *s)
{
  char *utf=g_locale_to_utf8(s, -1, NULL, NULL, NULL);
  gtk_clist_append (GTK_CLIST (console_list), &utf);
  g_free(utf);
}

/**
 * Clear the data showed n the console.
 */
void A4GL_clear_console (char *s)
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
  //UILIB_A4GL_gui_run_til_no_more ();
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
  A4GL_fgl_end_4gl_0();

 //UILIB_A4GL_gui_run_til_no_more ();
 return FALSE;
}


/**
 * Create the console widget.
 *
 * @todo : Define what is the console widget.
 */
void A4GL_create_console (void)
{


  GtkWidget *scroll;

  A4GL_debug("A4GL_create_console");

  console = (GtkWindow *) gtk_window_new (GTK_WINDOW_TOPLEVEL);
  if(!console)
    A4GL_debug("gtk_window_new: NULL");

  scroll = gtk_scrolled_window_new (NULL, NULL);
  if(!scroll)
    A4GL_debug("gtk_scrolled_window_new: NULL");

  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scroll),
                                  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  gtk_widget_show (scroll);

  console_list = gtk_clist_new (1);     /* 1 column for now.... */

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

  A4GL_debug("console created");

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
  gtk_object_set_data (GTK_OBJECT (win), "RETURNS", gtk_object_get_data (data, "BUTCODE"));
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
  char *txt_utf;
  GtkButton *but;

  switch (but_code)
    {
    case BUTTON_OK:
      txt = acl_getenv("A4GL_DIALOG_OK");
      break;
    case BUTTON_CANCEL:
      txt = acl_getenv("A4GL_DIALOG_CANCEL");
      break;
    case BUTTON_ABORT:
      txt = acl_getenv("A4GL_DIALOG_ABORT");
      break;
    case BUTTON_RETRY:
      txt = acl_getenv("A4GL_DIALOG_RETRY");
      break;
    case BUTTON_IGNORE:
      txt = acl_getenv("A4GL_DIALOG_IGNORE");
      break;
    case BUTTON_YES:
      txt = acl_getenv("A4GL_DIALOG_YES");
      break;
    case BUTTON_NO:
      txt = acl_getenv("A4GL_DIALOG_NO");
      break;
    default:
      txt = "FIXME: unknown Button";
      A4GL_debug("add_button: unknown button-code: %d\n", but_code);
    }

  txt_utf=g_locale_to_utf8(txt, -1, NULL, NULL, NULL);

  gtk_object_set_data (GTK_OBJECT (win), "RETURNS", 0);
  but = (GtkButton *) gtk_button_new_with_label (txt_utf);
  g_free(txt_utf);

  gtk_object_set_data (GTK_OBJECT (but), "BUTCODE", (gpointer) but_code);
  gtk_object_set_data (GTK_OBJECT (but), "DIALOGWIN", win);
  gtk_container_add (GTK_CONTAINER (GTK_DIALOG (win)->action_area), (GtkWidget *) but);
  gtk_signal_connect_object (GTK_OBJECT (but), "clicked", GTK_SIGNAL_FUNC (dialog_callback), GTK_OBJECT (win));
}


/**
 * 
 * 
 * @todo : Please describe this function.
 */
int 
A4GL_gtkdialog (char *caption, char *icon, int buttons, int defbutt, int dis, char *msg) {
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
  if(msg)
    label_utf=g_locale_to_utf8(msg, -1, NULL, NULL, NULL);
  else
    label_utf=NULL;
  label = (GtkLabel *) gtk_label_new (label_utf);
  #if GTK_CHECK_VERSION(2,0,0)
  if(A4GL_isyes(acl_getenv("A4GL_USE_PANGO_ML"))) {
    A4GL_debug("using PANGO ML for Label '%s'\n",msg);
    gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
  }
  #endif
  g_free(label_utf);
  gtk_container_add (GTK_CONTAINER (GTK_DIALOG (win)->vbox),
                     GTK_WIDGET (label));

  if (strlen (caption)) {
    label_utf=g_locale_to_utf8(caption, -1, NULL, NULL, NULL);
    gtk_window_set_title (GTK_WINDOW (win), label_utf);
    g_free(label_utf);
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
KeySnooper (GtkWidget * grab_widget, GdkEventKey * event, gpointer func_data) {
	A4GL_debug ("Key Snooper... %p %p %p\n", grab_widget, event, func_data);
	A4GL_debug ("Key Pressed! %x %x (%s)\n", event->keyval, event->state,
	gtk_accelerator_name (event->keyval, event->state));

  if (event->keyval == 0xffbe && event->state == 1)
    {
      A4GL_debug ("Toggle console...");
      A4GL_console_toggle ();
    }

  fflush (stdout);
  if (strcmp(gtk_accelerator_name (event->keyval, event->state),"<Control>c")==0) {
        A4GL_keypress (grab_widget, event, func_data);
  }

  if (strcmp(gtk_accelerator_name (event->keyval, event->state),"Escape")==0) {
        //event->keyval=27;
        A4GL_keypress (grab_widget, event, func_data);
  }
  //A4GL_clr_error_gtk ();
  return 0;
}

void MyStyleSetItemColor (GdkColor color,       /* The allocated color to be added to the style */
                          char item,    /* the item to which the color is to be applied */
                          /* 'f' = foreground; 'b' = background; */
                          /* 'l' = light;      'd' = dark; */
                          /* 'm' = mid;        't' = text; */
                          /* 's' = base. */
                          GtkStyle * style      /* The old style - changes made to a copy */
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
A4GL_alloc_colors (void) {
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
int A4GL_LL_colour_code(int a) {
	return a;
}

/**
 * 
 * 
 * @todo : Please describe this function.
 */
void* 
A4GL_LL_create_window(int h,int w,int y,int x,int border) {
GtkWidget *fixed=0;
GtkWidget *win=0;
GtkWidget *frame = 0;
GtkWidget *wxx = 0;

	if (x==0&&y==0&&h==0&&w==0) {
		int additional;
		GtkWidget *hbox;
		GtkWidget *fglmenu_bb;
		GtkWidget *ok_cancel;
		GtkWidget *frame;
		
		additional=0;
		if (!A4GL_isyes(acl_getenv("TRADMENU"))) {
			additional=15;
		}
		win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
		gtk_widget_set_usize (GTK_WIDGET (win), (A4GL_LL_screen_width()+additional)*gui_xwidth, (A4GL_LL_screen_height()+1)*gui_yheight);
		gtk_window_set_title (GTK_WINDOW (win), "4GL Application");
		gtk_widget_set_name(GTK_WIDGET(win), "AppWindow");
	
		if ( A4GL_menu_pos()=='T'|| A4GL_menu_pos()=='B') {
			hbox=gtk_vbox_new(0,3);
		} else {
			hbox=gtk_hbox_new(0,3);
		}
		if ( A4GL_menu_pos()=='T'|| A4GL_menu_pos()=='B') {
			fglmenu_bb=gtk_hbutton_box_new();
			ok_cancel=gtk_hbutton_box_new();
		} else {
			fglmenu_bb=gtk_vbutton_box_new();
			ok_cancel=gtk_vbutton_box_new();
		}
		gtk_widget_set_name(GTK_WIDGET(fglmenu_bb), "MenuButtons");
		gtk_widget_set_name(GTK_WIDGET(ok_cancel), "OKCancel");
		setup_ok_cancel(ok_cancel);
		gtk_button_box_set_layout(GTK_BUTTON_BOX(fglmenu_bb),GTK_BUTTONBOX_START);
		gtk_button_box_set_layout(GTK_BUTTON_BOX(ok_cancel),GTK_BUTTONBOX_START);
		gtk_widget_hide(ok_cancel); // We should only be showing fglmenu_bb or ok_cancel - never both
		gtk_widget_set_name(GTK_WIDGET(hbox), "MenuButtons");
		gtk_widget_show(hbox);
		if (!A4GL_isyes(acl_getenv("TRADMENU"))) {
			gtk_widget_set_name(GTK_WIDGET(fglmenu_bb), "MenuButtons");
			gtk_widget_show(fglmenu_bb);
		}
	
		fixed = gtk_fixed_new ();
		gtk_widget_set_name(GTK_WIDGET(fixed), "AppWindow");
		#if GTK_CHECK_VERSION(2,0,0)
			gtk_fixed_set_has_window    (GTK_FIXED(fixed),1);
		#endif
		gtk_widget_show (GTK_WIDGET (fixed));
		#ifdef USE_FRAMES
			frame=gtk_frame_new(0);
		#else
			frame=gtk_handle_box_new();
		#endif
		gtk_widget_set_name(GTK_WIDGET(frame), "AppWindow");
	
		if ( A4GL_menu_pos()=='L'|| A4GL_menu_pos()=='R') {
			gtk_box_set_child_packing(GTK_BOX(hbox),frame,1,1,2,GTK_PACK_START);
		} else {
			gtk_box_set_child_packing(GTK_BOX(hbox),frame,1,1,0,GTK_PACK_START);
		}
	
		gtk_widget_show(frame);
		gtk_container_add (GTK_CONTAINER (frame),fixed);
	
		if (!A4GL_isyes(acl_getenv("TRADMENU"))) {
			GtkWidget *f;
			GtkWidget *vbox;
			#ifdef USE_FRAMES
				f=gtk_frame_new(0);
			#else
				f=gtk_handle_box_new();
			#endif
			gtk_widget_set_name(GTK_WIDGET(f), "MenuButtons");
			vbox=gtk_vbox_new(0,0);
			if ( A4GL_menu_pos()=='L'|| A4GL_menu_pos()=='R') {
					gtk_widget_set_usize (GTK_WIDGET (vbox), additional*gui_xwidth, (A4GL_LL_screen_height()+1)*gui_yheight);
			}  else {
					gtk_widget_set_usize (GTK_WIDGET (vbox), (A4GL_LL_screen_width()+1)*gui_xwidth,2*gui_yheight);
			}
			gtk_widget_show(f);
			gtk_widget_set_name(GTK_WIDGET(f), "MenuButtons");
			gtk_widget_show(vbox);
			gtk_container_add (GTK_CONTAINER (vbox), fglmenu_bb);
			gtk_container_add (GTK_CONTAINER (vbox), ok_cancel);
			gtk_container_add(GTK_CONTAINER(f),vbox);
	
			if ( A4GL_menu_pos()=='T'|| A4GL_menu_pos()=='L') {
				gtk_container_add (GTK_CONTAINER (hbox), f);
				gtk_container_add (GTK_CONTAINER (hbox), frame);
			} else {
				gtk_container_add (GTK_CONTAINER (hbox), frame);
				gtk_container_add (GTK_CONTAINER (hbox), f);
			}
		}
	
		gtk_box_set_spacing(GTK_BOX(hbox),0);
		gtk_container_add (GTK_CONTAINER (win), hbox);
		win_screen=fixed;
		gtk_widget_set_usize (GTK_WIDGET (fixed), (A4GL_LL_screen_width())*gui_xwidth, (A4GL_LL_screen_height())*gui_yheight);
		gtk_object_set_data (GTK_OBJECT (win_screen), "BB", fglmenu_bb);
		gtk_object_set_data (GTK_OBJECT (win_screen), "OKCANCEL",ok_cancel);
		gtk_object_set_data (GTK_OBJECT (win), "FIXED", fixed);
		gtk_signal_connect (GTK_OBJECT (win), "delete_event", GTK_SIGNAL_FUNC (A4GL_delete_event), win);
		gtk_signal_connect (GTK_OBJECT (win), "destroy", GTK_SIGNAL_FUNC (A4GL_destroy_event), win);
	} else {
		h=h*gui_yheight;
		y=(y-1)*gui_yheight;
		w=w*gui_xwidth;
		x=(x-1)*gui_xwidth;
	
		A4GL_debug ("w=%d h=%d\n", w / XWIDTH, h / YHEIGHT);
		win = gtk_fixed_new ();
		#if GTK_CHECK_VERSION(2,0,0)
			gtk_fixed_set_has_window    (GTK_FIXED(win),1);
		#endif
		gtk_widget_set_usize (GTK_WIDGET (win), w+gui_xwidth, h+gui_yheight);
		gtk_object_set_data (GTK_OBJECT (win), "FIXED", fixed);
		if (border) {
			A4GL_debug("Creating bordered window...");
			wxx = 0;
			if (window_frame_type == 0) {
				wxx = gtk_event_box_new ();
			}
			if (window_frame_type == 99) {
				wxx = gtk_handle_box_new ();
			}
			if (wxx == 0) {
				A4GL_exitwith ("Invalid window style type");
				return 0;
			}
			// Add the event box as top of our window...
			gtk_fixed_put (GTK_FIXED (win_screen), wxx, x - XWIDTH, y - YHEIGHT );
			// Create a frame to go in our eventbox
			#ifdef USE_FRAMES
				frame = (GtkWidget *) gtk_frame_new (0);
				gtk_frame_set_shadow_type (GTK_FRAME (frame), frame_style);
			#else
				frame = (GtkWidget*)gtk_handle_box_new ();
				gtk_handle_box_set_shadow_type (GTK_HANDLE_BOX(frame), frame_style);
			#endif
			gtk_widget_set_usize (GTK_WIDGET (frame), w+XWIDTH , h+YHEIGHT);
			// Add our frame to the eventbox
			gtk_container_add (GTK_CONTAINER (wxx), GTK_WIDGET (frame));
			gtk_widget_show (GTK_WIDGET (wxx));
			gtk_widget_show (GTK_WIDGET (frame));
			gtk_container_add(GTK_CONTAINER(frame),win);
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
		} else {
			#if GTK_CHECK_VERSION(2,0,0)
				gtk_fixed_set_has_window    (GTK_FIXED(win),1);
			#endif
			gtk_fixed_put (GTK_FIXED (win_screen), win, x,y);
			gtk_object_set_data (GTK_OBJECT (win), "FIXED", win);
			gtk_object_set_data (GTK_OBJECT (win), "TOP", win);
		}
	}
  	gtk_widget_show (win);
	//printf("COnnecting key-press-event\n");
	gtk_signal_connect (GTK_OBJECT (win), "key-press-event", GTK_SIGNAL_FUNC (A4GL_keypress), win);
	//printf("COnnected\n");
	A4GL_debug("Created window %p for h=%d w=%d y=%d x=%d b=%d",win, h, w, y, x, border);
	UILIB_A4GL_gui_run_til_no_more ();
	return win;
}

void 
A4GL_LL_error_box(char* str,int attr) {
char *error=acl_getenv("A4GL_DIALOG_ERROR");
  	A4GL_gtkdialog (error, "", BUTTONS_OK, BUTTON_OK, 0, str);
}

char* 
A4GL_LL_field_buffer(void* field,int n) {
char *ptr;
   	ptr=A4GL_fld_val_generic (field);
	// printf("Got field value as : '%s'\n",ptr);
	return ptr;
}


int 
A4GL_LL_getch_swin(void* window_ptr) {
  int a;
  A4GL_set_abort (0);
  a = A4GL_readkey ();
  if (a != 0) {
      A4GL_debug ("Read %d from keyfile", a);
	A4GL_LL_gui_run_til_no_more();
      return a;
    }

	keypressed=0;
      	while (1) {
		a=get_keypress_from_buffer();
		if (a!=-1) break;
       		gtk_main_iteration ();
	}
	keypressed=0;
	//printf("KEYPRESS : %d (%x)\n",a,A4GL_which_key_aubit(a));
	if (a==3) {
#if (defined(WIN32) && ! defined(__CYGWIN__))
		set_intr_win32 (SIGINT);
#else
		kill(0,SIGINT);
#endif

	}

	a=A4GL_which_key_aubit(a);
	A4GL_logkey(a);
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
BOOL __stdcall
set_intr_win32 (DWORD type)
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

int A4GL_which_key_aubit(int gdk_key)
{
int a;
a=gdk_key;
        if (a==GDK_F12) {
		gtk_rc_reparse_all ();
		//A4GL_run_gtkrc();
		return A4GLKEY_F(12);
	}
	if (a==3) return -1;
        if (a==GDK_Escape) return 27;
        if (a==GDK_Down) return A4GLKEY_DOWN;
        if (a==GDK_Up) return A4GLKEY_UP;
        if (a==GDK_Left) return A4GLKEY_LEFT;
        if (a==GDK_Right) return A4GLKEY_RIGHT;
        if (a==GDK_Return) return A4GLKEY_ENTER;
        if (a==GDK_Tab) return 9;
        if (a==GDK_ISO_Left_Tab) return A4GLKEY_SHTAB;
        if (a==GDK_F1) return A4GLKEY_F(1);
        if (a==GDK_F2) return A4GLKEY_F(2);
        if (a==GDK_F3) return A4GLKEY_F(3);
        if (a==GDK_F4) return A4GLKEY_F(4);
        if (a==GDK_F5) return A4GLKEY_F(5);
        if (a==GDK_F6) return A4GLKEY_F(6);
        if (a==GDK_F7) return A4GLKEY_F(7);
        if (a==GDK_F8) return A4GLKEY_F(8);
        if (a==GDK_F9) return A4GLKEY_F(9);
        if (a==GDK_F10) return A4GLKEY_F(10);
        if (a==GDK_F11) return A4GLKEY_F(11);
        if (a==GDK_F12) return A4GLKEY_F(12);
        if (a==GDK_F13) return A4GLKEY_F(13);
        if (a==GDK_F14) return A4GLKEY_F(14);
        if (a==GDK_F15) return A4GLKEY_F(15);
        if (a==GDK_F16) return A4GLKEY_F(16);
        if (a==GDK_F17) return A4GLKEY_F(17);
        if (a==GDK_F18) return A4GLKEY_F(18);
        if (a==GDK_F19) return A4GLKEY_F(19);
        if (a==GDK_F20) return A4GLKEY_F(20);
        if (a==GDK_F21) return A4GLKEY_F(21);
        if (a==GDK_F22) return A4GLKEY_F(22);
        if (a==GDK_F23) return A4GLKEY_F(23);
        if (a==GDK_F24) return A4GLKEY_F(24);
        if (a==GDK_F25) return A4GLKEY_F(25);
        if (a==GDK_F26) return A4GLKEY_F(26);
        if (a==GDK_F27) return A4GLKEY_F(27);
        if (a==GDK_F28) return A4GLKEY_F(28);
        if (a==GDK_F29) return A4GLKEY_F(29);
        if (a==GDK_F30) return A4GLKEY_F(30);
        if (a==GDK_F31) return A4GLKEY_F(31);
        if (a==GDK_F32) return A4GLKEY_F(32);
        if (a==GDK_F33) return A4GLKEY_F(33);
        if (a==GDK_F34) return A4GLKEY_F(34);
        if (a==GDK_F35) return A4GLKEY_F(35);




	if (a==0xff08) return A4GLKEY_DC;
//printf("%x\n",a);
        return a;
}




void A4GL_LL_gui_run_til_no_more(void ) {
  //A4GL_debug("A4GL_LL_gui_run_til_no_more");
  if (A4GL_screen_mode (-1))
    {
      while (gtk_events_pending ())
        gtk_main_iteration ();
	if (keypressed==3) {



#if (defined(WIN32) && ! defined(__CYGWIN__))
		set_intr_win32 (SIGINT);
#else
		kill(0,SIGINT);
#endif

	}
    }
  else
    {
      A4GL_debug ("Skipping run_til_no_more - in pause mode");
    }
}



void A4GL_LL_hide_window(void* w) {
  gtk_widget_hide (w);
}


void A4GL_run_gtkrc(void) {
  char *gtkrc;
  char buff[255];
  char buff2[255];

  A4GL_debug("A4GL_run_gtkrc");

  gtkrc=acl_getenv("GTKRC");
  if (gtkrc==0) {
	gtkrc="";
  }

  if (strlen(gtkrc)==0) {
		sprintf(buff2,"%s/etc/gtkrc",acl_getenv("AUBITDIR"));
		gtkrc=buff2;
  }

#if GTK_CHECK_VERSION(2,0,0)
      sprintf (buff, "%s_2",gtkrc);
#else
      sprintf (buff, "%s", gtkrc);
#endif

      A4GL_debug("Reading RC File (gtk_rc_parse('%s')", buff);
      gtk_rc_parse (buff);
      A4GL_debug("done");
}




void A4GL_LL_initialize_display(void ) {
  //char *argvv[]={};
  //char *gtkrc;
  //char buff[255];
  //char buff2[255];

  A4GL_debug("A4GL_LL_initialize_display");

#if GTK_CHECK_VERSION(2,0,0)
  gtk_disable_setlocale(); /* tell GTK to NOT call setlocale(LC_ALL,"")! */
                           /* the only place where setlocate() should */
			   /* be called is lib/libaubit4gl/fglwrap.c */
#else
	#ifdef DEBUG
		A4GL_debug("gtk_disable_setlocale() skipped - using GTK+ v 1.2");
	#endif
#endif
  gtk_init (0, 0);
  if (acl_getenv("CELL_HEIGHT")) { if (strlen(acl_getenv("CELL_HEIGHT"))) gui_yheight=atoi(acl_getenv("CELL_HEIGHT")); }
  if (acl_getenv("CELL_WIDTH"))  { if (strlen(acl_getenv("CELL_WIDTH"))) gui_xwidth=atoi(acl_getenv("CELL_WIDTH")); }

  A4GL_debug("gui_xwidth:%d  gui_yheight:%d", gui_xwidth, gui_yheight);

  A4GL_run_gtkrc();

  A4GL_alloc_colors ();
  gtk_key_snooper_install (KeySnooper, 0);
  A4GL_create_console ();

  if (tooltips == 0) tooltips = (GtkWidget *) gtk_tooltips_new ();


  UILIB_A4GL_gui_run_til_no_more ();

}






void A4GL_LL_make_window_top(void* w) {
  static GtkWidget *b = 0;

  /* If we are not using formhandlers then we need to
     ensure modality with the currwindow...
   */

          b = gtk_object_get_data (GTK_OBJECT (w), "FRAME");
	  if (b) {
           	gtk_widget_hide (b);
          	gtk_widget_show (b);
		return;
          }

      b = gtk_object_get_data (GTK_OBJECT (w), "TOP");
	if (b) {
      		gtk_widget_hide (b);

      		//gtk_widget_show_all (b);
      		gtk_widget_show (b);

		return;
	}


      gtk_widget_hide (w);
      //gtk_widget_show_all (w);
      gtk_widget_show (w);
}

void A4GL_LL_move_window(void* w,int y,int x) {
int yo;
int xo;
  yo = (int) gtk_object_get_data (GTK_OBJECT (w), "Y_OFF");
  xo = (int) gtk_object_get_data (GTK_OBJECT (w), "X_OFF");
  gtk_fixed_move ((GtkFixed *) win_screen, w, (x - 1) * XWIDTH + xo, (y - 1) * YHEIGHT + yo);
}




void A4GL_LL_remove_window(void* x) {
void *xx;
	//printf("REMOVE WINDOW : %p\n",x);
xx=gtk_object_get_data(GTK_OBJECT(x),"TOP");
if (xx) {
  	gtk_widget_destroy (xx);
} else {
  	gtk_widget_destroy (x);
}
}


int A4GL_LL_screen_height(void ) {
char *ptr;
ptr=acl_getenv("LINES");
if (ptr==0||strlen(ptr)==0) return 25;
return atoi(ptr);
}

void A4GL_LL_screen_mode(void ) {
	//printf("NEED TO HIDE CONSOLE0\n");
	A4GL_hide_console();
}

void A4GL_LL_screen_refresh(void ) {
	//printf("NEED TO HIDE CONSOLE1\n");
	//A4GL_hide_console();
	UILIB_A4GL_gui_run_til_no_more();
}

void A4GL_LL_screen_redraw(void ) {
	//printf("NEED TO HIDE CONSOLE1\n");
	//A4GL_hide_console();
	UILIB_A4GL_gui_run_til_no_more();
}

void A4GL_LL_screen_update(void ) {
	//printf("NEED TO HIDE CONSOLE2\n");
	//A4GL_hide_console();
	UILIB_A4GL_gui_run_til_no_more();
}



int A4GL_LL_screen_width(void ) {
	int w=80;
        if (acl_getenv("COLUMNS")) {
			if (strlen(acl_getenv("COLUMNS"))) w=atoi(acl_getenv("COLUMNS"));
	}
	//printf("screen width=%d\n",w);
	return w;
}







void A4GL_LL_set_current_field(void* vform,void* field) {
struct s_a4gl_gtk_form *form;
int a;
	form=vform;
	
 	if (field) {
		gtk_widget_grab_focus (GTK_WIDGET (field));
		for (a=0;a<form->nwidgets;a++) {
			if (form->widgets[a]==field) {
				//printf("Set current field...\n");
				if (form->currentfield!=a) {
					form->curcol=0;
				}
				form->currentfield=a;
				break;
			}
		}
	}
}





void A4GL_LL_set_field_back(void* field,int attr) {
  char buff[255];
  //printf("set field back %p %x\n",field,attr);
  if (allocated_colors == 0)
    A4GL_alloc_colors ();
  //gtk_widget_set_style (field, rcolorStyles[attr & 7]);

    attr=attr&0xffffff00;
    sprintf(buff,"%x",attr>>8);
    gtk_widget_set_name(GTK_WIDGET(field), buff);
	
//printf("SET_FIELD_BACK : %p - %s\n",field,buff);


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





void A4GL_LL_set_field_fore(void* field,int attr) {
  char buff[255];
  char *ptr;
  //printf("set field fore %p %x\n",field,attr);
ptr=gtk_object_get_data(field,"WIDGETSNAME");
  if (allocated_colors == 0)
    A4GL_alloc_colors ();
    attr=attr&0xffffff00;
    sprintf(buff,"%x",attr>>8);
	if (ptr) {
		//printf("SET FIELD FORE on a proper field %x -> %s\n",attr,buff);
	}
    gtk_widget_set_name(GTK_WIDGET(field), buff);
	//printf("SET_FIELD_FORE : %p - %s\n",field,buff);

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



int A4GL_LL_set_field_opts(void* field,int oopt) {

//printf("field opts %p %x\n",field,oopt);
	gtk_object_set_data(GTK_OBJECT((GtkWidget *)field),"FIELD_OPTS",(void *)oopt);

    if (oopt & AUBIT_O_ACTIVE || oopt & AUBIT_O_EDIT) {
		A4GL_gui_set_active (field, 1);
    } else {
 		if (gtk_object_get_data(GTK_OBJECT(field),"MF_ISLABEL")
                || gtk_object_get_data(GTK_OBJECT(field),"DISPLAY_LABEL")) {
			// Labels are always active :)
			A4GL_gui_set_active (field, 1);
		} else {
			A4GL_gui_set_active (field, 0);
		}
    }
   return 1;
}

void A4GL_LL_show_window(void* w) {
    gtk_widget_show (w);
}


void A4GL_LL_sleep(int n) {
int c;
int b;
  for (c = 0; c < n; c++)
    {
      for (b = 0; b <= 9; b++)
        {
          a4gl_usleep (100000);
          UILIB_A4GL_gui_run_til_no_more ();
        }
    }
}

int A4GLHLUI_initlib(void) { return 0;}

void A4GL_LL_switch_to_line_mode(void ) {
	A4GL_show_console();
}


void A4GL_LL_wadd_char_xy_col(void* win,int x,int y,int ch,int curr_width,int curr_height,int iscurrborder) {
  GtkFixed *cwin;
  GtkEventBox *e;
  GtkLabel *lab;
  


  char buff_label[256];
  char buff_evt[256];
  char buff_char[256];
  char buff_attr[256];

  long old_attr=0;
  long has_old_attr=0;
  char cbuff[10];
  cbuff[0]=ch&0xff;
  cbuff[1]=0;
	
A4GL_debug("Wadd_char to window %p %d %d %x",win,x,y,ch);

      sprintf (buff_label, "LABEL_%d_%d", x, y);
      sprintf (buff_char, "LABEL_%d_%d_C", x, y);
      sprintf (buff_evt, "EVENTBOX_%d_%d", x, y);
      sprintf (buff_attr, "ATTR_%d_%d", x, y);
      
//printf("%d %d\n",x,y);
      cwin=gtk_object_get_data (GTK_OBJECT (win), "FIXED");
      lab = (GtkLabel *) gtk_object_get_data (GTK_OBJECT (cwin), buff_label);
      e = (GtkEventBox *) gtk_object_get_data (GTK_OBJECT (cwin), buff_evt);
      old_attr=(long)gtk_object_get_data(GTK_OBJECT(cwin),buff_attr);


      if (old_attr==ch &&lab && e) return;
      gtk_object_set_data(GTK_OBJECT(cwin),buff_attr,(void *)ch);

//printf("fixed=%p win=%p %c %x\n",cwin,win,ch&0xff,ch&0xffffff00);fflush(stdout);
	

		// It did have...
     if (ch==32||ch==0||ch==0x10720||ch==0x10700) {

		if (lab==0&&e==0) {
			//printf("Ignore...");
			return;
		}

#ifdef XXX
			if (lab) {
				gtk_widget_destroy(GTK_WIDGET(lab));
      		        	gtk_object_set_data (GTK_OBJECT (cwin), buff_label,0);
				//printf ("Destroy...%s in %p\n",buff_label,cwin);
			}
	
			if (e) {
				gtk_widget_destroy(GTK_WIDGET(e));
      		        	gtk_object_set_data (GTK_OBJECT (cwin), buff_evt,0);
				//printf ("Destroy...%s in %p\n",buff_evt,cwin);
			}
			return ;
#endif
      } 

	if ((ch&0xff)==32) {
		//printf("Ign spc %s\n",buff_label);
	}


      if (!lab) {
		char *lab_utf=g_locale_to_utf8(cbuff, -1, NULL, NULL, NULL);
		//printf("NEW LABEL FOR : %d %d\n",x,y);
                lab = (GtkLabel *) gtk_label_new (lab_utf);
		g_free(lab_utf);

		e=(GtkEventBox *)gtk_event_box_new();
                gtk_fixed_put (GTK_FIXED (cwin), GTK_WIDGET (e), A4GL_getx_coords(x), A4GL_gety_coords(y));
		gtk_container_add(GTK_CONTAINER(e),GTK_WIDGET(lab));

                gtk_object_set_data (GTK_OBJECT (cwin), buff_label, lab);
                gtk_object_set_data (GTK_OBJECT (cwin), buff_char, (void *)(ch&0xff));

                gtk_object_set_data (GTK_OBJECT (cwin), buff_evt, e);

		//gtk_label_set_justify( lab,GTK_JUSTIFY_CENTER);
		//gtk_misc_set_alignment(GTK_MISC(lab), 0.5f, 0.5f);
		gtk_misc_set_alignment(GTK_MISC(lab), 0.5f, 0.5f);
#if GTK_CHECK_VERSION(2,0,0)
		gtk_widget_set_size_request (GTK_WIDGET(e), gui_xwidth, gui_yheight);
		gtk_widget_set_size_request (GTK_WIDGET(lab), gui_xwidth, gui_yheight);

#endif

		has_old_attr=0;

        	gtk_widget_show (GTK_WIDGET (lab));
        	gtk_widget_show (GTK_WIDGET (e));

      } else {
		char *txt_utf=g_locale_to_utf8(cbuff, -1, NULL, NULL, NULL);
		has_old_attr=1;
                gtk_label_set_text (lab, txt_utf);
		g_free(txt_utf);
#if GTK_CHECK_VERSION(2,0,0)
		gtk_widget_set_size_request (GTK_WIDGET(lab), gui_xwidth, gui_yheight);
#endif		

		if ((ch&0xff)==32) {
			//printf("Ign spc %s reset\n",buff_label);
		}

      }
	
      if ((old_attr&0xffffff00)==(ch&0xffffff00) && has_old_attr) ;
      else {
      		A4GL_LL_set_field_back ((GtkWidget *) e  , ch); 
      		A4GL_LL_set_field_fore ((GtkWidget *) lab, ch);
      }
}


void A4GL_LL_set_form_userptr(void* vform,void* data) {
struct s_a4gl_gtk_form *form;
form=vform;
   form->userptr=data;
}


int A4GL_LL_set_chars_normal(int* n) {
	return 0;
}

void A4GL_LL_beep() {
	gdk_beep();
}

void* A4GL_LL_get_field_userptr(void* field) {
  return gtk_object_get_data (GTK_OBJECT (field), "USERPTR");
}

int A4GL_LL_get_field_width(void* f) {
  return (int)gtk_object_get_data (GTK_OBJECT ((GtkWidget *)f), "MF_COLS");
}

void* A4GL_LL_get_form_userptr(void* vform) {
struct s_a4gl_gtk_form *form;
	form=vform;
   return form->userptr;
}

int A4GL_LL_field_status(void* field) {
  return (int)gtk_object_get_data (GTK_OBJECT (field), "STATUS");
}


void A4GL_LL_set_field_userptr(void* field,void* ptr) {
  return gtk_object_set_data (GTK_OBJECT (field), "USERPTR",ptr);
}

int A4GL_LL_set_field_status(void* f,int stat) {
  gtk_object_set_data (GTK_OBJECT (f), "STATUS",(void *)stat);
  return stat;
}

void A4GL_LL_out_linemode(char* s) {
//A4GL_chkwin();
//printf("Adding '%s' to console\n",s);
A4GL_add_to_console (s);
}


int A4GL_LL_field_opts(void* field) {
	return (int)gtk_object_get_data(GTK_OBJECT(field),"FIELD_OPTS");
}

int A4GL_LL_decode_aubit_attr(int a,char s) {
	/* CHECK IMPLEMENTATION */
	return a;
}

void* A4GL_LL_current_field(void* vform) {
struct s_a4gl_gtk_form *form;
form=vform;
return form->widgets[form->currentfield];
}

void A4GL_LL_set_max_field(void* f,int n) {
  	gtk_object_set_data (GTK_OBJECT (f), "MAXFIELD",(void *)n);
	if (strcmp(gtk_object_get_data(GTK_OBJECT(f),"WIDGETSNAME"),"ENTRY")==0) {
        	gtk_entry_set_max_length(f,n);
	}

	// NEED MORE HERE...
}

int A4GL_LL_set_new_page(void* field,int n) {
	//printf("SET NEW PAGE %p %d\n",field,n);
  	gtk_object_set_data (GTK_OBJECT (field), "NEWPAGE",(void *)1);
	return 1;
}

/******************************************************************************
 *  ERROR HANDLING
 *****************************************************************************/
void A4GL_LL_delete_errorwindow(void* curr_error_window) {
A4GL_debug("error window : removing %p",curr_error_window);
	gtk_widget_destroy(curr_error_window);
}


void* A4GL_LL_create_errorwindow(int h,int w,int y,int x,int attr,char* str) {
GtkWidget *frame;  // We want it in a nice frame
GtkWidget *label;  // With some text
GtkWidget *evt;    // And we'll use this to get a background colour...
char buff[80];
char *lab_utf=g_locale_to_utf8(str, -1, NULL, NULL, NULL);
A4GL_debug("Create error window");

frame=gtk_frame_new(0);
label=gtk_label_new(lab_utf);
#if GTK_CHECK_VERSION(2,0,0)
if(A4GL_isyes(acl_getenv("A4GL_USE_PANGO_ML"))) {
  A4GL_debug("using PANGO ML for Label '%s'\n", str);
  gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
}
#endif
g_free(lab_utf);
evt=gtk_event_box_new();

if (A4GL_isyes(acl_getenv("FITOSIZE_ERRWIN")))  ;
else {
	gtk_widget_set_usize (GTK_WIDGET (frame), w*gui_xwidth , h*gui_yheight);
}

errorWindow=frame;
gtk_container_add(GTK_CONTAINER(frame),evt);
gtk_container_add(GTK_CONTAINER(evt),label);
gtk_fixed_put(win_screen,errorWindow,x*gui_xwidth,y*gui_yheight);
// Align it halfway through the frame vertically, but on the left
//
gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5f);
if (attr==0) {
	sprintf(buff,"Error");
	gtk_widget_set_name(GTK_WIDGET(frame), buff);
	gtk_widget_set_name(GTK_WIDGET(evt), buff);
	gtk_widget_set_name(GTK_WIDGET(label), buff);
} else {
	sprintf(buff,"%x",attr>>8);
	gtk_widget_set_name(GTK_WIDGET(frame), buff);
	gtk_widget_set_name(GTK_WIDGET(evt), buff);
	gtk_widget_set_name(GTK_WIDGET(label), buff);
}




//printf("SET FIELD FORE 2: %x\n",att,attrr);
//if (attr&0xffffff00) { A4GL_LL_set_field_back ((GtkWidget *) evt  , attr&0xffffff00); A4GL_LL_set_field_fore ((GtkWidget *) label, attr&0xffffff00); }

gtk_widget_show(evt);
gtk_widget_show(label);
gtk_widget_show(errorWindow);
A4GL_debug("error window : Returning %p",errorWindow);
return errorWindow;
}



char * A4GL_decode_str_fprop (struct_scr_field * fprop, int type)
{
  int b;
  for (b = 0; b < fprop->str_attribs.str_attribs_len; b++)
    {
      if (fprop->str_attribs.str_attribs_val[b].  type == type)
        {
          return fprop->str_attribs.str_attribs_val[b].value;
        }
    }
  return "";
}

/******************************************************************************
 *   Not Implemented Yet...
 *****************************************************************************/

/******************************************************************************
 *   MISC
 *****************************************************************************/
void A4GL_LL_set_bkg(void* win,int attr) {
char buff[256];
void *x;
char *ptr;
	sprintf(buff,"%x",attr>>8);
	//printf("set_bkg : %s\n",buff);
	ptr=(char *)gtk_widget_get_name(GTK_WIDGET(win));
	// If its an appwindow - we don't want to rename it..
	if (strcmp(ptr,"AppWindow")==0) return;

	gtk_widget_set_name(GTK_WIDGET(win), buff);
	x=gtk_object_get_data(GTK_OBJECT(win),"FIXED");
        if (x) {
		//printf("Set bkg on fixed too..\n");
		gtk_widget_set_name(GTK_WIDGET(x), buff);
	}
	x=gtk_object_get_data(GTK_OBJECT(win),"TOP");
        if (x) {
		//printf("Set bkg on top too..\n");
		gtk_widget_set_name(GTK_WIDGET(x), buff);
	}




}

int A4GL_LL_dump_screen(int n) {
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
 A4GL_LL_start_prompt (void *vprompt, int ap, int c, int h, int af,int curr_width,int iscurrborder)
{
  char *promptstr;
  int promptline;
  struct s_prompt *prompt;
  //void *sarr[3];
  void *p;
  //void *d;
  void *cw;
  struct s_form_dets fd;
  struct s_a4gl_gtk_form *f;
  int width;
  char buff[300];
  int a;
  int field_cnt = 0;
  //A4GL_chkwin ();
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

  cw=gtk_object_get_data (GTK_OBJECT (cw), "FIXED");
  if (cw==0) {
		printf("NO FIXED...\n");
  }

  if (UILIB_A4GL_iscurrborder ())
    promptline++;


  p=gtk_fixed_new();
  gtk_object_set_data(GTK_OBJECT(p),"FIXED",p);


#if GTK_CHECK_VERSION(2,0,0)
	gtk_fixed_set_has_window    (GTK_FIXED(p),1);
#endif
  gtk_widget_show(p);
  gtk_widget_set_usize (GTK_WIDGET (p), width*gui_xwidth, 1*gui_yheight);
  gtk_fixed_put(GTK_FIXED(cw),p,UILIB_A4GL_iscurrborder (),(promptline-1)*gui_yheight);

  if (p == 0)
    {
      A4GL_exitwith ("No prompt window created");
      return 0;
    }
  prompt->win = p;
  buff[width] = 0;
  //A4GL_wprintw (p, "%s", buff);
  promptstr = A4GL_char_pop ();
  prompt->mode = 0;
  prompt->h = h;
  prompt->insmode = 0;
  prompt->charmode = c;
  prompt->promptstr = promptstr;
  prompt->lastkey = 0;
  width -= strlen (promptstr);
  width--;
  memset(&fd,0,sizeof(struct s_form_dets));



  if (strlen (promptstr))
    {
	GtkWidget *evt;
	evt=gtk_event_box_new();
      	fd.form_fields[field_cnt++] = (void *) A4GL_LL_make_label (0, 0, promptstr);
	gtk_container_add(GTK_CONTAINER(evt),fd.form_fields[field_cnt-1]);
	gtk_widget_show(evt);
	gtk_misc_set_alignment(GTK_MISC(fd.form_fields[field_cnt-1]), 0.0f, 0.5f);
      	gtk_fixed_put (GTK_FIXED (p), evt,  0,0);
  	ap = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, ap, 0, 0);
  	if (ap)
    	{
      	A4GL_debug ("AP...");
      	if (strlen (promptstr))
        {
	  //printf("Setting attributes for prompt string %x %x\n",A4GL_LL_decode_aubit_attr (ap, 'f')>>8, A4GL_LL_decode_aubit_attr (ap, 'b')>>8);
//printf("SET FIELD FORE 4\n");
	
	  //printf("ap fore %x\n",A4GL_LL_decode_aubit_attr (ap, 'f'));
	  //printf("ap back %x\n",A4GL_LL_decode_aubit_attr (ap, 'b'));

          A4GL_LL_set_field_fore (fd.form_fields[0], A4GL_LL_decode_aubit_attr (ap, 'f'));
          A4GL_LL_set_field_back (evt, A4GL_LL_decode_aubit_attr (ap, 'b'));        
        } else {
  		A4GL_LL_set_field_back (fd.form_fields[0], A4GL_LL_colour_code (0));
  		A4GL_LL_set_field_fore (fd.form_fields[0], A4GL_LL_colour_code (7));

	}
    }

    }
  A4GL_debug ("Creating field %d %d %d", strlen (promptstr) + 1, 1, width - 1);
  A4GL_LL_set_new_page (fd.form_fields[field_cnt - 1], 1);

  fd.form_fields[field_cnt++] = (void *) A4GL_LL_make_field (0,0, strlen (promptstr), 1, width - 1);

  gtk_fixed_put (GTK_FIXED (p), fd.form_fields[field_cnt-1],  (strlen(promptstr)+1)*gui_xwidth,0);
  prompt->field = fd.form_fields[field_cnt - 1];

  //fd.form_fields[field_cnt++] = 0;        /* (void *) A4GL_make_label (0, strlen(promptstr)+width-1,"|"); */
  for (a=0;a<field_cnt;a++) {
		if (fd.form_fields[a]) gtk_widget_show(GTK_WIDGET(fd.form_fields[a]));
  }

  
  /* set_field_pad(fd.form_fields[1],' '); */
  A4GL_debug ("set field to =%p", prompt->field);
  A4GL_debug ("Field=%p", prompt->field);

   //A4GL_default_attributes (fd.form_fields[0], 0); 

  A4GL_default_attributes (prompt->field, 0);
  A4GL_debug ("STATIC OFF");
//printf("static off\n");

  //A4GL_field_opts_off (fd.form_fields[0], AUBIT_O_STATIC);


  A4GL_field_opts_off (prompt->field, AUBIT_O_STATIC);

  //printf ("ap=%d(%x) af=%d(%x)", ap, ap, af, af);
  af = A4GL_determine_attribute (FGL_CMD_INPUT, af, 0, 0);


  gtk_widget_show(prompt->field);

  //A4GL_LL_set_field_back (prompt->field, A4GL_LL_colour_code (0));
  //A4GL_LL_set_field_fore (prompt->field, A4GL_LL_colour_code (7));

  if (af)
    {
      A4GL_debug ("AF...");
      A4GL_LL_set_field_back (prompt->field, A4GL_LL_decode_aubit_attr (af, 'f'));
      A4GL_LL_set_field_fore (prompt->field, A4GL_LL_decode_aubit_attr (af, 'b'));      // maybe need 'B' for whole field..
      if (af & AUBIT_ATTR_INVISIBLE)
        {
          A4GL_debug ("Invisible");
printf("public off\n");
          A4GL_field_opts_off (prompt->field, AUBIT_O_PUBLIC);
        }

    }
  A4GL_field_opts_on (prompt->field, AUBIT_O_NULLOK);
  A4GL_debug ("Set attributes");

  buff[0] = 0;                  /* -2 */
  A4GL_debug ("Setting Buffer %p to '%s'", prompt->field, buff);
  A4GL_LL_set_field_buffer (prompt->field, 0, buff);
  A4GL_debug ("Set buffer ");

  //fd.form_fields[2] = 0;

  A4GL_debug ("Made fields");
  f = A4GL_LL_new_form (&fd);
  f->currentfield=f->nwidgets-1;
  A4GL_debug ("Form f = %p", f);
  prompt->f = f;
  A4GLSQL_set_status (0, 0);

  if (a4gl_status != 0)
    return (prompt->mode = 2);

  //d = derwin (p, 0, 0, width + 1, 1);
  //set_form_win (f, p);
  //set_form_sub (f, d);
  A4GL_debug ("Set form win");
  //a = post_form (f);
  A4GL_debug ("Posted form=%d", a);



  A4GL_LL_int_form_driver (f, AUBIT_REQ_FIRST_FIELD);
  A4GL_LL_int_form_driver (f, AUBIT_REQ_OVL_MODE);
  A4GLSQL_set_status (0, 0);
  A4GL_LL_screen_update ();
  return 1;
}



void A4GL_clear_prompt(struct s_prompt *prmt) {
	gtk_widget_destroy(prmt->win);
	A4GL_LL_screen_update();
}



/**
 * Implementaion in GTK GUI mode of the PROMPT 4gl statement.
 *
 * @param prompt A pointer to the prompt structure where the information about
 * it is stored.
 */
int
 A4GL_LL_prompt_loop (void *vprompt,int timeout,void *vevt)
{
  int a;
  void *p;
  int was_aborted = 0;
  int rblock;
  struct aclfgl_event_list *evt;

  void *mform;

  struct s_prompt *prompt;
  prompt = vprompt;
  evt=vevt;

  //A4GL_chkwin ();
  mform = prompt->f;

  A4GL_set_abort (0);

  p = prompt->win;

  if (prompt->mode == 1)
    {
      static char buff[10024];
      strcpy (buff, A4GL_LL_field_buffer (prompt->field, 0));
      A4GL_trim (buff);

      A4GL_push_char (buff);
      prompt->mode = 2;
      //unpost_form (prompt->f);
      A4GL_clear_prompt (prompt);
      return 0;
    }
  if (prompt->mode > 0)
    return 0;


      A4GL_LL_set_carat(prompt->f);
      A4GL_LL_screen_update ();
      abort_pressed = 0;
      was_aborted = 0;
      a = A4GL_LL_getch_swin (p);
      if (abort_pressed) prompt_last_key = -100;
      prompt->processed_onkey = a;
      A4GL_debug ("Read character... %d", a);
      A4GL_clr_error_nobox ("prompt");
      prompt_last_key = a;
      A4GL_set_last_key (a);
      prompt->lastkey = A4GL_get_lastkey ();
      rblock=A4GL_has_event_for_keypress(prompt->lastkey,evt);
      if (rblock) { // We appear to be all done here...
      		A4GL_push_null (DTYPE_CHAR, 1);
      		prompt->mode = 2;
      		A4GL_clear_prompt (prompt);
                return rblock;
      }





  a = A4GL_proc_key_prompt (a, mform, prompt);


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


/**
 * Set the GUI prompt style.
 *
 * @param a The prompt style
 */
void A4GL_gui_prompt_style (int a)
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
void* A4GL_LL_display_form(void * fd,int attrib,int curr_width,int curr_height,int iscurrborder) {
  struct s_form_dets *f;
 
  int rows, cols;
int b;
  char buff[80];
  int a;
  //int nattr;
  GtkWidget *w;
  GtkWidget *drwin;
  GtkFixed *cwin;
  int x,y;


  int fl;
struct s_a4gl_gtk_form *form;
GtkWidget *labwidget;
		char buff_label[50];

  //A4GL_chkwin ();
  f=fd;
  form=f->form;

  A4GL_debug ("In display_form");


  w = (GtkWidget *)A4GL_get_currwin ();
  cwin=gtk_object_get_data (GTK_OBJECT (w), "FIXED");

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
	for (x=0;x<255;x++) {
      		sprintf (buff_label, "LABEL_%d_%d", x, a);
		labwidget=gtk_object_get_data(GTK_OBJECT(w),buff_label);
		if (labwidget) {
			gtk_widget_destroy(labwidget);
		}
	}
    }
  drwin= gtk_object_get_data(GTK_OBJECT(cwin),"FORMWINDOW");
  if (drwin) {
		gtk_widget_destroy(drwin);
		drwin=0;
  }
  A4GL_LL_scale_form (f, &rows, &cols);
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

  if (form->notebook) {
	drwin=form->notebook;
  } else {
  	drwin=gtk_fixed_new();
  }

  if (UILIB_A4GL_iscurrborder ())
    {
	gtk_fixed_put(cwin,drwin,1,(fl+1)*gui_yheight);
    }
  else
    {
	gtk_fixed_put(cwin,drwin,0,(fl-1)*gui_yheight);
      //A4GL_debug ("MJAPASS2 rows=%d cols=%d fl=%d", rows, cols, fl);
      //drwin = derwin (panel_window ((PANEL *) w), rows, cols, fl - 1, 0);
    }


  gtk_object_set_data(GTK_OBJECT(cwin),"FORMWINDOW",(void *)drwin);
  gtk_object_set_data(GTK_OBJECT(drwin),"FIXED",(void *)drwin);

  A4GL_start_form (f);
  A4GL_clr_form (0);
  A4GL_debug ("And return");
  A4GL_LL_screen_update ();
  if (!form->notebook) {
  for (a=0;a<form->nwidgets;a++) {
	if (gtk_object_get_data(GTK_OBJECT(form->widgets[a]),"MF_ISLABEL"))  {
		char *ptr;
        	x=(int)gtk_object_get_data(GTK_OBJECT(form->widgets[a]),"MF_FCOL")+1;
        	y=(int)gtk_object_get_data(GTK_OBJECT(form->widgets[a]),"MF_FROW")+1;
		ptr=gtk_object_get_data(GTK_OBJECT(form->widgets[a]),"MF_LABELSTR");
		//printf("Label : '%s'\n",ptr);
		if (strlen(ptr)) {
		for (b=0;b<strlen(ptr);b++) {
			int c;
			c=ptr[b]&0xff;
			//printf("%p %d %d=%d\n",drwin,x+b,y,c);
			A4GL_LL_wadd_char_xy_col(drwin,x+b,y,c,curr_width,curr_height,iscurrborder) ;
		}
		}

	} else {
        	x=(int)gtk_object_get_data(GTK_OBJECT(form->widgets[a]),"MF_FCOL")*gui_xwidth;
        	y=(int)gtk_object_get_data(GTK_OBJECT(form->widgets[a]),"MF_FROW")*gui_yheight;
		gtk_fixed_put(GTK_FIXED(drwin),form->widgets[a],x,y);
		gtk_widget_ref(form->widgets[a]);
	}
	gtk_widget_show(form->widgets[a]);
  
  gtk_widget_show(drwin);
  }
 }
//printf("Displayed form..\n");

  return drwin;
}

void A4GL_LL_scale_form(void* vfd,int* y,int* x) {
struct s_a4gl_gtk_form *form;
struct s_form_dets *fd;
GtkWidget *widget;
int a;
int max_x=0;
int max_y=0;
int wx,wy,ww,wh;
fd=vfd;


form=fd->form;

if (form->frmMagic!=0xABC123) {
	char *ptr=0;
	
	A4GL_exitwith("INTERNAL ERROR BAD FORM");
	printf("BAD FORM DETECTED\n");
	*ptr=0;
	exit(0);
}


for (a=0;a<form->nwidgets;a++) {
	widget=form->widgets[a];
	wx=(int)gtk_object_get_data(GTK_OBJECT(widget),"MF_FCOL");
	wy=(int)gtk_object_get_data(GTK_OBJECT(widget),"MF_FROW");
	if (gtk_object_get_data(GTK_OBJECT(widget),"MF_ISLABEL")) {
		ww=strlen((char *)gtk_object_get_data(GTK_OBJECT(widget),"MF_LABELSTR"));
		wh=1;
	} else {
		ww=(int)gtk_object_get_data(GTK_OBJECT(widget),"MF_COLS");
		wh=(int)gtk_object_get_data(GTK_OBJECT(widget),"MF_ROWS");
	}
	wx+=ww;
	wy+=wh;
	if (wx>max_x) max_x=wx;
	if (wy>max_y) max_y=wy;
	
}
*y=max_y;
*x=max_x;

//printf("Sized form to %d,%d\n",*x,*y);
}


int A4GL_LL_form_page(void* vform) {
//struct s_a4gl_gtk_form *form;
	return 1;
}



int A4GL_LL_get_carat(void* vform) {
struct s_a4gl_gtk_form *form;
form=vform;

return form->curcol;
}


void* A4GL_LL_make_field(void *prop,int frow,int fcol,int rows,int cols) {
  struct struct_scr_field *fprop;
  void *widget;
  char *widget_str;
  char *config_str;
  fprop=prop;

  if (fprop) {
    widget_str=A4GL_decode_str_fprop (fprop, FA_S_WIDGET);
    if (strlen(widget_str)==0)
      widget_str="ENTRY";
    config_str=A4GL_decode_str_fprop(fprop,FA_S_CONFIG);
  } else {
    widget_str="ENTRY";
    config_str="";
  }

  widget=(void *)A4GL_make_widget (widget_str, config_str, cols);
  if (widget==0) {
	// Ooops - didn't make a widget...
  	widget=(void *)A4GL_make_widget ("ENTRY", "", cols);
	printf("WARNING - Coulnd't make widget as %s %s, made an entry field instead\n",widget_str, config_str);
  	if (widget==0) { // Couldn't even fake one..
		A4GL_assertion(1,"Failed to make a widget");
	}
  }
  A4GL_LL_set_field_opts (widget, 0);

  gtk_object_set_data(GTK_OBJECT(widget),"Attribute",(void *)fprop);
  gtk_object_set_data(GTK_OBJECT(widget),"MF_FROW",(void *)frow);
  gtk_object_set_data(GTK_OBJECT(widget),"MF_FCOL",(void *)fcol);
  gtk_object_set_data(GTK_OBJECT(widget),"MF_ROWS",(void *)rows);
  gtk_object_set_data(GTK_OBJECT(widget),"MF_COLS",(void *)cols);
  gtk_object_set_data(GTK_OBJECT(widget),"MF_ISLABEL",(void *)0);

  if(strcasecmp("LABEL", widget_str)==0) {
    gtk_object_set_data(GTK_OBJECT(widget),"DISPLAY_LABEL",(void *)1);
    gtk_widget_set_name(GTK_WIDGET(widget), "AppWindow");
	#if GTK_CHECK_VERSION(2,0,0)	
    if(A4GL_isyes(acl_getenv("A4GL_USE_PANGO_ML")))
      gtk_label_set_use_markup(GTK_LABEL(widget), TRUE);
	#endif
  }

  return widget;
}

void* A4GL_LL_make_label(int frow,int fcol,char* label) {
GtkWidget *widget=0;
char *label_utf;


if (strcmp(label,"[")==0) return 0;
if (strcmp(label,"]")==0) return 0;



label_utf=g_locale_to_utf8(label, -1, NULL, NULL, NULL);
widget=gtk_label_new(label_utf);

//printf("Making label : %s\n",label);
#if GTK_CHECK_VERSION(2,0,0)
if(A4GL_isyes(acl_getenv("A4GL_USE_PANGO_ML"))) {
  	A4GL_debug("using PANGO ML for Label '%s'\n",label);
  	gtk_label_set_use_markup(GTK_LABEL(widget), TRUE);
}
#endif
g_free(label_utf);


gtk_widget_set_name(GTK_WIDGET(widget), "FormLabel");

gtk_object_set_data(GTK_OBJECT(widget),"MF_FROW",(void *)frow);
gtk_object_set_data(GTK_OBJECT(widget),"MF_FCOL",(void *)fcol);
gtk_object_set_data(GTK_OBJECT(widget),"MF_ISLABEL",(void *)1);
gtk_object_set_data(GTK_OBJECT(widget),"MF_LABELSTR",strdup(label));
//printf("Made label %p - %s\n",widget,label);
return widget;

}


void A4GL_LL_set_carat(void* vform) {
struct s_a4gl_gtk_form *form;
char *s;
GtkWidget *w;
form=vform;
//printf("SET FOCUS %p\n",form->widgets[form->currentfield]);
//printf("current field = %d\n",form->currentfield);
w=form->widgets[form->currentfield];
//printf("w=%p\n",w);

gtk_widget_grab_focus (GTK_WIDGET (w));
//printf("Grabbed focus\n");
s=gtk_object_get_data(GTK_OBJECT(w),"WIDGETSNAME");

//printf("set_carat - %s\n",s);
if (s) {
if (strcmp(s,"ENTRY")==0) {
	gtk_editable_set_position(GTK_EDITABLE(form->widgets[form->currentfield]),form->curcol);
}
}
}


void A4GL_LL_set_field_buffer(void* field,int n,char* str) {
//printf("set_Field_buffer...\n");
A4GL_display_generic (field, str);
}

void A4GL_LL_set_form_page(void* vform,int page) {
//struct s_a4gl_gtk_form *form;
}

void* A4GL_LL_new_form(void* vfd) {
struct s_form_dets *fd;
struct s_a4gl_gtk_form *form;
int a;

/*
        int nwidgets;
        int npages;
        int currentpage;
        GtkWidget *currentfield;
        GtkWidget **widgets;
        GtkWidget *notebook;
        void *userptr;
*/

fd=vfd;
form=malloc(sizeof(struct s_a4gl_gtk_form));

/* Set everything up.. */
form->frmMagic=0xABC123;
form->nwidgets=0;
form->npages=1;
form->currentpage=1;
form->curcol=0;
form->currentfield=0;
form->widgets=0;
form->notebook=0;
form->userptr=0;

//printf("fd->form_Fields[0]=%d\n",fd->form_fields[0]);
//printf("fd->form_Fields[1]=%d\n",fd->form_fields[1]);

for (a=0;fd->form_fields[a];a++)  {
	if (gtk_object_get_data(GTK_OBJECT(fd->form_fields[a]),"NEWPAGE")) form->npages++;
}

//printf("%d widgets detected on %d pages\n",a,form->npages);

form->nwidgets=a;
form->widgets=malloc(sizeof(void *)*a);

if (form->npages>1) {
	form->notebook = gtk_notebook_new ();
	gtk_widget_show (form->notebook);
} else {
	form->notebook=0;
}

//printf("Making form notebook=%p\n",form->notebook);
for (a=0;fd->form_fields[a];a++)  {
	form->widgets[a]=fd->form_fields[a];
        A4GL_gui_set_active (form->widgets[a],0);
}
return form;
}


int A4GL_LL_int_form_driver(void* vform,int mode) {
struct s_a4gl_gtk_form *form;
GtkWidget *cwidget;
int a=0;
form=vform;
cwidget=form->widgets[form->currentfield];

//printf("FORM DRIVER : %p - %x\n",form,mode);
if (mode<=255 && a_isprint(mode) && mode >=' ') {
	gint iopos;
	char buff[2];
	char *utf;
	buff[0]=mode;
	buff[1]=0;
	utf=g_locale_to_utf8(buff, -1, NULL, NULL, NULL);
	// printf(" - CHAR (%c) - %s (UTF: %s)\n",mode,buff,utf);
	if (form->ovlins==1) {
		// printf("Insert mode - insert (%c) at %d\n", mode, form->curcol);
		iopos=form->curcol;
		gtk_editable_insert_text(GTK_EDITABLE(cwidget), utf, strlen(utf), &iopos);
		form->curcol++;
		//form->curcol+=strlen(utf);
		// printf("curcol now : %d\n",form->curcol);
	} else {
		// printf("overwrite mode - overwrite (%c) at %d\n", mode, form->curcol);
		gtk_editable_delete_text(GTK_EDITABLE(cwidget),form->curcol,form->curcol+1);
		iopos=form->curcol;
		gtk_editable_insert_text(GTK_EDITABLE(cwidget), utf, strlen(utf), &iopos);
		form->curcol++;
		//form->curcol+=strlen(utf);
		// printf("curcol now : %d\n",form->curcol);
	}
	g_free(utf);
} else {
	switch (mode) {
		case AUBIT_REQ_BEG_FIELD: 
				form->curcol=0;
				break;

		case AUBIT_REQ_END_FIELD:
				{	
				char *x=g_locale_from_utf8(gtk_entry_get_text(GTK_ENTRY(cwidget)), -1, NULL, NULL, NULL);
				A4GL_trim(x);
				form->curcol=strlen(x); 
				g_free(x);
				}
				break;


		case AUBIT_REQ_CLR_EOF: 
				gtk_editable_delete_text(GTK_EDITABLE(cwidget),form->curcol,-1);
				break;


		case AUBIT_REQ_CLR_FIELD: 
				//printf("CLEAR FIELD\n");
				gtk_editable_delete_text(GTK_EDITABLE(cwidget),0,-1);
				break;


		case AUBIT_REQ_DEL_CHAR: 
				//printf("DEL CHAR\n");
				gtk_editable_delete_text(GTK_EDITABLE(cwidget),form->curcol,form->curcol+1);
				break;


		case AUBIT_REQ_DEL_PREV:
				//printf("DEL PREV\n");
                                if(form->curcol>0) {
                                  gtk_editable_delete_text(GTK_EDITABLE(cwidget),form->curcol-1,form->curcol);
                                  form->curcol--;
                                }
				break;

		case AUBIT_REQ_FIRST_FIELD: 
				for (a=0;a<form->nwidgets;a++) {
					cwidget=form->widgets[a];
					if (gtk_object_get_data(GTK_OBJECT(cwidget),"MF_ISLABEL")) continue;
					form->currentfield=a;
					break;
				}
				break;
		


		case AUBIT_REQ_FIRST_PAGE: 
				break;
	

		case AUBIT_REQ_INS_MODE: 
				form->ovlins=1;
				break;


		case AUBIT_REQ_NEXT_CHAR:
				form->curcol++;
				break;


		case AUBIT_REQ_OVL_MODE: 
				form->ovlins=0;
				break;


		case AUBIT_REQ_PREV_CHAR: 
				form->curcol--;
				if (form->curcol<0) form->curcol=0;
				break;


		case AUBIT_REQ_VALIDATION: 
			//printf("REQ_VALIDATION\n"); 
			break;


	default: 
		if (mode>255) {
			printf("Unknown mode : %d\n",mode);
			{char *ptr=0; *ptr=0;}
		}
	}
}
return 0;
}


void A4GL_LL_set_field_attr(void* field) {
  struct struct_scr_field *f;

  f = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (field));
  if (f == 0) return;

  A4GL_debug ("Setting defs");


//printf("set_field_attr..\n");
  A4GL_default_attributes (field, f->datatype);
//printf("Done\n");


  A4GL_debug ("Set defs");

  if (A4GL_has_bool_attribute (f, FA_B_AUTONEXT))
    {
      A4GL_debug ("Autoskip");
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_field_opts_on (field, AUBIT_O_AUTOSKIP);
    }

  if (A4GL_has_bool_attribute (f, FA_B_INVISIBLE))
    {
      A4GL_debug ("Invisible ***");
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_field_opts_off (field, AUBIT_O_PUBLIC);
    }

  if (f->dynamic != 0)
    {
      A4GL_debug ("ZZZZ - SET OPTS STATIC OFF");
      A4GL_field_opts_off (field, AUBIT_O_STATIC);

      if (f->dynamic == -1)
        {
          A4GL_LL_set_max_field (field, 0);
        }
      else
        {
          A4GL_LL_set_max_field (field, f->dynamic);
        }

    }
  else
    {
      A4GL_field_opts_on (field, AUBIT_O_STATIC);
    }

/*
  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY))
    {
      A4GL_debug ("No entry");
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_field_opts_off (field, AUBIT_O_ACTIVE);
      A4GL_field_opts_off (field, AUBIT_O_EDIT);
    }
*/
  if (A4GL_has_bool_attribute (f, FA_B_REQUIRED))
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_field_opts_off (field, AUBIT_O_NULLOK);
    }
  else
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_field_opts_on (field, AUBIT_O_NULLOK);
    }

  if (A4GL_has_bool_attribute (f, FA_B_COMPRESS))
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      A4GL_field_opts_on (field, AUBIT_O_WRAP);
    }
}


#include <sys/timeb.h>



void tstamp(char *s) {
static FILE *ts=0;
static double ltime=0;
static double lltime=0;
double ntime=0;
struct timeb tp;
return;

ftime(&tp);
ntime=(double)tp.time;
ntime=ntime+(double)tp.millitm/1000.0;

if (ts==0) {
	ts=fopen("timings.out","w");
}
if (ts==0) return;

if (strcmp(s,"START")==0) {
	ltime=ntime;
	lltime=ntime;
	return;
}
fprintf(ts,"%s Since START %f Since Last TS %f\n",s,ntime-ltime,ntime-lltime);
lltime=ntime;
}




int A4GL_LL_endis_fields_ap (int en_dis, void* vap)
{
  GtkWidget *formdets;
  int a;
  va_list *ap;
  int nofields;
  GtkWidget **field_list;  
ap=vap;
  formdets = A4GL_get_curr_form (1);


  A4GL_debug ("Formdets = %p\n", formdets);

  nofields =
    A4GL_gen_field_list ((void *)&field_list, (void*) formdets, 9999, ap);
  A4GL_debug ("nofields=%d\n", nofields);

  for (a = 0; a <= nofields; a++)
    {
      A4GL_debug ("Doing something to %p %d\n", field_list[a], en_dis);
      A4GL_gui_set_active (field_list[a], en_dis);
    }
return 1;
}



int A4GL_LL_open_gui_form (char *name_orig, int absolute, int nat, char *like, int disable, void *handler_e, void *phandler_c) {
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
  w=malloc(sizeof(struct s_windows));

  handler_c=phandler_c;

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


  gtk_signal_connect (GTK_OBJECT (win), "delete_event", GTK_SIGNAL_FUNC (handler_e), win);
  gtk_signal_connect (GTK_OBJECT (win), "destroy", GTK_SIGNAL_FUNC (handler_e), win);
  //gtk_signal_connect (GTK_OBJECT (win), "focus_in_event", GTK_SIGNAL_FUNC (handler_e), win);

  form_dets = A4GL_read_form (formname, "uhmmm");

  w=(struct s_window *)A4GL_add_window(0,0,0,0,formname,form_dets, win);
  A4GL_win_stack((void *)w,'+');
  if (form_dets == 0)
    {
      A4GL_exitwith ("Unable to open form");
      return 0;
    }

  gtk_f=A4GL_LL_new_form(form_dets);

  for (a=0;a<gtk_f->nwidgets;a++) {
		int x,y;
                x=(int)gtk_object_get_data(GTK_OBJECT(gtk_f->widgets[a]),"MF_FCOL")*gui_xwidth;
                y=(int)gtk_object_get_data(GTK_OBJECT(gtk_f->widgets[a]),"MF_FROW")*gui_yheight;
                gtk_fixed_put(GTK_FIXED(fixed),gtk_f->widgets[a],x,y);
      		gtk_object_set_data (GTK_OBJECT(gtk_f->widgets[a]), "HANDLER", (void *)handler_c);
                gtk_widget_ref(gtk_f->widgets[a]);
        	gtk_widget_show(gtk_f->widgets[a]);
  }
  



  gtk_widget_show_all (GTK_WIDGET (win));
  //gtk_widget_show (GTK_WIDGET (win));
  handler_c (0, 0);
  gtk_widget_show (GTK_WIDGET (win));
  return 1;
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
find_curr_window(void)
{
void *w;
        w=(void *)A4GL_get_currwin();
        if (gtk_object_get_data(w,"TOP")) {
                A4GL_debug("Has parent...");
                w=gtk_object_get_data(w,"TOP");
        }
        return w;
}

int A4GL_LL_set_window_title(int nargs) {
static char *_functionName = "set_window_title";
   char s [256+1];
   struct BINDING fbind[1]={ /* print_param */
   {&s,0,256}
   }; /* end of binding */
   char *_paramnames[1]={
   "s"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {a4gl_status=-30174;A4GL_pop_args(nargs);return 0;}
   {
   A4GL_setnull(0,&s,256);
   }
   A4GL_pop_params(fbind,1);
        A4GL_trim(s);
        gtk_window_set_title(GTK_WINDOW(find_curr_window()),s);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}




int A4GL_LL_widget_name_match(void* wv,char* name) {

GtkWidget * w;
  void *s;
w=wv;
  if (w == 0) return 0;
//printf("widget name match : %s\n",name);
  s = gtk_object_get_data (GTK_OBJECT (w), "Attribute");
  if (s == 0) {
	//printf("No attribute\n");
    return 0;
  }
  return A4GL_attr_name_match (s, name);

}




int A4GL_LL_fieldnametoid(char* f,char* s,int n) {
  GtkWidget *formdets;
  GtkWidget *w;
  int nofields;
  GtkWidget **field_list = 0;


  A4GL_debug ("fgl_fieldnametoid (%p,%d)", s, n);


  formdets = (GtkWidget *) UILIB_A4GL_get_curr_form (1);
  A4GL_debug ("Getting field list formdets=%p parent=%p", formdets,
         gtk_object_get_data ((GtkObject *) formdets, "PARENT"));

  /* debug("Getting field list formdets=%p parent=%p",formdets,gtk_object_get_data(formdets,"TOP")); */


  //A4GL_exitwith ("serious bug in widget.c");

  nofields = A4GL_gen_field_chars ( (void *)&field_list, (GtkWindow *) formdets, s, n, 0);

  A4GL_debug ("done Getting field list - nofields=%d", nofields);

  if (nofields != -1)
    w = field_list[0];
  else
    w = 0;
  A4GL_debug ("field_list=%p\n", field_list);
  free (field_list);
  return (int) w;
}

void A4GL_LL_clr_form_fields(int to_defaults,char* defs) {
return ;
}


int A4GL_LL_disp_form_field_ap(int n,int attr,char* s,va_list* ap) {
  int a;
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

  formdets = (struct s_form_dets *)A4GL_find_form_for_win(w);

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


/*
** orig     = original string
** evt      = original event list from contruct..
** init_key = initial keystroke that caused us to be here.. (0 for before field)
** init_pos = position in field as retrived from the original field..
*/
int A4GL_LL_construct_large(char *orig, void *vevt,int init_key,int initpos,char *l,char *r,int curr_width,int curr_height,int fl) {
        static char rbuff[1024];
        //static char rbuff2[1024];
	struct s_form_dets fd;
        void  *cwin;
        GtkWidget *drwin;
	GtkWidget *v;
        struct s_a4gl_gtk_form *f;


        int ins_ovl='o';
        int looping=1;
        //int fl=0; // comment line...
        int fwidth;
        int a;
	struct aclfgl_event_list *evt;
			evt=vevt;
        A4GL_debug("In construct_large");

        strcpy(rbuff,orig);

        fwidth=UILIB_A4GL_get_curr_width ();
        if (fwidth>80) fwidth=80;
        cwin =  (void *)A4GL_get_currwin ();
        //fl = A4GL_getcomment_line ();
        if (fl > UILIB_A4GL_get_curr_height ()) fl = UILIB_A4GL_get_curr_height ();
	drwin=gtk_fixed_new();
	v=gtk_hbox_new(0,1);
//printf("Making fields\n");


        fd.form_fields[0]=gtk_label_new("[");
        fd.form_fields[1]=A4GL_LL_make_field(0,0,0,0,fwidth); // gtk_entry_new();

        fd.form_fields[2]=gtk_label_new("]");
	fd.form_fields[3]=0;

	gtk_object_set_data(GTK_OBJECT(fd.form_fields[0]),"WIDGETSNAME","LABEL");
        A4GL_field_opts_on (fd.form_fields[1], AUBIT_O_ACTIVE);
        A4GL_field_opts_on (fd.form_fields[1], AUBIT_O_EDIT);
        A4GL_field_opts_on (fd.form_fields[1], AUBIT_O_BLANK);
	gtk_object_set_data(GTK_OBJECT(fd.form_fields[1]),"WIDGETSNAME",(void *)"ENTRY");
	gtk_object_set_data(GTK_OBJECT(fd.form_fields[2]),"WIDGETSNAME",(void *)"LABEL");
	gtk_widget_show(fd.form_fields[0]);
	gtk_widget_show(fd.form_fields[1]);
	gtk_widget_show(fd.form_fields[2]);



  	//A4GL_default_attributes (fd.form_fields[1], 0);
  	//A4GL_add_signal_changed (fd.form_fields[1], 0);
  	//A4GL_add_signal_grab_focus (fd.form_fields[1], 0);
	//A4GL_field_opts_off (fd.form_fields[1], AUBIT_O_STATIC);


////printf("All done..");
//printf("Add to container b0=%p b1=%p b2=%p v=%p\n",fd.form_fields[0],fd.form_fields[1],fd.form_fields[2],v);
        f=A4GL_LL_new_form(&fd);
	
  	f->currentfield=1;
        A4GL_mja_set_field_buffer(fd.form_fields[1],0,rbuff);

	gtk_container_add(GTK_CONTAINER(v),fd.form_fields[0]);
	gtk_container_add(GTK_CONTAINER(v),fd.form_fields[1]);
	gtk_container_add(GTK_CONTAINER(v),fd.form_fields[2]);

	gtk_widget_set_sensitive(fd.form_fields[0],1);
	gtk_widget_set_sensitive(fd.form_fields[1],1);
	gtk_widget_set_sensitive(fd.form_fields[2],1);
  	cwin=gtk_object_get_data (GTK_OBJECT (cwin), "FIXED");
        gtk_fixed_put(GTK_FIXED(cwin),GTK_WIDGET(drwin),0,(fl)*gui_yheight);
	gtk_fixed_put(GTK_FIXED(drwin),GTK_WIDGET(v),0,0);

	gtk_widget_show_all(drwin);

//printf("Add vbox to fixed..");
        A4GL_LL_screen_update();

        A4GL_LL_int_form_driver(f,AUBIT_REQ_OVL_MODE);

        if (initpos) {
                //for (a=0;a<=initpos;a++) {
                        //A4GL_LL_int_form_driver(f,AUBIT_REQ_NEXT_CHAR);
                //}
		//printf("Go to end of field...\n");
                A4GL_LL_int_form_driver(f,AUBIT_REQ_END_FIELD);
		//printf("done\n");
        }

        a=0;

        while (looping) {
		//printf("call set carat\n"); fflush(stdout);
                A4GL_LL_set_carat(f);
                A4GL_LL_screen_update();
		//printf("call getch\n"); fflush(stdout);
                a=A4GL_LL_getch_swin (cwin);

                if (abort_pressed) break;
                if (A4GL_has_event_for_keypress(a,evt)) return a;



                switch (a) {

                        case 1:
                                if (ins_ovl=='o') {
                                        ins_ovl='i';
                                        A4GL_LL_int_form_driver(f,AUBIT_REQ_INS_MODE);
                                } else {
                                        ins_ovl='o';
                                        A4GL_LL_int_form_driver(f,AUBIT_REQ_OVL_MODE);
                                }

				break;


			case 4:
                                        A4GL_LL_int_form_driver(f,AUBIT_REQ_CLR_EOF);
				break;

                        case 27:
                        case A4GLKEY_DOWN:
                        case A4GLKEY_UP:
                        case A4GLKEY_ENTER:
                        case '\t': looping=0; break;

                        case A4GLKEY_LEFT:
                                if (A4GL_LL_get_carat(f)==0)  {looping=0;break;}
                                A4GL_LL_int_form_driver (f, AUBIT_REQ_PREV_CHAR);
                                break;


                        case 127:
                        case 8:
                        case A4GLKEY_DC:
                        case A4GLKEY_DL:
                        case A4GLKEY_BACKSPACE: A4GL_LL_int_form_driver (f, AUBIT_REQ_DEL_PREV); break;

                        case 24:                A4GL_LL_int_form_driver (f, AUBIT_REQ_DEL_CHAR);break;
                        case A4GLKEY_RIGHT:     A4GL_LL_int_form_driver (f, AUBIT_REQ_NEXT_CHAR);break;
                        default :            if (isprint(a) && a>=30&&a<=255)  {A4GL_LL_int_form_driver (f, a); }     break;
                }

        }
        A4GL_LL_int_form_driver(f,AUBIT_REQ_VALIDATION);
        strcpy(orig,A4GL_LL_field_buffer(fd.form_fields[1],0));

        A4GL_debug("Unpost and delete...");
		gtk_widget_destroy(drwin);
        A4GL_LL_screen_update();
        A4GL_comments(0);
        return a;
}




int A4GL_LL_disp_form_fields_ap(int n,int attr,char* formname,va_list* ap) {
  return 0;
}





int menu_callback (gpointer data) {
  //int nbutton;
  //A4GL_debug("Widget=%p data=%d\n",widget,data);
  //nbutton=(int)gtk_object_get_data(GTK_OBJECT(widget),"BUTTON");
  menu_response=(int)data;

  A4GL_clr_error_nobox ("menu_callback");

  keybuffer_cnt=0; /* throw away buffered keys when menuoption is selected */
  return TRUE;
}


int A4GL_LL_hide_h_menu(ACL_Menu *menu) {
  GtkWidget *bb;
  //printf("hide_h_menu\n");
  bb=gtk_object_get_data(GTK_OBJECT(win_screen),"BB");
  if (bb==0) return 0;
  gtk_widget_hide(bb);
  return 1;
}


static int A4GL_show_ok_cancel(int n) {
  GtkWidget *bb;
  if (n) { 
	//printf("SHOWING OK CANCEL\n");
  	bb=gtk_object_get_data(GTK_OBJECT(win_screen),"OKCANCEL");
  	if (bb==0) return 0;
  	gtk_widget_show(bb);
  	bb=gtk_object_get_data(GTK_OBJECT(win_screen),"BB");
  	if (bb==0) return 0;
  	gtk_widget_hide(bb);
  } else { 
  	bb=gtk_object_get_data(GTK_OBJECT(win_screen),"OKCANCEL");
  	if (bb==0) return 0;
  	gtk_widget_hide(bb);
  	bb=gtk_object_get_data(GTK_OBJECT(win_screen),"BB");
  	if (bb==0) return 0;
  	gtk_widget_show(bb);
  }
  return 1;
}


int A4GL_LL_disp_h_menu( ACL_Menu *menu) {
  GtkWidget *bb;
  int nbuttons;
  int a;
  char buff[255];
  ACL_Menu_Opts *mo;
  
  if (A4GL_isyes(acl_getenv("TRADMENU")))
    return 0;

  bb=gtk_object_get_data(GTK_OBJECT(win_screen),"BB");
  if (bb==0)
    return 0;

  gtk_widget_show(bb);
  nbuttons=(int)gtk_object_get_data(GTK_OBJECT(bb),"NBUTTONS");

  while (nbuttons<menu->num_opts) {
    GtkWidget *b;
    GtkWidget *l;
    sprintf(buff,"BUTTON_%d",nbuttons);
    l=gtk_label_new(" ");
    b=gtk_button_new();
    gtk_container_add(GTK_CONTAINER(b),l);
    gtk_widget_set_name(GTK_WIDGET(b), "MenuButtons");
    gtk_object_set_data(GTK_OBJECT(b),"LABEL",l);

    gtk_signal_connect_object (GTK_OBJECT (b), "clicked", GTK_SIGNAL_FUNC (menu_callback), (void *)nbuttons);
    gtk_widget_show(b);
    gtk_widget_show(l);
    gtk_object_set_data(GTK_OBJECT(bb),buff,b);
    gtk_object_set_data(GTK_OBJECT(b),"BUTTON",(void *)nbuttons++);
    gtk_object_set_data(GTK_OBJECT(b),"OPT",0);
    gtk_object_set_data(GTK_OBJECT(bb),"NBUTTONS",(void *)nbuttons);
    gtk_object_set_data(GTK_OBJECT(bb),"NBUTTONS",(void *)nbuttons);
    gtk_container_add(GTK_CONTAINER(bb),b);
  }

  mo=menu->first;

  for (a=0;a<nbuttons;a++) {
    GtkWidget *b;
    GtkWidget *l=0;
    sprintf(buff,"BUTTON_%d",a);
    b=gtk_object_get_data(GTK_OBJECT(bb),buff);
	#if GTK_CHECK_VERSION(2,0,0)	
    	gtk_button_set_use_stock(GTK_BUTTON(b),0);
	#endif
    if (a>=menu->num_opts) {
      gtk_widget_hide(b);
    } else {
#if GTK_CHECK_VERSION(2,0,0)
	//printf("'%s'\n",mo->opt_title);
	if (has_stock_item(mo->opt_title)) {
		gtk_button_set_label(GTK_BUTTON(b),stock_item(mo->opt_title));
    		gtk_button_set_use_stock(GTK_BUTTON(b),1);
	} else {
      		char *label_utf=g_locale_to_utf8(mo->opt_title, -1, NULL, NULL, NULL);
      		l= gtk_object_get_data(GTK_OBJECT(b),"LABEL");
			gtk_label_set_text(GTK_LABEL(l), label_utf);
      		//gtk_button_set_label(GTK_BUTTON(b), label_utf);
      		g_free(label_utf);
	}
#else
	//printf("OLD LABEL: %s\n",mo->opt_title);
	gtk_label_set_text(GTK_LABEL(l), mo->opt_title);
#endif
      if (mo->attributes & ACL_MN_HIDE)
        gtk_widget_hide(b);
      else
        gtk_widget_show(b);
      mo=mo->next_option;
    }
  }
  A4GL_LL_screen_update();
  return 1;
}




int A4GL_LL_menu_loop(ACL_Menu *menu) {

  int key;

  A4GL_LL_disp_h_menu(menu);

  if (A4GL_isyes(acl_getenv("TRADMENU")))
    return -1;

  menu_response=-1;

  while (menu_response==-1) {
    A4GL_LL_screen_update();

    if((key=get_keypress_from_buffer())>0) { /* key pressed: */
      ACL_Menu_Opts *f=menu->first; 
      int res=0;
	A4GL_clr_error_nobox ("gtkmenu");
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
      if(menu_response>=0)
        break;
    }
  }

  A4GL_LL_hide_h_menu(menu);
  return menu_response;
}




void A4GL_LL_wadd_char_xy_col_w (void *win, int x, int y, int ch,int curr_width,int curr_height,int iscurrborder) {
	A4GL_assertion(1,"Not implemented A4GL_LL_wadd_char_xy_col_w");
}




void A4GL_LL_clr_menu_disp (ACL_Menu * menu,int curr_width,void *cw)
{
  static char buff[1025];
  int off;
  int w;
  //void *cw;
  int y;

	if (A4GL_isyes(acl_getenv("TRADMENU"))) {

  A4GL_debug ("Clearing menu clr_menu_disp - %p",menu);
  memset (buff, ' ', 1023);
  buff[1024]=0;

  w=curr_width;
  off=menu->menu_offset;
  buff[w - off + 1] = 0;
  y=menu->gw_y;
  A4GL_wprintw (cw, 0, off - 1, y, buff);
  }
}


void
A4GL_LL_h_disp_title (ACL_Menu * menu, char *str,void *cw)
{

if (A4GL_isyes(acl_getenv("TRADMENU"))) {
        A4GL_wprintw (cw, 0, 1, menu->gw_y, "%s", str);
}


}



static char A4GL_menu_pos(void) {
static char pos=0;
char *c;
if (pos==0)  {
	if (A4GL_isyes(acl_getenv("MENUTOP")))     {pos='T'; return pos;}
	if (A4GL_isyes(acl_getenv("MENUBOTTOM")))  {pos= 'B'; return pos;}
	if (A4GL_isyes(acl_getenv("MENULEFT")))    {pos= 'L'; return pos;}
	if (A4GL_isyes(acl_getenv("MENURIGHT")))   {pos= 'R'; return pos;}
	c=acl_getenv("MENUPOSITION");
	if (c==0) {pos= 'R'; return pos;}
	if (strlen(c)==0) {pos= 'R'; return pos;}
	if (toupper(c[0])=='T') {pos= 'T'; return pos;}
	if (toupper(c[0])=='L') {pos= 'L'; return pos;}
	if (toupper(c[0])=='B') {pos= 'B'; return pos;}
	if (toupper(c[0])=='R') {pos= 'R'; return pos;}
	pos='R'; 
}

return pos;
}



void A4GL_LL_set_acc_intr_keys(int n) {
	//printf("show_ok_cancel(n=%d)\n",n);
	A4GL_show_ok_cancel(n) ;
}


#if GTK_CHECK_VERSION(2,0,0)
static int 
has_stock_item(char *s) {
	if (stock_item(s)) return 1;
	else return 0;
}

static char *
stock_item(char *s) {
char *ptr;
char buff[256];
char buff2[256];
	if (s[0]==' ') {
		strcpy(buff,&s[1]);
	} else {
		strcpy(buff,s);
	}
	A4GL_trim(buff);
	a4gl_upshift(buff);
	sprintf(buff2,"A4GL_STOCK_%s",buff);
	ptr=acl_getenv(buff2);
	if (ptr==0) return 0;
	if (strlen(ptr)==0) return 0;
	return ptr;

}

#endif
