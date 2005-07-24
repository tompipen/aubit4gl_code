/*
	CSQDC.c  -  Sql interpreter dynamic sql support functions

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
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <string.h>
#include <sqlca.h>
#include <sqlda.h>
#include <sqltypes.h>
#include "ccmnc.h"
#include "csqoc.h"
#include "csqdc.h"

extern fgw_fmttype *fgw_fmtstart();
extern char *fgw_fmtnew();
extern char *fgw_popquote();
extern int status;
extern fgw_listtype stlist;

/*
**  execute a statement
*/
int sql_run(i_query, st_p, touch)
char *i_query;
fgw_stmttype *st_p;
int touch;
{
    int r;
    int nr, dummy;

/* FIXME: using 4gl internals */
    _ffunload(st_p->sqlname, "\376", i_query, 0, (struct sqlvar_struct *)0);
    switch (r=sqlca.sqlcode)
    {
      case 0:
      case -363:
      case -416:
	break;
      default:
	if (sql_asktouch(touch))
	{
	    retquote(i_query);
	    if ((nr=fgl_call(sql_immediate, 1))!=1)
	    {
		r=-1320;
		while (nr--)
		    popint(&dummy);
	    }
	    else
		popint(&r);
	    if (!r)
		rsetnull(CINTTYPE, (char *) &r);
	}
	else
	    r=SQLNOTFOUND;
    }
    return r;
}

/*
**  init format data
*/
fgw_stmttype *sql_newstatement()
{
    fgw_stmttype *st_n;

    if ((st_n=(struct fgw_stmt *) malloc(sizeof(struct fgw_stmt)))!=NULL)
    {
	byfill(st_n, sizeof(struct fgw_stmt), 0);
	st_n->width=MINWIDTH;
	st_n->curstate=ST_NEWLYOPENED;
	tmpnam(st_n->sqlname);
	fgw_newentry(st_n, &stlist);
    }
    return st_n;
}

/*
**  free used resources (including temp unload file)
*/
sql_freestatement(st_p)
fgw_stmttype *st_p;
{

    if (st_p)
    {
	if (st_p->intovars)
	    fgw_tssdrop(&st_p->intovars);
	if (st_p->sqlda_ptr)
	    free(st_p->sqlda_ptr);
	if (st_p->sqlbuf)
	    free(st_p->sqlbuf);
	if (st_p->sqlfile)
	    close(st_p->sqlfile);
	if (st_p->sqlname[0])
	    unlink(st_p->sqlname);
	if (st_p->formats)
	    fgw_fmtclear(st_p->formats);
	if (st_p->headers)
	    fgw_fmtclear(st_p->headers);
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
	fgw_dropentry(st_p, &stlist);
    }
}

/*
** sets next placeholder
*/
sql_setholder(st_p, bytevar, c)
fgw_stmttype *st_p;
loc_t *bytevar;
char *c;
{
    status=-999;
}

/*
**  loads next line from unload file
*/
nextrow_sql(st_p)
fgw_stmttype *st_p;
{
    char *p;
    char *buf, *nbuf;
    int l, s;
    int cnt, i;
    sqlva *v;

/*
** avoid work  if error or no file
*/
    if (status || !st_p->sqlname)
	return 0;
/*
** needs buffer & field description
*/
    if (!st_p->sqlbuf)
    {
	if (!(st_p->sqlbuf=(char *) malloc(BUFSIZE)))
	{
	    
	    st_p->sqlname[0]='\0';
	    status=-208;
	    return 0;
	}
	else if ((st_p->sqlfile=fopen(st_p->sqlname, "r"))==NULL)
	{
	    st_p->sqlname[0]='\0';
	    status=-461;
	    return 0;
	}
	st_p->bufsize=BUFSIZE;
    }
/*
** read a linefull
*/
    s=st_p->bufsize-1;
    buf=st_p->sqlbuf;
    while (s)
    {
	if (fgets(buf, s, st_p->sqlfile)==NULL)
	    break;
	l=strlen(buf);
	s-=l;
	buf+=l;
	p=buf-1;
/*
**  drop cr's
*/
	while (*p=='\r' || *p=='\n')
	{
	    buf--;
	    p--;
	    s++;
	}
/*
** if delimiter, we're done
*/
	if (*p=='\376')
	{
	    *++p=0;
	    break;
	}
/*
** if slash, then it's a text column
*/
	else if (*p=='\\')		/* text columns fixup */
	{
	    buf++;
	    *++p='\n';
	    s--;
	}
/*
** if buffer not enough, enlarge it
*/
	if (!s)
	    if (nbuf=(char *) realloc(st_p->sqlbuf, st_p->bufsize+BUFSIZE))
	    {
		st_p->sqlbuf=nbuf;
		buf=nbuf+st_p->bufsize;
		st_p->bufsize+=BUFSIZE;
		s+=BUFSIZE;
	    }
	    else
		break;
    }
/*
** if we have read something, we need to build our sqlda struct
*/
    if (buf!=st_p->sqlbuf)
    {
/*
** we have to allocate it first & count the fields
*/
	if (!st_p->sqlda_ptr)
	{
	    p=st_p->sqlbuf;
	    cnt=0;
	    while (*p)
		if (*p++=='\376')
		    cnt++;
	    if (!(st_p->sqlda_ptr=(struct sqlda *) malloc(sizeof(struct sqlda)+
						     cnt*sizeof(sqlva))))
	    {
		status=-208;
		return 0;
	    }
	    st_p->sqlda_ptr->sqld=cnt;
	    st_p->sqlda_ptr->sqlvar=(sqlva *) ((char *) st_p->sqlda_ptr+
						sizeof(struct sqlda));
/*
** set the type
*/
	    for (i=0, v=st_p->sqlda_ptr->sqlvar; i<cnt; i++, v++)
		v->sqltype=CSTRINGTYPE;
	}
/*
** now fix pointers & lengths
*/
	p=st_p->sqlbuf;
	buf=p;
	for (i=0, v=st_p->sqlda_ptr->sqlvar; i<st_p->sqlda_ptr->sqld; i++, v++)
	{
	    for (; p; p++)
		if (*p=='\376')
		{
		    *p++='\0';
		    break;
		}
	    v->sqllen=strlen(buf)+1;
	    v->sqldata=buf;
	    buf=p;
	}
    }
    st_p->curstate=ST_OPENED;
    return (s<st_p->bufsize-1);
}

/*
** returns next field in unload buffer
*/
sqlva *nexttoken_sql(field, st_p)
int field;
fgw_stmttype *st_p;
{
    sqlva *col;

    if (status ||	/* avoid looping needlessly if allocation error */
	field>=st_p->sqlda_ptr->sqld)
	return NULL;
    return (sqlva *) ((st_p->sqlda_ptr->sqlvar)+field);
}
