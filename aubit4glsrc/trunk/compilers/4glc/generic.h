struct generic_entry_ident {
        char identifier[256];
};

struct generic_entry_variable {
        char variable_name[256];
        int is_record;
        int is_array;
        int subscripts[10];
        int dtype;
        int dim;
        int substr[2];
};

struct generic_entry_literal {
        char type;
        union  {
                char *  s;
                double  d;
                int     i;
        } data;
};


struct generic_entry_expression2 {
        struct generic_entry *lhs;
        char op;
        struct generic_entry *rhs;
};

struct generic_entry_expression1 {
        struct generic_entry *lhs;
        char op;
};

struct generic_entry_expression_f {
        char function_name[256];
        struct generic_entry_list *operands;
};


struct generic_entry_expression {
        char type;
        union {
                struct generic_entry_expression1 *e1;
                struct generic_entry_expression1 *e2;
                struct generic_entry_expression1 *ef;
        } data;
};

struct generic_entry {
        char type;
        union {
                struct generic_entry_ident *ident;
                struct generic_entry_variable *variable;
                struct generic_entry_literal *literal;
                struct generic_entry_list *list;
                struct generic_entry_expression *expr;
        } data;
};

struct generic_entry_list {
        struct generic_entry *entry;
        struct generic_entry_list *next;
};



struct generic_entry_ident *new_ident(char *identifier) ;
struct generic_entry_variable *new_variable(void) ;
struct generic_entry_literal *new_literal(char type,char *ptr) ;
struct generic_entry_expression2* new_expression2(struct generic_entry *l,struct generic_entry *r,char op) ;
struct generic_entry_expression1* new_expression1(struct generic_entry *l,char op) ;
struct generic_entry_expression_f * new_functioncall(char *functionname,struct generic_entry_list *l) ;
struct generic_entry_expression * new_expression(char type,void *expr) ;
struct generic_entry *new_entry(char type,void *entry) ;
struct generic_entry_list *new_list(struct generic_entry *entry) ;
void append_list(struct generic_entry_list *orig,struct generic_entry *entry);
