
struct s_section_item {
	int type;
	char *data;
};


struct s_section_entry {
	int nitems;
	struct s_section_item **items;
};

struct s_section_list {
	int nitems;
	struct s_section_entry **items;
};

struct s_parse_entry {
	char *name;
	struct s_section_list *item;
	int printed;
	char *calledby; /* first rule to call this rule */
	char *result;
} ;


struct s_parser_start {
	int nitems;
	struct s_parse_entry **items;
};




struct s_parser_start *new_parser_start  (struct s_parser_start *list, struct s_parse_entry *a1) ;
struct s_parse_entry *new_parse_entry    (char *name,struct s_section_list *a2) ;
struct s_section_list *new_section_list  (struct s_section_list *list, 	struct s_section_entry *a1) ;
struct s_section_entry *new_section_entry(struct s_section_entry *list, struct s_section_item *a1) ;

struct s_section_item *new_section_item__1(char *s) ;
struct s_section_item *new_section_item__2(char *s) ;

