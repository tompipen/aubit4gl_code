/*
	CMATC.c  -  Comparison functions

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

/*
**  returns the max of two ints
*/
maxint(nargs)
int nargs;
{
    int i, j;

    popint(&i);
    popint(&j);
    if (j>i) i=j;
    retint(i);
    return(1);
}

/*
**  returns the min of two ints
*/
minint(nargs)
int nargs;
{
    int i, j;

    popint(&i);
    popint(&j);
    if (i>j) i=j;
    retint(i);
    return(1);
}

/*
**  bitwise and
*/
bwand(nargs)
int nargs;
{
    int a1, a2;

    popint(&a2);
    popint(&a1);
    retint(a2 & a1);
    return(1);
}

/*
**  bitwise or
*/
bwor(nargs)
int nargs;
{
    int a1, a2;

    popint(&a2);
    popint(&a1);
    retint(a2 | a1);
    return(1);
}

/*
**  bitwise negation
*/
bwneg(nargs)
int nargs;
{
    int a1;

    popint(&a1);
    retint(~a1);
    return(1);
}

/*
**  exclusive or
*/
xor(nargs)
int nargs;
{
    int a1, a2;

    popint(&a2);
    popint(&a1);
    retint(a2 ^ a1);
    return(1);
}
