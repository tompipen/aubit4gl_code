//char *A4GL_strip_quotes(char *s);

struct s_pos_list {
	int start;
	int end;
	int sz;
};

struct s_nposlist {
	int npos;
	struct s_pos_list **list_of_character_positions;
	int memsz;
};

struct s_field_pos {
	char *name;
	char *null;
	struct s_nposlist *pos_list;
};

struct s_field_pos_list { 
	struct s_field_pos **pos;
	int npos;
};

struct filedef {
	int type;
	char *fname;
	char *delim;
	int nfields;
	struct s_field_pos_list *field_pos_list;
	
};


struct insert {
	char *tabname;
	char *colexpr;
};

struct s_dbloadline {
	struct filedef *f;
	struct insert *i;
};

#ifndef A4GL_debug
#define A4GL_debug A4GL_set_line(__FILE__,__LINE__);A4GL_debug_full
#endif
int is_column_name(char *s);
char *conv_dbl(char *s);
int process_entry (struct s_dbloadline *dbload);
void a4gl_dbload_yyerror(char *s);
int a4gl_dbload_yylex (void);
int parse(char *lv_cmd_file);
