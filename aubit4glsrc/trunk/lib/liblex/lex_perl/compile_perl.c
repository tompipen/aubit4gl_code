#include "compile_perl.h"

FILE *outfile = 0;
FILE *outfile_h = 0;


extern int ordbindcnt;
extern int ibindcnt;
extern int nullbindcnt;
extern int obindcnt;
extern int ebindcnt;
extern int fbindcnt;
extern char *outputfilename;
extern char curr_func[];
dll_import struct binding_comp *ibind;
dll_import struct binding_comp *nullbind;
dll_import struct binding_comp *obind;
dll_import struct binding_comp *ebind;
dll_import struct binding_comp *fbind;
dll_import struct binding_comp *ordbind;
int suppress_lines = 0;
int suppress_newlines = 0;
int need_space = 0;
int temp_indent = 0;
extern int ccnt;					/**< Block counter - defined in lexer.c */
extern int yylineno;
int setting_module_to_null = 0;

int when_case_has_expr;


static void add_used_block (int n, char *btype);
static int is_used_block (int n, char *btype);
static void free_need_globals (void);
static char * find_record_dot (char *s);
void need_globals (char *s);
char *encode_records (char *s);
int print_bind_set_value_param_3 (char *cname, char i);


static char *
Cname (char *s)
{
  static char buff[256];
  sprintf (buff, "DC_C%s_%s", A4GL_compiling_module_basename (), s);
  need_globals (buff);
  return buff;
}

static char *
Rname (char *s)
{
  static char buff[256];
  sprintf (buff, "DR_R%s_%s", A4GL_compiling_module_basename (), s);
  need_globals (buff);
  return buff;
}

static char *
Pname (char *s)
{
  static char buff[256];
  if (strcmp (s, "KFREE_SQL_MEM") == 0)
    {
      A4GL_assertion (1, "Rubbish detected");
    }
  sprintf (buff, "DP_P%s_%s", A4GL_compiling_module_basename (), s);
  need_globals (buff);
  return buff;
}

struct s_save_binding
{
  int nbind;
  struct binding_comp *bind;
};


int
print_bind_set_value_param (char *cname, char i)
{
  int a = 0;
  char *xx;
  xx = strdup (A4GL_strip_quotes (cname));
  if (i == 'i')
    {
      for (a = 0; a < ibindcnt; a++)
	{
	  A4GL_assertion (cname[0] != '"',
			  "Cursor name doesn't start with \"");
	  printc ("$%s->Parameter(%d,$%s);", Cname (xx), a,
		  use_scope (ibind[a].varname));
	}
      start_bind (i, 0);
      return a;
    }



  if (i == 'o')
    {
      int nmem;
      struct s_save_binding *s;
      a = obindcnt;
      if (obindcnt)
	{
	  s = malloc (sizeof (struct s_save_binding));
	  s->nbind = obindcnt;
	  nmem = sizeof (struct binding_comp) * obindcnt;
	  s->bind = malloc (nmem);
	  memcpy (s->bind, obind, nmem);
	  A4GL_add_pointer (xx, CURSOR_BIND_O, s);
	}

      start_bind (i, 0);
      return a;
    }


  A4GL_assertion (1, "End of function");
  return 0;
}

void
print_prepare_in_header (char *xx)
{
  if (A4GL_has_pointer (xx, PREPARE_PRINTED))
    return;
  A4GL_add_pointer (xx, PREPARE_PRINTED, (void *) 1);
}



int
am_setting_module ()
{
  return setting_module_to_null;
}



/*
static void
niy (char *f)
{
  printf ("Not implemented %s.\n", f);
}
*/

static void
niy_assert (char *s)
{
  printf ("%s\n", s);
  A4GL_assertion (1, "Not implemented.\n");
}


open_outfile ()
{
  char buff[1024];
  sprintf (buff, "%s.pl", outputfilename);
  outfile = fopen (buff, "w");

  sprintf (buff, "%s.plh", outputfilename);
  outfile_h = fopen (buff, "w");

  if (outfile)
    {
      fprintf (outfile, "#!/usr/bin/perl\n");
      fprintf (outfile, "require aubit4gl;\n");
    }



  if (outfile_h)
    {
      fprintf (outfile_h, "#START\n");
    }
}



int
LEXLIB_LEX_initlib (void)
{
  A4GL_setenv ("MARK_SCOPE_MODULE", "Y", 1);
  open_outfile ();
  return 1;
}


static void
print_space (void)
{
  static char buff[256];
  if (need_space == 0)
    return;
  if (suppress_newlines)
    return;
  need_space = 0;
  A4GL_assertion (temp_indent < 0, "temp indent<0");
  memset (buff, ' ', 255);
  buff[(ccnt + temp_indent) * 3] = 0;
  FPRINTF (outfile, "%s", buff);
}



void
printc_nl (void)
{
  need_space = 1;
  FPRINTF (outfile, "\n");
}

void
printc (char *fmt, ...)
{
  va_list ap;
  /*A4GL_debug("via printc (a) in lib\n"); */
  va_start (ap, fmt);
  LEXLIB_A4GL_internal_lex_printc (fmt, &ap);
}



void
printh (char *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  LEXLIB_A4GL_internal_lex_printh (fmt, &ap);
}


void
LEXLIB_A4GL_internal_lex_printc (char *fmt, va_list * ap)
{
  static char buff[40960] = "ERROR-empty init";
  char *ptr;
  int a;
  int os;

  if (outfile == 0)
    {
      open_outfile ();
      if (outfile == 0)
	return;
    }
  os = vsnprintf (buff, sizeof (buff), fmt, *ap);
  if (os >= sizeof (buff))
    {
      a4gl_yyerror ("Internal error - string too big\n");
      exit (0);
    }
  if (strcmp (buff, "\n") == 0)
    {
      printc_nl ();
      return;
    }

  ptr = strtok (buff, "\n");
  while (ptr)
    {
      if (!suppress_newlines)
	{
	  print_space ();
	  fprintf (outfile, "%s", ptr);
	  printc_nl ();
	}
      else
	{
	  fprintf (outfile, "%s", ptr);
	}
      ptr = strtok (0, "\n");
    }
}


void
LEXLIB_A4GL_internal_lex_printcomment (char *fmt, va_list * ap)
{
//
}

void
LEXLIB_A4GL_internal_lex_printh (char *fmt, va_list * ap)
{
  vfprintf (outfile_h, fmt, *ap);
}





char *
LEXLIB_A4GL_decode_array_string (char *var, char *s)
{
  static char buff[2000] = "";
  int a;
  char tmp[2] = "X";		/*  Just to get a terminator on it */
  strcpy (buff, "(");

  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == ',')
	{
	  strcat (buff, ")-1][(");
	}
      else
	{
	  tmp[0] = s[a];
	  strcat (buff, tmp);
	}
    }
  strcat (buff, ")-1");
  return buff;

}


char *
LEXLIB_A4GL_get_into_part (int d, int n)
{
  return ""; // INTO PART
}




char *
LEXLIB_A4GL_set_var_sql (int d, int n)
{
  static char buff[20000];
  int a;
  extern char *current_upd_table;
  strcpy (buff, "");
  for (a = 0; a < n; a++)
    {
      if (a > 0)
	{
	  strcat (buff, ",");
	}

      if (current_upd_table)
	{
	  A4GL_4glc_push_gen (UPDVAL2, "?");
	}
      strcat (buff, "?");
    }
  return buff;

}


char *
LEXLIB_get_column_transform (char *s)
{
  return s;
}



char *
LEXLIB_print_arr_expr_fcall (void *ptr)
{

  niy_assert (__PRETTY_FUNCTION__);
  return "";
}

char *
LEXLIB_print_curr_spec (int type, char *s)
{
  static char buff[3000];
  int ni;
  int no;
  int bt;

  extern int obindcnt, ibindcnt;
  //printc ("{ #3\n");
  if (type == 1)
    {
      bt = 0;
      ni = ibindcnt;
      no = obindcnt;
      if (obindcnt)
	{
	  bt++;
	  print_bind_definition ('o');
	}
      if (ibindcnt)
	{
	  bt += 2;
	  print_bind_definition ('i');
	}
      if (obindcnt)
	{
	  print_bind_set_value ('o');
	}
      if (ibindcnt)
	{
	  print_bind_set_value ('i');
	}

      switch (bt)
	{
	case 0:
	  sprintf (buff, "A4GLSQL_prepare_select(0,0,0,0,\"%s\")", s);
	  break;
	case 1:
	  sprintf (buff, "A4GLSQL_prepare_select(0,0,obind,%d,\"%s\")", no,
		   s);
	  break;
	case 2:
	  sprintf (buff, "A4GLSQL_prepare_select(ibind,%d,0,0,\"%s\")", ni,
		   s);
	  break;
	case 3:
	  sprintf (buff, "A4GLSQL_prepare_select(ibind,%d,obind,%d,\"%s\")",
		   no, ni, s);
	  break;
	}
    }
  if (type == 2)
    sprintf (buff, "%s", s);
  return buff;
}

char *
LEXLIB_print_select_all (char *buff,int converted)
{
  //int ni, no;
  //static char b2[20000];
  //int os;
  char *p;
  //printc ("{\n");
  //ni = print_bind_definition ('i');
  //no = print_bind_definition ('o');
  p = anon_prepare (buff);
  //strcpy(b2,p);
  //os=snprintf (b2, sizeof(b2),"%s", p);
  //if (os>=sizeof(b2)) {
  ////A4GL_debug("print_select_all failed");
  //a4gl_yyerror("Internal error - string too long\n");
  //exit(2);
  //}
  return strdup (p);

}

char *
LEXLIB_rettype (char *s)
{
  return "var";
}

int
LEXLIB_A4GL_bad_identifiers (char *ident)
{
  return 0;
}

int
LEXLIB_print_bind (char i)
{
  printf ("print_bind... %c\n", i);
  return 0;
}

int
LEXLIB_print_bind_definition (char i)
{
  return 0;
}

int
LEXLIB_print_bind_set_value (char i)
{
  return 0;
}

int
LEXLIB_print_let_manyvars (t_expr_str_list * expr_list)
{
printf("let_manyvars\n");
}

int
LEXLIB_print_param (char i, char *funcname)
{
  int a;
  int b;
  char *ptr;
  int dtype;

  if (fbindcnt)
    {
      for (a = 0; a < fbindcnt; a++)
	{
	  dtype = scan_variable (fbind[a].varname);
	  if (strchr (fbind[a].varname, '.'))
	    {
	      printc ("$%s=$p_%d;", fbind[a].varname, a);
	    }
	}
    }
  return fbindcnt;
}

void
LEXLIB_A4GL_add_put_string (char *buff)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_A4GL_generate_or (char *out, char *in1, char *in2)
{
  SPRINTF2 (out, "%s||%s", in1, in2);
}

void
LEXLIB_A4GL_incprint (void)
{

  int a;

  for (a = 0; a <= getinc (); a++)
    {
      printc ("   ");
    }
}

void
LEXLIB_A4GL_lex_parsed_fgl (void)
{
  if (outfile)
    {
      fprintf (outfile, "# END\n");
      fprintf (outfile, "AppEntry();\n");
      fclose (outfile);
      outfile = 0;
    }

  if (outfile_h)
    {
      fprintf (outfile_h, "# END\n");
      fclose (outfile_h);
      outfile_h = 0;
    }
}

void
LEXLIB_A4GL_prchkerr (int l, char *f)
{
}

void
LEXLIB_printDeclareFunctionStack (char *functionName)
{
  /* do nothing */
}

void
LEXLIB_printInitFunctionStack (void)
{
  /* do nothing */
}

void
LEXLIB_printPopFunction (void)
{
  /* do nothing */
}

void
LEXLIB_printPushFunction (void)
{
  /* do nothing */
}

void
LEXLIB_print_Constant (int type, char *v)
{
  /* do nothing */
}

void
LEXLIB_print_after_when (int endofblock)
{

  if (when_case_has_expr)
    printc ("break;");
  else
    printc ("}");
  temp_indent--;

}

void
LEXLIB_print_bind_pop1 (char i)
{
  niy_assert (__PRETTY_FUNCTION__);
}






void
LEXLIB_print_bind_pop2 (t_expr_str_list * ptr, char i)
{
  int a;
  //int dtype;
  struct expr_str *p;
  char *ptr_str = 0;
  a = 0;

  if (i != 'o')
    {
      A4GL_assertion (1, "Not Used");
    }
  A4GL_debug ("bind_pop2\n");

  if (is_just_expr_clipped (obind[a].varname, ptr))
    return;



  ptr = A4GL_rationalize_list_concat (ptr);

  if ((obind[a].dtype & DTYPE_MASK) == DTYPE_CHAR)
    {				// If its a character string -
      ptr_str = is_single_string (ptr);
    }


  A4GL_debug ("Checking ignore : %s ", obind[a].varname);


  if (scan_variable (obind[a].varname) != -1)
    {

      A4GL_debug ("XXX\n");

      set_suppress_newlines ();
      if (!is_ignore_var (obind[a].varname))
	{
	  printc ("$%s=", use_scope (fixup_squares (obind[a].varname)));
	}

      if (ptr->nlist > 1)
	{
	  p = A4GL_new_concat_list (ptr);
	}
      else
	{
	  p = ptr->list[0];
	}

      if (p->expr_type == ET_EXPR_NULL)
	{
	  if (!is_ignore_var (obind[a].varname))
	    {
	      LEXLIB_print_expr (p);
	    }
	}
      else
	{
	  int bit_like_null;
	  bit_like_null = 0;
	  if ((obind[a].dtype & DTYPE_MASK) == DTYPE_DECIMAL
	      || (obind[a].dtype & DTYPE_MASK) == DTYPE_INT
	      || (obind[a].dtype & DTYPE_MASK) == DTYPE_SMINT
	      || (obind[a].dtype & DTYPE_MASK) == DTYPE_FLOAT
	      || (obind[a].dtype & DTYPE_MASK) == DTYPE_SMFLOAT)
	    {

	      if (p->expr_type == ET_EXPR_LITERAL_STRING)
		{
		  if (strcmp (p->u_data.expr_string, "") == 0)
		    bit_like_null = 1;
		  if (strcmp (p->u_data.expr_string, " ") == 0)
		    bit_like_null = 1;
		}

	      if (bit_like_null)
		{
		  if (!is_ignore_var (obind[a].varname))
		    {
		      printc ("null #Bit like null");
		    }
		}
	    }


	  if (!bit_like_null)
	    {
	      ensure_dtype (p, obind[a].dtype & DTYPE_MASK, 0);
	      if (!is_ignore_var (obind[a].varname))
		{
		  LEXLIB_print_expr (p);
		}
	    }
	}
      if (!is_ignore_var (obind[a].varname))
	{
	  printc (";\n");
	}

      clr_suppress_newlines ();

      if ((obind[a].dtype & DTYPE_MASK) == DTYPE_CHAR)
	{
	  if (find_variable_scope (obind[a].varname) == 'L' || 1)
	    {
	      // If its a local character string -
	      // remember it's last assignment..
	      // this may come in useful ;-)

	    }
	}
    }
  else
    {
      char buff[1024];
      char *var;
      char *len;
      char *start;
      //int x;
      char *end;
      char *zero;
      char *cptr;
      A4GL_debug ("obind[a].varname='%s' @ %d", obind[a].varname, yylineno);
      strcpy (buff, obind[a].varname);
      cptr = strchr (buff, '(');
      if (!cptr)
	{
	  A4GL_assertion (1, "Can't find start a4gl_let_substr");
	}
      var = cptr + 1;
      cptr = strchr (var, ',');
      if (!cptr)
	{
	  A4GL_assertion (1, "Can't find start a4gl_let_substr(1)");
	}
      *cptr = 0;
      len = cptr + 1;
      cptr = strchr (len, ',');
      if (!cptr)
	{
	  A4GL_assertion (1, "Can't find start a4gl_let_substr(2)");
	}
      *cptr = 0;
      start = cptr + 1;
      cptr = strchr (start, ',');
      if (!cptr)
	{
	  A4GL_assertion (1, "Can't find start a4gl_let_substr(3)");
	}
      *cptr = 0;
      end = cptr + 1;
      cptr = strchr (end, ',');
      if (cptr)
	{
	  *cptr = 0;
	  zero = cptr + 1;
	}
      else
	{
	  zero = end;
	  end = 0;
	}
      cptr = strchr (zero, ')');
      if (!cptr)
	{
	  A4GL_assertion (1, "Can't find start a4gl_let_substr(4)");
	}
      *cptr = 0;

      if (strcmp (zero, "0") != 0)
	{
	  A4GL_assertion (1, "Can't decode the let_substr (0!=0)....\n");
	}

      if (end == 0)
	end = start;

      p = ptr->list[0];

      if (is_ignore_var (obind[a].varname));
      else
	{
	  printc ("$%s=substring($%s,%s,%s,", use_scope (var), use_scope (var),
		  start, end);
	  ensure_char (p, 0);
	  LEXLIB_print_expr (p);
	  printc (");");
	}


    }
}









void
ensure_char (struct expr_str *p, int f)
{
  return;
}








void
LEXLIB_print_case (t_expr_str * expr)
{
  set_suppress_newlines ();
  if (expr)
    {
      printc ("switch (");
      print_expr (expr);
      printc (") {");
    }
  clr_suppress_newlines ();

}

void
LEXLIB_print_case_end (void)
{
  printc ("}");
}


void
LEXLIB_print_close (char type, char *name)
{
}
void
LEXLIB_print_cmd_end (void)
{
  /* doesn't need to do anything */
}
void
LEXLIB_print_cmd_start (void)
{
  /* doesn't need to do anything */
}

void
LEXLIB_print_continue_block (int n, int brace, char *why)
{
  printc ("# CB\n");
  if (is_used_block (n, "C") || 1)
    {
      printc ("CONTINUE_BLOCK_%d:       # %d  ", n, yylineno);
    }

  if (brace)
    {
      if (strcmp (why, "FOR") == 0)
	{
	  return;
	}

      if (strcmp (why, "WHILE") == 0)
	{
	  return;
	}

      printc ("} #  CB %s \n", why);
    }

}
void
LEXLIB_print_declare (char *sa1, char *a2, char *a3, int h1, int h2)
{
  int a1;
  char *xx;
  char *yy;
  int ign;
  xx = strdup (A4GL_strip_quotes (a3));

  yy = strdup (A4GL_strip_quotes (a2));
  if (strlen (sa1))
    a1 = 1;
  else
    a1 = 0;

  if (h2)
    {

      //printf ("--->%s %s \n", xx, a3);
      if (!A4GL_find_pointer (xx, CURSOR_USED) && !ign)
	{
	  A4GL_add_pointer (xx, CURSOR_USED, (void *) 1);
	}
      printc ("$%s=new FGLScrollCursor();", Cname (xx));
    }
  else
    {
      if (!A4GL_find_pointer (xx, CURSOR_USED) && !ign)
	{
	  A4GL_add_pointer (xx, CURSOR_USED, (void *) 1);
	}
      printc ("$%s=new FGLCursor();", Cname (xx));
    }
  print_bind_set_value_param (a3, 'i');
  print_bind_set_value_param (a3, 'o');
  print_prepare_in_header (yy);

  printc ("$%s->CursorDeclare(%d,$%s);", Cname (xx), a1 + h1, Pname (yy));
  start_bind ('i', 0);
  start_bind ('o', 0);
}





void
LEXLIB_print_defer (int quit)
{
	printc("print defer");
}

void
LEXLIB_print_do_select (char *s,int converted)
{
int l = 0;

if (ibindcnt) l++;
if (obindcnt) l += 2;
LEXLIB_print_execute (s, l);
return;

}

void
LEXLIB_print_empty_bind (char *name)
{
	printc("print empty bind");
}

void
LEXLIB_print_end_block (int n)
{
  if (is_used_block (n, "E"))
    {
      printc ("END_BLOCK_%d:  # %d - %s\n\n", n, yylineno,
	      A4GL_compiling_module ());
    }

}

void
LEXLIB_print_exec_sql (char *s,int converted)
{
  char *p;

  p = anon_prepare (s);
  LEXLIB_print_execute (p, 0);
  printc ("$%s->Free();", Pname (p));
}

void
LEXLIB_print_exec_sql_bound (char *s,int converted)
{
  char *p;

  p = anon_prepare (s);
  LEXLIB_print_execute (p, 1);

}

void
LEXLIB_print_execute (char *stmt, int using)
{
  int ni;
  int no;
  char buff[2000];
  char *xx;
  stmt = strdup (stmt);
  if (stmt[0] != '"')
    {
      sprintf (buff, "\"%s\"", stmt);
    }
  else
    {
      strcpy (buff, stmt);
    }

  xx = strdup (A4GL_strip_quotes (stmt));


  if (A4GL_has_pointer (xx, EMULATE_CURRENT_OF))
    {
      if (ibindcnt)
        {
          print_bind_set_value_param_3 (buff, 'i');
        }
          print_prepare_in_header(xx);
      printc ("$%s->Update($%s);\n", Pname (xx),
              Cname (A4GL_find_pointer (xx, EMULATE_CURRENT_OF)));
    }
  else
    {

      if (using == 0)
        {
          print_prepare_in_header(xx);
          printc ("$%s->ExecuteSql(0);\n", Pname (xx));
        }

      if (using == 1)
        {
          ni = ibindcnt;
          print_bind_set_value_param_3 (buff, 'i');
          print_prepare_in_header(xx);
          printc ("$%s->ExecuteSql(%d);\n", Pname (xx), ni);
        }

      if (using == 2)
        {
          no = obindcnt;        //print_bind_definition ('o');

          print_prepare_in_header(xx);

          printc ("@%s=$%s->ExecuteSqlWithResults(0); \n",
             Rname (xx), Pname (xx));
          print_bind_set_value_param_3 (stmt, 'o');
        }
      if (using == 3)
        {
          ni = ibindcnt;
          print_bind_set_value_param_3 (buff, 'i');
          print_prepare_in_header(xx);
          printc
            ("@%s=$%s->ExecuteSqlWithResults(%d); \n",
             Rname (xx), Pname (xx), ni);
          print_bind_set_value_param_3 (stmt, 'o');
        }
    }
}

void
LEXLIB_print_execute_immediate (char *stmt)
{
	printc("EXECUTE IMMEDIATE\n");
}

void
LEXLIB_print_exit_loop (int type, int n)
{
  if (type == 0)
    {
      printc ("goto END_BLOCK_%d ; # EB ", n);
      add_used_block (n, "E");
    }
  A4GL_assertion(1,"Can't EXIT anything else");
}



void
LEXLIB_print_exit_program (t_expr_str * expr)
{
  if (expr)
    {
      set_suppress_newlines ();
      printc ("die(\"Exit : \".");
      real_print_expr (expr);
      printc (");");
      clr_suppress_newlines ();
    }
  else
    {
      printc ("die(\"Exit\");");
    }

}


void
LEXLIB_print_fetch_1 (void)
{
	printc("print fetch_1");
}


void
LEXLIB_print_fetch_2 (void)
{
	printc("print fetch_2");
}



void
LEXLIB_print_fgllib_start (char *db)
{
  extern int is_schema;
  if (db[0] != 0)
    {
      if (!is_schema)
	{
	  print_init_conn (db);
	}
      else
	{
	  printc ("#  NO DATABASE - SCHEMA ONLY ");
	}
    }
  print_function_variable_init ();
}




void
LEXLIB_print_flush_cursor (char *s)
{
	printc("print flush");
}

void
LEXLIB_print_for_end (char *var, void *from, void *to, void *step)
{
  temp_indent--;
  printc ("}");
}

void
LEXLIB_print_for_start (char *var, void *from, void *to, void *step)
{
	static int f=0;
  set_suppress_newlines();
  printc ("$%s=", var);
  print_expr (from);
  printc(";");
  clr_suppress_newlines();
  printc ("for_loop_%d: while (1) {",++f);
  temp_indent++;
  set_suppress_newlines();
  printc ("$for_step=");
  print_expr (step);
  printc(";");
  clr_suppress_newlines();
  set_suppress_newlines();
  printc ("$for_end=");
  print_expr (to);
  printc(";");
  clr_suppress_newlines();
  printc ("if ($for_step>0) {");
  printc ("   last for_loop_%d if ($%s>$for_end);",f,var);
  printc ("} else {");
  printc ("   last for_loop_%d if ($%s<$for_end);",f,var);
  printc ("}");

  //printc ("<=_e&&_step>0)||(%s>=_e&&_step<0);%s+=_step) {\n", var, var, var, var);

}

void
LEXLIB_print_for_step (char *var, void *from, void *to, void *step)
{
  printc ("$%s=$%s+$for_step;", var, var);
}

void
LEXLIB_print_foreach_close (char *cname)
{
  print_close ('C', cname);
}

void
LEXLIB_print_foreach_end (char *cname)
{
  char *xx;
  temp_indent--;
  xx = strdup (A4GL_strip_quotes (cname));
  printc ("}");
  printc ("$%s->CloseCursor(); # %c\n", Cname (xx),
	  A4GL_cursor_type (cname));
  printc ("# END FOREACH");

}

void
LEXLIB_print_foreach_next (char *cursorname, int has_using, char *into)
{
  char *xx;
  print_open_cursor (cursorname, has_using);
  xx = strdup (A4GL_strip_quotes (cursorname));

  printc ("$%s->ResetCursor();", Cname (xx));

  //Oban.dataSet(cursorname) do \n");

  printc ("while (1) {");
  temp_indent++;

  printc ("if (!$%s->MoveNext()) {break;}", Cname (xx));


  printc ("@%s=$%s->GetCurrent();", Rname (xx), Cname (xx));
  print_bind_set_value_param_2 (cursorname, 'o');

}

void
LEXLIB_print_foreach_start (void)
{
/* doesn't need to do anything */
  printc ("# FOREACH...");
}

void
LEXLIB_print_free_cursor (char *s)
{
}
void
LEXLIB_print_func_args (int c)
{
  print_function_variable_init ();
}

static void
real_print_func_call (t_expr_str * fcall)
{
  int a;
  //int f;
  int function_no;

  if (fcall->expr_type == ET_EXPR_FCALL)
    {
      struct expr_function_call *p;
      int n;

      p = fcall->u_data.expr_function_call;

      if (strcmp (p->fname, "fgl_drawbox") == 0)
	{
	  // Don't bother...
	  return;
	}




      set_suppress_newlines();
	if (ibindcnt) {
		printc("list(");
		for (a=0;a<ibindcnt;a++) {
				if (a) printc(",");
				printc("$%s", use_scope (fixup_squares (ibind[a].varname)));

		}
		printc(")=");
	}

      printc ("%s(\n", valid_func_name (p->fname));


      if (p->parameters)
	{
	  p->parameters = A4GL_rationalize_list (p->parameters);
	  for (a = 0; a < p->parameters->nlist; a++)
	    {
	      set_suppress_newlines ();

	      print_expr (p->parameters->list[a]);
	      if (a < p->parameters->nlist - 1)
		printc (", ");
	      clr_suppress_newlines ();
	    }
	}
      printc (");");
    }
    clr_suppress_newlines();



}





void
LEXLIB_print_func_call (t_expr_str * call)
{
  real_print_func_call (call);
}


void
LEXLIB_print_func_defret0 (void)
{
	printc("return;\n");
}


void
LEXLIB_print_func_end (void)
{
  printc ("}");
  printc ("\n");
  printc ("\n");
  printc ("\n");
}


void
LEXLIB_print_func_start_1 (char *isstatic, char *fname, int type)
{
  free_need_globals ();
  if (type == 0)
    {
      //int a;
      //int dtype;
      //extern int yylineno;
      printc (" \n");
      printc (" \n");
      printc (" \n");

      printc
	("\n\n\n#******************************************************************************");

      printc ("\nsub  %s {", valid_func_name (fname));
    }

}



void
LEXLIB_print_func_start_2 (char *isstatic, char *fname, int type)
{
  extern int class_cnt;
  char *p;

  if (fbindcnt==0) return;

  set_suppress_newlines();

  printc("my (");
  if (type == 0)
    {
      int a;
      int dtype;
      expand_bind (&fbind[0], 'F', fbindcnt, 1);
      for (a = 0; a < fbindcnt; a++)
	{
	  if (a) printc(",");
	  dtype = scan_variable (fbind[a].varname);
	  if (strchr (fbind[a].varname, '.'))
	    {
	      printc ("$p_%d", a);
	    }
	  else
	    {
	      char *l;
	      char *r;
	      l = fbind[a].varname;
	      r = rettype_integer_internal (dtype & DTYPE_MASK);
	      printc ("$%s", l);
	    }
	}

    }
  printc(")=@_;");
  clr_suppress_newlines ();
}


void
LEXLIB_print_goto (char *label)
{
	A4GL_assertion(1,"Can't goto in php\n");
}

void
LEXLIB_print_if_else (void)
{
  ccnt--;
  printc ("} else {\n");
  ccnt++;

}

void
LEXLIB_print_if_end (void)
{
  ccnt--;
  printc ("}");

}

void
LEXLIB_print_if_start (t_expr_str * ptr)
{
  set_suppress_newlines ();
  printc ("if (");
  LEXLIB_print_expr (ptr);
  printc (") {");
  ccnt++;
  clr_suppress_newlines ();

}





void
print_init_var (char *name, char *prefix, int alvl, int mlvl)
{
  int d;
  char tmpbuff[1024];
  int a0;
  int a1;
  int a2;
  int size;
  int lvl;
  int x;
  char prefix2[1024];
  int arrsizes[10];
  int cnt = 0;
  int acnt;
  int printing_arr;
  int dont_print = 0;
  static int ccc = 0;
  printing_arr = 0;
  int c;
  int count_squares = 0;
  memset (tmpbuff, 0, sizeof (tmpbuff));

  strcpy (tmpbuff, name);

  if (find_record_dot (tmpbuff))
    {
      char buffx[1024];
      char *ptr;
      char *sptr;
      /* OK - we're going to break this down... */
      strcpy (buffx, name);
      sptr = buffx;
      while (1)
	{
	  ptr = (char *)find_record_dot (sptr);
	  if (ptr)
	    {
	      if (ptr[-1] == 's' && ptr[-2] == 'i' && ptr[-3] == 'h' && ptr[-4] == 't')	// 'this' backwards...
		{
		  // Ignore it...
		  sptr = ptr + 1;
		  continue;
		}
	      break;
	    }
	  else
	    {
	      break;
	    }

	}
      /* We've found the next '.' */
      /* put the LHS onto 'prefix' */
      /* and the RHS into name... */
      *ptr = 0;
      ptr++;
      strcpy (prefix2, prefix);
      if (strlen (prefix2))
	{
	  strcat (prefix2, ".");
	}
      strcat (prefix2, buffx);

      x = get_variable_dets_arr3 (prefix2, &d, &a0, &a1, &a2, &size, &lvl, 0);

      if (x == -1)
	{
	  a4gl_yyerror ("Couldn't find variable to null it...[2]");
	  return;
	}

      if (x != -2)
	{
	  a4gl_yyerror ("I was expecting a record...");
	  return;
	}
      if (a0 && prefix2[strlen (prefix2) - 1] != ']')
	{
	  char buff_id[256];
	  printing_arr = 1;
	  //cnt = split_arrsizes (arr, (int *) &arrsizes);
	  arrsizes[0] = a0;
	  arrsizes[1] = a1;
	  arrsizes[2] = a2;
	  if (a0)
	    cnt = 1;
	  if (a1)
	    cnt = 2;
	  if (a2)
	    cnt = 3;
	  if (arrsizes[0] > 0)
	    {
	      for (acnt = 0; acnt < cnt; acnt++)
		{
		  SPRINTF2 (buff_id, "$fglcnt1_%d_%d", ccc++, alvl);
		  printc ("for (%s=0;%s<=%d;%s++) {", buff_id, buff_id,
			  arrsizes[acnt] - 1, buff_id);
		  temp_indent++;
		  strcat (prefix2, "[");
		  strcat (prefix2, buff_id);
		  strcat (prefix2, "]");
		  alvl++;
		}
	    }
	  else
	    {
	      dont_print = 1;
	    }
	}

      if (dont_print == 0)
	{
	  //printc ("/print_init 2");
	  print_init_var (ptr, prefix2, alvl, mlvl);
	}

      if (printing_arr && dont_print == 0)
	{
	  for (acnt = 0; acnt < cnt; acnt++)
	    {
	      temp_indent--;
	      printc ("}");
	      alvl--;

	    }
	}

      return;
    }


/* If we've got to here we can only be dealing with a leaf on a record*/
  strcpy (prefix2, prefix);

  if (strlen (prefix2))
    {
      strcat (prefix2, ".");
    }

  strcat (prefix2, name);


  x = get_variable_dets_arr3 (prefix2, &d, &a0, &a1, &a2, &size, &lvl, 0);
  if (x < 0)
    {
      a4gl_yyerror ("Couldn't find variable to null it...[1]");
      return;
    }
  dont_print = 0;
  if (a0 && prefix2[strlen (prefix2) - 1] != ']')
    {
      char buff_id[256];
      printing_arr = 1;
      arrsizes[0] = a0;
      arrsizes[1] = a1;
      arrsizes[2] = a2;
      if (a0)
	cnt = 1;
      if (a1)
	cnt = 2;
      if (a2)
	cnt = 3;
      //cnt = split_arrsizes (arr, (int *) &arrsizes);
      if (arrsizes[0] >= 0)
	{
	  for (acnt = 0; acnt < cnt; acnt++)
	    {
	      SPRINTF2 (buff_id, "$fglcnt2_%d_%d", ccc++, alvl);
	      printc ("for (%s=0;%s<=%d;%s++) {", buff_id, buff_id,
		      arrsizes[acnt] - 1, buff_id);
	      strcat (prefix2, "[");
	      strcat (prefix2, buff_id);
	      strcat (prefix2, "]");
	      alvl++;
	    }
	}
      else
	{
	  dont_print = 1;
	}
    }

  if (dont_print == 0)
    {
      int d1;
      d1 = d & DTYPE_MASK;
      if (d1 == DTYPE_INT ||
	  d1 == DTYPE_SMINT ||
	  d1 == DTYPE_FLOAT ||
	  d1 == DTYPE_SMFLOAT || d1 == DTYPE_DECIMAL || d1 == DTYPE_MONEY)
	{
	  if (d1 == DTYPE_DECIMAL)
	    {
	      printc ("$%s=0;", use_scope (fixup_squares (prefix2)));
	    }
	  else
	    {
	      printc ("$%s=0;", use_scope (fixup_squares (prefix2)));
	    }
	}
      else
	{
	  if (d1 == DTYPE_BYTE || d1 == DTYPE_TEXT)
	    {
	      printc ("$%s=new FGLBlob();",
		      use_scope (fixup_squares (prefix2)));
	    }
	  else
	    {
	      printc ("$%s=$null;", use_scope (fixup_squares (prefix2)));
	    }
	}
    }

  if (printing_arr && !dont_print)
    {
      for (acnt = 0; acnt < cnt; acnt++)
	{
	  printc ("}\n");
	  alvl--;
	}
    }

}





















void
LEXLIB_print_init_conn (char *db)
{
  if (db == 0)
    {
      printc ("DBConnect();\n");
    }
  else
    {
      printc ("DBConnect(\"%s\");\n", db);
    }

}

/**
 * Print in the generated output file the C implementation of the
 * INITIALIZE <variable_list> TO NULL 4gl statement.
 */
void
LEXLIB_print_init (int explicit)
{
  int cnt;


  //expand_bind (&nullbind[0], 'N', nullbindcnt, 0);

  printc ("# print_init");
  for (cnt = 0; cnt < nullbindcnt; cnt++)
    {
      if (is_ignore_var (nullbind[cnt].varname))
	continue;
      print_init_var (nullbind[cnt].varname, "", 0, am_setting_module ());
    }

  /*cnt = print_bind ('N'); */
  /*printc ("A4GL_set_init(nullbind,%d);\n", cnt); */
}

void
LEXLIB_print_init_table (char *s)
{
}

void
LEXLIB_print_label (char *s)
{
  printc ("%s:  \n", s);
}


void
LEXLIB_print_load (char *file, char *delim, char *tab, char *list)
{
	printc("LOAD\n");
}

void
LEXLIB_print_load_str (char *file, char *delim, char *sql)
{
	printc("LOADSTR\n");
}
void
LEXLIB_print_locate (char where, char *var, char *fname)
{
	printc("LOCATE\n");
}

void
LEXLIB_print_main_1 (void)
{
  free_need_globals ();
  printc
    ("\n\n\n#******************************************************************************");
  printc ("\n\n\nsub AppEntry() {\n", outputfilename);
}


void
LEXLIB_print_main_end (void)
{
  printc ("}");
}


void
LEXLIB_print_niy_assert (char *type)
{
}

void
LEXLIB_print_op (char *type)
{
	printc("print op\n");
}

void
LEXLIB_print_open_cursor (char *cname, int has_using)
{
  char *xx;
  int ign;


  xx = strdup (A4GL_strip_quotes (cname));

  if (A4GL_cursor_type (cname) == 'I')
    {
      printc ("# Dont open cursor - %s - its not real!", cname);
      return;
    }

  if (!A4GL_find_pointer (xx, CURSOR_USED))
    {
      A4GL_add_pointer (xx, CURSOR_USED, (void *) 1);
    }

  if (has_using)
    {
      int ni;
      ni = ibindcnt;		// print_bind_definition ('i');
      print_bind_set_value_param_2 (cname, 'i');
      printc ("$%s->OpenCursor();\n", Cname (xx));
    }
  else
    {
      printc ("$%s->OpenCursor();\n", Cname (xx));

    }

}

void
LEXLIB_print_open_session (char *s, char *v, char *user)
{
	printc("open session\n");
}

void
LEXLIB_print_option_op (int type, char *n, int mn)
{
}

void
LEXLIB_print_options (char n, char *s)
{
}

void
LEXLIB_print_otherwise (void)
{
  printc ("default:");
  temp_indent++;
}

void
LEXLIB_print_pop_variable (char *s)
{
	printc("print_pop_variable\n");
}


void
LEXLIB_print_prepare (char *stmt, char *sqlvar)
{

  char *xx = 0;
  char *p = 0;
  int use_repository = 0;
  sqlvar = strdup (sqlvar);
  stmt = strdup (stmt);
  xx = strdup (A4GL_strip_quotes (stmt));



  print_prepare_in_header (xx);
  A4GL_add_pointer (xx, PREPARE_USED, 0);

  printc ("$%s=new FGLEmulPrepare();", Pname (xx));
  if (sqlvar[0]=='"') {
  	printc ("$%s->PrepareFromDynamic(%s);", Pname (xx), sqlvar);
  } else {
  	printc ("$%s->PrepareFromDynamic(%s);", Pname (xx), use_scope (sqlvar));
  }

}


void
LEXLIB_print_push_null (void)
{
  printc ("$null");
}

void
LEXLIB_print_push_variable (char *s)
{
	printc("print_push_variable\n");
}


void
LEXLIB_print_pushchar (char *s)
{
	printc("print_push_char\n");
}


void
LEXLIB_print_put (char *cname, char *putvals)
{
	printc("print_put\n");
}


void
LEXLIB_print_range_check (char *var, char *size)
{
}

void
LEXLIB_print_return (t_expr_str_list * expr)
{
  int n;
  expr = A4GL_rationalize_list (expr);
  n = A4GL_new_list_get_count (expr);
  if (n == 0)
    printc ("return;");
  if (n == 1)
    {
      set_suppress_newlines ();
      printc ("return ");

      real_print_expr (expr->list[0]);
      printc(";");
      clr_suppress_newlines ();
    }

  if (n > 1)
    {
      int a;
      set_suppress_newlines ();
      printc ("return array(");
      for (a = 0; a < expr->nlist; a++)
	{
	  real_print_expr (expr->list[a]);
	  printc (",");
	}
      printc (");");
      clr_suppress_newlines ();

    }

}

void
LEXLIB_print_set_conn (char *conn)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_set_helpfile (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_set_langfile (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_set_options (char *type, char *id, char *var, char *val)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_sleep (t_expr_str * expr)
{
  /* do nothing */
}


void
LEXLIB_print_sql_block_cmd (char *sql)
{

  niy_assert (__PRETTY_FUNCTION__);
}


void
LEXLIB_print_sql_commit (int t)
{
	if (t==-1) {
		printc("Transaction('BEGIN');");
	}
	if (t==0) {
		printc("Transaction('ROLLBACK');");
	}
	if (t==1) {
		printc("Transaction('COMMIT');");
	}
}


void
LEXLIB_print_start_block (int n)
{
  printc(" # START BLOCK : %d %d\n",n,get_ccnt());
  /* do nothing */
}


void
LEXLIB_print_system_run (void *expr, int type, char *rvar)
{
  set_suppress_newlines ();
  if (rvar)
    {
      printc ("$%s=", use_scope (fixup_squares (rvar)));
    }

  printc ("system(", type);
  print_expr (expr);
  printc (");");

}

void
LEXLIB_print_unload (char *file, char *delim, char *sql)
{
	if (file[0]!='"') {
	printc("Unload($%s,%s,\"%s\");",use_scope(file),delim,sql);
	} else {
	printc("Unload(%s,%s,\"%s\");",use_scope(file),delim,sql);
	}
}


void
LEXLIB_print_validate (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}


void
LEXLIB_print_variable_new (struct variable *v, char scope, int level)
{
  int static_extern_flg;
  char arrbuff[256];
  char name[256];
  int a;
  static_extern_flg = 0;



  return ;



  if (scope == 'G')
    return;			// We can't be doing with printing global variables for each file - because we're only going to end up with a single file...
  if (level > 0)
    {
      for (a = 0; a < level; a++)
	{
	  printh ("  ");
	}
    }




  if ((level == 0 && is_system_variable (v->names.name))
      || (strcmp (acl_getenv ("A4GL_LEXTYPE"), "CM") == 0
	  && strcasecmp (v->names.name, "int_flag") == 0))
    {
      // Ignore all system variables
      return;
    }

  if ((level == 0 && is_system_variable (v->names.name))
      || (strcmp (acl_getenv ("A4GL_LEXTYPE"), "CM") == 0
	  && strcasecmp (v->names.name, "quit_flag") == 0))
    {
      // Ignore all system variables
      return;
    }


  strcpy (arrbuff, "-1");
  /* are we dealing with the sqlca variable ? */
  A4GL_debug ("v->names.name=%s", v->names.name);
  if (level == 0 && strcmp (v->names.name, "sqlca") == 0)
    {
#ifdef DEBUG
      A4GL_debug ("SQLCA!!!\n");
#endif
      if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0)
	{
	  return;
	}
    }

  if (scope == 'G' && strcasecmp (v->names.name, "time") == 0 && level == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Ignore time....\n");
#endif
      return;
    }


  if (v->is_array)
    {
      make_arr_str (arrbuff, v);
    }
  else
    {
      strcpy (arrbuff, "-1");
    }




  if (level == 0)		/* We only print 'static' or 'extern' at the start of a record/variable - not a nested record */
    {
      if (scope == 'G')
	{
	  static_extern_flg += 2;
	}

      if (scope == 'M' || scope == 'R')
	{
	  static_extern_flg += 1;
	}
      else
	{

	  if (v->is_static == 1)
	    {
	      static_extern_flg += 1;
	    }
	}
    }
  strcpy (name, v->names.name);
  if (level == 0
      && (A4GL_isyes (acl_getenv ("MARK_SCOPE"))
	  || A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE"))))
    {
      if (is_system_variable (name) && strncmp (name, "a4gl_sqlca", 10) != 0);
      else
	{
	  if (v->scope == 'G' || v->scope == 'g')
	    {
	      SPRINTF1 (name, "G_%s", v->names.name);
	    }
	  if (v->scope == 'M' || v->scope == 'm' || v->scope == 'R')
	    {
	      if (v->scope == 'R')
		{
		  SPRINTF3 (name, "R_%s_%s_%s",
			    A4GL_compiling_module_basename (),
			    curr_func, v->names.name);
		}
	      else
		{
		  if (A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE")))
		    {
		      SPRINTF2 (name, "M_%s_%s",
				A4GL_compiling_module_basename (),
				v->names.name);
		    }
		  else
		    {
		      SPRINTF1 (name, "M_%s", v->names.name);
		    }
		}
	    }
	  if (v->scope == 'L' || v->scope == 'l')
	    {
	      SPRINTF1 (name, "L_%s", v->names.name);


	      /*
	         if (strcmp(v->names.name,"to")==0) {
	         SPRINTF1 (name, "L_xxx_to", v->names.name);
	         }
	         if (strcmp(v->names.name,"from")==0) {
	         SPRINTF1 (name, "L_xxx_from", v->names.name);
	         }
	       */


	    }
	}
    }

  if (level == 0)
    {
      if (is_ignore_var (name))
	{
	  return;
	}
    }


  if (is_param (name))
    return;


  if (v->variable_type == VARIABLE_TYPE_SIMPLE)
    {
      char vbuff[256] = "";
      char abuff[256] = "";
      char tbuff[256] = "";
      strcpy (vbuff, name);
      strcpy (tbuff,
	      rettype_integer_internal (v->data.v_simple.
					datatype & DTYPE_MASK));
      //SPRINTF2 (vbuff, "%s %s", name, rettype_integer_internal (v->data.v_simple.datatype));
      if (v->is_array)
	{
	  if (strchr (arrbuff, '-') == 0)
	    {
	      strcat (abuff, "[");
	      strcat (abuff, arrbuff);
	      strcat (abuff, "]");
	    }
	  else
	    {
	      SPRINTF1 (tbuff, "%s *",
			rettype_integer_internal (v->data.v_simple.datatype));
	    }
	}

      if (v->data.v_simple.datatype == DTYPE_CHAR
	  || v->data.v_simple.datatype == DTYPE_VCHAR)
	{			/* Its a 'char' (may need varchar & friends too... */


	  if (v->data.v_simple.datatype == 0)
	    {
	      print_define_char (vbuff, tbuff, abuff,
				 v->data.v_simple.dimensions[0],
				 static_extern_flg, level);
	    }
	  else
	    {
	      print_define_char (vbuff, tbuff, abuff, v->data.v_simple.dimensions[0], static_extern_flg, level);	// Allow extra space to store the size...
	    }
	}
      else
	{

	  print_define (vbuff, tbuff, abuff, static_extern_flg, level);
	}

      return;
    }

  if (v->variable_type == VARIABLE_TYPE_RECORD)
    {
      //int a;
      char *name_ptr;
      name_ptr = name;

      if (strcmp (name, "to") == 0)
	{
	  name_ptr = "xxx_to";
	}
      if (strcmp (name, "from") == 0)
	{
	  name_ptr = "xxx_from";
	}
      if (level == 0)
	{
	  print_structures_in (&v->data.v_record, level + 1, scope);
	}

      if (arrbuff && strcmp (arrbuff, "-1") == 0)
	{
	  if (level)
	    {
	      printh ("$%s=$%s;\n", name_ptr, v->data.v_record.user_ptr);
	    }
	  else
	    {
	      printc ("$%s=$%s;", name_ptr, v->data.v_record.user_ptr);
	    }
	}
      else
	{
	  if (level)
	    {
	      printh ("$%s $%s[%s];\n", name_ptr,
		      v->data.v_record.user_ptr, arrbuff);
	    }
	  else
	    {
	      printc ("$%s $%s[%s];", name_ptr,
		      v->data.v_record.user_ptr, arrbuff);
	    }
	}


      return;
    }


  if (v->variable_type == VARIABLE_TYPE_ASSOC)
    {
      A4GL_assertion (1, "Not implemented");
    }

  if (v->variable_type == VARIABLE_TYPE_CONSTANT)
    {
      /* Maybe we should print out #define's for these ? */
      /* Maybe not - they should already have been converted by lexer.c */
      A4GL_assertion (1, "Not implemented");
    }


}


void
LEXLIB_print_when (int has_expr, t_expr_str * expr)
{
  set_suppress_newlines ();
  if (has_expr)
    {
      printc ("case ");
      print_expr (expr);
      printc (": ");
      when_case_has_expr = 1;
    }
  else
    {
      printc ("if ($case_expr==");
      print_expr (expr);
      printc ("{ # 1");
      when_case_has_expr = 0;
    }
  clr_suppress_newlines ();
  temp_indent++;
}


void
LEXLIB_print_while_1 (void)
{
	printf("/* WHILE 1 */");
}
void
LEXLIB_print_while_2 (t_expr_str * expr)
{
  set_suppress_newlines ();
    printc ("while (");
        real_print_expr (expr);
	  printc (") { #2");
	    clr_suppress_newlines ();
	      temp_indent++;

}

void
LEXLIB_print_while_end (void)
{
	temp_indent--;
	printc("}");
}

/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/

/* Reports */

void
LEXLIB_print_format_every_row (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

int
LEXLIB_print_agg_defines (char t, int a)
{
  niy_assert (__PRETTY_FUNCTION__);
  return 0;
}

void
LEXLIB_print_pause (char *msg)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_rep_ret (int report_cnt, int dolog)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_repctrl_block (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_report_1 (char *name)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_report_2 (int pdf, char *repordby)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_report_2_1 (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_report_ctrl (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_report_end (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_report_print (int type, char *semi, t_expr_str * expr)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_report_print_file (char *fname, char *semi)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_terminate_report (char *repname)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_start_report (char *where, t_expr_str * out,
			   char *repname, char *dimsetting)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_skip_by (double nval)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_skip_lines (double n)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_skip_to (char *nval)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_skip_top (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_need_lines (t_expr_str * expr)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_order_by_type (int type, int size)
{
  niy_assert (__PRETTY_FUNCTION__);
}

/* Enhancements/GUI */

void
LEXLIB_print_call_shared (t_expr_str_list * expr, char *libfile,
			  char *funcname)
{
}

void
LEXLIB_print_include (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_dealloc_arr (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_at_termination (char *f)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_alloc_arr (char *s, char *dim)
{
  niy_assert (__PRETTY_FUNCTION__);
}

int
LEXLIB_print_linked_cmd (int type, char *var)
{
  niy_assert (__PRETTY_FUNCTION__);
  return 0;
}

void
LEXLIB_print_display_array_p1 (char *arrvar, char *srec, char *scroll,
			       char *attr, void *iattr,char *Style)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_display_array_p2 (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_display_form (char *s, char *a,char *Style)
{
  niy_assert (__PRETTY_FUNCTION__);
}




void
LEXLIB_print_display_new (t_expr_str_list * exprs,
			  t_dt_display * disp, char *attr,char *Style)
{
  int a;
  exprs = A4GL_rationalize_list (exprs);
  if (exprs)
    {
      set_suppress_newlines ();
      printc ("print ");
      for (a = 0; a < exprs->nlist; a++)
	{
	  if (a)
	    {
	      printc (".");
	    }
	  real_print_expr (exprs->list[a]);
	}
      printc (".\"\\n\";");
      clr_suppress_newlines ();
    }

}

void
LEXLIB_print_remote_func (char *identifier)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_start_server (char *port, char *funclist)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_stop_external (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_import (char *funcname, int nargs)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_import_legacy (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_report_print_img (char *scaling, char *blob, char *type,
			       char *semi)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_realloc_arr (char *s, char *dim)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void *
LEXLIB_get_def_mn_file (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gtk_field (int type, char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gtk_field_2 (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gtk_menuhandler_1 (char *name)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gtk_menuhandler_bsm (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gtk_menuhandler_bsm_end (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gtk_menuhandler_end (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gtk_menuhandler_on (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gtk_menuhandler_on_end (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gui_do_fields (char *list, int mode)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gui_do_form (char *name, char *list, int mode)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_gui_do_menuitems (char *list, int mode)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_hide_window (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

char **
LEXLIB_CLASS_get_members (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
  return 0;
}

char **
LEXLIB_CLASS_get_variable (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
  return 0;
}

void
LEXLIB_CLASS_add_method (char *name, char *sig)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_CLASS_print_class_variable_type (char *buff)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_CLASS_print_reflector (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_CLASS_set_class_name (char *name)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_CLASS_set_parent_name (char *name)
{
  niy_assert (__PRETTY_FUNCTION__);
}


char *
LEXLIB_A4GL_get_undo_use (void)
{
  return "";
}

void
LEXLIB_print_undo_use (char *s)
{
  /* doesn't need to do anything */
}

void
LEXLIB_print_end_formhandler (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_formhandler (char *name)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_convert_report (char *report_name, char *fout,
			     char *type, char *layoutfile, char *file_or_pipe)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_free_convertable (char *report_name)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_class_func_call (char *var, char *identifier, void *args,
			      int args_cnt)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_declare_associate_1 (char *variable, char *size, char *n)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_declare_associate_2 (char *variable, char *size, char *n)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_use_session (char *sess)
{
  niy_assert (__PRETTY_FUNCTION__);
}


void
LEXLIB_print_pdf_call (char *a1, t_expr_str_list * args, char *a3)
{
  niy_assert (__PRETTY_FUNCTION__);
}

/* UI */
void
LEXLIB_print_input_1 (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_input_2 (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_input_fl (int byname, char *defs, char *helpno,
		       t_field_list * fldlist, char* attr,char *Style)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_prompt_1 (t_expr_str_list * expr, char *a1, char *a2,
		       char *a3, char *a4, int timeout,char *Style)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_prompt_end (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_prompt_forchar (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_menu_1 (int n)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_menu_1b (int n)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_befaft_field_1 (char *fieldexpr)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_befaft_field_2 (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

char *
LEXLIB_A4GL_get_formloop_str (int type)
{
  niy_assert (__PRETTY_FUNCTION__);
  return 0;
}

char *
LEXLIB_print_input_array (char *arrvar, char *helpno, char *defs,
			  char *srec, char *attr, void *inp_attr,char *Style)
{
  niy_assert (__PRETTY_FUNCTION__);
  return 0;
}

char *
LEXLIB_get_keyval_str (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
  return 0;
}

char *
LEXLIB_A4GL_get_display_str (int type, char *s, char *f)
{
}
void
LEXLIB_print_clr_fields_fl (t_field_list * flds, char *defs)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_clr_form (char *formname, char *clr, char *defs)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_clr_status (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_clr_window (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_continue_loop (int n, char *s)
{
	printc ("goto CONTINUE_BLOCK_%d;", n);
}

void
LEXLIB_print_current_window (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_show_menu (char *mname, char *mhand, void *ptr)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_show_window (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_screen_mode (int n)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_scroll (char *flds, char *updown)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_onaction_1 (char *action)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_onaction_2 (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_onkey_1 (char *key_list_str)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_onkey_2 (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_onkey_2_prompt (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_ontimer_1 (char *action)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_ontimer_2 (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_next_field (char *s)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_next_form_field (char *form, char *field)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_move_window (char *n, void *y_expr, void *x_expr, int rel)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_menu_block (int n, int menu_no)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_menu_block_end (int m, int n)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_message (t_expr_str_list * expr, int type, char *attr, int wait,char *Style)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_getfldbuf (char *fields)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_getwin (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_open_form (char *a1, t_expr_str * a2)
{
	printf("//print_open_form\n");
}

void
LEXLIB_print_open_form_gui (char *fname, char *at_gui, char *like_gui,
			    char *disable, char *formhandler)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_open_window (char *name, t_ow_open_window * type,
			  t_expr_str * y, t_expr_str * x,char *Text,char *Style)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_event (int type)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_error (t_expr_str_list * exprs, char *s, int wait,char *Style)
{
  int a;
  exprs = A4GL_rationalize_list (exprs);
  if (exprs)
    {
      set_suppress_newlines ();
      printc ("echo \"Error:\"");
      for (a = 0; a < exprs->nlist; a++)
	{
	  printc (".");
	  real_print_expr (exprs->list[a]);
	}
      printc (";");
      clr_suppress_newlines ();
    }

}

void
LEXLIB_print_end_menu_1 (int n)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_end_menu_2 (int n)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_event_2 (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_construct_1 (void)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_construct_2 (char *driver)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_construct_fl (int byname, char *constr_str,
			   t_field_list * field_list, char *attr, int cattr,char *Style)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_form_is_compiled (char *s, char *packer, char *formtype)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_output_to_report (t_expr_str_list * expr, char *repname)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_field_func (char type, char *name, char *var)
{
  niy_assert (__PRETTY_FUNCTION__);
}

void
LEXLIB_print_finish_report (char *repname)
{
  niy_assert (__PRETTY_FUNCTION__);
}







/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*********************************************************************************************************************/























static int
is_just_expr_clipped (char *v, struct expr_str_list *ptr)
{
  struct expr_str *p;
  if (ptr->nlist != 1)
    {
      return 0;
    }
  p = ptr->list[0];

  if (p->expr_type == ET_EXPR_OP_CLIP)
    {
      p = p->u_data.expr_expr;
      if (p->expr_type == ET_EXPR_PUSH_VARIABLE)
	{
	  if (strcmp (p->u_data.expr_push_variable->variable, v) == 0)
	    {
	      return 1;
	    }
	}

    }
  return 0;

}


struct expr_str_list *
A4GL_rationalize_list_concat (struct expr_str_list *l)
{
  int a;
  struct expr_str *p;
  struct expr_str *p2;
  struct expr_str_list *l2;
  //int b;
  //int printed = 0;

  if (l == 0)
    return 0;
  l = A4GL_rationalize_list (l);

  if ((l->nlist) > 1)
    {
      for (a = 0; a < l->nlist - 1; a++)
	{
	  //int pt1;
	  //int pt2;
	  p = l->list[a];
	  p2 = l->list[a + 1];


	  if (p->expr_type == ET_EXPR_LITERAL_STRING
	      && p2->expr_type == ET_EXPR_LITERAL_STRING)
	    {
	      // They're concating two literal strings - lets make the second one empty..
	      // and concat the strings *now* rather than runtime...
	      char *x1;
	      char *x2;
	      char *x3;
	      x1 = p->u_data.expr_string;
	      x2 = p2->u_data.expr_string;
	      x3 = malloc (strlen (x1) + strlen (x2) + 1);
	      strcpy (x3, x1);
	      strcat (x3, x2);
	      p->expr_type = ET_EXPR_REDUCED;
	      p2->u_data.expr_string = x3;
	    }
	}
    }



  l2 = A4GL_new_ptr_list (0);

  for (a = 0; a < l->nlist; a++)
    {
      p = l->list[a];
      if (p->expr_type != ET_EXPR_REDUCED)
	{
	  A4GL_new_append_ptr_list (l2, p);
	}
    }

  l = l2;

  return l;
}


char *
is_single_string (struct expr_str_list *ptr)
{
  return 0;
}




int
is_ignore_var (char *var)
{
  return 0;
}


char *need_globals_var[20000];
int need_globals_var_cnt = 0;


void
free_need_globals (void)
{
  int a;
  if (need_globals_var_cnt)
    {
      for (a = 0; a < need_globals_var_cnt; a++)
	{
	  free (need_globals_var[a]);
	  need_globals_var[a] = 0;
	}
      need_globals_var_cnt = 0;
    }
}

void need_globals (char *s)
{
  char buff[255];
  char *ptr;
  int a;
// Does nothing yet
// we need to issue a "global" statement at the top of any functions
// for any module or global variable used within that function
  if (strcmp (curr_func, "Module") == 0)
    return;
  strcpy (buff, s);
  ptr = strchr (buff, '.');
  if (ptr)
    *ptr = 0;
  ptr = strchr (buff, '[');
  if (ptr)
    *ptr = 0;
  for (a = 0; a < need_globals_var_cnt; a++)
    {
      if (strcmp (need_globals_var[a], buff) == 0)
	return;
    }
  need_globals_var[need_globals_var_cnt++] = strdup (buff);

  //printf ("%s %s\n", curr_func, buff);
}


char *encode_records (char *s)
{
  static char buff[20000];
  int a;
  int c;
  int b = 0;
  int last;
  int using_globals_var=0;

  if (s[0]=='M'||s[0]=='G') {
	  //strcpy(buff,"GLOBALS[\"");
	  //b=strlen(buff);
	  //using_globals_var=1;
  }


  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] != '.')
	{
	  buff[b++] = s[a];
	  continue;
	}
      last = -1;
      for (c = a + 1; c < strlen (s) + 1; c++)
	{
	  if (s[c] >= 'a' && s[c] <= 'z')
	    continue;
	  if (s[c] >= 'A' && s[c] <= 'Z')
	    continue;
	  if (s[c] == '_')
	    continue;
	  // found the last character!
	  last = c;
	  break;
	}

      if (last >= 0)
	{
		if (using_globals_var) {
			using_globals_var=0;
			buff[b++]='\'';
			buff[b++]=']';
		}
	  buff[b++] = '[';
	  buff[b++] = '"';
	  for (c = a + 1; c < last; c++)
	    {
	      buff[b++] = s[c];
	    }
	  buff[b++] = '"';
	  buff[b++] = ']';
	  a = last - 1;
	} 
    }


  if (using_globals_var) {
	    	using_globals_var=0;
		buff[b++]='\'';
		buff[b++]=']';
		buff[b]=0;
  }
  buff[b++] = 0;
  return buff;
}



char *
use_scope (char *s)
{
  static char buff[2000];
  //printf("USE SCOPE %s\n",s);
  if (s[0] == 'G' || s[0] == 'M' || s[0] == 'R')
    {
      need_globals (s);
      sprintf (buff, "%s", s);
      return encode_records (check_for_reserved_words (buff));
    }


/*
  if (strcmp (s, "a4gl_status") == 0)
    {
      return "a4gl_status";
    }
  if (strncmp (s, "a4gl_sqlca", 10) == 0)
    {
      sprintf (buff, "%s", s);
      return strdup (buff);
    }
*/

  return encode_records (check_for_reserved_words (s));
}



void
set_suppress_lines (void)
{
  suppress_lines++;
}

void
clr_suppress_lines (void)
{
  suppress_lines--;
}

void
set_suppress_newlines (void)
{
  if (suppress_newlines == 0)
    {
      print_space ();
    }
  suppress_newlines++;
}

void
clr_suppress_newlines (void)
{
  suppress_newlines--;

  if (suppress_newlines == 0)
    {
      printc_nl ();
    }
}

char *
fixup_squares (char *s)
{
  return s;

/*
  static char buff[20000];
  int a;
  strcpy (buff, s);
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == ']' && s[a + 1] == '[')
	{
	  buff[a] = ',';
	  buff[a + 1] = ' ';
	}
    }
  return buff;
*/
}


void
ensure_dtype (struct expr_str *e, int dtype, int notnull)
{
  return;
}


char *
check_for_reserved_words (char *s)
{
  //static char buff[256];
  char *ptr;

  return s;





  if (strstr (s, "to") || strstr (s, "from"));
  else
    {
      return s;
    }

  //ptr = has_reserved (s, "to", "xxx_to");
  //if (ptr)
  //return ptr;
//
  //ptr = has_reserved (s, "from", "xxx_from");
  //if (ptr)
  //return ptr;

  return s;
}



char *
anon_prepare (char *s)
{
  static char buff[20000];
  static char buff2[20000];
  static int cnt = 0;
  char *s2;

  if (A4GL_isyes (acl_getenv ("LEGACY")))
    {
      SPRINTF2 (buff, "__%s_%d", A4GL_compiling_module_basename (), yylineno);
    }
  else
    {
      SPRINTF2 (buff, "__%s_%d", A4GL_compiling_module_basename (), cnt++);
    }
  SPRINTF1 (buff2, "\"%s\"", buff);

  s2 = malloc (strlen (s) + 10);
  if (s[0] != '"')
    {
      SPRINTF1 (s2, "\"%s\"", s);
    }
  else
    {
      strcpy (s2, s);
    }
  LEXLIB_print_prepare (buff2, s2);
  free (s2);
  return buff;

}




void
LEXLIB_print_module_variable_init (void)
{
  printc ("$Done_init_module_variables_%s=0;\n",
	  A4GL_compiling_module_basename ());
  printc ("sub Init_module_variables_%s() {",
	  A4GL_compiling_module_basename ());
  temp_indent++;
  printc ("if ($Done_init_module_variables_%s) {return;}",
	  A4GL_compiling_module_basename ());
  printc ("$Done_init_module_variables_%s=1;",
	  A4GL_compiling_module_basename ());
  setting_module_to_null = 1;
  print_nullify ('M');
  setting_module_to_null = 0;
  temp_indent--;
  printc ("}");
  printc ("\n");

}


void
print_function_variable_init (void)
{
  printc ("Init_module_variables_%s();", A4GL_compiling_module_basename ());
  print_nullify ('F');
}

static char *
make_arr_str (char *s, struct variable *v)
{
  int a;
  char buff[256];
  int tot;
  strcpy (s, "");
  tot = 1;
  for (a = 0; a < MAX_ARR_SUB; a++)
    {
      if (v->arr_subscripts[a])
	{
	  tot *= v->arr_subscripts[a];
	  if (a)
	    strcat (s, ",");
	  SPRINTF1 (buff, "%d", v->arr_subscripts[a]);
	  strcat (s, buff);
	}
      else
	{
	  break;
	}
    }
  return strdup (s);
}



int
is_param (char *s)
{
  int a;
  char buff[256];
  if (fbindcnt == 0)
    return 0;
  if (isin_command ("REPORT"))
    return 0;

  //expand_bind (&fbind[0], 'F', fbindcnt, 1);
  for (a = 0; a < fbindcnt; a++)
    {
      //char *ptr;
      strcpy (buff, fbind[a].varname);
      //ptr=strchr(buff,'.'); if (ptr) { *ptr=0; }

      if (strcmp (s, buff) == 0)
	{
	  return 1;
	}
    }
  return 0;
}


char *
rettype_integer_internal (int n)
{
  return rettype_integer (n & DTYPE_MASK);
}




/**
 * Print the declaration of a char variable.
 *
 * The type of the variable comes in the first parameter.
 *
 * @param var The variable name and type.
 * @param size The size of the variable.
 * @param isstatic_extern The storage class used:
 *   - 1 : Static
 *   - 2 : Extern
 *   - Otherwise : Not static and not extern
 */

//vbuff,tbuff,abuff
static void
print_define_char (char *vbuff, char *tbuff, char *abuff,
		   int size, int isstatic_extern, int lvl)
{
  char buff[20];
  strcpy (buff, "");


return;


  if (lvl)
    {
      printh ("var $%s%s%s;\n", buff, vbuff, abuff);
    }
  else
    {
      if (strlen (abuff) || 1)
	{
	  if (isin_command ("REPORT"))
	    {
	      printh ("var $%s%s%s;\n", buff, vbuff, abuff);
	    }
	  else
	    {
	      printc ("var $%s%s%s;\n", buff, vbuff, abuff);
	    }
	}
      else
	{
	  if (isin_command ("REPORT"))
	    {
	      printh ("var $%s%s%s=$null #VSET;\n", buff, vbuff, abuff);
	    }
	  else
	    {
	      printc ("var $%s%s%s=$null #VSET;\n", buff, vbuff, abuff);
	    }
	}
    }
}




/**
 * Prints a variable declaration to the generated file.
 *
 * The type of the variable comes in the first parameter.
 *
 * @param varstring String with variable declaration
 * @param isstatic_extern The modifier of variable:
 *   - 1 : Variable should be declared as static
 *   - 2 : Variable should be declared as extern
 */
static void
print_define (char *vbuff, char *tbuff, char *abuff,
	      int isstatic_extern, int lvl)
{
  char buff[20];



  return;



  strcpy (buff, "");
/*
  if (is_ignore_var (vbuff) && lvl == 0)
    {
      return;
    }
*/

  if (strcmp (vbuff, "to") == 0)
    {
      vbuff = "xxx_to";
    }
  if (strcmp (vbuff, "from") == 0)
    {
      vbuff = "xxx_from";
    }

  if (lvl)
    {

      printh ("%s%s%s;\n", buff, vbuff, abuff);
    }
  else
    {
      if (isin_command ("REPORT"))
	{
	  if (strlen (abuff) == 0 && 0)
	    {
	      printh ("$%s%s%s=$null /*VSET*/;\n", buff, vbuff, abuff);
	    }
	  else
	    {
	      printh ("$%s%s%s=$null;\n", buff, vbuff, abuff);
	    }

	}
      else
	{

	  if (strlen (abuff) == 0 && 0)
	    {
	      printc ("$%s%s%s=$null #VSET;\n", buff, vbuff, abuff);
	    }
	  else
	    {
	      printc ("$%s%s%s=$null;\n", buff, vbuff, abuff);
	    }
	}
    }
}


void
print_structures_in (struct record_variable *v, int lvl, int scope)
{
  struct variable *vn;
  int a;
  static int c = 0;
  char buff[20055];
  char sbuff[20];
  temp_indent++;
  for (a = 0; a < v->record_cnt; a++)
    {
      vn = v->variables[a];
      if (vn->variable_type == VARIABLE_TYPE_RECORD)
	{
	  print_structures_in (&vn->data.v_record, lvl + 1, scope);
	}
    }
  temp_indent--;
  SPRINTF2 (v->user_ptr, "Fake_%s_%d",
	    A4GL_compiling_module_basename (), c++);

  SPRINTF0 (buff, "array (\n   ");

  for (a = 0; a < v->record_cnt; a++)
    {
      vn = v->variables[a];
      if (a)
	{
	  strcat (buff, ",\n   ");
	}
      sprintf (sbuff, "\"%s\"=>\"\"", vn->names.name);
      strcat (buff, sbuff);

      //LEXLIB_print_variable_new (vn, scope, lvl + 1);
    }
  strcat (buff, ");");

  printh ("$%s=%s\n", v->user_ptr, buff);
  printh ("\n");
}


char *
valid_func_name (char *s)
{
  return s;
}


static void
add_used_block (int n, char *btype)
{
  char buff[200];
  SPRINTF2 (buff, "%s_%d", btype, n);
  A4GL_add_pointer (buff, BLOCK_USED, (void *) 1);
}

static int
is_used_block (int n, char *btype)
{
  char buff[200];
  SPRINTF2 (buff, "%s_%d", btype, n);
  return A4GL_has_pointer (buff, BLOCK_USED);
}




int
print_bind_set_value_param_2 (char *cname, char i)
{
  int a;
  char *xx;

  xx = strdup (A4GL_strip_quotes (cname));

  if (i == 'o')
    {
      if (A4GL_has_pointer (xx, CURSOR_BIND_O))
	{
	  struct s_save_binding *s;
	  // Saved results....
	  if (obindcnt == 0)
	    {
	      s = A4GL_find_pointer (xx, CURSOR_BIND_O);
	      if (s)
		{
		  //int a;
		  extern long a_obind;
		  obind = ensure_bind (&a_obind, s->nbind + 1, obind);
		  obindcnt = s->nbind;
		  memcpy (obind, s->bind,
			  sizeof (struct binding_comp) * s->nbind);
		}
	    }
	}

      for (a = 0; a < obindcnt; a++)
	{
	  printc ("@%s=$%s[%d];\n", use_scope (obind[a].varname),
		  Rname (xx), a);
	}
      start_bind (i, 0);
      return a;
    }
  if (i == 'i')
    {

      for (a = 0; a < ibindcnt; a++)
	{
	  printc ("$%s->Parameter(%d,$%s);", Cname (xx), a,
		  use_scope (ibind[a].varname));
	}
      start_bind (i, 0);
      return a;
    }

  A4GL_assertion (1, "End of function");
  return 0;
}


char * find_record_dot (char *s)
{
  int c;
  int count_squares = 0;
  for (c = 0; c < strlen (s); c++)
    {
      if (s[c] == '[')
	count_squares++;
      if (s[c] == ']')
	count_squares--;
      if (count_squares == 0 && s[c] == '.')
	{
	  return &s[c];
	}
    }
  return 0;
}



int print_bind_set_value_param_3 (char *cname, char i)
{
  int a;
  char *xx;
  cname = strdup (cname);
  xx = strdup (A4GL_strip_quotes (cname));

  if (i == 'o')
    {
      printc("if (@%s) {",Rname (xx));
      for (a = 0; a < obindcnt; a++)
        {
          printc ("$%s=$%s[%d];\n", use_scope (obind[a].varname),Rname (xx), a);
        }
      printc("}");
      start_bind (i, 0);
      return a;
    }


  if (i == 'i')
    {

      for (a = 0; a < ibindcnt; a++)
        {
          if (ibind[a].varname[0] == 'G' || ibind[a].varname[0] == 'M')
            {
              print_prepare_in_header(xx);
              printc ("$%s->Parameter(%d,$%s);", Pname (xx), a,
                      use_scope(ibind[a].varname));
            }
          else
            {
              print_prepare_in_header(xx);
              printc ("$%s->Parameter(%d,$%s);", Pname (xx), a,
                      use_scope(ibind[a].varname));
            }
        }
      start_bind (i, 0);
      return a;
    }
  A4GL_assertion (1, "End of function");
  return 0;
}



void
LEXLIB_print_fetch_3 (struct s_fetch *fp, char *into)
{
  int x;
  struct expr_str *p;
  char *xx;
  x = obindcnt;

  xx = strdup (A4GL_strip_quotes (fp->cname));

  p = fp->fp->fetch_expr;
  if (fp->fp->ab_rel == FETCH_RELATIVE)
    {
      if (p->expr_type == ET_EXPR_LITERAL_LONG)
        {
          if (p->u_data.expr_long == 1)
            {
              printc ("$DC_%s->MoveNext();", Cname (xx));
            }
          if (p->u_data.expr_long == -1)
            {
              printc ("$DC_%s->MovePrevious();", Cname (xx));
            }
          if (p->u_data.expr_long != 1 && p->u_data.expr_long != -1)
            {
              printc ("$DC_%s->MoveRelative(%d);", Cname (xx),
                      p->u_data.expr_long);
            }
        }
      else
        {
          set_suppress_newlines ();
          printc ("$DC_%s->MoveRelative(", Cname (xx),
                  p->u_data.expr_long);
          print_expr (fp->fp->fetch_expr);
          printc (");");
          clr_suppress_newlines ();
        }
    }
  else
    {
      if (p->expr_type == ET_EXPR_LITERAL_LONG)
        {
          if (p->u_data.expr_long == 1)
            {
              printc ("$DC_%s->MoveFirst();", Cname (xx));
            }
          if (p->u_data.expr_long == -1)
            {
              printc ("$DC_%s->MoveLast();", Cname (xx));
            }
          if (p->u_data.expr_long != 1 && p->u_data.expr_long != -1)
            {
              printc ("$DC_%s->MoveAbsolute(%d);", Cname (xx), p->u_data.expr_long);
            }
        }
      else
        {
          set_suppress_newlines ();
          printc ("$DC_%s->MoveAbsolute(", Cname (xx));
                //ensure_int(fp->fp->fetch_expr,1);
          print_expr (fp->fp->fetch_expr);
          printc (");");
          clr_suppress_newlines ();
        }
    }

  printc ("if  (a4gl_sqlca.sqlcode==0) {");
  temp_indent++;
  printc ("@DR_%s=$DC_%s->Current();", Rname (xx), Cname (xx));
  print_bind_set_value_param_2 (fp->cname, 'o');
  temp_indent--;
  printc ("}");
  obindcnt = 0;
}

		
void LEXLIB_A4GL_initlex() {
	// required by API
}
