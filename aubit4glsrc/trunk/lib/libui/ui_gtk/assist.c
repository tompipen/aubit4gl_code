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
/*
#line 83 "assist.4gl"
=====================================================================
#line 84 "assist.4gl"
                    Functions definitions
#line 85 "assist.4gl"
=====================================================================
#line 86 "assist.4gl"
*/
#line 87 "assist.4gl"

#line 88 "assist.4gl"
/**
#line 89 "assist.4gl"
 *
#line 90 "assist.4gl"
 * @todo Describe function
#line 91 "assist.4gl"
 */
#line 92 "assist.4gl"
void *
#line 93 "assist.4gl"
find_curr_window(void) 
#line 94 "assist.4gl"
{
#line 95 "assist.4gl"
void *w;
#line 96 "assist.4gl"
	w=get_curr_win_gtk();
#line 97 "assist.4gl"
	if (gtk_object_get_data(w,"TOP")) {
#line 98 "assist.4gl"
		debug("Has parent...");
#line 99 "assist.4gl"
		w=gtk_object_get_data(w,"TOP");
#line 100 "assist.4gl"
	}
#line 101 "assist.4gl"
	return w;
#line 102 "assist.4gl"
}
#line 103 "assist.4gl"
/* End of code */ 
#line 109 "assist.4gl"
 
#line 109 "assist.4gl"
 
#line 109 "assist.4gl"

#line 109 "assist.4gl"
int aclfgl_set_window_title (int nargs){ 
#line 109 "assist.4gl"

#line 109 "assist.4gl"
static char _functionName[] = "set_window_title";
#line 109 "assist.4gl"
char s [256+1];
#line 113 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 113 "assist.4gl"
{&s,0,256}
#line 113 "assist.4gl"
}; /* end of binding */
#line 113 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 113 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 113 "assist.4gl"
pop_params(fbind,1);
#line 113 "assist.4gl"
CHK_UI
#line 114 "assist.4gl"
	trim(s);
#line 115 "assist.4gl"
	gtk_window_set_title(GTK_WINDOW(find_curr_window()),s);
#line 116 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 119 "assist.4gl"
return 0;
#line 119 "assist.4gl"
}
#line 119 "assist.4gl"
 
#line 123 "assist.4gl"
 
#line 123 "assist.4gl"
 
#line 123 "assist.4gl"

#line 123 "assist.4gl"
int aclfgl_get_window_title (int nargs){ 
#line 123 "assist.4gl"

#line 123 "assist.4gl"
static char _functionName[] = "get_window_title";
#line 123 "assist.4gl"
char s [256+1];
#line 126 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 126 "assist.4gl"
{&s,0,256}
#line 126 "assist.4gl"
}; /* end of binding */
#line 126 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 126 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 126 "assist.4gl"
pop_params(fbind,1);
#line 126 "assist.4gl"
CHK_UI
#line 127 "assist.4gl"
	trim(s);
#line 128 "assist.4gl"
	gtk_window_set_title(GTK_WINDOW(get_curr_win_gtk()),s);
#line 129 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 131 "assist.4gl"
return 0;
#line 131 "assist.4gl"
}
#line 131 "assist.4gl"
 
#line 136 "assist.4gl"
 
#line 136 "assist.4gl"
 
#line 136 "assist.4gl"

#line 136 "assist.4gl"
int aclfgl_set_window_icon (int nargs){ 
#line 136 "assist.4gl"

#line 136 "assist.4gl"
static char _functionName[] = "set_window_icon";
#line 136 "assist.4gl"
char s [256+1];
#line 140 "assist.4gl"
long w;
#line 140 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 140 "assist.4gl"
{&s,0,256}
#line 140 "assist.4gl"
}; /* end of binding */
#line 140 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 140 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 140 "assist.4gl"
pop_params(fbind,1);
#line 140 "assist.4gl"
CHK_UI
#line 141 "assist.4gl"
	trim(s);
#line 142 "assist.4gl"
	w=(int)make_pixmap(s);   //warning: assignment makes integer from pointer without a cast
#line 143 "assist.4gl"

#line 144 "assist.4gl"
	trim(s);
#line 145 "assist.4gl"
	//gtk_window_set_icon(GTK_WINDOW(find_curr_window()),w,0,0); ?
#line 146 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 149 "assist.4gl"
return 0;
#line 149 "assist.4gl"
}
#line 149 "assist.4gl"
 
#line 153 "assist.4gl"
 
#line 153 "assist.4gl"
 
#line 153 "assist.4gl"

#line 153 "assist.4gl"
int aclfgl_run_gui (int nargs){ 
#line 153 "assist.4gl"

#line 153 "assist.4gl"
static char _functionName[] = "run_gui";
#line 153 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 155 "assist.4gl"

#line 155 "assist.4gl"
}; /* end of binding */
#line 155 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 155 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 155 "assist.4gl"
pop_params(fbind,0);
#line 155 "assist.4gl"
CHK_UI
#line 156 "assist.4gl"
  while (1) {
#line 157 "assist.4gl"
    a4gl_usleep (100);
#line 158 "assist.4gl"
	gui_run_til_no_more ();
#line 159 "assist.4gl"
  }
#line 160 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 162 "assist.4gl"
return 0;
#line 162 "assist.4gl"
}
#line 162 "assist.4gl"
 
#line 181 "assist.4gl"
 
#line 181 "assist.4gl"
 
#line 181 "assist.4gl"

#line 181 "assist.4gl"
int aclfgl_set_frame_style (int nargs){ 
#line 181 "assist.4gl"

#line 181 "assist.4gl"
static char _functionName[] = "set_frame_style";
#line 181 "assist.4gl"
long s;
#line 184 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 184 "assist.4gl"
{&s,2,0}
#line 184 "assist.4gl"
}; /* end of binding */
#line 184 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 184 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 184 "assist.4gl"
pop_params(fbind,1);
#line 184 "assist.4gl"
CHK_UI
#line 185 "assist.4gl"
frame_style=s;
#line 186 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 188 "assist.4gl"
return 0;
#line 188 "assist.4gl"
}
#line 188 "assist.4gl"
 
#line 195 "assist.4gl"
 
#line 195 "assist.4gl"
 
#line 195 "assist.4gl"

#line 195 "assist.4gl"
int aclfgl_yeild (int nargs){ 
#line 195 "assist.4gl"

#line 195 "assist.4gl"
static char _functionName[] = "yeild";
#line 195 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 197 "assist.4gl"

#line 197 "assist.4gl"
}; /* end of binding */
#line 197 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 197 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 197 "assist.4gl"
pop_params(fbind,0);
#line 197 "assist.4gl"
CHK_UI
#line 198 "assist.4gl"
  gui_run_til_no_more ();
#line 199 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 201 "assist.4gl"
return 0;
#line 201 "assist.4gl"
}
#line 201 "assist.4gl"
 
#line 214 "assist.4gl"
 
#line 214 "assist.4gl"
 
#line 214 "assist.4gl"

#line 214 "assist.4gl"
int aclfgl_set_window_type (int nargs){ 
#line 214 "assist.4gl"

#line 214 "assist.4gl"
static char _functionName[] = "set_window_type";
#line 214 "assist.4gl"
long a;
#line 217 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 217 "assist.4gl"
{&a,2,0}
#line 217 "assist.4gl"
}; /* end of binding */
#line 217 "assist.4gl"
char *_paramnames[]={"a"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 217 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 217 "assist.4gl"
pop_params(fbind,1);
#line 217 "assist.4gl"
CHK_UI
#line 218 "assist.4gl"
window_frame_type=a;
#line 219 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 221 "assist.4gl"
return 0;
#line 221 "assist.4gl"
}
#line 221 "assist.4gl"
 
#line 225 "assist.4gl"
 
#line 225 "assist.4gl"
 
#line 225 "assist.4gl"

#line 225 "assist.4gl"
int aclfgl_set_prompt_style (int nargs){ 
#line 225 "assist.4gl"

#line 225 "assist.4gl"
static char _functionName[] = "set_prompt_style";
#line 225 "assist.4gl"
long a;
#line 228 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 228 "assist.4gl"
{&a,2,0}
#line 228 "assist.4gl"
}; /* end of binding */
#line 228 "assist.4gl"
char *_paramnames[]={"a"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 228 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 228 "assist.4gl"
pop_params(fbind,1);
#line 228 "assist.4gl"
CHK_UI
#line 229 "assist.4gl"
gui_prompt_style(a);
#line 230 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 232 "assist.4gl"
return 0;
#line 232 "assist.4gl"
}
#line 232 "assist.4gl"
GtkWidget *file_selector;
#line 239 "assist.4gl"
char selected_filename[256]="";
#line 240 "assist.4gl"

#line 241 "assist.4gl"
void
#line 242 "assist.4gl"
store_filename(GtkFileSelection *selector, gpointer user_data)
#line 243 "assist.4gl"
{
#line 244 "assist.4gl"
	strcpy(selected_filename , gtk_file_selection_get_filename (GTK_FILE_SELECTION(file_selector)));
#line 245 "assist.4gl"
}
#line 246 "assist.4gl"
/* End of code */ 
#line 251 "assist.4gl"
 
#line 251 "assist.4gl"
 
#line 251 "assist.4gl"

#line 251 "assist.4gl"
int aclfgl_get_filename (int nargs){ 
#line 251 "assist.4gl"

#line 251 "assist.4gl"
static char _functionName[] = "get_filename";
#line 251 "assist.4gl"
char title [256+1];
#line 257 "assist.4gl"
char fname [256+1];
#line 257 "assist.4gl"
char deffile [256+1];
#line 257 "assist.4gl"
char pattern [256+1];
#line 257 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 257 "assist.4gl"
{&title,0,256},
#line 257 "assist.4gl"
{&deffile,0,256},
#line 257 "assist.4gl"
{&pattern,0,256}
#line 257 "assist.4gl"
}; /* end of binding */
#line 257 "assist.4gl"
char *_paramnames[]={"title","deffile","pattern"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 257 "assist.4gl"
if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
#line 257 "assist.4gl"
pop_params(fbind,3);
#line 257 "assist.4gl"
{
#line 258 "assist.4gl"
	GtkWidget *b;
#line 259 "assist.4gl"
	GtkWidget *w;
#line 260 "assist.4gl"
	
#line 261 "assist.4gl"
	
#line 262 "assist.4gl"
	CHK_UI
#line 263 "assist.4gl"
	trim(title);
#line 264 "assist.4gl"
	trim(deffile);
#line 265 "assist.4gl"
	trim(pattern);
#line 266 "assist.4gl"
	file_selector = gtk_file_selection_new(title);
#line 267 "assist.4gl"
	gtk_file_selection_set_filename(GTK_FILE_SELECTION(file_selector),deffile);
#line 268 "assist.4gl"
	gtk_file_selection_complete(GTK_FILE_SELECTION(file_selector),pattern);
#line 269 "assist.4gl"

#line 270 "assist.4gl"
	b=GTK_FILE_SELECTION(file_selector)->ok_button;
#line 271 "assist.4gl"
	w=GTK_FILE_SELECTION(file_selector)->fileop_dialog;
#line 272 "assist.4gl"

#line 273 "assist.4gl"
	//gtk_window_set_modal(w,1);
#line 274 "assist.4gl"

#line 275 "assist.4gl"
	gtk_signal_connect (GTK_OBJECT (b), "clicked", GTK_SIGNAL_FUNC (store_filename), 0);
#line 276 "assist.4gl"

#line 277 "assist.4gl"
	/* Ensure that the dialog box is destroyed when the user clicks a button. */
#line 278 "assist.4gl"
#if (! defined(__CYGWIN__) && ! defined(__MINGW32__))
#line 279 "assist.4gl"
	gtk_signal_connect_object (GTK_OBJECT (b),
#line 280 "assist.4gl"
	                                       "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy),
#line 281 "assist.4gl"
	                                       (gpointer) file_selector);
#line 282 "assist.4gl"

#line 283 "assist.4gl"
	gtk_signal_connect_object (GTK_OBJECT (GTK_FILE_SELECTION(file_selector)->cancel_button),
#line 284 "assist.4gl"
	                                       "clicked", GTK_SIGNAL_FUNC (gtk_widget_destroy),
#line 285 "assist.4gl"
	                                       (gpointer) file_selector);
#line 286 "assist.4gl"
#endif
#line 287 "assist.4gl"
	/* Display that dialog */
#line 288 "assist.4gl"

#line 289 "assist.4gl"
	gtk_widget_show (file_selector);
#line 290 "assist.4gl"
	while (1) {
#line 291 "assist.4gl"
	    a4gl_usleep (100);
#line 292 "assist.4gl"
	 	gui_run_til_no_more ();
#line 293 "assist.4gl"
		if (strlen(selected_filename)!=0) {
#line 294 "assist.4gl"
			break;
#line 295 "assist.4gl"
		}
#line 296 "assist.4gl"
	}
#line 297 "assist.4gl"
	strcpy(fname,selected_filename);
#line 298 "assist.4gl"
}
#line 299 "assist.4gl"
/* End of code */
#line 300 "assist.4gl"

#line 300 "assist.4gl"
aclfgli_clr_err_flg();
#line 300 "assist.4gl"

#line 300 "assist.4gl"
push_variable(&fname,0x1000000);
#line 302 "assist.4gl"
A4GLSTK_popFunction();
#line 302 "assist.4gl"
return 1;
#line 302 "assist.4gl"
/* End command */
#line 302 "assist.4gl"
{debug("Line 257 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 302 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(257,_module_name);
#line 302 "assist.4gl"
/* ERROR */   if (status<0) chk_err(257,_module_name);
#line 302 "assist.4gl"
}
#line 302 "assist.4gl"
A4GLSTK_popFunction();
#line 302 "assist.4gl"
return 0;
#line 302 "assist.4gl"
}
#line 302 "assist.4gl"
 
#line 307 "assist.4gl"
 
#line 307 "assist.4gl"
 
#line 307 "assist.4gl"

#line 307 "assist.4gl"
int aclfgl_app_top_get (int nargs){ 
#line 307 "assist.4gl"

#line 307 "assist.4gl"
static char _functionName[] = "app_top_get";
#line 307 "assist.4gl"
long a;
#line 310 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 310 "assist.4gl"

#line 310 "assist.4gl"
}; /* end of binding */
#line 310 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 310 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 310 "assist.4gl"
pop_params(fbind,0);
#line 310 "assist.4gl"
CHK_UI
#line 311 "assist.4gl"
a= (long)win_screen;
#line 312 "assist.4gl"
/* End of code */
#line 313 "assist.4gl"

#line 313 "assist.4gl"
aclfgli_clr_err_flg();
#line 313 "assist.4gl"

#line 313 "assist.4gl"
push_variable(&a,0x2);
#line 313 "assist.4gl"
A4GLSTK_popFunction();
#line 313 "assist.4gl"
return 1;
#line 313 "assist.4gl"
/* End command */
#line 313 "assist.4gl"
{debug("Line 310 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 313 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(310,_module_name);
#line 313 "assist.4gl"
/* ERROR */   if (status<0) chk_err(310,_module_name);
#line 313 "assist.4gl"
}
#line 313 "assist.4gl"
A4GLSTK_popFunction();
#line 315 "assist.4gl"
return 0;
#line 315 "assist.4gl"
}
#line 315 "assist.4gl"
 
#line 320 "assist.4gl"
 
#line 320 "assist.4gl"
 
#line 320 "assist.4gl"

#line 320 "assist.4gl"
int aclfgl_app_hide (int nargs){ 
#line 320 "assist.4gl"

#line 320 "assist.4gl"
static char _functionName[] = "app_hide";
#line 320 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 322 "assist.4gl"

#line 322 "assist.4gl"
}; /* end of binding */
#line 322 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 322 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 322 "assist.4gl"
pop_params(fbind,0);
#line 322 "assist.4gl"
CHK_UI
#line 323 "assist.4gl"
gtk_widget_hide(win_screen);
#line 324 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 326 "assist.4gl"
return 0;
#line 326 "assist.4gl"
}
#line 326 "assist.4gl"
 
#line 330 "assist.4gl"
 
#line 330 "assist.4gl"
 
#line 330 "assist.4gl"

#line 330 "assist.4gl"
int aclfgl_app_show (int nargs){ 
#line 330 "assist.4gl"

#line 330 "assist.4gl"
static char _functionName[] = "app_show";
#line 330 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 332 "assist.4gl"

#line 332 "assist.4gl"
}; /* end of binding */
#line 332 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 332 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 332 "assist.4gl"
pop_params(fbind,0);
#line 332 "assist.4gl"
CHK_UI
#line 333 "assist.4gl"
gtk_widget_show(win_screen);
#line 334 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 336 "assist.4gl"
return 0;
#line 336 "assist.4gl"
}
#line 336 "assist.4gl"
 
#line 340 "assist.4gl"
 
#line 340 "assist.4gl"
 
#line 340 "assist.4gl"

#line 340 "assist.4gl"
int aclfgl_app_maximize (int nargs){ 
#line 340 "assist.4gl"

#line 340 "assist.4gl"
static char _functionName[] = "app_maximize";
#line 340 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 342 "assist.4gl"

#line 342 "assist.4gl"
}; /* end of binding */
#line 342 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 342 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 342 "assist.4gl"
pop_params(fbind,0);
#line 342 "assist.4gl"
CHK_UI
#line 343 "assist.4gl"
// Needs coding
#line 344 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 346 "assist.4gl"
return 0;
#line 346 "assist.4gl"
}
#line 346 "assist.4gl"
 
#line 350 "assist.4gl"
 
#line 350 "assist.4gl"
 
#line 350 "assist.4gl"

#line 350 "assist.4gl"
int aclfgl_app_minimize (int nargs){ 
#line 350 "assist.4gl"

#line 350 "assist.4gl"
static char _functionName[] = "app_minimize";
#line 350 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 352 "assist.4gl"

#line 352 "assist.4gl"
}; /* end of binding */
#line 352 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 352 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 352 "assist.4gl"
pop_params(fbind,0);
#line 352 "assist.4gl"
CHK_UI
#line 353 "assist.4gl"
// Needs coding
#line 354 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 356 "assist.4gl"
return 0;
#line 356 "assist.4gl"
}
#line 356 "assist.4gl"
 
#line 360 "assist.4gl"
 
#line 360 "assist.4gl"
 
#line 360 "assist.4gl"

#line 360 "assist.4gl"
int aclfgl_app_restore (int nargs){ 
#line 360 "assist.4gl"

#line 360 "assist.4gl"
static char _functionName[] = "app_restore";
#line 360 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 362 "assist.4gl"

#line 362 "assist.4gl"
}; /* end of binding */
#line 362 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 362 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 362 "assist.4gl"
pop_params(fbind,0);
#line 362 "assist.4gl"
CHK_UI
#line 363 "assist.4gl"
// Needs coding
#line 364 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 366 "assist.4gl"
return 0;
#line 366 "assist.4gl"
}
#line 366 "assist.4gl"
 
#line 371 "assist.4gl"
 
#line 371 "assist.4gl"
 
#line 371 "assist.4gl"

#line 371 "assist.4gl"
int aclfgl_entry_max_chars_set (int nargs){ 
#line 371 "assist.4gl"

#line 371 "assist.4gl"
static char _functionName[] = "entry_max_chars_set";
#line 371 "assist.4gl"
long l;
#line 375 "assist.4gl"
long g;
#line 375 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 375 "assist.4gl"
{&g,2,0},
#line 375 "assist.4gl"
{&l,2,0}
#line 375 "assist.4gl"
}; /* end of binding */
#line 375 "assist.4gl"
char *_paramnames[]={"g","l"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 375 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 375 "assist.4gl"
pop_params(fbind,2);
#line 375 "assist.4gl"
CHK_UI
#line 376 "assist.4gl"
gtk_entry_set_max_length(GTK_ENTRY(g),l);
#line 377 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 379 "assist.4gl"
return 0;
#line 379 "assist.4gl"
}
#line 379 "assist.4gl"
 
#line 385 "assist.4gl"
 
#line 385 "assist.4gl"
 
#line 385 "assist.4gl"

#line 385 "assist.4gl"
int aclfgl_entry_selected_cut (int nargs){ 
#line 385 "assist.4gl"

#line 385 "assist.4gl"
static char _functionName[] = "entry_selected_cut";
#line 385 "assist.4gl"
long g;
#line 388 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 388 "assist.4gl"
{&g,2,0}
#line 388 "assist.4gl"
}; /* end of binding */
#line 388 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 388 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 388 "assist.4gl"
pop_params(fbind,1);
#line 388 "assist.4gl"
{
#line 389 "assist.4gl"
CHK_UI
#line 390 "assist.4gl"
	gtk_editable_cut_clipboard(GTK_EDITABLE(g));
#line 391 "assist.4gl"
}
#line 392 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 394 "assist.4gl"
return 0;
#line 394 "assist.4gl"
}
#line 394 "assist.4gl"
 
#line 398 "assist.4gl"
 
#line 398 "assist.4gl"
 
#line 398 "assist.4gl"

#line 398 "assist.4gl"
int aclfgl_entry_selected_copy (int nargs){ 
#line 398 "assist.4gl"

#line 398 "assist.4gl"
static char _functionName[] = "entry_selected_copy";
#line 398 "assist.4gl"
long g;
#line 401 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 401 "assist.4gl"
{&g,2,0}
#line 401 "assist.4gl"
}; /* end of binding */
#line 401 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 401 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 401 "assist.4gl"
pop_params(fbind,1);
#line 401 "assist.4gl"
{
#line 402 "assist.4gl"
CHK_UI
#line 403 "assist.4gl"
	gtk_editable_copy_clipboard(GTK_EDITABLE(g));
#line 404 "assist.4gl"
}
#line 405 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 407 "assist.4gl"
return 0;
#line 407 "assist.4gl"
}
#line 407 "assist.4gl"
 
#line 411 "assist.4gl"
 
#line 411 "assist.4gl"
 
#line 411 "assist.4gl"

#line 411 "assist.4gl"
int aclfgl_entry_selected_paste (int nargs){ 
#line 411 "assist.4gl"

#line 411 "assist.4gl"
static char _functionName[] = "entry_selected_paste";
#line 411 "assist.4gl"
long g;
#line 414 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 414 "assist.4gl"
{&g,2,0}
#line 414 "assist.4gl"
}; /* end of binding */
#line 414 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 414 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 414 "assist.4gl"
pop_params(fbind,1);
#line 414 "assist.4gl"
{
#line 415 "assist.4gl"
CHK_UI
#line 416 "assist.4gl"
	gtk_editable_paste_clipboard(GTK_EDITABLE(g));
#line 417 "assist.4gl"
}
#line 418 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 420 "assist.4gl"
return 0;
#line 420 "assist.4gl"
}
#line 420 "assist.4gl"
 
#line 425 "assist.4gl"
 
#line 425 "assist.4gl"
 
#line 425 "assist.4gl"

#line 425 "assist.4gl"
int aclfgl_entry_selection_set (int nargs){ 
#line 425 "assist.4gl"

#line 425 "assist.4gl"
static char _functionName[] = "entry_selection_set";
#line 425 "assist.4gl"
long s;
#line 429 "assist.4gl"
long e;
#line 429 "assist.4gl"
long g;
#line 429 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 429 "assist.4gl"
{&g,2,0},
#line 429 "assist.4gl"
{&s,2,0},
#line 429 "assist.4gl"
{&e,2,0}
#line 429 "assist.4gl"
}; /* end of binding */
#line 429 "assist.4gl"
char *_paramnames[]={"g","s","e"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 429 "assist.4gl"
if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
#line 429 "assist.4gl"
pop_params(fbind,3);
#line 429 "assist.4gl"
{
#line 430 "assist.4gl"
CHK_UI
#line 431 "assist.4gl"
	gtk_editable_select_region(GTK_EDITABLE(g),(gint)s,(gint)e);
#line 432 "assist.4gl"
}
#line 433 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 435 "assist.4gl"
return 0;
#line 435 "assist.4gl"
}
#line 435 "assist.4gl"
 
#line 439 "assist.4gl"
 
#line 439 "assist.4gl"
 
#line 439 "assist.4gl"

#line 439 "assist.4gl"
int aclfgl_entry_text_get (int nargs){ 
#line 439 "assist.4gl"

#line 439 "assist.4gl"
static char _functionName[] = "entry_text_get";
#line 439 "assist.4gl"
long g;
#line 442 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 442 "assist.4gl"
{&g,2,0}
#line 442 "assist.4gl"
}; /* end of binding */
#line 442 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 442 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 442 "assist.4gl"
pop_params(fbind,1);
#line 442 "assist.4gl"
{
#line 443 "assist.4gl"
	char *s;
#line 444 "assist.4gl"
CHK_UI
#line 445 "assist.4gl"
	debug("g=%d %x",g,g);
#line 446 "assist.4gl"
	s=gtk_editable_get_chars(GTK_EDITABLE(g),0,-1);
#line 447 "assist.4gl"
	push_char(s);
#line 448 "assist.4gl"
	g_free(s);
#line 449 "assist.4gl"
	return 1;
#line 450 "assist.4gl"
}
#line 451 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 453 "assist.4gl"
return 0;
#line 453 "assist.4gl"
}
#line 453 "assist.4gl"
 
#line 458 "assist.4gl"
 
#line 458 "assist.4gl"
 
#line 458 "assist.4gl"

#line 458 "assist.4gl"
int aclfgl_field_hide (int nargs){ 
#line 458 "assist.4gl"

#line 458 "assist.4gl"
static char _functionName[] = "field_hide";
#line 458 "assist.4gl"
long g;
#line 461 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 461 "assist.4gl"
{&g,2,0}
#line 461 "assist.4gl"
}; /* end of binding */
#line 461 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 461 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 461 "assist.4gl"
pop_params(fbind,1);
#line 461 "assist.4gl"
debug("Hiding field %p\n",g);fflush(stdout);
#line 462 "assist.4gl"
//CHK_UI
#line 463 "assist.4gl"
debug("g=%p\n",g);
#line 464 "assist.4gl"
gtk_widget_hide((GtkWidget *)g);
#line 465 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 467 "assist.4gl"
return 0;
#line 467 "assist.4gl"
}
#line 467 "assist.4gl"
 
#line 471 "assist.4gl"
 
#line 471 "assist.4gl"
 
#line 471 "assist.4gl"

#line 471 "assist.4gl"
int aclfgl_field_show (int nargs){ 
#line 471 "assist.4gl"

#line 471 "assist.4gl"
static char _functionName[] = "field_show";
#line 471 "assist.4gl"
long g;
#line 474 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 474 "assist.4gl"
{&g,2,0}
#line 474 "assist.4gl"
}; /* end of binding */
#line 474 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 474 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 474 "assist.4gl"
pop_params(fbind,1);
#line 474 "assist.4gl"
CHK_UI
#line 475 "assist.4gl"
gtk_widget_show((GtkWidget *)g);
#line 476 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 478 "assist.4gl"
return 0;
#line 478 "assist.4gl"
}
#line 478 "assist.4gl"
 
#line 482 "assist.4gl"
 
#line 482 "assist.4gl"
 
#line 482 "assist.4gl"

#line 482 "assist.4gl"
int aclfgl_form_caption_get (int nargs){ 
#line 482 "assist.4gl"

#line 482 "assist.4gl"
static char _functionName[] = "form_caption_get";
#line 482 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 484 "assist.4gl"

#line 484 "assist.4gl"
}; /* end of binding */
#line 484 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 484 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 484 "assist.4gl"
pop_params(fbind,0);
#line 484 "assist.4gl"
CHK_UI
#line 485 "assist.4gl"
	//gtk_window_get_title(get_curr_win_gtk());
#line 486 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 488 "assist.4gl"
return 0;
#line 488 "assist.4gl"
}
#line 488 "assist.4gl"
 
#line 492 "assist.4gl"
 
#line 492 "assist.4gl"
 
#line 492 "assist.4gl"

#line 492 "assist.4gl"
int aclfgl_form_hide (int nargs){ 
#line 492 "assist.4gl"

#line 492 "assist.4gl"
static char _functionName[] = "form_hide";
#line 492 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 494 "assist.4gl"

#line 494 "assist.4gl"
}; /* end of binding */
#line 494 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 494 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 494 "assist.4gl"
pop_params(fbind,0);
#line 494 "assist.4gl"
CHK_UI
#line 495 "assist.4gl"
	gtk_widget_hide(GTK_WIDGET(get_curr_win_gtk()));
#line 496 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 498 "assist.4gl"
return 0;
#line 498 "assist.4gl"
}
#line 498 "assist.4gl"
 
#line 502 "assist.4gl"
 
#line 502 "assist.4gl"
 
#line 502 "assist.4gl"

#line 502 "assist.4gl"
int aclfgl_form_show (int nargs){ 
#line 502 "assist.4gl"

#line 502 "assist.4gl"
static char _functionName[] = "form_show";
#line 502 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 504 "assist.4gl"

#line 504 "assist.4gl"
}; /* end of binding */
#line 504 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 504 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 504 "assist.4gl"
pop_params(fbind,0);
#line 504 "assist.4gl"
CHK_UI
#line 505 "assist.4gl"
	gtk_widget_show(GTK_WIDGET(get_curr_win_gtk()));
#line 506 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 508 "assist.4gl"
return 0;
#line 508 "assist.4gl"
}
#line 508 "assist.4gl"
 
#line 512 "assist.4gl"
 
#line 512 "assist.4gl"
 
#line 512 "assist.4gl"

#line 512 "assist.4gl"
int aclfgl_form_is_open (int nargs){ 
#line 512 "assist.4gl"

#line 512 "assist.4gl"
static char _functionName[] = "form_is_open";
#line 512 "assist.4gl"
long s;
#line 515 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 515 "assist.4gl"
{&s,2,0}
#line 515 "assist.4gl"
}; /* end of binding */
#line 515 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 515 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 515 "assist.4gl"
pop_params(fbind,1);
#line 515 "assist.4gl"
CHK_UI
#line 516 "assist.4gl"
	//void *find_param (char *name);
#line 517 "assist.4gl"
	//if (find_param(s,WINCODE)) push_int(1);
#line 518 "assist.4gl"
	if ((int)find_param((char *)WINCODE)) push_int(1);
#line 519 "assist.4gl"
	else push_int(0);
#line 520 "assist.4gl"
	return 1;
#line 521 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 523 "assist.4gl"
return 0;
#line 523 "assist.4gl"
}
#line 523 "assist.4gl"
static int tolist(GtkWidget *a) {
#line 530 "assist.4gl"
	a=gtk_object_get_data(GTK_OBJECT(a),"Child");
#line 531 "assist.4gl"
	return (int)a;
#line 532 "assist.4gl"
}
#line 533 "assist.4gl"
/* End of code */ 
#line 539 "assist.4gl"
 
#line 539 "assist.4gl"
 
#line 539 "assist.4gl"

#line 539 "assist.4gl"
int aclfgl_list_count_get (int nargs){ 
#line 539 "assist.4gl"

#line 539 "assist.4gl"
static char _functionName[] = "list_count_get";
#line 539 "assist.4gl"
long g;
#line 542 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 542 "assist.4gl"
{&g,2,0}
#line 542 "assist.4gl"
}; /* end of binding */
#line 542 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 542 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 542 "assist.4gl"
pop_params(fbind,1);
#line 542 "assist.4gl"
CHK_UI
#line 543 "assist.4gl"
	g=tolist(GTK_WIDGET(g));
#line 544 "assist.4gl"
	push_int(GTK_CLIST(g)->rows);
#line 545 "assist.4gl"
	return 1;
#line 546 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 548 "assist.4gl"
return 0;
#line 548 "assist.4gl"
}
#line 548 "assist.4gl"
 
#line 552 "assist.4gl"
 
#line 552 "assist.4gl"
 
#line 552 "assist.4gl"

#line 552 "assist.4gl"
int aclfgl_list_current_get (int nargs){ 
#line 552 "assist.4gl"

#line 552 "assist.4gl"
static char _functionName[] = "list_current_get";
#line 552 "assist.4gl"
long s;
#line 555 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 555 "assist.4gl"
{&s,2,0}
#line 555 "assist.4gl"
}; /* end of binding */
#line 555 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 555 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 555 "assist.4gl"
pop_params(fbind,1);
#line 555 "assist.4gl"
CHK_UI
#line 556 "assist.4gl"
{
#line 557 "assist.4gl"
GList* sel ;
#line 558 "assist.4gl"
s=tolist(GTK_WIDGET(s));
#line 559 "assist.4gl"
sel = GTK_CLIST(s)->selection;
#line 560 "assist.4gl"
push_int(sel ? (int)(sel->data) :  -1);
#line 561 "assist.4gl"
return 1;
#line 562 "assist.4gl"
}
#line 563 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 565 "assist.4gl"
return 0;
#line 565 "assist.4gl"
}
#line 565 "assist.4gl"
 
#line 569 "assist.4gl"
 
#line 569 "assist.4gl"
 
#line 569 "assist.4gl"

#line 569 "assist.4gl"
int aclfgl_list_delete (int nargs){ 
#line 569 "assist.4gl"

#line 569 "assist.4gl"
static char _functionName[] = "list_delete";
#line 569 "assist.4gl"
long s;
#line 572 "assist.4gl"
long n;
#line 572 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 572 "assist.4gl"
{&s,2,0},
#line 572 "assist.4gl"
{&n,2,0}
#line 572 "assist.4gl"
}; /* end of binding */
#line 572 "assist.4gl"
char *_paramnames[]={"s","n"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 572 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 572 "assist.4gl"
pop_params(fbind,2);
#line 572 "assist.4gl"
CHK_UI
#line 573 "assist.4gl"
	s=tolist(GTK_WIDGET(s));
#line 574 "assist.4gl"
gtk_clist_remove(GTK_CLIST(s),n);
#line 575 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 577 "assist.4gl"
return 0;
#line 577 "assist.4gl"
}
#line 577 "assist.4gl"
 
#line 581 "assist.4gl"
 
#line 581 "assist.4gl"
 
#line 581 "assist.4gl"

#line 581 "assist.4gl"
int aclfgl_list_insert (int nargs){ 
#line 581 "assist.4gl"

#line 581 "assist.4gl"
static char _functionName[] = "list_insert";
#line 581 "assist.4gl"
long s;
#line 585 "assist.4gl"
long n;
#line 585 "assist.4gl"
char str [512+1];
#line 585 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 585 "assist.4gl"
{&s,2,0},
#line 585 "assist.4gl"
{&n,2,0},
#line 585 "assist.4gl"
{&str,0,512}
#line 585 "assist.4gl"
}; /* end of binding */
#line 585 "assist.4gl"
char *_paramnames[]={"s","n","str"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 585 "assist.4gl"
if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
#line 585 "assist.4gl"
pop_params(fbind,3);
#line 585 "assist.4gl"
CHK_UI
#line 586 "assist.4gl"
	s=tolist(GTK_WIDGET(s));
#line 587 "assist.4gl"
trim(str);
#line 588 "assist.4gl"
gtk_clist_insert((GtkCList *)s,(gint)n,(char **)&str);
#line 589 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 591 "assist.4gl"
return 0;
#line 591 "assist.4gl"
}
#line 591 "assist.4gl"
 
#line 595 "assist.4gl"
 
#line 595 "assist.4gl"
 
#line 595 "assist.4gl"

#line 595 "assist.4gl"
int aclfgl_list_selected (int nargs){ 
#line 595 "assist.4gl"

#line 595 "assist.4gl"
static char _functionName[] = "list_selected";
#line 595 "assist.4gl"
long s;
#line 598 "assist.4gl"
long n;
#line 598 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 598 "assist.4gl"
{&s,2,0},
#line 598 "assist.4gl"
{&n,2,0}
#line 598 "assist.4gl"
}; /* end of binding */
#line 598 "assist.4gl"
char *_paramnames[]={"s","n"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 598 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 598 "assist.4gl"
pop_params(fbind,2);
#line 598 "assist.4gl"
CHK_UI
#line 599 "assist.4gl"
{
#line 600 "assist.4gl"
GList* sel ;
#line 601 "assist.4gl"
s=tolist(GTK_WIDGET(s));
#line 602 "assist.4gl"
sel = GTK_CLIST(s)->selection;
#line 603 "assist.4gl"
}
#line 604 "assist.4gl"
//
#line 605 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 607 "assist.4gl"
return 0;
#line 607 "assist.4gl"
}
#line 607 "assist.4gl"
 
#line 609 "assist.4gl"
 
#line 609 "assist.4gl"
 
#line 609 "assist.4gl"

#line 609 "assist.4gl"
int aclfgl_splat_with_image (int nargs){ 
#line 609 "assist.4gl"

#line 609 "assist.4gl"
static char _functionName[] = "splat_with_image";
#line 609 "assist.4gl"
long w;
#line 613 "assist.4gl"
char img_file [256+1];
#line 613 "assist.4gl"
char lv_config [512+1];
#line 613 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 613 "assist.4gl"
{&img_file,0,256},
#line 613 "assist.4gl"
{&w,2,0}
#line 613 "assist.4gl"
}; /* end of binding */
#line 613 "assist.4gl"
char *_paramnames[]={"img_file","w"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 613 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 613 "assist.4gl"
pop_params(fbind,2);
#line 613 "assist.4gl"

#line 613 "assist.4gl"

#line 613 "assist.4gl"
aclfgli_clr_err_flg();
#line 613 "assist.4gl"

#line 613 "assist.4gl"
push_long(100);
#line 614 "assist.4gl"

#line 614 "assist.4gl"
pop_var2(&w,2,0);
#line 614 "assist.4gl"

#line 614 "assist.4gl"
/* End command */
#line 614 "assist.4gl"
{debug("Line 613 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 614 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(613,_module_name);
#line 614 "assist.4gl"
/* ERROR */   if (status<0) chk_err(613,_module_name);
#line 614 "assist.4gl"
}
#line 614 "assist.4gl"

#line 614 "assist.4gl"

#line 614 "assist.4gl"
aclfgli_clr_err_flg();
#line 614 "assist.4gl"

#line 614 "assist.4gl"
push_char("filename='");
#line 614 "assist.4gl"

#line 614 "assist.4gl"
push_variable(&img_file,0x1000000);
#line 614 "assist.4gl"
pushop(OP_CLIP);
#line 614 "assist.4gl"
pushop(OP_CONCAT);
#line 614 "assist.4gl"
push_char("';width='");
#line 614 "assist.4gl"

#line 614 "assist.4gl"
pushop(OP_CONCAT);
#line 614 "assist.4gl"
push_variable(&w,0x2);
#line 614 "assist.4gl"
push_char("<<<<");
#line 614 "assist.4gl"

#line 614 "assist.4gl"
pushop(OP_USING);
#line 614 "assist.4gl"
pushop(OP_CONCAT);
#line 614 "assist.4gl"
push_char("'");
#line 616 "assist.4gl"

#line 616 "assist.4gl"
pushop(OP_CONCAT);
#line 616 "assist.4gl"
pop_var2(&lv_config,0,512);
#line 616 "assist.4gl"

#line 616 "assist.4gl"
/* End command */
#line 616 "assist.4gl"
{debug("Line 614 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 616 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(614,_module_name);
#line 616 "assist.4gl"
/* ERROR */   if (status<0) chk_err(614,_module_name);
#line 616 "assist.4gl"
}
#line 616 "assist.4gl"

#line 616 "assist.4gl"

#line 616 "assist.4gl"
aclfgli_clr_err_flg();
#line 616 "assist.4gl"

#line 616 "assist.4gl"
CHK_UI
#line 617 "assist.4gl"
{
#line 618 "assist.4gl"
GtkWidget *widget;
#line 619 "assist.4gl"
GtkWidget *cw;
#line 620 "assist.4gl"
trim(lv_config);
#line 621 "assist.4gl"
widget=make_widget("pixmap",lv_config,w);
#line 622 "assist.4gl"
gtk_widget_show(widget);
#line 623 "assist.4gl"
cw=GTK_WIDGET(get_curr_win_gtk());
#line 624 "assist.4gl"
gtk_fixed_put (GTK_FIXED (cw), widget, 0, 20);
#line 625 "assist.4gl"
gtk_widget_show(cw);
#line 626 "assist.4gl"
}
#line 627 "assist.4gl"
/* End of code */
#line 628 "assist.4gl"
/* End command */
#line 628 "assist.4gl"
{debug("Line 616 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 629 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(616,_module_name);
#line 629 "assist.4gl"
/* ERROR */   if (status<0) chk_err(616,_module_name);
#line 629 "assist.4gl"
}
#line 629 "assist.4gl"
A4GLSTK_popFunction();
#line 629 "assist.4gl"
return 0;
#line 629 "assist.4gl"
}
#line 629 "assist.4gl"
