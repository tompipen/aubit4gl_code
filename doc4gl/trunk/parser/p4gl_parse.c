/**
 * @file 
 * Lexical parsing functions.
 *
 * This functions are mainly used by the lexer, but sometimes by the syntatic
 * parser.
 *
 * The identification of the reserved words is made by binary search instead
 * of lex to be much more fast.
 *
 * The algoritm is based on an example from the book:
 *    - " introduction to compiler construction with UNIX "
 *
 * @author : Sergio Ferreira
 *
 *
 * Problemas conhecidos:
 *    - CHARACTER e NUMERIC nao funcionam, provavelmente por causa da 
 *      ordenacao diferente do comportamento do strcmp()
 *    - Falta o table qualifier na definicao de variaveis LIKE
 *
 */


#include <stdio.h>
#include <ctype.h>
#include "p4gl_symtab.h"
#include "y.tab.h"
  
/**
 * Gives a pointer to the end of the reserved word table
 */
#define END(v)   (v-1 + sizeof v / sizeof v[0] )


/**
 * Reserved words ordered table
 */
static struct ReservedWords {
  char *nome_pr;          /* Nome da palavra reservada */
  int  valor_token;       /* Valor usado pelo yylex para o yacc */
  }ReservedWords[] = {
		"ABORT",             ABORT,
		"ABSOLUTE",          ABSOLUTE,
		/*"ACCEPT",         ACCEPT, */
		"ADD",               ADD,
		"AFTER",             AFTER,
		"ALL",               ALL,
		"ALLOCATE",          ALLOCATE,
		"ALTER",             ALTER,
		"AND",               AND,
		"ANSI",              ANSI,
		"ANY",               ANY,
		"APPEND",            APPEND,
		"ARRAY",             ARRAY,
		"AS",                AS,
		"ASC",               ASC,
		"ASCENDING",         ASCENDING,
		"ASCII",             ASCII,  
		"AT",                AT,
		"ATTACH",            ATTACH,
		"ATTRIBUTE",         ATTRIBUTE,
		"ATTRIBUTES",        ATTRIBUTE,
		"AUDIT",             AUDIT,
		"AUTHORIZATION",     AUTHORIZATION,
		"AUTONEXT",          AUTONEXT,

		"BEFORE",            BEFORE,
		"BEGIN",             BEGIN_TOK,
		"BETWEEN",           BETWEEN,
		"BLACK",             BLACK,  /* Attributo */
		"BLINK",             BLINK,  /* Attributo */
		"BLUE",              BLUE,  /* Attributo */
		"BOLD",              BOLD,  /* Attributo */
		"BORDER",            BORDER,  /* Attributo */
		"BOTH",              BOTH,
		"BOTTOM",            BOTTOM,
		"BREAK",             BREAK,
		"BUFFERED",          BUFFERED,
		"BY",                BY,
		"BYTE",              BYTE,

		"CALL",              CALL,
		"CASCADE",           CASCADE,
		"CASE",              CASE,
		"CHAR",              CHAR,       /* These two are synonims */
		"CHARACTER",         CHAR,
		"CHECK",             CHECK,
		"CLEAR",             CLEAR,
		"CLIPPED",           CLIPPED,
		"CLOSE",             CLOSE,
		"CLUSTER",           CLUSTER,
		"COLUMN",            COLUMN,    /* Columns and column are synonims */
		"COLUMNS",           COLUMNS,   /* It could return only one token ??? */
		"COMMAND",           COMMAND,
		"COMMENT",           COMMENT,
		"COMMIT",            COMMIT,
		"COMMITTED",         COMMITTED,
		"COMPRESS",          COMPRESS,
		"CONSTRAINED",       CONSTRAINED,
		"CONSTRAINT",        CONSTRAINT,
		"CONSTRAINTS",       CONSTRAINTS,
		"CONSTRUCT",         CONSTRUCT,
		"CONTINUE",          CONTINUE,
		"CONTROL",           CONTROL,
		"COUNT",             COUNT,
		"CREATE",            CREATE,
		"CURRENT",           CURRENT,
		"CURSOR",            CURSOR,
		"CYAN",              CYAN,   /* Atributo */

		"DATABASE",      DATABASE,
		"DATE",          DATE,
		"DATETIME",      DATETIME,
		"DEC",           DEC,
		"DECIMAL",       DEC,
		"DECLARE",       DECLARE,
		"DEFAULT",       DEFAULT,
		"DEFAULTS",      DEFAULTS,
		"DEFER",         DEFER,
		"DEFERRED",      DEFERRED,
		"DEFINE",        DEFINE,
		"DELETE",        DELETE,
		"DELIMITER",     DELIMITER,
		"DELIMITERS",    DELIMITERS,
		"DESC",          DESC,
		"DESCENDING",    DESCENDING,
		"DETACH",        DETACH,
		"DIAGNOSTICS",   DIAGNOSTICS,
		"DIM",           DIM,  /* Attributo */
		"DIRTY",         DIRTY,
		"DISABLE",       DISABLE,
		"DISABLED",      DISABLED,
		"DISPLAY",       DISPLAY,
		"DISTINCT",      DISTINCT,
		"DOUBLE",        DOUBLE,
		"DOWN",          DOWN,
		"DROP",          DROP,

		"ELSE",          ELSE,
		"ENABLE",        ENABLE,
		"ENABLED",       ENABLED,
		"END",           END_TOK,
		"ERROR",         ERROR,
		/* "ESC",  ESC, */
		"ESCAPE",      ESCAPE,
		"EVERY",       EVERY,
		"EXCLUSIVE",   EXCLUSIVE,
		"EXECUTE",     EXECUTE,
		"EXISTS",      EXISTS,
		"EXIT",        EXIT,
		"EXP",         EXP,
		"EXPLAIN",     EXPLAIN,
		"EXTEND",      EXTEND,
		"EXTENT",      EXTENT,
		"EXTERNAL",    EXTERNAL,

		"FALSE",       FALSE_TOK,
		"FETCH",       FETCH,
		"FIELD",       FIELD,
		"FILE",        FILE_TOK,
		"FILLFACTOR",  FILLFACTOR,
		"FILTERING",   FILTERING,
		"FINISH",      FINISH,
		"FIRST",       FIRST,
		"FLOAT",       FLOAT,
		"FLUSH",       FLUSH,
		"FOR",         FOR,
		"FOREACH",     FOREACH,
		"FOREIGN",     FOREIGN,
		"FORM",        FORM,
		"FORMAT",      FORMAT,
		"FORMONLY",    FORMONLY,
		"FOUND",       FOUND,
		"FRACTION",    FRACTION,
		"FRAGMENT",    FRAGMENT,
		"FREE",        FREE,
		"FROM",        FROM,
		"FUNCTION",    FUNCTION_TOK,

		"GLOBAL",      GLOBAL,
		"GLOBALS",     GLOBALS_TOK,
		"GO",          GO,
		"GOTO",        GOTO,
		"GRANT",       GRANT,
		"GREEN",       GREEN, /* Atributo */
		"GROUP",       GROUP,

		"HAVING",      HAVING,
		"HEADER",      HEADER,
		"HELP",        HELP,
		"HEX",         HEX,  /* Funcao interna */
		"HIDE",        HIDE,
		"HIGH",        HIGH,
		"HOLD",        HOLD,
		"HOUR",        HOUR,

		"IF",            IF,
		"IMMEDIATE",     IMMEDIATE,
		"IN",            IN,
		"INC_GLOBALS",   INC_GLOBALS,
		"INDEX",         INDEX,
		"INDEXES",       INDEXES,
		"INITIALIZE",    INITIALIZE,
		"INPUT",         INPUT,
		"INSERT",        INSERT,
		"INSTRUCTIONS",  INSTRUCTIONS,
		"INT",           INTEGER,
		"INTEGER",       INTEGER,
		"INTERRUPT",     INTERRUPT,
		"INTERVAL",      INTERVAL,
		"INTO",          INTO,
		"INVISIBLE",     INVISIBLE, /* atributo */
		"IS",            IS,
		"ISOLATION",     ISOLATION,

		"KEY",           KEY,

		"LABEL",         LABEL,
		"LAST",          LAST,
		"LEADING",       LEADING,
		"LEFT",          LEFT,
		"LENGTH",        LENGTH,  
		"LET",           LET,
		"LIKE",          LIKE,
		"LINE",          LINE,
		"LINES",         LINES,
		"LOAD",          LOAD,
		"LOCATE",        LOCATE,
		"LOCK",          LOCK,
		"LOG",           LOG,
		"LONG",          LONG,
		"LOW",           LOW,
		"MAGENTA",       MAGENTA, /* atributo */
		"MAIN",          MAIN,
		"MARGIN",        MARGIN,
		"MATCHES",       MATCHES,
		"MAX",           MAX,   /* Funcao interna */
		"MEDIUM",        MEDIUM,
		"MEMORY",        MEMORY,
		"MENU",          MENU,
		"MESSAGE",       MESSAGE,
		"MINUTE",        MINUTE,
		"MOD",           MOD,  /* Funcao interna */
		"MODE",          MODE,
		"MODIFY",        MODIFY,
		"MONEY",         MONEY,
		"NAME",          NAME,
		"NCHAR",         NCHAR,
		"NEED",          NEED,
		"NEXT",          NEXT,
		"NO",            NO,
		"NONE",          NONE,
		"NORMAL",        NORMAL,   /* atributo */
		"NOT",           NOT,
		"NULL",          NULL_TOK,
		"NUMERIC",       DEC, 
		"NVARCHAR",      NVARCHAR,

		"OF",            OF,
		"OFF",           OFF,
		"ON",            ON,
		"OPEN",          OPEN,
		"OPTIMIZATION",  OPTIMIZATION,
		"OPTION",        OPTION,
		"OPTIONS",       OPTIONS,
		"OR",            OR,
		"ORDER",         ORDER,
		"OTHERWISE",     OTHERWISE,
		"OUTER",         OUTER,
		"OUTPUT",        OUTPUT,

		"PAGE",          PAGE,
		"PAGENO",        PAGENO,
		"PAUSE",         PAUSE,
		"PDQPRIORITY",   PDQPRIORITY,
		"PICTURE",       PICTURE,
		"PIPE",          PIPE,
		"PRECISION",     PRECISION,
		"PREPARE",       PREPARE,
		"PREVIOUS",      PREVIOUS,
		"PRIMARY",       PRIMARY,
		"PRINT",         PRINT,
		"PRINTER",       PRINTER,
		"PRIOR",         PRIOR,
		"PRIVILEGES",    PRIVILEGES,
		"PROCEDURE",     PROCEDURE,
		"PROGRAM",       PROGRAM,
		"PROMPT",        PROMPT,
		"PUBLIC",        PUBLIC,
		"PUT",           PUT,

		"QUIT",          QUIT,

		"RAISE",         RAISE,
		"READ",          READ,
		"REAL",          REAL,
		"RECORD",        RECORD,
		"RED",           RED,   /* Attributo */
		"REFERENCES",    REFERENCES,
		"REFERENCING",   REFERENCING,
		"RELATIVE",      RELATIVE,
		"REMOVE",        REMOVE,
		"RENAME",        RENAME,
		"REPEATABLE",    REPEATABLE,
		"REPORT",        REPORT,
		"REQUIRED",      REQUIRED,
		"RESOURCE",      RESOURCE,
		"RESTRICT",      RESTRICT,
		"RETURN",        RETURN,
		"RETURNING",     RETURNING,
		"REVERSE",       REVERSE, /* Atributo */
		"REVOKE",        REVOKE,
		"RIGHT",         RIGHT,
		"ROBIN",         ROBIN,
		"ROLLBACK",      ROLLBACK,
		"ROLLFORWARD",   ROLLFORWARD,
		"ROUND",         ROUND,
		"ROW",           ROW,
		"ROWS",          ROWS,
		"RUN",           RUN,

		"SCREEN",      SCREEN,
		"SCROLL",      SCROLL,
		"SECOND",      SECOND,
		"SELECT",      SELECT,
		"SERIAL",      SERIAL,
		"SET",         SET,
		"SHARE",       SHARE,
		"SHOW",        SHOW,
		"SKIP",        SKIP,
		"SLEEP",       SLEEP,
		"SMALLFLOAT",  SMALLFLOAT,
		"SMALLINT",    SMALLINT,
		"SOME",        SOME,
		"SPACE",       SPACES,
		"SPACES",      SPACES,
		"SQL",         SQL_TOK,
		"SQLERROR",    SQLERROR,
		"SQLWARNING",  SQLWARNING,
		"STABILITY",   STABILITY,
		"START",       START,
		"STATISTICS",  STATISTICS,
		"STEP",        STEP,
		"STOP",        STOP,
		"SYNONYM",     SYNONYM,

		"TAB",         TAB,
		"TABLE",       TABLE,
		"TABLES",      TABLES,
		"TEMP",        TEMP,
		"TEXT",        TEXT,
		"THEN",        THEN,
		"THROUGH",     THROUGH,
		"THRU",        THRU,
		"TIME",        TIME,
		"TO",          TO,
		"TOP",         TOP,
		"TOTAL",       TOTAL,  /* Funcao interna */
		"TRAILER",     TRAILER,
		"TRANSACTION", TRANSACTION,
		"TRUE",        TRUE_TOK, 

		"UNCOMMITTED",   UNCOMMITTED,
		"UNCONSTRAINED", UNCONSTRAINED,
		"UNDERLINE",     UNDERLINE, /* Atributo */
		"UNION",         UNION,
		"UNIQUE",        UNIQUE,
		"UNITS",         UNITS,
		"UNLOAD",        UNLOAD,
		"UNLOCK",        UNLOCK,
		"UP",            UP,
		"UPDATE",        UPDATE,
		"USER",          USER,
		"USING",         USING,

		"VALIDATE",      VALIDATE,
		"VALUES",        VALUES,
		"VARCHAR",       VARCHAR,
		"VARIABLES",     VARIABLES,
		"VERIFY",        VERIFY,
		"VIEW",          VIEW,

		"WAIT",          WAIT,
		"WAITING",       WAITING,
		"WARNING",       WARNING,
		"WHEN",          WHEN,
		"WHENEVER",      WHENEVER,
		"WHERE",         WHERE,
		"WHILE",         WHILE,
		"WHITE",         WHITE,     /* Atributo */
		"WINDOW",        WINDOW,
		"WITH",          WITH,
		"WITHOUT",       WITHOUT,
		"WORDWRAP",      WORDWRAP,
		"WORK",          WORK,
		"WRAP",          WRAP,
		"YELLOW",        YELLOW,   /* Atributo */

  };

/**
 * The token passed as parameter was not matched in lexxer.
 * This routine see an ordered array using binary search to see if is a 
 * reserved word of Informix 4gl.
 *
 * @param YYText The pointer to the parser found token.
 * @return The integer value of the token if reserved word found
 *         or the integer value of IDENTIFIER otherwise.
 */
int GetReserved(char *YYText)
{
  struct ReservedWords 
	  *low  = ReservedWords,      /* Pointer to the begining of the array */
     *high = END(ReservedWords), /* Pointer to the end of the table      */
     *mid;                       /* Pointer to the midlle of the array   */

   int c;           /* To store srtcmp() return and see if goes up or down */
   char mytk[256];
	extern int lineno;

	/* todo : Isto devia ser controlado por opção para debug */
	 /*printf("Line %d - %s\n",lineno,YYText); fflush(stdout);  */
   strcpy(mytk,YYText);
   while ( low <= high )
   {
      mid = low + (high-low)/2;
      c = strcasecmp(mid->nome_pr,mytk);
		/*printf("Comparacao %s=%s ==== Low %d <-> HIGH %d\n",
			mid->nome_pr,mytk,low, high);  */
      if ( (c = strcasecmp(mid->nome_pr,mytk)) == 0) 
      {
			/* printf("Descobriu reservada %s\n", mid->nome_pr);  */
         return mid->valor_token;
      }
      else if (c < 0)
         low = mid+1;
      else
         high = mid-1;
    }
	 /*printf("Descobriu Identificador %s\n", mytk);     */
	 /* Ir ver se descobre uma cor ou atributo 
	 if (IsFglColor(YYText))
		 CopyToken(YYText,FGL_COLOR);
	    Teclas
	 Existem teclas que tembem sao outras palavras reservadas da linguagem
	 if (IsFglKey(YYText))
		 CopyToken(YYText,FGL_KEY);
		 Variaveis internas de 4gl
	 if (IsFglVariable(YYText))
		 CopyToken(YYText,FGL_KEY);
		 Funcoes internas de 4gl
	 if (IsFglFunction(YYText))
		 CopyToken(YYText,FGL_KEY);
		 Ainda faltam as funcoes C incluidas no runner ou nao
	  */
    CopyToken(YYText,IDENTIFIER);
    return(IDENTIFIER) ;
}


/* 
 *  Internal 4gl function table. This tree are not yet used
		"DBA",           DBA,
		"DBINFO",        DBINFO,
		"DBSERVERNAME",  DBSERVERNAME,
 */

/**
 * Internal 4gl function ordered table
 */
static struct FglFunctionTable {
  char *FunctionName;          
  }FglFunctionTable[] = {
		"ARG_VAL", 
		"ARR_COUNT", 
		"ARR_CURR", 
		"AVG", 
		"DAY", 
		"DOWNSHIFT", 
		"ERR_GET", 
		"ERR_PRINT", 
		"ERR_QUIT", 
		"ERRORLOG", 
		"EXTEND",
		"FGL_GETENV", 
		"FGL_KEYVAL", 
		"FGL_LASTKEY", 
		"FIELD_TOUCHED", 
		"GET_FLDBUF", 
		"INFIELD", 
		"MDY", 
		"MIN", 
		"MONTH", 
		"NUM_ARGS", 
		"ORD", 
		"SCR_LINE", 
		"SET_COUNT", 
		"SHOWHELP", 
		"STARTLOG", 
		"STDEV", 
		"SUM", 
		"UPSHIFT", 
		"WEEKDAY", 
		"YEAR" 
  };

/**
 * Check if the function name is an internal 4gl function.
 *
 * @param NmFunction The name of the function wanted.
 * @return - 1 : Is internal function.
 *         - 0 : Is not 4gl function.
 */
int IsFglFunction(char *NmFunction)
{
  struct FglFunctionTable 
			*low  = FglFunctionTable,
         *high = END(FglFunctionTable), 
         *mid; 

   int c;

   while ( low <= high )
   {
      mid = low + (high-low)/2;
      c = strcasecmp(mid->FunctionName,NmFunction);
		/*printf("Comparacao %s=%s ==== Low %d <-> HIGH %d\n",
			mid->FunctionName,mytk,low, high);  */
      if ( (c = strcasecmp(mid->FunctionName,NmFunction)) == 0) 
      {
			/* printf("Descobriu Funcao interna %s\n", mid->FunctionName); */
			return 1;
      }
      else if (c < 0)
         low  = mid+1;
      else
         high = mid-1;
    }
    return 0;
}

/**
 * Key definition keyword ordered table
 */
static struct FglKey {
  char *Key;          
  }FglKey[] = {
		"ACCEPT", 
		"DELETE", 
		"DOWN", 
		"ESC", 
		"ESCAPE", 
		"F", 
		"CONTROL-", 
		"HELP",
		"INSERT",
		"INTERRUPT",
		"LEFT",
		"NEXT",
		"NEXTPAGE",
		"PREVIOUS",
		"PREVIOUSPAGE",
		"PREVPAGE",
		"RETURN",
		"ENTER",
		"RIGHT",
		"TAB",
		"UP"
  };

/*
 * Checks if the string contains a fgl key definition 
 *
 * @param StrKey The string containing the key to be checked
 * @return - 1 : Is a key definition.
 *        - 0 : It is not a key definition.
 */
int IsFglKey(char *StrKey)
{
  struct FglKey 
			*low  = FglKey,
         *high = END(FglKey), 
         *mid; 

   int c;

	/* ??? Falta aqui o algoritmo para F1..F64 e CONTROL-char */
   while ( low <= high )
   {
      mid = low + (high-low)/2;
      c = strcasecmp(mid->Key,StrKey);
      if ( c == 0 )
			  return 1;
      else if (c < 0)
        low = mid+1;
      else
        high = mid-1;
    }

	 /* Isto esta por acabar */
	 if (strncasecmp(StrKey,"CONTROL-",8) == 0)
	 {
		 if ( !isalpha(StrKey[8]) )
			 return 0;
		  
		 /* Falta Retirar A,D,H,I,J,L,M,R,X */
		 return 1;
	 }

	 if (StrKey[0] == 'f' || StrKey[0] == 'F' )
	 {
		 /* Tem de ser um numero de tecla de funcao (entre 1 e 63) */
		 if ( !isdigit(StrKey[1]) )
			 return 0;
		 if ( StrKey[2] == '\0' || StrKey[2] == ' ' )
			 return 1;
		 if ( !isdigit(StrKey[2]) )
			 return 0;
		 return 1;
	 }
	 printf("%s nao é fglkey\n",StrKey);
    return 0;
}


/**
 * Internal variable ordered table
 */
static struct FglInternalVariable {
  char *Variable;          
  }FglInternalVariable[] = {
		"FALSE", 
		"INT_FLAG", 
		"NOTFOUND", 
		"NULL", 
		"QUIT_FLAG", 
		"SQLCA", 
		"STATUS",
		"TRUE"
  };

/**
 * Check if the string contains a fgl internal variable.
 *
 * @param InternalVariable The string containing the name of the internal 
 * variable.
 * @return - 1 : Is an internal 4gl variable
 *         - 0 : Otherwise
 */
int IsFglInternalVariable(char *InternalVariable)
{
  struct FglInternalVariable 
			*low  = FglInternalVariable,
         *high = END(FglInternalVariable),
         *mid;

   int c;

   while ( low <= high )
   {
      mid = low + (high-low)/2;
      c = strcasecmp(mid->Variable,InternalVariable);
      if ( c == 0) 
			return 1;
      else if (c < 0)
         low = mid+1;
      else
         high = mid-1;
    }
    return 0;
}

/**
 * Color list - attribute(s)
 * It May be attribute list
 *
 * Poderia ser o lexer a devolver um token denominado attributo simples
 */
static struct FglColorList {
  char *Color;          
  }FglColorList[] = {
		"BLACK", 
		"BLUE", 
		"CYAN", 
		"GREEN", 
		"MAGENTA", 
		"RED", 
		"YELLOW"
  };

/**
 * Check if the string contains a fgl color definition.
 *
 * @param Color The string that we want to check if it is a color.
 * @return - 1 : Is a color definition
 *         - 0 : It is not a color 
 */
int IsFglColor(char *Color)
{
  struct FglColorList 
			*low  = FglColorList,
         *high = END(FglColorList),
         *mid;

   int c;

   while ( low <= high )
   {
      mid = low + (high-low)/2;
      c = strcasecmp(mid->Color,Color);
      if ( c == 0) 
			return 1;
      else if (c < 0)
         low = mid+1;
      else
         high = mid-1;
    }
    return 0;
}
