/* <CONSTRUCT_STATEMENT> */

/**
 * Bison rules for the construct screen interaction 4gl statement.
 */

/**
 * The construct statement.
 * 4gl example code:
 *   CONSTRUCT BY NAME pr.* ON str
 *    ... construct events ...
 *   END CONSTRUCT
 */
construct_cmd	
  :	CONSTRUCT constr_rest end_constr 
  ;


/**
 * The main part of construct between CONSTRUCT and END CONSTRUCT
 * 4gl example code:
 *    BY NAME pr.* ON str
 *    AFTER FIELD xpto
 *       ... 4gl code ...
 */
constr_rest
  : BY_NAME variable ON constr_col_list opt_defs op_help opt_attributes
  | variable ON constr_col_list opt_defs FROM fld_list op_help opt_attributes
  ;

/**
 * Optional end construct.
 * @todo : change the name to op_end_construct
 */
end_constr 
  : 
  | constr_extra_commands END_CONSTRUCT 
  ;

/**
 * The construct column list
 * 4gl code example:
 *    xpto.a, xpto.b, x
 */
constr_col_list 
  : constr_col 
	| constr_col_list COMMA constr_col
  ;

/**
 * A construct column
 * 4gl code examples:
 *    xpto.*
 *    xpto.a
 *    y
 */
constr_col 
  : identifier 
  | identifier DOT identifier 
  | identifier DOT MULTIPLY 
  ;

/**
 * Extra comand list of the construct statement.
 */ 
constr_extra_commands 
  : constr_extra_command 
	| constr_extra_commands constr_extra_command
  ;

/**
 * Construct possible event statements.
 * 4gl code examples:
 *    BEFORE FIELD xpto
 *      ... 4gl statements ...
 *    AFTER FIELD xpto
 *      ... 4gl statements ...
 *    ON KEY (CONTROL-A)
 *      ... 4gl statements ...
 *    AFTER CONSTRUCT
 *      ... 4gl statements ...
 *    BEFORE CONSTRUCT
 *      ... 4gl statements ...
 */
constr_extra_command 
  : BEFFIELD bef_c_field_list commands 
	| AFTFIELD aft_c_field_list commands 
	| on_key_command commands 
	| AFTCONSTRUCT commands 
	| BEFCONSTRUCT commands 
  ;

/**
 * The before field construct list
 * 4gl code example:
 *    first_field, second_field
 */
bef_c_field_list 
  : field_name2 
	| bef_c_field_list COMMA field_name2 
  ;

/**
 * The after field construct list 
 * 4gl code example:
 *    first_field, second_field
 */
aft_c_field_list 
  : field_name2 
	| aft_c_field_list COMMA field_name2 
  ;

/* </CONSTRUCT_STATEMENT> */

