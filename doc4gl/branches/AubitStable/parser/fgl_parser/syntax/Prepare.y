
/* <PREPARE_STATEMENT> */

/**
 * Bison rules for the PREPARE statement of a dynamic sql statement.
 */

/**
 * Dynamic SQL preparation.
 * 4gl code examples:
 *    PREPARE stXpto FROM sqlStr
 *    USE SESSION connName FOR PREPARE stXpto FROM sqlStr
 */
prepare_cmd 
  : opt_use PREPARE stmt_id FROM var_or_char 
  ;

/* </PREPARE_STATEMENT> */
