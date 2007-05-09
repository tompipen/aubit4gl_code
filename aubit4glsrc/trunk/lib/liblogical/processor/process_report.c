#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../common/a4gl_lle.h"
#include "API_process.h"
int ispipe;

//int A4GLLOGREPPROC_initlib (void);
//int A4GL_setenv (char *v, char *val, int overwrite);
static int do_we_have(char *s) ;
static char * find_default_filter(char *rtype) ;

// The report itself
static struct r_report *report;


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
  char errbuff[1024] = "";
  int off = 0;
  char *ofile = "";
  int random_name = 1;


  if (argc > 2)
    {
      int a=1;


      if (strcmp (argv[a], "-M") == 0)
	{
	  a++;
	  running_program = argv[a];
	  off = a;
	  a++;
	}


      if (strcmp (argv[a], "-o") == 0)
	{
	  a++;
	  ofile = argv[a];
	  off = a;
	  a++;
	  random_name = 0;
	  ispipe = 0;
	}

      if (strcmp (argv[a], "-p") == 0)
	{
	  a++;
	  pipecmd = argv[a];
	  off = a;
	  a++;
	  random_name = 1;
	  ispipe = 1;
	}



    }

  if (argc - off != 4 && argc - off != 3)
    {
      printf
	("Usage %s [ -M program ] [ [-p|-o] output ] type report-file-name [filter-file-name]\n",
	 argv[0]);
      exit (1);
    }

  if (strcmp (argv[1 + off], "SAVE") == 0)
    {
      int a;
      // We just want to copy from report-file-name to output...
      FILE *fin;
      FILE *fout;
      fin = gzfopen (argv[2 + off], "r");
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

      fout = gzfopen (ofile, "w");
      while (1)
	{
	  a = gzfgetc (fin);
	  if (a==EOF) break;
	  //if (gzfeof (fin)) break;
	  gzfputc (a, fout);	// Slow - but it'll do for now..
	}
      gzfclose (fin);
      gzfclose (fout);
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
	char *default_filter;
	default_filter=find_default_filter(argv[1 + off]);
      if (default_filter != 0)
	{
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
	} else {
  		obtain_rbs_rbx (report, &rbs, &rbx);
      		if (!RP_default_file (report, errbuff, rbx, rbs))
			{
	  		printf ("No default file could be generated :\n%s\n", errbuff);
	  		exit (2);
			}
	}
    }
  		obtain_rbs_rbx (report, &rbs, &rbx);

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
      if (ispipe == 0 )
	{
	if (random_name) {
	  printf ("OK - output should be in %s\n", ofile);
	}
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




char *find_default_filter(char *rtype) {
      int found=0;
	char lf_modname[512];
	char lf_program[512];
      static char default_filter[256];



	if (running_program) {
		if (strchr(running_program,'/')) {
			strcpy(lf_program,strrchr(running_program,'/')+1);
		} else {
			strcpy(lf_program,running_program);
		}
		if (strchr(lf_program,'.')) {
			char *ptr;
			ptr=strrchr(lf_program,'.');
			*ptr=0;
		}
	}

	strcpy(lf_modname,report->modName);
	if (strchr(lf_modname,'.')) {
			char *ptr;
			ptr=strrchr(lf_modname,'.');
			*ptr=0;
	}

      strcpy (default_filter, "");
// Search order
// program_module_report
// program_report
// program_module
// module_report
// report
// module
// program

 
	if (!found && running_program) {
	  sprintf (default_filter, "%s/etc/%s_%s_%s_%s.lrf", acl_getenv ("AUBITDIR"), lf_program,lf_modname,report->repName,rtype);
	  if (do_we_have(default_filter)) found=1;
	}

     if (!found && running_program ) {
	  sprintf (default_filter, "%s/etc/%s_%s_%s.lrf", acl_getenv ("AUBITDIR"), lf_program,report->repName,rtype);
	  if (do_we_have(default_filter)) found=1;
     }

     if (!found && running_program) {
	  sprintf (default_filter, "%s/etc/%s_%s_%s.lrf", acl_getenv ("AUBITDIR"), lf_program,lf_modname,rtype);
	  if (do_we_have(default_filter)) found=1;
     }

     if (!found) {
	  sprintf (default_filter, "%s/etc/%s_%s_%s.lrf", acl_getenv ("AUBITDIR"), lf_modname,report->repName,rtype);
	  if (do_we_have(default_filter)) found=1;
     }
     if (!found) {
	  sprintf (default_filter, "%s/etc/%s_%s.lrf", acl_getenv ("AUBITDIR"), report->repName,rtype);
	  if (do_we_have(default_filter)) found=1;
	}

     if (!found) {
	  sprintf (default_filter, "%s/etc/%s_%s.lrf", acl_getenv ("AUBITDIR"), lf_modname,rtype);
	  if (do_we_have(default_filter)) found=1;
     }

     if (!found && running_program) {
	  sprintf (default_filter, "%s/etc/%s_%s.lrf", acl_getenv ("AUBITDIR"), lf_program,rtype);
	  if (do_we_have(default_filter)) found=1;
	}


      /* First off - lets see if we can find a specific filter... */
      if (report->max_col <= 80 &&!found)
	{
	  sprintf (default_filter, "%s/etc/default_%s_narrow.lrf", acl_getenv ("AUBITDIR"), rtype);

	  if (do_we_have(default_filter)) found=1;
	}

      if (report->max_col <= 132 && !found)
	{
	  sprintf (default_filter, "%s/etc/default_%s_normal.lrf", acl_getenv ("AUBITDIR"), rtype);
	  if (do_we_have(default_filter)) found=1;
	}

      if (report->max_col > 132 && !found)
	{
	  sprintf (default_filter, "%s/etc/default_%s_wide.lrf", acl_getenv ("AUBITDIR"), rtype);
	  if (do_we_have(default_filter)) found=1;
	}

      /* Finally - try just a standard default */
      if (!found)
	{
	  sprintf (default_filter, "%s/etc/default_%s.lrf", acl_getenv ("AUBITDIR"), rtype);
	  if (do_we_have(default_filter)) found=1;
	}

      if (found) {
		return default_filter;
      }


return 0;

}

static int do_we_have(char *s) {
	FILE *f;
	A4GL_debug("Looking for %s",s);
   	f = fopen (s, "r");
	if (f) {
		fclose(f);
		return 1;
	} else {
		return 0;
	}
}

