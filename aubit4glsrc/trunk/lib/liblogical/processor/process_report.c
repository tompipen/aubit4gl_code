#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../common/a4gl_lle.h"
#include "API_process.h"
int ispipe;

int A4GLLOGREPPROC_initlib (void);
int A4GL_setenv (char *v, char *val, int overwrite);

// The report itself
struct r_report *report;


// Summary information
int rbs;
struct s_rbx *rbx = 0;
char *pipecmd = 0;


int
main (int argc, char *argv[])
{
  FILE *fin_filter;
  char buff[256];
  char errbuff[1024] = "";
  int off = 0;
  char *ofile = "";
  int random_name = 1;


  if (argc > 2)
    {

      if (strcmp (argv[1], "-o") == 0)
	{
	  ofile = argv[2];
	  off = 2;
	  random_name = 0;
	  ispipe = 0;
	}
      if (strcmp (argv[1], "-p") == 0)
	{
	  pipecmd = argv[2];
	  off = 2;
	  random_name = 1;
	  ispipe = 1;
	}



    }

  if (argc - off != 4 && argc - off != 3)
    {
      printf
	("Usage %s [ -o output ] type report-file-name [filter-file-name]\n",
	 argv[0]);
      exit (1);
    }

  if (strcmp (argv[1 + off], "SAVE") == 0)
    {
      int a;
      // We just want to copy from report-file-name to output...
      FILE *fin;
      FILE *fout;
      fin = fopen (argv[2 + off], "r");
      if (fin == 0)
	{
	  printf ("Unable to open report output\n");
	  exit (2);
	}
      if (!strlen (ofile))
	{
	  printf ("No output filename, use -o output\n");
	  exit (1);
	}

      fout = fopen (ofile, "w");
      while (!feof (fin))
	{
	  a = fgetc (fin);
	  if (feof (fin))
	    break;
	  fputc (a, fout);	// Slow - but it'll do for now..
	}
      fclose (fin);
      fclose (fout);
      exit (0);
    }


  report = read_report_output (argv[2 + off]);


  if (report == 0)
    {
      printf ("Unable to open report output (%s) \n", argv[2 + off]);
      exit (2);
    }


  A4GL_setenv ("LOGREP", argv[1 + off], 1);
  A4GLLOGREPPROC_initlib ();


// We may not always need to do this - but for now...

  obtain_rbs_rbx (report, &rbs, &rbx);



  if (argc - off == 4)
    {
      if (!load_filter_file_header (argv[3 + off], &fin_filter, buff))
	{
	  printf ("Unable to open filter file : %s\n", buff);
	  exit (2);
	}
      if (!RP_load_file (report, fin_filter))
	{
	  printf ("Unable to open filter file : %s\n", buff);
	  exit (2);
	}
    }
  else
    {
      FILE *f = 0;
      char default_filter[256];
      strcpy (default_filter, "");

      /* First off - lets see if we can find a specific filter... */
      if (report->max_col <= 80 && strlen (default_filter) == 0)
	{
	  sprintf (default_filter, "%s/lib/default_%s_narrow.lrf",
		   acl_getenv ("AUBITDIR"), argv[1 + off]);
	  A4GL_debug ("Looking for %s\n", default_filter);
	  f = fopen (default_filter, "r");
	}

      if (report->max_col <= 132 && f == 0)
	{
	  sprintf (default_filter, "%s/lib/default_%s_normal.lrf",
		   acl_getenv ("AUBITDIR"), argv[1 + off]);
	  A4GL_debug ("Looking for %s\n", default_filter);
	  f = fopen (default_filter, "r");
	}

      if (report->max_col > 132 && f == 0)
	{
	  sprintf (default_filter, "%s/lib/default_%s_wide.lrf",
		   acl_getenv ("AUBITDIR"), argv[1 + off]);
	  A4GL_debug ("Looking for %s\n", default_filter);
	  f = fopen (default_filter, "r");
	}

      /* Finally - try just a standard default */
      if (f == 0)
	{
	  sprintf (default_filter, "%s/lib/default_%s.lrf",
		   acl_getenv ("AUBITDIR"), argv[1 + off]);
	  A4GL_debug ("Looking for %s\n", default_filter);
	  f = fopen (default_filter, "r");
	}


      if (f != 0)
	{
	  fclose (f);
	  A4GL_debug ("Found %s\n", default_filter);
	  if (!load_filter_file_header (default_filter, &fin_filter, buff))
	    {
	      printf ("Unable to open filter file : %s\n", buff);
	      exit (2);
	    }
	  if (!RP_load_file (report, fin_filter))
	    {
	      printf ("Unable to open filter file : %s\n", buff);
	      exit (2);
	    }
	}


      if (!RP_default_file (report, errbuff, rbx, rbs))
	{
	  printf ("No default file could be generated :\n%s\n", errbuff);
	  exit (2);
	}
    }

  // at this point - we've loaded the report, and the backend should have a filter...

  if (random_name)
    {
      tmpnam (buff);
      ofile = buff;
    }
  else
    {
      strcpy (buff, ofile);
    }

  if (RP_process_report (report, buff, rbx, rbs))
    {
      if (ispipe == 0)
	{
	  printf ("OK - output should be in %s\n", ofile);
	}
      else
	{
	  FILE *f;
	  FILE *p;
	  size_t count;
	  static char buf[BUFSIZ];
	  f = fopen (buff, "r");
	  p = popen (pipecmd, "w");
	  if (p == 0 || f == 0)
	    {
	      if (!p)
		{
		  fprintf (stderr, "Unable to open pipe\n");
		}
	      if (!f)
		{
		  fprintf (stderr, "Unable to open tmp file\n");
		}
	      exit (1);
	    }
	  while (!feof (f))
	    {
	      count = fread (buf, 1, BUFSIZ, f);
	      assert (ferror (f) == 0);
	      assert (fwrite (buf, 1, count, p) == count);
	      assert (ferror (p) == 0);
	    }
	  fclose (f);
	  fclose (p);
	}
    }
  else
    {
      printf ("Failed to process\n");
      exit (1);
    }
  exit (0);
}
