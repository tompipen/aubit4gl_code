
/* <SCREEN_ATTRIBUTE> */

/**
 * Bison rules for screen interaction attributes.
 */

/**
 * Optional (could be empty) attributes to be used in screens.
 * The optional attributes are used by the statements:
 *   CONSTRUCT
 *   DISPLAY ARRAY
 *   DISPLAY
 *   ERROR
 *   INPUT
 *   PROMPT
 */
opt_attributes
  :	
	| attributes_def 
  ;

/**
 * Possible screen interaction default attribute statement.
 * This attributes are used in the folowing statements:
 *   MESSAGE
 *   DISPLAY
 *   INPUT
 *   CONSTRUCT
 *   DISPLAY ARRAY
 *   DISPLAY
 *   ERROR
 *   PROMPT
 * 4gl code examples:
 *     ATTRIBUTES (REVERSE,WHITE)
 *     SIZE (10,20)
 */
attributes_def	
  : ATTRIBUTES OPEN_BRACKET attribs_sec CLOSE_BRACKET 
  | SIZE OPEN_BRACKET INT_VALUE COMMA INT_VALUE CLOSE_BRACKET
  ;

/**
 * Attribute list.
 * 4gl code example:
 *    REVERSE,WHITE
 */
attribs_sec	
  : attribute 
  | attribs_sec COMMA attribute 
  ;

/**
 * Specific possible screen attributes.
 * This attributes are used in the folowing statements:
 *   MESSAGE
 *   
 */
attribute	
  :BLACK
	|BLUE
	|CYAN
	|GREEN
	|MAGENTA
	|RED
	|WHITE
	|YELLOW
	|REVERSE
	|BLINK
	|UNDERLINE
	|BOLD
	|NORMAL
	|INVISIBLE
	|DIM
  |NO_NEW_LINES 
	|input_array_attributes 
	;

/**
 * Optional (could be empty) WINDOW attributes.
 * Used in OPEN WINDOW STATEMENT
 */
win_attributes
  :
	| win_attributes_def
  ;

/**
 * Window attribute sub section
 * Used in OPEN WINDOW STATEMENT
 * 4gl code example:
 *    ATTRIBUTES (MAGENTA,REVERSE)
 */
win_attributes_def	
  :	ATTRIBUTES OPEN_BRACKET wattribs_sec CLOSE_BRACKET 
  ;

/**
 * List of window attributes.
 * Used in OPEN WINDOW STATEMENT
 * 4gl code example:
 *    MAGENTA,REVERSE
 */
wattribs_sec	
  :	wattribute 
	|	wattribs_sec COMMA wattribute 
  ;

/**
 * Concrete window attributes.
 * Used in OPEN WINDOW STATEMENT
 */
wattribute	
  : attribute 
  |	BORDER 
	| PAD CHAR_VALUE
	|	COMMENT_LINE line_no
	|	FORM_LINE line_no
	|	ERROR_LINE line_no
	|	MENU_LINE line_no
	|	MSG_LINE line_no
	|	PROMPT_LINE line_no
  ;


/* </SCREEN_ATTRIBUTE> */
