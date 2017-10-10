#ifndef SQL_COMPILER_ALIAS_H
#define SQL_COMPILER_ALIAS_H

int set_ignore_indicators(void);
int clr_ignore_indicators(void);

// Aliases to make sure the names are unique
//
// Every now and then -check these with a script like 
// nm -a /home/aubit4gl/aubit4glsrc/plugins-*/libSQLPARSE_INFORMIX.so  | grep yy | grep -v "sqlparse_" | awk '{print "#define " $3 " sqlparse_" $3}' 
//
#define yylineno 		sqlparse_yylineno
#define yyin 			sqlparse_yyin
#define yywrap 			sqlparse_yywrap
#define yy_delete_buffer 	sqlparse_yy_delete_buffer
#define yy_scan_string 		sqlparse_yy_scan_string
#define yy_get_next_buffer 	sqlparse_yy_get_next_buffer
#define yy_scan_bytes           sqlparse_yy_scan_bytes

#define do_yyerror sqlparse_do_yyerror
#define yy_accept sqlparse_yy_accept
#define yy_base sqlparse_yy_base
#define yy_buffer_stack sqlparse_yy_buffer_stack
#define yy_buffer_stack_max sqlparse_yy_buffer_stack_max
#define yy_buffer_stack_top sqlparse_yy_buffer_stack_top
#define yy_c_buf_p sqlparse_yy_c_buf_p
#define yy_chk sqlparse_yy_chk
#define yy_create_buffer sqlparse_yy_create_buffer
#define yy_def sqlparse_yy_def
#define yy_did_buffer_switch_on_eof sqlparse_yy_did_buffer_switch_on_eof
#define yy_ec sqlparse_yy_ec
#define yy_fatal_error sqlparse_yy_fatal_error
#define yy_flex_debug sqlparse_yy_flex_debug
#define yy_flush_buffer sqlparse_yy_flush_buffer
#define yy_get_previous_state sqlparse_yy_get_previous_state
#define yy_hold_char sqlparse_yy_hold_char
#define yy_init sqlparse_yy_init
#define yy_init_buffer sqlparse_yy_init_buffer
#define yy_init_globals sqlparse_yy_init_globals
#define yy_last_accepting_cpos sqlparse_yy_last_accepting_cpos
#define yy_last_accepting_state sqlparse_yy_last_accepting_state
#define yy_load_buffer_state sqlparse_yy_load_buffer_state
#define yy_meta sqlparse_yy_meta
#define yy_more_flag sqlparse_yy_more_flag
#define yy_more_len sqlparse_yy_more_len
#define yy_n_chars sqlparse_yy_n_chars
#define yy_nxt sqlparse_yy_nxt
#define yy_reduce_print sqlparse_yy_reduce_print
#define yy_rule_can_match_eol sqlparse_yy_rule_can_match_eol
#define yy_scan_buffer sqlparse_yy_scan_buffer
#define yy_scan_bytes sqlparse_yy_scan_bytes
#define yy_stack_print sqlparse_yy_stack_print
#define yy_start sqlparse_yy_start
#define yy_switch_to_buffer sqlparse_yy_switch_to_buffer
#define yy_symbol_print sqlparse_yy_symbol_print
#define yy_symbol_value_print sqlparse_yy_symbol_value_print
#define yy_try_NUL_trans sqlparse_yy_try_NUL_trans
#define yyalloc sqlparse_yyalloc
#define yycheck sqlparse_yycheck
#define yydefact sqlparse_yydefact
#define yydefgoto sqlparse_yydefgoto
#define yydestruct sqlparse_yydestruct
#define yyensure_buffer_stack sqlparse_yyensure_buffer_stack
#define yyfree sqlparse_yyfree
#define yyget_debug sqlparse_yyget_debug
#define yyget_in sqlparse_yyget_in
#define yyget_leng sqlparse_yyget_leng
#define yyget_lineno sqlparse_yyget_lineno
#define yyget_out sqlparse_yyget_out
#define yyget_text sqlparse_yyget_text
#define yyleng sqlparse_yyleng
#define yylex_destroy sqlparse_yylex_destroy
#define yyout sqlparse_yyout
#define yypact sqlparse_yypact
#define yypgoto sqlparse_yypgoto
#define yypop_buffer_state sqlparse_yypop_buffer_state
#define yyprhs sqlparse_yyprhs
#define yypush_buffer_state sqlparse_yypush_buffer_state
#define yyr1 sqlparse_yyr1
#define yyr2 sqlparse_yyr2
#define yyrealloc sqlparse_yyrealloc
#define yyrestart sqlparse_yyrestart
#define yyrhs sqlparse_yyrhs
#define yyrline sqlparse_yyrline
#define yyset_debug sqlparse_yyset_debug
#define yyset_in sqlparse_yyset_in
#define yyset_lineno sqlparse_yyset_lineno
#define yyset_out sqlparse_yyset_out
#define yystos sqlparse_yystos
#define yytable sqlparse_yytable
#define yytext sqlparse_yytext
#define yytname sqlparse_yytname
#define yytranslate sqlparse_yytranslate
#define yyunput sqlparse_yyunput
#endif
