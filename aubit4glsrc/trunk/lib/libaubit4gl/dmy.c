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
# $Id: dmy.c,v 1.10 2003-05-15 07:10:39 mikeaubury Exp $
#
*/

/**
 * @file
 * Formating dates functions
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#ifdef OLD_INCL

#include <string.h>
#include "a4gl_aubit_lib.h"
#include "a4gl_debug.h"

#else

#include "a4gl_libaubit4gl_int.h"

#endif


/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define DDDD 0
#define DDD 1
#define DD 2
#define MMMM 3
#define MMM 5
#define MM 5
#define YYYY 6
#define YY 7

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char *g_dnames[] = {
  "Sun",
  "Mon",
  "Tue",
  "Wed",
  "Thu",
  "Fri",
  "Sat"
};

char *g_dnamesfull[] = {
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};


char *g_mnames[] = {
  "Jan",
  "Feb",
  "Mar",
  "Apr",
  "May",
  "Jun",
  "Jul",
  "Aug",
  "Sep",
  "Oct",
  "Nov",
  "Dec"
};


char *g_mnamesfull[] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_dategsub (char *s, char *r, char *p);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *  Format a date in the internal (long int) format to a string 
 *  formated acording to the using string.
 *
 *  @param dn The numeric date.
 *  @param us The using string (null means use DBDATE)
 *  @return The formated date.
 */
char *
A4GL_using_date (int dn, char *us)
{
  int d;
  int m;
  int y;
  int dno;
  static char buff[256];
  char buff2[256];

  char *using_strs[] = {
    "dddd", "ddd", "dd", "mmmm", "mmm", "mm", "yyyy", "yy", "th", "d", "m", ""
  };
  char *rusing_strs[] = {
    "\nA", "\nB", "\nC", "\nD", "\nE", "\nF", "\nG", "\nH", "\nI", "\nJ",
      "\nK", ""
  };

  char rep_strs[20][20];
  int a;
  int flg = 0;

  /* if no format is given, use DBDATE */
  if ((us == 0) || (*us == '\0'))
    {
      strcpy (buff, A4GL_dbdate_to_using (""));
    }
  else
    {
      strcpy (buff, us);
    }

  A4GL_get_date (dn, &d, &m, &y);
  dno = A4GL_day_in_week (d, m, y);
  /*
     g_dnamesfull[dno]);
     g_dnames[dno]);
     g_mnamesfull[m]);
     g_mnames[m]);
   */

  strcpy (rep_strs[0], (char *) A4GL_find_str_resource_int ("_FDAY", dno));
  strcpy (rep_strs[1], (char *) A4GL_find_str_resource_int ("_DAY", dno));
  sprintf (rep_strs[2], "%02d", d);
  strcpy (rep_strs[3], (char *) A4GL_find_str_resource_int ("_FMON", m));
  strcpy (rep_strs[4], (char *) A4GL_find_str_resource_int ("_MON", m));
  sprintf (rep_strs[5], "%02d", m);
  sprintf (rep_strs[6], "%04d", y);
  sprintf (rep_strs[7], "%02d", y % 100);
  A4GL_debug ("--DNO=%d", dno);
  sprintf (rep_strs[8], (char *) A4GL_find_str_resource_int ("_DAYTH", d));
  sprintf (rep_strs[9], "%d", d);
  sprintf (rep_strs[10], "%d", m);

  /* replace the ddmmyy etc with something the user cant have used */
  for (a = 0; using_strs[a][0] != 0; a++)
    {
      strcpy (buff2, A4GL_dategsub (buff, using_strs[a], rusing_strs[a]));
      strcpy (buff, buff2);
    }

  /* now replace these with what the user wants - this gets around d
     being replaced in wed etc */

  for (a = 0; rusing_strs[a][0] != 0; a++)
    {
      if (strstr (buff, rusing_strs[a]) != 0)
	{
	  flg = 1;
	  strcpy (buff2, A4GL_dategsub (buff, rusing_strs[a], rep_strs[a]));
	  strcpy (buff, buff2);
	}
    }

  if (flg == 0)
    return 0;

  return buff;
}

/**
 *
 * @todo Describe function
 */
char *
A4GL_dategsub (char *s, char *r, char *p)
{
  static char buff[256];
  char buff2[256];
  char buff3[256];
  char *ptr;
  buff[0] = 0;
  strcpy (buff2, s);
  while ((ptr = (char *) strstr (buff2, r)))
    {
      strncat (buff, buff2, ptr - buff2);
      strcat (buff, p);
      strcpy (buff3, ptr + strlen (r));
      strcpy (buff2, buff3);
    }
  strcat (buff, buff2);
  return buff;
}

/*
 * Converts a DBDATE environment variable style date format string
 * (eg. "DMY4/") into the format expected by 'using' (eg. "dd/mm/yyyy")
 *
 * @param	char *dbdate	DBDATE environment string
 * @return	pointer to buffer holding 'using' format string
 */
char *
A4GL_dbdate_to_using (char *dbdate)
{
  static char buff[20];
  char dmy[5] = " mdY";
  int d = 0;
  int m = 0;
  int y = 0;
  char sep;
  char *p;
  char *b;
  int i;

  /* if no dbdate format given, use the current environment variable */
  if ((dbdate == 0) || (*dbdate == '\0'))
    {
      strncpy (buff, A4GL_get_dbdate (), 10);
    }
  else
    {
      strncpy (buff, dbdate, 10);
    }

  /* scan dbdate format string and extract day/month/year positions,
   * the year length (2/4 digit), and the separator character
   */
  sep = '/';
  b = dmy;
  for (p = buff; *p > 0; p++)
    {
      switch (*p)
	{
	case 'd':
	case 'D':
	  if (d == 0)
	    {
	      *(++b) = 'd';
	      d = 1;
	    }
	  break;
	case 'm':
	case 'M':
	  if (m == 0)
	    {
	      *(++b) = 'm';
	      m = 1;
	    }
	  break;
	case 'y':
	case 'Y':
	  if (y == 0)
	    {
	      *(++b) = 'Y';
	      y = 1;
	    }
	  break;
	case '2':
	  if (*b == 'Y')
	    *b = 'y';
	  break;
	case '/':
	case '-':
	case '.':
	case ',':
	  sep = *p;
	  break;
	}
    }
  *(++b) = '\0';

  /* now write 'using' style format string into buff */
  b = buff;
  for (p = dmy, i = 0; *p > 0; p++, i++)
    {
      switch (*p)
	{
	case 'Y':
	  *b++ = 'y';
	  *b++ = 'y';
	  *p = 'y';
	case 'd':
	case 'm':
	case 'y':
	  *b++ = *p;
	  *b++ = *p;
	  break;
	}
      if (i > 0 && i < 3)
	*b++ = sep;
    }
  *b = '\0';

  return buff;
}

/*
 * Returns the current date format string, from (A4GL_)DBDATE (eg. "DMY2-").
 * If this is not set, then it returns the Informix default "MDY4/"
 * It also causes a runtime error if a badly formatted DBDATE is set.
 *
 * @param	void
 * @return	pointer to string holding dbdate format
 *
 */
char *
A4GL_get_dbdate (void)
{
  static char dbdate[10] = "";	// holds current DBDATE value
  char *p;
  int d = 0;
  int m = 0;
  int y = 0;

  /* keep the result in a static buffer, so we only have to
   * work out the format the first time this is called */

  if (dbdate[0] > '\0')
    return dbdate;

  /* try set the date format from (A4GL_)DBDATE */
  strncpy (dbdate, acl_getenv ("DBDATE"), 10);

  /* if still no date format, use Informix default "mdy4/" */
  if (dbdate[0] == '\0')
    {
      strcpy (dbdate, "MDY4/");
      return dbdate;
    }

  /* check the date format is valid - must have one each of D,M,Y */
  for (p = dbdate; (*p > '\0'); p++)
    {
      switch (*p)
	{
	case 'd':
	case 'D':
	  d++;
	  break;
	case 'm':
	case 'M':
	  m++;
	  break;
	case 'y':
	case 'Y':
	  y++;
	  break;
	}
    }

  if (d == 1 && m == 1 && y == 1)
    {
      /* looks good ... */
      return dbdate;
    }

  /* we have an invalid dbdate format - die ... */
  A4GL_set_errm (dbdate);
  A4GL_exitwith ("dmy.c - Invalid DBDATE format: %s");
  exit (1);
  return 0;
}




#ifdef REMOVEME

/**
 * Does nothing.
 *
 * @todo : See if this is used or planed to be.
 *
 * @return Allways 1
 */
int
get_day (void)
{
  return 1;
}

/**
 * Does nothing.
 *
 * @todo : See if this is used or planed to be.
 *
 * @return Allways 0
 */
int
get_dayno (void)
{

  return 0;
}

#endif

/* ================================ EOF ============================ */
