
// We allow 5 levels of array subscription...
#define MAX_ARR_SUB 15


#define VARIABLE_TYPE_SIMPLE    0
#define VARIABLE_TYPE_RECORD    1
#define VARIABLE_TYPE_ASSOC     2
#define VARIABLE_TYPE_CONSTANT  3
#define VARIABLE_TYPE_FUNCTION_DECLARE  4


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
struct name_list
{
  char *name;
  char *alias;
  struct name_list *next;
};

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
};




// Contant datatype...
#define CONST_TYPE_CHAR    1
#define CONST_TYPE_FLOAT   2
#define CONST_TYPE_INTEGER 3
#define CONST_TYPE_IDENT   4

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
  int variable_type;
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

/* Interface functions */

void set_variable_user_system (char n);
void variable_action (int category, char *name, char *type, char *n,
		      char *function);
void dump_var_records (void);
struct variable *find_variable_ptr (char *s);
void print_local_variables (void);
void print_module_variables (void);
void print_global_variables (void);
int find_variable (char *s, int *dtype, int *size, int *is_array,
		   void **var_ptr);
void print_variables (void);
int find_type (char *s);
long isarrvariable (char *s);
long isrecvariable (char *s);
int split_record (char *s, struct variable **v_record, struct variable **v1,
		  struct variable **v2);
struct variable *get_next_variable (struct variable *record,
				    struct variable *v1, struct variable *v2);
void set_current_variable_scope (char n);
struct record_list *split_record_list (char *s, char *prefix,
				       struct record_list *list);
void print_nullify (char type);
