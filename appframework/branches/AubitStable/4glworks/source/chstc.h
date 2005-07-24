/*
	CHSTC.h  -  Hashes, definitions

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Dec 99
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

#ifndef CHSTC_H
typedef struct h_entry_s
{
    int		next;		/* next entry */
    int		size;		/* total size of entry */
    short	type;		/* entry type (see sqltypes.h), -1 is emtpy */
    short	def;		/* offset to definition string */
    char	entry;		/* entry needs to be int aligned, as we
				   access ints & floats directly off entry */
} fgw_hstentry;

typedef struct
{
    int		magic;		/* just to make sure it's our type of blobs */
    int		freeptr;	/* free space handling */
    int		freecnt;
    int		entries;	/* # of entries */
    int		buckets[1];	/* buckets[0] is the # of buckets */
} fgw_hsthead;

#define STARTHASHSIZE 0x8000
#define HASHKEY 0x4d470000	/* builds up my ego! */
#define fgw_hashhead(arg1) ((fgw_hsthead *) (arg1->loc_buffer))
#define fgw_hashentry(arg1, arg2) ((fgw_hstentry *) ((arg1->loc_buffer)+(arg2)))
#define fgw_defentry(arg1) ((char *) &(arg1->entry)+(arg1->def))

extern fgw_hstentry *fgw_hstget();

#define CHSTC_H
#endif
