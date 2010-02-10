#include <stdio.h>

struct variable_element {
char * name;
char *dtype;
int isOptional;
long i_arr_size[3];
short unit_size;
long total_size;
long offset;
struct {
 unsigned int next_len;
 struct variable_element * next_val;
} next;
};
typedef struct variable_element variable_element; /* XX */

struct enum_element {
	char *element;
	int n;
};


struct enum_elements {
	int nelements;
	struct enum_element **elements;
};


enum var_category {
        CAT_NULL = 0,
        CAT_NORMAL = 1,
        CAT_STATIC = 2,
        CAT_EXTERN = 3,
        CAT_ALLOC = 4,
        CAT_ALLOC_STATIC = 5,
        CAT_ALLOC_EXTERN = 6,
        CAT_SUBSTRUCT = 7,
        CAT_PARAMETER = 8,
        CAT_PARAMETER_SET = 9,
};


struct npvariable {
        long variable_id;
        long def_block;
        enum var_category category;
        struct variable_element *var;
};
typedef struct npvariable npvariable;


struct define_variables
{
  int singleton;
  int var_len;
  struct variable_element *var_val;
};

void make_named_enum(char * name, struct enum_elements *elem_list);
struct define_variables *add_named_struct (char *s);
struct variable_element *new_variable_struct (struct define_variables *v,char *struct_name);
FILE *getOuputFile(void );
void *acl_malloc2(int n);
struct variable_element *new_variable_element_string (char *s);
struct enum_elements *append_enum_element(struct enum_elements *elem_list, struct enum_element *elem);
struct enum_element * new_enum_element(char *name, int value) ;

void make_named_struct (char *name, struct define_variables *v,int singleton);
void replace_named_struct(char *s,struct define_variables *v) ;
int has_named_struct (char *s);
int has_named_enum(char *s);
struct define_variables *add_variables(struct define_variables *v, struct variable_element * elem) ;
void add_variable (int type, struct variable_element *e, char *id, long set_i);
void add_function_definition(struct variable_element *rettype, char *s,struct define_variables *params);
void add_variable_array (int type, struct variable_element *e, char *id, long *arrsize, long set);



#define DCHAR   0
#define DSTRING 1
#define DINT    2
#define DLONG   3
#define DPTR    4
#define DDEC    5
#define DMON    6
#define DVOID   7
#define DLONGPTR   8
#define DSHORTPTR   9
#define DDBL    10
#define DDTIME 11

#define DBLOCK  126
#define DSTRUCT 127
#define DUNKNOWN -1

