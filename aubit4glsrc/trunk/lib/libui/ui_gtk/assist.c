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
/* This prototypes should be created by 4glc, in assist.h, but they are not:
assist.c:70: warning: no previous declaration for `aclfgl_set_window_title'
assist.c:92: warning: no previous declaration for `aclfgl_get_window_title'
assist.c:114: warning: no previous declaration for `aclfgl_set_window_icon'
assist.c:139: warning: no previous declaration for `aclfgl_run_gui'
assist.c:160: warning: no previous declaration for `aclfgl_set_frame_style'
assist.c:181: warning: no previous declaration for `aclfgl_yeild'
assist.c:199: warning: no previous declaration for `aclfgl_set_window_type'
assist.c:220: warning: no previous declaration for `aclfgl_set_prompt_style'
assist.c:247: warning: no previous declaration for `aclfgl_get_filename'
assist.c:321: warning: no previous declaration for `aclfgl_app_top_get'
assist.c:350: warning: no previous declaration for `aclfgl_app_hide'
assist.c:368: warning: no previous declaration for `aclfgl_app_show'
assist.c:386: warning: no previous declaration for `aclfgl_app_maximize'
assist.c:404: warning: no previous declaration for `aclfgl_app_minimize'
assist.c:422: warning: no previous declaration for `aclfgl_app_restore'
assist.c:440: warning: no previous declaration for `aclfgl_entry_max_chars_set'
assist.c:466: warning: no previous declaration for `aclfgl_entry_selected_cut'
assist.c:489: warning: no previous declaration for `aclfgl_entry_selected_copy'
assist.c:512: warning: no previous declaration for `aclfgl_entry_selected_paste'
assist.c:535: warning: no previous declaration for `aclfgl_entry_selection_set'
assist.c:568: warning: no previous declaration for `aclfgl_entry_text_get'
assist.c:596: warning: no previous declaration for `aclfgl_field_hide'
assist.c:619: warning: no previous declaration for `aclfgl_field_show'
assist.c:640: warning: no previous declaration for `aclfgl_form_caption_get'
assist.c:658: warning: no previous declaration for `aclfgl_form_hide'
assist.c:676: warning: no previous declaration for `aclfgl_form_show'
assist.c:694: warning: no previous declaration for `aclfgl_form_is_open'
assist.c:724: warning: no previous declaration for `aclfgl_list_count_get'
assist.c:747: warning: no previous declaration for `aclfgl_list_current_get'
assist.c:774: warning: no previous declaration for `aclfgl_list_delete'
assist.c:801: warning: no previous declaration for `aclfgl_list_insert'
assist.c:834: warning: no previous declaration for `aclfgl_list_selected'
*/
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
 
 
 
int aclfgl_set_window_title (int nargs){ 
static char _functionName[] = "set_window_title";
   char s [256+1];
   struct BINDING fbind[]={ /* print_param */
   {&s,0,256}
   }; /* end of binding */
   char *_paramnames[]={
   "s"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   CHK_UI
   	trim(s);
   	gtk_window_set_title(GTK_WINDOW(find_curr_window()),s);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_get_window_title (int nargs){ 
static char _functionName[] = "get_window_title";
   char s [256+1];
   struct BINDING fbind[]={ /* print_param */
   {&s,0,256}
   }; /* end of binding */
   char *_paramnames[]={
   "s"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   CHK_UI
   	trim(s);
   	gtk_window_set_title(GTK_WINDOW(get_curr_win_gtk()),s);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_set_window_icon (int nargs){ 
static char _functionName[] = "set_window_icon";
   char s [256+1];
   long w;
   struct BINDING fbind[]={ /* print_param */
   {&s,0,256}
   }; /* end of binding */
   char *_paramnames[]={
   "s"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   CHK_UI
   	trim(s);
   	w=(int)make_pixmap(s);   //warning: assignment makes integer from pointer without a cast
   	trim(s);
   	//gtk_window_set_icon(GTK_WINDOW(find_curr_window()),w,0,0); ?
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_run_gui (int nargs){ 
static char _functionName[] = "run_gui";
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
     while (1) {
   	usleep(100);
   	gui_run_til_no_more ();
     }
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_set_frame_style (int nargs){ 
static char _functionName[] = "set_frame_style";
   long s;
   struct BINDING fbind[]={ /* print_param */
   {&s,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "s"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   CHK_UI
   frame_style=s;
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_yeild (int nargs){ 
static char _functionName[] = "yeild";
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
     gui_run_til_no_more ();
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_set_window_type (int nargs){ 
static char _functionName[] = "set_window_type";
   long a;
   struct BINDING fbind[]={ /* print_param */
   {&a,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "a"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   CHK_UI
   window_frame_type=a;
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_set_prompt_style (int nargs){ 
static char _functionName[] = "set_prompt_style";
   long a;
   struct BINDING fbind[]={ /* print_param */
   {&a,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "a"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   CHK_UI
   gui_prompt_style(a);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
GtkWidget *file_selector;
char selected_filename[256]="";
void
store_filename(GtkFileSelection *selector, gpointer user_data)
{
	strcpy(selected_filename , gtk_file_selection_get_filename (GTK_FILE_SELECTION(file_selector)));
}
/* End of code */
 
 
 
int aclfgl_get_filename (int nargs){ 
static char _functionName[] = "get_filename";
   char title [256+1];
   char fname [256+1];
   char deffile [256+1];
   char pattern [256+1];
   struct BINDING fbind[]={ /* print_param */
   {&title,0,256}
   ,
   {&deffile,0,256}
   ,
   {&pattern,0,256}
   }; /* end of binding */
   char *_paramnames[]={
   "title"
   ,
   "deffile"
   ,
   "pattern"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,3);
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
   gtk_signal_connect_object (GTK_OBJECT (b),
                                          "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy),
                                          (gpointer) file_selector);
   gtk_signal_connect_object (GTK_OBJECT (GTK_FILE_SELECTION(file_selector)->cancel_button),
                                          "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy),
                                          (gpointer) file_selector);
   /* Display that dialog */
   gtk_widget_show (file_selector);
   while (1) {
   	
   	usleep(100);
    	gui_run_til_no_more ();
   	if (strlen(selected_filename)!=0) {
   		break;
   	}
   }
   strcpy(fname,selected_filename);
   }
   /* End of code */
   aclfgli_clr_err_flg();
   push_variable(&fname,0x1000000);
   A4GLSTK_popFunction();
   return 1;
   /* End command */
   {debug("Line 293 assist.4gl:");}
   if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
   /* SQLERROR */
      if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(293,_module_name);
   /* ERROR */
      if (status<0) chk_err(293,_module_name);
   }
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_app_top_get (int nargs){ 
static char _functionName[] = "app_top_get";
   long a;
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
   a= (long)win_screen;
   /* End of code */
   aclfgli_clr_err_flg();
   push_variable(&a,0x2);
   A4GLSTK_popFunction();
   return 1;
   /* End command */
   {debug("Line 345 assist.4gl:");}
   if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
   /* SQLERROR */
      if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(345,_module_name);
   /* ERROR */
      if (status<0) chk_err(345,_module_name);
   }
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_app_hide (int nargs){ 
static char _functionName[] = "app_hide";
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
   gtk_widget_hide(win_screen);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_app_show (int nargs){ 
static char _functionName[] = "app_show";
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
   gtk_widget_show(win_screen);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_app_maximize (int nargs){ 
static char _functionName[] = "app_maximize";
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
   // Needs coding
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_app_minimize (int nargs){ 
static char _functionName[] = "app_minimize";
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
   // Needs coding
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_app_restore (int nargs){ 
static char _functionName[] = "app_restore";
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
   // Needs coding
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_entry_max_chars_set (int nargs){ 
static char _functionName[] = "entry_max_chars_set";
   long l;
   long g;
   struct BINDING fbind[]={ /* print_param */
   {&g,2,0}
   ,
   {&l,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "g"
   ,
   "l"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,2);
   CHK_UI
   gtk_entry_set_max_length(GTK_ENTRY(g),l);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_entry_selected_cut (int nargs){ 
static char _functionName[] = "entry_selected_cut";
   long g;
   struct BINDING fbind[]={ /* print_param */
   {&g,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "g"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   {
   CHK_UI
   	gtk_editable_cut_clipboard(GTK_EDITABLE(g));
   }
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_entry_selected_copy (int nargs){ 
static char _functionName[] = "entry_selected_copy";
   long g;
   struct BINDING fbind[]={ /* print_param */
   {&g,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "g"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   {
   CHK_UI
   	gtk_editable_copy_clipboard(GTK_EDITABLE(g));
   }
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_entry_selected_paste (int nargs){ 
static char _functionName[] = "entry_selected_paste";
   long g;
   struct BINDING fbind[]={ /* print_param */
   {&g,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "g"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   {
   CHK_UI
   	gtk_editable_paste_clipboard(GTK_EDITABLE(g));
   }
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_entry_selection_set (int nargs){ 
static char _functionName[] = "entry_selection_set";
   long s;
   long e;
   long g;
   struct BINDING fbind[]={ /* print_param */
   {&g,2,0}
   ,
   {&s,2,0}
   ,
   {&e,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "g"
   ,
   "s"
   ,
   "e"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,3);
   {
   CHK_UI
   	gtk_editable_select_region(GTK_EDITABLE(g),(gint)s,(gint)e);
   }
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_entry_text_get (int nargs){ 
static char _functionName[] = "entry_text_get";
   long g;
   struct BINDING fbind[]={ /* print_param */
   {&g,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "g"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   {
   	char *s;
   CHK_UI
   	debug("g=%d %x",g,g);
   	s=gtk_editable_get_chars(GTK_EDITABLE(g),0,-1);
   	push_char(s);
   	g_free(s);
   	return 1;
   }
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_field_hide (int nargs){ 
static char _functionName[] = "field_hide";
   long g;
   struct BINDING fbind[]={ /* print_param */
   {&g,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "g"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   debug("Hiding field %p\n",g);fflush(stdout);
   //CHK_UI
   debug("g=%p\n",g);
   gtk_widget_hide((GtkWidget *)g);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_field_show (int nargs){ 
static char _functionName[] = "field_show";
   long g;
   struct BINDING fbind[]={ /* print_param */
   {&g,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "g"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   CHK_UI
   gtk_widget_show((GtkWidget *)g);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_form_caption_get (int nargs){ 
static char _functionName[] = "form_caption_get";
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
   	//gtk_window_get_title(get_curr_win_gtk());
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_form_hide (int nargs){ 
static char _functionName[] = "form_hide";
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
   	gtk_widget_hide(GTK_WIDGET(get_curr_win_gtk()));
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_form_show (int nargs){ 
static char _functionName[] = "form_show";
   struct BINDING fbind[]={ /* print_param */
   }; /* end of binding */
   char *_paramnames[]={
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,0);
   CHK_UI
   	gtk_widget_show(GTK_WIDGET(get_curr_win_gtk()));
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_form_is_open (int nargs){ 
static char _functionName[] = "form_is_open";
   long s;
   struct BINDING fbind[]={ /* print_param */
   {&s,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "s"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   CHK_UI
   	//void *find_param (char *name);
   	//if (find_param(s,WINCODE)) push_int(1);
   	if ((int)find_param((char *)WINCODE)) push_int(1);
   	else push_int(0);
   	return 1;
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
static int tolist(GtkWidget *a) {
	a=gtk_object_get_data(GTK_OBJECT(a),"Child");
	return (int)a;
}
/* End of code */
 
 
 
int aclfgl_list_count_get (int nargs){ 
static char _functionName[] = "list_count_get";
   long g;
   struct BINDING fbind[]={ /* print_param */
   {&g,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "g"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   CHK_UI
   	g=tolist(GTK_WIDGET(g));
   	push_int(GTK_CLIST(g)->rows);
   	return 1;
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_list_current_get (int nargs){ 
static char _functionName[] = "list_current_get";
   long s;
   struct BINDING fbind[]={ /* print_param */
   {&s,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "s"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,1);
   CHK_UI
   {
   GList* sel ;
   s=tolist(GTK_WIDGET(s));
   sel = GTK_CLIST(s)->selection;
   push_int(sel ? (int)(sel->data) :  -1);
   return 1;
   }
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_list_delete (int nargs){ 
static char _functionName[] = "list_delete";
   long s;
   long n;
   struct BINDING fbind[]={ /* print_param */
   {&s,2,0}
   ,
   {&n,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "s"
   ,
   "n"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,2);
   CHK_UI
   	s=tolist(GTK_WIDGET(s));
   gtk_clist_remove(GTK_CLIST(s),n);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_list_insert (int nargs){ 
static char _functionName[] = "list_insert";
   long s;
   long n;
   char str [512+1];
   struct BINDING fbind[]={ /* print_param */
   {&s,2,0}
   ,
   {&n,2,0}
   ,
   {&str,0,512}
   }; /* end of binding */
   char *_paramnames[]={
   "s"
   ,
   "n"
   ,
   "str"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,3);
   CHK_UI
   	s=tolist(GTK_WIDGET(s));
   trim(str);
   gtk_clist_insert((GtkCList *)s,(gint)n,(char **)&str);
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
 
 
 
int aclfgl_list_selected (int nargs){ 
static char _functionName[] = "list_selected";
   long s;
   long n;
   struct BINDING fbind[]={ /* print_param */
   {&s,2,0}
   ,
   {&n,2,0}
   }; /* end of binding */
   char *_paramnames[]={
   "s"
   ,
   "n"
   };
   A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
   if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
   pop_params(fbind,2);
   CHK_UI
   {
   GList* sel ;
   s=tolist(GTK_WIDGET(s));
   sel = GTK_CLIST(s)->selection;
   }
   //
   /* End of code */
   A4GLSTK_popFunction();
   return 0;
}
