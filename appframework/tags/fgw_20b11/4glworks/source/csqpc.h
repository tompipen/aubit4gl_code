/*
	CSQPC.h  -  Sql interpreter definitions

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

#ifndef CSQPC_H
#include <datetime.h>
#include <decimal.h>
#include <locator.h>
#include <sqlda.h>
#include "ccmnc.h"

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
    int count;
    struct exprstack *next;	/* function call parameter list */
} exprstack_t;

typedef struct controlstack
{
    int stmt_type;
    int state;
    int stmt_id;
    int dorows;
    int style;
    char *proc_start;
    phase1state_t phase1;
    phase1state_t next_phase1;
    char *destvar;
} controlstack_t;

typedef struct parserstate
{
    phase1state_t phase1;
    char *i_query;
    char *o_query;
    int i_size;
    int o_size;
    int s_start;
    int s_size;

    char *ibufp;
    char *tokstart;

    int parseroptions;
    fgw_tsstype *tsshead;
    fgw_stacktype control;
    fgw_stacktype exprlist;
    loc_t *vars;

    int def_fd;
    int width;
    int touch;
    int verbose;
    int html;
    int error_cont;

    int done_display;
    int curr_fd;
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
