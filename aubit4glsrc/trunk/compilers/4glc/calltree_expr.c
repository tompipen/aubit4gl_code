
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
//#include "cmds.x.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
char *expr_get_variable_usage_as_string (struct variable_usage *var_usage) ;

char *
upshift (char *a)
{
  int i;
  static char buff[256];
  strcpy (buff, a);
  for (i = 0; i < strlen (buff); i++)
    {
      buff[i] = toupper (buff[i]);
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
      buff[i] = tolower (buff[i]);
    }
  return buff;
}



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


    case ET_EXPR_VARIABLE_USAGE:
        return expr_get_variable_usage_as_string(e->expr_str_u.expr_variable_usage);
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
    case ET_EXPR_FCALL:
	{
		
               char buff[2000];
               sprintf(buff,"%s(..)", e->expr_str_u. expr_function_call  -> fname) ;
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
			return "INFIELD(..)";
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
		A4GL_pause_execution();
        printf ("Unhandled expression in dynamic sql(%s)\n", expr_name (e->expr_type));
        return  expr_name (e->expr_type);
      //exit (2);
      //    }
      }
return "X";
}

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


