#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../common/a4gl_lle.h"
#include "API_process.h"
int A4GLLOGREPPROC_initlib (void);
int A4GL_setenv(char *v,char *val,int overwrite);

// The report itself
struct r_report *report;


// Summary information
int rbs;
struct s_rbx *rbx = 0;


int main(int argc,char *argv[]) {
FILE *fin_filter;
char buff[256];
char errbuff[1024]="";
int off=0;
char *ofile="";
int random_name=1;


if (strcmp(argv[1],"-o")==0) {
  	ofile=argv[2];
	off=2;
	random_name=0;
} 


if (argc-off != 4 && argc-off!=3 )
    {
      printf ("Usage %s [ -o output ] type report-file-name [filter-file-name]\n", argv[0]);
      exit (1);
    }

  if (strcmp(argv[1+off],"SAVE")==0 ) {
		int a;
		// We just want to copy from report-file-name to output...
		FILE *fin;
		FILE *fout;
		fin=fopen(argv[2+off],"r");
		if (fin==0) {
			printf("Unable to open report output\n");	
			exit(2);
		}
		if (!strlen(ofile)) {
			printf("No output filename, use -o output\n");
			exit(1);
		}

		fout=fopen(ofile,"w");
		while (!feof(fin)) {
			a=fgetc(fin);
			if (feof(fin)) break;
			fputc(a,fout); // Slow - but it'll do for now..
		}
		fclose(fin);
		fclose(fout);
		exit(0);
  }
	

  report = read_report_output (argv[2+off]);


  if (report == 0)
    {
      printf ("Unable to open report output (%s) \n",argv[2+off]);
      exit (2);
    }


  A4GL_setenv ("LOGREP", argv[1+off], 1);
  A4GLLOGREPPROC_initlib();


// We may not always need to do this - but for now...

  obtain_rbs_rbx(report,&rbs,&rbx);



  if (argc-off==4) {
		if (!load_filter_file_header(argv[3+off], &fin_filter, buff)) {
			printf("Unable to open filter file : %s\n",buff);
			exit(2);
		}
		if (!RP_load_file(fin_filter)) {
			printf("Unable to open filter file : %s\n",buff);
			exit(2);
		}
  } else {
	if (!RP_default_file(errbuff)) {
		printf("No default file could be generated :\n%s\n",errbuff);
		exit(2);
	}
  }

  // at this point - we've loaded the report, and the backend should have a filter...




  strcpy(buff,ofile);

  if (RP_process_report(buff)) {
	if (random_name)      printf("OK - output should be in %s\n",buff);
  } else {
	printf("Failed to process\n");
	exit(1);
  }
  exit(0);
}


