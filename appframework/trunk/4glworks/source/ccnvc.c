/*
	CCNVC.c  -  Conversion functions

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Oct 92
	Current release: Jan 02

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include <sqltypes.h>

#ifndef popquote
#define popquote popvchar	/* since this is what we actually need */
#endif

/*
**  converts a ascii char to its int value
**  superseed by ord() in 4.11 and left there for backwards compatibility
*/
char2int(nargs)
int nargs;
{
    short i;
    char c[2];

    popquote(c, sizeof(c));
    i=c[0];
    retshort(i);
    return(1);
}

/*
**  converts a string to an integer
**  (used in place of i=c & whenever error continue, since error goes
**  to the log all the same, as of 4.13)
*/
str2int(nargs)
int nargs;
{
    char n[10], *p;
    int r;

    popquote(n, sizeof(n));
    fgw_clip(n);
    r=strtol(n, &p, 10);
    if (*p)
	rsetnull(CINTTYPE, (char *) &r);
    retint(r);
    return(1);
}
