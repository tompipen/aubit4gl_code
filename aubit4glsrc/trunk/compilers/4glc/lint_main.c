
#include "a4gl_libaubit4gl.h"
char *lint_get_variable_usage_as_string (struct variable_usage *var_usage);

int read_module_definition(module_definition *s,char *filename);
int yylineno;

FILE *lintfile;

module_definition this_module;

main(int argc,char *argv[]) {
module_definition *m;
int a;

if (argc<2) {
	printf("Usage : %s infile infile...\n",argv[0]);
	exit(2);
}

open_lintfile(0);

m=malloc(sizeof(struct module_definition)*(argc-1));

for (a=1;a<argc;a++) {
	char buff[256];
	sprintf(buff, argv[a]);
	if (strstr(buff,".dat")!=0) {
		char *p;
		p=strstr(buff,".dat");
		*p=0;
		//printf("Buff=%s\n",buff);
	}
	printf("Loading %s : ", buff); fflush(stdout);
	if ( A4GL_read_data_from_file("module_definition",&m[a-1],buff)) {
		printf("OK...\n", argv[a]);
	} else {
		printf("- Failed to load %s\n", argv[a]);
		exit(1);
	}
}

check_program(m, argc-1);
close_lintfile();
exit(0);
}



void
A4GL_warn (char *s)
{
  if (!A4GL_isyes (acl_getenv ("SUPPRESSWARNINGS")))
    {
      fprintf (stderr, "Warning : %s @ line %d\n", s, yylineno);
    }
}

/*
void
A4GL_lint (char *s)
{
  if (!A4GL_isyes (acl_getenv ("SUPPRESSLINT")))
    {
      fprintf (stderr, "  LINT Warning : %s @ line %d\n", s, yylineno);
    }
}

*/





char *expr_as_string_when_possible(expr_str *e) {

FILE *f;
  switch (e->expr_type)
    {
    case ET_EXPR_LITERAL_EMPTY_STRING:
      return "";
    /*case ET_EXPR_SUBSTRING:
      return "?"; */
    case ET_EXPR_LITERAL_STRING:
      return e->expr_str_u.expr_string;
      break;


    case ET_EXPR_VARIABLE_USAGE:

      {
		return lint_get_variable_usage_as_string(e->expr_str_u.expr_variable_usage);
		//return "FGLvariable"; 
      }
      break;

    case ET_EXPR_LITERAL_LONG:

      {
        static char smbuff[200];
        sprintf (smbuff, "%d", e->expr_str_u.expr_long);
        return smbuff;
      }
      break;
    case ET_EXPR_OP_USING:
      return "?";               // a date or a number - we dont care...
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
    case ET_EXPR_ASCII:
    case ET_EXPR_FCALL:
      return "?";

        case ET_EXPR_FALSE: return "0";
        case ET_EXPR_TRUE: return "1";

        case ET_EXPR_OP_CONCAT:
                      {
                char buff[2000];
                sprintf(buff,"%s,%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
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
                return "?";
        case ET_EXPR_OP_MONTH:
                return "?";


        case ET_EXPR_OP_MINUTE:
                return "?";

        case ET_EXPR_COLUMN:
                return "";

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
                sprintf(buff,"%s+%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
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
        //upshift (p);
        return p;
      }
      break;
    case ET_EXPR_DOWNSHIFT:

      {
        char *p;
        p = strdup (expr_as_string_when_possible (e->expr_str_u.expr_expr));
        //downshift (p);
        return p;
      }
      break;
    default:
        printf ("Unhandled expression in dynamic sql(%s) - line %d\n", expr_name (e->expr_type), yylineno);
        return "?";
      //exit (2);
      //    }
      }
return "X";
}



void set_yytext(char *s) {
}

