/*
	CSTRC.c  -  String manipulation related functions

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

#include <string.h>
#include <sqltypes.h>

#define SHORTSTRSIZE 133
#define SPACES " \t"

char *fgw_popquote();

/*
**  reformats a string so that it's right margined to the specified
**  length, plus returns starting non included char
*/
str_rightmargin(nargs)
int nargs;
{
    char bf[SHORTSTRSIZE],obf[SHORTSTRSIZE];
    int	d,i,j,k,l,m;
    int oi,oj,wc,iw;

    popint(&l);
    if (l>sizeof(bf)-1 || l<1)
	l=sizeof(bf)-1;
    popquote(bf, l+1);
    oi=0;
    i=0;
    j=0;
    d=1;
    wc=0;
    iw=1;
    while (d)
/*
**  hard CR - leave line unmargined
*/
	if ((bf[j]=='\n') || (bf[j]=='\r'))
	{
	    obf[i]=0;	
	    fgw_clip(obf);
	    i=strlen(obf);
	    j++;
	    goto done;
	}
/*
**  tab - move to next tab stop
*/
	else if (bf[j]=='\t')
	{
	    j++;
	    oj=j;
	    iw=1;
	    wc=0;
	    do
	    {
		oi=i;
		obf[i++]=' ';
		d=(i<=l);
	    } while ((i & 7) && (d));
	}
/*
**  space
*/
	else if (bf[j]==' ')
	{
	    oi=i;
	    obf[i++]=bf[j++];
	    oj=j;
	    iw=1;
	    d=(i<=l);
	}
/*
** plain printable char
*/
	else if ((bf[j]>' ') && (bf[j]<'\177'))
	{
	    obf[i++]=bf[j];
	    if (iw)
	    {
		wc++;
		iw=0;
	    }
	    d=(i<=l);
	    if (d)
		j++;
	}
/*
**  non printable char - just skip
*/
	else if (bf[j])
	    j++;
/*
**  end of string
*/
	else d=0;
    if ((--i!=oi) && (wc>1))
    {
	wc--;
	i=oi;
	j=oj;
    }
    obf[i]=0;
    fgw_clip(obf);
    i=strlen(obf);
/*
**  if more than one word, we have to remargin the string
*/
    if (wc>1)
    {
        wc--;
	iw=(l-i)/wc;
	m=(l-i)%wc;
	if (m) iw++;
	if (m>1) m--;
	k=i;
	d=l;
/*
**  while there are words, and we have space left
*/
	while ((wc) && (d-k))
	{
/*
**  pull current word to the right
*/
	    while (obf[k]!=' ')
		obf[d--]=obf[k--];
/*
**  and the spaces in the string
*/
	    while (obf[k]==' ')
		obf[d--]=obf[k--];
/*
**  still words left?
*/
	    if (--wc)
	    {
/*
**  fill with spaces
*/
		for (i=iw;i;i--)
		    obf[d--]=' ';
/*
** and adjust next word spacing
*/
		if (m)
		{
		    m--;
		    if (!m) iw--;
		}
	    }
/*
** no, just put spaces
*/
	    else while (d-k) obf[d--]=' ';
    	}
	i=l;
    }
done:
    retint(i);
    retint(j);
    retquote(obf);
    return(3);
}

/*
**  returns the position of a substring within a string
*/
pos(nargs)
int nargs;
{
    short i, j, k;
    char *str1;
    char *str2;

    str2=fgw_popquote();
    str1=fgw_popquote();
    retint(fgw_pos(str1, str2));
    free(str1);
    free(str2);
    return(1);
}

/*
**  returns the position of a char within a string
*/
poschr(nargs)
int nargs;
{
    short i, j, k;
    char *str1;
    char str2[2];

    popquote(str2, sizeof(str2));
    str1=fgw_popquote();
    retint(fgw_pos(str1, str2));
    free(str1);
    return(1);
}

/*
**  returns the position of the first of a set of chars within a string
*/
posbrk(nargs)
int nargs;
{
    char *str1;
    char str2[SHORTSTRSIZE];
    char *p;

    popquote(str2, sizeof(str2));
    str1=fgw_popquote();
    fgw_clip(str2);
    if ((p=strpbrk(str1, str2))==NULL)
	retint(0);
    else
	retint(p-str1+1);
    free(str1);
    return(1);
}
/*
**  returns the position of the first char not in a set  within a string
*/
posnbrk(nargs)
int nargs;
{
    short i;
    char *str1;
    char str2[SHORTSTRSIZE];

    popquote(str2, sizeof(str2));
    str1=fgw_popquote();
    fgw_clip(str2);
    if ((i=strspn(str1, str2))==strlen(str1))
	retint(0);
    else
	retint(i+1);
    free(str1);
    return(1);
}

/*
**  returns argument's first token & rest of string
*/
postoken(nargs)
int nargs;
{
    int i, c, r;
    char *p;
    char *bf;
    char sep[SHORTSTRSIZE];

    p="";
    rsetnull(CINTTYPE, (char *) &r);
    popquote(sep, sizeof(sep));
    if (bf=fgw_popquote())
	if ((i=strspn(bf, sep))!=strlen(bf))
	{
	    p=bf+i;
	    i+=strcspn(p, sep);
	    c=*(bf+i);
	    *(bf+i)=0;
	    if (c)
		r=i+2;
	}
    retquote(p);
    retint(r);
    if (bf)
	free(bf);
    return(2);
}

/*
**  returns argument's first token & rest of string
*/
get_token(nargs)
int nargs;
{
    int i, c;
    char *p,*q;
    char *bf;

    p="";
    q="";
    if (bf=fgw_popquote())
	if ((i=strspn(bf, SPACES))!=strlen(bf))
	{
	    p=bf+i;
	    i+=strcspn(p, SPACES);
	    c=*(q=bf+i);
	    *q=0;
	    if (c)
	    {
		++q;
		q+=strspn(q, SPACES);
	    }
	}
    retquote(p);
    retquote(q);
    if (bf)
	free(bf);
    return(2);
}

/*
**  returns the length of the initial matching segment of two strings
*/
str_compare(nargs)
int nargs;
{
    char *s1, *s2;
    char *c1, *c2;
    int i;

    s2=fgw_popquote();
    s1=fgw_popquote();
    for (c1=s1, c2=s2, i=0; *c1 && *c2; i++)
	if (*c1++!=*c2++)
	    break;
    free(s1);
    free(s2);
    retint(i);
    return(1);
}
