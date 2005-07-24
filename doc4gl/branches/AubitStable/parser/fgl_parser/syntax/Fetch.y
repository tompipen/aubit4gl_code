/* <FETCH_STATEMENT> */

/**
 * Bison rules for the fetch statements.
 */

/**
 * The cursor FETCH statement.
 * 4gl code examples:
 *   FETCH crName 
 *   FETCH crName INTO x,y,z
 *   FETCH FIRST crName
 *   FETCH LAST crName INTO x,y,z
 *   FETCH NEXT crName
 *   FETCH PREVIOUS crName
 *   FETCH PRIOR crName INTO x,y,z
 *   FETCH CURRENT crName
 *   FETCH RELATIVE 10 crName  INTO x,y,z
 *   FETCH ABSOLUTE i + 1 crName 
 */
fetch_statement
  : FETCH fetch_part opt_into_fetch_part
  ;

/**
 * The specification about what kind of fetch is made.
 * 4gl code examples:
 *   crName
 *   
 */
fetch_part
  : fetch_place fetch_cursor_name
  | fetch_cursor_name
  ;

/**
 * The kind of place for where the cursor should be positioned.
 * Used in the FETCH statement.
 * 4gl code examples:
 *   FIRST 
 *   LAST
 *   NEXT
 *   PREVIOUS
 *   PRIOR
 *   CURRENT
 *   RELATIVE 10
 *   ABSOLUTE i + 1
*/
fetch_place 
  : FIRST 
	| LAST
	| NEXT
	| PREVIOUS
	| PRIOR
	| CURRENT
	| RELATIVE fgl_expr
	| ABSOLUTE fgl_expr
  ;

/**
 * Optional INTO subcommand of the FETCH statement.
 * 4gl code examples:
 *   INTO a,b,c
 */
opt_into_fetch_part
  :
  | INTO obind_var_list 
  ;

/* </FETCH_STATEMENT> */
