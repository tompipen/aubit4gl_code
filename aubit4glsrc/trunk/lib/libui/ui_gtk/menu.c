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
# $Id: menu.c,v 1.13 2003-07-28 07:04:15 mikeaubury Exp $
#*/

/**
 * @file
 * Menu implementation for GTK Gui mode.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_lib_ui_gtk_int.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define ACL4GLGTK

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/**
 * The tooltips used to display the long description of options.
 */
extern GtkWidget *tooltips;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

//void A4GL_disp_h_menu (void *m);
//int A4GL_menu_loop (void *m);
//void A4GL_free_menu (void *m);
//void A4GL_next_option (void *menu, char *nextopt);
//void A4GL_menu_hide (void *m, va_list * ap);
//void A4GL_menu_show (void *m, va_list * ap);
//void *A4GL_new_menu_create (char *title, int x, int y, int mn_type, int help_no);
//void A4GL_add_menu_option (void *menubar, char *txt, char *keys, char *desc, int helpno, int attr);
//void A4GL_finish_create_menu (void *menubar);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Declaration of the event handler 
 *
 * @todo : THIS IS WRONG WRONG WRONG
 * @todo : GTK is supposed to give w,p looks like it p,w
 *
 * @param w The item object that called this handler
 * @param p The 
 */
static void
handler (GtkMenuItem * w, int p)
{
  GtkWidget *k;
  A4GL_debug ("Menu Option %p %p\n", w, p);
  A4GL_debug ("menu click");
  k = (GtkWidget *) gtk_object_get_data ((GtkObject *) p, "Parent");
  A4GL_debug ("Parent k=%p\n", k);
  gtk_object_set_data (GTK_OBJECT (k), "selected", w);
}



/**
 * Display a 4gl menu in gtk mode.
 *
 * Assume that all the information about the menu is allready initialized.
 *
 * Called by the generated C program.
 *
 * @param m The menu information. The only call to this function gives us a
 * ACL_Menu pointer here.
 */
void
A4GL_disp_h_menu (void *m)
{
  GtkWidget *a;
  GtkWindow *cwin;

  A4GL_clr_error_gtk ();
  cwin = (GtkWindow *) gtk_object_get_data (GTK_OBJECT (m), "MASTERWIN");

  a = (GtkWidget *) gtk_object_get_data (GTK_OBJECT (cwin), "MENUBAR");
  A4GL_debug ("in gui_disp_h_menu\n");
  if (a == 0)
    {
      A4GL_debug
	("no current menu - must have been a child thats not there anymore\n");
      /* v=gtk_object_get_data(cwin,"vbox"); */
      gtk_widget_show ((GtkWidget *)m);
      gtk_object_set_data (GTK_OBJECT (cwin), "MENUBAR", m);
      gtk_widget_show ((GtkWidget *)m);
      printf ("gtk_fixed_put(%p, %p, 0,0);\n", cwin, m);
      gtk_fixed_put ((GtkFixed *) cwin, (GtkWidget *)m, 0, 0);
      /* gtk_box_pack_start_defaults(v, m); */
      A4GL_debug ("Redisplayed me\n");
    }
}

/**
 * The menu loop implementation for GTK UI.
 *
 * @param m A pointer to the menu strutcure.
 * @return 
 */
int
A4GL_menu_loop (void *m)
{
  int a;
  GtkWidget *menubar;
  GtkWindow *cwin;
#ifdef DEBUG
  A4GL_debug ("Seting up menu");
#endif

/* Check were still up... */
  cwin = (GtkWindow *) gtk_object_get_data (GTK_OBJECT (m), "MASTERWIN");

  menubar = (GtkWidget *) gtk_object_get_data (GTK_OBJECT (cwin), "MENUBAR");
  if (menubar == 0)
    {
#ifdef DEBUG
      A4GL_debug ("no current menu - must have been a child\n");
#endif
      /* v=gtk_object_get_data(cwin,"vbox"); */
      gtk_widget_show (m);
      gtk_object_set_data (GTK_OBJECT (cwin), "MENUBAR", m);
      gtk_widget_show (m);
      printf ("gtk_fixed_put(%p, %p, 0,0);\n", cwin, m);
      gtk_fixed_put ((GtkFixed *) cwin, m, 0, 0);
#ifdef DEBUG
      A4GL_debug ("Redisplayed menu\n");
#endif
    }
  else
    {
      gtk_widget_hide (m);
      gtk_widget_show (m);
    }

  gtk_object_set_data (GTK_OBJECT (m), "selected", (gpointer) - 1);

#ifdef DEBUG
  A4GL_debug ("Entering menu loop");
#endif

  while (1)
    {
      a4gl_usleep (100);
      A4GL_gui_run_til_no_more ();

      a = (int) gtk_object_get_data (GTK_OBJECT (m), "selected");

      if (a != -1)
	{
#ifdef DEBUG
	  A4GL_debug ("A=%x", a);
#endif
	}

      if (a != -1)
	{
	  A4GL_clr_error_gtk ();
#ifdef DEBUG
	  A4GL_debug ("Exiting menu loop");
#endif
	  return a;
	}
    }
}

/**
 * Not used - NOT SO! IT IS USED.
 * OK, so how about a little descripton on HOW and WHERE it's used? TIA.
 *
 * 4GL call
 */
int A4GL_free_menu (void *m)
{
  GtkWindow *cwin;
  A4GL_debug ("Free menu...");
  cwin = (GtkWindow *) gtk_object_get_data (GTK_OBJECT (m), "MASTERWIN");
  gtk_object_set_data (GTK_OBJECT (cwin), "MENUBAR", (gpointer) 0);
  /* v=gtk_object_get_data(cwin,"vbox"); */
  gtk_container_remove ((GtkContainer *) cwin, m);
  A4GL_debug ("Freed menu\n");
return 1;
}

/**
 * Find the menu item.
 *
 * @param m A pointer to the menu.
 * @param s A string with the item name.
 * @return The pointer to the item widget. NULL if not found.
 */
static GtkWidget *
find_menu_item (void *m, char *s)
{
  int a;
  char buff[256];
  char *ptr;
  GtkWidget *widget;
  for (a = 0;; a++)
    {
      sprintf (buff, "MENUITEM%d", a);
      A4GL_debug ("MNTEST Looking for menuitem %s in menu %p", s, m);
      widget = (GtkWidget *) gtk_object_get_data (GTK_OBJECT (m), buff);

      if (widget)
	{
	  A4GL_debug ("MNTEST Found..");
	  ptr = (char *) gtk_object_get_data (GTK_OBJECT (widget), "Caption");
	  if (ptr)
	    {
	      if (strcasecmp (ptr, s) == 0)
		return widget;
	    }
	}
    }
  A4GL_debug ("MNTEST Not found..");
  return (GtkWidget *) 0;
}

/**
 * Execute the NEXT OPTION part of MENU statement.
 *
 * In GTK GUI mode have no efect.
 *
 * @param menu
 * @param nextop.
 */
void
A4GL_next_option (void *menu, char *nextopt)
{
  A4GL_debug ("next option - Has no effect in GUI mode");
}

/**
 * Not used but maybe should be.
 */
int
A4GL_menu_hide_ap (void *m, va_list * ap)
{
  GtkWidget *w;
  char *argp_c;
  A4GL_debug ("menu_hide - %p", m);
  while (1)
    {
      argp_c = va_arg (*ap, char *);
      if (argp_c == 0)
	break;
      A4GL_debug ("Finding %s\n", argp_c);
      w = find_menu_item (m, argp_c);
      if (w == 0)
	{
	  A4GL_exitwith ("Bad option - not in the menu");
	  return 0;
	}
      gtk_widget_hide (w);
    }
return 1;
}

/**
 * Show an item of the menu in GUI GTK mode.
 *
 * @param m The menu name.
 * @param ap The optionlist to be showed.
 */
int
A4GL_menu_show_ap (void *m, va_list * ap)
{
  GtkWidget *w;
  char *argp_c;

  while (1)
    {
      argp_c = va_arg (*ap, char *);
      if (argp_c == 0)
	break;
      w = find_menu_item (m, argp_c);
      if (w == 0)
	{
	  A4GL_exitwith ("Bad option - not in the menu");
	  return 0;
	}
      gtk_widget_show (w);
    }
return 1;
}


/**
 * Not used.
 */
/*
GtkWidget *
A4GL_new_menu (char *title, int x, int y, int mn_type, int help_no, int nopts,
va_list *ap)
{

  GtkWidget *menubar;
  //GtkWidget *fglmenu;
  GtkWindow *cwin;
  GtkWidget *w;
  GtkVBox *v;
  char buff[256];
  int cnt = 0;

  char *argp_c;
  int ret;

  if (nopts < 1)
    return 0;

  A4GL_debug ("Create window - title=%s", title);
  cwin = (GtkWindow *)get_curr_win_gtk ();
  //v=gtk_object_get_data(cwin,"vbox");
  menubar = (GtkWidget *)gtk_object_get_data (GTK_OBJECT (cwin), "MENUBAR");

  if (menubar)
    {
      printf (" gtk_container_remove(%p,%p);\n", cwin, menubar);
      gtk_container_remove (GTK_CONTAINER(cwin), menubar);
    }

  menubar = gtk_menu_bar_new ();
  gtk_object_ref (GTK_OBJECT(menubar));
  gtk_object_set_data (GTK_OBJECT (cwin), "MENUBAR", menubar);
  gtk_object_set_data (GTK_OBJECT (menubar), "MASTERWIN", cwin);
  gtk_widget_show (menubar);

  gtk_widget_set_usize (GTK_WIDGET (menubar),get_curr_width()*XWIDTH , YHEIGHT);
  printf ("gtk_fixed_put(%p, %p, 0,0);\n", cwin, menubar);

  gtk_fixed_put((GtkFixed *)cwin, menubar, 0, 0);
  //fglmenu=gtk_menu_new();
  A4GL_trim (title);
  if (strlen (title))
    {
      w = gtk_menu_item_new_with_label (title);
      gtk_widget_show (w);
      gtk_menu_bar_append (GTK_MENU_BAR (menubar), w);
    }


	//## "Option n", command key,short help text,help_no,attributes
  for (ret = 0; ret < nopts; ret++)
    {
      argp_c = va_arg (*ap, char *);
      w = gtk_menu_item_new_with_label (argp_c);

      A4GL_debug ("Add item %s", argp_c);

      gtk_signal_connect_object (
			  GTK_OBJECT (w), 
				"activate",
				GTK_SIGNAL_FUNC (handler), 
				(gpointer)ret
			);

      gtk_menu_bar_append (GTK_MENU_BAR (menubar), w);
      gtk_object_set_data (GTK_OBJECT (w), "Parent", menubar);
      gtk_object_set_data (GTK_OBJECT (w), "Caption", argp_c);

      sprintf (buff, "MENUITEM%d", cnt++);
      gtk_object_set_data (GTK_OBJECT (menubar), buff, w);
      gtk_widget_show (w);
      argp_c = va_arg (*ap, char *); // Key List

      argp_c = va_arg (*ap, char *); // Help
	if (strlen(argp_c))
      gtk_tooltips_set_tip (GTK_TOOLTIPS (tooltips), w, argp_c, argp_c);

      argp_c = va_arg (*ap, char *);
      argp_c = va_arg (*ap, char *);
    }

  gtk_object_set_data (GTK_OBJECT (menubar), "selected",(gpointer)-1);
  return menubar;
}

*/

/**
 * Create a new menu in GTK GUI mode.
 *
 * @param title The menu title.
 * @param x The column where to be created.
 * @param y The line where to be created.
 * @param mn_type The menu type:
 *   - Boxed
 *   - ???
 * @param help_no The help number of the menu.
 * @return A pointer to the widget that implements the menu.
 */
void *
A4GL_new_menu_create (char *title, int x, int y, int mn_type, int help_no)
{
  GtkWidget *menubar;
  GtkWindow *cwin;
  GtkWidget *w;

  A4GL_debug ("Create window - title=%s", title);
  cwin = GTK_WINDOW (A4GL_get_curr_win_gtk ());
  A4GL_debug ("Got cwin as %p\n", cwin);

  menubar = (GtkWidget *) gtk_object_get_data (GTK_OBJECT (cwin), "MENUBAR");

  if (menubar)
    {
      gtk_container_remove (GTK_CONTAINER (cwin), menubar);
    }

  menubar = gtk_menu_bar_new ();
  gtk_object_ref (GTK_OBJECT (menubar));
  gtk_object_set_data (GTK_OBJECT (cwin), "MENUBAR", menubar);
  gtk_object_set_data (GTK_OBJECT (menubar), "MASTERWIN", cwin);
  gtk_widget_show (menubar);
  gtk_widget_set_usize (GTK_WIDGET (menubar), A4GL_get_curr_width () * XWIDTH,
			YHEIGHT);
  gtk_object_set_data (GTK_OBJECT (menubar), "NOPTS", (gpointer) 0);
  printf ("gtk_fixed_put(%p, %p, 0,0);\n", cwin, menubar);
  gtk_fixed_put ((GtkFixed *) cwin, menubar, 0, 0);
  A4GL_trim (title);

  if (strlen (title))
    {
      w = gtk_menu_item_new_with_label (title);
      gtk_widget_show (w);
      gtk_menu_bar_append (GTK_MENU_BAR (menubar), w);
    }

  return menubar;
}



/**
 * Add a new menu option/item in GTK GUI mode.
 *
 * Generated in the C output file. Executed in run-time.
 *
 * @param menu A pointer to the menu structure.
 * @param txt The text of the option (immediatly after command)
 * @param keys The keys if so
 * @param desc The text long description (in GTK is a implemented as tooltip).
 * @param helpno The help number.
 * @param attr The attributes
 */
void
A4GL_add_menu_option (void *menubar, char *txt, char *keys, char *desc, int helpno,
		 int attr)
{
  GtkWidget *w;
  char buff[256];
  int cnt;

  w = gtk_menu_item_new_with_label (txt);

  gtk_menu_bar_append (GTK_MENU_BAR (menubar), w);
  gtk_object_set_data (GTK_OBJECT (w), "Parent", menubar);
  gtk_object_set_data (GTK_OBJECT (w), "Caption", txt);
  cnt = (int) gtk_object_get_data (GTK_OBJECT (menubar), "NOPTS");
  cnt++;
  gtk_signal_connect_object (GTK_OBJECT (w),
			     "activate",
			     GTK_SIGNAL_FUNC (handler), (gpointer) cnt - 1);
  sprintf (buff, "MENUITEM%d", cnt);
  A4GL_debug ("MJA - cnt = %d\n", cnt);
  gtk_object_set_data (GTK_OBJECT (menubar), buff, w);
  gtk_object_set_data (GTK_OBJECT (menubar), "NOPTS", (gpointer) cnt);
  gtk_widget_show (w);

  /*
     argp_c = va_arg (*ap, char *); // Key List
     argp_c = va_arg (*ap, char *); // Help
   */
  if (strlen (desc))
    gtk_tooltips_set_tip (GTK_TOOLTIPS (tooltips), w, desc, desc);

  /*
     argp_c = va_arg (*ap, char *);
     argp_c = va_arg (*ap, char *);
   */

}

/**
 * Terminate the menu creation in GTK GUI mode.
 *
 * Executed by the generated code at run-time after the menu created and all
 * the items inserted.
 *
 * @param menu The menu structure (GtkWidget).
 */
void
A4GL_finish_create_menu (void *menubar)
{
  gtk_object_set_data (GTK_OBJECT (menubar), "selected", (gpointer) - 1);
}

/* ============================== EOF ================================ */
