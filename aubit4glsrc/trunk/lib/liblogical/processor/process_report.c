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

  if (argc != 4 && argc!=3 )
    {
      printf ("Usage %s type report-file-name [filter-file-name]\n", argv[0]);
      exit (1);
    }

  report = read_report_output (argv[2]);



  if (report == 0)
    {
      printf ("Unable to open report output\n");
      exit (2);
    }


  A4GL_setenv ("LOGREP", argv[1], 1);
  A4GLLOGREPPROC_initlib();


// We may not always need to do this - but for now...

  obtain_rbs_rbx(report,&rbs,&rbx);



  if (argc==4) {
		if (!load_filter_file_header(argv[3], &fin_filter, buff)) {
			printf("Unable to open filter file : %s\n",buff);
			exit(2);
		}
		if (!RP_load_file(fin_filter)) {
			printf("Unable to open filter file : %s\n",buff);
			exit(2);
		}
  } else {
	if (!RP_default_file()) {
		printf("No default file could be generated\n");
		exit(2);
	}
  }

  // at this point - we've loaded the report, and the backend should have a filter...




  strcpy(buff,"");

  if (RP_process_report(buff)) {
	printf("OK - output should be in %s\n",buff);
  } else {
	printf("Failed to process\n");
	exit(1);
  }
  exit(0);
}


