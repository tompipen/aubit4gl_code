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
# $Id: read_dty.c,v 1.4 2002-05-20 11:41:12 afalout Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>
#include "a4gl_dbform.h"
#include "a4gl_stack.h"
#include "a4gl_debug.h" //debug()
#include "a4gl_dlsql.h" //A4GLSQL_get_datatype()

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
/*
static void
split_half(char *str,char *str1,char *str2)
{
	char fn[132];
	int a;
	char *ptr;
	strcpy(fn,str);
	for (a=strlen(fn);a>=0;a--) {
		if (fn[a]=='.') {
			fn[a]=0;
			break;
		}
	}
	ptr=&fn[a];
	strcpy(str1,fn);
	if (a>=0) strcpy(str2,ptr+1);
	else str2[0]=0;
}
*/

/**
 *
 * @todo Describe function
 */
/*
static void
split_tab_col_type(char *str,char *str1,char *str2,char *str3)
{
	split_half(str,str2,str3);
	split_half(str2,str1,str2);
}
*/

/**
 * Get the datatype from tables and columns.
 *
 * @param tabname The table name.
 * @param colname The column name.
 * @param dbname The database name.
 * @param tablist
 * @return
 *   - -1 : An error ocurred.
 *   - Otherwise : The datatype found
 */
int
get_dtype(char *tabname, char *colname,char *dbname,char *tablist[])
{
//	FILE *ifile;
//	char buff[132];
//	char tab[20];
//	char col[20];
//	char dtype[20];
//	char size[20];
	int a,b;
//    int dd;
//    int fs;
	b=0;

	if (strlen(tabname)!=0)
		{
		b=A4GLSQL_get_datatype(dbname,tabname,colname);
		if (b>=0 ) return b;
		else return -1;
		}

	if (tablist==0) {
	        debug("Column not found");
	        return -1;
	}

	for (a=0;tablist[a]!=0;a++) {
	    b=get_dtype(tablist[a],colname,dbname,0);
	    if (b>=0) return b;
	}

return -1;
}


//========================= EOF ==============================

