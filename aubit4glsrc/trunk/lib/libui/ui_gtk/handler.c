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
# $Id: handler.c,v 1.1 2002-06-26 06:11:44 afalout Exp $
#*/

/**
 * @file
 * Gtk event handling.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#ifdef OLD_INCL

	#include <ctype.h>
	#include <gtk/gtk.h>

	#ifdef __CYGWIN__
		#include <gdk/gdk.h>
		#include <glib.h>
		#include <stdio.h>
	#endif

	#include "a4gl_gtk_buttons.h"
	#include "a4gl_formxw.h"
	#include "a4gl_aubit_lib.h"			/* set_last_key() */
	#include "a4gl_debug.h"

#else

    #include "a4gl_lib_ui_gtk_int.h"

#endif


/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define ACL4GLGTK

#ifdef __CYGWIN__
	#define g_malloc malloc
	#define g_free free
#endif

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern char *desc_str[];
extern char *desc_bool[];
extern char *widgettype;
extern char *field;
int cnt = 0;
int keypressed = -1;
int beforefield = -1;
GtkWidget *actionfield=0;
int onfield = -1;

/** Last key pressed by the user */
int lastkey=0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#ifdef OLD_INCL
	void clear_something (void);
	int user_has_done_something (void);
	GtkWidget * get_which_field (void);
	int which_key (void);
	int keypress (GtkWidget * widget, GdkEventKey * event, gpointer user_data);
	void func (GtkWidget * w, char *mode);
	int gui_get_lastkey(void);
#endif


void
upshift_insert_text_handler (GtkEntry * entry,
			     const gchar * text,
			     gint length, gint * position, gpointer data);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Clear something that could been ocurred.
 */
void
clear_something (void)
{
  onfield = -1;
  beforefield = -1;
  actionfield = 0;
  field = 0;
  keypressed = -1;
}

/**
 * The user as done something.
 *
 * Find what he does and return the action code.
 *
 * @return The action code:
 *   - 0 : The user does not done nothing.
 *   - 1 : Some key pressed.
 *   - 2 : Before field ocurred.
 *   - 3 : On field ocurred ????
 *
 */
int
user_has_done_something (void)
{
/* printf("%d %d %d\n",keypressed,beforefield,onfield); */
  if (keypressed != -1)
    return 1;

  if (beforefield != -1)
    return 2;

  if (onfield != -1)
    return 3;

  return 0;
}

/**
 * Return the action field.
 *
 * @todo Define what is the action field.
 */
GtkWidget *
get_which_field (void)
{
  {debug("Returning action field : %p",actionfield);}
  return actionfield;
}

/**
 * Return the key that the user has pressed.
 */
int
which_key (void)
{
  return keypressed;
}

/**
 * Not used
 */
/*
static int
mja_keyval_from_name(char *s)
{
  if (key_val(s))
	  return key_val(s);
  else
		return (int)gdk_keyval_name((guint)s);
}
*/

/**
 * Handler function for user key pressed.
 *
 * @param The widget that send the event.
 * @param A pointer to a event describing structure.
 * @param user_data
 * @return
 */
int
keypress (GtkWidget * widget, GdkEventKey * event, gpointer user_data)
{

  debug ("Key Pressed! %x %x (%s)\n", event->keyval, event->state,gdk_keyval_name(event->keyval));fflush(stdout);

  if (event->state & 4)
    {				/*  Control key held down... */
      if (tolower (event->keyval) >= 'a' && tolower (event->keyval) <= 'z')
	keypressed = tolower (event->keyval) - 'a' + 1;
      else
	keypressed = -1;
    }
  else
    {
      keypressed = event->keyval;
    }

  lastkey=keypressed;
  set_last_key(lastkey);
  debug("setting action field=%p",widget);
  actionfield = widget;
return 0;
}

/**
 * Default func to be used as a listener callback for handling an event.
 * @param w The widget where the event ocurred.
 * @param mode
 */
void
func (GtkWidget * w, char *mode)
{

	debug("MJAMJA (func)- widget=%p\n",w);
	if (gtk_object_get_data(GTK_OBJECT(w),"HANDLER")!=0)
	{
		/* void (*hand)(); */
		void (*hand)(GtkWidget * w, char *mode);

		debug("MJAMJA------------> Own handler....\n");
		hand=gtk_object_get_data(GTK_OBJECT(w),"HANDLER");
		hand(w,mode);
		return;
	}

	debug("in func");
	debug ("!**** func ---%p '%s' (%s:%s)\n", w, mode, widgettype, field);
	fflush(stdout);
	debug ("**** func ---%p '%s' (%s:%s)\n", w, mode, widgettype, field);

  if (strcasecmp(mode,"grab_focus")==0) 
  {
      debug("grab focus detected...\n");
      fflush(stdout);

      debug("setting action field=%p",w);
      actionfield=w;

      beforefield=1;
      return ;
  }

  if (strcmp(mode,"clicked")==0)
    {
      char *key;
	  int m;
      onfield = 1;
	  debug("setting action field=%p",w);
      actionfield = w;

      key=gtk_object_get_data(GTK_OBJECT(w),"KEY");

      debug("Key=%p\n",key);fflush(stdout);

      if (key) 
	  {
		debug("Substituting specified key: %s\n",key);fflush(stdout);

		if (strcasecmp(key,"ACCEPT")==0)  
		{
			keypressed=27; /* FIXME */
		}  
		else 
		{
			if (strcasecmp(key,"INTERRUPT")==0)
			{
				keypressed=3; /* FIXME */
			}
			else
			{
				gtk_accelerator_parse(key,&keypressed,(GdkModifierType *)&m);
				if (m&4 && tolower(keypressed)>='a' && tolower(keypressed)<='z') keypressed=tolower(keypressed)-'a'+1;
				debug("keypressed=%x m=%x\n",keypressed,m);fflush(stdout);
			}
		}
      }
    }


#ifdef TESTING
  /*
  if (strcmp (field, "formonly.btn1[0]") == 0
      && strcmp (mode, "clicked") == 0)
    {
      testfunc ();
    }
    */
#endif


	debug("All done");
return;
}


/**
 * Event handling for working with the upshift attribute of a form field.
 *
 * @param A pointer to the entry widget.
 * @param text The text inserted.
 * @param length The length of the text inserted.
 * @param position The position in the text field.
 * @param data
 */
void
upshift_insert_text_handler (GtkEntry * entry,
			     const gchar * text,
			     gint length, gint * position, gpointer data)
{
  GtkEditable *editable = GTK_EDITABLE (entry);
  int i, count = 0;
  gchar *result = g_new (gchar, length);

  for (i = 0; i < length; i++)
    {
      result[count++] = islower (text[i]) ? toupper (text[i]) : text[i];
    }

  if (count > 0)
    {
      gtk_signal_handler_block_by_func (GTK_OBJECT (editable),
					GTK_SIGNAL_FUNC
					(upshift_insert_text_handler), data);
      gtk_editable_insert_text (editable, result, count, position);
      gtk_signal_handler_unblock_by_func (GTK_OBJECT (editable),
					  GTK_SIGNAL_FUNC
					  (upshift_insert_text_handler),
					  data);
    }
  gtk_signal_emit_stop_by_name (GTK_OBJECT (editable), "insert_text");

  g_free (result);
}

/**
 * Get the last key typed by the user.
 *
 * @return The last key typed.
 */
int
gui_get_lastkey(void)
{
  return lastkey;
}


/* =============================== EOF ================================= */
