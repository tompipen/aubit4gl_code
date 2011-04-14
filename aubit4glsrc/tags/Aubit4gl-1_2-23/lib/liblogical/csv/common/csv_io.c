#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_io.h"
#include "a4gl_lle.h"

void msgbox (char *title, char *txt) ;



static void csv_write_int(FILE *fout, int val) {
		fwrite(&val,sizeof(int),1,fout);
}

static void csv_write_string(FILE *fout, char *val) {
	if (val==0) {
		csv_write_int(fout,-1);
		return;
	}
	csv_write_int(fout,strlen(val));
	if (strlen(val)) {
		fwrite(val,strlen(val),1,fout);
	}
	return;
}


static int csv_read_int(FILE *fin) {
	int a;
	fread(&a,sizeof(int),1,fin);
	return a;
}

static char *csv_read_string(FILE *fin) {
int len;
char *ptr;
	len=csv_read_int(fin);
	if (len==-1) return 0;
	if (len==0) return strdup("");
	ptr=malloc(len+1);
	fread(ptr,len,1,fin);
	ptr[len]=0;
	return ptr;
	
}



//extern int rbs;
//extern struct s_rbx *rbx;

int write_csv(FILE *fout,struct csv_report_layout *csv_report_layout) {
	int a;
	int x;
	int y;
	struct csv_entry *centry;



	csv_write_int(fout, csv_report_layout->nblocks);
	for (a=0;a<csv_report_layout->nblocks;a++) {
		csv_write_int(fout, csv_report_layout->blocks[a].nrows);
		csv_write_int(fout, csv_report_layout->blocks[a].ncols);


		for (y=0;y<csv_report_layout->blocks[a].nrows;y++) {
			for (x=0;x<csv_report_layout->blocks[a].ncols;x++) {
				centry=csv_report_layout->blocks[a].matrix[y];
				if (centry[x].rb>=0) {
					//printf("Writing : x=%d y=%d rb=%d entry=%d\n",x,y,centry[x].rb,centry[x].entry);
					csv_write_int(fout,x);
					csv_write_int(fout,y);
					csv_write_int(fout,centry[x].rb);
					csv_write_int(fout,centry[x].entry);
					csv_write_string(fout, centry[x].fixed_text);
				}
			}
		}
		x=-1;
		y=-1;
		csv_write_int(fout, x);
		csv_write_int(fout, y);
	}
return 1;
}


struct csv_report_layout *read_csv(FILE *fin) {
	int a;
	int x;
	int y;
	struct csv_entry *entry;
	static struct csv_report_layout csv_report_layout;

	csv_report_layout.nblocks=csv_read_int(fin);
	csv_report_layout.blocks=acl_malloc2(sizeof(struct csv_blocks)*csv_report_layout.nblocks);

	for (a=0;a<csv_report_layout.nblocks;a++) {
		csv_report_layout.blocks[a].nrows=csv_read_int(fin);
		csv_report_layout.blocks[a].ncols=csv_read_int(fin);
		if (csv_report_layout.blocks[a].nrows==0) {
			csv_report_layout.blocks[a].matrix=0;
		} else {
			csv_report_layout.blocks[a].matrix=acl_malloc2(sizeof(struct csv_entry *)*csv_report_layout.blocks[a].nrows);
		

			for (y=0;y<csv_report_layout.blocks[a].nrows;y++) {
				csv_report_layout.blocks[a].matrix[y]=acl_malloc2(sizeof(struct csv_entry)*csv_report_layout.blocks[a].ncols);
			}
	
	
			for (y=0;y<csv_report_layout.blocks[a].nrows;y++) {
				entry=csv_report_layout.blocks[a].matrix[y];
				for (x=0;x<csv_report_layout.blocks[a].ncols;x++) {
					entry[x].rb=-1;
					entry[x].entry=-1;
					entry[x].special=0;
					entry[x].last_value=0;
                        		entry[x].fixed_text=0;
				}
			}
			
		
	
			while (1) {
				x=csv_read_int(fin);
				y=csv_read_int(fin);

				if (y>csv_report_layout.blocks[a].nrows) {
					return 0;
				}
				if (x>csv_report_layout.blocks[a].ncols) {
					return 0;
				}

				if (x==-1&&y==-1) break;
	
			 	entry=csv_report_layout.blocks[a].matrix[y];
			 	entry[x].rb=csv_read_int(fin);
			 	entry[x].entry=csv_read_int(fin);
			 	entry[x].fixed_text=csv_read_string(fin);
			}
		}
	}
	return &csv_report_layout;
}




struct csv_report_layout *default_csv(char *errbuff,void *vrbx,int rbs) {
int a;
int b;
int every=-1;
int n;
struct s_rbx *rbx;

static struct csv_report_layout csv_report_layout;
struct csv_entry *entry;
rbx=vrbx;



  for (a = 0; a < rbs; a++)
    {
	if (rbx[a].where=='E') every=a;
    }

   if (every==-1) {
		strcpy(errbuff,"There does not appear to be an on every row in this report.\n" 
				"It is not currently possible to generate a default CS output for a report with no ON EVERY ROW...");
		return 0;
   }
		
  //printf("Every=%d\n",every);
  csv_report_layout.nblocks=rbs;
  csv_report_layout.blocks=acl_malloc2(sizeof(struct csv_blocks)*csv_report_layout.nblocks);

  for (a=0;a<rbs;a++) {
	if (a!=every) {
  		csv_report_layout.blocks[a].nrows=0;
  		csv_report_layout.blocks[a].ncols=10;
	}  else {
  		csv_report_layout.blocks[a].ncols=10;
  		csv_report_layout.blocks[a].nrows=1;
	}
  }


  n=0;

  csv_report_layout.blocks[every].matrix=acl_malloc2(sizeof(struct csv_entry *)*1);
  csv_report_layout.blocks[every].matrix[0]=0;
  for (a = 0; a < rbs; a++)
    {
      	//printf ("%d %d %c %s \n", a, rbx[a].rb, rbx[a].where, rbx[a].why);
      	//printf ("%d entries to print of %d..\n", rbx[a].nentry_nos, rbx[a].max_entry);


	if (rbx[a].where=='B'|| rbx[a].where=='E') {
		//printf("Add - its a before or on every row...\n");
		for (b=0;b<rbx[a].nentry_nos;b++) {
			if (rbx[a].max_size_entry[b]) n++;
			csv_report_layout.blocks[every].matrix[0]=acl_realloc( csv_report_layout.blocks[every].matrix[0], sizeof(struct csv_entry)*n);
  			entry=csv_report_layout.blocks[every].matrix[0];
			//printf("Entry %d - %d/%d\n",n-1,rbx[a].rb,rbx[a].entry_nos[b]);
                        entry[n-1].rb=rbx[a].rb;
                        entry[n-1].entry=rbx[a].entry_nos[b];
                        entry[n-1].special=0;
                        entry[n-1].last_value=0;
                        entry[n-1].fixed_text=0;
		}
	} else {
		//printf("Ignore block\n");
	}
    }
    csv_report_layout.blocks[every].ncols=n;
//printf("All done\n");
return &csv_report_layout;
}


void msgbox (char *title, char *txt) {
	return;
}

