/* <UPDATE_RULE> */

/**
 * Bison rules to parse the UPDATE 4gl statement.
 */

/**
 * The SQL update statement to change data in the database.
 * 4gl code examples:
 *   UPDATE table SET ??? WHERE  table.a = 1
 */
update_statement_ss
  : UPDATE table_name set_clause_list_ss  where_upd_ss 
  ;

/**
 * The where current definition to make cursor for update changes.
 * 4gl code examples:
 *   WHERE CURRENT OF cursorName
 *   WHERE a = 1
 */
where_upd_ss 
  : 
	| WHERE_CURRENT_OF fetch_cursor_name 
	| WHERE search_condition_ss 
	;

/**
 * Set clause of a SQL Update Statement.
 * 4gl code examples:
 *   SET (columnOne,columnTwo) = (valOne,1)
 *   SET * = ( valOne,1,"xpto")
 *   SET tabName.* = ( valOne,1,"xpto")
 *   SET (colOne,columnTwo)
 *   SET * = colOne,colTwo
 *   SET tabName.* = colOne,colTwo
 */
set_clause_list_ss
  : XSET_OPEN_BRACKET upd_col_list CLOSE_BRACKET EQUAL 
	  OPEN_BRACKET upd_val_list_ss CLOSE_BRACKET 
  | XSET_MULTIPLY_EQUAL_OPEN_BRACKET upd_val_list_ss CLOSE_BRACKET 
  | XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET upd_val_list_ss CLOSE_BRACKET 
  | XSET upd_columns_ss  
  | XSET_MULTIPLY_EQUAL upd_val_list_ss  
  | XSET_ident_DOT_MULTIPLY_EQUAL upd_val_list_ss  
  ;

/**
 * Comma separated list of values that can be changed with an UPDATE statement.
 * 4gl code examples:
 *   columnOne,columnTwo
 */
upd_columns_ss 
  : col_1_ss  
	| upd_columns_ss COMMA col_1_ss 
  ;

/**
 * A possible column name to be used in the UPDATE SQL statement.
 * 4gl code example:
 *   columnOne
 *   define
 */
upd_column_name 
  : column_name  
	;

/**
 * A SET assignment in a single column.
 * 4gl code examples:
 *   colName = 1
 *   colName = "xpto"
 */
col_1_ss 
  : upd_column_name EQUAL upd_val_ss 
  ;

/**
 * A comma separated list of columns to be updated.
 * This rule is to use inside brackets.
 */
upd_col_list  
  : upd_column_name	
	| upd_col_list COMMA upd_column_name 
  ;

/**
 * A comma separated list of values to update columns.
 * To be used in the UPDATE statement.
 * 4gl code examples:
 *   valOne, 1
 *   valTwo, "xpto", NULL
 *   varName + 1 / 2
 */
upd_val_list_ss  
  : upd_val_ss 
	| upd_val_list_ss COMMA upd_val_ss 
  ;

/**
 * A possible value to use in the update statements.
 * 4gl code examples:
 *   NULL
 *   varName + 1 / 2
 */ 
upd_val_ss 
  : KW_NULL 
	| upd_value_expression_ss  
  ;

/**
 * An update value expression to use in an update statement.
 * 4gl code examples:
 *   varName
 *   1
 *   -10
 *   +14.6
 */
upd_value_expression_ss
  : upd_value_expression_initial_ss 
  | MINUS upd_value_expression_initial_ss 
  | PLUS upd_value_expression_initial_ss 
  ;

/**
 * The definition of a value to use as update value in the UPDATE statement.
 * 4gl code examples:
 *   1
 *   (select count(*) from xpto)
 *   @columnName
 *   @tableName.columnName
 *   "xpto"
 *   TRUE
 *   FALSE
 *   USER
 *   COUNT(*)
 */
upd_value_expression_initial_ss 
  : upd_var_ident_ibind_ss    
  | subquery_ss 
  | ATSIGN identifier 
  | ATSIGN identifier DOT identifier 
  | upd_value_expression_complex_ss 
  | literal
  | KW_TRUE
  | KW_FALSE
  | USER
  | COUNT_MULTIPLY
  ;

/**
 * A more complex expression to be used as a value to change column contents
 * with the UPDATE statement.
 * @todo : More examples
 * 4gl code examples:
 *   10 / 2
 *   10:10 + 1 UNITS HOUR
 */
upd_value_expression_complex_ss 
  : upd_value_expression_initial_ss DIVIDE upd_value_expression_ss 
  | upd_value_expression_initial_ss units_qual 
  | upd_value_expression_initial_ss MULTIPLY upd_value_expression_ss 
  | upd_value_expression_initial_ss PLUS upd_value_expression_ss 
  | upd_value_expression_initial_ss MINUS upd_value_expression_ss 
  | AVG OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET 
  | XMAX OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET 
  | XMIN OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET 
  | SUM OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET 
  | COUNT OPEN_BRACKET op_all upd_value_expression_ss CLOSE_BRACKET 
  | identifier OPEN_BRACKET upd_value_expr_list_ss CLOSE_BRACKET 
  | DATE OPEN_BRACKET upd_value_expr_list_ss CLOSE_BRACKET 
  | OPEN_BRACKET upd_value_expression_ss CLOSE_BRACKET 
  | EXTEND OPEN_BRACKET extend_qual_ss CLOSE_BRACKET 
  ;


upd_var_ident_ibind_ss
  : var_ident_ibind_ss 
  ;

/**
 * A comma separated list of expressions to be used in the complex expressions
 * of the update statement.
 * 4gl code examples:
 *   10 * 3 / varName, 5/varName
 */
upd_value_expr_list_ss 
  : upd_value_expression_ss 
  | upd_value_expr_list_ss COMMA upd_value_expression_ss 
  ;

/* </UPDATE_RULE> */
