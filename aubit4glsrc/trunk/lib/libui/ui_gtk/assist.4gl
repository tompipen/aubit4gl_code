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
# $Id: assist.4gl,v 1.4 2003-01-27 05:47:36 afalout Exp $

# ASSIST.4gl
#
# This is a helper module for wrapping all the GTK stuff thats callable
# from 4GL
#
# TODO: create Doc4GL style comments for functions using 4glDoc

code
/*
====================================================================
File assist.c was created from assist.4gl using 4glc compiler.

If you need to change something, edit assist.4gl, and NOT assist.c
====================================================================
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

extern int frame_style;
extern int ui_mode;
extern int window_frame_type;
extern GtkWidget *win_screen;
extern GtkWidget *currwindow;

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define CHK_UI if (ui_mode!=1) {exitwith("Not in GUI mode");return 0;} else {debug("UI mode ok");}


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void * find_curr_window(void);
void store_filename(GtkFileSelection *selector, gpointer user_data);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
void *
find_curr_window(void) 
{
void *w;
	w=get_curr_win_gtk();
	if (gtk_object_get_data(w,"TOP")) {
		debug("Has parent...");
		w=gtk_object_get_data(w,"TOP");
	}
	return w;
}
endcode


#########################################################################
# Set a window title
#########################################################################
function set_window_title(s)
define s char(256)
#define w integer
code
CHK_UI
	trim(s);
	gtk_window_set_title(GTK_WINDOW(find_curr_window()),s);
endcode
#
end function

#########################################################################
# Get a window title
#########################################################################
function get_window_title(s) 
define s char(256)
code
CHK_UI
	trim(s);
	gtk_window_set_title(GTK_WINDOW(get_curr_win_gtk()),s);
endcode
end function


#########################################################################
#
#########################################################################
function set_window_icon(s)
define s char(256)
define w integer
code
CHK_UI
	trim(s);
	w=(int)make_pixmap(s);   //warning: assignment makes integer from pointer without a cast

	trim(s);
	//gtk_window_set_icon(GTK_WINDOW(find_curr_window()),w,0,0); ?
endcode
#
end function

########################################################################
# Call this before 'END MAIN' if you have any menu or formhandlers
########################################################################
function run_gui()
code
CHK_UI
  while (1) {
    a4gl_usleep (100);
	gui_run_til_no_more ();
  }
endcode
end function

########################################################################
# This sets the frame style used for the 
# 4GL windows (frames). This should be called before the
#
#            OPEN WINDOW....
#
# and will be in effect until another call is made.
#
#
# This can be set to 
#
#  GTK_SHADOW_NONE       = 0
#  GTK_SHADOW_IN         = 1 ** DEFAULT
#  GTK_SHADOW_OUT        = 2
#  GTK_SHADOW_ETCHED_IN  = 3
#  GTK_SHADOW_ETCHED_OUT = 4
#
#######################################################################
function set_frame_style(s)
define s integer
code
CHK_UI
frame_style=s;
endcode
end function

#######################################################################
# Call this function periodically
#
# if you are running a large loop in order to keep the GUI updated
#
#######################################################################
function yeild()
code
CHK_UI
  gui_run_til_no_more ();
endcode
end function

#######################################################################
# This sets the window type
# Currently there are two possible values
#   0  - Normal Mode (Default)
#  99  - Tear off mode
#
# In tear off mode - the user can take your window and move it off the
# 'screen' window to somewhere else on their desktop.
#
# Can't think of too many practical uses for this - but it may be useful
# for housing menus in etc.
#######################################################################
function set_window_type(a)
define a integer
code
CHK_UI
window_frame_type=a;
endcode
end function

#########################################################################
#
#########################################################################
function set_prompt_style(a)
define a integer
code
CHK_UI
gui_prompt_style(a);
endcode
end function


#########################################################################
#
#########################################################################
code
GtkWidget *file_selector;
char selected_filename[256]="";

void
store_filename(GtkFileSelection *selector, gpointer user_data)
{
	strcpy(selected_filename , gtk_file_selection_get_filename (GTK_FILE_SELECTION(file_selector)));
}
endcode

########################################################################
# get_filename..
########################################################################
function get_filename(title,deffile,pattern)
define title char(256)
define fname char(256)
define deffile char(256)
define pattern char(256)
code
{
	GtkWidget *b;
	GtkWidget *w;
	
	
	CHK_UI
	trim(title);
	trim(deffile);
	trim(pattern);
	file_selector = gtk_file_selection_new(title);
	gtk_file_selection_set_filename(GTK_FILE_SELECTION(file_selector),deffile);
	gtk_file_selection_complete(GTK_FILE_SELECTION(file_selector),pattern);

	b=GTK_FILE_SELECTION(file_selector)->ok_button;
	w=GTK_FILE_SELECTION(file_selector)->fileop_dialog;

	//gtk_window_set_modal(w,1);

	gtk_signal_connect (GTK_OBJECT (b), "clicked", GTK_SIGNAL_FUNC (store_filename), 0);

	/* Ensure that the dialog box is destroyed when the user clicks a button. */
#if (! defined(__CYGWIN__) && ! defined(__MINGW32__))
	gtk_signal_connect_object (GTK_OBJECT (b),
	                                       "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy),
	                                       (gpointer) file_selector);

	gtk_signal_connect_object (GTK_OBJECT (GTK_FILE_SELECTION(file_selector)->cancel_button),
	                                       "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy),
	                                       (gpointer) file_selector);
#endif
	/* Display that dialog */

	gtk_widget_show (file_selector);
	while (1) {
	    a4gl_usleep (100);
	 	gui_run_til_no_more ();
		if (strlen(selected_filename)!=0) {
			break;
		}
	}
	strcpy(fname,selected_filename);
}
endcode
return fname
end function

# Get win_Screen
#########################################################################
#
#########################################################################
function app_top_get()
define a integer
code
CHK_UI
a= (long)win_screen;
endcode
return a;
end function


#########################################################################
#
#########################################################################
function app_hide()
code
CHK_UI
gtk_widget_hide(win_screen);
endcode
end function

#########################################################################
#
#########################################################################
function app_show()
code
CHK_UI
gtk_widget_show(win_screen);
endcode
end function

#########################################################################
#
#########################################################################
function app_maximize()
code
CHK_UI
// Needs coding
endcode
end function

#########################################################################
#
#########################################################################
function app_minimize()
code
CHK_UI
// Needs coding
endcode
end function

#########################################################################
#
#########################################################################
function app_restore()
code
CHK_UI
// Needs coding
endcode
end function


#########################################################################
#
#########################################################################
function entry_max_chars_set(g,l)
define l integer
define g integer
code
CHK_UI
gtk_entry_set_max_length(GTK_ENTRY(g),l);
endcode
end function



#########################################################################
#
#########################################################################
function entry_selected_cut(g)
define g integer
code
{
CHK_UI
	gtk_editable_cut_clipboard(GTK_EDITABLE(g));
}
endcode
end function

#########################################################################
#
#########################################################################
function entry_selected_copy(g)
define g integer
code
{
CHK_UI
	gtk_editable_copy_clipboard(GTK_EDITABLE(g));
}
endcode
end function

#########################################################################
#
#########################################################################
function entry_selected_paste(g)
define g integer
code
{
CHK_UI
	gtk_editable_paste_clipboard(GTK_EDITABLE(g));
}
endcode
end function


#########################################################################
#
#########################################################################
function entry_selection_set(g,s,e)
define s,e integer
define g integer
code
{
CHK_UI
	gtk_editable_select_region(GTK_EDITABLE(g),(gint)s,(gint)e);
}
endcode
end function

#########################################################################
#
#########################################################################
function entry_text_get(g)
define g integer
code
{
	char *s;
CHK_UI
	debug("g=%d %x",g,g);
	s=gtk_editable_get_chars(GTK_EDITABLE(g),0,-1);
	push_char(s);
	g_free(s);
	return 1;
}
endcode
end function


#########################################################################
#
#########################################################################
function field_hide(g)
define g integer
code
debug("Hiding field %p\n",g);fflush(stdout);
//CHK_UI
debug("g=%p\n",g);
gtk_widget_hide((GtkWidget *)g);
endcode
end function

#########################################################################
#
#########################################################################
function field_show(g)
define g integer
code
CHK_UI
gtk_widget_show((GtkWidget *)g);
endcode
end function

#########################################################################
#
#########################################################################
function form_caption_get()
code
CHK_UI
	//gtk_window_get_title(get_curr_win_gtk());
endcode
end function

#########################################################################
#
#########################################################################
function form_hide()
code
CHK_UI
	gtk_widget_hide(GTK_WIDGET(get_curr_win_gtk()));
endcode
end function

#########################################################################
#
#########################################################################
function form_show()
code
CHK_UI
	gtk_widget_show(GTK_WIDGET(get_curr_win_gtk()));
endcode
end function

#########################################################################
#
#########################################################################
function form_is_open(s)
define s integer
code
CHK_UI
	//void *find_param (char *name);
	//if (find_param(s,WINCODE)) push_int(1);
	if ((int)find_param((char *)WINCODE)) push_int(1);
	else push_int(0);
	return 1;
endcode
end function


#########################################################################
#
#########################################################################
code
static int tolist(GtkWidget *a) {
	a=gtk_object_get_data(GTK_OBJECT(a),"Child");
	return (int)a;
}
endcode


#########################################################################
#
#########################################################################
function list_count_get(g)
define g integer
code
CHK_UI
	g=tolist(GTK_WIDGET(g));
	push_int(GTK_CLIST(g)->rows);
	return 1;
endcode
end function

#########################################################################
#
#########################################################################
function list_current_get(s)
define s integer
code
CHK_UI
{
GList* sel ;
s=tolist(GTK_WIDGET(s));
sel = GTK_CLIST(s)->selection;
push_int(sel ? (int)(sel->data) :  -1);
return 1;
}
endcode
end function

#########################################################################
#
#########################################################################
function list_delete(s,n)
define s,n integer
code
CHK_UI
	s=tolist(GTK_WIDGET(s));
gtk_clist_remove(GTK_CLIST(s),n);
endcode
end function

#########################################################################
#
#########################################################################
function list_insert(s,n,str)
define s,n integer
define str char(512)
code
CHK_UI
	s=tolist(GTK_WIDGET(s));
trim(str);
gtk_clist_insert((GtkCList *)s,(gint)n,(char **)&str);
endcode
end function

#########################################################################
#
#########################################################################
function list_selected(s,n)
define s,n integer
code
CHK_UI
{
GList* sel ;
s=tolist(GTK_WIDGET(s));
sel = GTK_CLIST(s)->selection;
}
//
endcode
end function


function splat_with_image(img_file,w) 
define w integer
define img_file char(256)
define lv_config char(512)
let w=100
let lv_config="filename='",img_file clipped,"';width='",w using "<<<<","'"
code
CHK_UI
{
GtkWidget *widget;
GtkWidget *cw;
trim(lv_config);
widget=make_widget("pixmap",lv_config,w);
gtk_widget_show(widget);
cw=GTK_WIDGET(get_curr_win_gtk());
gtk_fixed_put (GTK_FIXED (cw), widget, 0, 20);
gtk_widget_show(cw);
}
endcode
end function

# ================================= EOF ================================
