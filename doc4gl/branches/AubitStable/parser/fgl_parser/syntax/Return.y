/* <RETURN_STATEMENT> */

/**
 * Bison rules for the RETURN statement.
 */

/**
 * The return statements
 * 4gl code examples:
 *   RETURN
 *   RETURN a
 *   RETURN 1, x.p
 *   RETURN a+b
 */
return_cmd 
  : RETURN op_fgl_expr_ret_list 
  ;

/**
 * Optional 4gl returning list of expressions.
 */
op_fgl_expr_ret_list
  : 
	| fgl_expr_ret_list
  ;

/**
 * Comma separated list of expressions to be used in RETURN statement.
 */
fgl_expr_ret_list 	
  : fgl_expr_ret
	| fgl_expr_ret_list COMMA fgl_expr_ret
  ;

/**
 * 4gl expression to be used in RETURN statement.
 */
fgl_expr_ret 
  : fgl_expr 
	| KW_NULL
  ;

/* </RETURN_STATEMENT> */
