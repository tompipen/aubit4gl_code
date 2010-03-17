
struct s_vname {
	int is_ptr;
	int is_array;
	int is_vararray;
	char *name;
};

struct s_dtype {
	int isvoid;
	int isunion;
	int isstruct;
	int isenum;
	int isunknown;

	char *type;
};


struct s_element {
	struct s_dtype datatype;
	struct s_vname vname;
	char *switch_on;
};

struct s_elements {
	char *union_or_struct_name;
	int nelements;
	struct s_element *elements;
	char *union_switch_on_enum_type;
	char *union_switch_on_enum_name;
	int usesAttributes;
	int usesElements;
};


struct s_enum {
	char *enum_name;
	struct s_enum_element *elements;
	int nelements;
};

struct s_enum_element {
	char *element_name;
	int val;
};
