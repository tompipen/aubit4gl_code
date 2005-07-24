/** <FGL_DEFINITION> */


/**
 * Fgl definition rules for the folowing 4gl code/statements:
 *   A 4gl module
 *   DEFINE
 *   FUNCTION 
 *   MAIN
 *   REPORT
 */

/**
 * A 4gl module. This is the main rule to parse a 4gl source file.
 * 4gl code example:
 *   DEFINE x SMALLINT
 *
 *   MAIN
 *     CALL hello()
 *   END MAIN
 *  
 *   FUNCTION hello()
 *     DISPLAY "Hello world"
 *   END FUNCTION
 */
module
  : op_module_header op_function_list 
	  { 
		  //$$ = new FglModule($2); 
			//*ast = $$;
			//FglNavigate($2);
		}
  ;


/**
 * The optional 4gl module header.
 * The module header could be the database, globals and modular
 * variables definition.
 */
op_module_header
  : 
	| module_header 
  ;

/**
 * The list of module header entry(s).
 */
module_header	
  :	module_entry 
	|	module_header module_entry
  ;

/**
 * The possible 4gl header for modules.
 * 4gl code examples:
 *
 */
module_entry 
  : module_import 
  | module_code 
  | module_globals_section 
  | module_define_section  
	;

/**
 * Optional Main or other functions definition.
 * This rule was called func_main_def in old Mike parser.
 *
 * @return A function list node.
 */
op_function_list
  : /* could be empty file */
	  { $$ = (FglNode *)0; }
  | function_list
	  { $$ = $1; }
  ;

/**
 * Not optional list of main or other kind of functions definition.
 * In mike parser this rule was called func_or_main2
 * @todo : Change the name ofthis rule to func_or_main_list
 *
 * @return A pointer to a list of functions (of diferent types).
 */
function_list 
  : abstract_function
	  { $$ = $1; }
	| function_list abstract_function 
	  //{ $$ = $1->addFunction($2); }
		{ $$ = AST_STATE->FunctionListCreate($1,$2); }
	;

/**
 * Abstract Function definition.
 * This rule is called func_or_main in Mike parser.
 * It is abstract because could be all function types (function, main,
 * report, etc).
 */
abstract_function	
  :	function_definition 
	  { $$ = $1; }
	|	main_def
	|	mem_func_def
	|	report_def
	|	pdf_report_def
  | menu_def
	| whenever_cmd 
  | formhandler_def
	|	code_cmd
	| import_m
	|	comment_cmd
	;

/*
 * Concrete Function definition.
 * This rule is called func_def on Mike parser.
 * 4gl code examples:
 *   FUNCTION funcName(x,y)
 *      ... define_statements ...
 *      ... 4gl statements ...
 *   END FUNCTION
 * @return A pointer to a Function node.
 */
function_definition	
  : ldeffunction identifier OPEN_BRACKET  op_param_var_list CLOSE_BRACKET 
      define_section 
      op_code commands 
		end_func_command
		 { $$ = AST_STATE->FunctionCreate($2); }
	;

/*
 * The end of the function rule 
 * @todo : Understand if this rule is realy needed.
 */
end_func_command 
  : END_FUNCTION 
  ;

/**
 * The specific MAIN function definition.
 * 4gl code example:
 *    MAIN 
 *      ... define statements ...
 *      ... fgl statements ...
 *    END MAIN
 */
main_def
  :	MAIN define_section commands END_MAIN 
  ;

include(FglReport.y)

/** </FGL_DEFINITION> */
