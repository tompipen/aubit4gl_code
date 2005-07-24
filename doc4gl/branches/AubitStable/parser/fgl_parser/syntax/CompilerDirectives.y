/* <COMPILER_DIRECTIVES> */

/**
 * Compiler directives of 4gl sources.
 * The compilerdirectives have direct influence in the generated code. They
 * are static after compilation not dynamic.
 *
 * @todo : Insert the database statement here
 */


/**
 * The database statement.
 * The schema is an extension to standard Informix 4gl.
 * 4gl code example:
 *    DATABASE xpto
 */
db_section	
  : DATABASE dbase_name 
	| SCHEMA dbase_name 
  ;

/**
 * The possible database names.
 * 4gl code examples:
 *   "a_database"
 *   varContainingDatabase
 */
dbase_name	
  :	identifier 
  | identifier ATSIGN identifier
  |	CHAR_VALUE 
	;

/* <WHENEVER_STATEMENTS> */

/**
 * The whenever handling compiler directives.
 * 4gl code examples:
 *   WHENEVER NOT FOUND CONTINUE
 *   WHENEVER SQLERROR CALL xptoFunc
 *   WHENEVER ANY ERROR STOP
 */
whenever_cmd 	
  :  WHENEVER_NOT_FOUND when_do
	|  WHENEVER_SQLERROR when_do
	|  WHENEVER_ANY_ERROR when_do
	|  WHENEVER_ERROR_CONTINUE 
	|  WHENEVER_ERROR when_do
	|  WHENEVER_SQLWARNING when_do
	|  WHENEVER_WARNING_CONTINUE 
	|  WHENEVER_WARNING when_do
	|  WHENEVER_SUCCESS when_do
	|  WHENEVER_SQLSUCCESS when_do
	;

/**
 * Actions that can be executed when an error or warning (defined in the
 * WHENEVER statement ocurr.
 * 4gl code examples:
 *   CONTINUE
 *   GO TO labelName
 *   GOTO :labelName
 *   STOP
 *   CALL xptoFunction
 */
when_do		
  :	CONTINUE 
	|	GO TO label_goto
	|	GOTO label_goto
	|	STOP
	|	FCALL function_name_when
	;

/**
 * A possible label where the whenever error goto can jump to.
 * 4gl code examples:
 *   labelName
 *   :labelName
 */
label_goto	
  :	identifier
  |	COLON identifier
	;

/**
 * A function that a program call when a WHENEVER event ocurr.
 * 4gl code examples:
 *   xptoFuncName
 */ 
function_name_when
  :	identifier
	;

/* </WHENEVER_STATEMENTS> */

/* <DEFER_STATEMENT> */

/**
 * The signal defer statement
 * 4gl code examples:
 *    DEFER INTERRUPT
 *    DEFER QUIT
 */
defer_cmd	
  : DEFER_INTERRUPT 
	|	DEFER_QUIT 
	;

/* </DEFER_STATEMENT> */

/* </COMPILER_DIRECTIVES> */
