/* <SCREEN_INTERACTION> */

/**
 * Bison rules to screen interaction 
 */

include(ScreenAttribute.y)
include(Construct.y)
include(Display.y)
include(Error.y)
include(Input.y)
include(Menu.y)

/**
 * The OPEN WINDOW statement that opens a new window somewhere in the
 * screen.
 * 4gl code examples:
 *    OPEN WINDOW wName AT 2, 10 WITH 2 ROWS, 5 COLUMNS
 *    OPEN WINDOW wName AT 2, 10 WITH FORM "XX"
 */
open_window_cmd 
  : OPEN_WINDOW open_win_name AT coords WITH window_type win_attributes  
  ;

/**
 * Optional AT location in screen where to open a status box.
 * This is an extension to Informix 4gl.
 * 4gl code examples:
 *   AT (2,4) 
 *   AT (x,y) 
 *   AT (x+2,y/5) 
 */
op_at_statusbox 
  : 
	| AT OPEN_BRACKET fgl_expr COMMA fgl_expr CLOSE_BRACKET op_size_statusbox
  ;

/**
 * Optional size of a statusbox.
 * This is an extension to Informix 4gl.
 * 4gl code example:
 *   SIZE (10,10)
 *   SIZE (width,heigth)
 */
op_size_statusbox 
  : 
	| SIZE OPEN_BRACKET fgl_expr COMMA fgl_expr CLOSE_BRACKET
  ;

/**
 * OPEN STATUSBOX statement.
 * This is an extension to Informix 4gl.
 * 4gl code example:
 *   OPEN STATUSBOX AT (2,3) SIZE (10,10)
 *   OPEN STATUSBOX AT (x+1,y/2) SIZE (width,heigth)
 */
open_statusbox_cmd 
  : OPEN_STATUSBOX identifier op_at_statusbox
  ;

/**
 * A possible name of a GUI form handler.
 * @todo : Define what is a form handler.
 */
formhandler_name
  : identifier 
  ;

/**
 * OPEN FORM statement to open a form in a window.
 * 4gl code examples:
 *    OPEN FORM xptoForm 
 */
open_form_cmd 
  : OPEN_FORM open_form_name  abstract_open_form_rest
      { $$ = AST_STATE->OpenFormCreate($2,$3); }
  ;

/**
 * Abstract place from where the form is opened.
 * The second part of the OPEN FORM statement where is choosed if it is 
 * standard or GUI extension.
 * The name of this rule in Mike parser is "open_form_rest"
 * 4gl code examples:
 *
 */
abstract_open_form_rest
  : open_form_gui
	| FROM fgl_expr 
      { $$ = AST_STATE->OpenFormFromCreate("Form name - To change"); }
			// @tbd
      //{ $$ = AST_STATE->OpenFormFromCreate($2); }
  ;

/**
 * The GUI open form extension to Informix 4gl.
 * 4gl code examples:
 *   AT ABSOLUTE (10,15) LIKE xpto.a DISABLE ALL USING xxx
 *   AT (10,15)
 */
open_form_gui
  :  op_at_gui op_like_gui op_disable KW_USING formhandler_name
  ;

/**
 * Optional AT substatement of a GUI form.
 * This is an extension to standard Informix 4gl.
 * 4gl code example:
 *   AT ABSOLUTE (10,15)
 *   AT (10,15)
 */
op_at_gui
  :
	| AT op_absolute OPEN_BRACKET fgl_expr COMMA fgl_expr CLOSE_BRACKET 
  ;

/**
 * Optional like to be used in a GUI open form statement.
 * 4gl code example:
 *   LIKE xpto.a
 */
op_like_gui
  : 
	| LIKE ident_or_var
  ;

/**
 * Optional absolute keyword to be used in GUI open form statement.
 */
op_absolute
  : 
	| ABSOLUTE 
  ;

/* <PROMPT_STATEMENT> */

/**
 * The 4gl interactive user prompt to the user.
 * 4gl code examples:
 *    PROMPT "Type something " FOR CHAR var 
 *    PROMPT "Type something " FOR CHAR TIMEOUT 150
 *    PROMPT "Type something " FOR CHAR var HELP 100
 *    PROMPT "Type something " FOR CHAR var HELP 100 ATTRIBUTE(REVERSE)
 */
prompt_cmd	
  : PROMPT prompt_title opt_attributes FOR opt_char
    variable opt_timeout opt_help_no opt_attributes 
    prompt_key_sec 
  ;

/**
 * Optional timeout to use in the PROMPT statement.
 * Define the amount of time that prompt wait for an answer.
 * This is an extension to Informix 4gl.
 * 4gl code example:
 *    TIMEOUT 150
 */
opt_timeout
  :
  | TIMEOUT INT_VALUE 
  ;

/**
 * A GUI prompt.
 * This rule is an extension to Informix 4gl.
 * 4gl code examples:
 *   PROMPT "What ? " RETURNING answerVar
 *   PROMPT "What ? " ATTRIBUTE RETURNING answerVar
 */
gui_prompt_cmd 
  : PROMPT prompt_title opt_attributes  RETURNING variable 
  ;

/**
 * Optional char used in PROMPT statement.
 */
opt_char 
  : /* empty */ 
  | CHAR 
  ;

/**
 * Optional key events of PROMPT statement
 * @todo : Change the name of the rule to opt
 * 4gl code examples:
 *     ON KEY CONTROL-W
 *       ... 4gl statements ...
 *     ON KEY CONTROL-X
 *       ... 4gl statements ....
 *   END PROMPT
 */
prompt_key_sec 
  :  /* empty */ 
	| prompt_key_clause END_PROMPT
	;

/**
 * The list key events for the PROMPT statement.
 * 4gl code examples:
 *   ON KEY CONTROL-W
 *     ... 4gl statements ....
 *   ON KEY CONTROL-X
 *     ... 4gl statements ....
 */
prompt_key_clause 
  : on_key_command_prompt
	| prompt_key_clause on_key_command_prompt 
	;

/**
 * A single key event to be used in the PROMPT statement.
 * 4gl code example:
 *   ON KEY CONTROL-W
 *     ... 4gl statements ....
 */
on_key_command_prompt 
  : on_key_command commands 
  ;

/**
 * The title for a PROMPT statement and gui PRoMPT statement.
 */
prompt_title 
  : fgl_expr_concat
	;

/* </PROMPT_STATEMENT> */

/* <SLEEP_STATEMENT> */

/**
 * Sleeps for a specified number of miliseconds.
 * 4gl code examples:
 *    SLEEP 1
 *    SLEEP numericVar
 */
sleep_cmd 
  : SLEEP fgl_expr 
  ;

/* </SLEEP_STATEMENT> */

/* <HIDE_WINDOW_STATEMENT> */

/**
 * The command to hide a window.
 * 4gl code examples:
 *   HIDE WINDOW wName
 */
hide_cmd 
  : HIDE_WINDOW win_name 
  ;

/* </HIDE_WINDOW_STATEMENT> */


/* <MOVE_WINDOW_STATEMENT> */

/**
 * A statement to move a window in the screen.
 * 4gl code examples:
 *   MOVE WINDOW wName TO x+3/2, y-4
 *   MOVE WINDOW wName BY x+3/2, y-4
 */ 
move_cmd 
  : MOVE_WINDOW win_name TO fgl_expr COMMA fgl_expr 
  |  MOVE_WINDOW win_name BY fgl_expr COMMA fgl_expr
  ;

/* <MOVE_WINDOW_STATEMENT> */


/* <CURRENT_WINDOW_STATEMENT> */

/**
 * The statement to make current (the visible window) a specific window.
 * 4gl code examples:
 *   CURRENT WINDOW IS SCREEN
 *   CURRENT WINDOW IS wName
 */
current_win_cmd	
  :	CWIS 
	|	CURRENT_WINDOW_IS win_name 
  ;

/* </CURRENT_WINDOW_STATEMENT> */

/* </SCREEN_INTERACTION> */
