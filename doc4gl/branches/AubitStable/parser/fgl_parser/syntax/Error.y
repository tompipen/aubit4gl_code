/* <ERROR_STATEMENT> */

/**
 * Bison rules for the ERROR statement.
 */

/**
 * Error statement
 * 4gl code example:
 *   ERROR "This is an error number : ", status ATTRIBUTE(REVERSE)
 */
error_cmd	
  : ERROR fgl_expr_concat opt_attributes 
	| ERROR fgl_expr_concat opt_attributes WAIT_FOR_KEY 
  ;

/* </ERROR_STATEMENT> */
