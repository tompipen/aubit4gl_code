char *xml_encode(char *su);



int XMLWrite_variable_ptr(char *nm, variable_ptr p) ;
int XMLWrite_command_ptr(char *nm, command_ptr p) ;
int XMLWrite_expr_str_ptr(char *nm, expr_str_ptr p) ;
int XMLWrite_single_option_ptr(char *nm, single_option_ptr p) ;
//int XMLWrite_x_report_format_section_entry_ptr(char *nm, x_report_format_section_entry_ptr p) ;
int XMLWrite_report_format_section_entry_ptr(char *nm, report_format_section_entry_ptr p);
int XMLWrite_when_ptr(char *nm, when_ptr p) ;
int XMLWrite_on_event_ptr(char *nm, on_event_ptr p) ;
int XMLWrite_cons_list_entry_ptr(char *nm, cons_list_entry_ptr p) ;
int XMLWrite_module_entry_ptr(char *nm, module_entry_ptr p) ;
int XMLWrite_int(char *nm, int *l) ;
int XMLWrite_s_plsql_caseEntry_ptr (char *nm, s_plsql_caseEntry_ptr p) ;
int XMLWrite_s_plsql_defineStmt_ptr (char *nm, s_plsql_defineStmt_ptr p) ;
int XMLWrite_s_plsql_exceptionHandler_ptr (char *nm, s_plsql_exceptionHandler_ptr p) ;
int XMLWrite_s_plsql_packageEntries_ptr (char *nm, s_plsql_packageEntries_ptr p) ;
int XMLWrite_s_plsql_parameter_ptr (char *nm, s_plsql_parameter_ptr p) ;
int XMLWrite_s_plsql_specs_ptr (char *nm, s_plsql_specs_ptr p) ;

char *xml_encode_char(char c);
int XMLWrite_str(char *nm, str *val);
int XMLWrite_elements_ptr(char *nm, elements_ptr p);
void gzoutstr(FILE *o, char *name, char *value) ;
char * acl_getenv_not_set_as_0 (const char *s);

#define  lng long;
