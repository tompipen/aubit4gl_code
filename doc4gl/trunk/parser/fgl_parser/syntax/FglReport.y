/** <FGL_REPORT> */

/**
 * Bison parser Rules for 4gl reports.
 */


/**
 * The definition of the special functions that are reports.
 * 4gl code examples:
 *   REPORT xptoRepName(a,b,c)
 *      DEFINE a,b,c SMALLINT
 *      ... Report definition sections ...
 *   END REPORT
 */
report_def 
  : REPORT identifier OPEN_BRACKET op_param_var_list CLOSE_BRACKET 
	  define_section report_section format_section END_REPORT 
  ;



/** </FGL_REPORT> */
