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
# $Id: widget.c,v 1.4 2002-10-13 11:44:40 afalout Exp $
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


#ifndef OLD_INCL

	struct s_widgets widgets[]={
	/*   Widget Type  cr_ function     parameters (placeholder).. */
		{""			, cr_textbox	,{"MAXCHARS",0} 			},
		{"TEXT" 	, cr_textbox	,{"MAXCHARS",0} 			},
		{"ENTRY"	, cr_textbox	,{"MAXCHARS",0} 			},
		{"BUTTON"	, cr_button		,{"*LABEL","*IMAGE",0} 		},
		{"CHECK"	, cr_check		,{0} 						},
		{"LABEL"	, cr_label		,{"CAPTION",0} 				},
		{"PIXMAP"	, cr_picture	,{"FILENAME",0} 			},
		{"COMBO"	, cr_combo		,{0} 						},
		{"RADIO"	, cr_radio		,{"NUM",0} 					},
		{"LIST"		, cr_list		,{0} 						},

		/* NOTE : Calendar needs about 22 characters wide by 7 lines */
		{"CALENDAR"	, cr_calendar	,{0} 						},
		/* 	NEWWIDGET 	*/
		{ "SCROLLBAR",cr_scrollbar 	,{0}						},
		/*
		{ "IMAGE"	, gtk_image_new	,{0}						},
		{ "LIST"	, gtk_list_new	,{0} 						},
		{ "MENU"	, gtk_menu_new	,{0} 						},
		{ "PROGRESS", gtk_progress_bar_new, {0} 				},
		{ "ARROW"	, cr_arrow		,{"TYPE","SHADOW",0} 		},
		{ "CALENDAR", gtk_calendar_new,{"MONTH","YEAR",0} 		},
        */
	{ 0 }
	};
#endif


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/*
this should be in a4gl_aubit_lib.h but it's different all over the
place - see a4gl_aubit_lib.h
*/
int gen_field_chars (GtkWidget *** field_list,	GtkWindow * cwin,...);

GtkWidget * make_widget (char *widget, char *config, int w);
char * decode_config (struct_form * f, int a);
char * decode_comments (struct_form * f, int a);
char * decode_widget (struct_form * f, int a);
GtkWidget * fgl_fieldnametoid(char *f,char *s,int n);

#ifdef OLD_INCL
	int KeySnooper (GtkWidget *grab_widget, GdkEventKey *event, gpointer func_data);
#endif
int strnullcmp(char *s1,char *s2);
int widget_name_match(GtkWidget *w,char *name);

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
make_widget (char *widget, char *config, int w)
{
int a;
GtkWidget *ptr;
char *buff;

  buff = strdup (config);
  split_config (buff);
  debug ("Making widget %s, %s\n", widget, config);
  for (a = 0; widgets[a].name; a++)
    {
      if (strcasecmp (widget, widgets[a].name) == 0)
	{
	  char *key;
	  widget_next_size=w;
	  debug("Making type %d",a);
	  ptr = widgets[a].make ();
	  debug("SIzing widget (%p)",ptr);
	  size_widget (ptr, w);
          dump_mem((char *)ptr);
 	  key = find_param ("*KEY");
	  if (key) {
			gtk_object_set_data(GTK_OBJECT(ptr),"KEY",key);
	  }


	gtk_object_set_data(GTK_OBJECT(ptr),"WIDGETSNAME",widget);

	if (strcasecmp(widget,"PIXMAP")!=0&&strcasecmp(widget,"LIST")!=0) {
		gtk_widget_set_sensitive (ptr, 0);
	}
	  return ptr;
	}
    }


	debug("No widget of that type available...");
	exitwith("Invalid Widget");
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
decode_config (struct_form * f, int a)
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
decode_comments (struct_form * f, int a)
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
decode_widget (struct_form * f, int a)
{
  int b;
  debug ("Decode widget a=%d\n", a);
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
  debug ("   Not found...\n");
  return "";
}


/**
 * Debug function to debug what was the last field created.
 *
 * @param txt A message to help in the debugging process.
 */
void
debug_last_field_created(char *txt)
{
  debug("Doing some debugging stuff on widget %p - %s\n",last_field_created,txt);
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
add_widget (int metric_no, struct_form * f,
	    GtkWidget * panel_to_add_to_window)
{
  struct_metrics *metric;
  GtkWidget *new_widget;
  char buff[256];


  debug("In add_widget");
  metric = &f->metrics.metrics_val[metric_no];

  if (strlen (metric->label) != 0)
    {
	debug("Is a label");
      /* Just a peice of text - create a label */
      new_widget = gtk_label_new (metric->label);

      gtk_fixed_put (GTK_FIXED (get_window_gtk (metric->scr)), new_widget,
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
      debug ("Is a field");
      w = metric->w;

      attr = find_attrib_from_metric (f, metric_no);

      if (attr == -1)
	{
	  debug ("attr=-1");
	  return;
	}

      ptr = decode_widget (f, attr);
      debug("decode_widget returns %s\n",ptr);
      if (strcmp (ptr, "") == 0)
	{
          debug("Must be an entry..");
	  ptr = "ENTRY";
	}

      comments = decode_comments (f, attr);

      new_widget = make_widget (ptr,
				decode_config (f, attr), w);

      if (new_widget == 0)
	{
	  debug ("Error new_widget=0 ptr='%s'\n", ptr);
	  exit (0);
	}

      gtk_object_set_data (GTK_OBJECT (new_widget), "Attribute",
			   &f->attributes.attributes_val[attr]);

      gtk_object_set_data (GTK_OBJECT (new_widget), "Metric", metric);

      debug ("Adding WidgetType '%s'....to %p\n", ptr,new_widget);
      gtk_object_set_data (GTK_OBJECT (new_widget), "WidgetType", ptr);



      /* Get the form.field[sub] identifier */
      strcpy (buff, make_field_from_metric (f, metric_no));
      gtk_object_set_data (GTK_OBJECT (new_widget), "Field", strdup (buff));

      strcpy (buff, make_colname_from_metric (f, metric_no));
      debug("Adding colname for %p - %s", new_widget,strdup (buff));

      gtk_object_set_data (GTK_OBJECT (new_widget), "Colname", strdup (buff));


      debug("Setting metric->field=%p",new_widget);
      metric->field = (int)new_widget;

      gtk_object_set_data (GTK_OBJECT (panel_to_add_to_window), strdup (buff),
			   new_widget);

      /* Add this to the current form as an object... */
      gtk_object_set_data (
			  (GtkObject *) get_window_gtk(metric->scr), 
				buff,
			  new_widget
			);

      gtk_fixed_put (GTK_FIXED (get_window_gtk (metric->scr)), new_widget,
		     (metric->x - 1) * XWIDTH, metric->y * 20);


      debug ("Comments='%s'\n", comments);

      if (strlen (comments) == 0)
	{
	  comments = "No help";
	}

      gtk_tooltips_set_tip (GTK_TOOLTIPS (tooltips), new_widget, comments,
			    comments);

      gtk_widget_show (new_widget);
      last_field_created=new_widget;
	debug_last_field_created("add_widget");
    }

}

/**
 * Gets the widget by the name of the field wanted.
 *
 * @param s The field name
 * @param n
 * @return w A pointer too the widget with the name passed.
 */
GtkWidget *
fgl_fieldnametoid(char *f,char *s,int n)
{
GtkWidget *formdets;
GtkWidget *w;
int nofields;
GtkWidget **field_list=0;
  
  if (ui_mode!=1)
  {
	  exitwith("Not in GUI mode");
	  return 0;
  }

  debug("fgl_fieldnametoid (%p,%d)",s,n);


  formdets = (GtkWidget *)get_curr_form ();
  debug("Getting field list formdets=%p parent=%p",formdets,gtk_object_get_data((GtkObject*)formdets,"PARENT"));

  /* debug("Getting field list formdets=%p parent=%p",formdets,gtk_object_get_data(formdets,"TOP")); */


  exitwith ("serious bug in widget.c");

  nofields = gen_field_chars (&field_list, (GtkWindow *)formdets, s,n,0);

  debug("done Getting field list - nofields=%d",nofields);

  if (nofields!=-1) w=field_list[0];
  else w=0;
  debug("field_list=%p\n",field_list);
  free(field_list);
  return w;
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
KeySnooper (GtkWidget *grab_widget, GdkEventKey *event, gpointer func_data)
{
  debug("Key Snooper... %p %p %p\n",grab_widget,event,func_data);
  debug ("Key Pressed! %x %x (%s)\n", event->keyval, event->state,
	gtk_accelerator_name(event->keyval,event->state)
  );


  if (event->keyval==0xffbe&&event->state==1) 
  {
    debug("Toggle console...");
	console_toggle();
  }

  fflush(stdout);
  keypress(grab_widget,event,func_data);
  clr_error_gtk();
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
widget_name_match(GtkWidget *w,char *name)
{
void *s;
	if (w==0) return 0;
	s=gtk_object_get_data(GTK_OBJECT(w),"Attribute");
	if (s==0) return 0;
	return attr_name_match(s,name);

}



/* ============================== EOF =============================== */
