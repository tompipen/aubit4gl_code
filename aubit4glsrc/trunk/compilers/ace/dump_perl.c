#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void A4GL_bname (char *str, char *str1, char *str2);

int compile_ace_report (char *filename);
int conv_out (char *fname);
void show_usage(char *argv0) ;

int
main (int argc, char *argv[])
{
  int rval;

  if (argc != 2)
    {
	show_usage(argv[0]);
      	exit (1);
    }

  if (strstr(argv[1],".aarc") || strcmp(argv[1],"-?")==0 || strcmp(argv[1],"-h")==0 ) {
		show_usage(argv[0]);
		exit(1);
  }

  A4GL_build_user_resources ();

  A4GL_setenv ("A4GL_PACKER","PERL",1);
  rval = compile_ace_report (argv[1]);

  if (rval == 0)
    {
      printf ("Report compiled OK\nConverting to perl program\n");
      if (conv_out (argv[1])) {
		printf("Generated code ok\n");
		exit(0);
	} else {
		printf("Failed to generate code\n");
		exit(1);
	}
    }
  else
    {
      printf ("Report did not compile - not converting\n");
      exit (1);
    }

}

int
conv_out (char *fname)
{
  FILE *f_in;
  FILE *f_out;
  char buff[256];
  char inbuff[256];
  int ch;
  char c[256];
  char b[256];
  char a[256];
  strcpy (c, fname);
  A4GL_bname (c, a, b);

  if (strlen(a)) {
  	sprintf (inbuff, "%s.aarc.pl", a);
  	sprintf (buff, "%s.run.pl", a);
  } else {
  	sprintf (inbuff, "%s.aarc.pl", b);
  	sprintf (buff, "%s.run.pl", b);
  }
  f_in = fopen (inbuff, "r");

  if (f_in == 0)
    {
      printf ("Unable to open generated output file %s\n", inbuff);
      return 0;
    }

  f_out = fopen (buff, "w");
  if (f_out==0) {
      printf ("Unable to open generated output file %s\n", buff);
      return 0;
  }

  fprintf (f_out, "#!/usr/local/bin/perl  -w\n");
  fprintf (f_out, "use DBI;\n");
  fprintf (f_out, "require report;\n\n");

  while (1)
    {
      ch = fgetc (f_in);
      if (feof (f_in))
	break;
      fputc (ch, f_out);
    }

  fprintf (f_out, "\n\nreport::run_report(\\%%report);\n\n");
  fclose (f_in);
  fclose (f_out);
  unlink(inbuff);
  return 1;
}


void show_usage(char *argv0) {
      	printf ("Usage:\n   %s ace-report.ace\n", argv0);
      	printf("\nNOTE : This program will *compile* the from the source '.ace' file.\n");
	printf("it ***does not*** accept a .aarc file as a parameter\n");
}
