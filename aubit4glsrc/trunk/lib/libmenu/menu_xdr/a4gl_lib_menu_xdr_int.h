

#include "a4gl_lib_menu_int.h"


	/* ============== from a4gl_menuxw.h ==================== */


	#ifdef __CYGWIN__
	    /* missing from rpcgen generated form_x.h on CygWin: */
		#define bool_t int
		#define u_int unsigned int
	

		#include <rpc/rpc.h>

	#endif


	#include "menu_x.h"


	#include "a4gl_lib_ui_gtk_int.h" /* make_pixmap */
	
	
	
	#include <gdk/gdk.h>
	#include <gtk/gtk.h>


