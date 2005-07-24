/*
	CRNDC.c  -  random number generator

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
#include <stdio.h>

static unsigned int seed=1;

/*
**  gets next random number
*/
get_rand(nargs)
int nargs;
{
    long i,j;

    popint(&i);
    seed=(0x8088405*seed+1) & 0xFFFF;
    j=seed % i;
    retint(j);
    return(1);
}

/*
**  sets the random generator seed
*/
start_rand(nargs)
int nargs;
{
    int i;

    popint(&i);
    seed=i;
    return(0);
}

/*
**  returns the current seed
*/
say_seed(nargs)
int nargs;
{
    retint(seed);
    return(1);
}

/*
**  asks the system clock for a seed
*/
get_seed(nargs)
int nargs;
{
    int i;

    i=(time(NULL)) & 0xFFFF;
    retint(i);
    return(1);
}
