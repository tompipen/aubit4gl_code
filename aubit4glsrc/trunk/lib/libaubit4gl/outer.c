#include "a4gl_libaubit4gl_int.h"



struct s_table_join
{
  char *table;
  char *alias;
};


//static struct s_select_list_item *joins[10][10];



//static int ntables=0;
//static struct s_table_join tables[200];




/*
for  (a=0;a<select->table_elements.ntables;a++) {
	tables[a].table=select->table_elements.tables[a].tabname;
	tables[a].alias=select->table_elements.tables[a].alias;
}
*/




static int
can_outer (struct s_select *select,
	   struct s_table *t, char *fill, struct s_table_list *tl)
{
  int has_outer = 0;

  while (t)
    {
      /* A tablename of '@' is a placeholder for an outer - so we don't need
       * to print it...
       * */

      if (strcmp (t->tabname, "@") != 0)
	{
	  t = t->next;
	  continue;
	}

      if (t->outer_next)
	{
	  struct s_table *t2;
	  //char *main_table;
	  //char *outer_table;
	  //char alias_buff[255];
	  //int b;
	  has_outer++;


	  t2 = t->outer_next;
	  if (t2->next == 0 && t2->outer_next == 0);
	  else
	    {
	      return 0;
	    }

	}

      t = t->next;

    }
  return has_outer;

}

int
A4GLSQLPARSE_from_clause_join (struct s_select *select,
			       struct s_table *t, char *fill,
			       struct s_table_list *tl)
{
  char buff[2000];
  struct s_table *last_t=0;
  int a = 0;
  strcpy (buff, "");
  if (!can_outer (select, t, fill, tl))
    return 0;




  while (t)
    {
      /* A tablename of '@' is a placeholder for an outer - so we don't need
       * to print it...
       * */

      if (strcmp (t->tabname, "@") != 0)
	{
	  if (a)
	    strcat (buff, ",");
	  strcat (buff, A4GLSQLCV_make_tablename (t->tabname, t->alias));
	  a++;
	  last_t = t;
	}




      if (t->outer_next)
	{
	  struct s_table *t2;
	  char *main_table;
	  char *outer_table;
	  char alias_buff[255];
	  int b;


	  t2 = t->outer_next;
	  if (t2->next == 0 && t2->outer_next == 0);
	  else
	    {
	      return 0;
	    }

	  main_table = last_t->alias;
	  if (!main_table)
	    main_table = last_t->tabname;
	  outer_table = t2->alias;
	  if (!outer_table)
	    {
	      outer_table = t2->tabname;
	      SPRINTF1 (alias_buff, "%s ", t2->tabname);
	    }
	  else
	    {
	      SPRINTF2 (alias_buff, "%s As %s", t2->tabname, t2->alias);
	    }


	  for (b = 0; b < select->list_of_items.nlist; b++)
	    {
	      struct s_select_list_item *p;
	      struct s_select_list_item *l;
	      struct s_select_list_item *r;
	      char *lt;
	      char *rt;
	      char *lc;
	      char *rc;
	      if (select->list_of_items.list[b]->type == E_SLI_JOIN)
		{
		  //int tnl;
		  //int tnr;
		  int found = 0;
		  p = select->list_of_items.list[b];
		  l = p->u_data.complex_expr.left;
		  r = p->u_data.complex_expr.right;
		  lt = l->u_data.column.tabname;
		  rt = r->u_data.column.tabname;
		  lc = l->u_data.column.colname;
		  rc = r->u_data.column.colname;

		  if (lt == 0 || rt == 0)
		    continue;
		  if (strcmp (lt, main_table) == 0
		      && strcmp (rt, outer_table) == 0)
		    found = 1;
		  if (strcmp (rt, main_table) == 0
		      && strcmp (lt, outer_table) == 0)
		    found = 1;
		  if (found)
		    {
		      char buff2[256];
		      SPRINTF2 (buff2, " LEFT OUTER JOIN %s ON %s", alias_buff,
			       get_select_list_item (select,
						     select->list_of_items.
						     list[b]));
		      select->list_of_items.list[b]->type = E_SLI_LITERAL;
		      p->u_data.expression = acl_strdup ("(1=1)");
		      strcat (buff, buff2);
		    }
		}
	    }
	}


      t = t->next;
    }
  strcpy (fill, buff);
  return 1;
}


#ifdef OBSOLETE
static void dump_joins (void)
{
  int a;
  int b;
  A4GL_debug ("---------------------------\n");
  for (a = 0; a < 10; a++)
    {
      if (tables[a].table == 0)
	continue;
      A4GL_debug ("%-20s ", tables[a].table);
      for (b = 0; b < a; b++)
	{
	  if (joins[a][b]) {
	    A4GL_debug ("1 ");
	  }
	  else {
	    A4GL_debug ("0 ");
	    }
	}
      A4GL_debug ("\n");
    }
  A4GL_debug ("---------------------------\n");

}
#endif



/* =============================== EOF ============================== */
