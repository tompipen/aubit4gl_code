
#ifndef _A4GL_LIB_UI_INT_H_
#define _A4GL_LIB_UI_INT_H_

#include "a4gl_lib_ui_int.h"


#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>	/* GDK_Down */


struct s_widget_funcs
{
/* GtkWidget *(*construct)(); *//* warning: function declaration isn't a prototype */
  GtkWidget *(*construct) ();
/* GtkWidget *(*setup_signals)(); *//* warning: function declaration isn't a prototype */
  GtkWidget *(*setup_signals) ();
};

struct s_widgets
{
  char *name;
/* GtkWidget *(*make)(); *//* warning: function declaration isn't a prototype */
  GtkWidget *(*make) (void);
  char *params[5];		/* up to 5 names parameters
				   These are not used directly from here
				   but its a good place to document them
				   This may be used later for checking when implemented
				 */
};


#define DIALOG_DISABLE_NONE    		0
#define DIALOG_DISABLE_PROGRAM 		1
#define DIALOG_DISABLE_ALL     		2

#define BUTTON_OK     				1
#define BUTTON_CANCEL 				2
#define BUTTON_ABORT  				3
#define BUTTON_RETRY  				4
#define BUTTON_IGNORE 				5
#define BUTTON_YES    				6
#define BUTTON_NO     				7

#define BUTTONS_OK 					0
#define BUTTONS_OK_CANCEL 			1
#define BUTTONS_RETRY_CANCEL		2
#define BUTTONS_ABORT_RETRY_IGNORE	3
#define BUTTONS_YES_NO				4
#define BUTTONS_YES_NO_CANCEL		5


int KeySnooper (GtkWidget * grab_widget, GdkEventKey * event,
		gpointer func_data);

char *A4GL_fld_val_generic (GtkWidget * k);


void A4GL_alloc_colors (void);
void A4GL_gui_set_field_fore (GtkWidget * w, int attr);
void A4GL_gui_set_field_back (GtkWidget * w, int attr);

GtkWidget *A4GL_cr_textbox (void);
GtkWidget *A4GL_cr_button (void);
GtkWidget *A4GL_cr_check (void);
GtkWidget *A4GL_cr_label (void);
GtkWidget *A4GL_cr_picture (void);
GtkWidget *A4GL_cr_pixbuf (void);
GtkWidget *A4GL_cr_combo (void);
GtkWidget *A4GL_cr_radio (void);
GtkWidget *A4GL_cr_list (void);
GtkWidget *A4GL_cr_calendar (void);
GtkWidget *A4GL_cr_scrollbar (void);
//Moved to ag4l_API_ui.h
//GtkWidget *A4GL_make_pixmap_gw (char *filename);
//void* A4GL_make_pixmap_gw(char* filename);

GtkWidget *A4GL_make_widget (char *widget, char *config, int w);

int A4GL_delete_event (GtkWidget * widget, GdkEvent * event, gpointer data);
void A4GL_destroy_event (GtkWidget * widget, gpointer data);


#ifndef DECLARE_DIMENSIONS
extern int gui_xwidth;
extern int gui_yheight;
#else
int gui_xwidth = 10;
int gui_yheight = 25;
#endif

#define XWIDTH gui_xwidth
#define YHEIGHT gui_yheight



int A4GL_display_generic (GtkWidget * k, char *s);
GtkWidget *A4GL_find_widget (GtkWindow * form, char *ident);



char *A4GL_make_colname_from_metric (struct_form * f, int metric_no);
char *A4GL_make_field_from_metric (struct_form * f, int metric_no);




	//void *get_curr_win_gtk(void);
void gui_init_gtk (int argc, char *argv[]);
GtkWindow *cr_window_gtk (char *s,
			  int iswindow,
			  int form_line,
			  int error_line,
			  int prompt_line,
			  int menu_line,
			  int border,
			  int comment_line, int message_line, int attrib);

void A4GL_gui_prompt_style (int a);

    /* disp_arr.c */

void A4GL_set_arr_fields (int n, int attr, ...);
void A4GL_set_array_mode (int type);
struct struct_screen_record *A4GL_get_srec_gtk (char *);

	/* signals.c */
void A4GL_add_signal_grab_focus (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_clicked (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_changed (GtkWidget * widget, void *funcptr);
void A4GL_add_signal_select_row (GtkWidget * widget, void *funcptr);


	/* error.c */
void A4GL_msg_window_gtk (char *s);
void A4GL_error_window_gtk (char *s);
void A4GL_clr_error_gtk (void);


	/* input.c */
void A4GL_gui_set_field_pop_attr (GtkWidget * w, int attr);
int A4GL_gui_proc_key_display_array (int a);
int A4GL_gen_field_list_gtk (GtkWidget *** field_list, GtkWindow * cwin, int a,
			va_list * ap);
void A4GL_clr_field (GtkWidget * f);
void A4GL_set_field_attr_with_attr (GtkWidget * field, int attr, int cmd_type);
void A4GL_set_field_attr_with_attr_already_determined (GtkWidget * field, int attr, int cmd_type);

	/* fields.c */
void A4GL_gui_set_active (GtkWidget * w, int en_dis);

	/* handler.c */
void A4GL_clear_something (void);
int A4GL_which_key (void);
int A4GL_user_has_done_something (void);
int A4GL_gui_get_lastkey (void);


	/* window.c */
int A4GL_decode_line_gtk (int l);
int A4GL_geterr_line_gtk (void);
int A4GL_getmsg_line_gtk (void);
void A4GL_gtkwin_stack (GtkWindow * w, int op);
int A4GL_getprompt_line_gtk (void);
int A4GL_get_curr_height_gtk (void);
int A4GL_get_curr_border_gtk (void);

	/* widget.c */
void A4GL_debug_last_field_created (char *txt);
/* #include "a4gl_formxw.h" *//* struct struct_form */
void A4GL_add_widget (int metric_no, struct_form * f,
		 GtkWidget * panel_to_add_to_window);
int get_widget_next_size();
#if GTK_CHECK_VERSION(2,0,0)
	void A4GL_ChangeWidgetFont(GtkLabel *label,char *font);
#endif

	/* frm.c */
void A4GL_make_widgets (struct_form * f, GtkWidget * panel_to_add_to_window);
int A4GL_find_attrib_from_metric (struct_form * f, int metric_no);


	/* gtk_4gl.c */
void A4GL_set_current_window (void * w);
int A4GL_decode_colour_attr_aubit (int a);
void A4GL_console_toggle (void);
GtkWidget *A4GL_get_window_gtk (int a);



	/* display.c */

void A4GL_dump_mem (char *ptr);

	/* cr_funcs.c */

void A4GL_size_widget (GtkWidget * w, int width);

	/* params.c */
void A4GL_split_config (char *str);


GtkWidget *A4GL_get_which_field (void);
int A4GL_keypress (GtkWidget * widget, GdkEventKey * event, gpointer user_data);
void A4GL_func (GtkWidget * w, char *mode);
char *field_buffer(GtkWidget *w,int n);

void *A4GL_find_param (char *name);


    /* giarray.c */
void *field_userptr(GtkWidget *w);
int A4GL_get_field_width(GtkWidget *w);
void A4GL_mja_set_field_buffer(GtkWidget *w,int n,char *s);

struct a4gl_frm {
        GtkWidget **widgets;
        GtkFixed *form_fixed;
};

#define REQ_DEL_PREV   0
#define REQ_CLR_EOF    1
#define REQ_INS_MODE   2
#define REQ_OVL_MODE   3
#define REQ_NEXT_CHAR  4
#define REQ_VALIDATION 5
#define REQ_PREV_CHAR  6
#define O_ACTIVE 1
#define O_EDIT 2

#endif

/* ================================ EOF =============================== */
