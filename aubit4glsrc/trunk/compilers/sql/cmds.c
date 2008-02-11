char *get_str_list_as_string(str_list *list,char *sep) {
char *rbuff=0;
int a;
        for (a=0;a<list->str_list_entry.str_list_entry_len;a++) {
                if (a) rbuff=make_sql_string_and_free(rbuff,strdup(sep),list->str_list_entry.str_list_entry_val[a], NULL);
                else rbuff=make_sql_string_and_free(list->str_list_entry.str_list_entry_val[a],NULL);
        }
return rbuff;
}



static char *get_select_list_item_list_with_separator (struct s_select *select, struct s_select_list_item_list *slist, char *sep)
{
  int a;
  char *rval;
  if (slist == 0)
    return;

  for (a = 0; a < slist->list.list_len; a++)
    {
      if (a) {
                rval=make_sql_string_and_free(rval, strdup(sep), strdup(get_select_list_item (select, slist->list.list_val[a])),NULL);
        } else {
                rval=strdup(get_select_list_item (select, slist->list.list_val[a]));
        }
    }
    return rval;
}

void
search_sql_variables (struct s_select_list_item_list *l,char dir)
{
  int a;
  if (l == 0)
    return;
  for (a = 0; a < l->list.list_len; a++)
    {
      if (l->list.list_val[a]->data.type == E_SLI_VARIABLE_USAGE)
        {
		A4GL_assertion(1,"Not expected in SQL compiler");
          //l->list.list_val[a]->data.type = E_SLI_VARIABLE;
          //l->list.list_val[a]->data.s_select_list_item_data_u.expression = get_sql_variable_usage (l->list.list_val[a]->data.s_select_list_item_data_u.var_usage,dir);
        }
    }
}

char *
get_select (struct s_select *s, char *forUpdate)
{
  char *str;
  char *ptr;
  char into_buff[65000] = "";

  if (forUpdate == 0)
    forUpdate = "";

  if (s->into)
    {
	strcpy(into_buff,"");

	// No 'INTO' in SQL compiler
        //strcpy(into_buff, get_sql_into_buff(s->into));
        //sprintf (into_buff, "\nINTO %s\n", local_get_expr_as_string_list_with_separator (s->into, ","));
    }

  str = make_select_stmt_v2 (0, s, into_buff);

  ptr = malloc (strlen (str) + strlen (forUpdate) + 1);
  if (strlen (forUpdate))
    {
      sprintf (ptr, "%s%s", str, forUpdate);
    }
  else
    {
      strcpy (ptr, str);
    }
  return ptr;
}



//
//
//
// the get_insert_cmd is derived from the function in lib/liblex/lex_esqlc/compile_c.c
char *
get_insert_cmd (struct struct_insert_cmd *insertCmd,int *converted)
{
  static char buff[64000];
  char *ptr;
  char smbuff[256];
  *converted=0;


  sprintf (smbuff, "INSERT INTO %s ", insertCmd->table);
  if (insertCmd->column_list)
    {
        sprintf(buff,"%s(%s) ", smbuff, get_str_list_as_string(insertCmd->column_list,","));
    } else {
        strcpy(buff, smbuff);
    }

  // Collect all our inbinds..
  if (insertCmd->value_list)
    {
      search_sql_variables (insertCmd->value_list,'i');
    }
  else
    {
      preprocess_sql_statement (insertCmd->subselect);
      search_sql_variables (&insertCmd->subselect->list_of_items,'i');
    }

  if (insertCmd->value_list)
    {
        char *p;
        char *p2;
        p=get_select_list_item_list_with_separator (NULL, insertCmd->value_list, ",");
        A4GL_assertion(p==0,"No values list!");
        strcat(buff,"VALUES (");
        strcat(buff,p);
        strcat(buff,")");
    }
  else
    {
      strcat(buff,get_select (insertCmd->subselect, ""));
    }

    ptr = A4GLSQLCV_check_sql (buff, converted);

    return strdup(ptr);
}







char *get_update_cmd(struct struct_update_cmd *updateCmd, int *converted) {
        int a;
        char *rval;
        //struct struct_update_cmd *u;
        struct s_select fake_select;
        struct s_select_list_item_list l;
        struct s_table t;
        char *ptr;
static char buff[64000];
char smbuff[2000];
      *converted=0;
strcpy(buff,"");

        fake_select.modifier = 0;
        fake_select.limit.start = -1;
        fake_select.limit.end = -1;
        fake_select.limit.offset = -1;
        fake_select.ncolumns = 0;
        fake_select.select_list = 0;
        fake_select.first = 0;
        fake_select.table_elements.tables.tables_len = 0;
        fake_select.table_elements.tables.tables_val = 0;
        fake_select.group_by = 0;
        fake_select.having = 0;
        fake_select.list_of_items.list.list_len = 0;
        fake_select.list_of_items.list.list_val = 0;
        fake_select.where_clause = 0;
        fake_select.next = 0;
        fake_select.sf = 0;
        fake_select.union_op = 0;
        fake_select.into = 0;
        fake_select.first = &t;

        fake_select.first->tabname = updateCmd->table;
        fake_select.first->alias = fake_select.first->tabname;

        fake_select.first->next = NULL;
        fake_select.first->outer_next = NULL;

        fake_select.table_elements.tables.tables_len = 0;
        fake_select.table_elements.tables.tables_val = 0;


        fake_select.where_clause = 0;
        if (updateCmd->where_clause)
          {
            fake_select.where_clause = updateCmd->where_clause->expr_str_u.sl_item;
          }
        fake_select.group_by = 0;
        fake_select.next = 0;
        fake_select.sf = 0;
        fake_select.into = 0;
        fake_select.union_op = 0;
        fake_select.extra_statement = 0;
        fake_select.select_list = updateCmd->value_list;

        A4GLSQLPARSE_from_clause_collect_tables (&fake_select, fake_select.first, &fake_select.table_elements);
        preprocess_sql_statement (&fake_select);
        search_sql_variables (&fake_select.list_of_items,'i');
        sprintf(buff,"UPDATE %s SET ",updateCmd->table);

        A4GL_assertion (updateCmd->column_list == 0, "No column list");
        A4GL_assertion (updateCmd->value_list == 0, "No value list");

        if (updateCmd->value_list->list.list_len == updateCmd->column_list->str_list_entry.str_list_entry_len)
          {
            // Same length..
            for (a = 0; a < updateCmd->value_list->list.list_len; a++)
              {
                if (a)
                  {
                        strcat(buff,",");
                  }
                rval = get_select_list_item (0, updateCmd->value_list->list.list_val[a]);
                sprintf (smbuff, "%s=%s", updateCmd->column_list->str_list_entry.str_list_entry_val[a], rval);
                strcat(buff,smbuff);
                free (rval);
              }
          }
        else
          {
                strcat(buff,"(");
            for (a = 0; a < updateCmd->column_list->str_list_entry.str_list_entry_len; a++)
              {
                if (a) {
                        strcat(buff,",");
                }
                strcat(buff, updateCmd->column_list->str_list_entry.str_list_entry_val[a]);
              }
            strcat (buff, ")=(");
            for (a = 0; a < updateCmd->value_list->list.list_len; a++)
              {
                if (a) {
                        strcat(buff,",");
                }
                rval = get_select_list_item (0, updateCmd->value_list->list.list_val[a]);
                strcat(buff,rval);
                free (rval);
              }
                strcat(buff,")");

          }
        if (updateCmd->where_clause)
          {
            if (updateCmd->where_clause->expr_type == ET_EXPR_WHERE_CURRENT_OF)
              {
                struct expr_str *e;
                strcat (buff, " WHERE CURRENT OF ");
                e=updateCmd->where_clause->expr_str_u.expr_expr;
                A4GL_assertion(e->expr_type!=ET_EXPR_IDENTIFIER,"Expecting an identifier");
                strcat(buff,e->expr_str_u.expr_string);
                //strcat(buff,get_ident_as_string(updateCmd->where_clause->expr_str_u.expr_expr));
              }
            else
              {
                strcat(buff," WHERE ");
                        strcat(buff, get_select_list_item (&fake_select,
                                              updateCmd->where_clause->expr_str_u.sl_item));
              }
          }


      ptr = A4GLSQLCV_check_sql (buff, converted);

return strdup(ptr);
}



char * get_delete_cmd (struct struct_delete_cmd *deleteCmd, int *converted) {
char topbuff[64000]="";
char smbuff[64000]="";
char *ptr;


      *converted=0;

      sprintf (topbuff, "DELETE FROM %s", deleteCmd->table);

      if (deleteCmd->where_clause != NULL)
        {

          if (deleteCmd->where_clause->expr_type == ET_EXPR_WHERE_CURRENT_OF)
            {
                char buff[2000];
                if (deleteCmd->where_clause->expr_str_u.expr_expr->expr_type==ET_EXPR_VARIABLE_IDENTIFIER) {
                        //yylineno=line_for_cmd;
                        //a4gl_yyerror("You cant use a variable id in this position...");
                        return 0;
                } else {
                        //printf("decode=%s\n", decode_e_expr_type(deleteCmd->where_clause->expr_str_u.expr_expr->expr_type));
                        sprintf(smbuff," WHERE CURRENT OF %s",deleteCmd->where_clause->expr_str_u.expr_expr->expr_str_u.expr_string);
                }
                /*
                if (deleteCmd->where_clause->expr_str_u.expr_type==ET_EXPR_
                ptr = A4GLSQLCV_check_sql (topbuff, converted);
                strcpy(topbuff,buff);
                sprintf(buff,
                strcpy(topbuff,"_r");
                */


                //,get_ident_as_string (deleteCmd->where_clause->expr_str_u.expr_expr));
            }
          else
            {
              struct s_select fake_select;
              struct s_select_list_item_list l;
              struct s_table t;
              fake_select.modifier = 0;
              fake_select.limit.start = -1;
              fake_select.limit.end = -1;
              fake_select.limit.offset = -1;
              fake_select.ncolumns = 0;
              fake_select.select_list = 0;
              fake_select.first = 0;
              fake_select.table_elements.tables.tables_len = 0;
              fake_select.table_elements.tables.tables_val = 0;
              fake_select.group_by = 0;
              fake_select.having = 0;
              fake_select.list_of_items.list.list_len = 0;
              fake_select.list_of_items.list.list_val = 0;
              fake_select.where_clause = 0;
              fake_select.next = 0;
              fake_select.sf = 0;
              fake_select.union_op = 0;
              fake_select.into = 0;

              fake_select.first = &t;

              fake_select.first->tabname = deleteCmd->table;
              fake_select.first->alias = fake_select.first->tabname;
              fake_select.first->next = NULL;
              fake_select.first->outer_next = NULL;
              fake_select.table_elements.tables.tables_len = 0;
              fake_select.table_elements.tables.tables_val = 0;

              fake_select.where_clause = deleteCmd->where_clause->expr_str_u.sl_item;
              fake_select.group_by = 0;
              fake_select.next = 0;
              fake_select.sf = 0;
              fake_select.into = 0;
              fake_select.union_op = 0;
              fake_select.extra_statement = 0;
              l.list.list_len = 0;
              l.list.list_val = 0;
              fake_select.select_list = &l;
              A4GLSQLPARSE_from_clause_collect_tables (&fake_select, fake_select.first, &fake_select.table_elements);

              preprocess_sql_statement (&fake_select);
              search_sql_variables (&fake_select.list_of_items,'i');

              sprintf (smbuff, " WHERE %s", get_select_list_item (&fake_select, deleteCmd->where_clause->expr_str_u.sl_item));

   }
        strcat(topbuff,smbuff);
  }



      ptr = A4GLSQLCV_check_sql (topbuff, converted);
return strdup(ptr);
}

