/* <DISPLAY_STATEMENT> */

/**
 * Bison rules for the display statements.
 * The display statements are:
 *   DISPLAY
 *   DISPLAY BY NAME
 *   
 */

/**
 * The display statement.
 * 4gl code example:
 *   DISPLAY a, " XPTO ", 4 ATTRIBUTE(REVERSE)
 */
display_cmd 
  : DISPLAY fgl_expr_list opt_at display_attr 
  ;

/**
 * Optional AT used on the DISPLAY statement.
 * 4gl code examples:
 *   AT 3, 5
 * @todo : More examples.
 */
opt_at 
  : 
	| AT display_coords 
	| TO_MENUITEM identifier 
	| TO_MAIN_CAPTION
	| TO fld_list
	| TO KWFORM identifier KWFIELD fld_list 
	| TO KWFORM identifier CAPTION 
	| TO_STATUSBOX identifier 
  ;

/**
 * The display by name statement definition.
 * 4gl code example:
 *   DISPLAY BY NAME a, b ATTRIBUTE(BORDER)
 */
display_b_n_cmd 
  : DISPLAY_BY_NAME ibind_var_list display_attr 
  ;



/**
 * The display form statement.
 * 4gl code example:
 *   DISPLAY FORM "form_name" ATTRIBUTE(REVERSE)
 */
display_form_cmd 
  : DISPLAY_FORM form_name display_attr 
  ;

/**
 * The display array statement.
 * 4gl code example:
 *   DISPLAY ARRAY array_var TO xpto.* ATTRIBUTES(REVERSE)
 *     ... EVENTS ...
 *   END DISPLAY
 */
display_array_cmd 
  : DISPLAY_ARRAY use_arr_var TO identifier DOT MULTIPLY opt_scroll 
	  opt_attributes disp_rest 
  ;

/**
 * Optional scroll to display array statement.
 * 4gl code example:
 *   SCROLL USING a
 * @todo : Understand what is this. I think that is an extension to standard 4gl
 */
opt_scroll
  : 
  | SCROLL_USING field_name 
  ;

/**
 * Attributes used on the DISPLAY statements.
 */
display_attr	
  :	opt_attributes 
	;

/**
 * The optional part (events and end display) of DISPLAY ARRAY statement.
 */
disp_rest 
  : 
	| disp_field_commands END_DISPLAY
	| END_DISPLAY
	;

/**
 * Event handlers list for DISPLAY ARRAY statement.
 */
disp_field_commands 
  : disp_field_command 
	| disp_field_commands disp_field_command
	;

/**
 * The specific DISPLAY ARRAY events
 * 4gl code examples:
 *    AFTER ROW
 *      ... 4gl code ...
 *    BEFORE ROW
 *      ... 4gl code ...
 *    ON KEY (CONTROL-P)
 *      ... 4gl code ...
 */
disp_field_command 
  : AFTROW commands 
	| BEFROW commands 
	| on_key_command commands 
  ;

/* </DISPLAY_STATEMENT> */
