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
# $Id: interval.c,v 1.9 2002-10-07 11:06:27 afalout Exp $
#
*/

/**
 * @file
 * Interval data type manipulation functions.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//extern int errno;
int rval_type;
struct ival rval_ival;			/* 1 */
double rval_double;				/* 2 */


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/* int 			valid_int 		(char *s, int *data,int size); */ /* in conv.c */
int 			mk_int_size		(int s,int l);

double 			get_rval_double	(void);
struct ival * 	get_rval_ival	(void);
int 			conv_invdatatoc	(int *data,int v1,int v2,int v3,char *buff);
int 			op_ival 		(struct ival *a, struct ival *b,
								double double_val,char op, char param);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
double
get_rval_double(void)
{
	return rval_double;
}



/**
 *
 * @todo Describe function
 */
struct ival *
get_rval_ival(void)
{
	return &rval_ival;
}


/**
 *
 * @todo Describe function
 */
int
conv_invdatatoc(int *data,int v1,int v2,int v3,char *buff)
{
  char fractions[6];

  debug ("v1=%d v2=%d v3=%d buff=%p\n", v1, v2, v3,buff);

  debug ("Y %d\n", data[0]);
  debug ("M %d\n", data[1]);
  debug ("D %d\n", data[2]);
  debug ("H %d\n", data[3]);
  debug ("m %d\n", data[4]);
  debug ("S %d\n", data[5]);
  debug ("F %d\n", data[6]);
  sprintf(fractions,"%05d",data[6]);

  while (data[5]>=60) {data[5]-=60;data[4]++;} /* Increase minutes */
  while (data[4]>=60) {data[4]-=60;data[3]++;} /* Increase Hours */
  while (data[3]>=24) {data[3]-=24;data[2]++;} /* Increase days */
  while (data[1]>=12) {data[1]-=12;data[0]++;}


  switch (v2) {
		case 2: data[1]+=data[0]*12;break; /* Month */
		case 4: data[3]+=data[2]*24;break; /* Hour */
		case 5: data[4]+=data[2]*24*60+data[3]*60;break; /* Minute */
		case 6: data[5]+=data[2]*24*60*60+data[3]*60*60+data[4]*60;break; /* Second */
	}


  debug("Normalized data..");

  if (v1>=7) { fractions[v1-6]=0; }

      if (v2 == 1)
	sprintf (buff, "%0*d%02d0000000000000", v3, data[0], data[1]);

      if (v2 == 2)
	sprintf (buff, "0000%0*d0000000000000", v3, data[1]);

      if (v2 == 3)
	sprintf (buff, "000000%0*d%02d%02d%02d%s",
		 v3, data[2], data[3], data[4], data[5], fractions);

      if (v2 == 4)
	sprintf (buff, "00000000%0*d%02d%02d%s",
		 v3, data[3], data[4], data[5], fractions);

      if (v2 == 5)
	sprintf (buff, "0000000000%0*d%02d%s",
		 v3, data[4], data[5], fractions);

      if (v2 == 6)
	sprintf (buff, "000000000000%0*d%s", v3, data[5], fractions);

      if (v2 >= 7)
	sprintf (buff, "000000000000000%d", v3);

	debug("Copied data");
      return 1;
}

/**
 * Valid operations on two intervals.
 *
 * Handles 
 * I * d
 * I / d
 * I + I
 * I - I
 * I / I
 * All other combinations of I and d are errors...
 *
 * @param a
 * @param b
 * @param double_val
 * @param op
 * @param param is either 'd' for double or 'I' for interval
 *        'D' is also used internally...
 */

int
op_ival (struct ival *a, struct ival *b, double double_val, char op,
 char param)
{
  int data_a[10];
  int data_b[10];
  int data_r[10];
  int mode;
  int cnt;
  int val1;
  int val2;
  int val3;
  int size;
  char buff[256];

  double v1 = 0;
  double v2;
  double r1 = 0;

	debug("In op_ival a=%p b=%p dv=%lf op=%c param=%c",a,b,double_val,op,param);

  if (param == 'd') /* We're using a double - so ignore 'b' */
    {
      b = a;
    }


	/* Extract the time stuff.. */


  debug("Converting intervals to strings...");


  /*
  inttoc(a, &a_str, mk_int_size(a->stime,a->ltime));
  debug("Converted first...");
  debug("a=%p b=%p\n",a,b);
  inttoc(b, &b_str, mk_int_size(b->stime,b->ltime));

  debug("Converted second...");
  debug("INtervals as strings = %s  & %s",a_str,b_str);

  valid_int (a_str, data_a,mk_int_size(a->stime,a->ltime));
  valid_int (b_str, data_b,mk_int_size(b->stime,b->ltime));
  */

  decode_interval (a, data_a);
  decode_interval (b, data_b);

  debug("Got interval data");
  /* Clear down the return variable.. */
  for (cnt = 0; cnt < 10; cnt++)
    {
      rval_ival.data[cnt] = '0';
      data_r[cnt]=0;
    }

	debug("Cleared down..");

  /* Are we dealing with a sensible sum ? */

  if (a->stime == 0 || a->stime == 1)
    {
      mode = 1;
      if (b->stime > 1)
	{
	  exitwith ("Cannot add a month/day and a non-month day interval");
	  return 0;
	}
    }
  else
    {
      mode = 0;
      if (b->stime <= 1)
	{
	  exitwith ("Cannot add a month/day and a non-month day interval");
	  return 0;
	}
    }



  if (mode == 1)
    { /* Number of years.. */
  	rval_ival.stime = 0x51;
  	rval_ival.ltime = 2;
      v1 = data_a[0] + data_a[1] / 12;
      v2 = data_b[0] + data_b[1] / 12;
    }
  else
    { /* Number of seconds... */
  	rval_ival.stime = 0x53;
  	rval_ival.ltime = 0xb;
      debug("v1 = %d + %d + %d + %d + %lf",data_a[2]*60*60*24 , data_a[3]*60*60 , data_a[4]*60 , data_a[5] , (double)(data_a[6])/100000.0);

      v1 = data_a[2]*60*60*24 + data_a[3]*60*60 + data_a[4]*60 + data_a[5] + (double)(data_a[6])/100000.0;
      v2 = data_b[2]*60*60*24 + data_b[3]*60*60 + data_b[4]*60 + data_b[5] + (double)(data_b[6])/100000.0;
    }





  if (param == 'd')
    {				/* Using a double */

      v2=double_val;


      switch (op)
	{
	case '+':
	  exitwith ("Can't add an interval to a number");
	  return 0;

	case '-':
	  exitwith ("Can't subtract numbers and interval");
	  return 0;

	case '/':
	  r1 = v1 / double_val;
	  rval_type = 1; /* Interval */
	  break;

	case '*':
		debug("v1=%lf dv=%lf\n",v1,double_val);
	  r1 = v1 * double_val;
	  rval_type = 1; /* Interval */
	  break;
	}
    }
  else
    {				/* Using another interval */
      switch (op)
	{
	case '+':
	  r1 = v1 + v2;
	  rval_type = 1; /* Interval */
	  break;
	case '-':
	  r1 = v1 - v2;
	  rval_type = 1; /* Interval */
	  break;
	case '/':
	  r1 = v1 / v2;
	  rval_type = 2; /* Number */
	  break;
	case '*':
	  exitwith ("Can't multiply two intervals");
	  return 0;
	  break;
	}

    }

	/* If we got to here r1 will contain either a number or an interval */

	if (rval_type==2) { /* Yip yip - this ones easy ! */
		rval_double=r1;
		return 2;
	}
	debug("r1=%lf mode=%d\n",r1,mode);


	if (mode==1) { /* we have a number of years in r1 */
		double yd,md;
		int y = 0;
		yd=floor(r1);
		md=(r1-y)*12.0;
		data_r[0]=yd;
		data_r[1]=md;

	} else {
		double sd,fd;
		int s;
		sd=floor(r1);
		fd=r1-sd;
		debug("sd=%lf fd=%lf\n",sd,fd);
		data_r[6]=fd*100000;
		s=sd;
		data_r[5]=s%60; s=s/60; /* Seconds */
		data_r[4]=s%60; s=s/60; /* Minutes */
		data_r[3]=s%60; s=s/24; /* Hours */
		data_r[2]=s; /* Days */
	}

	/* data_r should be set up now... */

  debug("stime=%x ltime=%x",rval_ival.stime,rval_ival.ltime);
  val1=rval_ival.ltime;
  val2=rval_ival.stime&15;
  val3=(rval_ival.stime>>4)&15;

  size=mk_int_size(rval_ival.stime,rval_ival.ltime);

  conv_invdatatoc(data_r,val1,val2,val3,buff);
  debug("buff=%s\n",buff);
  debug("Calling ctoint - size=%x",size);
  strcpy(rval_ival.data, buff);
  return rval_type;
}


/**
 *
 * @todo Describe function
 */
int
mk_int_size(int s,int l)
{
  return l+ (s<<4);
}

/* ==================================== EOF =========================== */

