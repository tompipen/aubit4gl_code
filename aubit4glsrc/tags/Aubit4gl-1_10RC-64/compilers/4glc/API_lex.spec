*
* API specs for LEX library interface - used by dlmagic script
* to create API_lex.c (try "make API_lex.c")
*
* Note - there are no spaces for void* int* etc.
*
*
*
* Name of the API:
LIBRARY LEX
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_LEXTYPE
* Add prefix for created API punctions:
*API_PREFIX LEXAPI_
* Add prefix for existing library functions:
LIB_PREFIX LEXLIB_
* Name of the header file to be referenced with #include
HEADER_FILE "API_lex_int.h"

#ifdef DEBUG
#undef DEBUG
#endif

#include "variables.h"
#include "field_handling.h"
#include "commands.h"

* ======================================================================
* Function calls definitions:
* func-name param-type param-name ... -> returns
*

/* ------------ functions from compile_[c|perl].c -------------- */



/* ----------- functions from compile_[c|perl]_gtk.c ------------------ */


* A4GL_bad_identifiers char* ident -> int


*change_arr_elem char* s -> char*
* get_array_rebase expr_str_list* s -> char*
*get_column_transform char* s -> char*
*A4GL_decode_array_string char* var expr_str_list* s -> char*
*get_array_substr expr_str_list* s -> char*
print_niy char* type -> void
*A4GL_get_into_part int d int n -> char*
*A4GL_set_var_sql int d int n char* currupdtable -> char*
*expr_as_string expr_str* s  -> char*

*A4GL_lex_parsed_fgl -> void
*rettype char* s -> char*


A4GL_initlex -> void
A4GL_write_generated_code module_definition* module -> int




CLASS_add_method char* name char* sig -> void
CLASS_get_members char* s -> char**
CLASS_get_variable char* s -> char**
CLASS_print_class_variable_type char* buff -> void
CLASS_print_reflector -> void
CLASS_set_class_name char* name -> void
CLASS_set_parent_name char* name -> void




* print_bind char i -> int
* print_display_new t_expr_str_list* exprs t_dt_display* disp char* attr char* style -> void
* print_linked_cmd int type,char* var -> int
* get_in_exists_sql char* s char t -> void*
* A4GL_expr_for_call char* ident long params int line char* file -> char*
/* print_display_line -> void */
* print_display_by_name char* attr -> void
* print_start_record int isstatic_extern char* varname char* arrsize int level -> void
* print_end_record char* vname char* arrsize int level -> void
* A4GL_get_push_literal char type,char* value -> char*
* print_define_char char* var,int size,int isstatic_extern -> void
* print_define char* varstring,int isstatic_extern -> void
* print_returning -> void
*A4GL_get_default_scaling -> char*
*A4GL_add_crud char* t char* v -> void
*   print_call_shared_bound char* libfile char* funcname -> void
*   print_end_call_shared -> void
*   print_call_external t_expr_str_list* expr char* host,char* funcname,char* port -> void
* print_end_call_external -> void
* get_for_default_step -> void*
* get_call_shared_bound_expr  char* lib char* name -> void*
* print_bind_expr void* ptr,char i -> int
* print_bind_pop1 char i -> void
* print_pop_variable char* s -> void
* print_getfldbuf char* fields -> void
/*  ============================== EOF ================================= */





