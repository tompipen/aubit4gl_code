/*
	CSQPC.h  -  Sql interpreter definitions

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Mar 00
	Current release: Sep 02

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

#ifndef CSQPC_H
#include <datetime.h>
#include <decimal.h>
#include <locator.h>
#include <sqlda.h>
#include "ccmnc.h"
#include "cfioc.h"
#include "csqdc.h"

typedef struct phase1state
{
    int input_char;
    int prev_input_char;
    int stmt_start;
    int next_stmt_start;
    int output_buffer_len;
} phase1state_t;

typedef struct exprstack
{
    int type;			/* see sqltypes.h */
    union
    {
	char *string;		/* strings */
	int intvalue;		/* integers */
	double real;		/* floats */
	dec_t *decimal;		/* decimals & money */
	dtime_t *datetime;	/* datetimes */
	intrvl_t *interval;	/* intervals */
	short range[2];		/* VAR substring range */
    } val; 
    int count;			/* # of expressions in list */
} exprstack_t;


typedef struct controlstack
{
    int stmt_type;
    int state;
    fgw_stmttype *stmt;
    int dorows;
    int style;
    char *proc_start;
    char *destvar;
    int element;
    int forcount;
    phase1state_t phase1;
    phase1state_t nextphase1;
} controlstack_t;

/*
** control stack states
** assumption is that states where expansions are allowed are positive
*/
#define S_WHILE		 4
#define S_NESTED	 3
#define S_INPROC	 2
#define S_ACTIVE	 1
#define S_DISABLED	 0
#define S_DISPROC	-2
#define S_CONTINUE	-3
#define S_IF		-4

typedef struct parserstate
{
    phase1state_t phase1;	/* outer layer */
    phase1state_t prevphase1;
    char *i_query;
    char *o_query;
    int i_size;
    int o_size;

    char *ibufp;		/* scanner & parser buffers */
    char *ibufe;
    char *sqlstart;
    char *sqlend;
    char sqlsv;
    char *tokstart;

    int parseroptions;
    fgw_tsstype *lexhead;
    fgw_tsstype *exphead;
    int inside_expansion;
    fgw_stacktype control;
    fgw_stacktype exprlist;
    loc_t *vars;

    fgw_fdesc *def_fd;		/* pointer to default stream:	NULL to blob
								-1 ignore */
    int width;
    int touch;
    int verbose;
    int html;
    int error_cont;

    int done_display;
    fgw_fdesc *curr_fd;		/* same meaning as def_fd */
    loc_t *txtvar;
} parserstate_t;

/*
**  script flags
*/
#define K_verbose	1
#define K_html		2
#define K_errorcont	4
#define K_dml		8
#define K_noconf	16

#define CSQPC_H
#endif
