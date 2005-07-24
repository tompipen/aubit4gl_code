/*
@(#)File:            $RCSfile: stchar.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Implement st_char() - Compatible with C-ISAM stchar()
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#include <string.h>
#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: stchar.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
** st_char -- copy a null terminated character string into a fixed length
** blank padded field
*/
void st_char(const char *from, char *to, size_t size)
{
	size_t len = strlen(from);
	if (len >= size)
	{
		memcpy(to, from, size);
	}
	else
	{
		memcpy(to, from, len);
		memset(to + len, ' ', size - len);
	}
}

#ifdef TEST

#include <assert.h>
#include <stdio.h>

int main(void)
{
}

#endif /* TEST */
