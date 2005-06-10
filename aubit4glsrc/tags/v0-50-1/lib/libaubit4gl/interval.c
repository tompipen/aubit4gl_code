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
# $Id: interval.c,v 1.19 2005-05-18 13:48:41 mikeaubury Exp $
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
  char fractions[6];
  char *buff;
  buff = i->data;

  A4GL_debug ("v1=%d v2=%d v3=%d buff=%p\n", v1, v2, v3, buff);

  A4GL_debug ("Y %d\n", data[0]);
  A4GL_debug ("M %d\n", data[1]);
  A4GL_debug ("D %d\n", data[2]);
  A4GL_debug ("H %d\n", data[3]);
  A4GL_debug ("m %d\n", data[4]);
  A4GL_debug ("S %d\n", data[5]);
  A4GL_debug ("F %d\n", data[6]);
  sprintf (fractions, "%05d", data[6]);

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

  A4GL_debug ("Normalized data %d %d %d %d %d %d %d",
	data[0],
	data[1],
	data[2],
	data[3],
	data[4],
	data[5],
	data[6]
);


  if (v1 >= 7)
    {
      fractions[v1 - 6] = 0;
      A4GL_debug ("Set fractions to %s\n", fractions);
    }

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
    sprintf (buff, "0000000000%0*d%02d%s", v3, data[4], data[5], fractions);

  if (v2 == 6)
    sprintf (buff, "000000000000%0*d%s", v3, data[5], fractions);

  if (v2 >= 7)
    sprintf (buff, "000000000000000%s", fractions);

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


  /*
     inttoc(a, &a_str, mk_int_size(a->stime,a->ltime));
     A4GL_debug("Converted first...");
     A4GL_debug("a=%p b=%p\n",a,b);
     inttoc(b, &b_str, mk_int_size(b->stime,b->ltime));

     A4GL_debug("Converted second...");
     A4GL_debug("INtervals as strings = %s  & %s",a_str,b_str);

     A4GL_valid_int (a_str, data_a,mk_int_size(a->stime,a->ltime));
     A4GL_valid_int (b_str, data_b,mk_int_size(b->stime,b->ltime));
   */

  A4GL_decode_interval (a, data_a);
  A4GL_decode_interval (b, data_b);

  A4GL_debug ("Got interval data");
  /* Clear down the return variable.. */
  for (cnt = 0; cnt < 10; cnt++)
    {
      rval_ival.data[cnt] = '0';
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


  if (mode == 1)
    {				/* we have a number of years in r1 */
      double yd, md;
      int y = 0;
      yd = floor (r1);
      md = (r1 - y) * 12.0;
      data_r[0] = yd;
      data_r[1] = md;

    }
  else
    {
      double sd, fd;
      int s;
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
A4GL_decode_interval (struct ival *ival, int *data)
{
  char buff[256];
  int i;
  int cnt = 0;
  char buff2[64];
  int s1;
  int s2;
  int c;
  int cpc;
  int c2;
  int ltime;

  char *codes[] = { "YEAR", "MONTH", "DAY", "HOUR", "MINUTE",
    "SECOND", "FRACTION",
    0
  };
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

  A4GL_debug ("Decoding interval into component parts");

  for (i = 0; i < 10; i++)
    {
      data[i] = 0;
    }

  s1 = ival->stime % 16;
  s2 = ival->stime / 16;
  A4GL_debug ("s1=%d s2=%d", s1, s2);
  memset(buff,0,sizeof(buff));

  memcpy(buff,ival->data,24);



/*
  sprintf (buff, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
	   ival->data[0], ival->data[1], ival->data[2], ival->data[3],
	   ival->data[4], ival->data[5],
	   ival->data[6], ival->data[7],
	   ival->data[8], ival->data[9],
	   ival->data[10], ival->data[11],
	   ival->data[12], ival->data[13],
	   ival->data[14], ival->data[15],
	   ival->data[16], ival->data[17], ival->data[18],
	   ival->data[19], ival->data[20], ival->data[21],
	   ival->data[22], ival->data[23]);
*/

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

  A4GL_debug ("Internals....");
  data[0] = ival->i_years;
  data[1] = ival->i_months;
  data[2] = ival->i_days;
  data[3] = ival->i_hours;
  data[4] = ival->i_minutes;
  data[5] = ival->i_seconds;
  data[6] = ival->i_fractions;
  A4GL_debug("Y %d M %d D %d  H %d M %d S %d F %d", data[0], data[1], data[2], data[3], data[4], data[5], data[6]);

}


/* ==================================== EOF =========================== */
