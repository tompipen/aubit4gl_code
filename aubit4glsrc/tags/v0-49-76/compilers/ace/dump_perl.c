#include <stdlib.h>
#include <stdio.h>
void A4GL_bname (char *str, char *str1, char *str2);

int compile_ace_report (char *filename);
int conv_out (char *fname);

int
main (int argc, char *argv[])
{
  int rval;

  if (argc != 2)
    {
      printf ("Usage:\n%s ace-report.ace\n", argv[0]);
      exit (1);
    }

  A4GL_build_user_resources ();

  A4GL_setenv ("A4GL_PACKER","PERL",1);

  rval = compile_ace_report (argv[1]);
  printf ("Got rval as %d\n", rval);

  if (rval == 0)
    {
      printf ("Report compiled OK\nConverting to perl program\n");
      exit (conv_out (argv[1]));
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
  int ch;
  char c[256];
  char b[256];
  char a[256];
  strcpy (c, fname);
  A4GL_bname (c, a, b);

  sprintf (buff, "%s.aarc.pl", a);
  f_in = fopen (buff, "r");

  if (f_in == 0)
    {
      printf ("Unable to open generated output file %s\n", buff);
      return 0;
    }

  sprintf (buff, "%s.run.pl", a);
  f_out = fopen (buff, "w");

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
  return 1;
}
