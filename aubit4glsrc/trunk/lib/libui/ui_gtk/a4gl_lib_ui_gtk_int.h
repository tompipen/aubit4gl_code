

#include "a4gl_lib_ui_int.h"


	#include <gtk/gtk.h>
	#include <gdk/gdkkeysyms.h>         /* GDK_Down */


/*
	#include "a4gl_gtk_buttons.h"
	#include "a4gl_gtk_display.h"
	#include "a4gl_gtk_params.h"
	#include "a4gl_gtk_color.h"
	#include "a4gl_gtk_frm.h"
	#include "a4gl_gtk_widget.h"
	#include "a4gl_gtk_cr_funcs.h"
	#include "a4gl_gtk_get_fld_val.h"
	#include "a4gl_gtk_widget_prot.h"
	#include "a4gl_gtk_d2.h"
	#include "a4gl_gtk_gtk_4gl.h"
	#include "a4gl_gtk_dims.h"
	#include "a4gl_gtk_handler.h"
*/


	/* #include "a4gl_gtk_cr_funcs.h" */

	struct s_widget_funcs {
		/* GtkWidget *(*construct)(); */ /* warning: function declaration isn't a prototype */
        GtkWidget *(*construct)();
		/* GtkWidget *(*setup_signals)(); */ /* warning: function declaration isn't a prototype */
        GtkWidget *(*setup_signals)();
	};

	struct s_widgets {
		char *name;
		/* GtkWidget *(*make)(); */ /* warning: function declaration isn't a prototype */
        GtkWidget *(*make)(void);
		char *params[5];/* up to 5 names parameters
				 These are not used directly from here
	             but its a good place to document them
				 This may be used later for checking when implemented
                 */
	};


	#define DIALOG_DISABLE_NONE    0
	#define DIALOG_DISABLE_PROGRAM 1
	#define DIALOG_DISABLE_ALL     2

	#define BUTTON_OK     1
	#define BUTTON_CANCEL 2
	#define BUTTON_ABORT  3
	#define BUTTON_RETRY  4
	#define BUTTON_IGNORE 5
	#define BUTTON_YES    6
	#define BUTTON_NO     7

	#define BUTTONS_OK 			0
	#define BUTTONS_OK_CANCEL 		1
	#define BUTTONS_RETRY_CANCEL		2
	#define BUTTONS_ABORT_RETRY_IGNORE	3
	#define BUTTONS_YES_NO			4
	#define BUTTONS_YES_NO_CANCEL		5


	int KeySnooper (GtkWidget *grab_widget, GdkEventKey *event, gpointer func_data);

   	char *fld_val_generic (GtkWidget * k);



	void alloc_colors(void);
	void gui_set_field_fore(GtkWidget *w,int attr);
	void gui_set_field_back(GtkWidget *w,int attr);

	GtkWidget *cr_textbox(void);
	GtkWidget *cr_button(void);
	GtkWidget *cr_check(void);
	GtkWidget *cr_label(void);
	GtkWidget *cr_picture(void);
	GtkWidget *cr_combo(void);
	GtkWidget *cr_radio(void);
	GtkWidget *cr_list(void);
	GtkWidget *cr_calendar(void);
	GtkWidget *cr_scrollbar(void);
	GtkWidget *make_pixmap(char *filename);


	gint delete_event (GtkWidget * widget, GdkEvent * event, gpointer data);
	void destroy_event (GtkWidget * widget, gpointer data);


	#ifndef DECLARE_DIMENSIONS
		extern int gui_xwidth;
		extern int gui_yheight;
	#else
		int gui_xwidth=8;
		int gui_yheight=20;
	#endif

	#define XWIDTH gui_xwidth
	#define YHEIGHT gui_yheight



	int display_generic (GtkWidget * k, char *s);
	GtkWidget *find_widget (GtkWindow * form, char *ident);



	char *make_colname_from_metric (struct_form * f, int metric_no);
	char *make_field_from_metric (struct_form * f, int metric_no);




	GtkWindow *get_curr_win_gtk(void);
	void gui_init_gtk (int argc, char *argv[]);
	GtkWindow * cr_window_gtk (
		char *s,
		int iswindow,
		int form_line,
		int error_line,
		int prompt_line,
		int menu_line,
		int border,
		int comment_line,
		int message_line,
		int attrib
	);

	void gui_prompt_style(int a);

	/* signals.c */
	void add_signal_grab_focus (GtkWidget * widget, void *funcptr);
	void add_signal_clicked (GtkWidget * widget, void *funcptr);
	void add_signal_changed (GtkWidget * widget, void *funcptr);
	void add_signal_select_row (GtkWidget * widget, void *funcptr);


	/* error.c */
	void msg_window_gtk(char *s);
	void error_window_gtk(char *s);
	void clr_error_gtk(void);


	/* input.c */
	void gui_set_field_pop_attr (GtkWidget * w, int attr);
	int gui_proc_key_display_array (int a);
	int gen_field_list_gtk (GtkWidget *** field_list, GtkWindow * cwin, int a,
			    va_list * ap);


	/* fields.c */
	void gui_set_active(GtkWidget *w,int en_dis);

	/* handler.c */
	void clear_something (void);
	int which_key (void);
	int user_has_done_something (void);
	int gui_get_lastkey(void);


	/* window.c */
	int decode_line_gtk (int l);
	int geterr_line_gtk(void);
	int getmsg_line_gtk(void);
	void gtkwin_stack(GtkWindow *w,int op);
	int getprompt_line_gtk(void);


	/* widget.c */
	void debug_last_field_created(char *txt);
	/* #include "a4gl_formxw.h" */ /* struct struct_form */
	void add_widget (int metric_no, struct_form * f, GtkWidget * panel_to_add_to_window);

	/* frm.c */
	void make_widgets (struct_form * f, GtkWidget * panel_to_add_to_window);
	int find_attrib_from_metric (struct_form * f, int metric_no);


	/* gtk_4gl.c */
	void set_current_window (GtkWindow * w);
	int decode_colour_attr_aubit(int a);
	void console_toggle (void);
	GtkWidget * get_window_gtk (int a);

	/* display.c */

	void dump_mem(char *ptr);

	/* cr_funcs.c */

	void size_widget (GtkWidget *w, int width);

	/* params.c */
	void split_config (char *str);


	GtkWidget *get_which_field (void);
	int keypress (GtkWidget * widget, GdkEventKey * event, gpointer user_data);
	void func (GtkWidget * w, char *mode);


	void *find_param (char *name);


    /* prompt.c */

	void a4gl_usleep(int a);



/* ================================ EOF =============================== */

