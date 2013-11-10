

struct s_idx_columns {

	string columnName<>;
	int datatype;
	int size;
};

struct s_idx_table {
	int tabid;
	int partnum;
	string tablename<>;
	struct s_idx_columns columns<>;
};


struct s_idx_tables {
	struct s_idx_table tables<>;
};
