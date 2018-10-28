
#define EXTERN_CONVFMTS
#include "a4gl_libaubit4gl_int.h"



/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/*
=====================================================================
                    Functions definitions
=====================================================================

*/
//static void A4GL_lvarchardec_ops (int op);


void A4GL_dt_dt_ops (int op);

#ifdef NOINT8SUPPORT
void
add_lvarchar_support (void)
{
#ifdef DEBUG
  A4GL_debug ("No lvarchar_support");
#endif
}
#else



void push_dec_op_from_int_int (int a, int b, char op);


static const char vNull[] ={0x0, 0xff};

static int
isCompare (int op)
{
  switch (op)
    {
    case OP_LESS_THAN:
    case OP_GREATER_THAN:
    case OP_LESS_THAN_EQ:
    case OP_GREATER_THAN_EQ:
    case OP_EQUAL:
    case OP_NOT_EQUAL:
      return 1;
    }
  return 0;
}


static char *
A4GL_display_lvarchar (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
//printf("A4GL_display_lvarchar");
	return 0;
}

static void
A4GL_null_lvarchar (void *p)
{
//printf("A4GL_null_lvarchar");
  a4gl_lvarchar *ptr;
  ptr = p;
  memcpy (ptr, &vNull, sizeof (vNull));
  //*ptr = 0x00LL;
}



static void A4GL_lvarchar_lvarchar_ops (int op)
{
  char *a=NULL;
  char *b=NULL;
  //double d1;
  //double d2;
  //double dc;
  int dt1;
  int dt2;
  int sz1;
  int sz2;
  //int l1;
  //int l2;
  int done1;
  int done2;

  int d1;
  int d2;
  int s1;
  int s2;
  char *ptr1;
  char *ptr2;

//printf("A4GL_lvarchar_lvarchar_ops\n");

  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
  A4GL_get_top_of_stack (2, &d2, &s2, (void **) &ptr2);

#ifdef DEBUG
  A4GL_debug (" About to pop '%s'(%s) '%s'(%s)", A4GL_null_as_null (ptr1),
	      A4GL_isnull (d1, ptr1) ? "null" : "not null", A4GL_null_as_null (ptr2), A4GL_isnull (d2, ptr2) ? "null" : "not null");
#endif

  b = A4GL_char_pop ();
  a = A4GL_char_pop ();

#ifdef DEBUG
  A4GL_debug ("a='%s' b='%s' op=%d\n", A4GL_null_as_null (a), A4GL_null_as_null (b), op);
#endif

  if (A4GL_isnull (DTYPE_CHAR, (void *) a) || A4GL_isnull (DTYPE_CHAR, (void *) b))
    {
#ifdef DEBUG
      A4GL_debug ("One of them is null...");
#endif
	  free (a);
	  free (b);
      if (isCompare (op)  && A4GL_return_0_on_null_compare())
	{
	  A4GL_push_int (0);
	  return;
	}
      else
	{
	  A4GL_push_null (DTYPE_CHAR, 0);
	return;
	}
    }

  else
    {
#ifdef DEBUG
      A4GL_debug ("OK - neither is null");
#endif
    }

  A4GL_trim_not_nl (b);
  A4GL_trim_not_nl (a);


#ifdef DEBUG
  A4GL_debug ("a='%s' b='%s' op=%d and they're trimmed\n", A4GL_null_as_null (a), A4GL_null_as_null (b), op);
#endif

  switch (op)
    {
    case OP_ADD:
    case OP_SUB:
    case OP_MULT:
    case OP_DIV:
    case OP_MOD:
    case OP_POWER:

      // Not normal to add two strings...
      A4GL_whats_in_a_string (a, &dt1, &sz1,DTYPE_DTIME);
      A4GL_whats_in_a_string (b, &dt2, &sz2,DTYPE_DTIME);

      done1 = 0;
      done2 = 0;
      if (dt1 == DTYPE_CHAR)
	{
	  free (a);
	  free (b);
     		A4GL_push_null(DTYPE_INT,0);
	  //A4GL_exitwith ("Invalid operation on a character string (1)");
	  return;
	}
      if (dt2 == DTYPE_CHAR)
	{
	  free (a);
	  free (b);
     A4GL_push_null(DTYPE_INT,0);
	  //A4GL_exitwith ("Invalid operation on a character string (2)");
	  return;
	}


      if (dt1 == DTYPE_DECIMAL)
	{
	  fgldecimal c;
	  A4GL_push_char (a);
	  A4GL_pop_var2 (&c, 5, 0x2010);
	  A4GL_push_variable (&c, 0x20100005);
	  done1 = 1;
	}
      if (dt1 == DTYPE_INT)
	{
	  long c;
	  A4GL_push_char (a);
	  A4GL_pop_var2 (&c, 2, 0);
	  A4GL_push_variable (&c, 0x2);
	  done1 = 1;
	}
      if (dt1 == DTYPE_DATE)
	{
	  long c;
	  A4GL_push_char (a);
	  A4GL_pop_var2 (&c, 7, 0);
	  A4GL_push_variable (&c, 0x7);
	  done1 = 1;
	}
      if (!done1)
	{
	  A4GL_assertion (1, "Unhandled character operation");
	}

      if (dt2 == DTYPE_DECIMAL)
	{
	  fgldecimal c;
	  A4GL_push_char (b);
	  A4GL_pop_var2 (&c, 5, 0x2010);
	  A4GL_push_variable (&c, 0x20100005);
	  done2 = 1;
	}
      if (dt2 == DTYPE_INT)
	{
	  long c;
	  A4GL_push_char (b);
	  A4GL_pop_var2 (&c, 2, 0);
	  A4GL_push_variable (&c, 0x2);
	  done2 = 1;
	}
      if (dt2 == DTYPE_DATE)
	{
	  long c;
	  A4GL_push_char (b);
	  A4GL_pop_var2 (&c, 7, 0);
	  A4GL_push_variable (&c, 0x7);
	  done2 = 1;
	}
      if (!done2)
	{
	  A4GL_assertion (1, "Unhandled character operation");
	}
      A4GL_pushop (op);
      return;




    case OP_LESS_THAN:
      A4GL_push_int (strcmp (a, b) < 0);
      free (a);
      free (b);
      return;

    case OP_GREATER_THAN:
      A4GL_push_int (strcmp (a, b) > 0);
      free (a);
      free (b);
      return;

    case OP_LESS_THAN_EQ:
      A4GL_push_int (strcmp (a, b) <= 0);
      free (a);
      free (b);
      return;

    case OP_GREATER_THAN_EQ:
      A4GL_push_int (strcmp (a, b) >= 0);
      free (a);
      free (b);
      return;

    case OP_EQUAL:
      //if (strcmp(a,"journal")==0 && strcmp(b,"all")==0) { A4GL_assertion(1,"Testing"); }
#ifdef DEBUG
      A4GL_debug ("Comparing %s %s - gives %d\n", A4GL_null_as_null (a), A4GL_null_as_null (b), (strcmp (a, b) == 0));
#endif
      A4GL_push_int (strcmp (a, b) == 0);
#ifdef DEBUG
      A4GL_debug ("Freeing my two popped strings %p and %p", a, b);
#endif
      free (a);
      free (b);
      return;

    case OP_NOT_EQUAL:
      A4GL_push_int (strcmp (a, b) != 0);
      free (a);
      free (b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  free (a);
  free (b);
  return;
}


static void A4GL_num_lvarchar_ops(int op) {
double d;
double d2;
char *p;
int dtype_string;
int sl;
//printf("A4GL_num_lvarchar_ops");
p=A4GL_char_pop();
d=A4GL_pop_double();

if (A4GL_isnull (DTYPE_CHAR, (void *) p) || A4GL_isnull (DTYPE_FLOAT, (void *) &d) ) {
        free(p);
        if (isCompare(op)  && A4GL_return_0_on_null_compare()) { A4GL_push_int (0); return; }
        A4GL_push_null (DTYPE_SMFLOAT, 0);
        return ;
}

A4GL_whats_in_a_string(p,&dtype_string,&sl,0);
if (dtype_string==DTYPE_DTIME || dtype_string==DTYPE_INTERVAL) {
        dtype_string=0;
}

if (dtype_string==0) {
        char buff[50000];
        strcpy(buff,p);
        A4GL_trim(buff);
        if (strlen(buff)) {
                A4GL_push_null (DTYPE_SMFLOAT, 0);
                return;
        }
        sprintf(buff,"%lf",d);
        A4GL_push_char(p);
        A4GL_push_char(buff);
        free(p);
        A4GL_lvarchar_lvarchar_ops(op);
        return;
        // Its not a nimber - so it must be null...
        //A4GL_push_null (DTYPE_SMFLOAT, 0);
        return;
}
// Numeric comparison...
A4GL_push_char(p);
free(p);
d2=A4GL_pop_double();
A4GL_push_double(d);
A4GL_push_double(d2);
A4GL_pushop(op);

}


static int
A4GL_isnull_lvarchar (void *p)
{
  int isnull;
//printf("A4GL_isnull_lvarchar\n");
  a4gl_lvarchar *ptr;
  ptr = p;
  if (memcmp (ptr, &vNull, sizeof (vNull)) == 0)
    {
      isnull = 1;
    }
  else
    {
      isnull = 0;
    }

  return isnull;
}


static char *A4GL_output_lvarchar(void) {
	return "a4gl_lvarchar";
}


static int A4GL_conv_lvarchar (int d1, void *p1, int d2, void *p2, int size) { 
//printf("A4GL_conv_lvarchar %d %d\n",d1,d2);
//A4GL_debug_print_stack();
if ((d2&DTYPE_MASK)==DTYPE_LVARCHAR) {
	char *s;
	A4GL_push_param(p1,d1);
	s=A4GL_char_pop();
	strcpy(((a4gl_lvarchar *)p2),s );
	//A4GL_push_char(((a4gl_lvarchar *)p2)->data);
        //printf("to %s\n", (((a4gl_lvarchar *)p2)));
	return 1;
} else {
	
	//char *s;

	A4GL_push_char(((a4gl_lvarchar *)p1));
//A4GL_debug_print_stack();
        //printf("from %s to %d %d\n", (((a4gl_lvarchar *)p1)), d2,size);

//A4GL_debug("Popping into %d\n", d2);
	A4GL_pop_param(p2,d2, size);
//A4GL_debug_print_stack();
	return 1;
}

	A4GL_assertion(1,"Not implemented");
 return 0;
}



static void A4GL_lvarchar_num_ops(int op) {
double d;
double d2;
char *p;
int dtype_string;
int sl;
//printf("A4GL_lvarchar_num_ops\n");
d=A4GL_pop_double();
p=A4GL_char_pop();

if (A4GL_isnull (DTYPE_LVARCHAR, (void *) p) || A4GL_isnull (DTYPE_FLOAT, (void *) &d) ) {
	free(p);
	if (isCompare(op)  && A4GL_return_0_on_null_compare()) { A4GL_push_int (0); return; }
      	A4GL_push_null (DTYPE_SMFLOAT, 0);
	return ;
}

A4GL_whats_in_a_string(p,&dtype_string,&sl,0);

if (dtype_string==DTYPE_DTIME || dtype_string==DTYPE_INTERVAL) {
	dtype_string=0;
}

if (dtype_string==0) { 
	char buff[30000];
	strcpy(buff,p);
	A4GL_trim(buff);
	if (strlen(buff)) {
   		A4GL_push_null (DTYPE_SMFLOAT, 0);
		return;
	}
	sprintf(buff,"%lf",d);
	A4GL_push_char(p);
	A4GL_push_char(buff);
	free(p);
	A4GL_lvarchar_lvarchar_ops(op);

	// Its not a nimber - so it must be null...
   	//A4GL_push_null (DTYPE_SMFLOAT, 0);
	return;
} 


// Numeric expression...
A4GL_push_char(p);
free(p);
d2=A4GL_pop_double();
A4GL_push_double(d2);
A4GL_push_double(d);
A4GL_pushop(op);

}

static void
A4GL_in_lvarchar_ops (int op)
{
  struct ival in1;
  //struct ival in2;
  //int ival_data1[10];
  int d1, d2;
  int s1;
  struct ival *pi1;
  //struct ival in;
  //int se1;
  //double d_i1;
  int s2;
  //int a;
  char *ptr;
  int done1;
//extern int params_cnt;

/*
  for (a = 0; a < 10; a++)
    {
      ival_data1[a] = 0;
    } */

#ifdef DEBUG
  A4GL_debug ("in_in_ops - op=%d", op);
#endif
// d2 op d1

  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &ptr);
  A4GL_get_top_of_stack (2, &d1, &s1, (void *) &pi1);

  if ((d1 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      A4GL_assertion (1, "Confused... Expecting an interval");
    }
  if ((d2 & DTYPE_MASK) != DTYPE_LVARCHAR )
    {
      A4GL_assertion (1, "Confused... Expecting a string");
    }


  if (A4GL_isnull (d1, (void *) pi1))
    {
      A4GL_drop_param ();
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }

  if (A4GL_isnull (DTYPE_LVARCHAR, ptr))
    {
      A4GL_drop_param ();
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }




  A4GL_assertion (pi1 == 0, "First interval is 0 (1)");


  memcpy (&in1, pi1, sizeof (struct ival));

  ptr = A4GL_char_pop ();
  A4GL_drop_param ();		// We've already memcpy'd this across...

#ifdef DEBUG
  A4GL_debug ("Got stuff off stack...");
#endif



  // Not normal to add two strings...
  	A4GL_whats_in_a_string (ptr, &d2, &s2,DTYPE_INTERVAL);
	
  A4GL_push_interval (&in1, s1);
  
#ifdef DEBUG
A4GL_debug("Here.. %d %d",d2,s2);

#endif


#ifdef DEBUG
A4GL_debug("Here..");
#endif
  done1 = 0;
  if (d2 == DTYPE_LVARCHAR)
    {
      free (ptr);
     A4GL_push_null(DTYPE_INT,0);
      A4GL_exitwith ("Invalid operation on a character string (3)");
      return;
    }
  if (d2 == DTYPE_DECIMAL)
    {
      fgldecimal c;
      A4GL_push_char (ptr);
      A4GL_pop_var2 (&c, 5, 0x2010);
      A4GL_push_variable (&c, 0x20100005);
      done1 = 1;
    }
  if (d2 == DTYPE_INT)
    {
      long c;
      A4GL_push_char (ptr);
      A4GL_pop_var2 (&c, 2, 0);
      A4GL_push_variable (&c, 0x2);
      done1 = 1;
    }
  if (d2 == DTYPE_DATE)
    {
      long c;
      A4GL_push_char (ptr);
      A4GL_pop_var2 (&c, 7, 0);
      A4GL_push_variable (&c, 0x7);
      done1 = 1;
    }
  if (d2 == DTYPE_INTERVAL)
    {
      acli_interval (ptr, s2);
      done1 = 1;
    }
  if (d2 == DTYPE_DTIME)
    {
      A4GL_assertion (1, "Failed to used a character string which looks like a datetime with an interval");
    }
  if (!done1)
    {
      A4GL_assertion (1, "Unhandled character operation");
    }

#ifdef DEBUG
A4GL_debug("Here..");
#endif
  A4GL_pushop (op);
#ifdef DEBUG
A4GL_debug("Here..");
#endif
  return;
}


static int
A4GL_dtype_function_lvarchar_getlength (char *base, int nparam)
{
//printf("A4GL_dtype_function_lvarchar_getlength\n");
  if (nparam != 0)
    {
      return 0;
    }
  return strlen(base);
}



static void
A4GL_dt_lvarchar_ops (int op)
{
  int dtype1;
  int dtype2;
  int sz1;
  int sz2;
  struct A4GLSQL_dtime *pdt2;
  void *pdt1;
  struct A4GLSQL_dtime dt1;
  struct A4GLSQL_dtime dt2;
  char *p;
#ifdef DEBUG
  A4GL_debug ("in A4GL_dt_char_ops");
#endif
  A4GL_get_top_of_stack (1, &dtype1, &sz1, (void *) &pdt1);
  A4GL_get_top_of_stack (2, &dtype2, &sz2, (void *) &pdt2);

  if (pdt2)
    {
      dt1.stime = pdt2->stime;
      dt1.ltime = pdt2->ltime;
    }
  else
    {
      // we've not been passed the datetime..
      dt1.stime = sz2 >> 4;
      dt1.ltime = sz2 & 15;
    }
  p = A4GL_char_pop ();
  A4GL_pop_param (&dt1, DTYPE_DTIME, dt1.stime * 16 + dt1.ltime);

#ifdef DEBUG
  A4GL_debug ("popped everything off...");
#endif
// Lets try converting our string to a datetime with the same units as our datetime...
  A4GL_push_char (p);

  dt2.stime = dt1.stime;
  dt2.ltime = dt1.ltime;
#ifdef DEBUG
  A4GL_debug ("Pushed our character back on - converting to a datetime...");
#endif


  if (A4GL_pop_param (&dt2, DTYPE_DTIME, dt2.stime * 16 + dt2.ltime))
    {
      // Success !
      A4GL_trim (p);
      if (strlen (p))
	{			// They might just be checking its not blank...
#ifdef DEBUG
	  A4GL_debug ("Converted ok");
#endif
	  A4GL_push_variable (&dt1, (ENCODE_SIZE (((dt1.stime * 16) + dt1.ltime))) + DTYPE_DTIME);
	  A4GL_push_variable (&dt2, (ENCODE_SIZE (((dt2.stime * 16) + dt2.ltime))) + DTYPE_DTIME);
	  A4GL_dt_dt_ops (op);
	}
      else
	{
	  A4GL_push_variable (&dt1, (ENCODE_SIZE (((dt1.stime * 16) + dt1.ltime))) + DTYPE_DTIME);
	  A4GL_push_char (" ");
	  A4GL_lvarchar_lvarchar_ops (op);
	}
      return;
    }
  else
    {
      // OK - we cant do that...
      A4GL_push_null (DTYPE_LVARCHAR, 0);
      return;
    }


// Should never get here!
  A4GL_push_null (DTYPE_LVARCHAR, 0);
  return;

}

static int
A4GL_dtype_function_lvarchar_substring (char *base, int nparam)
{
  int s=-1;
  int e=-1;
//printf("A4GL_dtype_function_lvarchar_substring\n");
  if (nparam==1) {
        s=A4GL_pop_long();
        e=s;
  }

  if (nparam==2) {
        e=A4GL_pop_long();
        s=A4GL_pop_long();
  }
  if (s<0 || e<0) return 0;
  A4GL_push_substr(base,strlen(base)<<16,s,e,0);
  return 1;
}


static void
A4GL_date_lvarchar_ops (int op)
{
  long a;
  char *ptr;
  long c;
  long d;
  char buff[256];
  int was_ok;
  int b;

  ptr = A4GL_char_pop ();
  a = A4GL_pop_long ();
  strncpy (buff, ptr, 255);
  buff[255] = 0;

  if (A4GL_isnull (DTYPE_INT, (void *) &a) || A4GL_isnull (DTYPE_LVARCHAR, (void *) ptr))
    {
      free (ptr);
#ifdef DEBUG
      A4GL_debug ("int_date - one is null");
#endif
      if (isCompare (op)  && A4GL_return_0_on_null_compare())
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }

  free (ptr);


  // Comparisons would normally be to another date....
  if (op == OP_LESS_THAN || op == OP_GREATER_THAN || op == OP_LESS_THAN_EQ || op == OP_GREATER_THAN_EQ || op == OP_EQUAL
      || op == OP_NOT_EQUAL)
    {
      // Firstly - is our string a date ?
      was_ok = A4GL_conversion_ok (-1);
      A4GL_conversion_ok (1);
      A4GL_push_char (buff);
      c = A4GL_pop_date ();
      if (!A4GL_conversion_ok (-1) || A4GL_isnull (DTYPE_DATE, (void *) &c))
	{			// Its not a date..
	  // Try as an integer ?
	  A4GL_push_char (buff);
	  b = A4GL_pop_long ();
	}
      else
	{
	  b = c;
	}

      A4GL_conversion_ok (was_ok);
    }
  else
    {
      A4GL_push_char (buff);
      b = A4GL_pop_long ();

    }

  switch (op)
    {
    case OP_ADD:
      a += b;
      if (a <= 2958464)
	A4GL_push_date (a);
      else
	A4GL_push_date (0);

      return;
    case OP_SUB:
      A4GL_push_date (a - b);
      return;
    case OP_MULT:
      A4GL_push_date (a * b);
      return;


    case OP_DIV:
      if (b == 0)
	{
	  A4GL_push_null (DTYPE_INT, 0);
	  return;
	}
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  push_dec_op_from_int_int (a, b, '/');
	  return;
	}

    case OP_MOD:
      A4GL_push_long (a % b);
      return;
    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_long (a);
	  return;
	}
      c = a;
      for (d = 1; d < b; d++)
	c *= a;
      A4GL_push_long (c);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a < b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a > b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a <= b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a >= b);
      return;
    case OP_EQUAL:
      A4GL_push_int (a == b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a != b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}


static void
A4GL_lvarchar_dt_ops (int op)
{
  int dtype1;
  int dtype2;
  int sz1;
  int sz2;
  struct A4GLSQL_dtime *pdt2;
  void *pdt1;
  struct A4GLSQL_dtime dt1;
  struct A4GLSQL_dtime dt2;
  char *p;

  A4GL_get_top_of_stack (1, &dtype2, &sz2, (void *) &pdt2);
  A4GL_get_top_of_stack (2, &dtype1, &sz1, (void *) &pdt1);

  dt1.stime = pdt2->stime;
  dt1.ltime = pdt2->ltime;
  A4GL_pop_param (&dt1, DTYPE_DTIME, dt1.stime * 16 + dt1.ltime);
  p = A4GL_char_pop ();

#ifdef DEBUG
  A4GL_debug ("popped everything off...");
#endif
// Lets try converting our string to a datetime with the same units as our datetime...
  A4GL_push_char (p);
  dt2.stime = dt1.stime;
  dt2.ltime = dt1.ltime;
#ifdef DEBUG
  A4GL_debug ("Pushed our character back on - converting to a datetime...");
#endif

  if (A4GL_pop_param (&dt2, DTYPE_DTIME, dt2.stime * 16 + dt2.ltime))
    {
      // Success !
#ifdef DEBUG
      A4GL_debug ("Converted ok");
#endif
      A4GL_push_variable (&dt2, (ENCODE_SIZE (((dt2.stime * 16) + dt2.ltime))) + DTYPE_DTIME);
      A4GL_push_variable (&dt1, (ENCODE_SIZE (((dt1.stime * 16) + dt1.ltime))) + DTYPE_DTIME);
      A4GL_dt_dt_ops (op);
      return;
    }
  else
    {
      // OK - we cant do that...
      A4GL_push_null (DTYPE_CHAR, 0);
      return;
    }


// Should never get here!
  A4GL_push_null (DTYPE_CHAR, 0);
  return;

}

static void *
A4GL_conv_copy_lvarchar (char *p)
{
  char *ptr;
//printf("A4GL_conv_copy_lvarchar\n");
  //last_was_empty = 0;
  A4GL_assertion (p == 0, "pointer was 0 in A4GL_push_char");
  if (p[0] == 0 && p[1] != 0)
    {
      ptr = (char *) A4GL_new_string_set ((int) strlen (p) + 1, p);
      ptr[0] = 0;
      ptr[1] = 1;
    }
  else
    {
      ptr = (char *) A4GL_new_string_set ((int) strlen (p), p);
    }
  return ptr;

}


static int A4GL_allocatecharpop_lvarchar(int d, a4gl_lvarchar *ptr ) {
//printf("A4GL_allocatecharpop_lvarchar\n");
return LVARCHARLENGTH+1;
}

void
add_lvarchar_support (void)
{
#ifdef DEBUG
#ifdef DEBUG
  A4GL_debug ("Has lvarchar_support\n");
#endif
#endif
  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "INIT", (void *) A4GL_null_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "ISNULL", (void *) A4GL_isnull_lvarchar);	//
  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "SETDTYPE", (void *) A4GL_isnull_lvarchar);	// Invalid conversion set it to 0
  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "DISPLAY", (void *) A4GL_display_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "OUTPUT", (void *) A4GL_output_lvarchar);
  //A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "COPY", (void *) A4GL_conv_copy_lvarchar);

  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "CONVTO_43", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_FLOAT, "CONVTO_43", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_DECIMAL, "CONVTO_43", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_INT, "CONVTO_43", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_SMINT, "CONVTO_43", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_SMFLOAT, "CONVTO_43", (void *) A4GL_conv_lvarchar);


  A4GL_add_datatype_function_i (DTYPE_CHAR, "CONVTO_43", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_VCHAR, "CONVTO_43", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_NVCHAR, "CONVTO_43", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_NCHAR, "CONVTO_43", (void *) A4GL_conv_lvarchar);


  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "CONVTO_5", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "CONVTO_3", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "CONVTO_1", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "CONVTO_2", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "CONVTO_0", (void *) A4GL_conv_lvarchar);
  A4GL_add_datatype_function_i (DTYPE_LVARCHAR, "ALLOCATECHARPOP", (void *) A4GL_allocatecharpop_lvarchar);

  A4GL_add_op_function (DTYPE_LVARCHAR, DTYPE_INT, OP_MATH, A4GL_lvarchar_num_ops);
  A4GL_add_op_function (DTYPE_LVARCHAR, DTYPE_SERIAL, OP_MATH, A4GL_lvarchar_num_ops);
  A4GL_add_op_function (DTYPE_LVARCHAR, DTYPE_SMINT, OP_MATH, A4GL_lvarchar_num_ops);
  A4GL_add_op_function (DTYPE_LVARCHAR, DTYPE_FLOAT, OP_MATH, A4GL_lvarchar_num_ops);
  A4GL_add_op_function (DTYPE_LVARCHAR, DTYPE_SMFLOAT, OP_MATH, A4GL_lvarchar_num_ops);
  A4GL_add_op_function (DTYPE_LVARCHAR, DTYPE_DECIMAL, OP_MATH, A4GL_lvarchar_num_ops);
  A4GL_add_op_function (DTYPE_LVARCHAR, DTYPE_MONEY, OP_MATH, A4GL_lvarchar_num_ops);
  A4GL_add_op_function (DTYPE_INT,        DTYPE_LVARCHAR,  OP_MATH, A4GL_num_lvarchar_ops);
  A4GL_add_op_function (DTYPE_SERIAL,     DTYPE_LVARCHAR,  OP_MATH, A4GL_num_lvarchar_ops);
  A4GL_add_op_function (DTYPE_SMINT,      DTYPE_LVARCHAR,  OP_MATH, A4GL_num_lvarchar_ops);
  A4GL_add_op_function (DTYPE_FLOAT,      DTYPE_LVARCHAR, OP_MATH, A4GL_num_lvarchar_ops);
  A4GL_add_op_function (DTYPE_SMFLOAT,    DTYPE_LVARCHAR, OP_MATH, A4GL_num_lvarchar_ops);
  A4GL_add_op_function (DTYPE_DECIMAL,    DTYPE_LVARCHAR, OP_MATH, A4GL_num_lvarchar_ops);
  A4GL_add_op_function (DTYPE_MONEY,      DTYPE_LVARCHAR, OP_MATH, A4GL_num_lvarchar_ops);

  A4GL_add_op_function (DTYPE_LVARCHAR, DTYPE_LVARCHAR, OP_MATH, A4GL_lvarchar_lvarchar_ops);
  A4GL_add_op_function (DTYPE_CHAR, DTYPE_LVARCHAR, OP_MATH, A4GL_lvarchar_lvarchar_ops);
  A4GL_add_op_function (DTYPE_LVARCHAR, DTYPE_CHAR, OP_MATH, A4GL_lvarchar_lvarchar_ops);
  A4GL_add_op_function (DTYPE_INTERVAL, DTYPE_LVARCHAR, OP_MATH, A4GL_in_lvarchar_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_LVARCHAR, OP_MATH, A4GL_date_lvarchar_ops);
  A4GL_add_op_function (DTYPE_LVARCHAR, DTYPE_DTIME, OP_MATH, A4GL_lvarchar_dt_ops);
  A4GL_add_op_function (DTYPE_DTIME, DTYPE_LVARCHAR, OP_MATH, A4GL_dt_lvarchar_ops);
  A4GL_add_datatype_function_i (DTYPE_NCHAR, ":getlength", (void *) A4GL_dtype_function_lvarchar_getlength);
  A4GL_add_datatype_function_i (DTYPE_NCHAR, ":substring", (void *) A4GL_dtype_function_lvarchar_substring);
}

#endif



