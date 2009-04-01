
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
//#include "cmds.x.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
char *expr_get_variable_usage_as_string (struct variable_usage *var_usage) ;
//static char *local_field_name_list_as_char(struct fh_field_list *fl) ;

char *
upshift (char *a)
{
  int i;
  static char buff[256];
  strcpy (buff, a);
  for (i = 0; i < strlen (buff); i++)
    {
      buff[i] = a4gl_toupper (buff[i]);
    }
  return buff;
}

/**
 *  * Downshift a string.
 *   *
 *    * @param a The string to be downshifted.
 *     * @return A pointer to a staic buffer where the string downshifted is putted.
 *      */
char *
downshift (char *a)
{
  int i;
  static char buff[256];
  strcpy (buff, a);
  for (i = 0; i < strlen (buff); i++)
    {
      buff[i] = a4gl_tolower (buff[i]);
    }
  return buff;
}




#ifdef OLD
char *expr_as_string_when_possible(expr_str *e) {

FILE *f;
  switch (e->expr_type)
    {
    case ET_EXPR_LITERAL_EMPTY_STRING:
      return "";
    //case ET_EXPR_SUBSTRING: return "?1?";
    case ET_EXPR_LITERAL_STRING:
	{
		char buff[23000];
		sprintf(buff,"\"%s\"", e->expr_str_u.expr_string);
      return strdup(buff);
	}
      break;

    case ET_EXPR_IDENTIFIER:
	{
		char buff[23000];
		sprintf(buff,"%s", e->expr_str_u.expr_string);
      return strdup(buff);
	}
      break;

    case ET_EXPR_VARIABLE_USAGE:
        return expr_get_variable_usage_as_string(e->expr_str_u.expr_variable_usage);
	break;

    case ET_EXPR_BRACKET:
      {
        static char smbuff[1024];
        char *ptr;
        ptr=strdup(expr_as_string_when_possible(e->expr_str_u.expr_expr));
        sprintf (smbuff, "(%s)", ptr);
        free(ptr);
        return smbuff;
      }
      break;



    case ET_EXPR_LITERAL_LONG:

      {
        static char smbuff[200];
        sprintf (smbuff, " %d", e->expr_str_u.expr_long);
        return smbuff;
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
      return "<ASCII>";

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
		strcpy(buff3,"");
		if (e->expr_str_u. expr_function_call->parameters) {
			for (a=0;a<e->expr_str_u. expr_function_call->parameters->list.list_len;a++) {
				if (a) strcat(buff3,",");
				strcpy(buff2,expr_as_string_when_possible(e->expr_str_u. expr_function_call->parameters->list.list_val[a]));
				strcat(buff3,buff2);
			}
		}
               sprintf(buff,"%s(%s)", e->expr_str_u. expr_function_call  -> fname,buff3) ;
      		return strdup(buff);
	}

        case ET_EXPR_FALSE: return "0";
        case ET_EXPR_TRUE: return "1";

        case ET_EXPR_OP_CONCAT:
                      {
                char buff[2000];
                sprintf(buff,"%s,%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;
    case ET_EXPR_OP_USING:
	                      {
                char buff[2000];
                sprintf(buff,"%s USING %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }

      break;

        case ET_EXPR_NOT:
                      {
                char buff[2000];
                sprintf(buff,"NOT(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
                return strdup(buff);
                }
                break;
        case ET_EXPR_OP_ISNULL:
                      {
                char buff[2000];
                sprintf(buff,"ISNULL(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_ISNOTNULL:
                      {
                char buff[2000];
                sprintf(buff,"IS NOT NULL(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_EQUAL:
                                {
                char buff[2000];
                sprintf(buff,"%s=%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_MATCHES:
                                {
                char buff[2000];
                sprintf(buff,"%s MATCHES %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_NOT_MATCHES:
                                {
                char buff[2000];
                sprintf(buff,"%s NOT MATCHES %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;



        case ET_EXPR_OP_GREATER_THAN:

                                {
                char buff[2000];
                sprintf(buff,"%s>%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_LESS_THAN:
                                {
                char buff[2000];
                sprintf(buff,"%s<%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;
        case ET_EXPR_INFIELD: {
			char buff[2000];
			strcpy(buff,"INFIELD(");
				strcat(buff,local_field_name_list_as_char(e->expr_str_u.expr_infield->field_list));
			strcat(buff,")");
			return buff; //"INFIELD(..)";
		}

        case ET_EXPR_OP_GREATER_THAN_EQ:
                                {
                char buff[2000];
                sprintf(buff,"%s>=%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_LESS_THAN_EQ:
                                {
                char buff[2000];
                sprintf(buff,"%s<=%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;



        case ET_EXPR_OP_NOT_EQUAL:
                                {
                char buff[2000];
                sprintf(buff,"%s!=%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_AND:
                                {
                char buff[2000];
                sprintf(buff,"%s AND %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;


        case ET_EXPR_OP_MOD:
                                {
                char buff[2000];
                sprintf(buff,"%s MOD %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_OR:
                                {
                char buff[2000];
                sprintf(buff,"%s AND %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
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
                sprintf(buff,"%s*%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;
        case ET_EXPR_OP_DIV:
                {
                char buff[2000];
                sprintf(buff,"%s/%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_ADD:
                {
                char buff[2000];
                sprintf(buff,"%s+%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;
        case ET_EXPR_OP_SUB:
                {
                char buff[2000];
                sprintf(buff,"%s-%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_SPACES:
                return " ";

        case ET_EXPR_TIME_EXPR: return "TIME";
        case ET_EXPR_TODAY: return "TODAY";


    case ET_EXPR_NULL:
      return "NULL";

        case ET_EXPR_DAY_FUNC:
      {
        char *p;
        char buff[256];
        sprintf (buff, "DAY(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
        return strdup (buff);
      }
      break;

    case ET_EXPR_YEAR_FUNC:

      {
        char *p;
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

    default:
		A4GL_pause_execution(); // ---  Place holder for error handling  --- SAFE TO LEAVE IN...
        printf ("Unhandled expression in dynamic sql(%s)\n", expr_name (e->expr_type));
        return  expr_name (e->expr_type);
      //exit (2);
      //    }
      }
return "X";
}



#endif

#define ET_EXPR_VARIABLE_USAGE_call expr_get_variable_usage_as_string


#include "expr_as_string_when_possible.c"

char *expr_get_variable_usage_as_string (struct variable_usage *var_usage) {
        char buff[2000];

        sprintf(buff, "%s",var_usage->variable_name);
        if (var_usage->subscripts.subscripts_len) {
                int a;
                strcat(buff, "[");
                for (a=0;a<var_usage->subscripts.subscripts_len;a++) {
                        if(a) strcat(buff, ",");
                        strcat(buff, expr_as_string_when_possible(var_usage->subscripts.subscripts_val[a]));
                }
                strcat(buff, "]");
        }
        if (var_usage->substrings_start) {
                strcat(buff, "[");
                strcat(buff, expr_as_string_when_possible(var_usage->substrings_start));
                if (var_usage->substrings_end) {
                        strcat(buff, ",");
                        strcat(buff, expr_as_string_when_possible(var_usage->substrings_end));
                }
                strcat(buff, "]");
        }
        if (var_usage->next) {
                char *ptr;
                strcat(buff,".");
                ptr=expr_get_variable_usage_as_string(var_usage->next);
                strcat(buff, ptr);
                free(ptr);
        }

        return strdup(buff);
}

#ifdef OLD
static char *local_ident_as_string(expr_str *f,int quote) {
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



static char *local_field_name_list_as_char(struct fh_field_list *fl) {
int a;
char *ptr=0;
char *ptr_field;

A4GL_assertion(fl==0,"No field list...");

ptr=acl_malloc2(10); /* Set it up initially...*/
strcpy(ptr,"");
for (a=0;a<fl->field_list_entries.field_list_entries_len;a++) {
        if (fl->field_list_entries.field_list_entries_val[a].fieldsub) {
                ptr_field=local_field_name_as_char(local_ident_as_string(fl->field_list_entries.field_list_entries_val[a].field,1), expr_as_string_when_possible(fl->field_list_entries.field_list_entries_val[a].fieldsub));
        } else {
                ptr_field=local_ident_as_string(fl->field_list_entries.field_list_entries_val[a].field,1);

        }
        ptr=acl_realloc(ptr,strlen(ptr)+strlen(ptr_field)+2);
        if (strlen(ptr)) strcat(ptr,",");
	ptr_field=A4GL_strip_quotes(ptr_field);
        strcat(ptr,ptr_field);
}

return ptr;
}
#endif
