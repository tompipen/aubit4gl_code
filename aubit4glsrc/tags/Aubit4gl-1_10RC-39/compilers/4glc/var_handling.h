/*

struct variable_usage {
	char *variable_name;

	int nsubscripts;
	expr_str *subscripts[10];
	int nsubstrings;
	expr_str *substrings[2];
	
	int variable_id;
	int scope;
	struct variable_usage *next;
};
*/

/*
struct num_list {
	char *num;
	struct num_list *next;
};
*/


struct array_list {
	struct expr_str_list *array;
	struct expr_str_list *substr;
	struct expr_str *assoc_var;
};

struct variable_usage *new_variable_usage (struct variable_usage *old, char *partname,char prepend) ;
void set_variable_usage_subscript(struct variable_usage *var,int sub,expr_str *val) ;
void set_variable_usage_substr(struct variable_usage *var,int sub,expr_str *val) ;
char *variable_usage_as_string(struct variable_usage *var,int ident);
//struct num_list *new_num_list_item(char *s);
//struct num_list *append_num_list(struct num_list *list, struct num_list *next) ;
struct variable_usage *append_variable_usage (struct variable_usage *old, struct variable_usage *new_usg);
//struct num_list *append_num_list_items(struct num_list *list, struct num_list *next);


#define VAR_USG_ANY 		0
#define VAR_USG_VARIABLE 	1
#define VAR_USG_IDENT 		2
#define VAR_USG_SIMPLE 		99


