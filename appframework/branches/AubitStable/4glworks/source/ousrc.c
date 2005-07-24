/*
	OUSRC.c  -  batch job input routines

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Nov 98
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

#include <fcntl.h>
#include <unistd.h>

extern int status;

#ifndef popquote
#define popquote popvchar	/* since this is what we actually need */
#endif

/*
**  gets next char from kbd (needed because prompt starts from
**  screen top)
*/
readchar(nargs)
int nargs;
{
    char c[2];

    c[0]=rgetkey();
    if (c[0]&128)
	c[0]=0;
    c[1]=0;
    retquote(c);
    return(1);
}
