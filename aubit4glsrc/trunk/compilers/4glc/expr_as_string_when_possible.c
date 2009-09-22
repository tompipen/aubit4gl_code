
static char *expr_as_string_ident_as_string(expr_str *f,int quote) {
static char buff[2000];
        switch (f->expr_type) {
                case ET_EXPR_IDENTIFIER:
                        if (quote) {
                                sprintf(buff,"\"%s\"", f->expr_str_u.expr_string);
                        } else {
                                sprintf(buff,"%s", f->expr_str_u.expr_string);
                        }
                        return buff;
                case ET_E_V_OR_LIT_STRING:
                        sprintf(buff,"%s", f->expr_str_u.expr_string);
                        return buff;

                default:
                        A4GL_assertion(1,"Not handled");
        }
        return "";
}


static char *local_field_name_as_char(char*fname,char *sub) {
static char buff[256];
SPRINTF2(buff,"%s[%s]",fname,sub);
return buff;
}


static char *local_rettype (char *s) {
  static char rs[20] = "long";
  int a;

  strcpy(rs,"unknown");

  A4GL_debug ("In rettype : %s", A4GL_null_as_null (s));

  a = atoi (s);

  A4GL_debug ("In rettype");
  if (A4GL_has_datatype_function_i (a, "OUTPUT"))
    {
      /* char *(*function) (); */
      char *(*function) (void);
      A4GL_debug ("In datatype");
      function = A4GL_get_datatype_function_i (a, "OUTPUT");
      A4GL_debug ("Copy");
      strcpy (rs, function ());
      A4GL_debug ("Returning %s\n", A4GL_null_as_null (rs));
      return rs;
    }
  if (strcmp (s, "0") == 0)
    strcpy (rs, "CHAR");
  if (strcmp (s, "1") == 0)
    strcpy (rs, "SMALLINT");
  if (strcmp (s, "2") == 0)
    strcpy (rs, "INTEGER");
  if (strcmp (s, "3") == 0)
    strcpy (rs, "FLOAT");
  if (strcmp (s, "4") == 0)
    strcpy (rs, "SMALLFLOAT");
  if (strcmp (s, "5") == 0)
    strcpy (rs, "DECIMAL");
  if (strcmp (s, "6") == 0)
    strcpy (rs, "INTEGER");
  if (strcmp (s, "7") == 0)
    strcpy (rs, "DATE");
  if (strcmp (s, "8") == 0)
    strcpy (rs, "MONEY");
  if (strcmp (s, "10") == 0)
    strcpy (rs, "DATETIME");
  if (strcmp (s, "11") == 0)
    strcpy (rs, "BYTE");
  if (strcmp (s, "12") == 0)
    strcpy (rs, "TEXT");
  if (strcmp (s, "13") == 0)
    strcpy (rs, "VARCHAR");
  if (strcmp (s, "14") == 0)
    strcpy (rs, "INTERVAL");
  return strdup (rs);
}



/**
 *  *  * Gets the C data type corresponding to 4gl data type
 *   *   *
 *    *    * @param s A string with the numeric 4gl data type (@see find_type())
 *     *     * @return The string (static) with the C declaration
 *      *      */
static char * local_rettype_integer (int n)
{
          char s[200];

            /*static char rs[20] = "long";*/
            /*int a;*/

            A4GL_debug ("rettype_integer : %d\n", n);

              SPRINTF1 (s, "%d", n);
                return local_rettype (s);
}


static char *expr_as_string_field_name_list_as_char(struct fh_field_list *fl) {
int a;
char *ptr=0;
char *ptr_field;

A4GL_assertion(fl==0,"No field list...");

ptr=acl_malloc2(10); /* Set it up initially...*/
strcpy(ptr,"");
for (a=0;a<fl->field_list_entries.field_list_entries_len;a++) {
        if (fl->field_list_entries.field_list_entries_val[a].fieldsub) {
                ptr_field=local_field_name_as_char(expr_as_string_ident_as_string(fl->field_list_entries.field_list_entries_val[a].field,1), expr_as_string_when_possible(fl->field_list_entries.field_list_entries_val[a].fieldsub));
        } else {
                ptr_field=expr_as_string_ident_as_string(fl->field_list_entries.field_list_entries_val[a].field,1);

        }
        ptr=acl_realloc(ptr,strlen(ptr)+strlen(ptr_field)+2);
        if (strlen(ptr)) strcat(ptr,",");
        ptr_field=A4GL_strip_quotes(ptr_field);
        strcat(ptr,ptr_field);
}

return ptr;
}

char *
expr_as_string_when_possible (expr_str * e)
{

  switch (e->expr_type)
    {
    case ET_EXPR_LITERAL_EMPTY_STRING:
      return "\"\"";
      //case ET_EXPR_SUBSTRING: return "?1?";
    case ET_EXPR_LITERAL_STRING:
      {
	char buff[23000];
	sprintf (buff, "\"%s\"", e->expr_str_u.expr_string);
	return strdup (buff);
      }
      break;


    case ET_EXPR_IDENTIFIER:
      {
	char buff[23000];
	sprintf (buff, "%s", e->expr_str_u.expr_string);
	return strdup (buff);
      }
      break;

    case ET_EXPR_VARIABLE_USAGE:
      return ET_EXPR_VARIABLE_USAGE_call (e->expr_str_u.expr_variable_usage);
      break;

    case ET_EXPR_BRACKET:
      {
	static char smbuff[1024];
	char *ptr;
	ptr = strdup (expr_as_string_when_possible (e->expr_str_u.expr_expr));
	sprintf (smbuff, "(%s)", ptr);
	free (ptr);
	return strdup(smbuff);
      }
      break;


    case ET_EXPR_SQLERRMESSAGE:
	return strdup("SQLERRMESSAGE");
	break;

    case ET_EXPR_LITERAL_LONG:

      {
	static char smbuff[200];
	sprintf (smbuff, " %ld", e->expr_str_u.expr_long);
	return strdup(smbuff);
      }
      break;

    case ET_EXPR_OP_CLIP:

      {
	char *p;
	p = strdup (expr_as_string_when_possible (e->expr_str_u.expr_expr));
	A4GL_trim (p);
	return p;
      }
      break;
    case ET_EXPR_GET_FLDBUF:

      return "<GET_FLDBUF>";
      
    case ET_EXPR_ASCII:
         {
         char buff[20000];
         char *ptr;
               ptr=strdup(expr_as_string_when_possible(e->expr_str_u.expr_expr));
               sprintf(buff,"ASCII(%s)",ptr);
               free(ptr);
               return strdup(buff);
         }

    case ET_EXPR_FIELD_TOUCHED:
      return "FIELD_TOUCHED(...)";
    case ET_EXPR_NOT_FIELD_TOUCHED:
      return "NOT_FIELD_TOUCHED(...)";

    case ET_EXPR_FCALL:
      {

	int a;
	char buff[5000];
	char buff2[5000];
	char buff3[5000];
	strcpy (buff3, "");
	if (e->expr_str_u.expr_function_call->parameters)
	  {
	    for (a = 0; a < e->expr_str_u.expr_function_call->parameters->list.list_len; a++)
	      {
		if (a)
		  strcat (buff3, ",");
		strcpy (buff2, expr_as_string_when_possible (e->expr_str_u.expr_function_call->parameters->list.list_val[a]));
		strcat (buff3, buff2);
	      }
	  }
	sprintf (buff, "%s(%s)", e->expr_str_u.expr_function_call->fname, buff3);
	return strdup (buff);
      }

    case ET_EXPR_FALSE:
      return "FALSE";

    case ET_EXPR_TRUE:
      return "TRUE";

    case ET_EXPR_OP_CONCAT:
      {
	char buff[2000];
	sprintf (buff, "%s,%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;
    case ET_EXPR_OP_USING:
      {
	char buff[2000];
	sprintf (buff, "%s USING %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }

      break;

    case ET_EXPR_NOT:
      {
	char buff[2000];
	sprintf (buff, "NOT(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
	return strdup (buff);
      }
      break;
    case ET_EXPR_OP_ISNULL:
      {
	char buff[2000];
	sprintf (buff, "ISNULL(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_ISNOTNULL:
      {
	char buff[2000];
	sprintf (buff, "IS NOT NULL(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_EQUAL:
      {
	char buff[2000];
	sprintf (buff, "%s=%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_MATCHES:
      {
	char buff[2000];
	sprintf (buff, "%s MATCHES %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_NOT_MATCHES:
      {
	char buff[2000];
	sprintf (buff, "%s NOT MATCHES %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;



    case ET_EXPR_OP_GREATER_THAN:

      {
	char buff[2000];
	sprintf (buff, "%s>%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_LESS_THAN:
      {
	char buff[2000];
	sprintf (buff, "%s<%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;
    case ET_EXPR_INFIELD:
      {
	static char buff[2000];
	strcpy (buff, "INFIELD(");
	strcat (buff, expr_as_string_field_name_list_as_char (e->expr_str_u.expr_infield->field_list));
	strcat (buff, ")");
	return strdup(buff);		//"INFIELD(..)";
      }

    case ET_EXPR_OP_GREATER_THAN_EQ:
      {
	char buff[2000];
	sprintf (buff, "%s>=%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_LESS_THAN_EQ:
      {
	char buff[2000];
	sprintf (buff, "%s<=%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;



    case ET_EXPR_OP_NOT_EQUAL:
      {
	char buff[2000];
	sprintf (buff, "%s!=%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_AND:
      {
	char buff[2000];
	sprintf (buff, "%s AND %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;


    case ET_EXPR_OP_MOD:
      {
	char buff[2000];
	sprintf (buff, "%s MOD %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_OR:
      {
	char buff[2000];
	sprintf (buff, "%s AND %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;



    case ET_EXPR_DATE_EXPR:
      return "DATE";

    case ET_EXPR_DATE_FUNC:
      {
	char buff[256];
	sprintf (buff, "DATE(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
	return strdup (buff);
      }
      break;
    case ET_EXPR_MONTH_FUNC:
      {
	char buff[256];
	sprintf (buff, "MONTH(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
	return strdup (buff);
      }
      break;

    case ET_EXPR_LITERAL_DOUBLE_STR:
      {
	char buff[256];
	sprintf (buff, "\"%s\"", e->expr_str_u.expr_string);
	return strdup (buff);
      }

    case ET_EXPR_OP_DAY:
      return "DAY(..)";
    case ET_EXPR_OP_MONTH:
      return "MONTH(..)";


    case ET_EXPR_OP_MINUTE:
      return "MINUTE(..)";

    case ET_EXPR_COLUMN:
      return "COLUMN ..";

    case ET_EXPR_CURRENT:
      return " CURRENT";
    case ET_EXPR_OP_MULT:
      {
	char buff[2000];
	sprintf (buff, "%s*%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;
    case ET_EXPR_OP_DIV:
      {
	char buff[2000];
	sprintf (buff, "%s/%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_ADD:
      {
	char buff[2000];
	sprintf (buff, "%s+%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_POWER:
      {
	char buff[2000];
	sprintf (buff, "%s**%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_SUB:
      {
	char buff[2000];
	sprintf (buff, "%s-%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left),
		 expr_as_string_when_possible (e->expr_str_u.expr_op->right));
	return strdup (buff);
      }
      break;

    case ET_EXPR_OP_SPACES:
      return " ";

    case ET_EXPR_TIME_EXPR:
      return "TIME";
    case ET_EXPR_TODAY:
      return "TODAY";


    case ET_EXPR_NULL:
      return "NULL";

    case ET_EXPR_DAY_FUNC:
      {
	char buff[256];
	sprintf (buff, "DAY(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
	return strdup (buff);
      }
      break;

    case ET_EXPR_YEAR_FUNC:

      {
	char buff[256];
	sprintf (buff, "YEAR(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
	return strdup (buff);
      }
      break;
    case ET_EXPR_UPSHIFT:

      {
	char *p;
	p = strdup (expr_as_string_when_possible (e->expr_str_u.expr_expr));
	upshift (p);
	return p;
      }
      break;
    case ET_EXPR_DOWNSHIFT:

      {
	char *p;
	p = strdup (expr_as_string_when_possible (e->expr_str_u.expr_expr));
	downshift (p);
	return p;
      }
      break;

    case ET_EXPR_PAGENO:
		return strdup("pageno");
    case ET_EXPR_LINENO:
		return strdup("lineno");

case ET_EXPR_CAST:
	{
		char buff[20000];
		sprintf(buff,"CAST (%s AS %s)", expr_as_string_when_possible(e->expr_str_u.expr_cast->expr),local_rettype_integer(e->expr_str_u.expr_cast->target_dtype));
		return strdup(buff);
	}
	break;
    case ET_EXPR_ASSOC:
	return strdup("ASSOC");

case ET_EXPR_PARAMETER:
	return e->expr_str_u.expr_param.expr_string;

case ET_EXPR_BOUND_FCALL:
   return strdup("BOUND_FCALL");

case ET_EXPR_SHARED_FCALL:
	{
	char buff[200];
		sprintf(buff,"ET_EXPR_SHARED_FCALL:%p",e);
   		return strdup(buff);
	}
	

case ET_EXPR_MEMBER_FCALL_NEW:
	return strdup("MEMBER_FUNCTIONCALL");

    default:
      A4GL_pause_execution ();	// ---  Place holder for error handling  --- SAFE TO LEAVE IN...
      printf ("Unhandled expression in dynamic sql(%s)\n", expr_name (e->expr_type));
      return expr_name (e->expr_type);
      //exit (2);
      //    }
    }
  return "X";
}



