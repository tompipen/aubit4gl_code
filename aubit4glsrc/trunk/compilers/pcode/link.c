#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
#define bool_t int
#define u_int unsigned int
#endif

#ifdef RPCGEN_HEADERS
#include "npcode.h"
#else
#include "npcode.xs.h"
#endif

#include "npcode_defs.h"
#include "a4gl_memhandling.h"

#define OPTIMIZETOO
void merge_module (module * new_module);
void replace_id (module * nm, int oldid, int newid);
void replace_id_in_var (struct variable_element *var, int oldid, int newid);
void link_make_new_param (int *n, struct param **p);
void replace_variable_id (struct module *new_module, long *newid);
int link_add_id (char *s, int cnt);
int add_param (struct param *p);
void replace_param (struct module *mptr, int from, int to);
int link_add_string (char *s, int cnt);
void A4GL_assertion (int fail, char*msg);

module *this_module;
char out_linked_name[256]="linked.4pp";
int optimised=0;

module *this_module_ptr;
module *modules;
int allocated_params;

#define GET_NEW_ID(m,x) get_new_id(m,x)
#define GET_OLD_ID(x) get_new_id(this_module,x)

char * get_new_id (module * new_module, int x)
{
  if (x >= new_module->id_table.id_table_len)
    {
      fprintf (stderr,"Get ID %d from max %d\n", x, new_module->id_table.id_table_len);
      A4GL_assertion (1, "ID is out of range");
    }
  return new_module->id_table.id_table_val[x].s;
}



int main (int argc, char *argv[])
{
  int a;
  int *skip;
  int fmodule=-1;

  //module smod;
  //
  do_compiler_start (argc, argv);
  modules = malloc (sizeof (module) * argc);
  skip=malloc(sizeof(int)*argc);

  for(a=0;a<argc;a++) {
	  skip[a]=1;
  }

  for (a = 1; a < argc; a++)
    {
       char *lv_progname;
        lv_progname = argv[a];
	skip[a]=1;
	if (strcmp(lv_progname,"-o")==0) {
		a++;
		skip[a]=1;
      		lv_progname = argv[a];
		strcpy(out_linked_name,lv_progname);
		continue;
	}

	if (
			strcmp(lv_progname,"-O")==0  ||
			strcmp(lv_progname,"-O1")==0  ||
			strcmp(lv_progname,"-O2")==0  ||
			strcmp(lv_progname,"-O3")==0  ||
			strcmp(lv_progname,"-O4")==0  ||
			strcmp(lv_progname,"-O5")==0  
			 ) {
				optimised=1;
			continue;
	}

	if (strncmp(lv_progname,"-l",2)==0) { // -llibname or -l libname
		if (strlen(lv_progname)==2) { // -l libname
			a++;
			skip[a]=1;
		}
		continue;
	}

	if (strncmp(lv_progname,"-L",2)==0) { // -Ldir or -L dir
		if (strlen(lv_progname)==2) { // -L dir
			a++;
			skip[a]=1;
		}
		continue;
	}


	skip[a]=0;
      if (fmodule==-1) fmodule=a;
      if (!process_xdr ('I', &modules[a - 1], lv_progname))
	{
	  fprintf (stderr,"Error loading %s\n", lv_progname);
	  exit(2);
	}
    }

  if (fmodule==-1) {
	  printf("Nothing to link\n");
  }

  this_module = &modules[fmodule-1];
  this_module->module_name = strdup ("PROGRAM");
  this_module_ptr = this_module;

  for (a = fmodule+1; a < argc; a++)
    {
      if (!skip[a]) {
      		merge_module (&modules[a - 1]);
      }
    }


  if (optimised) {
  	optimize();
  }


  a = process_xdr ('O', this_module, out_linked_name);

  if (a)
    {
         A4GL_debug ("Written ok %d\n", a);
	chmod(A4GL_get_last_outfile(),0700);
    }
  else
    {
      fprintf (stderr,"Failed to write %d\n", a);
      exit (1);
    }

return 0;
}

int
is_system_var (char *s)
{
  if (s[0] >= 'a' && s[0] <= 'z')
    {
      return 1;
    }
  if (s[0] == 'G')
    {
      return 1;
    }
  return 0;
}


int
find_old_mod_var (module * new_module, char *s)
{
  struct npfunction *module_func;
  struct cmd_block *blk;
  int a;

  module_func = &this_module->functions.functions_val[0];
  blk = module_func->cmds.cmds_val[0].cmd_u.c_block;
  for (a = 0; a < blk->c_vars.c_vars_len; a++)
    {
      if (strcmp (GET_OLD_ID (blk->c_vars.c_vars_val[a].var->name_id), s) ==
	  0)
	{
	  return a;
	}
    }

  fprintf (stderr,"Find old : %s failed\n", s);
  return -1;
}

void
merge_module (module * new_module)
{
  int a;
  int b;
  //int c;
  //int d;
  long *newid = 0;
  struct npfunction *module_func;
  struct cmd_block *blk;
A4GL_assertion(new_module==0,"new module=0 ?");
  //int orig_len;
/*
// In order to merge our module - we need to merge these items :
//    string_table
//    id_table
//    functions
//    variables
//    params
//
//    We also need to resolve any external functions which are
//    no longer external, and generate a new external functions list
*/

  for (a = 0; a < new_module->string_table.string_table_len; a++)
    {
      int nid;
      //int nsid;

      // generate a new string ID...
      nid =
	link_add_string (new_module->string_table.string_table_val[a].s,
			 new_module->string_table.string_table_val[a].rcnt);

      // Theres almost no chance they'll match - but whatever....
      if (nid != a)
	{
	  int b;
	  for (b = 0; b < new_module->params.params_len; b++)
	    {
	      if (new_module->params.params_val[b].param_type ==
		  PARAM_TYPE_LITERAL_STRING)
		{
		  if (new_module->params.params_val[b].param_u.str_entry == a)
		    {
		      // Lets use a negative number so we can't get confused between the 
		      // old IDs and the new IDs
		      // so we don't get multiple changes
		      new_module->params.params_val[b].param_u.str_entry =
			0 - nid;
		    }
		}
	    }
	}
    }






  // ok - at this time - we've modified all our ids to new ids but these are negative
  // we need to put these back..
  for (b = 0; b < new_module->params.params_len; b++)
    {
      if (new_module->params.params_val[b].param_type ==
	  PARAM_TYPE_LITERAL_STRING)
	{
	  if (new_module->params.params_val[b].param_u.str_entry < 0)
	    {
	      new_module->params.params_val[b].param_u.str_entry =
		0 - new_module->params.params_val[b].param_u.str_entry;
	    }
	}
    }






/* OK - done strings, now do IDs */






  newid = malloc (sizeof (long) * new_module->id_table.id_table_len);
  for (a = 0; a < new_module->id_table.id_table_len; a++)
    {
      int nsid;
      nsid =
	link_add_id (new_module->id_table.id_table_val[a].s,
		     new_module->id_table.id_table_val[a].rcnt);
      replace_id (new_module, a, 0 - nsid);
      newid[a] = 0 - nsid;
    }

  for (a = 0; a < new_module->id_table.id_table_len; a++)
    {
      replace_id (new_module, newid[a], 0 - newid[a]);
    }

  /* Done IDs ! */

  // getting there :-)
  // now - we've got to map our old parameters to new parameters..
  free (newid);
  newid = malloc (sizeof (long) * new_module->params.params_len);

  //orig_len=this_module->params.params_len;
  //this_module->params.params_len+=new_module->params.params_len;
  //this_module->params.params_val=realloc(this_module->params.params_val,sizeof(struct param)*new_module->params.params_len);
  allocated_params = this_module->params.params_len;
  for (a = 1; a < new_module->params.params_len; a++)
    {
      newid[a] = add_param (&new_module->params.params_val[a]);
      //printf("Replace ID : %d %d\n",a,newid[a]);
      replace_param (new_module, a, 0 - newid[a]);
    }

  for (a = 1; a < new_module->params.params_len; a++)
    {
      replace_param (new_module, 0 - newid[a], newid[a]);
    }

  for (a = 1; a < new_module->params.params_len; a++)
    {
      memcpy (&this_module->params.params_val[newid[a]],
	      &new_module->params.params_val[a], sizeof (struct param));
    }



  free (newid);



  /* Now - lets copy our remap all our variable IDs.. 
   * we'll need to start where we left off in the this module,
   * so we'll need to go through and change 0 to last max+1 etc ...
   */


  newid = malloc (sizeof (long) * (new_module->max_variable_id + 1));

  this_module->max_variable_id += (new_module->max_variable_id + 1);


  for (a = 0; a <= new_module->max_variable_id; a++)
    {				// its inclusive...
      newid[a] = (this_module->max_variable_id + 1000 + a);
    }

  module_func = &new_module->functions.functions_val[0];
  A4GL_assertion(module_func==0,"No module function");
  blk = module_func->cmds.cmds_val[0].cmd_u.c_block;
  for (a = 0; a < blk->c_vars.c_vars_len; a++)
    {
      struct cmd_block *base;
      int id;

      base = this_module->functions.functions_val[0].cmds.cmds_val[0].cmd_u.  c_block;

      if (is_system_var (GET_ID (blk->c_vars.c_vars_val[a].var->name_id)))
	{
	  int id;
	  id = find_old_mod_var (new_module, GET_ID (blk->c_vars.c_vars_val[a].var-> name_id));
	  if (id >= 0)
	    {
	      //printf ("Merge top level variables : Old ID : %d new id %d\n", blk->c_vars.c_vars_val[a].variable_id, id);
	      if (base->c_vars.c_vars_val[id].category==CAT_EXTERN) {// Was previously extern
		      if (blk->c_vars.c_vars_val[a].category==CAT_NORMAL) {
			      // Result ! - we've got our external variable !
			      base->c_vars.c_vars_val[id].category=CAT_NORMAL;
		      }

	      }
	      newid[blk->c_vars.c_vars_val[a].variable_id] = id;

	      continue;
	    }
	}
      A4GL_debug ("Add variable to top __MODULE function\n");
      // variable doesn't currently exist at in our base modules top area..
      // lets add it..
      base->c_vars.c_vars_len++;
      base->c_vars.c_vars_val =
	realloc (base->c_vars.c_vars_val,
		 base->c_vars.c_vars_len * sizeof (struct npvariable));
      id = base->c_vars.c_vars_len - 1;
      memcpy (&base->c_vars.c_vars_val[id], &blk->c_vars.c_vars_val[a], sizeof (struct npvariable));
      base->mem_to_alloc+=blk->c_vars.c_vars_val[a].var->total_size;
      //printf("Increasing memtoalloc : %d\n",blk->c_vars.c_vars_val[a].var->total_size);
      // We'll keep the variable ID we've just guessed -  but we'll need to set that in our base module...
      // 
      base->c_vars.c_vars_val[id].variable_id = newid[blk->c_vars.c_vars_val[a].variable_id];
      //
    }

  replace_variable_id (new_module, newid);
  free(blk->c_vars.c_vars_val);
  blk->c_vars.c_vars_val=0;
  blk->c_vars.c_vars_len=0;

// Now - lets checkout the parameters....
  for (a = 1; a < new_module->params.params_len; a++)
    {
      if (new_module->params.params_val[a].param_type == PARAM_TYPE_USE_VAR)
	{
	  new_module->params.params_val[a].param_u.uv->variable_id =
	    newid[new_module->params.params_val[a].param_u.uv->variable_id];
	}
    }

  free (newid);

// so - thats all our variables remapped...
// lets remap our functions - we don't need to worry about function '0' as thats just our __MODULE function
// which only contains variable definitions - we'll deal with those separately...
  for (a = 0; a < new_module->functions.functions_len; a++)
    {
      int new_func_id;
      this_module->functions.functions_len++;
      new_func_id = this_module->functions.functions_len - 1;
      this_module->functions.functions_val =
	realloc (this_module->functions.functions_val,
		 sizeof (struct npfunction) *
		 this_module->functions.functions_len);
      memcpy (&this_module->functions.functions_val[new_func_id],
	      &new_module->functions.functions_val[a],
	      sizeof (struct npfunction));
    }


}


void
replace_variable_id (struct module *new_module, long *newid)
{
  int b;
  int c;
  int d;
  // Variable IDs are stored in function blocks
  // and "use_variables" within parameters...
  // Lets sort out the function block stuff first...
  for (b = 0; b < new_module->functions.functions_len; b++)
    {

	    // replace the variable IDs used in the parameters...
      for (c=0; c<new_module->functions.functions_val[b].param_vars.param_vars_len;c++) {
		struct use_variable *v;
		v=&new_module->functions.functions_val[b].param_vars.param_vars_val[c];
		v->variable_id=newid[v->variable_id];
      }

	    // replace the variable IDs used in the commands
      for (c = 0; c < new_module->functions.functions_val[b].cmds.cmds_len;
	   c++)
	{

	  if (new_module->functions.functions_val[b].cmds.cmds_val[c].
	      npcode_cmd_type == CMD_BLOCK)
	    {
	      // this is probably only ever when c=0 - but for testing we'll look at all the commands
	      // if we ever hit an assertion - we'll know I was wrong ;-)
	      struct cmd_block *blk;
	      blk =
		new_module->functions.functions_val[b].cmds.cmds_val[c].cmd_u.
		c_block;
	      if (c != 0 && blk->c_vars.c_vars_len)
		{
		  A4GL_assertion (1,
				  "Unusual - wasnt expecting any variables in here\n");
		}

	      for (d = 0; d < blk->c_vars.c_vars_len; d++)
		{
		  blk->c_vars.c_vars_val[d].variable_id =
		    newid[blk->c_vars.c_vars_val[d].variable_id];
		}
	    }

	  if (new_module->functions.functions_val[b].cmds.cmds_val[c].
	      npcode_cmd_type == CMD_SET_VAR)
	    {
	      struct cmd_set_var *sv;
	      sv =
		new_module->functions.functions_val[b].cmds.cmds_val[c].cmd_u.
		c_setvar;
	      sv->variable.variable_id = newid[sv->variable.variable_id];
	    }

	  if (new_module->functions.functions_val[b].cmds.cmds_val[c].
	      npcode_cmd_type == CMD_SET_VAR_ONCE)
	    {
	      struct cmd_set_var1 *sv1;
	      sv1 =
		new_module->functions.functions_val[b].cmds.cmds_val[c].cmd_u.
		c_setvar1;
	      sv1->variable.variable_id = newid[sv1->variable.variable_id];
	    }
	}
    }

}





int add_param (struct param *p)
{
  int n;
  link_make_new_param (&n, 0);
  return this_module->params.params_len - 1;
}



void
replace_id (module * nm, int oldid, int newid)
{
  int a;
  int b;
  int c;

  // IDs are used within 
  //     param->param_u.c_call (func_id)
  //     external_function_table_val
  //     functions (func_name_id, module_name_id)
  //     variables (name_id)



  //printf("Replace ID : %d %d\n",oldid,newid);


  for (a = 0; a < nm->params.params_len; a++)
    {
      if (nm->params.params_val[a].param_type == PARAM_TYPE_CALL)
	{
	  if (nm->params.params_val[a].param_u.c_call->func_id == oldid)
	    {
	      nm->params.params_val[a].param_u.c_call->func_id = newid;
	    }
	}
    }

  for (a = 0; a < nm->external_function_table.external_function_table_len;
       a++)
    {
      if (nm->external_function_table.external_function_table_val[a] == oldid)
	{
	  nm->external_function_table.external_function_table_val[a] = newid;
	}
    }

  for (a = 0; a < nm->functions.functions_len; a++)
    {
      if (nm->functions.functions_val[a].func_name_id == oldid)
	{
	  nm->functions.functions_val[a].func_name_id = newid;
	}

      if (nm->functions.functions_val[a].module_name_id == oldid)
	{
	  nm->functions.functions_val[a].module_name_id = newid;
	}

      for (b = 0; b < nm->functions.functions_val[a].cmds.cmds_len; b++)
	{
	  if (nm->functions.functions_val[a].cmds.cmds_val[b].npcode_cmd_type == CMD_BLOCK)
	    {
	      struct cmd_block *blk;
	      blk = nm->functions.functions_val[a].cmds.cmds_val[b].cmd_u.c_block;
	      for (c = 0; c < blk->c_vars.c_vars_len; c++)
		{
		  replace_id_in_var (blk->c_vars.c_vars_val[c].var, oldid,
				     newid);
		}
	    }
	  if (nm->functions.functions_val[a].cmds.cmds_val[b].npcode_cmd_type == CMD_CALL)
	    {
	      struct npcmd_call *c;
	      c = nm->functions.functions_val[a].cmds.cmds_val[b].cmd_u.c_call;
	  	if (c->func_id == oldid)
	    	{
	      	c->func_id = newid;
	    	}
	    }

	  if (nm->functions.functions_val[a].cmds.cmds_val[b].npcode_cmd_type == CMD_ECALL)
	    {
	      struct ecall *c;
	      c = nm->functions.functions_val[a].cmds.cmds_val[b].cmd_u.c_ecall;
	  	if (c->func_id == oldid)
	    	{
			//printf("ECALL : %d to %d\n",oldid,newid);
	      	c->func_id = newid;
	    	}
	    }


	}

    }


}


void
replace_id_in_var (struct variable_element *var, int oldid, int newid)
{
  int a;
  if (var->name_id == oldid)
    {
      var->name_id = newid;
    }
  for (a = 0; a < var->next.next_len; a++)
    {
      replace_id_in_var (&var->next.next_val[a], oldid, newid);
    }

}

long
call_function (long pc, struct npcmd_call *c)
{
// Dummy function
return 0;
}

void *
get_var_ptr (struct use_variable *use_var, int *size)
{
// Dummy function
return 0;
}






int link_add_string (char *s, int cnt)
{
  int nsize;
  int a;
  char *nstr;


  nstr = (char *) strdup (s);

  for (a = 0; a < this_module->string_table.string_table_len; a++)
    {
      if (strcmp (nstr, this_module->string_table.string_table_val[a].s) == 0)
	{
	  free (nstr);
	  this_module->string_table.string_table_val[a].rcnt += cnt;
	  return a;
	}
    }

  this_module->string_table.string_table_len++;
  nsize =
    sizeof (struct vstring) * this_module->string_table.string_table_len;



  this_module->string_table.string_table_val =
    realloc (this_module->string_table.string_table_val, nsize);



  this_module->string_table.string_table_val[this_module->string_table.
					     string_table_len - 1].s = nstr;
  this_module->string_table.string_table_val[this_module->string_table.
					     string_table_len - 1].rcnt = cnt;
  return this_module->string_table.string_table_len - 1;
}





int link_add_id (char *s, int cnt)
{
  int a;
  //printf ("link_add_id - Finding '%s'\n", s);
  for (a = 0; a < this_module->id_table.id_table_len; a++)
    {
      if (strcmp (s, this_module->id_table.id_table_val[a].s) == 0)
	{
	  //printf ("Found it %d\n", a);
	  this_module->id_table.id_table_val[a].rcnt += cnt;
	  return a;
	}
    }

  // Its new....
  this_module->id_table.id_table_len++;
  this_module->id_table.id_table_val =
    realloc (this_module->id_table.id_table_val,
	     sizeof (struct vstring) * this_module->id_table.id_table_len);
  this_module->id_table.id_table_val[this_module->id_table.id_table_len -
				     1].s = acl_strdup (s);
  this_module->id_table.id_table_val[this_module->id_table.id_table_len -
				     1].rcnt = cnt;

  A4GL_debug ("Created it @ %d\n", this_module->id_table.id_table_len - 1);
  return this_module->id_table.id_table_len - 1;
}




void
link_make_new_param (int *n, struct param **p)
{
  if (this_module->params.params_len <= allocated_params)
    {
      allocated_params += 16;
      this_module->params.params_val =
	realloc (this_module->params.params_val,
		 sizeof (struct param) * allocated_params);
    }
  memset (&this_module->params.params_val[this_module->params.params_len], 0,
	  sizeof (this_module->params.
		  params_val[this_module->params.params_len]));
  this_module->params.params_val[this_module->params.params_len].param_type =
    PARAM_TYPE_EMPTY;
  if (p)
    {
      *p = &this_module->params.params_val[this_module->params.params_len];
    }
  if (n)
    {
      *n = this_module->params.params_len;
    }
  this_module->params.params_len++;
}


int has_function(char *s,int curr) {
	int a;
	for (a=curr+1;a<this_module->functions.functions_len;a++) {
		if (strcmp(GET_ID(this_module->functions.functions_val[a].func_name_id),s)==0) return 1;
	}
	return 0;
}


int cross_check() {
int a;
int ok=1;

// lets check for duplicate functions first...
for (a=0;a<this_module->functions.functions_len;a++) {
	if (has_function(GET_ID(this_module->functions.functions_val[a].func_name_id),a)) {
		printf("Duplicate function : %s\n",GET_ID(this_module->functions.functions_val[a].func_name_id));
		ok=0;
		continue;
	}
}

return 1;
}
