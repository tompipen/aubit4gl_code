/* <INPUT_STATEMENT> */

/**
 * Bison rules for the input statement.
 */

/**
 * Optional end input.
 */
end_input 
  :
  | field_commands END_INPUT 
  | END_INPUT 
	;

/**
 * Optional WHITHOUT DEFAULTS property of INPUT statement.
 */
opt_defs 
  : 
  | WITHOUT_DEFAULTS 
  ;

/**
 * The list of field commands to be used inside INPUT statement.
 * The commands are the field and input events.
 */
field_commands 
  : field_command 
	| field_commands field_command
	;

/**
 * The field commands tyo be used inside the INPUT statement.
 */
field_command 
  : BEFFIELD bef_field_list commands 
	| AFTFIELD aft_field_list commands 
	| AFTROW commands 
	| BEFROW commands 
	| on_key_command commands 
	| AFTINP commands 
	| BEFINP commands 
	| BEFORE_DELETE  commands 
	| BEFORE_INSERT  commands 
	| AFTER_DELETE  commands 
	| AFTER_INSERT  commands 
  ;

/**
 * The list of fields to be used in before field event of the INPUT
 * statement.
 */
bef_field_list 
  : field_name 
	| bef_field_list COMMA field_name 
  ;

/**
 * The list of fields to be used in after field events of the INPUT 
 * statement.
 */
aft_field_list 
  : field_name 
	| aft_field_list COMMA field_name 
  ;

/**
 * The next field command that is used inside the events of the INPUT
 * statement.
 */
next_field_cmd 
  : NEXTFIELD next_field 
  ;

/**
 *
 */
next_form_cmd 
  : NEXTFORM identifier KWFIELD next_field 
  ;

/**
 * The definition of the field that where to move with
 * NEXT FIELD command.
 */
next_field	
  :	NEXT 
	| PREVIOUS 
	| field_name 
  ;

/**
 * The main rule of the INPUT statement.
 */
input_cmd	
  :	INPUT inp_rest end_input 
  ;

/**
 * The inside of the INPUT statement.
 * 4gl code examples:
 *   BY NAME xpto.* HELP 100
 *   BY NAME xpto.* HELP 100
 *   ARRAY vsArray FROM pa 
 */
inp_rest
  : BY_NAME ibind_var_list opt_defs opt_help_no opt_attributes 
  | ibind_var_list opt_defs FROM fld_list  opt_help_no opt_attributes 
  | ARRAY use_arr_var opt_defs FROM identifier DOT MULTIPLY opt_help_no 
    opt_attributes
  ;

/**
 * Scroll statement that scrolls up or down the values of an array
 * in a screen array.
 */
scroll_cmd 
  : SCROLL fld_list up_or_down 
  ;

/**
 * The up or down definition os the scroll statement and the amount of
 * lines.
 * 4gl code example:
 *    UP 2
 *    DOWN 4
 *    UP
 *    DOWN
 */
up_or_down  
  : KWUP_BY INT_VALUE 
	| KWDOWN_BY INT_VALUE 
	| KWUP 
	| KWDOWN 
  ;

/**
 * Optional help used in the construct statement.
 * 4gl code example:
 *    HELP 20
 */
op_help 
  : 
	| HELP INT_VALUE
  ;

/**
 * Specific INPUT ARRAY attributes.
 * @todo : Understand if this rule could be merged with 
 * input_array_attributes_int rule.
 */
input_array_attributes
  : input_array_attributes_int 
  ;

/**
 * Specific INPUT ARRAY attributes.
 */
input_array_attributes_int 
  : CURRENT_ROW_DISPLAY_EQUAL CHAR_VALUE 	
	| COUNT EQUAL INT_VALUE
	| COUNT EQUAL variable
	| MAXCOUNT EQUAL INT_VALUE
	| MAXCOUNT EQUAL variable
	| INSERT_ROW_EQUAL_TRUE
	| INSERT_ROW_EQUAL_FALSE
	| DELETE_ROW_EQUAL_TRUE
	| DELETE_ROW_EQUAL_FALSE
  ;

/* </INPUT_STATEMENT> */
