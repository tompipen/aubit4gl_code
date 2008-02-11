#include "a4gl_libaubit4gl.h"
#include "a4gl_expr.h"
#include "lint.h"

#define FAKE_DTYPE_BOOL 90
extern int yylineno;


void ensure_dtype (struct expr_str *e, int dtype, int nonull);
void ensure_bool (struct expr_str *s, int notnull);
void ensure_smint (struct expr_str *s, int notnull);
void ensure_char (struct expr_str *s, int notnull);
void ensure_dtime (struct expr_str *s, int notnull);
void ensure_date (struct expr_str *s, int notnull);
void ensure_int (struct expr_str *s, int notnull);
void ensure_decimal (struct expr_str *s, int notnull);
void ensure_float (struct expr_str *s, int notnull);
void ensure_smfloat (struct expr_str *s, int notnull);
void ensure_interval (struct expr_str *s, int notnull);
void ensure_byte (struct expr_str *s, int notnull);
int expr_datatype (struct expr_str *p);
void make_cast (struct expr_str *s, int target_dtype, int notnull, int force);
void fix_compare (char *op, struct expr_str *s);
void force_float (struct expr_str *s);
//struct expr_str *get_expr_datatype(int n) ;

void
ensure_dtype (struct expr_str *e, int dtype, int notnull)
{

  dtype = dtype & DTYPE_MASK;
  switch (dtype & DTYPE_MASK)
    {
    case DTYPE_VCHAR:
      ensure_char (e, notnull);
      return;
    case DTYPE_CHAR:
      ensure_char (e, notnull);
      return;
    case DTYPE_SMINT:
      ensure_smint (e, notnull);
      return;
    case DTYPE_INT:
      ensure_int (e, notnull);
      return;
    case DTYPE_DTIME:
      ensure_dtime (e, notnull);
      return;
    case DTYPE_DATE:
      ensure_date (e, notnull);
      return;
    case DTYPE_FLOAT:
      ensure_float (e, notnull);
      return;
    case DTYPE_SMFLOAT:
      ensure_smfloat (e, notnull);
      return;
    case DTYPE_DECIMAL:
      ensure_decimal (e, notnull);
      return;
    case DTYPE_INTERVAL:
      ensure_interval (e, notnull);
      return;
    case DTYPE_BYTE:
      ensure_byte (e, notnull);
      return;
    case DTYPE_TEXT:
      ensure_byte (e, notnull);
      return;
    case FAKE_DTYPE_BOOL:
      ensure_bool (e, notnull);
      return;
    }

  PRINTF ("Unhandled ensure ; %d (%x)\n", dtype, dtype);
}



void
ensure_char (struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_CHAR || (d & DTYPE_MASK) == DTYPE_VCHAR)
        return;
    }
  make_cast (s, DTYPE_CHAR, notnull, 0);
}


void
ensure_dtime (struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_DTIME)
        return;
    }
  make_cast (s, DTYPE_DTIME, notnull, 0);
}

void
ensure_byte (struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_BYTE || (d & DTYPE_MASK) == DTYPE_TEXT)
        return;
    }
  if ((d & DTYPE_MASK) == DTYPE_TEXT)
    return;
  if ((d & DTYPE_MASK) == DTYPE_BYTE)
    return;
  make_cast (s, DTYPE_BYTE, notnull, 0);
}

void
ensure_interval (struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_INTERVAL)
        return;
    }
  make_cast (s, DTYPE_INTERVAL, notnull, 0);
}


void
force_float (struct expr_str *s)
{
  make_cast (s, DTYPE_FLOAT, 0, 1);
}

void
ensure_float (struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_FLOAT)
        return;
    }
  make_cast (s, DTYPE_FLOAT, notnull, 0);
}

void
ensure_smfloat (struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_SMFLOAT)
        return;
    }
  make_cast (s, DTYPE_SMFLOAT, notnull, 0);
}
void
ensure_date (struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_DATE)
        return;
    }
  make_cast (s, DTYPE_DATE, notnull, 0);
}

void
ensure_int (struct expr_str *s, int notnull)
{
  int d;
  if (!notnull)
    {
      d = expr_datatype (s);
      if (((d & DTYPE_MASK) == DTYPE_INT) && notnull == 0)
        return;
      if (s->expr_type==ET_EXPR_LITERAL_LONG) {
		return;
	}
    }
  make_cast (s, DTYPE_INT, notnull, 0);
}

void
ensure_smint (struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_SMINT)
        return;
    }
  make_cast (s, DTYPE_INT, notnull, 0);
}

void
ensure_decimal (struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_DECIMAL)
        return;
    }
  make_cast (s, DTYPE_DECIMAL, notnull, 0);
}


void
ensure_bool (struct expr_str *s, int notnull)
{
  //struct expr_str *p;
  //int d;
  int l;
  int r;

  if (s->expr_type == ET_EXPR_OP_NOT_EQUAL)
    {
      fix_compare ("<>", s);
    }
  if (s->expr_type == ET_EXPR_OP_EQUAL)
    {
      fix_compare ("=", s);
    }


  switch (s->expr_type)
    {
    case ET_EXPR_TRUE : 
		return;

    case ET_EXPR_FALSE : 
		return;
    case ET_EXPR_OP_OR:
      ensure_bool (s->expr_str_u.expr_op->left, notnull);
      ensure_bool (s->expr_str_u.expr_op->right, notnull);
      return;

    case ET_EXPR_OP_AND:
      ensure_bool (s->expr_str_u.expr_op->left, notnull);
      ensure_bool (s->expr_str_u.expr_op->right, notnull);
      return;

    case ET_EXPR_OP_ISNULL:
    case ET_EXPR_OP_ISNOTNULL:
      return;

    case ET_EXPR_OP_MATCHES:
    case ET_EXPR_OP_NOT_MATCHES:
      ensure_char (s->expr_str_u.expr_op->left, 1);
      ensure_char (s->expr_str_u.expr_op->right, 1);
      return;
    case ET_EXPR_NOT:
      ensure_bool (s->expr_str_u.expr_expr, notnull);
      return;

    case ET_EXPR_OP_NOT_EQUAL:
    case ET_EXPR_OP_GREATER_THAN:
    case ET_EXPR_OP_GREATER_THAN_EQ:
    case ET_EXPR_OP_LESS_THAN:
    case ET_EXPR_OP_LESS_THAN_EQ:
    case ET_EXPR_OP_LIKE:
    case ET_EXPR_OP_NOT_LIKE:
    case ET_EXPR_OP_EQUAL:

/* ANY CHANGES HERE SHOULD BE IN THIS IN THE expr_datatype bit too */

      l = expr_datatype (s->expr_str_u.expr_op->left) & DTYPE_MASK;
      r = expr_datatype (s->expr_str_u.expr_op->right) & DTYPE_MASK;



      if (l != r)
        {
          int fixed = 0;
          // Comparing differing types...
          if (l == DTYPE_INT && r == DTYPE_SMINT)
            {
              ensure_int (s->expr_str_u.expr_op->right, 0);
              fixed++;
            }
          if (l == DTYPE_DECIMAL && r == DTYPE_INT)
            {
              ensure_dtype (s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
              fixed++;
            }
          if (l == DTYPE_DECIMAL && r == DTYPE_SMINT)
            {
              ensure_dtype (s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
              fixed++;
            }
          if (l == DTYPE_DECIMAL && r == DTYPE_FLOAT)
            {
              ensure_dtype (s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
              fixed++;
            }

          if (l == DTYPE_SMINT && r == DTYPE_INT)
            {
              ensure_int (s->expr_str_u.expr_op->left, 0);
              fixed++;
            }



          if (l == FAKE_DTYPE_BOOL && (r == DTYPE_INT || r == DTYPE_SMINT))
            {
              ensure_int (s->expr_str_u.expr_op->left, 0);
              fixed++;
            }
          if (r == FAKE_DTYPE_BOOL && (l == DTYPE_INT || l == DTYPE_SMINT))
            {
              ensure_int (s->expr_str_u.expr_op->right, 0);
              fixed++;
            }

          if (!fixed)
            {
		char buff[256];
              	sprintf(buff,"'%s'!='%s' @ %d", dtype_as_string(l), dtype_as_string(r), yylineno);
		A4GL_lint (0, 0, "DIFFCOMP", "Different types in comparison", buff);
		//A4GL_lint(buff );
            }

        }
      return;

    case ET_EXPR_CAST:
      if (s->expr_str_u.expr_cast->target_dtype == FAKE_DTYPE_BOOL)
        {
          return;
        }
      // No break so this will drop through...
    default:
	
      A4GL_debug ("Implicit cast to boolean @ %d\n", yylineno);
    }

  make_cast (s, FAKE_DTYPE_BOOL, notnull, 0);
}


void
make_cast (struct expr_str *s, int target_dtype, int notnull, int force)
{
  int d;
  struct expr_str *p;
  d = expr_datatype (s);

  if (d == target_dtype && notnull == 0)
    return;                     // Happy Days!

  p = malloc (sizeof (struct expr_str));
  A4GL_assertion (p == 0, "Failed to allocate");
  memcpy (p, s, sizeof (struct expr_str));
  memset (s, 0, sizeof (struct expr_str));
  s->expr_type = ET_EXPR_CAST;
  s->expr_str_u.expr_cast = malloc (sizeof (struct s_expr_cast));
  s->expr_str_u.expr_cast->expr = p;
  s->expr_str_u.expr_cast->target_dtype = target_dtype & DTYPE_MASK;
  s->expr_str_u.expr_cast->src_dtype = d & DTYPE_MASK;
  s->expr_str_u.expr_cast->notnull = notnull;
  s->expr_str_u.expr_cast->force = force;
}



void
fix_compare (char *op, struct expr_str *s)
{
  int l;
  int r;
  int fixed = 0;

  l = expr_datatype (s->expr_str_u.expr_op->left) & DTYPE_MASK;
  r = expr_datatype (s->expr_str_u.expr_op->right) & DTYPE_MASK;

  if (strcmp(op,"=")==0) {
		struct expr_str *le;
		struct expr_str *re;
		char *len=0;
		char *ren=0;
		le=s->expr_str_u.expr_op->left;
		re=s->expr_str_u.expr_op->right;	

		if (le->expr_type==ET_EXPR_FCALL)  {
			len=le->expr_str_u.expr_function_call->fname;
		}
		if (re->expr_type==ET_EXPR_FCALL)  {
			ren=re->expr_str_u.expr_function_call->fname;
		}
		if (len ) {
			if (re->expr_type==ET_EXPR_LITERAL_LONG) {
				if (strcmp(len,"fgl_lastkey")==0) {
					A4GL_lint(le->expr_str_u.expr_function_call->module,le->expr_str_u.expr_function_call->line, "LASTKEYLIT", "Comparing fgl_lastkey against a literal integer",0);
				}
			}
		}
		if (ren ) {
			if (le->expr_type==ET_EXPR_LITERAL_LONG) {
				if (strcmp(ren,"fgl_lastkey")==0) {
					A4GL_lint(re->expr_str_u.expr_function_call->module,re->expr_str_u.expr_function_call->line, "LASTKEYLIT", "Comparing fgl_lastkey against a literal integer",0);
				}
			}
		}
	
  }



  // Comparing differing types...
  if (l == DTYPE_INT && r == DTYPE_SMINT)
    {
      ensure_int (s->expr_str_u.expr_op->right, 0);
      fixed++;
    }

  if (l == DTYPE_DECIMAL && r == DTYPE_INT)
    {
      ensure_dtype (s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (l == DTYPE_DECIMAL && r == DTYPE_SMINT)
    {
      ensure_dtype (s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (l == DTYPE_DECIMAL && r == DTYPE_FLOAT)
    {
      ensure_dtype (s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (r == DTYPE_DECIMAL && l == DTYPE_FLOAT)
    {
      ensure_dtype (s->expr_str_u.expr_op->left, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (l == DTYPE_SMINT && r == DTYPE_INT)
    {
      ensure_int (s->expr_str_u.expr_op->left, 0);
      fixed++;
    }

  if (l == FAKE_DTYPE_BOOL && (r == DTYPE_INT || r == DTYPE_SMINT))
    {
      ensure_int (s->expr_str_u.expr_op->left, 0);
      fixed++;
    }

  if (r == FAKE_DTYPE_BOOL && (l == DTYPE_INT || l == DTYPE_SMINT))
    {
      ensure_int (s->expr_str_u.expr_op->right, 0);
      fixed++;
    }

  if ((l==DTYPE_INT || l==DTYPE_SMINT) && r==DTYPE_CHAR) {
        if (s->expr_str_u.expr_op->right->expr_type==ET_EXPR_LITERAL_STRING) {
                char *a;
                a=strdup(s->expr_str_u.expr_op->right->expr_str_u.expr_string);
                A4GL_trim(a);

                if (strlen(a)==0 && (strcmp(op,"<>")==0 || strcmp(op,"=")==0 ) ) {
                        // Its a blank string...
                        // they mean is null or is not null
                        struct expr_str *l;
                        l=s->expr_str_u.expr_op->left;
                        if (strcmp(op,"<>")==0) {
                                s->expr_type=ET_EXPR_OP_ISNOTNULL;
                                s->expr_str_u.expr_expr=l;
                                free(a);
                                return ;
                        }
                        if (strcmp(op,"=")==0) {
                                s->expr_type=ET_EXPR_OP_ISNULL;
                                s->expr_str_u.expr_expr=l;
                                free(a);
                                return ;
                        }
                }
                free(a);

        }
  }
  l = expr_datatype (s->expr_str_u.expr_op->left) & DTYPE_MASK;
  r = expr_datatype (s->expr_str_u.expr_op->right) & DTYPE_MASK;

  //printf ("COMPARE %s %d %d\n", op, l, r);
}


static int
is_numeric (int n)
{
  n = n & DTYPE_MASK;
  switch (n)
    {
    case DTYPE_INT:
    case DTYPE_SMINT:
    case DTYPE_FLOAT:
    case DTYPE_SMFLOAT:
    case DTYPE_DECIMAL:
    case DTYPE_SERIAL:
      return 1;
    }
  return 0;
}



int
expr_datatype (struct expr_str *p)
{
  int l;
  int r;
  //int a;
char buff[256];
  switch (p->expr_type)
    {

    case ET_EXPR_CACHED:
		return expr_datatype(get_expr_datatype(p->expr_str_u.expr_long));

    case ET_EXPR_OP_SPACES:
		 ensure_int (p->expr_str_u.expr_expr, 0);
	return DTYPE_CHAR;

    case ET_EXPR_COLUMN:
		 ensure_int (p->expr_str_u.expr_expr, 0);
	return DTYPE_CHAR;

    case ET_EXPR_INFIELD:
      return FAKE_DTYPE_BOOL;

    case ET_EXPR_ASCII:
      ensure_int (p->expr_str_u.expr_expr, 0);
      return DTYPE_CHAR;

    case ET_EXPR_DOWNSHIFT:
    case ET_EXPR_UPSHIFT:
      ensure_char (p->expr_str_u.expr_expr, 0);
      return DTYPE_CHAR;

    case ET_EXPR_EXTEND:
      ensure_dtime (p->expr_str_u.expr_extend->expr, 0);
      return DTYPE_DTIME;


    case ET_EXPR_DATE_FUNC:
      //ensure_char (ptr->expr_str_u.expr_expr,0);
      return DTYPE_DATE;

    case ET_EXPR_NEG:
      if (is_numeric (expr_datatype (p->expr_str_u.expr_expr)))
        {
          return expr_datatype (p->expr_str_u.expr_expr);
        }
      if (p->expr_str_u.expr_expr == DTYPE_CHAR)
        return DTYPE_FLOAT;
    case ET_EXPR_CONCAT_LIST:
      return DTYPE_CHAR;
    case ET_EXPR_GET_FLDBUF:
      return DTYPE_CHAR;

    case ET_EXPR_OP_CONCAT:
      ensure_char (p->expr_str_u.expr_op->left, 0);
      ensure_char (p->expr_str_u.expr_op->right, 0);
      return DTYPE_CHAR;
    case ET_EXPR_TIME_EXPR:
      return DTYPE_DTIME;
    case ET_EXPR_TEMP:
      return p->expr_str_u.expr_tmp->dtype;

    case ET_EXPR_NOT:
      ensure_bool (p->expr_str_u.expr_expr, 0);
      return FAKE_DTYPE_BOOL;

    case ET_EXPR_TODAY:
      return DTYPE_DATE;
    case ET_EXPR_OP_SECOND:
    case ET_EXPR_OP_HOUR:
    case ET_EXPR_OP_MINUTE:
    case ET_EXPR_OP_DAY:
    case ET_EXPR_OP_MONTH:
    case ET_EXPR_OP_YEAR:
      return DTYPE_INTERVAL;




    /* 
 * 	case ET_EXPR_SUBSTRING:
      return DTYPE_CHAR;
      break;
*/

    case ET_EXPR_CURRENT:
      return DTYPE_DTIME;
    case ET_EXPR_OP_OR:
    case ET_EXPR_OP_AND:
      ensure_bool (p->expr_str_u.expr_op->left, 0);
      ensure_bool (p->expr_str_u.expr_op->right, 0);
      return DTYPE_INT;         // Actually boolean
    case ET_EXPR_CAST:
      return p->expr_str_u.expr_cast->target_dtype;
    case ET_EXPR_DAY_FUNC:
    case ET_EXPR_MONTH_FUNC:
    case ET_EXPR_YEAR_FUNC:
      return DTYPE_INT;

    case ET_EXPR_OP_ISNULL:
    case ET_EXPR_OP_ISNOTNULL:
      return FAKE_DTYPE_BOOL;   // Actually a Boolean...

    case ET_EXPR_OP_LIKE:
    case ET_EXPR_OP_NOT_LIKE:
    case ET_EXPR_OP_MATCHES:
    case ET_EXPR_OP_NOT_MATCHES:
      ensure_char (p->expr_str_u.expr_op->left, 0);
      ensure_char (p->expr_str_u.expr_op->right, 0);
      return FAKE_DTYPE_BOOL;   // Actually a Boolean...

    case ET_EXPR_OP_NOT_EQUAL:
      fix_compare ("<>", p);
      return FAKE_DTYPE_BOOL;   // Actually a Boolean...
    case ET_EXPR_OP_GREATER_THAN:
      fix_compare (">", p);
      return FAKE_DTYPE_BOOL;   // Actually a Boolean...
    case ET_EXPR_OP_GREATER_THAN_EQ:
      fix_compare (">=", p);
      return FAKE_DTYPE_BOOL;   // Actually a Boolean...
    case ET_EXPR_OP_LESS_THAN:
      fix_compare ("<", p);
      return FAKE_DTYPE_BOOL;   // Actually a Boolean...
    case ET_EXPR_OP_LESS_THAN_EQ:
      fix_compare ("<=", p);
      return FAKE_DTYPE_BOOL;   // Actually a Boolean...

    case ET_EXPR_OP_EQUAL:
      fix_compare ("=", p);
      return FAKE_DTYPE_BOOL;   // Actually a Boolean...


    case ET_EXPR_OP_USING:
      ensure_char (p->expr_str_u.expr_op->right, 0);
      return DTYPE_CHAR;

    case ET_EXPR_OP_CLIP:
      ensure_char (p->expr_str_u.expr_expr, 0);
      return DTYPE_CHAR;

    case ET_EXPR_STRING:
      return DTYPE_CHAR;
      break;

case ET_EXPR_VARIABLE_USAGE :
	{
	struct variable_usage *u;
		u=p->expr_str_u.expr_variable_usage;
		while (u->next) u=u->next;
	return u->datatype;
	}

	A4GL_assertion(1,"Fixme");
	break;

    case ET_EXPR_LITERAL_DOUBLE_STR:
      return DTYPE_FLOAT;

    case ET_EXPR_LITERAL_EMPTY_STRING:
      return DTYPE_CHAR;

    case ET_EXPR_LITERAL_STRING:
      return DTYPE_CHAR;
      break;

    case ET_EXPR_FALSE:
    case ET_EXPR_TRUE:
      return FAKE_DTYPE_BOOL;

    case ET_EXPR_LITERAL_LONG:
      if (p->expr_str_u.expr_long <= SHRT_MAX && p->expr_str_u.expr_long >= SHRT_MIN)
        {
          return DTYPE_SMINT;
        }
      return DTYPE_INT;

    case ET_EXPR_FCALL:
		yylineno=p->expr_str_u.expr_function_call->line;
		
		return find_function_single_rtype(p->expr_str_u.expr_function_call->fname);
		printf("Cant do calls yet\n");
		exit(1);
	/*
      a = find_function (p->expr_str_u.expr_function_call->fname);
      if (a == -1)
        {
          if (!write_meta ())
            {
              FPRINTF (stderr,
                       "No return type for function %s - assuming integer (%d %s)\n",
                       p->expr_str_u.expr_function_call->fname,
                       p->expr_str_u.expr_function_call->line,
                       p->expr_str_u.expr_function_call->module);
              PRINTF ("Not found : %s\n",
                      p->expr_str_u.expr_function_call->fname);
            }
          return DTYPE_INT;
        }
      if (functions[a].nreturn != 1)
        {
          FPRINTF (stderr, "Returns : %d\n", functions[a].nreturn);
          set_yytext (p->expr_str_u.expr_function_call->fname);
          a4gl_yyerror ("Returns not exactly one value");
          return 0;
        }
	
      return functions[a].return_dtype[0];
	*/
	return DTYPE_CHAR;

    case ET_EXPR_OP_MOD:
      return DTYPE_INT;



    case ET_EXPR_OP_ADD:
      l = expr_datatype (p->expr_str_u.expr_op->left) & DTYPE_MASK;
      r = expr_datatype (p->expr_str_u.expr_op->right) & DTYPE_MASK;


      if (l == DTYPE_DATE && r == DTYPE_INTERVAL)
        {
          struct expr_str *right;
          right = p->expr_str_u.expr_op->right;

          if (right->expr_type == ET_EXPR_OP_DAY)
            {                   // Fools I tell you !!!
              p->expr_str_u.expr_op->right = right->expr_str_u.expr_expr;
              ensure_int (p->expr_str_u.expr_op->right, 1);
              ensure_int (p->expr_str_u.expr_op->left, 1);
              ensure_date (p, 0);
            }
          else
            {

              if (right->expr_type == ET_EXPR_OP_MONTH || right->expr_type == ET_EXPR_OP_YEAR)
                {
                  return DTYPE_DATE;
                }
              PRINTF ("Not fixed date+interval %s\n", expr_name (right->expr_type));
              PRINTF ("dtype right = %d\n", expr_datatype (p->expr_str_u.expr_op->right));


              return DTYPE_DTIME;
            }
          return DTYPE_DATE;
        }
      if (r == DTYPE_INT
          && p->expr_str_u.expr_op->right->expr_type == ET_EXPR_LITERAL_LONG)
        {
          r = l;
        }

      if (l == DTYPE_INT
          && p->expr_str_u.expr_op->left->expr_type == ET_EXPR_LITERAL_LONG)
        {
          l = r;
        }

      if (l == r)
        {
          return l;
        }

      if (l == DTYPE_SMINT && r == DTYPE_INT)
        {
          ensure_int (p->expr_str_u.expr_op->left, 0);
          ensure_int (p->expr_str_u.expr_op->right, 0);
          return DTYPE_INT;
        }


      if (l == DTYPE_SMINT && r == FAKE_DTYPE_BOOL)
        {
          ensure_smint (p->expr_str_u.expr_op->left, 0);
          ensure_smint (p->expr_str_u.expr_op->right, 0);
		A4GL_lint (0, 0, "BOOLMATH", "BOOLEAN used in maths operation",0);
          return DTYPE_SMINT;
        }

      if (l == FAKE_DTYPE_BOOL && r == DTYPE_SMINT)
        {
          ensure_smint (p->expr_str_u.expr_op->left, 0);
          ensure_smint (p->expr_str_u.expr_op->right, 0);
		A4GL_lint (0, 0, "BOOLMATH", "BOOLEAN used in maths operation",0);
          return DTYPE_SMINT;
        }


      if (l == DTYPE_INT && r == FAKE_DTYPE_BOOL)
        {
          ensure_int (p->expr_str_u.expr_op->left, 0);
          ensure_int (p->expr_str_u.expr_op->right, 0);
		A4GL_lint (0, 0, "BOOLMATH", "BOOLEAN used in maths operation",0);
          return DTYPE_INT;
        }

      if (l == FAKE_DTYPE_BOOL && r == DTYPE_INT)
        {
          ensure_int (p->expr_str_u.expr_op->left, 0);
          ensure_int (p->expr_str_u.expr_op->right, 0);
		A4GL_lint (0, 0, "BOOLMATH", "BOOLEAN used in maths operation",0);
          return DTYPE_INT;
        }


      if (r == DTYPE_SMINT && l == DTYPE_INT)
        {
          ensure_int (p->expr_str_u.expr_op->left, 0);
          ensure_int (p->expr_str_u.expr_op->right, 0);
          return DTYPE_INT;
        }

      if (r == DTYPE_DATE && l == DTYPE_INT)
        {
          ensure_int (p->expr_str_u.expr_op->left, 0);
          ensure_int (p->expr_str_u.expr_op->right, 0);
          ensure_date (p, 0);
          return DTYPE_DATE;
        }
      if (l == DTYPE_DTIME && r == DTYPE_INTERVAL)
        {
          return DTYPE_DTIME;
        }
      if (r == DTYPE_DATE && l == DTYPE_SMINT)
        {

          ensure_int (p->expr_str_u.expr_op->left, 0);
          ensure_int (p->expr_str_u.expr_op->right, 0);
          ensure_date (p, 0);
          return DTYPE_DATE;
        }

      if (l == DTYPE_DATE && r == DTYPE_INT)
        {
          ensure_int (p->expr_str_u.expr_op->left, 1);
          ensure_int (p->expr_str_u.expr_op->right, 1);
          ensure_date (p, 0);
          return DTYPE_DATE;
        }

      if (l == DTYPE_DATE && r == DTYPE_SMINT)
        {
          ensure_int (p->expr_str_u.expr_op->left, 1);
          ensure_int (p->expr_str_u.expr_op->right, 1);
          ensure_date (p, 0);
          return DTYPE_DATE;
        }

      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
        {
          ensure_decimal (p->expr_str_u.expr_op->left, 0);
          ensure_decimal (p->expr_str_u.expr_op->right, 0);
          return DTYPE_DECIMAL;
        }

      if (l == DTYPE_FLOAT || r == DTYPE_FLOAT)
        {
          ensure_float (p->expr_str_u.expr_op->left, 0);
          ensure_float (p->expr_str_u.expr_op->right, 0);
          return DTYPE_FLOAT;
        }

	
		sprintf(buff, "%s!=%s",dtype_as_string(l), dtype_as_string(r));
		A4GL_lint (0, 0, "DIFFMATH", "Different types in operation", buff);
      		fprintf (stderr, "UNHANDLED ADD %d(%s) %d(%s) (%x %x)\n",
               		p->expr_str_u.expr_op->left->expr_type,
               		expr_name (p->expr_str_u.expr_op->left->expr_type),
               		p->expr_str_u.expr_op->right->expr_type,
               		expr_name (p->expr_str_u.expr_op->right->expr_type), l, r);
      return DTYPE_INT;

    case ET_EXPR_AGGREGATE:
        return DTYPE_FLOAT;

    case ET_EXPR_OP_DIV:
      l = expr_datatype (p->expr_str_u.expr_op->left) & DTYPE_MASK;
      r = expr_datatype (p->expr_str_u.expr_op->right) & DTYPE_MASK;

      if ((l == DTYPE_INT || l == DTYPE_SMINT) && (r == DTYPE_INT || r == DTYPE_SMINT))
        {
          force_float (p->expr_str_u.expr_op->left);
          force_float (p->expr_str_u.expr_op->right);
          ensure_dtype (p, DTYPE_FLOAT, 0);
          return DTYPE_FLOAT;
        }


      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
        {
          ensure_dtype (p->expr_str_u.expr_op->left, DTYPE_DECIMAL, 0);
          ensure_dtype (p->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
          return DTYPE_DECIMAL;
        }

      if (l == DTYPE_INT || l == DTYPE_SMINT || l == DTYPE_FLOAT || l == DTYPE_SMFLOAT)
        {
          ensure_dtype (p->expr_str_u.expr_op->left, DTYPE_FLOAT, 0);
          ensure_dtype (p->expr_str_u.expr_op->right, DTYPE_FLOAT, 0);
          l = DTYPE_FLOAT;
        }

      if (r == DTYPE_INT || r == DTYPE_SMINT || r == DTYPE_FLOAT || r == DTYPE_SMFLOAT)
        {
          ensure_dtype (p->expr_str_u.expr_op->left, DTYPE_FLOAT, 0);
          ensure_dtype (p->expr_str_u.expr_op->right, DTYPE_FLOAT, 0);
          r = DTYPE_FLOAT;
        }

      if (l == DTYPE_FLOAT && r == DTYPE_FLOAT)
        return DTYPE_FLOAT;

		sprintf(buff, "%s!=%s",dtype_as_string(l), dtype_as_string(r));
		A4GL_lint (0, 0, "DIFFMATH", "Different types in operation (/)", buff);

      fprintf (stderr, "UNHANDLED DIV %d(%s) %d(%s) (%x %x)\n",
               p->expr_str_u.expr_op->left->expr_type,
               expr_name (p->expr_str_u.expr_op->left->expr_type),
               p->expr_str_u.expr_op->right->expr_type,
               expr_name (p->expr_str_u.expr_op->right->expr_type), l, r);

    case ET_EXPR_OP_POWER:
      return DTYPE_FLOAT;



    case ET_EXPR_OP_MULT:

      l = expr_datatype (p->expr_str_u.expr_op->left) & DTYPE_MASK;
      r = expr_datatype (p->expr_str_u.expr_op->right) & DTYPE_MASK;

      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
        {
          if (p->expr_str_u.expr_op->left->expr_type == ET_EXPR_LITERAL_LONG)
            {
              struct expr_str *tmp;
              tmp = p->expr_str_u.expr_op->left;
              p->expr_str_u.expr_op->left = p->expr_str_u.expr_op->right;
              p->expr_str_u.expr_op->right = tmp;
            }
          ensure_decimal (p->expr_str_u.expr_op->left, 0);
          ensure_decimal (p->expr_str_u.expr_op->right, 0);

          return DTYPE_DECIMAL;
        }
      if (l == DTYPE_SMINT)
        l = DTYPE_INT;
      if (r == DTYPE_SMINT)
        r = DTYPE_INT;
      if (l == DTYPE_SMFLOAT)
        l = DTYPE_FLOAT;
      if (r == DTYPE_SMFLOAT)
        r = DTYPE_FLOAT;
      if (l == r)
        return l;

      if (l == DTYPE_FLOAT && r == DTYPE_FLOAT)
        {
          ensure_float (p->expr_str_u.expr_op->left, 0);
          ensure_float (p->expr_str_u.expr_op->right, 0);

          return DTYPE_FLOAT;
        }

      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
        {
          ensure_decimal (p->expr_str_u.expr_op->left, 0);
          ensure_decimal (p->expr_str_u.expr_op->right, 0);
          return DTYPE_DECIMAL;
        }

      if (l == DTYPE_INT && r == DTYPE_FLOAT)
        {
          ensure_float (p->expr_str_u.expr_op->left, 0);
          ensure_float (p->expr_str_u.expr_op->right, 0);
          return DTYPE_FLOAT;
        }

      if (l == DTYPE_FLOAT && r == DTYPE_INT)
        {
          ensure_float (p->expr_str_u.expr_op->left, 0);
          ensure_float (p->expr_str_u.expr_op->right, 0);
          return DTYPE_FLOAT;
        }
		sprintf(buff, "%s!=%s",dtype_as_string(l), dtype_as_string(r));
		//A4GL_pause_execution();
		A4GL_lint (0, 0, "DIFFMATH", "Different types in operation (*)", buff);
      fprintf (stderr, "UNHANDLED MULT %d(%s) %d(%s) (%x %x)\n",
               p->expr_str_u.expr_op->left->expr_type,
               expr_name (p->expr_str_u.expr_op->left->expr_type),
               p->expr_str_u.expr_op->right->expr_type,
               expr_name (p->expr_str_u.expr_op->right->expr_type), l, r);




    case ET_EXPR_OP_SUB:
      l = expr_datatype (p->expr_str_u.expr_op->left) & DTYPE_MASK;
      r = expr_datatype (p->expr_str_u.expr_op->right) & DTYPE_MASK;


      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
        {
          ensure_decimal (p->expr_str_u.expr_op->left, 0);
          ensure_decimal (p->expr_str_u.expr_op->right, 0);
          return DTYPE_DECIMAL;
        }

      if (l == DTYPE_DTIME && r == DTYPE_DTIME)
        {
          return DTYPE_INTERVAL;
        }

      if (l == DTYPE_DATE && r == DTYPE_DATE)
        {
          ensure_int (p->expr_str_u.expr_op->left, 0);
          ensure_int (p->expr_str_u.expr_op->right, 0);
          return DTYPE_INT;
        }

      if (l == DTYPE_DATE && r == DTYPE_INTERVAL)
        {
          struct expr_str *right;
          right = p->expr_str_u.expr_op->right;
          if (right->expr_type == ET_EXPR_OP_DAY)
            {                   // Fools I tell you !!!
              p->expr_str_u.expr_op->right = right->expr_str_u.expr_expr;
              ensure_int (p->expr_str_u.expr_op->left, 0);
              ensure_int (p->expr_str_u.expr_op->right, 0);
              ensure_date (p, 0);
            }
          else
            {

              if (right->expr_type == ET_EXPR_OP_MONTH || right->expr_type == ET_EXPR_OP_YEAR)
                {
                  return DTYPE_DATE;
                }
              fprintf (stderr, "Not fixed : %s (DATE-INTERVAL)\n", expr_name (right->expr_type));
              fprintf (stderr, "dtype right = %d\n", expr_datatype (p->expr_str_u.expr_op->right));

              return DTYPE_DTIME;
            }
          return DTYPE_DATE;
        }
      if (l == DTYPE_INT && r == DTYPE_FLOAT)
        {
          ensure_dtype (p->expr_str_u.expr_op->left, DTYPE_FLOAT, 0);
          l = DTYPE_FLOAT;
        }
      if (r == DTYPE_INT && l == DTYPE_FLOAT)
        {
          ensure_dtype (p->expr_str_u.expr_op->right, DTYPE_FLOAT, 0);
          r = DTYPE_FLOAT;
        }
      if (l == DTYPE_SMINT && r == DTYPE_FLOAT)
        {
          ensure_dtype (p->expr_str_u.expr_op->left, DTYPE_FLOAT, 0);
          l = DTYPE_FLOAT;
        }
      if (r == DTYPE_SMINT && l == DTYPE_FLOAT)
        {
          ensure_dtype (p->expr_str_u.expr_op->right, DTYPE_FLOAT, 0);
          r = DTYPE_FLOAT;
        }

      if (l == DTYPE_SMINT && r == DTYPE_INT)
        {
          ensure_dtype (p->expr_str_u.expr_op->left, DTYPE_INT, 0);
          l = DTYPE_INT;
        }

      if (r == DTYPE_SMINT && l == DTYPE_INT)
        {
          ensure_dtype (p->expr_str_u.expr_op->right, DTYPE_INT, 0);
          r = DTYPE_INT;
        }






      if (l == r)
        {
          return l;
        }

      if (r == DTYPE_DATE
          && (l == DTYPE_INT || l == DTYPE_SMINT || r == FAKE_DTYPE_BOOL))
        {
          struct expr_str *tmp;
          tmp = p->expr_str_u.expr_op->right;
          p->expr_str_u.expr_op->right = p->expr_str_u.expr_op->left;
          ensure_int (p->expr_str_u.expr_op->right, 0);
          p->expr_str_u.expr_op->left = tmp;        // Lets make sure the date is on the left...
          ensure_int (p->expr_str_u.expr_op->left, 0);
          ensure_date (p, 0);
          return DTYPE_DATE;
        }


      if (l == DTYPE_DATE
          && (r == DTYPE_INT || r == DTYPE_SMINT || r == FAKE_DTYPE_BOOL))
        {
          ensure_int (p->expr_str_u.expr_op->left, 0);
          ensure_int (p->expr_str_u.expr_op->right, 0);
          ensure_date (p, 0);
          return DTYPE_DATE;
        }

      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
        {
          ensure_decimal (p->expr_str_u.expr_op->left, 0);
          ensure_decimal (p->expr_str_u.expr_op->right, 0);
          return DTYPE_DECIMAL;
        }

      if (l == DTYPE_SMINT && r == DTYPE_SMFLOAT)
        {
          ensure_smfloat (p->expr_str_u.expr_op->left, 0);
          //ensure_smfloat (p->expr_str_u.expr_op->right, 0);
          return DTYPE_SMFLOAT;
	}

      if (l == DTYPE_SMINT && r == DTYPE_SMFLOAT)
        {
          //ensure_smfloat (p->expr_str_u.expr_op->left, 0);
          ensure_smfloat (p->expr_str_u.expr_op->right, 0);
          return DTYPE_SMFLOAT;
	}

      if (l == DTYPE_DTIME && r == DTYPE_INTERVAL)
        {
          //ensure_smfloat (p->expr_str_u.expr_op->left, 0);
          return DTYPE_DTIME;
	}


      if (l == DTYPE_DTIME && r == DTYPE_DATE)
        {
          return DTYPE_INTERVAL;
	}

      if (l == DTYPE_DATE && r == DTYPE_DTIME)
        {
          return DTYPE_INTERVAL;
	}

	sprintf(buff, "%s!=%s",dtype_as_string(l), dtype_as_string(r));
	A4GL_lint (0, 0, "DIFFMATH", "Different types in operation (-)", buff);

      fprintf (stderr, "UNHANDLED SUB %d(%s) %d(%s) (%x %x)\n",
               p->expr_str_u.expr_op->left->expr_type,
               expr_name (p->expr_str_u.expr_op->left->expr_type),
               p->expr_str_u.expr_op->right->expr_type,
               expr_name (p->expr_str_u.expr_op->right->expr_type), l, r);
      return DTYPE_INT;

    default:
	
      fprintf (stderr, "UNKNOWN Expression Datatype %s (%d)\n",
               expr_name (p->expr_type),
               yylineno);
	A4GL_pause_execution();
      return -1;
    }


  // Shouldn't happen
}

