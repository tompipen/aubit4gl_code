#define fgldate long
#include "a4gl_incl_4glhdr.h"
#include "assist.h"
static char _module_name[]="assist.4gl";
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
/* End of code */
extern 
long int_flag;
extern 
long quit_flag;
extern 
long a4gl_status;
extern 
struct {
long sqlcode;
char sqlerrm [72+1];
char sqlerrp [8+1];
long sqlerrd[6];
char sqlawarn [8+1];
char sqlstate [9+1];
} a4gl_sqlca;
extern 
fgldate today;
extern 
char user [8+1];
extern 
long pageno;
extern 
long lineno;
extern 
long usrtime;
extern 
long curr_hwnd;
extern 
long curr_form;
extern 
char err_file_name [32+1];
extern 
long err_file_no;
extern 
char curr_file_name [32+1];
extern 
long curr_line_no;
extern 
long err_status;
extern 
long aiplib_status;
static int _done_init_module_variables=1;
static init_module_variables() {
if (_done_init_module_variables==0) return;
_done_init_module_variables=0;
}
