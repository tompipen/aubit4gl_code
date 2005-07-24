/* <STORAGE_MANIPULATION> */

/* <INITIALIZE_STATEMENT> */

/**
 * The statement INITIALIZE to init values to variables.
 * 4gl code examples:
 *   INITIALIZE x, y, z.* TO NULL
 *   INITIALIZE x LIKE tab.col
 */ 
init_cmd 
  : INITIALIZE init_bind_var_list TO KW_NULL
  | INITIALIZE init_bind_var_list LIKE init_tab_list
  ;

/**
 * A list of tables used on initialize statement.
 */
init_tab_list 
  : init_tab 
	| init_tab_list COMMA init_tab 
  ;

/**
 * An table definitiono to be used on INITIALIZE statement.
 */
init_tab 
  : tab_name DOT column_name 
	| tab_name DOT MULTIPLY 
  ;

/**
 * Comma separated list of variables to be initialized with the INITIALIZE
 * statement.
 * 4gl code examples:
 *   a, b, XPTO.a THRU xpto.x
 */
init_bind_var_list
  :	init_bind_var 
	  { $$ = $1; }
	|	init_bind_var_list COMMA init_bind_var 
		{ $$ = AST_STATE->InitializeVariableListCreate($1,$3); }
  ;

/**
 * A single variable to be initialized with INITIALIZE statement.
 * 4gl code examples:
 *   a
 *   xpto.a THRU xpto.g
 */
init_bind_var 
  : variable  
	  { $$ = $1; }
	| variable THRU variable 
		{ $$ = AST_STATE->InitializeThruVariableCreate($1,$3); }
  ;

/* </INITIALIZE_STATEMENT> */

/* <LET_STATEMENT> */

/** 
 * The 4gl assignment LET stateement.
 * 4gl code examples:
 *    LET i = 10
 *    LET pRecord.* = NULL
 */
let_cmd 
  : LET obind_var_let_list EQUAL op_expr_null
  ;

/**
 * Optional null expression.
 * @todo : Change the name to this rule because it is not only for NULLS
 * 4gl code example:
 *   NULL
 *   
 */
op_expr_null
  : KW_NULL 
	| fgl_expr_concat 
	;

/* </LET_STATEMENT> */

/**
 * The LOCATE statement to tell where the blob variable is located (in memory
 * or file).
 * 4gl code examples:
 *    LOCATE blobVar IN MEMORY
 *    LOCATE blobVar IN FILE "/tmp/blobFile"
 */
locate_cmd 
  : LOCATE variable IN_MEMORY 
  | LOCATE variable IN_FILE file_name 
  ;

/* <VALIDATE_RULE> */

/**
 * The statement to validate the contents of variables with the values stored
 * in the tables filled by upscol utility.
 * 4gl code examples:
 *   VALIDATE firstVar, secondVar LIKE table.column, otherTable.otherColumn
 *   VALIDATE recordVar.* LIKE table.*
 */ 
validate_cmd 
  : VALIDATE init_bind_var_list LIKE validate_tab_list  
  ;

/**
 * A comma separated list of column names to be used to the VALIDATE statement.
 * 4gl code examples:
 *   
 */
validate_tab_list 
  : validate_tab 
	| validate_tab_list COMMA validate_tab 
  ;

/**
 * A possible column(s) name(s) to be used in the list of the VALIDATE 
 * statement.
 * 4gl code examples:
 *   table.column
 *   table.*
 */
validate_tab 
  : tab_name DOT column_name 
	| tab_name DOT MULTIPLY 
  ;

/* </VALIDATE_RULE> */

/* </STORAGE_MANIPULATION> */
