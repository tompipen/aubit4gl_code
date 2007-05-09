#include <stdio.h>


struct csv_entry {
	int rb;
	int entry;
	char *special;
	char *last_value;
	char *fixed_text;
};

struct csv_blocks {
	int nrows;
	int ncols;
	struct csv_entry **matrix;
};

struct csv_report_layout {
	int nblocks;
	struct csv_blocks *blocks;
};

int write_csv(FILE *fout,struct csv_report_layout *out);
struct csv_report_layout *read_csv(FILE *fin);
struct csv_report_layout *default_csv(char *errbuff,void *rbx,int rbs);
