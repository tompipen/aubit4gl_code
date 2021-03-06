#ifndef FGLC_VARIABLES_H
#define FGLC_VARIABLES_H

#include "dataio/fgl.xs.h"
// We allow 5 levels of array subscription...

#define MAX_ARR_SUB 15
/*
enum e_variable_type {
	VARIABLE_TYPE_SIMPLE   ,
	VARIABLE_TYPE_RECORD    ,
	VARIABLE_TYPE_ASSOC     ,
	VARIABLE_TYPE_CONSTANT  ,
	VARIABLE_TYPE_FUNCTION_DECLARE  ,
	VARIABLE_TYPE_OBJECT    ,
	VARIABLE_TYPE_ASSOC_INTERNAL     
};
*/

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
/*
// A simple variable
struct simple_variable
{
  int datatype;			// Integer data type
  int dimensions[2];		// Size - eg char(5), or decimal(16,2)
  // dimensions[1] isn't used yet...
};

// Record variables
struct record_variable
{
  struct variable **variables;	// List of pointers to the variables
  int record_alloc;		// Number of slots allocated
  int record_cnt;		// Number of slots used
  struct linked_variable *linked;	// Link to any table + pk or 0
  char *object_type; // Used for OBJECTS and RECORDs - for a record this will be 0
  char user_ptr[256];
};
*/



// Contant datatype...
//#define CONST_TYPE_CHAR    1
//#define CONST_TYPE_FLOAT   2
//#define CONST_TYPE_INTEGER 3
//#define CONST_TYPE_IDENT   4
/*
struct constant_data
{
  int consttype;		// The contant type
  union
  {
    char *data_c;		// The actual data for char
    int data_i;			// The data for an integer
    double data_f;		// The data for a float
  }
  data;
};

struct assoc_array_variable
{
  struct variable **variables;
  int size;
  int char_size;
};

struct linked_variable
{
  char *tabname;
  struct name_list col_list;
};

struct variable
{
  struct name_list names;
  enum e_variable_type variable_type;
  char user_system;
  char scope;
  int is_array;
  int is_static;
  int is_extern;
  int arr_subscripts[MAX_ARR_SUB];
  union
  {
    struct simple_variable v_simple;
    struct record_variable v_record;
    struct assoc_array_variable v_assoc;
    struct constant_data v_const;
    struct linked_variable v_linked;
  }
  data;
  char *src_module;
};



#ifndef BINDING_COMP_LIST

struct binding_comp_list {
        struct binding_comp *bind ;
        int nbind;
        int abind;
        char type;
	char *str;
};

struct binding_comp
{
  char varname[132];
  int dtype;
  int start_char_subscript;
  int end_char_subscript;
};

struct  binding_comp_list *empty_genbind(char i);
struct  binding_comp_list *copy_togenbind(char i);

#define BINDING_COMP_LIST
#endif
*/

/* Interface functions */
//typedef struct binding_comp_list t_binding_comp_list;
//

struct binding_list {
	        int nbindings;
	        char **bindings;
};

void set_variable_user_system (char n);
void variable_action (int category, char *name, char *type, char *n,
		      char *function);
void dump_var_records (void);
struct variable *find_variable_ptr (char *s);
//void print_local_variables (void);
//void print_module_variables (void);
//void print_global_variables (void);
int find_variable (char *s, int *dtype, int *size, int *is_array,struct variable **var_ptr);
void print_variables (void);
int find_type (char *s);
long isarrvariable (char *s);
long isrecvariable (char *s);
int split_record (char *s, struct variable **v_record, struct variable **v1, struct variable **v2, char bindtype);
struct variable *get_next_variable (struct variable *record,
				    struct variable *v1, struct variable *v2);
void set_current_variable_scope (char n);
struct record_list *split_record_list (char *s, char *prefix, struct record_list *list,char bindtype);
//void print_nullify (char type);

typedef struct variable s_variable;
struct binding_comp_list *copy_togenbind(int i) ;
int inc_var_usage_from_binding_list(struct expr_str_list *l);
struct variable *find_variable_vu_ptr(char *errbuff, struct variable_usage *v, char *scope, int err_if_whole_array) ;
struct variable_usage *check_var_usage (struct variable_usage *v);
struct variable * find_variable_vu_in (char *errbuff, struct variable_usage *vu, struct variable **list, int cnt,int err_if_whole_array,int lvl);

#endif
