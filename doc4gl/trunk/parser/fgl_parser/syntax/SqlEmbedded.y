/* <SQL_EMBEDDED> */

/**
 * Bison rules for emebedded SQL block.
 * The SQL block are pass troughtn without syntax validation.
 */

/**
 * An embedded SQL block.
 * This is an extension to Informix 4gl.
 * In a SQL block the statements are not parsed. This way we can use specific
 * statements of a concrete database (ex: postgresql) with a diferent SQL
 * dialect.
 * The only thing validated are the reserved words.
 * 4gl code examples:
 *   SQL
 *      SELECT * FROM xptoTable
 *   END SQL
 */
sql_block_cmd 
  : SQL sql_block END_SQL 
  ;

/**
 * The internal part of a SQL embededd block.
 */
sql_block 
  : sql_block_entry 
	| sql_block sql_block_entry  
  ;

/**
 * A piece of SQL code of an embedded SQL block.
 * This rule accepts any kind of reserved SQL token without validating
 * the syntax of the SQL statement.
 */
sql_block_entry
  : SQL_TEXT 
	| in_var 
	| sql_block_into 
  | ABSOLUTE
  | ACCEPT
  | ACL_BUILTIN
  | ADD
  | AFTER
  | ALL
  | ALTER
  | ANSI
  | ANY
  | APPEND
  | ARRAY
  | AS
  | ASC
  | ASCENDING
  | ASCII
  | ASSOCIATE
  | AT
  | ATSIGN
  | ATTRIBUTES
  | AUDIT
  | AUTHORIZATION
  | AVERAGE
  | AVG
  | BEFORE
  | BETWEEN
  | BLACK
  | BLINK
  | BLUE
  | BOLD
  | BORDER
  | BOTTOM
  | BUFFERED
  | BUTTONS
  | BY
  | BYTE
  | CAPTION
  | CASE
  | CCODE
  | CHAR
  | CHECK
  | CLEAR
  | CLIPPED
  | CLOSE
  | CLOSE_BRACKET
  | CLOSE_SQUARE
  | CODE_C
  | COLON
  | COLUMN
  | COLUMNS
  | COMMA
  | COMMAND
  | COMMENT
  | COMMIT
  | CONNECT
  | CONST
  | CONSTANT
  | CONSTRUCT
  | COUNT
  | CREATE
  | CURRENT
  | CURSOR
  | CYAN
  | DATABASE
  | DATE
  | DATETIME
  | DAY
  | DBA
  | DBYNAME
  | DEC
  | DECIMAL
  | DECLARE
  | DEFAULT
  | DEFAULTS
  | DEFER
  | DEFINE
  | DELETE
  | DELIMITER
  | DESC
  | DESCENDING
  | DIM
  | DISABLE
  | DISPLAY
  | DISTINCT
  | DIVIDE
  | DOT
  | DOUBLE
  | DOWNSHIFT
  | DROP
  | ELIF
  | ELSE
  | ENABLE
  | ENDCODE
  | EQUAL
  | ERROR
  | ESCAPE
  | EVERY
  | EXCLUSIVE
  | EXEC
  | EXECUTE
  | EXISTS
  | EXIT
  | EXTEND
  | EXTENT
  | EXTERNAL
  | FCALL
  | FETCH
  | FIELDTOWIDGET
  | FIELD_TOUCHED
  | FINISH
  | FIRST
  | FKEY
  | FLOAT
  | FLUSH
  | FOR
  | FOREACH
  | FOREIGN
  | FORMAT
  | FORMHANDLER
  | INPUT
  | FORM_IS_COMPILED
  | FOUND
  | FRACTION
  | FREE
  | FROM
  | FUNCTION
  | GET_FLDBUF
  | GLOBALS
  | GO
  | GOTO
  | GRANT
  | GREATER_THAN
  | GREEN
  | GROUP
  | HAVING
  | HEADER
  | HELP
  | HIDE
  | HOUR
  | ICON
  | ID_TO_INT
  | IF
  | IN
  | INCHES
  | INDEX
  | INFIELD
  | INITIALIZE
  | INPUT
  | INSERT
  | INTEGER
  | INTERRUPT
  | INTERVAL
  | INT_TO_ID
  | INVISIBLE
  | KEY
  | KWDOWN
  | KWFIELD
  | KWFORM
  | KWLINE
  | KWMESSAGE
  | KWNO
  | KWUP
  | KWWINDOW
  | KW_AND
  | KW_FALSE
  | KW_IS
  | KW_NULL
  | KW_OR
  | KW_TRUE
  | KW_USING
  | LAST
  | LEFT
  | LESS_THAN
  | LET
  | LIKE
  | LOCAL
  | LOCATE
  | LOG
  | MAGENTA
  | MAIN
  | MARGIN
  | MATCHES
  | MAXCOUNT
  | MEMORY
  | MENU
  | MENUHANDLER
  | MESSAGEBOX
  | MINUS
  | MINUTE
  | MM
  | MOD
  | MODE
  | MODIFY
  | MONEY
  | MONTH
  | MULTIPLY
  | NEED
  | NEXT
  | NEXTPAGE
  | NOCR
  | NORMAL
  | NOT
  | NUMERIC
  | OF
  | OFF
  | ON
  | OPEN
  | OPEN_BRACKET
  | OPEN_SQUARE
  | OPTION
  | OPTIONS
  | ORDER
  | OTHERWISE
  | OUTER
  | OUTPUT
  | PAD
  | PASSWORD
  | PAUSE
  | PDF_FUNCTION
  | PDF_REPORT
  | PERCENT
  | PLUS
  | POINTS
  | PRECISION
  | PREPARE
  | PREPEND
  | PREVIOUS
  | PREVPAGE
  | PRINT
  | PRIOR
  | PROCEDURE
  | PROGRAM
  | PROMPT
  | PUBLIC
  | PUT
  | QUIT
  | READONLY
  | REAL
  | RECORD
  | RECOVER
  | RED
  | REFERENCES
  | REGISTER
  | RELATIVE
  | REPORT
  | RESOURCE
  | RETURN
  | RETURNING
  | REVERSE
  | REVOKE
  | RIGHT
  | ROLLFORWARD
  | ROW
  | ROWS
  | RUN
  | SCHEMA
  | SCROLL
  | SECOND
  | SECTION
  | SELECT
  | SEMICOLON
  | SERIAL
  | SESSION
  | SHARED
  | SHOW
  | SINGLE_KEY
  | SIZE
  | SKIP
  | SLEEP
  | SMALLFLOAT
  | SMALLINT
  | SOME
  | SPACES
  | SQL
  | SQLSUCCESS
  | STATUSBOX
  | STEP
  | STOP
  | SUM
  | SYNONYM
  | TAB
  | TEMP
  | TEMPLATE
  | TEXT
  | THEN
  | THRU
  | TIMEOUT
  | TO
  | TOP
  | TRAILER
  | TUPLE
  | UNCONSTRAINED
  | UNDERLINE
  | UNION
  | UNIQUE
  | UNLOCK
  | UPDATE
  | UPSHIFT
  | USE
  | USER
  | VALIDATE
  | VALUES
  | VARCHAR
  | VARIABLE
  | WAIT
  | WAITING
  | WHEN
  | WHERE
  | WHILE
  | WHITE
  | WITH
  | WORDWRAP
  | WORK
  | XMAX
  | XMIN
  | XSET
  | YEAR
  | YELLOW
	;

/**
 * The definition of a 4gl variable usage inside an embedded SQL block.
 * 4gl code example:
 *   $varName
 */
in_var  
  : DOLLAR var_ident_ibind_ss 
  ;

/**
 * An optional INTO to be used in the embedded SQL blocks.
 * 4gl code examples:
 *   INTO a
 *   INTO aRecord.*
 */
sql_block_into
  : INTO obind_var_list 
  ;


/* </SQL_EMBEDDED> */
