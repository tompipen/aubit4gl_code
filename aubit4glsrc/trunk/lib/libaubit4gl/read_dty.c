/**
 * @file
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

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


