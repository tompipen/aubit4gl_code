

struct variable *new_simple_variable(char *name, int dtype, int scale1, int scale2);
struct variable_list *append_variable_list(struct variable_list *list, struct variable *ptr);
struct variable *make_new_type(char *name, struct variable *definition);
struct variable_list *new_variable_list(struct variable *ptr);
struct variable_list *merge_variable_list(struct variable_list *list, struct variable_list *list2);
struct variable * new_constant (char int_or_char, char *value, char *name);
struct variable *new_variable_pushLikeAllTableColumns(char *tabname,str_list *linked_to_list);
struct variable *new_variable_record(char *name, struct variable_list *vlist);
struct variable *new_variable_pushLikeTableColumn(char *tabname,char *colname);
struct variable *new_variable_like(char *tabcol);
struct variable *new_associate_variable(int assoc_char_size,int assoc_arr_size,struct variable *ptr);
struct variable *new_variable_dim(char *name);
struct variable *new_variable_object(char *name);
void set_variable_name(struct variable *ptr, char *name);
struct variable_list *create_variable_list(str_list *name_list,struct variable *var);
void set_variable_scope_for_variable_list(variable_list *list,enum e_scope escope);
