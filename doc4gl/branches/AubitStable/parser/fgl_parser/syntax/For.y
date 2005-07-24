/* <FOR_STATEMENT>

/**
 * Bison rule to the For loop.
 */

/**
 * The FOR loop statement.
 * 4gl code examples:
 *   FOR i = 1 TO 10 STEP 2
 *      ... 4gl statements ...
 *   END FOR
 */
for_cmd	
  : FOR variable EQUAL fgl_expr TO fgl_expr op_for_step commands END_FOR 
  ;

/**
 * The optional step in the FOR loop.
 * 4gl code example:
 *   STEP -1
 */
op_for_step 
  :	
	|	STEP fgl_expr
  ;

/* </FOR_STATEMENT>
