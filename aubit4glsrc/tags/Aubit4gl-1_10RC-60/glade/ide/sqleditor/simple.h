
#define KW_IDENTIFIER 258
#define KW_CONSTANT 259
#define KW_STRING_LITERAL 260
#define KW_INSERT 261
#define KW_SELECT 262
#define KW_DELETE 263
#define KW_UPDATE 264
#define KW_OBRACE 265
#define KW_CBRACE 266
#define KW_SEMI 267
#define KW_SPACE 268
#define KW_CHAR 269
#define KW_NL 270
#define KW_MINUS_MINUS  271
#define KW_INTO 272
#define KW_TEMP 273
#define KW_WHERE 274
#define KW_LOAD 275
#define KW_UNLOAD 276
#define KW_DELIMITER 277
#define KW_INFO_COL 278
#define KW_INFO_STAT 279
#define KW_INFO_IDX 280
#define KW_INFO_TABLES 281
#define KW_INFO_PRIV 282
#define KW_EXPLAIN 283


struct element {
	int lineno;
	char type;
	char *stmt;
	char *delim;
	char *fname;
};


#ifdef EXTERN_YYLVAL
extern
#endif


union  {
	char str[255];
	char *s;
	struct element elem;
} yylval;






int asql_unload_data(struct element *e);
int asql_load_data(struct element *e);
