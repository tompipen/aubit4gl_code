/* <IF_STATEMENT> */

/**
 * Bison rule for IF statement.
 */

/**
 * 4gl IF statement
 * 4gl code example:
 *    IF i = 1 THEN
 *       ... 4gl statements ...
 *    ELSE
 *       ... 4gl statements ...
 *    END IF
 */
if_cmd	
  : IF fgl_expr THEN  commands op_else END_IF 
  ;

/**
 * Optional ELSE subsatement of IF command.
 * 4gl code examples:
 *   ELSE
 *     ... 4gl statements ...
 *
 *   ELSE IF x = 1 THEN
 *     ... 4gl statements ...
 */
op_else 
  : 
	| ELSE commands
	| ELIF fgl_expr THEN commands op_else 
	;

/* </IF_STATEMENT> */
