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

/*
IMPORTANT NOTE:

This code has only been tested on RDS 1.10.03 on a 32 bit machine.
It is thought not to work with RDS 4.00 & above. The following guidelines
should help you get it to work:
1) junk should be 42, as per FAQ, but you'll have to find it out yourself. 
2) left margin handling works differently than in 1.10.03, since it is done
   before the beginning of report control blocks, and not just before printing
   a line. This means that the first row in a report will not have the correct
   left margin. You have three options
   2.1) print a blank line before anything else
   2.2) work out the left margin and pad the first row printed with enough
	spaces
   2.3) use the commented out code in page_adjmargins. This requires that you
	do some detective work to find out where needlmarg is within junk.
*/

typedef struct repdesc
{
	FILE *outfp;		/* output stream */
	short junk[28];		/* unknown       */
	short plength;		/* Page length   */
	short tmargin;		/* Top margin    */
	short bmargin;		/* Bottom margin */
	short lmargin;		/* Left margin   */
	short rmargin;		/* Right margin  */
	short fphlines;		/* Lines in first page header */
	short phlines;		/* Lines in page header */
	short ptlines;		/* Lines in page trailer */
	short junk2;		/* oktoinc?      */
	short tot;
}  Report;

extern Report *currep;		/* Parameters of current report */
extern int status;

FILE *infp;
FILE *outfpsv;

/*
**  sets a report page length
*/
page_len(nargs)
int nargs;
{
    int l;

    popint(&l);
    currep->tot=currep->tot-currep->plength+l;
    currep->plength=l;
    outfpsv=currep->outfp;
    return(0);
}

/*
**  adj report margin
*/
page_adjmargins(nargs)
int nargs;
{
    int lm, rm;

    popint(&rm);
    popint(&lm);
    currep->lmargin=lm;
    currep->rmargin=rm;
/*
**  4.0 & above
*/
/*    if (lm>0)
    {
	currep->needlmarg=1;
	maybelmarg();
    }
*/    return(0);
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
    infp=fopen(c, "r");
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
