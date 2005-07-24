/* <FOREACH_STATEMENT> */

/**
 *  Bison rules to the foreach loop.
 */

/**
 * The 4gl FOREACH statement.
 * 4gl code examples:
 *    FOREACH crXppto INTO rec.a, rec.b
 *      ...4gl statements...
 *    END FOREACH
 */
foreach_cmd	
  :	FOREACH fetch_cursor_name opt_foreach_using_part
    opt_foreach_into_fetch_part commands END_FOREACH 
  ;

/**
 * The optional foreach loop USING sub statement.
 * @todo : Add a type to the rule and insert values on the AST.
 * 4gl code example:
 *    USING a,b,2
 */
opt_foreach_using_part
  : 
	| KW_USING fgl_expr_list 
	;

/* </FOREACH_STATEMENT> */
