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
# $Id: cr_funcs.c,v 1.11 2003-10-09 13:02:54 afalout Exp $
#*/

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


#include "a4gl_lib_ui_gtk_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int widget_next_size;

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

int lastWidth=0;
int lastHeight=0;

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
A4GL_size_widget (GtkWidget * w, int width)
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
    y = y * YHEIGHT-(YHEIGHT/2);
  else
    y = 1 * YHEIGHT;		/* Use 1 character height */

  gtk_widget_set_usize (GTK_WIDGET (w), x, y);

  lastWidth=x;
  lastHeight=y;
}


/**
 * Create a pixmap from the information stored in a file.
 *
 * @param filename The name of the file where the pixmap is stored.
 * @return The pixmap widget.
 */
//GtkWidget *

void *
A4GL_make_pixmap_gw (char *filename)
{
  GdkPixmap *p;
  GtkWidget *pixmap;
  A4GL_debug ("Making pixmap from file:%s\n", filename);
  p = gdk_pixmap_colormap_create_from_xpm (0,
					   gdk_colormap_get_system (), NULL,
					   NULL, filename);
  if (p == 0)
    {
      printf ("Bad pixmap...");
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
    GtkWidget *widget, *window, *hbox;
	GdkPixbuf *pixbuf, *resized;

  //window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //g_signal_connect(G_OBJECT(window), "destroy",
                     //G_CALLBACK(gtk_main_quit), NULL);
    //gtk_window_set_title(GTK_WINDOW(window), "GtkPixbuf - scaling - bilinear");
    //gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);

    //hbox = gtk_hbox_new(FALSE, 10);
  printf ("Making pixmap from file:%s\n", filename);
  A4GL_trim(filename);


  pixbuf = gdk_pixbuf_new_from_file (filename,NULL);


  widget = gtk_image_new();
  A4GL_size_widget(widget,get_widget_next_size());
  resized = gdk_pixbuf_scale_simple(pixbuf, lastWidth-20, lastHeight-20, GDK_INTERP_BILINEAR);




  if (pixbuf==0||resized==0) {
		printf("Make pixmap failed...");
  }

  gtk_image_set_from_pixbuf(widget,resized);
  gdk_pixbuf_unref(resized);


  gtk_widget_show(widget);
  printf("pixmap=%p\n",pixbuf);
  //gtk_box_pack_start(GTK_BOX(hbox), widget, FALSE, FALSE, 2);

    g_object_unref(pixbuf);




 //gtk_widget_show(hbox);
 gtk_widget_show(widget);
return widget;
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
  filename = A4GL_find_param ("FILENAME");

  A4GL_debug ("Making picture filename=%s\n", filename);
  pixmap = A4GL_make_pixmap_gw (filename);

  A4GL_add_signal_grab_focus (pixmap, 0);
  A4GL_add_signal_clicked (pixmap, 0);
  return pixmap;
}

GtkWidget *
A4GL_cr_pixbuf (void)
{
  GtkWidget *pixmap;
  char *filename;
  filename = A4GL_find_param ("FILENAME");

  A4GL_debug ("Making picture filename=%s PIXBUF\n", filename);
  pixmap = A4GL_make_pixbuf_gw (filename);
  //A4GL_add_signal_grab_focus (pixmap, 0);
  //A4GL_add_signal_clicked (pixmap, 0);

	gtk_widget_show(pixmap);

  printf("Made : %p\n",pixmap);
  A4GL_add_signal_clicked ((GtkWidget *) pixmap, 0);
  A4GL_add_signal_grab_focus ((GtkWidget *) pixmap, 0);


      
  return pixmap;
}



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

  label = A4GL_find_param ("*LABEL");
  image = A4GL_find_param ("*IMAGE");

  b = (GtkButton *) gtk_button_new ();
  v = (GtkVBox *) gtk_vbox_new (0, 3);
  gtk_container_add (GTK_CONTAINER (b), GTK_WIDGET (v));


  if (label)
    {
      if (strlen (label))
	{
	  l = (GtkLabel *) gtk_label_new (label);
	  gtk_container_add (GTK_CONTAINER (v), GTK_WIDGET (l));
	  gtk_widget_show (GTK_WIDGET (l));
	  gtk_object_set_data (GTK_OBJECT (b), "LABEL", l);
#if GTK_CHECK_VERSION(2,0,0)
 A4GL_ChangeWidgetFont(l,"FIXED");
#endif
	}
    }

  if (image)
    {
      if (strlen (image))
	{
	  pixmap = A4GL_make_pixmap_gw (image);
	  gtk_container_add (GTK_CONTAINER (v), GTK_WIDGET (pixmap));
	  gtk_widget_show (pixmap);
	  gtk_object_set_data (GTK_OBJECT (b), "IMAGE", image);
	}
    }
  gtk_widget_show (GTK_WIDGET (v));	/* Vbox */
  gtk_widget_show (GTK_WIDGET (b));	/* Button itself.. */

  A4GL_add_signal_clicked ((GtkWidget *) b, 0);
  A4GL_add_signal_grab_focus ((GtkWidget *) b, 0);
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
      sprintf (buff, "L%d", a + 1);
      A4GL_debug ("Finding label %s\n", buff);
      ptr = A4GL_find_param (buff);
      A4GL_debug ("   %s\n", ptr);

      btn = gtk_radio_button_new_with_label (btn_grp, ptr);
      btn_grp = (GSList *) gtk_radio_button_group (GTK_RADIO_BUTTON (btn));
      gtk_box_pack_start (GTK_BOX (hbox), btn, TRUE, TRUE, 0);
      gtk_widget_show (btn);
      sprintf (buff, "V%d", a + 1);
      ptr = A4GL_find_param (buff);
      A4GL_debug ("Finding value %s = %s\n", buff, ptr);
      gtk_object_set_data (GTK_OBJECT (btn), "Value", ptr);
      gtk_object_set_data (GTK_OBJECT (btn), "Parent", hbox);


      sprintf (buff, "B%d", a + 1);
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
  if (maxchars)
    {
      entry = gtk_entry_new_with_max_length (maxchars);
    }
  else
    {
      entry = gtk_entry_new ();
    }
  A4GL_debug ("Created textbox widget %p", entry);
  gtk_widget_show (entry);
  A4GL_add_signal_changed (entry, 0);
  A4GL_add_signal_grab_focus (entry, 0);
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
  caption = A4GL_find_param ("CAPTION");
  label = gtk_label_new (caption);
  gtk_widget_show (label);
  A4GL_add_signal_grab_focus (label, 0);
  A4GL_add_signal_clicked (label, 0);
#if GTK_CHECK_VERSION(2,0,0)
 A4GL_ChangeWidgetFont(label,"FIXED");
#endif
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
      checkbox = gtk_check_button_new_with_label (label);
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


/* ================================== EOF ============================== */
