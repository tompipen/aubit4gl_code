/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: ops.c,v 1.71 2005-02-10 16:02:52 pjfalbe Exp $
#
*/

/**
 * @file
 * Data type operations functions
 *
 * This is complex stuff
 * What we want to be able to do is add datatypes programatically
 * We therefor maintain a list of available datatypes
 * and their various conversion routines..
 *
 * This is very much a work in progress....
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_libaubit4gl_int.h"

//static char *make_using (char *ptr);
void A4GL_date_date_ops (int op);
void A4GL_date_int_ops (int op);
void A4GL_int_date_ops (int op);
double trunc(double f);
void A4GL_smfloat_float_ops (int op);
void A4GL_float_smfloat_ops (int op);
void A4GL_smfloat_smfloat_ops (int op);
void
A4GL_add_op_function (int dtype1, int dtype2, int op, void (*function)(int ops));

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_int_int_ops (int op);
int A4GL_dectos (void *z, void *w, int size);
char * make_using_tostring (char *ptr, int d, int n);

#ifdef OLD_INCL
void A4GL_push_long (long a);
void A4GL_push_int (int a);
#endif
void A4GL_add_default_operations (void);
void A4GL_dt_in_ops (int op);
void A4GL_in_dt_ops (int op);
void A4GL_decode_datetime (struct A4GLSQL_dtime *d, int *data);
//void A4GL_ltrim(char *s) ;
void A4GL_dt_dt_ops (int op);
//int A4GL_ctodt (void *a, void *b, int size);
//int A4GL_ctoint (void *a, void *b, int size);
//static char *make_using_tostring (char *ptr, int d, int n);


char *A4GL_display_int (void *ptr, int size, int size_c,
			struct struct_scr_field *field_details,
			int display_type);
char *A4GL_display_smint (void *ptr, int size, int size_c,
			  struct struct_scr_field *field_details,
			  int display_type);
char *A4GL_display_float (void *ptr, int size, int size_c,
			  struct struct_scr_field *field_details,
			  int display_type);
char *A4GL_display_smfloat (void *ptr, int size, int size_c,
			    struct struct_scr_field *field_details,
			    int display_type);
char *A4GL_display_date (void *ptr, int size, int size_c,
			 struct struct_scr_field *field_details,
			 int display_type);
char *A4GL_display_char (void *ptr, int size, int size_c,
			 struct struct_scr_field *field_details,
			 int display_type);
char *A4GL_display_decimal (void *ptr, int size, int size_c,
			    struct struct_scr_field *field_details,
			    int display_type);
char *A4GL_display_money (void *ptr, int size, int size_c,
			  struct struct_scr_field *field_details,
			  int display_type);
char *A4GL_display_dtime (void *ptr, int size, int size_c,
			  struct struct_scr_field *field_details,
			  int display_type);
char *A4GL_display_interval (void *ptr, int size, int size_c,
			     struct struct_scr_field *field_details,
			     int display_type);
char *A4GL_display_byte (void *ptr, int size, int size_c,
			 struct struct_scr_field *field_details,
			 int display_type);
char *A4GL_display_text (void *ptr, int size, int size_c,
			 struct struct_scr_field *field_details,
			 int display_type);


static char *make_using_sz (char *ptr, int sz, int dig, int dec);
char *A4GL_tostring_decimal (void *p, int size, char *s_in, int n_in);

void A4GL_in_date_ops (int op);
int A4GL_days_in_month (int m, int y);
#define NUM_DIG(x)               ((x[0])&127 )
#define NUM_DEC(x)               ((x[1]))




/*
=====================================================================
                    Functions definitions
=====================================================================

*/

char *
A4GL_tostring_decimal (void *p, int size, char *s_in, int n_in)
{
  static char buff_1[256];
//int n,l;
//fgldecimal *p_d;
  char *ptr2;
//int size_c;
  char *ptr;

  ptr2 = p;
  if (s_in != 0 || n_in != 0)
    {
      A4GL_debug ("EXPECTING s_in=0 and n_in=0\n");
      return 0;
    }

  if (A4GL_isnull (DTYPE_DECIMAL, ptr2))
    {
      int n;
      n = size >> 8;
      if (size & 255)
	n++;
      memset (buff_1, ' ', n);
      buff_1[n] = 0;
      return buff_1;
    }

//size=(NUM_DIG(ptr2)<<8)+NUM_DEC(ptr2);
  A4GL_push_dec (p, 0, size);

//n=NUM_DIG(ptr2);
//l=NUM_DEC(ptr2);
//size_c=n;
//if (l) size_c++;


  ptr = make_using_tostring (ptr2, size >> 8, size & 255);	//,size_c,n*2,l);
  A4GL_debug ("Make using returns %s", ptr);
  A4GL_push_char (ptr);
  A4GL_pushop (OP_USING);
  ptr = A4GL_char_pop ();
  strcpy (buff_1, ptr);
  free (ptr);
  return buff_1;
}



/**
 *
 *
 * @return
 */
void A4GL_smfloat_smfloat_ops (int op)
{
  float a;
  float b;
  double dc;
  float d;

  b = A4GL_pop_float ();
  a = A4GL_pop_float ();
A4GL_debug("smfloat smfloat\n");
A4GL_debug("%f %f\n",a,b);
  if (A4GL_isnull (DTYPE_SMFLOAT, (void *) &a)
      || A4GL_isnull (DTYPE_SMFLOAT, (void *) &b))
    {
      A4GL_debug ("int_int - one is null");
      A4GL_push_null (DTYPE_SMFLOAT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      A4GL_push_float (a + b);
      return;
    case OP_SUB:
      A4GL_push_float ((a - b));
      return;
    case OP_MULT:
      A4GL_push_double ((double)(a * b));
      return;


    case OP_DIV:
	  A4GL_push_double ((double) a / (double) b);

    case OP_MOD:
      A4GL_push_long ((int)a % (int)b);
      return;

    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_float (a);
	  return;
	}

      dc = a;
      for (d = 1; d < b; d++) dc *= (double) a;
      A4GL_push_double (dc);
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

/**
 *
 *
 * @return
 */
void A4GL_float_smfloat_ops (int op)
{
  double a;
  float b;
  double c;
  float d;

  b = A4GL_pop_float ();
  a = A4GL_pop_double ();
A4GL_debug("float smfloat\n");
A4GL_debug("%f %f\n",a,b);
  if (A4GL_isnull (DTYPE_SMFLOAT, (void *) &a)
      || A4GL_isnull (DTYPE_SMFLOAT, (void *) &b))
    {
      A4GL_debug ("int_int - one is null");
      A4GL_push_null (DTYPE_SMFLOAT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      A4GL_push_double (a + b);
      return;
    case OP_SUB:
      A4GL_push_double ((a - b));
      return;
    case OP_MULT:
      A4GL_push_double ((double)(a * b));
      return;


    case OP_DIV:
	  A4GL_push_double ((double) a / (double) b);

    case OP_MOD:
      A4GL_push_long ((int)a % (int)b);
      return;

    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_double (a);
	  return;
	}

      c = a;

      for (d = 1; d < b; d++)
	c *= a;
      A4GL_push_double (c);
      return;

    case OP_LESS_THAN:
      A4GL_push_int ((float)a < (float)b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int ((float)a > (float)b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int ((float)a <= (float)b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int ((float)a >= (float)b);
      return;
    case OP_EQUAL:
      A4GL_push_int ((float)a == (float)b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int ((float)a != (float)b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/**
 *
 *
 * @return
 */
void A4GL_smfloat_float_ops (int op)
{
  float a;
  double b;
  double c;
  float d;

  b = A4GL_pop_double ();
  a = A4GL_pop_float ();
A4GL_debug("smfloat float\n");
A4GL_debug("%f %f\n",a,b);
  if (A4GL_isnull (DTYPE_SMFLOAT, (void *) &a)
      || A4GL_isnull (DTYPE_SMFLOAT, (void *) &b))
    {
      A4GL_debug ("int_int - one is null");
      A4GL_push_null (DTYPE_SMFLOAT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      A4GL_push_double (a + b);
      return;
    case OP_SUB:
      A4GL_push_double ((a - b));
      return;
    case OP_MULT:
      A4GL_push_double ((double)(a * b));
      return;


    case OP_DIV:
	  A4GL_push_double ((double) a / (double) b);

    case OP_MOD:
      A4GL_push_long ((int)a % (int)b);
      return;

    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_double (a);
	  return;
	}

      c = a;

      for (d = 1; d < b; d++)
	c *= (double)a;
      A4GL_push_double (c);
      return;

    case OP_LESS_THAN:
      A4GL_push_int ((float)a < (float)b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int ((float)a > (float)b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int ((float)a <= (float)b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int ((float)a >= (float)b);
      return;
    case OP_EQUAL:
      A4GL_push_int ((float)a == (float)b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int ((float)a != (float)b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/* ========================== EOF ========================== */



/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_dt_in_ops (int op)
{
  struct A4GLSQL_dtime dt;
  struct ival in;
  int ival_data[10];

#ifdef DEBUG
  A4GL_debug ("In dt_in_ops");
#endif
  //printf("DTIN Here\n");
  //fflush(stdout);
  A4GL_pop_param (&in, DTYPE_INTERVAL, -1);
  A4GL_pop_param (&dt, DTYPE_DTIME, -1);
  //printf("DTIN Here2\n");
  //fflush(stdout);

  A4GL_decode_interval (&in, &ival_data[0]);
  //printf("Interval : Y=%d\n",ival_data[0]);
  //printf("Interval : M=%d\n",ival_data[1]);

  //printf("Interval : D=%d\n",ival_data[2]);
  //printf("Interval : H=%d\n",ival_data[3]);
  //printf("Interval : M=%d\n",ival_data[4]);
  //printf("Interval : S=%d\n",ival_data[5]);
  //printf("Interval : F=%d\n",ival_data[6]);
  fflush (stdout);
  A4GL_push_int (0);
}


void
A4GL_in_date_ops (int op)
{
  struct ival *pi;
  int x_date;
  //struct A4GLSQL_dtime *pd;
  int d1;
  int d2;
  int s1;
  int s2;
  struct A4GLSQL_dtime dt;
  struct ival in;

  A4GL_get_top_of_stack (2, &d1, &s1, (void *) &x_date);
  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &pi);

  memset (&in, 0, sizeof (in));
  in.stime = pi->stime;
  in.ltime = pi->ltime;

  dt.stime = 1;
  dt.ltime = 3;
  A4GL_pop_var2 (&in, DTYPE_INTERVAL, in.stime * 16 + in.ltime);
  if (A4GL_isnull (DTYPE_INTERVAL, (void *) &in))
    {
      A4GL_debug ("INTERVAL IS NULL\n");
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_CHAR, 0);
      return;
    }

  A4GL_pop_param (&dt, DTYPE_DTIME, dt.stime * 16 + dt.ltime);
  if (A4GL_isnull (DTYPE_DTIME, (void *) &dt))
    {
      A4GL_debug ("DATE IS NULL\n");
      A4GL_push_null (DTYPE_CHAR, 0);
      return;
    }
  A4GL_push_variable (&dt, 0x13000a);
  A4GL_push_variable (&in,
		      ((in.stime * 16 + in.ltime) < 16) + DTYPE_INTERVAL);
  A4GL_debug_print_stack ();

// Now do it as a datetime/interval...
  A4GL_in_dt_ops (op);

}

/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_in_dt_ops (int op)
{
  struct A4GLSQL_dtime dt;
  struct ival in;
  int ival_data[10];
  int dtime_data[10];
  int d1;
  int d2;
  int s1;
  int mdy_m,mdy_d,mdy_y;
  int s2;

  long dt_days;
  double dt_seconds;
  long in_months;
  //long in_days;
  double in_seconds;


  //void *ptr1;
  struct ival *pi;
  struct A4GLSQL_dtime *pd;
  int ok = 0;
  char buff_2[256];
  int start;
  char *ptr;

  A4GL_debug ("in_dt_ops op=%d",op);
  A4GL_get_top_of_stack (2, &d1, &s1, (void *) &pd);
  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &pi);


  if ((d1 & DTYPE_MASK) != DTYPE_DTIME)
    {
      printf ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_DTIME);
    }

  if ((d2 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      printf ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_INTERVAL);
    }


  memset (&in, 0, sizeof (in));

  if (pi)
    {
      in.stime = pi->stime;
      in.ltime = pi->ltime;
    }

dt.stime=-1;
dt.ltime=-1;

  if (pd)
    {
      dt.stime = pd->stime;
      dt.ltime = pd->ltime;
    }

  A4GL_pop_var2 (&in, DTYPE_INTERVAL, in.stime * 16 + in.ltime);

  if (A4GL_isnull (DTYPE_INTERVAL, (void *) &in))
    {
      A4GL_debug ("INTERVAL IS NULL\n");
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_CHAR, 0);
      return;
    }


  A4GL_setnull(10,&dt,dt.stime*16+dt.ltime);

  A4GL_pop_param (&dt, DTYPE_DTIME, dt.stime * 16 + dt.ltime);

  if (A4GL_isnull (DTYPE_DTIME, (void *) &dt))
    {
      A4GL_debug ("DATETIME IS NULL\n");
      A4GL_push_null (DTYPE_CHAR, 0);
      return;

    }


  A4GL_decode_interval (&in, &ival_data[0]);


	A4GL_debug("\n\nInterval : Y=%d\n",ival_data[0]);
	A4GL_debug("Interval : M=%d\n",ival_data[1]);
	A4GL_debug("Interval : D=%d\n",ival_data[2]);
	A4GL_debug("Interval : H=%d\n",ival_data[3]);
	A4GL_debug("Interval : M=%d\n",ival_data[4]);
	A4GL_debug("Interval : S=%d\n",ival_data[5]);
	A4GL_debug("Interval : F=%d\n",ival_data[6]);



  A4GL_decode_datetime (&dt, &dtime_data[0]);



  A4GL_debug ("Datetime : Y=%d\n", dtime_data[0]);
  A4GL_debug ("Datetime : M=%d\n", dtime_data[1]);
  A4GL_debug ("Datetime : D=%d\n", dtime_data[2]);
  A4GL_debug ("Datetime : H=%d\n", dtime_data[3]);
  A4GL_debug ("Datetime : M=%d\n", dtime_data[4]);
  A4GL_debug ("Datetime : S=%d\n", dtime_data[5]);
  A4GL_debug ("Datetime : F=%d\n", dtime_data[6]);



  dt_days=A4GL_gen_dateno (dtime_data[2], dtime_data[1], dtime_data[0]); // As a date....

  //dt_seconds= (double)dtime_data[2]*24.0*60.0*60.0; // Days
  dt_seconds=0;
  dt_seconds+=(double)dtime_data[3]*60.0*60.0; // Hours
  dt_seconds+=(double)dtime_data[4]*60.0; // Minutes
  dt_seconds+=(double)dtime_data[5];
  dt_seconds+=(double)dtime_data[6]/100000.0 ; // Seconds

  in_months=ival_data[0]*12 + ival_data[1];
  in_seconds=0;


A4GL_debug(":::1 %d %lf %d -  %s",dt_days,dt_seconds,in_months,(op==OP_ADD)?"Add":"Subtract");

  if (in_months) { // We're dealing with month information...
	if (op==OP_ADD) {
		dtime_data[1]+=in_months;
		ok=1;
	}

	if (op==OP_SUB) {
		dtime_data[1]-=in_months;
		ok=1;
	}

	while (dtime_data[1]<1)  {dtime_data[1]+=12;dtime_data[0]--;}
	while (dtime_data[1]>12)  {dtime_data[1]-=12;dtime_data[0]++;}

	if (dtime_data[1]<1||dtime_data[1]>12) {
		A4GL_assertion(1,"Month out of range...");
	}

	if (A4GL_days_in_month (dtime_data[1], dtime_data[0]) < dtime_data[2]) {
		// We've done something like 30/01/2001 -> 30/02/2001 which isn't valid
		A4GL_debug("dim=%d data[2]=%d data[1]=%d data[0]=%d\n",A4GL_days_in_month (dtime_data[1], dtime_data[0]),dtime_data[2],dtime_data[1],dtime_data[0]);
		ok=0;
  		A4GL_push_null (DTYPE_CHAR,0);
		return;
	}
  } 

  if (in_months==0) {
  	in_seconds=(double)ival_data[2]*24.0*60.0*60.0; // Days
  	in_seconds+=(double)ival_data[3]*60.0*60.0; // Hours
  	in_seconds+=(double)ival_data[4]*60.0; // Minutes
  	in_seconds+=ival_data[5]+(double)ival_data[6]/100000.0 ; // Seconds

	A4GL_debug(":::2 %d %lf %d %lf %s",dt_days,dt_seconds,in_months,in_seconds,(op==OP_ADD)?"Add":"Subtract");
	//printf(":::2 %d %lf %d %lf %s\n",dt_days,dt_seconds,in_months,in_seconds,(op==OP_ADD)?"Add":"Subtract");

	if (op==OP_ADD) {
		long d;
		double dt;
		dtime_data[2]=0;
		dtime_data[3]=0;
		dtime_data[4]=0;
		dtime_data[5]=0;
		dtime_data[6]=0;
		ok=1;

		dt_seconds+=in_seconds;
		dt=trunc(dt_seconds);
		d=(long)dt;
		dtime_data[5]=d;
		dt_seconds-=dt-0.000005;
		dt_seconds*=100000;
		d=dt_seconds;
		dtime_data[6]=d;

      		while (dtime_data[6] > 99999) { dtime_data[5]++; dtime_data[6] -= 100000; }
      		while (dtime_data[5] >= 60) { dtime_data[4]++; dtime_data[5] -= 60; }
      		// Minutes
      		while (dtime_data[4] >= 60) { dtime_data[3]++; dtime_data[4] -= 60; }
      		// Hours
      		while (dtime_data[3] >= 24) { dtime_data[2]++; dtime_data[3] -= 24; }


      		// Days

		//printf("Delta for dt_days=%d\n",dtime_data[2]);
		dt_days+=dtime_data[2];

		A4GL_get_date(dt_days,&mdy_d,&mdy_m,&mdy_y);
		dtime_data[2]=mdy_d;
		dtime_data[1]=mdy_m;
		dtime_data[0]=mdy_y;
	

	}	


if (op==OP_SUB) {
		long d;
		double dt;


	dtime_data[2]=0;
	dtime_data[3]=0;
	dtime_data[4]=0;
	ok=1;

	dt_seconds-=in_seconds;
	dt=trunc(dt_seconds);
	d=(long)dt;
	dtime_data[5]=d;
	dt_seconds-=dt-0.000005;
	dt_seconds*=100000;
	d=dt_seconds;
	dtime_data[6]=d;


      if (dtime_data[6] < 0)
	{
	  dtime_data[5]--;
	  dtime_data[6] += 100000;
	  //printf("Carry F\n");
	}

      // Seconds
      while (dtime_data[5] < 0)
	{
	  dtime_data[4]--;
	  dtime_data[5] += 60;	/* printf("Carry S\n"); */
	}


      // Minutes
      while (dtime_data[4] < 0)
	{
	  dtime_data[3]--;
	  dtime_data[4] += 60;	/* printf("Carry M\n"); */
	}


      // Hours
      while (dtime_data[3] < 0)
	{
	  dtime_data[2]--;
	  dtime_data[3] += 24;	/* printf("Carry H\n"); */
	}

      		while (dtime_data[6] > 99999) { dtime_data[5]++; dtime_data[6] -= 100000; }
      		while (dtime_data[5] >= 60) { dtime_data[4]++; dtime_data[5] -= 60; }
      		// Minutes
      		while (dtime_data[4] >= 60) { dtime_data[3]++; dtime_data[4] -= 60; }
      		// Hours
      		while (dtime_data[3] >= 24) { dtime_data[2]++; dtime_data[3] -= 24; }


	dt_days+=dtime_data[2];
		A4GL_get_date(dt_days,&mdy_d,&mdy_m,&mdy_y);
		dtime_data[2]=mdy_d;
		dtime_data[1]=mdy_m;
		dtime_data[0]=mdy_y;




}

  }





























#ifdef OLDWAY
  switch (op)
    {
    case OP_ADD:
      // Fractions
      dtime_data[6] += ival_data[6];





      while (dtime_data[6] > 99999)
	{
	  dtime_data[5]++;
	  dtime_data[6] -= 100000;
	}

      // Seconds
      dtime_data[5] += ival_data[5];
      while (dtime_data[5] >= 60)
	{
	  dtime_data[4]++;
	  dtime_data[5] -= 60;
	}

      // Minutes
      dtime_data[4] += ival_data[4];
      while (dtime_data[4] >= 60)
	{
	  dtime_data[3]++;
	  dtime_data[4] -= 60;
	}

      // Hours
      dtime_data[3] += ival_data[3];
      while (dtime_data[3] >= 24)
	{
	  dtime_data[2]++;
	  dtime_data[3] -= 24;
	}

      // Days
      dtime_data[2] += ival_data[2];
      A4GL_debug ("Day : %d month=%d", dtime_data[2], dtime_data[1]);

      while (dtime_data[2] >
	     A4GL_days_in_month (dtime_data[1], dtime_data[0]))
	{
	  A4GL_debug ("day too high: %d %d m=%d y=%d\n", dtime_data[2],
		      A4GL_days_in_month (dtime_data[1], dtime_data[0]),
		      dtime_data[1], dtime_data[0]);
	  dtime_data[2] -= A4GL_days_in_month (dtime_data[1], dtime_data[0]);
	  dtime_data[1]++;
	  if (dtime_data[1] > 12)
	    {
	      dtime_data[0]++;
	      dtime_data[1] -= 12;
	    }
	}

      A4GL_debug ("Checking months... %d %d", dtime_data[1], ival_data[1]);
      // Months
      dtime_data[1] += ival_data[1];
      while (dtime_data[1] > 12)
	{
	  A4GL_debug ("Change months");
	  dtime_data[0]++;
	  dtime_data[1] -= 12;
	}

      // Years
      dtime_data[0] += ival_data[0];
      ok = 1;
      break;


    case OP_SUB:
      // Fractions
      dtime_data[6] -= ival_data[6];
      if (dtime_data[6] < 0)
	{
	  dtime_data[5]--;
	  dtime_data[6] += 100000;
	  //printf("Carry F\n");
	}

      // Seconds
      dtime_data[5] -= ival_data[5];
      while (dtime_data[5] < 0)
	{
	  dtime_data[4]--;
	  dtime_data[5] += 60;	/* printf("Carry S\n"); */
	}

      // Minutes
      dtime_data[4] -= ival_data[4];
      while (dtime_data[4] < 0)
	{
	  dtime_data[3]--;
	  dtime_data[4] += 60;	/* printf("Carry M\n"); */
	}

      // Hours
      dtime_data[3] -= ival_data[3];
      while (dtime_data[3] < 0)
	{
	  dtime_data[2]--;
	  dtime_data[3] += 24;	/* printf("Carry H\n"); */
	}

      if (dt.stime <= 3)
	{
	  // Days
	  dtime_data[2] -= ival_data[2];
	  while (dtime_data[2] <= 1)
	    {
	      dtime_data[1]--;
	      if (dtime_data[1] < 1)
		{
		  dtime_data[1] = 12;
		  dtime_data[0]--;
		}
	      dtime_data[2] +=
		A4GL_days_in_month (dtime_data[1], dtime_data[0]);
	    }
	}
      if (dt.stime <= 2)
	{
	  A4GL_debug ("CHECKING MONTHS.. %d %d", dtime_data[1], ival_data[1]);
	  // Months
	  dtime_data[1] -= ival_data[1];
	  while (dtime_data[1] < 1)
	    {
	      dtime_data[0]--;
	      dtime_data[1] = 12;	/*printf("Carry M\n"); */
	    }
	}

      if (dt.stime <= 1)
	{
	  // Years
	  dtime_data[0] -= ival_data[0];
	}


      ok = 1;
      break;
    }

#endif


//printf("ok=%d\n",ok);




  if (ok)
    {
      A4GL_debug ("Datetime : Y=%d\n", dtime_data[0]);
      A4GL_debug ("Datetime : M=%d\n", dtime_data[1]);
      A4GL_debug ("Datetime : D=%d\n", dtime_data[2]);
      A4GL_debug ("Datetime : H=%d\n", dtime_data[3]);
      A4GL_debug ("Datetime : M=%d\n", dtime_data[4]);
      A4GL_debug ("Datetime : S=%d\n", dtime_data[5]);
      A4GL_debug ("Datetime : F=%d\n", dtime_data[6]);

      A4GL_debug ("I reckon thats ok...");
      sprintf (buff_2, "%04d-%02d-%02d %02d:%02d:%02d.%05d",
	       dtime_data[0],
	       dtime_data[1],
	       dtime_data[2],
	       dtime_data[3], dtime_data[4], dtime_data[5], dtime_data[6]);

	//printf("buff_2=%s\n",buff_2);
      A4GL_debug ("Buff = %s", buff_2);
      start = 0;
      if (dtime_data[0] > 0 && !start)
	start = 1;
      if (dtime_data[1] > 0 && !start)
	start = 2;
      if (dtime_data[2] > 0 && !start)
	start = 3;
      if (dtime_data[3] > 0 && !start)
	start = 4;
      if (dtime_data[4] > 0 && !start)
	start = 4;
      if (dtime_data[5] > 0 && !start)
	start = 4;
      if (dtime_data[6] > 0 && !start)
	start = 4;


      //0123456789012345678901234
      //0000-MM-30 23:57:10.00000
      ptr = 0;
      switch (start)
	{
	case 1:
	  ptr = &buff_2[0];
	  break;
	case 2:
	  ptr = &buff_2[5];
	  break;
	case 3:
	  ptr = &buff_2[8];
	  break;
	case 4:
	  ptr = &buff_2[11];
	  break;
	case 5:
	  ptr = &buff_2[14];
	  break;
	case 6:
	  ptr = &buff_2[17];
	  break;
	case 7:
	  ptr = &buff_2[18];
	  break;
	}
      if (ptr == 0)
	{
	  A4GL_assertion (1,"Internal error in_dt_ops");
	  return;
	}

      dt.stime = start;
      //dt.ltime=11;

/*
		switch(dt.ltime) {
			case 1: buff_2[4]=0;break; //Y
			case 2: buff_2[7]=0;break; //M
			case 3: buff_2[10]=0;break; //D
			case 4: buff_2[13]=0;break; //H
			case 5: buff_2[16]=0;break; //M
			case 6: buff_2[19]=0;break; //D
		}
*/

      if (A4GL_ctodt (ptr, &dt, dt.stime * 16 + dt.ltime))
	{
	  A4GL_push_dtime (&dt);
	}
      else
	{
	  A4GL_push_null (DTYPE_DTIME, dt.stime * 16 + dt.ltime);
	}
      return;
    }



  A4GL_push_int (0);		// Or maybe push a null...
  //A4GL_push_null (DTYPE_CHAR,0);
}


/**
 *
 *
 * @return
 */
void
A4GL_int_int_ops (int op)
{
  long a;
  long b;
  long c;
  double dc;
  long d;

  b = A4GL_pop_long ();
  a = A4GL_pop_long ();

  if (A4GL_isnull (DTYPE_INT, (void *) &a)
      || A4GL_isnull (DTYPE_INT, (void *) &b))
    {
      A4GL_debug ("int_int - one is null");
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      A4GL_push_long (a + b);
      return;
    case OP_SUB:
      A4GL_push_long (a - b);
      return;
    case OP_MULT:
      A4GL_push_long (a * b);
      return;


    case OP_DIV:
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  A4GL_push_double ((double) a / (double) b);
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

      dc = a;
	c=a;
      for (d = 1; d < b; d++) {
	dc *= a;
	c*=a;
	}
	if ((c>0 && c<1000000000) || (c<0 && c>-1000000000 )) A4GL_push_long(c);
	else A4GL_push_double (dc);
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

void
A4GL_date_date_ops (int op)
{
  long a;
  long b;
  long c;
  long d;

  b = A4GL_pop_long ();
  a = A4GL_pop_long ();

  A4GL_debug ("MATH ROUTINE : date_date");
  if (A4GL_isnull (DTYPE_INT, (void *) &a)
      || A4GL_isnull (DTYPE_INT, (void *) &b))
    {
      A4GL_debug ("int_int - one is null");
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
	a+=b;
	if (a<=2958464) A4GL_push_date (a);
	else A4GL_push_date(0);
	
      return;
    case OP_SUB:
      A4GL_push_long (a - b);
      return;
    case OP_MULT:
      A4GL_push_long (a * b);
      return;


    case OP_DIV:
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  A4GL_push_double ((double) a / (double) b);
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

void
A4GL_date_char_ops (int op)
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
  strncpy(buff,ptr,255);
  buff[255]=0;

  if (A4GL_isnull (DTYPE_INT, (void *) &a) || A4GL_isnull (DTYPE_CHAR, (void *) &ptr))
    {
      free(ptr);
      A4GL_debug ("int_date - one is null");
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }

  free(ptr);


  // Comparisons would normally be to another date....
  if (op==OP_LESS_THAN|| op== OP_GREATER_THAN|| op== OP_LESS_THAN_EQ|| op== OP_GREATER_THAN_EQ|| op== OP_EQUAL|| op== OP_NOT_EQUAL) {
		// Firstly - is our string a date ?
  		was_ok=A4GL_conversion_ok(-1);
  		A4GL_conversion_ok(1);
  		A4GL_push_char(buff);
  		c=A4GL_pop_date();
  		if (!A4GL_conversion_ok()||A4GL_isnull(DTYPE_DATE,(void *)&c))  { // Its not a date..
			// Try as an integer ?
			A4GL_push_char(buff);
			b=A4GL_pop_long();
  		} else {
			b=c;
		}
		
  		A4GL_conversion_ok(was_ok);
    } else {
		A4GL_push_char(buff);
		b=A4GL_pop_long();

    }

  switch (op)
    {
    case OP_ADD:
	a+=b;
	if (a<=2958464) A4GL_push_date (a);
	else A4GL_push_date(0);

      return;
    case OP_SUB:
      A4GL_push_date (a - b);
      return;
    case OP_MULT:
      A4GL_push_date (a * b);
      return;


    case OP_DIV:
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  A4GL_push_double ((double) a / (double) b);
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



void
A4GL_date_int_ops (int op)
{
  long a;
  long b;
  long c;
  long d;



  b = A4GL_pop_long ();
  a = A4GL_pop_long ();

  A4GL_debug ("MATH ROUTINE : date_int %d %d", a, b);

  if (A4GL_isnull (DTYPE_INT, (void *) &a)
      || A4GL_isnull (DTYPE_INT, (void *) &b))
    {
      A4GL_debug ("int_date - one is null");
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
	a+=b;
	if (a<=2958464) A4GL_push_date (a);
	else A4GL_push_date(0);

      return;
    case OP_SUB:
      A4GL_push_date (a - b);
      return;
    case OP_MULT:
      A4GL_push_date (a * b);
      return;


    case OP_DIV:
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  A4GL_push_double ((double) a / (double) b);
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


void
A4GL_int_date_ops (int op)
{
  long a;
  long b;
  long c;
  long d;

  b = A4GL_pop_long ();
  a = A4GL_pop_long ();

  A4GL_debug ("MATH ROUTINE : int_date");

  if (A4GL_isnull (DTYPE_INT, (void *) &a)
      || A4GL_isnull (DTYPE_INT, (void *) &b))
    {
      A4GL_debug ("int_int - one is null");
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      A4GL_push_date (a + b);
      return;
    case OP_SUB:
      A4GL_push_date (a - b);
      return;
    case OP_MULT:
      A4GL_push_date (a * b);
      return;


    case OP_DIV:
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  A4GL_push_double ((double) a / (double) b);
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

/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_in_in_ops (int op)
{
  struct ival in2;
  struct ival in1;
  int ival_data1[10];
  int ival_data2[10];
  int d1, d2;
  int s1, s2;
  //void *ptr1;
  struct ival *pi1;
  struct ival *pi2;
  struct ival in;
  //int ok = 0;
  //char buff[256];
  //int start;
  //char *ptr;
  int se1;
  int se2;
  double d_i1;
  double d_i2;
  int a;
  for (a=0;a<10;a++) {
		ival_data1[a]=0;
		ival_data2[a]=0;
	}

  A4GL_debug ("in_in_ops - op=%d", op);
// d2 op d1
  A4GL_get_top_of_stack (2, &d2, &s2, (void *) &pi2);
  A4GL_get_top_of_stack (1, &d1, &s1, (void *) &pi1);


  if ((d1 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      printf ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_INTERVAL);
    }

  if ((d2 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      printf ("Confused... %d != %d\n", d2 & DTYPE_MASK, DTYPE_INTERVAL);
    }

  A4GL_assertion(pi1==0,"First interval is 0");
  A4GL_assertion(pi2==0,"Second interval is 0");

  se1 = pi1->stime & 0xf;
  se2 = pi2->stime & 0xf;
  se1 = 6;
  se2 = 6;
  if (se1 == 1 || se1 == 2)
    {
      se1 = 2;
    }
  if (se2 == 1 || se2 == 2)
    {
      se2 = 2;
    }

  if (se1 != se2)
    {
      A4GL_exitwith ("Can't use interval YEAR-MONTH and DAY-FRACTION together");
      return;
    }

  A4GL_debug ("se1=%d\n", se1);
  if (se1 == 2)
    {
      in1.stime = 0x82;		// MONTH(8)
      in1.ltime = 2;		// MONTH
      in2.stime = 0x82;
      in2.ltime = 2;
      in.stime = in1.stime;
      in.ltime = in1.ltime;

    }
  else
    {
      in1.stime = 0x86;		// SECOND(8)
      in1.ltime = 11;		// FRACTION(5)
      in2.stime = 0x86;
      in2.ltime = 11;
      in.stime = in1.stime;
      in.ltime = in1.ltime;
    }

  A4GL_debug("in_in.....");
  A4GL_debug_print_stack();
  A4GL_pop_param (&in1, DTYPE_INTERVAL, in1.stime * 16 + in1.ltime);
  A4GL_pop_param (&in2, DTYPE_INTERVAL, in1.stime * 16 + in2.ltime);
  if (in1.stime==0 || in1.ltime==0 || in2.stime==0 || in2.ltime==0) {
		A4GL_assertion(1,"Interval looks empty");
  }

  A4GL_decode_interval (&in1, ival_data1);
  A4GL_decode_interval (&in2, ival_data2);

  if (se1 == 2)
    {
      d_i1 = (double) ival_data1[1];
      d_i2 = (double) ival_data2[1];
    }
  else
    {
      double df1;
      double df2;
      d_i1 = (double) ival_data1[5];
      d_i2 = (double) ival_data2[5];

      df1 = (double) ival_data1[6];
      df2 = (double) ival_data2[6];
      df1 /= 100000.0;
      df2 /= 100000.0;
      d_i1 += df1;
      d_i2 += df2;
      A4GL_debug ("d_i1=%f d_i2=%f", d_i1, d_i2);
    }


  switch (op)
    {
    case OP_ADD:
      d_i1 = d_i2 + d_i1;
      if (se1 == 2)
	{
	  char buff_3[256];
	  sprintf (buff_3, "%f", d_i1);
	  acli_interval (buff_3, 0x822);
	  return;
	}
      else
	{
	  char buff_4[256];
	  sprintf (buff_4, "%f", d_i1);
	  A4GL_debug ("Converting : %s to interval second to second", buff_4);
	  acli_interval (buff_4, 0x867);	// was 866
	  return;
	}



    case OP_SUB:
      d_i1 = d_i2 - d_i1;
      if (se1 == 2)
	{
	  char buff_5[256];
	  sprintf (buff_5, "%f", d_i1);
	  acli_interval (buff_5, 0x822);
	  return;
	}
      else
	{
	  char buff_6[256];
	  sprintf (buff_6, "%f", d_i1);
	  A4GL_debug ("Converting : %s to interval second to second", buff_6);
	  acli_interval (buff_6, 0x867);	// Was 866
	  return;
	}



    case OP_MULT:		// Multiplying two Intervals ?
      A4GL_exitwith ("You can't multiply two intervals...");
      return;


    case OP_DIV:
      d_i1 = d_i2 / d_i1;
      A4GL_push_double (d_i1);	// This should be a number - not an interval
      return;

    case OP_MOD:
      A4GL_exitwith ("You can't mod two intervals...");
      return;

    case OP_POWER:
      A4GL_exitwith ("You can't raise the power of intervals...");
      return;

    case OP_LESS_THAN:
      A4GL_push_int (d_i2 < d_i1);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (d_i2 > d_i1);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (d_i2 <= d_i1);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (d_i2 >= d_i1);
      return;
    case OP_EQUAL:
      A4GL_push_int (d_i2 == d_i1);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (d_i2 != d_i1);
      return;
    }

  printf ("In in_in_ops.... op=%x d_i1=%f d_i2=%f\n", op, d_i1, d_i2);

  A4GL_assertion (1, "in_in - not implemented yet...");

}




/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_dt_dt_ops (int op)
{
  struct A4GLSQL_dtime dt2;
  struct A4GLSQL_dtime dt1;
  int dtime_data1[10];
  int dtime_data2[10];
  int d1, d2;
  int s1, s2;
  //void *ptr1;
  struct A4GLSQL_dtime *pi;
  struct A4GLSQL_dtime *pd;
  struct ival in;
  //int ok = 0;
  char buff_7[256];
  //int start;
  //char *ptr;
  //double d_d1;
  //double d_d2;

  memset(&in,0,sizeof(in));
  if (op != (OP_SUB) && op != (OP_EQUAL) && op != (OP_NOT_EQUAL)
      && op != (OP_LESS_THAN) && op != (OP_GREATER_THAN)
      && op != (OP_LESS_THAN_EQ) && op != (OP_GREATER_THAN_EQ))
    {

      A4GL_drop_param ();
      A4GL_drop_param ();

      A4GL_debug
	("Can only subtract, ==, != , <, <=, >,>= datetimes at the minute...");
      A4GL_push_int (0);
      return;
    }

// d2 - d1
  A4GL_get_top_of_stack (2, &d1, &s1, (void *) &pd);
  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &pi);


  if ((d1 & DTYPE_MASK) != DTYPE_DTIME)
    {
      printf ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_DTIME);
    }


  if (A4GL_isnull (DTYPE_DTIME, (void *) pd))
    {
      // First is null...
      A4GL_drop_param ();
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }


  if (A4GL_isnull (DTYPE_DTIME, (void *) pi))
    {
      // Second is null...
      A4GL_drop_param ();
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }

  dt1.stime = pi->stime;
  dt1.ltime = pi->ltime;

  dt2.stime = pd->stime;
  dt2.ltime = pd->ltime;

  A4GL_pop_param (&dt1, DTYPE_DTIME, dt1.stime * 16 + dt1.ltime);
  A4GL_pop_param (&dt2, DTYPE_DTIME, dt2.stime * 16 + dt2.ltime);


  A4GL_decode_datetime (&dt1, &dtime_data1[0]);
  A4GL_decode_datetime (&dt2, &dtime_data2[0]);

  A4GL_debug ("Dtime1=%d %d %d %d %d %d %d",
	      dtime_data1[0],
	      dtime_data1[1],
	      dtime_data1[2],
	      dtime_data1[3], dtime_data1[4], dtime_data1[5], dtime_data1[6]);

  A4GL_debug ("Dtime2=%d %d %d %d %d %d %d",
	      dtime_data2[0],
	      dtime_data2[1],
	      dtime_data2[2],
	      dtime_data2[3], dtime_data2[4], dtime_data2[5], dtime_data2[6]);



  if (op == (OP_EQUAL) || op == (OP_NOT_EQUAL))
    {
      int eq = 1;
      if (dtime_data2[0] != dtime_data1[0])
	eq = 0;
      if (dtime_data2[1] != dtime_data1[1])
	eq = 0;
      if (dtime_data2[2] != dtime_data1[2])
	eq = 0;
      if (dtime_data2[3] != dtime_data1[3])
	eq = 0;
      if (dtime_data2[4] != dtime_data1[4])
	eq = 0;
      if (dtime_data2[5] != dtime_data1[5])
	eq = 0;
      if (dtime_data2[6] != dtime_data1[6])
	eq = 0;

      if (op == (OP_EQUAL))
	{
	  if (eq)
	    A4GL_push_int (1);
	  else
	    A4GL_push_int (0);
	}
      else
	{
	  if (eq)
	    A4GL_push_int (0);
	  else
	    A4GL_push_int (1);
	}
      return;
    }



  if (op == (OP_SUB) || op == (OP_LESS_THAN) || op == (OP_GREATER_THAN)
      || op == (OP_LESS_THAN_EQ) || op == (OP_GREATER_THAN_EQ))
    {
	int s1;
	int s2;

	s1=-1;
	s2=-1;

	if (dtime_data1[0]&&s1==-1) s1=0;
	if (dtime_data1[1]&&s1==-1) s1=1;
	if (dtime_data1[2]&&s1==-1) s1=2;
	if (dtime_data1[3]&&s1==-1) s1=3;
	if (dtime_data1[4]&&s1==-1) s1=4;
	if (dtime_data1[5]&&s1==-1) s1=5;
	if (dtime_data1[6]&&s1==-1) s1=6;

	if (dtime_data2[0]&&s2==-1) s2=0;
	if (dtime_data2[1]&&s2==-1) s2=1;
	if (dtime_data2[2]&&s2==-1) s2=2;
	if (dtime_data2[3]&&s2==-1) s2=3;
	if (dtime_data2[4]&&s2==-1) s2=4;
	if (dtime_data2[5]&&s2==-1) s2=5;
	if (dtime_data2[6]&&s2==-1) s2=6;

/* We need to make sure we're comparing like for like... */
	if (s1>0||s2>0) { dtime_data1[0]=0; dtime_data2[0]=0; }
	if (s1>1||s2>1) { dtime_data1[1]=0; dtime_data2[1]=0; }
	if (s1>2||s2>2) { dtime_data1[2]=0; dtime_data2[2]=0; }
	if (s1>3||s2>3) { dtime_data1[3]=0; dtime_data2[3]=0; }
	if (s1>4||s2>4) { dtime_data1[4]=0; dtime_data2[4]=0; }
	if (s1>5||s2>5) { dtime_data1[5]=0; dtime_data2[5]=0; }
	if (s1>6||s2>6) { dtime_data1[6]=0; dtime_data2[6]=0; }



      A4GL_debug ("Op LT : %d (-%d <%d >%d", op, OP_SUB, OP_LESS_THAN,
		  OP_GREATER_THAN);

      dtime_data2[0] -= dtime_data1[0];	// Y
      dtime_data2[1] -= dtime_data1[1];	//
      dtime_data2[2] -= dtime_data1[2];
      dtime_data2[3] -= dtime_data1[3];
      dtime_data2[4] -= dtime_data1[4];
      dtime_data2[5] -= dtime_data1[5];
      dtime_data2[6] -= dtime_data1[6];

// Borrow some seconds for fractions
      while (dtime_data2[6] < 0)
	{
	  dtime_data2[6] += 100000;
	  dtime_data2[5]--;
	}

// Borrow some minutes for seconds
      while (dtime_data2[5] < 0)
	{
	  dtime_data2[5] += 60;
	  dtime_data2[4]--;
	}

// Borrow some hours for minutes
      while (dtime_data2[4] < 0)
	{
	  dtime_data2[4] += 60;
	  dtime_data2[3]--;
	}

// Borrow some days for some hours..
      while (dtime_data2[3] < 0)
	{
	  dtime_data2[3] += 24;
	  dtime_data2[2]--;
	}

// Borrow some months for some days. @ FIXME @todo fix days in months
      while (dtime_data2[2] < 0)
	{
	  dtime_data2[2] += A4GL_days_in_month(dtime_data2[1],dtime_data2[0]);
	  dtime_data2[1]--;
	}


      A4GL_debug ("Y %d M %d D %d H %d M %d S %d", dtime_data2[0],
		  dtime_data2[1], dtime_data2[2], dtime_data2[3],
		  dtime_data2[4], dtime_data2[5], dtime_data2[6]);

// Borrow some years for some months.
      while (dtime_data2[1] < 0)
	{
	  dtime_data2[1] += 12;
	  dtime_data2[0]--;
	}

      A4GL_debug ("Y %d M %d D %d H %d M %d S %d", dtime_data2[0],
		  dtime_data2[1], dtime_data2[2], dtime_data2[3],
		  dtime_data2[4], dtime_data2[5], dtime_data2[6]);





      if (op == (OP_SUB))
	{
	  if (dtime_data2[0] || dtime_data2[1] )
	    {
	      // YEAR TO MONTH interval
	      sprintf (buff_7, "%4d-%02d", dtime_data2[0], dtime_data2[1]);

	      A4GL_ctoint (buff_7, &in, 1298);
	      A4GL_push_interval (&in);
	    }
	  else
	    {
	      sprintf (buff_7, "%d %02d:%02d:%02d.%05d", dtime_data2[2],
		       dtime_data2[3], dtime_data2[4], dtime_data2[5],
		       dtime_data2[6]);
	      A4GL_debug ("Got buff as : %s - op=%d\n", buff_7, op);
	      A4GL_ctoint (buff_7, &in, 0x53b);
	      A4GL_debug ("Pushing Interval - %p - s=%x e=%x made from %s",
			  &in, in.stime, in.ltime);
	      A4GL_debug ("Buff = %s %x %x", buff_7);
	      A4GL_push_interval (&in);
	    }
	}
      else
	{
	  int eq;
	  int lt;
	  int gt;
	  eq = 0;
	  lt = 0;
	  gt = 0;

	  if (dtime_data2[0] || dtime_data2[1])
	    {
	      int y;
	      y = dtime_data2[0] * 12 + dtime_data2[1];
	      if (y > 0)
		gt = 1;
	      if (y < 0)
		lt = 1;
	      if (y == 0)
		eq = 1;
	    }
	  else
	    {
	      long d;
	      d = 0;
	      d += dtime_data2[2];
	      d *= 32;
	      d += dtime_data2[3];
	      d *= 24;
	      d += dtime_data2[4];
	      d *= 60;
	      d += dtime_data2[5];
	      if (d > 0)
		gt = 1;
	      if (d == 0)
		eq = 1;
	      if (d < 0)
		lt = 1;
	    }
	  A4GL_debug (" Boolean values ->    %d %d %d", lt, eq, gt);

	  if (op == (OP_LESS_THAN))
	    {
	      if (lt)
		A4GL_push_int (1);
	      else
		A4GL_push_int (0);
	      return;
	    }
	  if (op == (OP_GREATER_THAN))
	    {
	      if (gt)
		A4GL_push_int (1);
	      else
		A4GL_push_int (0);
	      return;
	    }

	  if (op == (OP_LESS_THAN_EQ))
	    {
	      if (lt || eq)
		A4GL_push_int (1);
	      else
		A4GL_push_int (0);
	      return;
	    }
	  if (op == (OP_GREATER_THAN_EQ))
	    {
	      if (gt || eq)
		A4GL_push_int (1);
	      else
		A4GL_push_int (0);
	      return;
	    }

	  A4GL_push_int (0);



	}


    }


}


/*
	display_...
	
	these accept 4 parameters

	ptr  		= pointer to original data
	size 		= size of data (for decimal etc)
	size_c		= size of character string to return into
	field_details 	= pointer to a field (or '0' for a normal 'display')
	display_type	=
				DISPLAY_TYPE_DISPLAY
				DISPLAY_TYPE_DISPLAY_AT
				DISPLAY_TYPE_DISPLAY_TO

		This allows the routine to differenciate between different DISPLAY types...

*/


char *
A4GL_display_int (void *ptr, int size, int size_c,
		  struct struct_scr_field *field_details, int display_type)
{
  long a;
  static char buff_8[256];
  A4GL_debug ("A4GL_display_int..");

  if (display_type == DISPLAY_TYPE_DISPLAY
      || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_INT, ptr))
	{
	  strcpy (buff_8, "           ");
	}
      else
	{
	  a = *(long *) ptr;
	  sprintf (buff_8, "%11ld", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull (DTYPE_INT, ptr))
	{
	  strcpy (buff_8, "");
	}
      else
	{
	  a = *(long *) ptr;
	  sprintf (buff_8, "%ld", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (ptr)
	{
	  A4GL_debug ("DISPLAY_TYPE_DISPLAY_TO : %d", *(int *) ptr);
	}

      if (ptr == 0 || A4GL_isnull (DTYPE_INT, ptr))
	{
	  A4GL_debug ("Int value is null");
	  strcpy (buff_8, "");
	  return buff_8;
	}

      a = *(long *) ptr;

      if (A4GL_isnull (DTYPE_INT, (void *) &a))
	{
	  A4GL_debug ("Int value is null");
	  strcpy (buff_8, "");
	  return buff_8;
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
      A4GL_pop_char (buff_8, size_c);
      A4GL_debug ("display_int Got '%s'", buff_8);
      return buff_8;
    }

  A4GL_debug ("Returning '%s'", buff_8);

  return buff_8;
}

char *
A4GL_display_smint (void *ptr, int size, int size_c,
		    struct struct_scr_field *field_details, int display_type)
{
  short a;
  static char buff_9[256];


  A4GL_debug ("A4GL_display_smint..");

  if (display_type == DISPLAY_TYPE_DISPLAY
      || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_SMINT, ptr))
	{
	  strcpy (buff_9, "      ");
	}
      else
	{
	  a = *(short *) ptr;
	  sprintf (buff_9, "%6d", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull (DTYPE_SMINT, ptr))
	{
	  strcpy (buff_9, "");
	}
      else
	{
	  a = *(short *) ptr;
	  sprintf (buff_9, "%d", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (A4GL_isnull (DTYPE_SMINT, ptr))
	{
	  strcpy (buff_9, "");
	  return buff_9;
	}
      a = *(short *) ptr;
      A4GL_debug ("display_smint a=%d", a);
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
      A4GL_push_int (a);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_9, size_c);
      A4GL_debug ("display_smint Got '%s'", buff_9);
      return buff_9;
    }

  return buff_9;

}

char *
A4GL_display_float (void *ptr, int size, int size_c,
		    struct struct_scr_field *field_details, int display_type)
{
  double a;
  static char buff_10[256];

  if (display_type == DISPLAY_TYPE_DISPLAY
      || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_FLOAT, ptr))
	{
	  strcpy (buff_10, "");
	  return buff_10;
	}
      a = *(double *) ptr;
      sprintf (buff_10, "%14.2f", a);
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      int cnt;
      if (A4GL_isnull (DTYPE_FLOAT, ptr))
	{
	  strcpy (buff_10, "");
	  return buff_10;
	}
      a = *(double *) ptr;
      sprintf (buff_10, "%f", a);
      for (cnt = strlen (buff_10) - 1; cnt > 0; cnt--)
	{
	  if (cnt <= 1)
	    break;
	  if (buff_10[cnt - 1] == '.')
	    break;
	  if (buff_10[cnt] != '0')
	    break;
	  if (buff_10[cnt] == '0')
	    buff_10[cnt] = 0;

	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (A4GL_isnull (DTYPE_FLOAT, ptr))
	{
	  strcpy (buff_10, "");
	  return buff_10;
	}
      a = *(double *) ptr;
      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff,
		  (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  memset (using_buff, '-', 255);
	  using_buff[size_c] = 0;
	  using_buff[size_c - 4] = '&';
	  using_buff[size_c - 3] = '.';
	  using_buff[size_c - 2] = '&';
	  using_buff[size_c - 1] = '&';
	}
      A4GL_push_double (a);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_10, size_c);
      return buff_10;
    }
  return buff_10;

}

char *
A4GL_display_smfloat (void *ptr, int size, int size_c,
		      struct struct_scr_field *field_details,
		      int display_type)
{
  float a;
  static char buff_11[256];

  if (display_type == DISPLAY_TYPE_DISPLAY
      || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_SMFLOAT, ptr))
	{
	  strcpy (buff_11, "");
	  return buff_11;
	}
      a = *(float *) ptr;
      sprintf (buff_11, "%14.2f", a);
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      int cnt;
      if (A4GL_isnull (DTYPE_SMFLOAT, ptr))
	{
	  strcpy (buff_11, "");
	  return buff_11;
	}
      a = *(float *) ptr;
      sprintf (buff_11, "%f", a);
      for (cnt = strlen (buff_11) - 1; cnt > 0; cnt--)
	{
	  if (cnt <= 1)
	    break;
	  if (buff_11[cnt - 1] == '.')
	    break;
	  if (buff_11[cnt] != '0')
	    break;
	  if (buff_11[cnt] == '0')
	    buff_11[cnt] = 0;

	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (A4GL_isnull (DTYPE_SMFLOAT, ptr))
	{
	  strcpy (buff_11, "");
	  return buff_11;
	}
      a = *(float *) ptr;
      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff,
		  (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  memset (using_buff, '-', 255);
	  using_buff[size_c] = 0;
	  using_buff[size_c - 4] = '&';
	  using_buff[size_c - 3] = '.';
	  using_buff[size_c - 2] = '&';
	  using_buff[size_c - 1] = '&';
	}
      A4GL_push_float (a);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_11, size_c);
    }

  return buff_11;

}

char *
A4GL_display_date (void *ptr, int size, int size_c,
		   struct struct_scr_field *field_details, int display_type)
{
  long a;
  static char buff_12[256];

  if (A4GL_isyes (acl_getenv ("IGNORE_DATEFMT")))
    {
      return 0;
    }


  A4GL_debug ("A4GL_display_date..");

  if (display_type == DISPLAY_TYPE_DISPLAY
      || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_DATE, ptr))
	{
	  strcpy (buff_12, "          ");
	}
      else
	{
	  a = *(long *) ptr;
	  A4GL_push_date (a);
	  if (size_c > 0)
	    {
	      A4GL_pop_char (buff_12, size_c);
	    }
	  else
	    {
	      char *ptr;
	      ptr = A4GL_char_pop ();
	      strcpy (buff_12, ptr);
	      free (ptr);
	    }
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull (DTYPE_INT, ptr))
	{
	  strcpy (buff_12, "");
	}
      else
	{
	  a = *(long *) ptr;
	  A4GL_push_date (a);
	  if (size_c > 0)
	    {
	      A4GL_pop_char (buff_12, size_c);
	    }
	  else
	    {
	      char *ptr;
	      ptr = A4GL_char_pop ();
	      strcpy (buff_12, ptr);
	      free (ptr);
	    }
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (ptr)
	{
	  A4GL_debug ("DISPLAY_TYPE_DISPLAY_TO : DATE(%d)", *(int *) ptr);
	}

      if (ptr == 0 || A4GL_isnull (DTYPE_INT, ptr))
	{
	  A4GL_debug ("Date value is null");
	  strcpy (buff_12, "");
	  return buff_12;
	}

      a = *(long *) ptr;

      if (A4GL_isnull (DTYPE_DATE, (void *) &a))
	{
	  A4GL_debug ("Date value is null");
	  strcpy (buff_12, "");
	  return buff_12;
	}

      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff,
		  (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	  A4GL_push_date (a);
	  A4GL_push_char (using_buff);
	  A4GL_pushop (OP_USING);
	  A4GL_pop_char (buff_12, size_c);
	}
      else
	{
	  char *ptr;
	  A4GL_push_date (a);
	  ptr = A4GL_char_pop ();
	  sprintf (buff_12, ptr);
	  free (ptr);
	}

      A4GL_debug ("display_date Got '%s'", buff_12);
      return buff_12;
    }

  A4GL_debug ("Returning '%s'", buff_12);

  return buff_12;
}

char *
A4GL_display_char (void *ptr, int size, int size_c,
		   struct struct_scr_field *field_details, int display_type)
{
  return 0;
}

char *
A4GL_display_decimal (void *ptr, int size, int size_c,
		      struct struct_scr_field *field_details,
		      int display_type)
{
  static char s_x0[256];
  static char buff_13[256];

  A4GL_debug ("Display_decimal size=%d", size);
  //if (size_c==-1) { return 0; }

  if (display_type == DISPLAY_TYPE_DISPLAY
      || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_DECIMAL, ptr))
	{
	  strcpy (buff_13, "");
	  return buff_13;
	}
      A4GL_push_dec (ptr, 0, size);


      if (size_c == -1)
	{
	  char *ptr2=0;
	  int n, l;
	  //char buff[256];
	  //char buff2[256];
	  ptr2 = ptr;
	  n = NUM_DIG (ptr2);
	  l = NUM_DEC (ptr2);
	  n = n - l + 1;
	  size_c = n + 1;
	}

//A4GL_debug("Calling make_using.. ptr=%p");
      A4GL_push_char (make_using_tostring (ptr, size >> 8, size & 255));
      A4GL_pushop (OP_USING);
      ptr = A4GL_char_pop ();
      strcpy (s_x0, ptr);
      free (ptr);
      return s_x0;
    }


  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      A4GL_push_dec (ptr, 0, size);
      if (size_c == -1)
	{
	  char *ptr;
	  ptr = A4GL_char_pop ();
	  strcpy (s_x0, ptr);
	  free (ptr);
	}
      else
	{
	  A4GL_pop_char (s_x0, size_c);
	}

      A4GL_trim (s_x0);
      A4GL_ltrim (s_x0);
      return s_x0;
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (A4GL_isnull (DTYPE_DECIMAL, ptr))
	{
	  strcpy (buff_13, "");
	  return buff_13;
	}

      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff,
		  (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  char *ptr2;
	  ptr2 = ptr;
	  //memset(using_buff,'-',255);
	  //using_buff[size_c]=0;
	  //using_buff[size_c-4]='&';
	  //using_buff[size_c-3]='.';
	  //using_buff[size_c-2]='&';
	  //using_buff[size_c-1]='&';
	  strcpy (using_buff,
		  make_using_sz (ptr2, size_c, NUM_DIG (ptr2) * 2,
				 NUM_DEC (ptr2)));
	}
      A4GL_push_dec (ptr, 0, size);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_13, size_c);
      return buff_13;
    }

  return 0;
}

char *
A4GL_display_money (void *ptr, int size, int size_c,
		    struct struct_scr_field *field_details, int display_type)
{
  static char s_x1[256];
  static char buff_14[256];
  char *ubuff;
  int a;

  A4GL_debug ("Display_money");
  //if (size_c==-1) { return 0; }


  if (display_type == DISPLAY_TYPE_DISPLAY
      || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_DECIMAL, ptr))
	{
	  strcpy (buff_14, "");
	  return buff_14;
	}
      A4GL_push_dec (ptr, 1, size);


      if (size_c == -1)
	{
	  char *ptr2;
	  int n, l;
	  //char buff[256];
	  //char buff2[256];
	  ptr2 = ptr;
	  n = NUM_DIG (ptr2);
	  l = NUM_DEC (ptr2);
	  n = n - l + 1;
	  size_c = n + 1;
	  A4GL_debug ("Forcing size : %x", size_c);
	}

      A4GL_debug ("Calling make_using.. ");
      strcpy (buff_14, "-");
      ubuff = make_using_tostring (ptr, size >> 8, size & 255);
      strcat (buff_14, ubuff);
      for (a = strlen (buff_14) - 1; a >= 0; a--)
	{
	  if (buff_14[a] == '-')
	    {
	      buff_14[a] = '$';
	      break;
	    }
	}
      //printf("buff=%s\n",buff);
      A4GL_push_char (buff_14);
      //A4GL_push_char(make_using(ptr));
      A4GL_pushop (OP_USING);
      ptr = A4GL_char_pop ();
      strcpy (s_x1, ptr);
      free (ptr);
      return s_x1;
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      A4GL_push_dec (ptr, 1, size);
      if (size_c == -1)
	{
	  char *ptr;
	  ptr = A4GL_char_pop ();
	  strcpy (s_x1, ptr);
	  free (ptr);
	}
      else
	{
	  A4GL_pop_char (s_x1, size_c);
	}

      A4GL_trim (s_x1);
      A4GL_ltrim (s_x1);
      return s_x1;
    }
  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (A4GL_isnull (DTYPE_MONEY, ptr))
	{
	  strcpy (buff_14, "");
	  return buff_14;
	}
      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff,
		  (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  char *ptr2;
	  ptr2 = ptr;
	  //memset(using_buff,'-',255);
	  //using_buff[size_c]=0;
	  //using_buff[size_c-4]='&';
	  //using_buff[size_c-3]='.';
	  //using_buff[size_c-2]='&';
	  //using_buff[size_c-1]='&';
	  strcpy (using_buff,
		  make_using_sz (ptr2, size_c, NUM_DIG (ptr2) * 2,
				 NUM_DEC (ptr2)));
	}
      A4GL_push_dec (ptr, 0, size);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_14, size_c);
      return buff_14;
    }

  return 0;

}

char *
A4GL_display_dtime (void *ptr, int size, int size_c,
		    struct struct_scr_field *field_details, int display_type)
{
  return 0;
}

char *
A4GL_display_interval (void *ptr, int size, int size_c,
		       struct struct_scr_field *field_details,
		       int display_type)
{
  return 0;
}

char *
A4GL_display_byte (void *ptr, int size, int size_c,
		   struct struct_scr_field *field_details, int display_type)
{
  return 0;
}

char *
A4GL_display_text (void *ptr, int size, int size_c,
		   struct struct_scr_field *field_details, int display_type)
{
  return 0;
}

/**
 *
 *
 * @return
 */
void
A4GL_add_default_operations (void)
{


/* Integer functions 
this covers all possibilities of
DTYPE_INT
DTYPE_SMINT
DTYPE_DATE
DTYPE_SERIAL
*/
//void *ptr;

  A4GL_add_op_function (DTYPE_INT, DTYPE_INT, OP_MATH,  A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SMFLOAT, DTYPE_SMFLOAT, OP_MATH,  A4GL_smfloat_smfloat_ops);
  A4GL_add_op_function (DTYPE_SMFLOAT, DTYPE_FLOAT, OP_MATH,  A4GL_smfloat_float_ops);
  A4GL_add_op_function (DTYPE_FLOAT, DTYPE_SMFLOAT, OP_MATH,  A4GL_float_smfloat_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_SMINT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_INT, DTYPE_SMINT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_INT, OP_MATH, A4GL_int_int_ops);

  A4GL_add_op_function (DTYPE_DATE, DTYPE_DATE, OP_MATH, A4GL_date_date_ops);

  A4GL_add_op_function (DTYPE_INT, DTYPE_DATE, OP_MATH, A4GL_int_date_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_DATE, OP_MATH, A4GL_int_date_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_SMINT, OP_MATH, A4GL_date_int_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_INT, OP_MATH, A4GL_date_int_ops);

  //A4GL_add_op_function (DTYPE_DATE, DTYPE_FLOAT, OP_MATH, A4GL_date_dbl_ops);
  //A4GL_add_op_function (DTYPE_FLOAT, DTYPE_DATE, OP_MATH, A4GL_dbl_date_ops);


  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_SERIAL, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_INT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_SMINT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_DATE, OP_MATH, A4GL_int_date_ops);

  A4GL_add_op_function (DTYPE_INT, DTYPE_SERIAL, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_SERIAL, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_SERIAL, OP_MATH, A4GL_date_int_ops);


  A4GL_add_op_function (DTYPE_DATE, DTYPE_CHAR, OP_MATH, A4GL_date_char_ops);

  A4GL_add_op_function (DTYPE_INTERVAL, DTYPE_INTERVAL, OP_MATH, A4GL_in_in_ops);
  A4GL_add_op_function (DTYPE_INTERVAL, DTYPE_DTIME, OP_MATH, A4GL_dt_in_ops);

  A4GL_add_op_function (DTYPE_DTIME, DTYPE_INTERVAL, OP_MATH, A4GL_in_dt_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_INTERVAL, OP_MATH, A4GL_in_date_ops);

  A4GL_add_op_function (DTYPE_DTIME, DTYPE_DTIME, OP_MATH, A4GL_dt_dt_ops);

  A4GL_debug ("Finished adding default operations");


  A4GL_add_datatype_function_i (DTYPE_INT, "DISPLAY", A4GL_display_int);
  A4GL_add_datatype_function_i (DTYPE_SERIAL, "DISPLAY", A4GL_display_int);
  A4GL_add_datatype_function_i (DTYPE_SMINT, "DISPLAY", A4GL_display_smint);
  A4GL_add_datatype_function_i (DTYPE_FLOAT, "DISPLAY", A4GL_display_float);
  A4GL_add_datatype_function_i (DTYPE_SMFLOAT, "DISPLAY", A4GL_display_smfloat);
  A4GL_add_datatype_function_i (DTYPE_DATE, "DISPLAY", A4GL_display_date);
  A4GL_add_datatype_function_i (DTYPE_CHAR, "DISPLAY", A4GL_display_char);
  A4GL_add_datatype_function_i (DTYPE_DECIMAL, "DISPLAY", A4GL_display_decimal);
  A4GL_add_datatype_function_i (DTYPE_MONEY, "DISPLAY", A4GL_display_money);
  A4GL_add_datatype_function_i (DTYPE_DTIME, "DISPLAY", A4GL_display_dtime);
  A4GL_add_datatype_function_i (DTYPE_INTERVAL, "DISPLAY", A4GL_display_interval);
  A4GL_add_datatype_function_i (DTYPE_BYTE, "DISPLAY", A4GL_display_byte);
  A4GL_add_datatype_function_i (DTYPE_TEXT, "DISPLAY", A4GL_display_text);


#ifndef CSCC
  A4GL_add_datatype_function_i (DTYPE_DECIMAL, ">STRING", A4GL_tostring_decimal);
#endif


  //A4GL_add_datatype_function_i (DTYPE_DTIME,  ">STRING", A4GL_tostring_dtime);


}


void A4GL_ltrim(char *s) {
int a;
char *buff;
char *ptr=0;
char *ptr2=0;
buff=strdup(s);
for (a=0;a<strlen(buff);a++) {
        if (buff[a]==' ') continue;
        ptr=&buff[a];
        break;
}

if (ptr==0) return;
ptr2=strdup(ptr);
strcpy(s,ptr2);
free(ptr2);
free(buff);
}



#ifdef OLD
static char *
make_using (char *ptr)
{
  static char buff[256];
  char buff2[256];
  int dig;
  int dec;

  A4GL_assertion (ptr == 0, "make_using has been passed a null pointer..");
  strcpy (buff,
	  "-------------------------------------------------------------------------------------------------------------------");
  dig = NUM_DIG (ptr) * 2;
  dec = NUM_DEC (ptr);
  A4GL_debug ("In make_using : dig=%d dec=%d", dig, dec);
  buff[dig - dec] = 0;

  if (dec)
    strcat (buff, "&.");
  else
    strcat (buff, "-&");

  memset (buff2, '&', 255);
  buff2[dec] = 0;
  strcat (buff, buff2);
  return buff;
}
#endif



char * make_using_tostring (char *ptr, int d, int n)
{
  static char buff_ts[256];
  char buff2[256];
  int dig;
  int dec;
  int another = 0;

  A4GL_assertion (ptr == 0, "make_using has been passed a null pointer..");

  strcpy (buff_ts,
	  "-------------------------------------------------------------------------------------------------------------------");
//dig=NUM_DIG(ptr)*2;
//dec=NUM_DEC(ptr);
  dig = d;
  dec = n;

//if (dig%2==1) another=1;

  buff_ts[dig - dec - another] = 0;

  if (dec)
    strcat (buff_ts, "&.");
  else
    strcat (buff_ts, "-&");

  memset (buff2, '&', 255);
  buff2[dec] = 0;
  strcat (buff_ts, buff2);
  return buff_ts;
}


static char *
make_using_sz (char *ptr, int sz, int dig, int dec)
{
  static char buff_sz[256];
  int a;
  int c;
  int l;
  A4GL_debug ("make_using_sz - size=%d num dec = %d dig=%d", sz, dec, dig);

  l = 1;			// '-'
  l += dec;
  if (dec)
    l++;			// '.'
  l += dig - dec;

  if (l > sz)
    {
      A4GL_dectos (ptr, buff_sz, 64);
      A4GL_ltrim (buff_sz);
      A4GL_trim (buff_sz);
      A4GL_debug ("make_using_sz dectos returns ---> %s", buff_sz);


      if (strlen (buff_sz) > sz)
	{
	  char *ptr;
	  // It doesn't fit - 
	  // what happens if we remove all the decimal places ?
	  ptr = a_strchr (buff_sz, '.');

	  if (ptr)
	    {
	      *ptr = 0;
	    }

	  if (strlen (buff_sz) > sz)
	    {
	      // Still doesn't fit - we're stuffed...
	      memset (buff_sz, '*', sz);
	      buff_sz[sz] = 0;
	      A4GL_debug ("make_using_sz - doesn't fit");
	      return buff_sz;
	    }

	  dig = strlen (buff_sz);
	  // Trim the decimals..
	  if (dec > sz - 2 - dig)
	    {
	      dec = sz - 2 - dig;
	    }
	  dig = sz - 2 - dec;
	  return make_using_sz (ptr, sz, dig, dec);
	}
    }


  memset (buff_sz, '-', 255);
  buff_sz[sz] = 0;			// Maximum length
  c = sz - 1;
  a = 0;
  if (dec)
    {
      while (a++ < dec)
	{
	  buff_sz[c--] = '&';
	}
      buff_sz[c--] = '.';
    }
  buff_sz[c--] = '&';
  return buff_sz;
}
