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
/* End of code */extern long int_flag;
#line 109 "assist.4gl"
extern long quit_flag;
#line 109 "assist.4gl"
extern long status;
#line 109 "assist.4gl"
extern struct {
#line 109 "assist.4gl"
long sqlcode;
#line 109 "assist.4gl"
char sqlerrm [72+1];
#line 109 "assist.4gl"
char sqlerrp [8+1];
#line 109 "assist.4gl"
long sqlerrd[6];
#line 109 "assist.4gl"
char sqlawarn [8+1];
#line 109 "assist.4gl"
char sqlstate [9+1];
#line 109 "assist.4gl"
} sqlca;
#line 109 "assist.4gl"
extern fgldate today;
#line 109 "assist.4gl"
extern char user [8+1];
#line 109 "assist.4gl"
extern long pageno;
#line 109 "assist.4gl"
extern long lineno;
#line 109 "assist.4gl"
extern long usrtime;
#line 109 "assist.4gl"
extern long curr_hwnd;
#line 109 "assist.4gl"
extern long curr_form;
#line 109 "assist.4gl"
extern char err_file_name [32+1];
#line 109 "assist.4gl"
extern long err_file_no;
#line 109 "assist.4gl"
extern char curr_file_name [32+1];
#line 109 "assist.4gl"
extern long curr_line_no;
#line 109 "assist.4gl"
extern long err_status;
#line 109 "assist.4gl"
extern long aiplib_status;
#line 109 "assist.4gl"
 
#line 109 "assist.4gl"
 
#line 109 "assist.4gl"
 
#line 109 "assist.4gl"

#line 109 "assist.4gl"
int aclfgl_set_window_title (int nargs){ /* Funtion Start */
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
}/* END OF FUNCTION */
#line 119 "assist.4gl"

#line 119 "assist.4gl"

#line 119 "assist.4gl"

#line 119 "assist.4gl"
 
#line 123 "assist.4gl"
 
#line 123 "assist.4gl"
 
#line 123 "assist.4gl"

#line 123 "assist.4gl"
int aclfgl_get_window_title (int nargs){ /* Funtion Start */
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
}/* END OF FUNCTION */
#line 131 "assist.4gl"

#line 131 "assist.4gl"

#line 131 "assist.4gl"

#line 131 "assist.4gl"
 
#line 136 "assist.4gl"
 
#line 136 "assist.4gl"
 
#line 136 "assist.4gl"

#line 136 "assist.4gl"
int aclfgl_set_window_icon (int nargs){ /* Funtion Start */
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
}/* END OF FUNCTION */
#line 149 "assist.4gl"

#line 149 "assist.4gl"

#line 149 "assist.4gl"

#line 149 "assist.4gl"
 
#line 153 "assist.4gl"
 
#line 153 "assist.4gl"
 
#line 153 "assist.4gl"

#line 153 "assist.4gl"
int aclfgl_run_gui (int nargs){ /* Funtion Start */
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
}/* END OF FUNCTION */
#line 162 "assist.4gl"

#line 162 "assist.4gl"

#line 162 "assist.4gl"

#line 162 "assist.4gl"
 
#line 181 "assist.4gl"
 
#line 181 "assist.4gl"
 
#line 181 "assist.4gl"

#line 181 "assist.4gl"
int aclfgl_set_frame_style (int nargs){ /* Funtion Start */
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
}/* END OF FUNCTION */
#line 188 "assist.4gl"

#line 188 "assist.4gl"

#line 188 "assist.4gl"

#line 188 "assist.4gl"
 
#line 195 "assist.4gl"
 
#line 195 "assist.4gl"
 
#line 195 "assist.4gl"

#line 195 "assist.4gl"
int aclfgl_yeild (int nargs){ /* Funtion Start */
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
}/* END OF FUNCTION */
#line 201 "assist.4gl"

#line 201 "assist.4gl"

#line 201 "assist.4gl"

#line 201 "assist.4gl"
 
#line 214 "assist.4gl"
 
#line 214 "assist.4gl"
 
#line 214 "assist.4gl"

#line 214 "assist.4gl"
int aclfgl_set_window_type (int nargs){ /* Funtion Start */
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
}/* END OF FUNCTION */
#line 221 "assist.4gl"

#line 221 "assist.4gl"

#line 221 "assist.4gl"

#line 221 "assist.4gl"
 
#line 225 "assist.4gl"
 
#line 225 "assist.4gl"
 
#line 225 "assist.4gl"

#line 225 "assist.4gl"
int aclfgl_set_prompt_style (int nargs){ /* Funtion Start */
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
}/* END OF FUNCTION */
#line 232 "assist.4gl"

#line 232 "assist.4gl"

#line 232 "assist.4gl"

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
int aclfgl_get_filename (int nargs){ /* Funtion Start */
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
#else
#line 287 "assist.4gl"
    printf ("FIXME: disabled stuff in assist.4gl");
#line 288 "assist.4gl"
    exit (4);
#line 289 "assist.4gl"
#endif
#line 290 "assist.4gl"
	/* Display that dialog */
#line 291 "assist.4gl"

#line 292 "assist.4gl"
	gtk_widget_show (file_selector);
#line 293 "assist.4gl"
	while (1) {
#line 294 "assist.4gl"
	    a4gl_usleep (100);
#line 295 "assist.4gl"
	 	gui_run_til_no_more ();
#line 296 "assist.4gl"
		if (strlen(selected_filename)!=0) {
#line 297 "assist.4gl"
			break;
#line 298 "assist.4gl"
		}
#line 299 "assist.4gl"
	}
#line 300 "assist.4gl"
	strcpy(fname,selected_filename);
#line 301 "assist.4gl"
}
#line 302 "assist.4gl"
/* End of code */
#line 303 "assist.4gl"

#line 303 "assist.4gl"
aclfgli_clr_err_flg();
#line 303 "assist.4gl"

#line 303 "assist.4gl"
push_variable(&fname,0x1000000);
#line 305 "assist.4gl"
A4GLSTK_popFunction();
#line 305 "assist.4gl"
return 1;
#line 305 "assist.4gl"
/* End command */
#line 305 "assist.4gl"
{debug("Line 257 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 305 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(257,_module_name);
#line 305 "assist.4gl"
/* ERROR */   if (status<0) chk_err(257,_module_name);
#line 305 "assist.4gl"
}
#line 305 "assist.4gl"
A4GLSTK_popFunction();
#line 305 "assist.4gl"
return 0;
#line 305 "assist.4gl"
}/* END OF FUNCTION */
#line 305 "assist.4gl"

#line 305 "assist.4gl"

#line 305 "assist.4gl"

#line 305 "assist.4gl"
 
#line 310 "assist.4gl"
 
#line 310 "assist.4gl"
 
#line 310 "assist.4gl"

#line 310 "assist.4gl"
int aclfgl_app_top_get (int nargs){ /* Funtion Start */
#line 310 "assist.4gl"

#line 310 "assist.4gl"
static char _functionName[] = "app_top_get";
#line 310 "assist.4gl"
long a;
#line 313 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 313 "assist.4gl"

#line 313 "assist.4gl"
}; /* end of binding */
#line 313 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 313 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 313 "assist.4gl"
pop_params(fbind,0);
#line 313 "assist.4gl"
CHK_UI
#line 314 "assist.4gl"
a= (long)win_screen;
#line 315 "assist.4gl"
/* End of code */
#line 316 "assist.4gl"

#line 316 "assist.4gl"
aclfgli_clr_err_flg();
#line 316 "assist.4gl"

#line 316 "assist.4gl"
push_variable(&a,0x2);
#line 316 "assist.4gl"
A4GLSTK_popFunction();
#line 316 "assist.4gl"
return 1;
#line 316 "assist.4gl"
/* End command */
#line 316 "assist.4gl"
{debug("Line 313 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 316 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(313,_module_name);
#line 316 "assist.4gl"
/* ERROR */   if (status<0) chk_err(313,_module_name);
#line 316 "assist.4gl"
}
#line 316 "assist.4gl"
A4GLSTK_popFunction();
#line 318 "assist.4gl"
return 0;
#line 318 "assist.4gl"
}/* END OF FUNCTION */
#line 318 "assist.4gl"

#line 318 "assist.4gl"

#line 318 "assist.4gl"

#line 318 "assist.4gl"
 
#line 323 "assist.4gl"
 
#line 323 "assist.4gl"
 
#line 323 "assist.4gl"

#line 323 "assist.4gl"
int aclfgl_app_hide (int nargs){ /* Funtion Start */
#line 323 "assist.4gl"

#line 323 "assist.4gl"
static char _functionName[] = "app_hide";
#line 323 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 325 "assist.4gl"

#line 325 "assist.4gl"
}; /* end of binding */
#line 325 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 325 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 325 "assist.4gl"
pop_params(fbind,0);
#line 325 "assist.4gl"
CHK_UI
#line 326 "assist.4gl"
gtk_widget_hide(win_screen);
#line 327 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 329 "assist.4gl"
return 0;
#line 329 "assist.4gl"
}/* END OF FUNCTION */
#line 329 "assist.4gl"

#line 329 "assist.4gl"

#line 329 "assist.4gl"

#line 329 "assist.4gl"
 
#line 333 "assist.4gl"
 
#line 333 "assist.4gl"
 
#line 333 "assist.4gl"

#line 333 "assist.4gl"
int aclfgl_app_show (int nargs){ /* Funtion Start */
#line 333 "assist.4gl"

#line 333 "assist.4gl"
static char _functionName[] = "app_show";
#line 333 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 335 "assist.4gl"

#line 335 "assist.4gl"
}; /* end of binding */
#line 335 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 335 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 335 "assist.4gl"
pop_params(fbind,0);
#line 335 "assist.4gl"
CHK_UI
#line 336 "assist.4gl"
gtk_widget_show(win_screen);
#line 337 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 339 "assist.4gl"
return 0;
#line 339 "assist.4gl"
}/* END OF FUNCTION */
#line 339 "assist.4gl"

#line 339 "assist.4gl"

#line 339 "assist.4gl"

#line 339 "assist.4gl"
 
#line 343 "assist.4gl"
 
#line 343 "assist.4gl"
 
#line 343 "assist.4gl"

#line 343 "assist.4gl"
int aclfgl_app_maximize (int nargs){ /* Funtion Start */
#line 343 "assist.4gl"

#line 343 "assist.4gl"
static char _functionName[] = "app_maximize";
#line 343 "assist.4gl"
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
// Needs coding
#line 347 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 349 "assist.4gl"
return 0;
#line 349 "assist.4gl"
}/* END OF FUNCTION */
#line 349 "assist.4gl"

#line 349 "assist.4gl"

#line 349 "assist.4gl"

#line 349 "assist.4gl"
 
#line 353 "assist.4gl"
 
#line 353 "assist.4gl"
 
#line 353 "assist.4gl"

#line 353 "assist.4gl"
int aclfgl_app_minimize (int nargs){ /* Funtion Start */
#line 353 "assist.4gl"

#line 353 "assist.4gl"
static char _functionName[] = "app_minimize";
#line 353 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 355 "assist.4gl"

#line 355 "assist.4gl"
}; /* end of binding */
#line 355 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 355 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 355 "assist.4gl"
pop_params(fbind,0);
#line 355 "assist.4gl"
CHK_UI
#line 356 "assist.4gl"
// Needs coding
#line 357 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 359 "assist.4gl"
return 0;
#line 359 "assist.4gl"
}/* END OF FUNCTION */
#line 359 "assist.4gl"

#line 359 "assist.4gl"

#line 359 "assist.4gl"

#line 359 "assist.4gl"
 
#line 363 "assist.4gl"
 
#line 363 "assist.4gl"
 
#line 363 "assist.4gl"

#line 363 "assist.4gl"
int aclfgl_app_restore (int nargs){ /* Funtion Start */
#line 363 "assist.4gl"

#line 363 "assist.4gl"
static char _functionName[] = "app_restore";
#line 363 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 365 "assist.4gl"

#line 365 "assist.4gl"
}; /* end of binding */
#line 365 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 365 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 365 "assist.4gl"
pop_params(fbind,0);
#line 365 "assist.4gl"
CHK_UI
#line 366 "assist.4gl"
// Needs coding
#line 367 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 369 "assist.4gl"
return 0;
#line 369 "assist.4gl"
}/* END OF FUNCTION */
#line 369 "assist.4gl"

#line 369 "assist.4gl"

#line 369 "assist.4gl"

#line 369 "assist.4gl"
 
#line 374 "assist.4gl"
 
#line 374 "assist.4gl"
 
#line 374 "assist.4gl"

#line 374 "assist.4gl"
int aclfgl_entry_max_chars_set (int nargs){ /* Funtion Start */
#line 374 "assist.4gl"

#line 374 "assist.4gl"
static char _functionName[] = "entry_max_chars_set";
#line 374 "assist.4gl"
long l;
#line 378 "assist.4gl"
long g;
#line 378 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 378 "assist.4gl"
{&g,2,0},
#line 378 "assist.4gl"
{&l,2,0}
#line 378 "assist.4gl"
}; /* end of binding */
#line 378 "assist.4gl"
char *_paramnames[]={"g","l"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 378 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 378 "assist.4gl"
pop_params(fbind,2);
#line 378 "assist.4gl"
CHK_UI
#line 379 "assist.4gl"
gtk_entry_set_max_length(GTK_ENTRY(g),l);
#line 380 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 382 "assist.4gl"
return 0;
#line 382 "assist.4gl"
}/* END OF FUNCTION */
#line 382 "assist.4gl"

#line 382 "assist.4gl"

#line 382 "assist.4gl"

#line 382 "assist.4gl"
 
#line 388 "assist.4gl"
 
#line 388 "assist.4gl"
 
#line 388 "assist.4gl"

#line 388 "assist.4gl"
int aclfgl_entry_selected_cut (int nargs){ /* Funtion Start */
#line 388 "assist.4gl"

#line 388 "assist.4gl"
static char _functionName[] = "entry_selected_cut";
#line 388 "assist.4gl"
long g;
#line 391 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 391 "assist.4gl"
{&g,2,0}
#line 391 "assist.4gl"
}; /* end of binding */
#line 391 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 391 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 391 "assist.4gl"
pop_params(fbind,1);
#line 391 "assist.4gl"
{
#line 392 "assist.4gl"
CHK_UI
#line 393 "assist.4gl"
	gtk_editable_cut_clipboard(GTK_EDITABLE(g));
#line 394 "assist.4gl"
}
#line 395 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 397 "assist.4gl"
return 0;
#line 397 "assist.4gl"
}/* END OF FUNCTION */
#line 397 "assist.4gl"

#line 397 "assist.4gl"

#line 397 "assist.4gl"

#line 397 "assist.4gl"
 
#line 401 "assist.4gl"
 
#line 401 "assist.4gl"
 
#line 401 "assist.4gl"

#line 401 "assist.4gl"
int aclfgl_entry_selected_copy (int nargs){ /* Funtion Start */
#line 401 "assist.4gl"

#line 401 "assist.4gl"
static char _functionName[] = "entry_selected_copy";
#line 401 "assist.4gl"
long g;
#line 404 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 404 "assist.4gl"
{&g,2,0}
#line 404 "assist.4gl"
}; /* end of binding */
#line 404 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 404 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 404 "assist.4gl"
pop_params(fbind,1);
#line 404 "assist.4gl"
{
#line 405 "assist.4gl"
CHK_UI
#line 406 "assist.4gl"
	gtk_editable_copy_clipboard(GTK_EDITABLE(g));
#line 407 "assist.4gl"
}
#line 408 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 410 "assist.4gl"
return 0;
#line 410 "assist.4gl"
}/* END OF FUNCTION */
#line 410 "assist.4gl"

#line 410 "assist.4gl"

#line 410 "assist.4gl"

#line 410 "assist.4gl"
 
#line 414 "assist.4gl"
 
#line 414 "assist.4gl"
 
#line 414 "assist.4gl"

#line 414 "assist.4gl"
int aclfgl_entry_selected_paste (int nargs){ /* Funtion Start */
#line 414 "assist.4gl"

#line 414 "assist.4gl"
static char _functionName[] = "entry_selected_paste";
#line 414 "assist.4gl"
long g;
#line 417 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 417 "assist.4gl"
{&g,2,0}
#line 417 "assist.4gl"
}; /* end of binding */
#line 417 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 417 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 417 "assist.4gl"
pop_params(fbind,1);
#line 417 "assist.4gl"
{
#line 418 "assist.4gl"
CHK_UI
#line 419 "assist.4gl"
	gtk_editable_paste_clipboard(GTK_EDITABLE(g));
#line 420 "assist.4gl"
}
#line 421 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 423 "assist.4gl"
return 0;
#line 423 "assist.4gl"
}/* END OF FUNCTION */
#line 423 "assist.4gl"

#line 423 "assist.4gl"

#line 423 "assist.4gl"

#line 423 "assist.4gl"
 
#line 428 "assist.4gl"
 
#line 428 "assist.4gl"
 
#line 428 "assist.4gl"

#line 428 "assist.4gl"
int aclfgl_entry_selection_set (int nargs){ /* Funtion Start */
#line 428 "assist.4gl"

#line 428 "assist.4gl"
static char _functionName[] = "entry_selection_set";
#line 428 "assist.4gl"
long e;
#line 432 "assist.4gl"
long s;
#line 432 "assist.4gl"
long g;
#line 432 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 432 "assist.4gl"
{&g,2,0},
#line 432 "assist.4gl"
{&s,2,0},
#line 432 "assist.4gl"
{&e,2,0}
#line 432 "assist.4gl"
}; /* end of binding */
#line 432 "assist.4gl"
char *_paramnames[]={"g","s","e"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 432 "assist.4gl"
if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
#line 432 "assist.4gl"
pop_params(fbind,3);
#line 432 "assist.4gl"
{
#line 433 "assist.4gl"
CHK_UI
#line 434 "assist.4gl"
	gtk_editable_select_region(GTK_EDITABLE(g),(gint)s,(gint)e);
#line 435 "assist.4gl"
}
#line 436 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 438 "assist.4gl"
return 0;
#line 438 "assist.4gl"
}/* END OF FUNCTION */
#line 438 "assist.4gl"

#line 438 "assist.4gl"

#line 438 "assist.4gl"

#line 438 "assist.4gl"
 
#line 442 "assist.4gl"
 
#line 442 "assist.4gl"
 
#line 442 "assist.4gl"

#line 442 "assist.4gl"
int aclfgl_entry_text_get (int nargs){ /* Funtion Start */
#line 442 "assist.4gl"

#line 442 "assist.4gl"
static char _functionName[] = "entry_text_get";
#line 442 "assist.4gl"
long g;
#line 445 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 445 "assist.4gl"
{&g,2,0}
#line 445 "assist.4gl"
}; /* end of binding */
#line 445 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 445 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 445 "assist.4gl"
pop_params(fbind,1);
#line 445 "assist.4gl"
{
#line 446 "assist.4gl"
	char *s;
#line 447 "assist.4gl"
CHK_UI
#line 448 "assist.4gl"
	debug("g=%d %x",g,g);
#line 449 "assist.4gl"
	s=gtk_editable_get_chars(GTK_EDITABLE(g),0,-1);
#line 450 "assist.4gl"
	push_char(s);
#line 451 "assist.4gl"
	g_free(s);
#line 452 "assist.4gl"
	return 1;
#line 453 "assist.4gl"
}
#line 454 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 456 "assist.4gl"
return 0;
#line 456 "assist.4gl"
}/* END OF FUNCTION */
#line 456 "assist.4gl"

#line 456 "assist.4gl"

#line 456 "assist.4gl"

#line 456 "assist.4gl"
 
#line 461 "assist.4gl"
 
#line 461 "assist.4gl"
 
#line 461 "assist.4gl"

#line 461 "assist.4gl"
int aclfgl_field_hide (int nargs){ /* Funtion Start */
#line 461 "assist.4gl"

#line 461 "assist.4gl"
static char _functionName[] = "field_hide";
#line 461 "assist.4gl"
long g;
#line 464 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 464 "assist.4gl"
{&g,2,0}
#line 464 "assist.4gl"
}; /* end of binding */
#line 464 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 464 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 464 "assist.4gl"
pop_params(fbind,1);
#line 464 "assist.4gl"
debug("Hiding field %p\n",g);fflush(stdout);
#line 465 "assist.4gl"
//CHK_UI
#line 466 "assist.4gl"
debug("g=%p\n",g);
#line 467 "assist.4gl"
gtk_widget_hide((GtkWidget *)g);
#line 468 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 470 "assist.4gl"
return 0;
#line 470 "assist.4gl"
}/* END OF FUNCTION */
#line 470 "assist.4gl"

#line 470 "assist.4gl"

#line 470 "assist.4gl"

#line 470 "assist.4gl"
 
#line 474 "assist.4gl"
 
#line 474 "assist.4gl"
 
#line 474 "assist.4gl"

#line 474 "assist.4gl"
int aclfgl_field_show (int nargs){ /* Funtion Start */
#line 474 "assist.4gl"

#line 474 "assist.4gl"
static char _functionName[] = "field_show";
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
CHK_UI
#line 478 "assist.4gl"
gtk_widget_show((GtkWidget *)g);
#line 479 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 481 "assist.4gl"
return 0;
#line 481 "assist.4gl"
}/* END OF FUNCTION */
#line 481 "assist.4gl"

#line 481 "assist.4gl"

#line 481 "assist.4gl"

#line 481 "assist.4gl"
 
#line 485 "assist.4gl"
 
#line 485 "assist.4gl"
 
#line 485 "assist.4gl"

#line 485 "assist.4gl"
int aclfgl_form_caption_get (int nargs){ /* Funtion Start */
#line 485 "assist.4gl"

#line 485 "assist.4gl"
static char _functionName[] = "form_caption_get";
#line 485 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 487 "assist.4gl"

#line 487 "assist.4gl"
}; /* end of binding */
#line 487 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 487 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 487 "assist.4gl"
pop_params(fbind,0);
#line 487 "assist.4gl"
CHK_UI
#line 488 "assist.4gl"
	//gtk_window_get_title(get_curr_win_gtk());
#line 489 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 491 "assist.4gl"
return 0;
#line 491 "assist.4gl"
}/* END OF FUNCTION */
#line 491 "assist.4gl"

#line 491 "assist.4gl"

#line 491 "assist.4gl"

#line 491 "assist.4gl"
 
#line 495 "assist.4gl"
 
#line 495 "assist.4gl"
 
#line 495 "assist.4gl"

#line 495 "assist.4gl"
int aclfgl_form_hide (int nargs){ /* Funtion Start */
#line 495 "assist.4gl"

#line 495 "assist.4gl"
static char _functionName[] = "form_hide";
#line 495 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 497 "assist.4gl"

#line 497 "assist.4gl"
}; /* end of binding */
#line 497 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 497 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 497 "assist.4gl"
pop_params(fbind,0);
#line 497 "assist.4gl"
CHK_UI
#line 498 "assist.4gl"
	gtk_widget_hide(GTK_WIDGET(get_curr_win_gtk()));
#line 499 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 501 "assist.4gl"
return 0;
#line 501 "assist.4gl"
}/* END OF FUNCTION */
#line 501 "assist.4gl"

#line 501 "assist.4gl"

#line 501 "assist.4gl"

#line 501 "assist.4gl"
 
#line 505 "assist.4gl"
 
#line 505 "assist.4gl"
 
#line 505 "assist.4gl"

#line 505 "assist.4gl"
int aclfgl_form_show (int nargs){ /* Funtion Start */
#line 505 "assist.4gl"

#line 505 "assist.4gl"
static char _functionName[] = "form_show";
#line 505 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 507 "assist.4gl"

#line 507 "assist.4gl"
}; /* end of binding */
#line 507 "assist.4gl"
char *_paramnames[]={};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 507 "assist.4gl"
if (nargs!=0) {status=-30174;pop_args(nargs);return 0;}
#line 507 "assist.4gl"
pop_params(fbind,0);
#line 507 "assist.4gl"
CHK_UI
#line 508 "assist.4gl"
	gtk_widget_show(GTK_WIDGET(get_curr_win_gtk()));
#line 509 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 511 "assist.4gl"
return 0;
#line 511 "assist.4gl"
}/* END OF FUNCTION */
#line 511 "assist.4gl"

#line 511 "assist.4gl"

#line 511 "assist.4gl"

#line 511 "assist.4gl"
 
#line 515 "assist.4gl"
 
#line 515 "assist.4gl"
 
#line 515 "assist.4gl"

#line 515 "assist.4gl"
int aclfgl_form_is_open (int nargs){ /* Funtion Start */
#line 515 "assist.4gl"

#line 515 "assist.4gl"
static char _functionName[] = "form_is_open";
#line 515 "assist.4gl"
long s;
#line 518 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 518 "assist.4gl"
{&s,2,0}
#line 518 "assist.4gl"
}; /* end of binding */
#line 518 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 518 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 518 "assist.4gl"
pop_params(fbind,1);
#line 518 "assist.4gl"
CHK_UI
#line 519 "assist.4gl"
	//void *find_param (char *name);
#line 520 "assist.4gl"
	//if (find_param(s,WINCODE)) push_int(1);
#line 521 "assist.4gl"
	if ((int)find_param((char *)WINCODE)) push_int(1);
#line 522 "assist.4gl"
	else push_int(0);
#line 523 "assist.4gl"
	return 1;
#line 524 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 526 "assist.4gl"
return 0;
#line 526 "assist.4gl"
}/* END OF FUNCTION */
#line 526 "assist.4gl"

#line 526 "assist.4gl"

#line 526 "assist.4gl"

#line 526 "assist.4gl"
static int tolist(GtkWidget *a) {
#line 533 "assist.4gl"
	a=gtk_object_get_data(GTK_OBJECT(a),"Child");
#line 534 "assist.4gl"
	return (int)a;
#line 535 "assist.4gl"
}
#line 536 "assist.4gl"
/* End of code */ 
#line 542 "assist.4gl"
 
#line 542 "assist.4gl"
 
#line 542 "assist.4gl"

#line 542 "assist.4gl"
int aclfgl_list_count_get (int nargs){ /* Funtion Start */
#line 542 "assist.4gl"

#line 542 "assist.4gl"
static char _functionName[] = "list_count_get";
#line 542 "assist.4gl"
long g;
#line 545 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 545 "assist.4gl"
{&g,2,0}
#line 545 "assist.4gl"
}; /* end of binding */
#line 545 "assist.4gl"
char *_paramnames[]={"g"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 545 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 545 "assist.4gl"
pop_params(fbind,1);
#line 545 "assist.4gl"
CHK_UI
#line 546 "assist.4gl"
	g=tolist(GTK_WIDGET(g));
#line 547 "assist.4gl"
	push_int(GTK_CLIST(g)->rows);
#line 548 "assist.4gl"
	return 1;
#line 549 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 551 "assist.4gl"
return 0;
#line 551 "assist.4gl"
}/* END OF FUNCTION */
#line 551 "assist.4gl"

#line 551 "assist.4gl"

#line 551 "assist.4gl"

#line 551 "assist.4gl"
 
#line 555 "assist.4gl"
 
#line 555 "assist.4gl"
 
#line 555 "assist.4gl"

#line 555 "assist.4gl"
int aclfgl_list_current_get (int nargs){ /* Funtion Start */
#line 555 "assist.4gl"

#line 555 "assist.4gl"
static char _functionName[] = "list_current_get";
#line 555 "assist.4gl"
long s;
#line 558 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 558 "assist.4gl"
{&s,2,0}
#line 558 "assist.4gl"
}; /* end of binding */
#line 558 "assist.4gl"
char *_paramnames[]={"s"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 558 "assist.4gl"
if (nargs!=1) {status=-30174;pop_args(nargs);return 0;}
#line 558 "assist.4gl"
pop_params(fbind,1);
#line 558 "assist.4gl"
CHK_UI
#line 559 "assist.4gl"
{
#line 560 "assist.4gl"
GList* sel ;
#line 561 "assist.4gl"
s=tolist(GTK_WIDGET(s));
#line 562 "assist.4gl"
sel = GTK_CLIST(s)->selection;
#line 563 "assist.4gl"
push_int(sel ? (int)(sel->data) :  -1);
#line 564 "assist.4gl"
return 1;
#line 565 "assist.4gl"
}
#line 566 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 568 "assist.4gl"
return 0;
#line 568 "assist.4gl"
}/* END OF FUNCTION */
#line 568 "assist.4gl"

#line 568 "assist.4gl"

#line 568 "assist.4gl"

#line 568 "assist.4gl"
 
#line 572 "assist.4gl"
 
#line 572 "assist.4gl"
 
#line 572 "assist.4gl"

#line 572 "assist.4gl"
int aclfgl_list_delete (int nargs){ /* Funtion Start */
#line 572 "assist.4gl"

#line 572 "assist.4gl"
static char _functionName[] = "list_delete";
#line 572 "assist.4gl"
long n;
#line 575 "assist.4gl"
long s;
#line 575 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 575 "assist.4gl"
{&s,2,0},
#line 575 "assist.4gl"
{&n,2,0}
#line 575 "assist.4gl"
}; /* end of binding */
#line 575 "assist.4gl"
char *_paramnames[]={"s","n"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 575 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 575 "assist.4gl"
pop_params(fbind,2);
#line 575 "assist.4gl"
CHK_UI
#line 576 "assist.4gl"
	s=tolist(GTK_WIDGET(s));
#line 577 "assist.4gl"
gtk_clist_remove(GTK_CLIST(s),n);
#line 578 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 580 "assist.4gl"
return 0;
#line 580 "assist.4gl"
}/* END OF FUNCTION */
#line 580 "assist.4gl"

#line 580 "assist.4gl"

#line 580 "assist.4gl"

#line 580 "assist.4gl"
 
#line 584 "assist.4gl"
 
#line 584 "assist.4gl"
 
#line 584 "assist.4gl"

#line 584 "assist.4gl"
int aclfgl_list_insert (int nargs){ /* Funtion Start */
#line 584 "assist.4gl"

#line 584 "assist.4gl"
static char _functionName[] = "list_insert";
#line 584 "assist.4gl"
long n;
#line 588 "assist.4gl"
long s;
#line 588 "assist.4gl"
char str [512+1];
#line 588 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 588 "assist.4gl"
{&s,2,0},
#line 588 "assist.4gl"
{&n,2,0},
#line 588 "assist.4gl"
{&str,0,512}
#line 588 "assist.4gl"
}; /* end of binding */
#line 588 "assist.4gl"
char *_paramnames[]={"s","n","str"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 588 "assist.4gl"
if (nargs!=3) {status=-30174;pop_args(nargs);return 0;}
#line 588 "assist.4gl"
pop_params(fbind,3);
#line 588 "assist.4gl"
CHK_UI
#line 589 "assist.4gl"
	s=tolist(GTK_WIDGET(s));
#line 590 "assist.4gl"
trim(str);
#line 591 "assist.4gl"
gtk_clist_insert((GtkCList *)s,(gint)n,(char **)&str);
#line 592 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 594 "assist.4gl"
return 0;
#line 594 "assist.4gl"
}/* END OF FUNCTION */
#line 594 "assist.4gl"

#line 594 "assist.4gl"

#line 594 "assist.4gl"

#line 594 "assist.4gl"
 
#line 598 "assist.4gl"
 
#line 598 "assist.4gl"
 
#line 598 "assist.4gl"

#line 598 "assist.4gl"
int aclfgl_list_selected (int nargs){ /* Funtion Start */
#line 598 "assist.4gl"

#line 598 "assist.4gl"
static char _functionName[] = "list_selected";
#line 598 "assist.4gl"
long n;
#line 601 "assist.4gl"
long s;
#line 601 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 601 "assist.4gl"
{&s,2,0},
#line 601 "assist.4gl"
{&n,2,0}
#line 601 "assist.4gl"
}; /* end of binding */
#line 601 "assist.4gl"
char *_paramnames[]={"s","n"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 601 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 601 "assist.4gl"
pop_params(fbind,2);
#line 601 "assist.4gl"
CHK_UI
#line 602 "assist.4gl"
{
#line 603 "assist.4gl"
GList* sel ;
#line 604 "assist.4gl"
s=tolist(GTK_WIDGET(s));
#line 605 "assist.4gl"
sel = GTK_CLIST(s)->selection;
#line 606 "assist.4gl"
}
#line 607 "assist.4gl"
//
#line 608 "assist.4gl"
/* End of code */A4GLSTK_popFunction();
#line 610 "assist.4gl"
return 0;
#line 610 "assist.4gl"
}/* END OF FUNCTION */
#line 610 "assist.4gl"

#line 610 "assist.4gl"

#line 610 "assist.4gl"

#line 610 "assist.4gl"
 
#line 612 "assist.4gl"
 
#line 612 "assist.4gl"
 
#line 612 "assist.4gl"

#line 612 "assist.4gl"
int aclfgl_splat_with_image (int nargs){ /* Funtion Start */
#line 612 "assist.4gl"

#line 612 "assist.4gl"
static char _functionName[] = "splat_with_image";
#line 612 "assist.4gl"
long w;
#line 616 "assist.4gl"
char img_file [256+1];
#line 616 "assist.4gl"
char lv_config [512+1];
#line 616 "assist.4gl"
struct BINDING fbind[]={ /* print_param */
#line 616 "assist.4gl"
{&img_file,0,256},
#line 616 "assist.4gl"
{&w,2,0}
#line 616 "assist.4gl"
}; /* end of binding */
#line 616 "assist.4gl"
char *_paramnames[]={"img_file","w"};A4GLSTK_pushFunction(_functionName,_paramnames,nargs);
#line 616 "assist.4gl"
if (nargs!=2) {status=-30174;pop_args(nargs);return 0;}
#line 616 "assist.4gl"
pop_params(fbind,2);
#line 616 "assist.4gl"

#line 616 "assist.4gl"

#line 616 "assist.4gl"
aclfgli_clr_err_flg();
#line 616 "assist.4gl"

#line 616 "assist.4gl"
push_long(100);
#line 617 "assist.4gl"

#line 617 "assist.4gl"
pop_var2(&w,2,0);
#line 617 "assist.4gl"

#line 617 "assist.4gl"
/* End command */
#line 617 "assist.4gl"
{debug("Line 616 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 617 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(616,_module_name);
#line 617 "assist.4gl"
/* ERROR */   if (status<0) chk_err(616,_module_name);
#line 617 "assist.4gl"
}
#line 617 "assist.4gl"

#line 617 "assist.4gl"

#line 617 "assist.4gl"
aclfgli_clr_err_flg();
#line 617 "assist.4gl"

#line 617 "assist.4gl"
push_char("filename='");
#line 617 "assist.4gl"

#line 617 "assist.4gl"
push_variable(&img_file,0x1000000);
#line 617 "assist.4gl"
pushop(OP_CLIP);
#line 617 "assist.4gl"
pushop(OP_CONCAT);
#line 617 "assist.4gl"
push_char("';width='");
#line 617 "assist.4gl"

#line 617 "assist.4gl"
pushop(OP_CONCAT);
#line 617 "assist.4gl"
push_variable(&w,0x2);
#line 617 "assist.4gl"
push_char("<<<<");
#line 617 "assist.4gl"

#line 617 "assist.4gl"
pushop(OP_USING);
#line 617 "assist.4gl"
pushop(OP_CONCAT);
#line 617 "assist.4gl"
push_char("'");
#line 619 "assist.4gl"

#line 619 "assist.4gl"
pushop(OP_CONCAT);
#line 619 "assist.4gl"
pop_var2(&lv_config,0,512);
#line 619 "assist.4gl"

#line 619 "assist.4gl"
/* End command */
#line 619 "assist.4gl"
{debug("Line 617 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 619 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(617,_module_name);
#line 619 "assist.4gl"
/* ERROR */   if (status<0) chk_err(617,_module_name);
#line 619 "assist.4gl"
}
#line 619 "assist.4gl"

#line 619 "assist.4gl"

#line 619 "assist.4gl"
aclfgli_clr_err_flg();
#line 619 "assist.4gl"

#line 619 "assist.4gl"
CHK_UI
#line 620 "assist.4gl"
{
#line 621 "assist.4gl"
GtkWidget *widget;
#line 622 "assist.4gl"
GtkWidget *cw;
#line 623 "assist.4gl"
trim(lv_config);
#line 624 "assist.4gl"
widget=make_widget("pixmap",lv_config,w);
#line 625 "assist.4gl"
gtk_widget_show(widget);
#line 626 "assist.4gl"
cw=GTK_WIDGET(get_curr_win_gtk());
#line 627 "assist.4gl"
gtk_fixed_put (GTK_FIXED (cw), widget, 0, 20);
#line 628 "assist.4gl"
gtk_widget_show(cw);
#line 629 "assist.4gl"
}
#line 630 "assist.4gl"
/* End of code */
#line 631 "assist.4gl"
/* End command */
#line 631 "assist.4gl"
{debug("Line 619 assist.4gl:");}if (aclfgli_get_err_flg()&&(sqlca.sqlcode !=0 || status !=0 || 0)) {
#line 632 "assist.4gl"
/* SQLERROR */   if (sqlca.sqlcode<0&&status==sqlca.sqlcode) chk_err(619,_module_name);
#line 632 "assist.4gl"
/* ERROR */   if (status<0) chk_err(619,_module_name);
#line 632 "assist.4gl"
}
#line 632 "assist.4gl"
A4GLSTK_popFunction();
#line 632 "assist.4gl"
return 0;
#line 632 "assist.4gl"
}/* END OF FUNCTION */
#line 632 "assist.4gl"

#line 632 "assist.4gl"

#line 632 "assist.4gl"

#line 632 "assist.4gl"
