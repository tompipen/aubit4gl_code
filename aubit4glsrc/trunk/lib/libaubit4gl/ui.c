/**
 * @file
 * GUI interface implementations
 *
 * The user interface functions pass allways from here.
 *
 * There is work to be done in this module in order to change it to work
 * like SQL library with several interfaces:
 *   - Curses
 *   - GTK
 *   - Thin client using TCP
 *
 * @todo Does this file belong in lib/ directory, or...?
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/************************************************************************
*
* (c) 1997-1998 Aubit Computing Ltd.
*
* $Id: ui.c,v 1.1 2002-04-17 01:38:52 afalout Exp $
*
************************************************************************/

#include "../libincl/dbform.h"
#include "../libincl/dbform.h"
#include "../libincl/debug.h"
#include "../libincl/aubitcolours.h"
#include "../runtime_tui.h"


extern int ui_mode;
#define LINE_MODE 0
#define SCREEN_MODE 1
int currscrmode = SCREEN_MODE;


set_scrmode(char a) {
	if (a=='L') currscrmode=LINE_MODE;
	else currscrmode=SCREEN_MODE;
}


isscrmode ()
{
  return (currscrmode == SCREEN_MODE);
}

islinemode ()
{
  return (currscrmode == LINE_MODE);
}

#define UI_MODE_TEXT 0
#define UI_MODE_GTK  1


void *libptr;
static int (*func)();
void *find_func(void *p,char *s);
void *find_func_allow_missing(void *p,char *s);

int A4GLUI_initlib (void)
{

        libptr=(void *)dl_openlibrary("UI",acl_getenv("AUBITGUI"));

        debug("libptr=%p\n",libptr);

        if (libptr==0) {
                exitwith("Unable to open UI library...");
                return 0;
        }

        func=find_func_allow_missing(libptr,"A4GLUI_initlib");

        if (func)
                return func();
        else
                return 1;
}



void *cr_window (char *s, int iswindow, int form_line, int error_line,
	   int prompt_line, int menu_line, int border, int comment_line,
	   int message_line, int attrib)
{

  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"cr_window");

  return (void *)func(
				s, iswindow, form_line, error_line, prompt_line,
			  menu_line, border, comment_line, message_line,
			  attrib
		);
}


/***************************************************************************
*/
int
cr_window_form (char *name,
		int iswindow, int form_line, int error_line, int
prompt_line,
		int menu_line, int border, int comment_line, int
message_line,
		int attrib)
{
char newname[1024];
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"cr_window_form");
  strcpy(newname,name);
  trim(newname);
    return func (newname,
			       iswindow,
			       form_line,
			       error_line,
			       prompt_line,
			       menu_line,
			       border, comment_line, message_line, attrib);

}




/***************************************************************************
*/
int
disp_fields (int n, int attr, ...)
{
  va_list ap;
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"disp_fields");
  va_start (ap, attr);

  return func (n, attr, &ap);
}

int
disp_form_fields (int n, int attr, char *formname,...)
{
  va_list ap;
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"disp_form_fields");
  va_start (ap, formname);
  return func (n, attr, formname,&ap);
}


/***************************************************************************
*/
int
open_form (char *name)
{
int a;
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"open_form");
  return func (name);
}


/**
 * Implementation of the OPEN FORM 4gl statement.
 *
 * @param name The form name.
 * @return
 */
int
close_form (char *name)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"close_form");
  return func (name);
}


/***************************************************************************
*/
int
disp_form (char *name, int attr)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"disp_form");
  return func (name, attr);
}

/**
 * Implementation of 4gl CURRENT WINDOW IS statement.
 *
 * @param win_name A string with the name of the window.
 * @return
 */
int
current_window (char *win_name)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"current_window");
  return func (win_name);

}


/**
 * This function aparentrly is not used
 * @todo Understand if the function is not used and if not remove it
 */
ACL_Menu *xxnew_menu (char *title, int x, int y, int mn_type, 
		    int help_no, int nopts, ...)
{
  va_list ap;
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"new_menu");
  va_start (ap, nopts);
  return (ACL_Menu *)func (title, x, y, mn_type, help_no, nopts, &ap);

}

/**
 * Create a new menu.
 *
 * Called by the generated C code at run-time.
 * The items are created after with other function call.
 *
 * @param title The menu title.
 * @param x The column where to be created.
 * @param y The line where to be created.
 * @param mn_type The menu type:
 *   - Boxed
 *   - ???
 * @param help_no The help number of the menu.
 * @return A pointer to the structure that identifies the menu.
 */
ACL_Menu *new_menu_create(char *title, int x, int y, int mn_type, int help_no)  {
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"new_menu_create");
  return (ACL_Menu *)func (title, x, y, mn_type, help_no);
}


/**
 * Add a new menu option/item.
 *
 * Executed at run-time by the generated program.
 *
 * @param menu A pointer to the menu structure.
 * @param txt The text of the option (immediatly after command)
 * @param keys The keys if so
 * @param desc The text long description.
 * @param helpno The help number.
 * @param attr The attributes
 */
void add_menu_option(ACL_Menu *menu,char *txt,char *keys,char *desc,
	int helpno,int attr)  
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"add_menu_option");
  func(menu,txt,keys,desc,helpno,attr);
}

/**
 * Terminate the menu creation.
 *
 * Executed by the generated code at run-time after the menu created and all
 * the items inserted.
 *
 * @param menu The menu structure.
 */
void finish_create_menu(ACL_Menu *menu)  
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"finish_create_menu");
  func(menu);

}

/**
 * Called by the 4gl compiled program to display the menu.
 * The menu should be allready initialized when this function called.
 *
 * @todo Clean the return values or return void. Since the called functions
 * does not return anything. The cast is just for clean the warning but this
 * should be fixed
 *
 * @param A pointer to the menu information.
 * @return The return value is not used 
 */
char *disp_h_menu (ACL_Menu *menu)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"disp_h_menu");
    return (char *)func (menu);
}

/**
 * Executes the menu loop until the user executes some option.
 *
 * Executed in run-time by the generated C code.
 *
 * @param menu A pointer to the menu structure information.
 */
int menu_loop (ACL_Menu *menu)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"menu_loop");
  return func(menu);
}


int
next_option (ACL_Menu * menu,char *nextopt)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"next_option");

return func ( menu, nextopt) ;
}


/**
 * Not used.
 */
int
free_menu (ACL_Menu * menu)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"free_menu");
  return func (menu);
}

int req_field(struct s_screenio *s, char *fieldname,int fno) {
  	if (libptr==0) A4GLUI_initlib();
  	func=find_func(libptr,"req_field");
  	return func (s, fieldname,fno,0,0);
	
}
/**
 * Not used but should be.
 */
int
menu_hide (ACL_Menu * menu, ...)
{
  va_list ap;
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"menu_hide");
  va_start (ap, menu);
  return func (menu, &ap);
}

/**
 * Show an item of the menu.
 *
 * Called by the generated C code at run-time.
 * 
 * @param The menu name to be showed.
 * @param ... The options to be showed.
 */
int menu_show (ACL_Menu * menu, ...)
{
  va_list ap;
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"menu_show");
  va_start (ap, menu);
  return func (menu, &ap);
}

/**
 * Show a menu in a window.
 *
 * Called by the generated C code.
 *
 * @param menuid The menu name.
 * @param handler The menu handler name.
 * @return
 */
int
show_menu (char *menuid, void *handler)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"show_menu");
  return func (menuid, handler);
}


/***************************************************************************
*/
int
aclfgli_pr_message (int attr,int wait)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"aclfgli_pr_message");
  return func (attr,wait);
}

/***************************************************************************
*/
int
display_error (int attr,int wait)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"display_error");
  A4GLSQL_set_status(0,0);  
  return func(attr,wait);
}

/**
 * This function is returng a GtkWidget if using get_curr_form_gtk.
 * @todo Understand why this is hapening. It seems that is obsolete whith
 * the new dynamic library way for UI(s).
 */
void *get_curr_form ()
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"get_curr_form");
  return (struct s_form_dets *)func ();
}


/**
 * Implementation of part of the INPUT 4gl statement.
 *
 * Generate a list of fields acording the parameters.
 *
 * @param field_list A pointer to the place where to put the field list.
 * @param formdets Pointer to the structure filled with the form details.
 * @param ...
 * @return
 */
int
gen_field_chars (void *** field_list, struct s_form_dets *formdets, ...)
{
  va_list ap;
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"gen_field_chars");
  va_start (ap, formdets);

  return func (field_list, formdets, &ap);

}

/**
 * Implementation of the form input loop.
 *
 * Called by the generated C code.
 *
 * @param s A pointer to the screen IO structure.
 */
int
form_loop (struct s_screenio *s)
{
int a;
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"form_loop");
  a= func (s);
  debug("Form_loop returns %d",a);
  return a;
}


/**
 *
 * @param s A pointer to the screen information.
 */
int push_constr (struct s_screenio *s)    
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"push_constr");
   return func (s);

}


/* Input stuff */


/**
 * Part of the C implementation of the input.
 *
 * Called by the generated C code.
 *
 * @param sio a pointer to the screen IO structure.
 */
int
set_fields (struct s_screenio *sio)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"set_fields");
  return func (sio);
}

/**
 * DISPLAY AT 4gl statement implementation.
 *
 * @param n The row number where the display is made.
 * @param a The column number.
 */
int
display_at (int n, int a)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"display_at");
  return func (n, a);
}


/**
 * Move the 4gl window.
 *
 * Implement the MOVE WINDOW 4gl statement.
 *
 * @param s The window name.
 * @param to_by Flag that identifies the scope of the move:
 *   - 0 : The move is abosulte in the screen.
 *   - 1 : The move is relative to the current position.
 */
int
movewin (char *winname, int absol)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"movewin");
  return func (winname, absol);
}

// Display..

/**
 * Implements the HIDE WINDOW 4gl instruction.
 *
 * @param winname The name of the window to be hidded.
 * @return ???
 */
int
hide_window (char *winname)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"hide_window");

    return func (winname);
}

/**
 * Show a window.
 *
 * @param winname The name of the window to be showed.
 */
int
show_window (char *winname)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"show_window");
  return func (winname);
}

/**
 * Check if the user was in a screen field.
 *
 * @todo : Fix the call of the generrated C code that call this function
 * with only one parameter.
 *
 * @param s The field name.
 * @param a
 */
long fgl_infield (char *s, int a)  
{

  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"fgl_infield");
  return func (s,a);
}

/**
 * Clear the content of a window.
 *
 * @param winname The name of the window to cleaned.
 */
int
clr_window (char *winname)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"clr_window");
    return func (winname);
}

/**
 * 4gl SLEEP statement implementation.
 */
int sleep_i ()
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"sleep_i");
  return func ();
}

/**
 * Implements the CLOSE WINDOW 4gl statement.
 *
 * Called by the generated C code.
 *
 * @param win_name The window name.
 */
int remove_window (char *win_name)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"remove_window");
  return func (win_name);
}

disp_arr(struct s_disp_arr *disp, void *ptr, char *srecname,int attrib,...)
{
va_list ap;
va_start(ap,attrib);

  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"disp_arr");
  return func (disp,ptr,srecname,attrib,&ap);
}
/**
 * C Implementation of the PROMPT 4gl statement.
 *
 * Called by the generated C code for a 4gl souced with PROMPT statement.
 *
 * @param prompt A pointer to the prompt structure where the information about
 * it is stored.
 */
prompt_loop (struct s_prompt *prompt)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"prompt_loop");
  return func (prompt);
}

/**
 * Implementation of the first part of C version PROMPT 4gl statement.
 *
 * @param prompt A pointer to the prompt identifier structure where this 
 *   function initialize the values.
 * @param ap The attributes for the message.
 * @param c Prompt for char (cbreak()) flag.
 * @param h The help number.
 * @param af The attributes.
 */
int
start_prompt (struct s_prompt *prompt, int ap, int c, int h, int af)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"start_prompt");
    return func (prompt, ap, c, h, af);
}


int endis_fields (int en_dis, ...) 
{
  va_list ap;
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"endis_fields");
  va_start (ap, en_dis);

  return func(en_dis,&ap);
}

/**
 * Clear the content of the fields in the current form.
 *
 * @param to_defaults Indicate if the values should be initialized just as in
 * defaults.
 */
void clr_form (int to_defaults) 
{

  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"clr_form");
  func(to_defaults);
  return;

}



#ifdef NO_LONGER_REQUIRED
gui_init(int c,char *argv[]) {
#ifdef HAS_GTK
START_HAS_GTK
	gui_init_gtk(c,argv);
	return;
END_HAS_GTK
#else
	printf("Not compiled for GUI environment\n");
	exitwith("Not compiled for a GUI environment");
	exit(0);
#endif
}
#endif

void A4GLUI_ui_init (int argc,char *argv[])
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"A4GLUI_ui_init");
  if (func) func(argc,argv);
}


int zrefresh ()
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"zrefresh");
    return func();
}

int gotolinemode ()
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"gotolinemode");
  return func();
}

int show_help (int a)
{
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"show_help");
  return func(a);
}


read_fields (struct s_form_dets * formdets) {
  if (libptr==0) A4GLUI_initlib();
  func=find_func_allow_missing(libptr,"read_fields");
  return func(formdets);
}

read_metrics (struct s_form_dets * formdets) {
  if (libptr==0) A4GLUI_initlib();
  func=find_func_allow_missing(libptr,"read_metrics");
  return func(formdets);
}

aclfgl_set_page(int a) {
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"aclfgl_set_page");
  return func(a);
}

aclfgl_get_page() {
  if (libptr==0) A4GLUI_initlib();
  func=find_func(libptr,"aclfgl_get_page");
  return func();
}


set_infield_from_stack() {
  if (libptr==0) A4GLUI_initlib();
  func=find_func_allow_missing(libptr,"set_infield_from_stack");
  return func();
}

fgl_fieldnametoid(char *f,char *s,int n) {
  if (libptr==0) A4GLUI_initlib();
  func=find_func_allow_missing(libptr,"fgl_fieldnametoid");
  return func(f,s,n);
}





/**
*  Decode a string attribute into an Aubit internal attribute
*
*  @param s The string to decode - should contain a single colour or attribute
*
**/
int get_attr_from_string(char *s) {
	if (strcasecmp(s,"BLACK")==0)     return AUBIT_COLOR_BLACK;
	if (strcasecmp(s,"RED")==0)       return AUBIT_COLOR_RED;
	if (strcasecmp(s,"GREEN")==0)     return AUBIT_COLOR_GREEN;
	if (strcasecmp(s,"YELLOW")==0)    return AUBIT_COLOR_YELLOW;
	if (strcasecmp(s,"BLUE")==0)      return AUBIT_COLOR_BLUE;
	if (strcasecmp(s,"MAGENTA")==0)   return AUBIT_COLOR_MAGENTA;
	if (strcasecmp(s,"CYAN")==0)      return AUBIT_COLOR_CYAN;
	if (strcasecmp(s,"WHITE")==0)     return AUBIT_COLOR_WHITE;

	if (strcasecmp(s,"NORMAL")==0)    return AUBIT_ATTR_NORMAL;
	if (strcasecmp(s,"REVERSE")==0)   return AUBIT_ATTR_REVERSE;
	if (strcasecmp(s,"UNDERLINE")==0) return AUBIT_ATTR_UNDERLINE;
	if (strcasecmp(s,"BOLD")==0)      return AUBIT_ATTR_BOLD;
	if (strcasecmp(s,"BLINK")==0)     return AUBIT_ATTR_BLINK;
	if (strcasecmp(s,"DIM")==0)       return AUBIT_ATTR_DIM;
	printf("Unknown attribute : %s\n",s);
	return -1;
}


/**
* Get a string representation of an attribute
*
* @param attr  Attribute to decode
* @param col_str Pointer to character string to store the colour 
* @param col_str Pointer to character string to store the attributes
*/
int get_strings_from_attr(int attr,char *col_str,char *attr_str) {
	int col_int;
	int attr_int;

	strcpy(col_str,"WHITE");
	strcpy(attr_str,"");

	col_int=(attr&0xf00);
debug("col_int=%x\n",col_int);
// Work out the colours first
	switch(col_int) {
		case AUBIT_COLOR_BLACK:   	strcpy(col_str,"BLACK");break;
		case AUBIT_COLOR_RED:     	strcpy(col_str,"RED");break;
		case AUBIT_COLOR_GREEN:   	strcpy(col_str,"GREEN");break;
		case AUBIT_COLOR_YELLOW:  	strcpy(col_str,"YELLOW");break;
		case AUBIT_COLOR_BLUE:    	strcpy(col_str,"BLUE");break;
		case AUBIT_COLOR_MAGENTA: 	strcpy(col_str,"MAGENTA");break;
		case AUBIT_COLOR_CYAN:    	strcpy(col_str,"CYAN");break;
		case AUBIT_COLOR_WHITE:   	strcpy(col_str,"WHITE");break;
	}

// Now for the attributes
	if (attr&AUBIT_ATTR_NORMAL) 		strcat(attr_str,"NORMAL ");
	if (attr&AUBIT_ATTR_REVERSE) 		strcat(attr_str,"REVERSE ");
	if (attr&AUBIT_ATTR_UNDERLINE) 		strcat(attr_str,"UNDERLINE ");
	if (attr&AUBIT_ATTR_BOLD) 		strcat(attr_str,"BOLD ");
	if (attr&AUBIT_ATTR_BLINK) 		strcat(attr_str,"BLINK ");
	if (attr&AUBIT_ATTR_DIM) 		strcat(attr_str,"DIM ");
	debug("get_strings returning %s %s",col_str,attr_str);
}
