/*
	CSQDC.ec  -  Sql interpreter dynamic sql support functions

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

#include <string.h>
#include <sqlca.h>
#include <sqlda.h>
#include <sqlstype.h>
#include <sqltypes.h>
#include <varchar.h>
#include <fglapi.h>
#include "ccmnc.h"
#include "chstc.h"
#include "csqoc.h"

EXEC SQL BEGIN DECLARE SECTION;
EXEC SQL include "csqdc.h";
EXEC SQL END DECLARE SECTION;

extern char *col2str_sql();
extern fgw_fmttype *fgw_fmtstart();
extern char *fgw_fmtnew();
extern int status;
extern fgw_listtype stlist;
static int prepare_sql();
static int immediate_sql();

/*
**  execute a statement
*/
int sql_run(i_query, st_p, touch)
char *i_query;
fgw_stmttype *st_p;
int touch;
{
    int r;

    r=prepare_sql(st_p, i_query);
    if (risnull(CINTTYPE, (char *) &r))
    {
	if (sql_asktouch(touch))
	{
	    r=immediate_sql(st_p);
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
	st_n->curstate=ST_UNINITIALIZED;
        fgw_newentry(st_n, &stlist);
    }
    return st_n;
}

/*
**  free used resources (including temp unload file)
*/
sql_freestatement(st_p)
EXEC SQL BEGIN DECLARE SECTION;
    struct fgw_stmt *st_p;
EXEC SQL END DECLARE SECTION;
{
    int i;
    sqlva *c;
    struct sqlca_s sqlcasave;

/*
** save sqlca for dbinfo/verbose messages
*/
    bycopy((char *) &sqlca, (char *) &sqlcasave, sizeof(sqlca));
    if (st_p)
    {
	if (st_p->curstate>=ST_NEWLYOPENED)
	    EXEC SQL CLOSE :st_p->curname;
	if (st_p->curname[0])
	    EXEC SQL FREE :st_p->curname;
	if (st_p->stmtname[0])
	    EXEC SQL FREE :st_p->stmtname;
	if (st_p->intovars)
	    fgw_tssdrop(&st_p->intovars);
/*
**  output sqlda: look for blob columns & free buffer
*/
	if (st_p->sqlda_ptr)
	{
	    for (i=st_p->sqlda_ptr->sqld, c=st_p->sqlda_ptr->sqlvar;
		 i; i--, c++)
		if ((c->sqltype==SQLTEXT || c->sqltype==SQLBYTES) &&
		    ((loc_t *) c->sqldata)->loc_buffer)
		    free(((loc_t *)c->sqldata)->loc_buffer);
	    free(st_p->sqlda_ptr);
	}
/*
**  input sqlda: look for blob columns & free buffer
*/
	if (st_p->sqlda_in.sqlvar)
	{
	    for (i=st_p->sqlda_in.sqld, c=st_p->sqlda_in.sqlvar;
		 i; i--, c++)
		if (c->sqltype==SQLTEXT &&
		    ((loc_t *) c->sqldata)->loc_mflags)
		    free(((loc_t *) c->sqldata)->loc_buffer);
	    free(st_p->sqlda_in.sqlvar);
	}
	if (st_p->sqlbuf)
	    free(st_p->sqlbuf);
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
    bycopy((char *) &sqlcasave, (char *) &sqlca, sizeof(sqlca));
}

/*
**  prepare statement
*/
static int prepare_sql(st_p, query)
EXEC SQL BEGIN DECLARE SECTION;
fgw_stmttype *st_p;
char *query;
EXEC SQL END DECLARE SECTION;
{
    int r;
EXEC SQL BEGIN DECLARE SECTION;
    struct sqlda *sqlda_ptr;	/* esql/c not so flexible with sqlda's */
    char sname[IDLENGTH];
EXEC SQL END DECLARE SECTION;

    if (query!=NULL &&
	st_p &&
	!(strlen(st_p->stmtname) || strlen(st_p->curname)))
    {
	sprintf(sname, "fgws%i", st_p->st_id);
	EXEC SQL PREPARE :sname FROM :query;
	if ((r=sqlca.sqlcode)<0)
	   goto badexit;
	strcpy(st_p->stmtname, sname);
	EXEC SQL DESCRIBE :st_p->stmtname INTO sqlda_ptr;
	if ((r=sqlca.sqlcode)<0)
	    goto badexit;
	st_p->sqlda_ptr=sqlda_ptr;	/* esql/c not so flexible with sqlda's */
	if (sqlca.sqlcode==0 ||
	    (sqlca.sqlcode==SQ_EXECPROC && st_p->sqlda_ptr->sqld>0))
	{
	    long colsize, bufsize=0;
	    int i;
	    sqlva *c;
/*
** Now's the tricky bit: first we scan the sqlda area converting types &
** adjusting sizes if necessary, adding up the total memory required
*/
	    for (i=st_p->sqlda_ptr->sqld, c=st_p->sqlda_ptr->sqlvar;
		 i; i--, c++)
	    {
		switch (c->sqltype)
		{
		  case CSHORTTYPE:
		  case CINTTYPE:
		  case CLONGTYPE:
		  case SQLSMINT:
		  case SQLINT:
		  case SQLSERIAL:
		    c->sqltype=SQLINT;
		    c->sqllen=sizeof(int);
		    break;
		  case CFLOATTYPE:
		  case CDOUBLETYPE:
		  case SQLFLOAT:
		  case SQLSMFLOAT:
		    c->sqltype=SQLFLOAT;
		    c->sqllen=sizeof(double);
		    break;
		  case CCHARTYPE:
		  case CFIXCHARTYPE:
		  case CSTRINGTYPE:
		  case SQLCHAR:
#ifdef SQLNCHAR
		  case SQLNCHAR:
#endif
		    c->sqltype=CSTRINGTYPE;
		    c->sqllen++;
		    break;
		  case CVCHARTYPE:
		  case SQLVCHAR:
#ifdef SQLNVCHAR
		  case SQLNVCHAR:
#endif
		    c->sqltype=CVCHARTYPE;
		    c->sqllen=VCMAX(c->sqllen)+1;
		    break;
		  case CDECIMALTYPE:
		  case SQLDECIMAL:
		  case CMONEYTYPE:
		  case SQLMONEY:
		  case CDATETYPE:
		  case SQLDATE:
		  case CDTIMETYPE:
		  case SQLDTIME:
		  case CINVTYPE:
		  case SQLINTERVAL:
		  case SQLTEXT:
		  case SQLBYTES:
		    break;
/*
** catch all for UDT's, extended data types etc. known to work with
** 4gl 7.3+, or more generally anything built over CliSDK. Known not
** to work with earlier products.
*/
		  default:
		    c->sqltype=CSTRINGTYPE;
		    c->sqllen=256;
		    break;
		}
		colsize=rtypmsize(c->sqltype, c->sqllen);
		bufsize=rtypalign(bufsize, c->sqltype);
		c->sqldata=(char *) bufsize; /* just an offset for now! */
		bufsize+=colsize;
	    }
/*
** then we allocate memory & fixup the pointers
*/
	    if (!(st_p->sqlbuf=(char *) malloc(bufsize)))
	    {
		r=-717;
		goto badexit;
	    }
	    for (i=st_p->sqlda_ptr->sqld, c=st_p->sqlda_ptr->sqlvar;
		 i; i--, c++)
	    {
		c->sqldata+=(long) (st_p->sqlbuf);
/*
**  text we load in memory, bytes we discard
*/
		switch (c->sqltype)
		{
		  case SQLTEXT:
		    ((loc_t *) c->sqldata)->loc_loctype=LOCMEMORY;
		    ((loc_t *) c->sqldata)->loc_bufsize=-1;
		    ((loc_t *) c->sqldata)->loc_buffer=NULL;
		    ((loc_t *) c->sqldata)->loc_indicator=0;
		    ((loc_t *) c->sqldata)->loc_mflags=0;
		    break;
		  case SQLBYTES:
		    ((loc_t *) c->sqldata)->loc_loctype=LOCMEMORY;
		    ((loc_t *) c->sqldata)->loc_bufsize=0;
		    ((loc_t *) c->sqldata)->loc_buffer=NULL;
		    ((loc_t *) c->sqldata)->loc_indicator=-1;
                }
	    }
	    sname[3]='c';
	    EXEC SQL DECLARE :sname CURSOR FOR :st_p->stmtname;
	    if ((r=sqlca.sqlcode)!=0)
		goto badexit;
	    strcpy(st_p->curname, sname);
	    sqlda_ptr=&(st_p->sqlda_in);	/* esql/c not so flexible with sqlda's */
	    EXEC SQL OPEN :st_p->curname USING DESCRIPTOR sqlda_ptr;
	    if ((r=sqlca.sqlcode)!=0)
		goto badexit;
	    st_p->curstate=ST_NEWLYOPENED;
	}
/*
** Ahhh, must be an insert statement, we have an input sqlda and we have
** placeholders passed to us...
*/
	else if (st_p->sqlda_ptr->sqld &&
		 st_p->sqlda_in.sqld==st_p->sqlda_ptr->sqld)
	{
	    int i;
	    sqlva *s, *d;

/*
** see if we have blobs, we'll build a nice loc_t for them
*/
	    for (i=st_p->sqlda_ptr->sqld, s=st_p->sqlda_ptr->sqlvar,
		 d=st_p->sqlda_in.sqlvar;
		 i; i--, s++, d++)
/*
** we only handle text - better a -617 than to go nullifying bytes silently
*/
	    	if (s->sqltype==SQLTEXT)
		{
		    loc_t *blob;

		    if (!(blob=(loc_t *) malloc(sizeof(loc_t))))
		    {
			r=-208;
			goto badexit;
		    }
		    if (d->sqltype==CSTRINGTYPE)
		    {
			blob->loc_buffer=d->sqldata;
			blob->loc_bufsize=stleng(d->sqldata);
			blob->loc_size=blob->loc_bufsize;
			blob->loc_mflags=0;
		    }
		    else if (blob->loc_buffer=(char *) malloc(MAXNUMLEN))
		    {
			blob->loc_bufsize=MAXNUMLEN;
			col2str_sql(d, blob->loc_buffer);
			blob->loc_size=stleng(blob->loc_buffer);
			blob->loc_mflags=LOC_ALLOC;
		    }
		    else
		    {
			r=-208;
			goto badexit;
		    }
		    blob->loc_indicator=(blob->loc_size<=0? -1: 0);
		    blob->loc_loctype=LOCMEMORY;
		    d->sqltype=s->sqltype;
		    d->sqldata=(char *) blob;
		}
	    free(st_p->sqlda_ptr);
	    st_p->sqlda_ptr=NULL;
	    rsetnull(CINTTYPE, (char *) &r);
	    st_p->curstate=ST_EXECUTABLE;
	}
/*
** just an executable statement with placeholders
*/
	else
	{
	    rsetnull(CINTTYPE, (char *) &r);
	    st_p->curstate=ST_EXECUTABLE;
	}
    }
    else
	r=EBADSTMT;
badexit:
    return r;
}

/*
**  execute non select statement
*/
static int immediate_sql(st_p)
EXEC SQL BEGIN DECLARE SECTION;
fgw_stmttype *st_p;
EXEC SQL END DECLARE SECTION;
{
    int r;
EXEC SQL BEGIN DECLARE SECTION;
    struct sqlda *sqlda_ptr;	/* esql/c not so flexible with sqlda's */
EXEC SQL END DECLARE SECTION;

    rsetnull(CINTTYPE, (char *) &r);
    if (st_p &&
	st_p->curstate==ST_EXECUTABLE)
    {
	sqlda_ptr=&(st_p->sqlda_in);	/* esql/c not so flexible with sqlda's */
	EXEC SQL EXECUTE :st_p->stmtname USING DESCRIPTOR sqlda_ptr;
	r=sqlca.sqlcode;
    }
    else
	r=EBADSTMT;
    return r;
}

/*
** sets next placeholder
*/
sql_setholder(st_p, bytevar, c)
fgw_stmttype *st_p;
loc_t *bytevar;
char *c;
{
    fgw_hstentry *var;
    struct sqlvar_struct *sqlvar;

    if (st_p==NULL)
	return;
    if (!st_p->sqlda_in.sqlvar)
	if (st_p->sqlda_in.sqlvar=(struct sqlvar_struct *)
				malloc(sizeof(struct sqlvar_struct)))
	    sqlvar=st_p->sqlda_in.sqlvar;
	else
	{
	    status=-208;
	    goto badexit;
	}
    else if (sqlvar=(struct sqlvar_struct *) realloc(st_p->sqlda_in.sqlvar,
			(st_p->sqlda_in.sqld+1)*sizeof(struct sqlvar_struct)))
    {
	st_p->sqlda_in.sqlvar=sqlvar;
	sqlvar+=st_p->sqlda_in.sqld;
    }
    else
    {
	status=-208;
	goto badexit;
    }
    byfill(sqlvar, sizeof(struct sqlvar_struct), 0);
/*
**  we leave sqllen to 0 on purpose - the engine will
**  truncate strings or extend datetimes/intervals if necessary
*/
    if (c && (var=fgw_hstget(bytevar, c)))
    {
	sqlvar->sqltype=var->type;
	sqlvar->sqldata=&(var->entry);
    }
    else
    {
	sqlvar->sqltype=CSTRINGTYPE;
	sqlvar->sqldata="";
    }
    st_p->sqlda_in.sqld++;
badexit:
}

/*
**  loads next row
*/
nextrow_sql(st_p)
EXEC SQL BEGIN DECLARE SECTION;
struct fgw_stmt *st_p;
EXEC SQL END DECLARE SECTION;
{
    struct sqlda *sqlda_ptr;	/* esql/c not so flexible with sqlda's */
    if (status)		/* avoid looping needlessly if allocation error */
	return 0;
    sqlda_ptr=st_p->sqlda_ptr;	/* esql/c not so flexible with sqlda's */
    EXEC SQL FETCH :st_p->curname USING DESCRIPTOR sqlda_ptr;
    if (status=sqlca.sqlcode)
	return 0;
    st_p->curstate=ST_OPENED;
    return 1;
}

/*
** returns next field in buffer
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
