#ifndef lint
static char const module_id[] =
  "$Id: widget_gtk.c,v 1.38 2008-11-04 17:58:59 mikeaubury Exp $";
#endif
#include <stdlib.h>
#include "a4gl_libaubit4gl.h"
#include "hl_proto.h"
#include "lowlevel.h"
#include "formdriver.h"
#include "low_gtk.h"
#include "a4gl_API_lowlevel.h"

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>	/* GDK_Down */
#include <ctype.h>

void textField_focus(GtkWidget * w, char *mode) ;
void A4GL_func (GtkWidget * w, char *mode);
void A4GL_add_signal_clicked (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_grab_focus (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_changed (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_select_row (GtkWidget * widget, void *funcptr);
extern GtkWidget *actionfield;
//extern int keypressed;

static void A4GL_set_pixbuf_gw (GtkWidget * widget, char *filename);

static GtkWidget *A4GL_cr_textbox (void);
static GtkWidget *A4GL_cr_button (void);
static GtkWidget *A4GL_cr_check (void);
static GtkWidget *A4GL_cr_label (void);
static GtkWidget *A4GL_cr_picture (void);
#if GTK_CHECK_VERSION(2,0,0)
static GtkWidget *A4GL_cr_pixbuf (void);
#endif
static GtkWidget *A4GL_cr_combo (void);
static GtkWidget *A4GL_cr_radio (void);
static GtkWidget *A4GL_cr_list (void);
static GtkWidget *A4GL_cr_calendar (void);
static GtkWidget *A4GL_cr_scrollbar (void);


void A4GL_dump_mem (char *ptr);
void A4GL_split_config (char *str);
void *A4GL_find_param (char *name);
GtkWidget *A4GL_make_widget (char *widget, char *config, int w,int h);
char *A4GL_fld_val_generic (GtkWidget * k);
void A4GL_gui_set_active (GtkWidget * w, int en_dis);
//void A4GL_size_widget(GtkWidget *w, int width);
void *UILIB_A4GL_make_pixmap_gw (char *filename);
void *A4GL_make_pixbuf_gw (char *filename);
//GtkWidget *A4GL_make_pixmap_from_mem(char *img);
//void A4GL_clicked_handler(GtkWidget *w, gpointer user_data);
//void A4GL_changed_handler(GtkWidget *w, gpointer user_data);
void A4GL_select_row_handler (GtkWidget * w, gint row, gint column,
			      GdkEventButton * event, gpointer user_data);
void A4GL_grab_focus_handler (GtkWidget * w, gpointer user_data);
//void A4GL_add_signal_clicked(GtkWidget *widget, void *funcptr);
//void A4GL_add_signal_grab_focus(GtkWidget *widget, void *funcptr);
//void A4GL_add_signal_changed(GtkWidget *widget, void *funcptr);
//void A4GL_add_signal_select_row(GtkWidget *widget, void *funcptr);
//void A4GL_func(GtkWidget *w, char *mode);
int A4GL_display_generic (GtkWidget * k, char *s,char *orig);


char *A4GL_decode_config (struct_form * f, int a);

int A4GL_fake_a_keypress (GtkWidget * widget, int key);


void A4GL_size_widget (GtkWidget * w, int width,int height);

struct s_widget_funcs
{
  /* GtkWidget *(*construct)(); *//* warning: function declaration isn't a prototype */
  GtkWidget *(*construct) ();
  /* GtkWidget *(*setup_signals)(); *//* warning: function declaration isn't a prototype */
  GtkWidget *(*setup_signals) ();
};

struct s_widgets
{
  char *name;
  /* GtkWidget *(*make)(); *//* warning: function declaration isn't a prototype */
  GtkWidget *(*make) (void);
  char *params[5];		/* up to 5 names parameters
				   These are not used directly from here
				   but its a good place to document them
				   This may be used later for checking when implemented
				 */
};

struct s_widgets widgets[] = {
  /*   Widget Type  cr_ function     parameters (placeholder).. */
  {"", A4GL_cr_textbox, {"MAXCHARS", 0}},
  {"TEXT", A4GL_cr_textbox, {"MAXCHARS", 0}},
  {"ENTRY", A4GL_cr_textbox, {"MAXCHARS", 0}},
  {"BUTTON", A4GL_cr_button, {"*LABEL", "*IMAGE", 0}},
  {"CHECK", A4GL_cr_check, {0}},
  {"LABEL", A4GL_cr_label, {"CAPTION", 0}},
  {"PIXMAP", A4GL_cr_picture, {"FILENAME", 0}},
  {"COMBO", A4GL_cr_combo, {0}},
  {"RADIO", A4GL_cr_radio, {"NUM", 0}},
  {"LIST", A4GL_cr_list, {0}},

#if GTK_CHECK_VERSION(2,0,0)
  {"PIXBUF", A4GL_cr_pixbuf, {"FILENAME", 0}},
  {"FIELD_BMP", A4GL_cr_pixbuf, {"FILENAME", 0}},
#endif

  /* NOTE : Calendar needs about 22 characters wide by 7 lines */
  {"CALENDAR", A4GL_cr_calendar, {0}},
  /*      NEWWIDGET       */
  {"SCROLLBAR", A4GL_cr_scrollbar, {0}},
  /*
     { "IMAGE"    , A4GL_gtk_image_new ,{0}                                            },
     { "LIST"     , A4GL_gtk_list_new  ,{0}                                            },
     { "MENU"     , A4GL_gtk_menu_new  ,{0}                                            },
     { "PROGRESS", A4GL_gtk_progress_bar_new, {0}                              },
     { "ARROW"    , A4GL_cr_arrow              ,{"TYPE","SHADOW",0}            },
     { "CALENDAR", A4GL_gtk_calendar_new,{"MONTH","YEAR",0}            },
   */
  {0}
};
GtkWidget *last_field_created;
int widget_next_size=0;
int widget_next_height=0;


#define TYPE_CHAR 1
#define TYPE_INT 2

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/** The arguments count */
static int args_cnt;

/** Array of arguments stored. */
static char *args[256];

/** The values of the parameters */
static char *args_val[256];

/** The types of the parameters */
static int args_type[256];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/*
=====================================================================
                    Functions definitions
=====================================================================
*/



void
A4GL_dump_mem (char *ptr)
{
  int a;
  A4GL_debug ("Mem A4GL_dump for %p\n", ptr);
  return;
  for (a = 0; a < 32; a++)
    {
      A4GL_debug ("%d : %x", a, ptr[a]);
    }
}



/**
 * Get parameters from a string.
 *
 * The parameter separator is ;
 *
 * @param str The string with the parameters.
 */
void
A4GL_split_config (char *str)
{
  char *ptr;
  char *s;
  int a;
  char *orig_ptr;
  ptr = strdup (str);
  orig_ptr = ptr;
  args_cnt = 0;

  while (1)
    {
      s = strtok (ptr, ";");

      if (s)
	{
	  args[args_cnt++] = s;
	}
      else
	{
	  break;
	}

      ptr = 0;
    }

  for (a = 0; a < args_cnt; a++)
    {
      args_val[a] = "";
      ptr = strchr (args[a], '=');

      if (ptr)
	{
	  *ptr = 0;
	  args_val[a] = ptr + 1;
	}

      if (args_val[a][0] == '\'')
	{
	  args_type[a] = TYPE_CHAR;
	  args_val[a][strlen (args_val[a]) - 1] = 0;
	  args_val[a]++;
	}
      else
	{
	  args_type[a] = TYPE_INT;
	}

      A4GL_debug ("'%s' = --%s-- type=%d\n", args[a], args_val[a],
		  args_type[a]);
    }

  if (args_cnt == 1)
    {
      if (strlen (args_val[0]) == 0 && strlen (args[0]))
	{
	  A4GL_debug ( "Looking at :%s\n", args[0]);
	  if (A4GL_key_val (args[0]) > 255)
	    {
	      // Looks like the config is just a key..
	      A4GL_debug ( "Key ? %s\n", args[0]);
	      args_type[0] = TYPE_CHAR;
	      args_val[0] = strdup (args[0]);	//@FIXME - memory leak
	      //if (args_val[0][0]=='f' && (args_arg[0][1]>='1' && args_val[0][1]<='9')) {a4gl_upshift(args_val[0]);}

	      args[0] = "KEY";
	    }
	}
    }
  //free(orig_ptr);
}

/**
 * Find a values of a parameter by name.
 *
 * @param name The name of the parameter to be finded.
 * @return A pointer to the bytes that have the values stored.
 */
void *
A4GL_find_param (char *name)
{
  int a;
  int reqd = 1;
  if (name[0] == '*')
    {
      reqd = 0;
      name++;
    }
  for (a = 0; a < args_cnt; a++)
    {
      if (A4GL_aubit_strcasecmp (args[a], name) == 0)
	{
	  if (args_type[a] == TYPE_CHAR)
	    return args_val[a];
	  else
	    return (void *) atoi (args_val[a]);
	}
    }

  if (reqd)
    {
      A4GL_debug ("Required Parameter not found %s\n", name);
      return 0;
    }
  else
    {
      return 0;
    }

}


/**
 * Create a widget
 *
 * @param widget The widget type.
 * @param config The optional config string attribute.
 * @param w The width of the widget.
 */
GtkWidget *
A4GL_make_widget (char *widget, char *config, int w,int h)
{
  int a;
  GtkWidget *ptr;
  char *buff;

  buff = strdup (config);
  A4GL_split_config (buff);
  A4GL_debug ("Making widget %s, %s\n", widget, config);
  for (a = 0; widgets[a].name; a++)
    {
      if (A4GL_aubit_strcasecmp (widget, widgets[a].name) == 0)
	{
	  char *key;
	  widget_next_size = w;
	  widget_next_height = h;
	  A4GL_debug ("Making type %d", a);
	  ptr = widgets[a].make ();
	  A4GL_debug ("SIzing widget (%p)", ptr);
	  A4GL_size_widget (ptr, w,h);
	  //A4GL_dump_mem ((char *) ptr);
	  key = A4GL_find_param ("*KEY");
	  if (key)
	    {
	      gtk_object_set_data (GTK_OBJECT (ptr), "KEY", key);
	    }


	  gtk_object_set_data (GTK_OBJECT (ptr), "WIDGETSNAME", widget);

	  if (A4GL_aubit_strcasecmp (widget, "PIXMAP") != 0
	      && A4GL_aubit_strcasecmp (widget, "LIST") != 0)
	    {
	      gtk_widget_set_sensitive (ptr, 0);
	    }
	  return ptr;
	}
    }


  A4GL_debug ("No widget of that type available...");
  FPRINTF (stderr, "Invalid Widget : %s\n", widget);
  fflush (stderr);
  A4GL_exitwith ("Invalid Widget");
  return 0;
}



/**
 * Decode the configuration information to more understandable information.
 *
 * The configuration information is defined with the CONFIG string attribute
 * in the form definition.
 *
 * @param f A pointer to the form describing strucutre.
 * @param a The field / attribute number sequence.
 * @return The config value
 */
char *
A4GL_decode_config (struct_form * f, int a)
{
  int b;
  for (b = 0; b < f->attributes.attributes_val[a].str_attribs.str_attribs_len;
       b++)
    {
      if (f->attributes.attributes_val[a].str_attribs.str_attribs_val[b].
	  type == FA_S_CONFIG)
	{
	  return f->attributes.attributes_val[a].str_attribs.
	    str_attribs_val[b].value;
	}
    }
  return "";
}






char *
A4GL_fld_val_generic (GtkWidget * k)
{
  char *ptr;
  char *txt;
  char *utf;
  static char txt_buf[2560];

  A4GL_debug ("in A4GL_fld_val_generic k=%p\n", k);

  ptr = gtk_object_get_data (GTK_OBJECT (k), "WIDGETSNAME");

  if (ptr == NULL)
    {
      A4GL_debug ("Cant find the widget!");
      return (char *) 1;
    }

  A4GL_debug ("Widgettye=%s\n", ptr);

  if (A4GL_aubit_strcasecmp (ptr, "LABEL") == 0)
    {
      gtk_label_get (GTK_LABEL (k), &txt);
      utf = g_locale_from_utf8 (txt, -1, NULL, NULL, NULL);
      strncpy (txt_buf, utf, 256);
      g_free (utf);
      return txt_buf;
    }



  if (A4GL_aubit_strcasecmp (ptr, "BUTTON") == 0)
    {
      GtkWidget *l;
      l = gtk_object_get_data (GTK_OBJECT (k), "LABEL");
      if (l)
	{
	  gtk_label_get (GTK_LABEL (l), &txt);
	  if (txt)
	    {
	      utf = g_locale_from_utf8 (txt, -1, NULL, NULL, NULL);
	      strncpy (txt_buf, utf, 256);
	      g_free (utf);
	    }
	  else
	    {
	      strcpy (txt_buf, "");
	    }
	}
      else
	{
	  strcpy (txt_buf, "");
	}
      return txt_buf;

    }


  if (A4GL_aubit_strcasecmp (ptr, "ENTRY") == 0 || A4GL_aubit_strcasecmp (ptr, "TEXT") == 0)
    {
      	if (gtk_object_get_data (GTK_OBJECT (k), "ISTEXTVIEW")) {
		GtkTextIter  start;
		GtkTextIter  end;
		GtkTextBuffer*b;
		char *ptr;

		b=gtk_text_view_get_buffer(GTK_TEXT_VIEW(k));
	  	gtk_text_buffer_get_iter_at_offset (b, &start, 0);
  		gtk_text_buffer_get_iter_at_offset (b, &end, 2560);

		ptr=gtk_text_buffer_get_text (b,&start,&end,0 );
      		utf = g_locale_from_utf8 (ptr, -1, NULL, NULL, NULL);
      		strncpy (txt_buf, utf, 2560);
	} else {
      		utf = g_locale_from_utf8 (gtk_entry_get_text (GTK_ENTRY (k)), -1, NULL, NULL, NULL);
      		strncpy (txt_buf, utf, 2560);
      		g_free (utf);
	}
      return txt_buf;
    }


  if (A4GL_aubit_strcasecmp (ptr, "CHECK") == 0)
    {
	//utf = g_locale_from_utf8 (gtk_entry_get_text (GTK_ENTRY (k)), -1, NULL, NULL, NULL);
      if (gtk_toggle_button_get_active((GTK_TOGGLE_BUTTON(k)))) {
      	strcpy (txt_buf, "1");
      } else {
      	strcpy (txt_buf, "0");
      }
      //g_free (utf);
      return txt_buf;
    }

  if (A4GL_aubit_strcasecmp (ptr, "RADIO") == 0)
    {
      int a;
      GtkWidget *btn;
      char buff[20];
      for (a = 0;; a++)
	{
	  SPRINTF1 (buff, "B%d", a + 1);
	  btn = gtk_object_get_data (GTK_OBJECT (k), buff);
	  if (btn == 0)
	    break;
	  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (btn)))
	    {
	      utf =
		g_locale_from_utf8 (gtk_object_get_data
				    (GTK_OBJECT (btn), "Value"), -1, NULL,
				    NULL, NULL);
	      strncpy (txt_buf, utf, 256);
	      g_free (utf);
	      return txt_buf;
	    }
	}
      return NULL;
    }


  if (A4GL_aubit_strcasecmp (ptr, "CALENDAR") == 0)
    {
      unsigned int d, m, y;
      static char buff[256];

      gtk_calendar_get_date (GTK_CALENDAR (k), &y, &m, &d);
      A4GL_push_variable (&m, 0x2);
      A4GL_push_variable (&d, 0x2);
      A4GL_push_variable (&y, 0x2);
      aclfgl_mdy (3);
      A4GL_pop_var2 (&buff, 0, 20);
      A4GL_trim (buff);
      utf = g_locale_from_utf8 (buff, -1, NULL, NULL, NULL);
      strncpy (txt_buf, utf, 256);
      g_free (utf);
      return txt_buf;
    }

  if (A4GL_aubit_strcasecmp (ptr, "SCROLLBAR") == 0)
    {
      static char buff[20];
      /* d=gtk_adjustment_get_value (GTK_ADJUSTMENT(k)); */
      SPRINTF1 (buff, "%d", 0);
      return buff;
    }

  FPRINTF (stderr, "UNKNOWN WIDGET TYPE: '%s'\n", ptr);
/* NEWWIDGET - Add here */


  return NULL;
}


void
A4GL_gui_set_active (GtkWidget * w, int en_dis)
{
  GtkWidget *p;
  char *wtype;
  A4GL_debug ("Set active : %p %d", w, en_dis);
  p = gtk_object_get_data (GTK_OBJECT (w), "Child");
  A4GL_debug ("p=%p", p);
  if (p == 0)
    p = w;
  A4GL_debug (" activate %p ", p);
  wtype = gtk_object_get_data (GTK_OBJECT (w), "WIDGETSNAME");
  if (wtype)
    {
      if (A4GL_aubit_strcasecmp (wtype, "pixmap") == 0)
	en_dis = 1;
    }
  gtk_widget_set_sensitive (p, en_dis);

}





/**
 * @file
 *
 * GTK GUI widget creation functions.
 *
 * NEWWIDGET : New widgets types will need information entered into this file
 * Look for the NEWWIDGET comment in the code.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/



/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

GtkWidget *A4GL_make_pixmap_from_mem (char *img);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

int lastWidth = 0;
int lastHeight = 0;

/**
 * Size a GTK widget.
 *
 * If the width have been specified in the global parameters use it instead 
 * the value passed as function parameter.
 * 
 * The height is geted from the global parameters.
 *
 * @param w A pointer to the widget to be sized.
 * @param width The width wanted for the widget.
 */
void
A4GL_size_widget (GtkWidget * w, int width,int height)
{
  int x, y;



  /* If we have a specified width - use it */
  x = (int) A4GL_find_param ("*WIDTH");
  if (x)
    x = x * XWIDTH;
  else
    x = (width + 2) * XWIDTH;	/* use the fields width in chars.. */

  /* DO we have a specified height ? */
  y = (int) A4GL_find_param ("*HEIGHT");
  if (y)
    y = y * YHEIGHT - (YHEIGHT / 2);
  else
    y = height * YHEIGHT;		/* Use 1 character height */


  if (w)
    {
      gtk_widget_set_usize (GTK_WIDGET (w), x, y);
    }

  gtk_object_set_data (GTK_OBJECT (w), "SIZE_X", (void *)x);
  gtk_object_set_data (GTK_OBJECT (w), "SIZE_Y", (void *)y);

  lastWidth = x;
  lastHeight = y;
}


/**
 * Create a pixmap from the information stored in a file.
 *
 * @param filename The name of the file where the pixmap is stored.
 * @return The pixmap widget.
 */
//GtkWidget *

void *
UILIB_A4GL_make_pixmap_gw (char *filename)
{
  GdkPixmap *p;
  GtkWidget *pixmap;
  A4GL_debug ("Making pixmap from file:%s (2)\n", filename);
  if (filename == 0)
    filename = "";
  p = gdk_pixmap_colormap_create_from_xpm (0,
					   gdk_colormap_get_system (), NULL,
					   NULL, filename);
  if (p == 0)
    {
      FPRINTF (stderr, "Bad pixmap...");
      //A4GL_exitwith ("Error creating pixmap");
      return 0;
    }

  pixmap = gtk_pixmap_new (p, 0);
  A4GL_debug ("New pixmap : %p\n", pixmap);
  return pixmap;
}

#if GTK_CHECK_VERSION(2,0,0)
void *
A4GL_make_pixbuf_gw (char *filename)
{
  //GdkPixbuf *p;
  //GtkWidget *pixbuf;
  //GtkWidget *window,*hbox, *resized,*widget;
  GtkWidget *widget=0;
  GdkPixbuf *pixbuf=0, *resized=0;

  if (filename == 0)
    filename = "";
  A4GL_debug ("Making pixmap from file:%s (1)\n", filename);
  A4GL_trim (filename);


  if (strlen(filename)) {
  		pixbuf = gdk_pixbuf_new_from_file (filename, NULL);
	} else {
		pixbuf=0;
	}


  widget = gtk_image_new ();
  A4GL_size_widget (widget, widget_next_size, widget_next_height);
	if (pixbuf) {
  		resized = gdk_pixbuf_scale_simple (pixbuf, lastWidth - 20, lastHeight - 20,
			     GDK_INTERP_BILINEAR);


	}

  if (pixbuf && resized == 0)
    {
      FPRINTF (stderr, "Make pixmap failed...");
    }

  if (resized) {
  	gtk_image_set_from_pixbuf (GTK_IMAGE (widget), resized);
  	gdk_pixbuf_unref (resized);
	}

  gtk_widget_show (widget);
  A4GL_debug ( "pixmap=%p\n", pixbuf);
  //gtk_box_pack_start(GTK_BOX(hbox), widget, FALSE, FALSE, 2);

  if (pixbuf) {
  g_object_unref (pixbuf);
	}


  //gtk_widget_show(hbox);
  gtk_widget_show (widget);
  return widget;
}

void A4GL_set_pixbuf_gw (GtkWidget * widget, char *filename)
{
  //GdkPixbuf *p;
  //GtkWidget *pixbuf;
  //GtkWidget *window,*hbox, *resized,*widget;
  GdkPixbuf *pixbuf, *resized;
  int scaletofit;

  if (filename == 0)
    filename = "";
  A4GL_debug ( "Making pixmap from file:%s (1)\n", filename);

  A4GL_trim (filename);


  pixbuf = gdk_pixbuf_new_from_file (filename, NULL);
  if (!pixbuf)
    {
      A4GL_debug ( "Make pixmap failed...");
      return;
    }
  else
    {

      scaletofit = (int) gtk_object_get_data (GTK_OBJECT (widget), "SCALE");

      if (scaletofit)
	{
	  resized = gdk_pixbuf_scale_simple (pixbuf, lastWidth - 20, lastHeight - 20, GDK_INTERP_BILINEAR);

	  if (resized == 0)
	    {
	      A4GL_debug ( "resize pixmap failed...");
	    }

	  lastWidth =
	    (int) gtk_object_get_data (GTK_OBJECT (widget), "SIZE_X");
	  lastHeight =
	    (int) gtk_object_get_data (GTK_OBJECT (widget), "SIZE_Y");
	  gtk_image_set_from_pixbuf (GTK_IMAGE (widget), resized);
	  gdk_pixbuf_unref (resized);
	  g_object_unref (pixbuf);
	}
      else
	{
	  gtk_image_set_from_pixbuf (GTK_IMAGE (widget), pixbuf);
	  g_object_unref (pixbuf);

	}
    }
  return;
}




#else
void *
A4GL_make_pixbuf_gw (char *filename)
{
  A4GL_exitwith ("make_pixbuf not available with GTK1.2");
  return 0;
}
#endif

/**
 * Create a new pixmap from a image allready loaded to memory.
 *
 * @param img A pointer to the image to be used in the widget.
 * @return The widget with the image.
 */
GtkWidget *
A4GL_make_pixmap_from_mem (char *img)
{
  GdkPixmap *p;
  GtkWidget *pixmap;
  A4GL_debug ("Adding pixmap from memory : %p", img);
  p = gdk_pixmap_colormap_create_from_xpm_d (0,
					     gdk_colormap_get_system (), NULL,
					     NULL, &img);
  A4GL_debug ("Done gdk bit");
  pixmap = gtk_pixmap_new (p, 0);
  A4GL_debug ("created pixmap");

  return pixmap;
}

/**
 * Create a widget picture in GTK GUI  mode.
 *
 * @return A pointer to the widget created.
 */
GtkWidget *
A4GL_cr_picture (void)
{
  GtkWidget *pixmap;
  char *filename;
  char *scaletofit;
  filename = A4GL_find_param ("FILENAME");

  A4GL_debug ("Making picture filename=%s\n", filename);
  pixmap = UILIB_A4GL_make_pixmap_gw (filename);
  if (pixmap)
    {
      A4GL_add_signal_grab_focus (pixmap, 0);
      /* A4GL_add_signal_clicked (pixmap, 0); */  // GLib-GObject-CRITICAL **: g_signal_connect_closure_by_id: assertion `signal_id > 0' failed
    }


  scaletofit = A4GL_find_param ("*SCALE");
  if (scaletofit) { 
		gtk_object_set_data(GTK_OBJECT(pixmap),"SCALE",scaletofit); 
	}

  return pixmap;
}

#if GTK_CHECK_VERSION(2,0,0)
GtkWidget *
A4GL_cr_pixbuf (void)
{
  GtkWidget *pixmap = 0;
  char *filename;
  char *scaletofit;
  A4GL_debug ( "Find param\n");

  filename = A4GL_find_param ("FILENAME");
  A4GL_debug ( "Found :%s\n", filename);
  A4GL_debug ("Making picture filename=%s PIXBUF\n", filename);
#if GTK_CHECK_VERSION(2,0,0)
  pixmap = A4GL_make_pixbuf_gw (filename);
#endif
  gtk_widget_show (pixmap);
  A4GL_debug ( "Made : %p\n", pixmap);
  A4GL_add_signal_grab_focus ((GtkWidget *) pixmap, 0);
  scaletofit = A4GL_find_param ("*SCALE");
  if (scaletofit) { 
		gtk_object_set_data(GTK_OBJECT(pixmap),"SCALE",scaletofit); 
	}
  return pixmap;
}
#endif


/**
 * Create a button widget.
 * The image and label used are getted from the global parameters.
 *
 * @return A pointer to the widget created.
 */
GtkWidget *
A4GL_cr_button (void)
{
  char *label;
  char *image;
  GtkLabel *l = 0;
  GtkButton *b;
  GtkVBox *v;
  GtkWidget *pixmap = 0;
  char *key;

  label = A4GL_find_param ("*LABEL");
  image = A4GL_find_param ("*IMAGE");
  key = A4GL_find_param ("*KEY");
  A4GL_debug ("key=%s\n", key);

  b = (GtkButton *) gtk_button_new (); 
  v = (GtkVBox *) gtk_vbox_new (0, 3);
  gtk_container_add (GTK_CONTAINER (b), GTK_WIDGET (v));


  if (label == 0)
    label = " ";
  if (strlen (label) == 0)
    label = " ";


  if (label)
    {
      if (strlen (label))
	{
	  char *utf = a4gl_locale_to_utf8 (label);
		l = (GtkLabel *) gtk_label_new (utf);
#if GTK_CHECK_VERSION(2,0,0)
	  /*
	     if(A4GL_isyes(acl_getenv("A4GL_USE_PANGO_ML"))) {
	     A4GL_debug("using PANGO ML for Label '%s'\n",label);
	     gtk_label_set_use_markup(l, TRUE);
	     }
	   */
#endif
	  g_free (utf);
	  gtk_widget_show (GTK_WIDGET (l));
	  gtk_object_set_data (GTK_OBJECT (b), "LABEL", l);
	  gtk_object_set_data (GTK_OBJECT (b), "PERMLABEL", l);
	  gtk_container_add (GTK_CONTAINER (v), GTK_WIDGET (l));
	}
    }

  if (image)
    {
      if (strlen (image))
	{
	  pixmap = UILIB_A4GL_make_pixmap_gw (image);
	  if (pixmap) {
	  	gtk_container_add (GTK_CONTAINER (v), GTK_WIDGET (pixmap));
	  	gtk_widget_show (pixmap);
	  	}
	  gtk_object_set_data (GTK_OBJECT (b), "IMAGE", image);
	}
    }

  gtk_widget_show (GTK_WIDGET (v));	/* Vbox */
  gtk_widget_show (GTK_WIDGET (b));	/* Button itself.. */
  if (key != 0)
    {
      if (strlen (key))
	{
	  A4GL_debug ( "ISKEY:%s\n", key);
	  gtk_object_set_data (GTK_OBJECT (b), "KEY", key);
	}
    }

  A4GL_add_signal_clicked ((GtkWidget *) b, 0);
  A4GL_add_signal_grab_focus ((GtkWidget *) b, 0);
  if (strcmp (label, " ") == 0 && A4GL_isyes(acl_getenv("HIDEEMPTYBUTTONS")))
    {
      gtk_widget_hide (GTK_WIDGET (b));
    } else {
      gtk_widget_show (GTK_WIDGET (b));
    }
  return GTK_WIDGET (b);
}

/**
 * Create a radio button widget.
 *
 * @return A pointer to the newly created radio button widget.
 */
GtkWidget *
A4GL_cr_radio (void)
{
  int a;
  char buff[40];
  char *ptr;
  int n;
  GSList *btn_grp;
  GtkHBox *hbox;
  GtkWidget *btn;
/*
 Config will contain
   Num = Number of radio buttons
   L1..LNum  = Labels
   V1..VNum  = Values
*/

  n = (int) A4GL_find_param ("NUM");
  A4GL_debug ("Radio group with %d buttons\n", n);
  btn_grp = NULL;
  hbox = (GtkHBox *) gtk_hbox_new (FALSE, 5);
  for (a = 0; a < n; a++)
    {
      SPRINTF1 (buff, "L%d", a + 1);
      A4GL_debug ("Finding label %s\n", buff);
      ptr = A4GL_find_param (buff);
      A4GL_debug ("   %s\n", ptr);

      btn =
	gtk_radio_button_new_with_label (btn_grp,
					 a4gl_locale_to_utf8 (ptr));
      btn_grp = (GSList *) gtk_radio_button_group (GTK_RADIO_BUTTON (btn));
      gtk_box_pack_start (GTK_BOX (hbox), btn, TRUE, TRUE, 0);
      gtk_widget_show (btn);
      SPRINTF1 (buff, "V%d", a + 1);
      ptr = A4GL_find_param (buff);
      A4GL_debug ("Finding value %s = %s\n", buff, ptr);
      gtk_object_set_data (GTK_OBJECT (btn), "Value", ptr);
      gtk_object_set_data (GTK_OBJECT (btn), "Parent", hbox);


      SPRINTF1 (buff, "B%d", a + 1);
      gtk_object_set_data (GTK_OBJECT (hbox), buff, btn);
      A4GL_debug ("Adding %s to %p\n", buff, hbox);
      A4GL_add_signal_clicked (btn, 0);
      A4GL_add_signal_grab_focus (btn, 0);
    }
  gtk_widget_show (GTK_WIDGET (hbox));
  /* add_signal_clicked(hbox,0); */
  A4GL_add_signal_grab_focus ((GtkWidget *) hbox, 0);
  return GTK_WIDGET (hbox);
}


/*
int
A4GL_kp (GtkWidget * widget, GdkEventKey * event, gpointer user_data)
{
printf("Hello World\n");
return 0;
}
*/


/**
 * Create a text box widget and show it.
 *
 * The data needed to create it is fetched from the global parameters.
 *
 * @return A pointer to the created textbox.
 */
GtkWidget *
A4GL_cr_textbox (void)
{
  GtkWidget *entry;
  int maxchars;
  A4GL_debug ("Making textbox");
  maxchars = (int) A4GL_find_param ("*MAXCHARS");
  if (widget_next_height > 1)
    {
	// Its a text box...
	entry=gtk_text_view_new();
      	gtk_object_set_data (GTK_OBJECT (entry), "ISTEXTVIEW", (void *)1);
  	gtk_widget_show (entry);

	//gtk_signal_connect (GTK_OBJECT (entry), "key-press-event", GTK_SIGNAL_FUNC (A4GL_kp), entry);



    }
  else
    {

      if (maxchars)
	{
	  entry = gtk_entry_new_with_max_length (maxchars);
	}
      else
	{
	  entry = gtk_entry_new ();
	}
  	gtk_widget_show (entry);
	gtk_object_set_data (GTK_OBJECT (entry), "HANDLER", (void *)textField_focus);
  	A4GL_add_signal_changed (entry, 0);
	//A4GL_add_signal_clicked(entry,0);
  	A4GL_add_signal_grab_focus (entry, 0);
    }
  A4GL_debug ("Created textbox widget %p", entry);

  return entry;
}

/**
 * Create and show a label widget.
 *
 * @return A pointer to the label widget.
 */
GtkWidget *
A4GL_cr_label (void)
{
  GtkWidget *label;
  char *caption;
  char *utf = NULL;
  caption = A4GL_find_param ("CAPTION");
  if (caption)
    utf = a4gl_locale_to_utf8 (caption);
  label = gtk_label_new (utf);
  g_free (utf);
  gtk_widget_show (label);
  A4GL_add_signal_grab_focus (label, 0);
  /* A4GL_add_signal_clicked (label, 0); */ // GLib-GObject-CRITICAL **: g_signal_connect_closure_by_id: assertion `signal_id > 0' failed
  return label;
}

/**
 * Create and show a check box widget in GTK gui mode.
 *
 * @return A pointer to the created check box widget.
 */
GtkWidget *
A4GL_cr_check (void)
{
  GtkWidget *checkbox;
  char *label = 0;
  char *value = 0;
  label = A4GL_find_param ("*LABEL");
  value = A4GL_find_param ("*VALUE");

  if (label)
    {
      char *utf = a4gl_locale_to_utf8 (label);
      checkbox = gtk_check_button_new_with_label (utf);
      g_free (utf);
    }
  else
    {
      checkbox = gtk_check_button_new ();
    }

  if (value)
    {
      gtk_object_set_data (GTK_OBJECT (checkbox), "VALUE", value);
    }
  else
    {
      gtk_object_set_data (GTK_OBJECT (checkbox), "VALUE", "1");
    }

  gtk_widget_show (checkbox);
  A4GL_add_signal_clicked (checkbox, 0);
  A4GL_add_signal_grab_focus (checkbox, 0);
  return checkbox;
}

/**
 * Create and show a combo box widget in GTK gui mode.
 *
 * @return A pointer to the created combo box widget.
 */
GtkWidget *
A4GL_cr_combo (void)
{
  GtkCombo *combo;
  combo = (GtkCombo *) gtk_combo_new ();
  gtk_object_set_data (GTK_OBJECT (combo->entry), "Parent", combo);
  gtk_widget_show (GTK_WIDGET (combo));
  A4GL_add_signal_changed (combo->entry, 0);
  A4GL_add_signal_grab_focus (combo->entry, 0);
  return (GtkWidget *) combo;
}


/**
 * Create and show a list widget.
 *
 * @return A pointer to the list.
 */
GtkWidget *
A4GL_cr_list (void)
{
  GtkWidget *w;
  GtkWidget *scroll;		/* CList needs to be in a scrolled window.. */

  /*
     This is the list widget - eventually this
     may be extended to take in a screen record and
     convert it to a list
     but for now lets keep things simple....
   */
  A4GL_debug ("Making list\n");
  scroll = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scroll),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  gtk_widget_show (scroll);

  w = gtk_clist_new (1);	/* 1 column for now.... */
  gtk_clist_set_selection_mode (GTK_CLIST (w), GTK_SELECTION_SINGLE);
  gtk_clist_set_shadow_type (GTK_CLIST (w), GTK_SHADOW_IN);

  gtk_container_add (GTK_CONTAINER (scroll), GTK_WIDGET (w));


  /* We don't want any titles displayed... */
  gtk_clist_column_titles_hide (GTK_CLIST (w));

  gtk_clist_set_column_width (GTK_CLIST (w), 0,
			      (widget_next_size - 2) * XWIDTH);

  gtk_object_set_data (GTK_OBJECT (w), "Parent", scroll);
  gtk_object_set_data (GTK_OBJECT (scroll), "Child", w);
  gtk_widget_show (w);

  A4GL_add_signal_select_row (w, 0);
  A4GL_add_signal_grab_focus (w, 0);
  A4GL_debug ("Made list w=%p", w);
  gtk_widget_set_sensitive (w, 0);
  return scroll;
}


/**
 * Create a calendar widget in GTK GUI mode.
 *
 * @return A pointer to the created widget.
 */
GtkWidget *
A4GL_cr_calendar (void)
{
  GtkWidget *cal;
  A4GL_debug ("Making calendar...");
  cal = gtk_calendar_new ();
  A4GL_debug ("showing");
  gtk_widget_show (cal);
  A4GL_add_signal_changed (cal, 0);
  A4GL_add_signal_grab_focus (cal, 0);
  A4GL_debug ("added signals");
  return cal;
}


/*
NEWWIDGET - Add cr_ function in this file
*/

/**
 *
 * @todo Describe function
 */
GtkWidget *
A4GL_cr_scrollbar (void)
{
  GtkWidget *sb;
  int x, y;

  x = (int) A4GL_find_param ("*WIDTH");
  y = (int) A4GL_find_param ("*HEIGHT");

  if (x == 0 && y == 0)
    x = 3;

  if (y > x)
    {
      /* Its vertical */
      sb = gtk_vscrollbar_new (0);

    }
  else
    {
      sb = gtk_hscrollbar_new (0);
      /* Its horizontal */
    }
  A4GL_debug ("showing");
  gtk_widget_show (sb);
  A4GL_add_signal_changed (sb, 0);
  A4GL_add_signal_grab_focus (sb, 0);
  A4GL_debug ("added signals");
  return sb;
}




struct_scr_field *attr;
struct_metrics *metr;
char *gtfield;
char *widgettype;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_clicked_handler (GtkWidget * w, gpointer user_data);
void A4GL_changed_handler (GtkWidget * w, gpointer user_data);




static void
set_widget_data (GtkWidget * widget)
{
  attr = gtk_object_get_data (GTK_OBJECT (widget), "Attribute");
  metr = gtk_object_get_data (GTK_OBJECT (widget), "Metric");
  gtfield = gtk_object_get_data (GTK_OBJECT (widget), "Field");
  widgettype = gtk_object_get_data (GTK_OBJECT (widget), "WidgetType");
}


/**
 * Callback function called as listener of a click event ocurred over a widget.
 *
 * @param w The widget where the event was fired.
 * @param user_data A pointer to the callback function that is listening the
 * event.
 */
void
A4GL_clicked_handler (GtkWidget * w, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget * nw, char *a);
  char *l;
  if (user_data)
    ptr = user_data;
  else
    ptr = A4GL_func;

  A4GL_debug ("Clicked... %p %p", w, user_data);
  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  if (l)
    {
      nw = GTK_WIDGET (l);
    }
  else
    {
      nw = w;
    }
  A4GL_debug ("\nclicked - ptr=%p w=%p\n", ptr, nw);

  set_widget_data (nw);
  ptr (nw, "clicked");
}

/**
 *
 * @param w A pointer to the widget.
 * @param user_data
 */
void
A4GL_changed_handler (GtkWidget * w, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget * nw, char *a);
  char *l;

  if (user_data)
    ptr = user_data;
  else
    ptr = A4GL_func;

  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  /* Is this a change on part of a larger widget  (eg combo/radio) */
  if (l)
    {
      nw = GTK_WIDGET (l);	/* Yes - signal the parent */
    }
  else
    {
      nw = w;			/* No - keep the signal for this widget */
    }
  A4GL_debug ("\nchanged - ptr=%p w=%p\n", ptr, nw);
  set_widget_data (nw);
  ptr (nw, "on");
}


/**
 *
 * @todo Describe function
 */
void
A4GL_select_row_handler (GtkWidget * w,
			 gint row,
			 gint column, GdkEventButton * event,
			 gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget * nw, char *a);
  char *l;

  if (user_data)
    ptr = user_data;
  else
    ptr = A4GL_func;

  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  /* Is this a change on part of a larger widget  (eg combo/radio) */
  if (l)
    {
      nw = GTK_WIDGET (l);	/* Yes - signal the parent */
    }
  else
    {
      nw = w;			/* No - keep the signal for this widget */
    }

  set_widget_data (nw);

  if (ptr)
    ptr (nw, "on");

  else
    {
      A4GL_debug ( "Nothing to do\n");
    }
}



/**
 *
 * @todo Describe function
 */
void
A4GL_grab_focus_handler (GtkWidget * w, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget * nw, char *a);

  char *l;

  A4GL_debug ("Focus change ");

  if (user_data)
    ptr = user_data;
  else
    ptr = A4GL_func;

  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  if (l)
    {
      nw = GTK_WIDGET (l);
    }
  else
    {
      nw = w;
    }

  set_widget_data (nw);
  A4GL_debug ("\nGrab focus w=%p ptr=%p\n", nw, ptr);

  ptr (nw, "grab_focus");
}


/**
 * Add a clicked standard (in this library) event listener.
 *
 * @param widget The widget that we want to add a listener.
 * @param funcptr A pointer to an aditional listener callback.
 */
void
A4GL_add_signal_clicked (GtkWidget * widget, void *funcptr)
{
  if (widget) {
  gtk_signal_connect (GTK_OBJECT (widget), "clicked",
		      GTK_SIGNAL_FUNC (A4GL_clicked_handler), funcptr);
  }
}


/**
 *
 * @todo Describe function
 */
void
A4GL_add_signal_grab_focus (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "grab-focus",
		      GTK_SIGNAL_FUNC (A4GL_grab_focus_handler), funcptr);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_add_signal_changed (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "changed",
		      GTK_SIGNAL_FUNC (A4GL_changed_handler), funcptr);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_add_signal_select_row (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "select_row",
		      GTK_SIGNAL_FUNC (A4GL_select_row_handler), funcptr);
}










void
A4GL_func (GtkWidget * w, char *mode)
{

  if (gtk_object_get_data (GTK_OBJECT (w), "HANDLER") != 0)
    {
      /* void (*hand)(); */
      void (*hand) (GtkWidget * w, char *mode);

      A4GL_debug ("MJAMJA------------> Own handler....\n");
      hand = gtk_object_get_data (GTK_OBJECT (w), "HANDLER");
      hand (w, mode);
      return;
    }

  A4GL_debug ("in func");
  A4GL_debug ("**** A4GL_func ---%p '%s' (%s:%s)\n", w, mode, widgettype,
	      gtfield);

  if (A4GL_aubit_strcasecmp (mode, "grab_focus") == 0)
    {
      A4GL_debug ("grab focus detected...\n");
      A4GL_debug ("setting A4GL_action field=%p", w);
      actionfield = w;

      return;
    }

  if (strcmp (mode, "clicked") == 0)
    {
      char *key;
      int m;
      unsigned int keyn;
      keyn = 0;
      A4GL_debug ("setting A4GL_action field=%p", w);
      actionfield = w;

      key = gtk_object_get_data (GTK_OBJECT (w), "KEY");

      A4GL_debug ( "Key=%p (%s)\n", key, key);

      if (key)
	{
	  A4GL_debug ("Substituting specified key: %s\n", key);

	  if (A4GL_aubit_strcasecmp (key, "ACCEPT") == 0)
	    {
	      keyn = 27;	/* FIXME */
	    }
	  else
	    {
	      if (A4GL_aubit_strcasecmp (key, "INTERRUPT") == 0)
		{
		  keyn = 3;	/* FIXME */
		}
	      else
		{
		  void *ptr;
		  ptr = &m;

		  gtk_accelerator_parse (key, &keyn, (GdkModifierType *) ptr);
		  if (keyn == 0 && m == 0)
		    {
		      FPRINTF (stderr, "Don't understand that key : %s\n",key);
		      a4gl_upshift (key);
		      gtk_accelerator_parse (key, &keyn,
					     (GdkModifierType *) ptr);
		      if (keyn == 0 && m == 0)
			{
			  keyn = A4GL_key_val (key);
			  FPRINTF (stderr, "Still dont understand that key - hope the aubit one just passed through...");
			}
		    }
		  if (m & 4 && tolower (keyn) >= 'a' && tolower (keyn) <= 'z')
		    keyn = tolower (keyn) - 'a' + 1;

		  A4GL_fake_a_keypress (w, keyn);
		  A4GL_debug ( "keyn=%x m=%x\n", keyn, m);
		  //fflush (stderr);
		}
	    }
	}
    }



  A4GL_debug ("All done");
  return;
}












/**
 * Display information to a widget.
 *
 * Check the widget type and use the apropriate method to do it.
 *
 * @param k A pointer to the widget where to display the information
 * @param s A pointer to the information to be displayed.
 * @return The result of the display:
 *   - 1 : Information displayed.
 *   - 0 :idget type not found.
 */
int
A4GL_display_generic (GtkWidget * k, char *s,char *orig)
{
  char *ptr;
  char *utf;
  char *btn;
  A4GL_debug ("in A4GL_display_generic k=%p s='%s'\n", k, s);



  ptr = gtk_object_get_data (GTK_OBJECT (k), "WIDGETSNAME");

  if (ptr == 0)
    {
      A4GL_debug ("Cant find the widget!");
      return 1;
    }

  A4GL_debug ("Widgettye=%s\n", ptr);

  utf = a4gl_locale_to_utf8 (s);

  if (utf==0) return 0;

  A4GL_debug("Here..");

  if (A4GL_aubit_strcasecmp (ptr, "BUTTON") == 0)
    {
      GtkWidget *w;
      GtkWidget *w2;
      btn = strdup (s);
      A4GL_trim (btn);

      w = gtk_object_get_data (GTK_OBJECT (k), "LABEL");
      w2=gtk_object_get_data (GTK_OBJECT (k), "PERMLABEL");
      if (w2) {
	      	char *buff;
	      	buff=strdup(s);
		A4GL_trim(buff);
	      	if (strlen(buff)==0) {
				free(buff);
					return 0;
		}
				free(buff);

      }
      if (w)
	{
	  gtk_label_set_text (GTK_LABEL (w), utf);
	  g_free (utf);
	}

      if (strlen (btn) == 0 && A4GL_isyes(acl_getenv("HIDEEMPTYBUTTONS")))
	{
	  gtk_widget_hide (GTK_WIDGET (k));
	}
      else
	{
	  gtk_widget_show (GTK_WIDGET (k));
	}
      free (btn);
    }



  if (A4GL_aubit_strcasecmp (ptr, "LABEL") == 0)
    {
      /* check whether a Gtk+ version equal to or greater than
       * major.minor.micro is present.
       */
      //#if ! GTK_CHECK_VERSION(2,0,0)
      // Old GTK sytle        
      //      GtkStyle *style;
      //#endif

      gtk_label_set_text (GTK_LABEL (k), utf);
#if GTK_CHECK_VERSION(2,0,0)
      if (A4GL_isyes (acl_getenv ("A4GL_USE_PANGO_ML")))
	{
	  A4GL_debug ("using PANGO ML for Label '%s'\n", s);
	  gtk_label_set_use_markup (GTK_LABEL (k), TRUE);
	}
#endif
      g_free (utf);
      return 1;
    }


  if (A4GL_aubit_strcasecmp (ptr, "PIXMAP") == 0 || A4GL_aubit_strcasecmp (ptr, "PIXBUF") == 0 ||  A4GL_aubit_strcasecmp (ptr, "FIELD_BMP")==0)
    {
  	if (A4GL_aubit_strcasecmp (ptr, "PIXMAP") == 0) {
		A4GL_debug("Cant change a pixmap - use a PIXBUF instead...\n");
	} else {
		char *s=0;
		if (orig) {
		s=strdup(orig); 
		A4GL_trim(s);
		A4GL_set_pixbuf_gw(k,s);
		free(s);
		}
	}
      return 1;
    }




  if (A4GL_aubit_strcasecmp (ptr, "ENTRY") == 0 || A4GL_aubit_strcasecmp (ptr, "TEXT") == 0)
    {
	A4GL_debug("Entry..");
      	if (gtk_object_get_data (GTK_OBJECT (k), "ISTEXTVIEW")) {
	  	GtkTextBuffer *buffer;
	  	buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (k));
		A4GL_trim(s);
  		utf = a4gl_locale_to_utf8 (s);
			
	  	gtk_text_buffer_set_text (buffer,utf, -1);
	 } else {
		A4GL_debug("Entry...2 : '%s'",utf);
      		gtk_entry_set_text (GTK_ENTRY (k), utf);
      		g_free (utf);
	 }
      return 1;
    }

  if (A4GL_aubit_strcasecmp (ptr, "LIST") == 0)
    {
      A4GL_debug ( "Adding to list...\n");
      k = gtk_object_get_data (GTK_OBJECT (k), "Child");
      gtk_clist_append (GTK_CLIST (k), &utf);
      g_free (utf);
    }

  if (A4GL_aubit_strcasecmp (ptr, "RADIO") == 0)
    {
      int a;
      GtkWidget *btn;
      char *ptr;
      char buff[20];
      for (a = 0;; a++)
	{
	  SPRINTF1 (buff, "B%d", a + 1);
	  A4GL_debug ("Looking for button %s\n", buff);
	  btn = gtk_object_get_data (GTK_OBJECT (k), buff);
	  A4GL_debug ("Got btn=%p\n", btn);
	  if (btn == 0)
	    break;
	  ptr = gtk_object_get_data (GTK_OBJECT (btn), "Value");
	  A4GL_debug ("Got value=%s - compare to %s\n", ptr, s);
	  if (strcmp (ptr, s) == 0)
	    {
	      A4GL_debug ("Ok - set it\n");
	      gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (btn), 1);
	      return 1;
	    }
	}
      return 0;
    }

  if (A4GL_aubit_strcasecmp (ptr, "CALENDAR") == 0)
    {
      int da;
      int d, m, y;
      char ss[100];
      strcpy (ss, s);
      //A4GLSQL_set_status (0, 0);
      A4GL_trim (ss);
      if (strlen (ss) == 0)
	{
	  gtk_calendar_clear_marks (GTK_CALENDAR (k));
	  return 0;
	}

      A4GL_debug ("s set to %s\n", ss);
      A4GL_push_variable (&ss, 0x140000);
      A4GL_pop_var2 (&da, 7, 0);
      A4GL_debug ("Got date as %d\n", da);

      if (a4gl_status != 0)
	return 1;
      A4GL_debug ("Everything seems ok...");

      A4GL_push_variable (&da, 0x7);
      aclfgl_day (1);
      A4GL_pop_var2 (&d, 2, 0);

      A4GL_push_variable (&da, 0x7);
      aclfgl_month (1);
      A4GL_pop_var2 (&m, 2, 0);

      A4GL_push_variable (&da, 0x7);
      aclfgl_year (1);
      A4GL_pop_var2 (&y, 2, 0);

      gtk_calendar_select_month (GTK_CALENDAR (k), m, y);
      gtk_calendar_select_day (GTK_CALENDAR (k), d);
      return 1;
    }

  if (A4GL_aubit_strcasecmp (ptr, "SCROLLBAR") == 0)
    {
      gdouble d;
      d = atof (s);
      gtk_adjustment_set_value ((GtkAdjustment *) GTK_ENTRY (k), d);
      /*
         #define GTK_ENTRY(obj)                  (GTK_CHECK_CAST ((obj), GTK_TYPE_ENTRY, GtkEntry))

         void       gtk_adjustment_set_value             (GtkAdjustment   *adjustment,
         gfloat           value);
       */
      return 1;
    }

/* NEWWIDGET - Add here */

  return 0;
}






/* ================================== EOF ============================== */
