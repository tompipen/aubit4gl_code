
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


static void trimnl (char *s)
{
  int a;
  for (a = strlen (s) - 1; a > 0; a--)
    {
      if (A4GL_isblank (s[a])||s[a]=='\n' || s[a]=='\r' ) s[a]=0;
        else break;
    }
}

int
main (int argc, char *argv[])
{
  FILE *fin_filter;
  char buff[2560];

printf("import lrf %d\n",argc);

if (argc!=3) {
	fprintf(stderr,"Usage: %s inputfile outputfile\n",argv[0]);
	exit(2);
}




      /*
      if (!RP_load_file (report, fin_filter))
	{
	  printf ("Unable to open filter file : %s\n", buff);
	  exit (2);
	} */
fin_filter=fopen(argv[1],"r");
fgets(buff,sizeof(buff), fin_filter);
trimnl(buff);
int nrecords;
char **fields;
fields=RP_split_on_delimiter(buff,&nrecords);
char *ltype;
char *rname;
char *mname;
char *fname;
ltype=fields[0];
rname=fields[1];
mname=fields[2];
fname=fields[3];
FILE *fout;
fout=fopen(argv[2],"w");
      A4GL_setenv ("LOGREP", ltype, 1);
      fprintf (fout, "A4GL_LOGICAL_REPORT %s\n", ltype);
      fprintf (fout, "%s %s\n",rname, mname);
      fprintf (fout, "%s\n", fname);

     if (RP_import_file(fin_filter, fout)) {
		fclose(fout);
		printf("Complete..\n");
	}
return 0;
}

