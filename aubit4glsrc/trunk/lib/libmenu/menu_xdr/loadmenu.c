/**
 * @file
 * aubit 4gl compiled menus load in GTK mode.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */
#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <strings.h>

/** Tooltip widget */
//extern GtkWidget *tooltips;
GtkWidget *tooltips = 0;
#define DECLARE_DIMENSIONS
#include "a4gl_gtk_dims.h"

//extern GtkWindow *get_curr_win_gtk (void);


//#include "menu_x.h"
#include "a4gl_menuxw.h"
#include "a4gl_io.h"
// 4glhdr.h will eventually include stdlib.h, which uses getenv(), so
// we need to set GETENV_OK and only then include debug.h
#ifdef __CYGWIN__
	#define GETENV_OK
#endif
#include "a4gl_debug.h"
#include "a4gl_incl_4glhdr.h"

#include "a4gl_gtk_cr_funcs.h"
#define ACL4GLGTK

#ifdef __CYGWIN__
#include <rpc/rpc.h>
#endif


/**
 * Get the caption part of the menu definition.
 *
 * The caption is the one that is before the new line.
 *
 * @param s The string with the menu definition.
 * @return The caption part.
 */
char *mn_caption(char *s) 
{
  static  char buff[256];
  char *ptr;
  strcpy(buff,s);
  ptr=strchr(buff,'\n');
  if (ptr==0)  return s;
  *ptr=0;
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
char *mn_help(char *s) 
{
  static  char buff[256];
  char *ptr;
  strcpy(buff,s);
  ptr=strchr(buff,'\n');
  if (ptr==0)  return "";
  return ptr+1;
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
make_menus (GtkWidget *menubar, GtkWidget * parent, menu_list * xdrm,
	    char *id, int type, void *handler)
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

  debug ("Trying to make menu %s parent=%p\n", id, parent);

  for (a = 0; a < xdrm->menus.menus_len; a++)
    {
      mm = &xdrm->menus.menus_val[a];
	debug("Found menu %s - %s\n",mm->id,id);
      if (strcasecmp (mm->id, id) == 0)
	{			// We've found our menu...
	  debug ("Found it\n");
	  nmenu = gtk_menu_new ();
	  debug ("Create new menu\n");
	  debug ("has %d options\n", mm->options.options_len);
	  for (b = 0; b < mm->options.options_len; b++)
	    {
	      o = &mm->options.options_val[b];
	      debug ("Adding option %s %s %s\n", o->caption, o->id,o->image);
	      if (strlen (o->submenu_id) != 0)
		{
		  debug ("Has a submenu\n");
		  submenu =
		    make_menus (menubar, nmenu, xdrm, o->submenu_id, 2,
				handler);
		}
	      else
		{
		  submenu = 0;
		}
	      //o = &mm->options.options_val[b];

	      trim(o->image);
	      trim(o->caption);

	      if (strlen(mn_caption(o->image))==0) {
		debug("Caption - no image");
	      	w = gtk_menu_item_new_with_label (mn_caption(o->caption));
		if (strlen(mn_help(o->caption))) gtk_tooltips_set_tip (GTK_TOOLTIPS (tooltips), w, mn_help(o->caption),mn_help(o->caption) );
		gtk_widget_show(w);
	      } else {
		GtkHBox *h;
		GtkLabel *l;
		GtkWidget *pixmap;
		debug("Caption & image ?");
	      	w = gtk_menu_item_new ();
		h = GTK_HBOX(gtk_hbox_new(0,0));
		gtk_container_add(GTK_CONTAINER(w),GTK_WIDGET(h));
		debug("Added hbox");
		if (strlen(mn_caption(o->caption))) {
			if (strlen(mn_caption(o->caption))){
			debug("Adding label");
				l = GTK_LABEL(gtk_label_new(mn_caption(o->caption)));
				gtk_label_set_justify(l,GTK_JUSTIFY_LEFT);
				gtk_box_pack_start(GTK_BOX(h),GTK_WIDGET(l),0,0,0);
				gtk_widget_show(GTK_WIDGET(l));
			}
		} 

		debug("making image");
		pixmap = make_pixmap (o->image);

		debug("Make image from pixmap");
		gtk_box_pack_end(GTK_BOX(h),GTK_WIDGET(pixmap),0,0,0);
		debug("SHowing");
		gtk_widget_show(GTK_WIDGET(pixmap));
		gtk_widget_show(GTK_WIDGET(h));

 	      }

	      gtk_object_set_data (GTK_OBJECT (w), "Parent", menubar);
	      gtk_object_set_data (GTK_OBJECT (w), "Caption", mn_caption(o->caption));
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

	      gtk_signal_connect_object (
				  GTK_OBJECT (w), 
					"activate",
					GTK_SIGNAL_FUNC (handler), 
					(gpointer)o->id
				);

	      //gtk_signal_connect_object (GTK_OBJECT (w), "activate-item",
	      //GTK_SIGNAL_FUNC (handler),
	      //ret);

	      if (strlen (o->submenu_id) != 0)
		{
		  gtk_menu_item_set_submenu (GTK_MENU_ITEM (w), submenu);
		}

	    }
	  debug ("All done\n");
	  return nmenu;
	}
    }
  debug ("Menu not found...\n");
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
static GtkWidget *
create_menu (menu_list *m, char *id, int mode, void *handler)
{
  int a;
  int b;
  menu *mm;
  GtkWidget *menubar;
  GtkWindow *cwin;
  GtkWidget *w;

// Get the vbox associated with the current window..
  cwin = GTK_WINDOW(get_curr_win_gtk ());

// Is there a menu bar there already ?
  menubar = gtk_object_get_data (GTK_OBJECT (cwin), "MENUBAR");

  if (menubar)
    {				// Yes - remove it
      gtk_container_remove (GTK_CONTAINER(cwin), menubar);
    }

// Create a new menubar
  menubar = gtk_menu_bar_new ();

 gtk_widget_set_usize (GTK_WIDGET (menubar),get_curr_width_gtk()*XWIDTH , YHEIGHT);


// I don't think this one is required when reading from menu files
// But it won't hurt
  gtk_object_ref (GTK_OBJECT(menubar));


  gtk_object_set_data (GTK_OBJECT (cwin), "MENUBAR", menubar);
  gtk_object_set_data (GTK_OBJECT (menubar), "MASTERWIN", cwin);

  gtk_widget_show (GTK_WIDGET(menubar));

  //gtk_box_pack_start (GTK_BOX (v), menubar, FALSE, FALSE, 2);
  gtk_fixed_put (GTK_FIXED(cwin), GTK_WIDGET(menubar), 0, 0);
  make_menus (menubar, menubar, m, id, 1, handler);
  debug ("Make menubar..\n");

  gtk_object_set_data (GTK_OBJECT (menubar), "selected", (void *)-1);
  return menubar;
}

/**
 * Load 4gl menus from a compiled file.
 *
 * @param fname
 * @param menuid The menu name.
 * @param mode
 * @param handler The menu handler name.
 * @return A pointer to the menu widget created.
 */
GtkWidget *
load_menu (char *fname, char *menu_id, int mode, void *handler)
{
  struct menu_list the_menus;
  FILE *f;
  XDR xdrp;
  int a;
  GtkWidget *w;
  char buff[256];

  sprintf (buff, "%s.mnu", fname);
  f = open_file_dbpath  (buff);

  if (f == 0)
    {
      debug ("Unable to open file %s\n", buff);
      exit (2);
    }
  memset (&the_menus, 0, sizeof (menu_list));
  xdrstdio_create (&xdrp, f, XDR_DECODE);
  a = xdr_menu_list (&xdrp, &the_menus);

  if (!a)
    {
      debug ("Bad format\n");
    }
  else
    {
      w = create_menu (&the_menus, menu_id, mode, handler);

    }
  debug ("All done - menubar should be displayed\n");
  gui_run_til_no_more ();
  return w;
}

/**
 * @todo : Confirm that its not used and remove it.
 */
/*
mn_itemexists (void)
{				// FIXME
  return 1;
}
*/

/**
 * Implementation of the SHOW MENU 4gl statement in GTK GUI mode.
 *
 * @param menuid The menu name.
 * @param handler The menu handler name.
 */
show_menu (char *menuid, void *handler)
{
  char *fname;
  void (*p)(char *);
  fname = char_pop ();
  p=handler;
  load_menu (fname, menuid, 0, handler);
  p("__BSM__");
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
endis_menuitems (int en_dis, ...)
{
  int a;
  va_list ap;
  GtkWidget *cwin;
  GtkWidget *menubar;
  GtkWidget *w;
  char *ptr;
  char buff[256];
  va_start (ap, en_dis);
  printf("endis....%d\n",en_dis);
  debug ("*****enable/disable menuitems...");
  cwin = GTK_WIDGET(get_curr_win_gtk ());

  //v=gtk_object_get_data(cwin,"vbox");

  menubar = gtk_object_get_data (GTK_OBJECT (cwin), "MENUBAR");
  debug ("menubar=%d", menubar);

  if (menubar == 0)
    {
	printf("No menu...");
      exitwith ("No menu displayed...");
      return;
    }

  while (ptr)
    {
      ptr = va_arg (ap, char *);
	printf("ptr=%s\n",ptr);
      if (ptr == 0)
	break;
      sprintf (buff, "ID:%s", ptr);
      debug ("Looking for %s", buff);
      w = gtk_object_get_data (GTK_OBJECT (menubar), buff);
      if (w)
	{
	  debug ("Found");
	  gtk_widget_set_sensitive (w, en_dis);
	}
      else
	{
		printf("No Widget\n");
	  debug ("No widget...");
	  exitwith ("Invalid menu ID");
	  return;
	}
    }
}


//==================================================================


//------------------duplicate from gtk_4gl.c:

/** The 4gl current window */
GtkWindow *currwindow = 0;

/**
 * Finds the 4gl current window
 *
 * @return The current window
 */
GtkWindow *get_curr_win_gtk (void)
{
  debug("Current window : %p",currwindow);
  return currwindow;
}

//-------------------duplicate from window.c:

/**
 * Gets the width of the current window (in GTK GUI mode).
 *
 * @return The width of the current window.
 */
int get_curr_width_gtk()
{
  GtkWidget *cwin;
  int width;
	cwin = (GtkWidget *)get_curr_win_gtk ();
  	width = (int)gtk_object_get_data (GTK_OBJECT(cwin), "WIDTH");
	return width;
}


//------------------- duplicate from gtk_4gl.c :

void gui_run_til_no_more (void)
{

  if (screen_mode (-1) )
    {
      while (gtk_events_pending ())
	gtk_main_iteration ();
    } else {
	debug("Skipping run_til_no_more - in pause mode");
    }

}


//-------------------- duplicate from cr_funcs.c :

/**
 * Create a pixmap from the information stored in a file.
 *
 * @param filename The name of the file where the pixmap is stored.
 * @return The pixmap widget.
 */
GtkWidget *
make_pixmap (char *filename)
{
  GdkPixmap *p;
  GtkWidget *pixmap;
  debug("Making pixmap from file:%s\n",filename);
  p = gdk_pixmap_colormap_create_from_xpm (0,
    gdk_colormap_get_system (), NULL,
    NULL, filename
  );
  if (p==0) {
    printf("Bad pixmap...");
    exitwith("Error creating pixmap");
    return 0;
  }

  pixmap = gtk_pixmap_new (p, 0);
  return pixmap;
}






