/* <CASE_STATEMENT> */

/**
 * Bison rules for 4gl case statement.
 */

/**
 * 4gl CASE statement.
 */
case_cmd	
  : CASE fgl_expr when_unit_expr op_otherwise_command_expr end_case_command 
  | CASE when_unit op_otherwise_command end_case_command 
  ;

/**
 * When sub statement of the case instruction with the statements that
 * are executed.
 * @todo : Explain this in a better way
 */
when_unit 
  : when_command 
	| when_unit when_command 
  ;

/**
 * The possible expressions in the when of a case command.
 */
when_unit_expr  
  : when_command_expr 
	| when_unit_expr when_command_expr 
  ;

/**
 * The end of a case statement
 */
end_case_command 
  : END_CASE 
  ;

/**
 * Optional otherwise command of the CASE statement.
 */
op_otherwise_command 
  : 
	| OTHERWISE commands 
  ;

/**
 * Optional otherwise command of the CASE statement.
 * @todo : Understand why i cant use the rule below.
 */
op_otherwise_command_expr 
  : 
	| OTHERWISE commands 
  ;

/**
 * The when definition without the statements to be executed.
 * 4gl code example:
 *    WHEN a = 1
 */
when_command	
  : WHEN  fgl_expr commands 
  ;

/**
 * @todo : understand the diference between this one a the one below.
 */
when_command_expr	
  : WHEN fgl_expr commands 
  ;

/* </CASE_STATEMENT> */
