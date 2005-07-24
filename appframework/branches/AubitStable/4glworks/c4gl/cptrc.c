/*
	CPTRC.c  -  Report IO functions

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

#ifndef popquote
#define popquote popvchar	/* since this is what we actually need */
#endif

#include <fcntl.h>
#include <stdio.h>
#include <fglrep.h>

FILE *infp;
FILE *outfpsv;

extern int status;
extern struct repdesc *c_rp;

fgw_fpsave()
{
    outfpsv=c_rp->outfp;
}

/*
**  sets a report page length
*/
page_len(nargs)
int nargs;
{
    int l;

    popint(&l);
    c_rp->tot=c_rp->tot-c_rp->plength+l;
    c_rp->plength=l;
/*    outfpsv=c_rp->outfp;
*/    return(0);
}

/*
**  adj report left & right margins
*/
page_adjmargins(nargs)
int nargs;
{
    int lm, rm;

    popint(&rm);
    popint(&lm);
    c_rp->lmargin=lm;
    c_rp->rmargin=rm;
/*
**  4.0 & above
*/
    if (lm>0)
    {
	c_rp->needlmarg=1;
	maybelmarg();
    }
    return(0);
}

/*
**  outputs a printer control string
*/
ptr_put(nargs)
int nargs;
{
    char bf[80];

    popquote(bf, sizeof(bf));
    fgw_clip(bf);
    status=(fputs(bf,outfpsv)==NULL);
    return(0);
}

/*
**  outputs a blob
*/
file_put(nargs)
int nargs;
{
    char c[90];
    char bf[128];
    int i;

    popquote(c, sizeof(c));
    fgw_clip(c);
    infp=fopen(c,"r");
    if (status=(infp==NULL))
	return(0);
    else
    do
    {
	i=fread(bf,1,128,infp);
        status=(fwrite(bf,1,i,outfpsv)!=i);
    } while (i==128);
    fclose(infp);
    return(0);
}
