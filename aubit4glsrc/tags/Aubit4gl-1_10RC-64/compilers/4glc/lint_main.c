#include "a4gl_4glc_int.h"
#include "lint.h"

//#include "a4gl_libaubit4gl.h"
//#include "lint.h"
//#include "a4gl_expr.h"
//char *expr_as_string_when_possible(expr_str *e);
//
//void A4GL_warn (char *s);


static int dbopen=0;
//char *lint_get_variable_usage_as_string (struct variable_usage *var_usage);

//int read_module_definition(module_definition *s,char *filename);
int yylineno;


module_definition this_module;
int set_exit=0;

static void trimnl(char *s) {
	char *ptr;
	ptr=strchr(s,'\n'); if (ptr) *ptr=0;
	ptr=strchr(s,'\r'); if (ptr) *ptr=0;
}

int
main (int argc, char *argv[])
{
  module_definition *m;
  int a;
int num=0;
int narg;

  if (argc < 2)
    {
      printf ("Usage : %s infile infile...\n", argv[0]);
      exit (2);
    }
  A4GL_build_user_resources ();
  open_lintfile (0);



  narg=1;


  if (strcmp(argv[1], "-e")==0) {
	narg++;
	set_exit=1;
  }


  if (strcmp(argv[1], "-f")==0 || strcmp(argv[1], "-fe")==0 || strcmp(argv[1], "-ef")==0)
    { // Read file to process from a file
	// can be used when there are *lots* of files
	// and we run out of space on the command line..
      char *fname;
      FILE *f;
      char buff[512];
	int lines=0;
      fname = argv[2];
      f = fopen (fname, "r");

	if (strchr(argv[1],'e')) {
		set_exit=1;
  	}


      if (f == 0)
	{
	  printf ("Unable to open input file (%s)\n",fname);
	  exit (2);
	}



	// Get the number of lines
	lines=0;
      while (1)
	{
	  strcpy (buff, "");
	  fgets (buff, 511, f);
	  if (feof (f))
	    break;
		lines++;
	}
	rewind(f);


  	m = malloc (sizeof (struct module_definition) * (lines));
	lines=0;
      while (1)
	{
	  strcpy (buff, "");
	  fgets (buff, 511, f);
	  if (feof (f))
	    break;
		trimnl(buff);
	  if (strstr (buff, ".dat") != 0)
	    {
	      char *p;
	      p = strstr (buff, ".dat");
	      *p = 0;
	      //printf("Buff=%s\n",buff);
	    }

	  printf ("Loading %s : ", buff);
	  fflush (stdout);
	  if (A4GL_read_data_from_file ("module_definition", &m[lines++], buff))
	    {
	      printf ("OK...\n");
	      fflush (stdout);
	    }
	  else
	    {
	      printf ("- Failed to load %s\n", buff);
	      fflush (stdout);
	      exit (1);
	    }

	}
	fclose(f);
	num=lines;
    }
  else
    {
  	m = malloc (sizeof (struct module_definition) * (argc - narg));

      for (a = narg; a < argc; a++)
	{
	  char buff[256];
	  strcpy (buff, argv[a]);
	  if (strstr (buff, ".dat") != 0)
	    {
	      char *p;
	      p = strstr (buff, ".dat");
	      *p = 0;
	      //printf("Buff=%s\n",buff);
	    }
	  printf ("Loading %s : ", buff);
	  fflush (stdout);
	  if (A4GL_read_data_from_file ("module_definition", &m[a - narg], buff))
	    {
	      printf ("OK...\n");
	      fflush (stdout);
	    }
	  else
	    {
	      printf ("- Failed to load %s\n", argv[a]);
	      fflush (stdout);
	      exit (1);
	    }
	}
	num=argc-narg;
    }

  check_program (m, num );
  close_lintfile ();
  if (set_exit) {
	if (get_nlints()) {
		exit(1);
	}
	exit(0);
  }
  exit (0);
}



void A4GL_warn (char *s)
{
  if (!A4GL_isyes (acl_getenv ("SUPPRESSWARNINGS")))
    {
      fprintf (stderr, "Warning : %s @ line %d\n", s, yylineno);
    }
}

/*
void
A4GL_lint (char *s)
{
  if (!A4GL_isyes (acl_getenv ("SUPPRESSLINT")))
    {
      fprintf (stderr, "  LINT Warning : %s @ line %d\n", s, yylineno);
    }
}

*/


#define ET_EXPR_VARIABLE_USAGE_call lint_get_variable_usage_as_string

#include "expr_as_string_when_possible.c"


void set_yytext(char *s) {
}



int current_is_report() { // just used for lineno/pageno ..
return 0;
}



void
open_db (char *s)
{
  char db[2048];
  char buff[256];

  A4GL_debug ("open_db %s", A4GL_null_as_null (s));
  strcpy (db, s);
  if (strlen(db)==0) return;

  A4GL_set_status (0, 1);
  A4GL_init_connection (db);
  if (A4GL_get_status () != 0)
    {
      SPRINTF2 (buff, "Could not connect to database %s (%s)",
               A4GL_null_as_null (db),
               A4GL_null_as_null (A4GLSQL_get_sqlerrm ()));
       		fprintf(stderr,"%s",buff);
	//exit(2);
	dbopen=0;
    }
dbopen=1;
}


//int isdbopeb() {
	//return dbopen;
//}
