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
# $Id: dmy.c,v 1.7 2002-06-25 03:22:30 afalout Exp $
#
*/

/**
 * @file
 * Formating dates functions
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

char *g_dnames[]={
"Sun",
"Mon",
"Tue",
"Wed",
"Thu",
"Fri",
"Sat"
};

char *g_dnamesfull[]={
"Sunday",
"Monday",
"Tuesday",
"Wednesday",
"Thursday",
"Friday",
"Saturday"
};


char *g_mnames[]={
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


char *g_mnamesfull[]={
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

char *		dategsub		(char *s,char *r,char *p);
char *		using_date		(int dn,char *us);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *  Format a date in the internal format to a string formated acording to the
 *  using string.
 *
 *  @param dn The numeric date.
 *  @param us The using string.
 *  @return The formated date.
 */
char *
using_date(int dn,char *us)
{
  int d;
  int m;
  int y;
  int dno;
  static char buff[256];
  char buff2[256];

  char *using_strs[]={
    "dddd","ddd","dd","mmmm","mmm","mm","yyyy","yy","th","d","m",""
  };
  char *rusing_strs[]={
    "\nA","\nB","\nC","\nD","\nE","\nF","\nG","\nH","\nI","\nJ","\nK",""
  };

  char rep_strs[20][20];
  int a;
  int flg=0;
  strcpy(buff,us);
  get_date(dn,&d,&m,&y);
  dno=day_in_week(d,m,y);
  /*
  g_dnamesfull[dno]);
  g_dnames[dno]);
  g_mnamesfull[m]);
  g_mnames[m]);
  */

  strcpy(rep_strs[0],(char *)find_str_resource_int("_FDAY",dno));
  strcpy(rep_strs[1],(char *)find_str_resource_int("_DAY",dno));
  sprintf(rep_strs[2],"%02d",d);
  strcpy(rep_strs[3],(char *)find_str_resource_int("_FMON",m));
  strcpy(rep_strs[4],(char *)find_str_resource_int("_MON",m));
  sprintf(rep_strs[5],"%02d",m);
  sprintf(rep_strs[6],"%04d",y);
  sprintf(rep_strs[7],"%02d",y%100);
  debug("--DNO=%d",dno);
  sprintf(rep_strs[8],(char *)find_str_resource_int("_DAYTH",d));
  sprintf(rep_strs[9],"%d",d);
  sprintf(rep_strs[10],"%d",m);

  /* replace the ddmmyy etc with something the user cant have used */
  for (a=0;using_strs[a][0]!=0;a++) {
    strcpy(buff2,dategsub(buff,using_strs[a],rusing_strs[a]));
    strcpy(buff,buff2);
  }
  debug("buff now : %s",buff);
  /* now replace these with what the user wants - this gets around d
  being replaced in wed etc */

  for (a=0;rusing_strs[a][0]!=0;a++) {
    if (strstr(buff,rusing_strs[a])!=0) {
      flg=1;
      strcpy(buff2,dategsub(buff,rusing_strs[a],rep_strs[a]));
      strcpy(buff,buff2);
    }
  }
  debug("Buff now %s\n",buff);
  if (flg==0) return 0;

  return buff;

}



/**
 *
 * @todo Describe function
 */
char *
dategsub(char *s,char *r,char *p)
{
	static char buff[256];
	char buff2[256];
	char buff3[256];
	char *ptr;
	buff[0]=0;
	strcpy(buff2,s);
	while ((ptr=(char *)strstr(buff2,r))) {
	    strncat(buff,buff2,ptr-buff2);
	    strcat(buff,p);
	    strcpy(buff3,ptr+strlen(r));
	    strcpy(buff2,buff3);
	}
	strcat(buff,buff2);
	return buff;
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
get_day(void)
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
get_dayno(void)
{

	return 0;
}

#endif

/* ================================ EOF ============================ */

