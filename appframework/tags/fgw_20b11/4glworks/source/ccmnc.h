/*
	CCMNC.h  -  functions used by C functions only, definitions

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Oct 99
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

#ifndef CCMNC_H
#ifndef popquote
#define popquote popvchar	/* since this is what we really want */
#endif


typedef struct fgw_list
{
    int id;
    struct fgw_list *next;
} fgw_listentry;

typedef struct
{
    fgw_listentry *head;
    fgw_listentry *last;
    int lastid;
    int base;
    int notfound;
} fgw_listtype;

typedef struct fgw_stack
{
    int len;
    int count;
    int size;
    char *stack;
} fgw_stacktype;

typedef struct fgw_tss
{
    struct fgw_tss *next;
    struct fgw_tss *prev;
    char string;
} fgw_tsstype;

extern char *fgw_popquote();
extern fgw_listentry *fgw_listsearch();
extern char *fgw_stackpop();
extern char *fgw_stackpeek();
extern char *fgw_tssmalloc();
extern char *fgw_tssrealloc();

#define CCMNC_H
#endif
