/**
 * @file
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*  ***************************************************************************
* (c) 1997-1998 Aubit Computing Ltd.
*
* $Id: read_dty.c,v 1.1 2002-04-17 00:01:36 afalout Exp $
*
* Project : Part Of Aubit 4GL Library Functions
*
* Change History :
*	$Log: not supported by cvs2svn $
*	Revision 1.4  2002/02/17 21:10:50  saferreira
*	Commented code
*	
*	Revision 1.3  2001/12/07 18:20:07  mikeaubury
*	dl stuff
*	
*	Revision 1.2  2001/11/29 22:26:59  saferreira
*	Some more warnings fixed and Doxygen comments added
*	
*	Revision 1.1.1.1  2001/08/20 02:36:26  afalout
*	Initial import to SF
*	
*	Revision 1.3  2001/06/12 03:37:30  afalout
*	make install, make clean
*	
*	Revision 1.2  2000/09/28 02:42:21  afalout
*	*** empty log message ***
*	
*	Revision 1.1.1.1  2000/01/29 03:11:50  cvs
*	Initial import of compiler sources using jCVS client
*	
*	Revision 1.3  1998/12/24 08:05:53  fglcomp
*	.
*
*	Revision 1.2  1998/08/09 11:51:48  fglcomp
*	Added ID classifications
*
*
*******************************************************************************/
#include <stdio.h>
#include "../libincl/dbform.h"
#include "../libincl/stack.h"


static split_half(char *str,char *str1,char *str2)
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

static split_tab_col_type(char *str,char *str1,char *str2,char *str3)
{
	split_half(str,str2,str3);
	split_half(str2,str1,str2);
}


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
get_dtype(char *tabname, char *colname,char *dbname,char *tablist[]) {
	FILE *ifile;
	char buff[132];
	char tab[20];
	char col[20];
	char dtype[20];
	char size[20];
	int a,b;
        int dd;
        int fs;
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


