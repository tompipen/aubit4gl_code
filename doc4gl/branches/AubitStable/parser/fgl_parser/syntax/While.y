
/* <WHILE_STATEMENT> */

/**
 * Bison rules for defining the while 4gl statement.
 */

/**
 * The while loop.
 * 4gl code example:
 *    WHILE i = 1 
 *      .. 4gl statements...
 *    END WHILE
 */
while_cmd 
  : WHILE fgl_expr commands END_WHILE 
  ;

/* </WHILE_STATEMENT> */
