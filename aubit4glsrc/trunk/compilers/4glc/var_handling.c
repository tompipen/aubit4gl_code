#include "variables.h"
#include "a4gl_4glc_int.h"
#include "var_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void variable_usage_as_string_int (struct variable_usage *var,
					  char *buff, int ident_flg);

struct variable_usage *
new_variable_usage (struct variable_usage *old, char *partname, char prepend)
{
  struct variable_usage *newv;
  int a;
  newv = acl_malloc2 (sizeof (struct variable_usage));

  newv->variable_name = acl_strdup (partname);
  newv->nsubscripts = 0;
  for (a = 0; a < 10; a++)
    {
      newv->subscripts[a] = 0;
    }

  newv->nsubstrings = 0;
  newv->substrings[0] = 0;
  newv->substrings[1] = 0;

  newv->variable_id = -1;
  newv->scope = 0;
  newv->next = 0;


  if (old)
    {
      if (prepend)
	{
	  newv->next = old;
	  return newv;
	}
      else
	{
	  old->next = newv;
	  return old;
	}
    }
  else
    {
      return newv;
    }
}


struct variable_usage *
append_variable_usage (struct variable_usage *old,
		       struct variable_usage *new_usg)
{
  struct variable_usage *orig;
  orig = old;
  while (old->next)
    old = old->next;
  old->next = new_usg;
  return orig;
}

void
set_variable_usage_subscript (struct variable_usage *var, int sub, char *val)
{
  var->subscripts[sub] = acl_strdup (val);
  if (sub >= var->nsubscripts)
    {
      var->nsubscripts = sub + 1;
    }
}


void
set_variable_usage_substr (struct variable_usage *var, int sub, char *val)
{
  if (sub > 1)
    {
      a4gl_yyerror ("Substring expression expected to be start or start,end");
      return;
    }
  var->substrings[sub] = acl_strdup (val);
  if (sub >= var->nsubstrings)
    {
      var->nsubstrings = sub + 1;
    }
}




char *
variable_usage_as_string (struct variable_usage *var, int ident_flg)
{
  static char buff[2048];
  int is_variable;
  strcpy (buff, "");
  if (ident_flg == VAR_USG_ANY)
    {
      char sbuff[2048];
      // Lets see what we've got...
      strcpy (sbuff, "");
      variable_usage_as_string_int (var, sbuff, VAR_USG_SIMPLE);
      if (scan_variable (sbuff) == -1)
	is_variable = 0;
      else
	is_variable = 1;

      if (is_variable)
	ident_flg = VAR_USG_VARIABLE;
      else
	ident_flg = VAR_USG_IDENT;
    }

  // At this point we should have
  // VAR_USG_VARIABLE, VAR_USG_IDENT, or VAR_USG_ANY
  variable_usage_as_string_int (var, buff, ident_flg);
  return buff;
}



static void
variable_usage_as_string_int (struct variable_usage *var, char *buff,
			      int ident_flg)
{
  int a;
  char tmpbuff[2048];
  int type=0;
  int arrsize, size, level;
  char arrbuff[256];
  arrsize=0;

  strcat (buff, var->variable_name);

  if (ident_flg != VAR_USG_SIMPLE && ident_flg != VAR_USG_IDENT)
    {
      get_variable_dets (buff, &type, &arrsize, &size, &level, arrbuff);
    }

  if (ident_flg != VAR_USG_SIMPLE)
    {				// If we're doing it "simple" ...
      // we dont need to worry about this - 
      // we just want the variable structure
      // not the array contents...

      if (var->nsubscripts && var->nsubstrings == 0)
	{
	  // It might be a substring..
	  //printf("Type = %x\n",type);
	  //
	  //

	  //printf("%d\n",arrsize);
	  //printf("%d\n",type);
	  //printf("%d\n",ident_flg);

	  if (arrsize == 0 || type == -1 || ident_flg == VAR_USG_IDENT)
	    {
	      //printf("Fix it...\n");
	      // This is a substring - not a subscript...
	      var->nsubstrings = var->nsubscripts;
	      var->substrings[0] = var->subscripts[0];
	      var->substrings[1] = var->subscripts[1];
	      if (var->nsubstrings > 2)
		{
		  a4gl_yyerror ("Too many subscripts for a substring");
		  return;
		}
	      var->nsubscripts = 0;
	    }
	}


      if (var->nsubscripts)
	{
	  if (ident_flg == VAR_USG_VARIABLE)
	    {
	      strcat (buff, "[");

	      for (a = 0; a < var->nsubscripts; a++)
		{
		  if (a)
		    strcat (buff, "][");
		  sprintf (tmpbuff, "((%s)-1)", var->subscripts[a]);
		  strcat (buff, tmpbuff);
		}
	      strcat (buff, "]");

	    }
	  else
	    {
		// Shouldn't happen ?
	          strcpy(buff, A4GLSQLCV_make_substr_s (A4GLSQLCV_check_colname (0, buff), 0,0,0));


	    }
	}

      if (var->nsubstrings)
	{
	  char tmpbuff[2048];
	  if (var->nsubstrings > 2)
	    {
	      A4GL_exitwith ("Shouldn't get to here...");
	      return;
	    }

	  if (var->nsubstrings == 1)
	    {
	      if (ident_flg == VAR_USG_VARIABLE)
		{
		  sprintf (tmpbuff, " a4gl_substr(%s , %d , %s ,0) ", buff,
			   type, var->substrings[0]);
		  strcpy (buff, tmpbuff);
		  strcpy (tmpbuff, "");
	  	strcat (buff, tmpbuff);
		}
	      else
		{
	          char *n;
	          n = A4GLSQLCV_make_substr_s (A4GLSQLCV_check_colname (0, buff), 1,var->substrings[0],0);
		strcpy(buff,n);
		}
	    }

	  if (var->nsubstrings == 2)
	    {
	      if (ident_flg == VAR_USG_VARIABLE)
		{
		  sprintf (tmpbuff, " a4gl_substr(%s , %d , %s , %s , 0) ",
			   buff, type, var->substrings[0],
			   var->substrings[1]);
		  strcpy (buff, tmpbuff);
		  strcpy (tmpbuff, "");
	  	strcat (buff, tmpbuff);
		}
	      else
		{
	          char *n;
	          n = A4GLSQLCV_make_substr_s (A4GLSQLCV_check_colname (0, buff), 2,var->substrings[0],var->substrings[1]);
		strcpy(buff,n);

		}
	    }
	}
    }

  if (var->next)
    {
      strcat (buff, ".");
    }

  if (var->next)
    {
      variable_usage_as_string_int (var->next, buff, ident_flg);
    }
}



struct num_list *
new_num_list_item (char *s)
{
  struct num_list *nl;
  nl = acl_malloc2 (sizeof (struct num_list));
  nl->num = acl_strdup (s);
  nl->next = 0;
  return nl;
}

struct num_list *
append_num_list_items (struct num_list *list, struct num_list *next)
{
  struct num_list *orig;
  orig = list;
  while (list->next != 0)
    list = list->next;
  list->next = next;
  return orig;
}
