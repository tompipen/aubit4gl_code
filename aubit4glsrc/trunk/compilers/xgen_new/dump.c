#include <stdio.h>
#include "elements.h"
#include <string.h>
#include <stdlib.h>

extern struct s_elements *all_elements;
extern int nall_elements;



extern struct s_enum *all_enums;
extern int nall_enums;

int istypedef(char *s) {
	if (strcmp(s,"command_ptr")==0) return 1;
	if (strcmp(s,"cons_list_entry_ptr")==0) return 1;
	if (strcmp(s,"elements_ptr")==0) return 1;
	if (strcmp(s,"expr_str_ptr")==0) return 1;
	if (strcmp(s,"module_entry_ptr")==0) return 1;
	if (strcmp(s,"on_event_ptr")==0) return 1;
	if (strcmp(s,"report_format_section_entry_ptr")==0) return 1;
	if (strcmp(s,"s_table_list_element_ptr")==0) return 1;
	if (strcmp(s,"single_option_ptr")==0) return 1;
	if (strcmp(s,"variable_ptr")==0) return 1;
	if (strcmp(s,"when_ptr")==0) return 1;
	return 0;
}


int check_for_ptr(char *s, char *d, int context) {
// Check for typedefs - atm these are all hardcoded, need to fix this later...
	if (strcmp(d,"variable_ptr")==0) return 1;
	if (strcmp(d,"command_ptr")==0) return 1;
	if (strcmp(d,"expr_str_ptr")==0) return 1;
	if (strcmp(d,"single_option_ptr")==0) return 1;
	if (strcmp(d,"report_format_section_entry_ptr")==0) return 1;
	if (strcmp(d,"when_ptr")==0) return 1;
	if (strcmp(d,"on_event_ptr")==0) return 1;
	if (strcmp(d,"cons_list_entry_ptr")==0) return 1;
	if (strcmp(d,"module_entry_ptr")==0) return 1;
	if (strcmp(d,"elements_ptr")==0) return 1;
	if (strcmp(d,"s_table_list_element_ptr")==0) return 1;
return 0;
}

int
findit (struct s_dtype *d)
{
  int a;
// Is it an enum ? 


  for (a = 0; a < nall_enums; a++)
    {
      if (strcmp (all_enums[a].enum_name, d->type) == 0)
	{
	  d->isunknown = 0;
	  d->isenum = 1;
	  return 1;
	}
    }




  for (a = 0; a < nall_elements; a++)
    {
      if (strcmp (all_elements[a].union_or_struct_name, d->type) == 0)
	{
	  d->isunknown = 0;
	  if (strlen (all_elements[a].union_switch_on_enum_type))
	    {
	      d->isunion = 1;
	    }
	  else
	    {
	      d->isstruct = 1;
	    }
	  return 1;
	}
    }
  return 0;
}


int
findit2 (struct s_dtype *d)
{
  int a;
// Is it an enum ? 


  d->isunknown =1;
  d->isenum =0;
  d->isstruct=0;
  d->isunion=0;

  for (a = 0; a < nall_enums; a++)
    {
      if (strcmp (all_enums[a].enum_name, d->type) == 0)
	{
	  d->isunknown = 0;
	  d->isenum = 1;
	  return 1;
	}
    }


  if (istypedef( d->type) ) {
	char buff[2000];
	char *ptr;

	 strcpy(buff,  d->type);
	ptr=strstr(buff,"_ptr");
	if (ptr) {
		*ptr=0;
		d->type=strdup(buff);
		//d->isptr=1;
	}
  }

  for (a = 0; a < nall_elements; a++)
    {
      if (strcmp (all_elements[a].union_or_struct_name, d->type) == 0)
	{
	  d->isunknown = 0;
	  if (strlen (all_elements[a].union_switch_on_enum_type))
	    {
	      d->isunion = 1;
	    }
	  else
	    {
	      d->isstruct = 1;
	    }
	  return 1;
	}
    }
  return 0;
}

char ustr[20000] = "";
void
clr_printed_union ()
{
  strcpy (ustr, "");
}

int
already_printed_union (char *s)
{
  char sbuff[200];
  sprintf (sbuff, "{%s}", s);
  //printf ("Checking for %s in %s", s, ustr);
  if (strstr (ustr, sbuff))
    {
      //printf ("found\n");
      return 1;
    }
  //printf ("Not found\n");
  strcat (ustr, sbuff);
  return 0;
}

void
dump_xs_h (char *name)
{
  FILE *hfile;
  int a;
  char buff[256];
  sprintf (buff, "%s.xh.h", name);
  hfile = fopen (buff, "w");
  if (!hfile)
    return;

  fprintf (hfile, "#ifndef XS_%s_XS_H\n", name);
  fprintf (hfile, "#define XS_%s_XS_H\n", name);
  fprintf (hfile, "#ifndef bool\n");
  fprintf (hfile, "#define bool int\n");
  fprintf (hfile, "#endif\n");
  fprintf (hfile, "\n");
  fprintf (hfile, "#define istypedefed\n");
  fprintf (hfile, "#include <stdio.h>\n");
  fprintf (hfile, "#include <stdlib.h>\n");
  fprintf (hfile, "#ifndef STDTYPEDEF\n");
  fprintf (hfile, "#define STDTYPEDEF\n");
  fprintf (hfile, "typedef char *funcname;\n");
  fprintf (hfile, "typedef char *str;\n");
  fprintf (hfile, "typedef char *sql_ident;\n");
  /*if (strcmp (name, "cmds") != 0)
    {
      fprintf (hfile, "typedef char *ex_str;\n");
    }
  */
  fprintf (hfile, "#endif\n");
  fprintf (hfile, "\n");


// First off - lets dump our enums
  for (a = 0; a < nall_enums; a++)
    {
      int b;
      fprintf (hfile, "enum %s {\n", all_enums[a].enum_name);
      for (b = 0; b < all_enums[a].nelements; b++)
	{
	  if (b < all_enums[a].nelements - 1)
	    {
	      fprintf (hfile, "  %s=%d,\n",
		       all_enums[a].elements[b].element_name,
		       all_enums[a].elements[b].val);
	    }
	  else
	    {
	      fprintf (hfile, "  %s=%d\n",
		       all_enums[a].elements[b].element_name,
		       all_enums[a].elements[b].val);
	    }
	}
      fprintf (hfile, "};\n");
      fprintf (hfile, "typedef enum %s t_%s;\n\n", all_enums[a].enum_name,
	       all_enums[a].enum_name);

    }






  for (a = 0; a < nall_elements; a++)
    {
      int b;
      int isunion = 0;

      if (strlen (all_elements[a].union_switch_on_enum_type))
	{
	  fprintf (hfile, "struct %s {\n",
		   all_elements[a].union_or_struct_name);
	  isunion = 1;
	  fprintf (hfile, "  enum %s %s;\n",
		   all_elements[a].union_switch_on_enum_type,
		   all_elements[a].union_switch_on_enum_name);
	  fprintf (hfile, "  union {\n");

	}
      else
	{
	  fprintf (hfile, "struct %s { /* 1 */\n",
		   all_elements[a].union_or_struct_name);
	}


      for (b = 0; b < all_elements[a].nelements; b++)
	{
	  struct s_element *e;
	  int stars = 0;
	  e = &all_elements[a].elements[b];


	  if (e->datatype.isvoid)
	    continue;
	  if (e->datatype.isunknown)
	    {
	      findit (&e->datatype);
	    }

	  if (e->vname.is_vararray)
	    {
	      fprintf (hfile, "struct {\n");
	      fprintf (hfile, "  unsigned int %s_len;\n", e->vname.name);
	    }


	  if (isunion)
	    fprintf (hfile, "  ");	// extra little bit of indent

	  if (isunion)
	    {
	      int skip = 0;
	      if (b)
		{
		  int c;
		  struct s_element *e2;

		  for (c = 0; c < b; c++)
		    {
		      if (c == b)
			continue;
		      e2 = &all_elements[a].elements[c];
		      if (e2->vname.name == 0)
			continue;	// void...
		      if (strcmp
			  (e->vname.name,
			   all_elements[a].elements[c].vname.name) == 0)
			{	// Already printed...
			  skip++;
			  continue;
			}

		    }
		}

	      if (skip)
		continue;

	      if (!skip)
		{
		  if (e->datatype.isstruct)
		    {
		      fprintf (hfile, "  struct %s /* 2 */", e->datatype.type);
		    }
		  else
		    {
		      if (e->datatype.isenum)
			{
			  fprintf (hfile, "  enum %s", e->datatype.type);
			}
		      else
			{

			  if (strcmp (e->datatype.type, "str") == 0
			      || strcmp (e->datatype.type, "char") == 0
			      || strcmp (e->datatype.type, "funcname") == 0
			      || strcmp (e->datatype.type, "short") == 0
			      || strcmp (e->datatype.type, "long") == 0
			      || strcmp (e->datatype.type, "sql_ident") == 0
			      || strcmp (e->datatype.type, "ex_str") == 0
			      || strcmp (e->datatype.type, "int") == 0
			      || strcmp (e->datatype.type, "double") == 0)
			    {
			      fprintf (hfile, "  %s /*known*/",
				       e->datatype.type);
			    }
			  else
			    {
			      fprintf (hfile, "  struct %s /* 3 */",
				       e->datatype.type);
			    }
			}
		    }
		}
	    }
	  else
	    {
	      if (e->datatype.isstruct)
		{
		  fprintf (hfile, "  struct %s/* 4 */", e->datatype.type);
		}
	      else
		{
		  if (e->datatype.isenum)
		    {
		      fprintf (hfile, "  enum %s", e->datatype.type);

		    }
		  else
		    {
		      if (strcmp (e->datatype.type, "str") == 0
			  || strcmp (e->datatype.type, "char") == 0
			  || strcmp (e->datatype.type, "funcname") == 0
			  || strcmp (e->datatype.type, "short") == 0
			  || strcmp (e->datatype.type, "long") == 0
			  || strcmp (e->datatype.type, "sql_ident") == 0
			  || strcmp (e->datatype.type, "ex_str") == 0
			  || strcmp (e->datatype.type, "int") == 0
			  || strcmp (e->datatype.type, "double") == 0)
			{
			  fprintf (hfile, "  %s /*known*/", e->datatype.type);
			}
		      else
			{
			
				if (istypedef(e->datatype.type)) {
			  		fprintf (hfile, "  %s /* 5 */", e->datatype.type);
				} else {
			  		fprintf (hfile, "  struct %s /* 5 */", e->datatype.type);
				}
			}
		    }
		}
	    }
	  if (e->vname.is_ptr )
	    stars++;

	  if (e->vname.is_vararray)
	    {
	      switch (stars)
		{
		case 0:
		  fprintf (hfile, " *%s_val", e->vname.name);
		  break;
		case 1:
		  fprintf (hfile, " **%s_val", e->vname.name);
		  break;
		}
	    }
	  else
	    {
	      switch (stars)
		{
		case 0:
		  fprintf (hfile, " %s", e->vname.name);
		  break;
		case 1:
		  fprintf (hfile, " *%s", e->vname.name);
		  break;
		}
	    }

	  if (e->vname.is_array)
	    {
	      fprintf (hfile, "[%d]", e->vname.is_array);
	    }
	  fprintf (hfile, ";\n");
	  if (e->vname.is_vararray)
	    {
	      fprintf (hfile, "} %s;\n", e->vname.name);
	    }

	}

      if (isunion)
	{
	  fprintf (hfile, "  } %s_u;\n",
		   all_elements[a].union_or_struct_name);
	}

      fprintf (hfile, "};\n");
      fprintf (hfile, "typedef struct %s t_%s;\n", all_elements[a].union_or_struct_name, all_elements[a].union_or_struct_name);

      fprintf (hfile, "\n\n");


    }
  fprintf (hfile, "#endif /*XS_%s_XS_H*/\n", name);


  fclose (hfile);
}



void
dump_write_xml (char *name)
{
  FILE *hfile;
  FILE *hfile_proto;
  int a;
  char buff[256];
  int *printed = 0;

  sprintf (buff, "%s.xo.c", name);
  hfile = fopen (buff, "w");
  if (!hfile)
    return;

  sprintf (buff, "%s.xoh.h", name);
  hfile_proto = fopen (buff, "w");
  if (!hfile_proto)
    return;

  fprintf (hfile, "#include \"%s.xnew.h\"\n", name);
  fprintf (hfile, "#include \"a4gl_libaubit4gl.h\"\n");
  fprintf (hfile, "extern FILE *ofile;\n\n");


// First off - lets dump our enums
  for (a = 0; a < nall_enums; a++)
    {
      int b;
      fprintf (hfile, "char *XMLEnumString_%s(int evalue) {\n",
	       all_enums[a].enum_name);
      fprintf (hfile_proto, "char *XMLEnumString_%s(int evalue) ;\n",
	       all_enums[a].enum_name);
      fprintf (hfile, "  switch (evalue) {\n");
      for (b = 0; b < all_enums[a].nelements; b++)
	{
	  fprintf (hfile, "  case %s: return \"%s\"; \n",
		   all_enums[a].elements[b].element_name,
		   all_enums[a].elements[b].element_name);
	}
      fprintf (hfile, "  }\n");
      fprintf (hfile, "  return \"BAD\";\n");
      fprintf (hfile, "}\n\n");
    }


  for (a = 0; a < nall_enums; a++)
    {
      int b;
      fprintf (hfile_proto, "int xmlbest_reader__decode_%s(char * evalue) ;\n", all_enums[a].enum_name);
      fprintf (hfile, "int xmlbest_reader__decode_%s(char * evalue) {\n", all_enums[a].enum_name);
      for (b = 0; b < all_enums[a].nelements; b++)
	{
	  fprintf (hfile, "  if (strcmp(evalue,\"%s\")==0) { return %s; }\n",
		   all_enums[a].elements[b].element_name,
		   all_enums[a].elements[b].element_name);
	}
      fprintf (hfile, "return 0;\n");
      fprintf (hfile, "}\n\n");
    }

  for (a = 0; a < nall_elements; a++)
    {
      int b;
      //int isunion=0;
      int issimple = 1;
      char union_match_before[2000];
      char union_match_after[2000];
      char union_name[2000];



      fprintf (hfile, "int XMLWrite_%s_std(char *nm, t_%s *f) { \n",
	       all_elements[a].union_or_struct_name,
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_proto, "int XMLWrite_%s_std(char *nm, t_%s *f) ; \n",
	       all_elements[a].union_or_struct_name,
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_proto, "#ifndef XMLWrite_%s\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_proto, "#define XMLWrite_%s XMLWrite_%s_std\n",
	       all_elements[a].union_or_struct_name,
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_proto, "#endif\n");

      fprintf (hfile, "if (f==0) return 1;");	/* null pointer */

      fprintf (hfile, "gzfprintf(ofile,\"<%s ",
	       all_elements[a].union_or_struct_name);


      if (strlen (all_elements[a].union_switch_on_enum_type))
	{			// Its a union..
	  fprintf (hfile, "%s='%%s' \", XMLEnumString_%s(f->%s));\n",
		   all_elements[a].union_switch_on_enum_type,
		   all_elements[a].union_switch_on_enum_type,
		   all_elements[a].union_switch_on_enum_name);

	}
      else
	{
	  fprintf (hfile, "\");\n");
	}

      fprintf (hfile, "if (nm) {gzfprintf(ofile,\"nm='%%s' \",nm);}\n");
      printed =
	realloc (printed, (all_elements[a].nelements + 1) * sizeof (long));

      for (b = 0; b < all_elements[a].nelements; b++)
	{
	  struct s_element *e;
	  e = &all_elements[a].elements[b];
	  printed[b] = 0;
	  strcpy (union_match_before, "");
	  strcpy (union_match_after, "");
	  strcpy (union_name, "");

	  if (strlen (all_elements[a].union_switch_on_enum_type))
	    {
	      sprintf (union_match_before, "if (f->%s==%s) {",
		       all_elements[a].union_switch_on_enum_name,
		       e->switch_on);
	      sprintf (union_match_after, "}");
	      sprintf (union_name, "%s_u.",
		       all_elements[a].union_or_struct_name);
	    }




	  if (e->datatype.isenum)
	    {
	      printed[b] = 1;
	      fprintf (hfile,
		       "%sgzfprintf(ofile,\"%s='%%s' \", XMLEnumString_%s(f->%s%s));%s\n",
		       union_match_before, e->vname.name, e->datatype.type,
		       union_name, e->vname.name, union_match_after);
	      continue;
	    }

	  if ((strcmp (e->datatype.type, "int") == 0 || strcmp (e->datatype.type, "long") == 0))
	    {
		char *type="%d";
		if (strcmp (e->datatype.type, "int") == 0) {
				type="%d";
		}
		if (strcmp (e->datatype.type, "long") == 0) {
				type="%ld";
		}

	      if (e->vname.is_array)
		{
		  int c;
		  for (c = 0; c < e->vname.is_array; c++)
		    {
		      fprintf (hfile, "%s gzfprintf(ofile,\"%s_%d='%s' \", f->%s%s[%d]);%s\n", union_match_before, e->vname.name, c, type, e->vname.name, union_name, c, union_match_after);
		    }
	      printed[b] = 1;
		}
	      else
		{
		  if (e->vname.is_vararray)
		    {
			/*
		      fprintf (hfile, "%s", union_match_before);
		      fprintf (hfile, "{\n");
		      fprintf (hfile,
			       "int loop;\nfor (loop=0;loop<f->%s%s.%s_len;loop++) { \n",
			       union_name, e->vname.name, e->vname.name);
		      fprintf (hfile,
			       "gzfprintf(ofile,\"%s_%%d='%s' \", loop,f->%s%s.%s_val[loop]); \n", e->vname.name, type, union_name, e->vname.name, e->vname.name);
		      fprintf (hfile, "}\n");
		      fprintf (hfile, "}\n");
		      fprintf (hfile, "%s", union_match_after);
			*/
		    }
		  else
		    {
	      printed[b] = 1;
		      fprintf (hfile,
			       "%s gzfprintf(ofile,\"%s='%s' \", f->%s%s);%s\n",
			       union_match_before, e->vname.name, type, union_name,
			       e->vname.name, union_match_after);
		    }
		}
	      continue;
	    }


	  if (strcmp (e->datatype.type, "double") == 0)
	    {
	      printed[b] = 1;
	      fprintf (hfile, "%sgzfprintf(ofile,\"%s='%%lf' \", f->%s%s);%s\n",
		       union_match_before, e->vname.name, union_name,
		       e->vname.name, union_match_after);
	      continue;
	    }

	  if (strcmp (e->datatype.type, "char") == 0)
	    {
	      printed[b] = 1;
	      if (e->vname.is_array)
		{
		  fprintf (hfile,
			   "%s if (strlen(f->%s)) {gzoutstr(ofile,\"%s\", xml_encode(f->%s%s));}%s\n",
			   union_match_before, e->vname.name, e->vname.name,
			   union_name, e->vname.name, union_match_after);
		}
	      else
		{
		  fprintf (hfile,
			   "%sgzfprintf(ofile,\"%s='%%s' \", xml_encode_char(f->%s%s));%s\n",
			   union_match_before, e->vname.name, union_name,
			   e->vname.name, union_match_after);
		}
	      continue;
	    }
	  if (strcmp (e->datatype.type, "str") == 0
	      || strcmp (e->datatype.type, "sql_ident") == 0
	      || strcmp (e->datatype.type, "ex_str") == 0)
	    {

	      if (e->vname.is_array)
		{

		  printed[b] = 1;
		  fprintf (hfile,
			   "%s ARR AR if (f->%s%s) {gzoutstr(ofile,\"%s\", xml_encode(f->%s%s));} %s\n",
			   union_match_before, union_name, e->vname.name,
			   e->vname.name, union_name, e->vname.name,
			   union_match_after);

		}
	      else
		{

		  if (e->vname.is_vararray)
		    {
		      printed[b] = 0;
		      issimple = 0;
		    }
		  else
		    {
		      printed[b] = 1;
		      fprintf (hfile,
			       "%s if (f->%s%s) {gzoutstr(ofile,\"%s\", xml_encode(f->%s%s));} %s\n",
			       union_match_before, union_name, e->vname.name,
			       e->vname.name, union_name, e->vname.name,
			       union_match_after);
		    }
		}
	      continue;
	    }


	  issimple = 0;
	}

      if (issimple)
	{
	  fprintf (hfile, "gzfprintf(ofile,\"/>\\n\");\n");
	}
      else
	{
	  fprintf (hfile, "gzfprintf(ofile,\">\\n\");\n");

	  for (b = 0; b < all_elements[a].nelements; b++)
	    {
	      struct s_element *e;
	      e = &all_elements[a].elements[b];

	      if (!printed[b])
		{
		  if (e->vname.name == 0)
		    continue;	// void
		  strcpy (union_match_before, "");
		  strcpy (union_match_after, "");
		  strcpy (union_name, "");

		  if (strlen (all_elements[a].union_switch_on_enum_type))
		    {
		      sprintf (union_match_after, "}");
		      sprintf (union_match_before, "if (f->%s==%s) {",
			       all_elements[a].union_switch_on_enum_name,
			       e->switch_on);
		      sprintf (union_name, "%s_u.",
			       all_elements[a].union_or_struct_name);
		    }


		  if (e->vname.is_array)
		    {
		      fprintf (hfile, "%s NOTYET1 %s", union_match_before,
			       union_match_after);
		    }
		  else
		    {
		      if (e->vname.is_vararray)
			{
			  fprintf (hfile, "%s", union_match_before);
			  fprintf (hfile, "{\n");
			  fprintf (hfile,
				   "int loop;\nfor(loop=0;loop<f->%s%s.%s_len;loop++){ /* 1 */\n",
				   union_name, e->vname.name, e->vname.name);
			  if (e->vname.is_ptr || check_for_ptr(e->vname.name,e->datatype.type, 2))
			    {
			      fprintf (hfile,
				       "XMLWrite_%s(\"%s\", f->%s%s.%s_val[loop]);\n",
				       e->datatype.type, e->vname.name,
				       union_name, e->vname.name,
				       e->vname.name);
			    }
			  else
			    {
			      fprintf (hfile,
				       "XMLWrite_%s(\"%s\", &f->%s%s.%s_val[loop]);\n",
				       e->datatype.type, e->vname.name,
				       union_name, e->vname.name,
				       e->vname.name);
			    }
			  fprintf (hfile, "}\n}\n");


			}
		      else
			{
			  if (e->vname.is_ptr || check_for_ptr(e->vname.name,e->datatype.type, 3))
			    {
			      fprintf (hfile,
				       "%sXMLWrite_%s(\"%s\", f->%s%s);%s\n",
				       union_match_before, e->datatype.type,
				       e->vname.name, union_name,
				       e->vname.name, union_match_after);
			    }
			  else
			    {
			      fprintf (hfile,
				       "%sXMLWrite_%s(\"%s\", &f->%s%s);%s\n",
				       union_match_before, e->datatype.type,
				       e->vname.name, union_name,
				       e->vname.name, union_match_after);
			    }
			}
		    }
		}
	    }

	  fprintf (hfile, "gzfprintf(ofile,\"</%s>\\n\");\n",
		   all_elements[a].union_or_struct_name);


	}
      fprintf (hfile, "return 1;\n}\n\n");
    }

  fclose (hfile);
  fclose (hfile_proto);
}


char *
get_enum_as_dtd_list (char *enum_name)
{
  int a;
  static char buff[10000];
  char smbuff[2000];
  int cnt = 0;
  sprintf (buff, "(");
  for (a = 0; a < nall_enums; a++)
    {
      int b;
      if (strcmp (all_enums[a].enum_name, enum_name) != 0)
	continue;		// thats not it...
      for (b = 0; b < all_enums[a].nelements; b++)
	{
	  sprintf (smbuff, "\"%s\"", all_enums[a].elements[b].element_name);
	  if (cnt)
	    strcat (buff, " | ");
	  strcat (buff, smbuff);
	  cnt++;
	}
    }
  strcat (buff, ")");
  return buff;
}



void
dump_write_parent (char *name)
{
  FILE *hfile_set_parent;
  int a;
  char buff[256];
  int c = 0;
  int issimple;
  int *printed = 0;
  int b;
  int printed_elem = 0;
  char union_name[200] = "";
  char union_match_before[2000];
  char union_match_after[2000];

  sprintf (buff, "%s.setparent.c", name);
  hfile_set_parent = fopen (buff, "w");
  if (!hfile_set_parent)
    return;


  //fprintf (hfile_set_parent, "#include \"cmds.xnew.h\"\n");
	fprintf (hfile_set_parent, "#include \"%s.xnew.h\"\n", name);
  fprintf (hfile_set_parent,
	   "int SetParent_%s(char *type, char *element, void *parent,  void *val) {\n",
	   name);

  for (a = 0; a < nall_elements; a++)
    {
      printed_elem = 0;
      issimple = 0;

      fprintf (hfile_set_parent, "  if (strcmp(type,\"%s\")==0) {\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_set_parent, "     t_%s *tmpVar;\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_set_parent, "     tmpVar=(t_%s *)parent;\n",
	       all_elements[a].union_or_struct_name);
      printed =
	realloc (printed, (all_elements[a].nelements + 1) * sizeof (long));


      strcpy (union_name, "");
      if (strlen (all_elements[a].union_switch_on_enum_type))
	{
	  sprintf (union_name, "%s_u.", all_elements[a].union_or_struct_name);
	}

      for (b = 0; b < all_elements[a].nelements; b++)
	{
	  struct s_element *e;
	  int skip = 0;
	  e = &all_elements[a].elements[b];
	  printed[b] = 0;

	  issimple = 0;


	  if (e->datatype.isenum)
	    {

	      fprintf (hfile_set_parent, "/* Is simple enum (%s) */\n",
		       e->vname.name);
	      issimple++;
	    }

	  if (strcmp (e->datatype.type, "int") == 0 || strcmp (e->datatype.type, "long") == 0)
	    {
              if (e->vname.is_vararray)
                {
                  printed[b] = 0;
                  issimple = 0;
                } else {
	      		fprintf (hfile_set_parent, "/* Is simple int (%s) */\n", e->vname.name);
	      		issimple++;
		}
	    }

	  if (strcmp (e->datatype.type, "double") == 0)
	    {
	      fprintf (hfile_set_parent, "/* Is simple double (%s) */\n",
		       e->vname.name);
	      issimple++;
	    }

	  if (strcmp (e->datatype.type, "char") == 0)
	    {
	      fprintf (hfile_set_parent, "/* Is simple char (%s) */\n",
		       e->vname.name);
	      issimple++;
	    }

	  if (strcmp (e->datatype.type, "str") == 0
	      || strcmp (e->datatype.type, "sql_ident") == 0
	      || strcmp (e->datatype.type, "ex_str") == 0)
	    {
	      if (e->vname.is_vararray)
		{
		  printed[b] = 0;
		  issimple = 0;
		}
	      else
		{
		  fprintf (hfile_set_parent, "/* Is simple string (%s) */\n",
			   e->vname.name);
		  issimple++;
		}
	    }


	  if (issimple)
	    {
	      fprintf (hfile_set_parent,
		       "     /* IGNORE %s - %d Of %d (Too simple %d)*/\n",
		       e->vname.name ? e->vname.name : "void", b,
		       all_elements[a].nelements, issimple);
	      continue;
	    }
	  fprintf (hfile_set_parent, "     /* %s - %d Of %d */\n",
		   e->vname.name ? e->vname.name : "void", b,
		   all_elements[a].nelements);
	  // Its no simple..

	  if (e->vname.name == 0)
	    continue;		// void

	  fprintf (hfile_set_parent, "     if (strcmp(element,\"%s\")==0) {\n", e->vname.name);

	  if (e->vname.is_ptr || check_for_ptr(e->vname.name,e->datatype.type, 4) )
	    {
	      if (e->vname.is_array)
		{
		  fprintf (hfile_set_parent,
			   "        tmpVar->%s=val; ARRAY\n", e->vname.name);
		}
	      else
		{
		  if (e->vname.is_vararray)
		    {
		      fprintf (hfile_set_parent,
			       "        tmpVar->%s%s.%s_len++;\n", union_name,
			       e->vname.name, e->vname.name);
		      fprintf (hfile_set_parent,
			       "        tmpVar->%s%s.%s_val=realloc(tmpVar->%s%s.%s_val, tmpVar->%s%s.%s_len*(sizeof(tmpVar->%s%s.%s_val[0])));\n",
			       union_name, e->vname.name, e->vname.name,
			       union_name, e->vname.name, e->vname.name,
			       union_name, e->vname.name, e->vname.name,
			       union_name, e->vname.name, e->vname.name);
		      fprintf (hfile_set_parent,
			       "        tmpVar->%s%s.%s_val[tmpVar->%s%s.%s_len-1]=val; // VAR ARRAY PTR\n",
			       union_name, e->vname.name, e->vname.name,
			       union_name, e->vname.name, e->vname.name);

		    }
		  else
		    {
		      fprintf (hfile_set_parent,
			       "        tmpVar->%s%s=val;\n", union_name,
			       e->vname.name);
		    }
		}
	    }
	  else
	    {
	      if (e->vname.is_array)
		{
		  fprintf (hfile_set_parent,
			   "        tmpVar->%s%s=val; ARRAY\n", union_name,
			   e->vname.name);
		}
	      else
		{
		  if (e->vname.is_vararray)
		    {
		      fprintf (hfile_set_parent,
			       "        tmpVar->%s%s.%s_len++;\n", union_name,
			       e->vname.name, e->vname.name);
		      fprintf (hfile_set_parent,
			       "        tmpVar->%s%s.%s_val=realloc(tmpVar->%s%s.%s_val, tmpVar->%s%s.%s_len*(sizeof(tmpVar->%s%s.%s_val[0])));\n",
			       union_name, e->vname.name, e->vname.name,
			       union_name, e->vname.name, e->vname.name,
			       union_name, e->vname.name, e->vname.name,
			       union_name, e->vname.name, e->vname.name);
		      fprintf (hfile_set_parent,
			       "        memcpy(&tmpVar->%s%s.%s_val[tmpVar->%s%s.%s_len-1],val,sizeof(tmpVar->%s%s.%s_val[0])); // VARR ARR\n",
			       union_name, e->vname.name, e->vname.name,
			       union_name, e->vname.name, e->vname.name,
			       union_name, e->vname.name, e->vname.name);
		    }
		  else
		    {
		      fprintf (hfile_set_parent,
			       "        memcpy(&tmpVar->%s%s,val,sizeof(tmpVar->%s%s)); /* 1 */\n",
			       union_name, e->vname.name, union_name,
			       e->vname.name);
		    }
		}
	    }

	  fprintf (hfile_set_parent, "        return 1;\n", e->vname.name);
	  fprintf (hfile_set_parent, "     }\n", e->vname.name);
	}

      fprintf (hfile_set_parent,
	       "     return 0; /* Couldn't find it ... */\n\n");
      fprintf (hfile_set_parent, "  }\n\n",
	       all_elements[a].union_or_struct_name);
    }

  fprintf (hfile_set_parent, "return 0;\n");
  fprintf (hfile_set_parent, "}\n");
  fclose (hfile_set_parent);
}


int
suppress_element (char *s)
{
  //if (strcmp (s, "variable") == 0) return 1;
  //if (strcmp (s, "s_expr_push_variable") == 0) return 1;
  //if (strcmp (s, "binding_comp") == 0) return 1;
  //if (strcmp (s, "s_expr_substring") == 0) return 1;
  return 0;
}

int
suppress_attlist (char *s)
{
  //if (strcmp (s, "variable") == 0) return 1;
  //if (strcmp (s, "s_expr_push_variable") == 0) return 1;
  //if (strcmp (s, "binding_comp") == 0) return 1;
  //if (strcmp (s, "s_expr_substring") == 0) return 1;
  return 0;
}


static char *decode_type(char *s) {
if (!istypedef(s)) {
	return s;
}

	if (strcmp(s,"variable_ptr")==0) return "variable";
	if (strcmp(s,"command_ptr")==0) return "command";
	if (strcmp(s,"expr_str_ptr")==0) return "expr_str";
	if (strcmp(s,"single_option_ptr")==0) return "single_option";
	if (strcmp(s,"report_format_section_entry_ptr")==0) return "report_format_section_entry";
	if (strcmp(s,"when_ptr")==0) return "when";
	if (strcmp(s,"on_event_ptr")==0) return "on_event";
	if (strcmp(s,"cons_list_entry_ptr")==0) return "cons_list_entry";
	if (strcmp(s,"module_entry_ptr")==0) return "module_entry";
	if (strcmp(s,"elements_ptr")==0) return "s_select_list_item";
	if (strcmp(s,"s_table_list_element_ptr")==0) return "s_table_list_element_ptr";




printf("DECODE : %s\n", s);
return s;
}

void
dump_write_dtd (char *name)
{
  FILE *hfile_attlist;
  FILE *hfile_elements;
  FILE *hfile_act_start;
  FILE *hfile_act_end;
  int a;
  char buff[256];
  int c = 0;
  int issimple;
  int *printed = 0;
  int b;
  int printed_elem = 0;
  char union_name[200] = "";
  char union_match_before[2000];
  char union_match_after[2000];

  sprintf (buff, "%s.elements.dtd", name);
  hfile_elements = fopen (buff, "w");
  if (!hfile_elements)
    return;

  sprintf (buff, "%s.attlist.dtd", name);
  hfile_attlist = fopen (buff, "w");
  if (!hfile_attlist)
    return;


  sprintf (buff, "%s.start.act", name);
  hfile_act_start = fopen (buff, "w");
  if (!hfile_act_start)
    return;

  sprintf (buff, "%s.end.act", name);
  hfile_act_end = fopen (buff, "w");
  if (!hfile_act_end)
    return;




  for (a = 0; a < nall_elements; a++)
    {
      printed_elem = 0;
      clr_printed_union ();

      if (!suppress_element (all_elements[a].union_or_struct_name))
	{
	  fprintf (hfile_elements, "<!ELEMENT %s ",
		   all_elements[a].union_or_struct_name);




	}


      fprintf (hfile_act_start, "<start tag='%s'>\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_act_start, "<![CDATA[\n");
      fprintf (hfile_act_start, "{\n");
      fprintf (hfile_act_start, "t_%s *tmpVar;\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_act_start,
	       "XMLPushOntoStack(\"%s\",  sizeof(t_%s),1,0,1,{nm});\n",
	       all_elements[a].union_or_struct_name,
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_act_start, "tmpVar=(t_%s *)XMLGetTopOfStack();\n",
	       all_elements[a].union_or_struct_name);
      strcpy (union_name, "");
      strcpy (union_match_before, "");
      strcpy (union_match_after, "");

      if (strlen (all_elements[a].union_switch_on_enum_type))
	{
	  fprintf (hfile_act_start, "if ({!%s}) {tmpVar->%s=0;} /*DDD */\n",
		   all_elements[a].union_switch_on_enum_type,
		   all_elements[a].union_switch_on_enum_name);
	  fprintf (hfile_act_start, "else {tmpVar->%s=xmlbest_reader__decode_%s({%s});}\n\n",
		   all_elements[a].union_switch_on_enum_name,
		   all_elements[a].union_switch_on_enum_type,
		   all_elements[a].union_switch_on_enum_type);
	  sprintf (union_name, "%s_u.", all_elements[a].union_or_struct_name);
	  sprintf (union_match_after, "}\n");
	}




      if (!suppress_attlist (all_elements[a].union_or_struct_name))
	{
	  fprintf (hfile_attlist, "<!ATTLIST %s nm CDATA #IMPLIED>\n",
		   all_elements[a].union_or_struct_name);
	}

      printed =
	realloc (printed, (all_elements[a].nelements + 1) * sizeof (long));

      for (b = 0; b < all_elements[a].nelements; b++)
	{
	  struct s_element *e;
	  int skip = 0;
	  e = &all_elements[a].elements[b];
	  printed[b] = 0;

	  if (strlen (all_elements[a].union_switch_on_enum_type))
	    {
	      sprintf (union_match_before, "\nif (tmpVar->%s==%s) {\n",
		       all_elements[a].union_switch_on_enum_name,
		       e->switch_on);
	    }




	  if (strlen (all_elements[a].union_switch_on_enum_type) || 1)
	    {			// Its a union...
	      int c;
	      struct s_element *e2;

	      for (c = 0; c < b; c++)
		{
		  int issimple = 0;
		  if (c == b)
		    continue;
		  e2 = &all_elements[a].elements[c];
		  if (e->vname.name == 0)
		    continue;	// void...
		  if (all_elements[a].elements[c].vname.name == 0)
		    continue;

		  if (strcmp (e->datatype.type, "str") == 0)
		    issimple++;
		  if (strcmp (e->datatype.type, "ex_str") == 0)
		    issimple++;
		  if (strcmp (e->datatype.type, "double") == 0)
		    issimple++;
		  if (strcmp (e->datatype.type, "int") == 0)
		    issimple++;
		  if (strcmp (e->datatype.type, "long") == 0)
		    issimple++;
		  if (strcmp (e->datatype.type, "short") == 0)
		    issimple++;
		  if (strcmp (e->datatype.type, "char") == 0)
		    issimple++;
		  if (e->datatype.isenum)
		    issimple = 1;

		  if (issimple)
		    {
		      if (strcmp
			  (e->vname.name,
			   all_elements[a].elements[c].vname.name) == 0)
			{	// Already printed...
			  skip++;
			  continue;
			}
		    }
		  else
		    {
		      if (strcmp
			  (e->datatype.type,
			   all_elements[a].elements[c].datatype.type) == 0)
			{	// Already printed...
			  skip++;
			  continue;
			}
		    }

		}
	    }









	  if (e->datatype.isenum)
	    {
	      printed[b] = 1;

	      if (!suppress_attlist (all_elements[a].union_or_struct_name))
		{
		  if (!skip)
		    fprintf (hfile_attlist,
			     "<!ATTLIST %s %s CDATA #IMPLIED>\n",
			     all_elements[a].union_or_struct_name,
			     e->vname.name,
			     get_enum_as_dtd_list (e->datatype.type));
		}

	      if (!skip || strlen (union_match_before))
		fprintf (hfile_act_start, "%s", union_match_before);
	      if (!skip || strlen (union_match_before))
		fprintf (hfile_act_start, "if ({!%s}) {tmpVar->%s%s=0;}/* EEE */\n",
			 e->vname.name, union_name, e->vname.name);
	      if (!skip || strlen (union_match_before))
		fprintf (hfile_act_start,
			 "else {tmpVar->%s%s=xmlbest_reader__decode_%s({%s});}\n\n",
			 union_name, e->vname.name, e->datatype.type,
			 e->vname.name);
	      if (!skip || strlen (union_match_before))
		fprintf (hfile_act_start, "%s", union_match_after);
	      continue;
	    }

	  if ((strcmp (e->datatype.type, "int") == 0 || strcmp (e->datatype.type, "long") == 0))
	    {
	      printed[b] = 1;
	      if (e->vname.is_array)
		{
		  int c;
		  for (c = 0; c < e->vname.is_array; c++)
		    {
		      if (!suppress_attlist
			  (all_elements[a].union_or_struct_name))
			{
			  if (!skip)
			    fprintf (hfile_attlist,
				     "<!ATTLIST %s %s_%d CDATA #IMPLIED>\n",
				     all_elements[a].union_or_struct_name,
				     e->vname.name, c);
			}
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start, "%s", union_match_before);
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start,
				 "if ({!%s_%d}) {tmpVar->%s%s[%d]=0;} /* XXX */\n",
				 e->vname.name, c, union_name, e->vname.name,
				 c);
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start,
				 "else {tmpVar->%s%s[%d]=atol({%s_%d});}\n\n",
				 union_name, e->vname.name, c, e->vname.name,
				 c);
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start, "%s", union_match_after);
		    }
		}
	      else
		{
		  if (e->vname.is_vararray)
		    {

		  printed[b] = 0;
		  issimple = 0;


#ifdef X
		      if (!suppress_attlist (all_elements[a].union_or_struct_name))
			{
			  if (!skip)
			    fprintf (hfile_attlist,
				     "<!ATTLIST %s %s CDATA #IMPLIED>\n",
				     all_elements[a].union_or_struct_name,
				     e->vname.name, c);
			}

		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start, "%s", union_match_before);
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start,
				 "if ({!%s}) {tmpVar->%s%s=0;} /* YYY */\n",
				 e->vname.name, union_name, e->vname.name);
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start,
				 "else {tmpVar->%s%s=atol({%s});}\n\n",
				 union_name, e->vname.name, e->vname.name);
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start, "%s", union_match_after);


#endif

		    }
		  else
		    {
		      if (!suppress_attlist
			  (all_elements[a].union_or_struct_name))
			{
			  if (!skip)
			    fprintf (hfile_attlist,
				     "<!ATTLIST %s %s CDATA #IMPLIED>\n",
				     all_elements[a].union_or_struct_name,
				     e->vname.name, c);
			}
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start, "%s", union_match_before);
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start,
				 "if ({!%s}) {tmpVar->%s%s=0;} /* ZZZ */\n",
				 e->vname.name, union_name, e->vname.name);
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start,
				 "else {tmpVar->%s%s=atol({%s});}\n\n",
				 union_name, e->vname.name, e->vname.name);
		      if (!skip || strlen (union_match_before))
			fprintf (hfile_act_start, "%s", union_match_after);
		    }
		}
		if ( printed[b]) {
	      continue;
		}
	    }

	  if (strcmp (e->datatype.type, "double") == 0)
	    {
	      printed[b] = 1;
	      if (!suppress_attlist (all_elements[a].union_or_struct_name))
		{
		  if (!skip)
		    fprintf (hfile_attlist,
			     "<!ATTLIST %s %s CDATA #IMPLIED>\n",
			     all_elements[a].union_or_struct_name,
			     e->vname.name);
		}
	      if (!skip || strlen (union_match_before))
		fprintf (hfile_act_start, "%s", union_match_before);
	      if (!skip || strlen (union_match_before))
		fprintf (hfile_act_start, "if ({!%s}) {tmpVar->%s%s=0;} /* AAA */\n",
			 e->vname.name, union_name, e->vname.name);
	      if (!skip || strlen (union_match_before))
		fprintf (hfile_act_start,
			 "else {tmpVar->%s%s=atof({%s});}\n\n", union_name,
			 e->vname.name, e->vname.name);
	      if (!skip || strlen (union_match_before))
		fprintf (hfile_act_start, "%s", union_match_after);
	      continue;
	    }

	  if (strcmp (e->datatype.type, "char") == 0)
	    {
	      printed[b] = 1;
	      if (!suppress_attlist (all_elements[a].union_or_struct_name))
		{
		  if (!skip)
		    fprintf (hfile_attlist,
			     "<!ATTLIST %s %s CDATA #IMPLIED>\n",
			     all_elements[a].union_or_struct_name,
			     e->vname.name);
		}
	      if (!skip || strlen (union_match_before))
		fprintf (hfile_act_start, "%s", union_match_before);

	      if (e->vname.is_array)
		{
		  if (!skip || strlen (union_match_before))
		    fprintf (hfile_act_start,
			     "if ({!%s}) {strcpy(tmpVar->%s%s,\"\");}\n",
			     e->vname.name, union_name, e->vname.name);
		  if (!skip || strlen (union_match_before))
		    fprintf (hfile_act_start,
			     "else {strcpy(tmpVar->%s%s,{%s});}\n\n",
			     union_name, e->vname.name, e->vname.name);
		}
	      else
		{
		  if (!skip || strlen (union_match_before))
		    fprintf (hfile_act_start,
			     "if ({!%s}) {tmpVar->%s%s=0;} /* BBB */\n", e->vname.name,
			     union_name, e->vname.name);
		  if (!skip || strlen (union_match_before))
		    fprintf (hfile_act_start,
			     "else {tmpVar->%s%s={%s}[0];}\n\n", union_name,
			     e->vname.name, e->vname.name);
		}
	      if (!skip || strlen (union_match_before))
		fprintf (hfile_act_start, "%s", union_match_after);
	      continue;
	    }

	  if (strcmp (e->datatype.type, "str") == 0
	      || strcmp (e->datatype.type, "sql_ident") == 0
	      || strcmp (e->datatype.type, "ex_str") == 0)
	    {
	      if (e->vname.is_vararray)
		{
		  printed[b] = 0;
		  issimple = 0;
		}
	      else
		{
		  if (!suppress_attlist
		      (all_elements[a].union_or_struct_name))
		    {
		      if (!skip)
			fprintf (hfile_attlist,
				 "<!ATTLIST %s %s CDATA #IMPLIED>\n",
				 all_elements[a].union_or_struct_name,
				 e->vname.name);
		    }
		  if (!skip || strlen (union_match_before))
		    fprintf (hfile_act_start, "%s", union_match_before);
		  if (!skip || strlen (union_match_before))
		    fprintf (hfile_act_start,
			     "if ({!%s}) {tmpVar->%s%s=0;} /* CCC */\n", e->vname.name,
			     union_name, e->vname.name);
		  if (!skip || strlen (union_match_before))
		    fprintf (hfile_act_start,
			     "else {tmpVar->%s%s=strdup({%s});}\n\n",
			     union_name, e->vname.name, e->vname.name);
		  if (!skip || strlen (union_match_before))
		    fprintf (hfile_act_start, "%s", union_match_after);
		  printed[b] = 1;
		  continue;
		}
	    }


	  // Its no simple..

	  if (e->vname.name == 0)
	    continue;		// void

	  fprintf (hfile_act_start,
		   "/* tmpVar->%s%s; is_vararray=%d skip=%d */\n", union_name,
		   e->vname.name, e->vname.is_vararray,0);


	  if (e->vname.is_vararray)
	    {
	      if (1 || !skip || strlen (union_match_before))
		fprintf (hfile_act_start, "%s", union_match_before);
	      if (1 || !skip || strlen (union_match_before))
		fprintf (hfile_act_start, "tmpVar->%s%s.%s_len=0; // Blah\n",
			 union_name, e->vname.name, e->vname.name);
	      if (1 || !skip || strlen (union_match_before))
		fprintf (hfile_act_start, "tmpVar->%s%s.%s_val=0;\n",
			 union_name, e->vname.name, e->vname.name);
	      if (1 || !skip || strlen (union_match_before))
		fprintf (hfile_act_start, "%s", union_match_after);
	    }
	  else
	    {
	      if (e->vname.is_array)
		{
		  fprintf (hfile_act_start, "// Array...\n", union_name,
			   e->vname.name, e->vname.name);
		}
	      else
		{
		  if (e->vname.is_ptr || check_for_ptr(e->vname.name,e->datatype.type, 5))
		    {
		      if (1 || !skip || strlen (union_match_before))
			fprintf (hfile_act_start, "%s", union_match_before);
		      if (1 || !skip || strlen (union_match_before))
			fprintf (hfile_act_start, "tmpVar->%s%s=0;\n",
				 union_name, e->vname.name, e->vname.name);
		      if (1 || !skip || strlen (union_match_before))
			fprintf (hfile_act_start, "%s", union_match_after);
		    }
		  else
		    {
		      if (1 || !skip || strlen (union_match_before))
			fprintf (hfile_act_start, "%s", union_match_before);
		      if (1 || !skip || strlen (union_match_before))
			fprintf (hfile_act_start,
				 "memset(&tmpVar->%s%s,0,sizeof(tmpVar->%s%s));\n",
				 union_name, e->vname.name, union_name,
				 e->vname.name);
		      if (1 || !skip || strlen (union_match_before))
			fprintf (hfile_act_start, "%s", union_match_after);
		    }
		}
	    }

	  if (e->vname.is_array)
	    {
	      if (!printed_elem)
		{
		  if (!suppress_element
		      (all_elements[a].union_or_struct_name))
		    {
		      fprintf (hfile_elements, "( ");
		      fprintf (hfile_elements, "%s", decode_type(e->datatype.type));
		    }
		}
	      else
		{
		  if (strlen (all_elements[a].union_switch_on_enum_type))
		    {
		      if (!suppress_element
			  (all_elements[a].union_or_struct_name))
			{
			  //if (!printed_elem_1(e->datatype.type)) {
			  if (!already_printed_union (e->datatype.type))
			    {
			      fprintf (hfile_elements, " | ",
				       e->datatype.type);
			      fprintf (hfile_elements, "(%s?) ",
				       decode_type(e->datatype.type));
			    }
			  //}
			}
		    }
		  else
		    {
		      if (!suppress_element
			  (all_elements[a].union_or_struct_name))
			{
			  fprintf (hfile_elements, ",  ", e->datatype.type);
			  fprintf (hfile_elements, "%s ",
				   decode_type(e->datatype.type));
			}
		    }
		}
	      printed_elem++;
	    }
	  else
	    {
	      if (e->vname.is_vararray)
		{
		  if (!printed_elem)
		    {
		      if (!suppress_element
			  (all_elements[a].union_or_struct_name))
			{
			  fprintf (hfile_elements, "( ");
			  fprintf (hfile_elements, "%s ",
				   decode_type(e->datatype.type));
			}
		    }
		  else
		    {
		      if (strlen (all_elements[a].union_switch_on_enum_type))
			{
			  if (!suppress_element
			      (all_elements[a].union_or_struct_name))
			    {
			      if (!already_printed_union (e->datatype.type))
				{
				  fprintf (hfile_elements, " | ",
					   e->datatype.type);
				  fprintf (hfile_elements, "(%s?) ",
					   decode_type(e->datatype.type));
				}
			    }
			}
		      else
			{
			  if (!suppress_element
			      (all_elements[a].union_or_struct_name))
			    {
			      if (!already_printed_union (e->datatype.type))
				{
				  fprintf (hfile_elements, "|",
					   e->datatype.type);
				if (strcmp(decode_type(e->datatype.type),"int")==0 && 0 ) {
				  fprintf (hfile_elements, "%s ", e->vname.name);
				} else {
				  fprintf (hfile_elements, "%s ", decode_type(e->datatype.type));
				}
					//decode_type(e->datatype.type), all_elements[a].union_or_struct_name,e->datatype.type
				}
			    }
			}
		    }
		  printed_elem++;
		}
	      else
		{
		  if (!printed_elem)
		    {
		      if (!suppress_element
			  (all_elements[a].union_or_struct_name))
			{
			  if (!already_printed_union (e->datatype.type))
			    {
			      fprintf (hfile_elements, "( ");
			      fprintf (hfile_elements, "%s ",
				       decode_type(e->datatype.type));
			    }
			}
		    }
		  else
		    {
		      if (strlen (all_elements[a].union_switch_on_enum_type))
			{
			  if (!suppress_element
			      (all_elements[a].union_or_struct_name))
			    {
			      if (!already_printed_union (e->datatype.type))
				{
				  fprintf (hfile_elements, " | ", e->vname.name);
				  fprintf (hfile_elements, "(%s?) ", decode_type(e->datatype.type));
				}
			    }
			}
		      else
			{
			  if (!suppress_element
			      (all_elements[a].union_or_struct_name))
			    {
			      if (!already_printed_union (e->datatype.type))
				{
				  fprintf (hfile_elements, "|  ", e->datatype.type);
				  fprintf (hfile_elements, "%s ", decode_type(e->datatype.type));
				}
			    }
			}
		    }
		  printed_elem++;
		}
	    }
	}

      if (strlen (all_elements[a].union_switch_on_enum_type))
	{			// Its a union..

	  if (!suppress_attlist (all_elements[a].union_or_struct_name))
	    {
	      fprintf (hfile_attlist,
		       "<!ATTLIST %s %s CDATA #REQUIRED> <!-- Switch on -->\n",
		       all_elements[a].union_or_struct_name,
		       all_elements[a].union_switch_on_enum_type,
		       get_enum_as_dtd_list (all_elements[a].
					     union_switch_on_enum_type));
	    }
	  //fprintf (hfile_attlist, "<!-- Switch on -->\n");



	}
      if (printed_elem)
	{
	  if (!suppress_element (all_elements[a].union_or_struct_name))
	    {
	      fprintf (hfile_elements, " )*");
	    }
	}
      else
	{
	  if (!suppress_element (all_elements[a].union_or_struct_name))
	    {
	      fprintf (hfile_elements, " EMPTY");
	    }
	}
      if (!suppress_element (all_elements[a].union_or_struct_name))
	{
	  fprintf (hfile_elements, ">\n\n\n");
	}
      fprintf (hfile_act_start, "}\n");
      fprintf (hfile_act_start, "]]>\n");
      fprintf (hfile_act_start, "</start>\n\n\n");

      fprintf (hfile_act_end, "<end tag='%s'>\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_act_end, "<![CDATA[\n");
      fprintf (hfile_act_end, "{\n");
      fprintf (hfile_act_end, "t_%s *tmpVar;\nchar *nm=0;",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_act_end, "ChkTopOfStack(\"%s\");\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_act_end, "tmpVar=(t_%s *)XMLGetTopOfStack();\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_act_end, "nm=XMLGetTopOfStackParentElem();\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_act_end, "XMLPopOffStack(\"%s\",1);\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_act_end, "SetParent(nm,XMLGetTopOfStack(), tmpVar);\n");
      fprintf (hfile_act_end, "Call_Callback (\"%s\", nm, tmpVar);\n",
	       all_elements[a].union_or_struct_name);
      fprintf (hfile_act_end, "}\n");
      fprintf (hfile_act_end, "]]>\n");
      fprintf (hfile_act_end, "</end>\n\n\n");


    }

  fclose (hfile_attlist);
  fclose (hfile_elements);
  fclose (hfile_act_start);
  fclose (hfile_act_end);

}



void
dump_structs (char *name)
{
  dump_xs_h (name);
  dump_write_xml (name);
  dump_write_dtd (name);
  dump_write_parent (name);
}

static void print_restrictions_enum(FILE *ofile, char *s) {
int a;
int b;
  for (a=0;a<nall_enums;a++) {
	if (strcmp(s,  all_enums[a].enum_name)==0) {
		fprintf(ofile,"  <xs:simpleType>\n");

    		fprintf(ofile,"   <xs:restriction base=\"xs:string\">\n");
		for (b=0;b<all_enums[a].nelements;b++) {
    			fprintf(ofile,"    <xs:enumeration value=\"%s\"/>\n", all_enums[a].elements[b].element_name);
		}
		fprintf(ofile,"   </xs:restriction>\n");
		fprintf(ofile,"  </xs:simpleType>\n");
		return;
	}
	
  }
}



void dump_xsd(char *name) {
  FILE *ofile;
  int a;

  ofile = fopen ("output.xsd", "w");
  fprintf(ofile,"<?xml version=\"1.0\" encoding=\"us-ascii\"?>\n");
  fprintf(ofile,"<xs:schema xmlns:xs=\"http://www.w3.org/2001/XMLSchema\">\n");




fprintf(ofile,"<xs:complexType name=\"module_entry_ptr\">\n");
fprintf(ofile," <xs:complexContent>\n");
fprintf(ofile,"  <xs:extension  base=\"module_entry\"/>\n");
fprintf(ofile," </xs:complexContent>\n");
fprintf(ofile,"</xs:complexType>\n");





  for (a = 0; a < nall_elements; a++)
    {
  	int b=0;
	 all_elements[a].usesAttributes=0;
	 all_elements[a].usesElements=0;

	  if (strlen(all_elements[a].union_switch_on_enum_type)) {
		all_elements[a].usesAttributes++;
	  }

      	  for (b = 0; b < all_elements[a].nelements; b++) {	
	  		struct s_element *e;
	  		e = &all_elements[a].elements[b];
	  		findit2 (&e->datatype);
	  		if (e->datatype.isvoid) continue;

			if (all_elements[a].elements[b].datatype.isstruct) {
				 all_elements[a].usesElements++;
				continue;
			}

			if (all_elements[a].elements[b].datatype.isunion) {
				 all_elements[a].usesElements++;
				 continue;
			}

			all_elements[a].usesAttributes++;
	  }
    }



  // Lets go through and dump a base datatype containing just our attributes...
  for (a = 0; a < nall_elements; a++)
    {
	char last_element[2000]="";
  	int b=0;
	char reqd[200]="required";
	if (!all_elements[a].usesAttributes) continue;

	if (all_elements[a].usesElements) {
		// We'll derive from this one later...
  		//fprintf (ofile, "<xs:element name=\"base_attr_%s\">\n", all_elements[a].union_or_struct_name);
		fprintf(ofile, "<xs:complexType name=\"base_attr_%s\">\n", all_elements[a].union_or_struct_name);
	} else {
  		//fprintf (ofile, "<xs:element name=\"%s\">\n", all_elements[a].union_or_struct_name);
		fprintf(ofile,"<xs:complexType name=\"%s\">\n", all_elements[a].union_or_struct_name);
	}
	  	if (strlen(all_elements[a].union_switch_on_enum_type)) {
				strcpy(reqd,"optional");
				fprintf(ofile,"  <xs:attribute name=\"%s\" use=\"required\">\n",  all_elements[a].union_switch_on_enum_name);
				print_restrictions_enum( ofile, all_elements[a].union_switch_on_enum_type);
				fprintf(ofile,"  </xs:attribute>\n");
		}
      	  	for (b = 0; b < all_elements[a].nelements; b++) {	
	  		struct s_element *e;
	  		e = &all_elements[a].elements[b];
	  		findit2 (&e->datatype);
	  		if (e->datatype.isvoid) continue;

			if (strcmp(last_element, all_elements[a].elements[b].vname.name)==0) {
				continue;
			}
			strcpy(last_element, all_elements[a].elements[b].vname.name);
	

			if ( all_elements[a].elements[b].datatype.isstruct) {
				continue;
			}

			if ( all_elements[a].elements[b].datatype.isunion) {
				continue;
			}

			if ( all_elements[a].elements[b].datatype.isenum) {
				fprintf(ofile,"  <xs:attribute name=\"%s\" use=\"%s\">\n",  all_elements[a].elements[b].vname.name,reqd);
				print_restrictions_enum( ofile, e->datatype.type);
				fprintf(ofile,"  </xs:attribute>\n");
				continue;
			}

			if (strcmp(all_elements[a].elements[b].datatype.type,"str")==0) {
				fprintf(ofile,"  <xs:attribute name=\"%s\" use=\"%s\" type=\"xs:string\"/>\n", all_elements[a].elements[b].vname.name,reqd);
				continue;
			}

			if (strcmp(all_elements[a].elements[b].datatype.type,"int")==0) {
				fprintf(ofile,"  <xs:attribute name=\"%s\" use=\"%s\" type=\"xs:int\"/>\n", all_elements[a].elements[b].vname.name,reqd);
				continue;
			}
			if (strcmp(all_elements[a].elements[b].datatype.type,"long")==0) {
				fprintf(ofile,"  <xs:attribute name=\"%s\" use=\"%s\" type=\"xs:long\"/>\n", all_elements[a].elements[b].vname.name,reqd);
				continue;
			}
			if (strcmp(all_elements[a].elements[b].datatype.type,"char")==0) {
				fprintf(ofile,"  <xs:attribute name=\"%s\" use=\"%s\" type=\"xs:string\"/>\n", all_elements[a].elements[b].vname.name,reqd);
				continue;
			}
			if (strcmp(all_elements[a].elements[b].datatype.type,"double")==0) {
				fprintf(ofile,"  <xs:attribute name=\"%s\" use=\"%s\" type=\"xs:double\"/>\n", all_elements[a].elements[b].vname.name,reqd);
				continue;
			}

			
			printf("%s\n", all_elements[a].elements[b].datatype.type);

			//fprintf(ofile,"  <xs:attribute name=\"%s\" use=\"%s\" type=\"%s\"/>\n", all_elements[a].elements[b].vname.name, reqd,all_elements[a].elements[b].datatype.type);
			continue;
			
	}
	if (all_elements[a].usesElements) {
		fprintf(ofile,"</xs:complexType>\n\n");
	} else {
		fprintf(ofile,"</xs:complexType>\n");
		//fprintf(ofile,"</xs:element>\n\n");
	}
    }



  for (a = 0; a < nall_elements; a++)
    {
	char last_element[2000]="";
  	int b=0;
	 if (!all_elements[a].usesElements) continue;

	 if (all_elements[a].usesAttributes) {
	  	//fprintf(ofile,"<xs:element name=\"%s\">\n", all_elements[a].union_or_struct_name);
	 	fprintf(ofile," <xs:complexType name=\"%s\">\n", all_elements[a].union_or_struct_name);
	 	fprintf(ofile,"  <xs:complexContent>\n");
	  	fprintf(ofile,"   <xs:extension  base=\"base_attr_%s\">\n",all_elements[a].union_or_struct_name);
	 } else {
	  	//fprintf(ofile,"<xs:element name=\"%s\">\n", all_elements[a].union_or_struct_name);
	 	fprintf(ofile," <xs:complexType name=\"%s\">\n", all_elements[a].union_or_struct_name);
         }
	
  	if (strlen(all_elements[a].union_switch_on_enum_type)) {
	 	fprintf(ofile,"  <xs:choice id=\"choice_%s\">\n", all_elements[a].union_or_struct_name);
	} else {
	 	fprintf(ofile,"  <xs:sequence>\n");
	}

      	  for (b = 0; b < all_elements[a].nelements; b++) {
			char arrbuff[1000];
	  		struct s_element *e;
	  		e = &all_elements[a].elements[b];
	  		findit2 (&e->datatype);
	  		if (e->datatype.isvoid) continue;
			strcpy(arrbuff,"");
			if (e->vname.is_array || e->vname.is_vararray) {
				sprintf(arrbuff," minOccurs=\"0\" maxOccurs=\"unbounded\"");
			}
			if (strcmp(last_element, all_elements[a].elements[b].vname.name)==0) {
				continue;
			}
			strcpy(last_element, all_elements[a].elements[b].vname.name);

			if ( all_elements[a].elements[b].datatype.isstruct) {
				fprintf(ofile,"  <xs:element type=\"%s\" name=\"%s\"%s/>\n", e->datatype.type,all_elements[a].elements[b].vname.name, arrbuff);
				//fprintf(ofile,"  <xs:element type=\"%s\" name=\"%s\"%s/>\n", e->datatype.type,e->datatype.type, arrbuff);
				continue;
			}

			if ( all_elements[a].elements[b].datatype.isunion) {
				fprintf(ofile," <xs:element type=\"%s\" name=\"%s\"%s/>\n",  e->datatype.type,all_elements[a].elements[b].vname.name,arrbuff);
				//fprintf(ofile," <xs:element type=\"%s\" name=\"%s\"%s/>\n",  e->datatype.type,e->datatype.type,arrbuff);
				continue;
			}

			continue;

			//fprintf(ofile,"<xs:element ref=\"%s\"/>\n", all_elements[a].elements[b].vname);
          }




	  if (strlen(all_elements[a].union_switch_on_enum_type)) {
			fprintf(ofile," </xs:choice>\n");
	 if (all_elements[a].usesAttributes) { fprintf (ofile, "</xs:extension>\n</xs:complexContent>\n"); }
			fprintf(ofile,"</xs:complexType>\n");
	  } else {
			fprintf(ofile," </xs:sequence>\n");
	 if (all_elements[a].usesAttributes) { fprintf (ofile, "</xs:extension>\n</xs:complexContent>\n"); }
			fprintf(ofile,"</xs:complexType>\n");
	  }
	  //fprintf (ofile, "</xs:element>\n\n");
	
    }
fprintf(ofile,"<xs:element name=\"module_definition\" type=\"module_definition\" />\n");
//fprintf(ofile,"<xs:element type=\"module_definition\" />\n");
fprintf(ofile,"</xs:schema>\n");
fclose(ofile);
}


void A4GL_pause_execution() {
printf("Pause\n");
}
