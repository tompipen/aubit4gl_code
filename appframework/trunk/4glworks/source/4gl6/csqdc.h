/*
	CSQDC.h  -  Sql interpreter dynamic sql support functions definitions

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Jan 97
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

#ifndef CSQDC_H
#include <sqlda.h>
typedef struct sqlvar_struct sqlva;

typedef struct
{
    char *entry;	/* pointer to entry allocated in heap */
    int etype;		/* type of entry, or size for headers */
} fgw_heapentry;

typedef struct
{
    int size;			/* max no of entries */
    int entries;		/* cur no of entries */
    fgw_heapentry heap[1];
} fgw_heaptype;

#define IDLENGTH 18
typedef struct fgw_stmt
{
    int st_id;			/* id */
    struct fgw_stmt *st_next;	/* pointer to next statement struct */
    int fmt_type,		/* type of format */
	headwidth,		/* max header width */
	width;			/* format width */
    fgw_heaptype *headers,	/* headers list */
		 *formats;	/* formats list */
    char *pretable,		/* various (html) strings */
	 *posttable,
	 *prerow,
	 *postrow,
	 *preheader,
	 *postheader,
	 *prefield,
	 *postfield;
    int countfields;		/* HTML column count flag */
    int curstate;		/* state: see ST_... defines above */
    char stmtname[IDLENGTH];	/* name of statement */
    char curname[IDLENGTH];	/* name of cursor */
    char *sqlbuf;		/* data returned from engine */
    struct sqlda *sqlda_ptr;	/* output sqlda area */
    struct sqlda sqlda_in;	/* input sqlda area */
    fgw_heaptype *intovars;	/* destination variables list */
    int field;			/* field count (needed for HTML field count
				   & vertical & brief formats displays) */
    int format;			/* format count (displays) */
} fgw_stmttype;

#define ST_UNINITIALIZED 0
#define ST_EXECUTABLE 2
#define ST_NEWLYOPENED 3
#define ST_OPENED 4

#define CSQDC_H
#endif
