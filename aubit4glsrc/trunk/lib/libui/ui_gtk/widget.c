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
# $Id: widget.c,v 1.18 2003-10-11 08:41:38 afalout Exp $
#*/

/**
 * @file
 * Widget creation and initialization.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

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

extern int ui_mode;

extern GtkWidget *tooltips;

/** A pointer to the last widget (input widgets) created */
GtkWidget *last_field_created;

int widget_next_size;

/** Descriptions of the string widget properties */
char *desc_str[] = {
  "INCLUDE",
  "PICTURE",
  "FORMAT",
  "DEFAULT",
  "PROGRAM",
  "WIDGET",
  "CONFIG",
  "COMMENTS",
  0
};

/** Descriptions of widget boolean properties */
char *desc_bool[] = {
  "AUTONEXT",
  "REVERSE",
  "INVISIBLE",
  "NOENTRY",
  "VERIFY",
  "WORDWRAP",
  "COMPRESS",
  "UPSHIFT",
  "DOWNSHIFT",
  "REQUIRED",
  0
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


#define A4GL_GTK_FONT_FIXED "Fixed 10"


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/*
this should be in a4gl_aubit_lib.h but it's different all over the
place - see a4gl_aubit_lib.h
*/
//int A4GL_gen_field_chars_ap (GtkWidget *** field_list, GtkWindow * cwin, ...);


char *	A4GL_decode_config 	(struct_form * f, int a);
char *	A4GL_decode_comments (struct_form * f, int a);
char *	A4GL_decode_widget 	(struct_form * f, int a);
int 	A4GL_strnullcmp 	(char *s1, char *s2);



/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Create a widget
 *
 * @param widget The widget type.
 * @param config The optional config string attribute.
 * @param w The width of the widget.
 */
GtkWidget *
A4GL_make_widget (char *widget, char *config, int w)
{
  int a;
  GtkWidget *ptr;
  char *buff;

  buff = strdup (config);
  A4GL_split_config (buff);
  A4GL_debug ("Making widget %s, %s\n", widget, config);
  for (a = 0; widgets[a].name; a++)
    {
      if (strcasecmp (widget, widgets[a].name) == 0)
	{
	  char *key;
	  widget_next_size = w;
	  A4GL_debug ("Making type %d", a);
	  ptr = widgets[a].make ();
	  A4GL_debug ("SIzing widget (%p)", ptr);
	  A4GL_size_widget (ptr, w);
	  A4GL_dump_mem ((char *) ptr);
	  key = A4GL_find_param ("*KEY");
	  if (key)
	    {
	      gtk_object_set_data (GTK_OBJECT (ptr), "KEY", key);
	    }


	  gtk_object_set_data (GTK_OBJECT (ptr), "WIDGETSNAME", widget);

	  if (strcasecmp (widget, "PIXMAP") != 0
	      && strcasecmp (widget, "LIST") != 0)
	    {
	      gtk_widget_set_sensitive (ptr, 0);
	    }
	  return ptr;
	}
    }


  A4GL_debug ("No widget of that type available...");
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

/**
 *
 * @param f A pointer to the form describing strucutre.
 * @param a The field / attribute number sequence.
 * @return
 */
char *
A4GL_decode_comments (struct_form * f, int a)
{
  int b;
  for (b = 0; b < f->attributes.attributes_val[a].str_attribs.str_attribs_len;
       b++)
    {
      if (f->attributes.attributes_val[a].str_attribs.str_attribs_val[b].
	  type == 7)
	{
	  return f->attributes.attributes_val[a].str_attribs.
	    str_attribs_val[b].value;
	}
    }
  return "";
}

/**
 * Analyse the attributes defined in the form to see if its a
 * specific widget and if so return a string that identify it.
 * 
 * @param f A pointer to the form information.
 * @param a The attribute sequence to access to the attribute array (one for
 * each field).
 * @return The widget type or an empty string if its not a specific wodget.
 */
char *
A4GL_decode_widget (struct_form * f, int a)
{
  int b;
  A4GL_debug ("Decode widget a=%d\n", a);
  for (b = 0; b < f->attributes.attributes_val[a].str_attribs.str_attribs_len;
       b++)
    {
      if (f->attributes.attributes_val[a].str_attribs.str_attribs_val[b].
	  type == FA_S_WIDGET)
	{
	  return f->attributes.attributes_val[a].str_attribs.
	    str_attribs_val[b].value;
	}
    }
  A4GL_debug ("   Not found...\n");
  return "";
}


/**
 * Debug function to A4GL_debug what was the last field created.
 *
 * @param txt A message to help in the debugging process.
 */
void
A4GL_debug_last_field_created (char *txt)
{
  A4GL_debug ("Doing some debugging stuff on widget %p - %s\n", last_field_created,
	 txt);
}

/**
 * Create a GTK widget for implementation of form fields and add it to the
 * panel where the form is displayed.
 *
 * Note that the text pieces of the form are added with a metric_no.
 *
 * If the field is not defined in the form with a specific WIDGET attribute
 * use a tex entry.
 *
 * @param metric_no The metric number of the field to be implemented.
 * @param f A pointer to the strucutre where the information of the form is
 * stored.
 * @panel panel_to_add_to_window Panel where the widgets are layed out.
 */
void
A4GL_add_widget (int metric_no, struct_form * f,
	    GtkWidget * panel_to_add_to_window)
{
  struct_metrics *metric;
  GtkWidget *new_widget;
  char buff[256];


  A4GL_debug ("In add_widget");
  metric = &f->metrics.metrics_val[metric_no];

  if (strlen (metric->label) != 0)
    {
      A4GL_debug ("Is a label");
      /* Just a peice of text - create a label */
      new_widget = gtk_label_new (metric->label);
#if GTK_CHECK_VERSION(2,0,0)
 A4GL_ChangeWidgetFont(new_widget,"FIXED");
#endif

      gtk_fixed_put (GTK_FIXED (A4GL_get_window_gtk (metric->scr)), new_widget,
		     metric->x * XWIDTH, metric->y * 20);
      gtk_widget_show (new_widget);
      metric->field = 0;
    }
  else
    {
      /* As these don't apply to labels, just set them as vars here */
      int w;
      int attr;
      char *ptr;
      char *comments;
      /* Got a proper field.. */
      A4GL_debug ("Is a field");
      w = metric->w;

      attr = A4GL_find_attrib_from_metric (f, metric_no);

      if (attr == -1)
	{
	  A4GL_debug ("attr=-1");
	  return;
	}

      ptr = A4GL_decode_widget (f, attr);
      A4GL_debug ("decode_widget returns %s\n", ptr);
      if (strcmp (ptr, "") == 0)
	{
	  A4GL_debug ("Must be an entry..");
	  ptr = "ENTRY";
	}

      comments = A4GL_decode_comments (f, attr);

      new_widget = A4GL_make_widget (ptr, A4GL_decode_config (f, attr), w);

      if (new_widget == 0)
	{
	  A4GL_debug ("Error new_widget=0 ptr='%s'\n", ptr);
	  exit (0);
	}

      gtk_object_set_data (GTK_OBJECT (new_widget), "Attribute",
			   &f->attributes.attributes_val[attr]);

      gtk_object_set_data (GTK_OBJECT (new_widget), "Metric", metric);

      A4GL_debug ("Adding WidgetType '%s'....to %p\n", ptr, new_widget);
      gtk_object_set_data (GTK_OBJECT (new_widget), "WidgetType", ptr);



      /* Get the form.field[sub] identifier */
      strcpy (buff, A4GL_make_field_from_metric (f, metric_no));
      gtk_object_set_data (GTK_OBJECT (new_widget), "Field", strdup (buff));

      strcpy (buff, A4GL_make_colname_from_metric (f, metric_no));
      A4GL_debug ("Adding colname for %p - %s", new_widget, strdup (buff));

      gtk_object_set_data (GTK_OBJECT (new_widget), "Colname", strdup (buff));


      A4GL_debug ("Setting metric->field=%p", new_widget);
      metric->field = (int) new_widget;

      gtk_object_set_data (GTK_OBJECT (panel_to_add_to_window), strdup (buff),
			   new_widget);

      /* Add this to the current form as an object... */
      gtk_object_set_data ((GtkObject *) A4GL_get_window_gtk (metric->scr),
			   buff, new_widget);

      gtk_fixed_put (GTK_FIXED (A4GL_get_window_gtk (metric->scr)), new_widget,
		     (metric->x - 1) * XWIDTH, metric->y * 20);


      A4GL_debug ("Comments='%s'\n", comments);

      if (strlen (comments) == 0)
	{
	  comments = "No help";
	}

      gtk_tooltips_set_tip (GTK_TOOLTIPS (tooltips), new_widget, comments,
			    comments);

      gtk_widget_show (new_widget);
      last_field_created = new_widget;
      A4GL_debug_last_field_created ("add_widget");
    }

}

/**
 * Gets the widget by the name of the field wanted.
 *
 * @param s The field name
 * @param n
 * @return w A pointer too the widget with the name passed.
 */
int
A4GL_fgl_fieldnametoid (char *f, char *s, int n)
{
  GtkWidget *formdets;
  GtkWidget *w;
  int nofields;
  GtkWidget **field_list = 0;

  if (ui_mode != 1)
    {
      A4GL_exitwith ("Not in GUI mode");
      return 0;
    }

  A4GL_debug ("fgl_fieldnametoid (%p,%d)", s, n);


  formdets = (GtkWidget *) A4GL_get_curr_form (1);
  A4GL_debug ("Getting field list formdets=%p parent=%p", formdets,
	 gtk_object_get_data ((GtkObject *) formdets, "PARENT"));

  /* debug("Getting field list formdets=%p parent=%p",formdets,gtk_object_get_data(formdets,"TOP")); */


  //A4GL_exitwith ("serious bug in widget.c");

  nofields =
    A4GL_gen_field_chars ((void ***) &field_list, (GtkWindow *) formdets, s, n, 0);

  A4GL_debug ("done Getting field list - nofields=%d", nofields);

  if (nofields != -1)
    w = field_list[0];
  else
    w = 0;
  A4GL_debug ("field_list=%p\n", field_list);
  free (field_list);
  return (int) w;
}

/**
 * An event listener to see wath keys the user are typing
 *
 * @param grab_widget The widget active when the user typed a key.
 * @param event A pointer to the structure that describes tyhe event.
 * @param func_data
 * @return Allways zero
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
  if (strcmp(gtk_accelerator_name (event->keyval, event->state),"<Control>c")==0) {
  	A4GL_keypress (grab_widget, event, func_data);
  }

  if (strcmp(gtk_accelerator_name (event->keyval, event->state),"Escape")==0) {
	//event->keyval=27;
  	A4GL_keypress (grab_widget, event, func_data);
  }
  A4GL_clr_error_gtk ();
  return 0;
}




/**
 *
 *
 * @param
 * @param
 * @return
 */
int
A4GL_widget_name_match (void *wv,  char *name)
{
GtkWidget * w;
  void *s;
w=wv;
  if (w == 0)
    return 0;
  s = gtk_object_get_data (GTK_OBJECT (w), "Attribute");
  if (s == 0)
    return 0;
  return A4GL_attr_name_match (s, name);

}

int
get_widget_next_size()
{
        return widget_next_size;
}


#if GTK_CHECK_VERSION(2,0,0)
void A4GL_ChangeWidgetFont(GtkLabel *label,char *font) {
PangoFontDescription    *pfd;
//int a;
A4GL_debug("A4GL_ChangeWidgetFont");
	if (strcmp(font,"FIXED")==0) {
		font=A4GL_GTK_FONT_FIXED;
		A4GL_debug("FONT FIXED MJAMJAMJA");
	} else {
		A4GL_debug("Font : %s",font);
	}


        pfd = pango_font_description_from_string(font);
        /* setting PangoFontDescription to label's layout */
        pango_layout_set_font_description(gtk_label_get_layout(label), pfd);
        /* asking label to resize/redraw itself, without this you'll not see the changes */
        gtk_widget_queue_resize(GTK_WIDGET(label));
        /* freeing PangoFontDescription, cause it has been copied by prev. call */
        pango_font_description_free(pfd);
}

#endif

char *
field_buffer(GtkWidget *w,int n)
{
	// Not implemented yet..
	return A4GL_fld_val_generic (w);
}

/*
A4GL_set_field_attr_with_attr
A4GL_set_field_attr_with_attr_already_determined
A4GL_req_field_input_array
A4GL_field_name_match
A4GL_clr_field
A4GL_get_curr_border
A4GL_get_metric_for


gcc -shared -Wl,--out-implib=TMP.dll.a -Wl,--export-all-symbols -o ../../libUI_G
TK.dll assist.o cr_funcs.o color.o display.o dialog.o d2.o disp_arr.o error.o fi
elds.o frm.o get_fld_val.o gtk_4gl.o giarray.o handler.o input.o menu.o prompt.o
 params.o signals.o window.o widget.o -LD:/cygwin/usr/lib   -ID:/cygwin/lib/glib
-2.0/include -ID:/cygwin/lib/gtk-2.0/include  -LD:/cygwin/lib -L../.. -laubit4gl
 -lgtk-win32-2.0 -lgdk-win32-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lpangowin32-1.0 -lg
di32 -lpango-1.0 -lgobject-2.0 -lgmodule-2.0 -lglib-2.0 -lintl-1 -liconv
Info: resolving _a4gl_status by linking to __imp__a4gl_status (auto-import)
Info: resolving _ui_mode by linking to __imp__ui_mode (auto-import)
Info: resolving _a4gl_sqlca by linking to __imp__a4gl_sqlca (auto-import)
Info: resolving _m_lastkey by linking to __imp__m_lastkey (auto-import)
Info: resolving _abort_pressed by linking to __imp__abort_pressed (auto-import)
Info: resolving _int_flag by linking to __imp__int_flag (auto-import)
Creating library file: TMP.dll.a
giarray.o: In function `process_control_stack':
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/giarray.c:2442: undefined r
eference to `A4GL_set_field_attr_with_attr'
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/giarray.c:2188: undefined r
eference to `A4GL_set_field_attr_with_attr'
giarray.o: In function `A4GL_iarr_arr_fields':
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/giarray.c:2561: undefined r
eference to `A4GL_set_field_attr_with_attr_already_determined'
giarray.o: In function `A4GL_req_field_input_array':
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/giarray.c:2640: undefined r
eference to `A4GL_field_name_match'
giarray.o: In function `A4GL_form_field_chk_iarr':
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/giarray.c:2848: undefined r
eference to `A4GL_clr_field'
giarray.o: In function `A4GL_decode_line_ib':
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/giarray.c:3224: undefined r
eference to `A4GL_get_curr_border'
giarray.o: In function `A4GL_copy_field_data':
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/giarray.c:3378: undefined r
eference to `A4GL_get_metric_for'
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/giarray.c:3380: undefined r
eference to `A4GL_get_metric_for'
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/giarray.c:3422: undefined r
eference to `A4GL_clr_field'
make: *** [../../libUI_GTK.dll] Error 1



gcc -shared -Wl,--out-implib=TMP.dll.a -Wl,--export-all-symbols -o ../../libUI_GTK.dll assist.o cr_funcs.o color.o display.o dialog.o d2.o disp_arr.o error.o fields.o frm.o get_fld_val.o gtk_4gl.o giarray.o handler.o input.o menu.o prompt.o params.o signals.o window.o widget.o -LD:/cygwin/usr/lib   -ID:/cygwin/lib/glib-2.0/include -ID:/cygwin/lib/gtk-2.0/include  -LD:/cygwin/lib -L../.. -laubit4gl -lgtk-win32-2.0 -lgdk-win32-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lpangowin32-1.0 -lgdi32 -lpango-1.0 -lgobject-2.0 -lgmodule-2.0 -lglib-2.0 -lintl-1 -liconv

gcc -shared -Wl,--out-implib=TMP.dll.a -Wl,--export-all-symbols -o ../../libUI_G
TK.dll assist.o cr_funcs.o color.o display.o dialog.o d2.o disp_arr.o error.o fi
elds.o frm.o get_fld_val.o gtk_4gl.o giarray.o handler.o input.o menu.o prompt.o
 params.o signals.o window.o widget.o -LD:/cygwin/usr/lib   -ID:/cygwin/lib/glib
-2.0/include -ID:/cygwin/lib/gtk-2.0/include  -LD:/cygwin/lib -L../.. -laubit4gl
 -lgtk-win32-2.0 -lgdk-win32-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lpangowin32-1.0 -lg
di32 -lpango-1.0 -lgobject-2.0 -lgmodule-2.0 -lglib-2.0 -lintl-1 -liconv
Info: resolving _a4gl_status by linking to __imp__a4gl_status (auto-import)
Info: resolving _ui_mode by linking to __imp__ui_mode (auto-import)
Info: resolving _a4gl_sqlca by linking to __imp__a4gl_sqlca (auto-import)
Info: resolving _m_lastkey by linking to __imp__m_lastkey (auto-import)
Info: resolving _abort_pressed by linking to __imp__abort_pressed (auto-import)
Info: resolving _int_flag by linking to __imp__int_flag (auto-import)
Creating library file: TMP.dll.a
input.o: In function `A4GL_set_field_attr_with_attr':
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/input.c:1020: undefined ref
erence to `A4GL_set_field_colour_attr'
input.o: In function `A4GL_set_field_attr_with_attr_already_determined':
D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libui/ui_gtk/input.c:1043: undefined ref
erence to `A4GL_set_field_colour_attr'
make: *** [../../libUI_GTK.dll] Error 1



*/



/* ============================== EOF =============================== */
