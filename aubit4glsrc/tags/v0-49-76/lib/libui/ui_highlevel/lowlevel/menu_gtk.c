/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# $Id: menu_gtk.c,v 1.5 2005-03-09 15:15:26 mikeaubury Exp $
#*/

/**
 * @file
 * aubit 4gl compiled menus load in GTK mode, 
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */



/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define ACL4GLGTK

/*
=====================================================================
		                    Includes
=====================================================================
*/


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
#include "menu_x.x.h"


static char *module_id="$Id: menu_gtk.c,v 1.5 2005-03-09 15:15:26 mikeaubury Exp $";


#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>     /* GDK_Down */


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/** Tooltip widget */
GtkWidget *tooltips_menu = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


char *A4GL_mn_caption (char *s);
char *A4GL_mn_help (char *s);
//void  A4GL_show_menu               (char *menuid, void *handler);
void A4GL_endis_menuitems (int en_dis, ...);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Get the caption part of the menu definition.
 *
 * The caption is the one that is before the new line.
 *
 * @param s The string with the menu definition.
 * @return The caption part.
 */
char *
A4GL_mn_caption (char *s)
{
  static char buff[256];
  char *ptr;
  strcpy (buff, s);
  ptr = strchr (buff, '\n');
  if (ptr == 0)
    return s;
  *ptr = 0;
  return buff;
}

/**
 * Return the help part of a string.
 *
 * The help part is after a new line.
 *
 * @param s The string where to get the help part.
 * @return A pointer to the string wanted.
 */
char *
A4GL_mn_help (char *s)
{
  static char buff[256];
  char *ptr;
  strcpy (buff, s);
  ptr = strchr (buff, '\n');
  if (ptr == 0)
    return "";
  return ptr + 1;
}

/**
 * Create a menu.
 *
 * @param menubar
 * @param parent
 * @param xdrm
 * @param id
 * @param type
 * @param handler
 * @return A pointer to the widget created.
 */
static GtkWidget *
make_menus (GtkWidget * menubar, GtkWidget * parent, menu_list * xdrm, char *id, int type, void *handler)
{
  menu *mm;
  menu_option_item *o;
  GtkWidget *w;
  GtkWidget *nmenu;
  GtkWidget *submenu;
  int a;
  int b;
  int cnt = 0;
  char buff[256];

  A4GL_debug ("Trying to make menu %s parent=%p\n", id, parent);

  for (a = 0; a < xdrm->menus.menus_len; a++)
    {
      mm = &xdrm->menus.menus_val[a];
      A4GL_debug ("Found menu %s - %s\n", mm->id, id);
      if (strcasecmp (mm->id, id) == 0)
	{			/* We've found our menu */
	  A4GL_debug ("Found it\n");
	  nmenu = gtk_menu_new ();
	  A4GL_debug ("Create new menu\n");
	  A4GL_debug ("has %d options\n", mm->options.options_len);
	  for (b = 0; b < mm->options.options_len; b++)
	    {
	      o = &mm->options.options_val[b];
	      A4GL_debug ("Adding option %s %s %s\n", o->caption, o->id, o->image);
	      if (strlen (o->submenu_id) != 0)
		{
		  A4GL_debug ("Has a submenu\n");
		  submenu =
		    make_menus (menubar, nmenu, xdrm, o->submenu_id, 2,
				handler);
		}
	      else
		{
		  submenu = 0;
		}
	      /* o = &mm->options.options_val[b]; */

	      A4GL_trim (o->image);
	      A4GL_trim (o->caption);

	      if (strlen (A4GL_mn_caption (o->image)) == 0)
		{
		  A4GL_debug ("Caption - no image");
		  w = gtk_menu_item_new_with_label (A4GL_mn_caption (o->caption));
		  if (strlen (A4GL_mn_help (o->caption)))
		    gtk_tooltips_set_tip (GTK_TOOLTIPS (tooltips_menu), w,
					  A4GL_mn_help (o->caption),
					  A4GL_mn_help (o->caption));
		  gtk_widget_show (w);
		}
	      else
		{
		  GtkHBox *h;
		  GtkLabel *l;
		  GtkWidget *pixmap;
		  A4GL_debug ("Caption & image ?");
		  w = gtk_menu_item_new ();
		  h = GTK_HBOX (gtk_hbox_new (0, 0));
		  gtk_container_add (GTK_CONTAINER (w), GTK_WIDGET (h));
		  A4GL_debug ("Added hbox");
		  if (strlen (A4GL_mn_caption (o->caption)))
		    {
		      if (strlen (A4GL_mn_caption (o->caption)))
			{
			  A4GL_debug ("Adding label");
			  l =
			    GTK_LABEL (gtk_label_new
				       (A4GL_mn_caption (o->caption)));
			  gtk_label_set_justify (l, GTK_JUSTIFY_LEFT);
			  gtk_box_pack_start (GTK_BOX (h), GTK_WIDGET (l), 0,
					      0, 0);
			  gtk_widget_show (GTK_WIDGET (l));
			}
		    }

		  A4GL_debug ("making image");
		  pixmap = A4GL_make_pixmap_gw (o->image);

		  A4GL_debug ("Make image from pixmap");
		  gtk_box_pack_end (GTK_BOX (h), GTK_WIDGET (pixmap), 0, 0,
				    0);
		  A4GL_debug ("SHowing");
		  gtk_widget_show (GTK_WIDGET (pixmap));
		  gtk_widget_show (GTK_WIDGET (h));

		}

	      gtk_object_set_data (GTK_OBJECT (w), "Parent", menubar);
	      gtk_object_set_data (GTK_OBJECT (w), "Caption",
				   A4GL_mn_caption (o->caption));
	      gtk_object_set_data (GTK_OBJECT (w), "ID", o->id);
	      sprintf (buff, "ID:%s", o->id);
	      gtk_object_set_data (GTK_OBJECT (menubar), buff, w);

	      sprintf (buff, "MENUITEM%d", cnt++);
	      gtk_object_set_data (GTK_OBJECT (menubar), buff, w);
	      if (parent == menubar)
		{
		  gtk_menu_bar_append (GTK_MENU_BAR (menubar), w);
		}
	      else
		{
		  gtk_menu_append (GTK_MENU (nmenu), w);
		}
	      gtk_widget_show (w);

	      gtk_signal_connect_object (GTK_OBJECT (w),
					 "activate",
					 GTK_SIGNAL_FUNC (handler),
					 (gpointer) o->id);

	      /*gtk_signal_connect_object (GTK_OBJECT (w), "activate-item",
	         GTK_SIGNAL_FUNC (handler),
	         ret); */

	      if (strlen (o->submenu_id) != 0)
		{
		  gtk_menu_item_set_submenu (GTK_MENU_ITEM (w), submenu);
		}

	    }
	  A4GL_debug ("All done\n");
	  return nmenu;
	}
    }
  A4GL_debug ("Menu not found\n");
  return 0;
}

/**
 * Create a menu item list.
 *
 * @param m
 * @param id
 * @param mode
 * @param handler
 * @return A pointer to the menu widget created.
 */
void * A4GL_LL_create_menu (menu_list * m, char *id, int mode, void *handler)
{
  GtkWidget *menubar;
  GtkWindow *cwin;
  extern GtkWidget *win_screen;
  /* Get the vbox associated with the current window */
//  cwin = GTK_WINDOW (A4GL_get_curr_win_gtk ());
//not sure if this is correct; A4GL_get_curr_win_gtk is no longer in API:


  cwin = win_screen;

  /* Is there a menu bar there already ? */
  menubar = gtk_object_get_data (GTK_OBJECT (cwin), "MENUBAR");

  if (menubar)
    {				/* Yes - remove it */
      gtk_container_remove (GTK_CONTAINER (cwin), menubar);
    }

  /* Create a new menubar */
  menubar = gtk_menu_bar_new ();

  gtk_widget_set_usize (GTK_WIDGET (menubar), A4GL_get_curr_width () * XWIDTH,
			YHEIGHT);


  /* I don't think this one is required when reading from menu files
     But it won't hurt */
  gtk_object_ref (GTK_OBJECT (menubar));


  gtk_object_set_data (GTK_OBJECT (cwin), "MENUBAR", menubar);
  gtk_object_set_data (GTK_OBJECT (menubar), "MASTERWIN", cwin);

  gtk_widget_show (GTK_WIDGET (menubar));

  /* gtk_box_pack_start (GTK_BOX (v), menubar, FALSE, FALSE, 2); */
  gtk_fixed_put (GTK_FIXED (cwin), GTK_WIDGET (menubar), 0, 0);
  make_menus (menubar, menubar, m, id, 1, handler);
  A4GL_debug ("Make menubar\n");

  gtk_object_set_data (GTK_OBJECT (menubar), "selected", (void *) -1);
  return (void *)menubar;
}


/**
 *
 * This is used from compile_c_gtk.c to check if Menu item does exist.
 * FIXME: not implemented
 */
int
A4GL_mn_itemexists (char *menuitem)
{
  return 1;
}


/**
 * Enable or disable menuitems in GTK gui mode.
 *
 * @param en_dis Indicate if we want to enable or disable.
 *   - 0 : Disable
 *   - 1 : Enable
 * @param ... The list of the items to be afected.
 */
void
A4GL_endis_menuitems (int en_dis, ...)
{
  va_list ap;
  GtkWidget *cwin;
  GtkWidget *menubar;
  GtkWidget *w;
  char *ptr = 0;
  char buff[256];
  va_start (ap, en_dis);
  printf ("endis:%d\n", en_dis);
  A4GL_debug ("*****enable/disable menuitems\n");
  //cwin = GTK_WIDGET (A4GL_get_curr_win_gtk ());

//not sure if this is correct; A4GL_get_curr_win_gtk is no longer in API:
  cwin = GTK_WIDGET (A4GL_get_currwin_name ());




  /* v=gtk_object_get_data(cwin,"vbox"); */

  menubar = gtk_object_get_data (GTK_OBJECT (cwin), "MENUBAR");
  A4GL_debug ("menubar=%d", menubar);

  if (menubar == 0)
    {
      printf ("No menu");
      A4GL_exitwith ("No menu displayed");
      return;
    }

  while (ptr)
    {
      ptr = va_arg (ap, char *);
      printf ("ptr=%s\n", ptr);
      if (ptr == 0)
	break;
      sprintf (buff, "ID:%s", ptr);
      A4GL_debug ("Looking for %s", buff);
      w = gtk_object_get_data (GTK_OBJECT (menubar), buff);
      if (w)
	{
	  A4GL_debug ("Found");
	  gtk_widget_set_sensitive (w, en_dis);
	}
      else
	{
	  printf ("No Widget\n");
	  A4GL_debug ("No widget\n");
	  A4GL_exitwith ("Invalid menu ID");
	  return;
	}
    }
}


/* =================================== EOF ============================= */
