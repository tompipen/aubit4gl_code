/* <INSERT_STATEMENT> */

/**
 * Bison rules for the INSERT sql statement.
 */

/**
 * Database insert statement.
 * @todo : Understand what ss means.
 * 4gl code examples:
 *   INSERT INTO xptoTable 
 *   INSERT INTO xptoTable (firstCol,secondCol,b,c) VALUES (a,b,8,"xx")
 *   INSERT INTO xptoTable (x,y,z) SELECT a,b,c FROM otherTable WHERE a > 1
 *   INSERT INTO xptoTable VALUES (a,b,8,"xx")
 *   INSERT INTO xptoTable SELECT a,b,c FROM otherTable WHERE a > 1
 */
insert_statement_ss
  : INSERT_INTO table_name op_insert_column_list ins_2_ss 
  ;

/**
 * The second part of the INSERT statement.
 * 4gl code examples:
 *   VALUES (a,b,8,"xx")
 *   SELECT a,b,c FROM otherTable WHERE a > 1
 */
ins_2_ss 
  : VALUES OPEN_BRACKET insert_value_list_ss CLOSE_BRACKET 
	| query_specification_ss
	;

/**
 * Optional INSERT statement column list.
 * 4gl code example:
 *   (a,b,8,"xx")
 */
op_insert_column_list
  : 
	| OPEN_BRACKET insert_column_list CLOSE_BRACKET
	;

/**
 * Comma separated column list used in the INSERT statement.
 * 4gl code examples:
 *   a
 *   x,y,z,w
 */
insert_column_list
  : column_name
	| insert_column_list COMMA column_name
  ;

/**
 * Comma separated list of values to be inserted in a table with the INSERT 
 * statement.
 * @todo : understand what ss means.
 * 4gl code examples:
 *    a,b,8,"xx",NULL
 */
insert_value_list_ss
  : insert_value_ss 
	| insert_value_list_ss COMMA insert_value_ss 
  ;

/**
 * Single value that can be inserted to be used in the INSERT statement.
 * @todo : understand what ss means.
 * 4gl code example:
 *   NULL
 *   a
 *   "xx"
 *   i+1
 */
insert_value_ss
  : value_expression_ss 
	| KW_NULL 
	;

/* </INSERT_STATEMENT> */
