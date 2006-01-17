*
* API specs for MENU library interface - used by dlmagic script
* to create API_menu.c (try "make API_menu.c")
*
* Note - there are no spaces for void* int* etc.
*
*
*
* Name of the API:
LIBRARY MENU
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_MENUTYPE
LIB_PREFIX A4GLMENU_
*
* Function calls definitions:
* func-name param-type param-name ... -> returns
*
*we should not make libaubit4gl depend on GTK headers - but how do I then
*return GtkWidget* ? Just return void*
*#include <gdk/gdk.h>
*#include <gtk/gtk.h>

* Name of the header file to be referenced with #include
*HEADER_FILE API_menu.h



/* ------- functions from lib/libmenu/menu_XXX/loadmenu.c */


/* int mn_itemexists (char *menuitem) */
A4GL_mn_itemexists char* menuitem -> int
A4GL_load_menu char* fname,char* menu_id,int mode,void* handler -> void*
A4GL_show_menu char* menuid,void* handler -> void
A4GL_write_menu void* menul -> void

/*  ============================ EOF ============================   */



