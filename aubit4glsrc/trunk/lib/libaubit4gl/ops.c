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
# $Id: ops.c,v 1.22 2003-07-04 09:43:39 mikeaubury Exp $
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


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_int_int_ops (int op);
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


char *A4GL_display_int (void *ptr, int size, int size_c,
		   struct struct_scr_field *field_details, int display_type);
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
		    struct struct_scr_field *field_details, int display_type);
char *A4GL_display_char (void *ptr, int size, int size_c,
		    struct struct_scr_field *field_details, int display_type);
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
		    struct struct_scr_field *field_details, int display_type);
char *A4GL_display_text (void *ptr, int size, int size_c,
		    struct struct_scr_field *field_details, int display_type);

static char *make_using(char *ptr) ;

#define NUM_DIG(x)               ((x[0])&127 )
#define NUM_DEC(x)               ((x[1]))




/*
=====================================================================
                    Functions definitions
=====================================================================
*/
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
  int s1;
  //void *ptr1;
  struct ival *pi;
  struct A4GLSQL_dtime *pd;
  int ok = 0;
  char buff[256];
  int start;
  char *ptr;

  A4GL_get_top_of_stack (2, &d1, &s1, (void **) &pd);

  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &pi);


  if ((d1 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      printf ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_INTERVAL);
    }


  in.stime = pi->stime;
  in.ltime = pi->ltime;
  dt.stime = pd->stime;
  dt.ltime = pd->ltime;
  A4GL_pop_var2 (&in, DTYPE_INTERVAL, in.stime * 16 + in.ltime);


  A4GL_pop_param (&dt, DTYPE_DTIME, dt.stime * 16 + dt.ltime);


  A4GL_decode_interval (&in, &ival_data[0]);
/*
	//printf("\n\nInterval : Y=%d\n",ival_data[0]);
	//printf("Interval : M=%d\n",ival_data[1]);
	//printf("Interval : D=%d\n",ival_data[2]);
	//printf("Interval : H=%d\n",ival_data[3]);
	//printf("Interval : M=%d\n",ival_data[4]);
	//printf("Interval : S=%d\n",ival_data[5]);
	//printf("Interval : F=%d\n",ival_data[6]);
*/

  A4GL_decode_datetime (&dt, &dtime_data[0]);

/*
	printf("Datetime : Y=%d\n",dtime_data[0]);
	printf("Datetime : M=%d\n",dtime_data[1]);
	printf("Datetime : D=%d\n",dtime_data[2]);
	printf("Datetime : H=%d\n",dtime_data[3]);
	printf("Datetime : M=%d\n",dtime_data[4]);
	printf("Datetime : S=%d\n",dtime_data[5]);
	printf("Datetime : F=%d\n",dtime_data[6]);
*/

  switch (op)
    {
    case OP_ADD:
      // Fractions
      dtime_data[6] += ival_data[6];
      if (dtime_data[6] > 99999)
	{
	  dtime_data[5]++;
	  dtime_data[6] -= 100000;
	}

      // Seconds
      dtime_data[5] += ival_data[5];
      if (dtime_data[5] > 60)
	{
	  dtime_data[4]++;
	  dtime_data[5] -= 60;
	}

      // Minutes
      dtime_data[4] += ival_data[4];
      if (dtime_data[4] > 60)
	{
	  dtime_data[3]++;
	  dtime_data[4] -= 60;
	}

      // Hours
      dtime_data[3] += ival_data[3];
      if (dtime_data[3] > 24)
	{
	  dtime_data[2]++;
	  dtime_data[3] -= 24;
	}

      // Days
      dtime_data[2] += ival_data[2];
      if (dtime_data[2] > 30)
	{
	  dtime_data[1]++;
	  dtime_data[2] -= 30;							    /** @todo Fix this **/
	}

      // Months
      dtime_data[1] += ival_data[1];
      if (dtime_data[1] > 12)
	{
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
      if (dtime_data[5] < 0)
	{
	  dtime_data[4]--;
	  dtime_data[5] += 60;	/* printf("Carry S\n"); */
	}

      // Minutes
      dtime_data[4] -= ival_data[4];
      if (dtime_data[4] < 0)
	{
	  dtime_data[3]--;
	  dtime_data[4] += 60;	/* printf("Carry M\n"); */
	}

      // Hours
      dtime_data[3] -= ival_data[3];
      if (dtime_data[3] < 0)
	{
	  dtime_data[2]--;
	  dtime_data[3] += 24;	/* printf("Carry H\n"); */
	}

      if (dt.stime <= 3)
	{
	  // Days
	  dtime_data[2] -= ival_data[2];
	  if (dtime_data[2] <= 1)
	    {
	      dtime_data[1]--;
	      dtime_data[2] += 30;	/** @todo Fix this **//*printf("Carry D\n"); */
	    }
	}

      if (dt.stime <= 2)
	{
	  // Months
	  dtime_data[1] -= ival_data[1];
	  if (dtime_data[1] <= 1)
	    {
	      dtime_data[0]--;
	      dtime_data[1] += 12;	/*printf("Carry M\n"); */
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

  if (ok)
    {
      sprintf (buff, "%04d-%02d-%02d %02d:%02d:%02d.%05d",
	       dtime_data[0],
	       dtime_data[1],
	       dtime_data[2],
	       dtime_data[3], dtime_data[4], dtime_data[5], dtime_data[6]);

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
      ptr=0;
      switch (start)
	{
	case 1:
	  ptr = &buff[0];
	  break;
	case 2:
	  ptr = &buff[5];
	  break;
	case 3:
	  ptr = &buff[8];
	  break;
	case 4:
	  ptr = &buff[11];
	  break;
	case 5:
	  ptr = &buff[14];
	  break;
	case 6:
	  ptr = &buff[17];
	  break;
	case 7:
	  ptr = &buff[18];
	  break;
	}
    if (ptr==0) {
		A4GL_exitwith("Internal error in_dt_ops");
		return;
	}

      dt.stime = start;
      //dt.ltime=11;

/*
		switch(dt.ltime) {
			case 1: buff[4]=0;break; //Y
			case 2: buff[7]=0;break; //M
			case 3: buff[10]=0;break; //D
			case 4: buff[13]=0;break; //H
			case 5: buff[16]=0;break; //M
			case 6: buff[19]=0;break; //D
		}
*/

      A4GL_ctodt (ptr, &dt, dt.stime * 16 + dt.ltime);

      A4GL_push_dtime (&dt);
      return;
    }



  A4GL_push_int (0);
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
  long d;

  b = A4GL_pop_long ();
  a = A4GL_pop_long ();

  if ( A4GL_isnull(DTYPE_INT,(void *)&a)|| A4GL_isnull(DTYPE_INT,(void *)&b)) {
		A4GL_debug("int_int - one is null");
		A4GL_push_null(DTYPE_INT,0);
		return;
  } else {
	A4GL_debug("OK - neither is null");
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
      c = a;
      for (d = 1; d <= b; d++)
	c *= b;
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

// d2 op d1
  A4GL_get_top_of_stack (2, &d2, &s2, (void **) &pi2);
  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &pi1);


  if ((d1 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      printf ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_INTERVAL);
    }


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

  A4GL_pop_param (&in1, DTYPE_INTERVAL, in1.stime * 16 + in2.ltime);
  A4GL_pop_param (&in2, DTYPE_INTERVAL, in1.stime * 16 + in2.ltime);


  A4GL_decode_interval (&in1, &ival_data1[0]);
  A4GL_decode_interval (&in2, &ival_data2[0]);

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
    }


  switch (op)
    {
    case OP_ADD:
      d_i1 = d_i2 + d_i1;
    case OP_SUB:
      d_i1 = d_i2 - d_i1;
      if (se1 == 2)
	{
	  char buff[256];
	  sprintf (buff, "%f", d_i1);
	  acli_interval (buff, 0x822);
	  return;
	}
      else
	{
	  char buff[256];
	  sprintf (buff, "%f", d_i1);
	  acli_interval (buff, 0x866);
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
      A4GL_exitwith ("You can't raise the A4GL_power of intervals...");
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
  char buff[256];
  //int start;
  //char *ptr;
  //double d_d1;
  //double d_d2;

  if (op != (OP_SUB))
    {
      A4GL_debug ("Can only subtract datetimes...");
      A4GL_push_int (0);
      return;
    }
// d2 - d1
  A4GL_get_top_of_stack (2, &d1, &s1, (void **) &pd);
  A4GL_get_top_of_stack (1, &d2, &s2, (void **) &pi);


  if ((d1 & DTYPE_MASK) != DTYPE_DTIME)
    {
      printf ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_DTIME);
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
      dtime_data2[2] += 30;
      dtime_data2[1]--;
    }

// Borrow some years for some months.
  while (dtime_data2[1] < 0)
    {
      dtime_data2[1] += 12;
      dtime_data2[0]--;
    }

  if (dtime_data2[0] || dtime_data2[1])
    {
      // YEAR TO MONTH interval
      sprintf (buff, "%4d-%02d", dtime_data2[0], dtime_data2[1]);

      A4GL_ctoint (buff, &in, 1298);
      A4GL_push_interval (&in);


    }
  else
    {
      sprintf (buff, "%d %02d:%02d:%02d.%05d", dtime_data2[2], dtime_data2[3],
	       dtime_data2[4], dtime_data2[5], dtime_data2[6]);
      A4GL_debug ("Got buff as : %s\n", buff);
      A4GL_ctoint (buff, &in, 0x53b);
      A4GL_debug ("Pushing Interval - %p - s=%x e=%x made from %s", &in, in.stime,
	     in.ltime);
      A4GL_debug ("Buff = %s %x %x", buff);
      A4GL_push_interval (&in);
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
  static char buff[256];
  A4GL_debug("A4GL_display_int..");

  if (display_type == DISPLAY_TYPE_DISPLAY|| display_type==DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull(DTYPE_INT,ptr)) {
		strcpy(buff,"           ");
	} else {
  		a = *(long *) ptr;
      		sprintf (buff, "%11ld", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull(DTYPE_INT,ptr)) {
		strcpy(buff,"");
	} else {
  		a = *(long *) ptr;
      		sprintf (buff, "%ld", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
		char using_buff[256];
      if (A4GL_isnull(DTYPE_INT,ptr)) { strcpy(buff,""); return buff; }
  		a = *(long *) ptr;
		if (A4GL_has_str_attribute (field_details, FA_S_FORMAT)) {
			strcpy(using_buff,(A4GL_get_str_attribute(field_details,FA_S_FORMAT)));
		} else {
			memset(using_buff,'-',255);
			using_buff[size_c]=0;
			using_buff[size_c-1]='&';
		}

		A4GL_push_long(a);
		A4GL_push_char(using_buff);
		A4GL_pushop (OP_USING);
      		A4GL_pop_char (buff, size_c);
		A4GL_debug("display_int Got '%s'",buff);
		return buff;
    }

  A4GL_debug("Returning '%s'",buff);

  return buff;
}

char *
A4GL_display_smint (void *ptr, int size, int size_c, struct struct_scr_field *field_details, int display_type)
{
  short a;
  static char buff[256];


  A4GL_debug("A4GL_display_smint..");

  if (display_type == DISPLAY_TYPE_DISPLAY|| display_type==DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull(DTYPE_SMINT,ptr)) {
		strcpy(buff,"      ");
	} else {
  		a = *(short *) ptr;
      		sprintf (buff, "%6d", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull(DTYPE_SMINT,ptr)) {
		strcpy(buff,"");
	} else {
  		a = *(short *) ptr;
      		sprintf (buff, "%d", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
                char using_buff[256];
      		if (A4GL_isnull(DTYPE_SMINT,ptr)) { strcpy(buff,""); return buff; }
  		a = *(short *) ptr;
		A4GL_debug("display_smint a=%d",a);
                if (A4GL_has_str_attribute (field_details, FA_S_FORMAT)) {
                        strcpy(using_buff,(A4GL_get_str_attribute(field_details,FA_S_FORMAT)));
                } else {
                	memset(using_buff,'-',255);
                	using_buff[size_c]=0;
                	using_buff[size_c-1]='&';
		}
		A4GL_push_int(a);
		A4GL_push_char(using_buff);
                A4GL_pushop (OP_USING);
                A4GL_pop_char (buff, size_c);
		A4GL_debug("display_smint Got '%s'",buff);
		return buff;
    }

  return buff;

}

char *
A4GL_display_float (void *ptr, int size, int size_c,
	       struct struct_scr_field *field_details, int display_type)
{
  double a;
  static char buff[256];

  if (display_type == DISPLAY_TYPE_DISPLAY|| display_type==DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull(DTYPE_FLOAT,ptr)) { strcpy(buff,""); return buff; }
  	a = *(double *) ptr;
      sprintf (buff, "%14.2f", a);
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      int cnt;
      if (A4GL_isnull(DTYPE_FLOAT,ptr)) { strcpy(buff,""); return buff; }
  	a = *(double *) ptr;
      sprintf (buff, "%f", a);
      for (cnt = strlen (buff) - 1; cnt > 0; cnt--)
	{
	  if (cnt <= 1)
	    break;
	  if (buff[cnt - 1] == '.')
	    break;
	  if (buff[cnt] != '0')
	    break;
	  if (buff[cnt] == '0')
	    buff[cnt] = 0;

	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
	char using_buff[256];
      if (A4GL_isnull(DTYPE_FLOAT,ptr)) { strcpy(buff,""); return buff; }
  	a = *(double *) ptr;
        if (A4GL_has_str_attribute (field_details, FA_S_FORMAT)) {
                    strcpy(using_buff,(A4GL_get_str_attribute(field_details,FA_S_FORMAT)));
        } else {
               	memset(using_buff,'-',255);
               	using_buff[size_c]=0;
               	using_buff[size_c-4]='&';
               	using_buff[size_c-3]='.';
               	using_buff[size_c-2]='&';
               	using_buff[size_c-1]='&';
	}
        A4GL_push_double (a);
        A4GL_push_char(using_buff);
        A4GL_pushop (OP_USING);
	return buff;
    }
  return buff;

}

char *
A4GL_display_smfloat (void *ptr, int size, int size_c,
		 struct struct_scr_field *field_details, int display_type)
{
  float a;
  static char buff[256];

  if (display_type == DISPLAY_TYPE_DISPLAY|| display_type==DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull(DTYPE_SMFLOAT,ptr)) { strcpy(buff,""); return buff; }
  a = *(float *) ptr;
      sprintf (buff, "%14.2f", a);
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      int cnt;
      if (A4GL_isnull(DTYPE_SMFLOAT,ptr)) { strcpy(buff,""); return buff; }
  a = *(float *) ptr;
      sprintf (buff, "%f", a);
      for (cnt = strlen (buff) - 1; cnt > 0; cnt--)
	{
	  if (cnt <= 1)
	    break;
	  if (buff[cnt - 1] == '.')
	    break;
	  if (buff[cnt] != '0')
	    break;
	  if (buff[cnt] == '0')
	    buff[cnt] = 0;

	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
        char using_buff[256];
      if (A4GL_isnull(DTYPE_SMFLOAT,ptr)) { strcpy(buff,""); return buff; }
  a = *(float *) ptr;
        if (A4GL_has_str_attribute (field_details, FA_S_FORMAT)) {
                    strcpy(using_buff,(A4GL_get_str_attribute(field_details,FA_S_FORMAT)));
        } else {
                memset(using_buff,'-',255);
                using_buff[size_c]=0;
                using_buff[size_c-4]='&';
                using_buff[size_c-3]='.';
                using_buff[size_c-2]='&';
                using_buff[size_c-1]='&';
        }
        A4GL_push_float (a);
        A4GL_push_char(using_buff);
        A4GL_pushop (OP_USING);
        A4GL_pop_char (buff, size_c);
    }

  return buff;

}

char *
A4GL_display_date (void *ptr, int size, int size_c,
	      struct struct_scr_field *field_details, int display_type)
{
  return 0;
}

char *
A4GL_display_char (void *ptr, int size, int size_c,
	      struct struct_scr_field *field_details, int display_type)
{
  return 0;
}

char *
A4GL_display_decimal (void *ptr, int size, int size_c,
		 struct struct_scr_field *field_details, int display_type)
{
static char s[256];
static char buff[256];

A4GL_debug("Display_decimal");
  //if (size_c==-1) { return 0; }

  if (display_type == DISPLAY_TYPE_DISPLAY|| display_type==DISPLAY_TYPE_PRINT) {
        A4GL_push_dec(ptr,0,size);


        if (size_c==-1) {
                char *ptr2;
                int n,l;
                //char buff[256];
                //char buff2[256];
                ptr2=ptr;
                n=NUM_DIG(ptr2);
                l=NUM_DEC(ptr2);
                n=n-l+1;
                size_c=n+1;
        }

        A4GL_push_char(make_using(ptr));
        A4GL_pushop(OP_USING);
        ptr=A4GL_char_pop();
        strcpy(s,ptr);
	free(ptr);
        return s;
  }


  if (display_type== DISPLAY_TYPE_DISPLAY_AT) {
	A4GL_push_dec(ptr,0,size);
	if (size_c==-1) {
		char *ptr;
		ptr=A4GL_char_pop();
		strcpy(s,ptr);
		free(ptr);
	} else {
		A4GL_pop_char(s,size_c);
	}

	A4GL_trim(s);
  	A4GL_ltrim(s);
	return s;
  }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
        char using_buff[256];
	if (A4GL_isnull(DTYPE_DECIMAL,ptr)) {
		strcpy(buff,"");
		return buff;
	}

        if (A4GL_has_str_attribute (field_details, FA_S_FORMAT)) {
                    strcpy(using_buff,(A4GL_get_str_attribute(field_details,FA_S_FORMAT)));
        } else {
                memset(using_buff,'-',255);
                using_buff[size_c]=0;
                using_buff[size_c-4]='&';
                using_buff[size_c-3]='.';
                using_buff[size_c-2]='&';
                using_buff[size_c-1]='&';
        }
        A4GL_push_dec (ptr,0,size);
        A4GL_push_char(using_buff);
        A4GL_pushop (OP_USING);
        A4GL_pop_char (buff, size_c);
		return buff;
    }

  return 0;
}

char *
A4GL_display_money (void *ptr, int size, int size_c,
	       struct struct_scr_field *field_details, int display_type)
{
static char s[256];
static char buff[256];

A4GL_debug("Display_money");
  //if (size_c==-1) { return 0; }


  if (display_type == DISPLAY_TYPE_DISPLAY|| display_type==DISPLAY_TYPE_PRINT) {
        A4GL_push_dec(ptr,1,size);


        if (size_c==-1) {
                char *ptr2;
                int n,l;
                //char buff[256];
                //char buff2[256];
                ptr2=ptr;
                n=NUM_DIG(ptr2);
                l=NUM_DEC(ptr2);
                n=n-l+1;
                size_c=n+1;
        }

	A4GL_push_char(make_using(ptr));
	A4GL_pushop(OP_USING);	
	ptr=A4GL_char_pop();
	strcpy(s,ptr);
	free(ptr);
        return s;
  }

  if (display_type== DISPLAY_TYPE_DISPLAY_AT) {
        A4GL_push_dec(ptr,1,size);
        if (size_c==-1) {
                char *ptr;
                ptr=A4GL_char_pop();
                strcpy(s,ptr);
                free(ptr);
        } else {
                A4GL_pop_char(s,size_c);
        }

	A4GL_trim(s);
        A4GL_ltrim(s);
        return s;
  }
  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
        char using_buff[256];
	if (A4GL_isnull(DTYPE_DECIMAL,ptr)) {
		strcpy(buff,"");
		return buff;
	}
        if (A4GL_has_str_attribute (field_details, FA_S_FORMAT)) {
                    strcpy(using_buff,(A4GL_get_str_attribute(field_details,FA_S_FORMAT)));
        } else {
                memset(using_buff,'-',255);
                using_buff[size_c]=0;
                using_buff[size_c-4]='&';
                using_buff[size_c-3]='.';
                using_buff[size_c-2]='&';
                using_buff[size_c-1]='&';
        }
        A4GL_push_dec (ptr,0,size);
        A4GL_push_char(using_buff);
        A4GL_pushop (OP_USING);
        A4GL_pop_char (buff, size_c);
		return buff;
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
		  struct struct_scr_field *field_details, int display_type)
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

  A4GL_add_op_function (DTYPE_INT, DTYPE_INT, OP_MATH, A4GL_int_int_ops);

  A4GL_add_op_function (DTYPE_SMINT, DTYPE_SMINT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_INT, DTYPE_SMINT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_INT, OP_MATH, A4GL_int_int_ops);

  A4GL_add_op_function (DTYPE_DATE, DTYPE_DATE, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_INT, DTYPE_DATE, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_DATE, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_SMINT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_INT, OP_MATH, A4GL_int_int_ops);

  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_SERIAL, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_INT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_SMINT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_DATE, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_INT, DTYPE_SERIAL, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_SERIAL, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_SERIAL, OP_MATH, A4GL_int_int_ops);

  A4GL_add_op_function (DTYPE_INTERVAL, DTYPE_INTERVAL, OP_MATH, A4GL_in_in_ops);
  A4GL_add_op_function (DTYPE_INTERVAL, DTYPE_DTIME, OP_MATH, A4GL_dt_in_ops);

  A4GL_add_op_function (DTYPE_DTIME, DTYPE_INTERVAL, OP_MATH, A4GL_in_dt_ops);

  A4GL_add_op_function (DTYPE_DTIME, DTYPE_DTIME, OP_MATH, A4GL_dt_dt_ops);

  A4GL_debug ("Finished adding default operations");


  A4GL_add_datatype_function_i (DTYPE_INT, "DISPLAY", A4GL_display_int);
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


}



void A4GL_ltrim(char *s) {
int a;
char *buff;
char *ptr=0;
buff=strdup(s);

for (a=0;a<strlen(buff);a++) {
	if (s[a]==' ') continue;
	ptr=&s[a]; 
	break;
}

if (ptr==0) return;

strcpy(s,ptr);
free(buff);
}



static char *make_using(char *ptr) {
static char buff[256];
char buff2[256];
int dig;
int dec;
strcpy(buff,"-------------------------------------------------------------------------------------------------------------------");
dig=NUM_DIG(ptr)*2;
dec=NUM_DEC(ptr);
buff[dig-dec]=0;
strcat(buff,"&.");
memset(buff2,'&',255);
buff2[dec]=0;
strcat(buff,buff2);
return buff;
}
/* ========================== EOF ========================== */
