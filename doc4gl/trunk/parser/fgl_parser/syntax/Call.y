/* <CALL_STATEMENT> */

/**
 * Bison rules for call statement.
 */


/**
 * Explicit function call.
 * @todo Add type and insertion on AST.
 * 4gl code example:
 *    CALL xpto(a,2,"XX")
 */
call_cmd	
  : FCALL call_ext 
  ;

/**
 * Continuation of the explicit function call.
 * This rule should
 *
 * @todo : I take of the validation of the get_fldbuff inside the input or 
 * construct.
 */
call_ext 
  : function_callb RETURNING variable 
  | GET_FLDBUF OPEN_BRACKET fld_list CLOSE_BRACKET RETURNING  ibind_var_list 
  | FORM_IS_COMPILED OPEN_BRACKET identifier 
	  COMMA CHAR_VALUE COMMA CHAR_VALUE CLOSE_BRACKET 
  | INFIELD OPEN_BRACKET field_name CLOSE_BRACKET RETURNING variable 
  | pdf_functions
  | FIELD_TOUCHED OPEN_BRACKET field_name_list CLOSE_BRACKET RETURNING variable 
  | variable COLON identifier OPEN_BRACKET opt_func_call_args CLOSE_BRACKET 
    opt_return 
  | identifier OPEN_BRACKET opt_func_call_args CLOSE_BRACKET opt_return 
  | SHARED char_or_var IN char_or_var OPEN_BRACKET 
    opt_func_call_args CLOSE_BRACKET opt_return 
  | identifier DOUBLE_COLON identifier  OPEN_BRACKET opt_func_call_args 
    CLOSE_BRACKET opt_return 
  | EXTERNAL remote_host_name COLON remote_func_name 
	  OPEN_SQUARE valid_port CLOSE_SQUARE OPEN_BRACKET
    opt_func_call_args CLOSE_BRACKET opt_return_remote
  ;

/**
 * Optional (could be void) returning of function call statement.
 * 4gl code example: RETURNING a,1,"xx"
 * @todo : Change the name to op_returning
 * @todo : Add AST insertion.
 */
opt_return 	
  : 
	| RETURNING ibind_var_list 
  ;

/**
 * Optional returning subsection of function call as RPC client
 */
opt_return_remote 	
  : 
  | RETURNING ibind_var_list
  | WITHOUT_WAITING
  ;


/**
 * Optional function call arguments.
 */
opt_func_call_args 
  : 
	| func_call_args
  ;

/**
 * Function call argument list.
 * 4gl code example:  a,b,1,"zz"
 */
func_call_args	
  : func_arg
	| func_call_args COMMA func_arg 
  ;


/**
 * A function argument.
 */
func_arg 	
  : fgl_expr_c 
  ;

/**
 * Remote host name to be used in the RPC function calls.
 */
remote_host_name 
  : CHAR_VALUE 
	| identifier
  ;

/**
 * Remote (RPC) function names.
 */
remote_func_name 
  : identifier 
  | identifier DOT identifier 
  ;

/* </CALL_STATEMENT> */
