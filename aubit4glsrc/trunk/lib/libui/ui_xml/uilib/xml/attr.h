#define attr_min(X,Y) (((X) < (Y)) ? (X) : (Y))

struct s_syncvalues {
	int nvalues;
	char **vals;
};

struct s_row {
	int rownum;
	struct s_syncvalues sync;
};

struct s_rows {
	int nrows;
	struct s_row *row;
};

struct s_attr {
	char *id;
	char *data;
	char *type;
	struct s_syncvalues sync;
	struct s_rows rows;
	int arrline;
	int scrline;
	int arrcount;
} ;


struct s_attr *xml_parse (char *s) ;
void dump_attr(struct s_attr *a);
int my_yyinput(char *buf,int maxsize);
