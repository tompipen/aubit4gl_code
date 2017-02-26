#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../common/a4gl_lle.h"
#include "API_process.h"
int ispipe;

//int A4GLLOGREPPROC_initlib (void);
//int A4GL_setenv (char *v, char *val, int overwrite);
//static int do_we_have(char *s) ;
//static char * find_default_filter(char *rtype) ;

// The report itself
//static struct r_report *report=NULL;


// Summary information
int rbs;
struct s_rbx *rbx = 0;
char *pipecmd = 0;
char *running_program=0;


int
main (int argc, char *argv[])
{
  FILE *fin_filter;
  char buff[256];

printf("Dump lrf\n");

if (argc!=3) {
	fprintf(stderr,"Usage: %s inputfile outputfile\n",argv[0]);
	exit(2);
}




char rname[200];
char mname[200];
char fname[200];
char ltype[200];
      if (!load_filter_file_header_info (argv[1], &fin_filter, buff, rname, mname, ltype, fname))
	{
	  printf ("Unable to open filter file : %s\n", buff);
	  printf("Ensure environment variable LOGREP is set to the type of file (CSV, PDF)\n");
	  exit (2);
	}

      A4GL_setenv ("LOGREP", ltype, 1);

/*
      if (!RP_load_file (report, fin_filter))
	{
	  printf ("Unable to open filter file : %s\n", buff);
	  exit (2);
	} */
FILE *fout;
fout=fopen(argv[2],"w");
fprintf(fout,"%s|%s|%s|%s\n", ltype, rname,mname,fname);
     if (RP_dump_file(fin_filter, fout)) {
		printf("Complete..\n");
	}
return 0;
}

