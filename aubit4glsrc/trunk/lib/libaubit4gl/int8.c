#include "a4gl_libaubit4gl_int.h"
#ifndef LLONG_MAX
#   define LLONG_MAX    9223372036854775807LL
#   define LLONG_MIN    (-LLONG_MAX - 1LL)
#endif

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
static void A4GL_int8dec_ops(int op) ;

#ifdef NOINT8SUPPORT
void add_int8_support(void) { 
	A4GL_debug("No int8_support");
}
#else


static const int8 vNull=0x8000000000000LL;

static char *A4GL_display_int8 (void *ptr, int size, int size_c,
                  struct struct_scr_field *field_details, int display_type)
{
  int8 a=0;
  int8 value_in_ptr=0;
  static char buff_16[256];
  memset(buff_16,0,sizeof(buff_16));
  A4GL_debug ("A4GL_display_int..");
	if (ptr==0) { // Assume its null
          strcpy (buff_16, "           ");
  return buff_16;

	}
  value_in_ptr=*(int8 *)ptr;

  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_INT8, ptr))
        {
          strcpy (buff_16, "           ");
        }
      else
        {
          a = value_in_ptr;
          SPRINTF1 (buff_16, "%20lld", a);
        }
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull (DTYPE_INT8, ptr))
        {
          strcpy (buff_16, "");
        }
      else
        {
          a =value_in_ptr;
          SPRINTF1 (buff_16, "%lld", a);
        }
    }
  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (ptr)
        {
          A4GL_debug ("DISPLAY_TYPE_DISPLAY_TO : %d", *(int *) ptr);
        }

      if (ptr == 0 || A4GL_isnull (DTYPE_INT8, ptr))
        {
          A4GL_debug ("Int value is null");
          strcpy (buff_16, "");
          return buff_16;
        }

      a = value_in_ptr;

      if (A4GL_isnull (DTYPE_INT8, (void *) &a))
        {
          A4GL_debug ("Int value is null");
          strcpy (buff_16, "");
          return buff_16;
        }

      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
        {
          strcpy (using_buff,
                  (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
        }
      else
        {
          memset (using_buff, '-', 255);
          using_buff[size_c] = 0;
          using_buff[size_c - 1] = '&';
        }

      A4GL_push_long (a);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_16, size_c);
      A4GL_debug ("display_int Got '%s'", buff_16);
      return buff_16;
    }

  A4GL_debug ("Returning '%s'", buff_16);

  return buff_16;
}


static void A4GL_null_int8(void *p) {
	int8 *ptr;
	ptr=p;
	memcpy(ptr,&vNull,sizeof(vNull));
	//*ptr = 0x00LL;
}

static void A4GL_zero_int8(void *p) {
	A4GL_assertion(p==0,"Pointer not set");
	*(int8 *)p = 0;
}

static int A4GL_isnull_int8(void *p) {
	int isnull;
	if (memcmp(p,&vNull,sizeof(vNull))==0) {
	 isnull=1;
	}
	else {
	isnull=0;
	}
	
	return isnull;
}



static void *A4GL_copy_int8(void *p) {
	int8 *ptr;
	ptr=(int8 *)malloc(sizeof(int8));
	A4GL_debug("Malloc : %p", ptr);
	*ptr=*(int8*)p;
	return ptr;
}

static void A4GL_int8_smint_ops(int op) {
int8 b;
int a;
int8 c;
int d;
//fgldecimal c_d;
char s1[2000];
char s2[2000];
A4GL_debug("here");
  b = A4GL_pop_int8 ();
  a = A4GL_pop_int ();
  switch (op) {
    case OP_ADD: 
    case OP_SUB: 
    case OP_MULT: 
    case OP_DIV:
    case OP_POWER:
    case OP_MOD: 
		// Overflow detection...-  Do the same thing with decimals..
		sprintf(s1,"%d",a); sprintf(s2,"%lld",b);
		if (A4GL_apm_str_detect_overflow(s1,s2,op,DTYPE_INT8)) {
			double d;
			d=A4GL_pop_double();
			A4GL_push_double(d);
			return;
		}
  }
  switch (op) {
    case OP_ADD: A4GL_push_int8 (a + b); return;
    case OP_SUB: A4GL_push_int8 ((a - b)); return;
    case OP_MULT: A4GL_push_int8 ((a * b)); return;

    case OP_DIV:
        if (b == 0)
          {
            A4GL_push_null (DTYPE_INT8, 0);
            return;
          }
          A4GL_push_double ((double) a / (double) b); 
      return;

    case OP_MOD: A4GL_push_int8 ((int8)a % (int8)b); return;

    case OP_POWER:
      if (b == 0)
        {
          A4GL_push_int8 (1);
          return;
        }
      if (b == 1)
        {
          A4GL_push_int8 (a); // FLOAT/SMFLOAT BASE
          return;
        }

      c = a;

      for (d = 1; d < b; d++)
        c *= a;
      	A4GL_push_int8 (c); // FLOAT/SMFLOAT BASE

      return;

    case OP_LESS_THAN: A4GL_push_int (a < b); return;
    case OP_GREATER_THAN: A4GL_push_int (a > b); return;
    case OP_LESS_THAN_EQ: A4GL_push_int (a <= b); return;
    case OP_GREATER_THAN_EQ: A4GL_push_int (a >= b); return;
    case OP_EQUAL: A4GL_push_int (a == b); return;
    case OP_NOT_EQUAL: A4GL_push_int (a != b); return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

static void A4GL_smint_int8_ops(int op) {
int b;
int8 a;
int8 c;
int d;
char s1[2000];
char s2[2000];

//fgldecimal c_d;
A4GL_debug("here");
  b = A4GL_pop_int ();
  a = A4GL_pop_int8 ();
  switch (op) {
    case OP_ADD: 
    case OP_SUB: 
    case OP_MULT: 
    case OP_DIV:
    case OP_POWER:
    case OP_MOD: 
		// Overflow detection...-  Do the same thing with decimals..
		sprintf(s1,"%lld",a); sprintf(s2,"%d",b);
		if (A4GL_apm_str_detect_overflow(s1,s2,op,DTYPE_INT8)) {
			double d;
			d=A4GL_pop_double();
			A4GL_push_double(d);
			return;
		}
  }


  switch (op) {
    case OP_ADD: A4GL_push_int8 (a + b); return;
    case OP_SUB: A4GL_push_int8 ((a - b)); return;
    case OP_MULT: A4GL_push_int8 ((a * b)); return;

    case OP_DIV:
        if (b == 0)
          {
            A4GL_push_null (DTYPE_INT8, 0);
            return;
          }
          A4GL_push_double ((double) a / (double) b); 
      return;

    case OP_MOD: A4GL_push_int8 ((int8)a % (int8)b); return;

    case OP_POWER:
      if (b == 0)
        {
          A4GL_push_int8 (1);
          return;
        }
      if (b == 1)
        {
          A4GL_push_int8 (a); // FLOAT/SMFLOAT BASE
          return;
        }

      c = a;

      for (d = 1; d < b; d++)
        c *= a;
      	A4GL_push_int8 (c); // FLOAT/SMFLOAT BASE

      return;

    case OP_LESS_THAN: A4GL_push_int (a < b); return;
    case OP_GREATER_THAN: A4GL_push_int (a > b); return;
    case OP_LESS_THAN_EQ: A4GL_push_int (a <= b); return;
    case OP_GREATER_THAN_EQ: A4GL_push_int (a >= b); return;
    case OP_EQUAL: A4GL_push_int (a == b); return;
    case OP_NOT_EQUAL: A4GL_push_int (a != b); return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

static void A4GL_int8_int8_ops(int op) {
int8 b;
int8 a;
int8 c;
int d;
char s1[2000];
char s2[2000];
//fgldecimal c_d;
A4GL_debug("here");
  b = A4GL_pop_int8 ();
  a = A4GL_pop_int8 ();

  switch (op) {
    case OP_ADD: 
    case OP_SUB: 
    case OP_MULT: 
    case OP_DIV:
    case OP_POWER:
    case OP_MOD: 
		// Overflow detection...-  Do the same thing with decimals..
		sprintf(s1,"%lld",a);
		sprintf(s2,"%lld",b);
		if (A4GL_apm_str_detect_overflow(s1,s2,op,DTYPE_INT8)) {
			double d;
			d=A4GL_pop_double();
			A4GL_push_double(d);
			return;
		}
  }

  switch (op) {
    case OP_ADD: 
			c=a + b;
				A4GL_push_int8 (c); 
			return;
    case OP_SUB: 
			c=a-b;
				A4GL_push_int8 (c); 
			return;
    case OP_MULT: 
			c=a * b; 
				A4GL_push_int8 (c); 
	return;

    case OP_DIV:
        if (b == 0)
          {
            A4GL_push_null (DTYPE_INT8, 0);
            return;
          }
          A4GL_push_double ((double) a / (double) b); 
      return;

    case OP_MOD: A4GL_push_int8 ((int8)a % (int8)b); return;

    case OP_POWER:
      if (b == 0)
        {
          A4GL_push_int8 (1);
          return;
        }
      if (b == 1)
        {
          A4GL_push_int8 (a); // FLOAT/SMFLOAT BASE
          return;
        }

      c = a;

      for (d = 1; d < b; d++)
        c *= a;
      	A4GL_push_int8 (c); // FLOAT/SMFLOAT BASE

      return;

    case OP_LESS_THAN: A4GL_push_int (a < b); return;
    case OP_GREATER_THAN: A4GL_push_int (a > b); return;
    case OP_LESS_THAN_EQ: A4GL_push_int (a <= b); return;
    case OP_GREATER_THAN_EQ: A4GL_push_int (a >= b); return;
    case OP_EQUAL: A4GL_push_int (a == b); return;
    case OP_NOT_EQUAL: A4GL_push_int (a != b); return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

	
static void A4GL_int_int8_ops(int op) {
int b;
int8 a;
int8 c;
int d;
//fgldecimal c_d;
char s1[2000];
char s2[2000];

A4GL_debug("here");
  b = A4GL_pop_int ();
  a = A4GL_pop_int8 ();


  switch (op) {
    case OP_ADD: 
    case OP_SUB: 
    case OP_MULT: 
    case OP_DIV:
    case OP_POWER:
    case OP_MOD: 
		// Overflow detection...-  Do the same thing with decimals..
		sprintf(s1,"%lld",a); sprintf(s2,"%d",b);
		if (A4GL_apm_str_detect_overflow(s1,s2,op,DTYPE_INT8)) {
			double d;
			d=A4GL_pop_double();
			A4GL_push_double(d);
			return;
		}
  }
  
  switch (op) {
    case OP_ADD: 
	
			c=a + b;
			
				A4GL_push_int8 (a + b); 
			return;
    case OP_SUB: 
				c=a - b;
				A4GL_push_int8 ((a - b)); 
			return;
    case OP_MULT: 
			c=a * b;
				A4GL_push_int8 ((a * b)); 
			return;

    case OP_DIV:
        if (b == 0)
          {
            A4GL_push_null (DTYPE_INT8, 0);
            return;
          }
          A4GL_push_double ((double) a / (double) b); 
      return;

    case OP_MOD: A4GL_push_int8 ((int8)a % (int8)b); return;

    case OP_POWER:
      if (b == 0)
        {
          A4GL_push_int8 (1);
          return;
        }
      if (b == 1)
        {
          A4GL_push_int8 (a); // FLOAT/SMFLOAT BASE
          return;
        }

      c = a;

      for (d = 1; d < b; d++)
        c *= a;
      	A4GL_push_int8 (c); // FLOAT/SMFLOAT BASE

      return;

    case OP_LESS_THAN: A4GL_push_int (a < b); return;
    case OP_GREATER_THAN: A4GL_push_int (a > b); return;
    case OP_LESS_THAN_EQ: A4GL_push_int (a <= b); return;
    case OP_GREATER_THAN_EQ: A4GL_push_int (a >= b); return;
    case OP_EQUAL: A4GL_push_int (a == b); return;
    case OP_NOT_EQUAL: A4GL_push_int (a != b); return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

	
static void A4GL_int8_int_ops(int op) {
int8 b=0;
long a=0;
int8 c;
int d;
//fgldecimal a_d;
//fgldecimal b_d;
//fgldecimal c_d;
char s1[2000];
char s2[2000];

A4GL_debug("here");

  a = A4GL_pop_long ();
//A4GL_pop_param (&b, DTYPE_INT8, 0);
 b = A4GL_pop_int8 ();


  switch (op) {
    case OP_ADD: 
    case OP_SUB: 
    case OP_MULT: 
    case OP_DIV:
    case OP_POWER:
    case OP_MOD: 
		// Overflow detection...-  Do the same thing with decimals..
		sprintf(s1,"%ld",a); sprintf(s2,"%lld",b);
		if (A4GL_apm_str_detect_overflow(s1,s2,op,DTYPE_INT8)) {
			double d;
			d=A4GL_pop_double();
			A4GL_push_double(d);
			return;
		}
		break;
  }
  

  switch (op) {
    case OP_ADD: 
			c=a + b; 
			A4GL_debug("c=%lld a=%ld b=%lld\n",c,a,b);
				A4GL_push_int8 (c); 
			return;
    case OP_SUB: 
			c=a - b; 
			A4GL_debug("c=%lld a=%ld b=%lld\n",c,a,b);
				A4GL_push_int8 (c); 
			return;
    case OP_MULT: 
			c=a * b;
			A4GL_debug("c=%lld a=%ld b=%lld\n",c,a,b);
				A4GL_push_null (DTYPE_INT8,0); 
			return;

    case OP_DIV:
        if (b == 0)
          {
            A4GL_push_null (DTYPE_INT8, 0);
            return;
          }
          A4GL_push_double ((double) a / (double) b); 
      return;

    case OP_MOD: 
		A4GL_push_int8 ((int8)a % (int8)b); return;

    case OP_POWER:
      if (b == 0)
        {
          A4GL_push_int8 (1);
          return;
        }
      if (b == 1)
        {
          A4GL_push_int8 (a); // FLOAT/SMFLOAT BASE
          return;
        }

      c = a;

      for (d = 1; d < b; d++)
        c *= a;
      	A4GL_push_int8 (c); // FLOAT/SMFLOAT BASE

      return;

    case OP_LESS_THAN: A4GL_push_int (a < b); return;
    case OP_GREATER_THAN: A4GL_push_int (a > b); return;
    case OP_LESS_THAN_EQ: A4GL_push_int (a <= b); return;
    case OP_GREATER_THAN_EQ: A4GL_push_int (a >= b); return;
    case OP_EQUAL: 	A4GL_push_int (a == b); return;
    case OP_NOT_EQUAL: 	A4GL_push_int (a!=b); return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

static void A4GL_float_int8_ops(int op) {
double b;
int8 a;
double c;
int d;

printf("A4GL_float_int8_ops\n");
A4GL_debug("here");
  b = A4GL_pop_double ();
  a = A4GL_pop_int8 ();
  switch (op) {
    case OP_ADD: A4GL_push_double ((double)a + (double)b); return;
    case OP_SUB: A4GL_push_double (((double)a - (double)b)); return;
    case OP_MULT: A4GL_push_double (((double)a * (double)b)); return;

    case OP_DIV:
        if (b == 0)
          {
            A4GL_push_null (DTYPE_FLOAT, 0);
            return;
          }
          A4GL_push_double ((double) a / (double) b); 
      return;

    case OP_MOD: A4GL_push_int8 ((int8)a % (int8)b); return;

    case OP_POWER:
      if (b == 0)
        {
          A4GL_push_double (1);
          return;
        }
      if (b == 1)
        {
          A4GL_push_double ((double)a); // FLOAT/SMFLOAT BASE
          return;
        }

      c = a;

      for (d = 1; d < b; d++) c *= (double)a;
      	A4GL_push_double ((double)c); // FLOAT/SMFLOAT BASE

      return;

    case OP_LESS_THAN: A4GL_push_int (a < b); return;
    case OP_GREATER_THAN: A4GL_push_int (a > b); return;
    case OP_LESS_THAN_EQ: A4GL_push_int (a <= b); return;
    case OP_GREATER_THAN_EQ: A4GL_push_int (a >= b); return;
    case OP_EQUAL: A4GL_push_int (a == b); return;
    case OP_NOT_EQUAL: A4GL_push_int (a != b); return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

static void A4GL_int8_float_ops(int op) {
int8 b;
double a;
double c;
int d;

printf("A4GL_int8_float_ops\n");
A4GL_debug("here");
  b = A4GL_pop_int8 ();
  a = A4GL_pop_double ();
  switch (op) {
    case OP_ADD: A4GL_push_double ((double)a + (double)b); return;
    case OP_SUB: A4GL_push_double (((double)a - (double)b)); return;
    case OP_MULT: A4GL_push_double (((double)a * (double)b)); return;

    case OP_DIV:
        if (b == 0)
          {
            A4GL_push_null (DTYPE_FLOAT, 0);
            return;
          }
          A4GL_push_double ((double) a / (double) b); 
      return;

    case OP_MOD: A4GL_push_int8 ((int8)a % (int8)b); return;

    case OP_POWER:
      if (b == 0)
        {
          A4GL_push_double (1);
          return;
        }
      if (b == 1)
        {
          A4GL_push_double ((double)a); // FLOAT/SMFLOAT BASE
          return;
        }

      c = a;

      for (d = 1; d < b; d++) c *= (double)a;
      	A4GL_push_double ((double)c); // FLOAT/SMFLOAT BASE

      return;

    case OP_LESS_THAN: A4GL_push_int (a < b); return;
    case OP_GREATER_THAN: A4GL_push_int (a > b); return;
    case OP_LESS_THAN_EQ: A4GL_push_int (a <= b); return;
    case OP_GREATER_THAN_EQ: A4GL_push_int (a >= b); return;
    case OP_EQUAL: A4GL_push_int (a == b); return;
    case OP_NOT_EQUAL: A4GL_push_int (a != b); return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

static void A4GL_int8_smfloat_ops(int op) {
int8 b;
double a;
double c;
int d;

A4GL_debug("here");
  b = A4GL_pop_int8 ();
  a = A4GL_pop_double ();
  switch (op) {
    case OP_ADD: A4GL_push_double ((double)a + (double)b); return;
    case OP_SUB: A4GL_push_double (((double)a - (double)b)); return;
    case OP_MULT: A4GL_push_double (((double)a * (double)b)); return;

    case OP_DIV:
        if (b == 0)
          {
            A4GL_push_null (DTYPE_FLOAT, 0);
            return;
          }
          A4GL_push_double ((double) a / (double) b); 
      return;

    case OP_MOD: A4GL_push_int8 ((int8)a % (int8)b); return;

    case OP_POWER:
      if (b == 0)
        {
          A4GL_push_double (1);
          return;
        }
      if (b == 1)
        {
          A4GL_push_double ((double)a); // FLOAT/SMFLOAT BASE
          return;
        }

      c = a;

      for (d = 1; d < b; d++) c *= (double)a;
      	A4GL_push_double ((double)c); // FLOAT/SMFLOAT BASE

      return;

    case OP_LESS_THAN: A4GL_push_int (a < b); return;
    case OP_GREATER_THAN: A4GL_push_int (a > b); return;
    case OP_LESS_THAN_EQ: A4GL_push_int (a <= b); return;
    case OP_GREATER_THAN_EQ: A4GL_push_int (a >= b); return;
    case OP_EQUAL: A4GL_push_int (a == b); return;
    case OP_NOT_EQUAL: A4GL_push_int (a != b); return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}
static void A4GL_smfloat_int8_ops(int op) {
float b;
int8 a;
float c;
int d;

A4GL_debug("here");
  b = A4GL_pop_float ();
  a = A4GL_pop_int8 ();
  switch (op) {
    case OP_ADD: A4GL_push_double ((double)a + (double)b); return;
    case OP_SUB: A4GL_push_double (((double)a - (double)b)); return;
    case OP_MULT: A4GL_push_double (((double)a * (double)b)); return;

    case OP_DIV:
        if (b == 0)
          {
            A4GL_push_null (DTYPE_SMFLOAT, 0);
            return;
          }
          A4GL_push_double ((double) a / (double) b); 
      return;

    case OP_MOD: A4GL_push_int8 ((int8)a % (int8)b); return;

    case OP_POWER:
      if (b == 0)
        {
          A4GL_push_double (1);
          return;
        }
      if (b == 1)
        {
          A4GL_push_double ((double)a); // FLOAT/SMFLOAT BASE
          return;
        }

      c = a;

      for (d = 1; d < b; d++) c *= (double)a;
      	A4GL_push_double ((double)c); // FLOAT/SMFLOAT BASE

      return;

    case OP_LESS_THAN: A4GL_push_int (a < b); return;
    case OP_GREATER_THAN: A4GL_push_int (a > b); return;
    case OP_LESS_THAN_EQ: A4GL_push_int (a <= b); return;
    case OP_GREATER_THAN_EQ: A4GL_push_int (a >= b); return;
    case OP_EQUAL: A4GL_push_int (a == b); return;
    case OP_NOT_EQUAL: A4GL_push_int (a != b); return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}


static void A4GL_int8dec_ops(int op) { // We'll use this for int8_dec and dec_int8
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
long l1;
long l2;
double dbl;
int d;
  //char *a1;
  //char *a2;
A4GL_debug("here");
  A4GL_pop_var2(&b,5,0x4020);
  A4GL_pop_var2(&a,5,0x4020);
A4GL_debug("dec_dec_ops");
  if (A4GL_isnull (DTYPE_DECIMAL, (void *) &a)
      || A4GL_isnull (DTYPE_DECIMAL, (void *) &b))
    {
      A4GL_push_null (DTYPE_DECIMAL, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec(&dc,64,32);

  switch (op)
    {
    case OP_ADD:
        a4gl_decadd(&a,&b,&dc);
        A4GL_push_dec_dec (&dc,0,16);
      return;
    case OP_SUB:
        a4gl_decsub(&a,&b,&dc);
        A4GL_push_dec_dec (&dc,0,16);
      return;
    case OP_MULT:
        a4gl_decmul(&a,&b,&dc);
        A4GL_push_dec_dec (&dc,0,16);
      return;


    case OP_DIV:
        a4gl_decdiv(&a,&b,&dc);
        A4GL_push_dec_dec (&dc,0,16);
        return;

    case OP_MOD:
        a4gl_dectolong(&a,&l1);
        a4gl_dectolong(&b,&l2);
        A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
        a4gl_dectolong(&b,&l2);
      if (l2 == 0)
        {
          A4GL_push_long (1);
          return;
        }
      if (l2 == 1)
        {
        a4gl_dectodbl(&a,&dbl);
          A4GL_push_float (dbl);
          return;
        }

      a4gl_deccopy(&dc, &a);
      for (d = 1; d < l2; d++) a4gl_decmul(&dc, &a,&dc);
      A4GL_push_dec_dec (&dc,0,16);
      return;

    case OP_LESS_THAN:
        A4GL_push_int (a4gl_deccmp(&a,&b)<0) ; return;
    case OP_GREATER_THAN:
        A4GL_push_int (a4gl_deccmp(&a,&b)>0) ; return;
    case OP_LESS_THAN_EQ:
        A4GL_push_int (a4gl_deccmp(&a,&b)<=0) ; return;
    case OP_GREATER_THAN_EQ:
        A4GL_push_int (a4gl_deccmp(&a,&b)>=0) ; return;
    case OP_EQUAL:
        A4GL_push_int (a4gl_deccmp(&a,&b)==0) ; return;
    case OP_NOT_EQUAL:
        A4GL_push_int (a4gl_deccmp(&a,&b)!=0) ; return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

static int
A4GL_conv_int8 (int d1, void *p1, int d2, void *p2, int size)
{
  //int8 l;
char buff[256];

  A4GL_debug ("A4GL_conv_int8 %d %d p1=%p p2=%p\n", d1, d2,p1,p2);
  if (d1 == DTYPE_INT8)
    {
      // Convert FROM int8..
      switch (d2)
	{
	case DTYPE_FLOAT:
	  *(double *) p2 = *(int8 *) p1;
	  return 1;
	case DTYPE_SMFLOAT:
	  *(float *) p2 = *(int8 *) p1;
	  return 1;
	case DTYPE_INT:
	  *(int *) p2 = *(int8 *) p1;
	  return 1;
	case DTYPE_INT8:
	  *(int8 *) p2 = *(int8 *) p1;
	  return 1;
	case DTYPE_SMINT:
	  *(short *) p2 = *(int8 *) p1;
	  return 1;
	case DTYPE_DECIMAL:
	  {
	    char buff[2000];
	    sprintf (buff, "%lld", *(int8 *) p1);
		A4GL_stodec(buff, p2,size);
	    //A4GL_push_char (buff);
	    //A4GL_pop_param (p2, d2, size);
	    return 1;
	  }
	case DTYPE_CHAR:
	  {
	    char buff[2000];
	    sprintf (buff, "%lld", *(int8 *) p1);
	    A4GL_push_char (buff);
	    A4GL_pop_param (p2, d2, size);
	    return 1;
	  }
	}
      return 0;
    }
  else
    {
      // Convert TO int8..
      switch (d1)
	{
	case DTYPE_FLOAT:
		sprintf(buff,"%lf", *(double *) p1);
		if (A4GL_apm_str_detect_overflow(buff, 0,0,DTYPE_INT8)) { // OVERFLOW DETECTION
			A4GL_push_null(DTYPE_INT8,0);
		} else {
	  		*(int8 *) p2 = *(double *) p1;
		}
		A4GL_debug("p2=%lld\n",*(int8 *)p2);
	  return 1;
	case DTYPE_SMFLOAT:
	  *(int8 *) p2 = *(float *) p1;
		A4GL_debug("p2=%lld\n",*(int8 *)p2);
	  return 1;
	case DTYPE_INT:
	  *(int8 *) p2 = *(int *) p1;
		A4GL_debug("p2=%lld\n",*(int8 *)p2);
	  return 1;
	case DTYPE_SMINT:
	  *(int8 *) p2 = *(short *) p1;
		A4GL_debug("p2=%lld\n",*(int8 *)p2);
	  return 1;
	case DTYPE_DECIMAL:
	  {
	    char buff[2000];
	    strcpy (buff, A4GL_dec_to_str (p1, 0));
	    sscanf (buff, "%lld", (int8 *) p2);
		A4GL_debug("p2=%lld\n",*(int8 *)p2);
	  }
	  return 1;
	case DTYPE_CHAR:
	  sscanf (p1, "%lld", (int8 *) p2);
		A4GL_debug("p2=%lld\n",*(int8 *)p2);
	  return 1;


	}
    }
  return 0;


}
void add_int8_support(void) {
	A4GL_debug("Has int8_support");
	A4GL_add_datatype_function_i (DTYPE_INT8, "INIT", (void *)A4GL_null_int8);
	A4GL_add_datatype_function_i (DTYPE_INT8, "ISNULL", (void *)A4GL_isnull_int8); //
	A4GL_add_datatype_function_i (DTYPE_INT8, "SETDTYPE", (void *)A4GL_zero_int8); // Invalid conversion set it to 0
	A4GL_add_datatype_function_i (DTYPE_INT8, "DISPLAY", (void *)A4GL_display_int8); 
	A4GL_add_datatype_function_i (DTYPE_INT8, "COPY", (void *)A4GL_copy_int8); 
	A4GL_add_datatype_function_i (DTYPE_INT8, "CONVTO_17", (void *)A4GL_conv_int8); 

	A4GL_add_datatype_function_i (DTYPE_FLOAT, "CONVTO_17", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_DECIMAL,  "CONVTO_17", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_INT,  "CONVTO_17", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_SMINT,  "CONVTO_17", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_SMFLOAT,  "CONVTO_17", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_CHAR,  "CONVTO_17", (void *)A4GL_conv_int8); 


	A4GL_add_datatype_function_i (DTYPE_INT8,  "CONVTO_5", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_INT8,  "CONVTO_3", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_INT8,  "CONVTO_1", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_INT8,  "CONVTO_2", (void *)A4GL_conv_int8); 


	A4GL_add_op_function (DTYPE_SMINT, 	DTYPE_INT8, OP_MATH, A4GL_smint_int8_ops);
	A4GL_add_op_function (DTYPE_INT, 	DTYPE_INT8, OP_MATH, A4GL_int_int8_ops);
	A4GL_add_op_function (DTYPE_FLOAT, 	DTYPE_INT8, OP_MATH, A4GL_float_int8_ops);
	A4GL_add_op_function (DTYPE_SMFLOAT, 	DTYPE_INT8, OP_MATH, A4GL_smfloat_int8_ops);
	A4GL_add_op_function (DTYPE_DECIMAL, 	DTYPE_INT8, OP_MATH, A4GL_int8dec_ops);

	A4GL_add_op_function (DTYPE_INT8,DTYPE_SMINT, 	OP_MATH, A4GL_int8_smint_ops);
	A4GL_add_op_function (DTYPE_INT8,DTYPE_INT, 	OP_MATH, A4GL_int8_int_ops);
	A4GL_add_op_function (DTYPE_INT8,DTYPE_FLOAT, 	 OP_MATH, A4GL_int8_float_ops);
	A4GL_add_op_function (DTYPE_INT8,DTYPE_SMFLOAT, OP_MATH, A4GL_int8_smfloat_ops);
	A4GL_add_op_function (DTYPE_INT8,DTYPE_DECIMAL,  OP_MATH, A4GL_int8dec_ops);

	A4GL_add_op_function (DTYPE_INT8,DTYPE_INT8,  OP_MATH, A4GL_int8_int8_ops);

}

#endif
