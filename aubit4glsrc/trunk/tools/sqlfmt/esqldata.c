/*
** @(#)$Id: esqldata.c,v 1.1 2002-11-28 06:40:47 afalout Exp $
** @(#)Keyword list for Informix ESQL/C
** @(#)Partially upgraded for IDS/UDO.
** @(#)J Leffler
*/

#ifndef lint
static const char sccs[] = "@(#)$Id: esqldata.c,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif

char *esql_tab[] =
{
	"ABORT",
	"ABS",
	"ACCESS",
	"ACOS",
	"ADD",
	"AFTER",
	"ALIGNMENT",
	"ALL",
	"ALLOCATE",
	"ALTER",
	"AND",
	"ANSI",
	"ANY",
	"APPEND",
	"AS",
	"ASC",
	"ASCII",
	"ASIN",
	"ATAN",
	"ATAN2",
	"ATTACH",
	"ATTRIBUTE",
	"ATTRIBUTES",
	"AUDIT",
	"AUTHORIZATION",
	"AUTONEXT",
	"AVERAGE",
	"AVG",
	"BEFORE",
	"BEGIN",
	"BEGINNING",
	"BEGWORK",
	"BETWEEN",
	"BINARY",
	"BLOB",
	"BOOLEAN",
	"BOTH",
	"BOTTOM",
	"BREAK",
	"BUFFERED",
	"BY",
	"BYTE",
	"CALL",
	"CANNOTHASH",
	"CASCADE",
	"CAST",
	"CHAR",
	"CHARACTER",
	"CHARACTER_LENGTH",
	"CHAR_LENGTH",
	"CHECK",
	"CLIENT",
	"CLIPPED",
	"CLOB",
	"CLOSE",
	"CLUSTER",
	"COLLECTION",
	"COLUMN",
	"COLUMNS",
	"COMMENT",
	"COMMENTS",
	"COMMIT",
	"COMMITTED",
	"COMPOSITES",
	"COMPRESS",
	"CONCURRENT",
	"CONNECT",
	"CONNECTION",
	"CONSTRAINT",
	"CONSTRAINTS",
	"CONTINUE",
	"COS",
	"COUNT",
	"CREATE",
	"CURRENT",
	"CURSOR",
	"DATABASE",
	"DATASKIP",
	"DATE",
	"DATETIME",
	"DAY",
	"DBA",
	"DBINFO",
	"DBSERVERNAME",
	"DEALLOCATE",
	"DEBUG",
	"DEC",
	"DECIMAL",
	"DECLARE",
	"DEFAULT",
	"DEFER",
	"DEFERRED",
	"DEFINE",
	"DELETE",
	"DELIMITER",
	"DESC",
	"DESCRIBE",
	"DESCRIPTOR",
	"DETACH",
	"DIRTY",
	"DISABLED",
	"DISCONNECT",
	"DISPLAY",
	"DISPLAYONLY",
	"DISTINCT",
	"DISTRIBUTIONS",
	"DO",
	"DOCUMENT",
	"DORMANT",
	"DOUBLE",
	"DOWNSHIFT",
	"DROP",
	"EACH",
	"EDITADD",
	"EDITUPDATE",
	"ELIF",
	"ELSE",
	"ENABLED",
	"END",
	"ENDING",
	"ERROR",
	"EVERY",
	"EXCEPTION",
	"EXCLUSIVE",
	"EXEC",
	"EXECUTE",
	"EXISTS",
	"EXIT",
	"EXITNOW",
	"EXP",
	"EXPLAIN",
	"EXPLICIT",
	"EXPRESSION",
	"EXTEND",
	"EXTENT",
	"EXTERNAL",
	"FETCH",
	"FILE",
	"FILLFACTOR",
	"FILTERING",
	"FIRST",
	"FIXED",
	"FLOAT",
	"FOR",
	"FOREACH",
	"FOREIGN",
	"FORM",
	"FORMAT",
	"FOUND",
	"FRACTION",
	"FRAGMENT",
	"FROM",
	"FUNCTION",
	"GET",
	"GLOBAL",
	"GRANT",
	"GROUP",
	"HAVING",
	"HEADER",
	"HEADINGS",
	"HELP",
	"HEX",
	"HIGH",
	"HOUR",
	"IF",
	"IMMEDIATE",
	"IMPLICIT",
	"IN",
	"INCLUDE",
	"INDEX",
	"INDEXES",
	"INFO",
	"INIT",
	"INPUT",
	"INSERT",
	"INSTRUCTIONS",
	"INT",
	"INT8",
	"INTEG",
	"INTEGER",
	"INTERNALLENGTH",
	"INTERVAL",
	"INTO",
	"IS",
	"ISOLATION",
	"KEEP",
	"KEY",
	"LANGUAGE",
	"LAST",
	"LEADING",
	"LEFT",
	"LENGTH",
	"LET",
	"LIKE",
	"LINE",
	"LINENO",
	"LINES",
	"LIST",
	"LISTING",
	"LOCK",
	"LOG",
	"LOG10",
	"LOGN",
	"LOOKUP",
	"LOW",
	"LVARCHAR",
	"MATCHES",
	"MAX",
	"MAXLEN",
	"MDY",
	"MEDIUM",
	"MIN",
	"MINUTE",
	"MOD",
	"MODE",
	"MODERATE",
	"MODIFY",
	"MONEY",
	"MONTH",
	"MULTISET",
	"NATIONAL",
	"NCHAR",
	"NEW",
	"NO",
	"NONE",
	"NOT",
	"NULL",
	"NUMERIC",
	"NVARCHAR",
	"OCTET_LENGTH",
	"OF",
	"OFF",
	"OLD",
	"ON",
	"ONLY",
	"OPAQUE",
	"OPCLASS",
	"OPEN",
	"OPTIMIZATION",
	"OPTION",
	"OR",
	"ORDER",
	"OUTER",
	"OUTPUT",
	"PAGE",
	"PASSEDBYVALUE",
	"PDQPRIORITY",
	"PERCENT",
	"POW",
	"PRECISION",
	"PREPARE",
	"PRIMARY",
	"PRIVATE",
	"PRIVILEGES",
	"PROCEDURE",
	"PUBLIC",
	"RAISE",
	"RANGE",
	"READ",
	"RECOVER",
	"REFERENCES",
	"REFERENCING",
	"REMAINDER",
	"REMOVE",
	"RENAME",
	"REPAIR",
	"REPEATABLE",
	"RESOLUTION",
	"RESOURCE",
	"RESTRICT",
	"RESUME",
	"RETURN",
	"RETURNING",
	"RETURNS",
	"REVOKE",
	"RIGHT",
	"ROBIN",
	"ROLE",
	"ROLLBACK",
	"ROLLFORWARD",
	"ROOT",
	"ROUND",
	"ROUTINE",
	"ROW",
	"ROWID",
	"ROWIDS",
	"ROWS",
	"SCHEMA",
	"SCREEN",
	"SECOND",
	"SECTION",
	"SELECT",
	"SERIAL",
	"SERIAL8",
	"SERIALIZABLE",
	"SESSION",
	"SET",
	"SHARE",
	"SIN",
	"SITENAME",
	"SIZE",
	"SKIP",
	"SMALLFLOAT",
	"SMALLINT",
	"SOME",
	"SPECIFIC",
	"SQL",
	"SQLCA",
	"SQLNOTFOUND",
	"SQRT",
	"STABILITY",
	"START",
	"STATISTICS",
	"STATUS",
	"STDEV",
	"STEP",
	"STOP",
	"STRATEGIES",
	"SUM",
	"SUPPORT",
	"SYNONYM",
	"SYSTEM",
	"SysAMs",
	"SysAggregates",
	"SysAttrTypes",
	"SysBlobs",
	"SysCasts",
	"SysChecks",
	"SysColAuth",
	"SysColDepend",
	"SysColattribs",
	"SysColauth",
	"SysColdepend",
	"SysColumns",
	"SysConstraints",
	"SysDefaults",
	"SysDepend",
	"SysDistrib",
	"SysErrors",
	"SysFragAuth",
	"SysFragments",
	"SysIndexes",
	"SysIndices",
	"SysInherits",
	"SysLangAuth",
	"SysLogMap",
	"SysObjState",
	"SysOpClasses",
	"SysOpClstr",
	"SysProcAuth",
	"SysProcBody",
	"SysProcPlan",
	"SysProcedures",
	"SysReferences",
	"SysRoleAuth",
	"SysRoutineLangs",
	"SysSynTable",
	"SysSynonyms",
	"SysTabAMData",
	"SysTabAuth",
	"SysTables",
	"SysTraceClasses",
	"SysTraceMsgs",
	"SysTrigBody",
	"SysTriggers",
	"SysUsers",
	"SysViews",
	"SysViolations",
	"SysXtdDesc",
	"SysXtdTypeAuth",
	"SysXtdTypes",
	"TABLE",
	"TABLES",
	"TAN",
	"TEMP",
	"TEXT",
	"THEN",
	"TIME",
	"TO",
	"TODAY",
	"TOP",
	"TOTAL",
	"TRACE",
	"TRAILER",
	"TRAILING",
	"TRANSACTION",
	"TRIGGER",
	"TRIGGERS",
	"TRIM",
	"TRUNC",
	"TYPE",
	"UNCOMMITTED",
	"UNDER",
	"UNION",
	"UNIQUE",
	"UNITS",
	"UNLOCK",
	"UPDATE",
	"USER",
	"USING",
	"VALUES",
	"VAR",
	"VARCHAR",
	"VARIABLE",
	"VARIABLES",
	"VARIANCE",
	"VARYING",
	"VIEW",
	"VIOLATIONS",
	"WAIT",
	"WEEKDAY",
	"WHERE",
	"WHILE",
	"WITH",
	"WITHOUT",
	"WORDWRAP",
	"WORK",
	"WRITE",
	"YEAR"
};

int	  esql_size  = sizeof(esql_tab) / sizeof(char *);
