
#define NO_FGL_X
#define _NO_FORM_X_H_
#include <string.h>
#include "overloads.h"

typedef struct command * command_ptr;
typedef struct expr_str * expr_str_ptr; 
typedef struct single_option * single_option_ptr;
typedef struct report_format_section_entry* report_format_section_entry_ptr;
typedef struct when* when_ptr;
typedef struct on_event* on_event_ptr;
typedef struct cons_list_entry* cons_list_entry_ptr;
typedef struct variable* variable_ptr;
typedef struct module_entry* module_entry_ptr;
typedef struct s_select_list_item *elements_ptr;
typedef struct s_table_list_element *s_table_list_element_ptr;

#include "fgl.xh.h"
#include "fgl.xoh.h"
#include "a4gl_xml.h"
#include "a4gl_gzip.h"

