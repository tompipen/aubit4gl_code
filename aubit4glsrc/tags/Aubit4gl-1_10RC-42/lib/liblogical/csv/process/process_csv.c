#include <stdio.h>
#define  _NO_WINDOWS_H_
#define NOSTRCPYMAP
#include "a4gl_libaubit4gl.h"
#include "../common/csv_io.h"
#include "../../common/a4gl_lle.h"
#include "../../processor/API_process.h"

//extern int rbs;
//extern struct s_rbx *rbx;

struct csv_report_layout *layout;

FILE *rep_fout=0;


int A4GLLOGREP_PROC_initlib() {
	return 1;
}



int RP_default_file(void *report, char *buff,void *rbx,int rbs) {
	layout=default_csv(buff,rbx,rbs);
	if (layout) return 1;
	else return 0;
}



int RP_load_file(void *report, FILE* fin) {
	layout=read_csv(fin);
	if (layout==0) {return 0;}
	return 1;
}


void start_block(int rb) {
int x;
int y;
int a;
struct csv_blocks *block;
struct csv_entry *centry;

//printf("Start block %d\n",rb);

for (a=0;a<layout->nblocks;a++) {
	block=&layout->blocks[a];
	// Lets clear everything down...
	for (y=0;y<block->nrows;y++) {
		centry=block->matrix[y];
		for (x=0;x<block->ncols;x++) {
			if (centry[x].rb==rb) {
				centry[x].special=0;
			}
			if (centry[x].fixed_text) {
				centry[x].special=centry[x].fixed_text;
			}

		}
	}
}

}

void end_block(int rb,struct s_rbx *rbx) {
int a;
int x;
int y;
int last;
struct csv_blocks *block;
struct csv_entry *centry;

//printf("End block %d\n",rb);

// First - we need to find our block to print...
for (a=0;a<layout->nblocks;a++) {
	if (rbx[a].rb!=rb) continue;

	block=&layout->blocks[a];

	// We may nee to print somethings...
	for (y=0;y<block->nrows;y++) {
		centry=block->matrix[y];
		last=0;

		// First - find out how many cells are actually used...
		for (x=0;x<block->ncols;x++) {
			
				if (centry[x].special && strlen(centry[x].special) && centry[x].rb>=0 && centry[x].entry>=0) {
					last=x;
				}
		}

		
		// Print all of these cells...
		for (x=0;x<=last;x++) {
			if (x) fprintf(rep_fout,",");
			/*
			if (x==0 && centry[x].special) {
				printf("%s\n", centry[x].special);
			}
			*/
			if (centry[x].special && strlen(centry[x].special) && centry[x].rb>=0 && centry[x].entry>=0) {
				fprintf(rep_fout,"\"%s\"",centry[x].special);
			} else {
				fprintf(rep_fout,"\"\"");
			}
		}
		fprintf(rep_fout,"\n");
	}
}

// Now clear down our data from wherever it was set...
#ifdef DONT_USE
for (a=0;a<layout->nblocks;a++) {
	block=&layout->blocks[a];
	// Lets clear everything down...
	for (y=0;y<block->nrows;y++) {
		centry=block->matrix[y];
		for (x=0;x<block->ncols;x++) {
			centry[x].special=0;
		}
	}
}
#endif

}


void process_block(int block_id,int entry_id,char *s) {
int a;
int x;
int y;
struct csv_blocks *block;
struct csv_entry *centry;


for (a=0;a<layout->nblocks;a++) {
	block=&layout->blocks[a];
	for (y=0;y<block->nrows;y++) {
		centry=block->matrix[y];
		for (x=0;x<block->ncols;x++) {
			/*
			if (x==0) {
				printf("%d %d %d %d --> %s\n", centry[x].entry, entry_id,  centry[x].rb, block_id,s);
			}
			*/
			if (centry[x].entry==entry_id && centry[x].rb==block_id) {
				//if (centry[x].special!=NULL) {
					//free(centry[x].special);
					//centry[x].special=NULL;
				//}
				/*
				if (x==0) {
					printf("Setting special to be %s\n", s);
				}
				*/
				centry[x].special=s;
			}
		}
	}
}


}

int RP_process_report(void *vreport, char* buff,void *vrbx,int rbs) {
struct r_report *report;
char fname[1024];
int a;
int b;
struct s_rbx *rbx=0;
rbx=vrbx;
report=vreport;
	rep_fout=0;

	if (layout==0|| report==0) {
		// We're missing something..
		printf("Missing layout or report : Layout=%p report=%p\n",layout,report);
		return 0;
	}

	// buff should contain a filename to store the output in or ""
	if (buff) {
		strcpy(fname,buff);
		A4GL_trim(fname);
	} else {
		strcpy(fname,"");
	}

	if (strlen(fname)==0) {
		tmpnam(fname);
		strcpy(buff,fname);
  		rep_fout=fopen(fname,"w");
	} else {
		if (strcmp(fname,"-")==0) {
  			rep_fout=stdout;
		} else {
  			rep_fout=fopen(fname,"w");
		}
	}


  	if (rep_fout==0) {
		printf("Can't open output : %s\n",fname);
                	return 0;
  	}
	// If we've got to here....

	for (a=0;a<report->nblocks;a++) {
		start_block(report->blocks[a].rb);
		for (b=0;b<report->blocks[a].nentries;b++) {
			process_block(report->blocks[a].rb, report->blocks[a].entries[b].entry_id, report->blocks[a].entries[b].string);
		}
		end_block(report->blocks[a].rb,rbx);
        }

	if (strcmp(buff,"-")!=0) {
		fclose(rep_fout);
	}
	return 1;
}
