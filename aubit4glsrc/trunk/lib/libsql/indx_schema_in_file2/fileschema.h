
struct s_idx_columns {
	char columnName[128];
	int datatype;
	int size;
};

struct s_idx_table {
int tabid;
int partnum;
char tablename[128];
struct {
 unsigned int columns_len;
 struct s_idx_columns * columns_val;
} columns;
};

struct s_idx_tables {
struct {
 unsigned int tables_len;
 struct s_idx_table * tables_val;
} tables;
};




int write_s_idx_tables(struct s_idx_tables *s,char *filename) ;
int read_s_idx_tables(struct s_idx_tables *s,char *filename) ;

