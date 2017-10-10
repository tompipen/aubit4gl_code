#include "a4gl_lib_lex_esqlc_int.h"


#include "field_handling.h"
#include "compile_c.h"

#include "cmd_funcs.h"
#include "fgl_enums.h"
void print_nullify (char type, variable_list * v);

extern int tmp_ccnt;
extern struct variable_list *current_entry_variables;
static int dump_class_function (char *class_name, struct s_function_definition *function_definition, int funcno,
				struct s_class_definition *class_def);

static char *
cleaned_class (char *s)
{
  char buff[300];
  char *ptr;
  strcpy (buff, s);
  while (1)
    {
      ptr = strchr (buff, '.');
      if (!ptr)
	break;
      *ptr = 'Z';
    }
  return strdup (buff);

}





static char *
get_sig_dtype (struct expr_str *parameter)
{
  struct variable_usage *p;
  if (parameter->expr_type != ET_EXPR_VARIABLE_USAGE)
    {
      printf ("Unexpected expression type %d\n", parameter->expr_type);
      return "0";
    }

  p = parameter->expr_str_u.expr_variable_usage;
  return getDatatypeSig(p->datatype&DTYPE_MASK, p->datatype>>17, p->object_type);

}



int
dump_class_definition (struct s_class_definition *class_def)
{
  int a;
  int printed = 0;
  int has_constructor = 0;
  printc ("/* 4GL CLASS */");
  printc ("#undef this");
  printc ("#define this a4gl_this");
  printc ("#undef base");
  printc ("#define base a4gl_base");

  printc ("struct s_a4glclass_%s {", cleaned_class (class_def->classname));
  tmp_ccnt++;
  if (class_def->parentname && strlen (class_def->parentname))
    {
      printed++;
      //printc("int base; /* %s */",class_def->parentname);
    }

  if (class_def->private_variables.variables.variables_len)
    {
      for (a = 0; a < class_def->private_variables.variables.variables_len; a++)
	{
	  //if (strcmp(class_def->private_variables.variables.variables_val[a]->names.names.names_val[0].name,"this")==0) {
	  //continue;
	  //}
	  //if (strcmp(class_def->private_variables.variables.variables_val[a]->names.names.names_val[0].name,"base")==0) {
	  //continue;
	  //}
	  printed++;
	  print_variable_new (class_def->private_variables.variables.variables_val[a], E_SCOPE_CLASS, 0);
	}
    }
  if (!printed)
    {
      printc ("int dummy;");	// Need 'something' - otherwise the struct would be empty...
    }
  tmp_ccnt--;
  printc ("};");

  printc ("#");

  printc ("static int class_getObjectType(int n) {");
  printc ("A4GL_push_char(\"%s\");", class_def->classname);
  printc ("return 1;");
  printc ("}");
  printc ("#");


  printc ("static int del_obj(long *objectID,int nparam) {");
  printc ("struct s_a4glclass_%s *data;", cleaned_class (class_def->classname));
  printc ("struct sObject *ptr;");
  printc ("if (!ensureObject(\"%s\",*objectID,&ptr)) {", class_def->classname);
  printc ("     A4GL_exitwith(\"Not an object of the correct type, or not initialized\");");
  printc ("     return 0;");
  printc ("  }");
  printc ("data=(struct s_a4glclass_%s*)ptr->objData;", cleaned_class (class_def->classname));
  if (class_def->parentname && strlen (class_def->parentname))
    {
      printc ("A4GL_destroy_object(\"%s\",data->base.objectid);", class_def->parentname);
    }
  printc ("free(data);");
  printc ("ptr->objData=NULL;");
  printc ("return 0;");
  printc ("}");
  printc ("#");
  printc ("static int new_obj(int n) {");
  printc ("struct sObject *obj;");
  if (class_def->parentname && strlen (class_def->parentname))
    {
      printc ("int parentObjectId;");
    }
  printc ("struct s_a4glclass_%s *objData;", cleaned_class (class_def->classname));
  printc ("obj=new_object(\"%s\");", class_def->classname);
  printc ("if (obj==NULL) {");
  printc ("   A4GL_push_objectID(0);");
  printc ("   return 1;");
  printc ("}");


  if (class_def->parentname && strlen (class_def->parentname))
    {
      printc ("parentObjectId=A4GL_create_object(\"%s\",0);", class_def->parentname);
      printc ("if (parentObjectId!=0) {");
      tmp_ccnt++;
    }

  printc ("objData=malloc(sizeof(struct s_a4glclass_%s));", cleaned_class (class_def->classname));
  printc ("objData->this.objectid=obj->objHeapId;");
  printc ("obj->objData=objData;");
  if (class_def->parentname && strlen (class_def->parentname))
    {
      printc ("objData->base.objectid=parentObjectId;");
    }
  printc ("A4GL_push_objectID(obj->objHeapId);");
  print_nullify (E_SCOPE_CLASS, &class_def->private_variables);
  printc ("return 1;");

  if (class_def->parentname && strlen (class_def->parentname))
    {


      tmp_ccnt--;
      printc ("} else {");
      tmp_ccnt++;
      // Something went wrong creating the parent object
      printc ("A4GL_push_objectID(0);");
      printc ("return 1;");
      printc ("}");
      tmp_ccnt--;
    }
  printc ("}");

  printc ("#");


  if (class_def->parentname && strlen (class_def->parentname))
    {

// This sets up the 'routeToParent' - 
// this does the inheritance from a base object to a child object
// if the A4GL_call_datatype_function_i cannot find a given function - it
// calls the class_RouteToParent (if it exists) instead to route it..
// If this function returns -1 - then the no base object picked up the function
// and we should mark an error (and pop the parameters from the stack)
//  
      printc ("static int class_castTo(long *objectID, int nParam){");
      printc ("struct sObject *objPtr;");
      printc ("struct { long objectid ; } a4gl_base;");

      printc ("char *objType;");
      printc ("struct s_a4glclass_%s *objData;", class_def->classname);
      //printc ("char buff[2000];");
      //printc("printf(\"...  in castTo (%s)\\n\");", class_def->classname);
      printc ("if (!ensureObject(\"%s\",*objectID,&objPtr)) {", class_def->classname);
      printc ("   A4GL_exitwith(\"Not an object of the correct type or not initialized\");");
      printc ("   return 0;");
      printc ("}");
      printc ("objData=objPtr->objData;");
      printc ("objType=A4GL_char_pop();");
      printc ("if (strcmp(\"%s\",objType)==0) { free(objType); /* No need to cast */    return *objectID; }", class_def->classname);
      printc ("if (strcmp(\"%s\",objType)==0) { free(objType); /* Just the parent */    return objData->base.objectid; }",
	      class_def->parentname);

      printc ("A4GL_push_char(objType); free(objType);");
      printc ("a4gl_base.objectid=objData->base.objectid;");
      printc ("/* Pass it to the parent - maybe it knows what its doing */");
      printc ("return A4GL_call_datatype_function_i(&a4gl_base,%d,\"%s.castTo\",1);", DTYPE_OBJECT, class_def->parentname);
      printc ("}");
      printc ("#");
      printc ("static int class_getparent(long *objectID, int _nargs){");
      printc ("struct sObject *objPtr;");
      printc ("struct s_a4glclass_%s *objData;", class_def->classname);
      //printc ("char buff[2000];");
      printc ("if (!ensureObject(\"%s\",*objectID,&objPtr)) {", class_def->classname);
      printc ("   A4GL_exitwith(\"Not an object of the correct type or not initialized\");");
      printc ("   return 0;");
      printc ("}");
      printc ("objData=objPtr->objData;");
      printc ("A4GL_push_objectID(objData->base.objectid);");
      printc ("return 1;");
      printc ("}");
      printc ("#");
      printc ("static int class_RouteToParent(long *objectID,char *function, int _nargs){");
      printc ("struct sObject *objPtr;");
      printc ("struct s_a4glclass_%s *objData;", class_def->classname);
      printc ("char buff[2000];");
      printc ("struct {");
      printc ("    long objectid ;");
      printc ("} a4gl_base;");
      printc ("sprintf(buff,\"%s.%%s\",function);", class_def->parentname);
      printc ("if (!ensureObject(\"%s\",*objectID,&objPtr)) {", class_def->classname);
      printc ("   A4GL_exitwith(\"Not an object of the correct type or not initialized\");");
      printc ("   return 0;");
      printc ("}");
      printc ("objData=objPtr->objData;");
      printc ("a4gl_base.objectid=objData->base.objectid;");
      printc ("return A4GL_call_datatype_function_i(&a4gl_base,%d,buff,_nargs);", DTYPE_OBJECT);
      printc ("}");
    }
  else
    {
      printc ("static int class_castTo(long *objectID, char *objType){");
      printc ("    return 0;");
      printc ("}");
      printc ("static int class_getparent(long *objectID, int _nargs){");
      printc ("    A4GL_push_objectID(0); return 1;");
      printc ("}");
      // There is no parent...
      printc ("static int class_RouteToParent(long *objectID,char *function, int _nargs){");
      printc ("    return -1;");
      printc ("}");
    }
  printc ("#");


  printc("static char *memberFunctions[]={");
  for (a = 0; a < class_def->class_entries.class_entries_len; a++)
    {

      if (class_def->class_entries.class_entries_val[a]->met_type == E_MET_FUNCTION_DEFINITION)
	{
              struct s_function_definition *fdef;
              int b;
		  expr_str_list *expanded_params;
		char *fname;
		char sig_fname[2000]="";

              	fdef = &class_def->class_entries.class_entries_val[a]->module_entry_u.function_definition;
		  expanded_params = expand_parameters (&fdef->variables, fdef->parameters);
                  for (b = 0; b < expanded_params->list.list_len; b++)
                    {
                      char tbuff[2300];
                      sprintf (tbuff, "%s", get_sig_dtype (expanded_params->list.list_val[b]));
		      strcat (sig_fname, tbuff);
		    }

	  	fname = class_def->class_entries.class_entries_val[a]->module_entry_u.function_definition.funcname;
		printc("\"%s\",\"%s\",", fname,sig_fname);
	}
    }
  printc("0};");
  printc("#");

  printc ("static void init_object(void) {");
  printc ("static int inited=0;");
  printc ("  if (inited) return;");
  printc ("  inited++;");

  printc ("  A4GL_add_object_type(\"%s\");", class_def->classname);

  printc ("  A4GL_add_datatype_function_i (%d, \":%s.castTo\", (void *)  class_castTo);", DTYPE_OBJECT, class_def->classname);
  printc ("  A4GL_add_datatype_function_i (%d, \":%s.getparent\", (void *)  class_getparent);", DTYPE_OBJECT, class_def->classname);
  printc ("  A4GL_add_datatype_function_i (%d, \":%s.RouteToParent\", (void *)  class_RouteToParent);", DTYPE_OBJECT,
	  class_def->classname);
  printc ("  A4GL_add_datatype_function_i (%d, \":%s.getobjectname\", (void *)  class_getObjectType);", DTYPE_OBJECT,
	  class_def->classname);


  for (a = 0; a < class_def->class_entries.class_entries_len; a++)
    {

      if (class_def->class_entries.class_entries_val[a]->met_type == E_MET_FUNCTION_DEFINITION)
	{
	  char *fname;
	  int found_dup;
	  char sig_fname[20000];
	  int b;
	  // Are we using this same function name elsewhere ?
	  found_dup = 0;
	  for (b = 0; b < class_def->class_entries.class_entries_len; b++)
	    {
	      if (a == b)
		continue;
	      if (strcmp
		  (class_def->class_entries.class_entries_val[a]->module_entry_u.function_definition.funcname,
		   class_def->class_entries.class_entries_val[b]->module_entry_u.function_definition.funcname) == 0)
		found_dup = 1;
	    }
	  fname = class_def->class_entries.class_entries_val[a]->module_entry_u.function_definition.funcname;
	  if (strcmp (fname, "main") == 0)
	    {
	      a4gl_yyerror ("A class cannot contain a 'MAIN'");
	      return 0;
	    }
	  if (!found_dup)
	    {
	      strcpy (sig_fname, fname);
	    }
	  else
	    {
	      struct s_function_definition *fdef;
	      int b;
	      fdef = &class_def->class_entries.class_entries_val[a]->module_entry_u.function_definition;
	      if (fdef->parameters == 0)
		{
		  sprintf (sig_fname, "%s_0", fname);
		}
	      else
		{
		  expr_str_list *expanded_params;
		  expanded_params = expand_parameters (&fdef->variables, fdef->parameters);
		  sprintf (sig_fname, "%s_%d", fname, expanded_params->list.list_len);

		  for (b = 0; b < expanded_params->list.list_len; b++)
		    {
		      char tbuff[2300];
		      sprintf (tbuff, "P%s", get_sig_dtype (expanded_params->list.list_val[b]));
		      strcat (sig_fname, tbuff);
		    }
		}

	    }

	  if (strcmp (fname, "new") == 0)
	    {
	      has_constructor = 1;
	    }

	  if (class_def->class_entries.class_entries_val[a]->module_entry_u.function_definition.function_type == E_FTYPE_STATIC)
	    {
	      a4gl_yyerror ("You cannot use LOCAL functions in a class");
	      return 0;
	    }

	  printh ("static int class_%s_%sN%d(long *objId, int nparam);\n", cleaned_class (class_def->classname), fname, a);
	  printc ("  A4GL_add_datatype_function_i (%d, \":%s.%s\", (void *)  class_%s_%sN%d);", DTYPE_OBJECT, class_def->classname,
		  sig_fname, cleaned_class (class_def->classname), fname, a);
	}
    }


  printc ("  A4GL_add_datatype_function_i (%d, \":%s.new\", (void *) class_%s_new);", DTYPE_OBJECT, class_def->classname,
	  cleaned_class (class_def->classname));
  printc ("  A4GL_add_datatype_function_i (%d, \":%s.~\", (void *) class_%s_delete);", DTYPE_OBJECT, class_def->classname,
	  cleaned_class (class_def->classname)); //, cleaned_class (class_def->classname));

  printc ("}");

  printc ("#");
  printc ("void Object_%s(void) {", cleaned_class (class_def->classname));
  printc ("   init_object();");
  printc ("}");


  if (!has_constructor)
    {
      printc ("#");
      printh ("static int class_%s_new(long *objId, int nparam);\n", cleaned_class (class_def->classname));
      printc ("static int class_%s_new(long *objId,int n) {", cleaned_class (class_def->classname));
      printc ("init_module_variables();");
      printc ("return new_obj(n);");
      printc ("}");
    }

  printc ("#");
  printh ("static int class_%s_delete(long *objId, int nparam);\n", cleaned_class (class_def->classname));
  printc ("static int class_%s_delete(long *objId,int n) {", cleaned_class (class_def->classname));
  printc ("init_module_variables();");
  printc ("del_obj(objId, n);");
  printc ("return 0;");
  printc ("}");


  for (a = 0; a < class_def->class_entries.class_entries_len; a++)
    {
      if (class_def->class_entries.class_entries_val[a]->met_type == E_MET_CMD)
	{
	  continue;
	}
      if (class_def->class_entries.class_entries_val[a]->met_type == E_MET_FUNCTION_DEFINITION)
	{
	  dump_class_function (class_def->classname,
			       &class_def->class_entries.class_entries_val[a]->module_entry_u.function_definition, a, class_def);
	}
      else
	{
	  a4gl_yyerror ("A class can only contain functions");
	}
    }

  printc ("#");
  return 1;
}


static int
dump_class_function (char *class_name, struct s_function_definition *function_definition, int funcno,
		     struct s_class_definition *class_def)
{
  int a;
  expr_str_list *expanded_params;
  printc ("#");
  printc ("#");
  printc ("#");
  dump_comments (function_definition->lineno);
  //line_for_cmd = function_definition->lineno;
  //parent_stack_cnt = 0;

  current_entry_variables = &function_definition->variables;

  //printh ("\nA4GL_FUNCTION static int %s%s (long *objectID,int _nargs); \n", function_definition->n_namespace, function_definition->funcname);
  printc ("\nstatic int class_%s_%sN%d (long *objectID,int _nargs){ \n", cleaned_class (class_name), function_definition->funcname,
	  funcno);
  printc ("void *_blobdata=0;");
  if (function_definition->function_type != E_FTYPE_OBJECT) {
  printc ("struct sObject *objPtr;");
  printc ("struct s_a4glclass_%s *objData;", class_name);
  printc ("struct {");
  printc ("    long objectid ;");
  printc ("} a4gl_this;");

  if (class_def->parentname && strlen (class_def->parentname))
    {
      printc ("struct {");
      printc ("    long objectid ;");
      printc ("} a4gl_base;");
    }
  }

  printDeclareFunctionStack (function_definition->funcname);
  //add_function_to_header (function_definition->funcname, function_definition->n_namespace, 1, function_definition->function_type);

// local variables...
//
  if (function_definition->variables.variables.variables_len)
    {
      for (a = 0; a < function_definition->variables.variables.variables_len; a++)
	{
	  print_variable_new (function_definition->variables.variables.variables_val[a], E_SCOPE_LOCAL, 0);
	}
    }
  printc ("#");
  expanded_params = expand_parameters (&function_definition->variables, function_definition->parameters);
  //yylineno = function_definition->lineno;
  print_param_g ('f', function_definition->funcname, expanded_params);


  dump_objdata (&function_definition->variables,1);

  if (function_definition->function_type != E_FTYPE_OBJECT)
    {
      set_object_function (1);
      printc ("if (!ensureObject(\"%s\",*objectID,&objPtr)) {", class_name);
      printc ("   A4GL_exitwith(\"Not an object of the correct type or not initialized\");");
      printc ("   return 0;");
      printc ("}");
      printc ("objData=objPtr->objData;");
      printc ("a4gl_this.objectid=*objectID;");
      if (class_def->parentname && strlen (class_def->parentname))
	{
	  printc ("a4gl_base.objectid=objData->base.objectid;");
	}
    }
  else
    {
      set_object_function (2);
      //printc ("objData=0;");
    }


  printc ("if (_nargs!=%d) {A4GL_set_status(-3002,0);A4GL_pop_args(_nargs);return -1;}\n", expanded_params->list.list_len);

  printc ("A4GLSTK_pushFunction_v2(_functionName,_paramnames,_nargs,_module_name,%d,_objData);", expanded_params->list.list_len);
  tmp_ccnt++;
  print_function_variable_init (&function_definition->variables);
  printc ("{int _lstatus=a4gl_status;");
  printc ("A4GL_pop_params_and_save_blobs(_fbind,%d,&_blobdata);\n", expanded_params->list.list_len);
  printc ("if (_lstatus!=a4gl_status) { A4GL_chk_err(%d,_module_name);  }", function_definition->lineno);
  printc ("}");



  printc ("#");

  if (function_definition->func_commands)
    {
      dump_command_list (function_definition->func_commands->cmds.cmds_val, function_definition->func_commands->cmds.cmds_len);

      /*
         for (a = 0; a < function_definition->func_commands->cmds.cmds_len; a++)
         {
         dump_cmd (function_definition->func_commands->cmds.cmds_val[a]);
         }
       */
    }

  dump_comments (function_definition->lastlineno);

  //printPopFunction (0, function_definition->lastlineno);
  //printc ("A4GL_dec_refcount(_objData);");
  printc ("A4GL_copy_back_blobs(_blobdata,0);");
  printc ("return 0;\n");
  tmp_ccnt--;
  printc ("}");
  printcomment ("/* END OF FUNCTION */\n\n\n\n");
  printc ("#");

  return 1;
}
