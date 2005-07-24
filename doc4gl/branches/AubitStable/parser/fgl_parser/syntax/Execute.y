/* <EXECUTE_STATEMENT> */

/**
 * Bison rules for the parser EXECUTE statement of a dynamic sql allready
 * prepared.
 */

/**
 * Execution of a prepared statement.
 * 4gl code examples:
 *   EXECUTE stXpto
 *   EXECUTE stXpto USING var, 1, 3
 *   EXECUTE IMEDIATE sqlStr
 */
execute_cmd 
  : EXECUTE stmt_id
  | EXECUTE stmt_id KW_USING ibind_var_list 
	| EXECUTE_IMMEDIATE var_or_char 
  ;

/* </EXECUTE_STATEMENT> */
