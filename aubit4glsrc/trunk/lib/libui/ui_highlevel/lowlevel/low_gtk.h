
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>     /* GDK_Down */


#define DIALOG_DISABLE_NONE             0
#define DIALOG_DISABLE_PROGRAM          1
#define DIALOG_DISABLE_ALL              2

#define BUTTON_OK                       1
#define BUTTON_CANCEL                   2
#define BUTTON_ABORT                    3
#define BUTTON_RETRY                    4
#define BUTTON_IGNORE                   5
#define BUTTON_YES                      6
#define BUTTON_NO                       7

#define BUTTONS_OK                      0
#define BUTTONS_OK_CANCEL               1
#define BUTTONS_RETRY_CANCEL            2
#define BUTTONS_ABORT_RETRY_IGNORE      3
#define BUTTONS_YES_NO                  4
#define BUTTONS_YES_NO_CANCEL           5
#ifndef DECLARE_DIMENSIONS
	extern int gui_xwidth;
	extern int gui_yheight;
#else
	int gui_xwidth = 10;
	int gui_yheight = 25;
#endif

#define XWIDTH gui_xwidth
#define YHEIGHT gui_yheight

#if ! GTK_CHECK_VERSION(2,0,0)
	//Function g_locale_to_utf8 introduced in GTK+ V 2
	//This is to allow us to compile with 1.x
        #define g_locale_to_utf8(a,b,c,d,e) g_strdup(a)
        #define g_locale_from_utf8(a,b,c,d,e) g_strdup(a)
#endif

//GTK2 only:
//#include <gtk/gtklabel.h>   /* gtk_label_set_use_markup() */

