#include "expr_munging.h"
#include "parsehelp.h"

static int madmath (char *module, int lineno, expr_str * p);

#define FAKE_DTYPE_BOOL 90
extern int yylineno;
char *expr_as_string_when_possible(expr_str *e);

void ensure_dtype (char *module, int lineno, struct expr_str *e, int dtype, int nonull); // This should not be static - its called elsewhere...
static void ensure_smint (char *module, int lineno, struct expr_str *s, int notnull);
static void ensure_char (char *module, int lineno, struct expr_str *s, int notnull);
static void ensure_dtime (char *module, int lineno, struct expr_str *s, int notnull);
static void ensure_date (char *module, int lineno, struct expr_str *s, int notnull);
static void ensure_int (char *module, int lineno, struct expr_str *s, int notnull);
static void ensure_decimal (char *module, int lineno, struct expr_str *s, int notnull);
static void ensure_money (char *module, int lineno, struct expr_str *s, int notnull);
static void ensure_float (char *module, int lineno, struct expr_str *s, int notnull);
static void ensure_smfloat (char *module, int lineno, struct expr_str *s, int notnull);
static void ensure_interval (char *module, int lineno, struct expr_str *s, int notnull);
static void ensure_byte (char *module, int lineno, struct expr_str *s, int notnull);
static void fix_compare (char *module, int lineno, char *op, struct expr_str *s);
static void force_float (char *module, int lineno, struct expr_str *s);

void
ensure_dtype (char *module, int lineno, struct expr_str *e, int dtype, int notnull)
{

  dtype = dtype & DTYPE_MASK;
  switch (dtype & DTYPE_MASK)
    {
    case DTYPE_VCHAR:
      ensure_char (module,lineno,e, notnull);
      return;
    case DTYPE_CHAR:
      ensure_char (module,lineno,e, notnull);
      return;
    case DTYPE_SMINT:
      ensure_smint (module,lineno,e, notnull);
      return;
    case DTYPE_INT:
      ensure_int (module,lineno,e, notnull);
      return;
    case DTYPE_SERIAL:
      ensure_int (module,lineno,e, notnull);
      return;
    case DTYPE_DTIME:
      ensure_dtime (module,lineno,e, notnull);
      return;
    case DTYPE_DATE:
      ensure_date (module,lineno,e, notnull);
      return;
    case DTYPE_FLOAT:
      ensure_float (module,lineno,e, notnull);
      return;
    case DTYPE_SMFLOAT:
      ensure_smfloat (module,lineno,e, notnull);
      return;
    case DTYPE_DECIMAL:
      ensure_decimal (module,lineno,e, notnull);
      return;
    case DTYPE_MONEY:
      ensure_money (module,lineno,e, notnull);
      return;
    case DTYPE_INTERVAL:
      ensure_interval (module,lineno,e, notnull);
      return;
    case DTYPE_BYTE:
      ensure_byte (module,lineno,e, notnull);
      return;
    case DTYPE_TEXT:
      ensure_byte (module,lineno,e, notnull);
      return;
    case FAKE_DTYPE_BOOL:
      ensure_bool (module, lineno, e, notnull);
      return;
    }

  PRINTF ("Unhandled ensure ; %d (%x)\n", dtype, dtype);
}



void
ensure_char (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (module, lineno, s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_CHAR || (d & DTYPE_MASK) == DTYPE_VCHAR)
	return;
    }
  make_cast (module, lineno, s, DTYPE_CHAR, notnull, 0);
}


void
ensure_dtime (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (module, lineno, s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_DTIME)
	return;
    }
  make_cast (module, lineno, s, DTYPE_DTIME, notnull, 0);
}

void
ensure_byte (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (module, lineno, s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_BYTE || (d & DTYPE_MASK) == DTYPE_TEXT)
	return;
    }
  if ((d & DTYPE_MASK) == DTYPE_TEXT)
    return;
  if ((d & DTYPE_MASK) == DTYPE_BYTE)
    return;
  make_cast (module, lineno, s, DTYPE_BYTE, notnull, 0);
}

void
ensure_interval (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (module, lineno, s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_INTERVAL)
	return;
    }
  make_cast (module, lineno, s, DTYPE_INTERVAL, notnull, 0);
}


void
force_float (char *module, int lineno, struct expr_str *s)
{
  make_cast (module, lineno, s, DTYPE_FLOAT, 0, 1);
}

void
ensure_float (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (module, lineno, s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_FLOAT)
	return;
    }
  make_cast (module, lineno, s, DTYPE_FLOAT, notnull, 0);
}

void
ensure_smfloat (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (module, lineno, s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_SMFLOAT)
	return;
    }
  make_cast (module, lineno, s, DTYPE_SMFLOAT, notnull, 0);
}

void
ensure_date (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (module, lineno, s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_DATE)
	return;
    }
  make_cast (module, lineno, s, DTYPE_DATE, notnull, 0);
}

void
ensure_int (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  if (!notnull)
    {
      d = expr_datatype (module, lineno, s);
      if (((d & DTYPE_MASK) == DTYPE_INT) && notnull == 0)
	return;
      if (s->expr_type == ET_EXPR_LITERAL_LONG)
	{
	  return;
	}
    }
  make_cast (module, lineno, s, DTYPE_INT, notnull, 0);
}

void
ensure_smint (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (module, lineno, s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_SMINT)
	return;
    }
  make_cast (module, lineno, s, DTYPE_INT, notnull, 0);
}

void
ensure_decimal (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (module, lineno, s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_DECIMAL)
	return;
    }
  make_cast (module, lineno, s, DTYPE_DECIMAL, notnull, 0);
}

void
ensure_money (char *module, int lineno, struct expr_str *s, int notnull)
{
  int d;
  d = expr_datatype (module, lineno, s);
  if (!notnull)
    {
      if ((d & DTYPE_MASK) == DTYPE_MONEY)
	return;
    }
  make_cast (module, lineno, s, DTYPE_MONEY, notnull, 0);
}

void
ensure_bool (char *module, int lineno, struct expr_str *s, int notnull)
{
  //struct expr_str *p;
  //int d;
  int l;
  int r;

  if (s->expr_type == ET_EXPR_OP_NOT_EQUAL)
    {
      fix_compare (module, lineno, "<>", s);
    }
  if (s->expr_type == ET_EXPR_OP_EQUAL)
    {
      fix_compare (module, lineno, "=", s);
    }


  switch (s->expr_type)
    {
    case ET_EXPR_TRUE:
      return;

    case ET_EXPR_FALSE:
      return;
    case ET_EXPR_OP_OR:
      ensure_bool (module, lineno, s->expr_str_u.expr_op->left, notnull);
      ensure_bool (module, lineno, s->expr_str_u.expr_op->right, notnull);
      return;

    case ET_EXPR_OP_AND:
      ensure_bool (module, lineno, s->expr_str_u.expr_op->left, notnull);
      ensure_bool (module, lineno, s->expr_str_u.expr_op->right, notnull);
      return;

    case ET_EXPR_OP_ISNULL:
    case ET_EXPR_OP_ISNOTNULL:
      return;

    case ET_EXPR_OP_MATCHES:
    case ET_EXPR_OP_NOT_MATCHES:
      ensure_char (module,lineno,s->expr_str_u.expr_op->left, 1);
      ensure_char (module,lineno,s->expr_str_u.expr_op->right, 1);
      return;
    case ET_EXPR_NOT:
      ensure_bool (module, lineno, s->expr_str_u.expr_expr, notnull);
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

      l = expr_datatype (module, lineno, s->expr_str_u.expr_op->left) & DTYPE_MASK;
      r = expr_datatype (module, lineno, s->expr_str_u.expr_op->right) & DTYPE_MASK;



      if (l != r)		// 1
	{
	  int fixed = 0;
	  // Comparing differing types...
	  if (l == DTYPE_INT && r == DTYPE_SMINT)
	    {
	      ensure_int (module,lineno,s->expr_str_u.expr_op->right, 0);
	      fixed++;
	    }

	  if (l == DTYPE_DECIMAL && r == DTYPE_INT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
	      fixed++;
	    }

	  if (l == DTYPE_CHAR && r == DTYPE_VCHAR)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_CHAR, 0);
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_CHAR, 0);
	      fixed++;
	    }

	  if (r == DTYPE_CHAR && l == DTYPE_VCHAR)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_CHAR, 0);
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_CHAR, 0);
	      fixed++;
	    }

	  if (l == DTYPE_DECIMAL && r == DTYPE_SMINT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
	      fixed++;
	    }

	  if (l == DTYPE_DECIMAL && r == DTYPE_FLOAT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
	      fixed++;
	    }

	  if (l == DTYPE_DECIMAL && r == DTYPE_SMFLOAT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
	      fixed++;
	    }

	  if (l == DTYPE_DECIMAL && r == DTYPE_MONEY)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_MONEY, 0);
	      fixed++;
	    }


	  if (l == DTYPE_MONEY && r == DTYPE_DECIMAL)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_MONEY, 0);
	      fixed++;
	    }

	  if (l == DTYPE_MONEY && r == DTYPE_INT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_MONEY, 0);
	      fixed++;
	    }

	  if (l == DTYPE_MONEY && r == DTYPE_SMINT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_MONEY, 0);
	      fixed++;
	    }

	  if (l == DTYPE_MONEY && r == DTYPE_FLOAT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_MONEY, 0);
	      fixed++;
	    }

	  if (l == DTYPE_MONEY && r == DTYPE_SMFLOAT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_MONEY, 0);
	      fixed++;
	    }

	  if (r == DTYPE_MONEY && l == DTYPE_INT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_MONEY, 0);
	      fixed++;
	    }

	  if (r == DTYPE_MONEY && l == DTYPE_SMINT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_MONEY, 0);
	      fixed++;
	    }

	  if (r == DTYPE_MONEY && l == DTYPE_FLOAT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_MONEY, 0);
	      fixed++;
	    }




	  if (r == DTYPE_DECIMAL && l == DTYPE_INT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_DECIMAL, 0);
	      fixed++;
	    }

	  if (r == DTYPE_DECIMAL && l == DTYPE_SMINT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_DECIMAL, 0);
	      fixed++;
	    }

	  if (r == DTYPE_DECIMAL && l == DTYPE_FLOAT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_DECIMAL, 0);
	      fixed++;
	    }

	  if (r == DTYPE_DECIMAL && l == DTYPE_SMFLOAT)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_DECIMAL, 0);
	      fixed++;
	    }

	  if (l == DTYPE_SMINT && r == DTYPE_INT)
	    {
	      ensure_int (module,lineno,s->expr_str_u.expr_op->left, 0);
	      fixed++;
	    }

	  if (l == FAKE_DTYPE_BOOL && (r == DTYPE_INT || r == DTYPE_SMINT))
	    {
	      ensure_int (module,lineno,s->expr_str_u.expr_op->left, 0);
	      fixed++;
	    }


	  if (r == FAKE_DTYPE_BOOL && (l == DTYPE_INT || l == DTYPE_SMINT))
	    {
	      ensure_int (module,lineno,s->expr_str_u.expr_op->right, 0);
	      fixed++;
	    }


	  if (l == DTYPE_CHAR && r == DTYPE_VCHAR)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_CHAR, 0);
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_CHAR, 0);
	      fixed++;
	    }

	  if (r == DTYPE_CHAR && l == DTYPE_VCHAR)
	    {
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_CHAR, 0);
	      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_CHAR, 0);
	      fixed++;
	    }
	  if (!fixed)
	    {
	      char buff[256];
	      sprintf (buff, "'%s'!='%s' @ %d", dtype_as_string (l), dtype_as_string (r), yylineno);
	      A4GL_lint (module, lineno, "DIFFCOMP", "Different types in comparison", buff);
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

  make_cast (module,lineno,s, FAKE_DTYPE_BOOL, notnull, 0);
}


void
make_cast (char *module, int lineno, struct expr_str *s, int target_dtype, int notnull, int force)
{
  int d;
  struct expr_str *p;
  d = expr_datatype (module, lineno, s);

  if (d == target_dtype && notnull == 0)
    return;			// Happy Days!
  if (d == target_dtype && d == DTYPE_CHAR)
    {
      // Happy days too..
      return;
    }

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
//printf("Cast : %d %d\n",  s->expr_str_u.expr_cast->src_dtype, s->expr_str_u.expr_cast->target_dtype );
}



void
fix_compare (char *module, int lineno, char *op, struct expr_str *s)
{
  int l;
  int r;
  int fixed = 0;
      struct expr_str *le;
      struct expr_str *re;

  l = expr_datatype (module, lineno, s->expr_str_u.expr_op->left) & DTYPE_MASK;
  r = expr_datatype (module, lineno, s->expr_str_u.expr_op->right) & DTYPE_MASK;
      le = s->expr_str_u.expr_op->left;
      re = s->expr_str_u.expr_op->right;


	if (le->expr_type==ET_EXPR_VARIABLE_USAGE && re->expr_type==ET_EXPR_VARIABLE_USAGE) {
		char *s1;
		char *s2;
		s1=strdup(expr_as_string_when_possible(le));
		s2=strdup(expr_as_string_when_possible(re));
		if (strcmp(s1,s2)==0) {
		  	A4GL_lint (module, lineno, "SAMEVARCOMP", "Comparing for equality of same variable", 0);
		}
		free(s1);
		free(s2);
	}

  if (strcmp (op, "=") == 0)
    {
      //struct expr_str *le;
      //struct expr_str *re;
      char *len = 0;
      char *ren = 0;



      if (le->expr_type == ET_EXPR_FCALL)
	{
	  len = le->expr_str_u.expr_function_call->fname;
	}
      if (re->expr_type == ET_EXPR_FCALL)
	{
	  ren = re->expr_str_u.expr_function_call->fname;
	}
      if (len)
	{
	  if (re->expr_type == ET_EXPR_LITERAL_LONG)
	    {
	      if (strcmp (len, "fgl_lastkey") == 0)
		{
		  A4GL_lint (le->expr_str_u.expr_function_call->module, le->expr_str_u.expr_function_call->line, "LASTKEYLIT", "Comparing fgl_lastkey against a literal integer", 0);
		}
	    }
	}
      if (ren)
	{
	  if (le->expr_type == ET_EXPR_LITERAL_LONG)
	    {
	      if (strcmp (ren, "fgl_lastkey") == 0)
		{
		  A4GL_lint (re->expr_str_u.expr_function_call->module, re->expr_str_u.expr_function_call->line, "LASTKEYLIT",
			     "Comparing fgl_lastkey against a literal integer", 0);
		}
	    }
	}

    }



  // Comparing differing types...
  if (l == DTYPE_INT && r == DTYPE_SMINT)
    {
      ensure_int (module,lineno,s->expr_str_u.expr_op->right, 0);
      fixed++;
    }

  if (l == DTYPE_DECIMAL && r == DTYPE_INT)
    {
      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (l == DTYPE_DECIMAL && r == DTYPE_SMINT)
    {
      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (l == DTYPE_DECIMAL && r == DTYPE_FLOAT)
    {
      ensure_dtype (module, lineno, s->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (r == DTYPE_DECIMAL && l == DTYPE_FLOAT)
    {
      ensure_dtype (module, lineno, s->expr_str_u.expr_op->left, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (l == DTYPE_SMINT && r == DTYPE_INT)
    {
      ensure_int (module,lineno,s->expr_str_u.expr_op->left, 0);
      fixed++;
    }

  if (l == FAKE_DTYPE_BOOL && (r == DTYPE_INT || r == DTYPE_SMINT))
    {
      ensure_int (module,lineno,s->expr_str_u.expr_op->left, 0);
      fixed++;
    }

  if (r == FAKE_DTYPE_BOOL && (l == DTYPE_INT || l == DTYPE_SMINT))
    {
      ensure_int (module,lineno,s->expr_str_u.expr_op->right, 0);
      fixed++;
    }

  if ((l == DTYPE_INT || l == DTYPE_SMINT) && r == DTYPE_CHAR)
    {
      if (s->expr_str_u.expr_op->right->expr_type == ET_EXPR_LITERAL_STRING)
	{
	  char *a;
	  a = strdup (s->expr_str_u.expr_op->right->expr_str_u.expr_string);
	  A4GL_trim (a);

	  if (strlen (a) == 0 && (strcmp (op, "<>") == 0 || strcmp (op, "=") == 0))
	    {
	      // Its a blank string...
	      // they mean is null or is not null
	      struct expr_str *l;
	      l = s->expr_str_u.expr_op->left;
	      if (strcmp (op, "<>") == 0)
		{
		  s->expr_type = ET_EXPR_OP_ISNOTNULL;
		  s->expr_str_u.expr_expr = l;
		  free (a);
		  return;
		}
	      if (strcmp (op, "=") == 0)
		{
		  s->expr_type = ET_EXPR_OP_ISNULL;
		  s->expr_str_u.expr_expr = l;
		  free (a);
		  return;
		}
	    }
	  free (a);

	}
    }




  l = expr_datatype (module, lineno, s->expr_str_u.expr_op->left) & DTYPE_MASK;
  r = expr_datatype (module, lineno, s->expr_str_u.expr_op->right) & DTYPE_MASK;
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



/* 
 * This is an abbreviated expr_datatype - it doesn't change the values and return -1 if it cant determine the
 * datatype for any reason - or the datatype is too complex...
 * This function is used to determine some internal optimizations - so it
 * deliberatly ignores things like function calls
 *
 * Use expr_datatype in preference for most things!!
 *
 */
int
simple_expr_datatype (struct expr_str *p)
{
  //int l;
  //int r;
  //char buff[256];
  switch (p->expr_type)
    {
    case ET_EXPR_LITERAL_DOUBLE_STR:
      return DTYPE_FLOAT;

    case ET_EXPR_LITERAL_EMPTY_STRING:
      return DTYPE_CHAR;

    case ET_EXPR_LITERAL_STRING:
      return DTYPE_CHAR;
      break;

    case ET_EXPR_LITERAL_LONG:
      if (p->expr_str_u.expr_long <= SHRT_MAX && p->expr_str_u.expr_long >= SHRT_MIN)
	{
	  return DTYPE_SMINT;
	}
      return DTYPE_INT;
    case ET_EXPR_BRACKET:
      return simple_expr_datatype (p->expr_str_u.expr_expr);
    case ET_EXPR_VARIABLE_USAGE:
      {
	struct variable_usage *u;
	u = p->expr_str_u.expr_variable_usage;
	while (u->next)
	  u = u->next;

	// If its a substring - can we find out the extent so we can 'adjust' our 
	// size we report back as the datatype...
	if (u->substrings_start)
	  {
	    // substring..
	    if (u->substrings_end == NULL || u->substrings_end == u->substrings_start)
	      {
		// end is the same as start - so its a single character..
		if (u->datatype == DTYPE_CHAR || u->datatype == DTYPE_VCHAR)
		  {
		    return (u->datatype & DTYPE_MASK) + ENCODE_SIZE (1);
		  }
	      }
	    else
	      {
		// Ok - theres a fair chance we can't work out what it is
		// but - we can if its just a couple of literals...
		if (u->substrings_start->expr_type == ET_EXPR_LITERAL_LONG && u->substrings_end->expr_type == ET_EXPR_LITERAL_LONG)
		  {
		    int s;
		    int e;
		    s = u->substrings_start->expr_str_u.expr_long;
		    e = u->substrings_end->expr_str_u.expr_long;
		    if (e < s)
		      e = s;
		    return (u->datatype & DTYPE_MASK) + ENCODE_SIZE ((e - s + 1));
		  }
	      }

	    // Just return 1 - its could be right, and we'd be wrong
	    // to say otherwise...
	    return (u->datatype & DTYPE_MASK) + ENCODE_SIZE (1);

	  }
	return u->datatype;
      }

      A4GL_assertion (1, "Fixme");
      break;

    default:
      return -1;

    }


  // Shouldn't happen
}
















/* 
 * The real expr_datatype!!! 
*/

int
expr_datatype (char *module, int lineno, struct expr_str *p)
{
  int l;
  int r;
  //int a;
  char buff[256];
  switch (p->expr_type)
    {

    case ET_EXPR_NULL:
      return DTYPE_NULL;

    case ET_EXPR_CACHED:
      return expr_datatype (module, lineno, get_cached_expr_datatype (p->expr_str_u.expr_cached.cache_num));

    case ET_EXPR_OP_SPACES:
      ensure_int (module,lineno,p->expr_str_u.expr_expr, 0);
      return DTYPE_CHAR;

    case ET_EXPR_COLUMN:
      ensure_int (module,lineno,p->expr_str_u.expr_expr, 0);
      return DTYPE_CHAR;

    case ET_EXPR_INFIELD:
      return FAKE_DTYPE_BOOL;


    case ET_EXPR_PAGENO:
      return DTYPE_INT;
    case ET_EXPR_LINENO:
      return DTYPE_INT;

    case ET_EXPR_ASCII:
      ensure_int (module,lineno,p->expr_str_u.expr_expr, 0);
      return DTYPE_CHAR;

    case ET_EXPR_DOWNSHIFT:
    case ET_EXPR_UPSHIFT:
      ensure_char (module,lineno,p->expr_str_u.expr_expr, 0);
      return DTYPE_CHAR;

    case ET_EXPR_EXTEND:
      ensure_dtime (module,lineno,p->expr_str_u.expr_extend->expr, 0);
      return DTYPE_DTIME;

    case ET_EXPR_FIELD_TOUCHED:
      return FAKE_DTYPE_BOOL;

    case ET_EXPR_DATE_FUNC:
      //ensure_char (ptr->expr_str_u.expr_expr,0);
      return DTYPE_DATE;

    case ET_EXPR_NEG:
      if (is_numeric (expr_datatype (module, lineno, p->expr_str_u.expr_expr)))
	{
	  return expr_datatype (module, lineno, p->expr_str_u.expr_expr);
	}
      if (p->expr_str_u.expr_expr == DTYPE_CHAR)
	return DTYPE_FLOAT;
    case ET_EXPR_CONCAT_LIST:
      return DTYPE_CHAR;
    case ET_EXPR_GET_FLDBUF:
      return DTYPE_CHAR;

    case ET_EXPR_OP_CONCAT:
      ensure_char (module,lineno, p->expr_str_u.expr_op->left, 0);
      ensure_char (module,lineno, p->expr_str_u.expr_op->right, 0);
      return DTYPE_CHAR;
    case ET_EXPR_TIME_EXPR:
      return DTYPE_DTIME;
    case ET_EXPR_TEMP:
      return p->expr_str_u.expr_tmp->dtype;

    case ET_EXPR_NOT:
      ensure_bool (module, lineno, p->expr_str_u.expr_expr, 0);
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
       *  case ET_EXPR_SUBSTRING:
       return DTYPE_CHAR;
       break;
       */

    case ET_EXPR_CURRENT:
      return DTYPE_DTIME;
    case ET_EXPR_OP_OR:
    case ET_EXPR_OP_AND:
      ensure_bool (module, lineno, p->expr_str_u.expr_op->left, 0);
      ensure_bool (module, lineno, p->expr_str_u.expr_op->right, 0);
      return DTYPE_INT;		// Actually boolean
    case ET_EXPR_CAST:
      return p->expr_str_u.expr_cast->target_dtype;
    case ET_EXPR_DAY_FUNC:
    case ET_EXPR_MONTH_FUNC:
    case ET_EXPR_YEAR_FUNC:
      return DTYPE_INT;

    case ET_EXPR_OP_ISNULL:
    case ET_EXPR_OP_ISNOTNULL:
      return FAKE_DTYPE_BOOL;	// Actually a Boolean...

    case ET_EXPR_OP_LIKE:
    case ET_EXPR_OP_NOT_LIKE:
    case ET_EXPR_OP_MATCHES:
    case ET_EXPR_OP_NOT_MATCHES:
      ensure_char (module,lineno,p->expr_str_u.expr_op->left, 0);
      ensure_char (module,lineno,p->expr_str_u.expr_op->right, 0);
      return FAKE_DTYPE_BOOL;	// Actually a Boolean...

    case ET_EXPR_OP_NOT_EQUAL:
      fix_compare (module, lineno, "<>", p);
      return FAKE_DTYPE_BOOL;	// Actually a Boolean...


    case ET_EXPR_OP_GREATER_THAN:
      fix_compare (module, lineno, ">", p);
      return FAKE_DTYPE_BOOL;	// Actually a Boolean...

    case ET_EXPR_OP_GREATER_THAN_EQ:
      fix_compare (module, lineno, ">=", p);
      return FAKE_DTYPE_BOOL;	// Actually a Boolean...

    case ET_EXPR_OP_LESS_THAN:
      fix_compare (module, lineno, "<", p);
      return FAKE_DTYPE_BOOL;	// Actually a Boolean...

    case ET_EXPR_OP_LESS_THAN_EQ:
      fix_compare (module, lineno, "<=", p);
      return FAKE_DTYPE_BOOL;	// Actually a Boolean...

    case ET_EXPR_OP_EQUAL:
      fix_compare (module, lineno, "=", p);
      return FAKE_DTYPE_BOOL;	// Actually a Boolean...

    case ET_EXPR_OP_NOT_IN:
    case ET_EXPR_OP_NOTIN_SUBQUERY:
    case ET_EXPR_OP_IN_SUBQUERY:
    case ET_EXPR_OP_IN:
      return FAKE_DTYPE_BOOL;	// Actually a Boolean...


    case ET_EXPR_OP_USING:
      ensure_char (module,lineno,p->expr_str_u.expr_op->right, 0);
      return DTYPE_CHAR;

    case ET_EXPR_OP_CLIP:
      ensure_char (module,lineno,p->expr_str_u.expr_expr, 0);
      return DTYPE_CHAR;

    case ET_EXPR_STRING:
      return DTYPE_CHAR;
      break;

    case ET_EXPR_VARIABLE_USAGE:
      {
	struct variable_usage *u;
	u = p->expr_str_u.expr_variable_usage;
	while (u->next)
	  u = u->next;

	// If its a substring - can we find out the extent so we can 'adjust' our 
	// size we report back as the datatype...
	if (u->substrings_start)
	  {
	    // substring..
	    if (u->substrings_end == NULL || u->substrings_end == u->substrings_start)
	      {
		// end is the same as start - so its a single character..
		if (u->datatype == DTYPE_CHAR || u->datatype == DTYPE_VCHAR)
		  {
		    return (u->datatype & DTYPE_MASK) + ENCODE_SIZE (1);
		  }
	      }
	    else
	      {
		// Ok - theres a fair chance we can't work out what it is
		// but - we can if its just a couple of literals...
		if (u->substrings_start->expr_type == ET_EXPR_LITERAL_LONG && u->substrings_end->expr_type == ET_EXPR_LITERAL_LONG)
		  {
		    int s;
		    int e;
		    s = u->substrings_start->expr_str_u.expr_long;
		    e = u->substrings_end->expr_str_u.expr_long;
		    if (e < s)
		      e = s;
		    return (u->datatype & DTYPE_MASK) + ENCODE_SIZE ((e - s + 1));
		  }
	      }

	    // Just return 1 - its could be right, and we'd be wrong
	    // to say otherwise...
	    return (u->datatype & DTYPE_MASK) + ENCODE_SIZE (1);

	  }
	return u->datatype;
      }

      A4GL_assertion (1, "Fixme");
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



    case ET_EXPR_IVAL_VAL:
      return DTYPE_INTERVAL + ENCODE_SIZE (p->expr_str_u.expr_interval->extend);

    case ET_EXPR_DTVAL:
      return DTYPE_DTIME + ENCODE_SIZE (p->expr_str_u.expr_datetime->extend);

    case ET_EXPR_TIME_FUNC:
      return DTYPE_DTIME + ENCODE_SIZE (72);

    case ET_EXPR_TIME:
      return DTYPE_DTIME + ENCODE_SIZE (72);

    case ET_EXPR_DATE_EXPR:
      return DTYPE_DATE;



    case ET_EXPR_LITERAL_LONG:
      if (p->expr_str_u.expr_long <= SHRT_MAX && p->expr_str_u.expr_long >= SHRT_MIN)
	{
	  return DTYPE_SMINT;
	}
      return DTYPE_INT;

    case ET_EXPR_FCALL:
      yylineno = p->expr_str_u.expr_function_call->line;

      return find_function_single_rtype (p->expr_str_u.expr_function_call->fname);

    case ET_EXPR_OP_MOD:
      return DTYPE_INT;






/* -------------------------------------------------------------------------------- */




    case ET_EXPR_OP_ADD:
      l = expr_datatype (module, lineno, p->expr_str_u.expr_op->left) & DTYPE_MASK;
      r = expr_datatype (module, lineno, p->expr_str_u.expr_op->right) & DTYPE_MASK;

      if (l == DTYPE_DATE && r == DTYPE_DATE)
	{
	  strcpy (buff, "+ on two DATEs");
	  A4GL_lint (module, lineno, "MADMATH", "Datatypes make no sense in this operation (+)", buff);
	  return DTYPE_DATE;
	}

      if (l == DTYPE_SERIAL)
	l = DTYPE_INT;
      if (r == DTYPE_SERIAL)
	r = DTYPE_INT;


      if (l == DTYPE_CHAR || r == DTYPE_CHAR || l == DTYPE_VCHAR || r == DTYPE_VCHAR)
	{
	  strcpy (buff, "+ involving a CHARs");
	  A4GL_lint (module, lineno, "MADMATH", "Datatypes make no sense in this operation", buff);
	  return DTYPE_FLOAT;
	}

      if (l == DTYPE_DATE && r == DTYPE_INTERVAL)
	{
	  struct expr_str *right;
	  right = p->expr_str_u.expr_op->right;

	  if (right->expr_type == ET_EXPR_OP_DAY)
	    {			// Fools I tell you !!!
	      p->expr_str_u.expr_op->right = right->expr_str_u.expr_expr;
	      ensure_int (module,lineno,p->expr_str_u.expr_op->right, 1);
	      ensure_int (module,lineno,p->expr_str_u.expr_op->left, 1);
	      ensure_date (module,lineno,p, 0);
	    }
	  else
	    {

	      if (right->expr_type == ET_EXPR_OP_MONTH || right->expr_type == ET_EXPR_OP_YEAR)
		{
		  return DTYPE_DATE;
		}
	      PRINTF ("Not fixed date+interval %s\n", expr_name (right->expr_type));
	      PRINTF ("dtype right = %d\n", expr_datatype (module, lineno, p->expr_str_u.expr_op->right));


	      return DTYPE_DTIME;
	    }
	  return DTYPE_DATE;
	}
      if (r == DTYPE_INT && p->expr_str_u.expr_op->right->expr_type == ET_EXPR_LITERAL_LONG)
	{
	  r = l;
	}

      if (l == DTYPE_INT && p->expr_str_u.expr_op->left->expr_type == ET_EXPR_LITERAL_LONG)
	{
	  l = r;
	}

      if (l == r)
	{
	  return l;
	}

      if (l == DTYPE_SMINT && r == DTYPE_INT)
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_INT;
	}


      if (l == DTYPE_SMINT && r == FAKE_DTYPE_BOOL)
	{
	  ensure_smint (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_smint (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_SMINT;
	}

      if (l == DTYPE_INT && r == FAKE_DTYPE_BOOL)
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_INT;
	}

      if (r == DTYPE_SMINT && l == FAKE_DTYPE_BOOL)
	{
	  ensure_smint (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_smint (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_SMINT;
	}

      if (r == DTYPE_INT && l == FAKE_DTYPE_BOOL)
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_INT;
	}



      if (l == DTYPE_SMINT && r == FAKE_DTYPE_BOOL)
	{
	  ensure_smint (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_smint (module,lineno,p->expr_str_u.expr_op->right, 0);
	  A4GL_lint (module, lineno, "BOOLMATH", "BOOLEAN used in maths operation", 0);
	  return DTYPE_SMINT;
	}

      if (l == FAKE_DTYPE_BOOL && r == DTYPE_SMINT)
	{
	  ensure_smint (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_smint (module,lineno,p->expr_str_u.expr_op->right, 0);
	  A4GL_lint (module, lineno, "BOOLMATH", "BOOLEAN used in maths operation", 0);
	  return DTYPE_SMINT;
	}


      if (l == DTYPE_INT && r == FAKE_DTYPE_BOOL)
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  A4GL_lint (module, lineno, "BOOLMATH", "BOOLEAN used in maths operation", 0);
	  return DTYPE_INT;
	}

      if (l == FAKE_DTYPE_BOOL && r == DTYPE_INT)
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  A4GL_lint (module, lineno, "BOOLMATH", "BOOLEAN used in maths operation", 0);
	  return DTYPE_INT;
	}


      if (r == DTYPE_SMINT && l == DTYPE_INT)
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_INT;
	}

      if (r == DTYPE_DATE && l == DTYPE_INT)
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  ensure_date (module,lineno,p, 0);
	  return DTYPE_DATE;
	}
      if (l == DTYPE_DTIME && r == DTYPE_INTERVAL)
	{
	  return DTYPE_DTIME;
	}
      if (r == DTYPE_DATE && l == DTYPE_SMINT)
	{

	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  ensure_date (module,lineno,p, 0);
	  return DTYPE_DATE;
	}

      if (l == DTYPE_DATE && r == DTYPE_INT)
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 1);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 1);
	  ensure_date (module,lineno,p, 0);
	  return DTYPE_DATE;
	}

      if (l == DTYPE_DATE && r == DTYPE_SMINT)
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 1);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 1);
	  ensure_date (module,lineno,p, 0);
	  return DTYPE_DATE;
	}

      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
	{
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_DECIMAL;
	}

      if (l == DTYPE_MONEY || r == DTYPE_MONEY)
	{
	  ensure_money (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_money (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_MONEY;
	}

      if (l == DTYPE_FLOAT || r == DTYPE_FLOAT)
	{
	  ensure_float (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_float (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_FLOAT;
	}

      if (l == DTYPE_SMFLOAT && r == DTYPE_FLOAT)
	{
	  ensure_float (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_float (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_FLOAT;
	}

      if (l == DTYPE_FLOAT && r == DTYPE_SMFLOAT)
	{
	  ensure_float (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_float (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_FLOAT;
	}

      sprintf (buff, "%s!=%s", dtype_as_string (l), dtype_as_string (r));
      A4GL_lint (module, lineno, "DIFFMATH", "Different types in operation", buff);
      fprintf (stderr, "UNHANDLED ADD %d(%s) %d(%s) (%x %x)\n",
	       p->expr_str_u.expr_op->left->expr_type,
	       expr_name (p->expr_str_u.expr_op->left->expr_type),
	       p->expr_str_u.expr_op->right->expr_type, expr_name (p->expr_str_u.expr_op->right->expr_type), l, r);
      return DTYPE_INT;

/* -------------------------------------------------------------------------------- */
    case ET_EXPR_OP_DIV:
      l = expr_datatype (module, lineno, p->expr_str_u.expr_op->left) & DTYPE_MASK;
      r = expr_datatype (module, lineno, p->expr_str_u.expr_op->right) & DTYPE_MASK;
      if (l == DTYPE_SERIAL)
	l = DTYPE_INT;
      if (r == DTYPE_SERIAL)
	r = DTYPE_INT;


      if (l == DTYPE_DATE || r == DTYPE_DATE)
	{
	  strcpy (buff, "/ involving a DATEs");
	  A4GL_lint (module, lineno, "MADMATH", "Datatypes make no sense in this operation (/)", buff);
	  return DTYPE_DATE;
	}
      if (l == DTYPE_CHAR || r == DTYPE_CHAR || l == DTYPE_VCHAR || r == DTYPE_VCHAR)
	{
	  strcpy (buff, "/ involving a CHARs");
	  A4GL_lint (module, lineno, "MADMATH", "Datatypes make no sense in this operation", buff);
	  return DTYPE_FLOAT;
	}

      if ((l == DTYPE_INT || l == DTYPE_SMINT) && (r == DTYPE_INT || r == DTYPE_SMINT))
	{
	  force_float (module,lineno,p->expr_str_u.expr_op->left);
	  force_float (module,lineno,p->expr_str_u.expr_op->right);
	  ensure_dtype (module, lineno, p, DTYPE_FLOAT, 0);
	  return DTYPE_FLOAT;
	}


      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
	{
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->left, DTYPE_DECIMAL, 0);
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->right, DTYPE_DECIMAL, 0);
	  return DTYPE_DECIMAL;
	}

      if (l == DTYPE_INT || l == DTYPE_SMINT || l == DTYPE_FLOAT || l == DTYPE_SMFLOAT)
	{
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->left, DTYPE_FLOAT, 0);
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->right, DTYPE_FLOAT, 0);
	  l = DTYPE_FLOAT;
	}

      if (r == DTYPE_INT || r == DTYPE_SMINT || r == DTYPE_FLOAT || r == DTYPE_SMFLOAT)
	{
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->left, DTYPE_FLOAT, 0);
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->right, DTYPE_FLOAT, 0);
	  r = DTYPE_FLOAT;
	}

      if (l == DTYPE_MONEY || r == DTYPE_MONEY)
	{
	  ensure_money (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_money (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_MONEY;
	}

      if (l == DTYPE_FLOAT && r == DTYPE_FLOAT)
	return DTYPE_FLOAT;

      sprintf (buff, "%s!=%s", dtype_as_string (l), dtype_as_string (r));
      A4GL_lint (module, lineno, "DIFFMATH", "Different types in operation (/)", buff);

      fprintf (stderr, "UNHANDLED DIV %d(%s) %d(%s) (%x %x)\n",
	       p->expr_str_u.expr_op->left->expr_type,
	       expr_name (p->expr_str_u.expr_op->left->expr_type),
	       p->expr_str_u.expr_op->right->expr_type, expr_name (p->expr_str_u.expr_op->right->expr_type), l, r);



/* -------------------------------------------------------------------------------- */
    case ET_EXPR_OP_MULT:

      l = expr_datatype (module, lineno, p->expr_str_u.expr_op->left) & DTYPE_MASK;
      r = expr_datatype (module, lineno, p->expr_str_u.expr_op->right) & DTYPE_MASK;
      if (l == DTYPE_SERIAL)
	l = DTYPE_INT;
      if (r == DTYPE_SERIAL)
	r = DTYPE_INT;

      if (l == DTYPE_DATE || r == DTYPE_DATE)
	{
	  strcpy (buff, "* on DATE");
	  A4GL_lint (module, lineno, "MADMATH", "Datatypes make no sense in this operation (/)", buff);
	  return DTYPE_DATE;
	}
      if (l == DTYPE_CHAR || r == DTYPE_CHAR || l == DTYPE_VCHAR || r == DTYPE_VCHAR)
	{
	  strcpy (buff, "* involving a CHARs");
	  A4GL_lint (module, lineno, "MADMATH", "Datatypes make no sense in this operation", buff);
	  return DTYPE_FLOAT;
	}
      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
	{
	  if (p->expr_str_u.expr_op->left->expr_type == ET_EXPR_LITERAL_LONG)
	    {
	      struct expr_str *tmp;
	      tmp = p->expr_str_u.expr_op->left;
	      p->expr_str_u.expr_op->left = p->expr_str_u.expr_op->right;
	      p->expr_str_u.expr_op->right = tmp;
	    }
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->right, 0);

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
	  ensure_float (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_float (module,lineno,p->expr_str_u.expr_op->right, 0);

	  return DTYPE_FLOAT;
	}

      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
	{
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_DECIMAL;
	}

      if (l == DTYPE_MONEY || r == DTYPE_MONEY)
	{
	  ensure_money (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_money (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_MONEY;
	}

      if (l == DTYPE_INT && r == DTYPE_FLOAT)
	{
	  ensure_float (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_float (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_FLOAT;
	}

      if (l == DTYPE_FLOAT && r == DTYPE_INT)
	{
	  ensure_float (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_float (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_FLOAT;
	}
      if (l == DTYPE_FLOAT && r == DTYPE_MONEY)
	{
	  ensure_float (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_MONEY;
	}
      if (l == DTYPE_INT && r == DTYPE_MONEY)
	{
	  return DTYPE_MONEY;
	}
      sprintf (buff, "%s!=%s", dtype_as_string (l), dtype_as_string (r));
      A4GL_lint (module, lineno, "DIFFMATH", "Different types in operation (*)", buff);
      fprintf (stderr, "UNHANDLED MULT %d(%s) %d(%s) (%x %x)\n",
	       p->expr_str_u.expr_op->left->expr_type,
	       expr_name (p->expr_str_u.expr_op->left->expr_type),
	       p->expr_str_u.expr_op->right->expr_type, expr_name (p->expr_str_u.expr_op->right->expr_type), l, r);



/* -------------------------------------------------------------------------------- */
    case ET_EXPR_OP_SUB:
      l = expr_datatype (module, lineno, p->expr_str_u.expr_op->left) & DTYPE_MASK;
      r = expr_datatype (module, lineno, p->expr_str_u.expr_op->right) & DTYPE_MASK;

      if (l == DTYPE_SERIAL)
	l = DTYPE_INT;
      if (r == DTYPE_SERIAL)
	r = DTYPE_INT;


      if (l == DTYPE_CHAR || r == DTYPE_CHAR || l == DTYPE_VCHAR || r == DTYPE_VCHAR)
	{
	  strcpy (buff, "- involving a CHARs");
	  A4GL_lint (module, lineno, "MADMATH", "Datatypes make no sense in this operation", buff);
	  return DTYPE_FLOAT;
	}

      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
	{
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_DECIMAL;
	}

      if (l == DTYPE_DTIME && r == DTYPE_DTIME)
	{
	  return DTYPE_INTERVAL;
	}

      if (l == DTYPE_DATE && r == DTYPE_DATE)
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_INT;
	}

      if (l == DTYPE_DATE && r == DTYPE_INTERVAL)
	{
	  struct expr_str *right;
	  right = p->expr_str_u.expr_op->right;
	  if (right->expr_type == ET_EXPR_OP_DAY)
	    {			// Fools I tell you !!!
	      p->expr_str_u.expr_op->right = right->expr_str_u.expr_expr;
	      ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	      ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	      ensure_date (module,lineno,p, 0);
	    }
	  else
	    {

	      if (right->expr_type == ET_EXPR_OP_MONTH || right->expr_type == ET_EXPR_OP_YEAR)
		{
		  return DTYPE_DATE;
		}
	      fprintf (stderr, "Not fixed : %s (DATE-INTERVAL)\n", expr_name (right->expr_type));
	      fprintf (stderr, "dtype right = %d\n", expr_datatype (module, lineno, p->expr_str_u.expr_op->right));

	      return DTYPE_DTIME;
	    }
	  return DTYPE_DATE;
	}
      if (l == DTYPE_INT && r == DTYPE_FLOAT)
	{
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->left, DTYPE_FLOAT, 0);
	  l = DTYPE_FLOAT;
	}
      if (r == DTYPE_INT && l == DTYPE_FLOAT)
	{
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->right, DTYPE_FLOAT, 0);
	  r = DTYPE_FLOAT;
	}
      if (l == DTYPE_SMINT && r == DTYPE_FLOAT)
	{
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->left, DTYPE_FLOAT, 0);
	  l = DTYPE_FLOAT;
	}
      if (r == DTYPE_SMINT && l == DTYPE_FLOAT)
	{
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->right, DTYPE_FLOAT, 0);
	  r = DTYPE_FLOAT;
	}

      if (l == DTYPE_SMINT && r == DTYPE_INT)
	{
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->left, DTYPE_INT, 0);
	  l = DTYPE_INT;
	}

      if (r == DTYPE_SMINT && l == DTYPE_INT)
	{
	  ensure_dtype (module, lineno, p->expr_str_u.expr_op->right, DTYPE_INT, 0);
	  r = DTYPE_INT;
	}






      if (l == r)
	{
	  return l;
	}

      if (r == DTYPE_DATE && (l == DTYPE_INT || l == DTYPE_SMINT || r == FAKE_DTYPE_BOOL))
	{
	  struct expr_str *tmp;
	  tmp = p->expr_str_u.expr_op->right;
	  p->expr_str_u.expr_op->right = p->expr_str_u.expr_op->left;
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  p->expr_str_u.expr_op->left = tmp;	// Lets make sure the date is on the left...
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_date (module,lineno,p, 0);
	  return DTYPE_DATE;
	}


      if (l == DTYPE_DATE && (r == DTYPE_INT || r == DTYPE_SMINT || r == FAKE_DTYPE_BOOL))
	{
	  ensure_int (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_int (module,lineno,p->expr_str_u.expr_op->right, 0);
	  ensure_date (module,lineno,p, 0);
	  return DTYPE_DATE;
	}

      if (l == DTYPE_DECIMAL || r == DTYPE_DECIMAL)
	{
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_decimal(module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_DECIMAL;
	}

      if (l == DTYPE_MONEY || r == DTYPE_MONEY)
	{
	  ensure_money (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_money (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_MONEY;
	}

      if (l == DTYPE_SMINT && r == DTYPE_SMFLOAT)
	{
	  ensure_smfloat (module,lineno,p->expr_str_u.expr_op->left, 0);
	  //ensure_smfloat (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_SMFLOAT;
	}

      if (l == DTYPE_SMINT && r == DTYPE_SMFLOAT)
	{
	  //ensure_smfloat (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_smfloat (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_SMFLOAT;
	}

      if (l == DTYPE_DTIME && r == DTYPE_INTERVAL)
	{
	  //ensure_smfloat (module,lineno,p->expr_str_u.expr_op->left, 0);
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


      if (l == DTYPE_SMFLOAT && (r == DTYPE_INT || r == DTYPE_SMINT))
	{
	  ensure_smfloat (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_smfloat (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_SMFLOAT;
	}
      if (r == DTYPE_SMFLOAT && (l == DTYPE_INT || l == DTYPE_SMINT))
	{
	  ensure_smfloat (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_smfloat (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_SMFLOAT;
	}

      if (l == DTYPE_SMFLOAT && r == DTYPE_FLOAT)
	{
	  ensure_float (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_float (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_FLOAT;
	}

      if (l == DTYPE_FLOAT && r == DTYPE_SMFLOAT)
	{
	  ensure_float (module,lineno,p->expr_str_u.expr_op->left, 0);
	  ensure_float (module,lineno,p->expr_str_u.expr_op->right, 0);
	  return DTYPE_FLOAT;
	}

      sprintf (buff, "%s!=%s", dtype_as_string (l), dtype_as_string (r));
      A4GL_lint (module, lineno, "DIFFMATH", "Different types in operation (-)", buff);

      fprintf (stderr, "UNHANDLED SUB %d(%s) %d(%s) (%x %x)\n",
	       p->expr_str_u.expr_op->left->expr_type,
	       expr_name (p->expr_str_u.expr_op->left->expr_type),
	       p->expr_str_u.expr_op->right->expr_type, expr_name (p->expr_str_u.expr_op->right->expr_type), l, r);
      return DTYPE_INT;


    case ET_EXPR_BOUND_FCALL:
	return DTYPE_INT;
		
/* -------------------------------------------------------------------------------- */
    case ET_EXPR_BRACKET:
      return expr_datatype (module, lineno, p->expr_str_u.expr_expr);
    case ET_EXPR_OP_POWER:
      return DTYPE_FLOAT;
    case ET_EXPR_AGGREGATE:
      return DTYPE_FLOAT;

    case ET_EXPR_NOT_FIELD_TOUCHED:
      return FAKE_DTYPE_BOOL;

    case ET_EXPR_NOT_EXISTS_SUBQUERY:
      return FAKE_DTYPE_BOOL;
    case ET_EXPR_EXISTS_SUBQUERY:
      return FAKE_DTYPE_BOOL;

	case ET_EXPR_RETURN_NULL:
		return DTYPE_NULL;

    default:

      fprintf (stderr, "UNKNOWN Expression Datatype %s (%d)\n", expr_name (p->expr_type), yylineno);
      A4GL_pause_execution ();	// SAFE TO COMMIT
      return -1;

    }


  // Shouldn't happen
}





int
madmath (char *module, int lineno, expr_str * p)
{
  struct s_operation
  {
    int left_dtype;
    int right_dtype;
    enum e_expr_type op;
    int ok;
    int cast_left;
    int cast_right;
    int expr_dtype;
  } operations[] =
  {

    {
    DTYPE_INT, DTYPE_INT, ET_EXPR_OP_SUB, 1, DTYPE_INT, DTYPE_INT, DTYPE_INT},
    {
    DTYPE_SMINT, DTYPE_SMINT, ET_EXPR_OP_SUB, 1, DTYPE_SMINT, DTYPE_SMINT, DTYPE_INT},
    {
    DTYPE_SMINT, DTYPE_SMINT, ET_EXPR_OP_ADD, 1, DTYPE_SMINT, DTYPE_SMINT, DTYPE_INT},
    {
    -1, -1, -1, -1, -1, -1, -1}
  };
  int a;
  int dtype_left;
  int dtype_right;
  int check = 0;
  a = 0;

  switch (p->expr_type)
    {
      /* This should be a complete list of everything that has a type of expr_op in the union 'switch' in fgl.x */
    case ET_EXPR_OP_ADD:
    case ET_EXPR_OP_AND:
    case ET_EXPR_OP_CONCAT:
    case ET_EXPR_OP_DIV:
    case ET_EXPR_OP_EQUAL:
    case ET_EXPR_OP_GREATER_THAN:
    case ET_EXPR_OP_GREATER_THAN_EQ:
    case ET_EXPR_OP_LESS_THAN:
    case ET_EXPR_OP_LESS_THAN_EQ:
    case ET_EXPR_OP_LIKE:
    case ET_EXPR_OP_MATCHES:
    case ET_EXPR_OP_MOD:
    case ET_EXPR_OP_MULT:
    case ET_EXPR_OP_NOT_EQUAL:
    case ET_EXPR_OP_NOT_LIKE:
    case ET_EXPR_OP_NOT_MATCHES:
    case ET_EXPR_OP_OR:
    case ET_EXPR_OP_POWER:
    case ET_EXPR_OP_SUB:
    case ET_EXPR_OP_USING:
      check = 1;
    default:
      return 0;
    }

  if (!check)
    return 0;

  dtype_left = -1;
  dtype_right = -1;

  if (p->expr_str_u.expr_op->left)
    {
      dtype_left = expr_datatype (module, lineno, p->expr_str_u.expr_op->left) & DTYPE_MASK;
    }


  if (p->expr_str_u.expr_op->right)
    {
      dtype_right = expr_datatype (module, lineno, p->expr_str_u.expr_op->right) & DTYPE_MASK;
    }



  if (dtype_left == DTYPE_TEXT || dtype_left == DTYPE_BYTE || dtype_right == DTYPE_TEXT || dtype_right == DTYPE_BYTE)
    {
      // Cant do anything useful with a TEXT or a BYTE
      return 1;			// Its bad...
    }



  if (dtype_left == DTYPE_SERIAL)
    dtype_left = DTYPE_INT;
  if (dtype_right == DTYPE_SERIAL)
    dtype_right = DTYPE_INT;

  while (1)
    {
      if (operations[a].op == -1)
	{
	  break;
	}

      if (p->expr_type == operations[a].op && dtype_left == operations[a].left_dtype && dtype_right == operations[a].right_dtype)
	{
	  if (!operations[a].ok)
	    {
	      return 1;		// Its bad...
	    }
	  if (p->expr_str_u.expr_op->left)
	    {
	      if (dtype_left != operations[a].cast_left)
		{
		  ensure_dtype (module, lineno, p->expr_str_u.expr_op->left, operations[a].cast_left, 0);
		}
	    }
	  if (p->expr_str_u.expr_op->right)
	    {
	      if (dtype_right != operations[a].cast_right)
		{
		  ensure_dtype (module, lineno, p->expr_str_u.expr_op->right, operations[a].cast_right, 0);
		}
	    }

	}

    }
  return 0;


}
