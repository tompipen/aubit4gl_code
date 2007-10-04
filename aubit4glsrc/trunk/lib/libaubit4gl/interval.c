/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# $Id: interval.c,v 1.24 2007-10-04 17:20:30 mikeaubury Exp $
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
static int rval_type;
static struct ival rval_ival;		/* 1 */
static double rval_double;		/* 2 */


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/* int 		 A4GL_valid_int 		(char *s, int *data,int size); *//* in conv.c */
int A4GL_mk_int_size (int s, int l);

double A4GL_get_rval_double (void);
struct ival *A4GL_get_rval_ival (void);
int A4GL_conv_invdatatoc (int *data, int v1, int v2, int v3, struct ival *d);
int A4GL_op_ival (struct ival *a, struct ival *b,
	     double double_val, char op, char param);


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
A4GL_get_rval_double (void)
{
  return rval_double;
}



/**
 *
 * @todo Describe function
 */
struct ival *
A4GL_get_rval_ival (void)
{
  return &rval_ival;
}



/**
 *
 * @todo Describe function
 */
int
A4GL_conv_invdatatoc (int *data, int v1, int v2, int v3, struct ival *i)
{
  //char fractions[6];
  //char *buff=0;
  //buff = i->data;

  //A4GL_debug ("v1=%d v2=%d v3=%d buff=%p\n", v1, v2, v3, buff);

  A4GL_debug ("Y %d\n", data[0]);
  A4GL_debug ("M %d\n", data[1]);
  A4GL_debug ("D %d\n", data[2]);
  A4GL_debug ("H %d\n", data[3]);
  A4GL_debug ("m %d\n", data[4]);
  A4GL_debug ("S %d\n", data[5]);
  A4GL_debug ("F %d\n", data[6]);
  //SPRINTF1 (fractions, "%05d", data[6]);

  while (data[5] >= 60)
    {
      data[5] -= 60;
      data[4]++;
    }				/* Increase minutes */
  while (data[4] >= 60)
    {
      data[4] -= 60;
      data[3]++;
    }				/* Increase Hours */
  while (data[3] >= 24)
    {
      data[3] -= 24;
      data[2]++;
    }				/* Increase days */
  while (data[1] >= 12)
    {
      data[1] -= 12;
      data[0]++;
    }


  switch (v2)
    {
    case 2:
      data[1] += data[0] * 12;
	data[0]=0;
      break;			/* Month */
    case 4:
      data[3] += data[2] * 24;
	data[2]=0;
      break;			/* Hour */
    case 5:
      data[4] += data[2] * 24 * 60 + data[3] * 60;
	data[2]=0;
	data[3]=0;
      break;			/* Minute */
    case 6:
      data[5] += data[2] * 24 * 60 * 60 + data[3] * 60 * 60 + data[4] * 60;
	data[2]=0;data[3]=0;data[4]=0;
      break;			/* Second */
    }


  A4GL_debug ("Normalized data..");

  i->i_years = data[0];
  i->i_months = data[1];
  i->i_days = data[2];
  i->i_hours = data[3];
  i->i_minutes = data[4];
  i->i_seconds = data[5];
  i->i_fractions = data[6];

  i->is_neg=0;

  if (i->i_years<0) 	{ i->i_years*=-1; i->is_neg=1; }
  if (i->i_days<0) 	{ i->i_days*=-1; i->is_neg=1; }
  if (i->i_hours<0) 	{ i->i_hours*=-1; i->is_neg=1; }
  if (i->i_minutes<0) 	{ i->i_minutes*=-1; i->is_neg=1; }
  if (i->i_seconds<0) 	{ i->i_seconds*=-1; i->is_neg=1; }

  A4GL_debug ("Normalized data %d %d %d %d %d %d %d",
	data[0],
	data[1],
	data[2],
	data[3],
	data[4],
	data[5],
	data[6]
);


#ifdef OBSOLETE
  if (v1 >= 7)
    {
      fractions[v1 - 6] = 0;
      A4GL_debug ("Set fractions to %s\n", fractions);
    }

  if (v2 == 1)
    SPRINTF3 (buff, "%0*d%02d0000000000000", v3, data[0], data[1]);

  if (v2 == 2)
    SPRINTF2 (buff, "0000%0*d0000000000000", v3, data[1]);

  if (v2 == 3)
    SPRINTF6 (buff, "000000%0*d%02d%02d%02d%s",
	     v3, data[2], data[3], data[4], data[5], fractions);

  if (v2 == 4)
    SPRINTF5 (buff, "00000000%0*d%02d%02d%s",
	     v3, data[3], data[4], data[5], fractions);

  if (v2 == 5)
    SPRINTF4 (buff, "0000000000%0*d%02d%s", v3, data[4], data[5], fractions);

  if (v2 == 6)
    SPRINTF3 (buff, "000000000000%0*d%s", v3, data[5], fractions);

  if (v2 >= 7)
    SPRINTF1 (buff, "000000000000000%s", fractions);
#endif
  A4GL_debug ("Copied data");
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
A4GL_op_ival (struct ival *a, struct ival *b, double double_val, char op,
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
int isneg_a;
int isneg_b;
int isneg_r;
  //char buff[256];

  double v1 = 0;
  double v2;
  double r1 = 0;

  A4GL_debug ("In A4GL_op_ival a=%p b=%p dv=%lf op=%c param=%c", a, b, double_val, op,
	 param);

  if (param == 'd')		/* We're using a double - so ignore 'b' */
    {
      b = a;
    }


  /* Extract the time stuff.. */


  A4GL_debug ("Converting intervals to strings...");


  A4GL_decode_interval (a, data_a,&isneg_a);
  A4GL_decode_interval (b, data_b,&isneg_b);

  rval_ival.is_neg=0;
  rval_ival.i_years=0;
  rval_ival.i_months=0;
  rval_ival.i_days=0;
  rval_ival.i_hours=0;
  rval_ival.i_minutes=0;
  rval_ival.i_seconds=0;
  rval_ival.i_fractions=0;


  A4GL_debug ("Got interval data");
  /* Clear down the return variable.. */
  for (cnt = 0; cnt < 10; cnt++)
    {
      //rval_ival.data[cnt] = '0';
      data_r[cnt] = 0;
    }

  A4GL_debug ("Cleared down..");

  /* Are we dealing with a sensible sum ? */

  if (a->stime == 0 || a->stime == 1)
    {
      mode = 1;
      if (b->stime > 1)
	{
	  A4GL_exitwith ("Cannot add a month/day and a non-month day interval");
	  return 0;
	}
    }
  else
    {
      mode = 0;
      if (b->stime <= 1)
	{
	  A4GL_exitwith ("Cannot add a month/day and a non-month day interval");
	  return 0;
	}
    }



  if (mode == 1)
    {				/* Number of years.. */
      rval_ival.stime = 0x51;
      rval_ival.ltime = 2;
      v1 = data_a[0] + data_a[1] / 12;
      v2 = data_b[0] + data_b[1] / 12;
    }
  else
    {				/* Number of seconds... */
      rval_ival.stime = 0x53;
      rval_ival.ltime = 0xb;
      A4GL_debug ("v1 = %d + %d + %d + %d + %lf", data_a[2] * 60 * 60 * 24,
	     data_a[3] * 60 * 60, data_a[4] * 60, data_a[5],
	     (double) (data_a[6]) / 100000.0);

      v1 =
	data_a[2] * 60 * 60 * 24 + data_a[3] * 60 * 60 + data_a[4] * 60 +
	data_a[5] + (double) (data_a[6]) / 100000.0;
      v2 =
	data_b[2] * 60 * 60 * 24 + data_b[3] * 60 * 60 + data_b[4] * 60 +
	data_b[5] + (double) (data_b[6]) / 100000.0;
    }

  if (isneg_a) v1*=-1.0;
  if (isneg_b) v2*=-1.0;



  if (param == 'd')
    {				/* Using a double */

      v2 = double_val;


      switch (op)
	{
	case '+':
	  A4GL_exitwith ("Can't add an interval to a number");
	  return 0;

	case '-':
	  A4GL_exitwith ("Can't subtract numbers and interval");
	  return 0;

	case '/':
	  r1 = v1 / double_val;
	  rval_type = 1;	/* Interval */
	  break;

	case '*':
	  A4GL_debug ("v1=%lf dv=%lf\n", v1, double_val);
	  r1 = v1 * double_val;
	  rval_type = 1;	/* Interval */
	  break;
	}
    }
  else
    {				/* Using another interval */
      switch (op)
	{
	case '+':
	  r1 = v1 + v2;
	  rval_type = 1;	/* Interval */
	  break;
	case '-':
	  r1 = v1 - v2;
	  rval_type = 1;	/* Interval */
	  break;
	case '/':
	  r1 = v1 / v2;
	  rval_type = 2;	/* Number */
	  break;
	case '*':
	  A4GL_exitwith ("Can't multiply two intervals");
	  return 0;
	  break;
	}

    }

  /* If we got to here r1 will contain either a number or an interval */

  if (rval_type == 2)
    {				/* Yip yip - this ones easy ! */
      rval_double = r1;
      return 2;
    }
  A4GL_debug ("r1=%lf mode=%d\n", r1, mode);

   for(cnt=0;cnt<10;cnt++) {
      data_r[cnt] = 0;
   }
  isneg_r=0;

  if (mode == 1)
    {				/* we have a number of years in r1 */
      double yd, md;
      int y = 0;
      if (r1<0) {r1*=-1; isneg_r=1;}
      yd = floor (r1);
      md = (r1 - y) * 12.0;
      data_r[0] = yd;
      data_r[1] = md;

    }
  else
    {
      double sd, fd;
      int s;
      if (r1<0) {r1*=-1; isneg_r=1;}
      sd = floor (r1);
      fd = r1 - sd;
      A4GL_debug ("sd=%lf fd=%lf\n", sd, fd);
      data_r[6] = fd * 100000;
      s = sd;
      data_r[5] = s % 60;
      s = s / 60;		/* Seconds */
      data_r[4] = s % 60;
      s = s / 60;		/* Minutes */
      data_r[3] = s % 60;
      s = s / 24;		/* Hours */
      data_r[2] = s;		/* Days */
    }

  /* data_r should be set up now... */

  A4GL_debug ("stime=%x ltime=%x", rval_ival.stime, rval_ival.ltime);
  val1 = rval_ival.ltime;
  val2 = rval_ival.stime & 15;
  val3 = (rval_ival.stime >> 4) & 15;

  size = A4GL_mk_int_size (rval_ival.stime, rval_ival.ltime);
	rval_ival.is_neg=isneg_r;

  A4GL_conv_invdatatoc (data_r, val1, val2, val3, &rval_ival);

  return rval_type;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_mk_int_size (int s, int l)
{
  return l + (s << 4);
}


/**
 * @param ival
 * @param data
 */
void
A4GL_decode_interval (struct ival *ival, int *data,int *isneg)
{
  int i;
  /*char buff[256];
  int cnt = 0;
  char buff2[64]; */
  int s1;
  int s2;
  /*int c;
  int cpc;
  int c2;
  int ltime; */

  /*
  char *codes[] = { "YEAR", "MONTH", "DAY", "HOUR", "MINUTE",
    "SECOND", "FRACTION",
    0
  };
  */
  /*
  int spc[] = {
    0,
    4,
    2,
    2,
    2,
    2,
    2,
    5
  };
*/
  A4GL_debug ("Decoding interval into component parts");

  for (i = 0; i < 10; i++)
    {
      data[i] = 0;
    }

  s1 = ival->stime % 16;
  s2 = ival->stime / 16;
  A4GL_debug ("s1=%d s2=%d", s1, s2);
#ifdef OBSOLETE
  //memset(buff,0,sizeof(buff));
  //memcpy(buff,ival->data,24);




  A4GL_debug ("buff=%s\n", buff);

  cnt = 0;
  for (c = 1; c < s1; c++)
    {
      A4GL_debug ("c=%d cnt=%d\n", c, cnt);
      cnt += spc[c];
    }

  A4GL_debug ("Cnt=%d\n", cnt);
  A4GL_debug ("Taking first part (size=%d) from %d", s2, cnt);

  c = s2;
  strncpy (buff2, &buff[cnt], s2);
  buff2[s2] = 0;
  A4GL_debug ("buff2 = '%s'\n", buff2);

  c2 = c;
  ltime = ival->ltime;
  if (ltime >= 7)
    ltime = 7;

  for (cpc = s1; cpc < ltime; cpc++)
    {
      A4GL_debug ("cpc=%d buff2=%s c2=%d cnt=%d cnt+c2=%d ", cpc, buff2, c2, cnt,
	     cnt + c2);
      data[cpc - 1] = atoi (buff2);

      buff2[0] = buff[cnt + c2];
      c2++;
      if (ival->ltime < 7)
	{
	  buff2[1] = buff[cnt + c2];
	  c2++;
	  buff2[2] = 0;
	}
      else
	{
	  buff2[1] = buff[cnt + c2];
	  c2++;
	  buff2[2] = buff[cnt + c2];
	  c2++;
	  buff2[3] = buff[cnt + c2];
	  c2++;
	  buff2[4] = buff[cnt + c2];
	  c2++;
	  buff2[4] = 0;
	}
    }

  A4GL_debug ("cpc=%d buff2=%s", cpc, buff2);
  data[cpc - 1] = atoi (buff2);
  for (c = 0; c < 7; c++)
    {
      A4GL_debug ("Data : %s %d\n", codes[c], data[c]);
    }
#endif

  A4GL_debug ("Internals....");
  data[0] = ival->i_years;
  data[1] = ival->i_months;
  data[2] = ival->i_days;
  data[3] = ival->i_hours;
  data[4] = ival->i_minutes;
  data[5] = ival->i_seconds;
  data[6] = ival->i_fractions;
   *isneg=ival->is_neg;
  A4GL_debug("Y %d M %d D %d  H %d M %d S %d F %d", data[0], data[1], data[2], data[3], data[4], data[5], data[6]);

}


/* ==================================== EOF =========================== */
