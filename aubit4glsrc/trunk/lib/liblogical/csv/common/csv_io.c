#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_io.h"
#include "a4gl_lle.h"



//extern int rbs;
//extern struct s_rbx *rbx;

int write_csv(FILE *fout,struct csv_report_layout *csv_report_layout) {
	int a;
	int x;
	int y;
	struct csv_entry *centry;



	fwrite(&csv_report_layout->nblocks,sizeof(int),1,fout);
	for (a=0;a<csv_report_layout->nblocks;a++) {
		fwrite(&csv_report_layout->blocks[a].nrows,sizeof(int),1,fout);
		fwrite(&csv_report_layout->blocks[a].ncols,sizeof(int),1,fout);


		for (y=0;y<csv_report_layout->blocks[a].nrows;y++) {
			for (x=0;x<csv_report_layout->blocks[a].ncols;x++) {
				centry=csv_report_layout->blocks[a].matrix[y];
				if (centry[x].rb>=0) {
					//printf("Writing : x=%d y=%d rb=%d entry=%d\n",x,y,centry[x].rb,centry[x].entry);
					fwrite(&x,sizeof(int),1,fout);
					fwrite(&y,sizeof(int),1,fout);
					fwrite(&centry[x].rb,sizeof(int),1,fout);
					fwrite(&centry[x].entry,sizeof(int),1,fout);
				}
			}
		}
		x=-1;
		y=-1;
		fwrite(&x,sizeof(int),1,fout);
		fwrite(&y,sizeof(int),1,fout);
	}
return 1;
}


struct csv_report_layout *read_csv(FILE *fin) {
	int a;
	int x;
	int y;
	struct csv_entry *entry;
	static struct csv_report_layout csv_report_layout;

	fread(&csv_report_layout.nblocks,sizeof(int),1,fin);
	csv_report_layout.blocks=malloc(sizeof(struct csv_blocks)*csv_report_layout.nblocks);

	for (a=0;a<csv_report_layout.nblocks;a++) {
		fread(&csv_report_layout.blocks[a].nrows,sizeof(int),1,fin);
		fread(&csv_report_layout.blocks[a].ncols,sizeof(int),1,fin);
		if (csv_report_layout.blocks[a].nrows==0) {
			csv_report_layout.blocks[a].matrix=0;
		} else {
			csv_report_layout.blocks[a].matrix=malloc(sizeof(struct csv_entry *)*csv_report_layout.blocks[a].nrows);
		

			for (y=0;y<csv_report_layout.blocks[a].nrows;y++) {
				csv_report_layout.blocks[a].matrix[y]=malloc(sizeof(struct csv_entry)*csv_report_layout.blocks[a].ncols);
			}
	
	
			for (y=0;y<csv_report_layout.blocks[a].nrows;y++) {
				entry=csv_report_layout.blocks[a].matrix[y];
				for (x=0;x<csv_report_layout.blocks[a].ncols;x++) {
					entry[x].rb=-1;
					entry[x].entry=-1;
					entry[x].special=0;
					entry[x].last_value=0;
				}
			}
			
		
	
			while (1) {
				fread(&x,sizeof(int),1,fin);
				fread(&y,sizeof(int),1,fin);
				if (y>csv_report_layout.blocks[a].nrows) {
					return 0;
				}
				if (x>csv_report_layout.blocks[a].ncols) {
					return 0;
				}
				if (x==-1&&y==-1) break;
	
			 	entry=csv_report_layout.blocks[a].matrix[y];
			 	fread(&entry[x].rb,sizeof(int),1,fin);
			 	fread(&entry[x].entry,sizeof(int),1,fin);
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
  csv_report_layout.blocks=malloc(sizeof(struct csv_blocks)*csv_report_layout.nblocks);

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

  csv_report_layout.blocks[every].matrix=malloc(sizeof(struct csv_entry *)*1);
  csv_report_layout.blocks[every].matrix[0]=0;
  for (a = 0; a < rbs; a++)
    {
      	//printf ("%d %d %c %s \n", a, rbx[a].rb, rbx[a].where, rbx[a].why);
      	//printf ("%d entries to print of %d..\n", rbx[a].nentry_nos, rbx[a].max_entry);


	if (rbx[a].where=='B'|| rbx[a].where=='E') {
		//printf("Add - its a before or on every row...\n");
		for (b=0;b<rbx[a].nentry_nos;b++) {
			if (rbx[a].max_size_entry[b]) n++;
			csv_report_layout.blocks[every].matrix[0]=realloc( csv_report_layout.blocks[every].matrix[0], sizeof(struct csv_entry)*n);
  			entry=csv_report_layout.blocks[every].matrix[0];
			//printf("Entry %d - %d/%d\n",n-1,rbx[a].rb,rbx[a].entry_nos[b]);
                        entry[n-1].rb=rbx[a].rb;
                        entry[n-1].entry=rbx[a].entry_nos[b];
                        entry[n-1].special=0;
                        entry[n-1].last_value=0;
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

