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
# $Id: dates.c,v 1.6 2002-06-01 11:54:59 afalout Exp $
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

#include <math.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
//#include <unistd.h>
//#include <pwd.h>


#include "a4gl_dbform.h"
#include "a4gl_dates.h"
#include "a4gl_constats.h"
#include "a4gl_stack.h"
#include "a4gl_dtypes.h"
#include "a4gl_debug.h"
#include "a4gl_aubit_lib.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/* #define DIGIT_ALIGN_LEFT */

int y2ktype=-1;
extern int errno;

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

void			day_array 	(int, int, int *);
//int			day_in_week (int, int, int);
int				day_in_year (int, int, int);
int     		y2kmode		(int yr);

static long 	gen_dateno2	(int day, int month, int year);
static int 		get_yr		(int d);
int 			get_month	(int d);

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
date_sep(int z) 
{
	if (z=='/'||z=='-'||z=='.') return 1;
	return 0;
}

/**
 * @return the 1 based day number within the year
 */
int 
day_in_year(day, month, year)
int day, month, year;
{
	int i, leap;

	leap = leap_year(year);
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
day_in_week(day, month, year)
int day, month, year;
{
	long temp;

	temp = (long)(year - 1) * 365 + leap_years_since_year_1(year - 1)
	    + day_in_year(day, month, year);
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
gen_dateno2(int day, int month, int year)
{
	long temp;
	if (month<1||month>12) return DATE_INVALID;
	if (day<1) return DATE_INVALID;
	if (day>days_in_month[leap_year(year)][month]) return DATE_INVALID;
	temp = (long)(year - 1) * 365 + leap_years_since_year_1(year - 1)
	    + day_in_year(day, month, year);
	return temp-EPOCH;
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
gen_dateno(int day,int month,int year)
{
	int z;
	#ifdef DEBUG
	/* {DEBUG} */ {        debug("In gen_dateno %d %d %d",day,month,year);}
	#endif
	z=gen_dateno2(day,month,year);
	if (z==DATE_INVALID) {
		exitwith("Invalid date");
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
get_yr(int d)
{
	int e;
	int h,l;
        debug("D=%d\n",d);
	if (d==DATE_INVALID||d<1000) return d;
	e=(int)((double)(d-13+EPOCH)/365.2425)+1;
	h=gen_dateno(31,12,e);
	/*l=gen_dateno(1,1,e);*/
	while (1) {
		l=h-365-leap_year(e)+1;
		if (d==l||d==h) {
			return e;
		}
		if (d<l) {
			e--;
			h=l-1;
			continue;
		}
		if (d>h) {
			h=h+365+leap_year(e);
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
get_month(int d)
{
//	int a;
	int i, leap;
	int year;
//	int yr2;
	int day;
	if (d==DATE_INVALID) return d;
	year=get_yr(d);
	day=d-gen_dateno(1,1,year)+1;
	leap = leap_year(year);
	for (i = 1; i <=12; i++) {
		day -= days_in_month[leap][i];
		if (day<=0)  {
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
get_date(int d,int *day,int *mn,int *yr)
{
//	int a;
	int i, leap;
	int year;
        debug("d=%d\n",d);
	if (d==DATE_INVALID||d<10000) return 0;
	year=get_yr(d);
	*day=d-gen_dateno(1,1,year)+1;
	leap = leap_year(year);
	for (i = 1; i <=12; i++) {
		*day -= days_in_month[leap][i];
		if (*day<=0)  {
			*day += days_in_month[leap][i];
			break;
		}
	}
	*mn=i;
	*yr=year;
	return 1;
}

/**
 *
 * @todo Describe function
 */
int
modify_year(int a) 
{
	#ifdef DEBUG
	/* {DEBUG} */ {debug("Modify year");}
	#endif
	a=y2kmode(a);
	return a;
}


/**
 *
 * @todo Describe function
 */
int
y2kmode(int yr)
{
char *ptr;
	int z;
//	struct tm *local_time;
//	time_t nw;
	int year; //yflag; ch, month
//	int zz;

	#ifdef DEBUG
	/* {DEBUG} */ {        debug("y2kmode");}
	#endif
        if (yr>99)
	{
		#ifdef DEBUG
		/* {DEBUG} */ {        debug("Year is ok");}
		#endif
	   return yr;
	}

	if (y2ktype==-1)
	{
		#ifdef DEBUG
		/* {DEBUG} */ {debug("y2ktype not set");}
		#endif
	    ptr=acl_getenv("AUBIT_Y2K");
	    if (ptr==0) y2ktype=50;
		    else y2ktype=atoi(ptr);
		#ifdef DEBUG
		/* {DEBUG} */ {debug("y2ktype set to %d",y2ktype);}
		#endif
	    if (y2ktype==0) y2ktype=50;
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

	/* this is right ! - not y2k specific  epoch = 1899*/


	/* year = local_time->tm_year + 1900;  */ /*DEBUGGING */
	year=1997;

	#ifdef DEBUG
	/* {DEBUG} */ {debug("Y2K1");	}
	#endif
	if (y2ktype==999) {return yr;}

	#ifdef DEBUG
	/* {DEBUG} */ {debug("Y2K2");	}
	#endif
	if (y2ktype==-999) {return yr+year-(year%100);}

	#ifdef DEBUG
	/* {DEBUG} */ {debug("Y2K3");	}
	#endif
	if (y2ktype>=1000&&y2ktype%100==0) 
	{
	  yr+=y2ktype;
	  return yr;
	}

	if (y2ktype>0&&y2ktype<100) 
	{
	    z=(year+y2ktype)%100;
	    if (yr>z) return year-(year%100)+yr;
	    else return year-(year%100)+100+yr;
	}

	if (y2ktype<0&&y2ktype>-100) 
	{
	    z=(year+y2ktype)%100;
	    if (yr>=z) return year-(year%100)+yr;
	    else return year-(year%100)+100+yr;
	}

    return 0;

}


// ============================= EOF ===============================

