/*
	CSQOC.c  -  Sql interpreter output/format support functions

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Jan 97
	Current release: Jun 02

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

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <datetime.h>
#include <decimal.h>
#include <locator.h>
#include <sqlda.h>
#include <sqlstype.h>
#include <sqltypes.h>
#include <varchar.h>
#include "ccmnc.h"
#include "cascc.h"
#include "cfioc.h"
#include "chstc.h"
#include "csqdc.h"
#include "csqec.h"
#include "csqoc.h"

#define STARTENTRYSIZE	10

#define FLD_NEXT 0
#define FLD_NL 1
#define FLD_TAB 2
#define FLD_BLANK 3
#define FLD_STRING 4
#define FLD_4gl 5
#define FLD_date 6
#define FLD_s 7
#define FLD_i 8
#define FLD_f 9
#define FLD_NFMT -1

fgw_fmttype *fgw_fmtstart();
char *fgw_fmtnew();
fgw_listtype stlist =
{
    NULL, NULL, 0, 0, EBADSTMT
};

extern sqlva *nexttoken_sql();
extern int status;

static ffheaders_sql();
static vertical_sql();
static oneperline_sql();
static fullformat_sql();
static brief_sql();
char *col2str_sql();
static double col2dub_sql();
static int col2int_sql();
static char *blobfixup_sql();
static format_sql();
static rightmargin_sql();
static leftmargin_sql();
static strlen_sql();
static addstring_sql();
static padline_sql();

static int fgw_fieldcount=0;
static fgw_fdesc *ofd=NULL;
static int txtoffset=0;
static int txtlines=0;

/*
** sets output stream
*/
sql_openfile(txtvar, fd)
loc_t *txtvar;
fgw_fdesc *fd;
{
    ofd=fd;
    if (ofd && ofd!=(fgw_fdesc *) -1)
    {
	txtoffset=txtvar->loc_size;
	txtlines=fgw_text(txtvar)->nolines;
    }
}

/*
** flushes output stream
*/
sql_flush(txtvar, all)
loc_t *txtvar;
int all;
{
    int l;
 
    if (!(txtvar->loc_size-txtoffset) || !ofd)
	return;
    if (ofd==(fgw_fdesc *)-1)
    {
	txtlines=0;
	txtoffset=0;
	txtvar->loc_size=0;
	fgw_recompindex(txtvar, 0);
    }
    if (all || *(txtvar->loc_buffer+txtvar->loc_size-1)=='\n')
	l=txtvar->loc_size;
    else
	l=fgw_text(txtvar)->textindex[fgw_text(txtvar)->nolines-1];
    if (l-txtoffset)
    {
/*
** FIXME: formalize IO error handling. right now a display will fail
** a select might survive
*/
	fgw_fdwrite(ofd, txtvar->loc_buffer+txtoffset, l-txtoffset);
	fgw_move(txtvar->loc_buffer+txtoffset, txtvar->loc_buffer+l,
	    txtvar->loc_size-l);
	txtvar->loc_size-=(l-txtoffset);
	fgw_recompindex(txtvar, txtlines);
    }
}

/*
**  parse & set format specifiers
*/
sql_setformat(st_p, f)
fgw_stmttype *st_p;
char *f;
{
    char *p, *q, *s, *t, *e;
    int l, et;
    int explicit; /* true if all columns have an explicit field delimiter */
    int html;	  /* true if there's no explicit formatting */
    int field, fieldlen;
    int fieldpos, templen;
    int haveheader, implicit;

/*
**  Overall goal is to have a FLD_NFMT length for headers whose field size
**  cannot be readily recognised. DO_MOD to avoid problems (?) with %
*/
#define SET_HEADER_SIZE(arg1, arg2) arg1=(arg1==FLD_NFMT||arg2==FLD_NFMT)? FLD_NFMT: arg1+arg2
#define DO_MOD(arg1, arg2) (arg1==FLD_NFMT)? 0: arg1 % arg2

    if (f==NULL ||
	st_p==NULL)
    {
	status=EBADSTMT;
        rsetnull(CINTTYPE, (char *) &explicit);
        return explicit;
    }
    status=0;
    st_p->formats=fgw_fmtstart();
    s=f;
    field=0;
    fieldlen=0;
    fieldpos=0;
    implicit=0;
    explicit=1;
/*
**  there's a couple of places where we should set html and we don't
**  truth is, it either doesn't break the logic, or it isn't really necessary
*/
    html=1;
    haveheader=st_p->headers? st_p->headers->entries: 0;
    while (t=strpbrk(s, "|%\\\n\t["))
    {
/*
**  see if we have a string to save, first
*/
	if (l=t-s)
	    if (p=fgw_fmtnew(&st_p->formats, l+1))
	    {
		strncpy(p, s, l);
		*(p+l)=0;
		html=html && (strspn(p, " ")==l);
		st_p->formats->fmt[st_p->formats->entries-1].etype=FLD_STRING;
		SET_HEADER_SIZE(fieldlen, l);
	    }
	switch (*t)
	{
/*
**  backslash only applies to t & n, anything else we just skip it
**  it will not escape %, [, and |
*/
	  case '\\':
	    if (*(++t)=='n')
		goto TOKEN_n;
	    else if (*t!='t')
	    {
		s=t;
		break;
	    }
/*
**  a real TAB
*/
	  case '\t':
	    html=0;
	    if (!fgw_fmtadd(&st_p->formats, NULL))
	    {
		status=-1319;
		return 0;
	    }
	    st_p->formats->fmt[st_p->formats->entries-1].etype=FLD_TAB;
	    l=DO_MOD((fieldlen+fieldpos), st_p->width);
	    SET_HEADER_SIZE(fieldlen, 8*(1+l/8));
	    s=++t;
	    break;
/*
**  a real NL
*/
	  case '\n':
TOKEN_n:
	    html=0;
	    if (!fgw_fmtadd(&st_p->formats, NULL))
	    {
		status=-1319;
		return 0;
	    }
/*
**  for NL we just pretend the current line is filled with blanks
*/
	    st_p->formats->fmt[st_p->formats->entries-1].etype=FLD_NL;
	    l=DO_MOD((fieldlen+fieldpos), st_p->width);
	    SET_HEADER_SIZE(fieldlen, st_p->width-l);
	    s=++t;
	    break;
/*
**  a format specifier or field delimiter
*/
	  case '[':
	  case '%':
	  case '|':
/*
**  see if it is escaped
*/
	    if (*t==*(t+1))
	    {
		if (!(p=fgw_fmtnew(&st_p->formats, 2)))
		{
		    status=-1319;
		    return 0;
		}
		st_p->formats->fmt[st_p->formats->entries-1].etype=FLD_STRING;
		*p++=*t;
		*p=0;
		s=t+2;
		break;
	    }
/*
**  set start, entry & length as if this was an invalid entry
*/
	    e=t;
	    l=1;
	    et=FLD_STRING;
	    s=t+1;
	    templen=1;
/*
**  a c format specifier
*/
	    if (*t=='%')
	    {
		if (p=strpbrk(t, "diouxXeEfgs"))
		{
/*
**  determine the type...
*/
		    switch (*p)
		    {
		      case 's':
			et=FLD_s;
			break;
		      case 'e':
		      case 'E':
		      case 'f':
		      case 'g':
			et=FLD_f;
			break;
		      default:
			et=FLD_i;
		    }
/*
**  ...the length of the formatted string...
*/
		    e=t;
		    while(!isdigit(*e) && e<p)
			e++;
		    if (p-e)
			templen=atoi(e);
		    else
			templen=FLD_NFMT;
/*
**  ...and start, length, new scan ptr
*/
		    l=p-t+1;
		    e=t;
		    s=p+1;
		    implicit++;
		}
	    }
/*
**  a 4gl format specifier
*/
	    else if (*t=='[')
	    {
/*
**  find specifier terminator
*/
		q=t;
		do
		{
		   p=strpbrk(q, "]");
		   e=q+1;
		}
/*
**  skipping escaped ones
*/
		while (p && *(p+1)==*p);
		if (p)
		{
/*
**  found it, set stuff as above
*/
		    e=t+1;
		    l=p-t-1;
		    s=p+1;
		    et=FLD_4gl;
		}
		templen=l;
		implicit++;
	    }
/*
**  format specifiers might act as implicit field separators
*/
	    if (*t=='|' || (et!=FLD_STRING && implicit>1))
	    {
		explicit=explicit && (*t=='|');
/*
** if explicit fields, then the implicit count starts from 0
** otherwise, we are about to put a field, so implicit is one already
*/
		implicit=(*t!='|');
		if (haveheader)
		{
		    st_p->headers->fmt[field].etype=fieldlen;
		    haveheader=st_p->headers->entries>field+1;
		}
/*
**  reset field info
*/
		if (fieldlen+fieldpos>st_p->width)
		    fieldpos=(fieldlen+fieldpos) % st_p->width;
		else if  (fieldlen!=FLD_NFMT)
		    fieldpos=fieldlen;
		else
		    fieldpos=0;
		fieldlen=0;
		field++;
		if (!fgw_fmtadd(&st_p->formats, NULL))
		{
		    status=-1319;
		    return 0;
		}
		st_p->formats->fmt[st_p->formats->entries-1].etype=FLD_NEXT;
	    }
/*
**  field separator, we're thru with this one
*/
	    if (*t=='|')
		continue;
/*
**  we have the format entry, go store it
*/
	    if (!(p=fgw_fmtnew(&st_p->formats, l+1)))
	    {
		status=-1319;
		return 0;
	    }
	    strncpy(p, e, l);
	    *(p+l)=0;
/*
**  for formats with 0 length, we have a special entry
*/
	    if (!templen)
		et=FLD_BLANK;
#ifdef BROKEN_DATE_FORMATTING
/*
**  try to figure out whether this is a date format
*/
	    else if (et==FLD_4gl)
		if (q=strpbrk(p, "dmy"))
		    if (*q==*++q)
			et=FLD_date;
#endif
	    st_p->formats->fmt[st_p->formats->entries-1].etype=et;
	    SET_HEADER_SIZE(fieldlen, templen);
	}
    }
/*
**  enter any remainder string
*/
    if (l=strlen(s))
	if (p=fgw_fmtnew(&st_p->formats, l+1))
	{
	    strcpy(p, s);
	    st_p->formats->fmt[st_p->formats->entries-1].etype=FLD_STRING;
	    SET_HEADER_SIZE(fieldlen, l);
	}
/*
**  field width is saved only to make sure that last header does not exceed
**  prescribed width
*/
    if (haveheader && fieldlen)
	st_p->headers->fmt[field].etype=fieldlen;
    return (explicit || html);
}

/*
**  sets next header
**  for headers, etype carries the width of each header.
**  for this scheme to work, all the headers should be in place
**  before calling sql_setformat
*/
sql_setheader(st_p, c)
fgw_stmttype *st_p;
char *c;
{
    char *d;
    int l;

    if (st_p==NULL)
	return;
    if (!st_p->headers)
    {
	st_p->headers=fgw_fmtstart();
	st_p->headwidth=0;
    }
    l=strlen(c);
    if (!(d=fgw_fmtnew(&st_p->headers, l)))
	status=-1319;
    else
    {
	strcpy(d, c); 
	if (strlen(c)>st_p->headwidth)
	    st_p->headwidth=strlen(c);
	st_p->headers->fmt[st_p->headers->entries-1].etype=FLD_NFMT;
    }
}

/*
**  gets pre & post row/header/columns html strings
*/
sql_setstrings(st_p, s)
fgw_stmttype *st_p;
char **s;
{
    int i;
    char **s1;

    s1=s;
    for (i=0; i<8; i++)
    {
/*
** To simplify field wrap logic HTML stuff is always NL terminated
** so that headers & fields always start at column 0
*/
	if (strlen(s[i]))
	    *s1=strcat(*s1, "\n");
    }
    if (st_p==NULL)
	return;
    if (st_p->pretable)
    {
	free(st_p->pretable);
	free(st_p->posttable);
	free(st_p->prerow);
	free(st_p->postrow);
	free(st_p->preheader);
	free(st_p->postheader);
	free(st_p->prefield);
	free(st_p->postfield);
    }
    st_p->postfield=*s++;
    st_p->prefield=*s++;
    st_p->postheader=*s++;
    st_p->preheader=*s++;
    st_p->postrow=*s++;
    st_p->prerow=*s++;
    st_p->posttable=*s++;
    st_p->pretable=*s++;
}

/*
**  sets field count flags (HTML only)
*/
sql_countfields(st_p, countfields, clear)
fgw_stmttype *st_p;
int countfields, clear;
{
    if (st_p==NULL)
	return;
    st_p->countfields=countfields;
    if (clear)
	if (countfields && st_p->headers)
	    fgw_fieldcount=st_p->headers->entries;
	else
	    fgw_fieldcount=0;
}

/*
**  gets field count (HTML only)
*/
sql_fieldcount()
{
    return fgw_fieldcount;
}

/*
**  sets output width
*/
sql_setwidth(st_p, w)
fgw_stmttype *st_p;
int w;
{
    if (st_p==NULL)
	return;
    if (w<MINWIDTH)
	st_p->width=MINWIDTH;
    else if (w>MAXWIDTH)
	st_p->width=MAXWIDTH;
    else
	st_p->width=w;
}

/*
**  executes a statement
*/
sql_dorows(st_p, textvar, vars, finish)
fgw_stmttype *st_p;
loc_t *textvar, *vars;
{
    int display;

    display=st_p->fmt_type!=FMT_NULL;
    if (fgw_testtext(textvar))
    {
	status=-717;
	return 0;
    }
    if (st_p==NULL)
	return 0;
    if (st_p->curstate==ST_NEWLYOPENED)
    {
	if (!nextrow_sql(st_p))
	    return 0;
	if (display && st_p->pretable)
	    addstring_sql(textvar, st_p->pretable);
	if (display && st_p->fmt_type==FMT_FULL)
	    ffheaders_sql(st_p, textvar);
    }
    else if (st_p->curstate!=ST_OPENED)
    {
	status=EBADSTMT;
	return 0;
    }
    else if (!nextrow_sql(st_p))
    {
	finish=1;
	goto allrows_end;
    }
/*
** stores values into vars, if needs be the case
*/
    if (st_p->intovars)
    {
	int fld_id=0;
	sqlva *col;
	double d;
	fgw_tsstype *into=st_p->intovars;

	while (into && (col=nexttoken_sql(fld_id++, st_p)))
	{
	    switch (col->sqltype)
	    {
	      case CDATETYPE:
	      case SQLDATE:
		fgw_hstadd(vars, &into->string,
			CDATETYPE, (char *) col->sqldata);
		break;
	      case CINTTYPE:
	      case SQLINT:
		fgw_hstadd(vars, &into->string,
			CINTTYPE, (char *) col->sqldata);
		break;
	      case SQLBYTES:
		fgw_hstadd(vars, &into->string,
			CSTRINGTYPE, "");
		break;
	      case SQLTEXT:
		fgw_hstadd(vars, &into->string,
			CSTRINGTYPE, blobfixup_sql((loc_t *) col->sqldata));
		break;
	      case CSTRINGTYPE:
	      case CVCHARTYPE:
		fgw_hstadd(vars, &into->string,
			CSTRINGTYPE, (char *) col->sqldata);
		break;
	      case CDTIMETYPE:
	      case SQLDTIME:
		fgw_hstadd(vars, &into->string,
			CDTIMETYPE, (char *) col->sqldata);
		break;
	      case CINVTYPE:
	      case SQLINTERVAL:
		fgw_hstadd(vars, &into->string,
			CINVTYPE, (char *) col->sqldata);
		break;
	      case CDECIMALTYPE:
	      case SQLDECIMAL:
		fgw_hstadd(vars, &into->string,
			CDECIMALTYPE, (char *) col->sqldata);
		break;
	      case CMONEYTYPE:
	      case SQLMONEY:
		fgw_hstadd(vars, &into->string,
			CMONEYTYPE, (char *) col->sqldata);
		break;
	      default:
		d=col2dub_sql(col);
		fgw_hstadd(vars, &into->string,
			CDOUBLETYPE, (char *) &d);
	    }
	    into=into->next;
	}
    }
    if (display)
	switch(st_p->fmt_type)
	{
	  case FMT_BRIEF:
	    do
	    brief_sql(st_p, textvar);
		while (finish && nextrow_sql(st_p));
	    break;
	  case FMT_FULL:
	    fullformat_sql(st_p, textvar, finish);
	    break;
	  case FMT_VERTICAL:
	    do
	    vertical_sql(st_p, textvar);
		while (finish && nextrow_sql(st_p));
	    break;
	}
allrows_end:
    if (display && finish && st_p->posttable)
	addstring_sql(textvar, st_p->posttable);
    if (st_p->field>fgw_fieldcount && st_p->countfields)
	fgw_fieldcount=st_p->field;
    return (!finish);
}

/*
**  expression display initialization
*/
sql_initdisplay(st_p, textvar)
fgw_stmttype *st_p;
loc_t *textvar;
{
    if (st_p==NULL)
	return;
    if (st_p->pretable)
	addstring_sql(textvar, st_p->pretable);
    if (st_p->fmt_type==FMT_FULL)
	ffheaders_sql(st_p, textvar);
    if (st_p->prerow)
	addstring_sql(textvar, st_p->prerow);
    st_p->field=0;
    st_p->format=0;
}

/*
**  expression display
*/
sql_display(st_p, textvar, col)
fgw_stmttype *st_p;
loc_t *textvar;
struct sqlvar_struct *col;
{
    char *f, b[MAXNUMLEN];

    switch(st_p->fmt_type)
    {
	  case FMT_BRIEF:
	    f=col2str_sql(col, &b);
	    if (((!st_p->field)+strlen_sql(textvar, fgw_text(textvar)->nolines)+
		 strlen(f))<=st_p->width)
	    {
		if (st_p->field)
		    addstring_sql(textvar, ",");
		addstring_sql(textvar, f);
	    }
	    st_p->field++;
	    break;
	  case FMT_FULL:
	    if (st_p->prefield)
		addstring_sql(textvar, st_p->prefield);
	    st_p->format=format_sql(textvar, col, st_p->formats, st_p->format,
				    st_p->width, 0);
	    if (st_p->postfield)
		addstring_sql(textvar, st_p->postfield);
	    st_p->field++;
	    break;
	  case FMT_VERTICAL:
	    if (st_p->prefield)
		oneperline_sql(st_p, textvar, col, 0);
	    else
		oneperline_sql(st_p, textvar, col, st_p->headwidth);
    }
}

/*
**  expression display wrap up
*/
sql_enddisplay(st_p, textvar)
fgw_stmttype *st_p;
loc_t *textvar;
{
    if (st_p->postrow)
    {
	addstring_sql(textvar, st_p->postrow);
	if (st_p->fmt_type==FMT_VERTICAL)
	    addstring_sql(textvar, "\n");
    }
    else
	addstring_sql(textvar, "\n");
    if (st_p->posttable)
	addstring_sql(textvar, st_p->posttable);
    if (st_p->field>fgw_fieldcount && st_p->countfields)
	fgw_fieldcount=st_p->field;
    sql_flush(textvar, 0);
}

/*
**  outputs full format headers
*/
static ffheaders_sql(st_p, textvar)
fgw_stmttype *st_p;
loc_t *textvar;
{
    char *f, *p, *q;
    int c, i, r;

/*
**  first row is headers, if HTML, not too much of a problem
*/
    if (st_p->headers)
    {
	if (st_p->prerow)
	    addstring_sql(textvar, st_p->prerow);
	if (st_p->preheader)
	    for (c=0; c<st_p->headers->entries; c++)
	    {
		if (st_p->headers->fmt[c].etype)
		{
		    addstring_sql(textvar, st_p->preheader);
		    addstring_sql(textvar, st_p->headers->fmt[c].entry);
		    addstring_sql(textvar, st_p->postheader);
		}
	    }
	else
/*
**  plain text, here
*/
	    for (c=0; c<st_p->headers->entries; c++)
	    {
		r=fgw_text(textvar)->nolines;
/*
**  we have some kind of format - in which case, the length of the field
**  has already been worked out in sql_setformat. will enter the header
**  padded to that length
*/
		if (st_p->headers->fmt[c].etype==FLD_NFMT)
		{
/*
** no format for this header - just stick it in
*/
		    addstring_sql(textvar, st_p->headers->fmt[c].entry);
		    addstring_sql(textvar, " ");
		}
		else if (st_p->headers->fmt[c].etype)
		{
/*
**  make sure that the header does not exceed the calculated width
*/
		    if (p=(char *) malloc(20))
		    {
			if (q=(char *) malloc(st_p->headers->fmt[c].etype+1))
			{
			    sprintf(p, "%%-%i.%is",
				    st_p->headers->fmt[c].etype,
				    st_p->headers->fmt[c].etype);
			    sprintf(q, p, st_p->headers->fmt[c].entry);
			    addstring_sql(textvar, q);
			    free(q);
			}
			free(p);
		    }
		}
/*
**  and now, make sure we do not exceed the maximum width
**  rightmargin_sql will also get rid of extra spaces we have created
**  to take into account NL's. Not entirely efficient, but this is only
**  done once, so who cares
*/
		while ((i=rightmargin_sql(textvar, r++, st_p->width, 0))>0);
		if (i)
		    return;
	    }
	if (st_p->postrow)
	    addstring_sql(textvar, st_p->postrow);
	else
	    addstring_sql(textvar, "\n");
    }
}

/*
**  vertical format
*/
static vertical_sql(st_p, textvar)
fgw_stmttype *st_p;
loc_t *textvar;
{
    sqlva *col;
    int o;
    int doable;

    if (st_p->prefield)
	o=0;
    else
	o=st_p->headwidth;
    st_p->field=0;
    st_p->format=0;
    if (st_p->prerow)
	addstring_sql(textvar, st_p->prerow);
    while (col=nexttoken_sql(st_p->field, st_p))
	oneperline_sql(st_p, textvar, col, o);
    if (st_p->postrow)
	addstring_sql(textvar, st_p->postrow);
    addstring_sql(textvar, "\n");
    sql_flush(textvar, 0);
}

/*
**  one field per line field output
*/
static oneperline_sql(st_p, textvar, col, o)
fgw_stmttype *st_p;
loc_t *textvar;
sqlva *col;
int o;
{
    int s;
    int doable;

/*
** headers first, if we have them
*/
    doable=(!st_p->headers) || (st_p->headers->entries<=st_p->field) ||
	   (st_p->headers->fmt[st_p->field].etype);
    if (st_p->preheader && doable)
	 addstring_sql(textvar, st_p->preheader);
    s=o+1;
    if (st_p->headers && doable && st_p->headers->entries>st_p->field)
    {
	addstring_sql(textvar,
		      st_p->headers->fmt[st_p->field].entry);
/*
**  work out how much padding we might need
*/
	s-=strlen(st_p->headers->fmt[st_p->field].entry);
    }
    if (doable)
	if (st_p->postheader)
	    addstring_sql(textvar, st_p->postheader);
	else if (o)
	    padline_sql(textvar, s);
/*
**  and then the actual field
*/
    if (st_p->prefield && doable)
	addstring_sql(textvar, st_p->prefield);
    st_p->format=format_sql(textvar, col, st_p->formats, st_p->format,
			    st_p->width, o);
    if (doable)
	if (st_p->postfield)
	    addstring_sql(textvar, st_p->postfield);
	else
	    addstring_sql(textvar, "\n");
    st_p->field++;
}

/* FIXME: plain full mode with headers but missing field format might want to
   trim field to header width? (not last header) */
/*
**  full format mode
*/
static fullformat_sql(st_p, textvar, finish)
fgw_stmttype *st_p;
loc_t *textvar;
int finish;
{
    sqlva *col;
    char *p, *q;
    int c, i, r;

    st_p->format=0;
/*
**  output next format
*/
    do
    {
	st_p->field=0;
	if (!st_p->formats && st_p->prerow && !st_p->format)
	    addstring_sql(textvar, st_p->prerow);
/*
**  format all fields
*/
	while (col=nexttoken_sql(st_p->field, st_p))
	{
	    st_p->field++;
	    if (st_p->prefield)
		addstring_sql(textvar, st_p->prefield);
	    st_p->format=format_sql(textvar, col, st_p->formats, st_p->format,
				    st_p->width, 0);
	    if (st_p->postfield)
		addstring_sql(textvar, st_p->postfield);
	}
/*
**  are we through with this format?
*/
	if (!st_p->formats || st_p->format>=st_p->formats->entries)
	{
	    if (st_p->postrow)
		addstring_sql(textvar, st_p->postrow);
	    else
		addstring_sql(textvar, "\n");
	    sql_flush(textvar, 0);
	    if (finish)
		st_p->format=0;
	    else
		return;
	}
    }
    while (nextrow_sql(st_p));
}

/*
**  brief format
*/
static brief_sql(st_p, textvar)
fgw_stmttype *st_p;
loc_t *textvar;
{
    sqlva *col;
    char *f;
    char b[MAXNUMLEN];
    int ml, ll, l;

    ml=st_p->width;
    ll=0;
    st_p->field=0;
    while ((col=nexttoken_sql(st_p->field++, st_p))!=NULL)
    {
	f=col2str_sql(col, &b);
	l=strlen(f);
	if (ll+l>ml)
	   break;
	if (ml!=st_p->width)
	    addstring_sql(textvar, ",");
	addstring_sql(textvar, f);
	ml=st_p->width-1;
	ll+=l;
    }
    addstring_sql(textvar, "\n");
    sql_flush(textvar, 0);
}

/*
**  conversion functions follow: I have tried a push column pop correct type
**  approach, but while shorter, it was much slower (by about a factor of 30!)
**
**  converts col to string
*/
char *col2str_sql(col, b)
sqlva *col;
char *b;
{
    int s;
    char *c;

    if (risnull(col->sqltype, (char *) col->sqldata))
	return "";
    switch(col->sqltype)
    {
      case CDECIMALTYPE:
      case SQLDECIMAL:
/* FIXME: I should probably handle DBMONEY here */
      case CMONEYTYPE:
      case SQLMONEY:
	s=2+2*(((dec_t *) col->sqldata)->dec_ndgts>((dec_t *) col->sqldata)->dec_exp?
	       ((dec_t *) col->sqldata)->dec_ndgts : ((dec_t *) col->sqldata)->dec_exp);
       	if (dectoasc((dec_t *) col->sqldata, b, s, -1))
	    *b='\0';
	else
	{
	    c=b+s;
	    while (*--c==' ');
	    *++c='\0';
	}
	break;
      case CDOUBLETYPE:
      case SQLFLOAT:
	sprintf(b, "%f", *(double *) col->sqldata);
	break;
      case CINTTYPE:
      case SQLINT:
	sprintf(b, "%i", *(int *) col->sqldata);
	break;
      case CDTIMETYPE:
      case SQLDTIME:
	dttoasc((dtime_t *) col->sqldata, b);
	break;
      case CINVTYPE:
      case SQLINTERVAL:
	intoasc((intrvl_t *) col->sqldata, b);
	break;
      case CDATETYPE:
      case SQLDATE:
	rdatestr(*(int *) col->sqldata, b);
	break;
      case CSTRINGTYPE:
      case CVCHARTYPE:
	return (char *) col->sqldata;
      case SQLBYTES:
	return "";
      case SQLTEXT:
	return blobfixup_sql((loc_t *) col->sqldata);
    }
    return b;
}

/*
**  converts col to a double
*/
double col2dub_sql(col)
sqlva *col;
{
    double d;
    if (risnull(col->sqltype, (char *) col->sqldata))
    {
	rsetnull(CDOUBLETYPE, (char *) &d);
	return d;
    }
    switch (col->sqltype)
    {
      case SQLINT:
      case CINTTYPE:
      case SQLDATE:
      case CDATETYPE:
	d=*(int *) col->sqldata;
	break;
      case CDECIMALTYPE:
      case CMONEYTYPE:
      case SQLDECIMAL:
      case SQLMONEY:
	if (!dectodbl((dec_t *) col->sqldata, &d))
	   break;
	goto cantconvert;
      case SQLFLOAT:
      case CDOUBLETYPE:
	return *(double *) col->sqldata;
/* FIXME: need to convert directly */
      case CDTIMETYPE:
      case SQLDTIME:
	pushdtime((dtime_t *) col->sqldata);
	popdub(&d);
	break;
      case CINVTYPE:
      case SQLINTERVAL:
	pushinv((intrvl_t *) col->sqldata);
	popdub(&d);
	break;
      case CSTRINGTYPE:
      case CVCHARTYPE:
	if (!rstod((char *) col->sqldata, &d))
	    break;
	goto cantconvert;
      case SQLTEXT:
	if (!rstod(blobfixup_sql((loc_t *) col->sqldata), &d))
	    break;
      default:
cantconvert:
	rsetnull(CDOUBLETYPE, (char *) &d);
    }
    return d;
}

/*
**  converts col to int
*/
static int col2int_sql(col)
sqlva *col;
{
    int i;

    if (risnull(col->sqltype, (char *) col->sqldata))
    {
	rsetnull(CINTTYPE, (char *) &i);
	return i;
    }
    switch (col->sqltype)
    {
      case SQLINT:
      case CINTTYPE:
      case SQLDATE:
      case CDATETYPE:
	return *(int *) col->sqldata;
      case CDECIMALTYPE:
      case CMONEYTYPE:
      case SQLDECIMAL:
      case SQLMONEY:
	if (!dectoint((dec_t *) col->sqldata, &i))
	   break;
	goto cantconvert;
      case SQLFLOAT:
      case CDOUBLETYPE:
	i=*(double *) col->sqldata;
	break;
/* FIXME: need to convert directly */
      case CDTIMETYPE:
      case SQLDTIME:
	pushdtime((dtime_t *) col->sqldata);
	popint(&i);
	break;
      case CINVTYPE:
      case SQLINTERVAL:
	pushinv((intrvl_t *) col->sqldata);
	popint(&i);
	break;
      case CSTRINGTYPE:
      case CVCHARTYPE:
	if (!rstoi((char *) col->sqldata, &i))
	    break;
	goto cantconvert;
      case SQLTEXT:
	if (!rstoi(blobfixup_sql((loc_t *) col->sqldata), &i))
	    break;
      default:
cantconvert:
	rsetnull(CINTTYPE, (char *) &i);
    }
    return i;
}

/*
**  0 terminates blob column buffer
*/
char *blobfixup_sql(b)
loc_t *b;
{
    char *c;

    if (!b->loc_buffer || !b->loc_size || b->loc_indicator)
	return "";
    if (b->loc_bufsize==b->loc_size)
	if (!(c=(char *) realloc(b->loc_buffer, b->loc_bufsize+1)))
	    return "";  /* maybe I should just return loc_size-1 bytes? */
	else
	{
	    b->loc_buffer=c;
	    b->loc_bufsize++;
	}
    *(b->loc_buffer+b->loc_size)='\0';
    return b->loc_buffer;
}

/*
**  format field
*/
static format_sql(t, col, flist, fidx, rl, ro)
loc_t *t;
sqlva *col;
fgw_fmttype *flist;
int fidx, rl, ro;
{
    int tok, nl, i, r;
    double d;
    char fld[MAXNUMLEN];
    char *p;

    nl=0;
    do
    {
	r=fgw_text(t)->nolines;
/*
** no format entry, here
*/
	if (!flist || fidx>=flist->entries)
	{
/*
** if not first field & fully formatted, leave a space here
*/
	    if (fidx && !ro)
		addstring_sql(t, " ");
	    addstring_sql(t, col2str_sql(col, &fld));
	    tok=FLD_NEXT;
	}
/*
** if valid format entry
*/
	else if ((tok=flist->fmt[fidx].etype)!=FLD_NEXT)
	{
/*
** if start of line & offset, pad with blanks here
*/
	    if (nl && ro)
	    {
		nl--;
		padline_sql(t, ro);
		r++;
	    }
	    fld[0]='\0';		/* in case of formatting errors */
/*
** got a format entry
*/
	    switch (tok)
	    {
	      case FLD_BLANK:
		break;
	      case FLD_NL:
/*
**  drop needless blanks other formats might have left
*/
		p=t->loc_buffer+t->loc_size-1;
		while (t->loc_size && *p--==' ')
		    t->loc_size--;
		addstring_sql(t, "\n");
		nl++;
		break;
	      case FLD_STRING:
		addstring_sql(t, flist->fmt[fidx].entry);
		break;
	      case FLD_TAB:
		if (*(t->loc_buffer+t->loc_size-1)=='\n')
		    i=0;
		else
		    i=strlen_sql(t, r);
		padline_sql(t, 8*(1+i/8)-i);
		break;
	      case FLD_4gl:
/*
**  anything that's not float, int or dec gets converted to a float first
*/
		switch (col->sqltype)
		{
		  case CDOUBLETYPE:
		  case SQLFLOAT:
		    i=rfmtdouble(*(double *) col->sqldata,
		                 flist->fmt[fidx].entry, fld);
		    break;
		  case CDATETYPE:
		  case SQLDATE:
		    i=rfmtdate(*(int *) col->sqldata,
			       flist->fmt[fidx].entry, fld);
		    break;
#ifdef HAS_DTFMT
		  case SQLDTIME:
		  case CDTIMETYPE:
		    i=dttofmtasc((dtime_t *) col->sqldata,
				 fld, sizeof(fld), flist->fmt[fidx].entry);
		    break;
		  case SQLINTERVAL:
		  case CINVTYPE:
		    i=intofmtasc((intrvl_t *) col->sqldata,
				 fld, sizeof(fld), flist->fmt[fidx].entry);
		    break;
#endif
		  case CINTTYPE:
		  case SQLINT:
		    i=rfmtlong(*(int *) col->sqldata,
		               flist->fmt[fidx].entry, fld);
		    break;
		  case CDECIMALTYPE:
		  case SQLDECIMAL:
		  case CMONEYTYPE:
		  case SQLMONEY:
		    i=rfmtdec((dec_t *) col->sqldata,
		              flist->fmt[fidx].entry, fld);
		    break;
		  default:
		    i=rfmtdouble(col2dub_sql(col),
		                 flist->fmt[fidx].entry, fld);
		}
		if (!i)
		    addstring_sql(t, fld);
		break;
#ifdef BROKEN_DATE_FORMATTING
	      case FLD_date:
		if (col->sqltype!=SQLDATE && col->sqltype!=CDATETYPE)
		    status=rstrdate(col2str_sql(col, &fld), &i);
		else
		    i=*(int *) col->sqldata;
		if (!rfmtdate(i, flist->fmt[fidx].entry, fld))
		    addstring_sql(t, fld);
		break;
#endif
	      case FLD_s:
/*
**  for string formats, first resize the buffer
*/
		switch (col->sqltype)
		{
		  case SQLTEXT:
		    i=((loc_t *) col->sqldata)->loc_size;
		    break;
		  case SQLBYTES:
		    i=0;
		    break;
		  case CSTRINGTYPE:
		  case CVCHARTYPE:
		    i=col->sqllen;
		    break;
		  default:
		    i=MAXNUMLEN;
		}
		if (fgw_resizebuffer(t, i))
		{
		    status=-1319;
		    return;
		}
/*
**  then format & recompute index
*/
		sprintf(t->loc_buffer+t->loc_size, flist->fmt[fidx].entry,
			col2str_sql(col, &fld));
		t->loc_size+=strlen(t->loc_buffer+t->loc_size);
		if (fgw_text(t)->nolines)
		    i=fgw_text(t)->nolines-1;
		else
		    i=0;
		fgw_recompindex(t, i);
		break;
	      case FLD_i:
                i=col2int_sql(col);
                if (!risnull(SQLINT, (char *) &i))
                {
                    sprintf(fld, flist->fmt[fidx].entry, i);
                    addstring_sql(t, fld);
                }
		break;
	      case FLD_f:
                d=col2dub_sql(col);
                if (!risnull(SQLFLOAT, (char *) &d))
                {
                    sprintf(fld, flist->fmt[fidx].entry, d);
                    addstring_sql(t, fld);
                }
		break;
	    }
	}
/*
**  and now, make sure we do not exceed the maximum width
*/
	while ((i=rightmargin_sql(t, r++, rl, ro))>0);
	if (i)
	    return fidx;
/*
**  and finally, if we had multiple lines (maybe a text blob?)
**  make sure that they are left margined decently
*/
	while ((i=leftmargin_sql(t, r++, rl, ro))>0);
	if (i)
	    return fidx;
	nl=*(t->loc_buffer+t->loc_size-1)=='\n';
	fidx++;
    }
    while (tok!=FLD_NEXT && flist->entries>fidx);
    return fidx;
}

/*
**  right margin specific line in blob
*/
static rightmargin_sql(t, r, rl, ro)
loc_t *t;
int rl, ro;
{
    int i, j, l;
    char *pd, *ps;

    if (r>fgw_text(t)->nolines || !fgw_text(t)->nolines)
	return 0;
    if ((l=strlen_sql(t, r))>rl)
    {
/*
**  see if we have to do clipping
*/
	pd=t->loc_buffer+fgw_text(t)->textindex[r-1]+rl;
	ps=pd;
	i=1;
	j=rl;
	while (j-- && *--pd==' ')
	    i--;
	pd++;
/*
**  resizing might be necessary
*/
	if (fgw_resizebuffer(t, i+ro))
	{
		status=-1319;
		return -1;
	}
/*
**  make room for NL & padding
*/
	fgw_move(pd+ro+1, ps, t->loc_size-fgw_text(t)->textindex[r-1]-rl);
/*
**  adj blob size
*/
	t->loc_size+=i+ro;
/*
**  add NL & padding
*/
	*pd++='\n';
	i=ro;
	while (i--)
	    *pd++=' ';
/*
** finally recompute line index
*/
	fgw_recompindex(t, r-1);
	return 1;
    }
    return 0;
}

/*
**  left & optionally right margin specific line in blob
*/
static leftmargin_sql(t, r, rl, ro)
loc_t *t;
int r, rl, ro;
{
    int i, l, nl, lo;
    char *pd, *ps;

    if (r>fgw_text(t)->nolines || !fgw_text(t)->nolines)
	return 0;
    l=strlen_sql(t, r);
    if (l+ro>rl)
    {
	nl=rl;
	i=1;
	lo=l+ro-rl;
    }
    else
    {
	nl=l+ro;
	i=0;
	lo=0;
    }
    ps=t->loc_buffer+fgw_text(t)->textindex[r-1]+nl-ro;
/*
**  either margin or split to do
*/
    if (i || ro)
    {
/*
**  see if we have to do clipping
*/
	while (ps>t->loc_buffer && *--ps==' ')
	    i--;
	ps++;
	pd=ps+i+ro;
/*
**  resizing might be necessary
*/
	if (fgw_resizebuffer(t, i+ro))
	{
	    status=-1319;
	    return -1;
	}
/*
**  make room for NL & padding
*/
	fgw_move(pd, ps, t->loc_size-fgw_text(t)->textindex[r]+lo);
/*
**  adj blob size
*/
	t->loc_size+=i+ro;
/*
**  add a NL
*/
	*--pd='\n';
/*
**  make room for padding;
*/
	pd=t->loc_buffer+fgw_text(t)->textindex[r-1]+ro;
	fgw_move(pd, pd-ro, nl-ro);
/*
**  pad
*/
	i=ro;
	while (i--)
	    *--pd=' ';
/*
** finally recompute line index
*/
	fgw_recompindex(t, r-1);
    }
    return 1;
}

/*
**  returns the length of the last line in the blob
*/
static strlen_sql(t, r)
loc_t *t;
int r;
{
    int s;

    if (!r)
	return 0;
    s=fgw_text(t)->textindex[r]-fgw_text(t)->textindex[r-1];
    if (r<fgw_text(t)->nolines || *(t->loc_buffer+t->loc_size-1)=='\n')
	s--;
    return s;
}

/*
** add a string to text variable
*/
static addstring_sql(textvar, str)
loc_t *textvar;
char *str;
{
    int l, s;

    if (!str)
	return;
    s=strlen(str);
    if (!s)
	return;
    if (fgw_resizebuffer(textvar, s))
    {
	status=-1319;
	return;
    }
    fgw_move(textvar->loc_buffer+textvar->loc_size, str, s);
    textvar->loc_size+=s;
    if (fgw_text(textvar)->nolines)
	l=fgw_text(textvar)->nolines-1;
    else
	l=0;
    fgw_recompindex(textvar, l);
}

/*
**  adds spaces to last line in blob
*/
static padline_sql(textvar, c)
loc_t *textvar;
int c;
{
    int i, l;
    char *p;

    if (c<1)
	return;
    if (fgw_resizebuffer(textvar, c))
    {
	status=-1319;
	return;
    }
    p=textvar->loc_buffer+textvar->loc_size;
    for (i=0; i<c; i++)
	*p++=' ';
    textvar->loc_size+=c;
    if (fgw_text(textvar)->nolines)
	l=fgw_text(textvar)->nolines-1;
    else
	l=0;
    fgw_recompindex(textvar, l);
}

/*
**  allocates a fmt structure
*/
fgw_fmttype *fgw_fmtstart()
{
    fgw_fmttype *h;

    h=(fgw_fmttype *) malloc(sizeof(fgw_fmttype)+
			  (STARTENTRYSIZE-1)*sizeof(fgw_fmtentry));
    h->entries=0;
    h->size=STARTENTRYSIZE;
    return(h);
}

/*
**  adds an entry to a fmt structure
*/
fgw_fmtadd(h, e)
fgw_fmttype **h;
char *e;
{
    fgw_fmttype *s;
    int c;

    if ((*h)->size==(*h)->entries)
    {
	s=*h;
	(*h)->size+=STARTENTRYSIZE;
	if (!(*h=(fgw_fmttype *) realloc(*h, sizeof(fgw_fmttype)+
			((*h)->size-1)*sizeof(fgw_fmtentry))))
	{
/*
** not enough space to realloc - we have lost whatever entry we had in
** the fgw_fmt struct, thus free everything there to avoid a memory leak
*/
	    for (c=0; c<s->entries; c++)
		free(s->fmt[c].entry);
	    return(0);
	}
    }
    (*h)->fmt[(*h)->entries++].entry=e;
    return(1);
}

/*
**  allocates & adds an entry to a fmt structure
*/
char *fgw_fmtnew(h, s)
fgw_fmttype **h;
int s;
{
    char *c;

    if (c=(char *) malloc(s))
	if (!fgw_fmtadd(h, c))
	{
	    free(c);
	    c=NULL;
	}
    return(c);
}

/*
**  deallocates a fmt structure
*/
fgw_fmtclear(h)
fgw_fmttype *h;
{
    int i;

    for (i=0; i<h->entries; i++)
	free(h->fmt[i].entry);
    free(h);
}
