/*
	IDATC.c  -  Freeform to Informix standard date conversion function

	Author:	Art S. Kagel (kagel@bloomberg.com)

	Initial release: ?
	Current release: Jan 98

	Note: 4gl interface, timezone adjustment and some error checking by
	Marco Greco (marco@4glworks.com), who makes no claim whatsoever
	on this code
*/

#ifndef popquote
#define popquote popvchar	/* since this is what we actually need */
#endif

#include <stdio.h>
#include "getdate.h"

extern struct timeval get_date();
extern get_date_err;

long days_in_mo[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
long days_in_lp[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

/*
**  returns time_t time from freeform date (sorry, Art, but I needed this too!)
*/
int get_timet_date(nargs)
int nargs;
{
    char datestr[256];
    struct timeval tv;

    popquote(datestr, 256);
    tv = get_date( datestr, NULL );
    if ( get_date_err )
    {
	retquote("");
	return(1);
    }
    retint(tv.tv_sec);
    return(1);
}
/*
** Convert freeform datetime string to standard Informix datetime
**
** Converts to full Informix precision: YEAR TO FRAC(5) -
** for lesser precisions, grab a substring, or pass thru extend()
** The format is fixed (ie yyyy-mm-dd hh:mm:ss.fffff)
*/
int get_str_date(nargs)
int nargs;
{
    char datestr[256];
    char stdstr[25];
    struct timeval tv;
    long id;         /* Holds Informix format date. */
    int year, month, day, hr, min, sec, ydays, yr, idx;

    popquote(datestr, 256);
/*
** Convert the string to a high resolution format.
** The timeb is more standard but timeval has higher resolution
** 1/(10^6) vs 1/(10^4)
*/
    tv = get_date( datestr, NULL );	/* MG: get_date will use current time */
    if ( get_date_err )
    {
	retquote("");
	return(1);
    }
/*
** account for timezone offset (relies on get_date calling localtime)
*/
    tv.tv_sec -= timezone;
/*
** Cannot use the standard UNIX date routines since they do not recognize 
** dates before 1970.
*/
    id = (tv.tv_sec / 86400) + 25568;
    sec = tv.tv_sec % 60;
    min = (tv.tv_sec / 60) % 60;
    hr  = (tv.tv_sec / 3600) % 24;
/*
** # Days between leap years.  365 * 3 + 366 == 1461
*/
    yr = (id - (id / 1461)) / 365;
    ydays = id - ((yr - 1) / 4 + yr * 365);

    if (((id - (id / 1461)) % 365) == 0 && (ydays == 0 || ydays > 364))
    {
        year = 1900 + yr - 1;
        month = 12;
        day = 31;
    }
    else
    {
        year = 1900 + yr;
        if ( ((year % 400) == 0 && (year % 4000) != 0) /* Skip 4th millenium */
          || ((year % 100) != 0 && (year % 4) == 0))   /* Not centuries. */
        {
/*
** In a leap year use adjusted table.
*/
            for (idx = 11; idx > 0; idx--)
                if (ydays > days_in_lp[idx])
                    break;
            day = ydays - days_in_lp[idx];
        }
        else
        {
            for (idx = 11; idx > 0; idx--)
                if (ydays > days_in_mo[idx])
                    break;
            day = ydays - days_in_mo[idx];
        }
        month = idx + 1;
    }
    sprintf( stdstr, 
            "%04.04d-%02.02d-%02.02d %02.02d:%02.02d:%02.02d.%05.05d", 
            year, 
            month, 
            day, 
            hr, 
            min, 
            sec,
            tv.tv_usec / 10 );
    retquote(stdstr);
    return(1);
}
