#ifndef A4GL_BUILTIN_FUNC_H
#define A4GL_BUILTIN_FUNC_H

#ifdef __cplusplus
extern "C"
{
#endif




int aclfgl_aclfgl_call_in_shared(int a) ;
int aclfgl_aclfgl_client_execute(int _nargs);
int aclfgl_aclfgl_client_set(int _nargs);
int aclfgl_aclfgl_embed_barcode (int _nargs);
int aclfgl_aclfgl_expand_env_vars_in_cmdline(int n);
int aclfgl_aclfgl_flushinp (int n);
int aclfgl_aclfgl_get_connection_username(int a) ;
int aclfgl_aclfgl_get_construct_element(int n) ; 
int aclfgl_aclfgl_get_pdf_encoding(int n);
int aclfgl_aclfgl_get_sql_requirement(int n);
int aclfgl_aclfgl_get_stack_trace(int n);
int aclfgl_aclfgl_get_user(int n);
int aclfgl_aclfgl_getclientfile(int _nargs);
int aclfgl_aclfgl_getcwd (int a);
int aclfgl_aclfgl_parse_csv(int nparam);
int aclfgl_aclfgl_random(int n) ;
int aclfgl_aclfgl_read_pipe(int nargs);
int aclfgl_aclfgl_replace_in_string(int n);
int aclfgl_aclfgl_replace_start(int nargs);
int aclfgl_aclfgl_send_to_ui(int _nargs);
int aclfgl_aclfgl_sendfile_to_ui(int _nargs);
int aclfgl_aclfgl_set_color (int _nargs);
int aclfgl_aclfgl_set_pdf_encoding(int n);
int aclfgl_aclfgl_setenv(int n);
int aclfgl_aclfgl_split_on_delimiter (int n);
int aclfgl_aclfgl_trim_nl(int n);
int aclfgl_aclfgl_walk_pointers (int n);
// These are UI functions - included in the generated a4gl_API_ui.h file
//int aclfgl_aclfgl_set_display_field_delimiters(int nparam);
//int aclfgl_aclfgl_add_acs_mapping(int nparam);
//int aclfgl_aclfgl_dump_screen(int n);
//int aclfgl_aclfgl_add_to_toolbar(int nparam);


//int aclfgl_aclfgl_libhelp_showhelp(int helpno);
//int aclfgl_aclfgl_closeiem(int nparams);
//int aclfgl_aclfgl_openiem(int nparams);
//int aclfgl_aclfgl_fetchiem(int nparams);
//int aclfgl_aclfgl_set_application_xml(int nparam);
#ifdef __cplusplus
}
#endif

#endif

