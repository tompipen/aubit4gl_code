#define fgldate long
#include "a4gl_incl_4glhdr.h"
#include "assist.h"
static char _module_name[]="assist.4gl";
/*
#line 37 "assist.4gl"
====================================================================
#line 38 "assist.4gl"
File assist.c was created from assist.4gl using 4glc compiler.
#line 39 "assist.4gl"

#line 40 "assist.4gl"
If you need to change something, edit assist.4gl, and NOT assist.c
#line 41 "assist.4gl"
====================================================================
#line 42 "assist.4gl"
*/
#line 43 "assist.4gl"

#line 44 "assist.4gl"
/*
#line 45 "assist.4gl"
=====================================================================
#line 46 "assist.4gl"
		                    Includes
#line 47 "assist.4gl"
=====================================================================
#line 48 "assist.4gl"
*/
#line 49 "assist.4gl"

#line 50 "assist.4gl"
#include "a4gl_lib_ui_gtk_int.h"
#line 51 "assist.4gl"

#line 52 "assist.4gl"
/*
#line 53 "assist.4gl"
=====================================================================
#line 54 "assist.4gl"
                    Variables definitions
#line 55 "assist.4gl"
=====================================================================
#line 56 "assist.4gl"
*/
#line 57 "assist.4gl"

#line 58 "assist.4gl"
extern int frame_style;
#line 59 "assist.4gl"
extern int ui_mode;
#line 60 "assist.4gl"
extern int window_frame_type;
#line 61 "assist.4gl"
extern GtkWidget *win_screen;
#line 62 "assist.4gl"
extern GtkWidget *currwindow;
#line 63 "assist.4gl"

#line 64 "assist.4gl"
/*
#line 65 "assist.4gl"
=====================================================================
#line 66 "assist.4gl"
                    Constants definitions
#line 67 "assist.4gl"
=====================================================================
#line 68 "assist.4gl"
*/
#line 69 "assist.4gl"

#line 70 "assist.4gl"
#define CHK_UI if (ui_mode!=1) {exitwith("Not in GUI mode");return 0;} else {debug("UI mode ok");}
#line 71 "assist.4gl"

#line 72 "assist.4gl"

#line 73 "assist.4gl"
/*
#line 74 "assist.4gl"
=====================================================================
#line 75 "assist.4gl"
                    Functions prototypes
#line 76 "assist.4gl"
=====================================================================
#line 77 "assist.4gl"
*/
#line 78 "assist.4gl"

#line 79 "assist.4gl"
void * find_curr_window(void);
#line 80 "assist.4gl"
void store_filename(GtkFileSelection *selector, gpointer user_data);
#line 81 "assist.4gl"

#line 82 "assist.4gl"
/* This prototypes should be created by 4glc, in assist.h, but they are not:
#line 83 "assist.4gl"

#line 84 "assist.4gl"
assist.c:70: warning: no previous declaration for `aclfgl_set_window_title'
#line 85 "assist.4gl"
assist.c:92: warning: no previous declaration for `aclfgl_get_window_title'
#line 86 "assist.4gl"
assist.c:114: warning: no previous declaration for `aclfgl_set_window_icon'
#line 87 "assist.4gl"
assist.c:139: warning: no previous declaration for `aclfgl_run_gui'
#line 88 "assist.4gl"
assist.c:160: warning: no previous declaration for `aclfgl_set_frame_style'
#line 89 "assist.4gl"
assist.c:181: warning: no previous declaration for `aclfgl_yeild'
#line 90 "assist.4gl"
assist.c:199: warning: no previous declaration for `aclfgl_set_window_type'
#line 91 "assist.4gl"
assist.c:220: warning: no previous declaration for `aclfgl_set_prompt_style'
#line 92 "assist.4gl"
assist.c:247: warning: no previous declaration for `aclfgl_get_filename'
#line 93 "assist.4gl"
assist.c:321: warning: no previous declaration for `aclfgl_app_top_get'
#line 94 "assist.4gl"
assist.c:350: warning: no previous declaration for `aclfgl_app_hide'
#line 95 "assist.4gl"
assist.c:368: warning: no previous declaration for `aclfgl_app_show'
#line 96 "assist.4gl"
assist.c:386: warning: no previous declaration for `aclfgl_app_maximize'
#line 97 "assist.4gl"
assist.c:404: warning: no previous declaration for `aclfgl_app_minimize'
#line 98 "assist.4gl"
assist.c:422: warning: no previous declaration for `aclfgl_app_restore'
#line 99 "assist.4gl"
assist.c:440: warning: no previous declaration for `aclfgl_entry_max_chars_set'
#line 100 "assist.4gl"
assist.c:466: warning: no previous declaration for `aclfgl_entry_selected_cut'
#line 101 "assist.4gl"
assist.c:489: warning: no previous declaration for `aclfgl_entry_selected_copy'
#line 102 "assist.4gl"
assist.c:512: warning: no previous declaration for `aclfgl_entry_selected_paste'
#line 103 "assist.4gl"
assist.c:535: warning: no previous declaration for `aclfgl_entry_selection_set'
#line 104 "assist.4gl"
assist.c:568: warning: no previous declaration for `aclfgl_entry_text_get'
#line 105 "assist.4gl"
assist.c:596: warning: no previous declaration for `aclfgl_field_hide'
#line 106 "assist.4gl"
assist.c:619: warning: no previous declaration for `aclfgl_field_show'
#line 107 "assist.4gl"
assist.c:640: warning: no previous declaration for `aclfgl_form_caption_get'
#line 108 "assist.4gl"
assist.c:658: warning: no previous declaration for `aclfgl_form_hide'
#line 109 "assist.4gl"
assist.c:676: warning: no previous declaration for `aclfgl_form_show'
#line 110 "assist.4gl"
assist.c:694: warning: no previous declaration for `aclfgl_form_is_open'
#line 111 "assist.4gl"
assist.c:724: warning: no previous declaration for `aclfgl_list_count_get'
#line 112 "assist.4gl"
assist.c:747: warning: no previous declaration for `aclfgl_list_current_get'
#line 113 "assist.4gl"
assist.c:774: warning: no previous declaration for `aclfgl_list_delete'
#line 114 "assist.4gl"
assist.c:801: warning: no previous declaration for `aclfgl_list_insert'
#line 115 "assist.4gl"
assist.c:834: warning: no previous declaration for `aclfgl_list_selected'
#line 116 "assist.4gl"
*/
#line 117 "assist.4gl"

#line 118 "assist.4gl"
/*
#line 119 "assist.4gl"
=====================================================================
#line 120 "assist.4gl"
                    Functions definitions
#line 121 "assist.4gl"
=====================================================================
#line 122 "assist.4gl"
*/
#line 123 "assist.4gl"

#line 124 "assist.4gl"
/**
#line 125 "assist.4gl"
 *
#line 126 "assist.4gl"
 * @todo Describe function
#line 127 "assist.4gl"
 */
#line 128 "assist.4gl"
void *
#line 129 "assist.4gl"
find_curr_window(void) 
#line 130 "assist.4gl"
{
#line 131 "assist.4gl"
void *w;
#line 132 "assist.4gl"
	w=get_curr_win_gtk();
#line 133 "assist.4gl"
	if (gtk_object_get_data(w,"TOP")) {
#line 134 "assist.4gl"
		debug("Has parent...");
#line 135 "assist.4gl"
		w=gtk_object_get_data(w,"TOP");
#line 136 "assist.4gl"
	}
#line 137 "assist.4gl"
	return w;
#line 138 "assist.4gl"
}
#line 139 "assist.4gl"
/* End of code */ 
#line 145 "assist.4gl"
 
#line 145 "assist.4gl"
 
#line 145 "assist.4gl"

#line 145 "assist.4gl"
int aclfgl_set_window_title (int nargs){ 
#line 145 "assist.4gl"

#line 145 "assist.4gl"
static char _functionName[] = "set_window_title";
#line 145 "assist.4gl"
char s [256+1];
#line 149 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 149 "assist.4gl"
{&s,0,256}
#line 149 "assist.4gl"
}; /* end of binding */
#line 149 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 149 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 149 "assist.4gl"
pop_params(fbind,1);
#line 149 "assist.4gl"
CHK_UI
#line 150 "assist.4gl"
	trim(s);
#line 151 "assist.4gl"
	gtk_window_set_title(GTK_WINDOW(find_curr_window()),s);
#line 152 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 155 "assist.4gl"
return 0;
#line 155 "assist.4gl"
}
#line 155 "assist.4gl"
 
#line 159 "assist.4gl"
 
#line 159 "assist.4gl"
 
#line 159 "assist.4gl"

#line 159 "assist.4gl"
int aclfgl_get_window_title (int nargs){ 
#line 159 "assist.4gl"

#line 159 "assist.4gl"
static char _functionName[] = "get_window_title";
#line 159 "assist.4gl"
char s [256+1];
#line 162 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 162 "assist.4gl"
{&s,0,256}
#line 162 "assist.4gl"
}; /* end of binding */
#line 162 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 162 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 162 "assist.4gl"
pop_params(fbind,1);
#line 162 "assist.4gl"
CHK_UI
#line 163 "assist.4gl"
	trim(s);
#line 164 "assist.4gl"
	gtk_window_set_title(GTK_WINDOW(get_curr_win_gtk()),s);
#line 165 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 167 "assist.4gl"
return 0;
#line 167 "assist.4gl"
}
#line 167 "assist.4gl"
 
#line 172 "assist.4gl"
 
#line 172 "assist.4gl"
 
#line 172 "assist.4gl"

#line 172 "assist.4gl"
int aclfgl_set_window_icon (int nargs){ 
#line 172 "assist.4gl"

#line 172 "assist.4gl"
static char _functionName[] = "set_window_icon";
#line 172 "assist.4gl"
char s [256+1];
#line 176 "assist.4gl"
long w;
#line 176 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 176 "assist.4gl"
{&s,0,256}
#line 176 "assist.4gl"
}; /* end of binding */
#line 176 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 176 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 176 "assist.4gl"
pop_params(fbind,1);
#line 176 "assist.4gl"
CHK_UI
#line 177 "assist.4gl"
	trim(s);
#line 178 "assist.4gl"
	w=(int)make_pixmap(s);   //warning: assignment makes integer from pointer without a cast
#line 179 "assist.4gl"

#line 180 "assist.4gl"
	trim(s);
#line 181 "assist.4gl"
	//gtk_window_set_icon(GTK_WINDOW(find_curr_window()),w,0,0); ?
#line 182 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 185 "assist.4gl"
return 0;
#line 185 "assist.4gl"
}
#line 185 "assist.4gl"
 
#line 189 "assist.4gl"
 
#line 189 "assist.4gl"
 
#line 189 "assist.4gl"

#line 189 "assist.4gl"
int aclfgl_run_gui (int nargs){ 
#line 189 "assist.4gl"

#line 189 "assist.4gl"
static char _functionName[] = "run_gui";
#line 189 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 191 "assist.4gl"

#line 191 "assist.4gl"
}; /* end of binding */
#line 191 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 191 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 191 "assist.4gl"
pop_params(fbind,0);
#line 191 "assist.4gl"
CHK_UI
#line 192 "assist.4gl"
  while (1) {
#line 193 "assist.4gl"
	usleep(100);
#line 194 "assist.4gl"
	gui_run_til_no_more ();
#line 195 "assist.4gl"
  }
#line 196 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 198 "assist.4gl"
return 0;
#line 198 "assist.4gl"
}
#line 198 "assist.4gl"
 
#line 217 "assist.4gl"
 
#line 217 "assist.4gl"
 
#line 217 "assist.4gl"

#line 217 "assist.4gl"
int aclfgl_set_frame_style (int nargs){ 
#line 217 "assist.4gl"

#line 217 "assist.4gl"
static char _functionName[] = "set_frame_style";
#line 217 "assist.4gl"
long s;
#line 220 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 220 "assist.4gl"
{&s,2,0}
#line 220 "assist.4gl"
}; /* end of binding */
#line 220 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 220 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 220 "assist.4gl"
pop_params(fbind,1);
#line 220 "assist.4gl"
CHK_UI
#line 221 "assist.4gl"
frame_style=s;
#line 222 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 224 "assist.4gl"
return 0;
#line 224 "assist.4gl"
}
#line 224 "assist.4gl"
 
#line 231 "assist.4gl"
 
#line 231 "assist.4gl"
 
#line 231 "assist.4gl"

#line 231 "assist.4gl"
int aclfgl_yeild (int nargs){ 
#line 231 "assist.4gl"

#line 231 "assist.4gl"
static char _functionName[] = "yeild";
#line 231 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 233 "assist.4gl"

#line 233 "assist.4gl"
}; /* end of binding */
#line 233 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 233 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 233 "assist.4gl"
pop_params(fbind,0);
#line 233 "assist.4gl"
CHK_UI
#line 234 "assist.4gl"
  gui_run_til_no_more ();
#line 235 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 237 "assist.4gl"
return 0;
#line 237 "assist.4gl"
}
#line 237 "assist.4gl"
 
#line 250 "assist.4gl"
 
#line 250 "assist.4gl"
 
#line 250 "assist.4gl"

#line 250 "assist.4gl"
int aclfgl_set_window_type (int nargs){ 
#line 250 "assist.4gl"

#line 250 "assist.4gl"
static char _functionName[] = "set_window_type";
#line 250 "assist.4gl"
long a;
#line 253 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 253 "assist.4gl"
{&a,2,0}
#line 253 "assist.4gl"
}; /* end of binding */
#line 253 "assist.4gl"
char *_paramnames[]={"a"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 253 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 253 "assist.4gl"
pop_params(fbind,1);
#line 253 "assist.4gl"
CHK_UI
#line 254 "assist.4gl"
window_frame_type=a;
#line 255 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 257 "assist.4gl"
return 0;
#line 257 "assist.4gl"
}
#line 257 "assist.4gl"
 
#line 261 "assist.4gl"
 
#line 261 "assist.4gl"
 
#line 261 "assist.4gl"

#line 261 "assist.4gl"
int aclfgl_set_prompt_style (int nargs){ 
#line 261 "assist.4gl"

#line 261 "assist.4gl"
static char _functionName[] = "set_prompt_style";
#line 261 "assist.4gl"
long a;
#line 264 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 264 "assist.4gl"
{&a,2,0}
#line 264 "assist.4gl"
}; /* end of binding */
#line 264 "assist.4gl"
char *_paramnames[]={"a"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 264 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 264 "assist.4gl"
pop_params(fbind,1);
#line 264 "assist.4gl"
CHK_UI
#line 265 "assist.4gl"
gui_prompt_style(a);
#line 266 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 268 "assist.4gl"
return 0;
#line 268 "assist.4gl"
}
#line 268 "assist.4gl"
GtkWidget *file_selector;
#line 275 "assist.4gl"
char selected_filename[256]="";
#line 276 "assist.4gl"

#line 277 "assist.4gl"
void
#line 278 "assist.4gl"
store_filename(GtkFileSelection *selector, gpointer user_data)
#line 279 "assist.4gl"
{
#line 280 "assist.4gl"
	strcpy(selected_filename , gtk_file_selection_get_filename (GTK_FILE_SELECTION(file_selector)));
#line 281 "assist.4gl"
}
#line 282 "assist.4gl"
/* End of code */ 
#line 287 "assist.4gl"
 
#line 287 "assist.4gl"
 
#line 287 "assist.4gl"

#line 287 "assist.4gl"
int aclfgl_get_filename (int nargs){ 
#line 287 "assist.4gl"

#line 287 "assist.4gl"
static char _functionName[] = "get_filename";
#line 287 "assist.4gl"
char title [256+1];
#line 293 "assist.4gl"
char fname [256+1];
#line 293 "assist.4gl"
char deffile [256+1];
#line 293 "assist.4gl"
char pattern [256+1];
#line 293 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 293 "assist.4gl"
{&title,0,256},
#line 293 "assist.4gl"
{&deffile,0,256},
#line 293 "assist.4gl"
{&pattern,0,256}
#line 293 "assist.4gl"
}; /* end of binding */
#line 293 "assist.4gl"
char *_paramnames[]={"title","deffile","pattern"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 293 "assist.4gl"
if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
#line 293 "assist.4gl"
pop_params(fbind,3);
#line 293 "assist.4gl"
{
#line 294 "assist.4gl"
GtkWidget *b;
#line 295 "assist.4gl"
GtkWidget *w;
#line 296 "assist.4gl"
CHK_UI
#line 297 "assist.4gl"
trim(title);
#line 298 "assist.4gl"
trim(deffile);
#line 299 "assist.4gl"
trim(pattern);
#line 300 "assist.4gl"
file_selector = gtk_file_selection_new(title);
#line 301 "assist.4gl"
gtk_file_selection_set_filename(GTK_FILE_SELECTION(file_selector),deffile);
#line 302 "assist.4gl"
gtk_file_selection_complete(GTK_FILE_SELECTION(file_selector),pattern);
#line 303 "assist.4gl"

#line 304 "assist.4gl"
b=GTK_FILE_SELECTION(file_selector)->ok_button;
#line 305 "assist.4gl"
w=GTK_FILE_SELECTION(file_selector)->fileop_dialog;
#line 306 "assist.4gl"

#line 307 "assist.4gl"
//gtk_window_set_modal(w,1);
#line 308 "assist.4gl"

#line 309 "assist.4gl"
gtk_signal_connect (GTK_OBJECT (b), "clicked", GTK_SIGNAL_FUNC (store_filename), 0);
#line 310 "assist.4gl"
                        
#line 311 "assist.4gl"
/* Ensure that the dialog box is destroyed when the user clicks a button. */
#line 312 "assist.4gl"

#line 313 "assist.4gl"
gtk_signal_connect_object (GTK_OBJECT (b),
#line 314 "assist.4gl"
                                       "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy),
#line 315 "assist.4gl"
                                       (gpointer) file_selector);
#line 316 "assist.4gl"

#line 317 "assist.4gl"
gtk_signal_connect_object (GTK_OBJECT (GTK_FILE_SELECTION(file_selector)->cancel_button),
#line 318 "assist.4gl"
                                       "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy),
#line 319 "assist.4gl"
                                       (gpointer) file_selector);
#line 320 "assist.4gl"

#line 321 "assist.4gl"
/* Display that dialog */
#line 322 "assist.4gl"

#line 323 "assist.4gl"
gtk_widget_show (file_selector);
#line 324 "assist.4gl"
while (1) {
#line 325 "assist.4gl"
	
#line 326 "assist.4gl"
	usleep(100);
#line 327 "assist.4gl"
 	gui_run_til_no_more ();
#line 328 "assist.4gl"
	if (strlen(selected_filename)!=0) {
#line 329 "assist.4gl"
		break;
#line 330 "assist.4gl"
	}
#line 331 "assist.4gl"
}
#line 332 "assist.4gl"
strcpy(fname,selected_filename);
#line 333 "assist.4gl"
}
#line 334 "assist.4gl"
/* End of code */
#line 335 "assist.4gl"

#line 335 "assist.4gl"
aclfgli_clr_err_flg();
#line 335 "assist.4gl"

#line 335 "assist.4gl"
push_variable(&fname,0x1000000);
#line 337 "assist.4gl"
A4GLSTK_popFunction();
#line 337 "assist.4gl"
return 1;
#line 337 "assist.4gl"
/* End command */
#line 337 "assist.4gl"
{debug("Line 293 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 337 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(293,_module_name);
#line 337 "assist.4gl"
/* ERROR */   if (status<0) chk_err(293,_module_name);
#line 337 "assist.4gl"
}
#line 337 "assist.4gl"
A4GLSTK_popFunction();
#line 337 "assist.4gl"
return 0;
#line 337 "assist.4gl"
}
#line 337 "assist.4gl"
 
#line 342 "assist.4gl"
 
#line 342 "assist.4gl"
 
#line 342 "assist.4gl"

#line 342 "assist.4gl"
int aclfgl_app_top_get (int nargs){ 
#line 342 "assist.4gl"

#line 342 "assist.4gl"
static char _functionName[] = "app_top_get";
#line 342 "assist.4gl"
long a;
#line 345 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 345 "assist.4gl"

#line 345 "assist.4gl"
}; /* end of binding */
#line 345 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 345 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 345 "assist.4gl"
pop_params(fbind,0);
#line 345 "assist.4gl"
CHK_UI
#line 346 "assist.4gl"
a= (long)win_screen;
#line 347 "assist.4gl"
/* End of code */
#line 348 "assist.4gl"

#line 348 "assist.4gl"
aclfgli_clr_err_flg();
#line 348 "assist.4gl"

#line 348 "assist.4gl"
push_variable(&a,0x2);
#line 348 "assist.4gl"
A4GLSTK_popFunction();
#line 348 "assist.4gl"
return 1;
#line 348 "assist.4gl"
/* End command */
#line 348 "assist.4gl"
{debug("Line 345 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 348 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(345,_module_name);
#line 348 "assist.4gl"
/* ERROR */   if (status<0) chk_err(345,_module_name);
#line 348 "assist.4gl"
}
#line 348 "assist.4gl"
A4GLSTK_popFunction();
#line 350 "assist.4gl"
return 0;
#line 350 "assist.4gl"
}
#line 350 "assist.4gl"
 
#line 355 "assist.4gl"
 
#line 355 "assist.4gl"
 
#line 355 "assist.4gl"

#line 355 "assist.4gl"
int aclfgl_app_hide (int nargs){ 
#line 355 "assist.4gl"

#line 355 "assist.4gl"
static char _functionName[] = "app_hide";
#line 355 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 357 "assist.4gl"

#line 357 "assist.4gl"
}; /* end of binding */
#line 357 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 357 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 357 "assist.4gl"
pop_params(fbind,0);
#line 357 "assist.4gl"
CHK_UI
#line 358 "assist.4gl"
gtk_widget_hide(win_screen);
#line 359 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 361 "assist.4gl"
return 0;
#line 361 "assist.4gl"
}
#line 361 "assist.4gl"
 
#line 365 "assist.4gl"
 
#line 365 "assist.4gl"
 
#line 365 "assist.4gl"

#line 365 "assist.4gl"
int aclfgl_app_show (int nargs){ 
#line 365 "assist.4gl"

#line 365 "assist.4gl"
static char _functionName[] = "app_show";
#line 365 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 367 "assist.4gl"

#line 367 "assist.4gl"
}; /* end of binding */
#line 367 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 367 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 367 "assist.4gl"
pop_params(fbind,0);
#line 367 "assist.4gl"
CHK_UI
#line 368 "assist.4gl"
gtk_widget_show(win_screen);
#line 369 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 371 "assist.4gl"
return 0;
#line 371 "assist.4gl"
}
#line 371 "assist.4gl"
 
#line 375 "assist.4gl"
 
#line 375 "assist.4gl"
 
#line 375 "assist.4gl"

#line 375 "assist.4gl"
int aclfgl_app_maximize (int nargs){ 
#line 375 "assist.4gl"

#line 375 "assist.4gl"
static char _functionName[] = "app_maximize";
#line 375 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 377 "assist.4gl"

#line 377 "assist.4gl"
}; /* end of binding */
#line 377 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 377 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 377 "assist.4gl"
pop_params(fbind,0);
#line 377 "assist.4gl"
CHK_UI
#line 378 "assist.4gl"
// Needs coding
#line 379 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 381 "assist.4gl"
return 0;
#line 381 "assist.4gl"
}
#line 381 "assist.4gl"
 
#line 385 "assist.4gl"
 
#line 385 "assist.4gl"
 
#line 385 "assist.4gl"

#line 385 "assist.4gl"
int aclfgl_app_minimize (int nargs){ 
#line 385 "assist.4gl"

#line 385 "assist.4gl"
static char _functionName[] = "app_minimize";
#line 385 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 387 "assist.4gl"

#line 387 "assist.4gl"
}; /* end of binding */
#line 387 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 387 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 387 "assist.4gl"
pop_params(fbind,0);
#line 387 "assist.4gl"
CHK_UI
#line 388 "assist.4gl"
// Needs coding
#line 389 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 391 "assist.4gl"
return 0;
#line 391 "assist.4gl"
}
#line 391 "assist.4gl"
 
#line 395 "assist.4gl"
 
#line 395 "assist.4gl"
 
#line 395 "assist.4gl"

#line 395 "assist.4gl"
int aclfgl_app_restore (int nargs){ 
#line 395 "assist.4gl"

#line 395 "assist.4gl"
static char _functionName[] = "app_restore";
#line 395 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 397 "assist.4gl"

#line 397 "assist.4gl"
}; /* end of binding */
#line 397 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 397 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 397 "assist.4gl"
pop_params(fbind,0);
#line 397 "assist.4gl"
CHK_UI
#line 398 "assist.4gl"
// Needs coding
#line 399 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 401 "assist.4gl"
return 0;
#line 401 "assist.4gl"
}
#line 401 "assist.4gl"
 
#line 406 "assist.4gl"
 
#line 406 "assist.4gl"
 
#line 406 "assist.4gl"

#line 406 "assist.4gl"
int aclfgl_entry_max_chars_set (int nargs){ 
#line 406 "assist.4gl"

#line 406 "assist.4gl"
static char _functionName[] = "entry_max_chars_set";
#line 406 "assist.4gl"
long l;
#line 410 "assist.4gl"
long g;
#line 410 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 410 "assist.4gl"
{&g,2,0},
#line 410 "assist.4gl"
{&l,2,0}
#line 410 "assist.4gl"
}; /* end of binding */
#line 410 "assist.4gl"
char *_paramnames[]={"g","l"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 410 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 410 "assist.4gl"
pop_params(fbind,2);
#line 410 "assist.4gl"
CHK_UI
#line 411 "assist.4gl"
gtk_entry_set_max_length(GTK_ENTRY(g),l);
#line 412 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 414 "assist.4gl"
return 0;
#line 414 "assist.4gl"
}
#line 414 "assist.4gl"
 
#line 420 "assist.4gl"
 
#line 420 "assist.4gl"
 
#line 420 "assist.4gl"

#line 420 "assist.4gl"
int aclfgl_entry_selected_cut (int nargs){ 
#line 420 "assist.4gl"

#line 420 "assist.4gl"
static char _functionName[] = "entry_selected_cut";
#line 420 "assist.4gl"
long g;
#line 423 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 423 "assist.4gl"
{&g,2,0}
#line 423 "assist.4gl"
}; /* end of binding */
#line 423 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 423 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 423 "assist.4gl"
pop_params(fbind,1);
#line 423 "assist.4gl"
{
#line 424 "assist.4gl"
CHK_UI
#line 425 "assist.4gl"
	gtk_editable_cut_clipboard(GTK_EDITABLE(g));
#line 426 "assist.4gl"
}
#line 427 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 429 "assist.4gl"
return 0;
#line 429 "assist.4gl"
}
#line 429 "assist.4gl"
 
#line 433 "assist.4gl"
 
#line 433 "assist.4gl"
 
#line 433 "assist.4gl"

#line 433 "assist.4gl"
int aclfgl_entry_selected_copy (int nargs){ 
#line 433 "assist.4gl"

#line 433 "assist.4gl"
static char _functionName[] = "entry_selected_copy";
#line 433 "assist.4gl"
long g;
#line 436 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 436 "assist.4gl"
{&g,2,0}
#line 436 "assist.4gl"
}; /* end of binding */
#line 436 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 436 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 436 "assist.4gl"
pop_params(fbind,1);
#line 436 "assist.4gl"
{
#line 437 "assist.4gl"
CHK_UI
#line 438 "assist.4gl"
	gtk_editable_copy_clipboard(GTK_EDITABLE(g));
#line 439 "assist.4gl"
}
#line 440 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 442 "assist.4gl"
return 0;
#line 442 "assist.4gl"
}
#line 442 "assist.4gl"
 
#line 446 "assist.4gl"
 
#line 446 "assist.4gl"
 
#line 446 "assist.4gl"

#line 446 "assist.4gl"
int aclfgl_entry_selected_paste (int nargs){ 
#line 446 "assist.4gl"

#line 446 "assist.4gl"
static char _functionName[] = "entry_selected_paste";
#line 446 "assist.4gl"
long g;
#line 449 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 449 "assist.4gl"
{&g,2,0}
#line 449 "assist.4gl"
}; /* end of binding */
#line 449 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 449 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 449 "assist.4gl"
pop_params(fbind,1);
#line 449 "assist.4gl"
{
#line 450 "assist.4gl"
CHK_UI
#line 451 "assist.4gl"
	gtk_editable_paste_clipboard(GTK_EDITABLE(g));
#line 452 "assist.4gl"
}
#line 453 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 455 "assist.4gl"
return 0;
#line 455 "assist.4gl"
}
#line 455 "assist.4gl"
 
#line 460 "assist.4gl"
 
#line 460 "assist.4gl"
 
#line 460 "assist.4gl"

#line 460 "assist.4gl"
int aclfgl_entry_selection_set (int nargs){ 
#line 460 "assist.4gl"

#line 460 "assist.4gl"
static char _functionName[] = "entry_selection_set";
#line 460 "assist.4gl"
long s;
#line 464 "assist.4gl"
long e;
#line 464 "assist.4gl"
long g;
#line 464 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 464 "assist.4gl"
{&g,2,0},
#line 464 "assist.4gl"
{&s,2,0},
#line 464 "assist.4gl"
{&e,2,0}
#line 464 "assist.4gl"
}; /* end of binding */
#line 464 "assist.4gl"
char *_paramnames[]={"g","s","e"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 464 "assist.4gl"
if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
#line 464 "assist.4gl"
pop_params(fbind,3);
#line 464 "assist.4gl"
{
#line 465 "assist.4gl"
CHK_UI
#line 466 "assist.4gl"
	gtk_editable_select_region(GTK_EDITABLE(g),(gint)s,(gint)e);
#line 467 "assist.4gl"
}
#line 468 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 470 "assist.4gl"
return 0;
#line 470 "assist.4gl"
}
#line 470 "assist.4gl"
 
#line 474 "assist.4gl"
 
#line 474 "assist.4gl"
 
#line 474 "assist.4gl"

#line 474 "assist.4gl"
int aclfgl_entry_text_get (int nargs){ 
#line 474 "assist.4gl"

#line 474 "assist.4gl"
static char _functionName[] = "entry_text_get";
#line 474 "assist.4gl"
long g;
#line 477 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 477 "assist.4gl"
{&g,2,0}
#line 477 "assist.4gl"
}; /* end of binding */
#line 477 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 477 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 477 "assist.4gl"
pop_params(fbind,1);
#line 477 "assist.4gl"
{
#line 478 "assist.4gl"
	char *s;
#line 479 "assist.4gl"
CHK_UI
#line 480 "assist.4gl"
	debug("g=%d %x",g,g);
#line 481 "assist.4gl"
	s=gtk_editable_get_chars(GTK_EDITABLE(g),0,-1);
#line 482 "assist.4gl"
	push_char(s);
#line 483 "assist.4gl"
	g_free(s);
#line 484 "assist.4gl"
	return 1;
#line 485 "assist.4gl"
}
#line 486 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 488 "assist.4gl"
return 0;
#line 488 "assist.4gl"
}
#line 488 "assist.4gl"
 
#line 493 "assist.4gl"
 
#line 493 "assist.4gl"
 
#line 493 "assist.4gl"

#line 493 "assist.4gl"
int aclfgl_field_hide (int nargs){ 
#line 493 "assist.4gl"

#line 493 "assist.4gl"
static char _functionName[] = "field_hide";
#line 493 "assist.4gl"
long g;
#line 496 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 496 "assist.4gl"
{&g,2,0}
#line 496 "assist.4gl"
}; /* end of binding */
#line 496 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 496 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 496 "assist.4gl"
pop_params(fbind,1);
#line 496 "assist.4gl"
debug("Hiding field %p\n",g);fflush(stdout);
#line 497 "assist.4gl"
//CHK_UI
#line 498 "assist.4gl"
debug("g=%p\n",g);
#line 499 "assist.4gl"
gtk_widget_hide((GtkWidget *)g);
#line 500 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 502 "assist.4gl"
return 0;
#line 502 "assist.4gl"
}
#line 502 "assist.4gl"
 
#line 506 "assist.4gl"
 
#line 506 "assist.4gl"
 
#line 506 "assist.4gl"

#line 506 "assist.4gl"
int aclfgl_field_show (int nargs){ 
#line 506 "assist.4gl"

#line 506 "assist.4gl"
static char _functionName[] = "field_show";
#line 506 "assist.4gl"
long g;
#line 509 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 509 "assist.4gl"
{&g,2,0}
#line 509 "assist.4gl"
}; /* end of binding */
#line 509 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 509 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 509 "assist.4gl"
pop_params(fbind,1);
#line 509 "assist.4gl"
CHK_UI
#line 510 "assist.4gl"
gtk_widget_show((GtkWidget *)g);
#line 511 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 513 "assist.4gl"
return 0;
#line 513 "assist.4gl"
}
#line 513 "assist.4gl"
 
#line 517 "assist.4gl"
 
#line 517 "assist.4gl"
 
#line 517 "assist.4gl"

#line 517 "assist.4gl"
int aclfgl_form_caption_get (int nargs){ 
#line 517 "assist.4gl"

#line 517 "assist.4gl"
static char _functionName[] = "form_caption_get";
#line 517 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 519 "assist.4gl"

#line 519 "assist.4gl"
}; /* end of binding */
#line 519 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 519 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 519 "assist.4gl"
pop_params(fbind,0);
#line 519 "assist.4gl"
CHK_UI
#line 520 "assist.4gl"
	//gtk_window_get_title(get_curr_win_gtk());
#line 521 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 523 "assist.4gl"
return 0;
#line 523 "assist.4gl"
}
#line 523 "assist.4gl"
 
#line 527 "assist.4gl"
 
#line 527 "assist.4gl"
 
#line 527 "assist.4gl"

#line 527 "assist.4gl"
int aclfgl_form_hide (int nargs){ 
#line 527 "assist.4gl"

#line 527 "assist.4gl"
static char _functionName[] = "form_hide";
#line 527 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 529 "assist.4gl"

#line 529 "assist.4gl"
}; /* end of binding */
#line 529 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 529 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 529 "assist.4gl"
pop_params(fbind,0);
#line 529 "assist.4gl"
CHK_UI
#line 530 "assist.4gl"
	gtk_widget_hide(GTK_WIDGET(get_curr_win_gtk()));
#line 531 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 533 "assist.4gl"
return 0;
#line 533 "assist.4gl"
}
#line 533 "assist.4gl"
 
#line 537 "assist.4gl"
 
#line 537 "assist.4gl"
 
#line 537 "assist.4gl"

#line 537 "assist.4gl"
int aclfgl_form_show (int nargs){ 
#line 537 "assist.4gl"

#line 537 "assist.4gl"
static char _functionName[] = "form_show";
#line 537 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 539 "assist.4gl"

#line 539 "assist.4gl"
}; /* end of binding */
#line 539 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 539 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 539 "assist.4gl"
pop_params(fbind,0);
#line 539 "assist.4gl"
CHK_UI
#line 540 "assist.4gl"
	gtk_widget_show(GTK_WIDGET(get_curr_win_gtk()));
#line 541 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 543 "assist.4gl"
return 0;
#line 543 "assist.4gl"
}
#line 543 "assist.4gl"
 
#line 547 "assist.4gl"
 
#line 547 "assist.4gl"
 
#line 547 "assist.4gl"

#line 547 "assist.4gl"
int aclfgl_form_is_open (int nargs){ 
#line 547 "assist.4gl"

#line 547 "assist.4gl"
static char _functionName[] = "form_is_open";
#line 547 "assist.4gl"
long s;
#line 550 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 550 "assist.4gl"
{&s,2,0}
#line 550 "assist.4gl"
}; /* end of binding */
#line 550 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 550 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 550 "assist.4gl"
pop_params(fbind,1);
#line 550 "assist.4gl"
CHK_UI
#line 551 "assist.4gl"
	//void *find_param (char *name);
#line 552 "assist.4gl"
	//if (find_param(s,WINCODE)) push_int(1);
#line 553 "assist.4gl"
	if ((int)find_param((char *)WINCODE)) push_int(1);
#line 554 "assist.4gl"
	else push_int(0);
#line 555 "assist.4gl"
	return 1;
#line 556 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 558 "assist.4gl"
return 0;
#line 558 "assist.4gl"
}
#line 558 "assist.4gl"
static int tolist(GtkWidget *a) {
#line 565 "assist.4gl"
	a=gtk_object_get_data(GTK_OBJECT(a),"Child");
#line 566 "assist.4gl"
	return (int)a;
#line 567 "assist.4gl"
}
#line 568 "assist.4gl"
/* End of code */ 
#line 574 "assist.4gl"
 
#line 574 "assist.4gl"
 
#line 574 "assist.4gl"

#line 574 "assist.4gl"
int aclfgl_list_count_get (int nargs){ 
#line 574 "assist.4gl"

#line 574 "assist.4gl"
static char _functionName[] = "list_count_get";
#line 574 "assist.4gl"
long g;
#line 577 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 577 "assist.4gl"
{&g,2,0}
#line 577 "assist.4gl"
}; /* end of binding */
#line 577 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 577 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 577 "assist.4gl"
pop_params(fbind,1);
#line 577 "assist.4gl"
CHK_UI
#line 578 "assist.4gl"
	g=tolist(GTK_WIDGET(g));
#line 579 "assist.4gl"
	push_int(GTK_CLIST(g)->rows);
#line 580 "assist.4gl"
	return 1;
#line 581 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 583 "assist.4gl"
return 0;
#line 583 "assist.4gl"
}
#line 583 "assist.4gl"
 
#line 587 "assist.4gl"
 
#line 587 "assist.4gl"
 
#line 587 "assist.4gl"

#line 587 "assist.4gl"
int aclfgl_list_current_get (int nargs){ 
#line 587 "assist.4gl"

#line 587 "assist.4gl"
static char _functionName[] = "list_current_get";
#line 587 "assist.4gl"
long s;
#line 590 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 590 "assist.4gl"
{&s,2,0}
#line 590 "assist.4gl"
}; /* end of binding */
#line 590 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 590 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 590 "assist.4gl"
pop_params(fbind,1);
#line 590 "assist.4gl"
CHK_UI
#line 591 "assist.4gl"
{
#line 592 "assist.4gl"
GList* sel ;
#line 593 "assist.4gl"
s=tolist(GTK_WIDGET(s));
#line 594 "assist.4gl"
sel = GTK_CLIST(s)->selection;
#line 595 "assist.4gl"
push_int(sel ? (int)(sel->data) :  -1);
#line 596 "assist.4gl"
return 1;
#line 597 "assist.4gl"
}
#line 598 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 600 "assist.4gl"
return 0;
#line 600 "assist.4gl"
}
#line 600 "assist.4gl"
 
#line 604 "assist.4gl"
 
#line 604 "assist.4gl"
 
#line 604 "assist.4gl"

#line 604 "assist.4gl"
int aclfgl_list_delete (int nargs){ 
#line 604 "assist.4gl"

#line 604 "assist.4gl"
static char _functionName[] = "list_delete";
#line 604 "assist.4gl"
long s;
#line 607 "assist.4gl"
long n;
#line 607 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 607 "assist.4gl"
{&s,2,0},
#line 607 "assist.4gl"
{&n,2,0}
#line 607 "assist.4gl"
}; /* end of binding */
#line 607 "assist.4gl"
char *_paramnames[]={"s","n"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 607 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 607 "assist.4gl"
pop_params(fbind,2);
#line 607 "assist.4gl"
CHK_UI
#line 608 "assist.4gl"
	s=tolist(GTK_WIDGET(s));
#line 609 "assist.4gl"
gtk_clist_remove(GTK_CLIST(s),n);
#line 610 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 612 "assist.4gl"
return 0;
#line 612 "assist.4gl"
}
#line 612 "assist.4gl"
 
#line 616 "assist.4gl"
 
#line 616 "assist.4gl"
 
#line 616 "assist.4gl"

#line 616 "assist.4gl"
int aclfgl_list_insert (int nargs){ 
#line 616 "assist.4gl"

#line 616 "assist.4gl"
static char _functionName[] = "list_insert";
#line 616 "assist.4gl"
long s;
#line 620 "assist.4gl"
long n;
#line 620 "assist.4gl"
char str [512+1];
#line 620 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 620 "assist.4gl"
{&s,2,0},
#line 620 "assist.4gl"
{&n,2,0},
#line 620 "assist.4gl"
{&str,0,512}
#line 620 "assist.4gl"
}; /* end of binding */
#line 620 "assist.4gl"
char *_paramnames[]={"s","n","str"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 620 "assist.4gl"
if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
#line 620 "assist.4gl"
pop_params(fbind,3);
#line 620 "assist.4gl"
CHK_UI
#line 621 "assist.4gl"
	s=tolist(GTK_WIDGET(s));
#line 622 "assist.4gl"
trim(str);
#line 623 "assist.4gl"
gtk_clist_insert((GtkCList *)s,(gint)n,(char **)&str);
#line 624 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 626 "assist.4gl"
return 0;
#line 626 "assist.4gl"
}
#line 626 "assist.4gl"
 
#line 630 "assist.4gl"
 
#line 630 "assist.4gl"
 
#line 630 "assist.4gl"

#line 630 "assist.4gl"
int aclfgl_list_selected (int nargs){ 
#line 630 "assist.4gl"

#line 630 "assist.4gl"
static char _functionName[] = "list_selected";
#line 630 "assist.4gl"
long s;
#line 633 "assist.4gl"
long n;
#line 633 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 633 "assist.4gl"
{&s,2,0},
#line 633 "assist.4gl"
{&n,2,0}
#line 633 "assist.4gl"
}; /* end of binding */
#line 633 "assist.4gl"
char *_paramnames[]={"s","n"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 633 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 633 "assist.4gl"
pop_params(fbind,2);
#line 633 "assist.4gl"
CHK_UI
#line 634 "assist.4gl"
{
#line 635 "assist.4gl"
GList* sel ;
#line 636 "assist.4gl"
s=tolist(GTK_WIDGET(s));
#line 637 "assist.4gl"
sel = GTK_CLIST(s)->selection;
#line 638 "assist.4gl"
}
#line 639 "assist.4gl"
//
#line 640 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 642 "assist.4gl"
return 0;
#line 642 "assist.4gl"
}
#line 642 "assist.4gl"
 
#line 644 "assist.4gl"
 
#line 644 "assist.4gl"
 
#line 644 "assist.4gl"

#line 644 "assist.4gl"
int aclfgl_splat_with_image (int nargs){ 
#line 644 "assist.4gl"

#line 644 "assist.4gl"
static char _functionName[] = "splat_with_image";
#line 644 "assist.4gl"
long w;
#line 648 "assist.4gl"
char img_file [256+1];
#line 648 "assist.4gl"
char lv_config [512+1];
#line 648 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 648 "assist.4gl"
{&img_file,0,256},
#line 648 "assist.4gl"
{&w,2,0}
#line 648 "assist.4gl"
}; /* end of binding */
#line 648 "assist.4gl"
char *_paramnames[]={"img_file","w"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 648 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 648 "assist.4gl"
pop_params(fbind,2);
#line 648 "assist.4gl"

#line 648 "assist.4gl"

#line 648 "assist.4gl"
aclfgli_clr_err_flg();
#line 648 "assist.4gl"

#line 648 "assist.4gl"
push_long(100);
#line 649 "assist.4gl"

#line 649 "assist.4gl"
pop_var2(&w,2,0);
#line 649 "assist.4gl"

#line 649 "assist.4gl"
/* End command */
#line 649 "assist.4gl"
{debug("Line 648 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 649 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(648,_module_name);
#line 649 "assist.4gl"
/* ERROR */   if (status<0) chk_err(648,_module_name);
#line 649 "assist.4gl"
}
#line 649 "assist.4gl"

#line 649 "assist.4gl"

#line 649 "assist.4gl"
aclfgli_clr_err_flg();
#line 649 "assist.4gl"

#line 649 "assist.4gl"
push_char("filename='");
#line 649 "assist.4gl"

#line 649 "assist.4gl"
push_variable(&img_file,0x1000000);
#line 649 "assist.4gl"
pushop(OP_CLIP);
#line 649 "assist.4gl"
pushop(OP_CONCAT);
#line 649 "assist.4gl"
push_char("';width='");
#line 649 "assist.4gl"

#line 649 "assist.4gl"
pushop(OP_CONCAT);
#line 649 "assist.4gl"
push_variable(&w,0x2);
#line 649 "assist.4gl"
push_char("<<<<");
#line 649 "assist.4gl"

#line 649 "assist.4gl"
pushop(OP_USING);
#line 649 "assist.4gl"
pushop(OP_CONCAT);
#line 649 "assist.4gl"
push_char("'");
#line 651 "assist.4gl"

#line 651 "assist.4gl"
pushop(OP_CONCAT);
#line 651 "assist.4gl"
pop_var2(&lv_config,0,512);
#line 651 "assist.4gl"

#line 651 "assist.4gl"
/* End command */
#line 651 "assist.4gl"
{debug("Line 649 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 651 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(649,_module_name);
#line 651 "assist.4gl"
/* ERROR */   if (status<0) chk_err(649,_module_name);
#line 651 "assist.4gl"
}
#line 651 "assist.4gl"

#line 651 "assist.4gl"

#line 651 "assist.4gl"
aclfgli_clr_err_flg();
#line 651 "assist.4gl"

#line 651 "assist.4gl"
CHK_UI
#line 652 "assist.4gl"
{
#line 653 "assist.4gl"
GtkWidget *widget;
#line 654 "assist.4gl"
GtkWidget *cw;
#line 655 "assist.4gl"
trim(lv_config);
#line 656 "assist.4gl"
widget=make_widget("pixmap",lv_config,w);
#line 657 "assist.4gl"
gtk_widget_show(widget);
#line 658 "assist.4gl"
cw=GTK_WIDGET(get_curr_win_gtk());
#line 659 "assist.4gl"
gtk_fixed_put (GTK_FIXED (cw), widget, 0, 20);
#line 660 "assist.4gl"
gtk_widget_show(cw);
#line 661 "assist.4gl"
}
#line 662 "assist.4gl"
/* End of code */
#line 663 "assist.4gl"
/* End command */
#line 663 "assist.4gl"
{debug("Line 651 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 664 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(651,_module_name);
#line 664 "assist.4gl"
/* ERROR */   if (status<0) chk_err(651,_module_name);
#line 664 "assist.4gl"
}
#line 664 "assist.4gl"
A4GLSTK_popFunction();
#line 664 "assist.4gl"
return 0;
#line 664 "assist.4gl"
}
#line 664 "assist.4gl"
