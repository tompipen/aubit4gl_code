
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define KW_INSERT 261
#define KW_SELECT 262
#define KW_DELETE 263
#define KW_UPDATE 264
#define KW_OBRACE 265
#define KW_CBRACE 266
#define KW_SEMI 267
#define KW_SPACE 268
#define CHAR 269
#define NL 270
#define KW_MINUS_MINUS  271
#define KW_INTO 272
#define KW_TEMP 273
#define KW_WHERE 274
#define KW_LOAD 275
#define KW_UNLOAD 276
#define KW_DELIMITER 277



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







