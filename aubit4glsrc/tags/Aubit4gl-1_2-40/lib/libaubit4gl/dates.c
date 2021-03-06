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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: dates.c,v 1.30 2010-06-21 17:56:03 mikeaubury Exp $
#
*/

/**
 * @file
 * Date functions.
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

/* #define DIGIT_ALIGN_LEFT */

int y2ktype = -1;
//extern int errno;

static int days_in_month[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/*
struct s_days {
	char *full_name;
	char *short_name;
} day_names[]={
	{"Sunday","Sun"},
	{"Monday","Mon"},
	{"Tuesday","Tue"},
	{"Wednesday","Wed"},
	{"Thursday","Thu"},
	{"Friday","Fri"},
	{"Saturday","Sat"}
};
*/

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/* leap year -- account for gregorian reformation in 1752 */
#define	leap_year(yr) \
	((yr) <= 1752 ? !((yr) % 4) : \
	(!((yr) % 4) && ((yr) % 100)) || !((yr) % 400))

/* number of centuries since 1700, not inclusive */
#define	centuries_since_1700(yr) \
	((yr) > 1700 ? (yr) / 100 - 17 : 0)

/* number of centuries since 1700 whose modulo of 400 is 0 */
#define	quad_centuries_since_1700(yr) \
	((yr) > 1600 ? ((yr) - 1600) / 400 : 0)

/* number of leap years between year 1 and this year, not inclusive */
#define	leap_years_since_year_1(yr) \
	((yr) / 4 - centuries_since_1700(yr) + quad_centuries_since_1700(yr))

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void day_array (int, int, int *);
int A4GL_day_in_year (int, int, int);
int A4GL_y2kmode (int yr);

static long gen_dateno2 (int day, int month, int year);
static int get_yr (int d);
int A4GL_get_month (int d);
int A4GL_days_in_month (int m, int y);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
int
A4GL_date_sep (int z)
{
  if (z == '/' || z == '-' || z == '.' || z==A4GL_get_dbdate_separator())
    return 1;
  return 0;
}

/**
 * @return the 1 based day number within the year
 */
int
A4GL_day_in_year (day, month, year)
     int day, month, year;
{
  int i, leap;

  leap = leap_year (year);
  for (i = 1; i < month; i++)
    day += days_in_month[leap][i];
  return (day);
}

/**
 * @return the 0 based day number for any date from 1 Jan. 1 to
 *	31 Dec. 9999.  Assumes the Gregorian reformation eliminates
 *	3 Sep. 1752 through 13 Sep. 1752.  Returns Thursday for all
 *	missing days.
 */
int
A4GL_day_in_week (day, month, year)
     int day, month, year;
{
  long temp;

  temp = (long) (year - 1) * 365 + leap_years_since_year_1 (year - 1) + A4GL_day_in_year (day, month, year);
  if (temp < 0)
    {				// Before year 1
      return 0;
    }
  if (temp < FIRST_MISSING_DAY)
    return ((temp - 1 + SATURDAY) % 7);
  if (temp >= (FIRST_MISSING_DAY + NUMBER_MISSING_DAYS))
    return (((temp - 1 + SATURDAY) - NUMBER_MISSING_DAYS) % 7);
  return (THURSDAY);
}

/**
 * Generate a date in the internal format (long)
 *
 * @param day The day of the month
 * @param month The month of the year
 * @param year The year
 *
 * @return The date in internal format
 */
static long
gen_dateno2 (int day, int month, int year)
{
  long temp;
  if (month < 1 || month > 12)
    {
#ifdef DEBUG
      A4GL_debug ("Invalid Month");
#endif
      return DATE_INVALID;
    }
  if (day < 1)
    {
#ifdef DEBUG
      A4GL_debug ("Invalid date (<1)");
#endif

      return DATE_INVALID;
    }
  if (day > days_in_month[leap_year (year)][month])
    {
#ifdef DEBUG
      A4GL_debug ("Invalid date (>month end)");
#endif
      return DATE_INVALID;
    }

  if (year < 0 || year > 9999)
    return DATE_INVALID;

  temp = (long) (year - 1) * 365 + leap_years_since_year_1 (year - 1) + A4GL_day_in_year (day, month, year);
  return temp - EPOCH;
}

/**
 * Generate a date in the internal format (long)
 *
 * @param day The day of the month
 * @param month The month of the year
 * @param year The year
 *
 * @return The date in internal format
 */
long
A4GL_gen_dateno (int day, int month, int year)
{
  long z;
#ifdef DEBUG
  {
    A4GL_debug ("In A4GL_gen_dateno %d %d %d", day, month, year);
  }
#endif
  z = gen_dateno2 (day, month, year);

#ifdef DEBUG
  A4GL_debug ("z=%d\n", z);
#endif
  if (z == DATE_INVALID)
    {
      //A4GL_exitwith ("Invalid date");
#ifdef DEBUG
      A4GL_debug ("Invalid date ? %ld %ld ", z, DATE_INVALID);
#endif
      return z;
    }
  return z;
}

/**
 *  Get the year from a date in the internal format
 *
 *  @param d The date
 *  @return The year
 */
static int
get_yr (int d)
{
  int e;
  int h, l;
#ifdef DEBUG
  A4GL_debug ("D=%d\n", d);
#endif
  if (d == DATE_INVALID)
    return d;
  e = (int) ((double) (d - 13 + EPOCH) / 365.2425) + 1;
  h = A4GL_gen_dateno (31, 12, e);

  if (h == DATE_INVALID)
    return h;

  /*l=gen_dateno(1,1,e); */
  while (1)
    {
      l = h - 365 - leap_year (e) + 1;
      if (d == l || d == h)
	{
	  return e;
	}
      if (d < l)
	{
	  e--;
	  h = l - 1;
	  continue;
	}
      if (d > h)
	{
	  h = h + 365 + leap_year (e);
	  e++;
	  continue;
	}

      break;
    }
  return e;
}


/**
 *  Get the month(?) from a date in the internal format
 *
 *  @param d The date
 *  @return The month (?)
 */
int
A4GL_get_month (int d)
{
  int i, leap;
  int year;
  int day;
  if (d == DATE_INVALID)
    return d;
  year = get_yr (d);
  day = d - A4GL_gen_dateno (1, 1, year) + 1;
  if (day == DATE_INVALID)
    {
      return day;
    }
  leap = leap_year (year);
  for (i = 1; i <= 12; i++)
    {
      day -= days_in_month[leap][i];
      if (day <= 0)
	{
	  day += days_in_month[leap][i];
	  break;
	}
    }
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_date (int d, int *day, int *mn, int *yr)
{
  int i, leap;
  int year;
#ifdef DEBUG
  A4GL_debug ("d=%d\n", d);
#endif
  *day = 0;
  *mn = 0;
  *yr = 0;
  if (d == DATE_INVALID)
    return 0;
  year = get_yr (d);
#ifdef DEBUG
  A4GL_debug ("YEAR = %d\n", year);
#endif
  *day = d - A4GL_gen_dateno (1, 1, year) + 1;

  if (*day == DATE_INVALID)
    return 0;

  leap = leap_year (year);
#ifdef DEBUG
  A4GL_debug ("leap=%d\n", leap);
#endif
  for (i = 1; i <= 12; i++)
    {
      *day -= days_in_month[leap][i];
      if (*day <= 0)
	{
	  *day += days_in_month[leap][i];
	  break;
	}
    }
  *mn = i;
  *yr = year;
#ifdef DEBUG
  A4GL_debug ("All done..");
#endif
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_modify_year (int a)
{
#ifdef DEBUG
  /* {DEBUG} */
  {
#ifdef DEBUG
    A4GL_debug ("Modify year");
#endif
  }
#endif
  a = A4GL_y2kmode (a);
  return a;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_y2kmode (int yr)
{
  char *ptr;
  int z;
  int year;


#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("y2kmode");
  }
#endif
  if (yr > 99)
    {
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("Year is ok");
      }
#endif
      return yr;
    }

  if (y2ktype == -1)
    {
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("y2ktype not set");
      }
#endif
      ptr = acl_getenv ("AUBIT_Y2K");
      if (ptr == 0)
	y2ktype = 50;
      else
	y2ktype = atoi (ptr);
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("y2ktype set to %d", y2ktype);
      }
#endif
      if (y2ktype == 0)
	y2ktype = 50;
    }

  /* y2ktypes
     +n (n<100) - set to nearest year using +n years from today as limit for future
     -n (n>-100) - set to nearest year using -n from today as limit for past
     (note: -25 = +75 )
     eg
     year=1997
     n=20, anything after 17 will be taken as historic, anything less than= 17 is future
     n=-20, anything before 77 will be taken as future, anything greater than= 77 is in the past, 69=2069, 79=1979, 0 = 2000

     XX00 - always use century XX
     999  - Do not add anything - dealing with AD 0-99
     -999 - use current century
   */

  /*
     time(&nw);
     local_time = localtime(&nw);
   */

  /* this is right ! - not y2k specific  epoch = 1899 */


  /* year = local_time->tm_year + 1900;  *//*DEBUGGING */
  year = 1997;

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Y2K1");
  }
#endif
  if (y2ktype == 999)
    {
      return yr;
    }

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Y2K2");
  }
#endif
  if (y2ktype == -999)
    {
      return yr + year - (year % 100);
    }

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Y2K3");
  }
#endif
  if (y2ktype >= 1000 && y2ktype % 100 == 0)
    {
      yr += y2ktype;
      return yr;
    }

  if (y2ktype > 0 && y2ktype < 100)
    {
      z = (year + y2ktype) % 100;
      if (yr > z)
	return year - (year % 100) + yr;
      else
	return year - (year % 100) + 100 + yr;
    }

  if (y2ktype < 0 && y2ktype > -100)
    {
      z = (year + y2ktype) % 100;
      if (yr >= z)
	return year - (year % 100) + yr;
      else
	return year - (year % 100) + 100 + yr;
    }

  return 0;

}


int
A4GL_days_in_month (int m, int y)
{
  int leap;
  leap = leap_year (y);
  return days_in_month[leap][m];
}




int
A4GL_get_date_from_formatted_date (char *format, char *data)
{
  int m = -1;
  int d = -1;
  int y = -1;
  int ytype = 0;
  char fmt_internal[2000];
  char data_internal[2000];
  char buff[200];
  int a;



  memset (fmt_internal, 0, sizeof (fmt_internal));
  memset (data_internal, 0, sizeof (data_internal));
  strcpy (fmt_internal, format);
  strcpy (data_internal, data);

  A4GL_trim (data_internal);
  A4GL_trim (fmt_internal);

if (strlen(data)==0) {
	return 0;
}

  for (a = 0; a < strlen (fmt_internal); a++)
    {
      if (fmt_internal[a] == 'y' && fmt_internal[a + 1] == 'y' && fmt_internal[a + 2] == 'y' && fmt_internal[a + 3] == 'y')
	{
	  // Got a 4 digit year...
	  buff[0] = data_internal[a];
	  buff[1] = data_internal[a + 1];
	  buff[2] = data_internal[a + 2];
	  buff[3] = data_internal[a + 3];
	  buff[4] = 0;
	  y = atol (buff);
	  fmt_internal[a] = ' ';
	  fmt_internal[a + 1] = ' ';
	  fmt_internal[a + 2] = ' ';
	  fmt_internal[a + 3] = ' ';
	  ytype = 4;
	}

      if (fmt_internal[a] == 'm' && fmt_internal[a + 1] == 'm' && fmt_internal[a + 2] == 'm' && m == -1)
	{
	  int mno;
	// 2 digit month
	  strcpy (buff, &data_internal[a]);
	  for (mno = 1; mno <= 12; mno++)
	    {
	      char *full_month;
		char buff_srch[200];
	        char buff_got[200];
	      full_month = A4GL_find_str_resource_int ("_MON", mno);
		strcpy(buff_srch,full_month);
		strncpy(buff_got,&data_internal[a], strlen (full_month));
		buff_got[ strlen (full_month)]=0;
a4gl_upshift(buff_got);
a4gl_upshift(buff_srch);
		if (strcmp (buff_got, buff_srch) == 0)
		{
		  m = mno;
		  break;
		}
	    }
	  if (m != -1)
	    {
	      fmt_internal[a] = ' ';
	      fmt_internal[a + 1] = ' ';
	      fmt_internal[a + 2] = ' ';
	    }
	}


      if (fmt_internal[a] == 'd' && fmt_internal[a + 1] == 'd' && fmt_internal[a + 2] == 'd')
	{
	// 3 digit day..
	  fmt_internal[a] = ' ';
	  fmt_internal[a + 1] = ' ';
	  fmt_internal[a + 2] = ' ';
	}

      if (fmt_internal[a] == 'd' && fmt_internal[a + 1] == 'd' && d == -1)
	{
	// 2 digit day
	  buff[0] = data_internal[a];
	  buff[1] = data_internal[a + 1];
	  buff[2] = 0;
	  d = atol (buff);
	  fmt_internal[a] = ' ';
	  fmt_internal[a + 1] = ' ';
	}


      if (fmt_internal[a] == 'm' && fmt_internal[a + 1] == 'm' && m == -1)
	{
	  buff[0] = data_internal[a];
	  buff[1] = data_internal[a + 1];
	  buff[2] = 0;
	  m = atol (buff);
	  fmt_internal[a] = ' ';
	  fmt_internal[a + 1] = ' ';
	}

     if (A4GL_date_sep(fmt_internal[a]=='.')) {
		// If we've got any of these - and we've got a number at that position - its not
		// a match on the format...
		if (data[a]>='0' && data[a]<='9') {
			return 0;
		}
	}


      if (fmt_internal[a] == 'y' && fmt_internal[a + 1] == 'y' && y == -1)
	{
	  // 2 digit year...
	  buff[0] = data_internal[a];
	  buff[1] = data_internal[a + 1];
	  buff[2] = 0;
	  y = atol (buff);
          if (y) {y=A4GL_y2kmode(y);}
	  fmt_internal[a] = ' ';
	  fmt_internal[a + 1] = ' ';
	}
    }


if (m!=-1 && d!=-1 && y!=-1) {
	int dno;
	char *ptr;
	// So - we think we've got it sorted
	// does using this date result in this date string with this format ? 
	dno= A4GL_gen_dateno(d,m,y);
	ptr= A4GL_using_date(dno,format);
	if (strcasecmp(ptr,data)==0) {
		// Cool - we found it!
			return dno;
	}
}

return 0;

}

/* ============================= EOF =============================== */
