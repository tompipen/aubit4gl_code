#include <stdio.h>
extern int lineno;
extern int colno;
extern int yydebug;

extern FILE *yyin;
char outputfile[132];
char *outputfilename;

char ofile[134];
char hfile[134];
char hsfile[134];

extern FILE *cfo;
extern FILE *cfio;
extern FILE *cfi;
extern FILE *hf;
extern FILE *hsf;
char export_name[128];

static bname (char *str, char *str1, char *str2)
{
  char fn[132];
  int a;
  char *ptr;
  strcpy (fn, str);

  for (a = strlen (fn); a >= 0; a--)
    {
      if (fn[a] == '.')
        {
          fn[a] = 0;
          break;
        }
    }
  ptr = &fn[a];
  strcpy (str1, fn);
  if (a >= 0)
        strcpy (str2, ptr + 1);
  else
    str2[0] = 0;
}


void
yyerror (char *s)
{
  char errfile[256];
  FILE *f;
  long ld;

  printf ("Error compiling %s.x (xline=%d yline=%d)\n",
	  outputfile, lineno, lineno);
  exit (2);
}

main (int argc, char *argv[])
{
  char a[128];
  char b[128];
  char c[128];
  char d[128];
int rval;
//  FILE *fopn;


  //load settings from config file(s):

yydebug=0;
  strcpy (d, "");

  if (argc > 1)
    {
     outputfilename = outputfile;

     strcpy (c, argv[1]);

     if (argc>2) {
     	strcpy (export_name, argv[2]);
     } else {
     	strcpy (export_name, argv[1]);
     }


     bname (c, a, b);

      if (b[0] == 0)
	{
	  strcat (c, ".x");
	}


	strcpy(outputfilename,a);



      yyin = (FILE *)fopen (c, "r");

	strcpy(ofile,outputfilename);
	strcat(ofile,".xo.c");
        cfo = (FILE *)fopen (ofile, "w");
	if (cfo==0) { printf("Unable to open output file\n");exit(1); }

	strcpy(ofile,outputfilename);
	strcat(ofile,".xi.c");
        cfi = (FILE *)fopen (ofile, "w");
	if (cfi==0) { printf("Unable to open output file\n");exit(1); }


	strcpy(ofile,outputfilename);
	strcat(ofile,".xio.c");
        cfio = (FILE *)fopen (ofile, "w");
	if (cfi==0) { printf("Unable to open output file\n");exit(1); }

	strcpy(hfile,outputfilename);
	strcat(hfile,".x.h");
        hf = (FILE *)fopen (hfile, "w");
	if (hf==0) { printf("Unable to open output file\n");exit(1); }

	strcpy(hsfile,outputfilename);
	strcat(hsfile,".xs.h");
        hsf = (FILE *)fopen (hsfile, "w");
	if (hsf==0) { printf("Unable to open output file\n");exit(1); }
    }

  else
    {

      printf ("Usage\n   %s filename\n", argv[0]);

      exit (0);

    }


  if (yyin == 0)
    {

      printf ("Error opening file : %s\n", c);

      exit (0);

    }


  write_genout();
  rval=yyparse ();

  fclose(cfo);
  fclose(cfi);
  fprintf(hsf,"\n\n#endif /*XS_%s_XS_H*/\n",outputfilename);
  fprintf(hf,"\n\n#endif /*X_%s_X_H*/\n",outputfilename);
  fclose(hf);
  fclose(hsf);

}




yywrap() {
	return 1;
}


write_genout() {
fprintf(cfi,"#include \"%s\"\n",hfile);
fprintf(cfio,"#include \"%s\"\n",hfile);
fprintf(cfo,"#include \"%s\"\n",hfile);


fprintf(cfio,"\n\nint write_%s(%s *s,char *filename) {\nint a;\n",export_name,export_name);
fprintf(cfio,"%s s_s;\n",export_name);
fprintf(cfio,"memcpy(&s_s,s,sizeof(s_s));\n");
fprintf(cfio,"if (!open_packer(filename,'O')) return 0;\n");
fprintf(cfio,"if (can_pack_all(\"%s\"))\n   a=pack_all(\"%s\",s,filename);\n else\n   a=output_%s(\"%s\",s_s,0,-1);\n",export_name,export_name,export_name,export_name);
fprintf(cfio,"close_packer('O');\n");
fprintf(cfio,"return a;\n");
fprintf(cfio,"}\n");
fprintf(cfio," \n");

fprintf(cfio,"\n\nint read_%s(%s *s,char *filename) {\nint a;\n",export_name,export_name);
fprintf(cfio,"if (!open_packer(filename,'I')) return 0;\n");
fprintf(cfio,"if (can_pack_all(\"%s\"))\n   a=unpack_all(\"%s\",s,filename);\n else\n   a=input_%s(\"%s\",s,0,-1);\n",export_name,export_name,export_name,export_name);
fprintf(cfio,"close_packer('I');\n");
fprintf(cfio,"return a;\n");
fprintf(cfio,"}\n");
fprintf(cfio," \n");

fprintf(hf,"#ifndef X_%s_X_H\n",outputfilename);
fprintf(hf,"#define X_%s_X_H\n",outputfilename);

fprintf(hsf,"#ifndef XS_%s_XS_H\n",outputfilename);
fprintf(hsf,"#define XS_%s_XS_H\n",outputfilename);
fprintf(hsf,"#define bool int\n",outputfilename);
fprintf(hsf,"#define istypedefed \n",outputfilename);
fprintf(hsf,"#include <stdio.h>\n",outputfilename);
fprintf(hsf,"#include <stdlib.h>\n",outputfilename);

fprintf(hf,"#include \"%s\"\n",hsfile);
//fprintf(hf,"int output_int (char *name, int val, int ptr, int isarr);\n");
//fprintf(hf,"int output_long (char *name, long val, int ptr, int isarr);\n");
//fprintf(hf,"int output_bool (char *name, int val, int ptr, int isarr);\n");
//fprintf(hf,"int output_string (char *name, char *val, int ptr, int isarr);\n");
//fprintf(hf,"int output_double (char *name, double val, int ptr, int isarr);\n");
//fprintf(hf,"int output_start_struct (char *s, char *n, int ptr, int isarr);\n");
//fprintf(hf,"int output_end_struct (char *s, char *n);\n");
//fprintf(hf,"int output_start_union (char *s, char *n, int ptr, int isarr);\n");
//fprintf(hf,"int output_nullptr (char *s);\n");
//fprintf(hf,"int output_okptr (char *s);\n");
//fprintf(hf,"int output_end_union (char *s, char *n);\n");
//fprintf(hf,"int output_enum (char *name, char *s, int d);\n");
//fprintf(hf,"int input_int (char *name, int *val, int ptr, int isarr);\n");
//fprintf(hf,"int input_long (char *name, long *val, int ptr, int isarr);\n");
//fprintf(hf,"int input_bool (char *name, int *val, int ptr, int isarr);\n");
//fprintf(hf,"int input_string (char *name, char **val, int ptr, int isarr);\n");
//fprintf(hf,"int input_double (char *name, double *val, int ptr, int isarr);\n");
//fprintf(hf,"int input_start_struct (char *s, char *n, int ptr, int isarr);\n");
//fprintf(hf,"int input_end_struct (char *s, char *n);\n");
//fprintf(hf,"int input_start_union (char *s, char *n, int ptr, int isarr);\n");
//fprintf(hf,"int input_ptr_ok (void );\n");
//fprintf(hf,"int input_end_union (char *s, char *n);\n");
//fprintf(hf,"int input_enum (char *name, int *d);\n");
}
