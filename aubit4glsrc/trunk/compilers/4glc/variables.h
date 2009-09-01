#ifndef FGLC_VARIABLES_H
#define FGLC_VARIABLES_H

#include "dataio/fgl.xs.h"
// We allow 5 levels of array subscription...

#define MAX_ARR_SUB 15

// This is used to store a list of
// variables extrapolated from a .* or a 'thru' entry

struct record_list
{
  int records_cnt;
  struct record_list_entry **list;
};

struct record_list_entry
{
  char *name;
  struct variable *variable;
};

// A list of names
struct orig_name_list
{
  char *name;
  char *alias;
  struct name_list *next;
};

struct binding_list {
	        int nbindings;
	        char **bindings;
};

void set_variable_user_system (char n);
void variable_action (int category, char *name, char *type, char *n,
		      char *function);
void dump_var_records (void);
struct variable *find_variable_ptr (char *s);
int find_variable (char *s, int *dtype, int *size, int *is_array,struct variable **var_ptr);
void print_variables (void);
int find_type (char *s);
long isarrvariable (char *s);
long isrecvariable (char *s);
int split_record (char *s, struct variable **v_record, struct variable **v1, struct variable **v2, char bindtype);
struct variable *get_next_variable (struct variable *record,
				    struct variable *v1, struct variable *v2);
void set_current_variable_scope ( enum e_scope n);
struct record_list *split_record_list (char *s, char *prefix, struct record_list *list,char bindtype);

typedef struct variable s_variable;
struct binding_comp_list *copy_togenbind(int i) ;
int inc_var_usage_from_binding_list(struct expr_str_list *l);
struct variable *find_variable_vu_ptr(char *errbuff, struct variable_usage *v, enum e_scope *scope, int err_if_whole_array) ;
struct variable_usage *check_var_usage (struct variable_usage *v);
struct variable * find_variable_vu_in (char *errbuff, struct variable_usage *vu, struct variable **list, int cnt,int err_if_whole_array,int lvl,struct variable_list *vlist);
void set_local_variables(struct variable_list *vlist);
struct variable * find_variable_vu_in_list(char *errbuff, struct variable_usage *v, struct variable_list *vlist, int err_if_while_array,int level);
void set_uses_constants(struct variable_list *v);
void make_constant_available(struct variable *v) ;
enum e_scope A4GL_get_current_variable_scope (void);
struct variable_usage *make_variable_usage_from_string(char *buff);
struct variable *find_dim_in_variable_list(struct variable_list *v,char *name);
#endif
