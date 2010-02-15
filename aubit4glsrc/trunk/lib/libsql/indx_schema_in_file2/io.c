#include<stdio.h>
#include <stdlib.h>
#include "fileschema.h"


int write_s_idx_tables(struct s_idx_tables *s,char *filename) {
FILE *f;
int a;
f=fopen(filename,"w");
if (f==0) {
	fprintf(stderr,"Unable to open output file : %s\n",filename);
	return 0;
}

// First - lets say how many tables there are...
fwrite(&s->tables.tables_len,sizeof(s->tables.tables_len),1,f);

// Now write a record for each table
// this will include the pointer to the columns array which will always
// be junk when we read the file back in
//
// So - we'll need to write those columns separately afterwards..
fwrite(s->tables.tables_val, sizeof(s->tables.tables_val[0]),s->tables.tables_len,f);

// Now - the columns need to be written...
for (a=0;a<s->tables.tables_len;a++) {
	fwrite(s->tables.tables_val[a].columns.columns_val, 
			sizeof(s->tables.tables_val[0].columns.columns_val[0]),
			s->tables.tables_val[a].columns.columns_len,f);
}

fclose(f);
return 1;
}



int read_s_idx_tables(struct s_idx_tables *s,char *filename) {
FILE *f;
int a;
f=fopen(filename,"r");
if (f==0) {
	// Couldn't open the file...
	return 0;
}

fread(&s->tables.tables_len,sizeof(s->tables.tables_len),1,f);
s->tables.tables_val=malloc(sizeof(s->tables.tables_val[0])*s->tables.tables_len);
fread(s->tables.tables_val, sizeof(s->tables.tables_val[0]),s->tables.tables_len,f);

for (a=0;a<s->tables.tables_len;a++) {
		s->tables.tables_val[a].columns.columns_val=malloc(sizeof(s->tables.tables_val[a].columns.columns_val[0])*s->tables.tables_val[a].columns.columns_len);
	fread(s->tables.tables_val[a].columns.columns_val, 
			sizeof(s->tables.tables_val[0].columns.columns_val[0]),
			s->tables.tables_val[a].columns.columns_len,f);
}


fclose(f);
return 1;
}
