/*
	CSQPC.c  -  Sql interpreter interface and outer layer

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Mar 00
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

#include <errno.h>
#include <math.h>
#include <ctype.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include <fglapi.h>
#include <locator.h>
#include <sqlca.h>
#include <sqlda.h>
#include <sqltypes.h>

#include "ccmnc.h"
#include "chstc.h"
#include "csqoc.h"
#include "csqpc.h"

#define BUFSIZE	32768
#define CHARSIZE 32767

extern char *fgw_getvar();
extern int fgw_scanreserved();
extern char *fgw_getstring();
extern int sql_parser();

/*
** 4gl interface
**
** sql_execute entry point
*/
sql_execute(nargs)
int nargs;
{
    char *i_query;
    int def_fd, flags, width;
    loc_t *txtvar;


    poplocator(&txtvar);
    popint(&width);
    popint(&flags);
    popint(&def_fd);
    if (!(i_query=fgw_popquote()))
	retint(-208);
    else
    {
	retint(fgw_sqlexec(i_query, strlen(i_query), def_fd, flags, 
			   width, txtvar));
	free(i_query);
    }
    return(1);
}
/*
** sql_execute2 entry point
*/
sql_execute2(nargs)
int nargs;
{
    loc_t *i_query;
    int def_fd, flags, width;
    loc_t *txtvar;

    poplocator(&txtvar);
    popint(&width);
    popint(&flags);
    popint(&def_fd);
    poplocator(&i_query);
    if (i_query->loc_type!=SQLTEXT || i_query->loc_loctype!=LOCMEMORY)
	retint(-717);
    else if (!i_query->loc_buffer || !i_query->loc_size || i_query->loc_indicator)
	retint(0);
    else
	retint(fgw_sqlexec(i_query->loc_buffer, i_query->loc_size, def_fd,
			   flags, width, txtvar));
    return(1);
}

/*
**  and clear outstanding statements
*/
static fgw_localfree(cs)
controlstack_t *cs;
{
    if (!risnull(CINTTYPE, (char *) &(cs->stmt_id)))
	sql_freestatement(cs->stmt_id);
}
/*
**  preprocessor (expansion, comments, and statement breakup)
*/
fgw_sqlexec(i_query, i_size, def_fd, flags, width, txtvar)
char *i_query;
int def_fd, flags, width;
loc_t *txtvar;
{
    parserstate_t state;		/* passed in bulk to yyparse */
    loc_t vars;				/* byte containing vars */
    int expstart=-1;			/* expansion start & end */
    int expend=-1;			/* (used to optimize while loops */
    int lastcode;			/* sql error */
    int expidx=1;			/* dirty hack not to change cexpl
					   initialization and maximise
					   expansion size (up to almost 32k) */
    int innerloop;

    byfill(&state, sizeof(parserstate_t), 0);
    byfill(&vars, sizeof(loc_t), 0);
    state.i_query=i_query;
    state.i_size=i_size;

    state.vars=&vars;

    state.error_cont=flags & K_errorcont;
    state.verbose=flags & K_verbose;
    state.html=flags & K_html;
/*
**  touch is true if dml+ddl allowed & no user confirmation required
**	     null if user confirmation required
**	     false if only selects allowed
*/
    state.touch=flags & (K_dml+K_noconf);
    if (state.touch==K_dml)
	rsetnull(CINTTYPE, &state.touch);
    else if (state.touch!=K_dml+K_noconf)
	state.touch=0;

    state.width=width;
    state.def_fd=def_fd;
    state.txtvar=txtvar;
/*
**  verbose is positive if interactive client
**	       false if non verbose
**	       negative if batch client - disallows verbose expansions and
**					  skips 'Please wait' interaction
*/
    {
	int isbatch;

/* FIXME: using 4gl interaction */
	fgl_call(usr_isbatch, 0);
	popint(&isbatch);
/* */
 	if (isbatch)
	    state.verbose=-1;
    }
    fgw_locatetext(state.txtvar);
    state.curr_fd=sql_openfile(state.txtvar, state.def_fd, state.def_fd);
    if (state.verbose>0)
    {
/*
** sql_explode will clear and redisplay  'please wait messages' as needed
*/
/* FIXME: using 4gl user interaction */
	pushquote("wa", 2);
	fgl_call(usr_status, 1);
/* */
    }
    fgw_stackinit(&state.exprlist, sizeof(exprstack_t));
    fgw_stackinit(&state.control, sizeof(controlstack_t));
    while (state.phase1.input_char<state.i_size)
    {
/*
**  this is a bit confusing, but if it's a child and in form mode,
**  we want to disallow window generating expansions, hence we switch
**  to non form mode verbage...
*/
	if (state.verbose && fgw_ischild())
	{
	    int dummy;

	    state.verbose=0;
/* FIXME: using 4gl user interaction */
	    pushint(1);
	    fgl_call(usr_setbatch, 1);
	    popint(&dummy);
/* */
	}
	if (expend<state.phase1.stmt_start ||
	    expstart>state.phase1.output_buffer_len)
	{
	    expstart=-1;
	    expend=-1;
	}
	else if (expend<state.phase1.output_buffer_len)
	    expend-=state.phase1.output_buffer_len;
	else if (expstart<state.phase1.stmt_start)
	    expstart=state.phase1.stmt_start;
/*
**  fire expansion - vars is located by sql_explode
*/
	{
	    int ip, s, e, l;
	    char txt[CHARSIZE];

	    l=state.i_size-state.phase1.input_char+expidx-2;
/* FIXME: using 4gl user interaction */
	    pushquote(state.i_query+state.phase1.input_char-expidx+1,
		      l>32766? 32766: l);
	    pushlocator(state.vars);
	    pushint(state.verbose);
/*	    pushint((state.stack_len? (state.stack->state==S_active ||
				  state.stack->state==S_procedure): 1));
*/	    pushint(1);
	    pushint(expidx);
	    fgl_call(sql_explode, 5);
	    popint(&ip);
	    popquote(&txt, CHARSIZE-1);
	    popint(&e);
	    popint(&s);
/* */
/*
** error in expansion? abort
*/
	    if (sqlca.sqlcode!=0)
	    {
		lastcode=sqlca.sqlcode;
		goto bad_exit;
	    }
/*
**  dirty hack to  maximize expansion size (up to 32k) without
**  chaninging cexpl initialization
*/
	    if (!risnull(CINTTYPE, (char *) &s))
	    {
		s+=state.phase1.input_char-expidx+1;
		e+=state.phase1.input_char-expidx+1;
	    }
	    if (!risnull(CINTTYPE, (char *) &ip))
		ip+=state.phase1.input_char-expidx+1;
	    expidx=2;
	    fgw_clip(txt);
/*
** resize output buffer
*/
	    if (state.o_size<
		(risnull(CINTTYPE, (char *) &s)? 0: e-s)+strlen(txt)+2)
	    {
		char *newbuf;

		newbuf=realloc(state.o_query, state.o_size+BUFSIZE);
		if (!newbuf)
		{
		     lastcode=-208;
		     goto bad_exit;
		}
		state.o_query=newbuf;
		state.o_size+=BUFSIZE;
	    }
/*
** finally, copy strings
*/
	    if (!risnull(CINTTYPE, (char *) &s) && (l=e-s+1))
	    {
		fgw_move(state.o_query+state.phase1.output_buffer_len,
		       state.i_query+s-1, l);
		state.phase1.output_buffer_len+=l;
		*(state.o_query+state.phase1.output_buffer_len)='\0';
	    }
	    if (l=strlen(txt))
	    {
		if (expstart<state.phase1.stmt_start)
		{
		    expstart=state.phase1.output_buffer_len;
		    state.phase1.prev_input_char=state.phase1.input_char;
		}
		strcpy(state.o_query+state.phase1.output_buffer_len, txt);
		state.phase1.output_buffer_len+=l;
		expend=state.phase1.output_buffer_len;
	    }
	    if (risnull(CINTTYPE, (char *) &ip))
		state.phase1.input_char=state.i_size;
	    else
		state.phase1.input_char=ip-1;
	}
	innerloop=state.phase1.output_buffer_len;
	while (innerloop)
	{
	    int foundstmt=0;
	    char *c, *c1, *r, *s;
	    int cs=-1, ce=-1;

	    state.phase1.next_stmt_start=state.phase1.stmt_start;
/*
**  identify the next statement, cleaning comments in the way
*/
	    while (state.phase1.next_stmt_start<state.phase1.output_buffer_len &&
		   !foundstmt)
	    {
		if (!(c=strpbrk(state.o_query+state.phase1.next_stmt_start,
				"{-\\\"\';")))
		{
		    state.phase1.next_stmt_start=state.phase1.output_buffer_len;
		    break;
		}
		state.phase1.next_stmt_start=(int) (c-state.o_query)+1;
		c1=c+1;
/*
**  found it!
*/
		if (*c==';')
		{
		    *c='\0';
		    foundstmt=1;
		    break;
		}
/*
**  found something, but not enough chars to see what it is
**  will postpone till more chars available
*/
		else if (state.phase1.next_stmt_start>=
			 state.phase1.output_buffer_len)
		{
		    state.phase1.next_stmt_start--;
		    break;
		}
/*
** comments (don't handle directives)
*/
		else if (*c=='-' && *c1=='-')
		{
/*
**  not enough characters to see if it is a directive
*/
		    if (!*(++c1))
			break;
/*
**  directive, skip
*/
		    else if (*c1=='+')
			continue;
		    s="\n";
		    cs=state.phase1.next_stmt_start-1;
		}
		else if (*c=='{' && *c1!='+')
		{
		    s="}";
		    cs=state.phase1.next_stmt_start-1;
		}
/*
**  skip escaped chars
*/
		else if (*c=='\\')
		{
		    state.phase1.next_stmt_start++;
		    continue;
		}
/*
**  quotes
*/
		else if (*c=='\'')
		    s="\'\\";
	        else if (*c=='\"')
		    s="\"\\";
/*
** not interesting
*/
		else
		    continue;
		r=state.o_query+state.phase1.next_stmt_start;
/*
**  find the other side of the comment or quote
*/
		while (c=strpbrk(r, s))
		{
		    if (*c!='\\')
			break;
		    else if (!*(c+1))
		    {
			c=NULL;
			break;
		    }
		    else
			r=c+1;
		}
/*
**  the other side not found
*/
		if (!c)
		{
/*
**  and there is nothing else to expand -- syntax error
*/
		    if (state.phase1.input_char==state.i_size)
		    {
			lastcode=-201;
			goto bad_exit;
		    }
/*
**  well, we'll start from scratch next time around
*/
		    cs=-1;
		    state.phase1.next_stmt_start--;
		    break;
		}
/*
**  quote, continue scanning
*/
		else if (*c=='\'' || *c=='\"')
		{
		    state.phase1.next_stmt_start=c-state.o_query+1;
		    continue;
		}
/*
**  cleanup comments
*/
		else if (*c=='\n')
		{
		    state.phase1.next_stmt_start=c-state.o_query+1;
		    ce=state.phase1.next_stmt_start-1;
		}
		else
		{
		    state.phase1.next_stmt_start=c-state.o_query+1;
		    ce=state.phase1.next_stmt_start;
		}
	        while (cs<ce)
		     *(state.o_query+(cs++))=' ';
/*		strcpy(state.o_query+cs, state.o_query+ce);
		state.phase1.next_stmt_start-=(ce-cs);
		state.phase1.output_buffer_len+=(ce-cs);
		if (expstart>=cs && expstart<ce)
		    expstart=cs;
		if (expend>=cs && expend<ce)
		    expend=cs; */
		cs=-1;
		ce=-1;
	    }
/*
**  test for the interrupt key every so often
*/
	    if (int_flag)
	    {
		lastcode=SQLNOTFOUND;
		goto bad_exit;
	    }
/*
**  process statement
*/
	    if (state.phase1.input_char==state.i_size ||
		foundstmt)
	    {
		state.parseroptions=0;
		lastcode=sql_parser(&state);
		if (risnull(CINTTYPE, (char *) &lastcode) && state.verbose)
		{
		    char txt1[256], txt2[256];

/* FIXME: using 4gl user interaction */
		    pushquote("cdbm.nm", 7);
		    fgl_call(txt_retrieve, 1);
		    popquote(&txt1, 255);
		    fgw_clip(txt1);
		    sprintf(txt2, "%s %i", txt1, sqlca.sqlerrd[2]);
		    pushquote(txt2, strlen(txt2));
		    fgl_call(usr_notify, 1);
/* */
		}
		else if (lastcode && lastcode!=SQLNOTFOUND)
		    goto bad_exit;
/*
**  skip to next statement
*/
		state.phase1.stmt_start=state.phase1.next_stmt_start;
/*
**  remove processed statements from ouput buffer
*/
		if (!state.control.count)
		{
		    if (state.phase1.stmt_start>=state.o_size)
		    {
			state.phase1.output_buffer_len=0;
			state.phase1.stmt_start=0;
			expstart=0;
			expend=0;
		    }
		    else
		    {
			strcpy(state.o_query,
			       state.o_query+state.phase1.stmt_start);
			state.phase1.output_buffer_len-=
			    state.phase1.stmt_start;
			state.phase1.stmt_start=0;
		    }
		}
	    }
	    innerloop=(state.phase1.stmt_start<state.o_size) && foundstmt;
	}
    }
/*
** non terminated loops are an error
*/
    if (state.control.count)
	lastcode=-201;
bad_exit:
/*
**  if necessary, output error message
*/
    if (state.verbose)
    {
	if (state.verbose>0)
	{
/* FIXME: using 4gl user interaction */
	    pushquote("", 0);
	    fgl_call(usr_status, 1);
	}
	if (lastcode!=SQLNOTFOUND && lastcode!=0)
	{
	    pushint(lastcode);
	    fgl_call(txt_retrieve, 1);
	    fgl_call(usr_notify, 1);
/* */
	}
    }
    fgw_stackfree(&state.control, fgw_localfree);
    fgw_stackfree(&state.exprlist, NULL);
    fgw_freehash(state.vars);
    fgw_tssdrop(&state.tsshead);
    if (state.o_query)
	free(state.o_query);
    if (fgw_ischild())
	exit(0);
    if (!lastcode || lastcode==SQLNOTFOUND)
	if (state.done_display)
	    lastcode=0;
	else
	    rsetnull(CINTTYPE, (char *) &lastcode);
    return(lastcode);
}


/*
** parses an inline expression, returns index of first invalid char
*/
sql_evalexpr(nargs)
int nargs;
{
    parserstate_t state;                /* passed in bulk to yyparse */
    loc_t vars;                         /* byte containing vars */
    char *buf, *r;
    int s, e, l;
    exprstack_t *exprlist;
 
    byfill(&state, sizeof(parserstate_t), 0);
    poplocator(&state.vars);
    popint(&e);
    popint(&s);
    buf=fgw_popquote();
    l=strlen(buf);
/*
** only parse if we have a proper string, start & end
*/
    if (buf && s>0 && s<=l && s<=e)
    {
/*
** adjust string start & zero terminate end
*/
	state.o_query=buf+s-1;
	if (e>l)
	    e=l;
	*(buf+e)='\0';
	state.phase1.output_buffer_len=s-e+1;
	state.parseroptions=1;
	fgw_stackinit(&state.exprlist, sizeof(exprstack_t));
/*
** do the parsing & pop the result
*/
	if (sql_parser(&state))
	    retquote("");
	else
	{
	    exprlist=(exprstack_t *) fgw_stackpop(&state.exprlist);
	    switch (exprlist->type)
	    {
	      case CDTIMETYPE:
		retdtime(exprlist->val.datetime);
		break;
	      case CINVTYPE:
		retinv(exprlist->val.interval);
		break;
	      case CDECIMALTYPE:
	      case CMONEYTYPE:
		retdec(exprlist->val.decimal);
		break;
	      case CDOUBLETYPE:
		retdub(&exprlist->val.real);
		break;
	      case CINTTYPE:
		retint(exprlist->val.intvalue);
		break;
	      case CDATETYPE:
		retdate(exprlist->val.intvalue);
		break;
	      default:
		retstring(exprlist->val.string);
	    }
/*
** work out next character: it's next token start, except if we have
** successfully reached the end of the string
*/
	    if(!*(state.ibufp-1))
		s=(int) (state.ibufp-buf);
	    else
		s=(int) (state.tokstart-buf)+1;
	}
	free(buf);
    }
    else
	retquote("");
    retint(s);
    fgw_stackfree(&state.exprlist, NULL);
    fgw_tssdrop(&state.tsshead);
    return(2);
}

/* FIXME: we require empty stubs for usr_warn & usr_confirm if sql_run
   used within cgi scripts
*/

/*
**  confirm database operation
*/
sql_asktouch(touch)
int touch;
{
    int r;

    if (risnull(CINTTYPE, (char *) &touch))
    {
/* FIXME: using 4gl user interaction */
	pushquote("cdbm.nq", 7);
	fgl_call(usr_confirm, 1);
	popint(&r);
/* */
	return r;
    }
    else if (touch)
	return 1;
    else
    {
/* FIXME: using 4gl user interaction */
	pushquote("cdbm.nq", 7);
	fgl_call(usr_warn, 1);
/* */
	return 0;
    }
}

/*
** returns first variable name, continuation from char buffer
*/
sql_getvar(nargs)
int nargs;
{
    char *buf, *c, *str, *e;
    int s, l, w;
    fgw_tsstype *head;
    void *t;			/* FIXME should be using tokenlist_t *t */

    popint(&l);
    popint(&s);
    buf=fgw_popquote();
    str=NULL;
    if (buf)
    {
/*
** fix start & end points
*/
	c=buf+s-1;	/* FIXME: should be checking validity of s, l */
	*(buf+l)='\0';
/*
** skip separators
*/
	while (*c==' ' || *c=='\t' || *c=='\n')
	{
	   c++;
	   s++;
	}
	if (((*c>='A' && *c<='Z') || (*c>='a' && *c<='z')) &&
	    (str=fgw_getvar(&head, c, &e, &t)))
	{
/*
** scan reserved words, bomb out if found
*/
	    if (w=fgw_scanreserved(str, t))
		str=NULL;
	    else
		s=1+(int) (e-buf);
	}
	else if ((*c=='\"') && fgw_delimident() &&
	    (str=fgw_getstring(&head, c, &e)))
		s=1+(int) (e-buf);
	free(buf);
    }
    if (str)
	retquote(str);
    else
	retquote("");
    retint(s);
    fgw_tssdrop(&head);
    return(2);
}
