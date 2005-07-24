/*
@(#)File:            $RCSfile: ldchar.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Implement ld_char() - Compatible with C-ISAM ldchar()
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#include <assert.h>
#include <string.h>
#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: ldchar.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
** ld_char -- copy a fixed length blank padded field to a null
** terminated string without trailing blanks
*/
size_t ld_char(const char *from, size_t size, char *to)
{
	const char *end = from + size - 1;
	size_t len;

	/* Find last non-blank character (being careful not to underflow) */
	while (end > from && *end == ' ')
		end--;
	if (*end == ' ')
		len = 0;	/* String is wholly blank */
	else
	{
		len = end - from + 1;
		memcpy(to, from, len);
	}
    to[len] = '\0';
	return(len);
}

#ifdef TEST

#include <assert.h>
#include <stdio.h>

int main(void)
{
}

#endif /* TEST */
