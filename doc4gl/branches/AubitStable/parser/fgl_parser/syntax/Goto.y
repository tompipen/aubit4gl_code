/* <GOTO_STATEMENT> */

/**
 * Bison rules to goto statement.
 */

/**
 * Goto statement
 * 4gl code example:
 *    GOTO xptoLabel
 */
goto_cmd 
  : GOTO label_goto 
  ;

/**
 * The 4gl LABEL statement to be used with the GOTO statement.
 * The identifier of the label is readed by the lexer.
 * 4gl code example:
 *   LABEL xpto
 */
label_cmd 
  : LABEL  
  ;


/* </GOTO_STATEMENT> */
