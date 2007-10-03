int set_ignore_indicators(void);
int clr_ignore_indicators(void);

#define yylineno sqlparse_yylineno
#define yyin sqlparse_yyin
#define yywrap sqlparse_yywrap
#define yy_delete_buffer sqlparse_yy_delete_buffer
#define yy_scan_string sqlparse_yy_scan_string
