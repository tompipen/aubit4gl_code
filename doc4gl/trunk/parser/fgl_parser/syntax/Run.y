/* <RUN_STATEMENT> */

/**
 * Bison rules for the RUN statement.
 */

/**
 * Run an external program making a fork and eventually a wait.
 * 4gl code examples:
 *   RUN "fgrep xx *" RETURNING x
 *   RUN "vi" WITHOUT WAITING
 *   RUN "vi" EXIT
 */
run_cmd 
  : RUN fgl_expr 
  | RUN fgl_expr RETURNING variable 
  | RUN fgl_expr WITHOUT_WAITING 
  | RUN fgl_expr WAIT 
  | RUN fgl_expr EXIT 
  ;

/* </RUN_STATEMENT> */
