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
*return GtkWidget* ?
write_menu
load_menu char* fname,char* menu_id,int mode,void* handler -> void*





