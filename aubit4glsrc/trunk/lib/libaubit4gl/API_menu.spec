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
*
* Function calls definitions:
* func-name param-type param-name ... -> returns"
*
*we should not make libaubit4gl depend on GTK headers - but how do I then
*return GtkWidget* ? Just return void*
*#include <gdk/gdk.h>
*#include <gtk/gtk.h>

* Name of the header file to be referenced with #include
*HEADER_FILE API_menu.h



/* ------- functions from lib/libmenu/menu_XXX/loadmenu.c */


/* int mn_itemexists (char *menuitem) */
mn_itemexists char* menuitem -> int

/* char *mn_caption(char *s) */

/* char *mn_help(char *s) */

/* static GtkWidget * make_menus (GtkWidget *menubar, GtkWidget * parent, menu_list * xdrm, char *id, int type, void *handler) */

/* static GtkWidget * create_menu (menu_list *m, char *id, int mode, void *handler) */

/* GtkWidget * load_menu (char *fname, char *menu_id, int mode, void *handler) */
load_menu char* fname,char* menu_id,int mode,void* handler -> void*

/* void show_menu (char *menuid, void *handler) */
show_menu char* menuid,void* handler -> void

/* void endis_menuitems (int en_dis, ...) */

/*  ------- functions from lib/libmenu/menu_xdr/menuwrite.c */

/* void error_with (char *s, char *a, char *b) */

/* void write_menu () */
write_menu -> void


/*  ============================ EOF ============================   */



