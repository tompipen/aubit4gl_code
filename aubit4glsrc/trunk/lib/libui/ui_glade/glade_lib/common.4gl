# Start

code
#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>

#define WINCODE 'w'
#define FORMCODE 'f'
#define IDCODE 'i'
endcode


function get_widget_for(lv_form,lv_field)
define lv_form INTEGER
define lv_field INTEGER
define lv_ok INTEGER
if not form_is_open(lv_form) then
code
	A4GL_debug(" FORM NOT OPEN when trying to get widget %s..",A4GL_find_gui_id_name_from_id(lv_field));
endcode
	display "***************************************FORM NOT OPEN when trying to get widget..."
	return 0
end if
code
{
	
	GtkWidget *w; // This should be a top level window...
	char *wname;
	GtkWidget *widget;
	static void *lform=0;
	static int lfield=0;
	static llv_ok=0;

	if (lv_form==lform && lv_field==lfield ) lv_ok=llv_ok;
	else {
		w=(GtkWidget *)lv_form;
		if (w==0) {
			A4GL_exitwith("Invalid Form");
			lv_ok=0;
		} else {
			wname=A4GL_find_gui_id_name_from_id(lv_field);
			if (wname==0) {
				A4GL_exitwith("Unknown widget ID");
				lv_ok=0;
			} else {
				//printf("Getting widget by name : %s from %p\n",wname,w);
				widget=gtk_object_get_data(GTK_OBJECT(w),wname);
				lv_ok=(long)widget;
				lform=lv_form;
				lfield=lv_field;
				llv_ok=lv_ok;
			}
		}
	}
}
//printf("Returning : %d\n",lv_ok);
endcode
return lv_ok
end function




function yield()
code
      while (gtk_events_pending ())
        gtk_main_iteration ();
endcode
end function

function beep()
code
gdk_beep();
endcode
end function
